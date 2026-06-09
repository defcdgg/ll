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

INCLUDE_ASM("asm/nonmatchings", sub_8010F10);

INCLUDE_ASM("asm/matchings", sub_801114C);

INCLUDE_ASM("asm/nonmatchings", sub_8011268);
INCLUDE_ASM("asm/nonmatchings", sub_80113CC);
INCLUDE_ASM("asm/nonmatchings", sub_8011454);
INCLUDE_ASM("asm/nonmatchings", sub_8012530);
INCLUDE_ASM("asm/nonmatchings", sub_8012790);
INCLUDE_ASM("asm/nonmatchings", sub_8013870);
INCLUDE_ASM("asm/nonmatchings", sub_8013934);
INCLUDE_ASM("asm/nonmatchings", sub_8013B0C);
INCLUDE_ASM("asm/nonmatchings", sub_8013C00);
INCLUDE_ASM("asm/nonmatchings", sub_8013F3C);
INCLUDE_ASM("asm/nonmatchings", sub_8013FE8);
INCLUDE_ASM("asm/nonmatchings", sub_8014084);
INCLUDE_ASM("asm/nonmatchings", sub_80140D0);
INCLUDE_ASM("asm/nonmatchings", sub_8014124);
INCLUDE_ASM("asm/nonmatchings", sub_801417C);
INCLUDE_ASM("asm/nonmatchings", sub_8014488);
INCLUDE_ASM("asm/nonmatchings", sub_801455C);
INCLUDE_ASM("asm/nonmatchings", sub_80146A8);
INCLUDE_ASM("asm/nonmatchings", sub_8014A68);

INCLUDE_ASM("asm/matchings", sub_801543C);

INCLUDE_ASM("asm/nonmatchings", sub_80154E8);
INCLUDE_ASM("asm/nonmatchings", sub_8015658);

INCLUDE_ASM("asm/matchings", sub_8015AF0);

