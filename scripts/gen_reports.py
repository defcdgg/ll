#!/usr/bin/env python3
"""从 functions.tsv + code.s 重生成 docs/reports/ (R5)。

functions.csv      addr,status,kind,module,name,size(ROM 字节)
remaining.txt      未匹配清单 (按 TU 分组, 含挂起标记)
"""
import csv, os, re

os.makedirs("docs/reports", exist_ok=True)
rows = list(csv.DictReader(open("functions.tsv"), delimiter="\t"))

# ROM 函数尺寸: 从 code.s 边界推
code = open("code.s").read()
pat = re.findall(r"thumb_func_start (\w+)\n\w+: @ (0x08[0-9a-fA-F]+)", code)
lst = sorted(set((int(a, 16), n) for n, a in pat))
size = {}
for i, (a, n) in enumerate(lst):
    nxt = lst[i + 1][0] if i + 1 < len(lst) else 0x0805769C
    size[n] = nxt - a

with open("docs/reports/functions.csv", "w", newline="") as f:
    w = csv.writer(f)
    w.writerow(["addr", "status", "kind", "module", "name", "rom_size"])
    for r in rows:
        w.writerow([r["addr"], r["status"], r.get("kind",""), r["module"], r["name"],
                    size.get(r["name"], "")])

from collections import defaultdict
by_tu = defaultdict(list)
for r in rows:
    if r["status"] == "0":
        by_tu[r["module"]].append(r)
with open("docs/reports/remaining.txt", "w") as f:
    f.write(f"未匹配 {sum(len(v) for v in by_tu.values())} 个\n")
    for tu in sorted(by_tu):
        f.write(f"\n[{tu}] {len(by_tu[tu])}\n")
        for r in by_tu[tu]:
            pend = "  ⏸ " + r["note"][:60] if "⏸" in r.get("note", "") else ""
            f.write(f'  {r["addr"]}  {r["name"]}{pend}\n')
print("docs/reports/{functions.csv,remaining.txt} 已生成")
