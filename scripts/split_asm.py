#!/usr/bin/env python3

import re
import sys
import os


def match_func(content):

    filepath = "asm/nonmatching"

    os.makedirs(filepath, exist_ok=True)

    pattern = re.compile(r'((?:thumb|arm)_func_start[\s\S]*?)(?=(?:thumb|arm)_func_start)')

    pat = re.compile(r'((?:thumb|arm)_func_start\s+\w+)\s*\n([\s\S]*?)(?=(?:thumb|arm)_func_start|$)')

    matches = pattern.findall(content)


    for m in matches:
        first_line = m.splitlines()[0]
        out_name = first_line.split(' ')[1]
        # if "null" in out_name:
        #     continue
        if out_name == "umul3232H32":
            break
        with open(f"{filepath}/{out_name}.s", 'w', encoding='utf-8') as f:
            f.write("	.syntax unified\n")
            f.write(m)
            f.write("	.syntax divided\n")

    


def main():
    input_file = "code.s"
    output_dir = "asm/nonmatching/"
    # output_file = f"{func_name}.s"

    if not os.path.exists(input_file):
        print(f"file '{input_file}' not found.")
        sys.exit(1)

    try:
        with open(input_file, 'r', encoding='utf-8') as f:
            content = f.read()
    except Exception as e:
        print(f"open file error: {e}")
        sys.exit(1)


    match_func(content)

 



if __name__ == "__main__":
    main()