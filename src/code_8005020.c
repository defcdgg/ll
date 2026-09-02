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




// @ 0x08005020
INCLUDE_ASM("asm/nonmatchings", sub_8005020);
// 屏幕淡化控制: 根据当前扫描线 (REG_VCOUNT) 与目标扫描线 gScreenFadeProgress 的差值,
// 每 16 行推进一桢渐变, 写入 REG_BLDY; 到达目标后恢复/切换 REG_BLDCNT。
//   fadeDelta = ((u16)gScreenFadeProgress - REG_VCOUNT) >> 4   (算术移位, 保留符号)
//   fadeDelta <= 0  → 过渡完成: BLDCNT = gBlendControl, BLDALPHA = gBlendCoefficients
//   (gScreenFadeFlags & 0x11) == 1 → BLDCNT = 0xBE (另一类混合模式)
//   其余         → BLDCNT = 0xFF
// 注: gScreenFadeProgress 在 iwram.h 里是 s16, 必须 (u16) 强转 —— 否则 GCC2 发
//     `ldrsh`(带 movs 零索引) 而非目标的 `ldrh`。参数不能声明成 u8(规则 65)。
// 注: 下面 `if (bldcnt != 0xFF)` 对未初始化变量赋值是**故意保留的死代码** ——
//     它让 GCC2 提前给 bldcnt 选定 callee-saved r4, 否则尾部会重新物化
//     `movs r0,#0xff`, 与目标不一致(删掉差 130 字节)。参见 RULES 规则 89。
// @ 0x080051D0
void ScreenFade_Apply(void)
{
    vu8 *vcountReg;
    s32 fadeDelta;
    u16 blendLevel;
    s16 signedFadeDelta;
    u16 blendControl;

    if (gScreenFadeFlags != 0)
    {
        if (blendControl != 0xFF)
            blendControl = 0xFF;
        vcountReg = (vu8 *)REG_ADDR_VCOUNT;
        blendControl = 0xFF;
        fadeDelta = (((u16)gScreenFadeProgress - *vcountReg) << 16) >> 20;
        blendLevel = (u16)fadeDelta;
        signedFadeDelta = (s16)fadeDelta;
        if (signedFadeDelta <= 0)
        {
            REG_BLDCNT = gBlendControl;
            REG_BLDALPHA = gBlendCoefficients;
            return;
        }
        if ((gScreenFadeFlags & 0x11) == 1)
        {
            if (signedFadeDelta > 0x10)
                blendLevel = 0x10;
            if ((blendLevel << 16) < 0)
                blendLevel = 0;
            REG_BLDY = blendLevel;
            REG_BLDCNT = 0xBE;
            return;
        }
        if (signedFadeDelta > 0x10)
            blendLevel = 0x10;
        if ((blendLevel << 16) < 0)
            blendLevel = 0;
        REG_BLDY = blendLevel;
        REG_BLDCNT = blendControl;
    }
}

