#!/usr/bin/env python3
"""从 src/*.c + ll.cfg 生成 functions.tsv (重构 R1)。

状态权威 = 源码本身 (functions.yaml 已删除, 本 TSV 即唯一函数清单):
  - `INCLUDE_ASM("asm/nonmatchings", name)`  -> status 0
  - `INCLUDE_ASM("asm/matchings", name)`    -> status 1 (asm 占位)
  - src 里真 C 定义 (列0 签名 + `{`)        -> status 1 (真 C)
  - 名字经 include/*.h 的 `#define 语义名 sub_XXX` 别名解析回 ll.cfg 名

列序 (制表符, 首行表头, 按 addr 升序):
  status	isa	module	addr	asm_lines	name	note
  module = C 文件 (src/<module>.c)
  asm_lines = asm/{matchings,nonmatchings}/<name>.s 的行数 (切片缺失时 0; code.s 变更后需重跑)
  note = 完成/挂起明细 (一行, 无制表符; 重新生成时按 addr 保留)
"""
import csv
import os
import re
import sys

LLCFG = "ll.cfg"
SRC_DIR = "src"
INCLUDE_DIR = "include"
ASM_DIR = "asm"
OUT = "functions.tsv"

FUNC_START = re.compile(r'^(?:thumb|arm)_func ')
INCLUDE_ASM_RE = re.compile(r'INCLUDE_ASM\("asm/(matchings|nonmatchings)",\s*(\w+)\)')
ALIAS_RE = re.compile(r'^#define\s+(\w+)\s+(\w+)\s*$')
DEF_START_RE = re.compile(r'^[A-Za-z_][A-Za-z_0-9 *]*?\b([A-Za-z_][A-Za-z_0-9]*)\s*\(')
SLOT_MACRO_RE = re.compile(r'^DEFINE_RANDOM_SLOT_FUNC_(?:16|24)\((\w+)\)')
SKIP_PREFIX = ("static", "extern", "typedef", "#", "asm(", "}", "{", "INCLUDE_ASM", "return")

# 预编译库源: 函数在 ll.cfg 有名字 (gbadisasm 需要), 但不参与反编译拆分, 不进 TSV
LIB_TUS = {"m4a", "agb_sram"}


def load_llcfg(path):
    info = {}
    for line in open(path, encoding="utf-8", errors="replace"):
        m = re.match(r'^(thumb|arm)_func (0x[0-9a-fA-F]+) (\w+)', line)
        if m:
            info[m.group(3)] = (int(m.group(2), 16), m.group(1))
    return info


def strip_comments(text):
    text = re.sub(r'/\*.*?\*/', lambda m: re.sub(r'[^\n]', ' ', m.group(0)), text, flags=re.S)
    return re.sub(r'//[^\n]*', '', text)


def load_aliases(llc, files):
    alias = {}
    for f in files:
        for line in open(f, encoding="utf-8", errors="replace"):
            m = ALIAS_RE.match(line)
            if m and m.group(2) in llc and m.group(1) not in llc:
                alias[m.group(1)] = m.group(2)
    return alias


def scan_definitions(text):
    """返回 {ll.cfg名: True} —— 该文件里真 C 定义的函数 (名字已解析别名)。"""
    found = set()
    lines = text.split("\n")
    i = 0
    while i < len(lines):
        line = lines[i]
        if line and line[0] not in " \t#{};":
            m = SLOT_MACRO_RE.match(line)
            if m:
                found.add(m.group(1))
                i += 1
                continue
            if line.startswith(SKIP_PREFIX):
                i += 1
                continue
            m = DEF_START_RE.match(line)
            if m:
                name = m.group(1)
                j = i
                found_def = False
                while j < len(lines):
                    cur = lines[j]
                    if "{" in cur:
                        found.add(name)
                        found_def = True
                        break
                    if cur.rstrip().endswith(";") and ")" in cur:
                        break
                    if j > i and DEF_START_RE.match(cur) and not cur.startswith(SKIP_PREFIX):
                        break
                    j += 1
                i = j + 1 if (found_def or j == i) else j
                continue
        i += 1
    return found


