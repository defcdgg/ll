#ifndef GUARD_GLOBALS_H
#define GUARD_GLOBALS_H

#include "gba/types.h"


#define A_BUTTON        0x0001
#define B_BUTTON        0x0002
#define SELECT_BUTTON   0x0004
#define START_BUTTON    0x0008
#define DPAD_RIGHT      0x0010
#define DPAD_LEFT       0x0020
#define DPAD_UP         0x0040
#define DPAD_DOWN       0x0080
#define R_BUTTON        0x0100
#define L_BUTTON        0x0200
#define RESET_GAME      0x000F


#define KEYS_MASK       0x03FF
#define KEY_INTR_ENABLE 0x4000
#define KEY_OR_INTR     0x0000
#define KEY_AND_INTR    0x8000
#define DPAD_ANY        ((DPAD_RIGHT | DPAD_LEFT | DPAD_UP | DPAD_DOWN))
#define JOY_EXCL_DPAD   0x030F


typedef void (*IntrFunc)(void);
typedef void (*GameFunc)(void);

void sub_08003088(void);



// GameFunc gGameFuncTable[] = {
//     sub_08003088
// };

// GameFunc gUnk_087E83F8[] = {
//     sub_8001538
// };

typedef struct
{
    u16 unk0;
    u16 unk2;
    u8 pad[0x5E - 4];
    u8 unk5E;
}Unk_03004F20;

struct LzContext
{
    u8* dest;
    u8* src;
    u8* flags;
    u32 unkC;
    u32 bitIndex;
    u32 size;
    u32 processedSize;
    u32 remainingSize;
};


struct Unk_LzData
{
    u32 uncompressedSize;
    u32 size;
    u8 data[1];
};



static inline void inl_cpufastset(void*src, void* dst, u32 sz)
{
    CpuFastCopy(src, dst, sz);
}

extern u8 gUnk_02004000[];
extern u8 gUnk_02005380[];

#define VRAM_BUF_2005000 (u16*)0x2005000
#define VRAM_BUF_2005800 (u16*)0x2005800


extern u16 gUnk_03000000;
extern u16 gUnk_03000002;

extern s32 gUnk_03001940;
extern u8 gUnk_03001944;
extern u32 gUnk_03001948;
extern u16 gUnk_03001988;

extern struct LzContext gLzContext;

extern u8 gUnk_030018F0[0x50];
extern u32 gUnk_03001948;
extern u32 gUnk_03001950[14];
extern u16 gUnk_030019B0;

extern u8 gUnk_030019C0[];

extern u8 gUnk_03001AC0;
extern u32 gUnk_03001AD0;
extern u32 gUnk_03001B50;
extern u8 gUnk_03001B54;
extern u8 gUnk_03001B60[];

extern u8 gUnk_03001C60[0x40];
extern u16 gUnk_03001CA0;
extern u32 gUnk_03001CB0;

extern u32 gUnk_03001D30;

extern u32 gIntrMainBuf[512];

extern u8 gUnk_0300259C;
extern u32 gUnk_030025A0;
extern u8 gUnk_030025A4;
extern u32 gUnk_030025A8;
extern u8  gUnk_030025B0;
extern u16 gUnk_030025B4;
extern s8 gUnk_030025B8;
extern u16 gUnk_030025C0[8];
extern u8 gUnk_030025D8;
extern u16 gUnk_030025E0[8];
extern u8 gUnk_030025F0;
extern u8 gUnk_030025F4;
extern u16 gUnk_030025F8;
extern u16 gUnk_030025FC;
extern u16 gUnk_03002600;
extern u8 gUnk_03002604;
extern u16 gUnk_03002608;
extern u8 gUnk_0300260C;
extern u32 gUnk_03002C38;
extern u16 gUnk_03002C3C;
extern s16 gUnk_03002C40;
extern u8 gUnk_03002C44;
extern u8 gUnk_03002C48;
extern u16 gUnk_03002C4C;
extern u8  gUnk_03002C50;
extern u8  gUnk_03002C58[8];

