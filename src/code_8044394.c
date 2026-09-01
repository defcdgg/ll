#include "code_0.h"
#include "data_805769C.h"
#include "gba/defines.h"
#include "gba/gba.h"
#include "gba/macro.h"
#include "globals.h"
#include "include_asm.h"
#include "iwram.h"
#include "m4a.h"
#include "save.h"
#include "sound.h"

void sub_8044394(u8 *obj)
{
    u8 active;
    u16 value;

    active = 0;
    value = 0;
    if (obj[0xBE] > 11 && gUnk_03000884 == 0)
    {
        switch (obj[0xBE])
        {
        case 0x2D:
            if (*(u16 *)(obj + 0x28) != 0)
            {
                value = 0x69;
                active = 1;
            }
            break;
        case 0x61:
            if (*(u16 *)(obj + 0x28) > 0x31)
            {
                value = 0x4E;
                active = 1;
            }
            break;
        case 0x68:
            if (*(u16 *)(obj + 0x28) > 0x31)
            {
                value = 0x4E;
                active = 1;
            }
            break;
        case 0x36:
        case 0x6A:
            if (*(u16 *)(obj + 0x28) > 0x22)
            {
                value = 0x4E;
                active = 1;
            }
            break;
        }
        if (active == 1)
        {
            Sfx_Play(value, 2, 0);
            gUnk_03000884 = active;
        }
    }
}
void sub_8044414(void)
{
    gUnk_03000889 = 0;
}
u16 sub_8044420(void)
{
    return gUnk_03000882;
}
void sub_804442C(u8 arg0)
{
    u8 i;

    gUnk_03000820 = arg0;
    gUnk_03000826 = 0;
    gUnk_03000844 = 0;
    gUnk_03000845 = 0;
    gUnk_03000856 = 0;
    gUnk_03000825 = 0;
    gUnk_0300086A = 1;
    gUnk_03000884 = 0;
    for (i = 0; i <= 0xB; i++)
    {
        gUnk_03004F90[i] = 0;
    }
}
void sub_804448C(void)
{
    gUnk_03000865 = 0;
}
u8 sub_8044498(void)
{
    return gUnk_03000865;
}
void sub_80444A4(u8 *arg0)
{
    u8 ids[12];
    u8 i;
    u32 base = GetObjPool();
    u8 count = sub_80462E4(arg0, ids, 0x6F);

    for (i = 0; i < count; i++)
    {
        *(u16 *)(base + ids[i] * 0xC8 + 0xB2) = 0;
    }
}
INCLUDE_ASM("asm/matchings", sub_80444E8);
/*
u8 sub_80444E8(void)
{
    if (*(u8 *)0x03000844 != 0)
    {
        return 0;
    }
    if (*(u8 *)0x03000845 != 0)
    {
        return 0;
    }
    if (*(u8 *)0x03000856 != 0)
    {
        return 0;
    }
    return 1;
}
*/
void sub_8044514(s16 arg0)
{
    gUnk_03000844 = 1;
    gUnk_03000845 = 0;
    gUnk_03000856 = 0;
    if (arg0 < 0)
    {
        gUnk_0300085A = 0xC;
    }
    else
    {
        gUnk_0300085A = arg0;
    }
    gUnk_03000857 = 0;
    gUnk_0300085C = 0;
    gUnk_03000886 = 0x37;
    gUnk_03000888 = 0;
}
void sub_8044574(s16 arg0, u16 arg1, u8 arg2)
{
    gUnk_03000844 = 1;
    gUnk_03000845 = 0;
    gUnk_03000856 = 0;
    if (arg0 < 0)
    {
        gUnk_0300085A = 0xC;
    }
    else
    {
        gUnk_0300085A = arg0;
    }
    gUnk_03000857 = 0;
    gUnk_0300085C = 0;
    gUnk_03000886 = arg1;
    gUnk_03000888 = arg2;
}
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
u16 sub_80453D8(void)
{
    u8 *base;
    u16 result;
    u8 i;
    u8 *obj;

    base = (u8 *)GetBuf_37410();
    result = 0;
    for (i = 0; i <= 6; i++)
    {
        obj = (u8 *)(i * 0xC8 + (u32)base);
        if (obj[0xAB] == 8)
        {
            if (sub_80187B4() & 0x20)
                result += *(u16 *)(*(u8 **)(obj + 0x88) + 0x26);
            else
                result += *(u16 *)(*(u8 **)(obj + 0x88) + 0x12);
        }
    }
    return result;
}
INCLUDE_ASM("asm/nonmatchings", sub_804542C);
INCLUDE_ASM("asm/nonmatchings", sub_80454A4);
INCLUDE_ASM("asm/nonmatchings", sub_80455A0);
INCLUDE_ASM("asm/nonmatchings", sub_8045688);
INCLUDE_ASM("asm/nonmatchings", sub_80457AC);
INCLUDE_ASM("asm/nonmatchings", sub_8045860);
INCLUDE_ASM("asm/nonmatchings", sub_8045940);
INCLUDE_ASM("asm/nonmatchings", sub_8045A10);
INCLUDE_ASM("asm/nonmatchings", sub_8045A74);
extern u8 gUnk_08093418[];