// @ 0x0800526C
void ScreenFade_Update(void)
{
    REG_BLDCNT = gBlendControl;
    if (gBlendControl & 0x80)
    {
        REG_BLDY = gBlendCoefficients;
    }
    else
    {
        REG_BLDALPHA = gBlendCoefficients;
    }

    if (gScreenFadeFlags != 0)
    {
        if (!(gScreenFadeFlags & 0x80))
            gScreenFadeProgress += gScreenFadeStep;

        if (gScreenFadeStep < 0)
        {
            if (gScreenFadeProgress <= 0)
                gScreenFadeFlags = 0;
        }
        else
        {
            if (gScreenFadeProgress > 0x1B0)
                gScreenFadeFlags |= 0x80;
        }
    }
}
// @ 0x080052F8
INCLUDE_ASM("asm/nonmatchings", sub_80052F8);
// @ 0x080053B4
INCLUDE_ASM("asm/nonmatchings", sub_80053B4);
// @ 0x080055E8
INCLUDE_ASM("asm/nonmatchings", sub_80055E8);
// @ 0x08005B2C
u16 *MapTile_At(s16 x, s16 y)
{
    s16 screenX, screenY;
    s16 tileX, tileY;
    u16 *buf;

    screenX = x - (gCameraPosX & ~0xF);

    screenY = y - (gCameraPosY & ~0xF);

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
// @ 0x08005BB4
u16 MapTile_CollisionBits(u16 *tiles, u16 x, u16 y)
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
// @ 0x08005C70
INCLUDE_ASM("asm/nonmatchings", Viewport_UpdateScroll);

// @ 0x080064AC
void BgMap_FillPattern(u16 arg0)
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
extern u8* gUnk_087EA020[];
extern u8 gUnk_082893EC[][0x140];

/* MapSceneDescriptor / gMapSceneDescriptors 见 include/data_805769C.h */

extern u8* gUnk_087E9AA0[];

/* 地图整背景装载 (场景切换时): 按 gMapSceneDescriptors[arg0] 场景描述符
 *   - field_10 起把 gUnk_087E9AA0[] 里最多 5 块 LZ77 tile 逐块解压到 0x02020000 (每块 4KB 槽);
 *   - DMA 0x4A60 字节 → 0x06000000 (BG VRAM);
 *   - field_12: gUnk_082893EC 子表 (0x140 半字) → BG PLTT; BgPal_ResetFirst 复位底色;
 *   - field_E: gUnk_087EA020[] 指针 (LZ77 tilemap) 解压 → 0x02005000 → 0x0600F000 (SBB)。 */
// @ 0x08006520
void MapBg_LoadFull(u8 arg0) {
    u8 idx;
    u16 i;

    VBlankIntrWait();
    SoundMain_Frame();
    idx = gMapSceneDescriptors[arg0].tileSetId;
    i = 0;
    while(gUnk_087E9AA0[idx] != 0)
    {
        LZ77UnCompWram(gUnk_087E9AA0[idx], (void*)0x02020000 + (i<<12));
        VBlankIntrWait();
        SoundMain_Frame();

        idx++;
        i++;
        if(i > 4)
            break;

    }

    DmaCopy32(3, 0x02020000, 0x06000000, 0x4A60);

    VBlankIntrWait();
    SoundMain_Frame();

    DmaCopy16(3, &gUnk_082893EC[gMapSceneDescriptors[arg0].bgPaletteId], 0x05000000, 0x140);

    BgPal_ResetFirst();

    DmaCopy16(3, gUnk_087EA020[gMapSceneDescriptors[arg0].tilemapId], 0x02005000, 0x280*2);

    DmaCopy16(3, 0x02005000, 0x0600F000, 0x800);

    VBlankIntrWait();
    SoundMain_Frame();
}

// @ 0x0800661C
INCLUDE_ASM("asm/nonmatchings", MapScene_Load);
// @ 0x080071EC
INCLUDE_ASM("asm/nonmatchings", MapScene_LoadNpcSlotIds);
/* 地图场景精灵初始化 (进入场景时): 槽 0 = 主角 (gPartyMemberIds[0]) 图块+调色板,
 * 槽 1 = 固定 11 号模型 (跟随者/光影?); 若场景描述符 npcSlotGroupId 有 NPC 集,
 * 把槽 2..9 里已在用的图块/调色板模型 (gSlotGfxId/gSlotPalId, 0xFF=空) 重载进 OBJ VRAM
 * (VRAM 最多 8 种 NPC 模型, 有的模型不变只是颜色不同)。 */
// @ 0x0800729C
void MapScene_InitSprites(u8 arg0) {
    u16 i;

    if(gObjGraphicsSetId & 0x80)
        return;

    gSlotGfxId[0] = gPartyMemberIds[0];
    gSlotPalId[0] = gPartyMemberIds[0];
    LoadSpriteSheetGfx(0, gPartyMemberIds[0]);
    LoadSpriteSheetPal(0, gPartyMemberIds[0]);
    gSlotGfxId[1] = 11;
    gSlotPalId[1] = 11;
    LoadSpriteSheetGfx(1, 11);
    LoadSpriteSheetPal(1, 11);
    if(gMapSceneDescriptors[arg0].npcSlotGroupId != 0)
    {
        for(i = 0; i < 8; i++)
        {
            if(gSlotGfxId[i + 2] != 0xFF)
            {
                LoadSpriteSheetGfx(i + 2, gSlotGfxId[i + 2]);
            }
        }

        for(i = 0; i < 8; i++)
        {
            if(gSlotPalId[i + 2] != 0xFF)
            {
                LoadSpriteSheetPal(i + 2, gSlotPalId[i + 2]);
            }
        }
    }
}
// @ 0x08007350
INCLUDE_ASM("asm/nonmatchings", sub_8007350);
// @ 0x08007964
u8 *AnimSlot_Parse(u16 arg0, u8 *arg1)
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
// @ 0x080079BC
u8 *AnimSlot_ParseLoop(u16 arg0, u8 *arg1)
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
// 推进精灵动画槽 arg0 的帧计数, 并把当前帧的图块拷进 0x02006000 图块缓存。
// 描述符布局见 iwram.h 的 Unk_030046A0:
//   field_0 = 模型库(1/2, 0=空闲)  field_1 = 帧数      field_2 = 帧分频移位
//   field_3 = 标志(bit1=暂停, bit0=一次性)  field_6/field_7 = 目标图块偏移
//   field_8/field_9 = 单帧宽/高(块)  field_A = 帧计数器  field_C = 帧数据指针
// 行跳距 0x80 个 u16; 每帧大小 = field_8 * field_9 * 2 字节。
// 注: rows 在声明处的提前赋值是 GCC2 寄存器分配所需(该死 store 会被删除,
//     但决定字面池加载位置与 home 寄存器选择), 删掉则不匹配。
// @ 0x08007A1C
void sub_8007A1C(s16 arg0)
{
    Unk_030046A0 *ptr;
    u16 frame;
    u8 *dest;
    u8 *src;
    u8 width;
    u8 rows = gUnk_030046A0[arg0].field_9;
    u32 bankOff;
    u32 rowOff;

    ptr = &gUnk_030046A0[arg0];
    if (ptr->field_0 == 0)
        return;
    if (ptr->field_3 & 2)
        return;
    ptr->field_A++;
    frame = ptr->field_A >> ptr->field_2;
    if (frame >= ptr->field_1)
    {
        if (ptr->field_3 & 1)
            gUnk_030046A0[arg0].field_0 = 0;
        gUnk_030046A0[arg0].field_A = 0;
        frame = 0;
    }
    if (gUnk_030046A0[arg0].field_0 == 0)
        return;
    bankOff = (gUnk_030046A0[arg0].field_0 - 1) << 15;
    rowOff = (gUnk_030046A0[arg0].field_7 << 8) + 0x02006000;
    dest = (u8 *)(bankOff + rowOff + (gUnk_030046A0[arg0].field_6 << 1));
    src = (u8 *)(gUnk_030046A0[arg0].field_C + (gUnk_030046A0[arg0].field_8 * gUnk_030046A0[arg0].field_9 * frame * 2));
    rows = gUnk_030046A0[arg0].field_9;
    while (rows != 0)
    {
        width = gUnk_030046A0[arg0].field_8;
        while (width != 0)
        {
            *(u16 *)dest = *(u16 *)src;
            src += 2;
            dest += 2;
            width--;
        }
        dest += (0x80 - gUnk_030046A0[arg0].field_8) * 2;
        rows--;
    }
}
// @ 0x08007ADC
INCLUDE_ASM("asm/nonmatchings", sub_8007ADC);
/* 按 gMapZoneType 分发命中区域的触发动作 (记录表 = gMapZoneHeader[type+1], 记录下标 gMapZoneEntryIdx):
 * 0=换图: 装载点 5 字段 + state 3 + 清开关位图; 1=图内传送: 4 字段 + state 4;
 * 2=state 8 (byte 0x47BC/0x47E0); 3=开关未置则跑脚本(2B 记录)返回 1; 4=A 键+朝向门控跑脚本(4B 记录)返回 0;
 * type>4 (含 0xFF 未命中) 返回 1。 */
// @ 0x08007BD0
s32 MapZone_Trigger(void)
{
    u32 *header = gMapZoneHeader;
    u8 type = gMapZoneType;
    u32 ofs = type * 4 + 4;
    u8 *rec = (u8 *)*(u32 *)((u8 *)header + ofs);
    u8 scriptId;
    u8 dir;

    switch (type)
    {
    case 0:
        rec += gMapZoneEntryIdx * 8;
        gMapNpcSetId = *rec;
        rec++;
        gSpawnTileX = *rec;
        rec++;
        gSpawnTileY = *rec;
        rec++;
        gSpawnFacingDir = *rec;
        rec++;
        gMoveCmdSetId = rec[0] + (rec[1] << 8);
        gMainGameState = 3;
        SwitchFlags_ClearRange();
        return 1;
    case 1:
        rec += gMapZoneEntryIdx * 8;
        gSpawnTileX = *rec;
        rec++;
        gSpawnTileY = *rec;
        rec++;
        gSpawnFacingDir = *rec;
        rec++;
        gMoveCmdSetId = rec[0] + (rec[1] << 8);
        gMainGameState = 4;
        return 1;
    case 2:
        rec += gMapZoneEntryIdx * 4;
        gChoiceGroupIdx = rec[0];
        gChoiceSubIdx = rec[1];
        gMainGameState = 8;
        SwitchFlags_ClearRange();
        return 1;
    case 3:
        rec += gMapZoneEntryIdx * 2;
        scriptId = *rec;
        if (SwitchFlags_Test(rec[1]) != 0)
            return 0;
        sub_80526A0(scriptId, 2);
        return 1;
    case 4:
        rec += gMapZoneEntryIdx * 4;
        scriptId = *rec;
        rec++;
        if ((gNewKeysRaw & 1) == 0)
            return 0;
        dir = rec[1];
        if (dir <= 7 && dir != gPlayerMoveDir)
            return 0;
        if (SwitchFlags_Test(rec[0]) != 0)
            return 0;
        sub_80526A0(scriptId, 2);
        return 0;
    default:
        return 1;
    }
}
/* 选项场景 (世界观/存档界面?)整屏资源装载:
 * HuffUnComp gUnk_087EA0FC[arg0] → 0x02020000 → 0x06000000 (BG tile),
 * LZ77 gUnk_087EA110[arg0] → 0x0600E000 (SBB), gUnk_087EA124[arg0] → PLTT 0x80 半字;
 * 再装载公共 UI 图块 (0x0809Cxxx/0x0809Dxxx 五组) + 对话头像调色板/图块;
 * 配置 BG0-3/混合 (0x1E41/0x1F00), BgMap_FillPattern 铺底, TextBlocks_Render 按
 * gUnk_087E96B4[gChoiceGroupIdx] 渲染文本块, HBlank 水波开启, 最后 Logo_LoadAssets(arg0)
 * 装场景标志精灵, gChoiceSel = gChoiceSubIdx。 */
extern u8* gUnk_087EA0FC[];
extern u8* gUnk_087EA110[];
extern u8* gUnk_087EA124[];
extern u8* gUnk_087E96B4[];

extern u8 gChoiceSel;
extern u8 gChoiceSubIdx;
extern u8 gUnk_030047B4;

void Logo_LoadAssets(u8 arg0);

// @ 0x08007D5C
void MapBg_LoadInterior(u8 arg0) {
    u16* dest;
    u16 i;

    gVBlankPipelineMode = 3;
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
    gBlendCoefficients = 0x1F00;

    DmaCopy16(3,0x08393288, 0x0600C000, 0x200);
    DmaCopy16(3,0x08393688, 0x05000140, 0x20);

    BgMap_FillPattern(0);
    DmaCopy16(3,0x02005000, 0x0600F000, 0x800);


    dest = (u16* )0x02005800;
    for(i = 0; i < 0x800; i++)
    {
        *dest++ = 0;
    }

    TextBlocks_Render(  gUnk_087E96B4[gChoiceGroupIdx] );
    gHBlankEffectMode = 1;
    REG_BG1CNT = 0x1E0F;
    REG_DISPCNT |= 0x200;
    HBlankWave_BuildTables(1);
    Logo_LoadAssets(arg0);
    gChoiceSel = gChoiceSubIdx;
}

/* 选项场景的 LOGO/标志精灵装载 (arg0=1 时按 0xFD 事件标志二态):
 * 未解锁: gUnk_0808721C +0x60 图块 → 0x06014000, 调色板 → 0x05000240,
 *   一个精灵 gUnk_0300000A[0], tileOffsetY=0x20, gUnk_03000008/0C 计时清零;
 * 已解锁: 两块图块 (+0x1A0→0x06014000, +0x2E4→0x06014200) + 两个调色板 (+0x20/+0x40→0x05000240/260),
 *   两个精灵 gUnk_0300000A[0]=底图(attr2=0x2A00), gUnk_0300000A[1]=前景(attr2=0x3A10)。
 * arg0 != 1: 清空 gUnk_0300000A。BattleIntro_Cursor 消费这两个槽做开场演出。 */
extern const u16 gUnk_0808721C[];
extern const u16 gUnk_0808723C[];
extern const u16 gUnk_0808725C[];

extern const u8 gUnk_0808727C[];
extern const u8 gUnk_080873BC[];
extern const u8 gUnk_08087500[];

/* 选项场景的 LOGO/标志精灵装载 (arg0=1 时按事件标志 0xFF 二态):
 * 解锁: gUnk_080873BC→0x06014000, gUnk_08087500→0x06014200, 双调色板 gUnk_0808723C/25C→0x05000240/260,
 *   两个精灵 gUnk_0300000A[0] (attr2=0x2A00), [1] (attr2=0x3A10);
 * 未解锁: gUnk_0808727C→0x06014000, 调色板取 gUnk_0808721C -0x60 起 (r4 复用技巧),
 *   单精灵 tileOffsetY=0x20, gUnk_03000008/0C 计时清零 (BattleIntro_Cursor 呼吸动画用)。
 * arg0 != 1: 清空 gUnk_0300000A。 */
/* 选项场景 LOGO/标志精灵装载 (0x08008094 分支由 BattleIntro_Cursor 消费):
 *   arg0==1 且 EventFlags_Test(0xFF): 双图块 (gUnk_080873BC / +0x144) + 双调色板 (-0x180/-0x160),
 *     两个精灵 gUnk_0300000A[0] (attr2=0x2A00), [1] (attr2=0x3A10);
 *   arg0==1 未解锁: 单图块 gUnk_0808727C + 调色板 (gUnk_0808727C-0x60 = gUnk_0808721C),
 *     单精灵 tileOffsetY=0x20, gUnk_03000008/0C 清零 (呼吸动画复位);
 *   arg0!=1: gUnk_0300000A 清空。
 * 代码生成要点: gfx 指针 ±偏移 形态 (r4 缓存 + adds r1, r4, r2) 才能命中目标的字面池内联布局,
 * 用独立符号 (gUnk_08087500 等) 会多出 4 个池导致 ROM 布局漂移。 */
/* 选项场景 LOGO/标志精灵装载 (v2 草稿: attr0 用局部变量传参) */
// @ 0x08007FB8
void Logo_LoadAssets(u8 arg0)
{
    SpriteNode* sprNode;
    u8 idx;
    u16 attr0, attr1, attr2;

    if (arg0 == 1)
    {
        if (EventFlags_Test(0xFF) != 0)
        {
            LZ77UnCompVram(gUnk_080873BC, (void *)0x06014000);
            LZ77UnCompVram(gUnk_080873BC + 0x144, (void *)0x06014200);
            DmaCopy16(3, gUnk_080873BC - 0x180, (void *)0x05000240, 0x20);
            DmaCopy16(3, gUnk_080873BC - 0x160, (void *)0x05000260, 0x20);

            idx = Sprite_AllocNode();

            sprNode = &gSpriteNodePool[idx];
            gUnk_0300000A[0] = idx;
            attr0 = 0;
            attr1 = 0x8000;
            attr2 = 0x2A00;
            sprNode->tileOffsetX = 0;
            sprNode->tileOffsetY = 0;
            Sprite_InitChainNode(sprNode, 1, attr0, attr1, attr2);

            idx = Sprite_AllocNode();

            sprNode = &gSpriteNodePool[idx];
            gUnk_0300000A[1] = idx;
            attr1 = 0x8000;
            attr2 = 0x3A10;
            sprNode->tileOffsetX = 0;
            sprNode->tileOffsetY = 0;
            Sprite_InitChainNode(sprNode, 1, 0, attr1, attr2);
        }
        else
        {
            LZ77UnCompVram(gUnk_0808727C, (void *)0x06014000);
            DmaCopy16(3, gUnk_0808727C - 0x60, (void *)0x05000240, 0x20);

            idx = Sprite_AllocNode();
            sprNode = &gSpriteNodePool[idx];
            gUnk_0300000A[0] = idx;
            attr0 = 0;
            attr1 = 0x8000;
            attr2 = 0x2a00;
            sprNode->tileOffsetX = 0;
            sprNode->tileOffsetY = 0x20;

            Sprite_InitChainNode(sprNode, 1, attr0, attr1, attr2);

            gUnk_03000008 = 0;
            gUnk_0300000C = 0;
        }
    }
    else
    {
        gUnk_0300000A[0] = 0;
        gUnk_0300000A[1] = 0;
    }
}
/* gChoiceDataBase 声明见 include/data_805769C.h (const u8[]) */

// @ 0x08008124
u32 sub_8008124(void)
{
    u8 *p;
    u8 i;

    p = (u8 *)gChoiceDataBase;
    /* 跳过 gChoiceGroupIdx 组记录: 每组含两个以 0xFF 结尾的字段 */
    for (i = 0; i != gChoiceGroupIdx; i = (u8)(i + 1))
    {
        if (*p != 0xFF)
        {
            do
            {
                while (*++p != 0xFF);
                p++;
            } while (*p != 0xFF);
        }
        p++;
    }

    /* 再跳过 gChoiceSubIdx 组记录: 每组含一个以 0xFF 结尾的字段 */
    for (i = 0; i != gChoiceSubIdx; i = (u8)(i + 1))
    {
        if (*p != 0xFF)
        {
            while (*++p != 0xFF);
        }
        p++;
    }

    gChoiceListPtr = p;
    gChoiceCursor = 0;

    /* 走到本组记录末尾, 统计跳过的字节数 */
    i = 0;
    while (*p != 0xFF)
    {
        p++;
        i = (u8)(i + 1);
    }
    gChoiceListLen = i;
}

// @ 0x080081C0
void BattleIntro_Cursor(void)
{

    if (gUnk_0300000A[1] != 0)
    {
        Sprite_EnqueueRender(0xb0, 0x18, gUnk_0300000A[1], 0, 1);
        Sprite_EnqueueRender(0xD0, 0x30, gUnk_0300000A[0], 0, 1);
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

        Sprite_EnqueueRender(0x68, 0x30, gUnk_0300000A[0], (gUnk_0300000C >> 6) + 0x10, 1);
    }
}
// @ 0x08008254
INCLUDE_ASM("asm/nonmatchings", ChoiceMenu_HandleInput);
/* Select one of the 88 portrait assets and seed its 8x8 dialogue tilemap. */
// @ 0x08008620
void DialogPortrait_Set(u8 portraitId, u8 position)
{
    u16 *dst;
    u16 tile;
    u16 row;
    u16 offset;
    u16 col;

    if (portraitId != 0)
    {
        if (portraitId > 0x58)
            portraitId = 0;
        portraitId--;
        gPendingPortraitSlot = position + 1;
        gPendingPortraitGfx = (u8 *)gDialogPortraitGfxTable[portraitId];
        gPendingPortraitPalette = (u16 *)&gDialogPortraitPalettes[gDialogPortraitPaletteIds[portraitId] * 16];
        if (position & 2)
            tile = 0xF2C0;
        else
            tile = 0xE280;
        dst = (u16 *)gDialogPortraitTilemapPtrs[position];
        offset = 0;
        for (row = 0; row < 8; row++)
        {
            for (col = 0; col < 8; col++)
            {
                *dst++ = tile + offset;
                offset++;
            }
            dst += 0x18;
        }
        return;
    }

    dst = (u16 *)gDialogPortraitTilemapPtrs[position];
    for (row = 0; row < 8; row++)
    {
        for (col = 0; col < 8; col++)
            *dst++ = 0;
        dst += 0x18;
    }
    gPendingPortraitSlot = 0;
}

// @ 0x080086FC
void sub_80086FC(void)
{
    if (gViewportFlags[0] & 1)
        gViewportFlags[1] = Rand_TableNext() & gViewportFlags[4];

    if (gViewportFlags[0] & 2)
        gViewportFlags[2] = Rand_TableNext() & gViewportFlags[4];

    if (gViewportFlags[0] & 4)
    {
        gViewportFlags[3]++;
        if (gViewportFlags[3] > 0xF)
            gViewportFlags[3] = 0;

        gBlendControl = 0x1C42;
        gBlendCoefficients = 0x0F00 | gViewportFlags[3];
        REG_DISPCNT |= DISPCNT_BG1_ON;
    }
}

extern const u16 gBgPalBackdropWhite[];
extern const u8* gIntroBgTiles[];    // [id*2]=3KB tile组, [id*2+1]=可选 8-tile 动画组(NULL=无)
extern const u8* gIntroBgMaps[];     // [id] LZ77 32x20 tilemap -> SBB 3 (0x0600E000)
extern const u16 gIntroBgPalettes[][0x20];

// @ 0x08008788
void IntroBg_Load(u8 arg0)
{
    gIntroBgTransferStage = 0;
    gIntroBgTileSetIndex = 0;
    gVBlankPipelineMode = 6;
    gObjGraphicsSetId = 0xFD;

    Scene_ResetResources();
    VBlankIntrWait();
    SoundMain_Frame();

    LZ77UnCompWram(gIntroBgTiles[arg0 * 2], (void *)0x02020000);
    gIntroBgTileSetIndex = 0;
    gIntroBgTransferStage = 1;
    VBlankIntrWait();
    SoundMain_Frame();

    if (gIntroBgTiles[arg0 * 2 + 1] != 0) {
        LZ77UnCompWram(gIntroBgTiles[arg0 * 2 + 1], (void *)0x02020000);
        gIntroBgTileSetIndex = 1;
        gIntroBgTransferStage = 1;
        VBlankIntrWait();
        SoundMain_Frame();
    }

    DmaCopy32(3, gIntroBgPalettes[arg0], PLTT, 0x40);
    DmaCopy16(3, gBgPalBackdropWhite, PLTT, 2);
    VBlankWait_PumpSound();

    LZ77UnCompWram(gIntroBgMaps[arg0], (void *)0x02020000);
    gIntroBgTileSetIndex = 0;
    gIntroBgTransferStage = 2;
    VBlankIntrWait();
    SoundMain_Frame();
    VBlankWait_PumpSound();

    REG_DISPCNT = 0x1960;
    REG_BG1CNT = 0;
    REG_BG2CNT = 0;
    REG_BG3CNT = 0x3C03;
}


// @ 0x080088B4
void ScreenFade_Start(u16 flags, s16 step, s16 param)
{
    gScreenFadeParam = param;
    gScreenFadeStep = step;

    if (step < 0)
    {
        gScreenFadeProgress = 0x1B0;
    }
    else
    {
        gScreenFadeProgress = 0;
    }

    gScreenFadeFlags = flags;
}

// @ 0x080088F4
void AnimSlot_BankReload(void)
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

/* 用 DMA0 把 gWindowTransitionScanlineTable 里的一个 WIN0H 值按扫描线喂给 REG_WIN0H,
 * 索引 = VCOUNT 的三角波 (0→81→0 跨一屏) → 窗口水平边界随扫描线摆动。
 *
 * ⚠ 全 ROM 无调用点 (code.s 里 6360 个 bl 全部已符号化, 没有 `bl Win0H_WaveDmaByVCount`;
 *   0x08008978 也未作为指针出现在任何数据里) → **死代码**。
 *   注: 旧名 HBlank_WaveDma / 旧注释"声音DMA0旋转" 是误读 —— 目的端 0x04000040
 *   是 REG_WIN0H (io.h: REG_OFFSET_WIN0H=0x40), 不是声音 FIFO (FIFO A/B 在 0xA0/0xAC)。
 */
// @ 0x08008978
void Win0H_WaveDmaByVCount(void) {
    u16 waveIdx;
    u8 subState = (u8)(gSceneSubState - 1);
    if (subState > 1) {
        return;
    }
    /* VCOUNT 低字节 (字节读 = 目标的 ldrb, 不能写 (u8)REG_VCOUNT) */
    waveIdx = *(u8 *)&REG_VCOUNT;
    if (waveIdx > 0x9F) {           /* > 159: 屏外扫描线 */
        if (waveIdx <= 0xE1) {
            return;
        }
        waveIdx = 0;
    } else {
        waveIdx = waveIdx + 1;
    }
    if (waveIdx > 0x51) {           /* 三角波: 0x52 半周期 */
        waveIdx = waveIdx - 0x52;
    } else {
        waveIdx = 0x51 - waveIdx;
    }
    DmaSet(0, gWindowTransitionScanlineTable + (waveIdx * 2), (void *)REG_ADDR_WIN0H, 0xE0400001);
}
// @ 0x080089E0
void ScreenFx_SetMode(u16 arg0)
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
            PaletteFx_Apply(arg0 - 3);
            break;
    }

    gSceneSubState = arg0;
}

