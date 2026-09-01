#!/usr/bin/env python3
"""rename_scoped.py —— 按【真实类型】限定地重命名结构体字段。

只改"变量类型解析后确认属于目标结构体"的那些访问点, 不碰其它结构体的同名字段。
用法: python3 scripts/rename_scoped.py Actor '{"旧名":"新名", ...}' [--apply]
"""
import re, sys, glob, collections
sys.path.insert(0, 'scripts')
import typecov as T

TARGET = sys.argv[1] if len(sys.argv) > 1 else 'Actor'
MAP = __import__('json').loads(sys.argv[2]) if len(sys.argv) > 2 else {}
APPLY = '--apply' in sys.argv

VAR_RX = re.compile(r'([A-Za-z_]\w*)\s*(->|\.)\s*([A-Za-z_]\w*)')
GLOB_RX = re.compile(r'\b(gActors|gUnk_03001EE0|gEffectActor|gDialogArrowActors)'
                     r'\s*(?:\[[^\]]*\])?\s*(->|\.)\s*([A-Za-z_]\w*)')

def strip_keep_lines(s):
    s = re.sub(r'/\*.*?\*/', lambda m: '\n' * m.group(0).count('\n'), s, flags=re.S)
    return re.sub(r'//[^\n]*', '', s)

def actor_vars(fname, params, body):
    vt = {}
    for p in (params.split(',') if params.strip() else []):
        m = re.match(r'^([A-Za-z_]\w*)\s*(\*?)\s*([A-Za-z_]\w*)$', p.strip())
        if m and m.group(1) in T.TYPES:
            vt[m.group(3)] = m.group(1)
    for m in re.finditer(r'\b([A-Za-z_]\w*)\s*(\*?)\s+([A-Za-z_]\w*)\s*(\[[^\]]*\])?\s*(?:=[^;]*)?;', body):
        if m.group(1) in T.TYPES:
            vt[m.group(3)] = m.group(1)
    for _ in range(3):
        for m in re.finditer(r'\b([A-Za-z_]\w*)\s*=\s*([^;]{1,90});', body):
            lhs, rhs = m.group(1), m.group(2).strip()
            if lhs in vt:
                continue
            gm = (re.match(r'^&\s*([A-Za-z_]\w*)\s*\[', rhs) or re.match(r'^([A-Za-z_]\w*)\s*\+', rhs)
                  or re.match(r'^&\s*([A-Za-z_]\w*)$', rhs) or re.match(r'^([A-Za-z_]\w*)$', rhs))
            if gm and gm.group(1) in T.GLOBALS and T.GLOBALS[gm.group(1)][0] in T.TYPES:
                vt[lhs] = T.GLOBALS[gm.group(1)][0]
    return {k for k, v in vt.items() if v == TARGET}

def main():
    T.load()
    # (file, lineno, col_start, col_end, old, new)
    edits = []
    for f in sorted(glob.glob('src/*.c')):
        raw = open(f).read().split('\n')
        clean = strip_keep_lines('\n'.join(raw)).split('\n')
        s = T.strip_c(open(f).read())
        for fname, params, body, line in T.functions(s):
            vars_ = actor_vars(fname, params, body)
            end = min(line + len(body.split('\n')) + 1, len(raw) + 1)
            for i in range(line, end):
                if i - 1 >= len(clean) or not clean[i - 1].strip():
                    continue          # 注释块内的行 -> clean 里为空, 跳过
                code = clean[i - 1]
                for m in VAR_RX.finditer(code):
                    v, _, fld = m.group(1), m.group(2), m.group(3)
                    if v in vars_ and fld in MAP:
                        edits.append((f, i, m.start(3), m.end(3), fld, MAP[fld]))
                for m in GLOB_RX.finditer(code):
                    fld = m.group(3)
                    if fld in MAP:
                        edits.append((f, i, m.start(3), m.end(3), fld, MAP[fld]))
    byfile = collections.defaultdict(list)
    for f, ln, a, b, o, n in edits:
        byfile[f].append((ln, a, b, o, n))
    total = 0
    for f, lst in sorted(byfile.items()):
        raw = open(f).read().split('\n')
        for ln, a, b, o, n in sorted(lst, key=lambda x: (x[0], -x[1])):
            line = raw[ln - 1]
            raw[ln - 1] = line[:a] + n + line[b:]
            total += 1
        if APPLY:
            open(f, 'w').write('\n'.join(raw))
        for ln, a, b, o, n in lst:
            print(f"  {f}:{ln}  {o} -> {n}")
    print(f"\n{'已应用' if APPLY else '试运行'}: {total} 处, 涉及 {len(byfile)} 个文件")

if __name__ == '__main__':
    main()
