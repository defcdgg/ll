#!/usr/bin/env python3
"""
audit.py -- 台账一致性审计 (多智能体并行的必备检查)

核对三件事 ((已删)ASSIGNMENTS 已冻结, 台账 = functions.tsv):
  1. functions.tsv 的 name 缓存列 vs ll.cfg 当前名 (改名漂移检测; gen_asm --sync 修复)
  2. status=1 的函数, 字节是否真的匹配 (fncheck 读 build/*.o; asm-match 的验 asm/matchings)
  3. note 列卫生 + "两个人同时在改同一个文件"迹象 (mtime 新鲜度)

用法:
  python3 scripts/audit.py            # 只报告
"""

import os
import re
import subprocess
import sys
from collections import defaultdict

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
os.chdir(ROOT)


def yaml_status():
    """{name: status} from functions.tsv (权威台账; 函数名以 ll.cfg 为准, 此处按 TSV 缓存名)。"""
    import csv
    with open("functions.tsv", errors="replace") as f:
        return {r["name"]: r["status"] for r in csv.DictReader(f, delimiter="\t")}


def fncheck(funcs):
    """批量跑 fncheck, 返回 {func: 'OK'|'FAIL'|'NOTBUILT'}"""
    if not funcs:
        return {}
    out = subprocess.run([sys.executable, "scripts/fncheck.py"] + list(funcs),
                         capture_output=True, text=True).stdout
    res = {}
    for line in out.splitlines():
        p = line.split()
        if len(p) >= 2 and p[0] in funcs:
            if p[1] == "OK":
                res[p[0]] = "OK"
            elif line.startswith(p[0] + " ") and "NOT BUILT" in line:
                res[p[0]] = "NOTBUILT"
            else:
                res[p[0]] = "FAIL"
    return res


def asm_check(func):
    """对 INCLUDE_ASM("asm/matchings") 占位的函数: 直接汇编那份 .s 与 baserom 比字节。
    返回 'ASM-OK' / 'ASM-BAD' / '-' (无参考文件)"""
    ref = f"asm/matchings/{func}.s"
    if not os.path.exists(ref):
        return "-"
    import tempfile
    with tempfile.TemporaryDirectory() as td:
        src = os.path.join(td, "t.s")
        obj = os.path.join(td, "t.o")
        binf = os.path.join(td, "t.bin")
        with open(src, "w") as f:
            f.write('\t.include "macros/function.inc"\n')
            f.write(open(ref, errors="replace").read())
        if subprocess.run(["arm-none-eabi-as", "-mcpu=arm7tdmi", "-mthumb-interwork",
                           "-I", "asm", "-o", obj, src], capture_output=True).returncode:
            return "ASM-BAD"
        subprocess.run(["arm-none-eabi-objcopy", "-O", "binary",
                        "--only-section=.text", obj, binf], capture_output=True)
        try:
            d = open(binf, "rb").read()
        except OSError:
            return "ASM-BAD"
        ys = yaml_status()
        addr = code_s_addrs().get(func)
        if addr is None:
            return "-"
        base = open("baserom.gba", "rb").read()
        off = addr - 0x08000000
        n = min(len(d), len(base) - off)
        return "ASM-OK" if all(d[i] == base[off + i] for i in range(n)) else "ASM-BAD"


def code_s_addrs():
    res = {}
    if os.path.exists("code.s"):
        for line in open("code.s", errors="replace"):
            m = re.match(r"^(\w+):\s*@ 0x([0-9a-fA-F]+)\s*$", line)
            if m:
                res[m.group(1)] = int(m.group(2), 16)
    return res


def main():
    import csv
    rows = list(csv.DictReader(open("functions.tsv", encoding="utf-8"), delimiter="\t"))
    ll_addr2name = {}
    for line in open("ll.cfg", encoding="utf-8", errors="replace"):
        m = re.match(r"^(?:thumb|arm)_func (0x[0-9a-fA-F]+) (\w+)", line)
        if m:
            ll_addr2name[int(m.group(1), 16)] = m.group(2)

    drift = [(r["addr"], r["name"], ll_addr2name[int(r["addr"], 16)])
             for r in rows if int(r["addr"], 16) in ll_addr2name
             and ll_addr2name[int(r["addr"], 16)] != r["name"]]
    missing = [r["addr"] + " " + r["name"] for r in rows if int(r["addr"], 16) not in ll_addr2name]

    print("=== functions.tsv 台账 ===")
    n1 = sum(1 for r in rows if r["status"] == "1")
    print(f"共 {len(rows)} 函数 | 已匹配 {n1} ({n1*100//len(rows)}%) | 未匹配 {len(rows)-n1}")
    print(f"改名漂移: {len(drift)}" + ("" if not drift else "  (跑 python3 scripts/gen_asm.py --sync 回写)"))
    for a, old, new in drift[:10]:
        print(f"  {a}: tsv='{old}' ll.cfg='{new}'")
    if missing:
        print(f"!! addr 不在 ll.cfg: {missing}")

    pend = [r for r in rows if r["status"] == "0"]
    pend_noted = [r for r in pend if r["note"].strip().startswith("⏸")]
    done_noted = [r for r in rows if r["status"] == "1" and r["note"].strip().startswith("✅")]
    print(f"note 覆盖: 挂起 {len(pend_noted)}/{len(pend)} | 完成 {len(done_noted)}/{n1}")

    bad = []
    verdict = fncheck([r["name"] for r in rows if r["status"] == "1"])
    for r in rows:
        if r["status"] != "1":
            continue
        v = verdict.get(r["name"], "NOTBUILT")
        if v == "OK":
            continue
        if v == "NOTBUILT" and asm_check(r["name"]) == "ASM-OK":
            continue
        bad.append((r["name"], v))
    print(f"\n=== status=1 字节核验 ===\n通过 {n1 - len(bad)}/{n1}")
    for nm, v in bad[:20]:
        print(f"  !! {nm}: {v}")

    print("\n=== 各翻译单元最后修改时间 ===")
    now = {}
    for f in sorted(os.listdir("src")):
        if f.endswith(".c"):
            now["src/" + f] = os.stat("src/" + f).st_mtime
    import time
    for path, mt in sorted(now.items(), key=lambda kv: -kv[1])[:8]:
        age = (time.time() - mt) / 60
        mark = "  <== 10 分钟内被改过, 避开" if age < 10 else ""
        print(f"  {time.strftime('%H:%M', time.localtime(mt))}  {path:24s} {age:6.0f} 分钟前{mark}")

    if drift or missing or bad:
        sys.exit(1)


if __name__ == "__main__":
    main()
