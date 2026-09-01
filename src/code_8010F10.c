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

INCLUDE_ASM("asm/nonmatchings", sub_8010F10);

extern u8 gUnk_08095828[][8];

void sub_801114C(void)
{
    u16 i;
    u8 j;
    u8 idx;
    PlayerStats *chara;
    u8 paletteId;
    u8* src;
    u16* dest;
    u8 charCode;
    u8 y;
    
    idx = gPartyMemberIds[gPartyMenuIdx];
    if(idx != 0) idx--;
    chara = &gPartyStats[idx];

    ClearBuffer( (u16* )0x02005AA0, 8, 6);

    for(i = 0; i < 3; i++)
    {
        idx = chara->skills[i + gSkillMenuPage];

        if(idx == 0xFF || idx == 0x26)
            break;

        if(i == gMenuCursorSel - 16)
        {
            gSkillMenuTmpB = idx;
            paletteId = 0xD;
        }
        else
        {
            paletteId = 0xB;
        }

        y = (i * 2) + 10;

        if(idx != 0xFF)
        {
            src = gUnk_08095828[(u8)(idx - 1)];
            dest = (u16*)0x2005820  + (y * 32);

            for(j = 0; j < 8; j++)
            {
                charCode = *src++;
                if(charCode == 0 )
                {
                    break;
                }
                Text_PutGlyph(dest++, charCode, paletteId);
            }
        }
    }



}
INCLUDE_ASM("asm/nonmatchings", sub_8011268);
INCLUDE_ASM("asm/nonmatchings", sub_80113CC);
INCLUDE_ASM("asm/nonmatchings", sub_8011454);
INCLUDE_ASM("asm/nonmatchings", sub_8012530);
INCLUDE_ASM("asm/nonmatchings", sub_8012790);
INCLUDE_ASM("asm/nonmatchings", sub_8013870);
INCLUDE_ASM("asm/nonmatchings", sub_8013934);
INCLUDE_ASM("asm/nonmatchings", sub_8013B0C);
INCLUDE_ASM("asm/nonmatchings", sub_8013C00);
extern u16 gUnk_03004D48;
extern u16 gUnk_03004DE8;
extern u8 gSaveSignature[];
extern u8 Save_Fsm_ByteResult(u8) __asm__("Save_Fsm");

static inline s16 Save_SigCheck(u8 *p)
{
    u8 i;

    for (i = 0; i < 12; i++)
    {
        if (*p != gSaveSignature[i])
        {
            return 1;
        }
        p++;
    }

    return 0;
}

void Save_LoadSlot0(void)
{
    u16 i;

    gUnk_03004D44 = 1;
    gUnk_03004DD0 = 0;

    while (Save_Fsm_ByteResult(1) != 0)
        ;

    if (Save_SigCheck((u8 *)0x02027000) == 0)
    {
        Save_SyncShadow();
        gUnk_03004DE8 = 1;
        return;
    }

    gUnk_03004DE8 = 0;
    gUnk_03004D48 = 0;

    i = 0;
    while (i < 0x5A)
        gSaveTimers[i++] = 0;

    i = 0;
    while (i < 8)
        gSaveFlags[i++] = 0;
}
extern u16 gUnk_080981E6[];   /* 块长度表 {2, 0x5A, 8, 0} */
extern u8 *gUnk_087EB1E8[];   /* 块指针表 {&gUnk_03004D48, gSaveTimers, gSaveFlags, ...} */
extern u8 gSaveSignature[];   /* 12B "LUNAR1_12_09" */

/* 把存档状态序列化进 0x02027000 影子缓冲: 签名(12B) + 各块数据 + 校验和字节。
   签名最后才写, 保证写一半的存档校验不过 (Save_LoadSlot0 的 sigCheck)。 */
void Save_LoadContinue(void)
{
    u8 *buf;
    u16 i;
    u16 count;
    u8 sum;
    u8 *src;
    u16 blk;
    u32 next;

    buf = (u8 *)0x02027000;

    for (i = 0; i <= 0xB; i++)
    {
        buf[i] = 0xFF;
    }

    sum = 0;
    i = 0xC;
    blk = 0;
    while ((count = gUnk_080981E6[blk]) != 0)
    {
        src = gUnk_087EB1E8[blk];
        next = blk + 1;
        while (count != 0)
        {
            buf[i] = *src;
            sum += buf[i];
            i++;
            src++;
            count--;
        }
        blk = next;
    }
    buf[i] = sum;

    for (i = 0; i <= 0xB; i++)
    {
        buf[i] = gSaveSignature[i];
    }
}

void SaveTimer_CountUsed(void)
{
    u16 i;
    u32 val;
    u8 mask;

    val = (u32)&gUnk_03004DE4;
    *(u16 *)val = 0;

    for (i = 0; i <= 0xAF; i++)
    {
        if ((i & 1) != 0)
        {
            val = gSaveTimers[i >> 1];
            mask = 0xF0;
        }
        else
        {
            val = gSaveTimers[i >> 1];
            mask = 0xF;
        }

        if ((mask & val) != 0)
        {
            gUnk_03004DE4++;
        }
    }
}

void SaveTimer_Inc(u8 arg0)
{
    u8 byte;
    u8 nib;
    u8 hi;

    byte = gSaveTimers[arg0 >> 1];

    if ((arg0 & 1) != 0)
    {
        nib = (byte >> 4) + 1;
        if (nib > 5)
        {
            nib = 5;
        }
        hi = nib << 4;
        byte = hi | (byte & 0xF);
    }
    else
    {
        nib = (byte & 0xF) + 1;
        if (nib > 5)
        {
            nib = 5;
        }
        byte = (byte & 0xF0) | nib;
    }

    gSaveTimers[arg0 >> 1] = byte;
}

void SaveTimer_Dec(u8 arg0)
{
    u8 byte;
    u8 nib;
    u8 hi;

    byte = gSaveTimers[arg0 >> 1];

    if ((arg0 & 1) != 0)
    {
        nib = byte >> 4;
        if (nib == 0)
        {
            nib = 1;
        }
        nib -= 1;
        hi = nib << 4;
        byte = hi | (byte & 0xF);
    }
    else
    {
        nib = byte & 0xF;
        if (nib == 0)
        {
            nib = 1;
        }
        nib -= 1;
        byte = (byte & 0xF0) | nib;
    }

    gSaveTimers[arg0 >> 1] = byte;
}

