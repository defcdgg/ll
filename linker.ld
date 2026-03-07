gNumMusicPlayers = 5;
gMaxLines = 0x1E;

ENTRY(__start)

MEMORY {
    ewram (w!x) : ORIGIN = 0x02000000, LENGTH = 256K
    iwram (w!x) : ORIGIN = 0x03000000, LENGTH = 32K
    rom (rx) : ORIGIN = 0x08000000, LENGTH = 8M
}

SECTIONS {
    ewram (NOLOAD) : ALIGN(4) {
        . = 0x00000000; gUnk_02000000 = .;
        . = 0x00040000;
    } >ewram

    iwram (NOLOAD) : ALIGN(4) {
        . = 0x00000000; gUnk_03000000 = .;

        . = 0x00001544;
        . = ALIGN(4);
        *libgcc.a:dp-bit.o(.bss);
        *libgcc.a:fp-bit.o(.bss);
        . = ALIGN(4); src/m4a.o(.bss*);
        . = 0x00004FA0; src/m4a.o(common_data);
        . = 0x00008000;
    } >iwram


    .text : ALIGN(4) {
        asm/crt0.o(.text);
        asm/code.o(.text);
        asm/m4a_asm.o(.text);
        src/m4a.o(.text);
        asm/libagbsyscall.o(.text);
        src/agb_sram.o(.text);
        *libgcc.a:_call_via_rX.o(.text);
        *libgcc.a:_divsi3.o(.text);
        *libgcc.a:_dvmd_tls.o(.text);
        *libgcc.a:_fixunsdfsi.o(.text);
        *libgcc.a:_fixunssfsi.o(.text);
        *libgcc.a:_modsi3.o(.text);
        *libgcc.a:_udivsi3.o(.text);
        *libgcc.a:_umodsi3.o(.text);
        *libgcc.a:dp-bit.o(.text);
        *libgcc.a:fp-bit.o(.text);
        *libgcc.a:_lshrdi3.o(.text);
        *libgcc.a:_muldi3.o(.text);
        *libgcc.a:_negdi2.o(.text);
        *libc.a:memcpy.o(.text);
    } >rom =0

    .rodata ALIGN(4) : SUBALIGN(4) {
        data/data.o(.rodata);
        src/m4a_tables.o(.rodata);
        data/sound_data.o(.rodata);
    } >rom =0


    /* DWARF 2 sections */
    .debug_aranges  0 : { *(.debug_aranges) }
    .debug_pubnames 0 : { *(.debug_pubnames) }
    .debug_info     0 : { *(.debug_info) }
    .debug_abbrev   0 : { *(.debug_abbrev) }
    .debug_line     0 : { *(.debug_line) }
    .debug_frame    0 : { *(.debug_frame) }
    .debug_str      0 : { *(.debug_str) }
    .debug_loc      0 : { *(.debug_loc) }
    .debug_macinfo  0 : { *(.debug_macinfo) }

    /* Discard everything not specifically mentioned above. */
    /DISCARD/ :
    {
        *(*);
    }
}
