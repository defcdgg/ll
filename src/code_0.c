#include "code_0.h"
#include "gba/defines.h"
#include "gba/gba.h"
#include "globals.h"
#include "global_tables.h"
#include "include_asm.h"
#include "iwram.h"
#include "m4a.h"
#include "sound.h"

extern void IntrMain();

typedef void (*IntrFunc)(void);
/*
    MultiSioIntr
    VBlankIntr
    HBlankIntr
    VCountIntr
*/
IntrFunc const gIntrTable[] = {
    sub_8016FC0, sub_800065C, sub_800124C, DummyIntr4, DummyIntr3, DummyIntr3, DummyIntr3,
    DummyIntr3,  DummyIntr3,  DummyIntr3,  DummyIntr3, DummyIntr3, DummyIntr3,
};

u8 const gUnk_080576D0[] = {
    0x00, 0x04, 0x09, 0x0e, 0x13, 0x18, 0x1d, 0x21, 0x26, 0x2a, 0x2f, 0x33, 0x37, 0x3b, 0x3f, 0x43, 0x46, 0x4a, 0x4d, 0x50, 0x53, 0x55,
    0x58, 0x5a, 0x5c, 0x5e, 0x5f, 0x61, 0x62, 0x62, 0x63, 0x63, 0x64, 0x63, 0x63, 0x62, 0x62, 0x61, 0x5f, 0x5e, 0x5c, 0x5a, 0x58, 0x55,
    0x53, 0x50, 0x4d, 0x4a, 0x46, 0x43, 0x3f, 0x3b, 0x37, 0x33, 0x2f, 0x2a, 0x26, 0x21, 0x1d, 0x18, 0x13, 0x0e, 0x09, 0x04, 0x00, 0xfc,
    0xf7, 0xf2, 0xed, 0xe8, 0xe3, 0xdf, 0xda, 0xd6, 0xd1, 0xcd, 0xc9, 0xc5, 0xc1, 0xbd, 0xba, 0xb6, 0xb3, 0xb0, 0xad, 0xab, 0xa8, 0xa6,
    0xa4, 0xa2, 0xa1, 0x9f, 0x9e, 0x9e, 0x9d, 0x9d, 0x9c, 0x9d, 0x9d, 0x9e, 0x9e, 0x9f, 0xa1, 0xa2, 0xa4, 0xa6, 0xa8, 0xab, 0xad, 0xb0,
    0xb3, 0xb6, 0xba, 0xbd, 0xc1, 0xc5, 0xc9, 0xcd, 0xd1, 0xd6, 0xda, 0xdf, 0xe3, 0xe8, 0xed, 0xf2, 0xf7, 0xfc};

u8 const gUnk_08057750[] = {
    0xe8, 0x86, 0xe1, 0x87, 0xdf, 0x8f, 0xed, 0x82, 0x23, 0x45, 0x05, 0x49, 0x1a, 0x71, 0x0a, 0x8b, 0x24, 0x40, 0x3d, 0x4f, 0x29, 0x36,
    0x32, 0x4e, 0xff, 0x85, 0x9f, 0x92, 0x98, 0x30, 0xf1, 0x35, 0x2a, 0xfe, 0x79, 0xfa, 0x80, 0x89, 0x06, 0x9d, 0x43, 0x74, 0x3f, 0x8a,
    0x48, 0xf5, 0x5e, 0xe9, 0xfc, 0x13, 0x77, 0x03, 0x76, 0x61, 0x16, 0x75, 0x27, 0x3c, 0xd6, 0x4a, 0xc1, 0x02, 0xbe, 0x0c, 0x0e, 0x4c,
    0xcc, 0x34, 0xc5, 0x25, 0x00, 0x38, 0xee, 0xa2, 0xc6, 0x14, 0xe0, 0x58, 0xef, 0x5d, 0x1e, 0x9e, 0xec, 0x8c, 0xea, 0x97, 0x1f, 0x83,
    0x31, 0x91, 0x8d, 0xa4, 0x88, 0x2f, 0x5a, 0xa9, 0x9b, 0x53, 0x21, 0x56, 0x4d, 0x78, 0x9a, 0x6f, 0x73, 0x68, 0xfd, 0x52, 0xf9, 0x6b,
    0x8e, 0x5f, 0x37, 0x41, 0x09, 0x5b, 0x08, 0x44, 0x3a, 0x5c, 0x39, 0x67, 0x42, 0x6a, 0x4b, 0x3b, 0x33, 0x1d, 0x22, 0xad, 0xaa, 0x94,
    0x84, 0x60, 0x20, 0x65, 0x55, 0x11, 0x95, 0xa6, 0x90, 0xa0, 0x62, 0x81, 0x59, 0x1b, 0x57, 0x2d, 0x50, 0x2e, 0x6d, 0x19, 0x99, 0x7b,
    0x96, 0x66, 0xab, 0x04, 0x93, 0xaf, 0x9c, 0x7c, 0xae, 0x7f, 0x28, 0x54, 0xa8, 0x6e, 0x01, 0x7d, 0x72, 0x64, 0x7e, 0x69, 0x1c, 0x63,
    0xf3, 0xd1, 0xc9, 0xd8, 0xc4, 0x12, 0xf7, 0x17, 0xa7, 0xfb, 0xdc, 0x15, 0xd7, 0xac, 0xa1, 0x2b, 0xb3, 0xdb, 0xb1, 0xc7, 0xc2, 0xcf,
    0xb2, 0xd0, 0xe6, 0x26, 0xf6, 0xba, 0x0f, 0xc0, 0xc3, 0xd3, 0x0d, 0xd5, 0xd2, 0xda, 0xb7, 0xbc, 0xf4, 0xa3, 0x07, 0xbd, 0xe3, 0xca,
    0xde, 0xd4, 0x2c, 0xcb, 0x6c, 0xf8, 0x10, 0x0b, 0x3e, 0xb4, 0x7a, 0xb5, 0x70, 0xe7, 0xa5, 0xd9, 0xb8, 0xe4, 0x51, 0xe5, 0xe2, 0xb9,
    0x47, 0xbf, 0x46, 0xce, 0xdd, 0xbb, 0xc8, 0x18, 0xb6, 0xeb, 0xb0, 0xf2, 0xcd, 0xf0, 0xff, 0xff, 0xff, 0xff};


/*
//gMoveDirectionLut
u8 const gUnk_0805881C[] ={0, 1, 5, 0, 7, 8, 6,
      0, 3, 2, 4, 0, 0, 0, 0, 0};




      //gUnk_0805887C
const u8 gSpriteTileCountTable[] = {
    1, 4, 16, 64,  // Square: 8x8, 16x16, 32x32, 64x64
    2, 4,  8, 32,  // Horizontal: 16x8, 32x8, 32x16, 64x32
    2, 4,  8, 32,  // Vertical: 8x16, 8x32, 16x32, 32x64
    99, 99, 99, 99 // Invalid/Prohibited Shape
};


//8058834
const u8 gSpriteDimensionsTable[] = {
    8, 8, 16, 16, 32, 32, 64, 64,  // Shape 0 (Square)
    16, 8, 32, 8, 32, 16, 64, 32,  // Shape 1 (Horizontal)
    8, 16, 8, 32, 16, 32, 32, 64,  // Shape 2 (Vertical)

    1, 1, 1, 1, 1, 1, 1, 1,

    15, 0, 0, 0, 252, 255, 228, 255,
    15, 0, 0, 0, 0, 0, 240, 255
};

//8058834
const s8 gSpriteDimensionsTable[] = {
    8, 8, 16, 16, 32, 32, 64, 64,  // Shape 0 (Square)
    16, 8, 32, 8, 32, 16, 64, 32,  // Shape 1 (Horizontal)
    8, 16, 8, 32, 16, 32, 32, 64,  // Shape 2 (Vertical)

    1, 1, 1, 1, 1, 1, 1, 1,

    15, 0, 0, 0, -4, -1, -28, -1,
    15, 0, 0, 0, 0, 0, -16, -1
};
*/
void sub_80002A0(void)
{
    u16 val;

    sub_8004ADC();

    switch (gUnk_03004698)
    {
        case 1:
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            break;
        case 2:
            gUnk_03002C40++;
            REG_BG1HOFS = (gUnk_03002C40 >> 1) & 0xFF;
            REG_BG1VOFS = 0;
            break;
        case 3:
            gUnk_03002C40++;
            REG_BG1HOFS = (gUnk_03002C40 >> 2) & 0xFF;
            REG_BG1VOFS = 0x10;
            break;
        case 4:
            REG_BG1HOFS = 0x40;
            REG_BG1VOFS = 0;
            break;
        case 5:
            REG_BG1HOFS = (s16)((u8)gUnk_030025B4 >> 3);
            REG_BG1VOFS = 0;
            break;
        case 6:
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0x1E;
            break;
        default:
            REG_BG1HOFS = (0x1F & gUnk_030025B4);
            REG_BG1VOFS = (0x1F & gUnk_030025FC);
            break;
    }

    REG_BG2HOFS = gUnk_03004848;
    REG_BG2VOFS = gUnk_03004828;
    REG_BG3HOFS = gUnk_0300484C;
    REG_BG3VOFS = gUnk_03004648;

    DmaCopy16(3, gOamBuffer, OAM, OAM_SIZE);

    sub_8002F6C();
    sub_8008D18();

    if (gUnk_03002604 == 0)
    {
        sub_805008C();
    }

    sub_800B14C();

    if (gUnk_03004800[13] != 0)
    {
        DmaCopy16(3, gUnk_02005380, 0x0600F380, 0x100);
        gUnk_03004800[13] = 0U;
    }

    REG_BLDCNT = gUnk_03004658;
    if (gUnk_03004658 & 0x80)
    {
        REG_BLDY = gUnk_03004550;
    }
    else
    {
        REG_BLDALPHA = gUnk_03004550;
    }

    sub_8005020();
    sub_80038CC();

    switch (gUnk_03004610)
    {
        case 0:
        default:
            break;
        case 1:
        case 3:
            val = (gUnk_03001988 - 1) & 0x3FF;
            gUnk_03001988 = val;
            gUnk_03001B54 = (val >> 2) + gUnk_030025FC;
            break;
        case 2:
        case 4:
            val = (gUnk_03001988 - 1) & 0x7FF;
            gUnk_03001988 = val;
            gUnk_03001B54 = (val >> 3) + gUnk_030025FC;
    }
}

void sub_80004F8(void)
{
    u16 val;

    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;

    DmaCopy16(3, gOamBuffer, OAM, 0x400);

    REG_BLDCNT = gUnk_03004658;
    REG_BLDALPHA = gUnk_03004550;

    DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);

    sub_8005020();
    val = (gUnk_03001988 - 1) & 0x3FF;
    gUnk_03001988 = val;
    gUnk_03001B54 = (val >> 2) + gUnk_030025FC;
}

void sub_80005A8(u16 scanline)
{
    switch (gUnk_03004610)
    {
        case 1:
        case 2:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + scanline) & 0xFF] + (gUnk_030025B4 & 0x1F);
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + scanline) & 0xFF] + (gUnk_030025FC & 0x1F);
            break;

        case 3:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + scanline) & 0xFF];
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + scanline) & 0xFF];
            break;

        case 4:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + scanline) & 0xFF];
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + scanline) & 0xFF];
            break;
    }
}

// VBlankIntr
void sub_800065C(void)
{

    switch (gUnk_0300259C)
    {
        case 1:
            m4aSoundVSync();
            sub_80002A0();
            break;
        case 2:
            m4aSoundVSync();
            sub_8018070();
            break;
        case 3:
            m4aSoundVSync();
            sub_80004F8();
            break;
        case 4:
            m4aSoundVSync();
            sub_8004ADC();

            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 4;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 4;
            REG_BG3VOFS = 0;

            REG_BLDCNT = gUnk_03004658;
            REG_BLDALPHA = gUnk_03004550;

            DmaCopy16(3, gOamBuffer, OAM, 0x400);
            DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);

            if (gUnk_03004DC0 != 0)
            {
                DmaCopy16(3, VRAM_BUF_2005000, 0x0600F000, 0x800);
                gUnk_03004DC0 = 0;
            }

            sub_8005020();
            break;
        case 5:
            sub_8016F30();
            m4aSoundVSync();
            sub_8004ADC();
            sub_8003264();

            // CpuFastCopy(gOamBuffer, (u32*)0x07000000, 0x400);
            CpuCopy(gOamBuffer, (void *)0x07000000, 0x400);

            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 0;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 0;
            REG_BG3VOFS = 0;
            REG_BLDCNT = gUnk_03004658;
            REG_BLDALPHA = gUnk_03004550;

            // CpuFastCopy(gUnk_02005800, 0x0600F800, 0x800);
            CpuCopy(VRAM_BUF_2005800, (void *)0x0600F800, 0x800);

            if (gUnk_03004DC0 != 0)
            {
                // CpuFastCopy(gUnk_02005000, 0x0600F000, 0x800);
                CpuCopy(VRAM_BUF_2005000, (void *)0x0600F000, 0x800);
                gUnk_03004DC0 = 0;
            }

            break;
        case 6:
            m4aSoundVSync();

            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 0;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 0;
            REG_BG3VOFS = 0;

            sub_8004ADC();
            DmaCopy16(3, gOamBuffer, OAM, 0x400);

            sub_8008E94();
            sub_805008C();

            REG_BLDCNT = gUnk_03004658;
            if (gUnk_03004658 & 0x80)
            {
                REG_BLDY = gUnk_03004550;
            }
            else
            {
                REG_BLDALPHA = gUnk_03004550;
            }

            sub_8005020();
            sub_80038CC();
            break;
        default:
            m4aSoundVSync();
            break;
    }

    gUnk_030025A4++;

    if (gGameTimer <= 0x0CDFD7EE)
    {
        gGameTimer++;
    }
    else
    {
        gGameTimer = 0x0CDFD7F0;
    }

    gUnk_030025A0++;
    REG_IME = 0;
    gUnk_03007FF8 |= 1;
    REG_IME = 1;
}

