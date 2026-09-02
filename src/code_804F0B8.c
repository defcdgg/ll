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
INCLUDE_ASM("asm/nonmatchings", sub_804F10C);
INCLUDE_ASM("asm/nonmatchings", sub_804F17C);
// INCLUDE_ASM("asm/nonmatchings", SioBattle_ResetState);
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
u8 SioBattle_GetState()
{
    return gUnk_03000E04;
}
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
INCLUDE_ASM("asm/nonmatchings", sub_804F280);
INCLUDE_ASM("asm/nonmatchings", sub_804F64C);
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
INCLUDE_ASM("asm/nonmatchings", sub_804F7F8);
INCLUDE_ASM("asm/nonmatchings", sub_804F8D8);
INCLUDE_ASM("asm/nonmatchings", sub_804F974);
INCLUDE_ASM("asm/nonmatchings", sub_804FA04);
INCLUDE_ASM("asm/nonmatchings", sub_804FA94);
INCLUDE_ASM("asm/nonmatchings", sub_804FB24);
extern u16 (*gUnk_0862D434[])(u32 *);

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
INCLUDE_ASM("asm/nonmatchings", sub_805008C);
INCLUDE_ASM("asm/nonmatchings", sub_80501B8);
INCLUDE_ASM("asm/nonmatchings", sub_8050434);
INCLUDE_ASM("asm/nonmatchings", sub_805063C);
INCLUDE_ASM("asm/nonmatchings", sub_8050720);
INCLUDE_ASM("asm/nonmatchings", sub_80511A0);
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
INCLUDE_ASM("asm/nonmatchings", sub_80512C4);
INCLUDE_ASM("asm/nonmatchings", sub_80513A0);
INCLUDE_ASM("asm/nonmatchings", sub_805144C);
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
INCLUDE_ASM("asm/nonmatchings", sub_8051AEC);
INCLUDE_ASM("asm/nonmatchings", sub_8051BE4);

u16 Script_GetFlags(void)
{
    return gUnk_03000E70;
}

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
INCLUDE_ASM("asm/nonmatchings", sub_80525E8);
INCLUDE_ASM("asm/nonmatchings", sub_80526A0);

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

extern u32 gUnk_087ED904[];

/* 注意: 原代码里这个 if 是个空转 —— 两个分支结果都是 arg0 = 0。
 * 不能删: 删了 GCC2 就不会生成 cmp/beq + movs 这三条,
 * 直接 `arg0 = 0;` 只会留一条 movs。 */
void BgTiles_LoadSet(u16 arg0)
{
    if (arg0 != 0)
    {
        arg0 = 0;
    }

    LZ77UnCompVram(gUnk_087ED904[arg0], (void *)0x0600B800);
}

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
s16 sub_80527AC(void)
{
    if (gUnk_03000F24 != 0)
    {
        DmaCopy32(3, 0x0203DE00, 0x0600B800, gUnk_03000F24 * 64);
        DmaWait(3);
    }
    return -1;
}
u32 TileDma_GetCtx(u32 *arg0)
{
    *arg0 = 0x03000EE8;
    return *(u16 *)0x03000F24;
}
extern u8 gUnk_0862D574[];

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
u32 sub_8052858(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    *ptr = (u32)(gUnk_02016200 + gUnk_02016000[data[1]]);
    return 1;
}
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
void nullsub_7() { }
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
INCLUDE_ASM("asm/nonmatchings", sub_80529B8);

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

u32 Op_BgmStop(u32 *ptr)
{
    Bgm_Stop();
    (*ptr)++;
    return 0;
}
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

u32 Op_BgmFadeIn(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    Bgm_FadeIn(param);

    *ptr += 2;

    return 0;
}
u32 Op_BgmFadeOut(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    Bgm_FadeOut(param);

    *ptr += 2;

    return 0;
}