void sub_8045B90(u8 *obj, u8 index)
{
    u16 original;
    u16 *current;
    u8 amount;
    u8 id;
    s32 wide;
    u8 *data;

    current = (u16 *)(obj + 0x70);
    original = *current;
    data = (u8 *)current;
    data += 0x29;
    data += index;
    id = *data;
    amount = gUnk_08093418[id * 5 + 4];
    if (sub_804E76C(obj, 3, 1) >= 0)
        amount = amount - 2;
    if (sub_804E76C(obj, 3, 2) >= 0)
        amount >>= 1;
    wide = (s16)original;
    original = wide - amount;
    if ((s16)original < 0)
        original = 0;
    *current = original;
}
INCLUDE_ASM("asm/nonmatchings", sub_8045BF4);
INCLUDE_ASM("asm/nonmatchings", sub_8045D00);
INCLUDE_ASM("asm/nonmatchings", sub_8045EB8);
INCLUDE_ASM("asm/nonmatchings", sub_8045F10);
INCLUDE_ASM("asm/nonmatchings", sub_8045F94);
INCLUDE_ASM("asm/nonmatchings", sub_8046060);
INCLUDE_ASM("asm/nonmatchings", sub_804612C);
INCLUDE_ASM("asm/nonmatchings", sub_804621C);
INCLUDE_ASM("asm/matchings", sub_80462E4);  /* 台账修正: yaml=[1] 且 .s 已在 matchings/ (坑7) */
INCLUDE_ASM("asm/nonmatchings", sub_8046480);
INCLUDE_ASM("asm/nonmatchings", sub_8046558);
INCLUDE_ASM("asm/nonmatchings", sub_804666C);
INCLUDE_ASM("asm/nonmatchings", sub_80466F0);
void sub_8046C50(void)
{
    u8 indices[8];
    u8 *buffer;
    u8 *base;
    u8 count;
    u8 i;
    u8 j;
    u8 max;
    u8 limit;

    base = (u8 *)GetObjPool();
    buffer = indices;
    count = 0;
    for (i = 0; i <= 4; i++)
        buffer[i] = 0;
    i = 0;
    max = 5;
    while (i < max)
    {
        if (sub_8045F10(base + i * 0xC8, 0x43) == 2)
        {
            buffer[count] = i;
            count++;
        }
        i++;
    }
    limit = count;
    for (j = 0; j < limit; j++)
        base[indices[j] * 0xC8 + 0xBC] = 4;
}
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
INCLUDE_ASM("asm/matchings", sub_8048764);

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

    return gPartyStats[index].lv;
}
u8 sub_80487A4(u8 arg0)
{
    u32 base;

    base = GetObjPool();
    return gBattleFormationIds[*(u8 *)(base + arg0 * 0xC8 + 0xBB)];
}
u8 sub_80487CC(u8 arg0)
{
    u8 i;
    u8 ret;

    ret = sub_80187A8();
    if (ret == 0xA1 || ret == 0xA7)
    {
        return 2;
    }
    for (i = 0; i <= 5; i++)
    {
        if (gBattleFormationIds[i] == gPartyMemberIds[arg0])
        {
            return i;
        }
    }
    return 0;
}
u16 sub_8048818(u8 objectIndex, u8 arg1)
{
    u32 base;
    u32 formation;
    u8 idx;

    base = GetObjPool();
    formation = gBattleFormationIds[*(u8 *)(base + objectIndex * 0xC8 + 0xBB)];
    idx = formation;
    if (formation != 0)
        idx = formation - 1;
    return sub_8009F70(formation, gPartyStats[idx].lv, arg1);
}
u8 sub_8048868(u8 objectIndex, u8 skill)
{
    u8 formation;
    u8 i;
    u32 base;

    base = GetObjPool();
    formation = gBattleFormationIds[
        *(u8 *)(base + objectIndex * 0xC8 + 0xBB)];
    if (formation != 0)
        formation--;

    for (i = 0; i <= 7; i++)
    {
        if (gPartyStats[formation].skills[i] == skill)
            break;
    }
    if (i <= 7)
        return 0;
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_80488CC);

