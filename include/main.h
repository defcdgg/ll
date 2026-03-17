#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"
#include "include_asm.h"



typedef struct
{
    u16 unk0;
    u16 unk2;
    u8 pad[0x5E - 4];
    u8 unk5E;
}Unk_03004F20;



static inline void inl_cpufastset(void*src, void* dst, u32 sz)
{
    CpuFastCopy(src, dst, sz);
}

extern u8 gUnk_02004000[];
extern u8 gUnk_02005380[];

#define VRAM_BUF_2005000 (u16*)0x2005000
#define VRAM_BUF_2005800 (u16*)0x2005800


extern s32 gUnk_03001940;
extern u32 gUnk_03001948;
extern u16 gUnk_03001988;
extern u8 gUnk_030019C0[];

extern u8 gUnk_03001AC0;
extern u32 gUnk_03001AD0;
extern u32 gUnk_03001B50;
extern u8 gUnk_03001B54;
extern u8 gUnk_03001B60[];

extern u32 gUnk_03001CB0;

extern u32 gUnk_03001D30;

extern u8 gUnk_0300259C;
extern u32 gUnk_030025A0;
extern u8 gUnk_030025A4;
extern u32 gUnk_030025A8;

extern u16 gUnk_030025B4;
extern u8 gUnk_030025D8;


extern u8 gUnk_030025F4;
extern u16 gUnk_030025FC;
extern u8 gUnk_03002604;
extern s16 gUnk_03002C40;
extern u8 gUnk_03002C48;

extern u8 gUnk_030032D0;

extern OamData gUnk_030035C0[128];

extern u16 gUnk_03004550;
extern u16 gUnk_03004610;
extern u16 gUnk_03004648;
extern u16 gUnk_03004658;
extern u16 gUnk_0300465C;

extern u16 gUnk_03004698;
extern u16 gUnk_03004800[];
extern u16 gUnk_03004828;
extern u8 gUnk_0300483C;

extern u8 gUnk_03004840;

extern u16 gUnk_03004848;
extern u16 gUnk_0300484C;
extern u8 gUnk_03004854;

extern u8 gUnk_03004910;

extern u8 gUnk_03004D40;

extern u8 gUnk_03004D4C;

extern u8 gUnk_03004DC0;

extern Unk_03004F20 gUnk_03004F20;

extern u16 gUnk_03007FF8;

extern void sub_8001014();
extern void sub_8001090();
extern void sub_8002F6C();
extern void sub_8003264();
extern void sub_8004AC0();
extern void sub_8004ADC();
extern void sub_8004B60();
extern void sub_8004B8C();
extern void sub_8004BBC();

extern void sub_8005020();

extern void sub_8008D18();
extern void sub_8008E94();
extern void sub_8009168();
extern void sub_8009A5C();

extern void sub_800B14C();

extern void sub_8016F30();

extern s32 sub_80171E4();

extern u32 sub_8017588();

extern void sub_8017600(u32*, u32*, u32, u32);
extern void sub_801761C();

extern void sub_8018070();

extern void sub_805008C();
extern void sub_80038CC();

extern void sub_8053838(s32);
extern void sub_805369C(s32);

extern void sub_80533F0();
extern void sub_8053688();
extern void sub_80535F4();



#endif