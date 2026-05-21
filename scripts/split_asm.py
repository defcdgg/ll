import re
import os
import sys
import yaml
import shutil

def split_asm_by_yaml(content, yaml_data):
    base_path = "asm"

    def get_func_pattern(func_name):
        return re.compile(
            rf'((?:thumb|arm)_func_start\s+{func_name}\b[\s\S]*?)(?=(?:thumb|arm)_func_start|$)'
        )

    for module, functions in yaml_data.items():
        for func_name, match_info in functions.items():
            
            if not match_info or not isinstance(match_info, list):
                continue
            status = match_info[0]
            
            # 1 = matchings，0 = nonmatchings
            if status == 1:
                folder_type = "matchings"
            elif status == 0:
                folder_type = "nonmatchings"
            else:
                print(f"Warning: Skipping unknown status for function: {func_name} (Status: {status})")
                continue
                
            target_dir = os.path.join(base_path, folder_type)
            os.makedirs(target_dir, exist_ok=True)
            
            func_regex = get_func_pattern(func_name)
            match = func_regex.search(content)
            
            if match:
                func_content = match.group(1)
                output_file_path = os.path.join(target_dir, f"{func_name}.s")
                
                with open(output_file_path, 'w', encoding='utf-8') as f:
                    f.write("\t.syntax unified\n")
                    f.write(func_content)
                    f.write("\t.syntax divided\n")
            else:
                print(f"Skipping unknown function: {func_name}")


def delete_folder(name):
    if os.path.exists(name):
        try:
            shutil.rmtree(name)
            print(f"Cleaned up old directory: {name}")
        except Exception as e:
            print(f"Warning: Could not delete {name}: {e}")

def main():
    input_asm = "code.s"
    input_yaml = "functions.yaml"

    delete_folder("asm/matchings")
    delete_folder("asm/nonmatchings")



    if not os.path.exists(input_asm):
        print(f"file '{input_asm}' not found.")
        sys.exit(1)
    if not os.path.exists(input_yaml):
        print(f"file '{input_yaml}' not found.")
        sys.exit(1)

    with open(input_yaml, "r", encoding="utf-8") as f:
        yaml_data = yaml.safe_load(f)

    with open(input_asm, "r", encoding="utf-8") as f:
        asm_content = f.read()

    split_asm_by_yaml(asm_content, yaml_data)
    print("Finish.")

if __name__ == "__main__":
    main()