u8 sub_8048934(u8 *arg0, u8 arg1)
{
    u8 b;
    u8 val;
    u8 *tbl;
    s8 *ptr;
    int off;

    ptr = arg0 + 0x99;
    b = ptr[arg1];
    tbl = gUnk_08093418;
    off = b * 5 + 4;
    val = *(u8 *)(off + tbl);
    if (sub_804E76C(arg0, 3, 1) >= 0)
    {
        val = val - 2;
    }
    if (sub_804E76C(arg0, 3, 2) >= 0)
    {
        val = val / 2;
    }
    return val;
}
u8 sub_8048984(u8 *arg0, u8 arg1)
{
    u8 *ptr;
    u8 index;

    ptr = arg0 + 0x99;
    index = ptr[arg1];
    return gUnk_08093418[index * 5 + 2] & 0xF;
}
u8 sub_80489A4(u8 *arg0, u8 arg1)
{
    if (arg1 <= 7)
    {
        u8 *ptr = arg0 + 0x99;

        arg1 = ptr[arg1];
    }
    return gUnk_08093418[arg1 * 5 + 1] & 0xF;
}
u16 sub_80489C8(u8 *arg0, u16 arg1)
{
    s32 diff;

    diff = *(u16 *)(arg0 + 0x72) - *(u16 *)(arg0 + 0x70);
    if (diff < arg1)
    {
        return diff;
    }
    return arg1;
}
u8 sub_80489E8(u8 *base, u8 *output, u8 mode, u16 flags)
{
    u8 count;
    u8 i;
    u8 end;

    count = 0;
    if (mode == 0)
    {
        for (i = 0; i <= 4; i++)
            output[i] = 0;
        i = 0;
        end = 5;
    }
    else
    {
        for (i = 0; i <= 6; i++)
            output[i] = 0;
        i = 5;
        end = 12;
    }
    for (; i < end; i++)
    {
        if (sub_8045F10(base + i * 0xC8, flags) == 2)
        {
            output[count] = i;
            count++;
        }
    }
    return count;
}
u8 sub_8048A68(u8 *arg0)
{
    s16 a;
    s16 b;
    s16 diff;

    a = *(s16 *)(arg0 + 0x6C);
    b = *(s16 *)(arg0 + 0xB2);
    diff = a - b;
    if (diff <= 0)
    {
        return 1;
    }
    return 0;
}
void sub_8048A88(u8 *arg0, s8 arg1, s8 arg2)
{
    u8 val;

    if (arg1 >= arg2)
    {
        return;
    }
    val = sub_8046E18(arg0, arg1, arg2);
    if (val >= arg2)
    {
        return;
    }
    sub_8048A88(arg0, arg1, val - 1);
    sub_8048A88(arg0, val + 1, arg2);
}
void sub_8048ACC(u8 *arg0, u8 arg1, u8 arg2)
{
    s8 val;
    u8 val2;

    if (arg1 <= 1)
    {
        return;
    }
    gUnk_030008F0 = arg2;
    gUnk_030008EC = GetObjPool();
    val = arg1 - 1;
    if (val <= 0)
    {
        return;
    }
    val2 = sub_8046E18(arg0, 0, val);
    if (val2 >= val)
    {
        return;
    }
    sub_8048A88(arg0, 0, val2 - 1);
    sub_8048A88(arg0, val2 + 1, val);
}
void sub_8048B30(u8 param1, u8 param2, u16 param3)
{
    gUnk_030008F1 = 0;
    gUnk_030008F2 = param1;
    gUnk_030008F3 = param2;
    gUnk_03000906 = param3;
}
INCLUDE_ASM("asm/matchings", sub_8048B5C);
/*
void sub_8048B5C(u8 *arg0, u8 arg1)
{
    if (arg0[0x91] == 0xB3 || arg0[0x92] == 0xB3)
    {
        *(u16 *)(arg0 + 0x88) = 0x20;
    }
    else
    {
        *(u16 *)(arg0 + 0x88) = arg1;
    }
}
*/
extern u8 gUnk_0839CC4C[];

u8 sub_8048B88(u8 *arg0)
{
    if (arg0[0xBE] <= 10)
    {
        return gUnk_0839CC4C[arg0[0x8D] * 4];
    }
    return 0;
}
INCLUDE_ASM("asm/matchings", sub_8048BAC);
// typedef struct {
//     u16 unk_0;
//     u8 value;
//     u8 unk_3;
// } Unk_0839CC4C;

// extern Unk_0839CC4C gUnk_0839CC4C[];

// u8 sub_8048BAC(u8 *arg0)
// {
//     if (arg0[0xBE] <= 10)
//     {
//         return gUnk_0839CC4C[arg0[0x8D]].value;
//     }
//     return 0;

// }
void sub_8048BD0(u8 *arg0)
{
    switch (arg0[0xBE])
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
        arg0[0xC3] = 0x10;
        break;
    case 5:
        if (arg0[0x8D] == 0)
        {
            arg0[0xC3] = 8;
        }
        else
        {
            arg0[0xC3] = 0x10;
        }
        break;
    default:
        return;
    }
}
extern u8 gUnk_0839D5BC[];

INCLUDE_ASM("asm/nonmatchings", sub_8048C30);


INCLUDE_ASM("asm/nonmatchings", sub_8048C80);
u8 sub_8048CEC(u8 *obj)
{
    u8 result;

    result = 0;
    if (obj[0xBE] <= 10)
    {
        if ((s8)obj[0xBC] != 2)
        {
            if (*(u16 *)(obj + 0x7E) != 0)
                result = 1;
            else if (*(u16 *)(obj + 0x80) != 0)
                result = 2;
        }
        else
        {
            if (*(u16 *)(obj + 0x7E) != 0)
                result = 3;
            else if (*(u16 *)(obj + 0x80) != 0)
                result = 4;
        }
    }
    return result;
}
INCLUDE_ASM("asm/matchings", sub_8048D40);
// typedef struct {
//     char gap1[0x7e];
//     u16 a,b,c,d,e;
//     char gap2[54];
//     u8 check_val;
// } MyStruct;