// @ 0x08008A3C
void AnimSlots_Release(void)
{
    s16 i;

    for (i = 0; i < 16; i++)
    {
        gUnk_030046A0[i].field_0 = 0;
    }
}

// @ 0x08008A60
void AnimSlots_StepAll(void)
{
    s16 i;

    for (i = 0; i < 16; i++)
    {
        sub_8007A1C(i);
    }
}
// @ 0x08008A80
void BgTiles_LoadUiSet(u8 arg0)
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
// @ 0x08008B14
void BgScroll_LoadFromTable(u16 arg0) {

    gCameraMinX = gMapViewportBoundsTable[arg0].cameraMinXBlocks << 6;

    gCameraMinY = gMapViewportBoundsTable[arg0].cameraMinYBlocks << 6;

    gMapWidthPx = gCameraMinX + (gMapViewportBoundsTable[arg0].mapWidthBlocks << 6);

    gMapHeightPx = gCameraMinY + (gMapViewportBoundsTable[arg0].mapHeightBlocks << 6);
}
// @ 0x08008B5C
void PlayerSheets_Load(void)
{
    // gSlotGfxId.field_0 = gPartyMemberIds[0];
    gSlotGfxId[0] = gPartyMemberIds[0];
    gSlotPalId[0] = gPartyMemberIds[0];

    LoadSpriteSheetGfx(0, gPartyMemberIds[0]);
    LoadSpriteSheetPal(0, gPartyMemberIds[0]);
    // gSlotGfxId.field_1 = 11;
    gSlotGfxId[1] = 11;
    gSlotPalId[1] = 11;
    LoadSpriteSheetGfx(1, 0xBU);
    LoadSpriteSheetPal(1, 0xBU);
}
// 0x087EA1A0: 248 项指针表, 每项指向一组 "精灵动画模型" 记录
//   记录块格式: u16 count; 随后 count 条变长记录 (见 AnimSlot_Parse)
extern u8 *gUnk_087EA1A0[];

// 把 gUnk_087EA1A0[setId] 这一组动画模型 (共 *ptr 条) 逐条解析进
// gUnk_030046A0[] 精灵模型描述符数组, 起始槽位为 startSlot。
// 槽位号 = startSlot + 记录序号, 与 sub_8007350 (整组装入槽位 0..) 是同族写法。
// @ 0x08008BA4
void sub_8008BA4(u8 setId, u8 startSlot)
{
    u8 *src;
    u16 endSlot;
    u16 slot;

    src = gUnk_087EA1A0[setId];
    endSlot = *(u16 *)src + startSlot;
    src += 2;

    for (slot = startSlot; slot < endSlot; slot++)
    {
        src = AnimSlot_Parse(slot, src);
    }
}

// @ 0x08008BE4
void AnimSlot_Pause(u8 arg0)
{
    gUnk_030046A0[arg0].field_3 |= 2;
}

// @ 0x08008BFC
void AnimSlot_Resume(u8 arg0)
{
    gUnk_030046A0[arg0].field_3 &= 0xFD;
}

// @ 0x08008C14
u8 AnimSlot_Active(u8 arg0)
{
    return gUnk_030046A0[arg0].field_0;
}

/* 重载单个精灵表槽位: 图块用 gSlotGfxId[slot]、调色板用 gSlotPalId[slot],
 * 0xFF 表示该部分不动。整块受 gObjGraphicsSetId 的 bit7 屏蔽。 */
// @ 0x08008C24
void ReloadSpriteSheet(u8 slot)
{

    if (!(gObjGraphicsSetId & GFXSET_NO_SPRITE_LOAD))
    {
        if (gSlotGfxId[slot] != 0xFF)
        {
            LoadSpriteSheetGfx(slot, gSlotGfxId[slot]);
        }

        if (gSlotPalId[slot] != 0xFF)
        {
            LoadSpriteSheetPal(slot, gSlotPalId[slot]);
        }
    }
}

/* 全量重载全部 12 个精灵表槽位(0x06011400 + 12*0x900 = 0x06018000 正好到 VRAM 尾)。 */
// @ 0x08008C70
void ReloadAllSpriteSheets(void)
{
    u8 i;

    for (i = 0; i < 12; i++)
    {
        if (!(gObjGraphicsSetId & GFXSET_NO_SPRITE_LOAD))
        {
            if (gSlotGfxId[i] != 0xFF)
            {
                LoadSpriteSheetGfx(i, gSlotGfxId[i]);
            }
            if (gSlotPalId[i] != 0xFF)
            {
                LoadSpriteSheetPal(i, gSlotPalId[i]);
            }
        }
    }
}

extern const u8 gChoiceDestTable[];

/* 把"当前选项号"解析成一个目的地像素坐标, 写进 gChoiceDestX / gChoiceDestY。
 *
 * gChoiceDestTable @0x08087648 是**分组变长表**: 每组 = [count][count × {x, y}],
 * 组间无填充, 由 count 推出下一组起点 (count*2 是数据字节数, 再 +1 跳过 count 字节)。
 * 实测 5 组, count = 5/7/9/9/5, 共 35 个目的地, 消耗 75/76 字节 (末 1 字节为 0 终止)。
 * 值域 x∈12..200, y∈32..128 → 240×160 屏幕的**像素坐标**。
 *
 * 组号 = gChoiceGroupIdx (由 sub_8008124 从 gChoiceDataBase 分层记录流定位);
 * 选项号 = 调用者传入 (Scene_EnterDoor 传 gChoiceListPtr[gChoiceCursor] 的低 nibble)。
 *
 * 代码生成要点 (已逐字节验证, bytecmp OK 88B):
 *   - 必须写成 `skipLen = *ptr << 1` 的**先读后自增**结构, 目标才是
 *     `ldrb; lsls #0x19; lsrs #0x18` + `adds r1,#1` 的形态
 *   - 循环里 `ptr += skipLen; i++; skipLen = *ptr<<1; ptr++;` 的顺序不能调
 *     (目标把 ptr++ 放在读 count 之后, 与 while 的底部测试配合)
 *   - 取项写成 `ptr + (arg0 << 1)` 再 `ptr[0]`/`ptr[1]`, 不要合并成 `ptr[arg0*2]`
 */
// @ 0x08008CC0
void ChoiceMenu_ResolveDest(u8 choiceIdx)
{
    const u8 *ptr;
    u8 i;
    u8 skipLen;

    ptr = gChoiceDestTable;
    i = 0;
    skipLen = *ptr << 1;
    ptr++;

    while (i != gChoiceGroupIdx)
    {
        ptr += skipLen;
        i++;
        skipLen = *ptr << 1;
        ptr++;
    }

    ptr = ptr + (choiceIdx << 1);
    gChoiceDestX = ptr[0];
    gChoiceDestY = ptr[1];
}
// }

// @ 0x08008D18
void DialogPortrait_FlushPending(void)
{
    u32 i;
    u16 *dest;

    if (gPendingPortraitSlot != 0)
    {

        LZ77UnCompVram(gPendingPortraitGfx, (void *)(((gPendingPortraitSlot - 1) >> 1) * 0x800 + 0x0600D000));

        i = (gPendingPortraitSlot - 1) >> 1;

        dest = (u16 *)(i * 0x20 + 0x050001C0);
        DmaCopy16(3, gPendingPortraitPalette, dest, 0x20);

        // (void* )0x040000D4->unk0 = (s32) gUnk_03004694;
        // (void* )0x040000D4->unk4 = (s32) ((((s32) (gUnk_0300483C - 1) >> 1) << 5) + 0x050001C0);
        // (void* )0x040000D4->unk8 = 0x80000010;
        gPendingPortraitSlot = 0;
    }
}

// @ 0x08008D78
u16 Camera_GetDrawOffset(void)
{
    switch (gCameraDrawMode)
    {
        case 2:
            return gDrawCamY >> 4;

        case 4:
            return gDrawCamY - 0x20;

        case 7:
            return gDrawCamY - gCameraPosY;

        default:
            return 0;
    }
}

// @ 0x08008DCC
void Bgm_Request(u8 arg0)
{
    gCurrentSongId = arg0;
}

// @ 0x08008DD8
void BgPal_ResetFirst(void)
{
    DmaCopy16(3, (void *)0x08087216, (void *)0x05000000, 2);
}

// @ 0x08008DF8
void AnimSlot_PlayOnce(u16 arg0, u8 *arg1)
{
    u16 count;

    count = *(u16 *)arg1;
    arg1 += 2;

    while (count != 0)
    {
        arg1 = AnimSlot_ParseLoop(arg0, arg1);

        sub_8007A1C(arg0);

        gUnk_030046A0[arg0].field_0 = 0;
        count--;
    }
}
// @ 0x08008E44
void BgMap_FillRow(u8 arg0)
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
    gViewportFlags[13] = 1;
}

