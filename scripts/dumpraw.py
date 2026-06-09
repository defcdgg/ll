import json
import os
import shutil

with open("scripts/data.json", "r", encoding="utf-8") as f:
    jsondata = json.load(f)

target_dir = "data/raw_data"
if os.path.exists(target_dir):
    shutil.rmtree(target_dir)
os.makedirs(target_dir, exist_ok=True)

with open("baserom.gba", "rb") as rom:
    for item in jsondata:
        filename = item['name']
        mem_addr = int(item['address'], 16)
        file_addr = mem_addr - 0x08000000
        size = item['size']

        rom.seek(file_addr)
        bin_data = rom.read(size)

        with open(f"{target_dir}/{filename}.bin", 'wb') as outbin:
            outbin.write(bin_data)
