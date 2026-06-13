#ifndef _IWRAM_H
#define _IWRAM_H

#include "gba/types.h"

#define NULL 0

typedef struct UnkNode
{
    u8 key; // offset 0, 用于比较排序
    u8 pad[3];
    struct UnkNode *prev; // offset 4
    struct UnkNode *next; // offset 8
} UnkNode;

struct LzContext
{
    u8 *dest;
    u8 *src;
    u8 *flags;
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
extern u16 gUnk_03000004;
extern u8 gUnk_03000008;
extern u8 gUnk_0300000A[];
extern u16 gUnk_0300000C;
extern u8 gUnk_03000010[4];
extern u8 gUnk_03000014[4];
extern u8 gUnk_03000018[4];
extern u16 gUnk_03000020[4];
extern u32 gUnk_03000028[4];
extern u8 *gUnk_03000038[4];

typedef struct
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u16 field_A;
    u16 field_C;
    u16 field_E;
} Unk_03000048;
extern Unk_03000048 gUnk_03000048;

typedef struct
{
    /* 0x00 */ u8 statusFlags; // 状态标志
    /* 0x01 */ u8 animTimer; // 动画计时器
    /* 0x02 */ u8 lerpFrame; // 移动倒计时/插值帧 (8 -> 0)
    /* 0x03 */ u8 oamSlotId; // 关联的渲染层 OAM 索引
    /* 0x04 */ s16 x; // 当前实时显示 X 坐标
    /* 0x06 */ s16 y; // 当前实时显示 Y 坐标
    /* 0x08 */ s16 moveStartX; // 移动起始点 A 坐标 X
    /* 0x0A */ s16 moveStartY; // 移动起始点 A 坐标 Y
    /* 0x0C */ s16 moveEndX; // 移动目标点 B 坐标 X
    /* 0x0E */ s16 moveEndY; // 移动目标点 B 坐标 Y
    /* 0x10 */ u16 field_10; // 基础图块起始 ID (BaseTileId)
    /* 0x12 */ u16 pad;
} UISpriteEntity; // Total Size: 0x14 (20 bytes)

typedef struct
{
    u8 statusFlags;
    u8 animTimer;
    u8 lerpFrame;
    u8 oamSlotId;
    s16 x;
    s16 y;
    s16 moveStartX;
    s16 moveStartY;
    s16 moveEndX;
    s16 moveEndY;
    u16 field_10;
    u16 pad;
} Unk_03000058;
extern Unk_03000058 gUnk_03000058[];
extern Unk_03000058 gUnk_030000BC[];

extern u8 gUnk_03000184;
extern u8 gUnk_03000185;
extern u8 gUnk_03000186;
extern u8 gUnk_03000187;
extern u8 gUnk_03000188[];
extern u8 gUnk_03000198;
extern u8 gUnk_03000199;
extern u8 gUnk_030001A0[];
extern u8 gUnk_030001B4[];

extern u8 *gUnk_030001D0[];

extern u8 gUnk_03000220;
extern u8 gUnk_03000221;
extern u8 gUnk_03000224;
extern u8 gUnk_03000225;
extern u8 gUnk_03000226;
extern u8 gUnk_03000227;
extern u32 gUnk_03000248;
extern u16 gUnk_03000312;
extern u16 gUnk_03000314;
extern u8 gUnk_03000316;
extern u16 gUnk_03000324;
extern u32 gUnk_03000328;
extern u8 gUnk_0300032E;
extern u16 gUnk_03000330[];
extern u32 gUnk_03000340;
typedef struct
{
    u8 padding0[8];
    u8 field_8;
    u8 field_9;
    u8 field_A;
    u8 field_B;
    u16 field_C;
    u8 padding1[6];
} Unk_03000348;
extern Unk_03000348 gUnk_03000348[];

extern u16 gUnk_03000384;
extern u16 gUnk_03000386;

extern u8 gUnk_030004D4;
extern u8 gUnk_030004D5;
extern u8 gUnk_030004D6;
extern u8 gUnk_030004D7;

extern u8 gUnk_030004F8;

typedef struct
{
    u16 field_0;
    u16 field_2;
    u16 field_4;
    u16 field_6;
    u16 field_8;
    u16 field_A;
    u16 field_C;
    u16 field_E;
} Unk_03000500;
extern Unk_03000500 gUnk_03000500;
extern u16 gUnk_03000510;
extern u8 gUnk_03000512;
extern u8 gUnk_03000514;