def asm_slice_lines(name, status):
    """asm 切片**主体**行数: 去掉 3 行头 (\t.syntax unified / thumb_func_start / 标签@地址)
    与尾部空行 + \t\t.syntax divided, 以及紧贴主体的尾部 "\t.align 2, 0"。
    主体内部的 .align 与字面池 .4byte 行仍计入 (多段池的函数 .align 会出现在池前)。
    目录与 status 不符时 (坑7: status 与切片落点漂移) 回退另一目录; 两处都没有返回 0。"""
    folders = ("matchings", "nonmatchings") if status == 1 else ("nonmatchings", "matchings")
    for folder in folders:
        p = os.path.join(ASM_DIR, folder, name + ".s")
        if not os.path.exists(p):
            continue
        L = open(p, encoding="utf-8", errors="replace").read().splitlines()
        end = len(L) - 2
        if end > 3 and L[end - 1].startswith("\t.align"):
            end -= 1
        return max(end - 3, 0)
    return 0


def main():
    llc = load_llcfg(LLCFG)
    src_files = sorted(
        os.path.join(SRC_DIR, f) for f in os.listdir(SRC_DIR) if f.endswith(".c")
    )
    hdr_files = sorted(
        os.path.join(INCLUDE_DIR, f) for f in os.listdir(INCLUDE_DIR) if f.endswith(".h")
    )
    alias = load_aliases(llc, src_files + hdr_files)

    rows = {}
    errors = []
    for path in src_files:
        tu = os.path.basename(path)[:-2]
        if tu in LIB_TUS:
            continue
        text = strip_comments(open(path, encoding="utf-8", errors="replace").read())
        for folder, name in INCLUDE_ASM_RE.findall(text):
            real = alias.get(name, name)
            if real not in llc:
                errors.append(f"{tu}: INCLUDE_ASM name not in ll.cfg: {name}")
                continue
            status = 1 if folder == "matchings" else 0
            if real in rows and rows[real][0] != status:
                errors.append(f"{tu}: conflicting status for {real}")
            rows[real] = (status, tu)
        for name in scan_definitions(text):
            real = alias.get(name, name)
            if real not in llc:
                continue
            if real in rows and rows[real][1] != "lib" and rows[real][0] == 0:
                errors.append(f"{tu}: {real} 既有 INCLUDE_ASM(nonmatchings) 又有真 C 定义")
            prev = rows.get(real)
            if prev and prev[0] == 1 and prev[1] != tu:
                errors.append(f"{tu}: {real} 在 {prev[1]} 和 {tu} 重复定义")
            rows[real] = (1, tu)

    out_rows = []
    old_note = {}
    if os.path.exists(OUT):
        for r in csv.DictReader(open(OUT, encoding="utf-8"), delimiter="\t"):
            try:
                old_note[int(r["addr"], 16)] = (r.get("note", "") or "").rstrip("\n")
            except (KeyError, ValueError):
                pass
    for name, (status, tu) in rows.items():
        addr, isa = llc[name]
        out_rows.append((status, isa, addr, name, tu, old_note.get(addr, "")))
    out_rows.sort(key=lambda r: r[2])
    seen = {}
    for r in out_rows:
        if r[2] in seen:
            errors.append(f"dup addr 0x{r[2]:08x}: {r[3]} vs {seen[r[2]]}")
        seen[r[2]] = r[3]

    with open(OUT, "w", encoding="utf-8") as f:
        f.write("status\tisa\tmodule\taddr\tasm_lines\tname\tnote\n")
        for status, isa, addr, name, tu, note in out_rows:
            f.write(f"{status}\t{isa}\t{tu}\t0x{addr:08x}\t{asm_slice_lines(name, status)}\t{name}\t{note}\n")

    n1 = sum(1 for r in out_rows if r[0] == 1)
    print(f"{OUT}: {len(out_rows)} 行 (status1={n1} status0={len(out_rows)-n1})")
    if errors:
        print("错误:")
        for e in errors[:40]:
            print("  " + e)
        sys.exit(1)


if __name__ == "__main__":
    main()
