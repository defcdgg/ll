#ifndef GUARD_MAIN_H
#define GUARD_MAIN_H

#include "global.h"

#ifndef INCLUDE_ASM

#define STR(x) #x

#define INCLUDE_ASM(NAME) \
__attribute__((naked)) void NAME(void){\
    asm(".include \"asm/nonmatching/" STR(NAME) ".inc\"");\
}
#endif




extern u8 gUnk_02005380[];

#define UNK_VRAM_BUFFER (u16*)0x2005800

extern u16 gUnk_03001988;
extern u8 gUnk_03001AC0;
extern u8 gUnk_03001B54;
// extern u8 gUnk_03001B60[];

extern u16 gUnk_030025B4;
extern u16 gUnk_030025FC;
extern u8 gUnk_03002604;
extern s16 gUnk_03002C40;

extern OamData gUnk_030035C0[128];

extern u16 gUnk_03004550;
extern u16 gUnk_03004610;
extern u16 gUnk_03004648;
extern u16 gUnk_03004658;
extern u16 gUnk_03004698;
extern u16 gUnk_03004800[];
extern u16 gUnk_03004828;
extern u16 gUnk_03004848;
extern u16 gUnk_0300484C;




extern void sub_8004ADC();
extern void sub_8002F6C();
extern void sub_8008D18();
extern void sub_805008C();
extern void sub_800B14C();
extern void sub_8005020();
extern void sub_80038CC();

extern void sub_8053838(s32);
extern void sub_805369C(s32);

extern void sub_80533F0();
extern void sub_8053688();
extern void sub_80535F4();

#endif