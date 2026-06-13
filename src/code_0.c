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

const u8 gUnk_0805881C[];
const u8 gUnk_08058834[];

typedef void (*IntrFunc)(void);
/*
    MultiSioIntr
    VBlankIntr
    HBlankIntr
    VCountIntr
*/
IntrFunc const gIntrTable[] = {
    sub_8016FC0, VBlankIntr, sub_800124C, DummyIntr4, DummyIntr3, DummyIntr3, DummyIntr3,
    DummyIntr3,  DummyIntr3, DummyIntr3,  DummyIntr3, DummyIntr3, DummyIntr3,
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

    REG_BG2HOFS = gBG2ScrollX;
    REG_BG2VOFS = gBG2ScrollY;
    REG_BG3HOFS = gBG3ScrollX;
    REG_BG3VOFS = gBG3ScrollY;

    DmaCopy16(3, gOamBuffer, OAM, OAM_SIZE);

    sub_8002F6C(); // Show Lunar Logo
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

    REG_BLDCNT = gBlendControl;
    if (gBlendControl & 0x80)
    {
        REG_BLDY = gUnk_03004550;
    }
    else
    {
        REG_BLDALPHA = gUnk_03004550;
    }

    sub_8005020();
    sub_80038CC();

    switch (gHBlankEffectMode)
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

    REG_BLDCNT = gBlendControl;
    REG_BLDALPHA = gUnk_03004550;

    DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);

    sub_8005020();
    val = (gUnk_03001988 - 1) & 0x3FF;
    gUnk_03001988 = val;
    gUnk_03001B54 = (val >> 2) + gUnk_030025FC;
}

void sub_80005A8(u16 scanline)
{
    switch (gHBlankEffectMode)
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
void VBlankIntr(void)
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

            REG_BLDCNT = gBlendControl;
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
            REG_BLDCNT = gBlendControl;
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

            REG_BLDCNT = gBlendControl;
            if (gBlendControl & 0x80)
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
    u16 keyInput;

    keyInput = ~REG_KEYINPUT;
    gNewKeysRaw = keyInput & ~gHeldKeysRaw;
    gHeldKeysRaw = keyInput;
}

void ReadKeys(void)
{
    u16 keyInput;

    keyInput = ~REG_KEYINPUT;
    gNewKeysRaw = keyInput & ~gHeldKeysRaw;
    gHeldKeysRaw = keyInput;
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


//AgbMain
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
    REG_BLDCNT = gBlendControl;
    REG_BLDALPHA = gUnk_03004550;

    CpuFastSet(VRAM_BUF_2005800, (void *)0x0600F800, 0x200);
    if (gUnk_03004DC0 != 0)
    {
        CpuFastSet(VRAM_BUF_2005000, (void *)0x0600F000, 0x200);
        gUnk_03004DC0 = 0;
    }
}
//切换场景加载
void sub_8001354(void)
{
    u16 i;
    u8 temp_r6;
    s32 temp_r7;

    sub_80008CC();
    temp_r6 = gUnk_0300259C;
    gUnk_0300259C = 0;
    temp_r7 = gUnk_03004608;
    gHBlankEffectMode = 0;
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

//New Game
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
    gPartyMemberIds[0] = 0;
    gPartyMemberIds[1] |= 0xFF;
    gPartyMemberIds[2] |= 0xFF;
    gPartyMemberIds[3] |= 0xFF;
    gPartyMemberIds[4] |= 0xFF;
    gPartyMemberIds[5] |= 0xFF;
    gBattleFormationIds[0] = 0;
    gBattleFormationIds[1] |= 0xFF;
    gBattleFormationIds[2] |= 0xFF;
    gBattleFormationIds[3] |= 0xFF;
    gBattleFormationIds[4] |= 0xFF;
    gBattleFormationIds[5] |= 0xFF;

    sub_800A924();

    for (i = 0; i < 11; i++)
    {
        sub_800A664(i);
        sub_800A79C(i);
    }

    gInventory[0xDD] = 2;
    gSilverAmount = 300;
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

    DmaCopy16(3, (void *)0x0203F000, gSpriteNodePool, 0xA00);
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


void sub_8001D08(void)
{
    u8 eventId;
    u8 moveFlags;
    u8 moveSpeed;

    moveFlags = 0;

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
        if (gUnk_030025F0 && (gUnk_0300465C & 0x80) == 0 && !gUnk_03004840 && (gNewKeysRaw & 0x30F) != 0)
        {
            sub_8052728(1);
            gMainGameState = 0xB;
            gUnk_03002600 = 5;
            return;
        }
    }

    if ((gHeldKeysRaw & ABXY_BUTTONS) == ABXY_BUTTONS)
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
                gNewKeysRaw = 0;
                gHeldKeysRaw = 0;
            }

            if (gUnk_03003480 != 0xFF)
            {
                sub_80526A0(gUnk_03003480, 2);
                gUnk_03003480 = 0xFF;
            }
            else
            {
                if (gNewKeysRaw & A_BUTTON)
                {
                    eventId = sub_8003F40();
                    if (eventId != 0)
                    {
                        sub_80526A0(eventId - 1, 2);
                    }
                }
                else if (gNewKeysRaw & B_BUTTON)
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

                    if (gHeldKeysRaw & DPAD_UP)
                    {
                        moveFlags = 1;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }
                    else if (gHeldKeysRaw & DPAD_DOWN)
                    {
                        moveFlags = 2;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }
                    if (gHeldKeysRaw & DPAD_LEFT)
                    {
                        moveFlags |= 4;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }
                    else if (gHeldKeysRaw & DPAD_RIGHT)
                    {
                        moveFlags |= 8;
                        gUnk_03002E80[0].field_12 |= 0x40;
                    }

                    if (gUnk_0805881C[moveFlags])
                    {
                        gUnk_030025B0 = gUnk_0805881C[moveFlags] - 1;
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
                if (ptr03002E80->sprNodeIdx && (ptr03002E80->field_1 & 1) != 0)
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
                    sub_800243C(sub_8004EDC(ptr03002E80), ptr03002E80->y, ptr03002E80->sprNodeIdx, sub_8004EB8(ptr03002E80),
                                ptr03002E80->field_1);
                    if (ptr03002E80->field_18)
                    {
                        gSpriteNodePool[ptr03002E80->field_18].flags = 0;
                        gSpriteNodePool[ptr03002E80->field_18].next = 0;
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
                if (ptr03002E80->sprNodeIdx)
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
                        gSpriteNodePool[ptr03002E80->field_18].flags = 0;
                        gSpriteNodePool[ptr03002E80->field_18].next = 0;
                        ptr03002E80->field_18 = 0;
                    }
                    if (sub_800243C(ptr03002E80->x, ptr03002E80->y, ptr03002E80->sprNodeIdx, ptr03002E80->field_1A,
                                    ptr03002E80->field_1))
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
            if (gChestObjects[i].sprNodeIdx)
            {
                sub_800243C(gChestObjects[i].x, gChestObjects[i].y, gChestObjects[i].sprNodeIdx, 0, 255);
            }
        }
    }

    sub_8009D34();
    sub_80032BC();
    sub_80091C4();
}

void sub_8002380(u8 charaId)
{
    CharacterObject *charaObj;
    SpriteNode *sprNode;

    if ((gUnk_030025A0 & 1) == (charaId & 1))
    {
        charaObj = &gUnk_03002E80[charaId];
        if (!(charaObj->field_1 & 2))
        {
            if (charaObj->field_18 == 0)
            {
                charaObj->field_18 = sub_8004BFC();
            }
            sprNode = &gSpriteNodePool[charaObj->field_18];

            if ((charaObj->field_1 & 1) != 0)
            {
                sprNode->attr0 = 0x4000;
                sprNode->attr1 = 0x4000;
                sprNode->attr2 = 0x892;
                sprNode->tileOffsetX = 0x1F4;
                sprNode->tileOffsetY = 0xFC;
            }
            else
            {
                sprNode->attr0 = 0x4000;
                sprNode->attr1 = 0;
                sprNode->attr2 = 0x892;
                sprNode->tileOffsetX = 0;
                sprNode->tileOffsetY = 0xFA;
            }
            sprNode->flags = 1;
            sprNode->animStep = 0;

            sub_800243C(sub_8004EDC(charaObj), charaObj->y - 0xA0, charaObj->field_18, -0xA0, 0xFE);
        }
    }
}
INCLUDE_ASM("asm/matchings", sub_800243C);

/*
u8 sub_800243C(s16 x, s16 y, u8 sprNodeIdx, s16 z, u8 arg4)
{
    SpriteNode* sprNode;
    u8 count;
    
    s16 screenX, screenY;
    s16 offsetX, offsetY;
    u8 flag;
    s16 i;

    flag = 0;

    sprNode = &gSpriteNodePool[sprNodeIdx];
    sprNode->x = x;
    sprNode->y = y;

    count = sprNode->flags & 0x7F;

    if(!(arg4 & 0x81) && (sprNode->animStep == 0 || sprNode->animStep == 2))
    {
        z++;
    }

    if (gUnk_03004800[0] & 1) {
        screenX = x - ((gUnk_030025B4 & ~0xF) + gBG3ScrollX);
    } else {
        screenX = x - gUnk_030025B4;
    }
    
    if (gUnk_03004800[0] & 2) 
    {
        screenY = y - ((gUnk_030025FC & ~0xF) + gBG3ScrollY) - 4 - z;
    } else {
        screenY = y - gUnk_030025FC - 4 - z;
    }

    while(count != 0)
    {
        gUnk_030025BC = gUnk_08058834[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6)];
        gUnk_03002C30 = gUnk_08058834[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6) + 1];


        if(sprNode->tileOffsetX > 256)
        {
            offsetX = sprNode->tileOffsetX - 511;
        }
        else
        {
            offsetX = sprNode->tileOffsetX;
        }

        if(sprNode->tileOffsetY > 128)
        {
            offsetY = sprNode->tileOffsetY - 255;
        }
        else
        {
            offsetY = sprNode->tileOffsetY;
        }

        if((x + gUnk_030025BC + offsetX) >= gUnk_030025B4 && (x +  offsetX) <= gUnk_030025B4 + 240
              && (y + gUnk_03002C30 + offsetY - z - 4) >= gUnk_030025FC && (y +  offsetY - z - 4) <= gUnk_030025FC + 160)
        {
            sprNode->flags &= ~0x80;
            sprNode->attr0 = (sprNode->attr0 & 0xFF00) + ((screenY + offsetY) & 0xFF);
            sprNode->attr1 = (sprNode->attr1 & 0xFE00) + ((screenX + offsetX) & 0x1FF);
            flag = 1;
        }
        else
        {
            sprNode->flags |= 0x80;
        }


        sprNode = sprNode->next;

        count--;
    }

       if(flag != 0)
    {
        SpriteNode* r5;
        SpriteNode* r1;
        SpriteNode* r2;
        i = 0;

        while(i < 128)
        {
            r1 = gSpriteRenderQueue[i];

            if(r1 == 0)
            {
                gSpriteRenderQueue[i] = &gSpriteNodePool[sprNodeIdx];
                break;
            }

            if((u16)r1->y < y)
            {
                s16 j;
                r2 = r1;
                gSpriteRenderQueue[i] = &gSpriteNodePool[sprNodeIdx];
                // i++;

                j = i + 1;
                while(j < 128)
                {
                    r1 = gSpriteRenderQueue[j];
                    gSpriteRenderQueue[j] = r2;
                    r2 = r1;
                    if(r2 == 0)
                        break;
                    j++;
                }


                return 0;
            }

            i++;
        }
        return 0;
    }
    return 1;
}
*/