typedef struct {
    u32 unk0;
    u8 unk4;
    u8 unk5;
    u16 unk6;
    u16 unk8;
    u8 pad[0x2C - 10];
    u8 unk2C;
    u8 unk2D;
    u16 unk2E;
    u16 unk30;
}Unk_03002E80;

extern Unk_03002E80 gUnk_03002E80;

extern u8 gUnk_030032D0;

typedef struct
{
    u32 unk0;
    u32 unk4;
} Unk_030035C0;

extern Unk_030035C0 gUnk_030035C0[128];

extern u16 gUnk_03004550;
extern u8 gUnk_03004608;
extern u16 gUnk_03004610;
extern u16 gUnk_03004614;

typedef struct{
    u8 unk0;
    u8 unk1;
}Unk_03004624;

extern Unk_03004624 gUnk_03004624;
extern u32 gUnk_0300462C;
extern u8 gUnk_03004634;
extern u8 gUnk_03004638;

extern u16 gUnk_03004648;
extern u16 gUnk_03004658;
extern u16 gUnk_0300465C;
extern u8 gUnk_0300466C;



extern u8 gUnk_0300468C;
extern u16 gUnk_03004698;

extern u8 gUnk_030047A4;
extern u8 gUnk_030047B8;
extern u8 gUnk_030047BC;
extern u8 gUnk_030047E4;
extern u16 gUnk_03004800[];
extern s8 gUnk_03004820;
extern u8 gUnk_03004824;

extern u16 gUnk_03004828;
extern u8 gUnk_0300483C;

extern u8 gUnk_03004840;

extern u16 gUnk_03004848;
extern u16 gUnk_0300484C;
extern u8 gUnk_03004850;
extern u8 gUnk_03004854;

extern u8 gUnk_03004910;

extern u8 gUnk_03004980[];

typedef struct{
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    u8 unk4;
    u8 unk5;
}Unk_03004AA0;

extern Unk_03004AA0 gUnk_03004AA0;
extern Unk_03004AA0 gUnk_03004A88;

extern u8 gUnk_03004D40;

extern u8 gUnk_03004D4C;

extern u8 gUnk_03004DC0;

extern Unk_03004F20 gUnk_03004F20;

extern u16 gUnk_03007FF8;


void sub_800065C(void);

extern void IntrMain();

extern void sub_8000170();

extern void sub_800124C();
extern void sub_8016FC0();

extern void DummyIntr3();
extern void DummyIntr4();


extern void sub_8001014();
extern void sub_8001090();
void sub_8002154();
extern void sub_8002F6C();
extern void sub_8003264();
extern void sub_80038CC();
void sub_800445C();
extern void sub_8004AC0();
extern void sub_8004ADC();
extern void sub_8004B60();
extern void sub_8004B8C();
extern void sub_8004BBC();

extern void sub_8005020();
void sub_80089E0(u8);
void sub_8008B14(u16);
extern void sub_8008D18();
extern void sub_8008E94();
extern void sub_8009168();
extern void sub_8009A5C();
void sub_8009B44();
extern void sub_8009B64();

void sub_800A664(u8);
void sub_800A79C(u8);
void sub_800A924();

extern void sub_800B14C();

extern void sub_8016F30();

extern s32 sub_80171E4();

extern u32 sub_8017588();

extern void sub_8017600(u32*, u32*, u32, u32);
extern void sub_801761C();
void sub_8017FA4(s8);
extern void sub_8018070();
extern void sub_801887C();
extern void sub_8021130();

extern void sub_805008C();
void sub_8052580();
void sub_80525E8(u8, u8, u8);
void sub_80526A0(u8, u8);
extern void sub_80533F0();
extern void sub_805359C();
extern void sub_80535F4();
extern void sub_805360C();
extern void sub_8053688();
void sub_805369C(u16 arg0);
void sub_80536EC(s32);
void sub_805374C(s32, s32, s32);
extern void sub_8053838(s32);




#endif /* GUARD_GLOBALS_H */
