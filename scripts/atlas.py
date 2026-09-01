#!/usr/bin/env python3
"""
atlas.py -- 全 ROM 函数图谱 + 连续模块边界划分 (定稿版)

## 硬约束
linker.ld 里 .text 按 .o 顺序摆放 => **模块必须是按原始顺序的连续函数区间**。
不重排任何函数。

## 为什么不用无约束聚类 / min-cut
- 社区发现会塌成一个巨簇 (实测 1028/1063) —— 游戏调用图是稠密连通的
- min-cut 目标退化: 一整段 = 零切割 = 最优
- 区间模块度也不敏感 (K 卡在 11, 切点全被 maxlen 顶住)

## 本方法
1) 亲和边 (5 路信号, 全部 IDF 加权 + 距离衰减 + 剔除 hub):
   A 调用边                w=1.0
   B 共享数据符号          w=0.8/log2(2+df)
   C 同构家族(助记符序列)  w=2.0
   D 参数化家族(常量抽象)  w=1.2
   E **同属一张调度表**    w=4.0   <-- ROM 自己写在地面上的真值
2) 目标函数 = 电导率型 (不退化):
       max Σ_S [ intra(S)/vol(S) · sqrt(|S|) ] − λ·#段
   单段时 intra/vol=0.5; 两个完美分离的模块 = 1.0+1.0
3) 单遍 DP, 回溯窗口 [min_funcs, max_funcs] -> O(n·maxlen)
4) 扫 λ 给肘部曲线; 每个切点的两个原始信号值写进报告, 人工可逐个推翻

## 产出
  .scratch/atlas.json     全量图谱
  modules.draft.yaml      模块边界提案 (人审后升级为 modules.yaml)
  docs/ATLAS.md           报告

用法: python3 scripts/atlas.py [--lam 0.30] [--min-funcs 8] [--max-funcs 90]
"""
import argparse, bisect, glob, hashlib, json, math, os, re, struct
from collections import Counter, defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)

INSN_RE = re.compile(r"^\t([a-z][a-z0-9.]*)\s*(.*)$")
BL_RE = re.compile(r"^\s*(?:bl|bx)\s+([\w$]+)")
POOL_LBL_RE = re.compile(r",\s*(_(?:08)?[0-9A-Fa-f]{6,8})\b")
DOT4_RE = re.compile(r"^_\w+:\s*\.4byte\s+(0x[0-9A-Fa-f]+)")
LABEL_RE = re.compile(r"^([\w$]+):\s*@ (0x[0-9A-Fa-f]+)")
NUM_RE = re.compile(r"0x[0-9a-fA-F]+|\d+")
HUB_CUT = 25
MAX_FAN = 60
CODE_LO, CODE_HI = 0x08000000, 0x08054000


# ------------------------------------------------------------------ 解析

def load_semantic_names(funcs):
    """语义锦点 = 已知真名。三个来源:
      1) ll.cfg 里不是 sub_/nullsub_ 的名字 (194 个, 多在 m4a 区)
      2) docs/progress.md 里的 `sub_XXX → RealName` 记录
      3) src/*.c 里的 `#define RealName sub_XXX` 别名
    """
    out = {}
    for addr, nm in load_llcfg().items():
        if not nm.startswith(("sub_", "nullsub_", "_")):
            out[nm] = addr
    if os.path.exists("docs/progress.md"):
        txt = open("docs/progress.md", errors="replace").read()
        for sub, real in re.findall(r"(sub_[0-9A-F]{7})\s*→\s*\*{0,2}([A-Za-z_]\w{3,})", txt):
            if sub in funcs:
                out.setdefault(real, funcs[sub]["addr"])
    for f in glob.glob("src/*.c"):
        for real, sub in re.findall(r"#define\s+([A-Za-z_]\w+)\s+(sub_[0-9A-F]{7})\b",
                                    open(f, errors="replace").read()):
            if sub in funcs:
                out.setdefault(real, funcs[sub]["addr"])
    return out


def load_llcfg():
    out = {}
    for line in open("ll.cfg", errors="replace"):
        m = re.match(r"^(thumb|arm)_func\s+(0x[0-9a-fA-F]+)\s+([\w$]+)", line)
        if m:
            out[int(m.group(2), 16)] = m.group(3)
    return out