/*

u8 sub_800243C(s16 x, s16 y, u8 arg2, s16 z, u8 arg4) {
    SpriteNode* sprNode;
    u8 num;
    s16 screenX, screenY;
    s16 offsetX, offsetY;
    u8 updateFlag;
    s16 i;
    s16 j;
    updateFlag = 0;

    sprNode = &gSpriteNodePool[arg2];
    sprNode->x = x;
    sprNode->y = y;

    num = sprNode->flags & 0x7F;

    if(!(arg4 & 0x81) && (sprNode->animStep == 0 || sprNode->animStep == 2))
    {
        z++;
    }

    if (gUnk_03004800[0] & 1) {
        screenX = x - ((gUnk_030025B4 & ~0xF) + gBG3ScrollX);
    } else {
        screenX = x - gUnk_030025B4;
    }

    if (gUnk_03004800[0] & 2)
    {
        screenY = y - ((gUnk_030025FC & ~0xF) + gBG3ScrollY) - 4 - z;
    } else {
        screenY = y - gUnk_030025FC - 4 - z;
    }

    while(num != 0)
    {
        gUnk_030025BC = gUnk_08058834[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6)];
        gUnk_03002C30 = gUnk_08058834[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6) + 1];


        if(sprNode->tileOffsetX > 256)
        {
            offsetX = sprNode->tileOffsetX - 511;
        }
        else
        {
            offsetX = sprNode->tileOffsetX;
        }

        if(sprNode->tileOffsetY > 128)
        {
            offsetY = sprNode->tileOffsetY - 255;
        }
        else
        {
            offsetY = sprNode->tileOffsetY;
        }

        if((x + gUnk_030025BC + offsetX) >= gUnk_030025B4 && (x +  offsetX) <= gUnk_030025B4 + 240
              && (y + gUnk_03002C30 + offsetY - z - 4) >= gUnk_030025FC && (y +  offsetY - z - 4) <= gUnk_030025FC + 160)
        {
            sprNode->flags &= ~0x80;
            sprNode->attr0 = (sprNode->attr0 & 0xFF00) + ((screenY + offsetY) & 0xFF);
            sprNode->attr1 = (sprNode->attr1 & 0xFE00) + ((screenX + offsetX) & 0x1FF);
            updateFlag = 1;
        }
        else
        {
            sprNode->flags |= 0x80;
        }


        sprNode = sprNode->next;

        num--;
    }

    if(updateFlag != 0)
    {
        struct SpriteNode* r1;
        struct SpriteNode* r2;
        i = 0;

        while(i < 128)
        {
            r1 = gSpriteRenderQueue[i];

            if(r1 == 0)
            {
                gSpriteRenderQueue[i] = &gSpriteNodePool[arg2];
                break;
            }

            if((u16)r1->y < y)
            {
                r2 = r1;
                gSpriteRenderQueue[i] = &gSpriteNodePool[arg2];
                // i++;

                j = (u16)(i + 1);
                while(j < 128)
                {
                    r1 = gSpriteRenderQueue[j];
                    gSpriteRenderQueue[j] = r2;
                    r2 = r1;
                    if(r2 == 0)
                        break;
                    j++;
                }


                return 0;
            }

            i++;
        }
        return 0;
    }
    return 1;
}
*/

INCLUDE_ASM("asm/matchings", sub_800271C);
/*

//这些数据在原始rom rodata中的位置是在 tileset_3_080583C4 后面
u8 gWalkAnimFrameMapping[] = {0, 1, 2, 1, 0, 1, 0, 1};
u8 gWalkDirectionMapping[] = {2, 3, 3, 3, 0, 1, 1, 1, 1, 2, 2, 2, 3, 0, 0, 0, 0};



extern SpriteNode gSpriteNodePool[128];

extern SpriteNode* gSpriteRenderQueue[128];

extern CharacterObject gCharacterObjects[];


void sub_800271C(u8 arg0)
{
    CharacterObject *charaObj;
    SpriteNode* sprNode;
    u16 paletteBits;
    u8 directionIndex;
    u8 temp_r7;
    u32 currentFrameTileOffset;

    charaObj = &gCharacterObjects[arg0];

    if ((charaObj->field_1 & 1) == 0)
    {
        if(!(charaObj->field_12 & 4))
        {
            if(charaObj->field_11 == 0)
            {
                charaObj->walkAnimCounter++;
            }
        }

        charaObj->walkAnimCounter &= 0x1F;

        paletteBits = charaObj->paletteIdx ;
        paletteBits <<= 12;

        sprNode = &gSpriteNodePool[charaObj->sprNodeIdx];
        
        if ((charaObj->field_1 & 0x7C) == 0)
        {
            sprNode->animStep = charaObj->walkAnimCounter >> 3;

            currentFrameTileOffset = gWalkAnimFrameMapping[sprNode->animStep] * 6;

            directionIndex = gWalkDirectionMapping[charaObj->facing];
            temp_r7 = directionIndex;

            if (temp_r7 == 3)
            {
                directionIndex = 1;
                sprNode->attr1 |= 0x1000;
            }
            else
            {
                sprNode->attr1 &= ~0x1000;
            }
            sprNode->attr2 = ((sprNode->attr2 & 0xC00) | ((directionIndex*18 + currentFrameTileOffset + charaObj->vramSlotIdx * 72 + 0xA0) & 0x3FF)) | paletteBits;

            sprNode = sprNode->next;
            if(sprNode)
            {
                if(temp_r7 == 3)
                {
                    sprNode->attr1 |= 0x1000;
                }
                else
                {
                    sprNode->attr1 &= ~0x1000;
                }
                sprNode->attr2 = ((sprNode->attr2 & 0xC00) | ((directionIndex*18 + currentFrameTileOffset + charaObj->vramSlotIdx * 72 + 0xA4) & 0x3FF)) | paletteBits;
            }

        }
        else if ((charaObj->field_1 & 4) == 0)
        {
            if ((charaObj->field_1 & 0x10) == 0)
            {
                if ((charaObj->field_1 & 0x20) )
                {
                    if (charaObj->facing != 0)
                    {
                        sprNode->attr2 = (sprNode->attr2 & 0xFC00) + ((charaObj->vramSlotIdx * 72 + 0xB0) & 0x3FF);
                    }
                    else
                    {
                        sprNode->attr2 = (sprNode->attr2 & 0xFC00) + ((charaObj->vramSlotIdx * 72 + 0xC0) & 0x3FF);
                    }

                    sprNode = sprNode->next;
                    sprNode->attr2 = (sprNode->attr2 & 0xFC00) + ((charaObj->vramSlotIdx * 72 + 0xA0) & 0x3FF);
                }
            }
            else
            {
                sprNode->animStep = charaObj->walkAnimCounter >> 3;
                directionIndex = gWalkDirectionMapping[charaObj->facing];
                
                if (directionIndex == 1)
                {
                    sprNode->attr1 |= 0x1000;
                }
                else
                {
                    sprNode->attr1 &= ~0x1000;
                }
            sprNode->attr2 = ((sprNode->attr2 & 0xC00) | ((charaObj->vramSlotIdx * 72 + 0xA0) & 0x3FF)) | paletteBits;
            }
        }
        else 
        {
            if ((charaObj->field_1 & 8) == 0)
            {
            
                sprNode->animStep = 0;
                temp_r7 =(charaObj->walkAnimCounter >> 3) & 3;

                directionIndex = gWalkDirectionMapping[charaObj->facing + 8];
                
                if (directionIndex & 1)
                {
                    currentFrameTileOffset = 0x20;
                }
                else
                {
                    currentFrameTileOffset = gWalkAnimFrameMapping[temp_r7 + 4] << 4;
                }
     
                if (directionIndex & 2)
                {
                    sprNode->attr1 |= 0x1000;
                }
                else
                {
                    sprNode->attr1 &= ~0x1000;
                }

            // sprNode->attr2 = ((sprNode->attr2 & 0xC00) | ((chara->field_2 * 72 +currentFrameTileOffset + 0xA0) & 0x3FF)) | paletteBits;
            }
            else
            {
                sprNode->animStep = 0;
                temp_r7 = (charaObj->walkAnimCounter >> 3) & 3;
                currentFrameTileOffset = gWalkAnimFrameMapping[temp_r7] * 16;
                sprNode->attr1 &= ~0x1000;
            }
            sprNode->attr2 = ((sprNode->attr2 & 0xC00) | ((charaObj->vramSlotIdx * 72 +currentFrameTileOffset + 0xA0) & 0x3FF)) | paletteBits;

        }
        return;
    }

    sub_80029D8(arg0);
}

asm(".align 2,0");

*/

INCLUDE_ASM("asm/matchings", sub_80029D8);

