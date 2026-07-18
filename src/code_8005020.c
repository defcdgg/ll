#include "code_0.h"
#include "gba/defines.h"
#include "gba/gba.h"
#include "gba/macro.h"
#include "globals.h"
#include "include_asm.h"
#include "iwram.h"
#include "m4a.h"
#include "save.h"
#include "sound.h"




INCLUDE_ASM("asm/nonmatchings", sub_8005020);
INCLUDE_ASM("asm/nonmatchings", sub_80051D0);

void sub_800526C(void)
{
    REG_BLDCNT = gBlendControl;
    if (gBlendControl & 0x80)
    {
        REG_BLDY = gUnk_03004550;
    }
    else
    {
        REG_BLDALPHA = gUnk_03004550;
    }

    if (gUnk_0300465C != 0)
    {
        if (!(gUnk_0300465C & 0x80))
            gUnk_030047A8 += gUnk_030047F0;

        if (gUnk_030047F0 < 0)
        {
            if (gUnk_030047A8 <= 0)
                gUnk_0300465C = 0;
        }
        else
        {
            if (gUnk_030047A8 > 0x1B0)
                gUnk_0300465C |= 0x80;
        }
    }
}
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
u16 sub_8005BB4(u16 *tiles, u16 x, u16 y)
{
    u16 *src;
    u16 ret;
    u16 xSubtile;
    u16 ySubtile;
    u16 val;

    src = tiles;

    ret = 0;

    xSubtile = x & 7;
    ySubtile = y & 7;

    val = *src & 0x3FF;
    src++;
    if (val <= gUnk_030047AC)
    {
        ret |= 4;
    }

    val = *src & 0x3FF;
    src++;
    if (val <= gUnk_030047AC)
    {
        ret |= 2;
    }

    if (xSubtile != 0)
    {
        val = *src & 0x3FF;
        ret |= 0x100;

        if (val <= gUnk_030047AC)
        {
            ret |= 1;
        }
    }

    if (ySubtile != 0)
    {
        ret |= 0x200;
        src += 0x1E;

        val = *src & 0x3FF;
        src++;
        if (val <= gUnk_030047AC)
        {
            ret |= 0x40;
        }

        val = *src & 0x3FF;
        src++;
        if (val <= gUnk_030047AC)
        {
            ret |= 0x20;
        }

        if (xSubtile != 0)
        {
            val = *src & 0x3FF;
            if (val <= gUnk_030047AC)
            {
                ret |= 0x10;
            }
        }
    }

    return ret;
}
INCLUDE_ASM("asm/nonmatchings", sub_8005C70);

void sub_80064AC(u16 arg0)
{
    u16 x;
    u16 y;
    u16 *dst = (u16 *)0x02005000;

    switch (arg0)
    {
        case 0:
            for (y = 0; y < 32; y++)
            {
                for (x = 0; x < 32; x++)
                {
                    *dst++ = 0xA000 + ((y & 3) << 2) + (x & 3);
                }
            }
            break;

        case 1:
            for (y = 0; y < 32; y++)
            {
                for (x = 0; x < 32; x++)
                {
                    *dst++ = 0xA000;
                }
            }
            break;
    }
}
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

