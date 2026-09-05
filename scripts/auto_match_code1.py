#!/usr/bin/env python3
"""Batch probe short ``code_1.c`` functions.

The script is deliberately conservative: it only changes ``functions.tsv`` for
functions that already have a C definition and pass ``fncheck``.  Other
functions are converted with m2c (when possible) and checked with fndiff; a
compile error, unsupported m2c output, or non-zero score is logged and the
next function is attempted.

Usage::

    .venv/bin/python scripts/auto_match_code1.py --apply

Without ``--apply`` this is a dry run.  Results are written to
``.scratch/auto_match_code1/status.tsv``.
"""

from __future__ import annotations

import argparse
import pathlib
import re
import subprocess
import sys

ROOT = pathlib.Path(__file__).resolve().parents[1]
SRC = ROOT / "src/code_8010F10.c"  # 2026-08-31 文件按模块首函数地址重命名(原 code_1.c)

TSV = ROOT / "functions.tsv"
ASM = ROOT / "asm/nonmatchings"
OUT = ROOT / ".scratch/auto_match_code1"


def run(cmd: list[str], **kwargs) -> subprocess.CompletedProcess[str]:
    return subprocess.run(cmd, cwd=ROOT, text=True, capture_output=True, **kwargs)


def function_defs(text: str) -> dict[str, str]:
    """Return complete C definitions keyed by function name."""
    result: dict[str, str] = {}
    pat = re.compile(r"(?m)^[A-Za-z_][\w\s\*]*\s+(sub_80[0-9A-Fa-f]+)\s*\([^;]*\)\s*\{")
    for m in pat.finditer(text):
        depth = 0
        end = None
        for i in range(m.end() - 1, len(text)):
            if text[i] == "{":
                depth += 1
            elif text[i] == "}":
                depth -= 1
                if depth == 0:
                    end = i + 1
                    break
        if end is not None:
            result[m.group(1)] = text[m.start():end]
    return result


def yaml_statuses() -> tuple[str, dict[str, int]]:
    text = TSV.read_text()
    statuses = {}
    for line in text.splitlines()[1:]:
        p = line.split("\t")
        if len(p) >= 6 and p[2] in ("code_8010F10", "code_801A3C4", "code_8020D50", "code_80264C0", "code_8044394"):
            statuses[p[5]] = int(p[0])
    return text, statuses


def set_status(text: str, func: str) -> str:
    lines = text.splitlines(True)
    for i, line in enumerate(lines):
        p = line.split("\t")
        if len(p) >= 6 and p[5] == func and p[0] == "0":
            p[0] = "1"
            lines[i] = "\t".join(p)
            break
    return "".join(lines)


def short_targets(statuses: dict[str, int]) -> list[tuple[str, int]]:
    names: set[str] = set(re.findall(r'INCLUDE_ASM\("asm/nonmatchings",\s*(\w+)\)', SRC.read_text()))
    names.update(function_defs(SRC.read_text()))
    out = []
    for name in names:
        if statuses.get(name, 1) != 0:
            continue
        path = ASM / f"{name}.s"
        if path.exists():
            lines = len(path.read_text(errors="replace").splitlines())
            if lines < 80:
                out.append((name, lines))
    return sorted(out, key=lambda x: (x[1], x[0]))


def m2c_candidate(func: str) -> pathlib.Path | None:
    src = (ASM / f"{func}.s").read_text(errors="replace")
    src = re.sub(r"^\tldr (r\d+), _[0-9A-Fa-f]+ @ =(0x[0-9A-Fa-f]+)$", r"\tldr \1, =\2", src, flags=re.M)
    src = re.sub(r"^_[0-9A-Fa-f]+: \.4byte .*\n?", "", src, flags=re.M)
    src = src.replace("\t.align 2, 0\n", "")
    tmp_s = OUT / f"{func}.input.s"
    tmp_s.write_text(src)
    out_c = OUT / f"{func}.m2c.c"
    p = run([str(ROOT / ".venv/bin/python"), "tools/m2c/m2c.py", "-t", "gba", "-f", func, str(tmp_s)])
    if p.returncode != 0:
        (OUT / f"{func}.m2c.err").write_text(p.stderr)
        return None
    out_c.write_text(p.stdout)
    if "goto " in p.stdout or "M2C_ERROR" in p.stdout:
        return None
    return out_c


def probe(func: str, candidate: pathlib.Path) -> tuple[str, str]:
    p = run(["scripts/fndiff.sh", func, str(candidate)])
    output = p.stdout + p.stderr
    (OUT / f"{func}.fndiff.txt").write_text(output)
    if p.returncode != 0:
        return "compile-fail", ""
    scores = re.findall(r"CURRENT \((\d+)\)", output)
    return ("score-" + scores[0] if scores else "probed"), (scores[0] if scores else "")


def main() -> int:
    global SRC, OUT

    ap = argparse.ArgumentParser()
    ap.add_argument("--apply", action="store_true", help="apply fncheck-proven C definitions")
    ap.add_argument("--source", default="code_8010F10.c",
                    help="source file under src/ (default: code_1.c)")
    args = ap.parse_args()
    source_name = pathlib.Path(args.source).name
    SRC = ROOT / "src" / source_name
    if not SRC.is_file():
        ap.error(f"source does not exist: {SRC}")
    OUT = ROOT / ".scratch" / ("auto_match_" + SRC.stem)
    OUT.mkdir(parents=True, exist_ok=True)
    yaml_text, statuses = yaml_statuses()
    defs = function_defs(SRC.read_text())
    targets = short_targets(statuses)
    rows: list[str] = ["function\tasm_lines\tresult\tdetail"]
    changed = False

    # Build once so fncheck can inspect existing C definitions.
    build = run(["make", f"build/src/{SRC.stem}.o"])
    build_ok = build.returncode == 0
    if not build_ok:
        (OUT / "build.log").write_text(build.stdout + build.stderr)
    for func, lines in targets:
        if func in defs:
            if not build_ok:
                rows.append(f"{func}\t{lines}\tbuild-fail\tcode_1.o could not be rebuilt")
                continue
            check = run([str(ROOT / ".venv/bin/python"), "scripts/fncheck.py", func])
            ok = check.returncode == 0 and " OK " in check.stdout
            if ok and args.apply:
                yaml_text = set_status(yaml_text, func)
                changed = True
                result = "matched-existing"
            elif ok:
                result = "ready-existing"
            else:
                result = "existing-fail"
            rows.append(f"{func}\t{lines}\t{result}\t{check.stdout.strip()}")
            continue

        candidate = ROOT / "permuter" / func / "base.c"
        if candidate.exists():
            result, detail = probe(func, candidate)
            rows.append(f"{func}\t{lines}\t{result}\t{detail}")
            continue

        candidate = m2c_candidate(func)
        if candidate is None:
            rows.append(f"{func}\t{lines}\tm2c-skip\tunsupported output or m2c error")
            continue
        result, detail = probe(func, candidate)
        rows.append(f"{func}\t{lines}\t{result}\t{detail}")

    if changed:
        TSV.write_text(yaml_text)
        split = run([str(ROOT / ".venv/bin/python"), "scripts/gen_asm.py"])
        if split.returncode != 0:
            print(split.stdout + split.stderr, file=sys.stderr)
            return 1
    (OUT / "status.tsv").write_text("\n".join(rows) + "\n")
    print("批处理完成: %d 个目标，结果见 %s" % (len(targets), OUT / "status.tsv"))
    if changed:
        print("已更新 functions.tsv 并重新生成 asm/matchings 与 asm/nonmatchings")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