/*


extern u8* gUnk_030032E0[];
extern u8 gUnk_03003490[];
extern u8 gUnk_03002C60[];

extern u8* gUnk_030044C0[];

u8 sub_8004A6C();

void sub_8002B54(u8 arg0, u8 *arg1);

void sub_8004A94(u8 , void* , u8 , u8 );


void sub_80029D8(u8 arg0) {
    CharacterObject* chara;
    u8* animDataPtr;
    u8* frameDataPtr;
    u16 offset;

    chara = &gUnk_03002E80[arg0];

    if(chara->currAnimIdx == 0xFF)
        
        return;

    animDataPtr = gUnk_030044C0[chara->currAnimIdx];

    if(chara->animFrameTimer == 0xFF)
        return;

    // offset = animDataPtr[2] + (animDataPtr[3] << 8);

    frameDataPtr = animDataPtr +  (animDataPtr[2] + (animDataPtr[3] << 8));

    
    if(chara->animFrameTimer == 0)
    {
        if( animDataPtr[6] + (animDataPtr[7] << 8) == 2)
        {
            sub_8004A94(sub_8004A6C(), gUnk_030032E0[chara->currAnimIdx], gUnk_03003490[chara->currAnimIdx] + 16, 2);
        }
        else
        {
            sub_8004A94(sub_8004A6C(), gUnk_030032E0[chara->currAnimIdx], gUnk_03003490[chara->currAnimIdx] + 16, 0);

        }
        frameDataPtr += 8;

        offset = (frameDataPtr[0] + (frameDataPtr[1] << 8)) << 1;
        // unkPtr = &animDataPtr[offset];

        sub_8002B54(arg0, (animDataPtr + animDataPtr[offset + 8] + (animDataPtr[offset + 9]<<8)) + 4);
        chara->animFrameTimer++;
    }
    else
    {
        u16 time = frameDataPtr[2] + (frameDataPtr[3] << 8);
        u16 count = frameDataPtr[6] + (frameDataPtr[7] << 8);

        frameDataPtr += 8;

        if(chara->animFrameTimer >= time)
        {
            if((gUnk_03002C60[chara->currAnimIdx] & 0x80) == 0)
            {
                chara->animFrameTimer = 0xFF;
                return;
            }
            else
            {
                chara->animFrameTimer = 0;
            }
        }
        
        while(count != 0)
        {
            if(chara->animFrameTimer == frameDataPtr[2] + (frameDataPtr[3] << 8) || chara->animFrameTimer == 0)
            {
                sub_8004F3C(&gRenderObjects[chara->sprNodeIdx]);
                if(chara->animFrameTimer == 0)
                {
                    offset = (frameDataPtr[0] + (frameDataPtr[1] << 8)) << 1;
                }
                else
                {
                    offset = (frameDataPtr[4] + (frameDataPtr[5] << 8)) << 1;
                }
                // offset = offset << 1;
                // unkPtr = animDataPtr + offset;
                // unkPtr = animDataPtr + unkPtr[8] + (unkPtr[9] << 8);
                
                sub_8002B54(arg0, (animDataPtr + animDataPtr[offset+8] + (animDataPtr[offset+9]<<8)) + 4);
                // sub_8002B54(arg0,  unkPtr + 4);
                break;

            }
            frameDataPtr+=4;
            count--;
        }
        

        if(chara->animFrameTimer != 0xFF)
        {
            chara->animFrameTimer++;
        }
        
    }
    
}
*/

INCLUDE_ASM("asm/matchings", sub_8002B54);

/*
extern u8 gUnk_03003490[];
extern s8 gUnk_0805887C[];

extern u32 gVramBufferPointers[];
extern s8 gUnk_08058834[];

extern u8 gSpriteWidth;
extern u8 gSpriteHeight;

const u8 gSpriteTileCount[4][4] = {
    // Size:   0,  1,  2,  3
    [0] = {    1,  4, 16, 64 }, // Shape 0: Square (8x8, 16x16, 32x32, 64x64)
    [1] = {    2,  4,  8, 32 }, // Shape 1: Horizontal (16x8, 32x8, 32x16, 64x32)
    [2] = {    2,  4,  8, 32 }, // Shape 2: Vertical (8x16, 8x32, 16x32, 32x64)
    [3] = {   99, 99, 99, 99 }  // Shape 3: Prohibited/Invalid
};

// 命名为：Sprite占用Tile数量查找表
const u8 gSpriteTileCountTable[] = {
    1, 4, 16, 64,  // Square: 8x8, 16x16, 32x32, 64x64
    2, 4,  8, 32,  // Horizontal: 16x8, 32x8, 32x16, 64x32
    2, 4,  8, 32,  // Vertical: 8x16, 8x32, 16x32, 32x64
    99, 99, 99, 99 // Invalid/Prohibited Shape
};


const u8 gSpriteDimensionsTable[] = {
    8, 8, 16, 16, 32, 32, 64, 64, // Shape 0: Square
    16, 8, 32, 8, 32, 16, 64, 32, // Shape 1: Horizontal
    8, 16, 8, 32, 16, 32, 32, 64, // Shape 2: Vertical
    0, 0, 0, 0, 0, 0, 0, 0        // Shape 3: Invalid
};

void sub_8004B2C(u16 id, void* src, void* dest, u8 arg3);


//00 00   idx
//02 00   num

//DF 80 F4 81 00 00 DF 80 04 40 08 00
//SpriteOamAttr[num]

void sub_8002B54(u8 arg0, u8 *arg1) {
    Unk_03002E80 *ptr2E80;
    struct SpriteNode *renderObj;
    struct SpriteNode *subObj;

    u16 vramOffset;
    u8 oamDataOffset;
    u16 val_r8;
    u8 num;
    u8* oamDataPtr;

    u8 tileCount;
    u16 dmaSlotId;
    u8* src;
    u8* dest;

    u8 val_r4_1;

    u16 attr0;
    u16 attr1;
    u16 attr2;
    s16 x;

    ptr2E80 = &gUnk_03002E80[arg0];

    if(arg0 <= 0x12)
    {
        vramOffset = 0x800;
        if (gMainGameState == 0xB)
        {
            vramOffset = 0x400;
        }
    }
    else
    {
        vramOffset = 0;
    }

    oamDataOffset = arg1[0] * 6 + 4;
    num = arg1[2];

    ptr2E80->sprNodeIdx = sub_8004BFC();
    renderObj = &gSpriteNodePool[ptr2E80->sprNodeIdx];

    val_r8 = gUnk_03003490[ptr2E80->field_16] * 72 + 160;

    oamDataPtr = &arg1[oamDataOffset];

    while(num != 0)
    {

        tileCount = gSpriteTileCountTable[(oamDataPtr[1] >> 6) * 4 + (oamDataPtr[3] >> 6)];

        val_r4_1 = oamDataPtr[4];
        dmaSlotId = sub_8004A44();

        src = (u8*) gVramBufferPointers[ptr2E80->field_16] + (val_r4_1 << 5);
        dest = (u8*)0x06010000 + (val_r8 << 5);
        sub_8004B2C(dmaSlotId, src, dest, tileCount);

        attr0 = oamDataPtr[0] | (oamDataPtr[1] << 8);

        if ((gUnk_03002C60[ptr2E80->field_16] & 0x40) != 0)
        {
            attr1 = (oamDataPtr[2] + (oamDataPtr[3] << 8)) | 0x1000;
        }
        else
        {
            attr1 = (oamDataPtr[2] + (oamDataPtr[3] << 8));
            renderObj->field_10 = attr1 & 0x1FF;
        }
        renderObj->field_12 = attr0 & 0xFF;

        attr2 = ((oamDataPtr[5] << 8) & ~0xFFF) + (vramOffset +(gUnk_03003490[ptr2E80->field_16] << 12) +  val_r8);

        subObj = sub_8004C28(renderObj, num, attr0, attr1, attr2);

        if ((gUnk_03002C60[ptr2E80->field_16] & 0x40) != 0)
        {

            gSpriteWidth = gSpriteDimensionsTable[ ((renderObj->attr0 >> 11) & 0x18) + ((renderObj->attr1 >> 13) & 6)];

            gSpriteHeight = gSpriteDimensionsTable[ ((renderObj->attr0 >> 11) & 0x18) + ((renderObj->attr1 >> 13) & 6) + 1];

            x = (~(attr1 & 0x1FF) - gSpriteWidth) & 0x1FF;
            renderObj->field_10 = x;
        }
        if (renderObj->field_10 > 0xFF)
        {
            renderObj->field_10--;
        }
        renderObj = subObj;

        oamDataPtr += 6;
        val_r8 += tileCount;

        num--;
    }
}

*/

// UpdateEncounter
u8 sub_8002D54(void)
{

    // gEncounterEnabled
    if (gUnk_03004820 == 0)
        return 0;

    if (gHeldKeysRaw & DPAD_ANY)
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
            gBlendControl = 0x1E41;
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

const u8 pltt_08057854[] = INCBIN_U8("data/lunar_logo/pltt.gbapal");
const u8 tilemap_08057874[] = INCBIN_U8("data/lunar_logo/tilemap.bin.lz");
const u8 tileset_1_08057A80[] = INCBIN_U8("data/lunar_logo/tileset_1.4bpp.lz");
const u8 tileset_2_08057EEC[] = INCBIN_U8("data/lunar_logo/tileset_2.4bpp.lz");
const u8 tileset_3_080583C4[] = INCBIN_U8("data/lunar_logo/tileset_3.4bpp.lz");

// extern u8 pltt_08057854[];
// extern u8 tilemap_08057874[];
// extern u8 tileset_1_08057A80[];
// extern u8 tileset_2_08057EEC[];
// extern u8 tileset_3_080583C4[];
#define GET_PLTT(n)    ((n) + 0)
#define GET_TILEMAP(n) ((n) + 32)
// INCLUDE_ASM("asm/matchings", sub_8002F6C);

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
            gBlendControl = 0x1C12;
            gUnk_03004550 = 0xC07;
            CpuFill16(0, (void *)0x0600F800, 0x800);

            gUnk_03002604 = 0;
        default:
            return;
    }
}


const u8 gUnk_0805881C[] ={0, 1, 5, 0, 7, 8, 6,
      0, 3, 2, 4, 0, 0, 0, 0, 0};

const u8 gUnk_0805882C[] ={0,1,2,1, 0,1,0,1};

