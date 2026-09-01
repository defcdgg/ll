#!/usr/bin/env python3
"""剩余报表: 未匹配函数清单 (make remaining, TU=xxx 过滤)。"""
import csv, os

tu = os.environ.get("TU")
rows = list(csv.DictReader(open("functions.tsv"), delimiter="\t"))
rs = [r for r in rows if r["status"] == "0" and (not tu or r["module"] == tu)]
tag = f" (TU={tu})" if tu else ""
print(f"未匹配 {len(rs)} 个{tag}")
for r in rs[:40]:
    note = "  挂起" if "挂起" in r.get("note", "") or "⏸" in r.get("note", "") else ""
    print(f'  {r["addr"]}  {r["module"]:<14} {r["name"]}{note}')
if len(rs) > 40:
    print(f"  ... 另 {len(rs)-40} 个")