u32 Op_SfxPlay(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    Sfx_Play(data[1], data[2], data[3] != 0);
    *ptr += 4;
    return 0;
}

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
u32 Op_WaitCharsStop(u32 *ptr)
{
    if (Chara_AnyMoving() == 0)
    {
        (*ptr)++;
        return 1;
    }

    return 0;
}
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
u32 Op_LoadCharaPal(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    SetSlotPalId(data[1], data[2] | (data[3] << 8));
    *ptr += 4;
    return 0;
}
u32 Op_WaitSpriteLoad(u32 *ptr)
{
    if (GetPendingSpriteLoad() == 0)
    {
        (*ptr)++;
        return 1;
    }

    return 0;
}

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
u32 Op_WaitSceneIdle(u32 *ptr)
{
    if (gSceneSubState == 0)
    {
        (*ptr)++;
        return 1;
    }
    return 0;
}
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
u32 Op_SetEventFlag(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    EventFlags_Set(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
u32 Op_ClearEventFlag(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    EventFlags_Reset(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
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
u32 Op_SetSwitch(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    SwitchFlags_Set(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
u32 Op_ClearSwitch(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    SwitchFlags_Reset(data[1] | (data[2] << 8));
    *ptr += 3;
    return 1;
}
u32 Op_CameraSnap(u32 *ptr)
{

    gCameraSnapFlag = 1;
    gUnk_030047B4 = 0;
    (*ptr)++;
    return 1;
}
s32 Op_CameraFollow(u32 *ptr)
{

    gCameraSnapFlag = 0;
    (*ptr)++;
    return 1;
}
u32 Op_WaitCameraSnap(u32 *ptr)
{
    if (gUnk_030047B4 != 0)
    {
        return 0;
    }
    (*ptr)++;
    return 1;
}
u32 Op_LoadCutsceneAnim(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    CutsceneAnim_Load(data[1] | (data[2] << 8), data[3], data[4]);
    *ptr += 5;
    return 0;
}
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
INCLUDE_ASM("asm/nonmatchings", sub_8052F44);
u32 Op_LoadAnimSet(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    sub_8008BA4(param1, param2);

    *ptr += 3;

    return 1;
}

u32 Op_AnimSlotResume(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    AnimSlot_Resume(param);

    *ptr += 2;

    return 1;
}
u32 Op_AnimSlotPause(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    AnimSlot_Pause(param);

    *ptr += 2;

    return 1;
}

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
u32 Op_MenuLoadAnims(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param1 = data[1];
    u8 param2 = data[2];

    MenuEnt_ParseRange(param1, param2);

    *ptr += 3;

    return 1;
}
u32 Op_MenuUnlock(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    MenuEnt_Unlock(param);

    *ptr += 2;

    return 1;
}

u32 Op_MenuLock(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    MenuEnt_Lock(param);

    *ptr += 2;

    return 1;
}

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

u32 Op_FullHealParty(u32 *ptr)
{
    FullHealParty();
    (*ptr)++;
    return 1;
}
u32 Op_EquipItem(u32 *ptr)
{
    u8 *data;

    data = (u8 *)*ptr;
    EquipItem(data[1], data[2], data[3]);
    *ptr += 4;
    return 1;
}
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
u32 Op_ChestOpen(u32 *ptr)
{
    // 读取外部变量的值作为参数
    u8 param = gUnk_03004860;

    Chest_Open(param);

    // 递增指针指向的值
    (*ptr)++;

    return 0;
}
u32 Op_SaveUiTrigger(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveUi_Open(param);

    *ptr += 2;

    return 0;
}
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
    do { do { do { do { do {
        *ptr = value;
    } while (0); } while (0); } while (0); } while (0); } while (0);
    return 0;
}
u32 Op_SaveTimerA(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveTimer_Inc(param);

    *ptr += 2;

    return 1;
}
u32 Op_SaveTimerB(u32 *ptr)
{
    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveTimer_Dec(param);

    *ptr += 2;

    return 1;
}
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
u32 Op_SaveOp(u32 *ptr)
{

    u8 *data = (u8 *)*ptr;

    u8 param = data[1];

    SaveFlag_Set(param);

    *ptr += 2;

    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8053270);
// 脚本 opcode: 遍历脚本数据里的一段 u16 标志号列表, 逐个清除标志位。
//   项数 = data[1] >> 1, 每项 = data[2+2k] | data[3+2k] << 8 (小端拼 u16)
//   号 <= 0x1FF → EventFlags_Reset(号)       (清 0x03001C60 标志位图)
//   号 >  0x1FF → SwitchFlags_Reset(号 - 0x200) (清 0x030018F0 标志位图)
// 最后把脚本指针推过整个列表。
// 注: 循环条件必须写成 `n > i`(界在左), 否则 GCC2 不会把 i=0 代入入口测试,
//     得到 `cmp r4,r0; bcs` 而非目标的 `cmp r0,#0; bls`。
// 注: `off = t + 2;` 必须单独一句(规律30), 写成 `*ptr + t + 2` 会被重结合成
//     `ldr; adds #2; add r8`。
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

u32 Op_StartLogoFade(u32 *ptr)
{

    gLogoEffectState = 1;
    (*ptr)++;
    return 0;
}
u32 Op_WaitLogoFade(u32 *arg0)
{
    if (gLogoEffectState == 0)
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