const u8 gUnk_08058834[] = {
    8, 8, 16, 16, 32, 32, 64, 64,
    16, 8, 32, 8, 32, 16, 64, 32,
    8, 16, 8, 32, 16, 32, 32, 64,

    1, 1, 1, 1, 1, 1, 1, 1,

    15, 0, 0, 0, 252, 255, 228, 255,
    15, 0, 0, 0, 0, 0, 240, 255
};

const u8 gUnk_08058864[] = {2, 3, 3, 3, 0, 1, 1, 1, 1, 2, 2, 2, 3, 0, 0, 0, 0,1, 1, 1, 1, 0, 0, 0};

const u8 gUnk_0805887C[] = {1, 4, 0x10, 0x40, 2, 4, 8, 0x20, 2, 4, 8, 0x20, 0x63, 0x63, 0x63, 0x63};

void sub_8003088(void)
{
    ReadKeys();
    sub_8004BE0();
    gUnk_087E83F8[gMainGameState]();
}

//地图场景切换，加载数据精灵
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
        sub_8008254(gNewKeysRaw);
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

void sub_80032BC(void) {
    u16 i;
    SpriteNode* sprNode;
    u8 count;
    u16 index;

    index = 0;

    for(i = 0; i < 128; i++)
    {
        sprNode = gSpriteRenderQueue[i];
        if(sprNode == NULL)
            continue;

        count = sprNode->flags & 0x7F;
        if(count)
        {
            while(count--)
            {
                if(count == 0xFF)
                    break;
                sprNode = sub_8004F64(&index, sprNode);
                if (sprNode == NULL)
                    break;
            }
        }

        if(index > 0x7F)
            return;
    }

    while(index < 128)
    {
        gOamBuffer[index].attrs[0] = 0xA0;
        gOamBuffer[index].attrs[1] = 0;
        index++;
    }

}

void sub_8003348(void)
{
    CharacterObject *charaObj;
    u8 sprNodeIdx;
    s16 i;
    u8 count;
    struct SpriteNode *current;
    struct SpriteNode *next;

    for (i = 0; i <= 23; i++)
    {
        charaObj = &gUnk_03002E80[i];
        sprNodeIdx = charaObj->sprNodeIdx;

        if (sprNodeIdx != 0)
        {

            if (charaObj->field_18 != 0)
            {
                gSpriteNodePool[charaObj->field_18].flags = 0;
                gSpriteNodePool[charaObj->field_18].next = 0;
                charaObj->field_18 = 0;
            }

            count = gSpriteNodePool[sprNodeIdx].flags;
            count &= 0x7F;
            current = &gSpriteNodePool[sprNodeIdx];

            while (count != 0)
            {
                current->flags = 0;
                next = current->next;
                current->next = 0;
                current = next;
                count--;
            }
        }
        gUnk_03002E80[i].sprNodeIdx = 0;
    }
}
INCLUDE_ASM("asm/matchings", sub_80033E8);
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

extern u8 gUnk_08091948[];

extern Unk_08088D80 gUnk_08088D80[];

typedef struct {
    u16 field_0;
    u8 pad[16 - 2];
}Unk_087EA394;
extern Unk_087EA394* gUnk_087EA394[];

void sub_800345C(u8, void*);


void sub_80033E8(u8 arg0) {
    Unk_087EA394* ptr2;
    u16 i;
    u16 temp_r0;
    u32 temp_r3;

    if (gUnk_0300467C & 0x80) 
        return;

    i = temp_r3 = gUnk_08088D80[arg0].field_9;
    if (i == 0)
        return;

    temp_r0 = (i - 1) * 18;
    arg0 = gUnk_08091948[temp_r0];

    ptr2 = gUnk_087EA394[temp_r3 - 1];
              

    for ( i = 2; i < arg0 + 2; i++)
    {
        sub_800345C(i, ptr2++);
    }
}
*/
INCLUDE_ASM("asm/matchings", sub_800345C);
/*
typedef struct{
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
    u8* field_C;
}UnkStruct;
void sub_800345C(u8 arg0, UnkStruct* arg1) {
    CharacterObject *chara;
    struct SpriteNode* renderObj;
    struct SpriteNode* subRenderObj;
    u8 idx;
    u16 attr0, attr1, attr2;

    chara = &gUnk_03002E80[arg0];
    idx = sub_8004BFC();

    if(idx > 0x6F)
        return;

    renderObj = &gRenderObjects[idx];
    chara->sprNodeIdx = idx;
    chara->fields_1.all_fields = arg1->field_0;
    chara->field_2 = arg1->field_1;
    chara->paletteId = arg1->field_2;

    chara->facingDir = arg1->field_3;
    chara->x = arg1->field_4 << 3;
    chara->y = (arg1->field_5 + 1) << 3;
    chara->field_A = arg1->field_6;
    chara->field_B = arg1->field_7;
    chara->field_C = arg1->field_8;
    chara->field_D = arg1->field_9;
    chara->field_F = arg1->field_A;
    chara->field_13 = arg1->field_B;
    chara->field_24 = arg1->field_C;
    chara->animTimer = 0;
    chara->field_E = chara->facingDir;
    chara->field_10 = 1;
    chara->field_11 = 0;
    chara->field_12 = 0;
    chara->field_17 = 0;
    chara->field_1A = 0;
    chara->field_18 = 0;
    chara->field_19 = 0;
    chara->field_14 = 0;
    chara->animIdx = 0xFF;

    if(chara->fields_1.stru.bit0 == 0)
    {
        if(chara->fields_1.stru.bit2)
        {
            attr0 = 0;
            attr1 = 0x8000;
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            renderObj->field_10 = 0x1F8;
            renderObj->field_12 = 0xE0;
            sub_8004C28(renderObj, 1, attr0, attr1, attr2);
        }
        else if(chara->fields_1.stru.bit4)
        {
            attr0 = 0x4000;
            attr1 = 0xC000;
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            renderObj->field_10 = 0x1E8;
            renderObj->field_12 = 0xF8;
            sub_8004C28(renderObj, 1, attr0, attr1, attr2);
        }
        else if(chara->fields_1.stru.bit5)
        {
            attr1 = 0x8000;
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xB0) & 0x3FF);
            renderObj->field_10 = 0x1F8;
            renderObj->field_12 = 0xE8;
            subRenderObj = sub_8004C28(renderObj, 2, 0, attr1, attr2);
            
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            subRenderObj->field_10 = 0x1F8;
            subRenderObj->field_12 = 0xC8;

            sub_8004C28(subRenderObj, 1, 0, attr1, attr2);    
    
        }
        else if(chara->fields_1.stru.bit6)
        {
            attr1 = 0x8000;
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            renderObj->field_10 = 0x1F8;
            renderObj->field_12 = 0xEE;
            subRenderObj = sub_8004C28(renderObj, 3, 0, attr1, attr2);
            
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xB0) & 0x3FF);
            subRenderObj->field_10 = 0x18;
            subRenderObj->field_12 = 0xEE;
            subRenderObj = sub_8004C28(subRenderObj, 2, 0, attr1, attr2);

            attr0 = 0x8000;
            attr1 = 0x8000;

            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xC0) & 0x3FF);
            subRenderObj->field_10 = 0x38;
            subRenderObj->field_12 = 0xEE;
            sub_8004C28(subRenderObj, 1, attr0, attr1, attr2);
        }
        else
        {
            attr1 = 0x4000;
          
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            renderObj->field_10 = 0;
            renderObj->field_12 = 0xE8;

            subRenderObj = sub_8004C28(renderObj, 2, 0, attr1, attr2);

            attr0 = 0x4000;

            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA4) & 0x3FF);
            subRenderObj->field_10 = 0;
            subRenderObj->field_12 = 0xF8;
            // attr1 = 0;
            subRenderObj = sub_8004C28(subRenderObj, 1, attr0, 0, attr2);
        }
    }
    else
    {
        renderObj->field_0 = 0x81;
        renderObj->subObject = NULL;
    }
    renderObj->animFrame = 0;
}


*/
void sub_800375C(u8 arg0)
{
    u8 temp_r1;
    CharacterObject *ptr3150;
    ptr3150 = &gUnk_03003178[arg0];
    temp_r1 = sub_8004BFC();
    if (temp_r1 < 0x70)
    {
        ptr3150->sprNodeIdx = 0;
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
        ptr3150->animIdx = 0xFF;
    }
}

void sub_80037DC(u8 arg0)
{
    u8 idx;
    CharacterObject *charaObj;
    SpriteNode *sprNode;

    charaObj = &gUnk_03002E80[arg0];

    idx = sub_8004BFC();
    if (idx < 0x70)
    {
        sprNode = &gSpriteNodePool[idx];
        charaObj->sprNodeIdx = idx;
        charaObj->field_1 = 2;
        charaObj->field_2 = 5;
        charaObj->paletteId = 5;
        charaObj->facingDir = 0;
        charaObj->field_A = 0;
        charaObj->field_B = 0;
        charaObj->field_C = 0;
        charaObj->field_D = 0;
        charaObj->field_F = 0;
        charaObj->field_13 = 0;
        charaObj->field_24 = 0;
        charaObj->animTimer = 0;
        charaObj->field_E = 0;
        charaObj->field_10 = 1;
        charaObj->field_11 = 0;
        charaObj->field_12 = 32;
        charaObj->field_17 = 0;
        charaObj->field_1A = 0;
        charaObj->field_18 = 0;
        charaObj->field_19 = 0;

        sprNode->flags = 0;
        sprNode->animStep = 0;
        sprNode->next = 0;
    }
}

void sub_800384C(void)
{
    u8 temp_r1;
    CharacterObject *ptr3150;
    struct SpriteNode *sprNode;

    ptr3150 = &gUnk_03003150;
    temp_r1 = sub_8004BFC();
    if (temp_r1 < 0x70)
    {
        sprNode = &gSpriteNodePool[temp_r1];
        ptr3150->sprNodeIdx = temp_r1;
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

        sprNode->flags = 128;
        sprNode->animStep = 0;
        sprNode->next = 0;
    }
}
INCLUDE_ASM("asm/matchings", sub_80038CC);