// void sub_8048D40(MyStruct *ptr)
// {
//     if (ptr->check_val <= 10)
//     {
//         ptr->a = 0;
//         ptr->b = 0;
//         ptr->c = 0;
//         ptr->d = 0;
//         ptr->e = 0;
//     }
// }
INCLUDE_ASM("asm/matchings", sub_8048D64);
// u16 sub_8048D64(u8 *arg0, u16 arg1)
// {
//     s32 diff;

//     diff = *(u16 *)(arg0 + 0x6E) - *(u16 *)(arg0 + 0x6C);
//     if (diff < arg1)
//     {
//         return diff;
//     }

//     return arg1;
// }
INCLUDE_ASM("asm/matchings", sub_8048D84);
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
INCLUDE_ASM("asm/matchings", sub_804AB10);
INCLUDE_ASM("asm/nonmatchings", sub_804AB40);
INCLUDE_ASM("asm/matchings", sub_804ABD0);
// void sub_804ABD0(void) {
//     u8 i;
//     u16 *ptr;

//     ptr = (u16 *)0x02035B04;
//     for (i = 0; i <= 0x19; i++)
//     {
//         ptr[i] = 0xB001;
//         ptr[i + 0x20] = 0xB001;
//     }
// }
/* tile 动画帧写入: 按 arg1*18 + gUnk_0300094D*2 索引 gUnk_0862D574 的 u16 帧表,
 * 把当前帧写入 dest[0]/dest[0x20] 两处 tilemap (值 = data*2 - 0x5000 / -0x4FFF),
 * 帧号 gUnk_0300094D++ 后检查: >3 或下一帧 == 0xF00 终止符 → 返回 1 (动画结束), 否则 0。 */
extern u8 gUnk_0862D574[];

u32 sub_804ABF8(u16 *dest, u8 arg1)
{
    u8 *base;
    u16 data;
    u16 off;
    u16 off2;

    base = gUnk_0862D574;
    off = gUnk_0300094D * 2 + arg1 * 18;
    data = *(u16 *)(base + off);
    dest[0] = data * 2 - 0x5000;
    dest[0x20] = data * 2 - 0x4FFF;

    gUnk_0300094D++;

    if (gUnk_0300094D > 3)
        return 1;

    off2 = gUnk_0300094D * 2 + arg1 * 18;
    if (*(u16 *)(base + off2) == 0xF00)
        return 1;

    return 0;
}

extern u8 gUnk_0839D348[];

