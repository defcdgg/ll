ENTRY(__start)

gNumMusicPlayers = 5;
gMaxLines = 0x1E;

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
        . = 0x00000002; gUnk_03000002 = .;
        . = 0x00000004; gUnk_03000004 = .;
        . = 0x00000010; gUnk_03000010 = .;
        . = 0x00000788; gUnk_03000788 = .;
        . = 0x000007BA; gUnk_030007BA = .;
        . = 0x00000DDE; gUnk_03000DDE = .;
        . = 0x00000E04; gUnk_03000E04 = .;
        . = 0x00000E70; gUnk_03000E70 = .;
        . = 0x00000F38; gUnk_03000F38 = .;
        . = 0x00000F3A; gUnk_03000F3A = .;
        . = 0x00000F3C; gUnk_03000F3C = .;
        . = 0x00000F3E; gUnk_03000F3E = .;
        . = 0x00000F40; gUnk_03000F40 = .;
        . = 0x00000F41; gUnk_03000F41 = .;
        . = 0x00000F42; gUnk_03000F42 = .;
        . = 0x00000F43; gUnk_03000F43 = .;
        . = 0x00000F50; gUnk_03000F50 = .;
        . = 0x00000F58; gMPlayTrack_0 = .;
        . = 0x00001408; gMPlayTrack_1 = .;
        . = 0x00001458; gMPlayTrack_2 = .;
        . = 0x000014A8; gMPlayTrack_3 = .;
        . = 0x000014F8; gMPlayTrack_4 = .;

        . = 0x00001544;
        . = ALIGN(4);
        *libgcc.a:dp-bit.o(.bss);
        *libgcc.a:fp-bit.o(.bss);
        . = ALIGN(4); src/m4a.o(.bss*);
        
        . = 0x000018F0; gUnk_030018F0 = .;
        . = 0x00001940; gUnk_03001940 = .;
        . = 0x00001944; gUnk_03001944 = .;
        . = 0x00001948; gGameTimer = .;
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
        . = 0x000025B0; gUnk_030025B0 = .;

        . = 0x000025B4; gUnk_030025B4 = .;
        . = 0x000025B8; gUnk_030025B8 = .;
        . = 0x000025C0; gUnk_030025C0 = .;
        . = 0x000025D4; gUnk_030025D4 = .;
        . = 0x000025D8; gUnk_030025D8 = .;
        . = 0x000025E0; gUnk_030025E0 = .;
        . = 0x000025F0; gUnk_030025F0 = .;
        . = 0x000025F4; gUnk_030025F4 = .;
        . = 0x000025F8; gUnk_030025F8 = .;
        . = 0x000025FC; gUnk_030025FC = .;
        . = 0x00002600; gUnk_03002600 = .;
        . = 0x00002604; gUnk_03002604 = .;
        . = 0x00002608; gUnk_03002608 = .;
        . = 0x0000260C; gUnk_0300260C = .;
        . = 0x00002C34; gUnk_03002C34 = .;
        . = 0x00002C38; gUnk_03002C38 = .;
        . = 0x00002C3C; gUnk_03002C3C = .;
        . = 0x00002C40; gUnk_03002C40 = .;
        . = 0x00002C44; gUnk_03002C44 = .;
        . = 0x00002C48; gUnk_03002C48 = .;
        . = 0x00002C4C; gUnk_03002C4C = .;
        . = 0x00002C50; gUnk_03002C50 = .;
        . = 0x00002C58; gUnk_03002C58 = .;
        . = 0x00002C80; gUnk_03002C80 = .;
        . = 0x00002E80; gUnk_03002E80 = .;
        . = 0x00003150; gUnk_03003150 = .;        
        . = 0x000032D0; gUnk_030032D0 = .;
        . = 0x00003360; gUnk_03003360 = .;
        . = 0x00003380; gUnk_03003380 = .;
        . = 0x000034C0; gUnk_030034C0 = .;     
        . = 0x000035C0; gUnk_030035C0 = .;
        . = 0x000039C0; gUnk_030039C0 = .;
        
        . = 0x00003AC0; gUnk_03003AC0 = .;
        . = 0x00004550; gUnk_03004550 = .;
        . = 0x00004608; gUnk_03004608 = .;
        . = 0x00004610; gUnk_03004610 = .;
        . = 0x00004614; gUnk_03004614 = .;
        . = 0x00004624; gUnk_03004624 = .;
        . = 0x0000462C; gUnk_0300462C = .;
        . = 0x00004634; gUnk_03004634 = .;
        . = 0x00004638; gUnk_03004638 = .;
        . = 0x00004648; gUnk_03004648 = .;

        . = 0x00004658; gUnk_03004658 = .;
        . = 0x0000465C; gUnk_0300465C = .;
        . = 0x0000466C; gUnk_0300466C = .;
        . = 0x0000467C; gUnk_0300467C = .;
        . = 0x0000468C; gUnk_0300468C = .;
        . = 0x00004698; gUnk_03004698 = .;
        . = 0x000046A0; gUnk_030046A0 = .;

        . = 0x000047A4; gUnk_030047A4 = .;
        . = 0x000047B0; gUnk_030047B0 = .;
        . = 0x000047B8; gUnk_030047B8 = .;
        . = 0x000047BC; gUnk_030047BC = .;
        . = 0x000047E4; gUnk_030047E4 = .;
        . = 0x00004800; gUnk_03004800 = .;
        . = 0x00004820; gUnk_03004820 = .;
        . = 0x00004824; gUnk_03004824 = .;
        . = 0x00004828; gUnk_03004828 = .;
        . = 0x0000483C; gUnk_0300483C = .;
        . = 0x00004840; gUnk_03004840 = .; 

        . = 0x00004848; gUnk_03004848 = .;
        . = 0x0000484C; gUnk_0300484C = .;
        . = 0x00004850; gUnk_03004850 = .;

        . = 0x00004854; gUnk_03004854 = .;
        . = 0x00004870; gUnk_03004870 = .;
        . = 0x00004890; gUnk_03004890 = .;
        . = 0x00004910; gUnk_03004910 = .;
        . = 0x00004920; gUnk_03004920 = .;
        . = 0x00004980; gUnk_03004980 = .;
        . = 0x00004A88; gUnk_03004A88 = .;
        . = 0x00004AA0; gUnk_03004AA0 = .;
        . = 0x00004D40; gUnk_03004D40 = .;
        . = 0x00004D4C; gUnk_03004D4C = .;
        . = 0x00004DC0; gUnk_03004DC0 = .;

        . = 0x00004F20; gUnk_03004F20 = .;
        . = 0x00004F90; gUnk_03004F90 = .;
        . = 0x00004FA0; src/m4a.o(common_data);
        . = 0x00007FF8; gUnk_03007FF8 = .;
        . = 0x00008000;
    } >iwram

    .text : ALIGN(4) {
        asm/crt0.o(.text);
        src/code_0.o(.text);

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
    }

    .rodata ALIGN(4) : SUBALIGN(4) {
        src/code_0.o(.rodata);
        data/data.o(.rodata);
        src/m4a_tables.o(.rodata);
        data/sound_data.o(.rodata);
        src/agb_sram.o(.rodata);
        . = ORIGIN(rom) + 0x7E83F0;
        data/data1.o(.rodata);

    } >rom =0xFF



    
}