/*
extern u8* gUnk_087E8430[];
extern u16 gUnk_030032D4;
extern u8 gUnk_03004540;
extern u16 gUnk_03003240;

extern u8 gUnk_080B9DFC[][32];
extern u8 gUnk_030034B0;

static inline void Inl_LoadSpriteSheetGfx(u8 id1, u16 idx)
{
    u8* dst = (void*)0x06011400 + id1 * 0x900;
    LZ77UnCompVram(gUnk_087E8430[idx],   dst);
}
static inline void Inl_LoadSpriteSheetPal(u8 id1, u16 idx)
{
    u8* src;
    u8* dst;
    src = gUnk_080B9DFC[idx];
    dst = (void*)0x05000200 + id1 * 32;
    DmaCopy16(3, src , dst ,0x20);
}

// LoadSpriteSheetAndPal
void sub_80038CC(void) {

    if (1 & gUnk_030032D0)
    {
        // CopySprite((void*)0x06011400 + gUnk_03004540 * 0x900,gUnk_030032D4);
        Inl_LoadSpriteSheetGfx(gUnk_03004540, gUnk_030032D4);
    }
    if (2 & gUnk_030032D0)
    {
        Inl_LoadSpriteSheetPal(gUnk_030034B0, gUnk_03003240);
    }
    gUnk_030032D0 = 0;
}
    */

