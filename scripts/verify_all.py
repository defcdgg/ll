#!/usr/bin/env python3
"""status=1 全量字节核验 (make verify 的第三步)。"""
import csv, subprocess, sys

rows = list(csv.DictReader(open("functions.tsv"), delimiter="\t"))
fns = [r["name"] for r in rows if r["status"] == "1"]
print(f"fncheck 扫描 {len(fns)} 个已匹配函数...")
sys.exit(subprocess.run(["python3", "scripts/fncheck.py"] + fns).returncode)
