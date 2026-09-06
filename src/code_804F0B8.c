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

// 检查对象 arg0 的两个候选编号(+0x91 / +0x92) 哪个通过 sub_804DD90(id, 6)。
// 仅当 arg1 截断到 u8 后恰好为 6 时才检查; 返回 1=前一个 / 2=后一个 / 0=都不行。
// 注: 全 ROM 无任何调用点(死代码), 两个已知引用位置都是直接 bl 不传参。
// 注: 两处 do {} while(0) 都是 GCC2 调度/分配屏障, 缺一不可(去掉分别差 48 / 7 字节);
//     `arg1 = (u8)arg1;` 必须显式写且参数声明为 s32 —— 若参数声明 u8,
//     GCC2 会把 `arg1 < 0` 当恒假折叠掉(少两条指令)。
// @ 0x0804F0B8
u8 sub_804F0B8(u8 *arg0, s32 arg1)
{
    u8 ret;
    u8 a;
    u8 b;

    arg1 = (u8)arg1;
    ret = 0;
    a = arg0[0x91];
    b = arg0[0x92];
    do
    {
        if (a == 0 && b == 0)
            return 0;
    } while (0);
    do
    {
        if (arg1 < 0)
            return ret;
        if (arg1 <= 5)
            return ret;
        if (arg1 != 6)
            return ret;
    } while (0);
    if ((u8)sub_804DD90(a, 6) != 0)
        ret = 1;
    else if ((u8)sub_804DD90(b, 6) != 0)
        ret = 2;
    return ret;
}
// @ 0x0804F10C
// 在 GetObjPool 的空闲槽里找第一个能命中 sub_804E76C(slot, arg0, arg1) 的槽,
// 返回其内部匹配下标 (0..5), 找不到返回 -1。sub_80489E8 先筛出通过
// sub_8045F10(slot, 0x1FF)==2 的槽下标 (0..4) 填进 values。
// 注: 需要 `int idx` 与 `s8 tmp` 两个中间变量才能复现 GCC2 的调度
// (idx 把乘 0xC8 提前; tmp = result 使截断 lsls/lsrs 排在 cmp 之前)。
s8 sub_804F10C(u8 arg0, u8 arg1)
{
    u8 i;
    u8 count;
    int idx;
    u8 values[5];
    s8 result;
    s8 found;
    s8 tmp;
    u8 *pool;

    found = -1;
    pool = (u8 *)GetObjPool();
    count = sub_80489E8(pool, values, 0, 0x1FF);
    for (i = 0; i < count; i++)
    {
        idx = values[i] * 0xC8;
        result = sub_804E76C(pool + idx, arg0, arg1);
        tmp = result;
        if (tmp >= 0)
        {
            found = result;
            break;
        }
    }
    return found;
}
// @ 0x0804F17C
// 在 GetObjPool 空闲槽中找所有通过 sub_804E76C(slot, arg1, arg2) 的槽,
// 把槽下标写入 arg0[0..found-1], 返回命中数量。
// 注: 用 r8/r9/sl 三个高位寄存器, 有 GCC2 泄漏风险。
u8 sub_804F17C(u8 *arg0, u8 arg1, u8 arg2)
{
    u8 i;
    u8 found;
    u8 count;
    u8 slots[5];
    u8 *pool;

    for (i = 0; i <= 4; i++)
        arg0[i] = 0;
    pool = (u8 *)GetObjPool();
    count = sub_80489E8(pool, slots, 0, 0x1FF);
    found = 0;
    for (i = 0; i < count; i++)
    {
        if (sub_804E76C(pool + slots[i] * 0xC8, arg1, arg2) >= 0)
        {
            arg0[found] = slots[i];
            found++;
        }
    }
    return found;
}
// INCLUDE_ASM("asm/nonmatchings", SioBattle_ResetState);
// @ 0x0804F210
void SioBattle_ResetState(void)
{
    u8 i;

    for (i = 0; i <= 4; i++)
    {
        gUnk_03000DF0[i] = 0;
    }

    gUnk_03000E04 = 0;
    gUnk_03000E05 = 0;
}
// @ 0x0804F244
u8 SioBattle_GetState()
{
    return gUnk_03000E04;
}
// @ 0x0804F250
void SioBattle_ClearSlots(void)
{
    u8 i;

    for (i = 0; i <= 9; i++)
    {
        gUnk_03000E08[i].field_0 = 0;
        gUnk_03000E08[i].field_2 = 0;
    }

    gUnk_03000E30 = 0;
}
// @ 0x0804F280
INCLUDE_ASM("asm/nonmatchings", sub_804F280);
// @ 0x0804F64C
INCLUDE_ASM("asm/nonmatchings", sub_804F64C);
// @ 0x0804F768
u32 Op_RemovePartyMember(u32 *ptr)
{
    u8 *data;
    u16 i;
    u8 temp;

    data = (u8 *)*ptr;
    for (i = 0; i <= 4; i++)
    {
        if (gPartyMemberIds[i] == data[1])
        {
            gPartyMemberIds[i] = 0xFF;
            for (; i <= 4; i++)
            {
                temp = gPartyMemberIds[i];
                gPartyMemberIds[i] = gPartyMemberIds[i + 1];
                gPartyMemberIds[i + 1] = temp;
            }
            break;
        }
    }

    for (i = 0; i <= 4; i++)
    {
        if (gBattleFormationIds[i] == data[1])
        {
            gBattleFormationIds[i] = 0xFF;
            break;
        }
    }

    *ptr += 2;
    return 1;
}
// @ 0x0804F7F8
// 脚本 opcode: 队伍添加 (Op_RemovePartyMember 的镜像)。
//   1) 把 data[1] 按升序插入 gPartyMemberIds[0..4] (已存在则跳过; 插入点后整体后移, 末位溢出丢弃);
//   2) Chara_ClearTempStatus(data[1]); gPartyMemberIds[5] = 0xFF;
//   3) 编队槽: 取 gPartyStats[id-1].field_unk[5] 记录的旧槽,
//      旧槽为空(0xFF) → 直接占回; 否则先查该 id 是否已在 gBattleFormationIds (在 → 仅回填槽号),
//      再找首个空槽(0xFF) → 写入 id 并回填槽号; 全满 → 不动。
u32 Op_AddPartyMember(u32 *ptr)
{
    u8 *data;
    u8 i;
    u8 temp;
    u8 val;
    u8 memberId;
    u8 newId;
    u8 idx;

    data = (u8 *)*ptr;
    i = 0;
    if (gPartyMemberIds[0] == data[1])
        goto after;
    do
    {
        // 死赋值(下一次迭代即被覆盖): 拉长 newId 伪寄存器寿命, 使全局分配把 ptr 给 r6、
        // newId 给 r7 (缺则 ptr 落 r7、stats 基址溢出从 ip 变 r7, 差 2 条指令)。
        newId = gPartyMemberIds[i];
        if (gPartyMemberIds[i] > data[1])
        {
            val = data[1];
            for (; i <= 4; i++)
            {
                temp = gPartyMemberIds[i];
                gPartyMemberIds[i] = val;
                val = temp;
            }
            goto after;
        }
        i++;
        if (i > 4)
            goto after;
    } while (gPartyMemberIds[i] != data[1]);
after:
    Chara_ClearTempStatus(data[1]);
    gPartyMemberIds[5] = 0xFF;

    memberId = data[1];
    idx = memberId;
    if (memberId != 0)
        idx = memberId - 1;

    if (gBattleFormationIds[gPartyStats[idx].field_unk[5]] == 0xFF)
    {
        gBattleFormationIds[gPartyStats[idx].field_unk[5]] = memberId;
    }
    else
    {
        i = 0;
        newId = memberId;
        do
        {
            if (gBattleFormationIds[i] == memberId)
            {
                gPartyStats[idx].field_unk[5] = i;
                goto end;
            }
            i++;
        } while (i <= 4);
        i = 0;
        do
        {
            if (gBattleFormationIds[i] == 0xFF)
            {
                gBattleFormationIds[i] = newId;
                gPartyStats[idx].field_unk[5] = i;
                goto end;
            }
            i++;
        } while (i <= 4);
    }
end:
    *ptr += 2;
    return 1;
}
// @ 0x0804F8D8
// 脚本 opcode: 按 gAfterBattleCounter 状态机分派。
//   state==3: 若 (sub_80187B4()&0x40)!=0 或 data[1]==0 → *ptr+=4;
//             否则 *ptr = gUnk_02016200 + gUnk_02016000[data[1]]; 清 state 返 1。
//   state==0: 初始化 gAfterBattleCounter=1 / gBattleResultType=data[3] /
//             gUnk_030025B8=data[2]+0xBA|0x1C(按 data[2] 符号) / gMainGameState=5; 返 0。
// 注: 用 `goto setup` 把 setup 块强制放成分支目标(冷路径)才匹配 `beq setup` 布局;
//     非 goto 写法分支被反转成 `bne` 使 setup 落 fall-through (差 127B)。待 flag 重构。
// 注: 跳转表需 `u16 idx = data[1] * 2` 中间量, 否则 ldr 基址被调度提到 lsls 前。
u32 sub_804F8D8(u32 *ptr)
{
    u8 *data;
    u8 state;
    u16 idx;

    data = (u8 *)*ptr;
    state = gAfterBattleCounter;
    if (state == 0)
        goto setup;
    if (state == 3)
    {
        if ((sub_80187B4() & 0x40) != 0 || data[1] == 0)
            *ptr += 4;
        else
        {
            idx = data[1] * 2;
            *ptr = (u32)(gUnk_02016200 + *(u16 *)((u32)gUnk_02016000 + idx));
        }
        gAfterBattleCounter = 0;
        return 1;
    }
    return 0;
setup:
    gAfterBattleCounter = 1;
    gBattleResultType = data[3];
    if ((s8)data[2] < 0)
        gUnk_030025B8 = data[2] + 0xBA;
    else
        gUnk_030025B8 = data[2] + 0x1C;
    gMainGameState = 5;
    return 0;
}
// @ 0x0804F974
// 脚本条件跳转: data[1] 为 flag 表字节数, 循环 count/2 个 u16 flag id
// (id<=0x1FF 查 EventFlags_Test, 否则查 SwitchFlags_Test(id-0x200)), 任一为真 →
// 指针跳到 0x02016200 + tbl[data[2]], 全假 → 指针推进 *ptr + t + 3; 恒返 1。
// 注: ① 跳转路径必须写 `u16 *tbl = (u16*)0x02016000;` 提升变量 + 字面量基址,
//     `*ptr = tbl[data[2]] + 0x02016200;` — 符号形式或加和顺序会让 GCC 把基址加法
//     跨跳合并进公共尾部 (基址落 r1, 目标要 r2, 差 5B)。
// ② 推进路径必须用嵌套块内新变量 `u32 step = t + 3; *ptr = *ptr + step;` —
//     让 t+3 独立于 *ptr 装载 (目标 mov r1,r8; adds r1,#3; ldr r0,[r6]; adds r0,r0,r1)。
u32 sub_804F974(u32 *ptr)
{
    u8 *data;
    u8 t;
    u8 n;
    u16 *tbl;
    u16 i;
    u16 v;
    u8 res;

    data = (u8 *)*ptr;
    t = data[1];
    n = t >> 1;
    tbl = (u16 *)0x02016000;
    for (i = 0; n > i; i++)
    {
        v = data[i * 2 + 3] | (data[i * 2 + 4] << 8);
        if (v > 0x1FF)
            res = SwitchFlags_Test(v - 0x200);
        else
            res = EventFlags_Test(v);
        if (res == 0)
            break;
    }
    if (res != 0)
        *ptr = tbl[data[2]] + 0x02016200;
    else
    {
        u32 step = t + 3;
        *ptr = *ptr + step;
    }
    return 1;
}
// @ 0x0804FA04
// INCLUDE_ASM("asm/nonmatchings", sub_804FA04);
u32 sub_804FA04(u32 *ptr)
{
    u8 *data;
    u8 t;
    u8 n;
    u32 off;
    u16 i;
    u16 v;
    u16 *tbl;
    u8 res;

    data = (u8 *) (*ptr);
    t = data[1];
    n = t >> 1;
    for (i = 0; n > i; i++)
    {
        v = data[(i * 2) + 3] | (data[(i * 2) + 4] << 8);
        if (v > 0x1FF)
        {
            res = SwitchFlags_Test(v - 0x200);
        }
        else
        {
            res = EventFlags_Test(v);
        }
        if (res != 0)
        {
            break;
        }
    }

    tbl = (u16 *) 0x02016000;
    if (res == 0)
    {
        *ptr = 0x02016200 + tbl[data[2]];
    }
    else
    {
        off = t + 3;
        *ptr = (*ptr) + off;
    }
    return 1;
}

