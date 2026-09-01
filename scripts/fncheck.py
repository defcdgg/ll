#!/usr/bin/env python3
"""
fncheck.py -- 多智能体协作下的"自证清白"工具

两个子命令:

  fncheck.py <func> [<func> ...]     只校验指定函数是否字节匹配。
                                     不需要整个 ROM 变绿: 直接从 build/*.o 里取出该函数的
                                     字节, 手工施加字面池重定位, 与 baserom.gba 对照,
                                     并忽略 bl/b 的相对偏移槽位 (它们依赖最终链接地址)。

  fncheck.py --blame                 整个 ROM 红了以后, 把差异字节归属到 .o / 函数,
                                     一眼看出是谁的改动造成的。

典型用法:
  make build/src/code_804F0B8.o           # 只编自己那个对象, 不碰别人的半成品
  python3 scripts/fncheck.py sub_8052C24
  -> sub_8052C24  OK  (108 bytes @0x08052C24, 5 bl slot ignored)
"""

import os
import re
import subprocess
import sys
from bisect import bisect_right

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
BUILD = os.path.join(ROOT, "build")
MAP = os.path.join(ROOT, "ll.map")
CODES = os.path.join(ROOT, "code.s")
LD = os.path.join(ROOT, "linker.ld")
BASE = os.path.join(ROOT, "baserom.gba")
ELF = os.path.join(ROOT, "ll.elf")

RELOC_CALL = {"R_ARM_CALL", "R_ARM_THM_CALL", "R_ARM_THM_XPC", "R_ARM_JUMP_SLOT"}
RELOC_ABS = {"R_ARM_ABS32", "R_ARM_ABS32_NOI"}


def die(msg):
    print("error:", msg, file=sys.stderr)
    sys.exit(1)


def run(cmd):
    r = subprocess.run(cmd, capture_output=True, text=True)
    return r.stdout


# ---------------------------------------------------------------- 符号地址表


def load_symbol_addresses():
    """symbol -> ROM address。函数以 code.s (原始反汇编) 为准 —— 它永远等于 baserom;
    ll.map 只作兜底 (布局被别人改动后 ll.map 地址会整体漂移, 不能用它做对比)。"""
    addrs = {}

    # 1) code.s: "sub_8052C24: @ 0x08052C24"  —— 权威来源, 先装
    if os.path.exists(CODES):
        with open(CODES, errors="replace") as f:
            for line in f:
                m = re.match(r"^(\w+):\s*@ 0x([0-9a-fA-F]+)\s*$", line)
                if m:
                    addrs[m.group(1)] = int(m.group(2), 16)

    # 2) linker.ld: 绝对赋值 + 段内偏移 (数据符号的权威来源)
    if os.path.exists(LD):
        mem = {}
        for m in re.finditer(r"^\s*(\w+)\s*\(.*?\)\s*:\s*ORIGIN\s*=\s*0x([0-9a-fA-F]+)",
                             open(LD, errors="replace").read(), re.M):
            mem[m.group(1)] = int(m.group(2), 16)
        text = open(LD, errors="replace").read()
        for m in re.finditer(r"^(\w+)\s*=\s*0x([0-9a-fA-F]+)\s*;", text, re.M):
            addrs.setdefault(m.group(1), int(m.group(2), 16))
        # 段内 ". = 0x00004614; gUnk_03004614 = .;" -> 按所属 MEMORY region 加基址
        cur = None
        for line in text.splitlines():
            ms = re.match(r"^\s*(\w+)\s*\(NOLOAD\)\s*:\s*ALIGN\(\d+\)\s*\{", line)
            if ms:
                cur = mem.get(ms.group(1))
                continue
            mo = re.match(r"^\s*\.\s*=\s*0x([0-9a-fA-F]+);\s*(\w+)\s*=\s*\.\s*;", line)
            if mo and cur is not None:
                addrs.setdefault(mo.group(2), cur + int(mo.group(1), 16))

    # 3) ll.map: 只做兜底。布局漂移时 ll.map 地址不可信, 不能用它覆盖 code.s/linker.ld。
    if os.path.exists(MAP):
        for line in open(MAP, errors="replace"):
            m = re.match(r"^\s+0x([0-9a-f]{8})\s+(\w+)$", line)
            if m:
                addrs.setdefault(m.group(2), int(m.group(1), 16))
    return addrs


# ---------------------------------------------------------------- 函数定位


_SYM_CACHE = {}


def _func_syms(path):
    """一个 .o 里所有 FUNC 符号: [(offset, size, name, shndx)], 按 offset 排序。带缓存。"""
    if path in _SYM_CACHE:
        return _SYM_CACHE[path]
    out = run(["arm-none-eabi-readelf", "-sW", path])
    syms = []
    for line in out.splitlines():
        p = line.split()
        if len(p) >= 8 and "FUNC" in p[3:5]:
            try:
                off = int(p[1], 16) & ~1
                size = int(p[2], 10)
                shndx = int(p[6], 10)
            except ValueError:
                continue
            syms.append((off, size, p[-1], shndx))
    syms.sort()
    _SYM_CACHE[path] = syms
    return syms


