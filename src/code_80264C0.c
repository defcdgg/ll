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

// @ 0x080264C0
INCLUDE_ASM("asm/nonmatchings", sub_80264C0);
// @ 0x0802698C
INCLUDE_ASM("asm/nonmatchings", sub_802698C);
// @ 0x08026D08
INCLUDE_ASM("asm/nonmatchings", sub_8026D08);
// @ 0x08026F88
INCLUDE_ASM("asm/nonmatchings", sub_8026F88);
// @ 0x0802723C
INCLUDE_ASM("asm/nonmatchings", sub_802723C);
// @ 0x0802761C
INCLUDE_ASM("asm/nonmatchings", sub_802761C);
// @ 0x08027760
INCLUDE_ASM("asm/nonmatchings", sub_8027760);
// @ 0x08027A20
INCLUDE_ASM("asm/nonmatchings", sub_8027A20);
// @ 0x08027D9C
INCLUDE_ASM("asm/nonmatchings", sub_8027D9C);
// @ 0x08028098
INCLUDE_ASM("asm/nonmatchings", sub_8028098);
// @ 0x080282EC
INCLUDE_ASM("asm/nonmatchings", sub_80282EC);
// @ 0x080285A0
INCLUDE_ASM("asm/nonmatchings", sub_80285A0);
// @ 0x080287EC
INCLUDE_ASM("asm/nonmatchings", sub_80287EC);
// @ 0x08028AD8
INCLUDE_ASM("asm/nonmatchings", sub_8028AD8);
// @ 0x08029268
INCLUDE_ASM("asm/nonmatchings", sub_8029268);
// @ 0x08029510
INCLUDE_ASM("asm/nonmatchings", sub_8029510);
// @ 0x08029784
INCLUDE_ASM("asm/nonmatchings", sub_8029784);
// @ 0x080299C8
INCLUDE_ASM("asm/nonmatchings", sub_80299C8);
// @ 0x08029BF8
INCLUDE_ASM("asm/nonmatchings", sub_8029BF8);
// @ 0x0802A154
INCLUDE_ASM("asm/nonmatchings", sub_802A154);
// @ 0x0802A86C
INCLUDE_ASM("asm/nonmatchings", sub_802A86C);
// @ 0x0802ADC4
INCLUDE_ASM("asm/nonmatchings", sub_802ADC4);
// @ 0x0802B0F0
INCLUDE_ASM("asm/nonmatchings", sub_802B0F0);
// @ 0x0802B608
INCLUDE_ASM("asm/nonmatchings", sub_802B608);
// @ 0x0802B8BC
INCLUDE_ASM("asm/nonmatchings", sub_802B8BC);
// @ 0x0802BB24
INCLUDE_ASM("asm/nonmatchings", sub_802BB24);
// @ 0x0802BD94
INCLUDE_ASM("asm/nonmatchings", sub_802BD94);
// @ 0x0802C0EC
INCLUDE_ASM("asm/nonmatchings", sub_802C0EC);
// @ 0x0802C490
INCLUDE_ASM("asm/nonmatchings", sub_802C490);
// @ 0x0802C714
INCLUDE_ASM("asm/nonmatchings", sub_802C714);
// @ 0x0802C9E8
INCLUDE_ASM("asm/nonmatchings", sub_802C9E8);
// @ 0x0802CE90
INCLUDE_ASM("asm/nonmatchings", sub_802CE90);
// @ 0x0802D1FC
INCLUDE_ASM("asm/nonmatchings", sub_802D1FC);
// @ 0x0802D454
INCLUDE_ASM("asm/nonmatchings", sub_802D454);
// @ 0x0802D728
INCLUDE_ASM("asm/nonmatchings", sub_802D728);
// @ 0x0802DA78
INCLUDE_ASM("asm/nonmatchings", sub_802DA78);
// @ 0x0802DE04
INCLUDE_ASM("asm/nonmatchings", sub_802DE04);
// @ 0x0802DFDC
INCLUDE_ASM("asm/nonmatchings", sub_802DFDC);
// @ 0x0802E234
INCLUDE_ASM("asm/nonmatchings", sub_802E234);
// @ 0x0802E49C
INCLUDE_ASM("asm/nonmatchings", sub_802E49C);
// @ 0x0802E6C8
INCLUDE_ASM("asm/nonmatchings", sub_802E6C8);
// @ 0x0802EAC4
INCLUDE_ASM("asm/nonmatchings", sub_802EAC4);
// @ 0x0802EDD8
INCLUDE_ASM("asm/nonmatchings", sub_802EDD8);
// @ 0x0802F100
INCLUDE_ASM("asm/nonmatchings", sub_802F100);
// @ 0x0802F480
INCLUDE_ASM("asm/nonmatchings", sub_802F480);
// @ 0x0802F6D8
INCLUDE_ASM("asm/nonmatchings", sub_802F6D8);
// @ 0x0802F9EC
INCLUDE_ASM("asm/nonmatchings", sub_802F9EC);
// @ 0x0802FE98
INCLUDE_ASM("asm/nonmatchings", sub_802FE98);
// @ 0x0803029C
INCLUDE_ASM("asm/nonmatchings", sub_803029C);
// @ 0x08030664
INCLUDE_ASM("asm/nonmatchings", sub_8030664);
// @ 0x080309B0
INCLUDE_ASM("asm/nonmatchings", sub_80309B0);
// @ 0x08030C08
INCLUDE_ASM("asm/nonmatchings", sub_8030C08);
// @ 0x08030D9C
INCLUDE_ASM("asm/nonmatchings", sub_8030D9C);
// @ 0x08030F30
INCLUDE_ASM("asm/nonmatchings", sub_8030F30);
// @ 0x080310C4
INCLUDE_ASM("asm/nonmatchings", sub_80310C4);
// @ 0x08031258
INCLUDE_ASM("asm/nonmatchings", sub_8031258);
// @ 0x080313EC
INCLUDE_ASM("asm/nonmatchings", sub_80313EC);
// @ 0x08031580
INCLUDE_ASM("asm/nonmatchings", sub_8031580);
// @ 0x08031714
INCLUDE_ASM("asm/nonmatchings", sub_8031714);
// @ 0x080318A8
INCLUDE_ASM("asm/nonmatchings", sub_80318A8);
// @ 0x08031A3C
INCLUDE_ASM("asm/nonmatchings", sub_8031A3C);
// @ 0x08031BD0
INCLUDE_ASM("asm/nonmatchings", sub_8031BD0);
// @ 0x08031D64
INCLUDE_ASM("asm/nonmatchings", sub_8031D64);
// @ 0x08031EF8
INCLUDE_ASM("asm/nonmatchings", sub_8031EF8);
// @ 0x0803208C
INCLUDE_ASM("asm/nonmatchings", sub_803208C);
// @ 0x08032220
INCLUDE_ASM("asm/nonmatchings", sub_8032220);
// @ 0x080323B4
INCLUDE_ASM("asm/nonmatchings", sub_80323B4);
// @ 0x08032548
INCLUDE_ASM("asm/nonmatchings", sub_8032548);
// @ 0x0803272C
INCLUDE_ASM("asm/nonmatchings", sub_803272C);
// @ 0x08032948
INCLUDE_ASM("asm/nonmatchings", sub_8032948);
// @ 0x08032D74
INCLUDE_ASM("asm/nonmatchings", sub_8032D74);
// @ 0x08032EA0
INCLUDE_ASM("asm/nonmatchings", sub_8032EA0);
// @ 0x080334B8
INCLUDE_ASM("asm/nonmatchings", sub_80334B8);
// @ 0x08033988
INCLUDE_ASM("asm/nonmatchings", sub_8033988);
// @ 0x08033E2C
INCLUDE_ASM("asm/nonmatchings", sub_8033E2C);
// @ 0x08034440
INCLUDE_ASM("asm/nonmatchings", sub_8034440);
// @ 0x080345AC
INCLUDE_ASM("asm/nonmatchings", sub_80345AC);
// @ 0x08034718
INCLUDE_ASM("asm/nonmatchings", sub_8034718);
// @ 0x080348A8
INCLUDE_ASM("asm/nonmatchings", sub_80348A8);
// @ 0x08034BFC
INCLUDE_ASM("asm/nonmatchings", sub_8034BFC);
// @ 0x08034D94
INCLUDE_ASM("asm/nonmatchings", sub_8034D94);
// @ 0x08034F00
INCLUDE_ASM("asm/nonmatchings", sub_8034F00);
// @ 0x08035130
INCLUDE_ASM("asm/nonmatchings", sub_8035130);
// @ 0x08035360
INCLUDE_ASM("asm/nonmatchings", sub_8035360);
// @ 0x0803586C
INCLUDE_ASM("asm/nonmatchings", sub_803586C);
// @ 0x08035B04
INCLUDE_ASM("asm/nonmatchings", sub_8035B04);
// @ 0x08035D9C
INCLUDE_ASM("asm/nonmatchings", sub_8035D9C);
// @ 0x08036034
INCLUDE_ASM("asm/nonmatchings", sub_8036034);
// @ 0x080362CC
INCLUDE_ASM("asm/nonmatchings", sub_80362CC);
// @ 0x08036564
INCLUDE_ASM("asm/nonmatchings", sub_8036564);
// @ 0x080368FC
INCLUDE_ASM("asm/nonmatchings", sub_80368FC);
// @ 0x08036B30
INCLUDE_ASM("asm/nonmatchings", sub_8036B30);
// @ 0x08036EA4
INCLUDE_ASM("asm/nonmatchings", sub_8036EA4);
// @ 0x08037078
INCLUDE_ASM("asm/nonmatchings", sub_8037078);
// @ 0x08037388
INCLUDE_ASM("asm/nonmatchings", sub_8037388);
// @ 0x08037868
INCLUDE_ASM("asm/nonmatchings", sub_8037868);
// @ 0x08037C40
INCLUDE_ASM("asm/nonmatchings", sub_8037C40);
// @ 0x08037E14
INCLUDE_ASM("asm/nonmatchings", sub_8037E14);
// @ 0x08037FE8
INCLUDE_ASM("asm/nonmatchings", sub_8037FE8);
// @ 0x080381BC
INCLUDE_ASM("asm/nonmatchings", sub_80381BC);
// @ 0x08038390
INCLUDE_ASM("asm/nonmatchings", sub_8038390);
// @ 0x08038568
INCLUDE_ASM("asm/nonmatchings", sub_8038568);
// @ 0x0803874C
INCLUDE_ASM("asm/nonmatchings", sub_803874C);
// @ 0x08038920
INCLUDE_ASM("asm/nonmatchings", sub_8038920);
// @ 0x08038C84
INCLUDE_ASM("asm/nonmatchings", sub_8038C84);
// @ 0x08038E44
INCLUDE_ASM("asm/nonmatchings", sub_8038E44);
// @ 0x08039024
INCLUDE_ASM("asm/nonmatchings", sub_8039024);
// @ 0x080392C0
INCLUDE_ASM("asm/nonmatchings", sub_80392C0);
// @ 0x080393E0
INCLUDE_ASM("asm/nonmatchings", sub_80393E0);
// @ 0x08039724
INCLUDE_ASM("asm/nonmatchings", sub_8039724);
// @ 0x08039C38
INCLUDE_ASM("asm/nonmatchings", sub_8039C38);
// @ 0x0803A478
INCLUDE_ASM("asm/nonmatchings", sub_803A478);
// @ 0x0803A8D0
INCLUDE_ASM("asm/nonmatchings", sub_803A8D0);
// @ 0x0803AF60
INCLUDE_ASM("asm/nonmatchings", sub_803AF60);
// @ 0x0803B484
INCLUDE_ASM("asm/nonmatchings", sub_803B484);
// @ 0x0803BBEC
INCLUDE_ASM("asm/nonmatchings", sub_803BBEC);
// @ 0x0803C328
INCLUDE_ASM("asm/nonmatchings", sub_803C328);
// @ 0x0803CE0C
INCLUDE_ASM("asm/nonmatchings", sub_803CE0C);
// @ 0x0803D20C
INCLUDE_ASM("asm/nonmatchings", sub_803D20C);
// @ 0x0803D60C
INCLUDE_ASM("asm/nonmatchings", sub_803D60C);
// @ 0x0803DECC
INCLUDE_ASM("asm/nonmatchings", sub_803DECC);
// @ 0x0803E58C
INCLUDE_ASM("asm/nonmatchings", sub_803E58C);
// @ 0x0803ED34
INCLUDE_ASM("asm/nonmatchings", sub_803ED34);
// @ 0x0803F21C
INCLUDE_ASM("asm/nonmatchings", sub_803F21C);
// @ 0x0803F328
INCLUDE_ASM("asm/nonmatchings", sub_803F328);
// @ 0x0803F444
INCLUDE_ASM("asm/nonmatchings", sub_803F444);
// @ 0x0803F5B4
void sub_803F5B4(u8 *obj)
{
    u32 pool;
    u8 i;
    u8 *buf;
    u32 result;

    pool = GetObjPool();
    sub_8020DF0(obj);
    gUnk_0300083D = sub_8020E5C();
    buf = (u8 *)sub_8020E54();
    gUnk_03000840 = buf;
    gUnk_03000858 = 0;
    for (i = 0; i < gUnk_0300083D; i++)
    {
        if ((gUnk_03000840[i] & 0xF0) == 0x10)
        {
            result = sub_804473C(obj, pool + (gUnk_03000840[i] & 0xF) * 0xC8);
            result += *(u16 *)(pool + (gUnk_03000840[i] & 0xF) * 0xC8 + 0xB2);
            *(u16 *)(pool + (gUnk_03000840[i] & 0xF) * 0xC8 + 0xB2) = result;
            gUnk_03000858++;
        }
    }
}
// @ 0x0803F658
INCLUDE_ASM("asm/nonmatchings", sub_803F658);
// @ 0x0803FF54
INCLUDE_ASM("asm/nonmatchings", sub_803FF54);
// @ 0x080401AC
INCLUDE_ASM("asm/nonmatchings", sub_80401AC);
// @ 0x080405A4
u8 sub_80405A4(u8 *obj)
{
    u8 result;

    result = 0;
    switch (gUnk_03000820)
    {
    case 0:
        gUnk_03000824 = obj[0x35];
        gUnk_03000822 = *(u16 *)(obj + 0x2A);
        gUnk_03000828 = obj[0xBF];
        gUnk_03000829 = obj[0xC0];
        gUnk_03000825 = 0;
        if (((u32 (*)(void))Rng_LcgNext)() % 0x64 <= 0x45 && (sub_80187B4() & 0x220) == 0)
        {
            u16 f2a = *(u16 *)(obj + 0x24) | 0x20;
            *(u16 *)(obj + 0x24) = f2a;
            gUnk_03000820 = 2;
        }
        else
        {
            gUnk_03000820 = 9;
        }
        break;
    case 2:
        if (gUnk_03000825 <= 0x13)
        {
            obj[0xBF] = sub_801768C(gUnk_03000828, -gUnk_03000828, 0x14, gUnk_03000825, gUnk_03000820);
            gUnk_03000825 += 1;
        }
        else
        {
            sub_80207A4();
            obj[0xBE] = 0xFF;
            obj[0xAB] = 7;
            gUnk_03000820 = 9;
        }
        break;
    case 9:
        result = 2;
        break;
    }
    return result;
}
// @ 0x08040690
INCLUDE_ASM("asm/nonmatchings", sub_8040690);
// @ 0x08040EE8
INCLUDE_ASM("asm/nonmatchings", sub_8040EE8);
// @ 0x08041308
INCLUDE_ASM("asm/nonmatchings", sub_8041308);
// @ 0x080416F0
INCLUDE_ASM("asm/nonmatchings", sub_80416F0);
// @ 0x080419E0
INCLUDE_ASM("asm/nonmatchings", sub_80419E0);
// @ 0x08041EDC
INCLUDE_ASM("asm/nonmatchings", sub_8041EDC);
// @ 0x08042200
u8 sub_8042200(u8 *obj)
{
    u8 result;

    result = 0;
    switch (gUnk_03000820)
    {
    case 0:
        gUnk_03000824 = obj[0x35];
        gUnk_03000822 = *(u16 *)(obj + 0x2A);
        sub_801CA08(obj, 3, 0x1B4, 0xD, result);
        gUnk_03000820 = 2;
        break;
    case 2:
        if (*(u16 *)(obj + 0x24) & 0x1000)
        {
            sub_804C3A4(obj[0x35], sub_801B954((void **)(obj + 0xC)));
            *(u16 *)(obj + 0x24) &= 0xEFFF;
            sub_80207DC(obj, obj[0xBF], obj[0xC0], gUnk_03000822, gUnk_03000824);
            gUnk_03000820 = 9;
        }
        break;
    case 9:
        result = 2;
        break;
    }
    return result;
}
// @ 0x080422B8
INCLUDE_ASM("asm/nonmatchings", sub_80422B8);
// @ 0x08042784
INCLUDE_ASM("asm/nonmatchings", sub_8042784);
// @ 0x08042AB4
u8 sub_8042AB4(u8 *obj)
{
    u8 result;

    result = 0;
    switch (gUnk_03000820)
    {
    case 0:
        gUnk_03000824 = obj[0x35];
        gUnk_03000822 = *(u16 *)(obj + 0x2A);
        gUnk_03000828 = obj[0xBF];
        gUnk_03000829 = obj[0xC0];
        gUnk_03000825 = 0;
        if ((sub_80187B4() & 0x200) == 0)
        {
            u16 f2a = *(u16 *)(obj + 0x24) | 0x20;
            *(u16 *)(obj + 0x24) = f2a;
            gUnk_03000820 = 2;
        }
        else
        {
            gUnk_03000820 = 0x12;
        }
        break;
    case 2:
        if (gUnk_03000825 <= 0x13)
        {
            obj[0xBF] = sub_801768C(gUnk_03000828, -gUnk_03000828, 0x14, gUnk_03000825, gUnk_03000820);
            gUnk_03000825 += 1;
        }
        else
        {
            gUnk_03000820 = 9;
        }
        break;
    case 9:
        sub_80207A4();
        obj[0xAB] = 7;
        obj[0xBE] = 0xFF;
        result = 2;
        break;
    case 0x12:
        result = 2;
        break;
    }
    return result;
}
// @ 0x08042B90
INCLUDE_ASM("asm/nonmatchings", sub_8042B90);
// @ 0x08042E70
INCLUDE_ASM("asm/nonmatchings", sub_8042E70);
// @ 0x08043554
INCLUDE_ASM("asm/nonmatchings", sub_8043554);
// @ 0x08043938
INCLUDE_ASM("asm/nonmatchings", sub_8043938);
// @ 0x08043B5C
INCLUDE_ASM("asm/nonmatchings", sub_8043B5C);
// @ 0x08043F90
INCLUDE_ASM("asm/nonmatchings", sub_8043F90);
