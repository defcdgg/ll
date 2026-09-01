#!/usr/bin/env python3
"""typecov.py —— 逐函数变量类型解析 + 字段访问归属统计。

解决"按字段名全局 grep 会被多个结构体的同名字段污染"的问题。
在函数作用域内解析: 形参类型 / 局部声明 / `v = &GLOB[i]` / `v = GLOB + n` / `v = &GLOB`
/ `v = <已知指针变量>`, 再把 `v->f` `v.f` `GLOB[i].f` 归到**真实类型**。

用法: python3 scripts/typecov.py Actor SpriteNode
"""
import re, sys, glob, collections

TYPES = {}      # typedef 名 -> [(type, field, array), ...]
GLOBALS = {}    # 全局变量名 -> (类型, 是指针, 是数组)

DECL_RX = re.compile(
    r'^(?:extern\s+)?(?:struct|union)?\s*([A-Za-z_]\w*)\s*(\*?)\s*([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*;',
    re.M)

def load():
    for f in sorted(glob.glob('include/*.h')) + sorted(glob.glob('src/*.c')):
        s = re.sub(r'/\*.*?\*/', ' ', open(f).read(), flags=re.S)
        s = re.sub(r'//[^\n]*', '', s)
        for m in re.finditer(r'typedef\s+(?:struct|union)\b[^{]*\{([^{}]*)\}\s*([A-Za-z_]\w*)\s*;', s, re.S):
            body, name = m.group(1), m.group(2)
            fl = []
            for dm in re.finditer(
                    r'^\s*(?:(?:const|signed|unsigned|volatile)\s+)*([A-Za-z_]\w*)\s*(\*?)\s*'
                    r'([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*;', body, re.M):
                fl.append((dm.group(1) + dm.group(2), dm.group(3), dm.group(4) or ''))
            TYPES.setdefault(name, fl)
        for m in DECL_RX.finditer(s):
            t, star, name, arr = m.groups()
            if t in ('typedef', 'return', 'extern', 'void', 'struct', 'union', 'if', 'while', 'for'):
                continue
            GLOBALS.setdefault(name, (t, bool(star), bool(arr)))

STRIP = [(re.compile(r'/\*.*?\*/', re.S), ''), (re.compile(r'//[^\n]*'), ''),
         (re.compile(r'"(?:\\.|[^"\\])*"'), '""'), (re.compile(r"'(?:\\.|[^'\\])'"), "''")]

def strip_c(s):
    # 块注释替换成等量换行, 保证行号与原文件一致 (rename_scoped.py 依赖这一点)
    s = re.sub(r'/\*.*?\*/', lambda m: '\n' * m.group(0).count('\n'), s, flags=re.S)
    s = re.sub(r'//[^\n]*', '', s)
    s = re.sub(r'"(?:\\.|[^"\\])*"', '""', s)
    s = re.sub(r"'(?:\\.|[^'\\])'", "''", s)
    return s

FUNC_RX = re.compile(r'^([A-Za-z_]\w*\s*\**)\s+([A-Za-z_]\w*)\s*\(([^)]*)\)\s*\{', re.M | re.S)

def functions(s):
    for m in FUNC_RX.finditer(s):
        i, depth = m.end() - 1, 0
        while i < len(s):
            if s[i] == '{':
                depth += 1
            elif s[i] == '}':
                depth -= 1
                if depth == 0:
                    break
            i += 1
        yield m.group(2), m.group(3), s[m.end() - 1:i + 1], s.count('\n', 0, m.start()) + 1

def resolve(fname, params, body, line):
    vt = {}
    for p in (params.split(',') if params.strip() else []):
        m = re.match(r'^([A-Za-z_]\w*)\s*(\*?)\s*([A-Za-z_]\w*)$', p.strip())
        if m and m.group(1) in TYPES:
            vt[m.group(3)] = m.group(1)
    for m in re.finditer(r'\b([A-Za-z_]\w*)\s*(\*?)\s+([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*(?:=[^;]*)?;', body):
        if m.group(1) in TYPES:
            vt[m.group(3)] = m.group(1)
    for _ in range(3):
        for m in re.finditer(r'\b([A-Za-z_]\w*)\s*=\s*([^;]{1,90});', body):
            lhs, rhs = m.group(1), m.group(2).strip()
            if lhs in vt:
                continue
            gm = (re.match(r'^&\s*([A-Za-z_]\w*)\s*\[', rhs) or re.match(r'^([A-Za-z_]\w*)\s*\+', rhs)
                  or re.match(r'^&\s*([A-Za-z_]\w*)$', rhs) or re.match(r'^([A-Za-z_]\w*)$', rhs))
            if gm and gm.group(1) in GLOBALS and GLOBALS[gm.group(1)][0] in TYPES:
                vt[lhs] = GLOBALS[gm.group(1)][0]
                continue
            sm = re.match(r'^&\s*([A-Za-z_]\w*)$', rhs)
            if sm and sm.group(1) in vt:
                vt[lhs] = vt[sm.group(1)]
    hits = collections.defaultdict(list)
    for m in re.finditer(r'\b([A-Za-z_]\w*)\s*(?:\[[^\]]*\])?\s*(?:->|\.)\s*([A-Za-z_]\w*)', body):
        v, fld = m.group(1), m.group(2)
        if v in vt and vt[v] in TYPES:
            hits[(vt[v], fld)].append((line, fname, v))
    for m in re.finditer(r'\b([A-Za-z_]\w*)\s*\[[^\]]*\]\s*(?:->|\.)\s*([A-Za-z_]\w*)', body):
        g, fld = m.group(1), m.group(2)
        if g in GLOBALS and GLOBALS[g][0] in TYPES:
            hits[(GLOBALS[g][0], fld)].append((line, fname, g + '[]'))
    return hits

def main():
    load()
    want = sys.argv[1:] or ['Actor']
    allhits = collections.defaultdict(list)
    for f in sorted(glob.glob('src/*.c')):
        for fname, params, body, line in functions(strip_c(open(f).read())):
            for k, v in resolve(fname, params, body, line).items():
                allhits[k].extend(v)
    for ty in want:
        cnt = {fld: len(v) for (t, fld), v in allhits.items() if t == ty}
        declared = {fld for _, fld, _ in TYPES.get(ty, [])}
        print(f"\n===== {ty}: 声明 {len(declared)} 字段, 被访问 {len(cnt)} 个 =====")
        for fld, c in sorted(cnt.items(), key=lambda x: -x[1]):
            ex = allhits[(ty, fld)][0]
            fn_type = dict((f, t) for t, f, _ in TYPES.get(ty, [])).get(fld, '?')
            mark = '' if fld in declared else '   ⚠ 不属于本结构体'
            print(f"  {fld:12s} {c:3d}次  {fn_type:6s}  例 {ex[1]}@{ex[0]} via {ex[2]}{mark}")
        print(f"  从未访问: {sorted(declared - set(cnt))}")

if __name__ == '__main__':
    main()
