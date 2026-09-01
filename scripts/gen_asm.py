#!/usr/bin/env python3
"""从 functions.tsv + ll.cfg + code.s 生成 asm/{matchings,nonmatchings}/<name>.s。

取代 split_asm.py。与它的三个本质区别:
  1. 主键 = addr。当前名以 ll.cfg 为准; TSV 的 name 列只是缓存,
     不一致 = 检测到改名 -> 报告, --sync 回写缓存列 (改名不再产生孤儿/失联)。
  2. 增量写: 内容不变不 touch 文件 (split_asm 全删重建 -> 每次全量重编)。
  3. 只依赖 TSV/ll.cfg/code.s, 不读 functions.yaml。

用法: gen_asm.py [--dry-run] [--sync] [--verbose]
退出码: 0 成功; 1 有错误 (缺块/重复 addr 等)。
"""
import argparse
import csv
import re
import sys
from collections import Counter

TSV = "functions.tsv"
LLCFG = "ll.cfg"
CODES = "code.s"
ASM = "asm"
HEADER = "\t.syntax unified\n"
FOOTER = "\t.syntax divided\n"
FUNC_START_RE = re.compile(r"^[ \t]*((?:thumb|arm)_func_start) (\w+)$", re.M)


def load_llcfg(path):
    addr2name = {}
    for line in open(path, encoding="utf-8", errors="replace"):
        m = re.match(r'^(?:thumb|arm)_func (0x[0-9a-fA-F]+) (\w+)', line)
        if m:
            addr2name[int(m.group(1), 16)] = m.group(2)
    return addr2name


def load_tsv(path):
    rows = []
    for r in csv.DictReader(open(path, encoding="utf-8"), delimiter="\t"):
        rows.append((int(r["status"]), r["isa"], r["module"], int(r["addr"], 16), r["name"]))
    return rows


def split_code_s(path):
    """name -> 函数块文本 (从 *_func_start 行起到下一个 *_func_start 前)。"""
    content = open(path, encoding="utf-8", errors="replace").read()
    starts = [(m.start(1), m.group(2)) for m in FUNC_START_RE.finditer(content)]
    blocks = {}
    for i, (pos, name) in enumerate(starts):
        if i + 1 < len(starts):
            end = starts[i + 1][0]
        else:
            end = len(content) - (1 if content.endswith("\n") else 0)
        blocks[name] = content[pos:end]
    return blocks


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--sync", action="store_true", help="把 ll.cfg 当前名回写进 TSV name 列")
    ap.add_argument("--verbose", action="store_true")
    args = ap.parse_args()

    addr2name = load_llcfg(LLCFG)
    rows = load_tsv(TSV)
    blocks = split_code_s(CODES)

    errors = []
    drift = []
    expected = {}
    for status, isa, module, addr, tsv_name in rows:
        name = addr2name.get(addr)
        if name is None:
            errors.append(f"addr 0x{addr:08x} 不在 ll.cfg (tsv 行: {tsv_name})")
            continue
        if name != tsv_name:
            drift.append((addr, tsv_name, name))
        folder = "matchings" if status == 1 else "nonmatchings"
        if name in expected:
            errors.append(f"重复 addr 0x{addr:08x}: {name}")
            continue
        if name not in blocks:
            errors.append(f"code.s 无函数块: {name} (0x{addr:08x})")
            continue
        expected[name] = (folder, HEADER + blocks[name] + FOOTER)

    dup_addr = [hex(a) for a, c in Counter(r[3] for r in rows).items() if c > 1]
    errors += [f"TSV 重复 addr {a}" for a in dup_addr]

    # 安全阀: 任何错误 (尤其 code.s/TSV 解析异常导致 expected 大面积缺失) 时不落盘,
    # 防止把整个 asm/ 目录清空。
    if errors:
        print("错误 (未改动 asm/):")
        for e in errors:
            print("  " + e)
        sys.exit(1)

    written = unchanged = deleted = 0
    if not args.dry_run:
        keep = {f"{folder}/{name}.s" for name, (folder, _) in expected.items()}
        for folder in ("matchings", "nonmatchings"):
            import os
            os.makedirs(f"{ASM}/{folder}", exist_ok=True)
            for fn in os.listdir(f"{ASM}/{folder}"):
                if f"{folder}/{fn}" not in keep:
                    os.remove(f"{ASM}/{folder}/{fn}")
                    deleted += 1
                    if args.verbose:
                        print(f"del  {folder}/{fn}")
        for name, (folder, text) in expected.items():
            path = f"{ASM}/{folder}/{name}.s"
            try:
                if open(path, encoding="utf-8").read() == text:
                    unchanged += 1
                    continue
            except OSError:
                pass
            with open(path, "w", encoding="utf-8") as f:
                f.write(text)
            written += 1
            if args.verbose:
                print(f"wri {folder}/{name}.s")

    if args.sync and drift and not args.dry_run:
        fix = {a: n for a, _, n in drift}
        lines = open(TSV, encoding="utf-8").read().splitlines(True)
        out = [lines[0]]
        for line in lines[1:]:
            p = line.split("\t")
            if len(p) >= 5 and int(p[3], 16) in fix:
                p[4] = fix[int(p[3], 16)]
                line = "\t".join(p)
            out.append(line)
        open(TSV, "w", encoding="utf-8").writelines(out)
        print(f"已同步 {len(drift)} 个改名进 {TSV}")

    mode = "dry-run: " if args.dry_run else ""
    print(f"{mode}目标 {len(expected)} 个 .s | 写入 {written} | 未变 {unchanged} | 删除 {deleted}")
    for addr, old, new in drift:
        print(f"drift: 0x{addr:08x} tsv='{old}' ll.cfg='{new}'" + ("  [--sync 回写]" if not args.dry_run and not args.sync else ""))
    if errors:
        print("错误:")
        for e in errors:
            print("  " + e)
        sys.exit(1)


if __name__ == "__main__":
    main()
