#!/usr/bin/env python3
"""从 functions.tsv 重生成 docs/reports/ (R5)。

remaining.md    未匹配清单 (按 C 文件 分组, Markdown 表格; 名称列链接到 asm 切片,
                VS Code / VSCodium 里 Ctrl+Click 直接打开; 无 note;
                行数 < SMALL(200) 的名称加 ▶ 前缀高亮;
                permuter 列链接到 permuter/&lt;fn&gt;/ 套件目录, 不存在则留空)

全量函数清单见 functions.tsv 本身 (addr/status/module/asm_lines/name/note),
不再另出 functions.csv 快照 —— 快照会滞后于 TSV, 造成口径不一致。
"""
import csv
import os
from collections import defaultdict

ASM_DIR = "asm"

os.makedirs("docs/reports", exist_ok=True)
rows = list(csv.DictReader(open("functions.tsv"), delimiter="\t"))

by_tu = defaultdict(list)
for r in rows:
    if r["status"] == "0":
        by_tu[r["module"]].append(r)

# 早期版本产出过 functions.csv / remaining.txt, 已废弃; 清掉残留避免两份口径
for stale_name in ("functions.csv", "remaining.txt"):
    stale = os.path.join("docs/reports", stale_name)
    if os.path.exists(stale):
        os.remove(stale)
        print("已删除废弃的 docs/reports/%s" % stale_name)


def slice_link(name):
    """docs/reports/remaining.md 视角下的 asm 切片相对链接; 切片缺失返回 None。"""
    for folder in ("nonmatchings", "matchings"):
        if os.path.exists(os.path.join(ASM_DIR, folder, name + ".s")):
            return "../../%s/%s/%s.s" % (ASM_DIR, folder, name)
    return None


def permuter_link(r):
    """返回 permuter 套件目录名 (未命中返回 None)。

    优先按 TSV 名称匹配, 否则回退到地址派生名 (sub_<addr 大写 hex>),
    因为套件通常在语义改名之前建立 (如 sub_80091C4)。
    """
    cands = [r["name"]]
    a = r["addr"].replace("0x", "").upper()
    if a.startswith("0"):  # sub_XXXXXXX = 地址去掉最高字节的 0 (0x080091c4 -> sub_80091C4)
        cands.append("sub_%s" % a[1:])
    for cand in cands:
        if os.path.isdir(os.path.join("permuter", cand)):
            return cand
    return None


SMALL = 200  # 行数低于它的加粗高亮 (优先攻击目标, 见 AGENTS.md §2)


def is_small(r):
    """行数列可解析为整数且低于 SMALL 阈值。"""
    try:
        return int(r["asm_lines"]) < SMALL
    except (TypeError, ValueError):
        return False


with open("docs/reports/remaining.md", "w", encoding="utf-8") as f:
    f.write("# 未匹配 %d 个\n" % sum(len(v) for v in by_tu.values()))
    f.write("\n(▶ = 行数 < %d, 优先目标)\n" % SMALL)
    for tu in sorted(by_tu):
        f.write("\n## %s (%d)\n\n" % (tu, len(by_tu[tu])))
        f.write("| addr | 行数 | 名称 | permuter |\n|---|---:|---|---|\n")
        for r in by_tu[tu]:
            link = slice_link(r["name"])
            cell = "[%s](%s)" % (r["name"], link) if link else r["name"]
            if is_small(r):
                cell = "▶ **%s**" % cell
            pd = permuter_link(r)
            pcell = "[permuter/%s/](../../permuter/%s/)" % (pd, pd) if pd else ""
            f.write("| %s | %5s | %s | %s |\n"
                    % (r["addr"], r.get("asm_lines", "?"), cell, pcell))
print("docs/reports/remaining.md 已生成")