INCLUDE_ASM("asm/nonmatchings", sub_801417C);
/* 把存档菜单的精灵挂进渲染队列: 先追加固定节点 gSpriteNodePool[112],
   再把 15 个菜单 UI 实体中 (statusFlags & 0xC0) == 0x80 的挂进队列下一个空槽。
   队列以 NULL 结尾, 每次都从上次落点继续向后找空槽。 */
void sub_8014488(void)
{
    u16 i;
    u16 j;

    if ((u8)(gUnk_03004D40 - 9) > 0xE6)
    {
        RenderQueue_Clear();
        return;
    }

    sub_8014A68();
    UiSprites_Update();

    i = 0;
    while (gSpriteRenderQueue[i] != 0)
    {
        i++;
    }

    gSpriteRenderQueue[i] = &gSpriteNodePool[112];

    for (j = 0; j <= 0xE; j++)
    {
        if ((gUiSprites[j].statusFlags & 0xC0) == 0x80)
        {
            if (gSpriteRenderQueue[i] != 0)
            {
                do
                {
                    i++;
                } while (gSpriteRenderQueue[i] != 0);
            }
            gSpriteRenderQueue[i] = &gSpriteNodePool[gUiSprites[j].oamSlotId];
        }
    }
}
/* 存档菜单初始化: 复位菜单状态, 把 15 个 UI 实体槽清零 (前 5 个按在队伍里的
   角色填坐标/图块), 然后建立光标精灵 + 5 个角色头像精灵的链节点并挂进渲染队列。
   attr2 一个变量同时承担两次调用的第 5 参数 —— 这样它才是跨块量, 由 global-alloc
   落在 r0; 若和 field_6 共用变量, 会被 arg2 的寄存器建议拽到 r2。 */
