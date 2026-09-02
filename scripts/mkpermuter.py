#!/usr/bin/env python3
"""一键创建 permuter 套件: permuter/<fn>/ 从 .s 与 src 里的真 C 函数复制脚手架。

用法:
    scripts/mkpermuter.py <函数名或0x地址>      # 单个函数
    scripts/mkpermuter.py sub_804D1B4
    scripts/mkpermuter.py 0x0804D1B4
    scripts/mkpermuter.py SoundMain_Frame

对目标函数:
  1) 解析 addr (ll.cfg, 含 include/*.h 的 #define 语义名别名) → functions.tsv 找 module/src 文件。
  2) 在 src 里定位真 C 函数定义 (INCLUDE_ASM 占位无 C 体 → 跳过并提示)。
  3) 复制 asm/nonmatchings|matchings/<fn>.s → permuter/<fn>/target.s 并汇编出 target.o。
  4) 把 C 函数体原样拷成 permuter/<fn>/base.c (种子; 需手动补 typedef/extern, 禁 #include)。
  5) 配 compile.sh + settings.toml。

base.c 仅为种子: permuter 用系统 cpp -nostdinc, 不能 include 项目头文件; 函数体里用到的
u8/u16/... 与本 TU extern/结构体都要在 base.c 顶部自行内联 (见 AGENTS.md §2b / RULES 规则96)。
"""
import re
import sys
import os
import glob
import subprocess

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))


def die(msg):
    sys.stderr.write("mkpermuter: %s\n" % msg)
    sys.exit(1)


def load_name_addr():
    """返回 {name: addr} 与 {addr: name}, 含 #define 别名解析。"""
    name2addr, addr2name = {}, {}
    cfg = os.path.join(ROOT, "ll.cfg")
    for line in open(cfg, errors="replace"):
        m = re.match(r'^(?:thumb|arm)_func\s+(0x[0-9A-Fa-f]+)\s+(\S+)', line)
        if m:
            a = int(m.group(1), 16)
            name2addr[m.group(2)] = a
            addr2name[a] = m.group(2)
    for h in glob.glob(os.path.join(ROOT, "include", "*.h")):
        for line in open(h, errors="replace"):
            m = re.match(r'#define\s+(\w+)\s+(\w+)\s*$', line)
            if m and m.group(2) in name2addr and m.group(1) not in name2addr:
                name2addr[m.group(1)] = name2addr[m.group(2)]
    return name2addr, addr2name


def module_of(addr):
    for line in open(os.path.join(ROOT, "functions.tsv"), errors="replace"):
        p = line.rstrip("\n").split("\t")
        if len(p) >= 5 and p[0] in ("0", "1"):
            try:
                if int(p[3], 16) == addr:
                    return p[2]
            except ValueError:
                pass
    return None


FUNC_RE = re.compile(
    r'^(?:[A-Za-z_][A-Za-z0-9_ *]*?)([A-Za-z_][A-Za-z0-9_]*)\s*\(')
KAND_R = re.compile(r'^[A-Za-z_][A-Za-z0-9_ ]+\s+[*]?[A-Za-z_]\w*\s*;\s*$')


def find_def(text_lines, want_addr, name2addr):
    """在 TU 文本里找 addr 对应的真 C 定义起始行(0 基)。返回 (def_start, canonical_name) 或 None。
    INCLUDE_ASM 占位或别名不存在时返回 None。"""
    n = len(text_lines)
    for i in range(n):
        s = text_lines[i].strip()
        if not s or s.startswith(('//', '/*', '*', '#', ' ', '\t')):
            continue
        fm = FUNC_RE.match(text_lines[i])
        if not fm:
            continue
        nm = fm.group(1)
        if name2addr.get(nm) != want_addr:
            continue
        # 校验是定义: 形参闭合后跟 '{' (可跨 K&R 声明行), 中途无顶层 ';'
        depth = 0
        j = i
        opened = False
        while j < n:
            seg = text_lines[j]
            if j == i:
                k0 = seg.find('(')
                if k0 < 0:
                    break
                seg = seg[k0:]
            for ch in seg:
                if ch == '(':
                    depth += 1
                    opened = True
                elif ch == ')':
                    depth -= 1
                    if opened and depth == 0:
                        tail = seg[seg.index(')') + 1:]
                        if ';' in tail:
                            return None
                        if '{' in tail:
                            return i, nm
                        # K&R: 声明行后跟 '{'
                        jj = j + 1
                        while jj < n:
                            t = text_lines[jj].strip()
                            if t == '':
                                jj += 1
                                continue
                            if t.startswith('{'):
                                return i, nm
                            if KAND_R.match(t):
                                jj += 1
                                continue
                            return None
                        return None
            j += 1
        # 未在单行闭合: 形参跨行, 继续看是否到 '{'
        # (罕见, 让 fncheck/手工处理; 简单兜底: 往后找非空 '{')
    return None