// @ 0x08008E94
void MapBg_FlushPending(void)
{
    switch (gIntroBgTransferStage)
    {
        case 1:
            switch (gIntroBgTileSetIndex)
            {
                case 0:
                    DmaCopy32(3, (void *)0x02020000, (void *)0x06000000, 0xc00);
                    break;

                case 1:
                    DmaCopy32(3, (void *)0x02020000, (void *)0x06000C00, 0xc0);
                    break;
            }
            gIntroBgTransferStage = 0;
            break;

        case 2:
            DmaCopy32(3, (void *)0x02020000, (void *)0x0600E000, 0x800);
            gIntroBgTransferStage = 0;
            break;
    }
}
/* 按当前地图从 0x08088400 的 256 项表中装载宝箱对象；见 ChestMapEntry。 */
void Chest_LoadForMap(u8 mapId)
{
    u8 slot;
    u8 recordIndex;
    const ChestMapEntry *entry;
    Chest *chest;
    Chest *chestBase;
    u8 flags;

    slot = 0;
    recordIndex = 0;
    entry = gChestSpawnTable;
    while (1)
    {
        if (mapId == entry->mapId)
        {
            chestBase = gChests;
            chest = &chestBase[slot];
            chest->mapEntryIndex = recordIndex;
            chest->x = entry->tileX << 3;
            chest->y = (entry->tileY << 3) + 8;
            chest->interactionId = entry->itemId;
            flags = gChestFlags[recordIndex >> 3];
            chest->flags = (flags >> (recordIndex & 7)) & 1;
            if (entry->specialFlag != 0)
                chest->flags |= 0x80;
            Chest_BuildSprite(slot);
            slot++;
        }

        entry++;
        if (recordIndex == 0xFF)
            break;
        recordIndex++;
        if (slot > 0xF)
            break;
    }

    while (slot <= 0xF)
    {
        gChests[slot].flags |= 0xFF;
        gChests[slot].spriteNodeIdx = 0;
        slot++;
    }
}
void Chest_BuildSprite(u8 arg0)
{
    struct SpriteNode *sprNode;
    struct SpriteNode *sprSubNode;
    u8 objIdx;
    u16 chestColor;
    u16 attr0;
    u16 attr1;
    u16 attr2;

    objIdx = Sprite_AllocNode();
    gChests[arg0].spriteNodeIdx = objIdx;
    sprNode = &gSpriteNodePool[objIdx];

    chestColor = 0x80 & gChests[arg0].flags ? 0xF : 0xE;

    if ((0x7F & gChests[arg0].flags) == 0)
    {

        attr0 = 0;
        attr1 = 0x4000;
        attr2 = ((chestColor << 12) | 0x896);

        sprNode->tileOffsetX = 0;
        sprNode->tileOffsetY = 0xF0;

        Sprite_InitChainNode(sprNode, 1, attr0, attr1, attr2);
    }
    else
    {
        attr0 = 0;
        attr1 = 0x4000;
        attr2 = ((chestColor << 12) + 0x89C);
        sprNode->tileOffsetX = 0;
        sprNode->tileOffsetY = 0xF0;
        sprSubNode = Sprite_InitChainNode(sprNode, 2, attr0, attr1, attr2);

        attr0 = 0x4000;
        attr1 = 0;
        attr2 = ((chestColor << 12) | 0x89A);
        sprSubNode->tileOffsetX = 0;
        sprSubNode->tileOffsetY = 0xE8;
        Sprite_InitChainNode(sprSubNode, 1, attr0, attr1, attr2);
    }
    sprNode->animStep = 0;
}
void Chest_Open(u8 arg0)
{
    u8 idx;

    if (gChests[arg0].flags & 1)
    {
        Sfx_Play(9, 0, 0);
    }
    else
    {
        Sfx_Play(8, 0, 0);
    }

    gChests[arg0].flags ^= 1;

    idx = gChests[arg0].mapEntryIndex;

    gChestFlags[idx >> 3] ^= (1 << (idx & 7));

    Sprite_FreeChain(&gSpriteNodePool[gChests[arg0].spriteNodeIdx]);
    Chest_BuildSprite(arg0);
    gUnk_03004860 = arg0;
}

/* 把“数字 0~9 字形”连同对应的 OBJ 调色板装进去, 供 HUD/菜单直接拼数字用:
 *   gDigitFontObjTiles (0x08088C40) → 0x060112C0  0x140 B = 10 个 4bpp 8×8 图块 = OBJ 图块槽 150~159
 *   gDigitFontObjPalettes (0x08088C00) → 0x050003C0  0x40 B  = 2 组 16 色 OBJ 调色板(槽 14~15)
 * 受 gObjGraphicsSetId 的 bit7 屏蔽; 槽 146~149 是箭头/滚动条字形(见 LoadArrowObjTiles)。
 * ⚠ `0x80 & gObjGraphicsSetId` 的常量在左不能改位置, 否则 GCC2 生成的指令序列会变(规则 5)。 */
// @ 0x08009114
void LoadDigitFontObjTiles(void)
{
    if (!(GFXSET_NO_SPRITE_LOAD & gObjGraphicsSetId))
    {
        nullsub_5();
        DmaCopy16(3, 0x08088C40, 0x060112C0, 0xA0 * 2);
        DmaCopy16(3, 0x08088C00, 0x050003C0, 0x20 * 2);
    }
}
// @ 0x08009168
void ChestFlags_ClearAll()
{
    u8 i = 0;
    // do{gChestFlags[i++] = 0;}while(i < 0x20);
    while (i < 0x20)
    {
        gChestFlags[i++] = 0;
    }
}
// @ 0x08009184
void ChestFlags_Toggle(u8 arg0)
{
    gChestFlags[arg0 >> 3] ^= (1 << (arg0 & 7));
}
// @ 0x080091A4
u8 ChestFlags_Test(u8 arg0)
{
    u8 val;
    val = gChestFlags[(arg0 >> 3) & 0x1F];
    return (val >> (arg0 & 7)) & 1;
}
// @ 0x080091C4
INCLUDE_ASM("asm/nonmatchings", sub_80091C4);

/* 调色板 DMA 上传: 平时整表刷新; 若 gUnk_03004910 非零则走特效流程 sub_80094FC。
 * 逐项: 标志 gUnk_03000010[i] 非零且未设 bit2 → 计算表内偏移:
 *   idx = gUnk_03000020[i] >> gUnk_03000018[i];  byte = gUnk_03000038[i][idx];
 *   src = gMenuEntityPaletteTable + (byte << 5) + 2;  → DMA3 拷贝 32 字节到 gUnk_03000028[i]。 */
extern const u8 gMenuEntityPaletteTable[];

// @ 0x08009370
void sub_8009370(void)
{
    s16 i;

    if (gUnk_03004910 != 0)
    {
        sub_80094FC();
    }
    else
    {
        PalTransfer_Flush();
        for (i = 0; i <= 3; i++)
        {
            if (gUnk_03000010[i] != 0 && (gUnk_03000010[i] & 4) == 0)
            {
                u32 src;
                u32 off;
                u8 *base;

                off = ((u32)(*(u8 *)(gUnk_03000038[i] + (gUnk_03000020[i] >> gUnk_03000018[i]))) << 5) + 2;
                base = (u8 *)gMenuEntityPaletteTable;
                src = (u32)(base + off);
                DmaSet(3, src, gUnk_03000028[i], 0x80000010);
            }
        }
    }
}

/* 调色板特效状态复位 (调色板暂存 0x0203E600, 备份 0x0203EA00):
 * mode: 1/7=白闪(开 WIN0 窗口), 3=黑闪, 5=备份当前调色板, 其他=从备份恢复。
 * 0x03004910 = mode+1 (供其他特效读取), 0x03004914/0x03004918 = 计时器清零。 */
extern u8 gUnk_03004914;
extern u8 gUnk_03004918;

// @ 0x08009428
void PaletteFx_Apply(u8 arg0)
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
            Palette_Backup();
            DmaCopy16(3, (void *)0x0203EA00, (void *)0x0203E600, PLTT_SIZE);
            break;

        default:
            DmaCopy16(3, (void *)0x0203EA00, (void *)0x0203E600, PLTT_SIZE);
            break;
    }
}

/* 调色板特效逐帧驱动 (PaletteFx_Apply 之后每帧调用):
 * 若 gUnk_03004914 置位 → 按 gUnk_03004918 & 3 选中 4 个调色板暂存区之一,
 *   DMA3 拷贝 0x80 半字到调色板 RAM 对应 0x100 字节段 (0x05000000 + idx*0x100)。
 * 之后清标志、计数器 +1。mode==2/7 (白闪) 且计数器超过阈值 (0x40/0x20) 时
 *   重新断言 WIN0 窗口, 并复位 gUnk_03004910/gSceneSubState。
 * 计数器到 4 时把窗口完全打开 (WIN0V=0x100, WININ/WINOUT=0x3F)。
 * 注: 两个分支内的 u8 局部读取 gUnk_03004910 是**故意**的 —— 让 GCC2 不跨分支
 *   CSE 该读, 使计数器 c 落 r1、state 落 r0 并重读, 与目标逐字节一致。 */
// @ 0x080094FC
void sub_80094FC(void)
{
    u8 counter;
    u32 src;
    u32 c;

    if (gUnk_03004914 == 0)
        return;

    counter = gUnk_03004918 & 3;
    switch (counter) {
    case 0: src = 0x0203E600; break;
    case 1: src = 0x0203E700; break;
    case 2: src = 0x0203E800; break;
    case 3: src = 0x0203E900; break;
    default: break;
    }

    DmaSet(3, src, 0x05000000 + (counter << 8), 0x80000080);

    gUnk_03004914 = 0;
    c = gUnk_03004918 + 1;
    gUnk_03004918 = c;

    if (gUnk_03004910 > 6) {
        if ((u8)c > 0x20) {
            u8 s2 = gUnk_03004910;
            if (s2 == 7) {
                REG_WIN0H = 0xF0;
                REG_WIN0V = 0xA0;
                REG_DISPCNT |= DISPCNT_WIN0_ON;
                REG_WININ = 0;
                REG_WINOUT = 0;
            }
            gUnk_03004910 = 0;
            gSceneSubState = 0;
        }
    } else if ((u8)c > 0x40) {
        u8 s3 = gUnk_03004910;
        if (s3 == 2) {
            REG_WIN0H = 0xF0;
            REG_WIN0V = 0xA0;
            REG_DISPCNT |= DISPCNT_WIN0_ON;
            REG_WININ = 0;
            REG_WINOUT = 0;
        }
        gUnk_03004910 = 0;
        gSceneSubState = 0;
    }

    if (gUnk_03004918 == 4) {
        REG_WIN0H = 0xF0;
        REG_WIN0V = 0x100;
        REG_WININ = 0x3F;
        REG_WINOUT = 0x3F;
    }
}

// @ 0x08009600
INCLUDE_ASM("asm/nonmatchings", sub_8009600);
// @ 0x08009A5C
void MenuEnt_ClearStates(void)
{
    s16 i;

    for (i = 0; i < 4; i++)
    {
        gUnk_03000010[i] = 0;
    }
}
/* 选项/菜单条目描述表 (0x087EA138): 每项指向 {u8 count; count 条变长记录}, 由 MenuEnt_ParseDesc 逐条解析 */
extern u8 *gUnk_087EA138[];

/* 解析 gUnk_087EA138[arg0-1] 组的全部条目 (条目 id 从 0 起, 写 0x02005000 区窗口) */
// @ 0x08009A7C
void MenuEnt_ParseAll(u8 arg0)
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
        src = MenuEnt_ParseDesc(i, src);

        count--;
        i++;
    }
}
/* 解析 gUnk_087EA138[arg1] 组的条目 id [arg0, arg0+count) 区间 */
// @ 0x08009AC4
void MenuEnt_ParseRange(u8 arg0, u8 arg1)
{
    u8 end;
    u8 cur;
    u8 *src = gUnk_087EA138[arg1];

    end = arg0 + *src++;
    cur = arg0;
    while (cur < end) {
        src = MenuEnt_ParseDesc(cur, src);
        cur++;
    }
}
// @ 0x08009B04
void MenuEnt_Unlock(u8 arg0)
{
    gUnk_03000010[arg0] &= 0xFB;
}
// @ 0x08009B1C
void MenuEnt_Lock(u8 arg0)
{
    gUnk_03000010[arg0] |= 4;
}

// @ 0x08009B34
u8 MenuEnt_GetState(u8 arg0)
{
    return gUnk_03000010[arg0];
}

// @ 0x08009B44
void Palette_Backup(void)
{
    DmaCopy16(3, PLTT, 0x0203EA00, PLTT_SIZE);
}

// @ 0x08009B64
void Palette_FillWhite(void)
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

// @ 0x08009B84
u8 *MenuEnt_ParseDesc(u8 arg0, u8 *src)
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
/* 静态地图物件图形槽装载: gUnk_0808EA0C 每组 8 字节 = 2 条 4 字节记录
 * {gfxIdx, palIdx, gfxSlot, palSlot}; 0xFF 记录跳过。
 * gfx: LZ77 → 0x06010000 + gfxSlot*0x20; pal: 0x080BABA0[palIdx] → OBJ PLTT 0x05000380+palSlot*0x20。
 * 槽号存入 gUnk_0300496C/gUnk_03004970 (StaticObjs_Spawn 用)。 */