void sub_804AC60(void)
{
    u32 local;
    u8 b;
    u8 *entry;

    b = *(u8 *)(gUnk_030009C8 + gUnk_030009C5);
    entry = gUnk_0839D348 + b * 18;
    if (sub_80187B4() & 0x20)
    {
        sub_8050434(entry, 0x4F1E);
        if ((u16)TileDma_GetCtx(&local) != 0)
        {
            sub_80187C0(0x400);
        }
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804ACC0);
void sub_804AD24(u8 *arg0)
{
    u8 value;

    gUnk_03000911 = (gUnk_03000911 + 1) % 16;

    value = gUnk_03000911 / 8;

    *(u16 *)(arg0 + 0xB6) = 0xB1BE + value;
}
void sub_804AD54(u16 *ptr)
{
    *(ptr + 0x5B) = 0xB000;
}
extern u8 gUnk_08619A60[];
extern u8 gUnk_08619430[];

void sub_804AD60(void)
{
    u8 *obj = gUnk_03000918;
    u8 zero;
    u16 flags;

    sub_801B81C(obj, 0xF0, 0x50, 0xDA * 2, 0xE, gUnk_08619A60,
                 gUnk_08619430, 0xA8 * 8, 1, 0x402);
    sub_801A3C4(obj);
    flags = 0xF7FF & *(u16 *)(obj + 0x18);
    zero = 0;
    *(u16 *)(obj + 0x18) = flags;
    sub_801A684(obj);
    gUnk_03000911 = zero;
    gUnk_03000910 = zero;
    gUnk_03000948 = zero;
    obj[0x2A] = zero;
    Bgm_Stop();
}
void sub_804ADE0(void)
{
    gUnk_03000910 = 0;
    gUnk_03000948 = 1;
}
void sub_804ADF8(void)
{
    ScreenFade_Start(2, 10, 0x32);
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
extern u32 gUnk_0861AAA4[];
extern u32 gUnk_0861C764[];

void sub_804B224(u16 *flags)
{
    if ((*flags & 0x80) != 0)
    {
        DmaCopy32(3, gUnk_0861AAA4, (void *)0x06012E80, 0x280);
        DmaWait(3);
        sub_804C2FC((u32)gUnk_0861C764, 0xF, 1);
        *flags &= 0xFF7F;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804B288);
INCLUDE_ASM("asm/nonmatchings", sub_804B3C0);
void sub_804B458(Unk_804B458 *entry, u8 slot, u16 *src, u16 *dest)
{
    u8 width;
    u8 frames;

    entry->field_3 = (entry->field_3 + 1) % entry->field_2;
    if (entry->field_3 == 0)
    {
        width = entry->field_4 & 0xF;
        frames = entry->field_4 >> 4;
        if (entry->field_8 == 0)
            entry->field_6 = (u8)((*(u8 *)&entry->field_6 + 1) % frames);
        else if (entry->field_6 == 0)
            entry->field_6 = frames - 1;
        else
            entry->field_6--;
        sub_804C2A0(src + (entry->field_1 << 4),
                    dest + (slot << 4), width, frames, entry->field_6);
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804B4D0);
INCLUDE_ASM("asm/nonmatchings", sub_804B56C);
INCLUDE_ASM("asm/nonmatchings", sub_804B654);
INCLUDE_ASM("asm/nonmatchings", sub_804B7B0);
INCLUDE_ASM("asm/nonmatchings", sub_804B834);
INCLUDE_ASM("asm/nonmatchings", sub_804B8E8);
INCLUDE_ASM("asm/nonmatchings", sub_804B96C);
void sub_804BB64(u8 start, u8 count)
{
    u8 i;
    u32 index;
    u8 *base;
    u8 *entry;
    u8 mask;
    u8 value;

    i = 0;
    if (i < count)
    {
        mask = 0xFF;
        do
        {
            base = gUnk_03000AE8;
            index = start + i;
            entry = base + index * 16;
            if ((entry[0] & 0xF) == 3)
            {
                if ((entry[0] & 0x20) == 0)
                    sub_804C3A4(entry[1], 1);
                sub_804C420((u8)index);
                value = entry[0];
                value |= mask;
                entry[0] = value;
                value = entry[1];
                value |= mask;
                entry[1] = value;
                entry[2] = 0;
                entry[3] = 0;
            }
            i++;
        } while (i < count);
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804BBDC);
INCLUDE_ASM("asm/nonmatchings", sub_804BD54);
INCLUDE_ASM("asm/nonmatchings", sub_804BDD8);
INCLUDE_ASM("asm/nonmatchings", sub_804BE90);
INCLUDE_ASM("asm/nonmatchings", sub_804BF14);
void sub_804C10C(u8 start, u8 count)
{
    u8 i;
    u32 index;
    u8 *base;
    u8 *entry;
    u8 mask;
    u8 value;

    i = 0;
    if (i < count)
    {
        mask = 0xFF;
        do
        {
            base = gUnk_03000BE8;
            index = start + i;
            entry = base + index * 16;
            if ((entry[0] & 0xF) == 3)
            {
                if ((entry[0] & 0x20) == 0)
                    sub_804C5F8(entry[1], 1);
                sub_804C674((u8)index);
                value = entry[0];
                value |= mask;
                entry[0] = value;
                value = entry[1];
                value |= mask;
                entry[1] = value;
                entry[2] = 0;
                entry[3] = 0;
            }
            i++;
        } while (i < count);
    }
}
void sub_804C184(void)
{
    sub_804C45C();
    sub_804C6B0();
}

void *sub_804C194(u8 arg0)
{

    switch (arg0)
    {
        case 0:
            return (void *)0x03000AE8;
        case 1:
            return (void *)0x03000BE8;
    }
    // No return?
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
u8 sub_804C214(u8 arg0, u8 arg1) {

    u8 ret = 0;

    switch (arg0)
    {
        case 0:
            if((gUnk_03000AE0 >> arg1) & 1)
            {
                ret = 1;
            }
            break;
        case 1:
            if((gUnk_03000AE2 >> arg1) & 1)
            {
                ret = 1;
            }
            break;
    }

    return ret;
}
void sub_804C250(u8 arg0, u8 arg1)
{
    switch (arg0)
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
    switch (arg0)
    {
        case 0:
            sub_804C420(arg1);
            break;
        case 1:
            sub_804C674(arg1);
            break;
    }
}

void sub_804C2A0(u16* arg0, u16* arg1, u8 arg2, u8 arg3, u8 arg4) {
    u8 i;

    for(i = 0; i < arg3; i++)
    {
        arg0[ i+arg2 ] = arg1[arg4 + arg2];

        arg4 = (arg4+1) % arg3;
    }

}
u16 sub_804C2F0(void)
{
    return gUnk_03000AE0;
}
void sub_804C2FC(u32 arg0, u8 arg1, u8 arg2) {
    u8 i;
    
    DmaCopy16(3, arg0, 0x5000200 + (arg1 << 5), arg2*0x20);
    DmaWait(3);

    for(i = 0; i < arg2; i++)
    {
        if(!((gUnk_03000AE0 >> (arg1 + i)) & 1))
        {
            gUnk_03000AE0 |= (1 << (arg1+i));
        }
    }
}
void sub_804C364(u8 arg0, u8 arg1) {
    u8 i;

    for(i = 0; i < arg1; i++)
    {
        if(!((gUnk_03000AE0 >> (arg0 + i)) & 1))
        {
            gUnk_03000AE0 |= (1 << (arg0+i));
        }
    }
}
void sub_804C3A4(u8 arg0, u8 arg1) {
    u8 i;
    for(i = 0; i < arg1; i++)
    {
        if(((gUnk_03000AE0 >> (arg0 + i)) & 1))
        {
            gUnk_03000AE0 &= ~(1 << (arg0+i));
        }
    }
}

void sub_804C3E4(u8 arg0) {
    DmaCopy16(3, 0x05000200+(arg0<<5), 0x02036AC0+(arg0<<5),0x20);
    DmaWait(3);
}

void sub_804C420(u8 arg0) {
    DmaCopy32(3, 0x02036AC0 + (arg0 << 5), 0x05000200 + (arg0 << 5), 32);
    DmaWait(3);
}

void sub_804C45C(void)
{
    u8 i;
    u8 *entry;

    for (i = 0; i <= 15; i++)
    {
        entry = gUnk_03000AE8 + i * 16;
        switch (entry[0] & 0xF)
        {
        case 1:
            sub_804B3C0(entry, i, 0x05000200, 0x02036AC0);
            break;
        case 2:
            sub_804B458((Unk_804B458 *)entry, i,
                        (u16 *)0x05000200, (u16 *)0x02036AC0);
            break;
        case 3:
            sub_804B4D0(entry, i, 0x05000200, 0x02036AC0);
            break;
        }
    }
}
/* 0x03000AE8 表的 16 字节项视图 (iwram.h 里只有 u8[] 声明, 不动它)。
 * 必须用结构体成员形式: 写成 `u8 *ptr; ptr[0] |= 0x40;` 时 GCC2 会把 IOR 的
 * 目的寄存器选成常量那个 (`mov r0, ip; orrs r0, r1`), 而目标是
 * `adds r0, r1, #0; orrs r0, r7` (先拷 b 再或常量)。见规则 11 / 67。 */
typedef struct {
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
    u8 pad[12];
} Unk_03000AE8;

void sub_804C4D8(u8 arg0, u8 arg1, u8 arg2)
{
    u8 i;
    Unk_03000AE8 *entry;

    for (i = 0; i < arg1; i++)
    {
        entry = (Unk_03000AE8 *)&gUnk_03000AE8[(arg0 + i) * 16];
        if ((entry->field_0 & 0xF) == 3)
        {
            entry->field_0 |= 0x40;
            entry->field_2 = arg2;
            entry->field_3 = 0;
        }
    }
}

u16 sub_804C53C(void)
{
    return gUnk_03000AE2;
}
void sub_804C548(u32 src, u8 slot, u8 count)
{
    u8 i;

    DmaCopy32(3, src, 0x05000000 + (slot << 5), count * 0x20);
    DmaWait(3);
    for (i = 0; i < count; i++)
    {
        if (((gUnk_03000AE2 >> (slot + i)) & 1) == 0)
            gUnk_03000AE2 |= 1 << (slot + i);
    }
}
void sub_804C5B8(u8 arg0, u8 arg1) {
    u8 i;

    for(i = 0; i < arg1; i++)
    {
        if(!((gUnk_03000AE2 >> (arg0 + i)) & 1))
        {
            gUnk_03000AE2 |= (1 << (arg0+i));
        }
    }
}

void sub_804C5F8(u8 arg0, u8 arg1) {
    u8 i;

    for(i = 0; i < arg1; i++)
    {
        if(((gUnk_03000AE2 >> (arg0 + i)) & 1))
        {
            gUnk_03000AE2 &= ~(1 << (arg0+i));
        }
    }
}
void sub_804C638(u8 arg0) {
    DmaCopy32(3, 0x05000000 + (arg0 << 5), 0x02036CC0 + (arg0 << 5), 32);
    DmaWait(3);
}
void sub_804C674(u8 arg0) {
    DmaCopy32(3, 0x02036CC0 + (arg0 << 5), 0x05000000 + (arg0 << 5), 32);
    DmaWait(3);
}
void sub_804C6B0(void)
{
    u8 i;
    u8 *entry;

    for (i = 0; i <= 15; i++)
    {
        entry = gUnk_03000BE8 + i * 16;
        switch (entry[0] & 0xF)
        {
        case 1:
            sub_804B3C0(entry, i, 0x05000000, 0x02036CC0);
            break;
        case 2:
            sub_804B458((Unk_804B458 *)entry, i,
                        (u16 *)0x05000000, (u16 *)0x02036CC0);
            break;
        case 3:
            sub_804B4D0(entry, i, 0x05000000, 0x02036CC0);
            break;
        }
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804C728);
INCLUDE_ASM("asm/nonmatchings", sub_804C78C);
INCLUDE_ASM("asm/nonmatchings", sub_804C890);
INCLUDE_ASM("asm/nonmatchings", sub_804C8E0);
INCLUDE_ASM("asm/nonmatchings", sub_804C9B4);
void sub_804CA2C(u8 *obj)
{
    u8 values[16];
    u8 count;
    u8 value;

    count = sub_80489E8((u8 *)GetObjPool(), values, 1, 0x7F);
    obj[0xBC] = 0;
    if ((s8)gUnk_03000D38[obj[0xBE]] < 0)
    {
        value = values[((s32 (*)(void))Rng_LcgNext)() % count];
        obj[0xBD] = value;
        gUnk_03000D38[obj[0xBE]] = values[((s32 (*)(void))Rng_LcgNext)() % count];
    }
    else
    {
        obj[0xBD] = gUnk_03000D38[obj[0xBE]];
    }
}

#define DEFINE_RANDOM_SLOT_FUNC_16(name)                  \
void name(u8 *obj)                                        \
{                                                         \
    u8 values[16];                                        \
    u8 count;                                             \
    u8 value;                                             \
                                                          \
    count = sub_80489E8((u8 *)GetObjPool(), values, 1,   \
                         0x7F);                           \
    obj[0xBC] = 0;                                        \
    if ((s8)gUnk_03000D38[obj[0xBE]] < 0)                 \
    {                                                     \
        value = values[((s32 (*)(void))Rng_LcgNext)() %   \
                       count];                            \
        obj[0xBD] = value;                                \
        gUnk_03000D38[obj[0xBE]] =                        \
            values[((s32 (*)(void))Rng_LcgNext)() % count]; \
    }                                                     \
    else                                                  \
    {                                                     \
        obj[0xBD] = gUnk_03000D38[obj[0xBE]];             \
    }                                                     \
}

#define DEFINE_RANDOM_SLOT_FUNC_24(name)                  \
void name(u8 *obj)                                        \
{                                                         \
    u8 values[24];                                        \
    u8 count;                                             \
    u8 value;                                             \
    u8 *base;                                             \
                                                          \
    base = (u8 *)GetObjPool();                           \
    obj[0xBC] = 0;                                        \
    count = sub_80489E8(base, values, 1, 0x17F);          \
    if ((s8)gUnk_03000D38[obj[0xBE]] < 0)                 \
    {                                                     \
        value = values[((s32 (*)(void))Rng_LcgNext)() %   \
                       count];                            \
        obj[0xBD] = value;                                \
        gUnk_03000D38[obj[0xBE]] =                        \
            values[((s32 (*)(void))Rng_LcgNext)() % count]; \
    }                                                     \
    else                                                  \
    {                                                     \
        obj[0xBD] = gUnk_03000D38[obj[0xBE]];             \
    }                                                     \
}

DEFINE_RANDOM_SLOT_FUNC_24(sub_804CAA0)
void sub_804CB18(u8 *obj)
{
    u8 values[16];
    u8 count;
    u8 value;

    count = sub_80489E8((u8 *)GetObjPool(), values, 1, 0x7F);
    obj[0xBC] = 0;
    if ((s8)gUnk_03000D38[obj[0xBE]] < 0)
    {
        value = values[((s32 (*)(void))Rng_LcgNext)() % count];
        obj[0xBD] = value;
        gUnk_03000D38[obj[0xBE]] = values[((s32 (*)(void))Rng_LcgNext)() % count];
    }
    else
    {
        obj[0xBD] = gUnk_03000D38[obj[0xBE]];
    }
}
DEFINE_RANDOM_SLOT_FUNC_16(sub_804CB8C)
DEFINE_RANDOM_SLOT_FUNC_24(sub_804CC00)
DEFINE_RANDOM_SLOT_FUNC_16(sub_804CC78)
DEFINE_RANDOM_SLOT_FUNC_16(sub_804CCEC)
DEFINE_RANDOM_SLOT_FUNC_16(sub_804CD60)
DEFINE_RANDOM_SLOT_FUNC_16(sub_804CDD4)
DEFINE_RANDOM_SLOT_FUNC_16(sub_804CE48)

#undef DEFINE_RANDOM_SLOT_FUNC_16
#undef DEFINE_RANDOM_SLOT_FUNC_24
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
typedef void (*UnkFuncDD70)(u8 *, u32);
extern UnkFuncDD70 gUnk_0839CE38[];

void sub_804DD70(u8 *ptr, u32 arg1) {
    gUnk_0839CE38[*(u8 *)(ptr + 0xBE) - 0x71](ptr, arg1);
}
extern const u8 gUnk_087EA580[];
extern const u8 gUnk_0839CEFC[];

u8 sub_804DD90(u8 arg0, u8 arg1)
{
    u8 result;
    const u8 *data;

    result = 0;
    data = gUnk_0839CEFC + gUnk_087EA580[arg0 * 12 + 10] * 3;
    switch (arg1)
    {
    case 0:
        result = data[0] & 0x3F;
        break;
    case 1:
        result = data[0] >> 6;
        break;
    case 2:
        result = data[1] & 0xF;
        break;
    case 3:
        result = (data[1] >> 4) & 3;
        break;
    case 4:
        result = data[1] >> 6;
        break;
    case 5:
        result = data[2] & 3;
        break;
    case 6:
        result = (data[2] >> 3) & 1;
        break;
    }
    return result;
}
extern u8 gUnk_03004980[];

void sub_804DE20(void)
{
    u8 i;

    for (i = 0; i <= 15; i++)
    {
        gUnk_03000D48[i].field_0 = 0;
        gUnk_03000D48[i].field_1 = 0;
    }
    gUnk_03000DDD = 0;
    for (i = 0; i <= 15; i++)
    {
        if (gUnk_03004980[gInvPageItemIds[i]] != 0)
        {
            gUnk_03000D48[gUnk_03000DDD].field_0 = gInvPageItemIds[i];
            gUnk_03000D48[gUnk_03000DDD].field_1 = gUnk_03004980[gInvPageItemIds[i]];
            gUnk_03000DDD++;
        }
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804DE8C);
u8 sub_804DF14(Unk_03000DEntry *dest)
{
    u8 count;
    u8 i;

    for (i = 0; i <= 15; i++)
    {
        dest[i].field_0 = 0;
        dest[i].field_1 = 0;
    }
    count = 0;
    for (i = 0; i < gUnk_03000DDC; i++)
    {
        if (gUnk_03000D88[i].field_1 != 0)
        {
            dest[count].field_0 = gUnk_03000D88[i].field_0;
            dest[count].field_1 = gUnk_03000D88[i].field_1;
            count++;
        }
    }
    return count;
}

void sub_804DF74(Unk_03000DEntry *entry, u8 *obj, u8 index)
{
    u8 i;
    u8 id;

    gUnk_03000DC8[index].field_0 = entry->field_0;
    gUnk_03000DC8[index].field_1 = entry->field_1;
    id = entry->field_0;
    obj[0xA4] = id;
    obj[0xBC] = 2;
    for (i = 0; i < gUnk_03000DDC; i++)
    {
        if (gUnk_03000D88[i].field_0 == entry->field_0)
        {
            gUnk_03000D88[i].field_1--;
            break;
        }
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_804DFD8);
INCLUDE_ASM("asm/nonmatchings", sub_804E0E4);
INCLUDE_ASM("asm/nonmatchings", sub_804E2AC);
INCLUDE_ASM("asm/nonmatchings", sub_804E6DC);
s8 sub_804E76C(u8 *obj, u8 arg1, u8 arg2)
{
    s8 result;
    u8 i;
    u8 *values;

    result = -1;
    if (obj[0xBE] <= 10)
    {
        values = obj + 0x8D;
        if (values[0] != 0 || values[1] != 0 ||
            values[2] != 0 || values[3] != 0 ||
            values[4] != 0 || values[5] != 0 ||
            values[6] != 0 || values[7] != 0)
        {
            for (i = 0; i <= 5; i++)
            {
                if (sub_804DD90(values[i], arg1) == arg2)
                {
                    result = i;
                    break;
                }
            }
        }
    }
    return result;
}
INCLUDE_ASM("asm/nonmatchings", sub_804E7EC);
INCLUDE_ASM("asm/nonmatchings", sub_804E85C);
INCLUDE_ASM("asm/nonmatchings", sub_804E9DC);
INCLUDE_ASM("asm/nonmatchings", sub_804EC04);
INCLUDE_ASM("asm/matchings", sub_804EEC4);
/*
extern u8 gUnk_03000DDD;

typedef struct 
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
}UnkStruct;
extern UnkStruct gUnk_03000D48[];

void sub_804EEC4(void)
{
    u8 i;

    for (i = 0; i < gUnk_03000DDD; i++)
    {
        gInventory[gUnk_03000D48[i].field_0] = gUnk_03000D48[i].field_1;
    }
}
*/
INCLUDE_ASM("asm/matchings", sub_804EF00);
/*
extern u8 gUnk_03000DDC;
extern u8 gUnk_03004980[];

typedef struct 
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
}UnkStruct;
extern UnkStruct gUnk_03000D88[];
extern UnkStruct gUnk_03000DC8[];

void sub_804EF00(u8 arg0) {
    
    u8 i;
    if(gUnk_03000DC8[arg0].field_0 == 0)
        return;

    for (i = 0; i < gUnk_03000DDC; i++)
    {
        if(gUnk_03000D88[i].field_0 == gUnk_03000DC8[arg0].field_0)
        {
            gUnk_03000D88[i].field_1 = gUnk_03000DC8[arg0].field_1;
        }
    }
}
*/
INCLUDE_ASM("asm/matchings", sub_804EF50);
/*
extern u8 gUnk_03000DDC;
extern u8 gUnk_03004980[];

typedef struct 
{
    u8 field_0;
    u8 field_1;
    u8 field_2;
    u8 field_3;
}UnkStruct;
extern UnkStruct gUnk_03000D88[];

void sub_804EF50(void) {
    u8 i;

    for (i = 0; i < gUnk_03000DDC; i++)
    {
        if(gUnk_03000D88[i].field_0 > 0xDC)
        {
            gUnk_03004980[gUnk_03000D88[i].field_0] = gUnk_03000D88[i].field_1;
        }
    }
}
*/
u8 sub_804EF90(u8 arg0)
{
    u8 i;
    u8 ret = 0xFF;

    for (i = 0; i < gUnk_03000DDC; i++)
    {
        if (gUnk_03000D88[i].field_0 == arg0)
        {
            ret = i;
            break;
        }
    }

    return ret;
}
INCLUDE_ASM("asm/nonmatchings", sub_804EFDC);
u8 sub_804F050(u8 arg0)
{
    u8 i;

    for (i = 0; i < 16; i++)
    {
        if (arg0 == gInvPageItemIds[i])
            break;
    }

    return i;
}
void sub_804F07C(void)
{
    gUnk_03000DDE = 0;
}
INCLUDE_ASM("asm/matchings", sub_804F088);
/*
u8 sub_804E2AC(u8*, u32);
u8 sub_804E0E4(u8*, u32);


u8 sub_804F088(u8* arg0, u32 arg1) {
    if (arg0[0xBE] > 0xAU) {
        return 2;
    }
    if ( arg0[0xA4] > 0xDCU) {
           return sub_804E0E4(arg0,arg1);
    
    } else {
         return sub_804E2AC(arg0,arg1);
    }
}
*/
