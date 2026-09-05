#!/usr/bin/env bash
# match_fn.sh <func> -- 合入收尾自动化 (R4): 校验 src 真 C -> TSV 翻状态 ->
# gen_asm -> 定向重编 -> fncheck -> 全量 make + SHA1 -> audit 提示。
# 前提: 你已把 src/<tu>.c 的 INCLUDE_ASM 行替换为真 C 且已 claim <func>。
set -euo pipefail
cd "$(dirname "$0")/.."

fn="${1:?用法: match_fn.sh <func>}"
[ -f ".claims/$fn.lock" ] && ag=$(awk -F= '/^agent=/{print $2}' ".claims/$fn.lock") || ag=""
if [ -n "$ag" ] && [ "$ag" != "${DECOMP_AGENT:-}" ]; then
  echo "锁持有者 $ag != DECOMP_AGENT=${DECOMP_AGENT:-未设}"; exit 1
fi

# ---- 1. 定位函数与 C 文件 ----
row=$(grep -P "\t$fn\t" functions.tsv) || { echo "TSV 里没有 $fn"; exit 1; }
status=$(awk -F'\t' -v n="$fn" '$6==n {print $1}' functions.tsv)
[ "$status" = "1" ] || { echo "$fn 在 TSV 里 status=0, 但查找失败?"; exit 1; }
tu=$(awk -F'\t' -v n="$fn" '$6==n {print $3}' functions.tsv)
srcf="src/$tu.c"

# ---- 2. 校验 src 是真 C (非 INCLUDE_ASM) ----
grep -qE "INCLUDE_ASM\(\"asm/matchings\", $fn\)" "$srcf" && {
  echo "SKIP: $srcf 里 $fn 是 INCLUDE_ASM(matchings) — asm 占位, 无需合入"; exit 0; }
grep -qE "INCLUDE_ASM\(\"asm/(non)?matchings\", $fn\)" "$srcf" && {
  echo "FAIL: $srcf 里 $fn 仍是 INCLUDE_ASM(nonmatchings) — 先替换为真 C"; exit 1; }

# ---- 3. TSV kind 已是 1 (status 权威 = 源码, tsv_init 语义) ----
# gen_asm 依据 status=1 + matchings 目录: 真 C 也需要 .s 在 matchings/ (等价旧 yaml[1])
python3 scripts/gen_asm.py --sync
[ -f "asm/matchings/$fn.s" ] || { echo "FAIL: asm/matchings/$fn.s 缺失"; exit 1; }

# ---- 4. 定向重编 + 字节定论 ----
make "build/src/$tu.o" > /dev/null 2>&1 || { echo "FAIL: 编译 build/src/$tu.o"; exit 1; }
python3 scripts/fncheck.py "$fn" || exit 1

# ---- 5. 全量终验 ----
timeout 900 make > /dev/null 2>&1
sha1sum -c ll.sha1

# ---- 6. audit + 提示 ----
python3 scripts/audit.py 2>&1 | sed -n '2,5p'
echo ""
echo "收尾清单:"
echo "  1. TSV note: awk -i inplace -F'\\t' -v n='$fn' '\$6==n {\$7=\"✅ $(date +%F) ${DECOMP_AGENT:-?}: fncheck OK\"; print}' OFS='\\t' functions.tsv"
echo "  2. git add -A && git commit -m 'match $fn'"
echo "  3. scripts/claim.sh --release $fn"
echo "  4. 故事写 docs/progress.md"