extern u8 gUnk_0808EA0C[][8];
extern u8 gUnk_0300496C[];
extern u8 gUnk_03004970[];

extern u8* gUnk_087EA33C[];

extern u16 gUnk_080BABA0[][16];

extern u16* gUnk_087EA38C[];
extern u8* gUnk_087EA368[];

// @ 0x08009BF0
void StaticObjGfx_LoadPair(u8 arg0) {
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

/* 静态地图物件生成: 从 gUnk_087EA38C[arg0-1] 指向的描述块读
 * {u16 count} + count × {u8 gfxSlot, u8 高字节, u16 x, u16 y, u16 z},
 * 填入 gStaticMapObjects[0..count-1]: field_C = 描述半字高字节, field_2/field_3(pal) = 图形槽 idx/+12,
 * dataPtr = gUnk_087EA368[palSlot] 动画描述, field_0=1 激活, 其余清零。 */
// @ 0x08009C84
void StaticObjs_Spawn(u8 arg0) {
    u16 var_r5;
    u8 idx;
    StaticMapObject* staticObj;
    u16* src;

    if (arg0 != 0) {
        arg0--;
        staticObj = gStaticMapObjects;
        src = gUnk_087EA38C[arg0];
        var_r5 = *src;
        src++;

        while(var_r5 != 0)
        {
            idx = *src;

            staticObj->field_C = *src & 0xFF00;
            src++;
            staticObj->x = *src;
            src++;
            staticObj->y = *src;
            src++;
            staticObj->z = *src;
            src++;
            staticObj->field_2 = gUnk_0300496C[idx];
            staticObj->field_3 = idx + 12;

            staticObj->dataPtr = gUnk_087EA368[gUnk_03004970[idx]];

            staticObj->field_0 = 1;
            staticObj->animTimer = 0;
            staticObj->field_1 = 0;
            staticObj->field_E = 0;

            var_r5--;
            staticObj++;

        }
    }
}

/* ⚠ code_0.h 里的 u8 返回类型会生成 lsls/cmp 截断; 目标是直接 cmp。
 * 本 TU 内用宏把调用改指到 s32 原型的本地别名 (同一 ROM 符号, 链接期同一地址)。 */
s32 Sprite_EnqueueRender_S32(u16, u16, u8, u16, u8);

/* 静态地图物件逐帧动画: 遍历 gStaticMapObjects[3] (field_0=激活):
 * animTimer != 0xFF 时按 dataPtr 动画描述换帧 (描述: {u16 首帧偏移, u16 帧时长, u16 帧数, u16 loop 偏移, ...});
 * 每 4 字节一条帧记录, 到点后通过 Sprite_InitChainNode 链重建精灵段 (StaticObj_BuildChain)。
 * 最后用 Sprite_EnqueueRender(x, y, sprNodeIdx, z, 3) 入渲染队列, 返回值写 field_E bit3 (被遮挡)。
 * gUnk_03004D4C != 0 (菜单打开) 时整帧跳过。 */
void StaticObj_BuildChain(u8, u8*);

// @ 0x08009D34
void StaticObjs_StepAll() {
    s16 var_ip;
    StaticMapObject* var_r7;
    s16 x;
    u8* src;
    u8* arr;
    u8* framePtr;
    u16 maxDuration;
    u16 loopCount;
    struct SpriteNode* renderObj;
    struct SpriteNode* nextRenderObj;

    if (gUnk_03004D4C != 0) {
        return;
    }
    var_r7 = gStaticMapObjects;

    for(var_ip = 0; var_ip < 3; var_ip++)
    {
        if(var_r7->field_0 != 0)
        {
            src = var_r7->dataPtr;
            if(var_r7->animTimer != 0xFF)
            {
                framePtr = src + (src[2] + (src[3] << 8));
                if(var_r7->animTimer == 0)
                {
                    framePtr = src + src[framePtr[8] * 2 + 8] + 4;
                    StaticObj_BuildChain(var_ip,  framePtr);
                    var_r7->animTimer++;
                }
                else
                {
                    if((var_r7->field_E & 8) == 0)
                    {
                        maxDuration = (framePtr[2] + (framePtr[3] << 8));
                        loopCount =  (framePtr[6] + (framePtr[7] << 8));
                        framePtr = framePtr + 8;
                        if(var_r7->animTimer >= maxDuration)
                        {
                            var_r7->animTimer = 0;
                        }
                        while(loopCount != 0)
                        {
                            if( var_r7->animTimer == (framePtr[2] + (framePtr[3] << 8)) || var_r7->animTimer == 0)
                            {
                                renderObj = &gSpriteNodePool[var_r7->field_1];
                                renderObj->flags = 0;
                                nextRenderObj = renderObj->next;
                                while(nextRenderObj != 0)
                                {
                                    renderObj->next = 0;
                                    renderObj = nextRenderObj;
                                    renderObj->flags = 0;
                                    nextRenderObj = renderObj->next;
                                }

                                if(var_r7->animTimer == 0)
                                {
                                    arr = src + src[framePtr[0] * 2 + 8] + 4;
                                }
                                else
                                {
                                    arr = src + src[framePtr[4] * 2 + 8] + 4;
                                }

                                StaticObj_BuildChain(var_ip, arr);
                                break;
                            }
                            framePtr+=4;
                            loopCount--;
                        }
                        if (var_r7->animTimer != 0xFF)
                        {
                            var_r7->animTimer++;
                        }
                    }
                }
            }

            if(Sprite_EnqueueRender_S32(var_r7->x, var_r7->y, var_r7->field_1, var_r7->z, 3) != 0)
            {
                var_r7->field_E |= 8;
            }
            else
            {
                var_r7->field_E &= ~8;
            }
        }


        var_r7++;
    }


}


/* 静态地图物件精灵段重建 (每帧动画换帧时调用):
 * var_r6 描述 = {u8 部件数相关偏移, u8, u8 部件数, u8, 之后 部件数 × 6 字节
 *   {u8 y, u8 高字节, u8 x, u8 高字节, u8 tileOffset, u8}}。
 * y 高字节拼进 attr0 (0x80<<7=0x4000 翻转位由 Sprite_InitChainNode 处理),
 * tileId 从 OBJ VRAM 基址 + tileOffset + 槽 field_2 选块, paletteId = field_3。 */
// @ 0x08009E80
void StaticObj_BuildChain(u8 arg0, u8* var_r6) {
    struct SpriteNode* subRenderObj;
    struct SpriteNode* renderObj;
    StaticMapObject* staticObj;
    u8 temp_r4;

    u16 temp_r3;
    u8 temp_sl;
    u8 var_r8;

    u8 r6_4;
    u8 r6_0;
    u16 r6_1;

    staticObj = &gStaticMapObjects[arg0];
    temp_r4 = var_r6[0] * 6 + 4;
    var_r8 = var_r6[2];

    staticObj->field_1 = Sprite_AllocNode();

    renderObj = &gSpriteNodePool[staticObj->field_1];

    temp_sl = staticObj->field_2;
    var_r6 = var_r6 + temp_r4;

    while(var_r8 != 0)
    {
        r6_4 = var_r6[4];
        r6_0 = var_r6[0];
        r6_1 = var_r6[1] << 8;
        temp_r3 = var_r6[2] | (var_r6[3] << 8);
        renderObj->tileOffsetX = temp_r3 & 0x1FF;
        r6_1 |= r6_0;
        renderObj->tileOffsetY = r6_0;

        subRenderObj = Sprite_InitChainNode(renderObj, var_r8, r6_1 , temp_r3,  ((staticObj->field_3 << 0xC) | staticObj->field_C | (r6_4 + temp_sl)));
        if (renderObj->tileOffsetX > 0xFFU) {
            renderObj->tileOffsetX--;
        }
        renderObj = subRenderObj;

        var_r6 += 6;

        var_r8--;
    }


}


// @ 0x08009F48
void StaticObjs_Reset(void)
{
    s16 i;

    for (i = 0; i < 3; i++)
    {
        gStaticMapObjects[i].field_0 = 0;
    }
}
/* 0x080921F0: 9 行 × 8 字节 — 职业(formation)× 八维属性 → 成长曲线号 (t, 0-40) */
extern const u8 gClassStatCurveTable[];
/* 0x080923D8: 按曲线号 t 划分的 100B/段成长表, 每段 [0]=段长, [1..] 逐级增量 */
extern const u8 gStatGrowthCurveTables[];

/* 属性成长查询: 按 (职业 classId, 等级 lv, 属性序号 statIdx) 返回该等级属性值。
 * - statIdx >= 8 && classId <= 10  → 10
 * - classId > 8: 特殊职业的固定值 (999 / 0 / 1 / 3 / 0xFF)
 * - 常规: t = gClassStatCurveTable[classId*8 + statIdx]; 累加
 *   gStatGrowthCurveTables[t*100 + 0..lv] (level+1 项), 全 0 且 statIdx==7 → 1
 * 调用点: sub_800A3C8 (队伍角色逐属性), sub_8048818 (战斗对象 formation)
 * 代码生成要点: ① switch(a) 每个 case 独立写 `return 10;`(合并成 case0..10 会被
 *   折叠成范围测试, 丢失跳表); ② `stride = t*100` 提前命名变量 (规则 30 分步形式);
 *   ③ while 循环比 do-while 更能复现 `cmp r2,r1; bhi` 入口守卫; ④ 首格条件必须
 *   写 `c >= 8` (u8 归一化成 `cmp r4,#7; bls`);
 *   ⑤ 定义必须用 K&R 旧式风格 (与头文件 `u16 sub_8009F70();` 空形参声明配套):
 *      改成全原型会触发 GCC2 的 default-promotion 冲突报错, 且会让已匹配的
 *      调用方 sub_8048818 的 formation 寄存器分配从 r2 漂到 r3 (规则 7 的坑) */
// @ 0x08009F70
u16 sub_8009F70(classId, lv, statIdx)
u8 classId;
u8 lv;
u8 statIdx;
{
    u8 t;
    u16 sum;
    u16 i;
    u16 stride;

    if (statIdx >= 8 && classId <= 10) {
        switch (classId) {
        case 0: return 10;
        case 1: return 10;
        case 2: return 10;
        case 3: return 10;
        case 4: return 10;
        case 5: return 10;
        case 6: return 10;
        case 7: return 10;
        case 8: return 10;
        case 9: return 10;
        case 10: return 10;
        }
    }
    if (classId > 8) {
        switch (statIdx) {
        case 0:
            return 0x3E7;
        case 1:
            if (classId == 9)
                return 0x3E7;
            return 0;
        case 7:
            if (classId == 9)
                return 1;
            return 3;
        }
        return 0xFF;
    }

    t = gClassStatCurveTable[classId * 8 + statIdx];
    stride = t * 100;
    sum = 0;
    i = 0;
    while (i <= lv) {
        sum = (u16)(sum + gStatGrowthCurveTables[stride + i]);
        i = (u16)(i + 1);
    }
    if (sum == 0 && statIdx == 7)
        sum = 1;
    return sum;
}
/* 0x08093418: 48 项 × 5 字节的表 (在 data/data.s 的 blob 里, 尚无独立符号) —— **名字未定**:
 *   [1] 高 4 位 = 分组号 (实测分布 0:8 2:6 3:8 4:8 5:8 6:4 7:2 15:4 项), 低 4 位含义未定
 *   [4] = 一个数值 (`ItemGetValue` 直接返回它)
 *   [0] 有两种呸此矛盾的读法, 未定谁对:
 *     - 本函数: `[0] <= lv + 1`  →  像"所需等级"; 0xFF = 特殊值
 *     - ItemFindSlot: `[0] == arg0 + 1`  →  像"物品/技能 id"
 *   写入的是 **表下标+1** (所以 skills[] 存的是行号, 0xFF = 空)
 * → 等 `ItemFindSlot` / `ItemGetValue` 的调用方语义查清后再统一改名。*/
extern u8 gUnk_08093418[];

/* 从 gUnk_08093418 筛出满足条件的行, 把 **行号+1** 填进 PlayerStats.skills[8],
 * 不足 8 个用 0xFF 补齐。
 *
 * 入选条件: [1] 高 nibble == groupId (groupId<=1 归为 0), 并且
 *   [0] == 0xFF  →  仅当 gPartyMemberIds[0] == 1
 *   [0] != 0xFF  →  [0] <= lv + 1
 *
 * 调用点: Chara_ClearTempStatus / sub_800A1B4 / sub_800A3C8 / sub_80457AC (共 4 处)
 *
 * 代码生成要点 (已逐字节验证):
 *   - `lv + 1` 必须写成对 u8 形参的算术, GCC2 会归一成 `(lv<<24) + (1<<24)` 再 `>>24`
 *     (与直接 `adds #1` 不同, 目标就是后者)
 *   - 两个分支都写 `flag = 1` 而不是 `goto`: GCC2 的 jump-threading 会自动把
 *     "[0]==0xFF 且 pid==1" 那条路直接跳到接受块 (ROM 就是 `b accept` 绕过 `cmp flag,#0`)
 *   - 本函数使用 r8/sb → 有 GCC2 跳函数泄漏风险 (规则 51), 合入后必须看全量 SHA1
 */
// @ 0x0800A048
void Stats_BuildSkillList(u8 *skills, u8 lv, u8 groupId)
{
    u8 i;
    u8 count;
    u8 flag;
    u8 lvLimit;

    lvLimit = lv + 1;
    if (groupId <= 1)
        groupId = 0;
    count = 0;
    for (i = 0; i <= 0x2F; i++)
    {
        if (groupId != (gUnk_08093418[i * 5 + 1] >> 4))
            continue;
        flag = 0;
        if (gUnk_08093418[i * 5] == 0xFF)
        {
            if (gPartyMemberIds[0] == 1)
                flag = 1;
        }
        else if (gUnk_08093418[i * 5] <= lvLimit)
            flag = 1;
        if (flag == 0)
            continue;
        *skills++ = i + 1;
        count++;
    }
    while (count <= 7)
    {
        *skills++ = 0xFF;
        count++;
    }
}
// @ 0x0800A0E4
u8 Chara_GetFormGfx(u8 arg0)
{
    u8 var_r2;
    PlayerStats *ptr;

    if (arg0 != 0)
    {
        arg0 -= 1;
    }

    ptr = &gPartyStats[arg0];
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
// @ 0x0800A1B4
INCLUDE_ASM("asm/nonmatchings", sub_800A1B4);
// @ 0x0800A3C8
INCLUDE_ASM("asm/nonmatchings", sub_800A3C8);

extern u8 gUnk_087EA580[];

/* 装备加成结算 (按敌人/角色数据表 gUnk_087EA580 的 12B 条目):
 *  arg0 = 角色/敌人 ID (0 直接返回)。
 *  表项 +8 的防御字节: 低 4 位 -1 选一个装备加成栏 += 表项 +6 (HP);
 *                     高 4 位 -1 选一个装备加成栏 += 表项 +7 (攻击)。
 *  7 个加成栏映射: 0=AtkBase 1=Def2 2=Agl 3=Men 4=Res 5=Noa 6=Luc。
 *  最后 ID 落在 [0x22,0x2B] 或 [0x37,0x3E] 时 Noa 额外 +1。
 * 匹配要点: `v = entry[8] & 0xF; if (v - 1 <= 6) switch (v - 1)` 的写法让
 *  val 装载落在 ands 与 subs 之间。第一分支的 `u8 bonusVal = entry[6]` 重读被
 *  CSE 合并成 val 的副本 (不增指令), 作用是缩短 val 的伪寄存器生命周期, 使
 *  其全局分配优先级高于 entry 基址 → val 落 r2/基址落 r3 (规则 112)。 */
// @ 0x0800A534
void sub_800A534(u8 arg0)
{
    u8 *entry;
    u8 *dst;
    u8 val;
    u32 v;

    if (arg0 == 0)
        return;

    entry = &gUnk_087EA580[arg0 * 12];

    v = entry[8] & 0xF;
    val = entry[6];
    if (v - 1 <= 6) {
        u8 bonusVal = entry[6];
        switch (v - 1) {
        case 0: dst = &gEquipBonusAtkBase; break;
        case 1: dst = &gEquipBonusDef2; break;
        case 2: dst = &gEquipBonusAgl; break;
        case 3: dst = &gEquipBonusMen; break;
        case 4: dst = &gEquipBonusRes; break;
        case 5: dst = &gEquipBonusNoa; break;
        case 6: dst = &gEquipBonusLuc; break;
        }
        *dst += bonusVal;
    }

    v = entry[8] >> 4;
    val = entry[7];
    if (v - 1 <= 6) {
        switch (v - 1) {
        case 0: dst = &gEquipBonusAtkBase; break;
        case 1: dst = &gEquipBonusDef2; break;
        case 2: dst = &gEquipBonusAgl; break;
        case 3: dst = &gEquipBonusMen; break;
        case 4: dst = &gEquipBonusRes; break;
        case 5: dst = &gEquipBonusNoa; break;
        case 6: dst = &gEquipBonusLuc; break;
        }
        *dst += val;
    }

    if ((u8)(arg0 - 0x22) <= 9 || (u8)(arg0 - 0x37) <= 7)
        gEquipBonusNoa += 1;
}
// @ 0x0800A664
INCLUDE_ASM("asm/nonmatchings", sub_800A664);

// @ 0x0800A79C
void Stats_RecalcEquip(u8 arg0)
{
    PlayerStats *chara;

    if (arg0 != 0)
        arg0--;
    chara = &gPartyStats[arg0];

    chara->equip_atc = gEquipBonusAtkBase;
    chara->equip_def = gEquipBonusDef2;
    chara->equip_agl = gEquipBonusAgl;
    chara->equip_men = gEquipBonusMen;
    chara->equip_res = gEquipBonusRes;
    chara->equip_noa = gEquipBonusNoa;
    chara->equip_luc = gEquipBonusLuc;

    chara->equip_atc += gEquipBonusAtk;
    chara->equip_def += gEquipBonusDef;

    chara->atc = chara->base_atc + chara->equip_atc;
    chara->def = chara->base_def + chara->equip_def;
    chara->agl = chara->base_agl + chara->equip_agl;
    chara->men = chara->base_men + chara->equip_men;
    chara->res = chara->base_res + chara->equip_res;
    chara->noa = chara->base_noa + chara->equip_noa;
    chara->luc = chara->base_luc + chara->equip_luc;
}
extern u32 gUnk_08092248[];

// @ 0x0800A86C
u8 ExpToLevel(s32 value) {
    s32 ret;
    u8 i;

    if (value > 9999999) {
        value = 9999999;
    }

    i = 0;
    while(value >= 0)
    {
        value -= gUnk_08092248[i];
        i++;
    }

    return i - 1;
}
// @ 0x0800A8A0
u32 LevelToExp(u8 arg0) {
    u8 i;
    u32 sum = 0;

    for ( i = 0; i <= arg0; i++)
    {
        sum += gUnk_08092248[i];
    }
    return sum;

}

extern u8 gUnk_08093418[];

// @ 0x0800A8D0
u8 ItemFindSlot(u8 arg0, u8 arg1)
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

// @ 0x0800A924
void Party_InitStats(void)
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
// @ 0x0800A958
u8 ItemGetValue(u8 arg0) {
    return gUnk_08093418[(arg0 - 1) * 5 + 4];
}
// @ 0x0800A970
void sub_800A970(void* arg0) {
    *((u16*)arg0+1) = *((u16*)arg0 + 9);
}
// @ 0x0800A978
void sub_800A978(void* arg0) {
    *((u16*)arg0+2) = *((u16*)arg0 + 10);
}

//FullHealParty
// @ 0x0800A980
void FullHealParty(void)
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

        ptr = &gPartyStats[charaId];
        ptr->hp = ptr->max_hp;
        ptr->mp = ptr->max_mp;
    }
}
// @ 0x0800A9C0
void EquipItem(u8 arg0, u8 newEquip, u8 equipSlotId) {
    u8 oldEquip;
    u8 var_r0;
    u8* equipSlot;

    PlayerStats* chara;

    var_r0 = arg0;
    if (arg0 != 0) {
        var_r0 = arg0 - 1;
    }

    chara = &gPartyStats[var_r0];

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
    Stats_RecalcEquip(arg0);
}

