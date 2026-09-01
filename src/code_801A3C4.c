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

INCLUDE_ASM("asm/nonmatchings", sub_801A3C4);
INCLUDE_ASM("asm/nonmatchings", sub_801A5EC);
void sub_801A684(u8 *arg0)
{
    u32 data;
    u32 off0;
    u32 off1;
    u16 type;
    u32 ptr14;
    u8 b29;
    u8 zero8;
    u16 zero16;
    u8 copied;

    do
    {
        data = *(u32 *)(arg0 + 0x10);
        off0 = data + *(u16 *)data;
        *(u32 *)(arg0 + 0) = off0;
        off1 = data + *(u16 *)(data + 2);
        *(u32 *)(arg0 + 4) = off1;
        *(u32 *)(arg0 + 8) = off0 + 4;
        *(u32 *)(arg0 + 0xC) = off1 + 4;

        // Keep GCC2's byte zero ahead of the independent halfword zero.
        zero8 = off0 & ~off0;
        zero16 = 0;
        *(u16 *)(arg0 + 0x1A) = zero16;
        *(u16 *)(arg0 + 0x1C) = zero16;
        *(u16 *)(arg0 + 0x1E) = *(u16 *)(arg0 + 0x24);
        copied = *(u8 *)(arg0 + 0x2F);
        *(u8 *)(arg0 + 0x29) = copied;
        *(u8 *)(arg0 + 0x28) = zero8;
    } while (0);

    type = (*(u16 *)(arg0 + 0x18) & 0xF) - 6;
    if (type <= 2)
    {
        sub_801A6F4(arg0);
    }
    else
    {
        ptr14 = *(u32 *)(arg0 + 0x14);
        b29 = *(u8 *)(arg0 + 0x29);
        sub_804C2FC(ptr14, b29, sub_801B954((void **)arg0));
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_801A6F4);
INCLUDE_ASM("asm/nonmatchings", sub_801A884);
INCLUDE_ASM("asm/nonmatchings", sub_801AD0C);
INCLUDE_ASM("asm/nonmatchings", sub_801B0B8);
INCLUDE_ASM("asm/nonmatchings", sub_801B570);

INCLUDE_ASM("asm/matchings", sub_801B688);

void sub_801B760(u16 arg0)
{
    if (sub_801B790(arg0) != 0)
    {
        return;
    }
    gObjFlagsA[arg0/8] |= (1 << (arg0 % 8));
}

u8 sub_801B790(u16 arg0)
{
    if ((gObjFlagsA[arg0 / 8] >> (arg0 % 8 )) & 1) return 1;
    return 0;
}
void sub_801B7B8(void)
{
    DmaFill32(3, 0, gObjFlagsA, 0x80);
    DmaWait(3);

    DmaFill32(3, 0, gObjFlagsB, 0x80);
    DmaWait(3);
}
typedef struct Unk_801B81C
{
    u8 pad_00[0x10];
    u32 field_10;
    u32 field_14;
    u16 field_18;
    u8 pad_1A[2];
    u16 field_1C;
    u8 pad_1E[2];
    u16 field_20;
    u16 field_22;
    u16 field_24;
    u16 field_26;
    u8 pad_28[3];
    u8 field_2B;
    u8 field_2C;
    u8 pad_2D[2];
    u8 field_2F;
} Unk_801B81C;

void sub_801B81C(u8 *arg0, u8 arg1, u8 arg2, u16 arg3, u8 arg4,
                 u32 arg5, u32 arg6, u16 arg7, u16 arg8, u16 arg9)
{
    Unk_801B81C *obj = (Unk_801B81C *)arg0;
    u16 value;

    obj->field_14 = arg6;
    value = arg9;
    obj->field_18 = value | 0x800;
    obj->field_26 = arg7;
    obj->field_10 = arg5;
    // This redundant write is required for the original GCC2 scheduling.
    obj->field_14 = arg6;
    obj->field_20 = arg8;
    obj->field_24 = arg3;
    obj->field_2F = arg4;
    obj->field_22 = 0;
    obj->field_1C = 0;
    obj->field_2B = arg1;
    obj->field_2C = arg2;
}

u8 sub_801B878(u8 *arg0, u8 arg1, u8 *arg2)
{
    s16 kind;

    kind = *(u16 *)(arg0 + 0x18) & 0xF;
    switch (kind)
    {
    case 6:
    case 7:
    case 8:
        sub_801AD0C(arg0);
        return arg1;
    default:
        return sub_801A884(arg0, arg1, arg2);
    }
}
u8 sub_801B8AC(u8 *arg0, u8 arg1)
{
    s16 kind;

    kind = *(u16 *)(arg0 + 0x18) & 0xF;
    switch (kind)
    {
    case 6:
        sub_801B570(arg0);
        return arg1;
    case 7:
    case 8:
        return arg1;
    default:
        return sub_801B0B8(arg0, arg1);
    }
}
u16 *sub_801B8E8(u16 *ptr, u16 value)
{
    u16 *current = (u16 *)((u8 *)ptr + 2);

    while (*(current + 1) <= value)
    {
        current += 2;
    }
    return current;
}
u16 *sub_801B8FC(u8 *arg0, u8 arg1, u16 arg2)
{
    u16 *current;
    u32 val;

    val = *(u16 *)(arg1 * 2 + *(u32 *)(arg0 + 0xC));
    current = (u16 *)(*(u32 *)(arg0 + 4) + val + 2);
    while (*(current + 1) <= arg2)
    {
        current += 2;
    }
    return current;
}
void sub_801B920(void)
{
    u8 i;

    GameOamData *oamPtr;
    Unk_030034C0 *srcPtr;

    oamPtr = &gOamBuffer[0];
    srcPtr = gOamAffineBuf;

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
void sub_801D12C(u8 *obj, u8 state)
{
    s16 value;

    if (obj[0xBE] <= 0xA)
    {
        switch (state)
        {
        case 0:
        case 1:
        case 2:
            value = obj[0xAB];
            switch (value)
            {
            case 0:
                if (*(u16 *)(obj + 0x6C) == *(u16 *)(obj + 0x6E))
                    state = 3;
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                state = 1;
                break;
            case 8:
                state = 2;
                break;
            }
            break;
        case 4:
            break;
        case 5:
            value = obj[0xAB];
            switch (value)
            {
            case 0:
                break;
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                state = 1;
                break;
            case 8:
                state = 2;
                break;
            }
            break;
        }
        obj[0xA2] = state;
    }
}
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
typedef struct Unk_8021064 {
    u16 field_0;
    u8 field_2;
    u8 field_3;
} Unk_8021064;

extern Unk_8021064 gUnk_03000670[];
extern u8 gUnk_0861C664[];
extern u8 gUnk_03000730_arr[]; // gUnk_03000730 的字节视图

void sub_801DE44(void)
{
    u8 i;
    u8 j;
    u8 flag;
    u32 ptr;

    gUnk_0300068C = 0;
    gUnk_0300068E = 1;
    gUnk_0300068D = 0;
    for (i = 0; i < 7; i++)
    {
        gUnk_03000670[i].field_0 = 0;
        gUnk_03000670[i].field_2 = 0;
        gUnk_03000670[i].field_3 = 0;
    }
    sub_804C2FC((u32)gUnk_0861C664, 0xF, 1);
    ptr = GetObjPool();
    for (j = 0; j < gUnk_0300073D; j++)
    {
        flag = 0;
        if ((gUnk_03000730_arr[j] & 0xF0) == 0)
            flag = 1;
        sub_801D710(ptr + (gUnk_03000730_arr[j] & 0xF) * 0xC8, flag);
    }
}
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

INCLUDE_ASM("asm/matchings", sub_80207B4);
// u8 sub_80207B4(void *arg0)
// {
//     if ((sub_80187B4() & 0x20))
//     {
//         return sub_801BE34(arg0);
//     }

//     return sub_801C484(arg0);
// }

/* 场景对象按 field_BE 分发到三种行为: ≤0xA → sub_801CBA4, ≤0x70 → sub_801CA08,
 * 其余 (field_BE-0x71 ≤ 0x8D) → sub_801CE80; 均传 (obj, 0, f2a, f35, 0)。 */
void sub_80207DC(u8 *obj, u8 bf, u8 c0, u16 f2a, u8 f35)
{
    if (obj[0xBE] <= 0xA)
        sub_801CBA4(obj, 0, f2a, f35, 0);
    else if (obj[0xBE] <= 0x70)
        sub_801CA08(obj, 0, f2a, f35, 0);
    else if ((u8)(obj[0xBE] - 0x71) <= 0x8D)
        sub_801CE80(obj, 0, f2a, f35, 0);
}

INCLUDE_ASM("asm/nonmatchings", sub_8020840);
INCLUDE_ASM("asm/nonmatchings", sub_80208A4);
INCLUDE_ASM("asm/matchings", sub_8020914);
void sub_802093C(u8 *arg0)
{
    u8 *ptr;
    u8 *addr;
    u8 new_var;
    s8 val;

    if (arg0[0xBE] > 0xB)
    {
        ptr = *(u8 **)(arg0 + 0x88);
        val = *(s8 *)(arg0 + 0xBC);
        switch (val)
        {
        case 0:
            addr = ptr + 0x23;
            break;
        case 1:
            addr = ptr + 0x24;
            break;
        default:
            return;
        }
        new_var = *addr;
        arg0[0xC3] = new_var;
    }
}
typedef struct Unk_08393B28 {
    u32 field_0;
    u32 field_4;
    u16 field_8;
    u16 field_A;
    u8 pad_B[8];
} Unk_08393B28;

extern Unk_08393B28 gUnk_08393B28[];

void sub_8020974(u8 *arg0, u16 arg1, u16 arg2, u8 arg3, u16 arg4)
{
    Unk_08393B28 *entry = &gUnk_08393B28[arg1];

    sub_801B81C(arg0, arg0[0x2B], arg0[0x2C], arg2, arg3,
                entry->field_0, entry->field_4, entry->field_8, entry->field_A, arg4);
}

INCLUDE_ASM("asm/matchings", sub_80209C8);
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

typedef struct {
    u8 pad0[0x88];
    u16 unk_88;
    u8 pad1[0xB0 - 0x88 - 2];
    u16 unk_B0;
    u8 pad2[0xBE - 0xB0 - 2];
    u8 unk_BE;
} MyStruct;

void sub_80209EC(MyStruct *ptr) {
    if (ptr->unk_BE <= 6) {
        ptr->unk_88 = 0;
        ptr->unk_B0 |= 2;
    }
}
typedef struct Unk_0839B2A4 {
    u32 field_0;
    u32 field_4;
    u16 field_8;
    u16 field_A;
    u8 pad_B[8];
} Unk_0839B2A4;

extern Unk_0839B2A4 gUnk_0839B2A4[];

void sub_8020A0C(void *arg0, u8 arg1) {
    u16 newval;
    Unk_0839B2A4 *tbl = gUnk_0839B2A4;
    sub_801B81C((u8 *)arg0 + 0x3C,
                *(u8 *)((u8 *)arg0 + 0xBF),
                *(u8 *)((u8 *)arg0 + 0xC0),
                0xDA << 1,
                0xE,
                tbl[0].field_0,
                tbl[0].field_4 + (arg1 << 5),
                (u16)(0x541 + tbl[0].field_8),
                tbl[0].field_A,
                2);
    *(u8 *)((u8 *)arg0 + 0x66) = 3;
    newval = 0x2000 | *(u16 *)((u8 *)arg0 + 0xB0);
    *(u16 *)((u8 *)arg0 + 0xB0) = newval;
}
u8 sub_8020A7C(u8 *arg0)
{
    u8 i;
    u8 ret;

    ret = 1;
    for (i = 0; i <= 4; i++)
    {
        if (sub_8045F10(arg0 + i * 0xC8, 0x114) == 1)
        {
            ret = 0;
        }
    }

    return ret;
}
u8 sub_8020AB0(void)
{
    u8 buf[8];
    u8 ret;

    ret = sub_80489E8((u8 *)GetObjPool(), buf, 0, 0x6B);
    if (sub_8044498() == 0)
    {
        return 1;
    }
    return ret != 0;
}

typedef struct Unk_8020AE4_node {
    u8 field_0;
    u8 pad_1[7];
    struct Unk_8020AE4_node *field_8;
    u32 field_C;
} Unk_8020AE4_node;

typedef struct Unk_03000690 {
    u32 field_0;
    u32 field_4;
    Unk_8020AE4_node *field_8;
} Unk_03000690;

void sub_8020AE4(void) {
    Unk_8020AE4_node *node = ((Unk_03000690 *)0x03000690)->field_8;
    while (node->field_0 <= 0xFE) {
        (*(u16 *)(node->field_C + 0xB2))++;
        node = node->field_8;
    }
}
void sub_8020B04(u8 *arg0) {
    u8 ids[12];
    u8 i;
    u32 base = GetObjPool();
    u8 count = sub_80462E4(arg0, ids, 0x7F);
    for (i = 0; i < count; i++) {
        sub_801D568(base + ids[i] * 0xC8);
    }
}
/*
extern u8 sub_80462E4(void *, u8 *, u8);
extern void sub_801D568(void *);

void sub_8020B04(void *arg0)
{
    u8 buf[12];
    u8 count;
    u8 i;
    u8 *base;

    base = (u8 *)GetObjPool();
    count = sub_80462E4(arg0, buf, 0x7F);
    for (i = 0; i < count; i++)
    {
        sub_801D568(base + buf[i] * 0xC8);
    }
}
*/
u32 sub_8020B48(void)
{
    return gUnk_03000718;
}
INCLUDE_ASM("asm/nonmatchings", sub_8020B54);
void sub_8020B90(u8 *arg0) {
    gUnk_030006F8[gUnk_03000714] = arg0;
    gUnk_03000714++;
    if (arg0[0xBE] > 0xB) {
        gUnk_03000718 = (u32)arg0;
    }
}

u8 sub_8020BC0(u8 *arg0) {
    s32 diff;
    u16 *ptr;

    ptr = (u16 *)(arg0 + 0x6C);
    diff = *(s16 *)(arg0 + 0x6C) - *(s16 *)(arg0 + 0xB2);
    if (diff <= 0) {
        *ptr = 0;
        return 1;
    }
    *ptr -= *(u16 *)(arg0 + 0xB2);
    return 0;
}

u8 sub_8020BF0(u8 *arg0) {
    u8 value;

    value = gUnk_030006F8[0][0xBE];
    if ((u8)(value - 0xB) <= 0x65) {
        return sub_801E848();
    }
    if ((u8)(value - 0x71) <= 0x8D) {
        return sub_8020C2C();
    }
}
typedef u8 (*UnkFunc20C2C)(u8 *);
extern UnkFunc20C2C gUnk_0839CE7C[];

u8 sub_8020C2C(void) {
    return gUnk_0839CE7C[*(u8 *)(gUnk_030006F8[0] + 0xBE) - 0x71](gUnk_030006F8[0]);
}

void sub_8020C58(u8 *entries, u32 arg1) {
    u8 count = *(u8 *)gUnk_0300062C;
    u8 i;
    for (i = 0; i < count; i++) {
        u8 *entry = (u8 *)(i * 0xC8 + (u32)entries);
        if (*(u8 *)(entry + 0xBE) == 0xFF) continue;
        if (*(u16 *)(entry + 0xB0) == 8 || *(u16 *)(entry + 0xB0) == 5) continue;
        if (!(sub_80187B4() & 0x20))
            sub_804CEE0(entry, arg1);
        else
            sub_804DD70(entry, arg1);
    }
}

void sub_8020CC4(void *arg0, u8 arg1, u8 arg2, u16 arg3, u8 arg4, u16 arg5, u16 arg6) {
    u16 newval;
    sub_801B81C((u8 *)arg0 + 0x3C, arg1, arg2, arg3, arg4,
                gUnk_08393B28[arg5].field_0, gUnk_08393B28[arg5].field_4,
                gUnk_08393B28[arg5].field_8, gUnk_08393B28[arg5].field_A, arg6);
    newval = 0x2000 | *(u16 *)((u8 *)arg0 + 0xB0);
    *(u16 *)((u8 *)arg0 + 0xB0) = newval;
}