def extract_body(text_lines, start, nm):
    """从定义行 start 抓取直到配对的函数体 '}' (注释/字符串感知)。返回含换行的文本。"""
    n = len(text_lines)
    depth = 0
    body_open = False
    out = []
    i = start
    while i < n:
        line = text_lines[i]
        out.append(line)
        depth += count_braces(line)
        if '{' in line:
            body_open = True
        if body_open and depth == 0:
            break
        i += 1
    return ''.join(out)


def count_braces(line):
    """粗略统计顶层 { 与 } (跳过注释与字符串)。够用于函数体配平。"""
    cnt = 0
    i = 0
    n = len(line)
    while i < n:
        c = line[i]
        if c == '/' and i + 1 < n and line[i + 1] == '/':
            break
        if c == '/' and i + 1 < n and line[i + 1] == '*':
            j = line.find('*/', i + 2)
            i = n if j < 0 else j + 2
            continue
        if c == '"':
            j = i + 1
            while j < n and line[j] != '"':
                if line[j] == '\\':
                    j += 1
                j += 1
            i = j + 1
            continue
        if c == "'":
            j = i + 1
            while j < n and line[j] != "'":
                if line[j] == '\\':
                    j += 1
                j += 1
            i = j + 1
            continue
        if c == '{':
            cnt += 1
        elif c == '}':
            cnt -= 1
        i += 1
    return cnt


COMPILE_SH = r'''#!/bin/bash
cd "$(dirname "$0")/../.." || exit 1
T=$(mktemp -d); trap 'rm -rf "$T"' EXIT
arm-none-eabi-cpp -nostdinc -I tools/agbcc/include -iquote include "$1" -o "$T/f.i" || exit 1
tools/preproc/preproc "$T/f.i" | tools/agbcc/bin/agbcc -mthumb-interwork -Wimplicit -Wparentheses -O2 -fhex-asm -fprologue-bugfix -o "$T/f.s" || exit 1
printf ".text\n\t.align\t2, 0\n" >> "$T/f.s"
arm-none-eabi-as -mcpu=arm7tdmi -mthumb-interwork -I sound -o "$3" "$T/f.s" || exit 1
'''