//     gUnk_03004670[0] = gPartyMemberIds[0];
//     gUnk_030047D0[0] = gPartyMemberIds[0];
//     sub_8004C8C(0, gPartyMemberIds[0]);
//     sub_8004CB8(0, gPartyMemberIds[0]);
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
u8 *sub_8007964(u16 arg0, u8 *arg1)
{
    u32 temp_r0;

    Unk_030046A0 *ptr46A0;

    ptr46A0 = &gUnk_030046A0[arg0];

    ptr46A0->field_0 = (arg1[0] & 1) + 1;
    ptr46A0->field_3 = arg1[1];
    arg1 += 2;

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

    ptr46A0->field_A = 0;
    ptr46A0->field_C = arg1;

    temp_r0 = ptr46A0->field_8 * ptr46A0->field_9 * ptr46A0->field_1;
    temp_r0 *= 2;

    arg1 += temp_r0;

    return arg1;
}
u8 *sub_80079BC(u16 arg0, u8 *arg1)
{
    u32 temp_r0;

    Unk_030046A0 *ptr46A0;

    ptr46A0 = &gUnk_030046A0[arg0];

    ptr46A0->field_0 = (arg1[0] & 1) + 1;
    ptr46A0->field_3 = arg1[1];
    arg1 += 2;

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

    gBlendControl = 0x1E41;
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
    gHBlankEffectMode = 1;
    REG_BG1CNT = 0x1E0F;
    REG_DISPCNT |= 0x200;
    sub_8000C98(1);
    sub_8007FB8(arg0);
    gUnk_0300469C = gUnk_030047E0;
}
*/
INCLUDE_ASM("asm/matchings", sub_8007FB8);
INCLUDE_ASM("asm/nonmatchings", sub_8008124);
void sub_80081C0(void)
{

    if (gUnk_0300000A[1] != 0)
    {
        sub_800243C(0xb0, 0x18, gUnk_0300000A[1], 0, 1);
        sub_800243C(0xD0, 0x30, gUnk_0300000A[0], 0, 1);
        return;
    }

    if (gUnk_0300000A[0] != 0)
    {
        if (gUnk_03000008 == 0)
        {
            gUnk_0300000C++;
            if (gUnk_0300000C == 0xC0)
            {
                gUnk_03000008 = 1;
            }
        }
        else
        {
            gUnk_0300000C--;
            if (gUnk_0300000C == 0)
            {
                gUnk_03000008 = 0;
            }
        }

        sub_800243C(0x68, 0x30, gUnk_0300000A[0], (gUnk_0300000C >> 6) + 0x10, 1);
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8008254);
INCLUDE_ASM("asm/nonmatchings", sub_8008620);

void sub_80086FC(void)
{
    if (gUnk_03004800[0] & 1)
        gUnk_03004800[1] = sub_8000FF8() & gUnk_03004800[4];

    if (gUnk_03004800[0] & 2)
        gUnk_03004800[2] = sub_8000FF8() & gUnk_03004800[4];

    if (gUnk_03004800[0] & 4)
    {
        gUnk_03004800[3]++;
        if (gUnk_03004800[3] > 0xF)
            gUnk_03004800[3] = 0;

        gBlendControl = 0x1C42;
        gUnk_03004550 = 0x0F00 | gUnk_03004800[3];
        REG_DISPCNT |= DISPCNT_BG1_ON;
    }
}

INCLUDE_ASM("asm/matchings", sub_8008788);
/*
extern u8* gUnk_087E9828[];
extern u8* gUnk_087E98C0[];

extern u8 gUnk_08086C1C[][0x40];

void sub_8008788(u8 arg0)
{
    gUnk_030047C8 = 0;
    gUnk_03004660 = 0;
    gUnk_0300259C = 6;
    gUnk_0300467C = 0xFD;

    sub_8003208();
    VBlankIntrWait();
    sub_80533F0();

    LZ77UnCompWram(gUnk_087E9828[arg0 * 2], (void *)0x02020000);
    gUnk_03004660 = 0;
    gUnk_030047C8 = 1;
    VBlankIntrWait();
    sub_80533F0();

    if (gUnk_087E9828[arg0 * 2 + 1] != 0) {
        LZ77UnCompWram(gUnk_087E9828[arg0 * 2 + 1], (void *)0x02020000);
        gUnk_03004660 = 1;
        gUnk_030047C8 = 1;
        VBlankIntrWait();
        sub_80533F0();
    }

    DmaCopy32(3, gUnk_08086C1C[arg0], PLTT, 0x20);

    // DmaCopy32(3, (void *)(0x08086C1C + arg0 * 0x40), PLTT, 0x20);
    DmaCopy16(3, (void *)0x08087216, PLTT, 2);
    sub_8000F94();

    LZ77UnCompWram(gUnk_087E98C0[arg0], (void *)0x02020000);
    gUnk_03004660 = 0;
    gUnk_030047C8 = 2;
    VBlankIntrWait();
    sub_80533F0();
    sub_8000F94();

    REG_DISPCNT = 0x1960;
    REG_BG1CNT = 0;
    REG_BG2CNT = 0;
    REG_BG3CNT = 0x3C03;
}

*/

void sub_80088B4(u16 arg0, s16 arg1, s16 arg2)
{
    gUnk_03004834 = arg2;
    gUnk_030047F0 = arg1;

    if (arg1 < 0)
    {
        gUnk_030047A8 = 0x1B0;
    }
    else
    {
        gUnk_030047A8 = 0;
    }

    gUnk_0300465C = arg0;
}

void sub_80088F4(void)
{
    if ((u32) * (u16 *)0x0300467C <= 0xFCU)
    {
        *(s32 *)0x03004620 = 0x02006000;
        *(s32 *)0x0300482C = 0x02001000;
        *(s32 *)0x03004690 = 0x02001800;
        *(s32 *)0x030047E8 = 0x02001C00;
        sub_80052F8();
        *(s32 *)0x03004620 = 0x0200E000;
        *(s32 *)0x0300482C = 0x02003000;
        *(s32 *)0x03004690 = 0x02003800;
        *(s32 *)0x030047E8 = 0x02003C00;
        sub_80052F8();
    }
}

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
INCLUDE_ASM("asm/matchings", sub_8008B14);
/*
typedef struct{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
}Unk_08089BC4;
extern Unk_08089BC4 gUnk_08089BC4[];

extern u16 gUnk_03004650; // 0x03004650
extern u16 gUnk_0300464C; // 0x0300464C
extern u16 gUnk_030047C4; // 0x030047C4
extern u16 gUnk_030047EC; // 0x030047EC

void sub_8008B14(u16 arg0) {

    gUnk_03004650 = gUnk_08089BC4[arg0].field_0 << 6;

    gUnk_0300464C = gUnk_08089BC4[arg0].field_1 << 6;

    gUnk_030047C4 = gUnk_03004650 + (gUnk_08089BC4[arg0].field_2 << 6);

    gUnk_030047EC = gUnk_0300464C + (gUnk_08089BC4[arg0].field_3 << 6);
}


*/
void sub_8008B5C(void)
{
    // gUnk_03004670.field_0 = gPartyMemberIds[0];
    gUnk_03004670[0] = gPartyMemberIds[0];
    gUnk_030047D0[0] = gPartyMemberIds[0];

    sub_8004C8C(0, gPartyMemberIds[0]);
    sub_8004CB8(0, gPartyMemberIds[0]);
    // gUnk_03004670.field_1 = 11;
    gUnk_03004670[1] = 11;
    gUnk_030047D0[1] = 11;
    sub_8004C8C(1, 0xBU);
    sub_8004CB8(1, 0xBU);
}
INCLUDE_ASM("asm/matchings", sub_8008BA4);
/*
extern u8* gUnk_087EA1A0[];

void sub_8008BA4(u8 arg0, u8 arg1) {
    u16 count;
    u16 end_limit;
    u8* src;
    u16 i;

    src = gUnk_087EA1A0[arg0];
    count = *(u16*)src;

    end_limit = count + arg1;
    src = src + 2;
    i = arg1;

    while(i < end_limit)
    {
        src = sub_8007964(i, src);
        i++;
    }
}

*/

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

void sub_8008C24(u8 arg0)
{

    if (!(gUnk_0300467C & 0x80))
    {
        if (gUnk_03004670[arg0] != 0xFF)
        {
            sub_8004C8C(arg0, gUnk_03004670[arg0]);
        }

        if (gUnk_030047D0[arg0] != 0xFF)
        {
            sub_8004CB8(arg0, gUnk_030047D0[arg0]);
        }
    }
}

void sub_8008C70(void)
{
    u8 i;

    for (i = 0; i < 12; i++)
    {
        if (!(gUnk_0300467C & 0x80))
        {
            if (gUnk_03004670[i] != 0xFF)
            {
                sub_8004C8C(i, gUnk_03004670[i]);
            }
            if (gUnk_030047D0[i] != 0xFF)
            {
                sub_8004CB8(i, gUnk_030047D0[i]);
            }
        }
    }
}

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

void sub_8008D18(void)
{
    u32 i;
    u16 *dest;

    if (gUnk_0300483C != 0)
    {

        LZ77UnCompVram(gUnk_030047CC, (void *)(((gUnk_0300483C - 1) >> 1) * 0x800 + 0x0600D000));

        i = (gUnk_0300483C - 1) >> 1;

        dest = (u16 *)(i * 0x20 + 0x050001C0);
        DmaCopy16(3, gUnk_03004694, dest, 0x20);

        // (void* )0x040000D4->unk0 = (s32) gUnk_03004694;
        // (void* )0x040000D4->unk4 = (s32) ((((s32) (gUnk_0300483C - 1) >> 1) << 5) + 0x050001C0);
        // (void* )0x040000D4->unk8 = 0x80000010;
        gUnk_0300483C = 0;
    }
}

u16 sub_8008D78(void)
{
    switch (gUnk_0300460C)
    {
        case 2:
            return gUnk_03004684 >> 4;

        case 4:
            return gUnk_03004684 - 0x20;

        case 7:
            return gUnk_03004684 - gUnk_030025FC;

        default:
            return 0;
    }
}

void sub_8008DCC(u8 arg0)
{
    gUnk_03004850 = arg0;
}

void sub_8008DD8(void)
{
    DmaCopy16(3, (void *)0x08087216, (void *)0x05000000, 2);
}

void sub_8008DF8(u16 arg0, u8 *arg1)
{
    u16 count;

    count = *(u16 *)arg1;
    arg1 += 2;

    while (count != 0)
    {
        arg1 = sub_80079BC(arg0, arg1);

        sub_8007A1C(arg0);

        gUnk_030046A0[arg0].field_0 = 0;
        count--;
    }
}
void sub_8008E44(u8 arg0)
{
    u16 *dest;
    u16 i, j;
    u16 val;

    dest = (u16 *)0x020053A8;

    val = 32;

    if (arg0 != 0)
    {
        val = 0;
    }

    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 8; j++)
        {
            *dest = val + 0xA200;
            dest++;
            val++;
        }
        dest += 24;
    }
    gUnk_03004800[13] = 1;
}