void sub_801455C(void)
{
    u16 i;
    u16 attr1;
    u16 attr2;
    u16 attr0;
    SpriteNode *obj;

    MenuState_Reset();
    gUnk_03000048.field_4 = 0x60;
    gUnk_03000048.field_6 = 0x2C;
    sub_800E668(1);

    for (i = 0; i <= 0xE; i++)
    {
        if (i <= 4 && gPartyMemberIds[i] != 0xFF)
        {
            gUiSprites[i].x = 0x48 + ((i * 5) << 3);
            gUiSprites[i].y = 8;
            gUiSprites[i].statusFlags = 0x80;
            gUiSprites[i].baseTileId = i * 3 * 16 + 0x200;
            gUiSprites[i].oamSlotId = 0x71 + i;
        }
        else
        {
            gUiSprites[i].x = 0;
            gUiSprites[i].y = 0;
            gUiSprites[i].statusFlags = 0;
            gUiSprites[i].oamSlotId = 0;
        }
        gUiSprites[i].animTimer = 0;
        gUiSprites[i].lerpFrame = 0;
    }

    MenuUi_SpawnAuxSprites(3);
    gUiSprites[5].statusFlags |= 8;

    obj = (SpriteNode *)0x03004380;
    attr0 = gUnk_03000048.field_6;
    attr1 = ((gUnk_03000048.field_4 - 0x20) & 0x1FF);
    attr1 += 0x8000;
    attr2 = 0x21C0;
    Sprite_InitChainNode(obj, 1, attr0, attr1, attr2);
    gSpriteRenderQueue[0] = obj;

    for (i = 0; i <= 4; i++)
    {
        obj++;
        if (gPartyMemberIds[i] != 0xFF)
        {
            attr1 = 0x8028 + ((i * 5) << 3);
            attr2 = ((i + 3) << 12) + ((i * 3 * 16 + 0x200) & 0x3FF);
            Sprite_InitChainNode(obj, 1, 8, attr1, attr2);
            gSpriteRenderQueue[i + 1] = obj;
        }
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80146A8);
INCLUDE_ASM("asm/nonmatchings", sub_8014A68);

extern u8 *D_87EB2A8[];




// const u8 m1[] = {
//     9, 9, 0xF0, 9, 0xFF
// };

extern u8* D_87EB2A8[];

// const u8* D_87EB2A8[] = {
    // m1
// };

// shop 
void sub_801543C(u8 arg0) {
    u8 var_r6;
    u8 i;
    u8* src;
    u8 x, y;
    u16* dst;
    u8 count;

    for(i = 0; i < 3; i++)
    {
        if (i == *(u8* )0x03000187)
        {
            var_r6 = 0xD;
        }
        else
        {
            var_r6 = 0xB;
        }
        src = D_87EB2A8[i];
        x = *src++;
        y = *src++;

         dst = (u16*)0x02005800 + x + y * 32;

        if(arg0 == 0)
        {
            count = 0;
            while(*src != 0xFF)
            {
                src++;
                count++;
            }

            while(count != 0)
            {
                Text_PutGlyph(dst++, 0, 0x0B);
                count--;
            }
        }
        else
        {
            while(*src != 0xFF)
            {
                Text_PutGlyph(dst++, *src++, var_r6);
            }
        }
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_80154E8);
INCLUDE_ASM("asm/nonmatchings", sub_8015658);

INCLUDE_ASM("asm/matchings", sub_8015AF0);

void InvUi_DrawCursors(void)
{

    if (Inv_PrevNonZero() != 0)
    {

        SetBgUnknown((u16 *)0x02005992, (((gUnk_03000198 >> 3) & 1) + 0x826));
    }
    else
    {
        SetBgUnknown1((u16 *)0x02005992, 0xb27F);
    }

    if (Inv_NextNonZero(4) != 0)
    {
        SetBgUnknown((u16 *)0x02005BD2, (((gUnk_03000198 >> 3) & 1) + 0x26));
    }
    else
    {
        SetBgUnknown1((u16 *)0x02005BD2, 0xB27F);
    }
}
INCLUDE_ASM("asm/nonmatchings", InvUi_Main);
INCLUDE_ASM("asm/nonmatchings", sub_8015E1C);
void Save_ResetReadState(void)
{
    gUnk_03004D44 = 1;
    gUnk_03004DD0 = 0;
}
void Save_StartWrite(void)
{
    Save_LoadContinue();
    gUnk_03004D44 = 3;
    gUnk_03004DD0 = 0;
    *(u8 *)0x03000221 = 1;
    Msg_ShowById(0x18, 0xB);
}

INCLUDE_ASM("asm/matchings", sub_8015ED0);

void SaveUi_DrawSlots(void)
{
    u8 var_r3;
    u8 i;

    for (i = 0; i < 3; i++)
    {
        Save_FillSlot3(i);

        var_r3 = *(u8 *)0x03000220 == i ? 0xD : 0xB;

        sub_8010F10(i, 8, i * 2 + 5, var_r3);
    }
}
u32 SaveTimer_Get(u8 arg0)
{
    u8 temp_r2;
    temp_r2 = gSaveTimers[arg0 >> 1];

    return (arg0 & 1) != 0 ? (temp_r2 >> 4) : (temp_r2 & 15);
}
void SaveFlag_Set(u8 x)
{
    gSaveFlags[x >> 3] |= (1 << (x & 7));
}
int SaveFlag_Get(u8 arg0)
{
    return (gSaveFlags[arg0 >> 3] >> (arg0 & 7)) & 1;
}
void SaveUi_Open(u8 arg0)
{
    gSaveUiParam = arg0;
    gUnk_03004D40 = 0x28;
    gSaveBusyB = 0;
    gSaveBusyA = 1;
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

void Num_Draw16(s16 arg0, u16 *dest)
{
    sub_800BFF8(arg0, dest, 0xB000);
}

void Hud_DrawLv(u8 arg0, u8 x, u8 y)
{
    u16 *dest;

    if (arg0 != 0)
        arg0--;

    dest = (u16 *)0x02005800 + x + y * 32;
    *dest = 0xB257;
    dest += 3;

    Num_Draw16(gPartyStats[arg0].lv + 1, dest);
}

void Hud_DrawHp(u8 arg0, u8 x, u8 y)
{
    u16 *dest;
    u32 unk;

    if (arg0 != 0)
        arg0--;

    dest = (u16 *)0x02005800 + x + y * 32;
    *dest = 0xB258;
    dest += 3;

    unk = gPartyStats[arg0].hp == gPartyStats[arg0].max_hp ? 0xF000 : 0xB000;

    sub_800BFF8(gPartyStats[arg0].hp, dest, unk);
}

void Hud_DrawMp(u8 arg0, u8 x, u8 y)
{
    u16 *dest;
    u32 unk; // color

    if (arg0 != 0)
        arg0--;

    dest = (u16 *)0x02005800 + x + y * 32;
    *dest = 0xB259;
    dest += 3;

    unk = gPartyStats[arg0].mp == gPartyStats[arg0].max_mp ? 0xF000 : 0xB000;

    sub_800BFF8(gPartyStats[arg0].mp, dest, unk);
}

/* 窗口/菜单瓦片图 (0x02005800, 行距 32 个 u16) 的**单个字形**写入器。
 *
 * 本项目 UI 文字是 8×16 字形: 一个字占**上下两格** —— 顶格写 tilemap[0], 底格写
 * tilemap + 0x20 (下一行同列)。字形 N 占用字模瓦片 2N 与 2N+1。
 * 写入值是标准 BG 图块项 (位 0-9 = 瓦片号, 位 12-15 = 调色板号), 故 *tilemap = (palette<<12) + tileId。
 *
 * charCode 的三种取值:
 *   0        空白字形, 上下两格都写瓦片 1 —— Text_ClearRect 里手写的 0xB001 就是它的结果
 *   1..0xFF  基本字模块, tileId = charCode * 2
 *   xx|0xFE  转义: 高字节 xx 索引**扩展字模块**, tileId = 0x280 + xx * 2
 *            (0x280 = 640, 与 Text_WriteChars 用的 8×8 块基址 0x200 并列成两个字体块)
 *
 * 调用者: Msg_RenderLine / Msg_DrawPoolSegment / Msg_ShowEndMark / Text_DrawChar /
 *         MenuUi_DrawItemList / Text_WriteOrClear —— 所有 8×16 文字路径都汇到这一个原语。
 *
 * 代码生成要点 (已逐字节验证: fndiff score=0, bytecmp OK 100B)。下面每条都是实测过的坑:
 *   - `palette << 12` **必须每个分支各写一遍**; 外提成公共前缀会让 GCC2 重排块 (2435 -> 2610)
 *   - 外层必须是 `if (charCode != 0) { 转义 / 基本 } else { 空白 }` 的**嵌套**形式;
 *     平铺成 if / else if / else 不匹配 (905) —— 目标的空白字形体在函数末尾, 是条远跳
 *   - 底格瓦片号: 基本分支用 `|= 1` (目标 orrs), 转义分支用 `+= 1` (目标 adds)。
 *     数值等价 (tileId 恒为偶) 但指令不同, 不能统一写法 (规则 36)
 *   - 转义分支的 `>> 7` 不能改写成 `>> 8 << 1` 或 `* 2` —— GCC2 的移位域折叠不同 (5)
 *   - 两格之间用 `tilemap += 0x20` 推进, **不能**写成 tilemap[0] / tilemap[32] 下标 (1610)
 */
#define TILEMAP_ROW_STRIDE 0x20 /* 瓦片图一行 = 32 个 u16 */
#define GLYPH_TILES        2    /* 一个 8×16 字形占 2 个 8×8 字模瓦片 */
#define EXT_GLYPH_BASE     0x280 /* 扩展字模块的瓦片基址 */
#define ESCAPE_PREFIX      0xFE  /* charCode 低字节为此值时, 高字节索引扩展字模块 */
#define BLANK_TILE         1     /* 空白字形瓦片 */
#define PAL_SHIFT          12    /* BG 图块项的调色板号位移 */
#define GLYPH_BOTTOM_MASK  (GLYPH_TILES - 1)

void Text_PutGlyph(u16 *tilemap, u16 charCode, u8 palette)
{
    u16 palAttr;
    u16 tileId;

    if (charCode != 0)
    {
        if ((charCode & 0xFF) == ESCAPE_PREFIX)
        {
            palAttr = palette << PAL_SHIFT;
            tileId = ((charCode & 0xFF00) >> 7) + EXT_GLYPH_BASE;
            *tilemap = palAttr + tileId;
            tilemap += TILEMAP_ROW_STRIDE;
            tileId += 1;
            *tilemap = palAttr + tileId;
        }
        else
        {
            palAttr = palette << PAL_SHIFT;
            tileId = charCode * GLYPH_TILES;
            *tilemap = palAttr + tileId;
            tilemap += TILEMAP_ROW_STRIDE;
            tileId |= GLYPH_BOTTOM_MASK;
            *tilemap = palAttr + tileId;
        }
    }
    else
    {
        palAttr = palette << PAL_SHIFT;
        tileId = BLANK_TILE;
        *tilemap = palAttr + tileId;
        tilemap += TILEMAP_ROW_STRIDE;
        *tilemap = palAttr + tileId;
    }
}

void TextBlocks_Render(u8 *src)
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
                Text_PutGlyph(dest, (charCode << 8) | 0xFE, paletteId);
            }
            else
            {
                Text_PutGlyph(dest, charCode, paletteId);
            }
            dest++;
        }
    }
}