void sub_80008CC(void)
{

    sub_8053838(0);
    sub_8053838(1);
    sub_8053838(2);
    sub_8053838(3);
    sub_805369C(0);
    VBlankIntrWait();

    while (REG_DISPSTAT & 1)
        ;

    sub_80533F0();
    sub_8053688();
    VBlankIntrWait();

    while (REG_DISPSTAT & 1)
        ;

    sub_80533F0();
    sub_80535F4();
    VBlankIntrWait();
    while (REG_DISPSTAT & 1)
        ;

    sub_80533F0();
    VBlankIntrWait();
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
}

s32 sub_800096C(void)
{

    switch (gUnk_03001B50)
    {
        case 0:
            REG_RCNT = 0xC000;
            VBlankIntrWait();
            sub_8017600(&gUnk_03001AD0, &gUnk_03001CB0, 0x10, 0);
            gUnk_03004F20.unk5E = 1;
            gUnk_03004F20.unk2 = 1;
            gUnk_03001B50++;
        case 1:
            gUnk_03001940 = sub_80171E4();

            if (gUnk_03001940 == -1)
            {
                gUnk_030025A8 = 5;
                gUnk_03001B50 = 6;
                break;
            }

            if ((sub_8017588() == 0) && (gUnk_03001940 <= 0xFF))
            {
                if (gUnk_03001D30 == 0)
                {
                    sub_801761C();
                    gUnk_03001B50 = 4;
                    gUnk_030025A8 = 2;
                }
                gUnk_03001D30--;
                break;
            }

            switch (gUnk_03001940)
            {
                case 0:
                case 1:
                    if (gUnk_03001D30 == 0)
                    {
                        sub_801761C();
                        gUnk_03001B50 = 4;
                        gUnk_030025A8 = 2;
                    }
                    else
                    {
                        gUnk_03001D30--;
                    }
                    break;

                case 2:
                    if (sub_8017588() == 0)
                    {
                        sub_801761C();
                        gUnk_03001B50 = 5;
                        gUnk_030025A8 = 3;
                    }
                    else if (gUnk_030025A8 == 0)
                    {
                        gUnk_03004F20.unk5E = 1;
                        gUnk_03004F20.unk2 = 1;
                        gUnk_030025A8 = 1;
                    }
                    break;

                case 0x101:
                case 0x102:
                case 0x103:
                case 0x104:
                    gUnk_030025A8 = 3;
                    gUnk_03001B50 = 5;
                    break;

                default:
                    break;
            }

            break;
        case 2:
        case 3:
        case 4:
            sub_801761C();
            gUnk_03001B50 = 9;
            break;
        case 5:
            sub_801761C();
            gUnk_03001B50 = 9;
            break;
        case 6:
            gUnk_03001B50 = 0;
            break;
        case 7:
            sub_801761C();
            break;
        case 8:
            if (gUnk_030025A8 == 0)
            {
                sub_801761C();
                gUnk_03001B50 = 0;
            }
            break;
        case 9:
            sub_801761C();
            gUnk_03001B50 = 8;
            break;
    }

    return sub_8017588();
}

void sub_8000B58(u32 arg0)
{
    u16 i;

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)PLTT, PLTT_SIZE);
    DmaFill16(3, 0, &gUnk_02004000, 0x2000);

    sub_8004B8C();
    sub_8004BBC();

    gGameTimer = 0;
    gUnk_030032D0 = 0;
    gUnk_03002604 = 0;
    gUnk_03004910 = 0;
    gUnk_03004840 = 0;
    gUnk_0300465C = 0;
    gUnk_030025F4 = 0xFF;

    for (i = 0; i < 16; i++)
    {
        gUnk_03004800[i] = 0;
    }

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8009A5C();
    sub_8001090();
    sub_8001014();
    sub_8009168();

    gUnk_0300259C = 0;
    gUnk_03004D4C = 0;
    gUnk_03004D40 = 0;
    gUnk_03004854 = 0;
    gUnk_030025D8 = 0;
    gUnk_0300483C = 0;
    gUnk_03002C48 = 0;
}

void sub_8000C98(u16 arg0)
{

    u16 i;
    u8 mask;
    s8 stepH, stepV;
    s8 divH, divV;

    mask = 0x7F;
    switch (arg0)
    {
        case 1:
            divH = 12;
            stepH = 32;
            divV = 12;
            stepV = 16;
            break;
        case 2:
            divH = 16;
            stepH = 8;
            divV = 4;
            stepV = 16;
            mask = 0x3F;
            break;
        case 3:
            divH = 16;
            stepH = 32;
            divV = 32;
            stepV = 4;
            break;
        case 4:
            divH = 4;
            stepH = 1;
            divV = 16;
            stepV = 1;
            mask = 0x3F;
            break;
        default:
            return;
    }

    for (i = 0; i < 255; i++)
    {
        gUnk_03001B60[i] = gUnk_080576D0[(i * stepH) & mask] / divH;
        gUnk_030019C0[i] = gUnk_080576D0[(i * stepV) & mask] / divV;
    }
}

u32 sub_8000D5C(void)
{
    u8 flag;
    u32 bit_offset;
    u16 lz_token;
    s32 match_length;
    s32 match_offset;
    s32 i;

    if (gLzContext.size > gLzContext.remainingSize)
    {
        gLzContext.size = gLzContext.remainingSize;
    }

    gLzContext.processedSize = 0;

    if (gLzContext.size >= 0)
    {
        while (gLzContext.size > gLzContext.processedSize)
        {
            flag = gLzContext.flags[gLzContext.bitIndex >> 3];
            bit_offset = gLzContext.bitIndex & 7;

            if ((flag >> bit_offset) & 1)
            {
                lz_token = gLzContext.src[0] + (gLzContext.src[1] << 8);
                gLzContext.src += 2;

                match_offset = (lz_token & 0x0FFF) + 1;
                match_length = (lz_token >> 12) + 3;

                for (i = 0; i < match_length; i++)
                {
                    *gLzContext.dest = *(gLzContext.dest - match_offset);
                    gLzContext.dest++;
                    gLzContext.processedSize++;
                }
            }
            else
            {
                *gLzContext.dest++ = *gLzContext.src++;
                gLzContext.processedSize++;
            }

            gLzContext.bitIndex++;
        }
    }

    if (gLzContext.remainingSize > gLzContext.size)
    {
        gLzContext.remainingSize -= gLzContext.processedSize;
        return gLzContext.remainingSize;
    }

    return 0;
}

void sub_8000E1C(u8 arg0)
{

    REG_IME = 0;

    if (arg0 == 0)
    {
        gUnk_0300259C = 4;
        DmaCopy16(3, IntrMain, gIntrMainBuf, sizeof(gIntrMainBuf));
        REG_IE = INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_GAMEPAK;
        REG_DISPSTAT = REG_DISPSTAT | 0x10;
    }
    else
    {
        gUnk_0300259C = 5;
        DmaCopy16(3, sub_8000170, gIntrMainBuf, sizeof(gIntrMainBuf));
        REG_IE = 0xFFFD & REG_IE;
        REG_DISPSTAT = 0xFFEF & REG_DISPSTAT;
    }

    INTR_VECTOR = &gIntrMainBuf;
    REG_IME = 1;
}

void sub_8000ED8(void)
{

    while ((REG_VCOUNT & 0xFF) > 0xC8)
        ;

    REG_DISPCNT &= 0xFF7F;
    VBlankIntrWait();

    while (REG_DISPSTAT & DISPSTAT_VBLANK)
        ;

    sub_805360C();
    sub_805369C(0);
    VBlankIntrWait();

    while (REG_DISPSTAT & DISPSTAT_VBLANK)
        ;

    sub_80533F0();
}

void sub_8000F54(void)
{
    gUnk_0300259C = 0;
    gMainGameState = 0xB;
    gUnk_03002600 = 0;
    sub_8053688();
    VBlankIntrWait();
    sub_80533F0();
    sub_80535F4();
    VBlankIntrWait();
    sub_80533F0();
}

void nullsub_5() { }

void sub_8000F94(void)
{
    VBlankIntrWait();
    sub_80533F0();
}

void sub_8000FA4(void)
{
    VBlankIntrWait();
    while (REG_DISPSTAT & DISPSTAT_VBLANK)
        ;
    sub_80533F0();
}

void sub_8000FD0(u8 *dest, struct Unk_LzData *arg1, u32 arg2)
{
    u8 *ptr;

    gLzContext.unkC = arg1->uncompressedSize;
    gLzContext.remainingSize = gLzContext.unkC;
    gLzContext.dest = dest;
    ptr = arg1->data;
    gLzContext.src = ptr;
    gLzContext.flags = ptr + arg1->size;
    gLzContext.bitIndex = 0;
    gLzContext.size = arg2;
}

u8 sub_8000FF8(void)
{
    return gUnk_08057750[gUnk_030025A4++];
}

void sub_8001014(void)
{
    u16 i;

    for (i = 0; i < 0x40; i++)
    {
        gUnk_03001C60[i] = 0;
    }
}

u8 sub_8001030(u16 arg0)
{
    return gUnk_03001C60[arg0 >> 3] & (1 << (arg0 & 7));
    // return gUnk_03001C60[arg0 / 8] & (1 << (arg0 % 8));
}

void sub_8001050(u16 arg0)
{
    gUnk_03001C60[arg0 >> 3] |= (1 << (arg0 & 7));
}

void sub_8001070(u16 arg0)
{
    gUnk_03001C60[arg0 >> 3] &= ~(1 << (arg0 & 7));
}

void sub_8001090(void)
{
    u16 i;

    for (i = 0; i < 0x50; i++)
    {
        gUnk_030018F0[i] = 0;
    }
}

u8 sub_80010AC(u16 arg0)
{
    return gUnk_030018F0[arg0 >> 3] & (1 << (arg0 & 7));
}

void sub_80010CC(u16 arg0)
{
    gUnk_030018F0[arg0 >> 3] |= 1 << (arg0 & 7);
}

void sub_80010EC(u16 arg0)
{
    gUnk_030018F0[arg0 >> 3] &= ~(1 << (arg0 & 7));
}

void sub_800110C(void)
{
    u16 i;

    for (i = 0x3D; i < 0x50; i++)
    {
        gUnk_030018F0[i] = 0;
    }
}

void sub_8001128(void)
{
    RegisterRamReset(3);
    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1;
    gUnk_03001AC0 = 0;
    sub_8009B64();
    DmaCopy32(3, gIntrTable, gUnk_03001950, sizeof(gUnk_03001950));
    DmaCopy16(3, IntrMain, gIntrMainBuf, sizeof(gIntrMainBuf));

    INTR_VECTOR = gIntrMainBuf;
    gMainGameState = 0xB;
    gUnk_03002600 = 0;

    REG_IE = INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_GAMEPAK;
    REG_DISPSTAT = DISPSTAT_HBLANK_INTR | DISPSTAT_VBLANK_INTR;
    REG_IME = 1;

    VBlankIntrWait();
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON
        | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON;
    ;
    sub_8000B58(0);
    sub_805359C();
    sub_8021130();
    gUnk_03002600 = 0;
}

void sub_80011F0(void)
{
    u16 key;

    key = ~REG_KEYINPUT;
    gUnk_03001CA0 = key & ~gUnk_030019B0;
    gUnk_030019B0 = key;
}

void sub_800121C(void)
{
    u16 key;

    key = ~REG_KEYINPUT;
    gUnk_03001CA0 = key & ~gUnk_030019B0;
    gUnk_030019B0 = key;
}

void DummyIntr3() { }

void sub_800124C(void)
{
    switch (gUnk_0300259C)
    {
        case 1:
        case 3:
            sub_80005A8(0xFF & REG_VCOUNT);
            break;
        case 2:
            sub_801887C();
            break;
    }
}

void DummyIntr4() { }

void DummyIntr5() { }

void sub_800128C(void)
{
    gUnk_03001AC0 = 0;
    sub_8001128();

    while (1)
    {
        gMainTasks[gUnk_03001AC0]();
        VBlankIntrWait();
        sub_80533F0();
    }
}

void sub_80012B8(void)
{
    sub_8016F30();
    m4aSoundVSync();
    sub_8004ADC();
    sub_8003264();
    CpuFastSet(gOamBuffer, (void *)0x07000000, 0x100);

    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BLDCNT = gUnk_03004658;
    REG_BLDALPHA = gUnk_03004550;

    CpuFastSet(VRAM_BUF_2005800, (void *)0x0600F800, 0x200);
    if (gUnk_03004DC0 != 0)
    {
        CpuFastSet(VRAM_BUF_2005000, (void *)0x0600F000, 0x200);
        gUnk_03004DC0 = 0;
    }
}