// @ 0x0804FA94
// 脚本条件跳转 (任一 flag 置位版, 镜像 sub_804F974): data[1] 为 flag 表字节数, 循环 count/2 个
// u16 flag id (id<=0x1FF 查 EventFlags_Test, 否则查 SwitchFlags_Test(id-0x200)), 任一为真 →
// 指针跳到 gUnk_02016200 + gUnk_02016000[data[2]], 全假 → 指针推进 data + count + 3; 恒返 1。
// 注: t 全程存 r8 (推进路径 mov r1,r8)、0x1FF 存 sb; 跳转路径必须写 tbl 提升变量 + 字面量基址
// 在前的和 (`tbl = (u16*)0x02016000;` 提到 if 前, `*ptr = 0x02016200 + tbl[data[2]]`) ——
// 直写/符号形式会让 GCC 把基址加法跨跳合并进公共尾部 (基址落 r1, 目标要 r2, 差 5B)。
// `n > i` / `v > 0x1FF` 的操作数序对应 cmp r7,r4 / cmp r1,sb, 勿翻转。
// res 无初值 = 原始代码如此 (零循环时读 r1 残值, 目标同样无初始化指令)。
u32 sub_804FA94(u32 *ptr)
{
    u8 *data;
    u8 t;
    u8 n;
    u32 off;
    u16 i;
    u16 v;
    u16 *tbl;
    u8 res;

    data = (u8 *) (*ptr);
    t = data[1];
    n = t >> 1;
    for (i = 0; n > i; i++)
    {
        v = data[(i * 2) + 3] | (data[(i * 2) + 4] << 8);
        if (v > 0x1FF)
        {
            res = SwitchFlags_Test(v - 0x200);
        }
        else
        {
            res = EventFlags_Test(v);
        }
        if (res != 0)
        {
            break;
        }
    }

    tbl = (u16 *) 0x02016000;
    if (res != 0)
    {
        *ptr = 0x02016200 + tbl[data[2]];
    }
    else
    {
        off = t + 3;
        *ptr = (*ptr) + off;
    }
    return 1;
}
// @ 0x0804FB24
INCLUDE_ASM("asm/nonmatchings", sub_804FB24);
extern u16 (*gUnk_0862D434[])(u32 *);