extern u8 gUnk_03000518[0x80];
extern u8 gUnk_03000598[0x80];

extern u32 gUnk_0300062C;
extern u8 gUnk_03000630;
extern u32 gUnk_03000718;
extern u8 gUnk_0300071C;
extern u32 gUnk_03000730;
extern u8 gUnk_0300073D;
extern u8 gUnk_03000744;
extern u8 gUnk_03000748[];
extern u8 gUnk_03000758[];
extern u8 gUnk_03000763;
extern u8 gUnk_03000788[][5];
extern u8 gUnk_030007BA;
extern s8 gUnk_03000814;
extern s8 gUnk_03000815;
extern u8 gUnk_03000816;
extern u8 gUnk_03000826;
extern u8 gUnk_03000865;
extern u16 gUnk_03000882;
extern u8 gUnk_03000889;
extern u8 gUnk_030008F1;
extern u8 gUnk_030008F2;
extern u8 gUnk_030008F3;
extern u16 gUnk_03000906;
extern u8 gUnk_03000910;
extern u8 gUnk_03000911;
extern u8 gUnk_03000948;
extern u8 gUnk_0300097E;

extern u32 gUnk_030009D0;
extern u8 gUnk_03000AD8;
extern u8 gUnk_03000ADD;
extern u16 gUnk_03000ADE;
extern u16 gUnk_03000AE0;
extern u16 gUnk_03000AE2;
extern u8 gUnk_03000D38[];
extern u8 gUnk_03000DDE;
extern u8 gUnk_03000E04;
extern u16 gUnk_03000E70;
extern u16 gUnk_03000F38;
extern u16 gUnk_03000F3A;
extern u16 gUnk_03000F3C;
extern s16 gUnk_03000F3E;
extern u8 gUnk_03000F40;
extern u8 gUnk_03000F41;
extern u8 gUnk_03000F42;
extern u8 gUnk_03000F43;
extern u8 gUnk_03000F50;

extern u8 gUnk_030018F0[0x50];

extern s32 gUnk_03001940;
extern u8 gMainGameState;
extern u32 gGameTimer; // 3001948
extern u32 gUnk_03001950[14];
extern u16 gUnk_03001988;

extern struct LzContext gLzContext; // 3001990

extern u16 gHeldKeysRaw;

extern u8 gUnk_030019C0[];

extern u8 gUnk_03001AC0;
extern u32 gUnk_03001AD0;
extern u32 gUnk_03001B50;
extern u8 gUnk_03001B54;
extern u8 gUnk_03001B60[];

extern u8 gUnk_03001C60[0x40];
extern u16 gNewKeysRaw;
extern u32 gUnk_03001CB0;

extern u32 gUnk_03001D30;
extern u32 gIntrMainBuf[512];

typedef struct
{
    u8 sprNodeIdx;
    u8 field_1;
    u8 field_2;
    u8 paletteId;
    u8 facingDir;
    u8 animTimer;
    s16 x;
    s16 y;
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
    u16 field_14;
    u8 animIdx;
    u8 field_17;
    u8 field_18;
    u8 field_19;
    s16 field_1A;
    u8 gap1C[8];
    u8 *field_24;
} CharacterObject;

extern CharacterObject gUnk_03001EE0[];

extern u8 gUnk_0300259C;
extern u32 gUnk_030025A0;
extern u8 gUnk_030025A4;
extern u32 gUnk_030025A8;
extern u8 gUnk_030025B0;
extern s16 gUnk_030025B4;
extern u8 gUnk_030025B8;
extern u8 gUnk_030025BC;
extern u8 gSpriteWidth;
extern u16 gUnk_030025C0[8];
extern u16 gUnk_030025D4;
extern u8 gUnk_030025D8;
extern u16 gUnk_030025E0[8];
extern u8 gUnk_030025F0;
extern u8 gUnk_030025F4;
extern u16 gUnk_030025F8;
extern s16 gUnk_030025FC;
extern u16 gUnk_03002600;
extern u8 gUnk_03002604;
extern u16 gUnk_03002608;
extern u8 gUnk_0300260C;