void sub_8001354(void)
{
    u16 i;
    u8 temp_r6;
    s32 temp_r7;

    sub_80008CC();
    temp_r6 = gUnk_0300259C;
    gUnk_0300259C = 0;
    temp_r7 = gUnk_03004608;
    gUnk_03004610 = 0;
    sub_8009A5C();
    gUnk_030025F8 = gUnk_0300468C * 8;
    gUnk_03002C3C = gUnk_03004638 * 8;
    if (gUnk_03004854 != 0)
    {
        gUnk_030025B4 = gUnk_030025F8;
        gUnk_030025FC = gUnk_03002C3C;
    }
    sub_8004B8C();
    sub_8004BBC();
    sub_8004BE0();

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8008A3C();
    sub_8009F48();
    sub_8003348();
    gUnk_030025B0 = gUnk_030047A4;
    sub_80040E4();
    sub_800445C();
    sub_800661C(gUnk_030047E4);
    sub_800729C(gUnk_030047E4);
    sub_80033E8(gUnk_030047E4);
    sub_8008B14(gUnk_03004614);
    sub_8008F28(gUnk_030047E4);
    sub_8009BF0(gUnk_03004920);
    sub_8009C84(gUnk_03004920);

    gUnk_0300259C = temp_r6;

    if ((sub_8052574() & 1) == 0)
    {
        sub_80526A0(0xFF, 2);
        sub_8050014();
    }

    sub_8002154();

    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if ((sub_8052574() & 1) == 0)
    {
        sub_8009B44();
        sub_80089E0(3);
    }

    gUnk_03002C50 = 2;
    gMainGameState = 1;
    gUnk_03002600 = 0;
    sub_8000ED8();

    if (gUnk_030025F4 != 0xFF || gUnk_03004608 == 0)
        return;

    if (temp_r7 == gUnk_03004608)
    {
        sub_805369C(0);
        sub_8000FA4();
        sub_8053720();
        sub_8000FA4();
        sub_80536C0(4);
    }
    else
    {
        sub_805369C(0);
        sub_8000FA4();
        sub_8053688();
        sub_8000FA4();
        sub_8053628(gUnk_03004608, 0);
        sub_8000FA4();
        sub_80536C0(4);
    }
}

void sub_8001538(void)
{
    u8 i;
    u16 i1;

    gUnk_030025F4 = 0xFF;
    gUnk_030025D8 = 0;
    gUnk_03000000 = 0;
    gUnk_03000002 = 0;
    gUnk_03002600 = 0;
    gUnk_03002C4C = 0;
    gUnk_03002608 = 0;
    gUnk_03002C44 = 0;
    gUnk_0300260C = 0;
    gUnk_03004624.unk0 = 0;
    gUnk_03004624.unk1 = 0;

    gUnk_0300259C = 1;
    gUnk_030047E4 = 0x82;
    gUnk_0300468C = 0;
    gUnk_03004638 = 0;
    gUnk_030047A4 = 0;
    gUnk_03004614 = 0;
    gUnk_03004AA0[0] = 0;
    gUnk_03004AA0[1] |= 0xFF;
    gUnk_03004AA0[2] |= 0xFF;
    gUnk_03004AA0[3] |= 0xFF;
    gUnk_03004AA0[4] |= 0xFF;
    gUnk_03004AA0[5] |= 0xFF;
    gUnk_03004A88[0] = 0;
    gUnk_03004A88[1] |= 0xFF;
    gUnk_03004A88[2] |= 0xFF;
    gUnk_03004A88[3] |= 0xFF;
    gUnk_03004A88[4] |= 0xFF;
    gUnk_03004A88[5] |= 0xFF;

    sub_800A924();

    for (i = 0; i < 11; i++)
    {
        sub_800A664(i);
        sub_800A79C(i);
    }

    gUnk_03004980[0xDD] = 2;
    gUnk_03002C38 = 0x12C;
    gGameTimer = 0;
    gUnk_030025F8 = 0x60;
    gUnk_03002C3C = 0x50;

    sub_8052580();

    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if (gUnk_030025F0 == 0)
    {
        gUnk_03004634 = 1;
        gUnk_03004850 = 1;
        sub_80525E8(1, 0, 1);

        for (i1 = 0; i1 < 16; i1++)
        {
            sub_8000FA4();
        }
    }
    else
    {
        sub_80525E8(0, 0, 1);
        for (i1 = 0; i1 < 4; i1++)
        {
            sub_8000FA4();
        }
    }
    sub_80526A0(1, 2);
    gMainGameState = 1;
    gUnk_03002600 = 0;
}

void sub_8001708(void)
{
    u16 i;

    if (gUnk_03004840 == 0 && gUnk_03002600 == 1)
    {
        gUnk_030025F8 = gUnk_0300468C << 3;
        gUnk_03002C3C = gUnk_03004638 << 3;

        if (gUnk_03004854 != 0)
        {
            gUnk_030025B4 = gUnk_030025F8;
            gUnk_030025FC = gUnk_03002C3C;
        }

        sub_8008B14(gUnk_03004614);
        gUnk_030025B0 = gUnk_030047A4;
        sub_800445C();

        for (i = 0; i < 8; i++)
        {
            gUnk_030025C0[i] = gUnk_03002E80[0].x;
            gUnk_030025E0[i] = gUnk_03002E80[0].y;
            gUnk_03002C58[i] = gUnk_03002E80[0].facingDir;
        }

        gUnk_03002E80[1].x = gUnk_03002E80[0].x;
        gUnk_03002E80[1].y = gUnk_03002E80[0].y;
        gUnk_03002E80[1].facingDir = gUnk_03002E80[0].facingDir;

        sub_80089E0(3);
        gUnk_03002C50 = 2;
        gMainGameState = 1;
        gUnk_03002600 = 0;
    }
    else
    {

        if (gUnk_03002600 != 1)
        {
            gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
            gUnk_03002600 = 1;
            sub_8009B44();
            sub_80089E0(4);
        }
    }

    sub_8002154();
}

void sub_8001828(void)
{
    u16 i;
    u8 val;
    val = gUnk_03004840;

    if (val == 0 && gUnk_03002600 == 1)
    {
        sub_80008CC();
        gUnk_0300259C = val;
        gUnk_03002600 = val;

        if (gUnk_03002C48 != 0)
        {
            gUnk_03002C48++;
            sub_8017FA4(gUnk_030025B8);
        }
        else
        {
            sub_8017FA4(gUnk_03004820);
        }

        gUnk_03001AC0 = 1;
        gUnk_0300259C = 2;
    }
    else
    {
        if (gUnk_03002600 != 1)
        {
            gUnk_03002600 = 1;
            sub_8009B44();
            sub_80089E0(4);
            sub_805374C(0x16, 0, 0);
            sub_80536EC(0x2E);
        }
        sub_8002154();
    }
}