void sub_8008E94(void)
{
    switch (gUnk_030047C8)
    {
        case 1:
            switch (gUnk_03004660)
            {
                case 0:
                    DmaCopy32(3, (void *)0x02020000, (void *)0x06000000, 0xc00);
                    break;

                case 1:
                    DmaCopy32(3, (void *)0x02020000, (void *)0x06000C00, 0xc0);
                    break;
            }
            gUnk_030047C8 = 0;
            break;

        case 2:
            DmaCopy32(3, (void *)0x02020000, (void *)0x0600E000, 0x800);
            gUnk_030047C8 = 0;
            break;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8008F28);
void sub_8008FD0(u8 arg0)
{
    struct SpriteNode *sprNode;
    struct SpriteNode *sprSubNode;
    u8 objIdx;
    u16 chestColor;
    u16 attr0;
    u16 attr1;
    u16 attr2;

    objIdx = sub_8004BFC();
    gChestObjects[arg0].sprNodeIdx = objIdx;
    sprNode = &gSpriteNodePool[objIdx];

    chestColor = 0x80 & gChestObjects[arg0].field_0 ? 0xF : 0xE;

    if ((0x7F & gChestObjects[arg0].field_0) == 0)
    {

        attr0 = 0;
        attr1 = 0x4000;
        attr2 = ((chestColor << 12) | 0x896);

        sprNode->tileOffsetX = 0;
        sprNode->tileOffsetY = 0xF0;

        sub_8004C28(sprNode, 1, attr0, attr1, attr2);
    }
    else
    {
        attr0 = 0;
        attr1 = 0x4000;
        attr2 = ((chestColor << 12) + 0x89C);
        sprNode->tileOffsetX = 0;
        sprNode->tileOffsetY = 0xF0;
        sprSubNode = sub_8004C28(sprNode, 2, attr0, attr1, attr2);

        attr0 = 0x4000;
        attr1 = 0;
        attr2 = ((chestColor << 12) | 0x89A);
        sprSubNode->tileOffsetX = 0;
        sprSubNode->tileOffsetY = 0xE8;
        sub_8004C28(sprSubNode, 1, attr0, attr1, attr2);
    }
    sprNode->animStep = 0;
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

    sub_8004F3C(&gSpriteNodePool[gChestObjects[arg0].sprNodeIdx]);
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

INCLUDE_ASM("asm/matchings", sub_8009428);
/*
extern u8 gUnk_03004914;
extern u8 gUnk_03004918;

void sub_8009428(u8 arg0)
{
    u16 i;
    u16 fill;
    u16 *dst;

    gUnk_03004914 = 0;
    gUnk_03004910 = arg0 + 1;
    gUnk_03004918 = 0;

    switch (gUnk_03004910) {
        case 1:
        case 7:
            fill =  0x7FFF;
            REG_WIN0H = 0xF0FF;
            REG_WIN0V = 0x00A0;
            REG_DISPCNT |= DISPCNT_WIN0_ON;
            REG_WININ = 0;
            REG_WINOUT = 0;
        case 3:
            if (gUnk_03004910 == 3)
                fill = 0;

            i = 0x200;
            dst = (u16*)0x0203E600;
            while(i > 0)
            {
                *dst++ = fill;
                i--;
            }


            DmaCopy16(3, (void *)0x0203E600, PLTT, PLTT_SIZE);
            break;

        case 5:
            sub_8009B44();
            DmaCopy16(3, (void *)0x0203EA00, (void *)0x0203E600, PLTT_SIZE);
            break;

        default:
            DmaCopy16(3, (void *)0x0203EA00, (void *)0x0203E600, PLTT_SIZE);
            break;
    }
}
*/

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
INCLUDE_ASM("asm/matchings", sub_8009A7C);
/*
extern u8 *gUnk_087EA138[];

void sub_8009A7C(u8 arg0)
{
    u8 count;
    s16 i;
    u8 *src;

    if (arg0 == 0)
        return;

    src = gUnk_087EA138[arg0 - 1];
    count = *src++;

    i = 0;
    while(count != 0)
    {
        src = sub_8009B84(i, src);

        count--;
        i++;
    }
}
*/
INCLUDE_ASM("asm/matchings", sub_8009AC4);
/*
extern u8 *gUnk_087EA138[];

void sub_8009AC4(u8 arg0, u8 arg1)
{
    u8 end;
    u8 cur;
    u8 *src = gUnk_087EA138[arg1];

    end = arg0 + *src++;
    cur = arg0;
    while (cur < end) {
        src = sub_8009B84(cur, src);
        cur++;
    }
}
*/
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
/*
extern u8 gUnk_0808EA0C[][8];
extern u8 gUnk_0300496C[];
extern u8 gUnk_03004970[];

extern u8* gUnk_087EA33C[];

extern u16 gUnk_080BABA0[][16];

void sub_8009BF0(u8 arg0) {
    u8* var_r4;
    u8 var_r5;

    if (arg0 != 0) {
        arg0--;
        var_r4 = &gUnk_0808EA0C[arg0][0];

        for(var_r5 = 0; var_r5 < 2; var_r5++)
        {
            if(var_r4[0] != 0xFF)
            {
                gUnk_0300496C[var_r5] = var_r4[2];
                gUnk_03004970[var_r5] = var_r4[3];
                LZ77UnCompVram(gUnk_087EA33C[var_r4[0]], (u16*)0x06010000 + (var_r4[2] << 4));

                DmaCopy16(3, (u16*) gUnk_080BABA0[var_r4[1]], (u16*)0x05000380 + (var_r5 << 4), 0x20);

            }
            var_r4+=4;
        }
    }
}

*/
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
    PlayerStats *ptr;

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

void sub_800A79C(u8 arg0)
{
    PlayerStats *chara;

    if (arg0 != 0)
        arg0--;
    chara = &gUnk_03004AC0[arg0];

    chara->equip_atc = gUnk_03004A90;
    chara->equip_def = gUnk_03004AA8;
    chara->equip_agl = gUnk_03004AB0;
    chara->equip_men = gUnk_03004A98;
    chara->equip_res = gUnk_03004A94;
    chara->equip_noa = gUnk_03004AB4;
    chara->equip_luc = gUnk_03004AB8;

    chara->equip_atc += gUnk_03004AAC;
    chara->equip_def += gUnk_03004A80;

    chara->atc = chara->base_atc + chara->equip_atc;
    chara->def = chara->base_def + chara->equip_def;
    chara->agl = chara->base_agl + chara->equip_agl;
    chara->men = chara->base_men + chara->equip_men;
    chara->res = chara->base_res + chara->equip_res;
    chara->noa = chara->base_noa + chara->equip_noa;
    chara->luc = chara->base_luc + chara->equip_luc;
}
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
/*
extern u32 gUnk_08092248[];
u32 sub_800A8A0(u8 arg0) {
    u8 i;
    u32 sum = 0;

    for ( i = 0; i <= arg0; i++)
    {
        sum += gUnk_08092248[i];
    }
    return sum;

}
*/

INCLUDE_ASM("asm/matchings", sub_800A8D0);

/*
extern u8 gUnk_08093418[];

u8 sub_800A8D0(u8 arg0, u8 arg1)
{
    u8 i;
    u8 adjusted = arg0 + 1;

    if (arg1 <= 1)
        arg1 = 0;

    for (i = 0; i <= 0x2F; i++)
    {
        if ( arg1 == (gUnk_08093418[i* 5 + 1] >> 4) )
            if( (gUnk_08093418[i * 5] ) == adjusted)
                return i + 1;
    }

    return 0xFF;
}
*/

void sub_800A924(void)
{
    u8 i;

    for (i = 1; i < 11; i++)
    {
        sub_800A1B4(i);
    }

    for (i = 1; i < 255; i++)
    {
        gInventory[i] = 0;
    }
}
INCLUDE_ASM("asm/matchings", sub_800A958);
// extern u8 gUnk_08093418[];

// u8 sub_800A958(u8 arg0) {
//     return gUnk_08093418[(arg0 - 1) * 5 + 4];
// }
INCLUDE_ASM("asm/matchings", sub_800A970);
/*
void sub_800A970(void* arg0) {
    *((u16*)arg0+1) = *((u16*)arg0 + 9);
}

*/
INCLUDE_ASM("asm/matchings", sub_800A978);
/*
void sub_800A978(void* arg0) {
    *((u16*)arg0+2) = *((u16*)arg0 + 10);
}
*/

//FullHealParty
void sub_800A980(void)
{
    u8 i;
    u8 charaId;
    PlayerStats *ptr;

    for (i = 0; i < 6; i++)
    {
        charaId = gPartyMemberIds[i];
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

    PlayerStats* chara;

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
        if (gInventory[oldEquip] < 99)
        {
            AddInventoryItem(oldEquip, 1);
        }
    }

    sub_800A664(arg0);
    sub_800A79C(arg0);
}
*/

//sub_800AA60
void AddInventoryItem(u8 itemId, u8 count)
{
    s32 totalCount;

    totalCount = gInventory[itemId] + count;
    if (totalCount > 99)
    {
        gInventory[itemId] = 99;
    }
    else
    {
        gInventory[itemId] = totalCount;
    }
}

//sub_800AA84
void RemoveInventoryItem(u8 itemId, u8 count)
{
    s32 totalCount;

    totalCount = gInventory[itemId] - count;
    if (totalCount < 0)
    {
        gInventory[itemId] = 0;
    }
    else
    {
        gInventory[itemId] = totalCount;
    }
}

void sub_800AAA4(s32 arg0)
{
    gSilverAmount += arg0;

    if (gSilverAmount > 999999)
    {
        gSilverAmount = 999999;
    }
}
void sub_800AAC0(s32 arg0)
{
    gSilverAmount -= arg0;

    if (gSilverAmount > 999999)
    {
        gSilverAmount = 0;
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
    PlayerStats *ptr;

    for (i = 0; i < 5; i++)
    {
        charaId = gPartyMemberIds[i];
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
void sub_800AB7C(u8 arg0)
{
    PlayerStats *actor;
    if (arg0 <= 1)
    {
        actor = &gUnk_03004AC0[0];
        sub_800A048(actor->skills, actor->lv, arg0);

        if (actor->field_unk[2] == 1 && (u8)(actor->field_unk[3] - 5) <= 3)
        {
            actor->field_unk[2] = 0;
            actor->field_unk[3] = 0;
        }
    }
}
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


//FullHealCharacter
void sub_800ACA4(u8 arg0)
{
    PlayerStats *ptr;

    if (arg0 != 0)
    {
        arg0--;
    }

    ptr = &gUnk_03004AC0[arg0];
    ptr->hp = ptr->max_hp;
    ptr->mp = ptr->max_mp;
}

INCLUDE_ASM("asm/nonmatchings", sub_800ACC8);

INCLUDE_ASM("asm/matchings", sub_800B14C);
/*
void sub_800B14C(void)
{
    if (gUnk_03004D4C != 0) {
        if ((u8)(gUnk_03004D4C - 7) <= 4) {
            sub_8016068();
            return;
        }
        if (gUnk_03004D4C == 12) {
            sub_80160F4();
            sub_800B2D0();
            return;
        }
        if ((u8)(gUnk_03004D4C - 0x35) <= 7) {
            sub_8008C24(gUnk_03004D4C + 0xCD);
            return;
        }

        DmaCopy16(3, (void *)0x02005800, (void *)0x0600F800, 0x800);
        switch (gUnk_03004D4C) {
            case 2:
                LZ77UnCompVram((void *)0x08095A1C, (void *)0x0600D000);
                break;
            case 3:
                LZ77UnCompVram((void *)0x08095C94, (void *)0x0600D400);
                break;
            case 4:
                LZ77UnCompVram((void *)0x08095F14, (void *)0x0600D800);
                break;
            case 5:
                LZ77UnCompVram((void *)0x0809619C, (void *)0x0600DC00);
                break;
        }
        return;
    }

    if (gUnk_03004D40 != 0) {
        if ((u8)(gUnk_03004D40 - 3) <= 4) {
            sub_8016068();
        } else if (gUnk_03004D40 == 2) {
            sub_80160F4();
            sub_800B2D0();
        } else if ((u8)(gUnk_03004D40 + 0xF) <= 7) {
            sub_8008C24(gUnk_03004D40 + 0x11);
        } else {
            DmaCopy16(3, (void *)0x02005800, (void *)0x0600F800, 0x800);
            switch (gUnk_03004D40) {
                case 0x1F:
                    LZ77UnCompVram((void *)0x08095A1C, (void *)0x0600D000);
                    break;
                case 0x20:
                    LZ77UnCompVram((void *)0x08095C94, (void *)0x0600D400);
                    break;
                case 0x21:
                    LZ77UnCompVram((void *)0x08095F14, (void *)0x0600D800);
                    break;
                case 0x22:
                    LZ77UnCompVram((void *)0x0809619C, (void *)0x0600DC00);
                    break;
            }
        }
        return;
    }

    if (gUnk_0300467C != 0xFF) {
        DmaCopy16(3, (void *)0x02004000, (void *)0x0600E000, 0x800);
        if (gUnk_0300467C != 0xFE)
            DmaCopy16(3, (void *)0x02004800, (void *)0x0600E800, 0x800);
    }
}
*/
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
void sub_800B314(void)
{
    u8 i;

    if (gUnk_03000185 == 0)
        return;

    if (gUnk_03000184 == 4)
    {
        sub_80165B8();
        for (i = 0; i < 5; i++)
        {
            if (gPartyMemberIds[i] != 0xFF)
            {
                u8 y = i * 5 + 5;
                sub_80161F4(gPartyMemberIds[i], y, 5);
                sub_8016260(gPartyMemberIds[i], y, 6);
            }
        }
    }

    gUnk_03000185 = 0;
}

INCLUDE_ASM("asm/nonmatchings", sub_800B374);

INCLUDE_ASM("asm/matchings", sub_800BEE4);
/*
void sub_800BEE4(u8 *src, u8 palette)
{
    u16 *dst = (u16 *)0x02005C44;
    u16 count ;

    sub_8016368(dst++, 0xC8, 0xB);
    count = 1;
    while (*src != 0xFF) {
        u16 ch = *src++;
        if (ch == 0xFE)
        {
            ch = (*src++ << 8) | 0xFE;
            sub_8016368(dst++, ch, palette);
        }
        else
        {
            sub_8016368(dst++, ch, palette);
        }
        count++;
    }

    sub_8016368(dst++, 0xC9, 0xB);
    count++;
    while (count <= 0x1C) {
        sub_8016368(dst++, 0, 0xB);
        count++;
    }
}
*/
INCLUDE_ASM("asm/matchings", sub_800BF5C);
/*
#define MAX_UI_ENTITIES 15
#define PARTY_SIZE 5

extern u8 gPartyCharacterIds[PARTY_SIZE];       // 0x03004AA0: 存放当前队伍角色ID
extern UISpriteEntity gUISpriteEntities[MAX_UI_ENTITIES]; // 0x03000058

void sub_800BF5C(u8 arg0) {
    u16 i;

    for (i = 0; i < MAX_UI_ENTITIES; i++) {


        if (i < PARTY_SIZE && gPartyCharacterIds[i] != 0xFF) {

            gUISpriteEntities[i].x = (i * 40) + 0x48;
            gUISpriteEntities[i].y = 8;
            gUISpriteEntities[i].statusFlags = 0x80;
            gUISpriteEntities[i].field_10 = (i * 48) + 0x200;
            gUISpriteEntities[i].oamSlotId = i + 0x71;
        }
        else
        {

            gUISpriteEntities[i].x = 0;
            gUISpriteEntities[i].y = 0;
            gUISpriteEntities[i].statusFlags = 0;
            gUISpriteEntities[i].oamSlotId = 0;
        }

        // --- 所有实体公共重置 ---
        gUISpriteEntities[i].animTimer = 0;
        gUISpriteEntities[i].lerpFrame = 0;
    }

    if(arg0 == 0)
    {
        sub_800EB98(0);
        gUISpriteEntities[5].statusFlags |= 8;
    }
}

*/
INCLUDE_ASM("asm/nonmatchings", sub_800BFF8);

void sub_800C0D8(void)
{
    u16 i;
    u16 attr0;
    u16 attr1;
    u16 attr2;
    struct SpriteNode *obj = (struct SpriteNode *)0x03004380;

    attr0 = gUnk_03000048.field_6;
    attr1 = ((gUnk_03000048.field_4 - 0x20) & 0x1FF);
    attr1 += 0x8000;
    attr2 = 0x21C0;
    sub_8004C28(obj, 1, attr0, attr1, attr2);

    gSpriteRenderQueue[0] = obj;

    sub_80046DC(0x4C, 0, 9);

    for (i = 0; i < 5; i++)
    {
        obj++;
        if (gPartyMemberIds[i] != 0xFF)
        {
            attr1 = 0x8028 + ((i * 5) << 3);
            attr2 = ((i + 3) << 12) + ((i * 3 * 16 + 0x200) & 0x3FF);
            sub_8004C28(obj, 1, 8, attr1, attr2);
            gSpriteRenderQueue[i + 1] = obj;
        }
        sub_800375C(i);
    }
}
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

INCLUDE_ASM("asm/matchings", sub_800E668);
/*
typedef struct {
    u8 field0;
    u8 unused1;
    u8 field2;
    u8 unused3;
    u16 field4;
    u16 field6;
    u16 field8;
    u16 fieldA;
    u16 fieldC;
    u16 fieldE;
} Unk_03000048;

typedef struct {
u16 x;
u16 y;
} Vec2;

extern Unk_03000048 gUnk_03000048;
extern s8 gUnk_03000185;
extern u8 gUnk_03000186;
extern u8 gUnk_03000187;
extern u8 gUnk_03000188[];
extern u8 gUnk_030025F0;
extern u8 gUnk_03004D40;
extern Vec2* gUnk_087EB1F4[];
extern Vec2* gUnk_087EB214[];
extern Vec2* gUnk_087EB22C[];

void sub_800E668(u8 arg0) {
    Vec2* ptr;

    if (arg0 != 0xFF)
    {
        gUnk_03000188[gUnk_03000186] = gUnk_03000187;
        gUnk_03000186 = arg0;
        gUnk_03000187 = gUnk_03000188[gUnk_03000186];
        sub_8010624(0xFF, 0);
        gUnk_03000185 = 1;
    }

    gUnk_03000048.fieldC = gUnk_03000048.field4;
    gUnk_03000048.fieldE = gUnk_03000048.field6;


    if(gUnk_030025F0 == 0)
    {
        if(gUnk_03004D40 == 0)
        {
            ptr = &gUnk_087EB1F4[gUnk_03000186][gUnk_03000187];
        }
        else
        {
            ptr = &gUnk_087EB22C[gUnk_03000186][gUnk_03000187];
        }
    }
    else
    {
        ptr = &gUnk_087EB214[gUnk_03000186][gUnk_03000187];
    }

    gUnk_03000048.field8 = ptr->x;
    gUnk_03000048.fieldA = ptr->y;

    gUnk_03000048.field2 = 8;
    gUnk_03000048.field0 &= 0xFE;

}
*/

INCLUDE_ASM("asm/matchings", sub_800E71C);
/*
struct Vec2
{
    u16 x;
    u16 y;
};
struct MenuCharacter {
    u8 r;      // 0x00 标志位，bit7 可能控制显示
    u8 frameCounter;  // 0x01 帧计数器
    u8 unk2;          // 0x02 动画速度或状态
    u8 unk3;          // 0x03 未知
    u16 pos0_x;        // 0x04 当前位置 X
    u16 pos0_y;        // 0x06 当前位置 Y
    u16 pos1_x;        // 0x08 目标位置 X（可能用于平滑移动）
    u16 pos1_y;        // 0x0A 目标位置 Y
    u16 pos2_x;        // 0x0C 旧位置 X（备份）
    u16 pos2_y;        // 0x0E 旧位置 Y
    u32 unk10;        // 0x10 未知
};

extern struct MenuCharacter gMenuCharacters[];

extern  u8  gPartyMemberIDs[];   // 0x03004AA0
extern  u8  gFormationIDs[]; // 0x03004A88, 长度为5
extern u16 gPositionTable[];      // 0x08098418, 半字表


void sub_800E71C(u8 idx, u8 mode) {
    struct MenuCharacter* ch;
    u8 ch_id;
    u8 i;
    u16 tbl_idx;
    u16 x, y;

    if(idx == 0xFF)
        return;

    ch = &gMenuCharacters[idx];

    ch->pos2_x = ch->pos0_x;
    ch->pos2_y = ch->pos0_y;


    switch(mode)
    {
        case 1:
            x = 40;
            y = 8;
            break;

        case 0:
            x = idx * 40 + 72;
            y = 8;
            break;

        default:
            ch_id = gPartyMemberIDs[idx];

            for ( i = 0; i < 5; i++) {
                if (gFormationIDs[i] == ch_id) {
                    break;
                }
            }

            tbl_idx = (i + 2) ;
            x = gPositionTable[tbl_idx << 1 ] + 0x18;
            y = gPositionTable[(tbl_idx << 1) + 1] + 8;
            break;

    }

    ch->pos1_x = x;
    ch->pos1_y = y;
    ch->unk2 = 8;
}
*/
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

    PlayerStats *ptr4AC0;
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
INCLUDE_ASM("asm/matchings", sub_8010434);
INCLUDE_ASM("asm/nonmatchings", sub_80104F8);
INCLUDE_ASM("asm/nonmatchings", sub_8010624);
INCLUDE_ASM("asm/nonmatchings", sub_8010770);
INCLUDE_ASM("asm/matchings", sub_8010978);