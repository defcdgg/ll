#!/usr/bin/env bash
# bytecmp.sh <func> <candidate.c> <abs-symbol-assignments...>
# 单函数**字节级**判定 (EXPERIENCE 经验 29): 编候选 -> 部分链接(施加字面池重定位)
# -> objcopy 出 .text -> 与 permuter/<func>/target.o 的 .text 逐字节 cmp。
# 输出 "OK" = 字节完全一致 (bl 槽位除外)。比 fndiff 的 score 更可信。
set -euo pipefail
cd "$(dirname "$0")/.."
fn="${1:?}"; src="${2:?}"; shift 2
dir="permuter/$fn"; out=".scratch/bytecmp/$fn"; mkdir -p "$out"
ref="asm/nonmatchings/$fn.s"; [ -f "$ref" ] || ref="asm/matchings/$fn.s"
[ -f "$dir/target.o" ] || { { printf '\t.include "macros/function.inc"\n'; cat "$ref"; } > "$dir/target.s"; \
  arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -I asm -o "$dir/target.o" "$dir/target.s"; }
"./$dir/compile.sh" "$src" x "$out/mine.o" 2> "$out/err.txt" || { echo "COMPILE-FAIL"; tail -5 "$out/err.txt"; exit 1; }
{ printf 'SECTIONS { .text 0 : { *(.text) } }\n'; printf '%s\n' "$@"; } > "$out/abs.ld"
arm-none-eabi-ld -T "$out/abs.ld" -o "$out/linked.o" "$out/mine.o" 2>"$out/lerr.txt" || { echo "LINK-FAIL"; cat "$out/lerr.txt"; exit 1; }
arm-none-eabi-objcopy -O binary --only-section=.text "$out/linked.o" "$out/mine.bin"
arm-none-eabi-objcopy -O binary --only-section=.text "$dir/target.o" "$out/tgt.bin"
if cmp -s "$out/mine.bin" "$out/tgt.bin"; then echo "OK ($(wc -c < "$out/mine.bin") bytes)";
else echo "DIFF: $(cmp -l "$out/mine.bin" "$out/tgt.bin" | wc -l) bytes / $(wc -c < "$out/mine.bin")"; fi