void sub_80018D4(void)
{
    s16 i;

    REG_IME = 0;
    sub_8009A5C();
    gUnk_0300259C = 0;
    sub_8004BE0();

    for (i = 0; i < 0x80; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    if (gUnk_03002C48 != 0)
    {
        gUnk_03002C48++;

        if (gUnk_03002C34 == 2)
        {
            sub_8008DD8();
            REG_WIN0H = 0xF0;
            REG_WIN0V = 0xA0;
            REG_DISPCNT |= DISPCNT_WIN0_ON;
            REG_WININ = 0;
            REG_WINOUT = 0;
            gUnk_0300259C = 1;
            gMainGameState = 1;
            gUnk_03002600 = 0;
            REG_IME = 1;
            sub_8000ED8();
            return;
        }
    }
    sub_800445C();
    gUnk_0300259C = 1;
    REG_IME = 1;
    sub_800661C(gUnk_030047E4);

    if (!(1 & sub_8052574()))
    {
        sub_80525E8(gUnk_03004850, 0, 1);
    }

    sub_8008C70();
    sub_8008B14(gUnk_03004614);
    sub_8009BF0(gUnk_03004920);

    gMainGameState = 1;
    gUnk_03002600 = 0;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if (gUnk_03002C48 == 0 || (gUnk_03002C34 != 1))
    {
        sub_8009B44();
        sub_80089E0(3);
    }

    sub_8000ED8();

    if (gUnk_03004608 != 0)
    {
        sub_8000FA4();
        sub_8053628(gUnk_03004608, 0);
        sub_8000FA4();
        sub_80536C0(4);
    }

    sub_8002154();
}

void sub_8001A7C(void)
{
    s32 var_r4;

    if (gUnk_03004840 == 0 && gUnk_03002600 == 1)
    {
        sub_80008CC();
        sub_8009A5C();
        sub_8004B8C();
        sub_8004BBC();
        sub_8004BE0();
        sub_8007D5C(gUnk_030047BC);
        sub_8008B5C();
        sub_80040E4();
        gUnk_030025B4 = 0;
        gUnk_030025FC = 0;
        gUnk_030025B0 = 4;
        sub_8009B44();
        sub_80089E0(3);
        gUnk_03002600 = 0;
        gMainGameState = 9;
        sub_8004E04();
        sub_8008124();

        sub_8008CC0(*(u8 *)(gUnk_0300462C + gUnk_0300466C) & 0xF);

        gUnk_030025F8 = gUnk_03004824;
        gUnk_03002C3C = gUnk_030047B8;
        gUnk_03002E80[1].x = gUnk_03004824;
        gUnk_03002E80[1].y = gUnk_030047B8 - 8;
        gUnk_03002E80[1].field_12 |= 0x10u;
        gUnk_03002E80[1].facingDir = 4;
        sub_80081C0();
        sub_8000ED8();
        gUnk_03004608 = 0;

        var_r4 = sub_8001030(0x39) != 0 ? 6 : 5;

        sub_8000FA4();
        sub_8053628(var_r4, 0);
        sub_8000FA4();
        sub_80536C0(4);
        return;
    }

    if (gUnk_03002600 != 1)
    {
        gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
        gUnk_03002600 = 1;
        sub_8009B44();
        sub_80089E0(4);
        sub_80536EC(0x2E);
    }

    sub_8002154();
}
void sub_8001BD0(void)
{
    s16 i;

    sub_8009A5C();
    sub_8004BE0();

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8008A3C();
    sub_8009F48();
    sub_8052580();

    gUnk_0300260C = 0;
    gUnk_03004854 = 0;
    gUnk_030025F4 = 0xFF;

    DmaCopy16(3, (void *)0x0203F000, gRenderObjects, 0xA00);
    DmaCopy16(3, (void *)0x0203FE00, (void *)0x030034C0, 0x100);

    sub_800445C();
    sub_8004358();
    sub_800661C(gUnk_030047E4);
    sub_80525E8(gUnk_03004850, 0, 1);
    sub_8008C70();
    sub_8008B14(gUnk_03004614);
    sub_8009BF0(gUnk_03004920);
    sub_8009C84(gUnk_03004920);

    gMainGameState = 1;
    gUnk_03002600 = 0;

    sub_8009B44();
    sub_80089E0(3);

    gUnk_03002C50 = 2;

    sub_8000ED8();

    if (gUnk_03004608 != 0)
    {
        sub_8053628(gUnk_03004608, 0);
        sub_8002154();
        sub_8000FA4();
        sub_80536C0(4);
    }
    sub_8002154();
}

INCLUDE_ASM("asm/matchings", sub_8001D08);
/*
extern u8 gUnk_0805881C[];

void sub_8001D08(void)
{
    u8 val;
    u8 idx;
    u8 moveSpeed;

    idx = 0;

    gUnk_03002E80[0].field_12 &= ~0x40;

    if ((sub_8052574() & 1) == 0)
    {
        gUnk_030025D8 = 0;
        if (gUnk_030025F0 && (gUnk_0300465C & 0x80) == 0 && !gUnk_03004840)
        {
            gMainGameState = 0xB;
            gUnk_03002600 = 5;
            return;
        }
    }
    else
    {
        gUnk_030025D8 = 1;
        if (gUnk_030025F0 && (gUnk_0300465C & 0x80) == 0 && !gUnk_03004840 && (gUnk_03001CA0 & 0x30F) != 0)
        {
            sub_8052728(1);
            gMainGameState = 0xB;
            gUnk_03002600 = 5;
            return;
        }
    }

    if ((gUnk_030019B0 & DPAD_ANY) == DPAD_ANY)
    {
        //Reset Game
        sub_8052728(1);
        sub_8000F54();
        return;
    }

    if (gUnk_03004D4C == 0 && gUnk_0300260C == 0)
    {
        if (!gUnk_030025D8 && (gUnk_0300465C & 0x80) == 0 && !gUnk_03004840)
        {
            if (gUnk_03002C50 != 0)
            {
                gUnk_03002C50--;
                gUnk_03001CA0 = 0;
                gUnk_030019B0 = 0;
            }

            if (gUnk_03003480 != 0xFF)
            {
                sub_80526A0(gUnk_03003480, 2);
                gUnk_03003480 = 0xFF;
            }
            else
            {
                if (gUnk_03001CA0 & A_BUTTON)
                {
                    val = sub_8003F40();
                    if (val != 0)
                    {
                        sub_80526A0(val - 1, 2);
                    }
                }
                else if (gUnk_03001CA0 & B_BUTTON)
                {
                    sub_800ACC8();
                }
                if ((sub_8052574() & 1) != 0)
                {
                    gUnk_030025D8 = 1;
                }

                //gUnk_030025D8 = 1     表示当前正在对话，无法移动
                //gUnk_03004D4C = 0xD   菜单界面，无法移动

                if (gUnk_030025D8 || gUnk_03004D4C)
                {
                    moveSpeed = 0;
                }
                else
                {
                    if (sub_8002D54() != 0)
                    {
                        //gMainGameState = 5 立即进入战斗界面
                        gMainGameState = 5;
                        return;
                    }

                    if (gUnk_030019B0 & DPAD_UP)
                    {
                        idx = 1;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }
                    else if (gUnk_030019B0 & DPAD_DOWN)
                    {
                        idx = 2;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }
                    if (gUnk_030019B0 & DPAD_LEFT)
                    {
                        idx |= 4;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }
                    else if (gUnk_030019B0 & DPAD_RIGHT)
                    {
                        idx |= 8;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }

                    if (gUnk_0805881C[idx])
                    {
                        gUnk_030025B0 = gUnk_0805881C[idx] - 1;
                        moveSpeed = 2;
                    }
                    else
                    {
                        moveSpeed = 0;
                    }
                }
                // MovePlayer(&x, &y, direction, moveSpeed);
                sub_80055E8(&gUnk_030025F8, &gUnk_03002C3C, gUnk_030025B0 + 1, moveSpeed);
            }
        }
    }
    else if (gUnk_03004D4C != 0)
    {
        sub_800ACC8();
    }
    else
    {
        //gUnk_0300260C = 1  开始播放传送动画
        switch (gUnk_0300260C)
        {
            case 1:
                gUnk_0300260C = 2;
                break;
            case 2:
                sub_80046DC(0x78, 0, 0xA);
                sub_8000F94();
                sub_80046DC(0x79, 1, 0xA);
                sub_8000F94();
                gUnk_0300260C = 3;
                break;
            case 3:
                sub_805374C(0x19, 0, 0);
                sub_800384C();
                sub_8004FA8(0x12, 0);
                gUnk_0300260C = 4;
                break;
            case 4:
                if (sub_8004FD0(0x12) != 0)
                {
                    sub_805374C(0x1A, 0, 0);
                    sub_8004D38(0);
                    sub_8004D38(1);
                    sub_8004FA8(0x12, 1);
                    gUnk_0300260C = 5;
                }
                break;
            case 5:
                if (sub_8004FD0(0x12) != 0)
                {
                    gMainGameState = 3;
                    sub_8004D38(0x12);
                    gUnk_0300260C = 9;
                }
                break;
            case 6:
                sub_805374C(0x1A, 0, 0);
                sub_80046DC(0x7A, 0, 0xA);
                sub_8000F94();
                sub_80046DC(0x7B, 1, 0xA);
                sub_8000F94();
                sub_800384C();
                sub_8004FA8(0x12, 0);
                gUnk_0300260C = 7;
                break;
            case 7:
                if (sub_8004FD0(0x12) != 0)
                {
                    sub_805374C(0x19, 0, 0);
                    sub_8004FA8(0x12, 1);
                    gUnk_0300260C = 8;
                }
                break;
            case 8:
                if (sub_8004FD0(0x12) != 0)
                {
                    gUnk_0300260C = 0;
                    sub_8004D38(0x12);
                }
                break;
            case 9:
                if ((0x80 & gUnk_0300465C) || (gUnk_03004840 != 0))
                {
                    gUnk_0300260C = 10;
                }
                break;

            case 10:
                if (!(0x80 & gUnk_0300465C) && (gUnk_03004840 == 0))
                {
                    gUnk_0300260C = 6;
                }
                break;
        }
    }

    if (gUnk_030025D8 != 0)
    {
        gUnk_03002E80[0].field_12 |= 0x40;
    }
    sub_8050014();
    sub_8002DDC();
    sub_8002154();
}
*/
void sub_8002154(void)
{
    u16 i;
    u16 ret0;
    CharacterObject *ptr03002E80;
    ChestObject *ptr03004890;

    sub_8005C70();
    sub_8008A60();
    sub_80053B4(gUnk_030025B4, gUnk_030025FC);

    if (gUnk_0300467C != 0xFF)
    {
        if ((gUnk_0300467C & 0x80) != 0 && gUnk_0300467C < 0xFE)
        {
            i = 0;
            ptr03002E80 = gUnk_03002E80;
            do
            // for(; i < 19; i++)
            {
                if (ptr03002E80->renderObjIdx && (ptr03002E80->field_1 & 1) != 0)
                {
                    ret0 = sub_8003C54(i);
                    if (ret0 == 1 && ptr03002E80->field_24)
                    {
                        ptr03002E80->field_10++;
                        ret0 = 2;
                    }
                    if (ret0 <= 1)
                    {
                        sub_8003B08(i);
                    }
                    sub_800271C(i);
                    sub_800243C(sub_8004EDC(ptr03002E80), ptr03002E80->y, ptr03002E80->renderObjIdx, sub_8004EB8(ptr03002E80),
                                ptr03002E80->field_1);
                    if (ptr03002E80->field_18)
                    {
                        gRenderObjects[ptr03002E80->field_18].field_0 = 0;
                        gRenderObjects[ptr03002E80->field_18].subObject = 0;
                        ptr03002E80->field_18 = 0;
                    }
                    sub_8002380(i);
                }
                ptr03002E80++;
                i++;
            } while (i < 19);
        }
        else
        {
            sub_800445C();
            i = 2;
            ptr03002E80 = &gUnk_03002E80[i];
            do
            // for( ; i < 19; i++)
            {
                if (ptr03002E80->renderObjIdx)
                {
                    if (!gUnk_03004D4C && (!gUnk_0300260C || gUnk_0300260C == 9) && (ptr03002E80->field_12 & 0x88) != 8)
                    {
                        ret0 = sub_8003C54(i);
                        if (ret0 == 1 && ptr03002E80->field_24)
                        {
                            ptr03002E80->field_10++;
                            ret0 = 2;
                        }
                        if (ret0 <= 1)
                        {
                            sub_8003B08(i);
                        }
                    }
                    sub_800271C(i);
                    if (ptr03002E80->field_18)
                    {
                        gRenderObjects[ptr03002E80->field_18].field_0 = 0;
                        gRenderObjects[ptr03002E80->field_18].subObject = 0;
                        ptr03002E80->field_18 = 0;
                    }
                    if (sub_800243C(ptr03002E80->x, ptr03002E80->y, ptr03002E80->renderObjIdx, ptr03002E80->field_1A, ptr03002E80->field_1))
                    {
                        ptr03002E80->field_12 |= 8;
                    }
                    else
                    {
                        ptr03002E80->field_12 &= ~8;
                        sub_8002380(i);
                    }
                }
                ptr03002E80++;
                i++;
            } while (i < 19);
        }

        for (i = 0; i < 16; i++)
        {
            if (gChestObjects[i].renderObjIdx)
            {
                sub_800243C(gChestObjects[i].x, gChestObjects[i].y, gChestObjects[i].renderObjIdx, 0, 255);
            }
        }
    }

    sub_8009D34();
    sub_80032BC();
    sub_80091C4();
}

void sub_8002380(u8 arg0)
{
    CharacterObject *temp_r4;
    struct RenderObject *temp_r0;
    u8 flag;

    if ((gUnk_030025A0 & 1) == (arg0 & 1))
    {
        temp_r4 = &gUnk_03002E80[arg0];
        if (!(temp_r4->field_1 & 2))
        {
            if (temp_r4->field_18 == 0)
            {
                temp_r4->field_18 = sub_8004BFC();
            }
            temp_r0 = &gRenderObjects[temp_r4->field_18];

            flag = (temp_r4->field_1 & 1);

            if (flag != 0)
            {
                temp_r0->attr0 = 0x4000;
                temp_r0->attr1 = 0x4000;
                temp_r0->attr2 = 0x892;
                temp_r0->field_10 = 0x1F4;
                temp_r0->field_12 = 0xFC;
            }
            else
            {
                temp_r0->attr0 = 0x4000;
                temp_r0->attr1 = flag;
                temp_r0->attr2 = 0x892;
                temp_r0->field_10 = flag;
                temp_r0->field_12 = 0xFA;
            }
            temp_r0->field_0 = 1;
            temp_r0->animFrame = 0;

            sub_800243C(sub_8004EDC(temp_r4), temp_r4->y - 0xA0, temp_r4->field_18, -0xA0, 0xFE);
        }
    }
}
INCLUDE_ASM("asm/matchings", sub_800243C);
INCLUDE_ASM("asm/nonmatchings", sub_800271C);

INCLUDE_ASM("asm/nonmatchings", sub_80029D8);
INCLUDE_ASM("asm/nonmatchings", sub_8002B54);

// UpdateEncounter
u8 sub_8002D54(void)
{

    // gEncounterEnabled
    if (gUnk_03004820 == 0)
        return 0;

    if (gUnk_030019B0 & DPAD_ANY)
    {
        if (sub_8001030(0xBB) == 0)
        {
            // gEncounterTimer
            gUnk_030025D4--;
            if (gUnk_030025D4 == 0)
            {
                // Rand
                gUnk_030025D4 = ((sub_8000FF8() & 7) << 5) + 0xE8;
                if (gUnk_030047B0 == 0x7B)
                {
                    gUnk_030025D4 >>= 1;
                }
                return 1;
            }
        }
        else
        {
            if (gUnk_030025D4 < 0xE8)
            {
                gUnk_030025D4 = 0xE8;

                if (gUnk_030047B0 == 0x7B)
                {
                    gUnk_030025D4 = 0x74;
                }
            }
        }
    }

    return 0;
}

void sub_8002DDC(void)
{

    if (gUnk_03002604 == 0)
    {
        return;
    }
    switch (gUnk_03002604)
    {
        case 1:
            REG_DISPCNT &= 0xFEFF;
            gUnk_03004658 = 0x1E41;
            gUnk_03004550 = 0xF00;
            gUnk_03000004 = 0;
            return;

        case 2:
        case 3:
        case 4:
        case 10:
            break;

        case 5:
            REG_DISPCNT |= 0x100;
            gUnk_03004550 = 0xF00;
            gUnk_03002604++;
            break;

        case 6:
            gUnk_03000004++;
            gUnk_03004550 &= 0xF00;
            gUnk_03004550 |= (gUnk_03000004 >> 2) & 0x1F;
            if ((gUnk_03000004 >> 2) == 0x1F)
            {
                gUnk_03002604++;
                gUnk_03000004 = 0;
            }
            break;

        case 7:
            gUnk_03000004++;
            if (!(gUnk_03000004 & 3))
            {
                gUnk_03004550 -= 0x100;
                if (!(gUnk_03004550 & 0xFF00))
                {
                    gUnk_03002604++;
                    gUnk_03000004 = gUnk_03004550 & 0xFF00;
                }
            }
            break;

        case 8:
            gUnk_03000004++;
            if (gUnk_03000004 > 0x1B3)
            {
                gUnk_03002604++;
                gUnk_03000004 = 0;
            }
            break;
        case 9:
            gUnk_03000004++;
            gUnk_03004550 = (((gUnk_03000004 >> 2) & 0x1F) << 8) | ((0x1F - (gUnk_03000004 >> 2)) & 0x1F);
            if (gUnk_03004550 == 0x1F00)
            {
                gUnk_03002604++;
                gUnk_03000004 = 0;
            }
            break;
    }
}

extern u8 pltt_08057854[];
extern u8 tilemap_08057874[];
extern u8 tileset_1_08057A80[];
extern u8 tileset_2_08057EEC[];
extern u8 tileset_3_080583C4[];
#define GET_PLTT(n)    ((n) + 0)
#define GET_TILEMAP(n) ((n) + 32)
// INCLUDE_ASM("asm/nonmatchings", sub_8002F6C); //Matched

void sub_8002F6C(void)
{

    switch (gUnk_03002604)
    {
        case 1:
            REG_BG0CNT = BGCNT_SCREENBASE(31) | BGCNT_CHARBASE(2);
            DmaCopy16(3, (void *)GET_PLTT(pltt_08057854), (void *)0x050001C0, 0x20);
            LZ77UnCompVram((void *)GET_TILEMAP(pltt_08057854), (void *)BG_SCREEN_ADDR(31));
            gUnk_03002604++;
            break;
        case 2:
            LZ77UnCompVram(tileset_1_08057A80, (void *)0x06008000);
            gUnk_03002604++;
            break;
        case 3:
            LZ77UnCompVram(tileset_2_08057EEC, (void *)0x06008800);
            gUnk_03002604++;
            break;
        case 4:
            LZ77UnCompVram(tileset_3_080583C4, (void *)0x06009000);
            gUnk_03002604++;
            break;
        case 10:
            REG_DISPCNT &= 0xFEFF;
            gUnk_03004658 = 0x1C12;
            gUnk_03004550 = 0xC07;
            CpuFill16(0, (void *)0x0600F800, 0x800);

            gUnk_03002604 = 0;
        default:
            return;
    }
}

void sub_8003088(void)
{
    sub_800121C();
    sub_8004BE0();
    gUnk_087E83F8[gMainGameState]();
}

void sub_80030B0()
{
    if (gUnk_03004840 == 0 && gUnk_03002600 == 1)
    {
        gMainGameState = 2;
        gUnk_0300259C = 1;
    }
    else if (gUnk_03002600 != 1)
    {
        gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
        gUnk_03002600 = 1;
        sub_8009B44();
        sub_80089E0(4U);
    }
    sub_8002154();
}

void sub_8003114(void)
{
    sub_800ACC8();
    sub_800C194();
    sub_80032BC();
}

void sub_8003128(void)
{
    if (!(0x80 & gUnk_0300465C) && (gUnk_03004840 == 0))
    {
        sub_8008254(gUnk_03001CA0);
    }
    sub_80081C0();
    sub_800445C();
    sub_80032BC();
    sub_80091C4();
}

void sub_8003168()
{
    if (gUnk_03004840 == 0 && gUnk_03002600 == 1)
    {
        sub_80043D4();
        gMainGameState = 2;
        gUnk_0300259C = 1;
    }
    else if (gUnk_03002600 != 1)
    {
        gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
        gUnk_03002600 = 1;
        sub_8009B44();
        sub_80089E0(4);
        sub_80536EC(0x2E);
    }
    sub_80081C0();
    sub_800445C();
    sub_80032BC();
    sub_80091C4();
}

void sub_80031E4()
{
    sub_8011454();
    sub_80091C4();
    sub_80032BC();
}

void sub_80031F8()
{
    sub_801417C();
    sub_80032BC();
}

void sub_8003208(void)
{
    u16 i;

    sub_8003348();
    sub_8004BE0();
    sub_8004B8C();
    sub_8004BBC();

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8008A3C();
    sub_8009F48();
    sub_80032BC();
}

void sub_8003254(u8 arg0)
{
    sub_80029D8(arg0);
}

void sub_8003264()
{
    u16 i;
    u32 var_r3;

    for (i = 0; i < 32; i++)
    {
        if (gUnk_03003380[i].field_1 != 0)
        {
            var_r3 = gUnk_03003380[i].field_1 == 2 ? 0x40 : 0x20;
            DmaCopy16(3, gUnk_03003380[i].field_4, 0x05000000 + (gUnk_03003380[i].field_0 << 5), var_r3);
            gUnk_03003380[i].field_1 = 0;
        }
    }
}

// http://localhost/scratch/IeynD
INCLUDE_ASM("asm/matchings", sub_80032BC);

void sub_8003348(void)
{
    CharacterObject *ptr2E80;
    u8 renderObjIdx;
    s16 i;
    u8 count;
    struct RenderObject *cur;
    struct RenderObject *next;

    for (i = 0; i <= 23; i++)
    {
        ptr2E80 = &gUnk_03002E80[i];
        renderObjIdx = ptr2E80->renderObjIdx;

        if (renderObjIdx != 0)
        {

            if (ptr2E80->field_18 != 0)
            {
                gRenderObjects[ptr2E80->field_18].field_0 = 0;
                gRenderObjects[ptr2E80->field_18].subObject = 0;
                ptr2E80->field_18 = 0;
            }

            count = gRenderObjects[renderObjIdx].field_0;
            count &= 0x7F;
            cur = &gRenderObjects[renderObjIdx];

            while (count != 0)
            {
                cur->field_0 = 0;
                next = cur->subObject;
                cur->subObject = 0;
                cur = next;
                count--;
            }
        }
        gUnk_03002E80[i].renderObjIdx = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80033E8);
INCLUDE_ASM("asm/nonmatchings", sub_800345C);
void sub_800375C(u8 arg0)
{
    u8 temp_r1;
    CharacterObject *ptr3150;
    ptr3150 = &gUnk_03003178[arg0];
    temp_r1 = sub_8004BFC();
    if (temp_r1 < 0x70)
    {
        ptr3150->renderObjIdx = 0;
        ptr3150->field_1 = 2;
        ptr3150->field_2 = 9;
        ptr3150->paletteId = 9;
        ptr3150->facingDir = 0;
        ptr3150->x = (gUnk_030025B4 + (arg0 * 5 + 5) * 8);
        ptr3150->y = (gUnk_030025FC + 0x28);
        ptr3150->field_A = 0;
        ptr3150->field_B = 0;
        ptr3150->field_C = 0;
        ptr3150->field_D = 0;
        ptr3150->field_F = 0;
        ptr3150->field_13 = 0x80;
        ptr3150->field_24 = 0;
        ptr3150->animTimer = 0;
        ptr3150->field_E = 0;
        ptr3150->field_10 = 1;
        ptr3150->field_11 = 0;
        ptr3150->field_12 = 0x20;
        ptr3150->field_17 = 0;
        ptr3150->field_1A = 0;
        ptr3150->field_18 = 0;
        ptr3150->field_19 = 0;
        ptr3150->field_14 = 0;
        ptr3150->vramBufferIdx = 0xFF;
    }
}

void sub_80037DC(u8 arg0)
{
    u8 idx;
    CharacterObject *ptr03002E80;
    struct RenderObject *renderObj;

    ptr03002E80 = &gUnk_03002E80[arg0];

    idx = sub_8004BFC();
    if (idx < 0x70)
    {
        renderObj = &gRenderObjects[idx];
        ptr03002E80->renderObjIdx = idx;
        ptr03002E80->field_1 = 2;
        ptr03002E80->field_2 = 5;
        ptr03002E80->paletteId = 5;
        ptr03002E80->facingDir = 0;
        ptr03002E80->field_A = 0;
        ptr03002E80->field_B = 0;
        ptr03002E80->field_C = 0;
        ptr03002E80->field_D = 0;
        ptr03002E80->field_F = 0;
        ptr03002E80->field_13 = 0;
        ptr03002E80->field_24 = 0;
        ptr03002E80->animTimer = 0;
        ptr03002E80->field_E = 0;
        ptr03002E80->field_10 = 1;
        ptr03002E80->field_11 = 0;
        ptr03002E80->field_12 = 32;
        ptr03002E80->field_17 = 0;
        ptr03002E80->field_1A = 0;
        ptr03002E80->field_18 = 0;
        ptr03002E80->field_19 = 0;
        renderObj->field_0 = 0;
        renderObj->animFrame = 0;
        renderObj->subObject = 0;
    }
}

void sub_800384C(void)
{
    u8 temp_r1;
    CharacterObject *ptr3150;
    struct RenderObject *renderObj;

    ptr3150 = &gUnk_03003150;
    temp_r1 = sub_8004BFC();
    if (temp_r1 < 0x70)
    {
        renderObj = &gRenderObjects[temp_r1];
        ptr3150->renderObjIdx = temp_r1;
        ptr3150->field_1 = 2;
        ptr3150->field_2 = 0xA;
        ptr3150->paletteId = 0xA;
        ptr3150->facingDir = 0;
        ptr3150->x = (gUnk_030025F8 + 8);
        ptr3150->y = (gUnk_03002C3C + 0xC);
        ptr3150->field_A = 0;
        ptr3150->field_B = 0;
        ptr3150->field_C = 0;
        ptr3150->field_D = 0;
        ptr3150->field_F = 0;
        ptr3150->field_13 = 0x80;
        ptr3150->field_24 = 0;
        ptr3150->animTimer = 0;
        ptr3150->field_E = 0;
        ptr3150->field_10 = 1;
        ptr3150->field_11 = 0;
        ptr3150->field_12 = 0x20;
        ptr3150->field_17 = 0;
        ptr3150->field_1A = 0;
        ptr3150->field_18 = 0;
        ptr3150->field_19 = 0;
        renderObj->field_0 = 128;
        renderObj->animFrame = 0;
        renderObj->subObject = 0;
    }
}
INCLUDE_ASM("asm/matchings", sub_80038CC);

// extern u8* gUnk_087E8430[];
// extern u16 gUnk_030032D4;
// extern u8 gUnk_03004540;
// extern u16 gUnk_03003240;

// extern u8 gUnk_080B9DFC[][32];
// extern u8 gUnk_030034B0;

// static inline void CopySprite(u8 id1, u16 idx)
// {
//     u8* dst = (void*)0x06011400 + id1 * 0x900;
//     LZ77UnCompVram(gUnk_087E8430[idx],   dst);
// }
// static inline void CopySpritePal(u8 id1, u16 idx)
// {
//     u8* src;
//     u8* dst;
//     src = gUnk_080B9DFC[idx];
//     dst = (void*)0x05000200 + id1 * 32;
//     DmaCopy16(3, src , dst ,0x20);
// }

// void sub_80038CC(void) {

//     if (1 & gUnk_030032D0)
//     {
//         // CopySprite((void*)0x06011400 + gUnk_03004540 * 0x900,gUnk_030032D4);
//         CopySprite(gUnk_03004540, gUnk_030032D4);
//     }
//     if (2 & gUnk_030032D0)
//     {
//         CopySpritePal(gUnk_030034B0, gUnk_03003240);
//     }
//     gUnk_030032D0 = 0;
// }
INCLUDE_ASM("asm/nonmatchings", sub_8003958);
void sub_8003B08(u16 arg0) {
    u8 var_r5;
    u8* temp_r2;
    CharacterObject* chara;
    u8 cmd;

    chara = &gUnk_03002E80[arg0];
    
    if(chara->field_24 != 0)
    {
        var_r5 = 0;
        while(var_r5 == 0)
        {
            temp_r2 = chara->field_24 + chara->field_17;
            cmd = *temp_r2++;
            switch(cmd)
            {
                case 0xFE:
                    chara->field_17 = 0;
                    break;
                case 0xFD:
                    chara->field_12 |= 0x20;
                    chara->field_12 &= 0x7F;
                    // chara->field_12 = (chara->field_12 | 0x20) & 0x7F;
                    chara->field_24 = NULL;
                    return;
                case 0xFF:
                    chara->field_12 &= 0x7B;
                    chara->field_24 = NULL;
                    var_r5++;
                    break;
                case 3:
                    chara->field_E = temp_r2[0];
                    chara->field_17 += 2;
                    break;
                case 1:
                    chara->field_17 += 3;
                    chara->field_E = temp_r2[0];
                    chara->facingDir = chara->field_E;
                    chara->field_F = 0;
                    chara->field_10 = cmd;
                    chara->field_11 = temp_r2[1];
                    var_r5++;
                    break;
                    
                case 2:
                    chara->field_12 |=  0x10;
                    chara->field_17 += 4;

                    chara->field_E = *temp_r2++;
                    chara->field_E &= 7;
                    
                    chara->field_F = temp_r2[0];
                    chara->field_10 = temp_r2[1] + 1;
                    return;
                
                default:
                    chara->field_17 += 4;
                    chara->field_E = temp_r2[0] ;
                    temp_r2++;
                    chara->field_F = temp_r2[0];
                    chara->field_10 = temp_r2[1] + 1;
                    var_r5++;
                break;
                    
            }
            chara->field_E &= 7;
            chara->facingDir = chara->field_E;
        }
        return;
    }
    

    if(gUnk_030025D8 == 0)
    {
        switch ((sub_8000FF8() & 7))
        {
            case 1:
            case 4:
            case 5:
            case 6:
                chara->field_11 = 0x10;
                chara->field_10 = 1;
                break;
            case 2:
                chara->field_E++;
                break;
            case 3:
                chara->field_E--;
                break;
            case 7:
                break;
        }
        
        chara->field_E &= 7;
        chara->facingDir = chara->field_E;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8003C54);
INCLUDE_ASM("asm/nonmatchings", sub_8003F40);
INCLUDE_ASM("asm/nonmatchings", sub_80040E4);
INCLUDE_ASM("asm/nonmatchings", sub_8004358);
INCLUDE_ASM("asm/nonmatchings", sub_80043D4);
INCLUDE_ASM("asm/nonmatchings", sub_800445C);
INCLUDE_ASM("asm/nonmatchings", sub_80046DC);
INCLUDE_ASM("asm/nonmatchings", sub_800478C);

INCLUDE_ASM("asm/matchings", sub_8004980);
// typedef struct{
//     u8 unk0;
//     u8 unk1;
//     u8 unk2;
//     u8 unk3;
// }Unk_087E94FC;

// extern u8 gUnk_03003480;
// extern u8 gUnk_03004618;
// extern u16 gUnk_030047B0;
// extern Unk_087E94FC gUnk_087E94FC[];

// void sub_8004980(void) {
//     u8 i;

//     gUnk_03003480 = 0xFF;

//     for(i = 0; i < 22; i++)
//     {
//         if(gUnk_087E94FC[i].unk0 == gUnk_030047B0)
//         {
//             gUnk_03004618 = i + 1;
//             return;
//         }
//     }
//     gUnk_03004618 = 0;
// }

void sub_80049C8(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{

    CharacterObject *ptr = &gUnk_03002E80[arg0];

    if (arg1)
    {
        ptr->y = ((arg2 + 1) << 3) + arg3;
    }
    else
    {
        ptr->x = (arg2 << 3) + arg3;
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_8004A00);
// void sub_8004A00(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
// {
//     s16 val;
//     CharacterObject *ptr2E80;

//     if (arg2 != 0)
//     {
//         val = arg3;
//     }
//     else
//     {
//         val = -arg3;
//     }

//     ptr2E80 = &gUnk_03002E80[arg0];

//     if (arg1 != 0)
//     {
//         ptr2E80->y += val;
//     }
//     else
//     {
//         ptr2E80->x += val;
//     }
// }

u16 sub_8004A44(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        if (gUnk_03003360[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

u8 sub_8004A6C()
{
    u8 i;

    for (i = 0; i < 32; i++)
    {
        if (gUnk_03003380[i].field_1 == 0)
        {
            return i;
        }
    }
    return -1;
}

void sub_8004A94(u8 arg0, u32 arg1, s8 arg2, u8 arg3)
{

    gUnk_03003380[arg0].field_0 = arg2;
    gUnk_03003380[arg0].field_4 = arg1;

    if (arg3 != 0)
    {
        gUnk_03003380[arg0].field_1 = 2;
    }
    else
    {
        gUnk_03003380[arg0].field_1 = 1;
    }
}

void sub_8004AC0(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        gUnk_03003360[i] = 0;
    }
}

void sub_8004ADC(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        if (gUnk_03003360[i] != 0)
        {
            DmaCopy16(3, gVramTransferQueue[i].src, gVramTransferQueue[i].dest, gUnk_03003360[i] << 5);
            gUnk_03003360[i] = 0;
        }
    }
}

void sub_8004B2C(u16 arg0, void* arg1, void* arg2, u8 arg3)
{

    if (arg0 < 32)
    {
        gVramTransferQueue[arg0].src = arg1;
        gVramTransferQueue[arg0].dest = arg2;
        gUnk_03003360[arg0] = arg3;
    }
}

void sub_8004B60()
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        gUnk_03003380[i].field_1 = 0;
        gUnk_03003380[i].field_0 = 0;
        gUnk_03003380[i].field_4 = 0;
    }
}

void sub_8004B8C()
{
    u16 i;

    for (i = 0; i < 128; i++)
    {
        gRenderObjects[i].field_0 = 0;
        gRenderObjects[i].subObject = 0;
    }
}

void sub_8004BBC(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        gUnk_030034C0[i].field_0 = 0;
        gUnk_030034C0[i].field_2 = 0;
        gUnk_030034C0[i].field_4 = 0;
        gUnk_030034C0[i].field_6 = 0;
    }
}

void sub_8004BE0(void)
{
    u16 i;
    for (i = 0; i < 128; i++)
    {
        gRenderObjectPtrSortList[i] = 0;
    }
}

u8 sub_8004BFC(void)
{
    u16 i;

    for (i = 2; i < 0x70; i++)
    {
        if (gRenderObjects[i].field_0 == 0)
        {
            return i;
        }
    }
    return 0;
}
static inline u8 findEmpty_Inl()
{
    u16 i;
    for (i = 2; i < 0x70; i++)
    {
        if (gRenderObjects[i].field_0 == 0)
        {
            return i;
        }
    }
    return 0;
}

struct RenderObject *sub_8004C28(struct RenderObject *obj, u8 arg1, u16 arg2, u16 arg3, u16 arg4)
{
    u8 foundIndex;

    obj->field_0 = arg1;
    obj->attr0 = arg2;
    obj->attr1 = arg3;
    obj->attr2 = arg4;
    obj->animFrame = 0;

    if ((arg1 & 0x7F) == 1)
        return 0;

    foundIndex = findEmpty_Inl();

    if (foundIndex == 0)
    {
        return 0;
    }

    obj->subObject = &gRenderObjects[foundIndex];
    return &gRenderObjects[foundIndex];
}
INCLUDE_ASM("asm/matchings", sub_8004C8C);
// extern u8* gUnk_087E8430[];
// LoadSpriteGfx
// void sub_8004C8C(u8 arg0, u16 arg1) {
//     u8* src;
//     u16* dst;

//     dst = (u16*)0x06011400 + (arg0 * 0x480);
//     // src = gUnk_087E8430[arg1];
//     LZ77UnCompVram(gUnk_087E8430[arg1],  dst);
// }

INCLUDE_ASM("asm/matchings", sub_8004CB8);
// extern u8 gUnk_080B9DFC[][0x20];
// LoadSpritePal
// void sub_8004CB8(u8 arg0, u16 arg1) {
//     u8* src;
//     u16* dst;

//     src = gUnk_080B9DFC[arg1];
//     dst = (u16*)0x05000200 + (arg0 * 0x10);

//     DmaCopy16(3, src, dst, 0x20);
// }
INCLUDE_ASM("asm/matchings", sub_8004CE8);
// extern u8 gUnk_08393728[];
// extern u8 gUnk_08393768[];

// void sub_8004CE8(s8 arg0) {

//     u8* src;
//     u16 size;

//     if( arg0 >= 0)
//     {
//         src = gUnk_08393728;
//         size = 0x40;
//     }
//     else
//     {
//         src = gUnk_08393768;
//         size = 0x80;
//     }

//     DmaCopy16(3, src, 0x06011240, size);
// }

void sub_8004D20(u8 arg0, u8 arg1, u8 arg2)
{
    CharacterObject *p;
    p = &gUnk_03002E80[arg0];

    p->field_2 = arg1;
    p->paletteId = arg2;

    // gUnk_03002E80[arg0].unk2 = arg1;
    // gUnk_03002E80[arg0].unk3 = arg2;
}

void sub_8004D38(u8 arg0)
{
    CharacterObject *ptr2E80;
    struct RenderObject *node;
    struct RenderObject *next;

    ptr2E80 = &gUnk_03002E80[arg0];

    node = &gRenderObjects[ptr2E80->renderObjIdx];

    if (node->field_0 != 0)
    {
        node->field_0 = 0;

        next = node->subObject;
        if (next != 0)
        {
            do
            {
                node->subObject = 0;
                node = next;
                if (node->field_0 == 0)
                    break;
                node->field_0 = 0;
                next = node->subObject;
            } while (next != 0);
        }
    }

    ptr2E80->renderObjIdx = 0;
}
void sub_8004D8C(u8 arg0, u8* arg1)
{
    CharacterObject *ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];
    ptr2E80->field_24 = arg1;
}
void sub_8004DA4(u8 arg0)
{
    CharacterObject *ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];
    ptr2E80->field_12 |= 0x80;
    ptr2E80->field_12 &= 0xDF;
    ptr2E80->field_10 = 1;
    ptr2E80->field_17 = 0;
    ptr2E80->field_11 = 0;
}
s32 sub_8004DD0(void)
{
    u8 i;
    CharacterObject *ptr2E80;
    ptr2E80 = gUnk_03002E80;

    for (i = 0; i < 0x18; i++)
    {
        if (ptr2E80->renderObjIdx != 0 && ptr2E80->field_12 & 0x80)
            return 1;
        ptr2E80++;
    }

    return 0;
}
void sub_8004E04(void)
{
    gUnk_03002C44 |= 1;
}
void sub_8004E14(u8 arg0, u16 arg1)
{
    gUnk_03004670[arg0] = arg1;

    gUnk_03004540 = arg0;
    gUnk_030032D4 = arg1;
    gUnk_030032D0 |= 1;
}

void sub_8004E48(u8 arg0, u16 arg1)
{
    gUnk_030047D0[arg0] = arg1;
    gUnk_030034B0 = arg0;
    gUnk_03003240 = arg1;
    gUnk_030032D0 |= 2;
}
u8 sub_8004E7C(void)
{
    return gUnk_030032D0;
}
void sub_8004E88(u8 arg0, s32 arg1, s32 arg2, u8 arg3)
{
    CharacterObject *ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];

    ptr2E80->x = arg1 * 8;
    ptr2E80->y = arg2 * 8;
    ptr2E80->field_11 = 0;
    ptr2E80->facingDir = arg3;
    ptr2E80->field_E = arg3;
}