def load_yaml():
    """{name: (module, status)} from functions.tsv"""
    import csv
    st = {}
    with open("functions.tsv", errors="replace") as f:
        for r in csv.DictReader(f, delimiter="\t"):
            st[r["name"]] = (r["module"], int(r["status"]))
    return st


def parse_func(path):
    mnem, calls, plabels, poolvals, addr = [], [], [], {}, None
    for line in open(path, errors="replace"):
        if addr is None:
            m = LABEL_RE.match(line)
            if m:
                addr = int(m.group(2), 16)
            continue
        s = line.strip()
        m = DOT4_RE.match(s)
        if m:
            poolvals[s.split(":")[0]] = int(m.group(1), 16)
            continue
        m = INSN_RE.match(line)
        if not m:
            continue
        mnem.append(m.group(1) + " " + NUM_RE.sub("#", m.group(2)))
        mm = BL_RE.match(line)
        if mm:
            calls.append(mm.group(1))
        else:
            mm = POOL_LBL_RE.search(line)
            if mm:
                plabels.append(mm.group(1))
    return addr, mnem, calls, [poolvals[p] for p in plabels if p in poolvals]


def sig_exact(mnem):
    return hashlib.sha1(" ".join(m.split()[0] for m in mnem).encode()).hexdigest()[:12]


def sig_shape(mnem):
    return hashlib.sha1(" ".join(mnem).encode()).hexdigest()[:12]


# ------------------------------------------------------------------ 调度表

def handler_tables(names_at):
    """扫 ROM 找函数指针数组, 区分编译器跳转表与真正的调度表。
    跳转表: 所有目标落在同一个函数内。调度表: 目标跨 >=3 个函数。"""
    rom = open("baserom.gba", "rb").read()
    addrs = sorted(names_at)
    tabs, i = [], 0
    while i + 16 <= len(rom):
        v = struct.unpack_from("<I", rom, i)[0]
        if CODE_LO <= (v & ~1) < CODE_HI:
            j, t = i, []
            while j + 4 <= len(rom):
                w = struct.unpack_from("<I", rom, j)[0]
                if not (CODE_LO <= (w & ~1) < CODE_HI):
                    break
                t.append(w & ~1)
                j += 4
            if len(t) >= 4:
                ea = 0x08000000 + i
                f_of = lambda a: names_at[addrs[bisect.bisect_right(addrs, a) - 1]] \
                    if a >= addrs[0] else None
                tgt = sorted({f_of(x) for x in t} - {None},
                             key=lambda nm: funcs_by_addr_order.get(nm, 1 << 40))
                own = f_of(ea)
                if len(tgt) >= 3 and not (len(tgt) == 1 and tgt[0] == own):
                    tabs.append({"table": ea, "n": len(t), "funcs": tgt})
                i = j
                continue
        i += 4
    tabs.sort(key=lambda x: -len(x["funcs"]))
    return tabs


# ------------------------------------------------------------------ 划分

def build_stats(nodes, edges, decay):
    idx = {v: i for i, v in enumerate(nodes)}
    n = len(nodes)
    fwd = defaultdict(lambda: defaultdict(float))
    vol = [0.0] * n
    m = 0.0
    for u, v, w in edges:
        iu, iv = idx.get(u), idx.get(v)
        if iu is None or iv is None or iu == iv:
            continue
        a, b = (iu, iv) if iu < iv else (iv, iu)
        wd = w / (1.0 + (b - a) / decay) if decay else w
        fwd[a][b] += wd
        vol[a] += wd
        vol[b] += wd
        m += wd
    rows = []
    for i in range(n):
        cum, acc = [], 0.0
        for j, w in sorted(fwd[i].items()):
            acc += w
            cum.append((j, acc))
        rows.append(cum)
    VP = [0.0] * (n + 1)
    for i in range(n):
        VP[i + 1] = VP[i] + vol[i]
    return n, rows, VP, m


def rowsum(rows, a, b):
    acc = 0.0
    for j, c in rows[a]:
        if j >= b:
            break
        acc = c
    return acc