void sub_8015B90(void)
{

    if (sub_8016AA0() != 0)
    {

        SetBgUnknown((u16 *)0x02005992, (((gUnk_03000198 >> 3) & 1) + 0x826));
    }
    else
    {
        SetBgUnknown1((u16 *)0x02005992, 0xb27F);
    }

    if (sub_8016AD4(4) != 0)
    {
        SetBgUnknown((u16 *)0x02005BD2, (((gUnk_03000198 >> 3) & 1) + 0x26));
    }
    else
    {
        SetBgUnknown1((u16 *)0x02005BD2, 0xB27F);
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8015C18);
INCLUDE_ASM("asm/nonmatchings", sub_8015E1C);
void sub_8015E88(void)
{
    gUnk_03004D44 = 1;
    gUnk_03004DD0 = 0;
}
void sub_8015EA0(void)
{
    sub_8013FE8();
    gUnk_03004D44 = 3;
    gUnk_03004DD0 = 0;
    *(u8 *)0x03000221 = 1;
    sub_8016508(0x18, 0xB);
}

INCLUDE_ASM("asm/matchings", sub_8015ED0);

void sub_8015F14(void)
{
    u8 var_r3;
    u8 i;

    for (i = 0; i < 3; i++)
    {
        sub_8010E58(i);

        var_r3 = *(u8 *)0x03000220 == i ? 0xD : 0xB;

        sub_8010F10(i, 8, i * 2 + 5, var_r3);
    }
}
u32 sub_8015F50(u8 arg0)
{
    u8 temp_r2;
    temp_r2 = gUnk_03004D60[arg0 >> 1];

    return (arg0 & 1) != 0 ? (temp_r2 >> 4) : (temp_r2 & 15);
}
void sub_8015F74(u8 x)
{
    gUnk_03004DC8[x >> 3] |= (1 << (x & 7));
}
int sub_8015F94(u8 arg0)
{
    return (gUnk_03004DC8[arg0 >> 3] >> (arg0 & 7)) & 1;
}
void sub_8015FB4(u8 arg0)
{
    gUnk_03004DD4 = arg0;
    gUnk_03004D40 = 0x28;
    gUnk_03004DD8 = 0;
    gUnk_03004DC4 = 1;
    gMainGameState = 0xD;

    ClearBuffer((u16 *)0x02005800, 30, 20);
}
INCLUDE_ASM("asm/matchings", sub_8016038);
INCLUDE_ASM("asm/matchings", sub_8016068);
INCLUDE_ASM("asm/matchings", sub_80160CC);
void sub_80160F4(void)
{
    DmaCopy32(3, 0x02020000, 0x06013800, 0x800);
    DmaCopy16(3, 0x0809E644, 0x05000240, 0x20);
    DmaCopy32(3, 0x02020800, 0x06017000, 0x1000);
    DmaCopy16(3, 0x080A12D0, 0x05000340, 0x40);
    DmaCopy16(3, 0x0808B7D4, 0x050001C0, 0x40);
}
INCLUDE_ASM("asm/matchings", sub_8016178);
INCLUDE_ASM("asm/matchings", sub_80161F4);

void sub_801624C(s16 arg0, u16 *dest)
{
    sub_800BFF8(arg0, dest, 0xB000);
}

void sub_8016260(u8 arg0, u8 x, u8 y)
{
    u16 *dest;

    if (arg0 != 0)
        arg0--;

    dest = (u16 *)0x02005800 + x + y * 32;
    *dest = 0xB257;
    dest += 3;

    sub_801624C(gUnk_03004AC0[arg0].lv + 1, dest);
}

void sub_80162A8(u8 arg0, u8 x, u8 y)
{
    u16 *dest;
    u32 unk;

    if (arg0 != 0)
        arg0--;

    dest = (u16 *)0x02005800 + x + y * 32;
    *dest = 0xB258;
    dest += 3;

    unk = gUnk_03004AC0[arg0].hp == gUnk_03004AC0[arg0].max_hp ? 0xF000 : 0xB000;

    sub_800BFF8(gUnk_03004AC0[arg0].hp, dest, unk);
}

void sub_8016308(u8 arg0, u8 x, u8 y)
{
    u16 *dest;
    u32 unk; // color

    if (arg0 != 0)
        arg0--;

    dest = (u16 *)0x02005800 + x + y * 32;
    *dest = 0xB259;
    dest += 3;

    unk = gUnk_03004AC0[arg0].mp == gUnk_03004AC0[arg0].max_mp ? 0xF000 : 0xB000;

    sub_800BFF8(gUnk_03004AC0[arg0].mp, dest, unk);
}

INCLUDE_ASM("asm/matchings", sub_8016368);

void sub_80163CC(u8 *src)
{
    u16 *dest;
    u8 x;
    u8 y;
    u8 paletteId;
    u8 charCode;

    while ((x = *src++) != 0xFF)
    {
        y = *src++;
        paletteId = *src++;
        dest = (u16 *)0x02005800 + x + (y * 32);

        while ((charCode = *src++) != 0xFF)
        {
            if (charCode == 0xFE)
            {
                charCode = *src++;
                sub_8016368(dest, (charCode << 8) | 0xFE, paletteId);
            }
            else
            {
                sub_8016368(dest, charCode, paletteId);
            }
            dest++;
        }
    }
}

u8 sub_8016424(s32 *ptr, s32 divisor)
{
    u8 count = 0;
    while (1)
    {
        *ptr -= divisor;
        if (*ptr < 0)
        {
            *ptr += divisor;
            break;
        }
        count++;
    }
    return count;
}

void sub_8016444(u16 *arg0, u16 arg1, u8 arg2)
{
    sub_8016368(sub_8016460(arg0, arg1, arg2), 0xC9, 0xB);
}
INCLUDE_ASM("asm/matchings", sub_8016460);
INCLUDE_ASM("asm/matchings", sub_80164C0);
void sub_80164F8(u16 arg0)
{
    sub_8016508(arg0, 0xB);
}
void sub_8016508(u16 arg0, u8 arg1)
{
    u16 i;
    u32 target;
    u8 *ptr;

    ptr = gUnk_030001D0[arg0 >> 6];

    target = arg0 & 0x3F;

    i = 0;

    while (i != target)
    {
        if (*ptr++ == 0xFF)
            i++;
    }

    sub_800BEE4(ptr, arg1);
}

s32 sub_801654C(u8 *arg0, u8 arg1, u8 arg2)
{
    u8 x, y;
    u16 *dest;
    u8 len;

    x = *arg0++;
    y = *arg0++;

    dest = (u16 *)0x02005800 + x + y * 32;

    if (arg2 == 0)
    {
        len = 0;
        while (*arg0 != 0xFF)
        {
            arg0++;
            len++;
        }
        while (len > 0)
        {
            sub_8016368(dest++, 0, 0x0B);
            len--;
        }
    }
    else
    {
        while (*arg0 != 0xFF)
        {
            sub_8016368(dest++, *arg0++, arg1);
        }
    }

    // No Return?
}

u8 sub_80165B8(void)
{
    return gUnk_03000188[0] - 1;
}
void sub_80165C8(u8 x, u8 y, u8 width, u8 height)
{
    u16 *temp_buf;
    u16 *buf;
    u16 row, col;
    buf = (u16 *)(0x02005800) + x + y * 32;
    for (row = 0; row < height; row++)
    {
        temp_buf = buf;
        for (col = 0; col < width; col++)
        {
            *buf++ = 0xB001;
        }
        buf = temp_buf + 0x20;
    }
}
void sub_8016628(u8 arg0, u8 arg1)
{
    u8 i;
    Unk_03000058 *p;

    if (gUnk_03004D40 != 0 && arg0 == 0xFF)
    {
        arg0 = 5;
    }

    p = gUnk_03000058;
    for (i = 0; i < 15; i++)
    {
        if (p->statusFlags != 0 && i != arg0)
        {
            if (arg1 != 0)
            {
                p->statusFlags &= 0xBF;
            }
            else
            {
                p->statusFlags |= 0x40;
            }
        }
        p++;
    }
}

void sub_801667C(void)
{
    u8 temp_r0;
    u8 i;
    Unk_03000058 *p;

    p = gUnk_030000BC;

    for (i = 5; i < 15; i++)
    {
        if (p->statusFlags != 0)
            p->statusFlags |= 0x40;
        p++;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80166A4);
INCLUDE_ASM("asm/nonmatchings", sub_80166FC);
INCLUDE_ASM("asm/nonmatchings", sub_8016758);
void sub_80167D4(u8 arg0, u8 arg1)
{
    u8 ret = sub_80165B8();
    if (ret != 0xFF)
    {
        sub_800E170(arg0, arg1, ret);
    }
}
u8 sub_80167F8(u8 arg0)
{
    u8 i;
    u8 val;

    val = gUnk_03004A88[arg0];

    i = 0;
    while (gUnk_03004AA0[i] != val)
    {
        i++;
        if (i > 4)
            return i;
    }

    return i;
}
void sub_801682C(void)
{
    u8 var_r2;

    var_r2 = gUnk_03004AA0[(u8)(gUnk_03000188[0] - 1)];
    if (var_r2 != 0)
    {
        var_r2--;
    }
    sub_800FF10(gUnk_030001B4[gUnk_03000187 - 6], gUnk_03000188[gUnk_03000186], var_r2);
}
s32 sub_8016878(void)
{
    return sub_8010170(gUnk_03000188[gUnk_03000186], gUnk_030001B4[gUnk_03000187 - 6]);
}
void sub_80168A8(void)
{
    u8 var_r0;

    var_r0 = gUnk_03004AA0[gUnk_03000226];

    if (var_r0 != 0)
    {
        var_r0--;
    }

    gUnk_03000224 = gUnk_03004AC0[var_r0].field_unk[2];
    gUnk_03000225 = gUnk_03004AC0[var_r0].field_unk[3];
}

void sub_80168EC(void)
{
    u8 var_r0;

    var_r0 = gUnk_03004AA0[gUnk_03000226];

    if (var_r0 != 0)
    {
        var_r0--;
    }

    gUnk_03004AC0[var_r0].field_unk[2] = gUnk_03000224;
    gUnk_03004AC0[var_r0].field_unk[3] = gUnk_03000225;
}

u8 sub_8016930(u8 arg0)
{
    s32 temp_r2;
    u8 var_r0;
    u8 ret;

    temp_r2 = gUnk_03000227 + arg0;
    ;

    if (temp_r2 < 8)
    {
        var_r0 = gUnk_03004AA0[gUnk_03000226];
        if (var_r0 != 0)
            var_r0--;

        ret = gUnk_03004AC0[var_r0].skills[temp_r2];

        if (ret != 0x26)
            return ret;
    }

    return 0xFF;
}
// INCLUDE_ASM("asm/nonmatchings", sub_8016978);
#define gUnk_0839CFAA ((const u8 *)0x0839CFAA)

u8 sub_8016978(void)
{
    u8 i;

    for (i = 0; i <= 0xF; i++)
    {
        if (gUnk_03004980[gUnk_0839CFAA[i]] != 0)
        {
            return i + 1;
        }
    }

    return 0;
}
// INCLUDE_ASM("asm/nonmatchings", sub_80169AC);

#define gUnk_0839CFAA ((const u8 *)0x0839CFAA)
u8 sub_80169AC(void)
{
    u8 i;

    i = gUnk_03000227 - 1;
    while (i != 0xFF)
    {
        if (gUnk_03004980[gUnk_0839CFAA[i]] != 0)
        {
            return i;
        }
        i--;
    }

    return 0xFF;
}

INCLUDE_ASM("asm/nonmatchings", sub_80169EC);
// extern u8 gUnk_0839CFAA[];
// u8 sub_80169EC(u8 arg0)
// {
//     u8 item;

//     if (arg0 <= 0xF)
//     {
//         item = gUnk_0839CFAA[arg0];
//         if (gUnk_03004980[item] != 0)
//         {
//             return item;
//         }
//     }

//     return 0xFF;
// }
INCLUDE_ASM("asm/nonmatchings", sub_8016A14);
void sub_8016A6C(void)
{
    u8 i;

    for (i = 1; i <= 0xFD; i++)
    {
        if (gUnk_03004980[i] != 0)
        {
            gUnk_03000199 = i;
            return;
        }
    }
    gUnk_03000199 = 0;
}
u8 sub_8016AA0(void)
{
    u8 index;
    u8 value;
    index = gUnk_03000199;

    if (index == 1)
        return 0;

    while (index != 0)
    {
        index--;
        if (gUnk_03004980[index] != 0)
            return index;
    }
    return 0;
}
u8 sub_8016AD4(u8 arg0)
{
    u8 idx;
    u8 count;

    idx = gUnk_03000199;
    count = 0;

    while (count < arg0)
    {
        if (gUnk_03004980[idx] != 0)
        {
            count++;
        }
        idx++;

        if (idx == 0xFF)
            return 0;
    }

    while (idx != 0xFF)
    {
        if (gUnk_03004980[idx] != 0)
        {
            return idx;
        }
        idx++;
    }

    return 0;
}

INCLUDE_ASM("asm/nonmatchings", sub_8016B30);
void sub_8016BB0(void)
{
    sub_8013FE8();
    gUnk_03004D44 = 3;
    gUnk_03004DD0 = 0xC;
    gUnk_03000221 = 0;
    sub_8016508(0x18U, 0xBU);
}
void sub_8016BE0(u16 *dest, u8 *src, u8 arg2)
{

    while (*src != 0xFF)
    {
        *dest = (arg2 << 12) + 0x200 + *src;
        dest++;
        src++;
    }
}

void sub_8016C10(u16 *dest, u8 *src)
{

    while (*src != 0xFF)
    {
        *dest = 0xF200;
        dest++;
        src++;
    }
}

u16 *sub_8016C2C(u8 x, u8 y)
{
    return (u16 *)0x2005800 + ((y * 32) + x);
}

void sub_8016C44(void)
{
    struct RenderObject *ptr = &gRenderObjects[112]; // 03004380
    gUnk_03000048.field_6 = 0;
    gUnk_03000048.field_4 = 0;
    sub_8004C28(ptr, 1, 0, 0x81E0, 0x21C0);
    gRenderObjectPtrSortList[0] = ptr;
    sub_800E668(0);
}
INCLUDE_ASM("asm/nonmatchings", sub_8016C88);
INCLUDE_ASM("asm/nonmatchings", sub_8016D24);
INCLUDE_ASM("asm/nonmatchings", sub_8016E30);
INCLUDE_ASM("asm/nonmatchings", sub_8016E80);
INCLUDE_ASM("asm/nonmatchings", sub_8016F30);
INCLUDE_ASM("asm/nonmatchings", sub_8016FC0);
void sub_80170BC(void)
{
    if (gUnk_03004DF0[0] != 0)
    {
        gUnk_03004DF0[6] = 1;
    }
}
void sub_80170D0(void)
{
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;

    REG_SIOCNT = 0x2003;
    REG_TM3CNT = 0xBFC0;
    REG_IF = 0xC0;
    gUnk_03004DF0[6] = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8017120);
INCLUDE_ASM("asm/nonmatchings", sub_80171E4);
INCLUDE_ASM("asm/nonmatchings", sub_8017588);
INCLUDE_ASM("asm/nonmatchings", sub_80175C0);
void sub_8017600(u32 *arg0, u32 *arg1, u32 arg2, u32 arg3)
{
    gUnk_03004F80.field_4 = arg0;
    gUnk_03004F80.field_0 = arg1;
    gUnk_03004F80.field_8 = arg2 >> 4;
    gUnk_03004F80.field_A = 0;
    gUnk_03004F80.field_C = arg3;
}
INCLUDE_ASM("asm/nonmatchings", sub_801761C);
INCLUDE_ASM("asm/nonmatchings", sub_8017640);
INCLUDE_ASM("asm/nonmatchings", sub_801768C);
INCLUDE_ASM("asm/nonmatchings", sub_80177AC);
INCLUDE_ASM("asm/nonmatchings", sub_8017FA4);
INCLUDE_ASM("asm/nonmatchings", sub_8018070);
INCLUDE_ASM("asm/nonmatchings", sub_80182A8);
INCLUDE_ASM("asm/nonmatchings", sub_80184A8);
INCLUDE_ASM("asm/nonmatchings", sub_801869C);
void sub_8018744(void)
{
    gUnk_03000316 = 10;
}
INCLUDE_ASM("asm/nonmatchings", sub_8018750);

u32 sub_801878C(void)
{
    return gUnk_03000340;
}
void sub_8018798(u8 index, u16 value)
{
    gUnk_03000330[index] = value;
}

u8 sub_80187A8()
{
    return gUnk_0300032E;
}
u16 sub_80187B4()
{
    return gUnk_03000324;
}
void sub_80187C0(u16 arg0)
{
    gUnk_03000324 |= arg0;
}
void sub_80187D4(u16 arg0)
{
    gUnk_03000324 &= ~arg0;
}
u16 sub_80187E8()
{
    return gUnk_03000314;
}
u16 sub_80187F4()
{
    return gUnk_03000312;
}
void sub_8018800(UnkNode *node)
{
    node->prev = node;
    node->next = node;
    node->key = -1;
}
void sub_801880C(UnkNode *node, u8 arg1)
{
    node->prev = 0;
    node->next = 0;
    node->key = arg1;
}
void sub_8018818(UnkNode *head, UnkNode *new_node)
{
    UnkNode *cur = head->next;

    while (cur->key < new_node->key)
    {
        cur = cur->next;
    }
    new_node->next = cur;
    new_node->prev = cur->prev;
    cur->prev->next = new_node;
    cur->prev = new_node;
}
void sub_8018838(u32 arg0)
{
    gUnk_03000328 = arg0;
}
/*
    LCG（linear congruential generator）线性同余算法
*/
u16 sub_8018844(void)
{
    u32 seed;
    seed = gUnk_03000328 * 0x41C64E6D + 0x3039;
    gUnk_03000328 = seed;
    return (seed / 0x10000) & 0x7FFF;
}

u32 sub_8018864()
{
    return 0x02037028;
}
u32 sub_801886C()
{
    return 0x03000248;
}
u32 sub_8018874()
{
    return 0x02037410;
}

void sub_801887C(void)
{
    if (!(gUnk_03000324 & 8))
    {
        sub_80199E0();
        sub_804AF60();
    }
}
void sub_801889C(void)
{
    sub_8019784();
    if (!(gUnk_03000324 & 8))
    {
        sub_804AE2C();
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80188BC);
INCLUDE_ASM("asm/nonmatchings", sub_8018928);
INCLUDE_ASM("asm/nonmatchings", sub_8018A58);
INCLUDE_ASM("asm/nonmatchings", sub_8018BF8);
INCLUDE_ASM("asm/nonmatchings", sub_8018D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8018E34);
INCLUDE_ASM("asm/nonmatchings", sub_8018EA8);
INCLUDE_ASM("asm/nonmatchings", sub_8018FC0);
INCLUDE_ASM("asm/nonmatchings", sub_8019148);
INCLUDE_ASM("asm/nonmatchings", sub_80191CC);
INCLUDE_ASM("asm/nonmatchings", sub_8019304);
INCLUDE_ASM("asm/nonmatchings", sub_801933C);
INCLUDE_ASM("asm/nonmatchings", sub_80196D4);
INCLUDE_ASM("asm/nonmatchings", sub_8019748);
INCLUDE_ASM("asm/nonmatchings", sub_8019784);
INCLUDE_ASM("asm/nonmatchings", sub_80199E0);
INCLUDE_ASM("asm/nonmatchings", sub_8019AD0);
INCLUDE_ASM("asm/nonmatchings", sub_8019B98);
void sub_8019DF8()
{
    gUnk_03000510 = 0;
}
void sub_8019E04(u16 arg0)
{
    gUnk_03000510 |= arg0;
}
u16 sub_8019E18()
{
    return gUnk_03000510;
}
void sub_8019E24(u16 mask)
{
    gUnk_03000510 &= ~mask;
}
void sub_8019E38(void)
{
    REG_DISPCNT &= 0xF7FF;
}
void sub_8019E4C(void)
{
    REG_DISPCNT |= 0x800;
}
INCLUDE_ASM("asm/nonmatchings", sub_8019E60);
void sub_8019ECC(void)
{
    REG_DISPCNT &= 0xFEFF;
}

void sub_8019EE0(u8 index, u8 arg1, u8 arg2)
{
    gUnk_03000348[index].field_8 = arg1;
    gUnk_03000348[index].field_9 = 0;
    gUnk_03000348[index].field_A = arg2;
    gUnk_03000348[index].field_C = 5;
}
INCLUDE_ASM("asm/nonmatchings", sub_8019F08);
INCLUDE_ASM("asm/nonmatchings", sub_8019F78);
u8 sub_801A05C(u8 index)
{
    return gUnk_03000348[index].field_C;
}
INCLUDE_ASM("asm/nonmatchings", sub_801A074);
INCLUDE_ASM("asm/nonmatchings", sub_801A0F0);
void sub_801A13C()
{
    gUnk_03000384 = 0;
}
u16 sub_801A148()
{
    return gUnk_03000384;
}
void sub_801A154(u16 mask)
{
    gUnk_03000384 &= ~mask;
}
void sub_801A168(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    gUnk_03000384 &= 0xFFF0;
    gUnk_03000384 |= 1;
    gUnk_03000384 |= 0x2000;
    if (gUnk_03000384 & 0x1000)
        gUnk_03000384 &= ~0x1000;

    gUnk_03000386 = 0;

    gUnk_030004D4 = arg0;
    gUnk_030004D5 = arg1;
    gUnk_030004D6 = arg2;
    gUnk_030004D7 = arg3;
}
INCLUDE_ASM("asm/nonmatchings", sub_801A1DC);

void sub_801A218(void)
{
    REG_DISPCNT &= 0xDFFF;
    REG_BLDY = 0;
    REG_BLDCNT = 0;

    gUnk_03000384 &= 0xFFF0;
    gUnk_03000384 &= 0xEFFF;
    
    if (gUnk_03000384 & 0x4000)
    {
        gUnk_03000384 &= 0xBFFF;
    }

    *(u8 *)0x030004D7 = 0;
}

void sub_801A270(void)
{
    DmaFill16(3, 100, (void*)0x020362C0, 0x800);
    DmaWait(3);
}

INCLUDE_ASM("asm/nonmatchings", sub_801A2AC);
// void sub_801A2AC(u16 arg0, u8 arg1, u8 arg2)
// {
//     REG_BLDCNT = arg0;
//     REG_BLDALPHA = arg1 | (arg2 << 8);

//     if (((arg0 >> 6) & 2) == 2)
//     {
//         REG_BLDY = arg1;
//     }
// }
INCLUDE_ASM("asm/nonmatchings", sub_801A2EC);
void sub_801A324(void)
{
    gUnk_030004F8 = 0;
    return;
}
void sub_801A330(void)
{
    gUnk_030004F8 = 4;
}
u8 sub_801A33C(void)
{
    return gUnk_030004F8;
}
void sub_801A348(void)
{
    gUnk_03000512 = 0;
    gUnk_03000514 = 0;
}
void sub_801A35C(void)
{
    sub_8018BF8();
    sub_80187D4(0x10);
}

void sub_801A36C(void)
{

    REG_BG0HOFS = gUnk_03000500.field_0;
    REG_BG0VOFS = gUnk_03000500.field_2;
    REG_BG1HOFS = gUnk_03000500.field_4;
    REG_BG1VOFS = gUnk_03000500.field_6;
    REG_BG2HOFS = gUnk_03000500.field_8;
    REG_BG2VOFS = gUnk_03000500.field_A;
    REG_BG3HOFS = gUnk_03000500.field_C;
    REG_BG3VOFS = gUnk_03000500.field_E;
}
INCLUDE_ASM("asm/matchings", sub_801A3A8);

INCLUDE_ASM("asm/nonmatchings", sub_801A3C4);
INCLUDE_ASM("asm/nonmatchings", sub_801A5EC);
INCLUDE_ASM("asm/nonmatchings", sub_801A684);
INCLUDE_ASM("asm/nonmatchings", sub_801A6F4);
INCLUDE_ASM("asm/nonmatchings", sub_801A884);
INCLUDE_ASM("asm/nonmatchings", sub_801AD0C);
INCLUDE_ASM("asm/nonmatchings", sub_801B0B8);
INCLUDE_ASM("asm/nonmatchings", sub_801B570);

INCLUDE_ASM("asm/matchings", sub_801B688);

INCLUDE_ASM("asm/nonmatchings", sub_801B760);
INCLUDE_ASM("asm/nonmatchings", sub_801B790);
void sub_801B7B8(void)
{
    DmaFill32(3, 0, gUnk_03000518, 0x80);
    DmaWait(3);

    DmaFill32(3, 0, gUnk_03000598, 0x80);
    DmaWait(3);
}
INCLUDE_ASM("asm/nonmatchings", sub_801B81C);
INCLUDE_ASM("asm/nonmatchings", sub_801B878);
INCLUDE_ASM("asm/nonmatchings", sub_801B8AC);
u16 *sub_801B8E8(u16 *ptr, u16 value)
{
    u16 *current = (u16 *)((u8 *)ptr + 2);

    while (*(current + 1) <= value)
    {
        current += 2;
    }
    return current;
}
INCLUDE_ASM("asm/nonmatchings", sub_801B8FC);
void sub_801B920(void)
{
    u8 i;

    GameOamData *oamPtr;
    Unk_030034C0 *srcPtr;

    oamPtr = &gOamBuffer[0];
    srcPtr = gUnk_030034C0;

    for (i = 0; i < 32; i++)
    {
        oamPtr->fields.AffineParam = srcPtr->field_0;
        oamPtr++;
        oamPtr->fields.AffineParam = srcPtr->field_2;
        oamPtr++;
        oamPtr->fields.AffineParam = srcPtr->field_4;
        oamPtr++;
        oamPtr->fields.AffineParam = srcPtr->field_6;
        oamPtr++;
        srcPtr++;
    }

    // do {
    //     oamPtr[0].fields.AffineParam = srcPtr->field_0;
    //     oamPtr++;
    //     oamPtr[0].fields.AffineParam = srcPtr->field_2;
    //     oamPtr++;
    //     oamPtr[0].fields.AffineParam = srcPtr->field_4;
    //     oamPtr++;
    //     oamPtr[0].fields.AffineParam = srcPtr->field_6;

    //     oamPtr++;
    //     srcPtr++;
    //     i++;
    // } while (i < 32);
}
u8 sub_801B954(void **ptr)
{
    return *((u8 *)(*ptr + 2));
}
u16 sub_801B95C(void **ptr)
{
    void *p = *(ptr + 1); // ptr偏移4字节（一个指针大小），等价于ptr[1]
    return *(u16 *)((u8 *)p + 2);
}
INCLUDE_ASM("asm/nonmatchings", sub_801B964);
INCLUDE_ASM("asm/nonmatchings", sub_801BE34);
INCLUDE_ASM("asm/nonmatchings", sub_801C484);
INCLUDE_ASM("asm/nonmatchings", sub_801CA08);
INCLUDE_ASM("asm/nonmatchings", sub_801CBA4);
INCLUDE_ASM("asm/nonmatchings", sub_801CE80);
INCLUDE_ASM("asm/nonmatchings", sub_801CF90);
INCLUDE_ASM("asm/nonmatchings", sub_801D12C);
INCLUDE_ASM("asm/nonmatchings", sub_801D19C);
INCLUDE_ASM("asm/nonmatchings", sub_801D214);
INCLUDE_ASM("asm/nonmatchings", sub_801D378);
INCLUDE_ASM("asm/nonmatchings", sub_801D468);
INCLUDE_ASM("asm/nonmatchings", sub_801D568);
INCLUDE_ASM("asm/nonmatchings", sub_801D710);
INCLUDE_ASM("asm/nonmatchings", sub_801D984);
INCLUDE_ASM("asm/nonmatchings", sub_801DAA0);
INCLUDE_ASM("asm/nonmatchings", sub_801DB3C);
INCLUDE_ASM("asm/nonmatchings", sub_801DC20);
INCLUDE_ASM("asm/nonmatchings", sub_801DD04);
INCLUDE_ASM("asm/nonmatchings", sub_801DDB0);
INCLUDE_ASM("asm/nonmatchings", sub_801DE44);
INCLUDE_ASM("asm/nonmatchings", sub_801DEDC);
INCLUDE_ASM("asm/nonmatchings", sub_801DF90);
INCLUDE_ASM("asm/nonmatchings", sub_801E040);
INCLUDE_ASM("asm/nonmatchings", sub_801E1D8);
INCLUDE_ASM("asm/nonmatchings", sub_801E30C);
INCLUDE_ASM("asm/nonmatchings", sub_801E4D4);
INCLUDE_ASM("asm/nonmatchings", sub_801E690);
INCLUDE_ASM("asm/nonmatchings", sub_801E848);
INCLUDE_ASM("asm/nonmatchings", sub_801EA70);
INCLUDE_ASM("asm/nonmatchings", sub_801EC3C);
INCLUDE_ASM("asm/nonmatchings", sub_801ED40);
INCLUDE_ASM("asm/nonmatchings", sub_801EE6C);
INCLUDE_ASM("asm/nonmatchings", sub_801EEE4);
INCLUDE_ASM("asm/nonmatchings", sub_801F3FC);
INCLUDE_ASM("asm/nonmatchings", sub_801F76C);
INCLUDE_ASM("asm/nonmatchings", sub_801F884);
INCLUDE_ASM("asm/nonmatchings", sub_801FA10);
INCLUDE_ASM("asm/nonmatchings", sub_801FAB8);
INCLUDE_ASM("asm/nonmatchings", sub_801FEBC);
INCLUDE_ASM("asm/nonmatchings", sub_801FF40);
INCLUDE_ASM("asm/nonmatchings", sub_80200E8);
INCLUDE_ASM("asm/nonmatchings", sub_8020228);
INCLUDE_ASM("asm/nonmatchings", sub_802031C);
INCLUDE_ASM("asm/nonmatchings", sub_8020648);
u8 sub_8020798(void)
{
    return gUnk_03000744;
}
void sub_80207A4(void)
{
    gUnk_03000630--;
}

INCLUDE_ASM("asm/nonmatchings", sub_80207B4);
// u8 sub_80207B4(void *arg0)
// {
//     if ((sub_80187B4() & 0x20))
//     {
//         return sub_801BE34(arg0);
//     }

//     return sub_801C484(arg0);
// }

INCLUDE_ASM("asm/nonmatchings", sub_80207DC);
INCLUDE_ASM("asm/nonmatchings", sub_8020840);
INCLUDE_ASM("asm/nonmatchings", sub_80208A4);
INCLUDE_ASM("asm/nonmatchings", sub_8020914);
INCLUDE_ASM("asm/nonmatchings", sub_802093C);
INCLUDE_ASM("asm/nonmatchings", sub_8020974);
INCLUDE_ASM("asm/nonmatchings", sub_80209C8);
// void sub_80209C8(u8 *arg0)
// {
//     u16 *ptr;
//     u16 new_var;

//     if (arg0[0xBE] <= 6)
//     {
//         ptr = (u16 *)(arg0 + 0x88);
//         if (*ptr <= 0x1F)
//         {
//             *ptr += 4;
//             ptr = (u16 *)(arg0 + 0xB0);
//             new_var = *ptr | 2;
//             *ptr = new_var;
//         }
//     }
// }

INCLUDE_ASM("asm/nonmatchings", sub_80209EC);
INCLUDE_ASM("asm/nonmatchings", sub_8020A0C);
INCLUDE_ASM("asm/nonmatchings", sub_8020A7C);
INCLUDE_ASM("asm/nonmatchings", sub_8020AB0);
INCLUDE_ASM("asm/nonmatchings", sub_8020AE4);
INCLUDE_ASM("asm/nonmatchings", sub_8020B04);
u32 sub_8020B48(void)
{
    return gUnk_03000718;
}
INCLUDE_ASM("asm/nonmatchings", sub_8020B54);
INCLUDE_ASM("asm/nonmatchings", sub_8020B90);
INCLUDE_ASM("asm/nonmatchings", sub_8020BC0);
INCLUDE_ASM("asm/nonmatchings", sub_8020BF0);
INCLUDE_ASM("asm/nonmatchings", sub_8020C2C);
INCLUDE_ASM("asm/nonmatchings", sub_8020C58);
INCLUDE_ASM("asm/nonmatchings", sub_8020CC4);
INCLUDE_ASM("asm/nonmatchings", sub_8020D50);
INCLUDE_ASM("asm/nonmatchings", sub_8020DA0);
void sub_8020DE4(void)
{
    gUnk_0300071C = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8020DF0);
u32 *sub_8020E54(void)
{
    return &gUnk_03000730;
}
u8 sub_8020E5C(void)
{
    return gUnk_0300073D;
}
u32 sub_8020E68(void)
{
    return gUnk_0300062C;
}
void sub_8020E74(void)
{
    u8 i;
    for (i = 0; i <= 10; i++)
    {
        gUnk_03000748[i] = 0;
    }
}
void sub_8020E90(u8 *arg0)
{
    if (arg0[0xBE] <= 10)
    {
        gUnk_03000748[arg0[0xBE]] = 1;
    }
}
INCLUDE_ASM("asm/matchings", sub_8020EAC);

// extern u8 gUnk_03000748[];

// typedef struct {
//     u8 pad[0xBE];
//     u8 field_BE;
// } Unk;

// u8 sub_8020EAC(Unk* unkStruct) {
//     u8 result = 0;

//     if (unkStruct->field_BE <= 10) {
//         result = gUnk_03000748[unkStruct->field_BE ];
//     }
//     return result;
// }
void sub_8020EC8(void)
{
    u8 i;

    gUnk_03000763 = 0;
    for (i = 0; i <= 10; i++)
    {
        gUnk_03000758[i] = 0;
    }
}
void sub_8020EEC(u8 value)
{
    gUnk_03000758[gUnk_03000763] = value;
    gUnk_03000763++;
}
INCLUDE_ASM("asm/nonmatchings", sub_8020F08);
INCLUDE_ASM("asm/nonmatchings", sub_8020F4C);
INCLUDE_ASM("asm/nonmatchings", sub_8020FB8);
INCLUDE_ASM("asm/nonmatchings", sub_802103C);
INCLUDE_ASM("asm/nonmatchings", sub_8021064);
INCLUDE_ASM("asm/nonmatchings", sub_80210C0);

void sub_8021130(void)
{
    u8 i;

    for (i = 0; i < 10; i++)
    {
        gUnk_03000788[i][0] = 0;
        gUnk_03000788[i][1] = 0;
        gUnk_03000788[i][2] = 0;
        gUnk_03000788[i][3] = 0;
        gUnk_03000788[i][4] = 0;
    }
    gUnk_030007BA = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8021184);
INCLUDE_ASM("asm/nonmatchings", sub_80212B4);
INCLUDE_ASM("asm/nonmatchings", sub_802151C);
INCLUDE_ASM("asm/nonmatchings", sub_8021700);
INCLUDE_ASM("asm/nonmatchings", sub_8021788);
INCLUDE_ASM("asm/nonmatchings", sub_802181C);
INCLUDE_ASM("asm/nonmatchings", sub_802192C);
INCLUDE_ASM("asm/nonmatchings", sub_8022458);
INCLUDE_ASM("asm/nonmatchings", sub_8022550);
INCLUDE_ASM("asm/nonmatchings", sub_8022710);
INCLUDE_ASM("asm/nonmatchings", sub_8022F2C);
INCLUDE_ASM("asm/nonmatchings", sub_80230BC);
INCLUDE_ASM("asm/nonmatchings", sub_8023320);
INCLUDE_ASM("asm/nonmatchings", sub_8023414);
INCLUDE_ASM("asm/nonmatchings", sub_8023820);
INCLUDE_ASM("asm/nonmatchings", sub_80244BC);
INCLUDE_ASM("asm/nonmatchings", sub_8024618);
INCLUDE_ASM("asm/nonmatchings", sub_80246E8);
INCLUDE_ASM("asm/nonmatchings", sub_8024820);
INCLUDE_ASM("asm/nonmatchings", sub_8024940);
void sub_802550C(u8 value)
{
    gUnk_03000816 = value;
}
INCLUDE_ASM("asm/nonmatchings", sub_8025518);
void sub_8025638(void)
{
    gUnk_03000814 = -1;
    gUnk_03000815 = -1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8025650);
INCLUDE_ASM("asm/nonmatchings", sub_80256E4);
INCLUDE_ASM("asm/nonmatchings", sub_802576C);
INCLUDE_ASM("asm/nonmatchings", sub_80257D8);
INCLUDE_ASM("asm/nonmatchings", sub_8025994);
INCLUDE_ASM("asm/nonmatchings", sub_8025DA8);
INCLUDE_ASM("asm/nonmatchings", sub_80260BC);
INCLUDE_ASM("asm/nonmatchings", sub_80264C0);
INCLUDE_ASM("asm/nonmatchings", sub_802698C);
INCLUDE_ASM("asm/nonmatchings", sub_8026D08);
INCLUDE_ASM("asm/nonmatchings", sub_8026F88);
INCLUDE_ASM("asm/nonmatchings", sub_802723C);
INCLUDE_ASM("asm/nonmatchings", sub_802761C);
INCLUDE_ASM("asm/nonmatchings", sub_8027760);
INCLUDE_ASM("asm/nonmatchings", sub_8027A20);
INCLUDE_ASM("asm/nonmatchings", sub_8027D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8028098);
INCLUDE_ASM("asm/nonmatchings", sub_80282EC);
INCLUDE_ASM("asm/nonmatchings", sub_80285A0);
INCLUDE_ASM("asm/nonmatchings", sub_80287EC);
INCLUDE_ASM("asm/nonmatchings", sub_8028AD8);
INCLUDE_ASM("asm/nonmatchings", sub_8029268);
INCLUDE_ASM("asm/nonmatchings", sub_8029510);
INCLUDE_ASM("asm/nonmatchings", sub_8029784);
INCLUDE_ASM("asm/nonmatchings", sub_80299C8);
INCLUDE_ASM("asm/nonmatchings", sub_8029BF8);
INCLUDE_ASM("asm/nonmatchings", sub_802A154);
INCLUDE_ASM("asm/nonmatchings", sub_802A86C);
INCLUDE_ASM("asm/nonmatchings", sub_802ADC4);
INCLUDE_ASM("asm/nonmatchings", sub_802B0F0);
INCLUDE_ASM("asm/nonmatchings", sub_802B608);
INCLUDE_ASM("asm/nonmatchings", sub_802B8BC);
INCLUDE_ASM("asm/nonmatchings", sub_802BB24);
INCLUDE_ASM("asm/nonmatchings", sub_802BD94);
INCLUDE_ASM("asm/nonmatchings", sub_802C0EC);
INCLUDE_ASM("asm/nonmatchings", sub_802C490);
INCLUDE_ASM("asm/nonmatchings", sub_802C714);
INCLUDE_ASM("asm/nonmatchings", sub_802C9E8);
INCLUDE_ASM("asm/nonmatchings", sub_802CE90);
INCLUDE_ASM("asm/nonmatchings", sub_802D1FC);
INCLUDE_ASM("asm/nonmatchings", sub_802D454);
INCLUDE_ASM("asm/nonmatchings", sub_802D728);
INCLUDE_ASM("asm/nonmatchings", sub_802DA78);
INCLUDE_ASM("asm/nonmatchings", sub_802DE04);
INCLUDE_ASM("asm/nonmatchings", sub_802DFDC);
INCLUDE_ASM("asm/nonmatchings", sub_802E234);
INCLUDE_ASM("asm/nonmatchings", sub_802E49C);
INCLUDE_ASM("asm/nonmatchings", sub_802E6C8);
INCLUDE_ASM("asm/nonmatchings", sub_802EAC4);
INCLUDE_ASM("asm/nonmatchings", sub_802EDD8);
INCLUDE_ASM("asm/nonmatchings", sub_802F100);
INCLUDE_ASM("asm/nonmatchings", sub_802F480);
INCLUDE_ASM("asm/nonmatchings", sub_802F6D8);
INCLUDE_ASM("asm/nonmatchings", sub_802F9EC);
INCLUDE_ASM("asm/nonmatchings", sub_802FE98);
INCLUDE_ASM("asm/nonmatchings", sub_803029C);
INCLUDE_ASM("asm/nonmatchings", sub_8030664);
INCLUDE_ASM("asm/nonmatchings", sub_80309B0);
INCLUDE_ASM("asm/nonmatchings", sub_8030C08);
INCLUDE_ASM("asm/nonmatchings", sub_8030D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8030F30);
INCLUDE_ASM("asm/nonmatchings", sub_80310C4);
INCLUDE_ASM("asm/nonmatchings", sub_8031258);
INCLUDE_ASM("asm/nonmatchings", sub_80313EC);
INCLUDE_ASM("asm/nonmatchings", sub_8031580);
INCLUDE_ASM("asm/nonmatchings", sub_8031714);
INCLUDE_ASM("asm/nonmatchings", sub_80318A8);
INCLUDE_ASM("asm/nonmatchings", sub_8031A3C);
INCLUDE_ASM("asm/nonmatchings", sub_8031BD0);
INCLUDE_ASM("asm/nonmatchings", sub_8031D64);
INCLUDE_ASM("asm/nonmatchings", sub_8031EF8);
INCLUDE_ASM("asm/nonmatchings", sub_803208C);
INCLUDE_ASM("asm/nonmatchings", sub_8032220);
INCLUDE_ASM("asm/nonmatchings", sub_80323B4);
INCLUDE_ASM("asm/nonmatchings", sub_8032548);
INCLUDE_ASM("asm/nonmatchings", sub_803272C);
INCLUDE_ASM("asm/nonmatchings", sub_8032948);
INCLUDE_ASM("asm/nonmatchings", sub_8032D74);
INCLUDE_ASM("asm/nonmatchings", sub_8032EA0);
INCLUDE_ASM("asm/nonmatchings", sub_80334B8);
INCLUDE_ASM("asm/nonmatchings", sub_8033988);
INCLUDE_ASM("asm/nonmatchings", sub_8033E2C);
INCLUDE_ASM("asm/nonmatchings", sub_8034440);
INCLUDE_ASM("asm/nonmatchings", sub_80345AC);
INCLUDE_ASM("asm/nonmatchings", sub_8034718);
INCLUDE_ASM("asm/nonmatchings", sub_80348A8);
INCLUDE_ASM("asm/nonmatchings", sub_8034BFC);
INCLUDE_ASM("asm/nonmatchings", sub_8034D94);
INCLUDE_ASM("asm/nonmatchings", sub_8034F00);
INCLUDE_ASM("asm/nonmatchings", sub_8035130);
INCLUDE_ASM("asm/nonmatchings", sub_8035360);
INCLUDE_ASM("asm/nonmatchings", sub_803586C);
INCLUDE_ASM("asm/nonmatchings", sub_8035B04);
INCLUDE_ASM("asm/nonmatchings", sub_8035D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8036034);
INCLUDE_ASM("asm/nonmatchings", sub_80362CC);
INCLUDE_ASM("asm/nonmatchings", sub_8036564);
INCLUDE_ASM("asm/nonmatchings", sub_80368FC);
INCLUDE_ASM("asm/nonmatchings", sub_8036B30);
INCLUDE_ASM("asm/nonmatchings", sub_8036EA4);
INCLUDE_ASM("asm/nonmatchings", sub_8037078);
INCLUDE_ASM("asm/nonmatchings", sub_8037388);
INCLUDE_ASM("asm/nonmatchings", sub_8037868);
INCLUDE_ASM("asm/nonmatchings", sub_8037C40);
INCLUDE_ASM("asm/nonmatchings", sub_8037E14);
INCLUDE_ASM("asm/nonmatchings", sub_8037FE8);
INCLUDE_ASM("asm/nonmatchings", sub_80381BC);
INCLUDE_ASM("asm/nonmatchings", sub_8038390);
INCLUDE_ASM("asm/nonmatchings", sub_8038568);
INCLUDE_ASM("asm/nonmatchings", sub_803874C);
INCLUDE_ASM("asm/nonmatchings", sub_8038920);
INCLUDE_ASM("asm/nonmatchings", sub_8038C84);
INCLUDE_ASM("asm/nonmatchings", sub_8038E44);
INCLUDE_ASM("asm/nonmatchings", sub_8039024);
INCLUDE_ASM("asm/nonmatchings", sub_80392C0);
INCLUDE_ASM("asm/nonmatchings", sub_80393E0);
INCLUDE_ASM("asm/nonmatchings", sub_8039724);
INCLUDE_ASM("asm/nonmatchings", sub_8039C38);
INCLUDE_ASM("asm/nonmatchings", sub_8039C6C);
INCLUDE_ASM("asm/nonmatchings", sub_803A478);
INCLUDE_ASM("asm/nonmatchings", sub_803A8D0);
INCLUDE_ASM("asm/nonmatchings", sub_803AF60);
INCLUDE_ASM("asm/nonmatchings", sub_803B484);
INCLUDE_ASM("asm/nonmatchings", sub_803BBEC);
INCLUDE_ASM("asm/nonmatchings", sub_803C328);
INCLUDE_ASM("asm/nonmatchings", sub_803CE0C);
INCLUDE_ASM("asm/nonmatchings", sub_803D20C);
INCLUDE_ASM("asm/nonmatchings", sub_803D60C);
INCLUDE_ASM("asm/nonmatchings", sub_803DECC);
INCLUDE_ASM("asm/nonmatchings", sub_803E58C);
INCLUDE_ASM("asm/nonmatchings", sub_803ED34);
INCLUDE_ASM("asm/nonmatchings", sub_803F21C);
INCLUDE_ASM("asm/nonmatchings", sub_803F328);
INCLUDE_ASM("asm/nonmatchings", sub_803F444);
INCLUDE_ASM("asm/nonmatchings", sub_803F5B4);
INCLUDE_ASM("asm/nonmatchings", sub_803F658);
INCLUDE_ASM("asm/nonmatchings", sub_803FF54);
INCLUDE_ASM("asm/nonmatchings", sub_80401AC);
INCLUDE_ASM("asm/nonmatchings", sub_80405A4);
INCLUDE_ASM("asm/nonmatchings", sub_8040690);
INCLUDE_ASM("asm/nonmatchings", sub_8040EE8);
INCLUDE_ASM("asm/nonmatchings", sub_8041308);
INCLUDE_ASM("asm/nonmatchings", sub_80416F0);
INCLUDE_ASM("asm/nonmatchings", sub_80419E0);
INCLUDE_ASM("asm/nonmatchings", sub_8041EDC);
INCLUDE_ASM("asm/nonmatchings", sub_8042200);
INCLUDE_ASM("asm/nonmatchings", sub_80422B8);
INCLUDE_ASM("asm/nonmatchings", sub_8042784);
INCLUDE_ASM("asm/nonmatchings", sub_8042AB4);
INCLUDE_ASM("asm/nonmatchings", sub_8042B90);
INCLUDE_ASM("asm/nonmatchings", sub_8042E70);
INCLUDE_ASM("asm/nonmatchings", sub_8043554);
INCLUDE_ASM("asm/nonmatchings", sub_8043938);
INCLUDE_ASM("asm/nonmatchings", sub_8043B5C);
INCLUDE_ASM("asm/nonmatchings", sub_8043F90);
INCLUDE_ASM("asm/nonmatchings", sub_8044394);
void sub_8044414(void)
{
    gUnk_03000889 = 0;
}
u16 sub_8044420(void)
{
    return gUnk_03000882;
}
INCLUDE_ASM("asm/nonmatchings", sub_804442C);
void sub_804448C(void)
{
    gUnk_03000865 = 0;
}
u8 sub_8044498(void)
{
    return gUnk_03000865;
}
INCLUDE_ASM("asm/nonmatchings", sub_80444A4);
INCLUDE_ASM("asm/nonmatchings", sub_80444E8);
INCLUDE_ASM("asm/nonmatchings", sub_8044514);
INCLUDE_ASM("asm/nonmatchings", sub_8044574);
u8 *sub_80445E0()
{
    return gUnk_03004F90;
}
INCLUDE_ASM("asm/nonmatchings", sub_80445E8);
u8 sub_8044680(u8 *arg0)
{
    if (arg0[0xBE] <= 10)
    {
        return sub_803FF54(arg0);
    }

    return sub_80405A4(arg0);
}
u8 sub_80446A4(u8 *arg0)
{
    if (arg0[0xBE] <= 10)
    {
        return gUnk_03000826;
    }

    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_80446BC);
s32 sub_8044728()
{
    return 2;
}
s32 sub_804472C()
{
    return 0;
}
s32 sub_8044730()
{
    return 0;
}
s32 sub_8044734()
{
    return 0;
}
s32 sub_8044738()
{
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_804473C);
INCLUDE_ASM("asm/nonmatchings", sub_80448A8);
INCLUDE_ASM("asm/nonmatchings", sub_8044A40);
INCLUDE_ASM("asm/nonmatchings", sub_8044F4C);
INCLUDE_ASM("asm/nonmatchings", sub_8045098);
INCLUDE_ASM("asm/nonmatchings", sub_804519C);
INCLUDE_ASM("asm/nonmatchings", sub_8045328);
INCLUDE_ASM("asm/nonmatchings", sub_80453D8);
INCLUDE_ASM("asm/nonmatchings", sub_804542C);
INCLUDE_ASM("asm/nonmatchings", sub_80454A4);
INCLUDE_ASM("asm/nonmatchings", sub_80455A0);
INCLUDE_ASM("asm/nonmatchings", sub_8045688);
INCLUDE_ASM("asm/nonmatchings", sub_80457AC);
INCLUDE_ASM("asm/nonmatchings", sub_8045860);
INCLUDE_ASM("asm/nonmatchings", sub_8045940);
INCLUDE_ASM("asm/nonmatchings", sub_8045A10);
INCLUDE_ASM("asm/nonmatchings", sub_8045A74);
INCLUDE_ASM("asm/nonmatchings", sub_8045B90);
INCLUDE_ASM("asm/nonmatchings", sub_8045BF4);
INCLUDE_ASM("asm/nonmatchings", sub_8045D00);
INCLUDE_ASM("asm/nonmatchings", sub_8045EB8);
INCLUDE_ASM("asm/nonmatchings", sub_8045F10);
INCLUDE_ASM("asm/nonmatchings", sub_8045F94);
INCLUDE_ASM("asm/nonmatchings", sub_8046060);
INCLUDE_ASM("asm/nonmatchings", sub_804612C);
INCLUDE_ASM("asm/nonmatchings", sub_804621C);
INCLUDE_ASM("asm/nonmatchings", sub_80462E4);
INCLUDE_ASM("asm/nonmatchings", sub_8046480);
INCLUDE_ASM("asm/nonmatchings", sub_8046558);
INCLUDE_ASM("asm/nonmatchings", sub_804666C);
INCLUDE_ASM("asm/nonmatchings", sub_80466F0);
INCLUDE_ASM("asm/nonmatchings", sub_8046C50);
INCLUDE_ASM("asm/nonmatchings", sub_8046CD4);
INCLUDE_ASM("asm/nonmatchings", sub_8046E18);
INCLUDE_ASM("asm/nonmatchings", sub_8046F0C);
INCLUDE_ASM("asm/nonmatchings", sub_8047024);
INCLUDE_ASM("asm/nonmatchings", sub_80471AC);
INCLUDE_ASM("asm/nonmatchings", sub_80472E8);
INCLUDE_ASM("asm/nonmatchings", sub_804753C);
INCLUDE_ASM("asm/nonmatchings", sub_80476DC);
INCLUDE_ASM("asm/nonmatchings", sub_8047B1C);
INCLUDE_ASM("asm/nonmatchings", sub_8047D28);
INCLUDE_ASM("asm/nonmatchings", sub_8047DC8);
INCLUDE_ASM("asm/nonmatchings", sub_8047FCC);
INCLUDE_ASM("asm/nonmatchings", sub_80480EC);
INCLUDE_ASM("asm/nonmatchings", sub_80481B8);
INCLUDE_ASM("asm/nonmatchings", sub_8048310);
INCLUDE_ASM("asm/nonmatchings", sub_8048458);
INCLUDE_ASM("asm/nonmatchings", sub_80485A4);
INCLUDE_ASM("asm/nonmatchings", sub_8048690);
INCLUDE_ASM("asm/nonmatchings", sub_8048764);

// typedef struct {
//     u8 padding0[153];  // 0x00 ~ 0x98 填充
//     u8 data_array[8];  // 0x99 ~ 0xA0 刚好 8 个元素的数组 (对应 val <= 7)
//     u8 check_val;      // 0xA1 偏移处的字节
// } MyStruct;

// u8 sub_8048764(MyStruct *src) {
//     u8 val = src->check_val;

//     if (val <= 7) {
//         return src->data_array[val];
//     } else {
//         return val;
//     }
// }

u8 sub_804877C(u8 arg0)
{
    u8 index;

    index = sub_80487A4(arg0);
    if (index != 0)
    {
        index--;
    }

    return gUnk_03004AC0[index].lv;
}
INCLUDE_ASM("asm/nonmatchings", sub_80487A4);
INCLUDE_ASM("asm/nonmatchings", sub_80487CC);
INCLUDE_ASM("asm/nonmatchings", sub_8048818);
INCLUDE_ASM("asm/nonmatchings", sub_8048868);
INCLUDE_ASM("asm/nonmatchings", sub_80488CC);
INCLUDE_ASM("asm/nonmatchings", sub_8048934);
INCLUDE_ASM("asm/nonmatchings", sub_8048984);
INCLUDE_ASM("asm/nonmatchings", sub_80489A4);
INCLUDE_ASM("asm/nonmatchings", sub_80489C8);
INCLUDE_ASM("asm/nonmatchings", sub_80489E8);
INCLUDE_ASM("asm/nonmatchings", sub_8048A68);
INCLUDE_ASM("asm/nonmatchings", sub_8048A88);
INCLUDE_ASM("asm/nonmatchings", sub_8048ACC);
void sub_8048B30(u8 param1, u8 param2, u16 param3)
{
    gUnk_030008F1 = 0;
    gUnk_030008F2 = param1;
    gUnk_030008F3 = param2;
    gUnk_03000906 = param3;
}
INCLUDE_ASM("asm/nonmatchings", sub_8048B5C);
INCLUDE_ASM("asm/nonmatchings", sub_8048B88);
// #define gUnk_0839CC4C ((const u8 *)0x0839CC4C)
// u8 sub_8048B88(u8 *arg0)
// {
//     if (arg0[0xBE] <= 10)
//     {
//         return gUnk_0839CC4C[arg0[0x8D] * 4];
//     }
//     return 0;
    
// }
INCLUDE_ASM("asm/nonmatchings", sub_8048BAC);
INCLUDE_ASM("asm/nonmatchings", sub_8048BD0);
INCLUDE_ASM("asm/nonmatchings", sub_8048C30);
INCLUDE_ASM("asm/nonmatchings", sub_8048C80);
INCLUDE_ASM("asm/nonmatchings", sub_8048CEC);
INCLUDE_ASM("asm/nonmatchings", sub_8048D40);
INCLUDE_ASM("asm/nonmatchings", sub_8048D64);
INCLUDE_ASM("asm/nonmatchings", sub_8048D84);
INCLUDE_ASM("asm/nonmatchings", sub_8048DA4);
INCLUDE_ASM("asm/nonmatchings", sub_8048F0C);
INCLUDE_ASM("asm/nonmatchings", sub_8048FB8);
INCLUDE_ASM("asm/nonmatchings", sub_80492C0);
INCLUDE_ASM("asm/nonmatchings", sub_80494F0);
INCLUDE_ASM("asm/nonmatchings", sub_80497B0);
INCLUDE_ASM("asm/nonmatchings", sub_80498E0);
INCLUDE_ASM("asm/nonmatchings", sub_8049958);
INCLUDE_ASM("asm/nonmatchings", sub_8049AD8);
INCLUDE_ASM("asm/nonmatchings", sub_8049B70);
INCLUDE_ASM("asm/nonmatchings", sub_8049C1C);
INCLUDE_ASM("asm/nonmatchings", sub_8049D58);
INCLUDE_ASM("asm/nonmatchings", sub_8049DF8);
INCLUDE_ASM("asm/nonmatchings", sub_804A148);
INCLUDE_ASM("asm/nonmatchings", sub_804A368);
INCLUDE_ASM("asm/nonmatchings", sub_804AA2C);
INCLUDE_ASM("asm/nonmatchings", sub_804AB10);
INCLUDE_ASM("asm/nonmatchings", sub_804AB40);
INCLUDE_ASM("asm/nonmatchings", sub_804ABD0);
INCLUDE_ASM("asm/nonmatchings", sub_804ABF8);
INCLUDE_ASM("asm/nonmatchings", sub_804AC60);
INCLUDE_ASM("asm/nonmatchings", sub_804ACC0);
INCLUDE_ASM("asm/nonmatchings", sub_804AD24);
void sub_804AD54(u16 *ptr)
{
    *(ptr + 0x5B) = 0xB000;
}
INCLUDE_ASM("asm/nonmatchings", sub_804AD60);
void sub_804ADE0(void)
{
    gUnk_03000910 = 0;
    gUnk_03000948 = 1;
}
void sub_804ADF8(void)
{
    sub_80088B4(2, 10, 0x32);
    gUnk_03000910 = 0;
    gUnk_03000911 = 0;
    gUnk_03000948 = 2;
    gUnk_0300097E = 0;

}
INCLUDE_ASM("asm/nonmatchings", sub_804AE2C);
INCLUDE_ASM("asm/nonmatchings", sub_804AF60);
INCLUDE_ASM("asm/nonmatchings", sub_804B080);
void sub_804B1EC(void)
{
    gUnk_03000ADE = 0;
}
void sub_804B1F8(u32 arg0)
{
    gUnk_030009D0 = arg0;
    gUnk_03000ADE |= 0x11;
    gUnk_03000AD8 = 0;
    gUnk_03000ADD = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_804B224);
INCLUDE_ASM("asm/nonmatchings", sub_804B288);
INCLUDE_ASM("asm/nonmatchings", sub_804B3C0);
INCLUDE_ASM("asm/nonmatchings", sub_804B458);
INCLUDE_ASM("asm/nonmatchings", sub_804B4D0);
INCLUDE_ASM("asm/nonmatchings", sub_804B56C);
INCLUDE_ASM("asm/nonmatchings", sub_804B654);
INCLUDE_ASM("asm/nonmatchings", sub_804B7B0);
INCLUDE_ASM("asm/nonmatchings", sub_804B834);
INCLUDE_ASM("asm/nonmatchings", sub_804B8E8);
INCLUDE_ASM("asm/nonmatchings", sub_804B96C);
INCLUDE_ASM("asm/nonmatchings", sub_804BB64);
INCLUDE_ASM("asm/nonmatchings", sub_804BBDC);
INCLUDE_ASM("asm/nonmatchings", sub_804BD54);
INCLUDE_ASM("asm/nonmatchings", sub_804BDD8);
INCLUDE_ASM("asm/nonmatchings", sub_804BE90);
INCLUDE_ASM("asm/nonmatchings", sub_804BF14);
INCLUDE_ASM("asm/nonmatchings", sub_804C10C);
void sub_804C184(void)
{
    sub_804C45C();
    sub_804C6B0();
}

void *sub_804C194(u8 arg0) {

    switch (arg0) {
        case 0:
            return (void *)0x03000AE8;
        case 1:
            return (void *)0x03000BE8;
    }
    //No return?
}

void sub_804C1B4(u8 arg0, u8 arg1, u8 arg2)
{
    switch (arg0) 
    {
        case 0:
            sub_804C364(arg1, arg2);
            break;
        case 1:
            sub_804C5B8(arg1, arg2);
            break;
    }
}

void sub_804C1E4(u8 arg0, u8 arg1, u8 arg2)
{
    switch (arg0) 
    {
        case 0:
            sub_804C3A4(arg1, arg2);
            break;
        case 1:
            sub_804C5F8(arg1, arg2);
            break;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804C214);
void sub_804C250(u8 arg0, u8 arg1)
{
    switch(arg0)
    {
        case 0:
            sub_804C3E4(arg1);
            break;
        case 1:
            sub_804C638(arg1);
            break;
    }
}
void sub_804C278(u8 arg0, u8 arg1)
{
    switch(arg0)
    {
        case 0:
            sub_804C420(arg1);
            break;
        case 1:
            sub_804C674(arg1);
            break;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804C2A0);
u16 sub_804C2F0(void)
{
    return gUnk_03000AE0;
}
INCLUDE_ASM("asm/nonmatchings", sub_804C2FC);
INCLUDE_ASM("asm/nonmatchings", sub_804C364);
INCLUDE_ASM("asm/nonmatchings", sub_804C3A4);
INCLUDE_ASM("asm/nonmatchings", sub_804C3E4);
INCLUDE_ASM("asm/nonmatchings", sub_804C420);
// void sub_804C420(u8 arg0) {
//     DmaCopy16(3, (void*)0x02036AC0 + (arg0 << 5), (void*)0x05000200 + (arg0 << 5), 16);
//     DmaWait(3);
// }

INCLUDE_ASM("asm/nonmatchings", sub_804C45C);
INCLUDE_ASM("asm/nonmatchings", sub_804C4D8);
u16 sub_804C53C(void)
{
    return gUnk_03000AE2;
}
INCLUDE_ASM("asm/nonmatchings", sub_804C548);
INCLUDE_ASM("asm/nonmatchings", sub_804C5B8);
INCLUDE_ASM("asm/nonmatchings", sub_804C5F8);
INCLUDE_ASM("asm/nonmatchings", sub_804C638);
INCLUDE_ASM("asm/nonmatchings", sub_804C674);
INCLUDE_ASM("asm/nonmatchings", sub_804C6B0);
INCLUDE_ASM("asm/nonmatchings", sub_804C728);
INCLUDE_ASM("asm/nonmatchings", sub_804C78C);
INCLUDE_ASM("asm/nonmatchings", sub_804C890);
INCLUDE_ASM("asm/nonmatchings", sub_804C8E0);
INCLUDE_ASM("asm/nonmatchings", sub_804C9B4);
INCLUDE_ASM("asm/nonmatchings", sub_804CA2C);
INCLUDE_ASM("asm/nonmatchings", sub_804CAA0);
INCLUDE_ASM("asm/nonmatchings", sub_804CB18);
INCLUDE_ASM("asm/nonmatchings", sub_804CB8C);
INCLUDE_ASM("asm/nonmatchings", sub_804CC00);
INCLUDE_ASM("asm/nonmatchings", sub_804CC78);
INCLUDE_ASM("asm/nonmatchings", sub_804CCEC);
INCLUDE_ASM("asm/nonmatchings", sub_804CD60);
INCLUDE_ASM("asm/nonmatchings", sub_804CDD4);
INCLUDE_ASM("asm/nonmatchings", sub_804CE48);
void sub_804CEBC(void)
{
    u8 i;
    u8 *ptr;

    for (i = 0; i <= 10; i++)
    {
        gUnk_03000D38[i] = 0xFF;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804CEE0);
INCLUDE_ASM("asm/nonmatchings", sub_804D0F8);
INCLUDE_ASM("asm/nonmatchings", sub_804D1B4);
INCLUDE_ASM("asm/nonmatchings", sub_804D260);
INCLUDE_ASM("asm/nonmatchings", sub_804D310);
INCLUDE_ASM("asm/nonmatchings", sub_804D3A0);
INCLUDE_ASM("asm/nonmatchings", sub_804D44C);
INCLUDE_ASM("asm/nonmatchings", sub_804D4FC);
INCLUDE_ASM("asm/nonmatchings", sub_804D5B4);
INCLUDE_ASM("asm/nonmatchings", sub_804D708);
INCLUDE_ASM("asm/nonmatchings", sub_804D798);
INCLUDE_ASM("asm/nonmatchings", sub_804D840);
INCLUDE_ASM("asm/nonmatchings", sub_804D8F4);
INCLUDE_ASM("asm/nonmatchings", sub_804DA04);
INCLUDE_ASM("asm/nonmatchings", sub_804DABC);
INCLUDE_ASM("asm/nonmatchings", sub_804DB64);
INCLUDE_ASM("asm/nonmatchings", sub_804DC24);
INCLUDE_ASM("asm/nonmatchings", sub_804DCD8);
INCLUDE_ASM("asm/nonmatchings", sub_804DD70);
INCLUDE_ASM("asm/nonmatchings", sub_804DD90);
INCLUDE_ASM("asm/nonmatchings", sub_804DE20);
INCLUDE_ASM("asm/nonmatchings", sub_804DE8C);
INCLUDE_ASM("asm/nonmatchings", sub_804DF14);
INCLUDE_ASM("asm/nonmatchings", sub_804DF74);
INCLUDE_ASM("asm/nonmatchings", sub_804DFD8);
INCLUDE_ASM("asm/nonmatchings", sub_804E0E4);
INCLUDE_ASM("asm/nonmatchings", sub_804E2AC);
INCLUDE_ASM("asm/nonmatchings", sub_804E6DC);
INCLUDE_ASM("asm/nonmatchings", sub_804E76C);
INCLUDE_ASM("asm/nonmatchings", sub_804E7EC);
INCLUDE_ASM("asm/nonmatchings", sub_804E85C);
INCLUDE_ASM("asm/nonmatchings", sub_804E9DC);
INCLUDE_ASM("asm/nonmatchings", sub_804EC04);
INCLUDE_ASM("asm/nonmatchings", sub_804EEC4);
INCLUDE_ASM("asm/nonmatchings", sub_804EF00);
INCLUDE_ASM("asm/nonmatchings", sub_804EF50);
INCLUDE_ASM("asm/nonmatchings", sub_804EF90);
INCLUDE_ASM("asm/nonmatchings", sub_804EFDC);
INCLUDE_ASM("asm/nonmatchings", sub_804F050);
void sub_804F07C(void)
{
    gUnk_03000DDE = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_804F088);
INCLUDE_ASM("asm/nonmatchings", sub_804F0B8);
INCLUDE_ASM("asm/nonmatchings", sub_804F10C);
INCLUDE_ASM("asm/nonmatchings", sub_804F17C);
INCLUDE_ASM("asm/nonmatchings", sub_804F210);
u8 sub_804F244()
{
    return gUnk_03000E04;
}
INCLUDE_ASM("asm/nonmatchings", sub_804F250);
INCLUDE_ASM("asm/nonmatchings", sub_804F280);
INCLUDE_ASM("asm/nonmatchings", sub_804F64C);
INCLUDE_ASM("asm/nonmatchings", sub_804F768);
INCLUDE_ASM("asm/nonmatchings", sub_804F7F8);
INCLUDE_ASM("asm/nonmatchings", sub_804F8D8);
INCLUDE_ASM("asm/nonmatchings", sub_804F974);
INCLUDE_ASM("asm/nonmatchings", sub_804FA04);
INCLUDE_ASM("asm/nonmatchings", sub_804FA94);
INCLUDE_ASM("asm/nonmatchings", sub_804FB24);
INCLUDE_ASM("asm/nonmatchings", sub_8050014);
INCLUDE_ASM("asm/nonmatchings", sub_805008C);
INCLUDE_ASM("asm/nonmatchings", sub_80501B8);
INCLUDE_ASM("asm/nonmatchings", sub_8050434);
INCLUDE_ASM("asm/nonmatchings", sub_805063C);
INCLUDE_ASM("asm/nonmatchings", sub_8050720);
INCLUDE_ASM("asm/nonmatchings", sub_80511A0);
INCLUDE_ASM("asm/nonmatchings", sub_8051230);
INCLUDE_ASM("asm/nonmatchings", sub_80512C4);
INCLUDE_ASM("asm/nonmatchings", sub_80513A0);
INCLUDE_ASM("asm/nonmatchings", sub_805144C);
INCLUDE_ASM("asm/nonmatchings", sub_8051A1C);
INCLUDE_ASM("asm/nonmatchings", sub_8051AEC);
INCLUDE_ASM("asm/nonmatchings", sub_8051BE4);

u16 sub_8052574(void)
{
    return gUnk_03000E70;
}

INCLUDE_ASM("asm/nonmatchings", sub_8052580);
INCLUDE_ASM("asm/nonmatchings", sub_80525E8);
INCLUDE_ASM("asm/nonmatchings", sub_80526A0);

void sub_8052728(u8 arg0) {

    switch (arg0) {
        default:
        case 1:
            *(u32*)0x03000E6C = 0x02016200;
            *(u16* )0x03000E70 &= ~1;
            break;
        case 3:
            *(u16* )0x03000E70 &= ~1;
            break;
    }
}


INCLUDE_ASM("asm/nonmatchings", sub_8052758);
// void sub_8052758(u16 arg0)
// {
//     if (arg0 != 0)
//     {
//         arg0 = 0;
//     }

//     LZ77UnCompVram(gUnk_087ED904[arg0], (void *)0x0600B800);
// }
INCLUDE_ASM("asm/nonmatchings", sub_8052780);
INCLUDE_ASM("asm/nonmatchings", sub_80527AC);
u16 sub_80527F4(u32 *arg0)
{
    *arg0 = 0x03000EE8;
    return *(u16 *)0x03000F24;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052808);
INCLUDE_ASM("asm/nonmatchings", sub_8052858);
INCLUDE_ASM("asm/nonmatchings", sub_8052878);
void nullsub_7() { }
INCLUDE_ASM("asm/nonmatchings", sub_80528C8);
INCLUDE_ASM("asm/nonmatchings", sub_805291C);
INCLUDE_ASM("asm/nonmatchings", sub_80529B8);

u32 sub_8052A14(u32 *ptr)
{
  u8 *data;
  u8 param1;
  u16 param2;
  u8 new_var;
  data = (u8 *) (*ptr);
  new_var = data[3];
  param2 = data[2] | (new_var << 8);
  sub_8053628(data[1], param2);
  *ptr += 4;
  return 0;
}

u32 sub_8052A38(u32 *ptr)
{
    sub_8053688();
    (*ptr)++;
    return 0;
}
u32 sub_8052A50(u32 *ptr)
{
    u8 *data;
    u8 new_var;

    data = (u8 *)*ptr;
    new_var = data[3];
    sub_805369C(data[2] | (new_var << 8));
    *ptr += 4;
    return 0;
}

u32 sub_8052A70(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_80536C0(param);

    *ptr += 2;

    return 0;
}
u32 sub_8052A8C(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_80536EC(param);

    *ptr += 2;

    return 0;
}

u32 sub_8052AA8(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_805374C(data[1], data[2], data[3] != 0);
    *ptr += 4;
    return 0;
}

u32 sub_8052ACC(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8053838(param);

    *ptr += 2;

    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052AE8);
INCLUDE_ASM("asm/nonmatchings", sub_8052B34);
u32 sub_8052B80(u32 *ptr)
{
    if (sub_8004DD0() == 0)
    {
        (*ptr)++;
        return 1;
    }

    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052BA0);
u32 sub_8052BE0(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_8004E48(data[1], data[2] | (data[3] << 8));
    *ptr += 4;
    return 0;
}
u32 sub_8052C04(u32 *ptr)
{
    if (sub_8004E7C() == 0)
    {
        (*ptr)++;
        return 1;
    }

    return 0;
}

INCLUDE_ASM("asm/nonmatchings", sub_8052C24);
INCLUDE_ASM("asm/nonmatchings", sub_8052C90);
u32 sub_8052CD0(u32 *ptr)
{
    if (gUnk_03004840 == 0)
    {
        (*ptr)++;
        return 1;
        
    }
    return 0;

}
INCLUDE_ASM("asm/nonmatchings", sub_8052CF0);
INCLUDE_ASM("asm/nonmatchings", sub_8052D4C);
u32 sub_8052D8C(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_8001050(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
u32 sub_8052DAC(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_8001070(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052DCC);
u32 sub_8052E0C(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_80010CC(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
u32 sub_8052E2C(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_80010EC(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
u32 sub_8052E4C(u32 *ptr)
{

    gUnk_03004854 = 1;
    gUnk_030047B4 = 0;
    (*ptr)++;
    return 1;
}
s32 sub_8052E6C(u32 *ptr)
{

    gUnk_03004854 = 0;
    (*ptr)++;
    return 1;
}
u32 sub_8052E80(u32 *ptr)
{
    if (gUnk_030047B4 != 0)
    {
        return 0;

    }
        (*ptr)++;
        return 1;
}
u32 sub_8052E9C(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_80046DC(data[1] | (data[2] << 8), data[3], data[4]);
    *ptr += 5;
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052EC0);
INCLUDE_ASM("asm/nonmatchings", sub_8052F20);
INCLUDE_ASM("asm/nonmatchings", sub_8052F44);
u32 sub_8052FAC(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    sub_8008BA4(param1, param2);

    *ptr += 3;

    return 1;
}

u32 sub_8052FC8(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8008BFC(param);

    *ptr += 2;

    return 1;
}
u32 sub_8052FE4(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8008BE4(param);

    *ptr += 2;

    return 1;
}

u32 sub_8053000(u32 *arg0)
{
    u8 *data = (u8 *)*arg0;

    if (!sub_8008C14(data[1]))
    {
        *arg0 += 2;
        return 1;
    }

    return 0;
}
u32 sub_8053024(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    sub_8009AC4(param1, param2);

    *ptr += 3;

    return 1;
}
u32 sub_8053040(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8009B04(param);

    *ptr += 2;

    return 1;
}

u32 sub_805305C(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8009B1C(param);

    *ptr += 2;

    return 1;
}

u32 sub_8053078(u32 *arg0)
{
    u8 *data = (u8 *)*arg0;

    if (!sub_8009B34(data[1]))
    {
        *arg0 += 2;
        return 1;
    }

    return 0;
}

u32 sub_805309C(u32 *ptr)
{
    sub_800A980();
    (*ptr)++;
    return 1;
}
u32 sub_80530B4(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    sub_800A9C0(data[1], data[2], data[3]);
    *ptr += 4;
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_80530D4);
INCLUDE_ASM("asm/nonmatchings", sub_8053104);
INCLUDE_ASM("asm/nonmatchings", sub_8053138);
u32 sub_805316C(u32 *ptr)
{
    // 读取外部变量的值作为参数
    u8 param = gUnk_03004860;

    sub_800908C(param);

    // 递增指针指向的值
    (*ptr)++;

    return 0;
}
u32 sub_805318C(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8015FB4(param);

    *ptr += 2;

    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_80531A8);
u32 sub_80531E4(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_80140D0(param);

    *ptr += 2;

    return 1;
}
u32 sub_8053200(u32 *ptr)
{
    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8014124(param);

    *ptr += 2;

    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_805321C);
u32 sub_8053254(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    sub_8015F74(param);

    *ptr += 2;

    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8053270);
INCLUDE_ASM("asm/nonmatchings", sub_80532DC);
u32 sub_8053348(u32 *ptr)
{

    sub_800110C();
    (*ptr)++;
    return 1;
}
INCLUDE_ASM("asm/matchings", sub_8053360);
// typedef struct ScriptContext{
//     u8* scriptPtr;
// }ScriptContext;

// script gJumpTableOffsets
// extern u16 gUnk_02016000[];

// extern u8 gUnk_02016200[];

// s32 sub_8053360(ScriptContext* ctx) {
//     u8* ptr;
//     u8 idx;
//     u16* ofsPtr;

//     ptr = ctx->scriptPtr;

//     if(gUnk_03002C38 > (ptr[2] + (ptr[3] << 8)))
//     {
//         idx = ptr[1];
//         ofsPtr = gUnk_02016000 + idx;
//         ctx->scriptPtr = gUnk_02016200 + *ofsPtr;
//     }
//     else
//     {
//         ctx->scriptPtr = ptr + 4;
//     }
//     return 1;
// }

u32 sub_80533A0(u32 *ptr)
{

    gUnk_03002604 = 1;
    (*ptr)++;
    return 0;
}
u32 sub_80533B4(u32 *arg0)
{
    if (gUnk_03002604 == 0)
    {
        *arg0 += 1;
        return 1;
    }
    return 0;
}
u32 sub_80533D4(u32 *ptr)
{
    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    sub_800A3C8(param1, param2);

    *ptr += 3;

    return 1;
}