u16 sub_8004EB8(CharacterObject *arg0)
{
    if (arg0->field_12 & 1)
    {
        return arg0->field_1A + sub_8008D78();
    }

    return arg0->field_1A;
}
s16 sub_8004EDC(CharacterObject *arg0)
{
    if (arg0->field_12 & 1)
    {
        switch (gUnk_0300460C)
        {
            case 2:
                return arg0->x - (gUnk_030047C0 - 256);
            case 5:
                return arg0->x - (gUnk_030047C0 - gUnk_030025B4);
        }
    }
    return arg0->x;
}
void sub_8004F3C(struct RenderObject *arg0)
{

    struct RenderObject *node;
    struct RenderObject *next;

    if (arg0->field_0 == 0)
        return;

    arg0->field_0 = 0;

    node = arg0->subObject;

    if (node == 0)
        return;

    do
    {
        arg0->subObject = 0;
        arg0 = node;
        if (node->field_0 == 0)
            break;
        node->field_0 = 0;
        node = arg0->subObject;
    } while (node != 0);
}
INCLUDE_ASM("asm/matchings", sub_8004F64);
// typedef struct GameOamData1{
//     u32 attr0;
//     u32 attr1;
// }GameOamData1;
// extern GameOamData1 gOamBuffer[128];

// struct Unk_03002C80* sub_8004F64(u16* ptrIndex, struct Unk_03002C80* arg1) {

