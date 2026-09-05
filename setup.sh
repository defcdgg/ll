#!/bin/bash
# 环境搭建: 校验依赖 -> 拉子模块 -> 建 .venv -> 编 agbcc/工具 -> 出 code.s+asm -> 自证 SHA1
#
# 选项:
#   --skip-venv      不建 .venv (只要 make 能过就行; fndiff/permuter 会不可用)
#   --no-verify      结尾不跑全量 make + sha1sum (省几分钟, 但失去"环境真可用"的定论)
#   --fast           不清 build/ (增量重编)
#   --with-qtydump   额外编一份诊断用 tools/agbcc/bin/agbcc_qtydump (scripts/qtydump.sh 依赖)
set -e

echo "=== Lunar Legend Decompilation - Setup ==="

SKIP_VENV=0
NO_VERIFY=0
FAST=0
WITH_QTYDUMP=0
for arg in "$@"; do
    case "$arg" in
        --skip-venv)    SKIP_VENV=1 ;;
        --no-verify)    NO_VERIFY=1 ;;
        --fast)         FAST=1 ;;
        --with-qtydump) WITH_QTYDUMP=1 ;;
        -h|--help)      sed -n '2,8p' "$0"; exit 0 ;;
        *)              echo "Error: unknown option '$arg' (try --help)"; exit 1 ;;
    esac
done

# 单一权威值, 别在多处硬编码 (旧版在 echo 和比较处各写了一遍)
BASEROM_SHA1="483b2c37330cf914c121801acd9f15776f92eb29"

warn() { echo "  !! $*"; }

# Check for required tools
check_tool() {
    if ! command -v "$1" &> /dev/null; then
        echo "Error: $1 is not installed."
        echo "$2"
        exit 1
    fi
}

ARM_TC="Install ARM GNU Toolchain: https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads (Debian/Ubuntu: binutils-arm-none-eabi)"
# cpp 是编译主链路 (Makefile: CPP := $(PREFIX)cpp), 每个 .c 都要过它 —— 旧版漏查
check_tool arm-none-eabi-cpp   "$ARM_TC"
check_tool arm-none-eabi-as    "$ARM_TC"
check_tool arm-none-eabi-ld    "$ARM_TC"
check_tool arm-none-eabi-objcopy "$ARM_TC"
# agbcc 的 build.sh 需要 ar (tools/agbcc/build.sh: binutils 探测)
check_tool arm-none-eabi-ar    "$ARM_TC"
check_tool make   "Install make via your package manager."
check_tool git    "Needed for submodules (tools/agbcc, m2c, asm-differ, decomp-permuter)."
check_tool python3 "Needed by scripts/gen_asm.py, audit.py, fncheck.py, dumpraw.py."
check_tool gcc    "Host gcc builds agbcc (and the 'ctx' make target)."

# Check for baserom
if [ ! -f baserom.gba ]; then
    echo "Error: baserom.gba not found."
    echo "Place your Lunar Legend (Japan) ROM as baserom.gba in the project root."
    echo "Expected SHA1: $BASEROM_SHA1"
    exit 1
fi

# Verify baserom SHA1
echo "Verifying baserom.gba..."
if command -v sha1sum &> /dev/null; then
    SHA1_CMD="sha1sum"
elif command -v shasum &> /dev/null; then
    SHA1_CMD="shasum -a 1"
else
    # 旧版这里会让 set -e 静默退出, 什么提示都不给
    echo "Error: neither sha1sum nor shasum is available; cannot verify baserom.gba."
    exit 1
fi
ACTUAL_SHA1=$($SHA1_CMD baserom.gba | cut -d' ' -f1)

if [ "$ACTUAL_SHA1" != "$BASEROM_SHA1" ]; then
    echo "Error: baserom.gba SHA1 mismatch."
    echo "  Expected: $BASEROM_SHA1"
    echo "  Got:      $ACTUAL_SHA1"
    echo "Make sure you have the correct ROM."
    exit 1
fi
echo "baserom.gba: OK"

# Init submodules (无嵌套, 不需要 --recursive)
echo ""
echo "Initializing submodules..."
git submodule update --init

# Python venv for the decomp tooling (asm-differ / decomp-permuter / m2c).
# 函数清单侧脚本 (gen_asm/audit/fncheck/tsv_init/gen_reports/atlas) 无第三方依赖, 系统 python3 即可;
# 但 scripts/fndiff.sh 硬编码 .venv/bin/python, 所以这个 venv 是必需的。
VENV=.venv
VENV_PKGS="colorama watchdog Levenshtein cxxfilt toml graphviz"
if [ "$SKIP_VENV" = "1" ]; then
    echo ""
    echo "Skipping .venv (--skip-venv): scripts/fndiff.sh and permuter will NOT work."
elif [ ! -x "$VENV/bin/python" ]; then
    echo ""
    echo "Creating python venv in $VENV ..."
    python3 -m venv "$VENV"
    if ! "$VENV/bin/pip" install --disable-pip-version-check -q $VENV_PKGS; then
        warn "pip install failed (offline?). 'make' still works, but"
        warn "  scripts/fndiff.sh  -> needs colorama watchdog Levenshtein cxxfilt"
        warn "  permuter.py        -> needs toml"
        warn "Re-run later: $VENV/bin/pip install $VENV_PKGS"
    fi
elif ! "$VENV/bin/python" -c "import colorama, watchdog, Levenshtein, cxxfilt, toml" 2>/dev/null; then
    echo ""
    echo "Existing $VENV is missing tooling deps, installing..."
    "$VENV/bin/pip" install --disable-pip-version-check -q $VENV_PKGS \
        || warn "pip install failed; fndiff/permuter unavailable."