INCLUDE_ASM("asm/nonmatchings", sub_8003958);
void sub_8003B08(u16 arg0)
{
    u8 var_r5;
    u8 *temp_r2;
    CharacterObject *chara;
    u8 cmd;

    chara = &gUnk_03002E80[arg0];

    if (chara->field_24 != 0)
    {
        var_r5 = 0;
        while (var_r5 == 0)
        {
            temp_r2 = chara->field_24 + chara->field_17;
            cmd = *temp_r2++;
            switch (cmd)
            {
                case 0xFE:
                    chara->field_17 = 0;
                    break;
                case 0xFD:
                    chara->field_12 |= 0x20;
                    chara->field_12 &= 0x7F;
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
                    chara->field_12 |= 0x10;
                    chara->field_17 += 4;

                    chara->field_E = *temp_r2++;
                    chara->field_E &= 7;

                    chara->field_F = temp_r2[0];
                    chara->field_10 = temp_r2[1] + 1;
                    return;

                default:
                    chara->field_17 += 4;
                    chara->field_E = temp_r2[0];
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

    if (gUnk_030025D8 == 0)
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
INCLUDE_ASM("asm/matchings", sub_8003F40);
INCLUDE_ASM("asm/nonmatchings", sub_80040E4);
// INCLUDE_ASM("asm/matchings", sub_8004358);

void sub_8004358(void) {
    u16 i;

    if(!(gUnk_03002C44 & 1))
    {
        for(i = 0; i < 8; i++)
        {
            gUnk_030025C0[i] = gUnk_03002E80[0].x;
            gUnk_030025E0[i] = gUnk_03002E80[0].y;
            gUnk_03002C58[i] = gUnk_03002E80[0].facingDir & 7;
        }

        gUnk_03002E80[1].x = gUnk_03002E80[0].x;
        gUnk_03002E80[1].y = gUnk_03002E80[0].y;
        gUnk_03002E80[1].facingDir = gUnk_03002E80[0].facingDir & 7;
    }
}

// INCLUDE_ASM("asm/matchings", sub_80043D4);

void sub_80043D4(void) {
    u16 i;

    for(i = 0; i < 8; i++)
    {
        gUnk_030025C0[i] = gUnk_03002E80[0].x;
        gUnk_030025E0[i] = gUnk_03002E80[0].y;
        gUnk_03002C58[i] = gUnk_03002E80[0].facingDir;
    }

    gUnk_03002E80[1].x = gUnk_030025C0[7];
    gUnk_03002E80[1].y = gUnk_030025E0[7];
    gUnk_03002E80[1].facingDir = gUnk_03002C58[7];
    gUnk_03002C44 &= 0x80;
}
INCLUDE_ASM("asm/matchings", sub_800445C);
/*
void sub_800445C(void) {
    CharacterObject* chara;
    u16 i;

    u8 a;
    chara = &gUnk_03002E80[0];
    if(chara->sprNodeIdx != 0)
    {
        a = (chara->field_12 & 0x80);
        if(a != 0)
        {
            if(sub_8003C54(0) < 2)
            {
                sub_8003B08(0);
            }

            for(i = 7; i > 0; i--)
            {
                gUnk_030025C0[i] = gUnk_030025C0[i - 1];
                gUnk_030025E0[i] = gUnk_030025E0[i - 1];
                gUnk_03002C58[i] = gUnk_03002C58[i - 1];
            }

            gUnk_030025C0[0] = chara->x;
            gUnk_030025E0[0] = chara->y;
            gUnk_03002C58[0] = chara->facingDir & 7;

            gUnk_030025B0 = chara->facingDir;
            gUnk_030025F8 = chara->x;
            gUnk_03002C3C = chara->y - 8;

        }

        else
        {
            if((u8)(gUnk_0300260C - 6) < 2 || gUnk_0300260C == 9 || gUnk_0300260C == 10)
                return;

            if(chara->field_12 & 0x40)
            {
                chara->field_11 = 0 ;

                for(i = 7; i > 0; i--)
                {
                    gUnk_030025C0[i] = gUnk_030025C0[i - 1];
                    gUnk_030025E0[i] = gUnk_030025E0[i - 1];
                    gUnk_03002C58[i] = gUnk_03002C58[i - 1];
                }
                gUnk_030025C0[0] = chara->x;
                gUnk_030025E0[0] = chara->y;
                gUnk_03002C58[0] = chara->facingDir & 7;

            }
            else
            {
                chara->field_11 = 1;
            }
            chara->facingDir = gUnk_030025B0;
            chara->x = gUnk_030025F8;
            chara->y = gUnk_03002C3C + 8;

        }

        if((chara->field_1 & 1) == 0)
        {
            sub_800271C(0);
            sub_800243C(chara->x, chara->y, chara->sprNodeIdx, chara->field_1A, chara->field_1 );
            if(chara->field_18 != 0)
            {
                gSpriteNodePool[chara->field_18].field_0 = 0;
                gSpriteNodePool[chara->field_18].subObject = 0;
                chara->field_18 = 0;
            }

            sub_8002380(0);
        }
    }

    chara++;
    if(chara->sprNodeIdx != 0)
    {
        if((gUnk_03002C44 & 1) == 0)
        {
            if((u8)( gUnk_0300260C - 6) < 2 || gUnk_0300260C == 9 || gUnk_0300260C == 10)
                return;
            {
                chara->facingDir = gUnk_03002C58[7];
                chara->x = gUnk_030025C0[7];
                chara->y = gUnk_030025E0[7];
            }

        }
        else
        {
            if(chara->field_12 & 0x80 && sub_8003C54(1) < 2)
            {
                sub_8003B08(1);
            }
        }

        if((chara->field_1 & 1) == 0)
        {
            sub_800271C(1);
            sub_800243C(chara->x, chara->y, chara->sprNodeIdx, chara->field_1A, chara->field_1 );
            if(chara->field_18 != 0)
            {
                gSpriteNodePool[chara->field_18].field_0 = 0;
                gSpriteNodePool[chara->field_18].subObject = 0;
                chara->field_18 = 0;
            }

            sub_8002380(1);
        }
    }


}
*/
// INCLUDE_ASM("asm/matchings", sub_80046DC);


typedef struct{
    u16 scriptIdx;
    u16 gfxIdx;
    u8 palIdx;
    u8 field_5;
    u16 field_6;
}CutsceneAnimConfig;

const CutsceneAnimConfig gCutsceneAnimConfigTable[] = {
{0, 0, 0, 0x80, 0},
{1, 1, 1, 0x80, 0},
{2, 2, 2, 0x80, 0},
{3, 3, 8, 0, 0},
{4, 4, 3, 0x80, 0},
{5, 5, 0, 0x80, 0},
{6, 6, 0, 0x80, 0},
{7, 7, 0, 0, 0},
{8, 8, 2, 0x80, 0},
{9, 9, 1, 0x80, 0},
{0xA, 0xA, 1, 0x80, 0},
{0xB, 0xB, 1, 0, 0},
{0xC, 0xC, 1, 0, 0},
{0xD, 0xD, 0, 0, 0},
{0xE, 0xE, 0, 0, 0},
{0xF, 0xF, 2, 0, 0},
{0x10, 0x10, 1, 0, 0},
{0x11, 0x11, 1, 0, 0},
{0x12, 0x12, 1, 0, 0},
{0x13, 0x13, 1, 0, 0},
{0x14, 0x14, 2, 0x80, 0},
{0x15, 0x15, 1, 0x80, 0},
{0x16, 0x16, 1, 0, 0},
{0x17, 0x17, 1, 0x80, 0},
{0x18, 0x18, 0, 0x80, 0},
{0x19, 0x19, 0, 0x80, 0},
{0x1A, 0x1A, 1, 0x80, 0},
{0x1B, 0x1B, 4, 0x80, 0},
{0x1C, 0x1C, 4, 0, 0},
{0x1D, 0x1D, 4, 0, 0},
{0x1E, 0x1E, 0, 0, 0},
{0x1F, 0x1F, 1, 0, 0},
{0x20, 0x20, 0, 0, 0},
{0x21, 0x21, 1, 0, 0},
{0x22, 0x22, 2, 0, 0},
{0x23, 0x23, 3, 0x80, 0},
{0x24, 0x24, 0xE, 0x80, 0},
{0x25, 0x25, 0xE, 0, 0},
{0x26, 0x26, 3, 0x80, 0},
{0x27, 0x27, 0, 0x80, 0},
{0x28, 0x28, 1, 0x80, 0},
{0x29, 0x29, 0, 0x80, 0},
{0x2A, 0x2A, 0, 0, 0},
{3, 3, 9, 0, 0},
{0x2B, 0x2B, 1, 0, 0},
{0x2C, 0x2C, 0, 0, 0},
{0x2D, 0x2D, 0xA, 0, 0},
{0x2E, 0x2E, 0xA, 0, 0},
{0x2F, 0x2F, 0xA, 0, 0},
{0x30, 0x30, 0xA, 0, 0},
{0x31, 0x31, 0xA, 0, 0},
{0x32, 0x32, 0xA, 0x80, 0},
{0x33, 0x33, 4, 0x80, 0},
{0x34, 0x34, 4, 0, 0},
{0x35, 0x35, 5, 0x80, 0},
{0x36, 0x36, 5, 0, 0},
{0x37, 0x37, 6, 0x80, 0},
{0x38, 0x38, 6, 0, 0},
{0x39, 0x39, 7, 0x80, 0},
{0x3A, 0x3A, 7, 0, 0},
{0x3B, 0x3B, 0xB, 0, 0},
{0x3B, 0x3B, 0xC, 0, 0},
{0x3C, 0x3C, 0xF, 0, 0},
{0x3D, 0x3D, 0xF, 0, 0},
{0x3E, 0x3E, 0x10, 0x80, 0},
{0x3F, 0x3F, 0x11, 0, 0},
{0x40, 0x40, 0x11, 0, 0},
{0x41, 0x41, 4, 0x80, 0},
{0x42, 0x42, 4, 0x80, 0},
{0x43, 0x43, 4, 0x80, 0},
{0x44, 0x44, 4, 0, 0},
{0x45, 0x45, 4, 0x80, 0},
{0x46, 0x46, 4, 0, 0},
{0x47, 0x47, 4, 0, 0},
{0x48, 0x48, 0xD, 0x80, 0},
{0x49, 0x49, 0xD, 0x80, 0},
{0x4A, 0x4A, 0x12, 0, 0},
{0x4B, 0x4B, 0x13, 0, 0},
{0x4C, 0x4C, 0x14, 0, 0},
{0x4D, 0x4D, 0x14, 0, 0},
{0x4E, 0x4E, 0x14, 0, 0},
{0x4F, 0x4F, 0x14, 0, 0},
{0x50, 0x50, 0x15, 0x80, 0},
{0x51, 0x51, 0x16, 0, 0},
{0x52, 0x52, 4, 0x80, 0},
{0x53, 0x53, 0, 0x80, 0},
{0x54, 0x54, 2, 0x80, 0},
{0x55, 0x55, 0, 0x80, 0},
{0x56, 0x56, 1, 0x80, 0},
{0x57, 0x57, 2, 0x80, 0},
{0x58, 0x58, 4, 0x80, 0},
{0x59, 0x59, 0, 0x80, 0},
{0x5A, 0x5A, 4, 0x80, 0},
{0x5B, 0x5B, 0x17, 0, 0},
{0x5C, 0x5C, 0x17, 0, 0},
{0x5D, 0x5D, 1, 0, 0},
{0x5E, 0x5E, 0x17, 0x80, 0},
{0x5F, 0x5F, 0, 0, 0},
{0x60, 0x60, 0, 0x80, 0},
{0x61, 0x61, 0x18, 0x80, 0},
{0x62, 0x62, 0x18, 0, 0},
{0x63, 0x63, 0x18, 0, 0},
{0x64, 0x64, 0x18, 0, 0},
{0x65, 0x65, 0x18, 0, 0},
{0x66, 0x66, 0x19, 0x80, 0},
{0x67, 0x67, 0x19, 0, 0},
{0x68, 0x68, 2, 0x80, 0},
{0x69, 0x69, 2, 0, 0},
{0x6A, 0x6A, 0x1A, 0x80, 0},
{0x6B, 0x6B, 0x1A, 0, 0},
{0x6C, 0x6C, 2, 0, 0},
{0x6D, 0x6D, 0x1A, 0, 0},
{0x6E, 0x6E, 0x1E, 0x80, 0},
{0x6F, 0x6F, 0x1E, 0x80, 0},
{0x70, 0x70, 0x1E, 0, 0},
{0x71, 0x71, 0x1E, 0, 0},
{0x72, 0x72, 0x1E, 0, 0},
{0x73, 0x73, 1, 0, 0},
{0x74, 0x74, 1, 0, 0},
{0x75, 0x75, 1, 0, 0},
{0x76, 0x76, 0x25, 0, 0},
{0x77, 0x77, 0x25, 0, 0},
{0x78, 0x78, 0x25, 0, 0},
{0x79, 0x79, 0x25, 0, 0},
{0x7A, 0x7A, 0x1C, 0x80, 0},
{0x7B, 0x7B, 0x1C, 0, 0},
{0x7C, 0x7C, 0x1C, 0, 0},
{0x7D, 0x7D, 0x1C, 0, 0},
{0x7E, 0x7E, 0x1C, 0, 0},
{0x7F, 0x7F, 0x1C, 0, 0},
{0x80, 0x80, 0x1C, 0, 0},
{0x81, 0x81, 0x1C, 0x80, 0},
{0x82, 0x82, 0x1F, 0, 0},
{0x83, 0x83, 0x23, 0x80, 0},
{0x84, 0x84, 0x1F, 0, 0},
{0x85, 0x85, 0x1F, 0x80, 0},
{0x86, 0x86, 0x1F, 0, 0},
{0x87, 0x87, 0x1F, 0x80, 0},
{0x88, 0x88, 0x24, 0x80, 0},
{0x89, 0x89, 0x24, 0, 0},
{0x8A, 0x8A, 1, 0x80, 0},
{0x8B, 0x8B, 1, 0x80, 0},
{0x8C, 0x8C, 1, 0, 0},
{0x8D, 0x8D, 0x1F, 0x80, 0},
{0x8E, 0x8E, 0x1F, 0, 0},
{0x8F, 0x8F, 0x1F, 0, 0},
{0x90, 0x90, 0, 0, 0},
{0x91, 0x91, 0, 0, 0},
{0x92, 0x92, 0, 0, 0},
{0x93, 0x93, 0, 0, 0},
{0x94, 0x94, 0x17, 0, 0},
{0x95, 0x95, 0x17, 0, 0},
{0x96, 0x96, 0x26, 0, 0},
{0x97, 0x97, 0x27, 0, 0},
{0x98, 0x98, 0x28, 0, 0},
{0x99, 0x99, 0x29, 0, 0},
{0x9A, 0x9A, 0x2A, 0, 0},
{0x9B, 0x9B, 0x2B, 0x80, 0},
{0x9C, 0x9C, 0x2B, 0, 0},
{0x9D, 0x9D, 0x2B, 0x80, 0},
{0x9E, 0x9E, 0x2C, 0x80, 0},
{0x9F, 0x9F, 6, 0, 0},
{0xA0, 0xA0, 6, 0x80, 0},
{0xA1, 0xA1, 6, 0, 0},
{0xA2, 0xA2, 6, 0, 0},
{0xA3, 0xA3, 0x2D, 0, 0},
{0xA4, 0xA4, 0x2D, 0, 0},
{0xA5, 0xA5, 0x2D, 0, 0},
{0xA6, 0xA6, 0x2D, 0, 0},
{0xA7, 0xA7, 0x2D, 0, 0},
{0xA8, 0xA8, 7, 0, 0},
{0xA9, 0xA9, 7, 0, 0},
{0xAA, 0xAA, 7, 0, 0},
{0xAB, 0xAB, 7, 0, 0},
{0xAC, 0xAC, 0x20, 0, 0},
{0xAD, 0xAD, 0x20, 0, 0},
{0xAE, 0xAE, 0x20, 0x80, 0},
{0xAF, 0xAF, 0x20, 0, 0},
{0xB0, 0xB0, 0x20, 0, 0},
{0xB1, 0xB1, 0x2E, 0x80, 0},
{0xB2, 0xB2, 0x2E, 0, 0},
{0xB3, 0xB3, 0x2E, 0, 0},
{0xB4, 0xB4, 0, 0, 0},
{0xB5, 0xB5, 0, 0x80, 0},
{0xB6, 0xB6, 0, 0x80, 0},
{0xB7, 0xB7, 0, 0, 0},
{0xB8, 0xB8, 0x17, 0x80, 0},
{0xB9, 0xB9, 0x17, 0, 0},
{0xBA, 0xBA, 0x17, 0x80, 0},
{0xBB, 0xBB, 0x17, 0, 0},
{0xBC, 0xBC, 7, 0, 0},
{0xBD, 0xBD, 7, 0x80, 0},
{0xBE, 0xBE, 7, 0x80, 0},
{0xBF, 0xBF, 6, 0x80, 0},
{0xC0, 0xC0, 7, 0, 0},
{0xC1, 0xC1, 6, 0, 0},
{0xC2, 0xC2, 0, 0x80, 0},
{0xC3, 0xC3, 0, 0x80, 0},
{0xC4, 0xC4, 1, 0x80, 0},
{0xC5, 0xC5, 1, 0x80, 0},
{0xC6, 0xC6, 4, 0x80, 0},
{0xC7, 0xC7, 4, 0x80, 0},
{0xC8, 0xC8, 5, 0x80, 0},
{0xC9, 0xC9, 5, 0x80, 0},
{0xCA, 0xCA, 6, 0x80, 0},
{0xCB, 0xCB, 6, 0x80, 0},
{0xCC, 0xCC, 7, 0x80, 0},
{0xCD, 0xCD, 7, 0x80, 0},
{0xCE, 0xCE, 0x31, 0x80, 0},
{0xCF, 0xCF, 0x31, 0x80, 0},
{0xD0, 0xD0, 5, 0x80, 0},
{0xD1, 0xD1, 5, 0, 0},
{0xD2, 0xD2, 4, 0x80, 0},
{0xD3, 0xD3, 4, 0, 0},
{0xD4, 0xD4, 5, 0, 0},
{0xD5, 0xD5, 5, 0x80, 0},
{0xD6, 0xD6, 4, 0x80, 0},
{0xD7, 0xD7, 4, 0x80, 0},
{0xD8, 0xD8, 5, 0x80, 0},
{0xD9, 0xD9, 7, 0x80, 0},
{0xDA, 0xDA, 6, 0x80, 0},
{0xDB, 0xDB, 0x2F, 0, 0},
{0xDC, 0xDC, 0x22, 0, 0},
{0xDD, 0xDD, 0x22, 0, 0},
{0xDE, 0xDE, 0x22, 0, 0},
{0xDF, 0xDF, 0x22, 0, 0},
{0xE0, 0xE0, 5, 0x80, 0},
{0xE1, 0xE1, 5, 0, 0},
{0xE2, 0xE2, 4, 0x80, 0},
{0xE3, 0xE3, 0x20, 0, 0},
{0xE4, 0xE4, 0x2E, 0, 0},
{0xE5, 0xE5, 0x23, 0, 0},
{0xE6, 0xE6, 0x2E, 0, 0},
{0xE7, 0xE7, 0x20, 0, 0},
{0xE8, 0xE8, 0x20, 0, 0},
{0xE9, 0xE9, 6, 0, 0},
{0xEA, 0xEA, 0x32, 0, 0},
{0xEB, 0xEB, 0x32, 0, 0},
{0xEC, 0xEC, 0x32, 0, 0},
{0xED, 0xED, 0x32, 0, 0},
{0xEE, 0xEE, 0x32, 0x80, 0},
{0xEF, 0xEF, 0x32, 0, 0},
{0xF0, 0xF0, 6, 0, 0},
{0xF1, 0xF1, 6, 0, 0},
{0xF2, 0xF2, 0x20, 0, 0},
{0xF3, 0xF3, 0x20, 0x80, 0},
{0xF4, 0xF4, 0x20, 0x80, 0},
{0xF5, 0xF5, 0x23, 0x80, 0},
{0xF6, 0xF6, 0x23, 0x80, 0},
{0xF7, 0xF7, 0x23, 0x80, 0},
{0xF8, 0xF8, 0x23, 0x80, 0},
{0xF9, 0xF9, 0x23, 0, 0},
{0xFA, 0xFA, 0x23, 0, 0},
{0xFB, 0xFB, 0x23, 0x80, 0},
{0xFC, 0xFC, 0x30, 0, 0},
{0xFD, 0xFD, 0x30, 0x80, 0},
{0xFE, 0xFE, 0x30, 0, 0},
{0xFF, 0xFF, 0x30, 0, 0},
{0x100, 0x100, 0x30, 0x80, 0},
{0x101, 0x101, 0x30, 0, 0},
{0x102, 0x102, 0x33, 0, 0},
{0x103, 0x103, 0x33, 0x80, 0},
{0x104, 0x104, 0x33, 0, 0},
{0x105, 0x105, 0x33, 0, 0},
{0x106, 0x106, 0x33, 0x80, 0},
{0x107, 0x107, 0x31, 0x80, 0},
{0x108, 0x108, 0x31, 0, 0},
{0x109, 0x109, 0x31, 0x80, 0},
{0x10A, 0x10A, 0, 0x80, 0},
{0x10B, 0x10B, 0, 0x80, 0},
{0x10C, 0x10C, 0, 0, 0},
{0x10D, 0x10D, 0, 0, 0},
{0x10E, 0x10E, 6, 0, 0},
{0x10F, 0x10F, 6, 0, 0},
{0x110, 0x110, 6, 0, 0},
{0x111, 0x111, 6, 0, 0},
{0x112, 0x112, 6, 0, 0},
{0x113, 0x113, 0, 0x80, 0},
{0x114, 0x114, 4, 0, 0},
{0x115, 0x115, 5, 0, 0},
{0x116, 0x116, 3, 0, 0},
{0x117, 0x117, 7, 0, 0},
{0x118, 0x118, 7, 0x80, 0},
{0x119, 0x119, 7, 0x80, 0},
{0x11A, 0x11A, 7, 0x80, 0},
{0x11B, 0x11B, 0x31, 0x80, 0},
{0x11C, 0x11C, 0x31, 0x80, 0},
{0x11D, 0x11D, 0x31, 0, 0},
{0x11E, 0x11E, 0x31, 0, 0},
{0x11F, 0x11F, 0x31, 0, 0},
{0x120, 0x120, 0x31, 0, 0},
{0x121, 0x121, 0x31, 0x80, 0},
{0x122, 0x122, 0x31, 0, 0},
{0x123, 0x123, 0x31, 0, 0},
{0x124, 0x124, 0x31, 0, 0},
{0x125, 0x125, 0x31, 0x80, 0},
{0x126, 0x126, 0x31, 0, 0},
{0x127, 0x127, 0x31, 0x80, 0},
{0x128, 0x128, 0x31, 0, 0},
{0x129, 0x129, 0x31, 0, 0},
{0x12A, 0x12A, 0x31, 0, 0},
{0x12B, 0x12B, 0x31, 0, 0},
{0x12C, 0x12C, 0x31, 0, 0},
{0x12D, 0x12D, 0, 0, 0},
{0x12E, 0x12E, 0x31, 0, 0},
{0x12F, 0x12F, 0, 0, 0},
{0x130, 0x130, 0, 0x80, 0},
{0x131, 0x131, 0x34, 0x80, 0},
{0x132, 0x132, 0x34, 0x80, 0},
{0x133, 0x133, 0x34, 0, 0},
{0x134, 0x134, 0x34, 0x80, 0},
{0x135, 0x135, 0x34, 0, 0},
{0x136, 0x136, 0x35, 0, 0},
{0x137, 0x137, 0, 0x80, 0},
{0x138, 0x138, 0x36, 0x80, 0},
{0x139, 0x139, 0x36, 0, 0},
{0x13A, 0x13A, 0, 0, 0},
{0x13B, 0x13B, 0x35, 0x80, 0},
{0x13C, 0x13C, 0x31, 0x80, 0},
{0x13D, 0x13D, 6, 0x80, 0},
{0x13E, 0x13E, 7, 0x80, 0},
{0x13F, 0x13F, 4, 0x80, 0},
{0x140, 0x140, 4, 0x80, 0},
{0x141, 0x141, 4, 0, 0},
{0x142, 0x142, 4, 0x80, 0},
{0x143, 0x143, 4, 0, 0},
{0x144, 0x144, 4, 0, 0},
{0x145, 0x145, 4, 0, 0},
{0x146, 0x146, 4, 0, 0},
{0x147, 0x147, 4, 0, 0},
{0x148, 0x148, 4, 0x80, 0},
{0x149, 0x149, 4, 0, 0},
{0x14A, 0x14A, 4, 0, 0},
{0x14B, 0x14B, 5, 0, 0},
{0x14C, 0x14C, 5, 0, 0},
{0x14D, 0x14D, 5, 0x80, 0},
{0x14E, 0x14E, 0, 0, 0},
{0x14F, 0x14F, 0, 0, 0},
{0x150, 0x150, 0, 0, 0},
{0x151, 0x151, 0, 0, 0},
{0x152, 0x152, 0, 0x80, 0},
{0x153, 0x153, 0x17, 0, 0},
{0x154, 0x154, 0x17, 0x80, 0},
{0x155, 0x155, 0x37, 0, 0},
{0x156, 0x156, 0x37, 0, 0},
{0x157, 0x157, 0x37, 0x80, 0},
{0x158, 0x158, 0x37, 0, 0},
{0x159, 0x159, 0x37, 0x80, 0},
{0x15A, 0x15A, 0x35, 0, 0},
{0x15B, 0x15B, 0x35, 0, 0},
{0x15C, 0x15C, 5, 0, 0},
{0x15D, 0x15D, 5, 0, 0},
{0x15E, 0x15E, 5, 0, 0},
{0x15F, 0x15F, 5, 0x80, 0},
{0x160, 0x160, 5, 0, 0},
{0x161, 0x161, 5, 0, 0},
{0x162, 0x162, 5, 0, 0},
{0x163, 0x163, 5, 0x80, 0},
{0x164, 0x164, 5, 0, 0},
{0x165, 0x165, 5, 0x80, 0},
{0x166, 0x166, 0x21, 0, 0},
{0x167, 0x167, 0x21, 0, 0},
{0x168, 0x168, 0x21, 0x80, 0},
{0x169, 0x169, 0x21, 0x80, 0},
{0x16A, 0x16A, 0x38, 0, 0},
{0x16B, 0x16B, 0x38, 0x80, 0},
{0x16C, 0x16C, 0x38, 0, 0},
{0x16D, 0x16D, 0x31, 0, 0},
{0x16E, 0x16E, 6, 0, 0},
{0x16F, 0x16F, 4, 0, 0},
{0x170, 0x170, 7, 0, 0},
{0x171, 0x171, 7, 0, 0},
{0x172, 0x172, 6, 0, 0},
{0x173, 0x173, 4, 0, 0},
{0x174, 0x174, 4, 0, 0},
{0x175, 0x175, 4, 0x80, 0},
{0x176, 0x176, 4, 0x80, 0},
{0x177, 0x177, 4, 0, 0},
{0x178, 0x178, 0x1B, 0x80, 0},
{0x179, 0x179, 0x1B, 0, 0},
{0x17A, 0x17A, 7, 0x80, 0},
{0x17B, 0x17B, 0x30, 0x80, 0},
{0x17C, 0x17C, 1, 0x80, 0},
{0x17D, 0x17D, 1, 0x80, 0},
{0x17E, 0x17E, 1, 0, 0},
{0x17F, 0x17F, 1, 0x80, 0},
{0x180, 0x180, 0x39, 0x80, 0},
{0x181, 0x181, 0x39, 0x80, 0},
{0x182, 0x182, 0x39, 0x80, 0},
{0x183, 0x183, 0x39, 0x80, 0},
{0x184, 0x184, 0x39, 0x80, 0},
{0x185, 0x185, 0x39, 0, 0},
{0x186, 0x186, 0x39, 0x80, 0},
{0x187, 0x187, 0x39, 0x80, 0},
{0x188, 0x188, 0x39, 0x80, 0},
{0x189, 0x189, 0x39, 0, 0},
{0x18A, 0x18A, 0x39, 0x80, 0},
{0x18B, 0x18B, 0x39, 0, 0},
{0x18C, 0x18C, 0x39, 0, 0},
{0x18D, 0x18D, 0x39, 0, 0},
{0x18E, 0x18E, 0x39, 0x80, 0},
{0x18F, 0x18F, 0x39, 0, 0},
{0x190, 0x190, 0x39, 0, 0},
{0x191, 0x191, 0x39, 0, 0},
{0x192, 0x192, 0x39, 0, 0},
{0x193, 0x193, 0x39, 0, 0},
{0x194, 0x194, 0x34, 0x80, 0},
{0x195, 0x195, 0x34, 0, 0},
{0x196, 0x196, 0x34, 0x80, 0},
{0x197, 0x197, 0x34, 0, 0},
{0x198, 0x198, 0x34, 0x80, 0},
{0x199, 0x199, 0x31, 0, 0},
{0x19A, 0x19A, 1, 0, 0},
{0x19B, 0x19B, 0x34, 0, 0},
{0x19C, 0x19C, 0x24, 0, 0},
{0x19D, 0x19D, 0x1D, 0, 0},
{0x19E, 0x19E, 0x1D, 0, 0},
{0x19F, 0x19F, 1, 0x80, 0},
{0x1A0, 0x1A0, 0x3B, 0, 0},
{0x1A1, 0x1A1, 4, 0, 0},
{0x1A2, 0x1A2, 4, 0x80, 0},
{0x1A3, 0x1A3, 0x3C, 0, 0},
{0x1A4, 0x1A4, 0x21, 0, 0},
{0x1A5, 0x1A5, 4, 0, 0},
{0x1A6, 0x1A6, 0x31, 0, 0},
{0x1A7, 0x1A7, 0x31, 0, 0},
{0x1A8, 0x1A8, 6, 0, 0},
{0x1A9, 0x1A9, 8, 0, 0},
{0x136, 0x136, 0x3A, 0, 0},
{0x1AA, 0x1AA, 0, 0x80, 0},
{0x1AB, 0x1AB, 0x31, 0, 0},
{0x1AC, 0x1AC, 0x31, 0x80, 0},
{0x1AD, 0x1AD, 1, 0x80, 0},
{0x1AE, 0x1AE, 1, 0, 0},
{0x1AF, 0x1AF, 0x1B, 0, 0},
{0x1B0, 0x1B0, 0x1B, 0, 0},
{0x1B1, 0x1B1, 0x1B, 0, 0},
{0x1B2, 0x1B2, 0x1B, 0, 0},
{0x1B3, 0x1B3, 0x1B, 0x80, 0},
{0x1B4, 0x1B4, 0x37, 0x80, 0},
{0x1B5, 0x1B5, 0x37, 0, 0},
{0x1B6, 0x1B6, 0x38, 0, 0},
{0x1B7, 0x1B7, 0x38, 0x80, 0},
{0x1B8, 0x1B8, 0x21, 0x80, 0},
{0x1B9, 0x1B9, 0x1D, 0, 0},
{0x1BA, 0x1BA, 0x34, 0, 0},
{0x1BB, 0x1BB, 0x34, 0x80, 0},
{0x1BC, 0x1BC, 0x1D, 0, 0},
{0x1BD, 0x1BD, 7, 0x80, 0},
{0x1BE, 0x1BE, 6, 0x80, 0},
{0x1BF, 0x1BF, 0, 0x80, 0},
{0x1C0, 0x1C0, 0, 0x80, 0},
{0x1C1, 0x1C1, 0x20, 0, 0},
{0x1C2, 0x1C2, 0x3D, 0, 0},
{0x1C3, 0x1C3, 0x3D, 0, 0},
{0x1C4, 0x1C4, 0, 0, 0},
{0x1C5, 0x1C5, 0x1B, 0, 0},
{0x1C6, 0x1C6, 0x31, 0x80, 0},
{0x1C7, 0x1C7, 6, 0x80, 0},
{0x1C8, 0x1C8, 4, 0x80, 0},
{0x1C9, 0x1C9, 0x1D, 0x80, 0},
{0x1CA, 0x1CA, 0x3E, 0, 0},
{0x1CB, 0x1CB, 6, 0, 0},
{0x1CC, 0x1CC, 7, 0, 0},
{0x1CD, 0x1CD, 5, 0, 0},
{0x1CE, 0x1CE, 0x31, 0, 0},
{0x1CF, 0x1CF, 3, 0x80, 0},
{0x1D0, 0x1D0, 0x3A, 0x80, 0},
{0x1D1, 0x1D1, 1, 0x80, 0},
{0x1D2, 0x1D2, 1, 0x80, 0},
{0x1D3, 0x1D3, 1, 0x80, 0},
{0x1D4, 0x1D4, 0, 0x80, 0},
{0x1D5, 0x1D5, 0, 0x80, 0},
{0x1D6, 0x1D6, 0, 0x80, 0},
{0x1D7, 0x1D7, 3, 0, 0},
{0x1D8, 0x1D8, 7, 0, 0},
{0x1D9, 0x1D9, 7, 0x80, 0},
{0x1DA, 0x1DA, 7, 0, 0},
{0x1DB, 0x1DB, 7, 0, 0},
{0x1DC, 0x1DC, 7, 0, 0},
{0x1DD, 0x1DD, 0, 0, 0},
};

extern u8 gUnk_0838EEF4[];

#define CUTSCENE_ANIM_BASE  ((u8*)0x02020000)
void sub_80046DC(u16 arg0, u8 arg1, u8 arg2) {
        u8 a;
    u8 b;

    gUnk_030044C0[arg1] = gUnk_087E860C[gCutsceneAnimConfigTable[arg0].scriptIdx];
    gVramBufferPointers[arg1] = (u32)(CUTSCENE_ANIM_BASE + arg1 * 0x1000);

    if(arg2 > 99)
    {
        a = 0x40;
        b = arg2 - 100;
    }
    else
    {
        a = 0;
        b = arg2;
    }
    gUnk_03002C60[arg1] = a | gCutsceneAnimConfigTable[arg0].field_5;
    gUnk_03003490[arg1] = b;
    gUnk_030032E0[arg1] = &gUnk_0838EEF4[gCutsceneAnimConfigTable[arg0].palIdx * 32];
    LZ77UnCompWram((void*)gUnk_087E8D84[gCutsceneAnimConfigTable[arg0].gfxIdx], (void*)(CUTSCENE_ANIM_BASE + arg1 * 0x1000));
}

/*

typedef struct{
    u16 field_0;
    u16 field_2;
    u8 field_4;
    u8 field_5;
    u16 field_6;
}Unk_0805888C;

extern Unk_0805888C gUnk_0805888C[];
extern u32 gUnk_087E860C[];
extern u8 gUnk_0838EEF4[];

extern u8* gUnk_087E8D84[];

extern u32 gUnk_030044C0[];
extern u32 gUnk_03003250[];
extern u8 gUnk_03002C60[];
extern u8 gUnk_03003490[];
extern u8* gUnk_030032E0[];

#define VRAM_BASE  ((u8*)0x02020000)
#define VRAM_STRIDE 0x1000

void sub_80046DC(u16 arg0, u8 arg1, u8 arg2) {
    u8 a;
    u8 b;

    gUnk_030044C0[arg1] = gUnk_087E860C[gUnk_0805888C[arg0].field_0];
    gUnk_03003250[arg1] = (u32)(VRAM_BASE + arg1 * VRAM_STRIDE);

    if(arg2 > 99)
    {
        a = 0x40;
        b = arg2 - 100;
    }
    else
    {
        a = 0;
        b = arg2;
    }

    gUnk_03002C60[arg1] = a | gUnk_0805888C[arg0].field_5;
    gUnk_03003490[arg1] = b;

    gUnk_030032E0[arg1] = &gUnk_0838EEF4[gUnk_0805888C[arg0].field_4 * 32];
    LZ77UnCompWram(gUnk_087E8D84[gUnk_0805888C[arg0].field_2], (u32)(VRAM_BASE + arg1 * VRAM_STRIDE));

}


*/

INCLUDE_ASM("asm/nonmatchings", sub_800478C);


void sub_8004980(void) {
    u8 i;

    gUnk_03003480 = 0xFF;

    for(i = 0; i < 22; i++)
    {
        if(gUnk_087E94FC[i].field_0 == gUnk_030047B0)
        {
            gUnk_03004618 = i + 1;
            return;
        }
    }
    gUnk_03004618 = 0;

}

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

INCLUDE_ASM("asm/matchings", sub_8004A00);
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

void sub_8004B2C(u16 arg0, void *arg1, void *arg2, u8 arg3)
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
        gSpriteNodePool[i].flags = 0;
        gSpriteNodePool[i].next = 0;
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
        gSpriteRenderQueue[i] = 0;
    }
}

u8 sub_8004BFC(void)
{
    u16 i;

    for (i = 2; i < 0x70; i++)
    {
        if (gSpriteNodePool[i].flags == 0)
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
        if (gSpriteNodePool[i].flags == 0)
        {
            return i;
        }
    }
    return 0;
}

SpriteNode *sub_8004C28(SpriteNode *sprNode, u8 arg1, u16 arg2, u16 arg3, u16 arg4)
{
    u8 foundIndex;

    sprNode->flags = arg1;
    sprNode->attr0 = arg2;
    sprNode->attr1 = arg3;
    sprNode->attr2 = arg4;
    sprNode->animStep = 0;

    if ((arg1 & 0x7F) == 1)
        return 0;

    foundIndex = findEmpty_Inl();

    if (foundIndex == 0)
    {
        return 0;
    }

    sprNode->next = &gSpriteNodePool[foundIndex];
    return &gSpriteNodePool[foundIndex];
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
    struct SpriteNode *node;
    struct SpriteNode *next;

    ptr2E80 = &gUnk_03002E80[arg0];

    node = &gSpriteNodePool[ptr2E80->sprNodeIdx];

    if (node->flags != 0)
    {
        node->flags = 0;

        next = node->next;
        if (next != 0)
        {
            do
            {
                node->next = 0;
                node = next;
                if (node->flags == 0)
                    break;
                node->flags = 0;
                next = node->next;
            } while (next != 0);
        }
    }

    ptr2E80->sprNodeIdx = 0;
}
void sub_8004D8C(u8 arg0, u8 *arg1)
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
u8 sub_8004DD0(void)
{
    u8 i;
    CharacterObject *ptr2E80;
    ptr2E80 = gUnk_03002E80;

    for (i = 0; i < 0x18; i++)
    {
        if (ptr2E80->sprNodeIdx != 0 && ptr2E80->field_12 & 0x80)
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
void sub_8004F3C(struct SpriteNode *arg0)
{

    struct SpriteNode *node;
    struct SpriteNode *next;

    if (arg0->flags == 0)
        return;

    arg0->flags = 0;

    node = arg0->next;

    if (node == 0)
        return;

    do
    {
        arg0->next = 0;
        arg0 = node;
        if (node->flags == 0)
            break;
        node->flags = 0;
        node = arg0->next;
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
    ptr2E80->animIdx = arg1;
}
s32 sub_8004FD0(u8 arg0)
{
    CharacterObject *ptr;

    if (arg0 < 0x64)
    {
        ptr = &gUnk_03002E80[arg0];

        gUnk_03002C60[ptr->animIdx] &= 0x7F;

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