// @ 0x08050014
void ScriptPump_Run(void)
{
    u16 keys;

    if ((gUnk_03000E70 & 1) != 0 && (gUnk_03000E70 & 0x200) == 0)
    {
        keys = ~REG_KEYINPUT;
        gUnk_03000F2E = keys & ~gUnk_03000F2C;
        gUnk_03000F2C = keys;
        sub_80182A8(gUnk_03000F2C, &gUnk_03000ED8);
        while (gUnk_0862D434[*(u8 *)gUnk_03000E6C](&gUnk_03000E6C) == 1)
        {
        }
    }
}

// @ 0x0805008C
// 脚本泵的逐帧后台服务: 在脚本活动期间 (bit0=脚本中, bit9=暂停) 按 gUnk_03000E70 的请求位
// 刷新 BG0 滚动/瓦片/LZ 块; LZ 解压完成后把脚本指针跳到解压缓冲 gUnk_02016200 的入口表项。
// 注: ① op==0||0x17 且 bgRequest==0 才走第一 DMA 块, 否则(含非 0/0x17 op)重读 gUnk_03000E70
//     若 bit4 置位走第二 DMA 块 —— `goto block2` 使编译器生成 bne 直跳 E2, 差 1B;
//     ② LZ 表须 `u16 *entryTbl = gUnk_02016000;` 中间指针 (permuter 发现, 修池加载序, 差 4B);
//     ③ bgRequest 必须内联 (抽变量多 1B)。fncheck OK 300B。
void sub_805008C(void)
{
    u8 op;
    u16 bgRequest;
    u16 *entryTbl;

    if ((gUnk_03000E70 & 1) != 0 && (gUnk_03000E70 & 0x200) == 0)
    {
        op = *(u8 *)gUnk_03000E6C;
        if (op == 0 || op == 0x17)
        {
            bgRequest = gUnk_03000E70 & 0x10;
            if (bgRequest == 0)
            {
                REG_BG0HOFS = bgRequest;
                REG_BG0VOFS = bgRequest;
                DmaSetUnchecked(3, 0x02005800, 0x0600F800, 0x80000400);
            }
            else
            {
                goto block2;
            }
        }
        if (gUnk_03000E70 & 0x10)
        {
        block2:
            REG_BG0HOFS = 0;
            REG_BG0VOFS = 0;
            DmaSetUnchecked(3, 0x02005800, 0x0600F800, 0x80000400);
        }
    }
    if ((gUnk_03000E70 & 0x40) != 0 && FlushTileDma() < 0)
        gUnk_03000E70 &= ~0x40;
    if ((gUnk_03000E70 & 0x100) != 0)
    {
        BgTiles_LoadSet(0);
        gUnk_03000E70 &= ~0x100;
    }
    if ((gUnk_03000E70 & 0x200) != 0)
    {
        if (LZ_UncompressChunk() == 0)
        {
            if ((gUnk_03000E70 & 0x400) != 0)
            {
                entryTbl = gUnk_02016000;
                gUnk_03000E6C = (u32)(gUnk_02016200 + entryTbl[gUnk_03000E69]);
                gUnk_03000E70 &= ~0x400;
            }
            gUnk_03000E70 &= ~0x200;
        }
    }
}
// @ 0x080501B8
INCLUDE_ASM("asm/nonmatchings", sub_80501B8);
// @ 0x08050434
INCLUDE_ASM("asm/nonmatchings", sub_8050434);
// @ 0x0805063C
INCLUDE_ASM("asm/nonmatchings", sub_805063C);
// @ 0x08050720
INCLUDE_ASM("asm/nonmatchings", sub_8050720);
// @ 0x080511A0
u8 sub_80511A0(u32 *arg0)
{
    u8 ret = 1;
    u8 i;
    if (gUnk_03000E78 != 0)
    {
        gUnk_03000E78--;
        *arg0 = gUnk_03000E80[gUnk_03000E78];
    }
    else
    {
        *arg0 = *arg0 + 1;
        Bgm_Request(gUnk_03000E68);
        gUnk_03000E70 &= 0xFFFE;
        i = 0;
        while (i < gUnk_03000ECA)
        {
            gUnk_03000EA0[i] = 0;
            gUnk_03000EC0[i] = 0;
            i++;
        }
        gUnk_03000ECA = 0;
        ret = 0;
    }
    return ret;
}
// @ 0x08051230
u32 Op_ScriptStop(u32 *ptr)
{
    u8 *data;
    u8 i;
    u8 state;
    u32 action;

    data = (u8 *)*ptr;
    if ((gUnk_03000E70 & 0x200) == 0)
    {
        data++;
        Bgm_Request(gUnk_03000E68);
        state = *data != 0 ? 1 : 3;
        action = state;
        switch (action)
        {
            default:
            case 1:
                gUnk_03000E6C = (u32)gUnk_02016200;
            case 3:
                break;
        }

        gUnk_03000E70 &= ~1;
        for (i = 0; i < gUnk_03000ECA; i++)
        {
            gUnk_03000EA0[i] = 0;
            gUnk_03000EC0[i] = 0;
        }

        action = 0;
        gUnk_03000ECA = action;
    }
    return 0;
}
// @ 0x080512C4
INCLUDE_ASM("asm/nonmatchings", sub_80512C4);
// @ 0x080513A0
INCLUDE_ASM("asm/nonmatchings", sub_80513A0);
// @ 0x0805144C
INCLUDE_ASM("asm/nonmatchings", sub_805144C);
// @ 0x08051A1C
u32 Op_OpenWindow(u32 *ptr)
{
    u32 bgcnt;

    DmaFill16(3, 0xB000, gWindowBgBuf, 0x800);
    DmaWait(3);
    DmaFill16(3, 0, (void *)0x0600F800, 0x800);
    {
        vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA3;
        u32 status = dmaRegs[2];
        u32 mask = DMA_ENABLE << 16;
        u32 value = *ptr;

        if ((s32)status < 0)
        {
            do
            {
                status = dmaRegs[2];
            } while (status & mask);
        }
        REG_DISPCNT |= DISPCNT_BG0_ON;
        bgcnt &= ~3;
        bgcnt &= ~0xC;
        bgcnt |= BGCNT_CHARBASE(2);
        bgcnt &= ~0x30;
        bgcnt &= ~BGCNT_MOSAIC;
        bgcnt &= ~BGCNT_256COLOR;
        bgcnt |= BGCNT_SCREENBASE(31);
        bgcnt &= ~BGCNT_WRAP;
        bgcnt &= ~BGCNT_TXT512x512;
        REG_BG0CNT = bgcnt;
        gUnk_03000E70 |= 0x10;
        *ptr = value + 1;
    }
    return 1;
}
// @ 0x08051AEC
s16 sub_8051AEC(s16 arg0, s16 arg1, s16 arg2, s16 arg3, u8 mode)
{
    switch ((s8)mode)
    {
        case 0:
            break;
        case 1:
            arg1 = ((float)arg1) * ((((float)arg3) * 10.0f) / ((float)arg2) / 10.0f);
            break;
        case 2:
            arg1 = ((float)arg1) * (((((-10.0f) * ((float)arg3)) / ((float)arg2)) + 20.0f) / 10.0f);
            break;
    }

    return arg0 + ((arg1 * arg3) / arg2);
}
// @ 0x08051BE4
INCLUDE_ASM("asm/nonmatchings", sub_8051BE4);