// sub_800AA60 = AddInventoryItem
// @ 0x0800AA60
void sub_800AA60(u8 itemId, u8 count)
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

// sub_800AA84 = RemoveInventoryItem
// @ 0x0800AA84
void sub_800AA84(u8 itemId, u8 count)
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

// @ 0x0800AAA4
void Silver_Add(s32 arg0)
{
    gSilverAmount += arg0;

    if (gSilverAmount > 999999)
    {
        gSilverAmount = 999999;
    }
}
// @ 0x0800AAC0
void Silver_Sub(s32 arg0)
{
    gSilverAmount -= arg0;

    if (gSilverAmount > 999999)
    {
        gSilverAmount = 0;
    }
}
extern u8 gUnk_087EA580[];

// @ 0x0800AADC
u8 sub_800AADC(u8 arg0) {
    return gUnk_087EA580[arg0 * 12 + 4] & 0xF;
}
extern u8 gUnk_087EA580[];

// @ 0x0800AAF8
u16 sub_800AAF8(u8 arg0) {
    return gUnk_087EA580[arg0 * 12] + (gUnk_087EA580[arg0 * 12 + 1] << 8);
}
extern u8 gUnk_087EA580[];

// @ 0x0800AB18
u16 sub_800AB18(u8 arg0) {
    return gUnk_087EA580[arg0 * 12 + 2] + (gUnk_087EA580[arg0 * 12 + 3] << 8);
}

// @ 0x0800AB3C
u8 Party_AnyEquip(void)
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

        ptr = &gPartyStats[charaId];

        if (ptr->equip_slot1 != 0)
            return 1;
    }
    return 0;
}
// @ 0x0800AB7C
void Chara_ClearTempStatus(u8 arg0)
{
    PlayerStats *actor;
    if (arg0 <= 1)
    {
        actor = &gPartyStats[0];
        Stats_BuildSkillList(actor->skills, actor->lv, arg0);

        if (actor->field_unk[2] == 1 && (u8)(actor->field_unk[3] - 5) <= 3)
        {
            actor->field_unk[2] = 0;
            actor->field_unk[3] = 0;
        }
    }
}
// @ 0x0800ABBC
void Stats_ClearEquipBonus(void)
{
    gEquipBonusAtkBase = 0;
    gEquipBonusDef2 = 0;
    gEquipBonusAgl = 0;
    gEquipBonusMen = 0;
    gEquipBonusRes = 0;
    gEquipBonusNoa = 0;
    gEquipBonusLuc = 0;
    gEquipBonusAtk = 0;
    gEquipBonusDef = 0;
}
/* PartyForm_ApplyBonus — 队伍形态一致性检查 (0x0800AC08):
 * 4 名角色 (1-based id) 的种族/形态字节 (field_4 高 4 位) 全部相同时,
 * 若形态为 0xE/0xF (特殊形态) 则设置全队攻/防加成 (Stats_RecalcEquip 消费)。 */
// @ 0x0800AC08
void PartyForm_ApplyBonus(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    u8 val;
    EnemyCharaStat* p0, *p1, *p2, *p3;
    p0 = &gCharaBaseData[arg0];
    p1 = &gCharaBaseData[arg1];
    p2 = &gCharaBaseData[arg2];
    p3 = &gCharaBaseData[arg3];

    val = p0->formRace & 0xF0;

    if( val == (p1->formRace & 0xF0)
        && val == (p2->formRace & 0xF0)
        && val == (p3->formRace & 0xF0))
    {
        switch(val >> 4)
        {
            case 0xF:
                gEquipBonusAtk = 0x22;
                gEquipBonusDef = 0x2D;

                break;
            case 0xE:
                gEquipBonusAtk = 0x3C;
                gEquipBonusDef = 0x3F;
                break;
        }
    }
}


//FullHealCharacter
// @ 0x0800ACA4
void FullHealCharacter(u8 arg0)
{
    PlayerStats *ptr;

    if (arg0 != 0)
    {
        arg0--;
    }

    ptr = &gPartyStats[arg0];
    ptr->hp = ptr->max_hp;
    ptr->mp = ptr->max_mp;
}

// @ 0x0800ACC8
INCLUDE_ASM("asm/nonmatchings", sub_800ACC8);