extern u8 gSpriteHeight;
extern u8 gUnk_03002C30;
extern u8 gUnk_03002C34;
extern u32 gSilverAmount;
extern u16 gUnk_03002C3C;
extern s16 gUnk_03002C40;
extern u8 gUnk_03002C44;
extern u8 gUnk_03002C48;
extern u16 gUnk_03002C4C;
extern u8 gUnk_03002C50;
extern u8 gUnk_03002C58[8];
extern u8 gUnk_03002C60[];
// extern struct Unk_03003AC0 *gUnk_03002C80[128];

extern CharacterObject gUnk_03002E80[];

// extern Unk_03003150 gUnk_03003150;
// extern Unk_03003150 gUnk_03003178[];

extern CharacterObject gUnk_03003150;
extern CharacterObject gUnk_03003178[];
extern u16 gUnk_03003240;

extern u32 gVramBufferPointers[];

extern u8 gUnk_030032D0;
extern u16 gUnk_030032D4;
extern u8* gUnk_030032E0[];

extern u8 gUnk_03003360[32];

typedef struct
{
    u8 field_0;
    u8 field_1;
    u8 pad[2];
    u32 field_4;
} Unk_03003380;

extern Unk_03003380 gUnk_03003380[32];

extern u8 gUnk_03003480;
extern u8 gUnk_03003490[];
extern u8 gUnk_030034B0;

typedef struct
{
    u16 field_0;
    u16 field_2;
    u16 field_4;
    u16 field_6;
} Unk_030034C0;

extern Unk_030034C0 gUnk_030034C0[];

typedef union
{
    struct
    {
        u32 VPos : 8;
        u32 AffineMode : 2;
        u32 ObjMode : 2;
        u32 Mosaic : 1;
        u32 ColorMode : 1;
        u32 Shape : 2;
        u32 HPos : 9;
        u32 AffineParamNo_L : 3;
        u32 HFlip : 1;
        u32 VFlip : 1;
        u32 Size : 2;

        u16 CharNo : 10;
        u16 Priority : 2;
        u16 Pltt : 4;
        u16 AffineParam;
    } fields;

    u32 attrs[2];

} GameOamData;
extern GameOamData gOamBuffer[128];

typedef struct
{
    void *src;
    void *dest;
} Unk_030039C0;

extern Unk_030039C0 gVramTransferQueue[32];

typedef struct SpriteNode
{
    /* 0x00 */ u8 flags; ///< Flags: bit 0=active, bits 1-7=chain count
    /* 0x01 */ u8 animStep;

    /* 0x02 */ u16 attr0; ///< GBA OAM Attribute 0 (Y pos, shape, mode, affine flags)
                          ///< Bits 0-7: Y coordinate
                          ///< Bits 8-9: Affine mode
                          ///< Bits 10-11: OBJ mode (normal/transparent/window)
                          ///< Bit 12: Mosaic enable
                          ///< Bit 13: Color mode (0=16 color, 1=256 color)
                          ///< Bits 14-15: Shape (square/horizontal/vertical)

    /* 0x04 */ u16 attr1; ///< GBA OAM Attribute 1 (X pos, size, flip, affine param)
                          ///< Bits 0-8: X coordinate
                          ///< Bits 9-11: Affine parameter number (lower 3 bits)
                          ///< Bit 12: Horizontal flip
                          ///< Bit 13: Vertical flip
                          ///< Bits 14-15: Size (depends on shape)

    /* 0x06 */ u16 attr2; ///< GBA OAM Attribute 2 (tile ID, palette, priority)
                          ///< Bits 0-9: Character/tile number
                          ///< Bits 10-11: Display priority
                          ///< Bits 12-15: Palette number

    /* 0x08 */ s16 x; ///< Logical/screen X position (before OAM conversion)
    /* 0x0A */ s16 y; ///< Logical/screen Y position (before OAM conversion)

    /* 0x0C */ struct SpriteNode *next; ///< Pointer to next sprite in chain (multi-tile sprites)

    /* 0x10 */ u16 tileOffsetX; ///< Tile offset X for multi-tile sprites
    /* 0x12 */ u16 tileOffsetY; ///< Tile offset Y for multi-tile sprites

} SpriteNode; // Size: 0x14 (20 bytes)

extern struct SpriteNode *gSpriteRenderQueue[128]; // 3002C80
extern struct SpriteNode gSpriteNodePool[128]; // 3003AC0

/*
struct Unk_03003AC0
{
    u8 field_0;
    u8 animFrame;
    u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 x;
    s16 y;
    struct Unk_03003AC0 *field_C;
    u16 field_10;
    u16 field_12;
};
extern struct Unk_03003AC0 gUnk_03003AC0[128];
*/

