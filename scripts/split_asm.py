#!/usr/bin/env python3
"""DEPRECATED: 已被 scripts/gen_asm.py (functions.tsv 驱动) 取代。

保留此薄壳仅为兼容旧文档/脚本中的 `python3 scripts/split_asm.py` 调用。
functions.yaml 已删除; 台账 = functions.tsv, 生成 = gen_asm.py。
"""
import os
import sys

print("note: split_asm.py 已废弃, 转调 scripts/gen_asm.py (台账 = functions.tsv)", file=sys.stderr)
os.execv(sys.executable, [sys.executable, os.path.join(os.path.dirname(__file__), "gen_asm.py")] + sys.argv[1:])