// @ 0x0800B14C
void SceneBg_Reload(void)
{
    if (gUnk_03004D4C != 0) {
        if ((u8)(gUnk_03004D4C - 7) <= 4) {
            sub_8016068();
            return;
        }
        if (gUnk_03004D4C == 12) {
            sub_80160F4();
            MenuState_Reset();
            return;
        }
        if ((u8)(gUnk_03004D4C - 0x35) <= 7) {
            ReloadSpriteSheet(gUnk_03004D4C + 0xCD);
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
            MenuState_Reset();
        } else if ((u8)(gUnk_03004D40 + 0xF) <= 7) {
            ReloadSpriteSheet(gUnk_03004D40 + 0x11);
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

    if (gObjGraphicsSetId != 0xFF) {
        DmaCopy16(3, (void *)0x02004000, (void *)0x0600E000, 0x800);
        if (gObjGraphicsSetId != 0xFE)
            DmaCopy16(3, (void *)0x02004800, (void *)0x0600E800, 0x800);
    }
}
// @ 0x0800B2D0
void MenuState_Reset(void)
{
    u8 i;
    gMenuCursorGrp = 0;
    gMenuCursorSel = 0;

    gUnk_03000048.field_0 = 1;
    gUnk_03000048.field_1 = 0;
    gUnk_03000048.field_2 = 0;
    gUnk_03000048.field_3 = 0;
    gUnk_03000048.field_4 = 0x18;
    gUnk_03000048.field_6 = 8;

    for (i = 0; i < 16; i++)
    {
        gMenuCursorStack[i] = 0;
    }
}
// @ 0x0800B314
void MenuHp_Update(void)
{
    u8 i;

    if (gUnk_03000185 == 0)
        return;

    if (gUnk_03000184 == 4)
    {
        Menu_GetFocus();
        for (i = 0; i < 5; i++)
        {
            if (gPartyMemberIds[i] != 0xFF)
            {
                u8 y = i * 5 + 5;
                sub_80161F4(gPartyMemberIds[i], y, 5);
                Hud_DrawLv(gPartyMemberIds[i], y, 6);
            }
        }
    }

    gUnk_03000185 = 0;
}

// @ 0x0800B374
INCLUDE_ASM("asm/nonmatchings", sub_800B374);

/* 把一条消息 (字节编码字符串) 解码成一整行瓦片, 写进单行缓冲 gMsgLineBuf (u16[29])。
 *
 * 消息编码:
 *   0xFF = 结束
 *   0xFE = 转义前缀, 后跟一个高位字节 → 16 位码 ((hi << 8) | 0xFE)
 *   其它 = 直接作为 16 位字符/瓦片码
 * 输出布局: [0xC8 左边框] [N 个内容码] [0xC9 右边框] [0 补齐] —— 共 29 项 (count 到 0x1C)。
 * 边框与补齐固定用调色板 0xB (默认调色板, 见 Msg_ShowById 的实参),
 * 内容用调用者传的 palette。
 *
 * 调用者: Msg_ShowById (src/code_8010F10.c) 先在 gMsgTable 块里跳过 target 个 0xFF
 * 定位到第 target 条消息, 再交给本函数。Text_PutGlyph = 写一个 u16 瓦片项。
 *
 * 代码生成要点 (已逐字节验证):
 *   - `count` 必须是 **u16**: 自增生成 `adds r0,r6,#1; lsls #0x10; lsrs #0x10` (u16 截断)
 *   - 转义分支用 `|` 不用 `+`: 目标是 `orrs r1, r0` (规则 36)
 *   - 两个分支各自重复写一次 Text_PutGlyph 调用, **不能外提** (规则 38): 目标就是两份调用点
 *   - `dst++` 在目标里是 `adds r0,r5,#0; adds r5,#2` (先传后推), 不要写成 `*dst++` 以外的形式
 */
// @ 0x0800BEE4
void Msg_RenderLine(u8 *src, u8 palette)
{
    u16 *dst = gMsgLineBuf;
    u16 count;

    Text_PutGlyph(dst++, 0xC8, 0xB);
    count = 1;
    while (*src != 0xFF)
    {
        u16 ch = *src++;

        if (ch == 0xFE)
        {
            ch = (*src++ << 8) | 0xFE;
            Text_PutGlyph(dst++, ch, palette);
        }
        else
        {
            Text_PutGlyph(dst++, ch, palette);
        }
        count++;
    }

    Text_PutGlyph(dst++, 0xC9, 0xB);
    count++;
    while (count <= 0x1C)
    {
        Text_PutGlyph(dst++, 0, 0xB);
        count++;
    }
}
/* 重建 HUD 队伍精灵实体表 (gUiSprites, 15 项)。
 *
 * 前 5 项 = 队伍成员: 若 gPartyMemberIds[i] != 0xFF 则启用,
 *   x = i*40 + 0x48, y = 8, statusFlags = 0x80 (激活),
 *   field_10 = 基础图块起始 ID = i*48 + 0x200, oamSlotId = i + 0x71 (关联的渲染层 OAM 索引)
 * 其余项与空队伍槽一律清 x/y/statusFlags/oamSlotId;
 * 15 项都额外重置 animTimer = 0 与 lerpFrame = 0 (公共重置)。
 *
 * mode == 0 时多做一步: 调 MenuUi_SpawnAuxSprites(0) 并给实体[5] 的 statusFlags 置 bit3。
 *   (实体[5] 即 gUiSpritesAux, 偏移 0x64 = 5*20, 是第一个非队伍槽)
 * 调用点: sub_800ACC8 传 0, sub_801417C 传 1。
 *
 * 代码生成要点 (已逐字节验证):
 *   - `i` 必须是 **u16**: 自增生成 `adds; lsls #0x10; lsrs #0x10` (规则 68 同类)
 *   - 启用分支的乘法要写成 `i * 40` / `i * 48` 这种十进制常量:
 *     GCC2 拆成 `lsls #2; adds i; lsls #3` (= i*5*8) 与 `lsls #1; adds i; lsls #4` (= i*3*16),
 *     与目标一致; 换成移位形式或先算指针会改变指令数
 *   - 末尾必须写 `gUiSprites[5].statusFlags |= 8`, **不能**用 `gUiSpritesAux` 符号:
 *     目标是 `ldr r0,=0x03000058; adds r0,#0x64` (复用同一池项),
 *     用独立符号会改成 `ldr r0,=0x030000BC` 并多出一个字面池项 (实测多 20 字节)
 *   - `|=` 目标是 `movs r1,#8; orrs r1, r2` (先物化常量再或, 规则 5/76 同类)
 */
// @ 0x0800BF5C
void PartyUi_InitEntities(u8 mode)
{
    u16 i;

    for (i = 0; i < 15; i++)
    {
        if (i < 5 && gPartyMemberIds[i] != 0xFF)
        {
            gUiSprites[i].x = i * 40 + 0x48;
            gUiSprites[i].y = 8;
            gUiSprites[i].statusFlags = 0x80;
            gUiSprites[i].baseTileId = i * 48 + 0x200;
            gUiSprites[i].oamSlotId = i + 0x71;
        }
        else
        {
            gUiSprites[i].x = 0;
            gUiSprites[i].y = 0;
            gUiSprites[i].statusFlags = 0;
            gUiSprites[i].oamSlotId = 0;
        }

        /* 公共重置: 15 项全部清动画计时器与插值帧 */
        gUiSprites[i].animTimer = 0;
        gUiSprites[i].lerpFrame = 0;
    }

    if (mode == 0)
    {
        MenuUi_SpawnAuxSprites(0);
        gUiSprites[5].statusFlags |= 8;
    }
}
// @ 0x0800BFF8
INCLUDE_ASM("asm/nonmatchings", sub_800BFF8);

// @ 0x0800C0D8
void BattleIntro_Setup(void)
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
    Sprite_InitChainNode(obj, 1, attr0, attr1, attr2);

    gSpriteRenderQueue[0] = obj;

    CutsceneAnim_Load(0x4C, 0, 9);

    for (i = 0; i < 5; i++)
    {
        obj++;
        if (gPartyMemberIds[i] != 0xFF)
        {
            attr1 = 0x8028 + ((i * 5) << 3);
            attr2 = ((i + 3) << 12) + ((i * 3 * 16 + 0x200) & 0x3FF);
            Sprite_InitChainNode(obj, 1, 8, attr1, attr2);
            gSpriteRenderQueue[i + 1] = obj;
        }
        Chara_InitDialogArrow(i);
    }
}
// @ 0x0800C194
INCLUDE_ASM("asm/nonmatchings", sub_800C194);
// @ 0x0800C2F8
INCLUDE_ASM("asm/nonmatchings", sub_800C2F8);

// @ 0x0800E170
void MenuUi_SetEntityPos(u8 arg0, u8 arg1, u8 arg2)
{

    switch (arg0)
    {
        case 0:
            gUiSprites[arg2].x = arg2 * 0x28 + 0x48;
            gUiSprites[arg2].y = 8;
            break;
        case 1:
            gUiSprites[arg2].x = 0x28;
            gUiSprites[arg2].y = 8;

            break;
        case 2:
            gUiSprites[arg2].x = 0x30;
            gUiSprites[arg2].y = 16;
            break;
    }
    switch (arg1)
    {
        case 2:
            gUiSprites[arg2].statusFlags &= 0xBF;
            gUiSprites[arg2].statusFlags &= 0xFE;
            break;
        case 1:
            gUiSprites[arg2].statusFlags &= 0xBF;
            gUiSprites[arg2].statusFlags |= 1;
            break;
        case 0:
            gUiSprites[arg2].statusFlags |= 0x40;
            gUiSprites[arg2].statusFlags &= 0xFE;
            break;
    }
}

// @ 0x0800E244
INCLUDE_ASM("asm/nonmatchings", sub_800E244);

typedef struct {
u16 x;
u16 y;
} Vec2;

extern Vec2* gUnk_087EB1F4[];
extern Vec2* gUnk_087EB214[];
extern Vec2* gUnk_087EB22C[];

// @ 0x0800E668
void sub_800E668(u8 arg0) {
    Vec2* ptr;

    if (arg0 != 0xFF)
    {
        gMenuCursorStack[gMenuCursorGrp] = gMenuCursorSel;
        gMenuCursorGrp = arg0;
        gMenuCursorSel = gMenuCursorStack[gMenuCursorGrp];
        sub_8010624(0xFF, 0);
        gUnk_03000185 = 1;
    }

    gUnk_03000048.field_C = gUnk_03000048.field_4;
    gUnk_03000048.field_E = gUnk_03000048.field_6;


    if(gCutsceneActive == 0)
    {
        if(gUnk_03004D40 == 0)
        {
            ptr = &gUnk_087EB1F4[gMenuCursorGrp][gMenuCursorSel];
        }
        else
        {
            ptr = &gUnk_087EB22C[gMenuCursorGrp][gMenuCursorSel];
        }
    }
    else
    {
        ptr = &gUnk_087EB214[gMenuCursorGrp][gMenuCursorSel];
    }

    gUnk_03000048.field_8 = ptr->x;
    gUnk_03000048.field_A = ptr->y;

    gUnk_03000048.field_2 = 8;
    gUnk_03000048.field_0 &= 0xFE;

}

// @ 0x0800E71C
INCLUDE_ASM("asm/matchings", UiSprite_BeginSlide);
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

UI 精灵实体滑动设定 (UiSprite_BeginSlide, asm 已匹配; 下方为等价 C 草稿):
   当前 x/y 存为移动起点 moveStart(0x0C/0x0E), 按模式算终点 moveEnd(0x08/0x0A),
   lerpFrame=8 启动插值 (UiSprites_Update 每帧消费)。
   mode 1: 终点 (0x28, 8);  mode 0: 终点 (idx*0x28+0x48, 8);
   其他:   按 gPartyMemberIDs[idx] 在编队 gFormationIDs[5] 里的位次 +2 查
           gPositionTable 得 (x+0x18, y+8)。
// @ 0x0800E71C
void UiSprite_BeginSlide(u8 idx, u8 mode) {
    UISpriteEntity* sprite;
    u8 ch_id;
    u8 i;
    u16 tbl_idx;
    u16 x, y;

    if(idx == 0xFF)
        return;

    sprite = &gUiSprites[idx];

    sprite->moveStartX = sprite->x;
    sprite->moveStartY = sprite->y;


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

    sprite->moveEndX = x;
    sprite->moveEndY = y;
    sprite->lerpFrame = 8;
}
*/
/* 菜单/UI 精灵实体的逐帧更新 (由 sub_8014488 与 sub_800C194 每帧调用):
 *   1. 遍历 15 个 gUiSprites (bit7=激活):
 *      - lerpFrame != 0: 8 步定点点插值 (LERP_POS, asrs#3), 走完贴合 moveEnd;
 *      - baseTileId 选片: bit0 动画模式 (animTimer bit3 翻转选 +0/0x10 半片),
 *        bit1 固定 +0x60 变体, 其余直用 baseTileId;
 *      - 把 x/y 写进关联 SpriteNode (gSpriteNodePool[oamSlotId]) 的 OAM 属性:
 *        attr0 <- y (低 8 位), attr1 <- x-0x20 (低 9 位), attr2 <- tileId
 *        (bit2/3 变体: 从 0x5000/0x6000 窗口字库行选块, 直接清低 10 位加 tileId)。 */
// @ 0x0800E7BC
void UiSprites_Update(void) {
    u8 step;
    u16 i;

    u16 dx, dy;
    u16 tileId;

    UISpriteEntity* sprite;
    struct SpriteNode* node;

    sprite = gUiSprites;

    for (i = 0; i < 15; i++, sprite++)
    {
        if(!(sprite->statusFlags & 0x80)) continue;

        if(sprite->lerpFrame != 0)
        {
            sprite->lerpFrame--;
            if(sprite->lerpFrame != 0)
            {
                dx = sprite->moveEndX - sprite->moveStartX;
                dy = sprite->moveEndY - sprite->moveStartY;
                step = 8 - sprite->lerpFrame;

                sprite->x = LERP_POS(sprite->moveStartX, dx, step);
                sprite->y = LERP_POS(sprite->moveStartY, dy, step);
            }
            else
            {
                sprite->x = sprite->moveEndX;
                sprite->y = sprite->moveEndY;
            }
        }

        if(sprite->statusFlags & 0x1)
        {
            if(sprite->statusFlags & 0x2)
            {
                tileId = sprite->baseTileId + 0x60;
            }
            else
            {
                sprite->animTimer++;
                tileId = ((sprite->animTimer & 8) << 1) + sprite->baseTileId;
            }
        }
        else
        {
            tileId = sprite->baseTileId;
        }

        node = &gSpriteNodePool[sprite->oamSlotId];

        SET_OAM_Y(node->attr0, sprite->y);
        SET_OAM_X(node->attr1, sprite->x - 0x20);

        if (sprite->statusFlags & 0x04)
        {
            if (sprite->statusFlags & 0x08)
            {
                node->attr2 = (node->attr2 & OAM2_PRIORITY) + tileId - 0x6000;
            }
            else
            {
                node->attr2 = (node->attr2 & OAM2_PRIORITY) + tileId - 0x5000;
            }
        }
        else
        {
            node->attr2 = (node->attr2 & 0xFC00) + tileId;
        }
    }
}
// @ 0x0800E8F8
INCLUDE_ASM("asm/nonmatchings", sub_800E8F8);
// @ 0x0800EAE4
INCLUDE_ASM("asm/nonmatchings", sub_800EAE4);

extern u8* gUiSpritesAuxDesc[];

/* 菜单辅助精灵生成 (PartyUi_InitEntities mode==0 与 sub_800E244 调用):
 * src = gUiSpritesAuxDesc[arg0]; count = *src++;
 * 前 count 项写 gUiSpritesAux[i]: {u8 x→field_4, u8 y→field_6, statusFlags=0x84,
 *   baseTileId = 0x380 + byte3, oamSlotId = i+0x76 (SpriteNode 池槽), animTimer/lerpFrame = 0},
 * 并 Sprite_InitChainNode(&gSpriteNodePool[oamSlotId], 1, y, x|0x4000, 0xB000|(tile&0x3FF))
 *   (attr0=y 局部变量缓存跨越中间存储 → 目标 r2 存活到 mov ip, r2; attr1 的 0x4000 = X 翻转)。
 * 余下 i..9 清 statusFlags = 0。 */
/* 菜单辅助精灵生成 (待匹配; 语义已完整还原, 卡点 = 零常量/常量池的寄存器分配选择):
 *   src = gUiSpritesAuxDesc[arg0]; count = *src++;
 *   前 count 项写 gUiSpritesAux[i]: {u8 x→field_4, u8 y→field_6, statusFlags=0x84,
 *   baseTileId = 0x380 + byte3, oamSlotId = i+0x76, animTimer/lerpFrame = 0},
 *   并 Sprite_InitChainNode(&gSpriteNodePool[oamSlotId], 1, y, x|0x4000, 0xB000|(tile&0x3FF))
 *   (attr0 = y 经 ip 传递, r2 从 ldrb 起跨整个循环体存活; attr1 的 0x4000 = X 翻转)。
 *   余下 i..9 清 statusFlags = 0。
 *   调用点: PartyUi_InitEntities (mode==0), sub_800E244。
 * 卡点: 目标零常量分配到 sb (`movs r2,#0; mov sb,r2`), 0x4000/0x3FF 常量直接经 r2 物化;
 * 本侧分配到 r9 且常量走 ip 中转 (多余 mov 对) —— 需 permuter 探索声明顺序。
 *
// @ 0x0800EB98
void MenuUi_SpawnAuxSprites(u8 arg0) {
    u8 y;
    u8* src;
    u8 count;
    u8 i;
    UISpriteEntity* obj;

    src = gUiSpritesAuxDesc[arg0];
    count = *src++;
    obj = gUiSpritesAux;

    for(i = 0; i < count; i++)
    {
        obj->x = *src++;
        y = *src;
        obj->y = y;
        src++;
        obj->statusFlags = 0x84;
        obj->baseTileId = (0xE0 << 2) + (*src++);
        obj->oamSlotId = i + 0x76;
        obj->animTimer = 0;
        obj->lerpFrame = 0;

        Sprite_InitChainNode(&gSpriteNodePool[obj->oamSlotId], 1, y, obj->x | 0x4000, (obj->baseTileId & 0x3FF) | 0xB000);
        obj++;
    }

    while(i < 10)
    {
        obj->statusFlags = 0;
        obj++;
        i++;
    }
}
*/
// @ 0x0800EB98
INCLUDE_ASM("asm/matchings", MenuUi_SpawnAuxSprites);


// @ 0x0800EC54
INCLUDE_ASM("asm/nonmatchings", sub_800EC54);
// @ 0x0800F128
INCLUDE_ASM("asm/nonmatchings", sub_800F128);
// @ 0x0800F3AC
INCLUDE_ASM("asm/nonmatchings", sub_800F3AC);

extern u8 gUnk_03000199;
extern u8 gUnk_030001A0[];
extern u8 gUnk_03004980[];


extern const u8 gUnk_08095028[][8]; // 物品/名称字符串表 (data_805769C.c / blob), [id] = 8 字符名

static inline void drawSome(u8 var_r7, u8 idx, u8 plttIdx)
{
    u8 i;
    u8* src;
    u16* dst;
    u8 ch;
    u8 x, y;
    
    x = (var_r7 & 1) * 13 + 3;
    y = (var_r7 & 0xFE) + 6;

    if(idx)
    {
        src = gUnk_08095028[idx];
        dst = (u16*)0x2005800 + x + ( y * 32);
        
        for(i = 0; i < 8; i++)
        {
            ch = *src++;
            if(ch == 0 )
            {
                break;
            }
            Text_PutGlyph(dst++, ch, plttIdx);
        }
    }

}



// @ 0x0800F4A8
void MenuUi_DrawItemList(void) {
    u8 idx;

    u8 var_r7;
    s32 x;
    u8 y;
    u8* src;
    u16* dst;
    u8 plttIdx;
    u8 i;
    u8 ch;
    u8 val;
    u8 x1;
    u16* dst1;

    ClearBuffer((u16* )0x02005986, 0x18, 0xA);

    idx = gUnk_03000199;

    if(idx == 0) idx = 1;

    var_r7 = 0;
            

    while(idx <= 0xFD)
    {
        val = gUnk_03004980[idx];
        if(val != 0)
        {
            gUnk_030001A0[var_r7] = idx;

            if(gMenuCursorStack[gMenuCursorGrp] == var_r7)
            {
                x = (var_r7 & 1) * 13 + 3;
                y = (var_r7 & ~1) + 6;

                if(idx)
                {
                    src = gUnk_08095028[idx];
                    dst = (u16*)0x2005800 + x + ( y * 32);
                    
                    for(i = 0; i < 8; i++)
                    {
                        ch = *src++;
                        if(ch == 0 )
                        {
                            break;
                        }
                        Text_PutGlyph(dst++, ch, 0xD);
                    }
                }
            }
            else
            {
                x = (var_r7 & 1) * 13 + 3;
                                y = (var_r7 & ~1) + 6;

                if(idx)
                {
                    src = gUnk_08095028[idx];
                    dst = (u16*)0x2005800 + x + ( y * 32);
                    
                    for(i = 0; i < 8; i++)
                    {
                        ch = *src++;
                        if(ch == 0 )
                        {
                            break;
                        }
                        Text_PutGlyph(dst++, ch, 0xB);
                    }
                }
            }
                x1 = (var_r7 & 1) * 13 + 13;
                dst1 = (u16*)0x02005980 + x1 + ((var_r7 & ~1) * 32); 
            sub_800EAE4(dst1, val, 12);
            var_r7++;
            
        }

        idx++;
        if(var_r7 > 9)
        {
            break;
        }

    }
    
    while(var_r7 <= 9)
            {
                gUnk_030001A0[var_r7] = 0;
                var_r7++;
            }

  
    gUnk_03000199 = gUnk_030001A0[0];
}


extern u8 gInvPageUpItems[];
extern u8 gInvPageDownItems[];

/* 从 gUnk_03004980 物品/事件表中, 以 gInvViewState[0] 为起点向下、
 * 以 gInvViewState[9] 为起点向上, 各最多拾取 2 个非零项到
 * gInvPageUpItems[] / gInvPageDownItems[]。 */
// @ 0x0800F670
void sub_800F670(void)
{
    u8 idx;
    u8 count;

    idx = gInvViewState[0];
    gInvPageUpItems[0] = 0;
    gInvPageUpItems[1] = 0;
    idx = (u8)(idx - 1);
    if (idx != 0xFF)
    {
        count = 0;
        while (count <= 1 && idx != 0)
        {
            if (gUnk_03004980[idx] != 0)
            {
                gInvPageUpItems[count] = idx;
                count = (u8)(count + 1);
            }
            idx = (u8)(idx - 1);
        }
    }

    gInvPageDownItems[0] = 0;
    gInvPageDownItems[1] = 0;
    idx = gInvViewState[9];
    if (idx != 0 && idx != 0xFF)
    {
        idx = (u8)(idx + 1);
        count = 0;
        while (count <= 1 && idx <= 0xFD)
        {
            if (gUnk_03004980[idx] != 0)
            {
                gInvPageDownItems[count] = idx;
                count = (u8)(count + 1);
            }
            idx = (u8)(idx + 1);
        }
    }
}

// @ 0x0800F70C
INCLUDE_ASM("asm/nonmatchings", sub_800F70C);
// @ 0x0800FA24
INCLUDE_ASM("asm/nonmatchings", sub_800FA24);
// @ 0x0800FB2C
INCLUDE_ASM("asm/nonmatchings", sub_800FB2C);
// @ 0x0800FDEC
INCLUDE_ASM("asm/nonmatchings", sub_800FDEC);
// @ 0x0800FF10
INCLUDE_ASM("asm/nonmatchings", sub_800FF10);
// @ 0x08010170
INCLUDE_ASM("asm/nonmatchings", sub_8010170);
// @ 0x0801026C
u8 ItemGetUsePower(u8 arg0, u8 arg1)
{

    PlayerStats *ptr4AC0;
    u8 val;

    if (arg0 != 0)
        arg0--;

    ptr4AC0 = &gPartyStats[arg0];

    val = ItemGetValue(arg1);

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

// @ 0x08010300
INCLUDE_ASM("asm/nonmatchings", sub_8010300);
u8 EventFlags_Test(u16);
extern u8 gUnk_080987C4[];

// @ 0x08010434
u8 WarpTable_Check(void)
{
    u8 i;
    u8 val;

    if (EventFlags_Test(0xBA))
        return 0;

    i = 0;
    while ((val = gUnk_080987C4[i]) != 0) {
        if (val == gCurrentMapId) {
            i++;
            gMapNpcSetId = gUnk_080987C4[i++];
            gSpawnTileX = gUnk_080987C4[i++];
            gSpawnTileY = gUnk_080987C4[i++];
            gSpawnFacingDir = gUnk_080987C4[i++];
            gMoveCmdSetId = gUnk_080987C4[i]  + (gUnk_080987C4[i+1] << 8);
            gWarpAnimState = 1;
            gUnk_03004D4C = 0x34;
            return 1;
        }
        i += 7;
    }

    return 0;
}

// @ 0x080104F8
INCLUDE_ASM("asm/nonmatchings", sub_80104F8);
// @ 0x08010624
INCLUDE_ASM("asm/nonmatchings", sub_8010624);
// @ 0x08010770
INCLUDE_ASM("asm/nonmatchings", sub_8010770);

extern const u8 gScreenIdleIconPageMap[];

/* 收集已看过的开场整屏图: 遍历 gScreenIdleEventFlags 的 bit 0..14,
 * 把对应地图 ID (gScreenIdleIconPageMap[i]) 依次填进 gScreenIdleIconIds 并以 0 补满 16 项,
 * 最后游标归零。调用点: sub_800ACC8 (菜单场景初始化)。
 * 消费者: sub_800C2F8 (游标/翻页) + sub_800F3AC (逐项绘制地点图标)。 */
// @ 0x08010978
void ScreenIdleIcons_BuildList(void)
{
    u8 i;
    u8 i2;

    if (EventFlags_Test(0xFD))
        gScreenIdleEventFlags[1] |= 0x20;

    for (i = 0, i2 = 0; i <= 0xE; i++) {
        if ((gScreenIdleEventFlags[i >> 3] >> (i & 7)) & 1)
        {
            gScreenIdleIconIds[i2] = gScreenIdleIconPageMap[i];
            i2++;
        }
    }

    while (i2 <= 0xF)
    {
        gScreenIdleIconIds[i2] = 0;
        i2++;
    }

    gScreenIdleIconCursor = 0;
}
