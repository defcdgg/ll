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
        . = 0x00004000; gUnk_02004000 = .;
        . = 0x00005000; gUnk_02005000 = .;
        . = 0x00005380; gUnk_02005380 = .;
        . = 0x00005800; gUnk_02005800 = .;
        . = 0x00040000;
    } >ewram

    iwram (NOLOAD) : ALIGN(4) {
        . = 0x00000000; gUnk_03000000 = .;


        . = 0x00001544;
        . = ALIGN(4);
        *libgcc.a:dp-bit.o(.bss);
        *libgcc.a:fp-bit.o(.bss);
        . = ALIGN(4); src/m4a.o(.bss*);
        
        . = 0x000018F0; gUnk_030018F0 = .;
        . = 0x00001940; gUnk_03001940 = .;
        . = 0x00001944; gUnk_03001944 = .;
        . = 0x00001948; gUnk_03001948 = .;
        . = 0x00001950; gUnk_03001950 = .;
        . = 0x00001988; gUnk_03001988 = .;
        . = 0x00001990; gLzContext = .;
        . = 0x000019B0; gUnk_030019B0 = .;
        . = 0x000019C0; gUnk_030019C0 = .;
        . = 0x00001AC0; gUnk_03001AC0 = .;
        . = 0x00001AD0; gUnk_03001AD0 = .;    
        . = 0x00001B50; gUnk_03001B50 = .;
        . = 0x00001B54; gUnk_03001B54 = .;
        . = 0x00001B60; gUnk_03001B60 = .;
        . = 0x00001C60; gUnk_03001C60 = .;
        . = 0x00001CA0; gUnk_03001CA0 = .;
        . = 0x00001CB0; gUnk_03001CB0 = .;
        . = 0x00001D30; gUnk_03001D30 = .;
        . = 0x00001D80; gIntrMainBuf = .;
        . = 0x0000259C; gUnk_0300259C = .;
        . = 0x000025A0; gUnk_030025A0 = .;
        . = 0x000025A4; gUnk_030025A4 = .;
        . = 0x000025A8; gUnk_030025A8 = .;

        . = 0x000025B4; gUnk_030025B4 = .;
        . = 0x000025D8; gUnk_030025D8 = .;
        . = 0x000025F4; gUnk_030025F4 = .;
        . = 0x000025FC; gUnk_030025FC = .;
        . = 0x00002600; gUnk_03002600 = .;    
        . = 0x00002604; gUnk_03002604 = .;    
        . = 0x00002C40; gUnk_03002C40 = .;
        . = 0x00002C48; gUnk_03002C48 = .;

        . = 0x000032D0; gUnk_030032D0 = .;
        . = 0x000035C0; gUnk_030035C0 = .;

        . = 0x00004550; gUnk_03004550 = .;

        . = 0x00004610; gUnk_03004610 = .;
        . = 0x00004648; gUnk_03004648 = .;

        . = 0x00004658; gUnk_03004658 = .;
        . = 0x0000465C; gUnk_0300465C = .;
        . = 0x00004698; gUnk_03004698 = .;

        . = 0x00004800; gUnk_03004800 = .;
        . = 0x00004828; gUnk_03004828 = .;
        . = 0x0000483C; gUnk_0300483C = .;
        . = 0x00004840; gUnk_03004840 = .; 

        . = 0x00004848; gUnk_03004848 = .; 
        . = 0x0000484C; gUnk_0300484C = .;
        . = 0x00004854; gUnk_03004854 = .;
        . = 0x00004910; gUnk_03004910 = .;
        . = 0x00004D40; gUnk_03004D40 = .;
        . = 0x00004D4C; gUnk_03004D4C = .;
        . = 0x00004DC0; gUnk_03004DC0 = .;

        . = 0x00004F20; gUnk_03004F20 = .;

        . = 0x00004FA0; src/m4a.o(common_data);
        . = 0x00007FF8; gUnk_03007FF8 = .;
        . = 0x00008000;
    } >iwram


    .text : ALIGN(4) {
        asm/crt0.o(.text);
        src/code_80002A0.o(.text);
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
        src/code_80002A0.o(.rodata);
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