else
    echo ""
    echo "$VENV is up-to-date, skipping."
fi

# 各 agent 的临时区 (scripts/atlas.py 直接 open(".scratch/atlas.json") 且不会自建)
mkdir -p .scratch

# Clean generated files
echo ""
if [ "$FAST" = "1" ]; then
    echo "Cleaning generated asm/ (keeping build/, --fast)..."
    rm -rf asm/nonmatchings asm/matchings
else
    echo "Cleaning generated files..."
    rm -rf asm/nonmatchings asm/matchings build
fi

# Build agbcc (skip if cached and up-to-date)
echo ""
AGBCC_CACHE_FILE="tools/agbcc/.build_cache"
AGBCC_COMMIT=$(git -C tools/agbcc rev-parse HEAD 2>/dev/null || echo "unknown")

if [ -f tools/agbcc/bin/agbcc ] && [ -f tools/agbcc/bin/old_agbcc ] \
   && [ -f "$AGBCC_CACHE_FILE" ] && [ "$(cat "$AGBCC_CACHE_FILE")" = "$AGBCC_COMMIT" ]; then
    echo "agbcc is up-to-date (cached), skipping build."
else
    echo "Building agbcc (this takes a while)..."
    cd tools/agbcc
    # build.sh 会依次产出 agbcc / old_agbcc / agbcc_arm, 而 install.sh 无条件 cp 这三个
    # (tools/agbcc/install.sh), 所以任何一步失败都必须当场停下 ——
    # 旧版写成 `./build.sh || true`, 结果是死在 install.sh 的报错上, 完全指不到真因。
    if ! ./build.sh > ../../.scratch/agbcc-build.log 2>&1; then
        echo "Error: tools/agbcc/build.sh failed. Last 25 lines of .scratch/agbcc-build.log:"
        tail -25 ../../.scratch/agbcc-build.log
        echo "Hint: agbcc is a 2.7.2-era GCC; a very new host gcc/g++ may need CC=gcc-12 CXX=g++-12."
        exit 1
    fi
    ./install.sh ../..
    cd ../..

    # Makefile 两个变体都用: agbcc (普通 C 文件) + old_agbcc (m4a/m4a_tables/agb_sram)
    for b in agbcc old_agbcc; do
        if [ ! -f "tools/agbcc/bin/$b" ]; then
            echo "Error: tools/agbcc/bin/$b missing after build."
            exit 1
        fi
    done

    echo "$AGBCC_COMMIT" > "$AGBCC_CACHE_FILE"
fi

# 可选: 诊断版编译器 (只 dump local-alloc 的 qty 优先级表), 与正式 agbcc 字节等价, 已验证
if [ "$WITH_QTYDUMP" = "1" ] && [ ! -x tools/agbcc/bin/agbcc_qtydump ]; then
    echo ""
    echo "Building agbcc_qtydump (diagnostic)..."
    (
        cd tools/agbcc
        git apply ../../scripts/patches/agbcc-qty-dump.patch
        # 无论成败都把子模块还原干净, 否则下次 make 会用到打过补丁的编译器
        trap 'git checkout -- gcc/local-alloc.c' EXIT
        make -C gcc normal -j1
        cp gcc/agbcc bin/agbcc_qtydump
        make -C gcc clean
    )
    git -C tools/agbcc checkout -- gcc/local-alloc.c 2>/dev/null || true
fi

build_tool(){
    echo ""
    if [ -f tools/$1/$1 ]; then
        echo "$1 is up-to-date, skip build."
    else
        echo "Building $1..."
        cd tools/$1
        make
        if [ ! -f $1 ]; then
            echo "Error: $1 failed to build."
            exit 1
        fi
        cd ../../
    fi
}

build_tool gbafix
build_tool preproc
build_tool gbadisasm

# Raw data blobs referenced by src/data_*.c via INCBIN_U32("data/raw_data/*.bin").
# data/raw_data 不入库, 必须在这里从 baserom 提取, 否则 make 报 Failed to open ...bin
echo ""
echo "Extracting data/raw_data from baserom.gba..."
python3 scripts/dumpraw.py

# Generate asm/ from ROM (走 make 目标, 避免与 Makefile 里的命令漂移; split_asm.py 已废弃)
echo ""
echo "Generating assembly from ROM..."
make code.s
make asm

# Self-verification: 光看 sha1sum -c 会被旧 ll.gba 骗过 (编译失败时产物不更新),
# 所以必须真的跑一次 make 并看尾部。
if [ "$NO_VERIFY" = "1" ]; then
    echo ""
    echo "Skipping final build verification (--no-verify)."
else
    echo ""
    echo "Building ROM and verifying SHA1..."
    # 注意: `make | tail` 在 `if !` 里拿不到 make 的退出码 (管道状态是 tail 的),
    # 所以先落盘再判状态, 并把尾部报错打出来 (AGENTS 铁律 5)。
    if ! make > .scratch/setup-make.log 2>&1; then
        echo "Error: make failed. Last 30 lines of .scratch/setup-make.log:"
        tail -30 .scratch/setup-make.log
        exit 1
    fi
    tail -5 .scratch/setup-make.log
    sha1sum -c ll.sha1
fi

echo ""
echo "=== Setup complete ==="
echo "Run 'make' to build the ROM and verify the match."
echo "Read AGENTS.md first; claim a function with scripts/claim.sh <fn>."