// @ 0x08052574
u16 Script_GetFlags(void)
{
    return gUnk_03000E70;
}

// @ 0x08052580
void Script_ResetVM(void)
{
    u8 i;

    gUnk_03000E6C = (u32)gUnk_02016200;
    gUnk_03000E70 = 0;
    gUnk_03000E72 = 0;
    gUnk_03000ECB = 1;
    gUnk_03000ECC = 0xC;
    gUnk_03000E78 = 0;
    for (i = 0; i <= 7; i++)
    {
        gUnk_03000E80[i] = 0;
    }
    gUnk_03000ECA = 0;
}
// @ 0x080525E8
INCLUDE_ASM("asm/nonmatchings", sub_80525E8);
// @ 0x080526A0
// 脚本 VM 启动/跳转: 按 arg1 模式设置脚本指针 gUnk_03000E6C, 然后清局部槽并置运行标志。
//   arg1==2 -> 跳到脚本区第 arg0 项入口 (gUnk_02016200 + gUnk_02016000[arg0])
//   arg1==3 -> 保持脚本指针不变
//   其它    -> 复位到脚本区基址 gUnk_02016200
// 之后把 8 个 u16 局部槽 (gScriptLocalSlots) 全置 0xFFFF, 置运行标志 bit0, 清 gUnk_03000E72。
// 注: base 0x02016200 / 表基址 0x02016000 必须写字面量, 换 gUnk_02016200/gUnk_02016000 符号
//     会改变 case2 块寄存器分配 (差 9B); `= -1` 是窄化 store 的 ldrh/orr/strh 展开形状,
//     写 `|= 0xFFFF` 或经局部指针/强转视图访问都会被折叠成直接 store (字节错)。
void sub_80526A0(u8 arg0, u8 arg1)
{
    u8 i;
    u16 *tbl;

    tbl = (u16 *)0x02016000;
    switch (arg1)
    {
    default:
    case 1:
        gUnk_03000E6C = 0x02016200;
        break;
    case 2:
        gUnk_03000E6C = 0x02016200 + tbl[arg0];
        break;
    case 3:
        break;
    }
    for (i = 0; i <= 7; i++)
    {
        gScriptLocalSlots[i] = -1;
    }
    gUnk_03000E70 = gUnk_03000E70 | 1;
    gUnk_03000E72 = 0;
}