u8 Math_DivLoop(s32 *ptr, s32 divisor)
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

void Msg_ShowEndMark(u16 *arg0, u16 arg1, u8 arg2)
{
    Text_PutGlyph(Msg_DrawPoolSegment(arg0, arg1, arg2), 0xC9, 0xB);
}
/* 把全局消息池里第 segIdx 段字形串渲染进 dest, 返回推进后的 dest 游标。
 *
 * gMsgPool @0x0830FC04 (708 B, 仍在 data/data.s 的 blob 内, 两端都 4 对齐可单独搬出):
 *   段间用 0xFF 分隔; 串内 0xFE 是转义前缀, 后跟高位字节 -> 16 位字形码 (hi<<8)|0xFE。
 *   先走 segIdx 个 0xFF 定位到目标段, 再逐字发 Text_PutGlyph(dest++, code, palette)。
 *   串的**终止 0xFF 不消耗** —— 调用者 Msg_ShowEndMark 靠它在返回的游标处补右边框 0xC9。
 *
 * 代码生成要点 (已逐字节验证, fndiff score=0):
 *   - `*p` 必须写**三次** (循环测 / ==0xFE 测 / 实参), 目标就是两次 ldrb +
 *     一次 "ldrb r1; adds r0,r1,#0; cmp r0,#0xff" 的共享载入;
 *     提成局部变量 code 会少一条 ldrb 并改变载入时机 -> 不匹配
 *   - `dest++` 必须写在实参位置 (先传后推: adds r0,r5,#0; adds r5,#2), 且要在算 code 之前
 *   - 定位循环写成 `for (i = 0; i != segIdx; ) { if (*p++ != 0xFF) continue; i++; }`
 *     即 p++ 无条件、i++ 只在命中 0xFF 时 —— 与目标的顶部测试 + 两条回边一致
 */
u16 *Msg_DrawPoolSegment(u16 *dest, u16 segIdx, u8 palette)
{
    const u8 *p;
    u16 i;

    p = (const u8 *)0x0830FC04;

    for (i = 0; i != segIdx; )
    {
        if (*p++ != 0xFF)
            continue;
        i++;
    }

    while (*p != 0xFF)
    {
        if (*p == 0xFE)
        {
            p++;
            Text_PutGlyph(dest++, (*p << 8) | 0xFE, palette);
        }
        else
        {
            Text_PutGlyph(dest++, *p, palette);
        }
        p++;
    }

    return dest;
}
/* 给主文本池 gMsgPoolMain @0x080936A0 (6536 B, 0xFF 分隔) 建**快速跳转索引**。
 *
 * 线性扫过池中的 0xFF 分隔符计数段号 n, 每满 64 段就把该段起点记进
 * gMsgSegIndex @0x030001D0 (64 项 × u32 = 256 B): index[n >> 6] = p。
 * 段 0 的起点单独写在 index[0]。遇到连续两个 0xFF (段末) 即结束。
 *
 * 代码生成要点 (已逐字节验证: fndiff score=0, bytecmp OK 56B):
 *   - 首次写入必须写成 `*(u32 *)0x030001D0 = p;` 而**不能**复用 `index` 变量,
 *     否则 GCC2 会把池载入直接落到 r3, 少掉目标的 `ldr r0; str [r0]; adds r3,r0,#0` 复制
 *   - 且 `n = 0;` 必须夹在首次写入与 `index = ...` 之间 (决定那条 adds 的位置)
 *   - `n` 必须是 u32/int: 用 u16 会给 n++ 加上 lsls/lsrs 截断
 */
void Msg_BuildSegmentIndex(void)
{
    const u8 *p;
    u32 *index;
    u32 n;

    p = (const u8 *)0x080936A0;
    *(u32 *)0x030001D0 = (u32)p;
    n = 0;
    index = (u32 *)0x030001D0;

    for (;;)
    {
        while (*p != 0xFF)
            p++;
        p++;
        n++;
        if ((n & 0x3F) == 0)
            index[n >> 6] = (u32)p;
        if (*p == 0xFF)
            return;
    }
}
void Msg_Show(u16 arg0)
{
    Msg_ShowById(arg0, 0xB);
}
void Msg_ShowById(u16 arg0, u8 arg1)
{
    u16 i;
    u32 target;
    u8 *ptr;

    ptr = gMsgTable[arg0 >> 6];

    target = arg0 & 0x3F;

    i = 0;

    while (i != target)
    {
        if (*ptr++ == 0xFF)
            i++;
    }

    Msg_RenderLine(ptr, arg1);
}

s32 Text_WriteOrClear(u8 *arg0, u8 arg1, u8 arg2)
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
            Text_PutGlyph(dest++, 0, 0x0B);
            len--;
        }
    }
    else
    {
        while (*arg0 != 0xFF)
        {
            Text_PutGlyph(dest++, *arg0++, arg1);
        }
    }

    // No Return?
}