//     if(arg1->count < 0 )
//     {
//         return arg1->next;
//     }

//     if(*ptrIndex < 128)
//     {
//         gOamBuffer[*ptrIndex].attr0 = arg1->attr0 + (arg1->attr1 << 16);
//         gOamBuffer[*ptrIndex].attr1 = arg1->attr2;

//         (*ptrIndex)++;
//     }

//     return arg1->next;
// }

void sub_8004FA8(u8 arg0, u8 arg1)
{
    CharacterObject *ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];
    ptr2E80->field_1 |= 1;
    ptr2E80->field_14 = 0;
    ptr2E80->vramBufferIdx = arg1;
}
s32 sub_8004FD0(u8 arg0)
{
    CharacterObject *ptr;

    if (arg0 < 0x64)
    {
        ptr = &gUnk_03002E80[arg0];

        gUnk_03002C60[ptr->vramBufferIdx] &= 0x7F;

        if (ptr->field_14 > 0xFE)
            return 1;
    }
    else
    {
        ptr = &gUnk_03001EE0[arg0];
        ptr->field_14 = 0xFF;
        return 1;
    }

    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8005020);
INCLUDE_ASM("asm/nonmatchings", sub_80051D0);
INCLUDE_ASM("asm/nonmatchings", sub_800526C);
INCLUDE_ASM("asm/nonmatchings", sub_80052F8);
INCLUDE_ASM("asm/nonmatchings", sub_80053B4);
INCLUDE_ASM("asm/nonmatchings", sub_80055E8);
u16 *sub_8005B2C(s16 x, s16 y)
{
    s16 screenX, screenY;
    s16 tileX, tileY;
    u16 *buf;

    screenX = x - (gUnk_030025B4 & ~0xF);

    screenY = y - (gUnk_030025FC & ~0xF);

    if (screenX < 0 || screenY < 0 || screenX > 240 || screenY > 160)
    {
        return 0;
    }

    tileX = screenX >> 3;
    tileY = screenY >> 3;

    if (gUnk_03004688 == 0)
    {
        return (u16 *)0x02004000 + (tileY * 32) + tileX;
    }
    else
    {
        return (u16 *)0x02004800 + (tileY * 32) + tileX;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8005BB4);
INCLUDE_ASM("asm/nonmatchings", sub_8005C70);
INCLUDE_ASM("asm/nonmatchings", sub_80064AC);
INCLUDE_ASM("asm/matchings", sub_8006520);
/*
typedef struct {
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
  u8 field_A;
  u8 field_B;
  u16 field_C;
  u16 field_E;
  u16 field_10;
  u16 field_12;
}Unk_08088D80;

extern Unk_08088D80 gUnk_08088D80[];
extern u8* gUnk_087EA020[];
extern u8 gUnk_082893EC[][0x140];

extern u8* gUnk_087E9AA0[];

void sub_8006520(u8 arg0) {
    u8 idx;
    u16 i;

    VBlankIntrWait();
    sub_80533F0();
    idx = gUnk_08088D80[arg0].field_10;
    i = 0;
    while(gUnk_087E9AA0[idx] != 0)
    {
        LZ77UnCompWram(gUnk_087E9AA0[idx], (void*)0x02020000 + (i<<12));
        VBlankIntrWait();
        sub_80533F0();

        idx++;
        i++;
        if(i > 4)
            break;

    }

    DmaCopy32(3, 0x02020000, 0x06000000, 0x4A60);

    VBlankIntrWait();
    sub_80533F0();

    DmaCopy16(3, &gUnk_082893EC[gUnk_08088D80[arg0].field_12], 0x05000000, 0x140);

    sub_8008DD8();

    DmaCopy16(3, gUnk_087EA020[gUnk_08088D80[arg0].field_E], 0x02005000, 0x280*2);

    DmaCopy16(3, 0x02005000, 0x0600F000, 0x800);

    VBlankIntrWait();
    sub_80533F0();
}
    */

INCLUDE_ASM("asm/nonmatchings", sub_800661C);
INCLUDE_ASM("asm/nonmatchings", sub_80071EC);
INCLUDE_ASM("asm/matchings", sub_800729C);
// InitMapSceneSprite
//  void sub_800729C(u8 arg0) {
//      u16 i;

//     if(gUnk_0300467C & 0x80)
//         return;

//     gUnk_03004670[0] = gUnk_03004AA0[0];
//     gUnk_030047D0[0] = gUnk_03004AA0[0];
//     sub_8004C8C(0, gUnk_03004AA0[0]);
//     sub_8004CB8(0, gUnk_03004AA0[0]);
//     gUnk_03004670[1] = 11;
//     gUnk_030047D0[1] = 11;
//     sub_8004C8C(1, 11);
//     sub_8004CB8(1, 11);
// gMapSceneConfigs
//     if(gUnk_08088D80[arg0].field_9 != 0)
//     {
// VRAM最多8种不同的精灵模型（会有一些模型没变，但是颜色不一样的npc）
//         for(i = 0; i < 8; i++)
//         {
//             if(gUnk_03004670[i + 2] != 0xFF)
//             {
//                 sub_8004C8C(i + 2, gUnk_03004670[i + 2]);
//             }
//         }

//         for(i = 0; i < 8; i++)
//         {
//             if(gUnk_030047D0[i + 2] != 0xFF)
//             {
//                 sub_8004CB8(i + 2, gUnk_030047D0[i + 2]);
//             }
//         }
//     }
// }
INCLUDE_ASM("asm/nonmatchings", sub_8007350);
INCLUDE_ASM("asm/nonmatchings", sub_8007964);
u8* sub_80079BC(u16 arg0, u8* arg1) {
    u32 temp_r0;

    Unk_030046A0* ptr46A0;
    
    ptr46A0 = &gUnk_030046A0[arg0];

    ptr46A0->field_0 = (arg1[0] & 1) + 1;
    ptr46A0->field_3 = arg1[1];
    arg1+= 2;
    
    ptr46A0->field_1 = *arg1;
    arg1++;
    
    ptr46A0->field_2 = *arg1;
    arg1++;

    ptr46A0->field_6 = *arg1;
    arg1++;
    
    ptr46A0->field_7 = *arg1;
    arg1++;
    ptr46A0->field_8 = *arg1;
    arg1++; 
    ptr46A0->field_9 = *arg1;
    arg1++;  

    ptr46A0->field_A = (ptr46A0->field_1 << ptr46A0->field_2) - 2;
    ptr46A0->field_C = arg1;

    temp_r0 = ptr46A0->field_8 * ptr46A0->field_9 * ptr46A0->field_1;
    temp_r0 *= 2;

    arg1 += temp_r0;

    return arg1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8007A1C);
INCLUDE_ASM("asm/nonmatchings", sub_8007ADC);
INCLUDE_ASM("asm/nonmatchings", sub_8007BD0);
INCLUDE_ASM("asm/matchings", sub_8007D5C);
/*
extern u8* gUnk_087EA0FC[];
extern u8* gUnk_087EA110[];
extern u8* gUnk_087EA124[];
extern u8* gUnk_087E96B4[];

extern u8 gUnk_0300469C;
extern u8 gUnk_030047E0;
extern u8 gUnk_030047B4;

void sub_8007D5C(u8 arg0) {
    u16* dest;
    u16 i;

    gUnk_0300259C = 3;
    HuffUnComp(gUnk_087EA0FC[arg0], (void* )0x02020000);
    LZ77UnCompVram((void* )0x02020000, (void* )0x06000000);
    LZ77UnCompVram(gUnk_087EA110[arg0], (void* )0x0600E000);
    DmaCopy16(3, gUnk_087EA124[arg0], PLTT, 0x80 * 2);
    LZ77UnCompVram((void* )0x0809CB90, (void* )0x06008000);
    nullsub_5();
    LZ77UnCompVram((void* )0x0809D198, (void* )0x06009000);
    nullsub_5();
    LZ77UnCompVram((void* )0x0809D718, (void* )0x0600A000);
    nullsub_5();
    LZ77UnCompVram((void* )0x0809DCE8, (void* )0x0600B000);
    nullsub_5();
    DmaCopy16(3,0x0809C834, 0x05000160, 0x30 * 2);
    nullsub_5();
    LZ77UnCompVram((void* )0x08095A1C, (void* )0x0600D000);
    LZ77UnCompVram((void* )0x08095C94, (void* )0x0600D400);
    LZ77UnCompVram((void* )0x08095F14, (void* )0x0600D800);
    LZ77UnCompVram((void* )0x0809619C, (void* )0x0600DC00);

    DmaCopy16(3,0x08087216, PLTT, 2);

    REG_DISPCNT = (REG_DISPCNT & 0xE000) | 0x1560;
    REG_BG2CNT = 0x3C02;
    REG_BG3CNT = 0x3D01;
    REG_BG0CNT = 0x3F08;

    gUnk_03004658 = 0x1E41;
    gUnk_03004550 = 0x1F00;

    DmaCopy16(3,0x08393288, 0x0600C000, 0x200);
    DmaCopy16(3,0x08393688, 0x05000140, 0x20);

    sub_80064AC(0);
    DmaCopy16(3,0x02005000, 0x0600F000, 0x800);


    dest = (u16* )0x02005800;
    for(i = 0; i < 0x800; i++)
    {
        *dest++ = 0;
    }

    sub_80163CC(  gUnk_087E96B4[gUnk_030047B4] );
    gUnk_03004610 = 1;
    REG_BG1CNT = 0x1E0F;
    REG_DISPCNT |= 0x200;
    sub_8000C98(1);
    sub_8007FB8(arg0);
    gUnk_0300469C = gUnk_030047E0;
}
*/
INCLUDE_ASM("asm/nonmatchings", sub_8007FB8);
INCLUDE_ASM("asm/nonmatchings", sub_8008124);
void sub_80081C0(void) {
    
    if(gUnk_0300000A[1] != 0)
    {
        sub_800243C(0xb0, 0x18, gUnk_0300000A[1], 0, 1);
        sub_800243C(0xD0, 0x30, gUnk_0300000A[0], 0, 1);
        return;
    }

    if(gUnk_0300000A[0] != 0)
    {
        if(gUnk_03000008 == 0)
        {
            gUnk_0300000C++;
            if(gUnk_0300000C == 0xC0)
            {
                gUnk_03000008 = 1;
            }
        }
        else
        {
            gUnk_0300000C--;
            if(gUnk_0300000C == 0)
            {
                gUnk_03000008 = 0;
            }
        }
        
        sub_800243C(0x68, 0x30, gUnk_0300000A[0], (gUnk_0300000C >> 6) + 0x10, 1);
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8008254);
INCLUDE_ASM("asm/nonmatchings", sub_8008620);
INCLUDE_ASM("asm/nonmatchings", sub_80086FC);
INCLUDE_ASM("asm/nonmatchings", sub_8008788);
INCLUDE_ASM("asm/nonmatchings", sub_80088B4);
INCLUDE_ASM("asm/nonmatchings", sub_80088F4);
INCLUDE_ASM("asm/nonmatchings", sub_8008978);
void sub_80089E0(u16 arg0)
{

    switch (arg0)
    {
        case 1:
            gUnk_03004604 = 0;
            REG_WIN0H = DISPLAY_WIDTH;
            REG_WIN0V = DISPLAY_HEIGHT;
            REG_WININ = 0x3F;
            REG_WINOUT = 0;
            break;
        case 0:
            gUnk_03004604 = DISPLAY_WIDTH;
            break;
        default:
            sub_8009428(arg0 - 3);
            break;
    }

    gUnk_03004840 = arg0;
}

void sub_8008A3C(void)
{
    s16 i;

    for (i = 0; i < 16; i++)
    {
        gUnk_030046A0[i].field_0 = 0;
    }
}

void sub_8008A60(void)
{
    s16 i;

    for (i = 0; i < 16; i++)
    {
        sub_8007A1C(i);
    }
}
void sub_8008A80(u8 arg0)
{
    if (arg0 == 0)
    {
        LZ77UnCompVram((void *)0x0809C8B4, (void *)0x0600C800);
        nullsub_5();
    }
    LZ77UnCompVram((void *)0x0809CB90, (void *)0x06008000);
    nullsub_5();
    LZ77UnCompVram((void *)0x0809D198, (void *)0x06009000);
    nullsub_5();
    LZ77UnCompVram((void *)0x0809D718, (void *)0x0600A000);
    nullsub_5();
    LZ77UnCompVram((void *)0x0809DCE8, (void *)0x0600B000);
    nullsub_5();

    DmaCopy16(3, 0x0809C834, 0x05000160, 0x60);

    nullsub_5();
}
INCLUDE_ASM("asm/nonmatchings", sub_8008B14);
void sub_8008B5C(void)
{
    // gUnk_03004670.field_0 = gUnk_03004AA0[0];
    gUnk_03004670[0] = gUnk_03004AA0[0];
    gUnk_030047D0[0] = gUnk_03004AA0[0];

    sub_8004C8C(0, gUnk_03004AA0[0]);
    sub_8004CB8(0, gUnk_03004AA0[0]);
    // gUnk_03004670.field_1 = 11;
    gUnk_03004670[1] = 11;
    gUnk_030047D0[1] = 11;
    sub_8004C8C(1, 0xBU);
    sub_8004CB8(1, 0xBU);
}
INCLUDE_ASM("asm/nonmatchings", sub_8008BA4);

void sub_8008BE4(u8 arg0)
{
    gUnk_030046A0[arg0].field_3 |= 2;
}

void sub_8008BFC(u8 arg0)
{
    gUnk_030046A0[arg0].field_3 &= 0xFD;
}

u8 sub_8008C14(u8 arg0)
{
    return gUnk_030046A0[arg0].field_0;
}

INCLUDE_ASM("asm/nonmatchings", sub_8008C24);
INCLUDE_ASM("asm/nonmatchings", sub_8008C70);
INCLUDE_ASM("asm/matchings", sub_8008CC0);
// extern u8 gUnk_08087658[];

// extern u8 gUnk_030047BC;
// extern u8 gUnk_03004824;
// extern u8 gUnk_030047B8;

// void sub_8008CC0(u8 arg0) {
//     u8 i;
//     u8 skipLen;
//     u8* ptr;
//     ptr = gUnk_08087658;
//     i = 0;
//     skipLen = (*ptr << 1);
//     ptr++;

//     while(i != gUnk_030047BC)
//     {
//         ptr += skipLen;
//         i++;
//         skipLen = (*ptr << 1);
//         ptr++;
//     }

//     ptr = ptr + (arg0 << 1);
//     gUnk_03004824 = ptr[0];
//     gUnk_030047B8 = ptr[1];

// }
INCLUDE_ASM("asm/matchings", sub_8008D18);
INCLUDE_ASM("asm/nonmatchings", sub_8008D78);

void sub_8008DCC(u8 arg0)
{
    gUnk_03004850 = arg0;
}

void sub_8008DD8(void)
{
    DmaCopy16(3, (void *)0x08087216, (void *)0x05000000, 2);
}

void sub_8008DF8(u16 arg0, u8* arg1) {
    u16 count;

    count = *(u16*)arg1;
    arg1 += 2;

    while(count != 0)
    {
        arg1 = sub_80079BC(arg0, arg1);

        sub_8007A1C(arg0);

        gUnk_030046A0[arg0].field_0 = 0;
        count--;
    }
}
void sub_8008E44(u8 arg0) {
    u16* dest;
    u16 i, j;
    u16 val;

    dest = (u16* )0x020053A8;

    val = 32;
    
    if(arg0 != 0)
    {
        val = 0;
    }

    for(i = 0; i < 4; i++)
    {
        for(j = 0; j < 8; j++)
        {
            *dest = val + 0xA200;
            dest++;
            val++;
        }
        dest += 24;
    }
    gUnk_03004800[13] = 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8008E94);
INCLUDE_ASM("asm/nonmatchings", sub_8008F28);
void sub_8008FD0(u8 arg0)
{
    struct RenderObject *obj;
    struct RenderObject *subObj;
    u8 objIdx;
    u16 chestColor;
    u16 attr0;
    u16 attr1;
    u16 attr2;

    objIdx = sub_8004BFC();
    gChestObjects[arg0].renderObjIdx = objIdx;
    obj = &gRenderObjects[objIdx];

    chestColor = 0x80 & gChestObjects[arg0].field_0 ? 0xF : 0xE;

    if ((0x7F & gChestObjects[arg0].field_0) == 0)
    {

        attr0 = 0;
        attr1 = 0x4000;
        attr2 = ((chestColor << 12) | 0x896);

        obj->field_10 = 0;
        obj->field_12 = 0xF0;

        sub_8004C28(obj, 1, attr0, attr1, attr2);
    }
    else
    {
        attr0 = 0;
        attr1 = 0x4000;
        attr2 = ((chestColor << 12) + 0x89C);
        obj->field_10 = 0;
        obj->field_12 = 0xF0;
        subObj = sub_8004C28(obj, 2, attr0, attr1, attr2);

        attr0 = 0x4000;
        attr1 = 0;
        attr2 = ((chestColor << 12) | 0x89A);
        subObj->field_10 = 0;
        subObj->field_12 = 0xE8;
        sub_8004C28(subObj, 1, attr0, attr1, attr2);
    }
    obj->animFrame = 0;
}
void sub_800908C(u8 arg0)
{
    u8 idx;

    if (gChestObjects[arg0].field_0 & 1)
    {
        sub_805374C(9, 0, 0);
    }
    else
    {
        sub_805374C(8, 0, 0);
    }

    gChestObjects[arg0].field_0 ^= 1;

    idx = gChestObjects[arg0].field_1;

    gUnk_03004870[idx >> 3] ^= (1 << (idx & 7));

    sub_8004F3C(&gRenderObjects[gChestObjects[arg0].renderObjIdx]);
    sub_8008FD0(arg0);
    gUnk_03004860 = arg0;
}

void sub_8009114(void)
{
    if (!(0x80 & gUnk_0300467C))
    {
        nullsub_5();
        DmaCopy16(3, 0x08088C40, 0x060112C0, 0xA0 * 2);
        DmaCopy16(3, 0x08088C00, 0x050003C0, 0x20 * 2);
    }
}
void sub_8009168()
{
    u8 i = 0;
    // do{gUnk_03004870[i++] = 0;}while(i < 0x20);
    while (i < 0x20)
    {
        gUnk_03004870[i++] = 0;
    }
}
void sub_8009184(u8 arg0)
{
    gUnk_03004870[arg0 >> 3] ^= (1 << (arg0 & 7));
}
u8 sub_80091A4(u8 arg0)
{
    u8 val;
    val = gUnk_03004870[(arg0 >> 3) & 0x1F];
    return (val >> (arg0 & 7)) & 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_80091C4);
INCLUDE_ASM("asm/nonmatchings", sub_8009370);
INCLUDE_ASM("asm/nonmatchings", sub_8009428);
INCLUDE_ASM("asm/nonmatchings", sub_80094FC);
INCLUDE_ASM("asm/nonmatchings", sub_8009600);
void sub_8009A5C(void)
{
    s16 i;

    for (i = 0; i < 4; i++)
    {
        gUnk_03000010[i] = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8009A7C);
INCLUDE_ASM("asm/nonmatchings", sub_8009AC4);
void sub_8009B04(u8 arg0)
{
    gUnk_03000010[arg0] &= 0xFB;
}
void sub_8009B1C(u8 arg0)
{
    gUnk_03000010[arg0] |= 4;
}

u8 sub_8009B34(u8 arg0)
{
    return gUnk_03000010[arg0];
}

void sub_8009B44(void)
{
    DmaCopy16(3, PLTT, 0x0203EA00, PLTT_SIZE);
}

void sub_8009B64(void)
{
    u16 i;
    u16 *dst;
    i = 0x200;
    dst = (u16 *)0x05000000;

    while (i > 0)
    {
        *dst = 0x7FFF;
        dst++;
        i--;
    }
}

u8 *sub_8009B84(u8 arg0, u8 *src)
{
    gUnk_03000010[arg0] = src[0];
    gUnk_03000018[arg0] = src[1];
    src += 2;
    gUnk_03000028[arg0] = (*src << 5) + 0x05000002;
    src++;
    gUnk_03000014[arg0] = *src;
    src++;
    gUnk_03000038[arg0] = src;
    src += gUnk_03000014[arg0];
    gUnk_03000020[arg0] = 0;
    return src;
}
INCLUDE_ASM("asm/matchings", sub_8009BF0);
INCLUDE_ASM("asm/matchings", sub_8009C84);
INCLUDE_ASM("asm/matchings", sub_8009D34);
INCLUDE_ASM("asm/matchings", sub_8009E80);

void sub_8009F48(void)
{
    s16 i;

    for (i = 0; i < 3; i++)
    {
        gStaticMapObjects[i].field_0 = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8009F70);
INCLUDE_ASM("asm/nonmatchings", sub_800A048);
u8 sub_800A0E4(u8 arg0)
{
    u8 var_r2;
    Unk_03004AC0 *ptr;

    if (arg0 != 0)
    {
        arg0 -= 1;
    }

    ptr = &gUnk_03004AC0[arg0];
    switch (arg0)
    {
        case 0:
            if (ptr->equip_slot1 == 0x15)
            {
                if (ptr->equip_slot5 == 0xCB || ptr->equip_slot6 == 0xCB)
                {
                    return 0x38;
                }
            }
            return 0x31;
        case 1:
            return 0x32;
        case 2:
            if (ptr->equip_slot5 == 0xBF || ptr->equip_slot6 == 0xBF)
            {
                return 0x39;
            }
            return 0x33;
        case 3:

            if (ptr->equip_slot5 == 0xBF || ptr->equip_slot6 == 0xBF)
            {
                return 0x3A;
            }
            return 0x34;
        case 4:
            if (ptr->equip_slot1 == 0x3B)
            {
                return 0x3B;
            }
            return 0x35;
        case 5:
            if (ptr->equip_slot1 == 0x3C)
            {
                return 0x3C;
            }
            return 0x36;
        default:
            return 0xFF;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_800A1B4);
INCLUDE_ASM("asm/nonmatchings", sub_800A3C8);
INCLUDE_ASM("asm/nonmatchings", sub_800A534);
INCLUDE_ASM("asm/nonmatchings", sub_800A664);
INCLUDE_ASM("asm/nonmatchings", sub_800A79C);
INCLUDE_ASM("asm/matchings", sub_800A86C);
// u8 sub_800A86C(s32 value) {
//     s32 ret;
//     u8 i;

//     if (value > 9999999) {
//         value = 9999999;
//     }

//     i = 0;
//     while(value >= 0)
//     {
//         value -= gUnk_08092248[i];
//         i++;
//     }

//     return i - 1;
// }
INCLUDE_ASM("asm/matchings", sub_800A8A0);
INCLUDE_ASM("asm/nonmatchings", sub_800A8D0);

void sub_800A924(void)
{
    u8 i;

    for (i = 1; i < 11; i++)
    {
        sub_800A1B4(i);
    }

    for (i = 1; i < 255; i++)
    {
        gUnk_03004980[i] = 0;
    }
}
INCLUDE_ASM("asm/matchings", sub_800A958);
// extern u8 gUnk_08093418[];

// u8 sub_800A958(u8 arg0) {
//     return gUnk_08093418[(arg0 - 1) * 5 + 4];
// }
INCLUDE_ASM("asm/matchings", sub_800A970);
INCLUDE_ASM("asm/matchings", sub_800A978);
void sub_800A980(void)
{
    u8 i;
    u8 charaId;
    Unk_03004AC0 *ptr;

    for (i = 0; i < 6; i++)
    {
        charaId = gUnk_03004AA0[i];
        if (charaId == 0xFF)
            continue;
        if (charaId != 0)
            charaId--;

        ptr = &gUnk_03004AC0[charaId];
        ptr->hp = ptr->max_hp;
        ptr->mp = ptr->max_mp;
    }
}
INCLUDE_ASM("asm/matchings", sub_800A9C0);
/*
void sub_800A9C0(u8 arg0, u8 newEquip, u8 equipSlotId) {
    u8 oldEquip;
    u8 var_r0;
    u8* equipSlot;

    Unk_03004AC0* chara;

    var_r0 = arg0;
    if (arg0 != 0) {
        var_r0 = arg0 - 1;
    }

    chara = &gUnk_03004AC0[var_r0];

    switch (equipSlotId)
    {
        case 1: equipSlot = &chara->equip_slot2; break;
        case 2: equipSlot = &chara->equip_slot3; break;
        case 3: equipSlot = &chara->equip_slot4; break;
        case 4: equipSlot = &chara->equip_slot5; break;
        case 5: equipSlot = &chara->equip_slot6; break;
        default: equipSlot = &chara->equip_slot1; break;
    }
    oldEquip = *equipSlot;
    *equipSlot = newEquip;

     if (oldEquip != 0) {
        if (gUnk_03004980[oldEquip] <= 0x62)
        {
            sub_800AA60(oldEquip, 1);
        }
    }

    sub_800A664(arg0);
    sub_800A79C(arg0);
}
*/

void sub_800AA60(u8 arg0, u8 count)
{
    s32 cnt;

    cnt = gUnk_03004980[arg0] + count;
    if (cnt > 99)
    {
        gUnk_03004980[arg0] = 99;
    }
    else
    {
        gUnk_03004980[arg0] = cnt;
    }
}

void sub_800AA84(u8 arg0, u8 count)
{
    s32 cnt;

    cnt = gUnk_03004980[arg0] - count;
    if (cnt < 0)
    {
        gUnk_03004980[arg0] = 0;
    }
    else
    {
        gUnk_03004980[arg0] = cnt;
    }
}

void sub_800AAA4(s32 arg0)
{
    gUnk_03002C38 += arg0;

    if (gUnk_03002C38 > 999999)
    {
        gUnk_03002C38 = 999999;
    }
}
void sub_800AAC0(s32 arg0)
{
    gUnk_03002C38 -= arg0;

    if (gUnk_03002C38 > 999999)
    {
        gUnk_03002C38 = 0;
    }
}
INCLUDE_ASM("asm/matchings", sub_800AADC);
// typedef struct
// {
//     u32 field_0;
//     u8 field_4;
//     u8 field_5;
//     u16 field_6;
//     u32 field_8;
// }Unk;
// extern u8 unk87EA580[];
// s32 sub_800AADC(u8 arg0) {
//     return unk87EA580[arg0 * 12 + 4] & 0xF;
// }
INCLUDE_ASM("asm/matchings", sub_800AAF8);
// typedef struct
// {
//     u8 field_0;
//     u8 field_1;
//     u8 field_2;
//     u8 field_3;
//     u8 field_4;
//     u8 field_5;
//     u16 field_6;
//     u32 field_8;
// }Unk;
// extern u8 unk87EA580[];
// u16 sub_800AAF8(u8 arg0) {
//     return unk87EA580[arg0 * 12] + (unk87EA580[arg0 * 12 + 1] << 8) ;
// }
INCLUDE_ASM("asm/matchings", sub_800AB18);
// extern u8 unk87EA580[];

// u16 sub_800AB18(u8 arg0) {
//     return unk87EA580[arg0 * 12 + 2] + (unk87EA580[arg0 * 12 + 3] << 8) ;
// }

u8 sub_800AB3C(void)
{

    u16 i;
    u8 charaId;
    Unk_03004AC0 *ptr;

    for (i = 0; i < 5; i++)
    {
        charaId = gUnk_03004AA0[i];
        if (charaId == 0xFF)
            continue;
        if (charaId != 0)
            charaId--;

        ptr = &gUnk_03004AC0[charaId];

        if (ptr->equip_slot1 != 0)
            return 1;
    }
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_800AB7C);
void sub_800ABBC(void)
{
    gUnk_03004A90 = 0;
    gUnk_03004AA8 = 0;
    gUnk_03004AB0 = 0;
    gUnk_03004A98 = 0;
    gUnk_03004A94 = 0;
    gUnk_03004AB4 = 0;
    gUnk_03004AB8 = 0;
    gUnk_03004AAC = 0;
    gUnk_03004A80 = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_800AC08);
void sub_800ACA4(u8 arg0)
{
    Unk_03004AC0 *ptr;

    if (arg0 != 0)
    {
        arg0--;
    }

    ptr = &gUnk_03004AC0[arg0];
    ptr->hp = ptr->max_hp;
    ptr->mp = ptr->max_mp;
}
INCLUDE_ASM("asm/nonmatchings", sub_800ACC8);
INCLUDE_ASM("asm/nonmatchings", sub_800B14C);
void sub_800B2D0(void)
{
    u8 i;
    gUnk_03000186 = 0;
    gUnk_03000187 = 0;

    gUnk_03000048.field_0 = 1;
    gUnk_03000048.field_1 = 0;
    gUnk_03000048.field_2 = 0;
    gUnk_03000048.field_3 = 0;
    gUnk_03000048.field_4 = 0x18;
    gUnk_03000048.field_6 = 8;

    for (i = 0; i < 16; i++)
    {
        gUnk_03000188[i] = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_800B314);
INCLUDE_ASM("asm/nonmatchings", sub_800B374);
INCLUDE_ASM("asm/nonmatchings", sub_800BEE4);
INCLUDE_ASM("asm/matchings", sub_800BF5C);
INCLUDE_ASM("asm/nonmatchings", sub_800BFF8);
INCLUDE_ASM("asm/nonmatchings", sub_800C0D8);
INCLUDE_ASM("asm/nonmatchings", sub_800C194);
INCLUDE_ASM("asm/nonmatchings", sub_800C2F8);

void sub_800E170(u8 arg0, u8 arg1, u8 arg2)
{

    switch (arg0)
    {
        case 0:
            gUnk_03000058[arg2].x = arg2 * 0x28 + 0x48;
            gUnk_03000058[arg2].y = 8;
            break;
        case 1:
            gUnk_03000058[arg2].x = 0x28;
            gUnk_03000058[arg2].y = 8;

            break;
        case 2:
            gUnk_03000058[arg2].x = 0x30;
            gUnk_03000058[arg2].y = 16;
            break;
    }
    switch (arg1)
    {
        case 2:
            gUnk_03000058[arg2].statusFlags &= 0xBF;
            gUnk_03000058[arg2].statusFlags &= 0xFE;
            break;
        case 1:
            gUnk_03000058[arg2].statusFlags &= 0xBF;
            gUnk_03000058[arg2].statusFlags |= 1;
            break;
        case 0:
            gUnk_03000058[arg2].statusFlags |= 0x40;
            gUnk_03000058[arg2].statusFlags &= 0xFE;
            break;
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_800E244);

// http://localhost/scratch/E4CZr
INCLUDE_ASM("asm/matchings", sub_800E668);

INCLUDE_ASM("asm/matchings", sub_800E71C);
INCLUDE_ASM("asm/matchings", sub_800E7BC);
INCLUDE_ASM("asm/nonmatchings", sub_800E8F8);
INCLUDE_ASM("asm/nonmatchings", sub_800EAE4);

INCLUDE_ASM("asm/matchings", sub_800EB98);

INCLUDE_ASM("asm/nonmatchings", sub_800EC54);
INCLUDE_ASM("asm/nonmatchings", sub_800F128);
INCLUDE_ASM("asm/nonmatchings", sub_800F3AC);

INCLUDE_ASM("asm/matchings", sub_800F4A8);

INCLUDE_ASM("asm/nonmatchings", sub_800F670);
INCLUDE_ASM("asm/nonmatchings", sub_800F70C);
INCLUDE_ASM("asm/nonmatchings", sub_800FA24);
INCLUDE_ASM("asm/nonmatchings", sub_800FB2C);
INCLUDE_ASM("asm/nonmatchings", sub_800FDEC);
INCLUDE_ASM("asm/nonmatchings", sub_800FF10);
INCLUDE_ASM("asm/nonmatchings", sub_8010170);
u8 sub_801026C(u8 arg0, u8 arg1)
{

    Unk_03004AC0 *ptr4AC0;
    u8 val;

    if (arg0 != 0)
        arg0--;

    ptr4AC0 = &gUnk_03004AC0[arg0];

    val = sub_800A958(arg1);

    if (ptr4AC0->equip_slot5 == 0xAF)
    {
        val >>= 1;
        if (val == 0)
            val = 1;
        return val;
    }

    if (ptr4AC0->equip_slot6 == 0xAF)
    {
        val >>= 1;
        if (val == 0)
            val = 1;
        return val;
    }

    if (ptr4AC0->equip_slot2 == 0x63)
    {
        if (val > 2)
            val -= 2;
        else
            val = 1;
    }

    if (ptr4AC0->equip_slot3 == 0x83)
    {
        if (val > 2)
            val -= 2;
        else
            val = 1;
    }

    if (ptr4AC0->equip_slot3 == 0x84)
    {
        if (val > 2)
            val -= 2;
        else
            val = 1;
    }

    return val;
}

INCLUDE_ASM("asm/nonmatchings", sub_8010300);
INCLUDE_ASM("asm/nonmatchings", sub_8010434);
INCLUDE_ASM("asm/nonmatchings", sub_80104F8);
INCLUDE_ASM("asm/nonmatchings", sub_8010624);
INCLUDE_ASM("asm/nonmatchings", sub_8010770);
INCLUDE_ASM("asm/nonmatchings", sub_8010978);