def dp_segment(n, rows, VP, lam, minlen, maxlen):
    best = [None] * (n + 1)
    par = [-1] * (n + 1)
    best[0] = 0.0
    for b in range(1, n + 1):
        lo = max(0, b - maxlen)
        hi = b - minlen
        if b == n:
            hi = b - 1
        if hi < 0:
            continue
        intra = 0.0
        for a in range(b - 1, lo - 1, -1):
            if a <= hi and best[a] is not None:
                volseg = VP[b] - VP[a]
                dens = (intra / volseg) if volseg > 0 else 0.0
                val = best[a] + dens * math.sqrt(b - a) - lam
                if best[b] is None or val > best[b]:
                    best[b] = val
                    par[b] = a
            intra += rowsum(rows, a, b)
    if best[n] is None:
        return [], 0.0
    cuts, i = [], n
    while i > 0 and par[i] >= 0:
        cuts.append(par[i])
        i = par[i]
    return sorted(c for c in cuts if c > 0), best[n]


def merge_small(cuts, n, floor):
    cuts = sorted(set(cuts))
    changed = True
    while changed and cuts:
        changed = False
        b = [0] + cuts + [n]
        for k in range(len(b) - 1):
            if b[k + 1] - b[k] < floor:
                if k == 0:
                    cuts.remove(b[1])
                elif k == len(b) - 2:
                    cuts.remove(b[k])
                else:
                    cuts.remove(b[k] if (b[k] - b[k - 1]) <= (b[k + 2] - b[k + 1]) else b[k + 1])
                cuts = sorted(set(cuts))
                changed = True
                break
    return cuts


# ------------------------------------------------------------------ 主流程