_SEC_CACHE = {}


def _section_sizes(path):
    """shndx -> 字节大小 (readelf -SW)。带缓存。"""
    if path in _SEC_CACHE:
        return _SEC_CACHE[path]
    out = run(["arm-none-eabi-readelf", "-SW", path])
    sz = {}
    for line in out.splitlines():
        # 格式: [ N] Name Type Addr Off Size ES Flg Lk Inf Al   —— 第 3 个十六进制列才是 Size
        m = re.match(r"\s*\[\s*(\d+)\]\s+\S+\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)", line)
        if m:
            sz[int(m.group(1))] = int(m.group(4), 16)
    _SEC_CACHE[path] = sz
    return sz


def find_function(func):
    """在 build/**/*.o 中找到符号 func, 返回 (obj, offset, size)。

    ⚠ asm-match 的函数由 `thumb_func_start` 宏产出, **不带 .size 属性** →
    符号表里 size == 0。旧版本用 `if size:` 直接拒掉它们, 造成对已匹配
    (但仍是 INCLUDE_ASM) 的函数误报 "NOT BUILT"。现在用同 section 内下一个
    符号的起点推长度。
    """
    for dirpath, _, files in os.walk(BUILD):
        for fn in files:
            if not fn.endswith(".o"):
                continue
            path = os.path.join(dirpath, fn)
            syms = _func_syms(path)
            for i, (off, size, name, shndx) in enumerate(syms):
                if name != func:
                    continue
                if size:
                    return path, off, size
                # size 未知: 先找同 section 里下一个 FUNC 作为右边界
                for j in range(i + 1, len(syms)):
                    n_off, _, _, n_shndx = syms[j]
                    if n_shndx != shndx:
                        continue
                    if n_off > off:
                        return path, off, n_off - off
                # 本节最后一个符号: 用节大小定长
                sec = _section_sizes(path).get(shndx)
                if sec:
                    return path, off, sec - off
                return None
    return None


def section_bytes(obj, offset, size):
    out = run(["arm-none-eabi-readelf", "-SW", obj])
    secs = []
    for line in out.splitlines():
        m = re.match(r"^\s+\[\s*\d+\]\s+(\S+)\s+\S+\s+([0-9a-f]+)\s+([0-9a-f]+)\s+([0-9a-f]+)", line)
        if m:
            secs.append((m.group(1), int(m.group(4), 16), int(m.group(3), 16)))
    with open(obj, "rb") as f:
        data = f.read()
    for name, secsize, fileoff in secs:
        if name.startswith(".text") and offset < secsize:
            return data[fileoff + offset: fileoff + offset + size]
    die("section lookup failed for %s (offset 0x%x)" % (obj, offset))


def relocs(obj):
    """返回 {字节偏移: (type, symbol)}"""
    out = run(["arm-none-eabi-objdump", "-r", obj])
    cur_sec = None
    res = {}
    for line in out.splitlines():
        ms = re.match(r"RELOCATION RECORDS FOR \[([^\]]+)\]", line)
        if ms:
            cur_sec = ms.group(1)
            continue
        if cur_sec is None or not cur_sec.startswith(".text"):
            continue
        m = re.match(r"^([0-9a-f]{4,})\s+(\S+)\s+(.*)$", line.strip())
        if m:
            try:
                res[int(m.group(1), 16)] = (m.group(2), m.group(3).split()[0])
            except ValueError:
                pass
    return res


# ---------------------------------------------------------------- 子命令