// @ 0x08052728
void Script_Abort(u8 arg0)
{

    switch (arg0)
    {
        default:
        case 1:
            *(u32 *)0x03000E6C = 0x02016200;
            *(u16 *)0x03000E70 &= ~1;
            break;
        case 3:
            *(u16 *)0x03000E70 &= ~1;
            break;
    }
}

extern u8 *gUnk_087ED904[];

/* 注意: 原代码里这个 if 是个空转 —— 两个分支结果都是 arg0 = 0。
 * 不能删: 删了 GCC2 就不会生成 cmp/beq + movs 这三条,
 * 直接 `arg0 = 0;` 只会留一条 movs。 */
// @ 0x08052758
void BgTiles_LoadSet(u16 arg0)
{
    if (arg0 != 0)
    {
        arg0 = 0;
    }

    LZ77UnCompVram(gUnk_087ED904[arg0], (void *)0x0600B800);
}

// @ 0x08052780
void TileDma_Reset(void)
{
    u8 i;

    for (i = 0; i <= 0x1D; i++)
    {
        gUnk_03000EE8[i] = 0;
    }

    gUnk_03000F24 = 0;
}
// 把待传的图块数据从 EWRAM 暂存区 0x0203DE00 用 DMA3 刷到 VRAM 0x0600B800。
// gUnk_03000F24 = 待传块数, 每块 64 字节(= 16 个 u32); 无待传项时不发 DMA。
// 调用方按 (s16)返回值 < 0 判定已刷新。同族写法见 DialogCtx_Flush。
// @ 0x080527AC
s16 sub_80527AC(void)
{
    if (gUnk_03000F24 != 0)
    {
        DmaCopy32(3, 0x0203DE00, 0x0600B800, gUnk_03000F24 * 64);
        DmaWait(3);
    }
    return -1;
}
// @ 0x080527F4
u32 TileDma_GetCtx(u32 *arg0)
{
    *arg0 = 0x03000EE8;
    return *(u16 *)0x03000F24;
}
extern u8 gUnk_0862D574[];

// @ 0x08052808
u32 Op_LoadTileGfx(u8 arg0)
{
    sub_8050434((u32)(arg0 * 18) + (u32)gUnk_0862D574 + gUnk_03000F2A * 2, 0x6F1E);
    if (gUnk_03000F24 != 0)
    {
        gUnk_03000E70 |= 0x40;
        return 1;
    }
    return 0;
}
// 脚本 opcode: 无条件把脚本指针改到脚本区 0x02016200 里第 data[1] 项的入口。
// gUnk_02016000[] = 项偏移表(u16), gUnk_02016200 = 脚本数据基址。
// 同族写法见 Script_Call / Op_IfEventFlagJump。
// @ 0x08052858
u32 sub_8052858(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    *ptr = (u32)(gUnk_02016200 + gUnk_02016000[data[1]]);
    return 1;
}
// @ 0x08052878
u32 Script_Call(u32 *ptr)
{
    u8 *data;
    u16 ofs;

    data = (u8 *)*ptr;
    if (gUnk_03000E78 <= 7)
    {
        gUnk_03000E80[gUnk_03000E78] = (u32)(data + 2);
        ofs = *(u16 *)((u32)gUnk_02016000 + data[1] * 2);
        gUnk_03000E78++;
        *ptr = ofs + (u32)gUnk_02016200;
    }
    else
    {
        *ptr = (u32)(data + 2);
    }
    return 1;
}
// @ 0x080528C4
void nullsub_7() { }
// @ 0x080528C8
u32 Op_DialogSetup(u32 *ptr)
{
    u8 *p;
    u8 a1, a2, a3, a4, a5, a6;

    p = (u8 *)*ptr;
    a1 = *(++p);
    a2 = *(++p);
    a3 = *(++p);
    a4 = *(++p);
    a5 = *(++p);
    a6 = *(p + 1);
    sub_8019F08(gWindowBgBuf, a1, a2, a3, a4, a5);
    *ptr += 7;
    if (a6 == 1)
    {
        return 0;
    }
    return 1;
}
// @ 0x0805291C
u32 Op_CloseWindow(u32 *ptr)
{
    DmaFill16(3, 0xB000, gWindowBgBuf, 0x800);
    DmaWait(3);
    DmaFill16(3, 0, (void *)0x0600F800, 0x800);
    {
        vu32 *dmaRegs = (vu32 *)REG_ADDR_DMA3;
        u32 status = dmaRegs[2];
        u32 mask = DMA_ENABLE << 16;
        u32 value = *ptr;

        if ((s32)status < 0)
        {
            do
            {
                status = dmaRegs[2];
            } while (status & mask);
        }
        REG_DISPCNT &= ~DISPCNT_BG0_ON;
        gUnk_03000E70 |= 0x100;
        *ptr = value + 1;
    }
    return 0;
}
// @ 0x080529B8
u8 sub_80529B8(u8 **ptr)
{
    u8 *data = *ptr;
    u8 ret = 0;
    u8 idx = data[1];
    data = 0;
    if ((gUnk_03000E70 & 0x20) == 0)
    {
        gUnk_03000E74 = 0;
        gUnk_03000E70 |= 0x20;
    }
    else if (gUnk_03000E74 < idx)
    {
        gUnk_03000E74++;
    }
    else
    {
        gUnk_03000E74 = 0;
        gUnk_03000E70 &= ~0x20;
        *ptr += 2;
        ret = 1;
    }
    return ret;
}

// @ 0x08052A14
u32 Op_BgmPlay(u32 *ptr)
{
    u8 *data;
    u8 param1;
    u16 param2;
    u8 new_var;
    data = (u8 *)(*ptr);
    new_var = data[3];
    param2 = data[2] | (new_var << 8);
    Bgm_Play(data[1], param2);
    *ptr += 4;
    return 0;
}

// @ 0x08052A38
u32 Op_BgmStop(u32 *ptr)
{
    Bgm_Stop();
    (*ptr)++;
    return 0;
}
// @ 0x08052A50
u32 Op_BgmVolume(u32 *ptr)
{
    u8 *data;
    u8 new_var;

    data = (u8 *)*ptr;
    new_var = data[3];
    Bgm_SetVolume(data[2] | (new_var << 8));
    *ptr += 4;
    return 0;
}