u8 Menu_GetFocus(void)
{
    return gMenuCursorStack[0] - 1;
}
void Text_ClearRect(u8 x, u8 y, u8 width, u8 height)
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
void MenuUi_SetExclusive(u8 arg0, u8 arg1)
{
    u8 i;
    UISpriteEntity *p;

    if (gUnk_03004D40 != 0 && arg0 == 0xFF)
    {
        arg0 = 5;
    }

    p = gUiSprites;
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

void MenuUi_HideAll(void)
{
    u8 temp_r0;
    u8 i;
    UISpriteEntity *p;

    p = gUiSpritesAux;

    for (i = 5; i < 15; i++)
    {
        if (p->statusFlags != 0)
            p->statusFlags |= 0x40;
        p++;
    }
}
extern const u8 gUnk_08095028[];

void Text_DrawChar(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    const u8 *src;
    u16 *dest;
    u8 i;
    u8 ch;

    if (arg0 != 0)
    {
        src = gUnk_08095028 + arg0 * 8;
        dest = (u16 *)(0x02005800 + arg1 * 2 + arg2 * 64);
        i = 0;
        while (i <= 7 && (ch = *src++) != 0)
        {
            Text_PutGlyph(dest++, ch, arg3);
            i++;
        }
    }
}
void sub_80166FC(u8 charId, u8 x, u8 y, u8 palette)
{
    u8 j;
    u8 charCode;
    u8 *src;
    u16 *dest;

    if (charId == 0xFF)
        return;

    src = gUnk_08095828[(u8)(charId - 1)];
    dest = (u16 *)(x * 2 + 0x02005800 + y * 64);

    for (j = 0; j < 8; j++)
    {
        charCode = *src++;
        if (charCode == 0)
            break;
        Text_PutGlyph(dest++, charCode, palette);
    }
}
void sub_8016758(u8 x, u8 y, u8 kind)
{
    int xOffset;
    u32 bit;
    u32 state;
    u16 tile;

    state = gUnk_03000198;
    bit = (state >> 3) & 1;
    switch (kind)
    {
    case 0:
        tile = 0x826 | bit;
        break;
    case 1:
        tile = 0x26 + bit;
        break;
    case 2:
        tile = 0x428 | bit;
        break;
    case 3:
        tile = 0x28 + bit;
        break;
    default:
        tile = 0x3F;
        break;
    }

    xOffset = x * 2;
    *(u16 *)(0x02005800 + xOffset + y * 64) = 0xB240 + tile;
}
void MenuUi_MoveCursor(u8 arg0, u8 arg1)
{
    u8 ret = Menu_GetFocus();
    if (ret != 0xFF)
    {
        MenuUi_SetEntityPos(arg0, arg1, ret);
    }
}
u8 Party_SlotOfMember(u8 arg0)
{
    u8 i;
    u8 val;

    val = gBattleFormationIds[arg0];

    i = 0;
    while (gPartyMemberIds[i] != val)
    {
        i++;
        if (i > 4)
            return i;
    }

    return i;
}
void SkillMenu_SaveCursor(void)
{
    u8 var_r2;

    var_r2 = gPartyMemberIds[(u8)(gMenuCursorStack[0] - 1)];
    if (var_r2 != 0)
    {
        var_r2--;
    }
    sub_800FF10(gItemUseCtx[gMenuCursorSel - 6], gMenuCursorStack[gMenuCursorGrp], var_r2);
}
s32 ItemUse_Execute(void)
{
    return sub_8010170(gMenuCursorStack[gMenuCursorGrp], gItemUseCtx[gMenuCursorSel - 6]);
}
void ItemUse_SetCtx(void)
{
    u8 var_r0;

    var_r0 = gPartyMemberIds[gPartyMenuIdx];

    if (var_r0 != 0)
    {
        var_r0--;
    }

    gSkillMenuTmpA = gPartyStats[var_r0].field_unk[2];
    gSkillMenuTmpB = gPartyStats[var_r0].field_unk[3];
}

void SkillMenu_RestoreCursor(void)
{
    u8 var_r0;

    var_r0 = gPartyMemberIds[gPartyMenuIdx];

    if (var_r0 != 0)
    {
        var_r0--;
    }

    gPartyStats[var_r0].field_unk[2] = gSkillMenuTmpA;
    gPartyStats[var_r0].field_unk[3] = gSkillMenuTmpB;
}

u8 SkillMenu_GetSkill(u8 arg0)
{
    s32 temp_r2;
    u8 var_r0;
    u8 ret;

    temp_r2 = gSkillMenuPage + arg0;
    ;

    if (temp_r2 < 8)
    {
        var_r0 = gPartyMemberIds[gPartyMenuIdx];
        if (var_r0 != 0)
            var_r0--;

        ret = gPartyStats[var_r0].skills[temp_r2];

        if (ret != 0x26)
            return ret;
    }

    return 0xFF;
}
// INCLUDE_ASM("asm/nonmatchings", Inv_FindFirstHeld);

u8 Inv_FindFirstHeld(void)
{
    u8 i;

    for (i = 0; i <= 0xF; i++)
    {
        if (gInventory[gInvPageItemIds[i]] != 0)
        {
            return i + 1;
        }
    }

    return 0;
}
// INCLUDE_ASM("asm/nonmatchings", Inv_FindPrevHeld);

u8 Inv_FindPrevHeld(void)
{
    u8 i;

    i = gSkillMenuPage - 1;
    while (i != 0xFF)
    {
        if (gInventory[gInvPageItemIds[i]] != 0)
        {
            return i;
        }
        i--;
    }

    return 0xFF;
}

/* 返回第 page 页对应的道具 id, 若玩家一个都没持有则返回 0xFF。
 * page 越界 (> 15) 同样返回 0xFF —— 调用者 sub_8011268 自己先测过一遍, 这里再兜一次。
 *
 * 与 Inv_FindFirstHeld / Inv_FindPrevHeld / sub_804DE20 / sub_804F050 共用 gInvPageItemIds。
 *
 * 代码生成要点 (已逐字节验证): `page` 必须**就地复用**存道具 id, 不要再声明第二个 u8 局部 ——
 * 多一个 qty 会让 GCC2 把表基址分到 r2 而不是目标的 r0 (实测 score 20, 只差 4 字节)。
 * 同理 gInvPageItemIds 必须是真 extern 数组, 用强转宏写法同样会换寄存器。
 */
u8 Inv_FindHeldItemOnPage(u8 page)
{
    if (page > 0xF)
        return 0xFF;

    page = gInvPageItemIds[page];
    if (gInventory[page] == 0)
        return 0xFF;

    return page;
}
/* 把 0x02027000 影子缓冲的存档数据拷回各真实块 (Save_LoadContinue 的逆操作)。
 * 签名校验通过后调用: 逐块按长度表 gUnk_080981E6[i] 拷 count 字节到
 * gUnk_087EB1E8[i] 指向的地址, 源偏移 offset 从 0xC 起连续递增。 */
void Save_SyncShadow(void)
{
    u8 *shadow = (u8 *)0x02027000;
    u16 offset = 0xC;
    u32 i = 0;
    u16 len;

    len = gUnk_080981E6[0];
    if (len == 0)
        return;

    do
    {
        u8 *dest = (u8 *)gUnk_087EB1E8[i];
        i++;

        while (len != 0)
        {
            *dest = shadow[offset];
            offset = (u16)(offset + 1);
            dest++;
            len = (u16)(len - 1);
        }

        i = (u16)i;
        len = gUnk_080981E6[i];
    } while (len != 0);
}

void Inv_SeekFirst(void)
{
    u8 i;

    for (i = 1; i <= 0xFD; i++)
    {
        if (gInventory[i] != 0)
        {
            gInvCursor2 = i;
            return;
        }
    }
    gInvCursor2 = 0;
}
u8 Inv_PrevNonZero(void)
{
    u8 index;
    u8 value;
    index = gInvCursor2;

    if (index == 1)
        return 0;

    while (index != 0)
    {
        index--;
        if (gInventory[index] != 0)
            return index;
    }
    return 0;
}
u8 Inv_NextNonZero(u8 arg0)
{
    u8 idx;
    u8 count;

    idx = gInvCursor2;
    count = 0;

    while (count < arg0)
    {
        if (gInventory[idx] != 0)
        {
            count++;
        }
        idx++;

        if (idx == 0xFF)
            return 0;
    }

    while (idx != 0xFF)
    {
        if (gInventory[idx] != 0)
        {
            return idx;
        }
        idx++;
    }

    return 0;
}

INCLUDE_ASM("asm/nonmatchings", sub_8016B30);
void SaveUi_OpenLoad(void)
{
    Save_LoadContinue();
    gUnk_03004D44 = 3;
    gUnk_03004DD0 = 0xC;
    gSaveModeFlag = 0;
    Msg_ShowById(0x18U, 0xBU);
}
void Text_WriteChars(u16 *dest, u8 *src, u8 arg2)
{

    while (*src != 0xFF)
    {
        *dest = (arg2 << 12) + 0x200 + *src;
        dest++;
        src++;
    }
}

void Text_FillHidden(u16 *dest, u8 *src)
{

    while (*src != 0xFF)
    {
        *dest = 0xF200;
        dest++;
        src++;
    }
}

u16 *Text_TileAt(u8 x, u8 y)
{
    return (u16 *)0x2005800 + ((y * 32) + x);
}

void sub_8016C44(void)
{
    SpriteNode *ptr = &gSpriteNodePool[112]; // 03004380
    gUnk_03000048.field_6 = 0;
    gUnk_03000048.field_4 = 0;
    Sprite_InitChainNode(ptr, 1, 0, 0x81E0, 0x21C0);
    gSpriteRenderQueue[0] = ptr;
    sub_800E668(0);
}
INCLUDE_ASM("asm/nonmatchings", sub_8016C88);
INCLUDE_ASM("asm/nonmatchings", sub_8016D24);
void Sio_BuildPacket(u8 *src)
{
    u32 checksum;
    u32 i;
    u16 *packet;
    u8 *state;

    checksum = 0;
    state = gSioState;
    **(u8 * volatile *)(state + 0x1C) = state[0xB];
    (*((u8 * volatile *)(state + 0x1C)))[1] = state[2] ^ state[3];
    *(u16 *)(*(u8 * volatile *)(state + 0x1C) + 2) = 0;
    CpuSet(src, *(u8 * volatile *)(state + 0x1C) + 4, 0x04000006);

    i = 0;
    packet = *(u16 * volatile *)(state + 0x1C);
    for (; i <= 0xD; i++)
        checksum += *packet++;

    *(u16 *)(*(u8 * volatile *)(state + 0x1C) + 2) = ~checksum - 0x10;
    state[4] = 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8016E80);
void sub_8016F30(void)
{
    u8 *state;
    u32 mode;
    u32 temp;
    u32 zero;
    u16 sioData;
    vu16 *sio;

    state = gSioState;
    mode = state[0];
    if (mode != 0)
    {
        if (state[1] != 0 && state[6] != 0)
        {
            *(s32 *)(state + 0x18) = -1;
            temp = *(u32 *)(state + 0x28);
            *(u32 *)(state + 0x28) = *(u32 *)(state + 0x24);
            *(u32 *)(state + 0x24) = temp;

            if (state[4] != 0)
            {
                temp = *(u32 *)(state + 0x20);
                *(u32 *)(state + 0x20) = *(u32 *)(state + 0x1C);
                *(u32 *)(state + 0x1C) = temp;
                zero = 0;
                state[4] = zero;
                *(u32 *)(state + 0x14) = zero;
            }

            sio = (vu16 *)REG_ADDR_SIOCNT;
            state[7] = (*(vu32 *)sio << 25) >> 31;
            sioData = 0xFEFE;
            sio[1] = sioData;
            sio[0] |= 0x80;
            REG_TM3CNT_H = 0xC0;
        }
    }
    else
    {
        if (state[9] == 0)
        {
            REG_IME = mode;
            gUnk_03007FF8 |= 0x80;
            REG_IME = 1;
        }
        state[9] = mode;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8016FC0);
void Sio_SetReady(void)
{
    if (gSioState[0] != 0)
    {
        gSioState[6] = 1;
    }
}
void Sio_Shutdown(void)
{
    REG_IME = 0;
    REG_IE &= 0xFF3F;
    REG_IME = 1;

    REG_SIOCNT = 0x2003;
    REG_TM3CNT = 0xBFC0;
    REG_IF = 0xC0;
    gSioState[6] = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8017120);
INCLUDE_ASM("asm/nonmatchings", sub_80171E4);
u32 Sio_IsHost(void)
{
    u32 ret;

    ret = 0;
    if (gSioState[1] == 2)
    {
        if (*(u16 *)((u8 *)&gSioSession + 0x18 + gSioSession.field_4D * 24) == 0x4E4C)
        {
            ret = 1;
        }
    }
    return ret;
}
void sub_80175C0(void)
{
    s32 i;
    s32 zero;
    Unk_03004F20_entry *p;

    sub_8016C88();
    CpuFill32(0, &gSioSession, 0x60);
    zero = 0;
    p = &gSioSession.unk18[zero];
    i = 1;
    do {
        p->field_0 = zero;
        p->field_2 = zero;
        p++;
        i--;
    } while (i >= 0);
    sub_8017120(1);
}
void Sio_SetXferCtx(u32 *arg0, u32 *arg1, u32 arg2, u32 arg3)
{
    gSioXferCtx.field_4 = arg0;
    gSioXferCtx.field_0 = arg1;
    gSioXferCtx.field_8 = arg2 >> 4;
    gSioXferCtx.field_A = 0;
    gSioXferCtx.field_C = arg3;
}
void Sio_ClearSlot(void)
{
    u8 index;

    index = gSioSession.field_4D;
    *(u16 *)((u8 *)&gSioSession + 0x18 + index * 24) = 0;
    Sio_Shutdown();
}
void sub_8017640(void *dst, void *src, s32 count)
{
    u8 *d;
    u8 *s;
    if (((u32)dst | (u32)src) & 3)
    {
        d = dst;
        s = src;
        count = count * 4;
        count--;
        while (count != -1) { *d++ = *s++; count--; }
    }
    else
    {
        count = count - 1;
        while (count != -1) { *(u32 *)dst = *(u32 *)src; dst = (u8 *)dst + 4; src = (u8 *)src + 4; count--; }
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_801768C);
INCLUDE_ASM("asm/nonmatchings", BattleTask_Run);
INCLUDE_ASM("asm/nonmatchings", sub_8017FA4);
INCLUDE_ASM("asm/nonmatchings", sub_8018070);
INCLUDE_ASM("asm/nonmatchings", sub_80182A8);
INCLUDE_ASM("asm/nonmatchings", sub_80184A8);
INCLUDE_ASM("asm/nonmatchings", sub_801869C);
void sub_8018744(void)
{
    gUnk_03000316 = 10;
}
INCLUDE_ASM("asm/matchings", sub_8018750);

u32 sub_801878C(void)
{
    return gGstate340;
}
void sub_8018798(u8 index, u16 value)
{
    gGstate330[index] = value;
}

u32 sub_80187A8()
{
    return gGstate32E;
}
u16 sub_80187B4()
{
    return gGstate324;
}
void sub_80187C0(u16 arg0)
{
    gGstate324 |= arg0;
}
void sub_80187D4(u16 arg0)
{
    gGstate324 &= ~arg0;
}
u16 sub_80187E8()
{
    return gGstate314;
}
u16 sub_80187F4()
{
    return gGstate312;
}
void ListNode_Init(UnkNode *node)
{
    node->prev = node;
    node->next = node;
    node->key = -1;
}
void ListNode_InitKey(UnkNode *node, u8 arg1)
{
    node->prev = 0;
    node->next = 0;
    node->key = arg1;
}
void ListNode_InsertSorted(UnkNode *head, UnkNode *new_node)
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
    gBattleRngSeed = arg0;
}
/*
    LCG（linear congruential generator）线性同余算法
*/
u16 Rng_LcgNext(void)
{
    u32 seed;
    seed = gBattleRngSeed * 0x41C64E6D + 0x3039;
    gBattleRngSeed = seed;
    return (seed / 0x10000) & 0x7FFF;
}

u32 GetObjPool()
{
    return 0x02037028;
}
u32 GetCtx_0248()
{
    return 0x03000248;
}
u32 GetBuf_37410()
{
    return 0x02037410;
}

void sub_801887C(void)
{
    if (!(gGstate324 & 8))
    {
        sub_80199E0();
        sub_804AF60();
    }
}
void sub_801889C(void)
{
    sub_8019784();
    if (!(gGstate324 & 8))
    {
        sub_804AE2C();
    }
}
void sub_80188BC(void)
{
    u16 keys;
    u16 tmp;

    if ((s8)gUnk_03000316 <= 0)
        goto readkeys;
    gUnk_03000316--;
    tmp = gUnk_03000316;
    if ((s8)tmp > 0)
        goto clear;
readkeys:
    keys = (u16)~REG_KEYINPUT;
    gGstate312 = keys & ~gUnk_03000310;
    gUnk_03000310 = keys;
    goto tail;
clear:
    gGstate312 = 0;
    gUnk_03000310 = 0;
tail:
    sub_80182A8(gUnk_03000310, gGstate330);
}
INCLUDE_ASM("asm/nonmatchings", sub_8018928);
INCLUDE_ASM("asm/nonmatchings", sub_8018A58);
INCLUDE_ASM("asm/nonmatchings", sub_8018BF8);
INCLUDE_ASM("asm/nonmatchings", sub_8018D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8018E34);
INCLUDE_ASM("asm/nonmatchings", sub_8018EA8);
INCLUDE_ASM("asm/nonmatchings", sub_8018FC0);
void Bg0_InitClear(s32 a, s32 b, s32 c, s32 d) {
    u16 *ewram;
    u16 *vram;
    u16 i;
    ewram = (u16 *) 0x02035AC0;
    vram = (u16 *) 0x06007000;
    i = 0;
    do {
        ewram[i] = 0;
        vram[i] = 0;
        i++;
    } while (i <= 0x3FF);
    REG_DISPCNT |= DISPCNT_BG0_ON;
    d &= ~3;
    d &= ~0xC;
    d |= 8;
    d &= ~0x30;
    d &= ~0x40;
    d &= ~0x80;
    d &= 0xFFFFE0FF;
    d |= 0xE00;
    d &= ~0x2000;
    do { d &= ~0xC000; } while (0);
    REG_BG0CNT = d;
}
INCLUDE_ASM("asm/nonmatchings", sub_80191CC);
/* 清空 gDialogCtx[0..2] 共 3 个表项。
 * 注意必须用结构体成员形式逐个写: 目标是对同一基址取 11 个 `strb [r0,#N]`
 * + 2 个 `strh [r0,#0xc/#0xe]` 位移寻址。改成 `u8 *b; b[N] = 0;` 会被 GCC2
 * 强度削减成 `adds` 连续递增, 逐指令全变(规则 11 / 67)。
 * 0xb (field_B) 不被清零; 0xe/0xf 是一条 u16 存零, 所以原代码在那里看的是 u16 字段。 */
void DialogCtx_Clear3(void)
{
    u8 i;
    Unk_03000348 *ptr;

    for (i = 0; i <= 2; i++)
    {
        ptr = &gDialogCtx[i];
        ptr->padding0[0] = 0;
        ptr->padding0[1] = 0;
        ptr->padding0[2] = 0;
        ptr->padding0[3] = 0;
        ptr->padding0[4] = 0;
        ptr->padding0[5] = 0;
        ptr->padding0[6] = 0;
        ptr->padding0[7] = 0;
        ptr->field_8 = 0;
        ptr->field_9 = 0;
        ptr->field_A = 0;
        ptr->field_C = 0;
        *(u16 *)&ptr->field_E = 0;
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_801933C);
INCLUDE_ASM("asm/nonmatchings", sub_80196D4);
void DialogCtx_SetPair(u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
    u8 a;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 *tbl;
    u8 *ptr;

    a = arg0;
    b = arg1;
    c = arg2;
    d = arg3;
    e = arg4;
    tbl = (u8 *)gDialogCtx;
    ptr = tbl + a * 0x14;
    ptr[0] = b;
    ptr[1] = c;
    ptr[2] = d;
    ptr[3] = e;
    ptr[4] = b;
    ptr[5] = c;
    ptr[6] = d;
    ptr[7] = e;
}
INCLUDE_ASM("asm/nonmatchings", sub_8019784);
INCLUDE_ASM("asm/nonmatchings", sub_80199E0);
INCLUDE_ASM("asm/nonmatchings", sub_8019AD0);
INCLUDE_ASM("asm/nonmatchings", sub_8019B98);
void BattleUiFlag_Clear()
{
    gBattleUiFlags = 0;
}
void BattleUiFlag_Set(u16 arg0)
{
    gBattleUiFlags |= arg0;
}
u16 BattleUiFlag_Get()
{
    return gBattleUiFlags;
}
void BattleUiFlag_Reset(u16 mask)
{
    gBattleUiFlags &= ~mask;
}
void Disp_ObjOff(void)
{
    REG_DISPCNT &= 0xF7FF;
}
void Disp_ObjOn(void)
{
    REG_DISPCNT |= 0x800;
}
// 清空 VRAM 上编号 0x2C0 的那块图块(0x06005800, 4bpp 8×8 = 32 字节),
// 并把 32×32 = 1024 项的 tilemap 缓冲区(0x020352C0)全部填成指向该空白图块。
// 项格式: bit0-9 图块号(0x2C0), bit10-11 清 0, bit12-15 = 3|(原值 bit14-15)。
// 注: attr 在原始代码里就是**未初始化**的局部 —— 目标第一条相关指令是
//     `ands r2, r0`(r2 从未被写入), 两个调用点也都直接 `bl sub_8019E60` 不传参。
//     写成参数或预先赋值都会多指令/少指令, 不匹配。
void sub_8019E60(void)
{
    u32 attr;
    u16 *map;
    u8 *tile;
    u16 i;
    u32 tmp;

    map = (u16 *)0x020352C0;
    tile = (u8 *)0x06005800;
    for (i = 0; i <= 0x1F; i++)
    {
        tile[i] = 0;
    }

    attr &= ~0x3FF;
    attr |= 0x2C0;
    tmp = 0x400;
    attr &= ~tmp;
    attr &= ~0x800;
    attr &= ~0xF000;
    attr |= 0x3000;
    // 注: 外层 do {} while(0) 是 GCC2 调度屏障(规律25)。去掉后第二个循环的
    //     `movs r1,#0` 会从 `orrs r2,r0` 之前挪到之后, 差 4 字节。
    do
    {
        for (i = 0; i <= 0x3FF; i++)
        {
            tmp = attr;
            map[i] = tmp;
        }
    } while (0);
}
void Disp_Bg1Off(void)
{
    REG_DISPCNT &= 0xFEFF;
}

void DialogCtx_SetHead(u8 index, u8 arg1, u8 arg2)
{
    gDialogCtx[index].field_8 = arg1;
    gDialogCtx[index].field_9 = 0;
    gDialogCtx[index].field_A = arg2;
    gDialogCtx[index].field_C = 5;
}
INCLUDE_ASM("asm/nonmatchings", sub_8019F08);
INCLUDE_ASM("asm/nonmatchings", sub_8019F78);
u8 DialogCtx_GetField_C(u8 index)
{
    return gDialogCtx[index].field_C;
}
/* BG map 矩形区域调色板覆盖: 以 (x,y) 为左上角、width×height 的半字区,
 * 每项 (tile & 0x0FFF) + palette<<12 (保留 tile 号, 替换高 4 位调色板号)。
 * 调用点: sub_8020D50.c 菜单条目高亮 (style+0xB 选调色板, x=8, y=(i-view)*2+8, w=9, h=2)。 */
void BgMap_PalFillRect(base, palette, x, y, width, height)
u16 *base;
u16 palette;
u8 x;
u8 y;
u8 width;
u8 height;
{
    u8 col;
    u16 *dst;
    u8 row;

    dst = base + ((16 * (y * 2)) + x);
    for (row = 0; row < height; row++)
    {
        for (col = 0; col < width; col++)
        {
            dst[col] = (palette << 12) + (dst[col] & 0x0FFF);
        }

        dst += 32;
    }
}
void DialogCtx_Flush(void) {
    if(gDialogCtx[0].field_C || gDialogCtx[1].field_C != 0 || gDialogCtx[2].field_C != 0)
    {
        DmaCopy32(3,0x02035AC0, 0x06007000,0x800);
        DmaWait(3);
    }
}
void FlashFlag_Clear()
{
    gFlashFlags = 0;
}
u16 FlashFlag_Get()
{
    return gFlashFlags;
}
void FlashFlag_Reset(u16 mask)
{
    gFlashFlags &= ~mask;
}
void BattleFx_Init(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{
    gFlashFlags &= 0xFFF0;
    gFlashFlags |= 1;
    gFlashFlags |= 0x2000;
    if (gFlashFlags & 0x1000)
        gFlashFlags &= ~0x1000;

    gUnk_03000386 = 0;

    gUnk_030004D4 = arg0;
    gUnk_030004D5 = arg1;
    gUnk_030004D6 = arg2;
    gUnk_030004D7 = arg3;
}
void BattleFx_Stop(void)
{
    gFlashFlags &= 0xFFF0;
    gFlashFlags &= 0xEFFF;
    if (gFlashFlags & 0x4000)
    {
        gFlashFlags &= 0xBFFF;
    }

    gUnk_030004D7 = 0;
}

void BattleFx_DispOff(void)
{
    REG_DISPCNT &= 0xDFFF;
    REG_BLDY = 0;
    REG_BLDCNT = 0;

    gFlashFlags &= 0xFFF0;
    gFlashFlags &= 0xEFFF;

    if (gFlashFlags & 0x4000)
    {
        gFlashFlags &= 0xBFFF;
    }

    *(u8 *)0x030004D7 = 0;
}

void sub_801A270(void)
{
    DmaFill16(3, 100, (void *)0x020362C0, 0x800);
    DmaWait(3);
}

INCLUDE_ASM("asm/matchings", sub_801A2AC);
// void sub_801A2AC(u16 arg0, u8 arg1, u8 arg2)
// {
//     REG_BLDCNT = arg0;
//     REG_BLDALPHA = arg1 | (arg2 << 8);

//     if (((arg0 >> 6) & 2) == 2)
//     {
//         REG_BLDY = arg1;
//     }
// }
INCLUDE_ASM("asm/matchings", sub_801A2EC);
// extern u8* gUnk_087EBDF0[];
// void sub_801A2EC(void)
// {
//     if (gUnk_030004F8 <= 3)
//     {
//         LZ77UnCompVram(gUnk_087EBDF0[gUnk_030004F8], (void *)(0x06008000 + gUnk_030004F8 * 0x1000));
//         gUnk_030004F8++;
//     }
// }
void BgLoad_Reset(void)
{
    gUnk_030004F8 = 0;
    return;
}
void BgLoad_Finish(void)
{
    gUnk_030004F8 = 4;
}
u8 BgLoad_GetPos(void)
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

void BgScrolls_WriteAll(void)
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