def main():
    if len(sys.argv) != 2:
        die("用法: mkpermuter.py <函数名或0x地址>")
    arg = sys.argv[1]
    name2addr, addr2name = load_name_addr()
    m = re.match(r'^0x([0-9A-Fa-f]+)$', arg)
    if m:
        addr = int(m.group(1), 16)
        nm = addr2name.get(addr)
        if nm is None:
            die("地址 0x%X 不在 ll.cfg (或已改名, 用现名再试)" % addr)
    else:
        if arg not in name2addr:
            die("找不到 %r (ll.cfg / include/*.h #define 别名均无)" % arg)
        addr = name2addr[arg]
        nm = addr2name.get(addr, arg)
    mod = module_of(addr)
    if not mod:
        die("functions.tsv 里没有 module 归属 (0x%X)" % addr)
    src = os.path.join(ROOT, "src", mod + ".c")
    if not os.path.isfile(src):
        die("src 文件不存在: %s" % src)
    lines = open(src, errors="replace").read().splitlines(keepends=True)
    hit = find_def(lines, addr, name2addr)
    if hit is None:
        # 是 INCLUDE_ASM 占位?
        has_inc = any('INCLUDE_ASM' in l and nm in l for l in lines)
        die("函数 %s 在 %s 里%s; INCLUDE_ASM 占位 (无 C 体) 或定义形态不支持。"
            % (nm, src, " 仍是 INCLUDE_ASM," if has_inc else "没有找到真 C 定义,"))
    start, canon = hit
    body = extract_body(lines, start, canon)

    # canon = src 定义里的标识符 (base.c 原样输出它); 若与 ll.cfg 名不同则为 #define 别名情形
    cfgname = nm
    if canon != cfgname:
        print("注: src 定义名 %s != ll.cfg 规范名 %s (#define 别名情形)" % (canon, cfgname))

    d = os.path.join(ROOT, "permuter", canon)
    os.makedirs(d, exist_ok=True)
    # 1) .s 参考: 先按 src 名找, 别名情形回退 ll.cfg 规范名
    ref = None
    for cand in (os.path.join(ROOT, "asm", "nonmatchings", canon + ".s"),
                 os.path.join(ROOT, "asm", "matchings", canon + ".s"),
                 os.path.join(ROOT, "asm", "nonmatchings", cfgname + ".s"),
                 os.path.join(ROOT, "asm", "matchings", cfgname + ".s")):
        if os.path.isfile(cand):
            ref = cand
            break
    if ref:
        tgt = os.path.join(d, "target.s")
        with open(tgt, "w") as f:
            f.write('\t.include "macros/function.inc"\n')
            f.write(open(ref, errors="replace").read())
        r = subprocess.run(["arm-none-eabi-as", "-mcpu=arm7tdmi",
                            "-mthumb-interwork", "-I", os.path.join(ROOT, "asm"),
                            "-o", os.path.join(d, "target.o"), tgt],
                           capture_output=True, text=True)
        if r.returncode != 0:
            sys.stderr.write("汇编 target.o 失败 (可忽略, fndiff.sh 会重建): %s\n" % r.stderr.strip())
    else:
        print("警告: 无 asm/{non,}matchings/%s.s, 稍后请用 fndiff.sh 自动生成参考。" % canon)
    # 2) base.c 种子
    header = ("// auto seed: 从 %s 原样拷入的函数体 (addr 0x%X).\n"
              "// permuter 用 -nostdinc, 禁 #include; 需在下方函数前补:\n"
              "//   typedef (u8/u16/u32/s8/s16/s32/int) 与本函数用到的 extern/结构体内联。\n\n"
              % (os.path.relpath(src, ROOT), addr))
    with open(os.path.join(d, "base.c"), "w") as f:
        f.write(header + body)
        if not body.endswith("\n"):
            f.write("\n")
    # 3) compile.sh
    with open(os.path.join(d, "compile.sh"), "w") as f:
        f.write(COMPILE_SH)
    os.chmod(os.path.join(d, "compile.sh"), 0o755)
    # 4) settings.toml
    with open(os.path.join(d, "settings.toml"), "w") as f:
        f.write('func_name = "%s"\ncompiler_type = "gcc"\n' % canon)
    if canon != cfgname:
        print("   ⚠ 别名函数: base.c 函数名是 %s, 而 target 符号是 %s;\n"
              "     跑 permuter 前请把 base.c 的函数名改成 %s 或调整 settings.func_name。" % (canon, cfgname, cfgname))
    print("已创建 permuter/%s/  (%s @ 0x%X, src/%s.c)" % (canon, canon, addr, mod))
    print("  base.c      函数体种子 (补 typedef/extern 后即可跑)")
    print("  compile.sh  fndiff 用编译脚本 (与 Makefile 同 flag)")
    print("  settings.toml")
    print("  target.s/o  参考 (来自 %s)" % (os.path.relpath(ref, ROOT) if ref else "缺失"))
    print("下一步: cd permuter/%s && ../../.venv/bin/python ../../tools/decomp-permuter/permuter.py . -j 1" % canon)


if __name__ == "__main__":
    main()