def cmd_blame():
    if not (os.path.exists(ELF) and os.path.exists(BASE)):
        die("需要 ll.elf 和 baserom.gba (先 make rom)")
    rom = open(os.path.join(ROOT, "ll.gba"), "rb").read()
    base = open(BASE, "rb").read()
    n = min(len(rom), len(base))
    bad = [i for i in range(n) if rom[i] != base[i]]
    if not bad:
        print("ROM 与 baserom 完全一致 (%d bytes)" % len(rom))
        return
    print("差异字节: %d / %d" % (len(bad), n))

    # 先判断“整体位移”: 并行开发中别人改完函数尺寸, 后面所有段会平移, 表观上几百万字节“不同”
    import collections as _c
    votes = _c.Counter()
    for probe in (0x10000, 0x100000, 0x200000, 0x400000, 0x600000, 0x7E0000):
        if probe + 256 > len(rom):
            continue
        j = base.find(rom[probe:probe + 256])
        if j >= 0 and j != probe:
            votes[j - probe] += 1
    shift = votes.most_common(1)[0][0] if votes else None
    if shift:
        moved = sum(1 for i in bad if 0 <= i + shift < n and rom[i] == base[i + shift])
        real = len(bad) - moved
        print("检测到整体位移: ll.gba 内容在 baserom 里偏移 %+d  (由 .o 尺寸变化引起)" % shift)
        print("  %d 字节是位移假差异, **真实内容差异只有 %d 字节**" % (moved, real))
        bad = [i for i in bad if 0 <= i + shift < n and rom[i] != base[i + shift]]
        print()
    if not bad:
        print("除位移外无真实差异 -> 树是“内容正确、布局漂移”, 等对方收尾即可。")
        return

    # 用 ll.map 建 地址 -> .o 区间表
    extents = []
    if os.path.exists(MAP):
        for line in open(MAP, errors="replace"):
            m = re.match(r"^\s+\.\w+\s+0x([0-9a-f]{8})\s+0x([0-9a-f]+)\s+(\S+\.o)", line)
            if m:
                extents.append((int(m.group(1), 16), int(m.group(2), 16), m.group(3)))
    extents.sort()
    starts = [e[0] for e in extents]

    import collections
    owner = collections.Counter()
    for i in bad:
        a = 0x08000000 + i
        k = bisect_right(starts, a) - 1
        o = "?"
        if k >= 0:
            s, sz, obj = extents[k]
            if a < s + sz:
                o = obj
        owner[o] += 1
    print("\n差异归属 (按 .o):")
    for o, c in owner.most_common(12):
        flag = "  <== 你的改动?" if o in sys.argv[2:] else ""
        print("  %9d  %s%s" % (c, o, flag))
    print("\n首个真实差异地址: 0x%08x" % (0x08000000 + bad[0]))
    if shift:
        print("(已扣除 %+d 位移; 要定位真因请查该地址所属函数与其之前 .o 的尺寸变化)" % shift)


def cmd_check(funcs):
    addrs = load_symbol_addresses()
    rc = 0
    for func in funcs:
        loc = find_function(func)
        if not loc:
            print("%-24s NOT FOUND  (对象里没有这个 FUNC 符号; 或它是所在 section 最后一个符号无法定长)"
                  % func)
            rc = 1
            continue
        obj, off, size = loc
        want = addrs.get(func)
        if want is None:
            print("%-24s 未知原始地址 (code.s / ll.map 里找不到)" % func)
            rc = 1
            continue
        blob = bytearray(section_bytes(obj, off, size))
        rel = {o - off: v for o, v in relocs(obj).items() if off <= o < off + size}
        call_slots = {o + k for o, (t, _) in rel.items() if t in RELOC_CALL for k in range(4)}
        skipped, patched, unresolved = 0, 0, []
        for o, (typ, sym) in rel.items():
            if o + 4 > len(blob):
                continue
            if typ in RELOC_CALL:
                skipped += 1                      # bl 偏移依赖最终布局, 跳过
                continue
            if typ in RELOC_ABS:
                a = addrs.get(sym)
                if a is None and sym.startswith("."):
                    # 段符号自引用 (如 R_ARM_ABS32 指向 .text): 最终值 = 本对象该节在 ROM 的起点。
                    # 起点直接由已知量推出: 函数 ROM 地址(code.s, 权威) - 函数在该节内的偏移。
                    # 不取 ll.map, 避开布局漂移问题。
                    a = (want - off) if sym == ".text" else None
                if a is None:
                    unresolved.append(sym)
                    continue
                # R_ARM_ABS32 是 REL 型: 加数就存在池字里 (如 &gSpriteNodePool[112]
                # 会编成 gSpriteNodePool + 0x8C0)。只写符号地址会算错, 必须加上加数。
                addend = int.from_bytes(blob[o:o + 4], "little")
                blob[o:o + 4] = ((a + addend) & 0xFFFFFFFF).to_bytes(4, "little")
                patched += 1
        base = open(BASE, "rb").read()
        seg = base[want - 0x08000000: want - 0x08000000 + len(blob)]
        diffs = [i for i in range(min(len(blob), len(seg)))
                 if blob[i] != seg[i] and i not in call_slots]
        status = "OK " if not diffs and not unresolved else "FAIL"
        if diffs or unresolved:
            rc = 1
        note = "%d bytes @0x%08x, %d 池重定位已施加, %d bl 槽忽略" % (
            len(blob), want, patched, skipped)
        if unresolved:
            note += "  未解析符号: %s" % ", ".join(sorted(set(unresolved))[:6])
        if diffs:
            note += "  差异偏移: %s" % ", ".join("+0x%x" % d for d in diffs[:12])
        print("%-24s %s  (%s)" % (func, status, note))
    return rc


def main():
    a = sys.argv[1:]
    if not a:
        print(__doc__)
        return 0
    if a[0] == "--blame":
        cmd_blame()
        return 0
    return cmd_check(a)


if __name__ == "__main__":
    sys.exit(main())
