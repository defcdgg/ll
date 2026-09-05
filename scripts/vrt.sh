#!/bin/bash
# quick variant tester for sub_80525E8 case2 register alloc
cd "$(dirname "$0")/.."
sed -n '/switch (mode)/,/^    }/p' permuter/sub_80525E8/base.c
echo "=== dump case2 region (from 0x5e) ==="
arm-none-eabi-objdump -d .scratch/fndiff/sub_80525E8/mine.o 2>/dev/null | sed -n '/5e:/,/bx/p'