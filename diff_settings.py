def apply(config, args):
    config["baseimg"] = "baserom.o"  # ELF wrapper for baserom.gba (.text @ 0x08000000)
    config["myimg"] = "ll.elf"
    config["mapfile"] = "ll.map"
    config["map_format"] = "gnu"
    config["arch"] = "arm32"
    config["objdump_executable"] = "arm-none-eabi-objdump"
    config["objdump_flags"] = ["-marmv4t", "-Mforce-thumb"]
    config["disassemble_all"] = True
    config["source_directories"] = ["."]
    config["diff_section"] = ".text"