// @ 0x08052A70
u32 Op_BgmFadeIn(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    Bgm_FadeIn(param);

    *ptr += 2;

    return 0;
}
// @ 0x08052A8C
u32 Op_BgmFadeOut(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    Bgm_FadeOut(param);

    *ptr += 2;

    return 0;
}

// @ 0x08052AA8
u32 Op_SfxPlay(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    Sfx_Play(data[1], data[2], data[3] != 0);
    *ptr += 4;
    return 0;
}

// @ 0x08052ACC
u32 Op_SfxStop(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    Sfx_StopTrack(param);

    *ptr += 2;

    return 0;
}
/* 从记录 rec 的 [1]..[2] 号段随机取一值查表 gUnk_02016000, 结果指针写入 *arg0。
 * 表基址/目标基址必须写成常量地址 (非数组符号): GCC2 对 SYMBOL_REF 会把基址留在 callee-saved
 * r7 不外提重取, 导致 val/max 寄存器分配错位 (差 15B); 常量地址才触发 rematerialize 命中目标。 */
// @ 0x08052AE8
u32 sub_8052AE8(u32 *arg0)
{
    u8 *rec;
    u8 diff;
    u16 val;
    u16 *tbl;

    rec = (u8 *)*arg0;
    tbl = (u16 *)0x02016000;
    val = tbl[rec[1]];
    if (rec[1] < rec[2])
    {
        diff = rec[2] - rec[1];
        val = tbl[(u8)(rec[1] + ((u32 (*)(void))Rng_LcgNext)() % (diff + 1))];
    }
    *arg0 = 0x02016200 + val;
    return 1;
}
// @ 0x08052B34
u32 sub_8052B34(u32 *ptr)
{
    u8 *data;
    u16 ofs;

    data = (u8 *)*ptr;
    if (gUnk_03000E78 <= 7)
    {
        gUnk_03000E80[gUnk_03000E78] = (u32)(data + 2);
        ofs = *(u16 *)((u32)gUnk_02016000 + data[1] * 2);
        gUnk_03000E78++;
        *ptr = ofs + (u32)gUnk_02016200;
    }
    else
    {
        *ptr = (u32)(data + 2);
    }
    return 1;
}
// @ 0x08052B80
u32 Op_WaitCharsStop(u32 *ptr)
{
    if (Chara_AnyMoving() == 0)
    {
        (*ptr)++;
        return 1;
    }

    return 0;
}
// @ 0x08052BA0
u32 Op_LoadCharaGfx(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (data[1] == 0xFF)
    {
        gMoveCmdSetId = data[2] + (data[3] << 8);
        BgScroll_LoadFromTable(gMoveCmdSetId);
    }
    else
    {
        SetSlotGfxId(data[1], data[2] | (data[3] << 8));
    }
    *ptr += 4;
    return 0;
}
// @ 0x08052BE0
u32 Op_LoadCharaPal(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    SetSlotPalId(data[1], data[2] | (data[3] << 8));
    *ptr += 4;
    return 0;
}
// @ 0x08052C04
u32 Op_WaitSpriteLoad(u32 *ptr)
{
    if (GetPendingSpriteLoad() == 0)
    {
        (*ptr)++;
        return 1;
    }

    return 0;
}

