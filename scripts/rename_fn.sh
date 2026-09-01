#!/usr/bin/env bash
# rename_fn.sh <old> <new> [--force] [--dry-run] [--prototype]
# 全链函数改名 (R4): ll.cfg -> code.s -> include/*.h 原型 + src/*.c 引用点 -> gen_asm -> 定向重编 -> fncheck。
# 失败任意一步自动回滚。详见 REFACTOR_PLAN.md R4。
#
# 事故根因防御 (RULES): 默认 **不改原型签名**, 只换名字。需要升级签名时人工加 --prototype。
set -euo pipefail
cd "$(dirname "$0")/.."

old="${1:?用法: rename_fn.sh <old> <new> [--dry-run] [--prototype]}"
new="${2:?缺 <new>}"; shift 2
DRY=0; FORCE=0; PROTO=0
for a in "$@"; do case "$a" in
  --dry-run) DRY=1;; --force) FORCE=1;; --prototype) PROTO=1;;
  *) echo "未知参数: $a"; exit 2;;
esac; done

[ "$old" != "$new" ] || { echo "old == new"; exit 2; }

# ---- 1. 前置检查 ----
grep -qE "^(thumb|arm)_func 0x[0-9a-f]+ $old\$" ll.cfg || { echo "ll.cfg 里没有 $old"; exit 1; }
grep -qE "^(thumb|arm)_func 0x[0-9a-f]+ $new\$" ll.cfg && { echo "ll.cfg 已有 $new, 撞车"; exit 1; }
grep -qP "^[01]\t[a-z]+\t\w+\t0x[0-9a-f]+\t$old\t" functions.tsv || { echo "functions.tsv 里没有 $old"; exit 1; }

addr=$(grep -E "^(thumb|arm)_func 0x[0-9a-f]+ $old\$" ll.cfg | awk '{print $2}')
if [ "$FORCE" != 1 ]; then
  lock=".claims/$old.lock"
  [ -f "$lock" ] || { echo "未认领: 先 scripts/claim.sh $old (或 --force)"; exit 1; }
  ag=$(awk -F= '/^agent=/{print $2}' "$lock")
  [ "$ag" = "${DECOMP_AGENT:-}" ] || { echo "锁持有者 $ag != DECOMP_AGENT=${DECOMP_AGENT:-未设} (或 --force)"; exit 1; }
fi

# ---- 2. 备份 ----
BK=".scratch/rename/$old"
mkdir -p "$BK"
cp ll.cfg code.s functions.tsv "$BK/"
for f in include/*.h src/*.c; do grep -qE "\b$old\b" "$f" && cp "$f" "$BK/$(echo "$f" | tr / _)"; done
rollback() {
  echo "== 回滚 =="
  cp "$BK/ll.cfg" "$BK/code.s" "$BK/functions.tsv" .
  for b in "$BK"/src_* "$BK"/include_*; do
    [ -f "$b" ] || continue
    case "$b" in
      */src_*) dest="src/$(basename "$b" | sed 's/^src_//')";;
      *) dest="include/$(basename "$b" | sed 's/^include_//')";;
    esac
    cp "$b" "$dest"
  done
  echo "已回滚 (备份在 $BK)"
}
trap rollback ERR

[ "$DRY" = 1 ] && { echo "[dry-run] 将改名 $old -> $new (addr $addr); 触碰文件:"; grep -lE "\b$old\b" include/*.h src/*.c; exit 0; }

# ---- 3. ll.cfg + code.s ----
sed -i "s/^\(\(thumb\|arm\)_func $addr\) $old\$/\1 $new/" ll.cfg
tools/gbadisasm/gbadisasm baserom.gba -c ll.cfg > code.s
grep -qE "^(thumb|arm)_func $addr $new\$" ll.cfg || { echo "ll.cfg 改名失败"; exit 1; }

# ---- 4. include/*.h + src/*.c 引用点 (只换名, 不动签名) ----
touching=$(grep -lE "\b$old\b" include/*.h src/*.c || true)
for f in $touching; do
  sed -i "s/\b$old\b/$new/g" "$f"
done
echo "改名引用点: $(echo "$touching" | wc -l) 个文件"

# ---- 5. functions.tsv 缓存名同步 ----
sed -i "s/^\(0x[0-9a-f]*	[01]	[a-z]*	[0-9]*	\)$old\t/\1$new\t/" functions.tsv
python3 scripts/gen_asm.py --sync

# ---- 6. 定向重编受影响 TU + fncheck ----
tus=$(grep -lE "\b$new\b" src/*.c | sed 's|src/||; s|\.c$||' | sort -u)
make ${tus:+$tus/%.o} > /dev/null 2>&1 || make > /dev/null   # 缺依赖时退全量
fails=0
for tu in $tus; do true; done
python3 scripts/fncheck.py "$new" || fails=1
# 调用点在同一 TU 的已匹配函数一并核验
for f in $(grep -lE "\b$new\b" src/*.c); do
  tu=$(basename "$f" .c)
  for fn in $(awk -F'\t' -v t="$tu" '$3==t && $2==1 {print $5}' functions.tsv); do
    python3 scripts/fncheck.py "$fn" > /dev/null 2>&1 || { echo "FAIL: $fn ($tu)"; fails=1; }
  done
done
[ "$fails" = 0 ] || { echo "fncheck 有 FAIL"; exit 1; }

# ---- 7. 全量终验 ----
timeout 900 make > /dev/null 2>&1
sha1sum -c ll.sha1
trap - ERR
echo "OK: $old -> $new (addr $addr), SHA1 绿"