extern u32 gUnk_030044C0[];

extern u8 gUnk_03004540;
extern u16 gUnk_03004550;
extern u16 gUnk_03004604;
extern u8 gUnk_03004608;
extern u8 gUnk_0300460C;
extern u16 gHBlankEffectMode;
extern u16 gUnk_03004614;
extern u8 gUnk_03004618;

typedef struct
{
    u8 unk0;
    u8 unk1;
} Unk_03004624;

extern Unk_03004624 gUnk_03004624;
extern u8 *gUnk_0300462C;
extern u8 gUnk_03004634;
extern u8 gUnk_03004638;

extern u16 gBG3ScrollY;
extern u16 gUnk_0300464C;
extern u16 gUnk_03004650;
extern u16 gBlendControl;
extern u16 gUnk_0300465C;
extern u16 gUnk_03004660;
extern u8 gUnk_0300466C;

typedef struct
{
    u8 field_0;
    u8 field_1;
} Unk_03004670;

// extern Unk_03004670 gUnk_03004670;
extern u8 gUnk_03004670[];
extern u16 gUnk_0300467C;
extern u16 gUnk_03004684;
extern u16 gUnk_03004688;
extern u8 gUnk_0300468C;
extern u16 *gUnk_03004694;
extern u16 gUnk_03004698;

typedef struct
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 field_4;
    u8 field_5;
    u8 field_6;
    u8 field_7;
    u8 field_8;
    u8 field_9;
    u16 field_A;
    u8 *field_C;
} Unk_030046A0;

extern Unk_030046A0 gUnk_030046A0[];

extern u8 gUnk_030047A4;
extern s16 gUnk_030047A8;
extern u16 gUnk_030047AC;
extern u16 gUnk_030047B0;
extern u8 gUnk_030047B4;
extern u8 gUnk_030047B8;
extern u8 gUnk_030047BC;

extern u16 gUnk_030047C0;
extern u16 gUnk_030047C4;
extern u16 gUnk_030047C8;
extern u8 *gUnk_030047CC;
// extern Unk_03004670 gUnk_030047D0;
extern u8 gUnk_030047D0[];

extern u8 gUnk_030047E4;
extern u16 gUnk_030047EC;
extern s16 gUnk_030047F0;

extern u16 gUnk_03004800[];
extern u8 gUnk_03004820;
extern u8 gUnk_03004824;

extern u16 gBG2ScrollY;

extern s16 gUnk_03004834;

extern u8 gUnk_0300483C;

extern u8 gUnk_03004840;

extern u16 gBG2ScrollX;
extern u16 gBG3ScrollX;

extern u8 gUnk_03004850;
extern u8 gUnk_03004854;
extern u8 gUnk_03004860;
extern u8 gUnk_03004870[32];

typedef struct
{
    u8 field_0;
    u8 field_1;
    u8 sprNodeIdx;
    u8 field_3;
    s16 x;
    s16 y;
} ChestObject;

extern ChestObject gChestObjects[16];

extern u8 gUnk_03004910;
extern u8 gUnk_03004920;

typedef struct
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u16 animTimer;
    s16 x;
    s16 y;
    s16 z;
    u16 field_C;
    u8 field_E;
    u8 field_F;
    u8 *dataPtr;
} StaticMapObject;

extern StaticMapObject gStaticMapObjects[3]; // gUnk_03004930

extern u8 gInventory[];


extern u8 gUnk_03004A80;
extern u8 gBattleFormationIds[];
extern u8 gUnk_03004A90;
extern u8 gUnk_03004A94;
extern u8 gUnk_03004A98;
extern u8 gPartyMemberIds[];
extern u8 gUnk_03004AA8;
extern u8 gUnk_03004AAC;
extern u8 gUnk_03004AB0;
extern u8 gUnk_03004AB4;
extern u8 gUnk_03004AB8;

extern u8 gUnk_03004D40;