def area_of(lo, hi, tablist):
    """顶层分区 (用户领域知识: 引擎部分 vs 脚本部分, 脚本在 0x08052xxx 附近)"""
    if any("0x0862D434" in t for t in tablist) or lo >= 0x0804F250:
        return "SCRIPT"
    if lo < 0x08004F00:
        return "BOOT/INTR"
    if any(x in "".join(tablist) for x in ("0x0839CD5C", "0x0839D4CC", "0x0839CEC4")):
        return "ENGINE/OBJECT"
    if lo < 0x08017000:
        return "ENGINE/SYS"
    return "ENGINE/CORE"


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--lam", type=float, default=0.30)
    ap.add_argument("--min-funcs", type=int, default=8)
    ap.add_argument("--max-funcs", type=int, default=90)
    ap.add_argument("--floor", type=int, default=8)
    ap.add_argument("--decay", type=float, default=40.0)
    ap.add_argument("--top", type=int, default=60)
    args = ap.parse_args()

    names = load_llcfg()
    status = load_yaml()
    funcs = {}
    for folder, matched in (("asm/nonmatchings", 0), ("asm/matchings", 1)):
        if not os.path.isdir(folder):
            continue
        for fn in sorted(os.listdir(folder)):
            if not fn.endswith(".s"):
                continue
            nm = fn[:-2]
            addr, mnem, calls, pools = parse_func(os.path.join(folder, fn))
            funcs[nm] = {"name": nm, "addr": addr, "matched": matched,
                         "tu_yaml": status.get(nm, (None, None))[0],
                         "n_insn": len(mnem), "calls": calls, "pools": pools,
                         "sig": sig_exact(mnem), "shape": sig_shape(mnem),
                         "realname": names.get(addr, nm) if addr else nm}
    order = sorted(funcs.values(), key=lambda f: f["addr"] or 0)
    nodes = [f["name"] for f in order]
    n = len(nodes)

    # ---- 调度表 (地面真值)
    names_at = {f["addr"]: f["name"] for f in order if f["addr"]}
    handler_tables.__globals__["funcs_by_addr_order"] = {f["name"]: f["addr"] or 0 for f in order}
    tables = handler_tables(names_at)
    tab_of = {}
    for t in tables:
        for f in t["funcs"]:
            tab_of.setdefault(f, []).append(t["table"])

    # ---- 亲和边
    def is_data(p):
        return (p >> 24) in (0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0D, 0x0E)

    df = Counter()
    for f in order:
        for p in {x for x in f["pools"] if is_data(x)}:
            df[p] += 1
    edges = []
    for f in order:
        for c in set(f["calls"]):
            if c in funcs:
                edges.append((f["name"], c, 1.0))
    users = defaultdict(list)
    for f in order:
        for p in {x for x in f["pools"] if is_data(x)}:
            if df[p] <= HUB_CUT:
                users[p].append(f["name"])
    for sym, us in users.items():
        if len(us) < 2:
            continue
        w = 0.8 / math.log2(2 + df[sym])
        us = us[:MAX_FAN]
        for i in range(len(us)):
            for j in range(i + 1, len(us)):
                edges.append((us[i], us[j], w))
    for kind, wt in (("sig", 2.0), ("shape", 1.2)):
        fam = defaultdict(list)
        for f in order:
            fam[f[kind]].append(f["name"])
        for k, v in fam.items():
            if 1 < len(v) <= HUB_CUT:
                for i in range(len(v)):
                    for j in range(i + 1, len(v)):
                        edges.append((v[i], v[j], wt))
    for t in tables:
        v = t["funcs"][:MAX_FAN]
        for i in range(len(v)):
            for j in range(i + 1, len(v)):
                edges.append((v[i], v[j], 4.0))

    n, rows, VP, mtot = build_stats(nodes, edges, args.decay)

    curve = []
    for lam in (1.2, 0.9, 0.7, 0.55, 0.45, 0.38, 0.30, 0.24, 0.18, 0.13, 0.09, 0.06):
        c, q = dp_segment(n, rows, VP, lam, args.min_funcs, args.max_funcs)
        curve.append((lam, len(merge_small(c, n, args.floor)) + 1, round(q, 2)))

    cuts, q = dp_segment(n, rows, VP, args.lam, args.min_funcs, args.max_funcs)
    cuts = merge_small(cuts, n, args.floor)
    bounds = [0] + cuts + [n]

    famshape = defaultdict(list)
    for f in order:
        famshape[f["sig"]].append(f["name"])
    dup = {k: v for k, v in famshape.items() if len(v) > 1}

    segs = []
    for si in range(len(bounds) - 1):
        mem = nodes[bounds[si]:bounds[si + 1]]
        ms = set(mem)
        addrs = [funcs[m]["addr"] for m in mem]
        un = [m for m in mem if not funcs[m]["matched"]]
        symc, romc = Counter(), Counter()
        for m in mem:
            for p in {x for x in funcs[m]["pools"] if is_data(x)}:
                (romc if p >> 24 == 8 else symc)[p] += 1
        anchors = sorted({funcs[m]["realname"] for m in mem
                          if not funcs[m]["realname"].startswith(("sub_", "nullsub_", "_"))})
        segs.append({
            "id": si, "n": len(mem), "lo": min(addrs), "hi": max(addrs),
            "unmatched": len(un), "un_insn": sum(funcs[m]["n_insn"] for m in un),
            "tot_insn": sum(funcs[m]["n_insn"] for m in mem),
            "tables": [f"0x{t['table']:08X}({len(t['funcs'])})"
                       for t in tables if len(set(t["funcs"]) & ms) >= 3],
            "funcs": mem, "anchors": anchors[:8],
            "key_iw": [hex(x) for x, _ in symc.most_common(4)],
            "key_rom": [hex(x) for x, _ in romc.most_common(4)],
        })

    # ---- 语义锚点 + 顶层分区
    sem = load_semantic_names(funcs)
    sem_addrs = {a: nm for nm, a in sem.items() if a}
    for s in segs:
        found = sorted({sem_addrs[funcs[m]["addr"]] for m in s["funcs"]
                        if funcs[m]["addr"] in sem_addrs})
        found += sorted({funcs[m]["realname"] for m in s["funcs"]
                         if not funcs[m]["realname"].startswith(("sub_", "nullsub_", "_"))
                         and funcs[m]["realname"] not in found})
        s["anchors"] = found[:10]
        s["area"] = area_of(s["lo"], s["hi"], s["tables"])

    json.dump({"functions": funcs, "tables": tables,
               "segments": [{k: (v if k != "funcs" else v[:0]) for k, v in s.items()} for s in segs],
               "seg_funcs": [[s["id"], s["funcs"]] for s in segs]},
              open(".scratch/atlas.json", "w"), indent=1)

    with open("modules.draft.yaml", "w") as fh:
        fh.write("# 模块边界提案 -- scripts/atlas.py 生成; 人工确认后升级为 modules.yaml\n")
        fh.write("# 硬约束: 模块 = 按原始顺序的连续函数区间, 不重排任何函数\n")
        fh.write(f"lam: {args.lam}\ndecay: {args.decay}\nmin_funcs: {args.min_funcs}\n"
                 f"max_funcs: {args.max_funcs}\n")
        fh.write("dispatch_tables:\n")
        for t in tables:
            fh.write(f"  - {{table: 0x{t['table']:08X}, items: {t['n']}, handlers: {len(t['funcs'])},"
                     f" lo: 0x{funcs[t['funcs'][0]]['addr']:08X},"
                     f" hi: 0x{funcs[t['funcs'][-1]]['addr']:08X}}}\n")
        fh.write("modules:\n")
        for s in segs:
            fh.write(f"  - id: M{s['id']:02d}\n")
            fh.write(f"    range: [0x{s['lo']:08X}, 0x{s['hi']:08X}]\n")
            fh.write(f"    funcs: {s['n']}   unmatched: {s['unmatched']}   un_insn: {s['un_insn']}\n")
            if s["tables"]:
                fh.write(f"    dispatch_tables: {s['tables']}\n")
            fh.write(f"    area: {s['area']}\n")
            if s["anchors"]:
                fh.write(f"    anchors: {s['anchors']}\n")
            fh.write(f"    key_iwram: {s['key_iw']}\n    key_rom: {s['key_rom']}\n")
            fh.write(f"    funcs_list: {s['funcs']}\n")

    total, matched = n, sum(1 for f in funcs.values() if f["matched"])
    un_insn = sum(f["n_insn"] for f in funcs.values() if not f["matched"])
    L = []
    w = L.append
    w("# 函数图谱与模块边界提案")
    w("")
    w("> 自动生成: `python3 scripts/atlas.py`。产物: 本文件 + `modules.draft.yaml` + `.scratch/atlas.json`")
    w(">")
    w("> **硬约束**: 模块 = 按原始顺序的连续函数区间, 不重排任何函数 (linker.ld 的 .text 顺序决定)")
    w("")
    w(f"- 函数 **{total}**, 已匹配 **{matched}** ({matched/total*100:.1f}%), "
      f"未匹配 **{total-matched}** / **{un_insn:,}** 条指令")
    w(f"- 亲和边 {len(edges)} 条 (m={mtot:.0f}), 调度表 **{len(tables)}** 张, λ={args.lam} → **{len(segs)} 个模块**")
    w("")
    w("## 0. ROM 自己的模块骨架: 函数指针调度表")
    w("")
    w("全 ROM 264 张指针数组里, 254 张是编译器生成的 switch 跳转表(目标都在同一函数内),")
    w("只有下面这些是**真正的跨函数调度表** —— 一张表 = 一个处理器家族 = 一个模块的铁证:")
    w("")
    w("| 表地址 | 项数 | 不同函数 | 目标范围 | 判读 |")
    w("|---|---|---|---|---|")
    for t in tables:
        lo = funcs[t["funcs"][0]]["addr"]
        hi = funcs[t["funcs"][-1]]["addr"]
        guess = ""
        if t["table"] == 0x0862D434:
            guess = "**脚本 opcode 处理器表**"
        elif t["table"] == 0x0839CD5C:
            guess = "**引擎对象/角色状态处理器表**"
        elif lo and 0x08025000 <= lo <= 0x08045000:
            guess = "引擎子处理器表"
        elif hi and hi < 0x08018000:
            guess = "中断/初始化向量表"
        w(f"| 0x{t['table']:08X} | {t['n']} | {len(t['funcs'])} | 0x{lo:08X}–0x{hi:08X} | {guess} |")
    w("")
    w("## 1. 方法验证 —— 现有 5 个 .o 的边界, detector 是否独立复现")
    w("")
    known = [(0x08005020, "code_80002A0 | code_8005020"), (0x080109F8, "code_8005020 | save"),
             (0x08010F10, "save | code_8010F10"), (0x0801A3C4, "code_8010F10 | code_801A3C4"),
             (0x08020D50, "code_801A3C4 | code_8020D50"), (0x080264C0, "code_8020D50 | code_80264C0"),
             (0x08044394, "code_80264C0 | code_8044394"), (0x0804F0B8, "code_8044394 | code_804F0B8"),
             (0x080539A0, "code | m4a 声音驱动")]
    det = [funcs[nodes[i]]["addr"] for i in cuts]
    w("| 现有边界 | 地址 | 最近的检测切点 | 相差函数数 |")
    w("|---|---|---|---|")
    for addr, why in known:
        pos = next((i for i, nm in enumerate(nodes) if (funcs[nm]["addr"] or 0) >= addr), None)
        if pos is None:
            continue
        near = min(cuts, key=lambda c: abs(c - pos))
        w(f"| {why} | 0x{addr:08X} | 0x{funcs[nodes[near]]['addr']:08X} | **{abs(near-pos)}** |")
    w("")
    w("## 1b. λ 扫描 (每段罚项 → 模块数; 找肘部)")
    w("")
    w("| λ | " + " | ".join(str(x[0]) for x in curve) + " |")
    w("|---|" + "---|" * len(curve))
    w("| 模块数 | " + " | ".join(str(x[1]) for x in curve) + " |")
    w("| 目标值 | " + " | ".join(str(x[2]) for x in curve) + " |")
    w("")
    w("## 2. 模块清单 (按未匹配指令数 = 工作量排序)")
    w("")
    w("| 模块 | 分区 | 地址区间 | 函数 | 未匹配 | 未匹配指令 | 调度表 | 语义锚点 | 关键工作内存 |")
    w("|---|---|---|---|---|---|---|---|---|")
    for s in sorted(segs, key=lambda x: -x["un_insn"])[:args.top]:
        w(f"| **M{s['id']:02d}** | {s['area']} | 0x{s['lo']:08X}–0x{s['hi']:08X} | {s['n']} | "
          f"{s['unmatched']} | {s['un_insn']:,} | {', '.join(s['tables']) or '—'} | "
          f"{', '.join(s['anchors'][:3]) or '—'} | {', '.join(s['key_iw'][:2]) or '—'} |")
    w("")
    w("## 3. 参数化同构家族 (一个任务包, 做一个中一串)")
    w("")
    segid = {m: s["id"] for s in segs for m in s["funcs"]}
    w("| 大小 | 未匹配 | 指令/函数 | 成员 | 所属模块 |")
    w("|---|---|---|---|---|")
    shown = 0
    for k, v in sorted(dup.items(), key=lambda kv: -len(kv[1])):
        if not any(not funcs[m]["matched"] for m in v):
            continue
        ss = sorted({segid[m] for m in v})
        w(f"| {len(v)} | {sum(1 for m in v if not funcs[m]['matched'])} | {funcs[v[0]]['n_insn']} | "
          f"{', '.join(v[:5])}{' …' if len(v) > 5 else ''} | "
          f"{','.join('M%02d' % x for x in ss[:5])}{' ⚠跨' if len(ss) > 1 else ''} |")
        shown += 1
        if shown >= args.top:
            break
    w("")
    w("## 4. 每个模块的函数明细")
    w("")
    for s in segs:
        w(f"### M{s['id']:02d} [{s['area']}]  0x{s['lo']:08X}–0x{s['hi']:08X}  "
          f"({s['n']} 函数 / {s['unmatched']} 未匹配 / {s['un_insn']:,} 指令)")
        w("")
        if s["tables"]:
            w("调度表: " + ", ".join(s["tables"]))
        if s["anchors"]:
            w("锚点: " + ", ".join(s["anchors"]))
        if s["key_iw"]:
            w("工作内存: " + ", ".join(s["key_iw"]))
        if s["key_rom"]:
            w("ROM 表: " + ", ".join(s["key_rom"]))
        w("")
        w("```")
        w("  地址        指令  ll.cfg 名                     函数")
        for m in s["funcs"]:
            f = funcs[m]
            w(f"{' ' if f['matched'] else '*'}{f['addr']:#010x} {f['n_insn']:5d}  "
              f"{f['realname']:28s} {m}")
        w("```")
        w("")
    open("docs/ATLAS.md", "w").write("\n".join(L))
    print(f"函数 {total} | 匹配 {matched} | 亲和边 {len(edges)} | 调度表 {len(tables)} | "
          f"λ={args.lam} -> {len(segs)} 模块")
    print("λ 曲线 (λ, K, 目标值):", curve)
    print("模块大小:", [s["n"] for s in segs])
    print("[写出] docs/ATLAS.md  modules.draft.yaml  .scratch/atlas.json")


if __name__ == "__main__":
    main()
