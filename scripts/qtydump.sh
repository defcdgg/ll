#!/bin/bash
# qtydump.sh <candidate.c> [outfile]
#
# Dump agbcc's local-alloc quantity priority table for a candidate C file,
# using the patched compiler tools/agbcc/bin/agbcc_qtydump.
#
# The patch (scripts/patches/agbcc-qty-dump.patch) is diagnostic only and is
# built as a SEPARATE binary -- the build pipeline always uses bin/agbcc.
# Verified: patched and unpatched agbcc produce byte-identical .s for all 10
# translation units.
#
# IMPORTANT SCOPE LIMIT: local-alloc only assigns pseudos that live entirely
# within ONE basic block.  Values that cross a basic-block boundary (loop
# counters, pointers live across a branch or call, anything function-wide) are
# assigned by global-alloc (global.c) and DO NOT APPEAR in this table.  If a
# register-home problem involves a long-lived value, this dump will show few or
# no relevant qtys -- that is the signal that the decision belongs to
# global-alloc, not local-alloc, and the QTY_CMP_PRI model does not apply.
#
# Columns:
#   ord    allocation order after qsort (order find_free_reg hands out regs)
#   qty    quantity number (ties in pri are broken by LOWER qty number)
#   refs   qty_n_refs -- reference count from flow.c (includes REG_EQUIV notes)
#   birth/death/life  insn-number range the qty is live
#   size   qty_size in registers
#   pri    QTY_CMP_PRI = floor_log2(refs)*refs*size/life*10000  (-1 if life==0)
#   sugg   qty_phys_num_sugg     (nonzero => allocated in the earlier pass)
#   csug   qty_phys_num_copy_sugg
#   xcall  qty_n_calls_crossed
#   reg    final hard register assigned by local-alloc (-1 = left to global)
#   pseudos  the pseudo-register numbers belonging to this qty
set -e
cd "$(dirname "$0")/.." || exit 1

SRC="$1"
OUT="${2:-.scratch/qtydump/$(basename "$SRC" .c).qty.txt}"

if [ -z "$SRC" ] || [ ! -f "$SRC" ]; then
    echo "usage: scripts/qtydump.sh <candidate.c> [outfile]" >&2
    exit 1
fi

CC1=tools/agbcc/bin/agbcc_qtydump
if [ ! -x "$CC1" ]; then
    echo "error: $CC1 not built." >&2
    echo "  cd tools/agbcc/gcc" >&2
    echo "  git apply ../../../scripts/patches/agbcc-qty-dump.patch" >&2
    echo "  make normal && cp agbcc ../bin/agbcc_qtydump" >&2
    echo "  git checkout -- local-alloc.c   # keep submodule clean" >&2
    exit 1
fi

mkdir -p "$(dirname "$OUT")"
T=$(mktemp -d); trap 'rm -rf "$T"' EXIT

arm-none-eabi-cpp -nostdinc -I tools/agbcc/include -iquote include "$SRC" -o "$T/f.i"
tools/preproc/preproc "$T/f.i" charmap.txt > "$T/f.pp" 2>/dev/null \
    || cp "$T/f.i" "$T/f.pp"

AGBCC_QTY_DUMP="$OUT" "$CC1" \
    -mthumb-interwork -Wimplicit -Wparentheses -O2 -fhex-asm -fprologue-bugfix \
    -o "$T/f.s"  < "$T/f.pp"

echo "qty table -> $OUT"
cat "$OUT"