// @ 0x08052C24
u32 Op_SceneChangeFade(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    Palette_Backup();
    switch (data[1])
    {
        case 0:
            gSceneEntryFlag = 0xFF;
            ScreenFx_SetMode(4);
            break;
        case 1:
            gSceneEntryFlag = 0xFF;
            ScreenFx_SetMode(7);
            break;
        case 2:
            gSceneEntryFlag = 0xFF;
            Bgm_FadeOut(0x2E);
            ScreenFx_SetMode(4);
            break;
    }
    *ptr += 2;
    return 1;
}
// @ 0x08052C90
u32 Op_SceneChangePlain(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    switch (data[1])
    {
        case 0:
            Palette_Backup();
            /* fall through */
        case 1:
            ScreenFx_SetMode(3);
            break;
        case 2:
            Palette_Backup();
            ScreenFx_SetMode(7);
            break;
    }
    *ptr += 2;
    return 1;
}
// @ 0x08052CD0
u32 Op_WaitSceneIdle(u32 *ptr)
{
    if (gSceneSubState == 0)
    {
        (*ptr)++;
        return 1;
    }
    return 0;
}
// @ 0x08052CF0
u32 Op_LoadMap(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    gMapNpcSetId = data[1];
    gMoveCmdSetId = data[2] + (data[3] << 8);
    gSpawnTileX = data[4];
    gSpawnTileY = data[5];
    gSpawnFacingDir = data[6];
    gMainGameState = 2;
    gVBlankPipelineMode = 1;
    *ptr = (u32)(data + 7);
    return 0;
}
// @ 0x08052D4C
u32 Op_IfEventFlagJump(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (EventFlags_Test(data[1] | (data[2] << 8)) != 0)
    {
        *ptr = *(u16 *)((u32)gUnk_02016000 + data[3] * 2) + (u32)gUnk_02016200;
    }
    else
    {
        *ptr += 4;
    }
    return 1;
}
// @ 0x08052D8C
u32 Op_SetEventFlag(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    EventFlags_Set(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
// @ 0x08052DAC
u32 Op_ClearEventFlag(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    EventFlags_Reset(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
// @ 0x08052DCC
u32 Op_IfSwitchJump(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (SwitchFlags_Test(data[1] | (data[2] << 8)) != 0)
    {
        *ptr = *(u16 *)((u32)gUnk_02016000 + data[3] * 2) + (u32)gUnk_02016200;
    }
    else
    {
        *ptr += 4;
    }
    return 1;
}
// @ 0x08052E0C
u32 Op_SetSwitch(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    SwitchFlags_Set(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
// @ 0x08052E2C
u32 Op_ClearSwitch(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    SwitchFlags_Reset(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
// @ 0x08052E4C
u32 Op_CameraSnap(u32 *ptr)
{

    gCameraSnapFlag = 1;
    gUnk_030047B4 = 0;
    (*ptr)++;
    return 1;
}
// @ 0x08052E6C
s32 Op_CameraFollow(u32 *ptr)
{

    gCameraSnapFlag = 0;
    (*ptr)++;
    return 1;
}
// @ 0x08052E80
u32 Op_WaitCameraSnap(u32 *ptr)
{
    if (gUnk_030047B4 != 0)
    {
        return 0;
    }
    (*ptr)++;
    return 1;
}
// @ 0x08052E9C
u32 Op_LoadCutsceneAnim(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    CutsceneAnim_Load(data[1] | (data[2] << 8), data[3], data[4]);
    *ptr += 5;
    return 0;
}
// @ 0x08052EC0
u32 Op_RestartCharaAnim(u32 *ptr)
{
    u8 *data;
    u8 v;

    data = (u8 *)*ptr;
    if (gActors[data[1]].sprNodeIdx != 0)
    {
        Sprite_FreeChain(&gSpriteNodePool[gActors[data[1]].sprNodeIdx]);
    }
    v = Sprite_AllocNode();
    if (v <= 0x6F)
    {
        gActors[data[1]].sprNodeIdx = v;
        Chara_StartScriptAnim(data[1], data[2]);
    }
    *ptr += 3;
    return 0;
}
// @ 0x08052F20
u32 Op_WaitCharaAnim(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (Chara_AnimWaitDone(data[1]) != 0)
    {
        *ptr += 2;
        return 1;
    }
    return 0;
}
// 脚本 opcode: 队伍成员计数条件跳转。
//   统计 gPartyMemberIds[0..4] 中等于 data[1] 的成员个数 count。
//   count == data[2] → 脚本指针跳到 gUnk_02016200 + gUnk_02016000[data[3]]
//   否则             → 跳过本指令(4 字节)
// 注: 同族条件跳转见 Op_IfEventFlagJump / Op_IfSwitchJump / Op_IfMoneyJump;
//     跳转表写法必须写成 *(u16 *)((u32)gUnk_02016000 + data[3] * 2) + gUnk_02016200,
//     与 Op_IfEventFlagJump 逐字节同形。
// 注: 循环计数 i 必须是 u16 (目标 lsls/lsrs #0x10), count 必须是 u8 (#0x18);
//     且 i 不能在声明处初始化 —— `for (i = 0; ...)` 自带初始化, 预先写
//     `u16 i = 0;` 会让 GCC2 把 data/count 的寄存器 home 在 r3/r4 互换(差 12B)。
// @ 0x08052F44
u32 sub_8052F44(u32 *ptr)
{
    u8 *data = (u8 *)*ptr;
    u8 count = 0;
    u16 i;

    for (i = 0; i <= 4; i++)
    {
        if (gPartyMemberIds[i] == data[1])
        {
            count++;
            break;
        }
    }
    if (count == data[2])
    {
        *ptr = *(u16 *)((u32)gUnk_02016000 + data[3] * 2) + (u32)gUnk_02016200;
    }
    else
    {
        *ptr += 4;
    }
    return 1;
}
// @ 0x08052FAC
u32 Op_LoadAnimSet(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    sub_8008BA4(param1, param2);

    *ptr += 3;

    return 1;
}

// @ 0x08052FC8
u32 Op_AnimSlotResume(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    AnimSlot_Resume(param);

    *ptr += 2;

    return 1;
}
// @ 0x08052FE4
u32 Op_AnimSlotPause(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    AnimSlot_Pause(param);

    *ptr += 2;

    return 1;
}

// @ 0x08053000
u32 Op_WaitAnimSlotIdle(u32 *arg0)
{
    u8 *data = (u8 *)*arg0;

    if (!AnimSlot_Active(data[1]))
    {
        *arg0 += 2;
        return 1;
    }

    return 0;
}
// @ 0x08053024
u32 Op_MenuLoadAnims(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    MenuEnt_ParseRange(param1, param2);

    *ptr += 3;

    return 1;
}
// @ 0x08053040
u32 Op_MenuUnlock(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    MenuEnt_Unlock(param);

    *ptr += 2;

    return 1;
}

// @ 0x0805305C
u32 Op_MenuLock(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    MenuEnt_Lock(param);

    *ptr += 2;

    return 1;
}

// @ 0x08053078
u32 Op_WaitMenuReady(u32 *arg0)
{
    u8 *data = (u8 *)*arg0;

    if (!MenuEnt_GetState(data[1]))
    {
        *arg0 += 2;
        return 1;
    }

    return 0;
}

// @ 0x0805309C
u32 Op_FullHealParty(u32 *ptr)
{
    FullHealParty();
    (*ptr)++;
    return 1;
}
// @ 0x080530B4
u32 Op_EquipItem(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    EquipItem(data[1], data[2], data[3]);
    *ptr += 4;
    return 1;
}
// @ 0x080530D4
u32 Op_GiveTakeItem(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (data[2] > 100)
    {
        sub_800AA84(data[1], data[2] - 100);
    }
    else
    {
        sub_800AA60(data[1], data[2]);
    }

    *ptr += 3;
    return 1;
}
// @ 0x08053104
u32 Op_SilverAddSub(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (data[1] != 0)
    {
        Silver_Add(data[2] + (data[3] << 8));
    }
    else
    {
        Silver_Sub(data[2] + (data[3] << 8));
    }
    *ptr += 4;
    return 1;
}
extern u8 gUnk_03004980[];

// @ 0x08053138
u32 Op_IfItemQtyJump(u32 *ptr)
{
    u8 *data;
    u8 index;

    data = (u8 *)*ptr;
    index = data[1];
    if (gUnk_03004980[index] <= 0x62)
    {
        *ptr = (u32)(data + 3);
    }
    else
    {
        *ptr = *(u16 *)((u32)gUnk_02016000 + data[2] * 2) + (u32)gUnk_02016200;
    }
    return 1;
}
// @ 0x0805316C
u32 Op_ChestOpen(u32 *ptr)
{
    // 读取外部变量的值作为参数
    u8 param = gUnk_03004860;

    ChestObject_Open(param);

    // 递增指针指向的值
    (*ptr)++;

    return 0;
}
// @ 0x0805318C
u32 Op_SaveUiTrigger(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveUi_Open(param);

    *ptr += 2;

    return 0;
}
// @ 0x080531A8
u32 Op_IfSaveLoadedJump(u32 *ptr)
{
    u8 *data;
    u32 base;
    u32 value;
    u32 index;

    data = (u8 *)*ptr;
    if (gSaveBusyA != 0)
    {
        return 0;
    }
    if (gSaveBusyB == 0)
    {
        value = (u32)(data + 2);
    }
    else
    {
        index = data[1] * 2;
        base = (u32)gUnk_02016000;
        value = *(u16 *)(base + index);
        base = (u32)gUnk_02016200;
        value += base;
    }
    do
    {
        do
        {
            do
            {
                do
                {
                    do
                    {
                        *ptr = value;
                    } while (0);
                } while (0);
            } while (0);
        } while (0);
    } while (0);
    return 0;
}
// @ 0x080531E4
u32 Op_SaveTimerA(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveTimer_Inc(param);

    *ptr += 2;

    return 1;
}
// @ 0x08053200
u32 Op_SaveTimerB(u32 *ptr)
{
    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveTimer_Dec(param);

    *ptr += 2;

    return 1;
}
// @ 0x0805321C
u32 Op_IfSaveFlagJump(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (SaveTimer_Get(data[1]) != 0)
    {
        *ptr += 3;
    }
    else
    {
        *ptr = *(u16 *)((u32)gUnk_02016000 + data[2] * 2) + (u32)gUnk_02016200;
    }
    return 1;
}
// @ 0x08053254
u32 Op_SaveOp(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveFlag_Set(param);

    *ptr += 2;

    return 1;
}
// 脚本 opcode: 遍历脚本数据里的一段 u16 标志号列表, 逐个置位。
//   项数 = data[1] >> 1, 每项 = data[2+2k] | data[3+2k] << 8 (小端拼 u16)
//   号 <= 0x1FF → EventFlags_Set(号)        (置 0x03001C60 位图)
//   号 >  0x1FF → SwitchFlags_Set(号 - 0x200)(置 0x030018F0 位图)
// 最后把脚本指针推过整个列表。sub_80532DC 的 Set 姊妹。
// 注: 循环条件必须写成 `n > i`(界在左), 否则 GCC2 不会把 i=0 代入入口测试。
//     `off = t + 2;` 必须单独一句(规律30)。
// @ 0x08053270
u32 sub_8053270(u32 *ptr)
{
    u8 *data;
    u8 t;
    u8 n;
    u32 off;
    u16 v;
    u16 i;

    data = (u8 *)*ptr;
    t = data[1];
    n = t >> 1;
    for (i = 0; n > i; i++)
    {
        v = data[i * 2 + 2] | (data[i * 2 + 3] << 8);
        if (v > 0x1FF)
            SwitchFlags_Set(v - 0x200);
        else
            EventFlags_Set(v);
    }
    off = t + 2;
    *ptr = *ptr + off;
    return 1;
}
// 脚本 opcode: 遍历脚本数据里的一段 u16 标志号列表, 逐个清除标志位。
//   项数 = data[1] >> 1, 每项 = data[2+2k] | data[3+2k] << 8 (小端拼 u16)
//   号 <= 0x1FF → EventFlags_Reset(号)       (清 0x03001C60 标志位图)
//   号 >  0x1FF → SwitchFlags_Reset(号 - 0x200) (清 0x030018F0 标志位图)
// 最后把脚本指针推过整个列表。
// 注: 循环条件必须写成 `n > i`(界在左), 否则 GCC2 不会把 i=0 代入入口测试,
//     得到 `cmp r4,r0; bcs` 而非目标的 `cmp r0,#0; bls`。
// 注: `off = t + 2;` 必须单独一句(规律30), 写成 `*ptr + t + 2` 会被重结合成
//     `ldr; adds #2; add r8`。
// @ 0x080532DC
u32 sub_80532DC(u32 *ptr)
{
    u8 *data;
    u8 t;
    u8 n;
    u32 off;
    u16 v;
    u16 i;

    data = (u8 *)*ptr;
    t = data[1];
    n = t >> 1;
    for (i = 0; n > i; i++)
    {
        v = data[i * 2 + 2] | (data[i * 2 + 3] << 8);
        if (v > 0x1FF)
            SwitchFlags_Reset(v - 0x200);
        else
            EventFlags_Reset(v);
    }
    off = t + 2;
    *ptr = *ptr + off;
    return 1;
}
// @ 0x08053348
u32 Op_ClearSwitchTail(u32 *ptr)
{

    SwitchFlags_ClearRange();
    (*ptr)++;
    return 1;
}
// 脚本 opcode: 金额条件跳转。
//   操作数: data[1] = 跳转表索引, data[2..3] = 小端 u16 金额阈值
//   银两 > 阈值 → 脚本指针跳到 gUnk_02016200 + gUnk_02016000[data[1]]
//   否则           → 跳过本指令(4 字节)
// 注: 参数不是 ScriptContext 结构体。本文件里所有 Op_* 都是 `u32 Op_xxx(u32 *ptr)`,
//     ptr 指向脚本指针本身(即 *ptr = scriptPtr), 与邻居 Op_IfEventFlagJump 同形。
// @ 0x08053360
u32 Op_IfMoneyJump(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    if (gSilverAmount > data[2] + (data[3] << 8))
    {
        *ptr = *(u16 *)((u32)gUnk_02016000 + data[1] * 2) + (u32)gUnk_02016200;
    }
    else
    {
        *ptr = (u32)(data + 4);
    }
    return 1;
}

// @ 0x080533A0
u32 Op_StartLogoFade(u32 *ptr)
{

    gLogoEffectState = 1;
    (*ptr)++;
    return 0;
}
// @ 0x080533B4
u32 Op_WaitLogoFade(u32 *arg0)
{
    if (gLogoEffectState == 0)
    {
        *arg0 += 1;
        return 1;
    }
    return 0;
}
// @ 0x080533D4
u32 sub_80533D4(u32 *ptr)
{
    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    sub_800A3C8(param1, param2);

    *ptr += 3;

    return 1;
}
