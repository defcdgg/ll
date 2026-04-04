#ifndef _IWRAM_H
#define _IWRAM_H

#include "gba/types.h"

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


extern u16 gUnk_03000000;
extern u16 gUnk_03000002;

extern u8 gUnk_03000010[];

extern u8 gUnk_03000DDE;
extern u8 gUnk_03000E04;
extern u16 gUnk_03000E70;
extern u16 gUnk_03000F38;
extern u16 gUnk_03000F3A;
extern u16 gUnk_03000F3C;
extern u16 gUnk_03000F3E;
extern u8 gUnk_03000F40;
extern u8 gUnk_03000F41;
extern u8 gUnk_03000F42;
extern u8 gUnk_03000F43;
extern u8 gUnk_03000F50;


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

extern u8 gUnk_03002C34;
extern u32 gUnk_03002C38;
extern u16 gUnk_03002C3C;
extern s16 gUnk_03002C40;
extern u8 gUnk_03002C44;
extern u8 gUnk_03002C48;
extern u16 gUnk_03002C4C;
extern u8  gUnk_03002C50;
extern u8  gUnk_03002C58[8];

extern u32 gUnk_03002C80[128];

typedef struct {
  u8 field_0;
  u8 field_1;
  u8 field_2;
  u8 field_3;
  u8 field_4;
  u8 field_5;
  u16 field_6;
  u16 field_8;
  u8 field_A;
  u8 field_B;
  u8 field_C;
  u8 field_D;
  u8 field_E;
  u8 field_F;
  u8 field_10;
  u8 field_11;
  u8 field_12;
  u8 field_13;
  u8 field_14;
  u8 field_15;
  u8 field_16;
  u8 field_17;
  u8 field_18;
  u8 field_19;
  u16 field_1A;
  u8 gap1C[8];
  u32 field_24;
}Unk_03002E80;

extern Unk_03002E80 gUnk_03002E80[];

typedef struct 
{
  u8 field_0;
  u8 field_1;
  u8 field_2;
  u8 field_3;
  u8 field_4;
  u8 field_5;
  u16 field_6;
  u16 field_8;
  u8 field_A;
  u8 field_B;
  u8 field_C;
  u8 field_D;
  u8 field_E;
  u8 field_F;
  u8 field_10;
  u8 field_11;
  u8 field_12;
  u8 field_13;
  u8 gap14[3];
  u8 field_17;
  u8 field_18;
  u8 field_19;
  u16 field_1A;
  u8 gap1C[8];
  u32 field_24;
}Unk_03003150;

extern Unk_03003150 gUnk_03003150;

extern u8 gUnk_030032D0;

extern u8 gUnk_03003360[32];

typedef struct
{
    u8 field_0;
    u8 field_1;
    u8 pad[2];
    u32 field_4;
}Unk_03003380;

extern Unk_03003380 gUnk_03003380[32];

typedef struct
{
    u16 field_0;
    u16 field_2;
    u16 field_4;
    u16 field_6;
}Unk_030034C0;

extern Unk_030034C0 gUnk_030034C0[];

typedef struct
{
    u32 field_0;
    u32 field_4;
} Unk_030035C0;

extern Unk_030035C0 gUnk_030035C0[128];


typedef struct
{
    u32 field_0;
    u32 field_4;
}Unk_030039C0;

extern Unk_030039C0 gUnk_030039C0[32];

typedef struct
{
    u8 field_0;
    u8 field_1;
    u16 field_2;
    u16 field_4;
    u16 field_6;
    u8 pad[4];
    u32 field_C;
    u16 field_10;
    u16 field_12;
}Unk_03003AC0;

extern Unk_03003AC0 gUnk_03003AC0[128];

extern u16 gUnk_03004550;
extern u8 gUnk_03004608;
extern u16 gUnk_03004610;
extern u16 gUnk_03004614;

typedef struct{
    u8 unk0;
    u8 unk1;
}Unk_03004624;

extern Unk_03004624 gUnk_03004624;
extern u8* gUnk_0300462C;
extern u8 gUnk_03004634;
extern u8 gUnk_03004638;

extern u16 gUnk_03004648;
extern u16 gUnk_03004658;
extern u16 gUnk_0300465C;
extern u8 gUnk_0300466C;



extern u8 gUnk_0300468C;
extern u16 gUnk_03004698;

typedef struct{
    u8 pad[16];
}Unk_030046A0;

extern Unk_030046A0 gUnk_030046A0[];

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

extern u8 gUnk_03004870[32];

extern u8 gUnk_03004910;
extern u8 gUnk_03004920;
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
typedef struct
{
    u16 unk0;
    u16 unk2;
    u8 pad[0x5E - 4];
    u8 unk5E;
}Unk_03004F20;
extern Unk_03004F20 gUnk_03004F20;

extern u8 gUnk_03004F90[];

extern u16 gUnk_03007FF8;

#endif