typedef struct
{
    /** 0x00 */ u8 lv;
    /** 0x01 */ u8 field_1;
    /** 0x02 */ u16 hp;
    /** 0x04 */ u16 mp;
    /** 0x06 */ u16 atc;
    /** 0x08 */ u16 def;
    /** 0x0A */ u16 agl;
    /** 0x0C */ u16 men;
    /** 0x0E */ u16 res;
    /** 0x10 */ u8 noa;
    /** 0x11 */ u8 luc;
    /** 0x12 */ u16 max_hp;
    /** 0x14 */ u16 max_mp;
    /** 0x16 */ u8 base_atc;
    /** 0x17 */ u8 base_def;
    /** 0x18 */ u8 base_agl;
    /** 0x19 */ u8 base_men;
    /** 0x1A */ u8 base_res;
    /** 0x1B */ u8 base_noa;
    /** 0x1C */ u8 base_luc;

    /** 0x1D */ u8 equip_atc;
    /** 0x1E */ u8 equip_def;
    /** 0x1F */ u8 equip_agl;
    /** 0x20 */ u8 equip_men;
    /** 0x21 */ u8 equip_res;
    /** 0x22 */ u8 equip_noa;
    /** 0x23 */ u8 equip_luc;

    /** 0x24 */ u8 equip_slot1;
    /** 0x25 */ u8 equip_slot2;
    /** 0x26 */ u8 equip_slot3;
    /** 0x27 */ u8 equip_slot4;
    /** 0x28 */ u8 equip_slot5;
    /** 0x29 */ u8 equip_slot6;

    /** 0x2A */ u8 skills[8];
    /** 0x32 */ u8 field_unk[6];

    /** 0x38 */ u32 exp;
    /** 0x3C */ u32 next_exp;
} PlayerStats;

extern PlayerStats gUnk_03004AC0[];

extern u8 gUnk_03004D44;

extern u8 gUnk_03004D4C;
extern u8 gUnk_03004D50;
extern u8 gUnk_03004D60[];

extern u8 gUnk_03004DC0;
extern u8 gUnk_03004DC4;
extern u8 gUnk_03004DC8[];

extern u8 gUnk_03004DD0;
extern u8 gUnk_03004DD4;
extern u8 gUnk_03004DD8;

extern u8 gUnk_03004DF0[];

typedef struct
{
    u16 unk0;
    u16 unk2;
    u8 pad[0x5E - 4];
    u8 unk5E;
} Unk_03004F20;
extern Unk_03004F20 gUnk_03004F20;

typedef struct
{
    u32 *field_0;
    u32 *field_4;
    u16 field_8;
    u16 field_A;
    u16 field_C;
    u16 field_E;
} Unk_03004F80;

extern Unk_03004F80 gUnk_03004F80;

extern u8 gUnk_03004F90[];

extern u16 gUnk_03007FF8;

typedef struct SaveInfo
{
    /** 0x00 */ char str[12]; // 12
    /** 0x0C */ u32 gameTimer; // 4
    /** 0x10 */ u32 silverAmount; // 4
    /** 0x14 */ u8 field_030047E4; // 1
    /** 0x15 */ u8 field_0300468C; // 1
    /** 0x16 */ u8 field_03004638; // 1
    /** 0x17 */ u8 field_030047A4; // 1
    /** 0x18 */ u16 field_03004614; // 2
    /** 0x1A */ PlayerStats field_03004AC0[10]; // 0x280 (10 * 0x40)
    /** 0x29A */ u16 field_03004624; // 2
    /** 0x29C */ u8 field_03004AA0[6]; // 6
    /** 0x2A2 */ u8 field_03004980[256]; // 0x100
    /** 0x3A2 */ u8 field_03001C60[64]; // 0x40
    /** 0x3E2 */ u8 field_030018F0[64]; // 0x40
    /** 0x422 */ CharacterObject field_03002E80[18]; // 0x2D0 (18 * 0x28)
    /** 0x6F2 */ u8 field_0203F000[0xE00]; // 0xE00
    /** 0x14F2 */ u8 field_0203FE00[0x100]; // 0x100

    /** 0x15F2 */ u16 field_030025F8; // 2
    /** 0x15F4 */ u16 field_03002C3C; // 2
    /** 0x15F6 */ u8 field_030025B0; // 1
    /** 0x15F7 */ u8 field_03004A88[6]; // 6
    /** 0x15FD */ u8 field_03004870[32]; // 0x20
    /** 0x161D */ ChestObject field_03004890[16]; // 0x80 (16 * 8)
    /** 0x169D */ u8 field_03004670[12]; // 0xC
    /** 0x16A9 */ u8 field_030047D0[12]; // 0xC
    /** 0x16B5 */ u8 field_03004850; // 1
    /** 0x16B6 */ u8 field_03002C44; // 1
} SaveInfo; // 总大小: 0x16B7 字节

#endif