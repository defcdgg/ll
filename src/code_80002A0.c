#include "code_0.h"
#include "gba/defines.h"
#include "gba/gba.h"
#include "globals.h"
#include "data_87E83F0.h"
#include "data_805769C.h"
#include "include_asm.h"
#include "iwram.h"
#include "m4a.h"
#include "sound.h"

extern void IntrMain();



// @ 0x080002A0
void VBlank_UpdateGameScreen(void)
{
    u16 val;

    VramTransfer_Flush();

    switch (gBg1ScrollMode)
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
            REG_BG1HOFS = (s16)((u8)gCameraPosX >> 3);
            REG_BG1VOFS = 0;
            break;
        case 6:
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0x1E;
            break;
        default:
            REG_BG1HOFS = (0x1F & gCameraPosX);
            REG_BG1VOFS = (0x1F & gCameraPosY);
            break;
    }

    REG_BG2HOFS = gBG2ScrollX;
    REG_BG2VOFS = gBG2ScrollY;
    REG_BG3HOFS = gBG3ScrollX;
    REG_BG3VOFS = gBG3ScrollY;

    DmaCopy16(3, gOamBuffer, OAM, OAM_SIZE);

    LogoAssets_Load(); // Show Lunar Logo
    DialogPortrait_FlushPending();

    if (gLogoEffectState == 0)
    {
        sub_805008C();
    }

    SceneBg_Reload();

    if (gViewportFlags[13] != 0)
    {
        DmaCopy16(3, gUnk_02005380, 0x0600F380, 0x100);
        gViewportFlags[13] = 0U;
    }

    REG_BLDCNT = gBlendControl;
    if (gBlendControl & 0x80)
    {
        REG_BLDY = gBlendCoefficients;
    }
    else
    {
        REG_BLDALPHA = gBlendCoefficients;
    }

    VBlank_UpdateSpriteAndWindow();
    PendingSpriteLoad_Flush();

    switch (gHBlankEffectMode)
    {
        case 0:
        default:
            break;
        case 1:
        case 3:
            val = (gHBlankScrollCounter - 1) & 0x3FF;
            gHBlankScrollCounter = val;
            gHBlankWaveRow = (val >> 2) + gCameraPosY;
            break;
        case 2:
        case 4:
            val = (gHBlankScrollCounter - 1) & 0x7FF;
            gHBlankScrollCounter = val;
            gHBlankWaveRow = (val >> 3) + gCameraPosY;
    }
}

// @ 0x080004F8
void VBlank_UpdateScreenSimple(void)
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
    REG_BLDALPHA = gBlendCoefficients;

    DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);

    VBlank_UpdateSpriteAndWindow();
    val = (gHBlankScrollCounter - 1) & 0x3FF;
    gHBlankScrollCounter = val;
    gHBlankWaveRow = (val >> 2) + gCameraPosY;
}

/* H-Blank 中断里逐扫描线调用 (Intr_HandleHBlank → 本函数, 实参 = REG_VCOUNT & 0xFF)。
 * 用 HBlankWave_BuildTables 预先算好的两张表, 把 BG1 的每行偏移重写成水波:
 *   索引 = (gHBlankWaveRow + scanline) & 0xFF, gHBlankWaveRow 由 VBlank 每帧推进 (相位)。
 * mode 1/2 额外叠加摄像机低 5 位, mode 3/4 纯波; mode 0 = 不动 (case 缺省不写)。
 */
// @ 0x080005A8
void HBlankWave_ApplyLineScroll(u16 scanline)
{
    switch (gHBlankEffectMode)
    {
        case 1:
        case 2:
            REG_BG1HOFS = gHBlankWaveH[(gHBlankWaveRow + scanline) & 0xFF] + (gCameraPosX & 0x1F);
            REG_BG1VOFS = gHBlankWaveV[(gHBlankWaveRow + scanline) & 0xFF] + (gCameraPosY & 0x1F);
            break;

        case 3:
            REG_BG1HOFS = gHBlankWaveH[(gHBlankWaveRow + scanline) & 0xFF];
            REG_BG1VOFS = gHBlankWaveV[(gHBlankWaveRow + scanline) & 0xFF];
            break;

        case 4:
            REG_BG1HOFS = gHBlankWaveH[(gHBlankWaveRow + scanline) & 0xFF];
            REG_BG1VOFS = gHBlankWaveV[(gHBlankWaveRow + scanline) & 0xFF];
            break;
    }
}

// VBlankIntr
// @ 0x0800065C
void VBlankIntr(void)
{

    switch (gVBlankPipelineMode)
    {
        case 1:
            m4aSoundVSync();
            VBlank_UpdateGameScreen();
            break;
        case 2:
            m4aSoundVSync();
            sub_8018070();
            break;
        case 3:
            m4aSoundVSync();
            VBlank_UpdateScreenSimple();
            break;
        case 4:
            m4aSoundVSync();
            VramTransfer_Flush();

            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 4;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 4;
            REG_BG3VOFS = 0;

            REG_BLDCNT = gBlendControl;
            REG_BLDALPHA = gBlendCoefficients;

            DmaCopy16(3, gOamBuffer, OAM, 0x400);
            DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);

            if (gBgTileReloadFlag != 0)
            {
                DmaCopy16(3, VRAM_BUF_2005000, 0x0600F000, 0x800);
                gBgTileReloadFlag = 0;
            }

            VBlank_UpdateSpriteAndWindow();
            break;
        case 5:
            sub_8016F30();
            m4aSoundVSync();
            VramTransfer_Flush();
            PalTransfer_Flush();

            // CpuFastCopy(gOamBuffer, (u32*)0x07000000, 0x400);
            CpuCopy(gOamBuffer, (void *)0x07000000, 0x400);

            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 0;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 0;
            REG_BG3VOFS = 0;
            REG_BLDCNT = gBlendControl;
            REG_BLDALPHA = gBlendCoefficients;

            // CpuFastCopy(gWindowBgBuf, 0x0600F800, 0x800);
            CpuCopy(VRAM_BUF_2005800, (void *)0x0600F800, 0x800);

            if (gBgTileReloadFlag != 0)
            {
                // CpuFastCopy(gUnk_02005000, 0x0600F000, 0x800);
                CpuCopy(VRAM_BUF_2005000, (void *)0x0600F000, 0x800);
                gBgTileReloadFlag = 0;
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

            VramTransfer_Flush();
            DmaCopy16(3, gOamBuffer, OAM, 0x400);

            MapBg_FlushPending();
            sub_805008C();

            REG_BLDCNT = gBlendControl;
            if (gBlendControl & 0x80)
            {
                REG_BLDY = gBlendCoefficients;
            }
            else
            {
                REG_BLDALPHA = gBlendCoefficients;
            }

            VBlank_UpdateSpriteAndWindow();
            PendingSpriteLoad_Flush();
            break;
        default:
            m4aSoundVSync();
            break;
    }

    gRandCursor++;

    if (gGameTimer <= 0x0CDFD7EE)
    {
        gGameTimer++;
    }
    else
    {
        gGameTimer = 0x0CDFD7F0;
    }

    gFrameCounter++;
    REG_IME = 0;
    gUnk_03007FF8 |= 1;
    REG_IME = 1;
}

// @ 0x080008CC
void Display_ShutdownSequence(void)
{

    Sfx_StopTrack(0);
    Sfx_StopTrack(1);
    Sfx_StopTrack(2);
    Sfx_StopTrack(3);
    Bgm_SetVolume(0);
    VBlankIntrWait();

    while (REG_DISPSTAT & 1)
        ;

    SoundMain_Frame();
    Bgm_Stop();
    VBlankIntrWait();

    while (REG_DISPSTAT & 1)
        ;

    SoundMain_Frame();
    Sound_VSyncOff();
    VBlankIntrWait();
    while (REG_DISPSTAT & 1)
        ;

    SoundMain_Frame();
    VBlankIntrWait();
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
}

// @ 0x0800096C
s32 Sio_LinkTask(void)
{

    switch (gSioLinkState)
    {
        case 0:
            REG_RCNT = 0xC000;
            VBlankIntrWait();
            Sio_SetXferCtx(&gUnk_03001AD0, &gUnk_03001CB0, 0x10, 0);
            gSioSession.unk5E = 1;
            gSioSession.unk2 = 1;
            gSioLinkState++;
        case 1:
            gSioRecvWord = sub_80171E4();

            if (gSioRecvWord == -1)
            {
                gUnk_030025A8 = 5;
                gSioLinkState = 6;
                break;
            }

            if ((Sio_IsHost() == 0) && (gSioRecvWord <= 0xFF))
            {
                if (gSioRetryTimer == 0)
                {
                    Sio_ClearSlot();
                    gSioLinkState = 4;
                    gUnk_030025A8 = 2;
                }
                gSioRetryTimer--;
                break;
            }

            switch (gSioRecvWord)
            {
                case 0:
                case 1:
                    if (gSioRetryTimer == 0)
                    {
                        Sio_ClearSlot();
                        gSioLinkState = 4;
                        gUnk_030025A8 = 2;
                    }
                    else
                    {
                        gSioRetryTimer--;
                    }
                    break;

                case 2:
                    if (Sio_IsHost() == 0)
                    {
                        Sio_ClearSlot();
                        gSioLinkState = 5;
                        gUnk_030025A8 = 3;
                    }
                    else if (gUnk_030025A8 == 0)
                    {
                        gSioSession.unk5E = 1;
                        gSioSession.unk2 = 1;
                        gUnk_030025A8 = 1;
                    }
                    break;

                case 0x101:
                case 0x102:
                case 0x103:
                case 0x104:
                    gUnk_030025A8 = 3;
                    gSioLinkState = 5;
                    break;

                default:
                    break;
            }

            break;
        case 2:
        case 3:
        case 4:
            Sio_ClearSlot();
            gSioLinkState = 9;
            break;
        case 5:
            Sio_ClearSlot();
            gSioLinkState = 9;
            break;
        case 6:
            gSioLinkState = 0;
            break;
        case 7:
            Sio_ClearSlot();
            break;
        case 8:
            if (gUnk_030025A8 == 0)
            {
                Sio_ClearSlot();
                gSioLinkState = 0;
            }
            break;
        case 9:
            Sio_ClearSlot();
            gSioLinkState = 8;
            break;
    }

    return Sio_IsHost();
}

// @ 0x08000B58
void System_SoftReset(u32 arg0)
{
    u16 i;

    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void *)PLTT, PLTT_SIZE);
    DmaFill16(3, 0, &gUnk_02004000, 0x2000);

    SpritePool_Clear();
    Queue34C0_Clear();

    gGameTimer = 0;
    gPendingSpriteLoad = 0;
    gLogoEffectState = 0;
    gUnk_03004910 = 0;
    gSceneSubState = 0;
    gScreenFadeFlags = 0;
    gSceneEntryFlag = 0xFF;

    for (i = 0; i < 16; i++)
    {
        gViewportFlags[i] = 0;
    }

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    VramTransfer_Clear();
    PalTransfer_Clear();
    MenuEnt_ClearStates();
    SwitchFlags_ClearAll();
    EventFlags_ClearAll();
    ChestFlags_ClearAll();

    gVBlankPipelineMode = 0;
    gUnk_03004D4C = 0;
    gUnk_03004D40 = 0;
    gCameraSnapFlag = 0;
    gDialogueActive = 0;
    gUnk_0300483C = 0;
    gAfterBattleCounter = 0;
}

/* 用 gWaveSineTable 算出两张"逐扫描线 BG1 偏移表" gHBlankWaveH / gHBlankWaveV。
 *
 * mode (写入 gHBlankEffectMode, 见 VBlank_UpdateGameScreen / HBlankWave_ApplyLineScroll):
 *   0 / 其它 = 不构建 (直接 return), 1..4 = 四种涟漪预设
 *
 *   mode  tableMask  hStep hDiv | vStep vDiv   每 255 行内的水平波周期数
 *   1     0x7F        32   12   |  16    12    63.8
 *   2     0x3F         8   16   |  16     4    31.9
 *   3     0x7F        32   16   |   4    32    63.8
 *   4     0x3F         1    4   |   1    16     4.0
 *
 * tableMask 决定取表的哪一半:
 *   0x7F = 整个 128 项周期 (含"负半周"); 0x3F = 只用前 64 项 (0→100→0 的正半拱)。
 *
 * ⚠ 原代码把表当 **u8 无符号**读 (表项 0xFC..0xFF 即负半周 → 252..255), 除数才是 s8
 *   (asm: `lsls #0x18; asrs #0x18` + `bl __divsi3`)。所以 tableMask=0x7F 的 mode 1/3
 *   在负半周会得到一个大正数而非负偏移 (例 mode1: 0,8,0,13 循环), 靠 BG 偏移寄存器回绕
 *   出视觉效果。这是原作者的写法, 不要"顺手修正"成 s8 表 —— 会改变生成字节。
 */
// @ 0x08000C98
void HBlankWave_BuildTables(u16 mode)
{

    u16 i;
    u8 tableMask;
    s8 hStep, vStep;
    s8 hDiv, vDiv;

    tableMask = 0x7F;
    switch (mode)
    {
        case 1:
            hDiv = 12;
            hStep = 32;
            vDiv = 12;
            vStep = 16;
            break;
        case 2:
            hDiv = 16;
            hStep = 8;
            vDiv = 4;
            vStep = 16;
            tableMask = 0x3F;
            break;
        case 3:
            hDiv = 16;
            hStep = 32;
            vDiv = 32;
            vStep = 4;
            break;
        case 4:
            hDiv = 4;
            hStep = 1;
            vDiv = 16;
            vStep = 1;
            tableMask = 0x3F;
            break;
        default:
            return;
    }

    /* 255 = 屏幕可见行数 + 一屏余量, 供 (gHBlankWaveRow + scanline) & 0xFF 索引 */
    for (i = 0; i < 255; i++)
    {
        gHBlankWaveH[i] = gWaveSineTable[(i * hStep) & tableMask] / hDiv;
        gHBlankWaveV[i] = gWaveSineTable[(i * vStep) & tableMask] / vDiv;
    }
}

// @ 0x08000D5C
u32 LZ_UncompressChunk(void)
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

// @ 0x08000E1C
void Intr_SetMode(u8 arg0)
{

    REG_IME = 0;

    if (arg0 == 0)
    {
        gVBlankPipelineMode = 4;
        DmaCopy16(3, IntrMain, gIntrMainBuf, sizeof(gIntrMainBuf));
        REG_IE = INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_GAMEPAK;
        REG_DISPSTAT = REG_DISPSTAT | 0x10;
    }
    else
    {
        gVBlankPipelineMode = 5;
        DmaCopy16(3, sub_8000170, gIntrMainBuf, sizeof(gIntrMainBuf));
        REG_IE = 0xFFFD & REG_IE;
        REG_DISPSTAT = 0xFFEF & REG_DISPSTAT;
    }

    INTR_VECTOR = &gIntrMainBuf;
    REG_IME = 1;
}

// @ 0x08000ED8
void Display_RestartAfterLoad(void)
{

    while ((REG_VCOUNT & 0xFF) > 0xC8)
        ;

    REG_DISPCNT &= 0xFF7F;
    VBlankIntrWait();

    while (REG_DISPSTAT & DISPSTAT_VBLANK)
        ;

    Sound_VSyncOn();
    Bgm_SetVolume(0);
    VBlankIntrWait();

    while (REG_DISPSTAT & DISPSTAT_VBLANK)
        ;

    SoundMain_Frame();
}

// @ 0x08000F54
void System_ResetToLogo(void)
{
    gVBlankPipelineMode = 0;
    gMainGameState = 0xB;
    gScenePhase = 0;
    Bgm_Stop();
    VBlankIntrWait();
    SoundMain_Frame();
    Sound_VSyncOff();
    VBlankIntrWait();
    SoundMain_Frame();
}

// @ 0x08000F90
void nullsub_5() { }

// @ 0x08000F94
void VBlankWait_PumpSound(void)
{
    VBlankIntrWait();
    SoundMain_Frame();
}

// @ 0x08000FA4
void VBlankWaitExit_PumpSound(void)
{
    VBlankIntrWait();
    while (REG_DISPSTAT & DISPSTAT_VBLANK)
        ;
    SoundMain_Frame();
}

// @ 0x08000FD0
void LZ_InitContext(u8 *dest, struct Unk_LzData *arg1, u32 arg2)
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

// @ 0x08000FF8
u8 Rand_TableNext(void)
{
    return gRandShuffleTable[gRandCursor++];
}

// @ 0x08001014
void EventFlags_ClearAll(void)
{
    u16 i;

    for (i = 0; i < 0x40; i++)
    {
        gEventFlags[i] = 0;
    }
}

// @ 0x08001030
u8 EventFlags_Test(u16 arg0)
{
    return gEventFlags[arg0 >> 3] & (1 << (arg0 & 7));
    // return gEventFlags[arg0 / 8] & (1 << (arg0 % 8));
}

// @ 0x08001050
void EventFlags_Set(u16 arg0)
{
    gEventFlags[arg0 >> 3] |= (1 << (arg0 & 7));
}

// @ 0x08001070
void EventFlags_Reset(u16 arg0)
{
    gEventFlags[arg0 >> 3] &= ~(1 << (arg0 & 7));
}

// @ 0x08001090
void SwitchFlags_ClearAll(void)
{
    u16 i;

    for (i = 0; i < 0x50; i++)
    {
        gSwitchFlags[i] = 0;
    }
}

// @ 0x080010AC
u8 SwitchFlags_Test(u16 arg0)
{
    return gSwitchFlags[arg0 >> 3] & (1 << (arg0 & 7));
}

// @ 0x080010CC
void SwitchFlags_Set(u16 arg0)
{
    gSwitchFlags[arg0 >> 3] |= 1 << (arg0 & 7);
}

// @ 0x080010EC
void SwitchFlags_Reset(u16 arg0)
{
    gSwitchFlags[arg0 >> 3] &= ~(1 << (arg0 & 7));
}

// @ 0x0800110C
void SwitchFlags_ClearRange(void)
{
    u16 i;

    for (i = 0x3D; i < 0x50; i++)
    {
        gSwitchFlags[i] = 0;
    }
}

// @ 0x08001128
void System_Init(void)
{
    RegisterRamReset(3);
    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1;
    gMainTaskSlot = 0;
    Palette_FillWhite();
    DmaCopy32(3, gIntrTable, gUnk_03001950, sizeof(gUnk_03001950));
    DmaCopy16(3, IntrMain, gIntrMainBuf, sizeof(gIntrMainBuf));

    INTR_VECTOR = gIntrMainBuf;
    gMainGameState = 0xB;
    gScenePhase = 0;

    REG_IE = INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_GAMEPAK;
    REG_DISPSTAT = DISPSTAT_HBLANK_INTR | DISPSTAT_VBLANK_INTR;
    REG_IME = 1;

    VBlankIntrWait();
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON
        | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON;
    ;
    System_SoftReset(0);
    Sound_Init();
    sub_8021130();
    gScenePhase = 0;
}

// @ 0x080011F0
void ReadKeysRaw(void)
{
    u16 keyInput;

    keyInput = ~REG_KEYINPUT;
    gNewKeysRaw = keyInput & ~gHeldKeysRaw;
    gHeldKeysRaw = keyInput;
}

// @ 0x0800121C
void ReadKeys(void)
{
    u16 keyInput;

    keyInput = ~REG_KEYINPUT;
    gNewKeysRaw = keyInput & ~gHeldKeysRaw;
    gHeldKeysRaw = keyInput;
}

// @ 0x08001248
void DummyIntr3() { }

// @ 0x0800124C
void Intr_HandleHBlank(void)
{
    switch (gVBlankPipelineMode)
    {
        case 1:
        case 3:
            HBlankWave_ApplyLineScroll(0xFF & REG_VCOUNT);
            break;
        case 2:
            sub_801887C();
            break;
    }
}

// @ 0x08001284
void DummyIntr4() { }

// @ 0x08001288
void DummyIntr5() { }


//AgbMain
// @ 0x0800128C
void AgbMain(void)
{
    gMainTaskSlot = 0;
    System_Init();

    while (1)
    {
        gMainTasks[gMainTaskSlot]();
        VBlankIntrWait();
        SoundMain_Frame();
    }
}

// @ 0x080012B8
void VBlank_UpdateScreenMode5(void)
{
    sub_8016F30();
    m4aSoundVSync();
    VramTransfer_Flush();
    PalTransfer_Flush();
    CpuFastSet(gOamBuffer, (void *)0x07000000, 0x100);

    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BLDCNT = gBlendControl;
    REG_BLDALPHA = gBlendCoefficients;

    CpuFastSet(VRAM_BUF_2005800, (void *)0x0600F800, 0x200);
    if (gBgTileReloadFlag != 0)
    {
        CpuFastSet(VRAM_BUF_2005000, (void *)0x0600F000, 0x200);
        gBgTileReloadFlag = 0;
    }
}
//切换场景加载
// @ 0x08001354
void SceneTransition_Load(void)
{
    u16 i;
    u8 temp_r6;
    s32 temp_r7;

    Display_ShutdownSequence();
    temp_r6 = gVBlankPipelineMode;
    gVBlankPipelineMode = 0;
    temp_r7 = gSceneTransitionArg;
    gHBlankEffectMode = 0;
    MenuEnt_ClearStates();
    gCameraTargetX = gSpawnTileX * 8;
    gCameraTargetY = gSpawnTileY * 8;
    if (gCameraSnapFlag != 0)
    {
        gCameraPosX = gCameraTargetX;
        gCameraPosY = gCameraTargetY;
    }
    SpritePool_Clear();
    Queue34C0_Clear();
    RenderQueue_Clear();

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    VramTransfer_Clear();
    PalTransfer_Clear();
    AnimSlots_Release();
    StaticObjs_Reset();
    Sprites_ReleaseAll();
    gPlayerMoveDir = gSpawnFacingDir;
    Party_FollowAnim();
    Party_FollowStep();
    MapScene_Load(gMapNpcSetId);
    MapScene_InitSprites(gMapNpcSetId);
    Sprites_LoadMapNPCs(gMapNpcSetId);
    BgScroll_LoadFromTable(gMoveCmdSetId);
    Chest_LoadForMap(gMapNpcSetId);
    StaticObjGfx_LoadPair(gMapObjGfxSetId);
    StaticObjs_Spawn(gMapObjGfxSetId);

    gVBlankPipelineMode = temp_r6;

    if ((Script_GetFlags() & 1) == 0)
    {
        sub_80526A0(0xFF, 2);
        ScriptPump_Run();
    }

    Sprites_UpdateFrame();

    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if ((Script_GetFlags() & 1) == 0)
    {
        Palette_Backup();
        ScreenFx_SetMode(3);
    }

    gInputLockFrames = 2;
    gMainGameState = 1;
    gScenePhase = 0;
    Display_RestartAfterLoad();

    if (gSceneEntryFlag != 0xFF || gSceneTransitionArg == 0)
        return;

    if (temp_r7 == gSceneTransitionArg)
    {
        Bgm_SetVolume(0);
        VBlankWaitExit_PumpSound();
        Bgm_Continue();
        VBlankWaitExit_PumpSound();
        Bgm_FadeIn(4);
    }
    else
    {
        Bgm_SetVolume(0);
        VBlankWaitExit_PumpSound();
        Bgm_Stop();
        VBlankWaitExit_PumpSound();
        Bgm_Play(gSceneTransitionArg, 0);
        VBlankWaitExit_PumpSound();
        Bgm_FadeIn(4);
    }
}

//New Game
// @ 0x08001538
void NewGame_Init(void)
{
    u8 i;
    u16 i1;

    gSceneEntryFlag = 0xFF;
    gDialogueActive = 0;
    gUnk_03000000 = 0;
    gUnk_03000002 = 0;
    gScenePhase = 0;
    gSceneLoadToggle = 0;
    gUnk_03002608 = 0;
    gPartyFollowFlags = 0;
    gWarpAnimState = 0;
    gScreenIdleEventFlags[0] = 0;
    gScreenIdleEventFlags[1] = 0;

    gVBlankPipelineMode = 1;
    gMapNpcSetId = 0x82;
    gSpawnTileX = 0;
    gSpawnTileY = 0;
    gSpawnFacingDir = 0;
    gMoveCmdSetId = 0;
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

    Party_InitStats();

    for (i = 0; i < 11; i++)
    {
        sub_800A664(i);
        Stats_RecalcEquip(i);
    }

    gInventory[0xDD] = 2;
    gSilverAmount = 300;
    gGameTimer = 0;
    gCameraTargetX = 0x60;
    gCameraTargetY = 0x50;

    Script_ResetVM();

    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if (gCutsceneActive == 0)
    {
        gUnk_03004634 = 1;
        gCurrentSongId = 1;
        sub_80525E8(1, 0, 1);

        for (i1 = 0; i1 < 16; i1++)
        {
            VBlankWaitExit_PumpSound();
        }
    }
    else
    {
        sub_80525E8(0, 0, 1);
        for (i1 = 0; i1 < 4; i1++)
        {
            VBlankWaitExit_PumpSound();
        }
    }
    sub_80526A0(1, 2);
    gMainGameState = 1;
    gScenePhase = 0;
}

// @ 0x08001708
void Scene_EnterMap(void)
{
    u16 i;

    if (gSceneSubState == 0 && gScenePhase == 1)
    {
        gCameraTargetX = gSpawnTileX << 3;
        gCameraTargetY = gSpawnTileY << 3;

        if (gCameraSnapFlag != 0)
        {
            gCameraPosX = gCameraTargetX;
            gCameraPosY = gCameraTargetY;
        }

        BgScroll_LoadFromTable(gMoveCmdSetId);
        gPlayerMoveDir = gSpawnFacingDir;
        Party_FollowStep();

        for (i = 0; i < 8; i++)
        {
            gFollowerHistX[i] = gActors[0].x;
            gFollowerHistY[i] = gActors[0].y;
            gFollowerHistDir[i] = gActors[0].facingDir;
        }

        gActors[1].x = gActors[0].x;
        gActors[1].y = gActors[0].y;
        gActors[1].facingDir = gActors[0].facingDir;

        ScreenFx_SetMode(3);
        gInputLockFrames = 2;
        gMainGameState = 1;
        gScenePhase = 0;
    }
    else
    {

        if (gScenePhase != 1)
        {
            gSceneLoadToggle = (gSceneLoadToggle + 1) & 1;
            gScenePhase = 1;
            Palette_Backup();
            ScreenFx_SetMode(4);
        }
    }

    Sprites_UpdateFrame();
}

// @ 0x08001828
void Scene_ExitToMenu(void)
{
    u16 i;
    u8 val;
    val = gSceneSubState;

    if (val == 0 && gScenePhase == 1)
    {
        Display_ShutdownSequence();
        gVBlankPipelineMode = val;
        gScenePhase = val;

        if (gAfterBattleCounter != 0)
        {
            gAfterBattleCounter++;
            sub_8017FA4(gUnk_030025B8);
        }
        else
        {
            sub_8017FA4(gEncounterEnabled);
        }

        gMainTaskSlot = 1;
        gVBlankPipelineMode = 2;
    }
    else
    {
        if (gScenePhase != 1)
        {
            gScenePhase = 1;
            Palette_Backup();
            ScreenFx_SetMode(4);
            Sfx_Play(0x16, 0, 0);
            Bgm_FadeOut(0x2E);
        }
        Sprites_UpdateFrame();
    }
}

// @ 0x080018D4
void Scene_Reload(void)
{
    s16 i;

    REG_IME = 0;
    MenuEnt_ClearStates();
    gVBlankPipelineMode = 0;
    RenderQueue_Clear();

    for (i = 0; i < 0x80; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    VramTransfer_Clear();
    PalTransfer_Clear();
    if (gAfterBattleCounter != 0)
    {
        gAfterBattleCounter++;

        if (gBattleResultType == 2)
        {
            BgPal_ResetFirst();
            REG_WIN0H = 0xF0;
            REG_WIN0V = 0xA0;
            REG_DISPCNT |= DISPCNT_WIN0_ON;
            REG_WININ = 0;
            REG_WINOUT = 0;
            gVBlankPipelineMode = 1;
            gMainGameState = 1;
            gScenePhase = 0;
            REG_IME = 1;
            Display_RestartAfterLoad();
            return;
        }
    }
    Party_FollowStep();
    gVBlankPipelineMode = 1;
    REG_IME = 1;
    MapScene_Load(gMapNpcSetId);

    if (!(1 & Script_GetFlags()))
    {
        sub_80525E8(gCurrentSongId, 0, 1);
    }

    ReloadAllSpriteSheets();
    BgScroll_LoadFromTable(gMoveCmdSetId);
    StaticObjGfx_LoadPair(gMapObjGfxSetId);

    gMainGameState = 1;
    gScenePhase = 0;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if (gAfterBattleCounter == 0 || (gBattleResultType != 1))
    {
        Palette_Backup();
        ScreenFx_SetMode(3);
    }

    Display_RestartAfterLoad();

    if (gSceneTransitionArg != 0)
    {
        VBlankWaitExit_PumpSound();
        Bgm_Play(gSceneTransitionArg, 0);
        VBlankWaitExit_PumpSound();
        Bgm_FadeIn(4);
    }

    Sprites_UpdateFrame();
}

// @ 0x08001A7C
void Scene_EnterDoor(void)
{
    s32 var_r4;

    if (gSceneSubState == 0 && gScenePhase == 1)
    {
        Display_ShutdownSequence();
        MenuEnt_ClearStates();
        SpritePool_Clear();
        Queue34C0_Clear();
        RenderQueue_Clear();
        MapBg_LoadInterior(gChoiceGroupIdx);
        PlayerSheets_Load();
        Party_FollowAnim();
        gCameraPosX = 0;
        gCameraPosY = 0;
        gPlayerMoveDir = 4;
        Palette_Backup();
        ScreenFx_SetMode(3);
        gScenePhase = 0;
        gMainGameState = 9;
        Party_SetFollowMode();
        sub_8008124();

        ChoiceMenu_ResolveDest(*(u8 *)(gChoiceListPtr + gChoiceCursor) & 0xF);

        gCameraTargetX = gChoiceDestX;
        gCameraTargetY = gChoiceDestY;
        gActors[1].x = gChoiceDestX;
        gActors[1].y = gChoiceDestY - 8;
        gActors[1].stateFlags |= 0x10u;
        gActors[1].facingDir = 4;
        BattleIntro_Cursor();
        Display_RestartAfterLoad();
        gSceneTransitionArg = 0;

        var_r4 = EventFlags_Test(0x39) != 0 ? 6 : 5;

        VBlankWaitExit_PumpSound();
        Bgm_Play(var_r4, 0);
        VBlankWaitExit_PumpSound();
        Bgm_FadeIn(4);
        return;
    }

    if (gScenePhase != 1)
    {
        gSceneLoadToggle = (gSceneLoadToggle + 1) & 1;
        gScenePhase = 1;
        Palette_Backup();
        ScreenFx_SetMode(4);
        Bgm_FadeOut(0x2E);
    }

    Sprites_UpdateFrame();
}
// @ 0x08001BD0
void Scene_RestoreAfterBattle(void)
{
    s16 i;

    MenuEnt_ClearStates();
    RenderQueue_Clear();

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    VramTransfer_Clear();
    PalTransfer_Clear();
    AnimSlots_Release();
    StaticObjs_Reset();
    Script_ResetVM();

    gWarpAnimState = 0;
    gCameraSnapFlag = 0;
    gSceneEntryFlag = 0xFF;

    DmaCopy16(3, (void *)0x0203F000, gSpriteNodePool, 0xA00);
    DmaCopy16(3, (void *)0x0203FE00, (void *)0x030034C0, 0x100);

    Party_FollowStep();
    Followers_ResetHistory();
    MapScene_Load(gMapNpcSetId);
    sub_80525E8(gCurrentSongId, 0, 1);
    ReloadAllSpriteSheets();
    BgScroll_LoadFromTable(gMoveCmdSetId);
    StaticObjGfx_LoadPair(gMapObjGfxSetId);
    StaticObjs_Spawn(gMapObjGfxSetId);

    gMainGameState = 1;
    gScenePhase = 0;

    Palette_Backup();
    ScreenFx_SetMode(3);

    gInputLockFrames = 2;

    Display_RestartAfterLoad();

    if (gSceneTransitionArg != 0)
    {
        Bgm_Play(gSceneTransitionArg, 0);
        Sprites_UpdateFrame();
        VBlankWaitExit_PumpSound();
        Bgm_FadeIn(4);
    }
    Sprites_UpdateFrame();
}


// @ 0x08001D08
void Task_MapExplore(void)
{
    u8 eventId;
    u8 moveFlags;
    u8 moveSpeed;

    moveFlags = 0;

    gActors[0].stateFlags &= ~0x40;

    if ((Script_GetFlags() & 1) == 0)
    {
        gDialogueActive = 0;
        if (gCutsceneActive && (gScreenFadeFlags & 0x80) == 0 && !gSceneSubState)
        {
            gMainGameState = 0xB;
            gScenePhase = 5;
            return;
        }
    }
    else
    {
        gDialogueActive = 1;
        if (gCutsceneActive && (gScreenFadeFlags & 0x80) == 0 && !gSceneSubState && (gNewKeysRaw & 0x30F) != 0)
        {
            Script_Abort(1);
            gMainGameState = 0xB;
            gScenePhase = 5;
            return;
        }
    }

    if ((gHeldKeysRaw & ABXY_BUTTONS) == ABXY_BUTTONS)
    {
        //Reset Game
        Script_Abort(1);
        System_ResetToLogo();
        return;
    }

    if (gUnk_03004D4C == 0 && gWarpAnimState == 0)
    {
        if (!gDialogueActive && (gScreenFadeFlags & 0x80) == 0 && !gSceneSubState)
        {
            if (gInputLockFrames != 0)
            {
                gInputLockFrames--;
                gNewKeysRaw = 0;
                gHeldKeysRaw = 0;
            }

            if (gPendingCharaSwitch != 0xFF)
            {
                sub_80526A0(gPendingCharaSwitch, 2);
                gPendingCharaSwitch = 0xFF;
            }
            else
            {
                if (gNewKeysRaw & A_BUTTON)
                {
                    eventId = CheckFacingEvent();
                    if (eventId != 0)
                    {
                        sub_80526A0(eventId - 1, 2);
                    }
                }
                else if (gNewKeysRaw & B_BUTTON)
                {
                    sub_800ACC8();
                }
                if ((Script_GetFlags() & 1) != 0)
                {
                    gDialogueActive = 1;
                }

                //gDialogueActive = 1     表示当前正在对话，无法移动
                //gUnk_03004D4C = 0xD   菜单界面，无法移动

                if (gDialogueActive || gUnk_03004D4C)
                {
                    moveSpeed = 0;
                }
                else
                {
                    if (CheckEncounter() != 0)
                    {
                        //gMainGameState = 5 立即进入战斗界面
                        gMainGameState = 5;
                        return;
                    }

                    if (gHeldKeysRaw & DPAD_UP)
                    {
                        moveFlags = 1;
                        gActors[0].stateFlags |= 0x40;
                    }
                    else if (gHeldKeysRaw & DPAD_DOWN)
                    {
                        moveFlags = 2;
                        gActors[0].stateFlags |= 0x40;
                    }
                    if (gHeldKeysRaw & DPAD_LEFT)
                    {
                        moveFlags |= 4;
                        gActors[0].stateFlags |= 0x40;
                    }
                    else if (gHeldKeysRaw & DPAD_RIGHT)
                    {
                        moveFlags |= 8;
                        gActors[0].stateFlags |= 0x40;
                    }

                    if (gWalkMoveDirLut[moveFlags])
                    {
                        gPlayerMoveDir = gWalkMoveDirLut[moveFlags] - 1;
                        moveSpeed = 2;
                    }
                    else
                    {
                        moveSpeed = 0;
                    }
                }
                MovePlayer(&gCameraTargetX, &gCameraTargetY, gPlayerMoveDir + 1, moveSpeed);
            }
        }
    }
    else if (gUnk_03004D4C != 0)
    {
        sub_800ACC8();
    }
    else
    {
        //gWarpAnimState = 1  开始播放传送动画
        switch (gWarpAnimState)
        {
            case 1:
                gWarpAnimState = 2;
                break;
            case 2:
                CutsceneAnim_Load(0x78, 0, 0xA);
                VBlankWait_PumpSound();
                CutsceneAnim_Load(0x79, 1, 0xA);
                VBlankWait_PumpSound();
                gWarpAnimState = 3;
                break;
            case 3:
                Sfx_Play(0x19, 0, 0);
                Chara_InitEffectAtPlayer();
                Chara_StartScriptAnim(0x12, 0);
                gWarpAnimState = 4;
                break;
            case 4:
                if (Chara_AnimWaitDone(0x12) != 0)
                {
                    Sfx_Play(0x1A, 0, 0);
                    Chara_FreeSprite(0);
                    Chara_FreeSprite(1);
                    Chara_StartScriptAnim(0x12, 1);
                    gWarpAnimState = 5;
                }
                break;
            case 5:
                if (Chara_AnimWaitDone(0x12) != 0)
                {
                    gMainGameState = 3;
                    Chara_FreeSprite(0x12);
                    gWarpAnimState = 9;
                }
                break;
            case 6:
                Sfx_Play(0x1A, 0, 0);
                CutsceneAnim_Load(0x7A, 0, 0xA);
                VBlankWait_PumpSound();
                CutsceneAnim_Load(0x7B, 1, 0xA);
                VBlankWait_PumpSound();
                Chara_InitEffectAtPlayer();
                Chara_StartScriptAnim(0x12, 0);
                gWarpAnimState = 7;
                break;
            case 7:
                if (Chara_AnimWaitDone(0x12) != 0)
                {
                    Sfx_Play(0x19, 0, 0);
                    Chara_StartScriptAnim(0x12, 1);
                    gWarpAnimState = 8;
                }
                break;
            case 8:
                if (Chara_AnimWaitDone(0x12) != 0)
                {
                    gWarpAnimState = 0;
                    Chara_FreeSprite(0x12);
                }
                break;
            case 9:
                if ((0x80 & gScreenFadeFlags) || (gSceneSubState != 0))
                {
                    gWarpAnimState = 10;
                }
                break;

            case 10:
                if (!(0x80 & gScreenFadeFlags) && (gSceneSubState == 0))
                {
                    gWarpAnimState = 6;
                }
                break;
        }
    }

    if (gDialogueActive != 0)
    {
        gActors[0].stateFlags |= 0x40;
    }
    ScriptPump_Run();
    LogoBlendEffect_Update();
    Sprites_UpdateFrame();
}

// @ 0x08002154
void Sprites_UpdateFrame(void)
{
    u16 i;
    u16 ret0;
    Actor *ptr03002E80;
    Chest *ptr03004890;

    Viewport_UpdateScroll();
    AnimSlots_StepAll();
    sub_80053B4(gCameraPosX, gCameraPosY);

    if (gObjGraphicsSetId != 0xFF)
    {
        if ((gObjGraphicsSetId & 0x80) != 0 && gObjGraphicsSetId < 0xFE)
        {
            i = 0;
            ptr03002E80 = gActors;
            do
            // for(; i < 19; i++)
            {
                if (ptr03002E80->sprNodeIdx && (ptr03002E80->renderFlags & 1) != 0)
                {
                    ret0 = Chara_StepMove(i);
                    if (ret0 == 1 && ptr03002E80->cmdStream)
                    {
                        ptr03002E80->stepTimer++;
                        ret0 = 2;
                    }
                    if (ret0 <= 1)
                    {
                        Chara_ProcessCmdStream(i);
                    }
                    Sprite_UpdateCharaAnim(i);
                    Sprite_EnqueueRender(Chara_GetDrawX(ptr03002E80), ptr03002E80->y, ptr03002E80->sprNodeIdx, Chara_GetDrawZ(ptr03002E80),
                                ptr03002E80->renderFlags);
                    if (ptr03002E80->subSprNodeIdx)
                    {
                        gSpriteNodePool[ptr03002E80->subSprNodeIdx].flags = 0;
                        gSpriteNodePool[ptr03002E80->subSprNodeIdx].next = 0;
                        ptr03002E80->subSprNodeIdx = 0;
                    }
                    Sprite_SetupDialogArrow(i);
                }
                ptr03002E80++;
                i++;
            } while (i < 19);
        }
        else
        {
            Party_FollowStep();
            i = 2;
            ptr03002E80 = &gActors[i];
            do
            // for( ; i < 19; i++)
            {
                if (ptr03002E80->sprNodeIdx)
                {
                    if (!gUnk_03004D4C && (!gWarpAnimState || gWarpAnimState == 9) && (ptr03002E80->stateFlags & 0x88) != 8)
                    {
                        ret0 = Chara_StepMove(i);
                        if (ret0 == 1 && ptr03002E80->cmdStream)
                        {
                            ptr03002E80->stepTimer++;
                            ret0 = 2;
                        }
                        if (ret0 <= 1)
                        {
                            Chara_ProcessCmdStream(i);
                        }
                    }
                    Sprite_UpdateCharaAnim(i);
                    if (ptr03002E80->subSprNodeIdx)
                    {
                        gSpriteNodePool[ptr03002E80->subSprNodeIdx].flags = 0;
                        gSpriteNodePool[ptr03002E80->subSprNodeIdx].next = 0;
                        ptr03002E80->subSprNodeIdx = 0;
                    }
                    if (Sprite_EnqueueRender(ptr03002E80->x, ptr03002E80->y, ptr03002E80->sprNodeIdx, ptr03002E80->z,
                                    ptr03002E80->renderFlags))
                    {
                        ptr03002E80->stateFlags |= 8;
                    }
                    else
                    {
                        ptr03002E80->stateFlags &= ~8;
                        Sprite_SetupDialogArrow(i);
                    }
                }
                ptr03002E80++;
                i++;
            } while (i < 19);
        }

        for (i = 0; i < 16; i++)
        {
            if (gChests[i].spriteNodeIdx)
            {
                Sprite_EnqueueRender(gChests[i].x, gChests[i].y, gChests[i].spriteNodeIdx, 0, 255);
            }
        }
    }

    StaticObjs_StepAll();
    OAM_FlushFromQueue();
    sub_80091C4();
}

// @ 0x08002380
void Sprite_SetupDialogArrow(u8 charaId)
{
    Actor *charaObj;
    SpriteNode *sprNode;

    if ((gFrameCounter & 1) == (charaId & 1))
    {
        charaObj = &gActors[charaId];
        if (!(charaObj->renderFlags & 2))
        {
            if (charaObj->subSprNodeIdx == 0)
            {
                charaObj->subSprNodeIdx = Sprite_AllocNode();
            }
            sprNode = &gSpriteNodePool[charaObj->subSprNodeIdx];

            if ((charaObj->renderFlags & 1) != 0)
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

            Sprite_EnqueueRender(Chara_GetDrawX(charaObj), charaObj->y - 0xA0, charaObj->subSprNodeIdx, -0xA0, 0xFE);
        }
    }
}
// @ 0x0800243C
INCLUDE_ASM("asm/matchings", Sprite_EnqueueRender);

/*
// @ 0x0800243C
u8 Sprite_EnqueueRender(s16 x, s16 y, u8 sprNodeIdx, s16 z, u8 arg4)
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

    if (gViewportFlags[0] & 1) {
        screenX = x - ((gCameraPosX & ~0xF) + gBG3ScrollX);
    } else {
        screenX = x - gCameraPosX;
    }
    
    if (gViewportFlags[0] & 2) 
    {
        screenY = y - ((gCameraPosY & ~0xF) + gBG3ScrollY) - 4 - z;
    } else {
        screenY = y - gCameraPosY - 4 - z;
    }

    while(count != 0)
    {
        gCurSpriteW = gWalkAnimDimTable[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6)];
        gCurSpriteH = gWalkAnimDimTable[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6) + 1];


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

        if((x + gCurSpriteW + offsetX) >= gCameraPosX && (x +  offsetX) <= gCameraPosX + 240
              && (y + gCurSpriteH + offsetY - z - 4) >= gCameraPosY && (y +  offsetY - z - 4) <= gCameraPosY + 160)
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

// @ 0x0800243C
u8 Sprite_EnqueueRender(s16 x, s16 y, u8 arg2, s16 z, u8 arg4) {
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

    if (gViewportFlags[0] & 1) {
        screenX = x - ((gCameraPosX & ~0xF) + gBG3ScrollX);
    } else {
        screenX = x - gCameraPosX;
    }

    if (gViewportFlags[0] & 2)
    {
        screenY = y - ((gCameraPosY & ~0xF) + gBG3ScrollY) - 4 - z;
    } else {
        screenY = y - gCameraPosY - 4 - z;
    }

    while(num != 0)
    {
        gCurSpriteW = gWalkAnimDimTable[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6)];
        gCurSpriteH = gWalkAnimDimTable[ ((sprNode->attr0 >> 11) & 0x18) + ((sprNode->attr1 >> 13) & 6) + 1];


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

        if((x + gCurSpriteW + offsetX) >= gCameraPosX && (x +  offsetX) <= gCameraPosX + 240
              && (y + gCurSpriteH + offsetY - z - 4) >= gCameraPosY && (y +  offsetY - z - 4) <= gCameraPosY + 160)
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

// @ 0x0800271C
INCLUDE_ASM("asm/matchings", Sprite_UpdateCharaAnim);
/*

//这些数据在原始rom rodata中的位置是在 tileset_3_080583C4 后面
u8 gWalkAnimFrameMapping[] = {0, 1, 2, 1, 0, 1, 0, 1};
u8 gWalkDirectionMapping[] = {2, 3, 3, 3, 0, 1, 1, 1, 1, 2, 2, 2, 3, 0, 0, 0, 0};



extern SpriteNode gSpriteNodePool[128];

extern SpriteNode* gSpriteRenderQueue[128];

extern Actor gActors[];


// @ 0x0800271C
void Sprite_UpdateCharaAnim(u8 arg0)
{
    Actor *charaObj;
    SpriteNode* sprNode;
    u16 paletteBits;
    u8 directionIndex;
    u8 temp_r7;
    u32 currentFrameTileOffset;

    charaObj = &gActors[arg0];

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

    Anim_PlayCustom(arg0);
}

asm(".align 2,0");

*/

// @ 0x080029D8
INCLUDE_ASM("asm/matchings", Anim_PlayCustom);

/*


extern u8* gCutsceneAnimPals[];
extern u8 gCutsceneAnimSlots[];
extern u8 gCutsceneAnimFlags[];

extern u8* gCutsceneAnimScripts[];

u8 PalTransfer_AllocSlot();

void Anim_BuildOamChain(u8 arg0, u8 *arg1);

void PalTransfer_Enqueue(u8 , void* , u8 , u8 );


// @ 0x080029D8
void Anim_PlayCustom(u8 arg0) {
    Actor* chara;
    u8* animDataPtr;
    u8* frameDataPtr;
    u16 offset;

    chara = &gActors[arg0];

    if(chara->currAnimIdx == 0xFF)
        
        return;

    animDataPtr = gCutsceneAnimScripts[chara->currAnimIdx];

    if(chara->animFrameTimer == 0xFF)
        return;

    // offset = animDataPtr[2] + (animDataPtr[3] << 8);

    frameDataPtr = animDataPtr +  (animDataPtr[2] + (animDataPtr[3] << 8));

    
    if(chara->animFrameTimer == 0)
    {
        if( animDataPtr[6] + (animDataPtr[7] << 8) == 2)
        {
            PalTransfer_Enqueue(PalTransfer_AllocSlot(), gCutsceneAnimPals[chara->currAnimIdx], gCutsceneAnimSlots[chara->currAnimIdx] + 16, 2);
        }
        else
        {
            PalTransfer_Enqueue(PalTransfer_AllocSlot(), gCutsceneAnimPals[chara->currAnimIdx], gCutsceneAnimSlots[chara->currAnimIdx] + 16, 0);

        }
        frameDataPtr += 8;

        offset = (frameDataPtr[0] + (frameDataPtr[1] << 8)) << 1;
        // unkPtr = &animDataPtr[offset];

        Anim_BuildOamChain(arg0, (animDataPtr + animDataPtr[offset + 8] + (animDataPtr[offset + 9]<<8)) + 4);
        chara->animFrameTimer++;
    }
    else
    {
        u16 time = frameDataPtr[2] + (frameDataPtr[3] << 8);
        u16 count = frameDataPtr[6] + (frameDataPtr[7] << 8);

        frameDataPtr += 8;

        if(chara->animFrameTimer >= time)
        {
            if((gCutsceneAnimFlags[chara->currAnimIdx] & 0x80) == 0)
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
                Sprite_FreeChain(&gRenderObjects[chara->sprNodeIdx]);
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
                
                Anim_BuildOamChain(arg0, (animDataPtr + animDataPtr[offset+8] + (animDataPtr[offset+9]<<8)) + 4);
                // Anim_BuildOamChain(arg0,  unkPtr + 4);
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

// @ 0x08002B54
INCLUDE_ASM("asm/matchings", Anim_BuildOamChain);

/*
extern u8 gCutsceneAnimSlots[];
extern s8 gSpriteTileCountTable[];

extern u32 gVramBufferPointers[];
extern s8 gWalkAnimDimTable[];

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

void VramTransfer_Enqueue(u16 id, void* src, void* dest, u8 arg3);


//00 00   idx
//02 00   num

//DF 80 F4 81 00 00 DF 80 04 40 08 00
//SpriteOamAttr[num]

// @ 0x08002B54
void Anim_BuildOamChain(u8 arg0, u8 *arg1) {
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

    ptr2E80 = &gActors[arg0];

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

    ptr2E80->sprNodeIdx = Sprite_AllocNode();
    renderObj = &gSpriteNodePool[ptr2E80->sprNodeIdx];

    val_r8 = gCutsceneAnimSlots[ptr2E80->field_16] * 72 + 160;

    oamDataPtr = &arg1[oamDataOffset];

    while(num != 0)
    {

        tileCount = gSpriteTileCountTable[(oamDataPtr[1] >> 6) * 4 + (oamDataPtr[3] >> 6)];

        val_r4_1 = oamDataPtr[4];
        dmaSlotId = VramTransfer_AllocSlot();

        src = (u8*) gVramBufferPointers[ptr2E80->field_16] + (val_r4_1 << 5);
        dest = (u8*)0x06010000 + (val_r8 << 5);
        VramTransfer_Enqueue(dmaSlotId, src, dest, tileCount);

        attr0 = oamDataPtr[0] | (oamDataPtr[1] << 8);

        if ((gCutsceneAnimFlags[ptr2E80->field_16] & 0x40) != 0)
        {
            attr1 = (oamDataPtr[2] + (oamDataPtr[3] << 8)) | 0x1000;
        }
        else
        {
            attr1 = (oamDataPtr[2] + (oamDataPtr[3] << 8));
            renderObj->field_10 = attr1 & 0x1FF;
        }
        renderObj->field_12 = attr0 & 0xFF;

        attr2 = ((oamDataPtr[5] << 8) & ~0xFFF) + (vramOffset +(gCutsceneAnimSlots[ptr2E80->field_16] << 12) +  val_r8);

        subObj = Sprite_InitChainNode(renderObj, num, attr0, attr1, attr2);

        if ((gCutsceneAnimFlags[ptr2E80->field_16] & 0x40) != 0)
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
// @ 0x08002D54
u8 CheckEncounter(void)
{

    // gEncounterEnabled
    if (gEncounterEnabled == 0)
        return 0;

    if (gHeldKeysRaw & DPAD_ANY)
    {
        if (EventFlags_Test(0xBB) == 0)
        {
            // gEncounterTimer
            gEncounterCounter--;
            if (gEncounterCounter == 0)
            {
                // Rand
                gEncounterCounter = ((Rand_TableNext() & 7) << 5) + 0xE8;
                if (gCurrentMapId == 0x7B)
                {
                    gEncounterCounter >>= 1;
                }
                return 1;
            }
        }
        else
        {
            if (gEncounterCounter < 0xE8)
            {
                gEncounterCounter = 0xE8;

                if (gCurrentMapId == 0x7B)
                {
                    gEncounterCounter = 0x74;
                }
            }
        }
    }

    return 0;
}

// @ 0x08002DDC
void LogoBlendEffect_Update(void)
{

    if (gLogoEffectState == 0)
    {
        return;
    }
    switch (gLogoEffectState)
    {
        case 1:
            REG_DISPCNT &= 0xFEFF;
            gBlendControl = 0x1E41;
            gBlendCoefficients = 0xF00;
            gUnk_03000004 = 0;
            return;

        case 2:
        case 3:
        case 4:
        case 10:
            break;

        case 5:
            REG_DISPCNT |= 0x100;
            gBlendCoefficients = 0xF00;
            gLogoEffectState++;
            break;

        case 6:
            gUnk_03000004++;
            gBlendCoefficients &= 0xF00;
            gBlendCoefficients |= (gUnk_03000004 >> 2) & 0x1F;
            if ((gUnk_03000004 >> 2) == 0x1F)
            {
                gLogoEffectState++;
                gUnk_03000004 = 0;
            }
            break;

        case 7:
            gUnk_03000004++;
            if (!(gUnk_03000004 & 3))
            {
                gBlendCoefficients -= 0x100;
                if (!(gBlendCoefficients & 0xFF00))
                {
                    gLogoEffectState++;
                    gUnk_03000004 = gBlendCoefficients & 0xFF00;
                }
            }
            break;

        case 8:
            gUnk_03000004++;
            if (gUnk_03000004 > 0x1B3)
            {
                gLogoEffectState++;
                gUnk_03000004 = 0;
            }
            break;
        case 9:
            gUnk_03000004++;
            gBlendCoefficients = (((gUnk_03000004 >> 2) & 0x1F) << 8) | ((0x1F - (gUnk_03000004 >> 2)) & 0x1F);
            if (gBlendCoefficients == 0x1F00)
            {
                gLogoEffectState++;
                gUnk_03000004 = 0;
            }
            break;
    }
}


#define GET_PLTT(n)    ((n) + 0)
#define GET_TILEMAP(n) ((n) + 32)
// INCLUDE_ASM("asm/matchings", LogoAssets_Load);

// @ 0x08002F6C
void LogoAssets_Load(void)
{

    switch (gLogoEffectState)
    {
        case 1:
            REG_BG0CNT = BGCNT_SCREENBASE(31) | BGCNT_CHARBASE(2);
            DmaCopy16(3, (void *)GET_PLTT(pltt_08057854), (void *)0x050001C0, 0x20);
            LZ77UnCompVram((void *)GET_TILEMAP(pltt_08057854), (void *)BG_SCREEN_ADDR(31));
            gLogoEffectState++;
            break;
        case 2:
            LZ77UnCompVram(tileset_1_08057A80, (void *)0x06008000);
            gLogoEffectState++;
            break;
        case 3:
            LZ77UnCompVram(tileset_2_08057EEC, (void *)0x06008800);
            gLogoEffectState++;
            break;
        case 4:
            LZ77UnCompVram(tileset_3_080583C4, (void *)0x06009000);
            gLogoEffectState++;
            break;
        case 10:
            REG_DISPCNT &= 0xFEFF;
            gBlendControl = 0x1C12;
            gBlendCoefficients = 0xC07;
            CpuFill16(0, (void *)0x0600F800, 0x800);

            gLogoEffectState = 0;
        default:
            return;
    }
}




// @ 0x08003088
void Task_DispatchGameState(void)
{
    ReadKeys();
    RenderQueue_Clear();
    gUnk_087E83F8[gMainGameState]();
}

//地图场景切换，加载数据精灵
// @ 0x080030B0
void SceneTransition_RequestMap()
{
    if (gSceneSubState == 0 && gScenePhase == 1)
    {
        gMainGameState = 2;
        gVBlankPipelineMode = 1;
    }
    else if (gScenePhase != 1)
    {
        gSceneLoadToggle = (gSceneLoadToggle + 1) & 1;
        gScenePhase = 1;
        Palette_Backup();
        ScreenFx_SetMode(4U);
    }
    Sprites_UpdateFrame();
}

// @ 0x08003114
void Task_DialogueFrame(void)
{
    sub_800ACC8();
    sub_800C194();
    OAM_FlushFromQueue();
}

// @ 0x08003128
void Task_BattleMenuFrame(void)
{
    if (!(0x80 & gScreenFadeFlags) && (gSceneSubState == 0))
    {
        ChoiceMenu_HandleInput(gNewKeysRaw);
    }
    BattleIntro_Cursor();
    Party_FollowStep();
    OAM_FlushFromQueue();
    sub_80091C4();
}

// @ 0x08003168
void Scene_ReloadViaMenu()
{
    if (gSceneSubState == 0 && gScenePhase == 1)
    {
        Followers_SyncToTail();
        gMainGameState = 2;
        gVBlankPipelineMode = 1;
    }
    else if (gScenePhase != 1)
    {
        gSceneLoadToggle = (gSceneLoadToggle + 1) & 1;
        gScenePhase = 1;
        Palette_Backup();
        ScreenFx_SetMode(4);
        Bgm_FadeOut(0x2E);
    }
    BattleIntro_Cursor();
    Party_FollowStep();
    OAM_FlushFromQueue();
    sub_80091C4();
}

// @ 0x080031E4
void Task_SaveMenuFrame()
{
    sub_8011454();
    sub_80091C4();
    OAM_FlushFromQueue();
}

// @ 0x080031F8
void Task_TextFrame()
{
    sub_801417C();
    OAM_FlushFromQueue();
}

// @ 0x08003208
void Scene_ResetResources(void)
{
    u16 i;

    Sprites_ReleaseAll();
    RenderQueue_Clear();
    SpritePool_Clear();
    Queue34C0_Clear();

    for (i = 0; i < 128; i++)
    {
        gOamBuffer[i].attrs[0] = 0;
        gOamBuffer[i].attrs[1] = 0;
    }

    VramTransfer_Clear();
    PalTransfer_Clear();
    AnimSlots_Release();
    StaticObjs_Reset();
    OAM_FlushFromQueue();
}

// @ 0x08003254
void Anim_StepChara(u8 arg0)
{
    Anim_PlayCustom(arg0);
}

// @ 0x08003264
void PalTransfer_Flush()
{
    u16 i;
    u32 var_r3;

    for (i = 0; i < 32; i++)
    {
        if (gPalTransferQueue[i].field_1 != 0)
        {
            var_r3 = gPalTransferQueue[i].field_1 == 2 ? 0x40 : 0x20;
            DmaCopy16(3, gPalTransferQueue[i].field_4, 0x05000000 + (gPalTransferQueue[i].field_0 << 5), var_r3);
            gPalTransferQueue[i].field_1 = 0;
        }
    }
}

// @ 0x080032BC
void OAM_FlushFromQueue(void) {
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
                sprNode = Sprite_WriteOam(&index, sprNode);
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

// @ 0x08003348
void Sprites_ReleaseAll(void)
{
    Actor *charaObj;
    u8 sprNodeIdx;
    s16 i;
    u8 count;
    struct SpriteNode *current;
    struct SpriteNode *next;

    for (i = 0; i <= 23; i++)
    {
        charaObj = &gActors[i];
        sprNodeIdx = charaObj->sprNodeIdx;

        if (sprNodeIdx != 0)
        {

            if (charaObj->subSprNodeIdx != 0)
            {
                gSpriteNodePool[charaObj->subSprNodeIdx].flags = 0;
                gSpriteNodePool[charaObj->subSprNodeIdx].next = 0;
                charaObj->subSprNodeIdx = 0;
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
        gActors[i].sprNodeIdx = 0;
    }
}
// @ 0x080033E8
INCLUDE_ASM("asm/matchings", Sprites_LoadMapNPCs);
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
}MapSceneDescriptor;

extern u8 gUnk_08091948[];

extern const MapSceneDescriptor gMapSceneDescriptors[];

typedef struct {
    u16 field_0;
    u8 pad[16 - 2];
}Unk_087EA394;
extern Unk_087EA394* gUnk_087EA394[];

void Chara_InitFromDesc(u8, void*);


// @ 0x080033E8
void Sprites_LoadMapNPCs(u8 arg0) {
    Unk_087EA394* ptr2;
    u16 i;
    u16 temp_r0;
    u32 temp_r3;

    if (gObjGraphicsSetId & 0x80) 
        return;

    i = temp_r3 = gMapSceneDescriptors[arg0].npcSlotGroupId;
    if (i == 0)
        return;

    temp_r0 = (i - 1) * 18;
    arg0 = gUnk_08091948[temp_r0];

    ptr2 = gUnk_087EA394[temp_r3 - 1];
              

    for ( i = 2; i < arg0 + 2; i++)
    {
        Chara_InitFromDesc(i, ptr2++);
    }
}
*/
// @ 0x0800345C
INCLUDE_ASM("asm/matchings", Chara_InitFromDesc);
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
// @ 0x0800345C
void Chara_InitFromDesc(u8 arg0, UnkStruct* arg1) {
    Actor *chara;
    struct SpriteNode* renderObj;
    struct SpriteNode* subRenderObj;
    u8 idx;
    u16 attr0, attr1, attr2;

    chara = &gActors[arg0];
    idx = Sprite_AllocNode();

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
            Sprite_InitChainNode(renderObj, 1, attr0, attr1, attr2);
        }
        else if(chara->fields_1.stru.bit4)
        {
            attr0 = 0x4000;
            attr1 = 0xC000;
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            renderObj->field_10 = 0x1E8;
            renderObj->field_12 = 0xF8;
            Sprite_InitChainNode(renderObj, 1, attr0, attr1, attr2);
        }
        else if(chara->fields_1.stru.bit5)
        {
            attr1 = 0x8000;
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xB0) & 0x3FF);
            renderObj->field_10 = 0x1F8;
            renderObj->field_12 = 0xE8;
            subRenderObj = Sprite_InitChainNode(renderObj, 2, 0, attr1, attr2);
            
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            subRenderObj->field_10 = 0x1F8;
            subRenderObj->field_12 = 0xC8;

            Sprite_InitChainNode(subRenderObj, 1, 0, attr1, attr2);    
    
        }
        else if(chara->fields_1.stru.bit6)
        {
            attr1 = 0x8000;
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            renderObj->field_10 = 0x1F8;
            renderObj->field_12 = 0xEE;
            subRenderObj = Sprite_InitChainNode(renderObj, 3, 0, attr1, attr2);
            
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xB0) & 0x3FF);
            subRenderObj->field_10 = 0x18;
            subRenderObj->field_12 = 0xEE;
            subRenderObj = Sprite_InitChainNode(subRenderObj, 2, 0, attr1, attr2);

            attr0 = 0x8000;
            attr1 = 0x8000;

            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xC0) & 0x3FF);
            subRenderObj->field_10 = 0x38;
            subRenderObj->field_12 = 0xEE;
            Sprite_InitChainNode(subRenderObj, 1, attr0, attr1, attr2);
        }
        else
        {
            attr1 = 0x4000;
          
            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA0) & 0x3FF);
            renderObj->field_10 = 0;
            renderObj->field_12 = 0xE8;

            subRenderObj = Sprite_InitChainNode(renderObj, 2, 0, attr1, attr2);

            attr0 = 0x4000;

            attr2 = ((chara->paletteId << 12) + 0x800) + (((chara->field_2 * 72) + 0xA4) & 0x3FF);
            subRenderObj->field_10 = 0;
            subRenderObj->field_12 = 0xF8;
            // attr1 = 0;
            subRenderObj = Sprite_InitChainNode(subRenderObj, 1, attr0, 0, attr2);
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
// @ 0x0800375C
void Chara_InitDialogArrow(u8 arg0)
{
    u8 temp_r1;
    Actor *ptr3150;
    ptr3150 = &gDialogArrowActors[arg0];
    temp_r1 = Sprite_AllocNode();
    if (temp_r1 < 0x70)
    {
        ptr3150->sprNodeIdx = 0;
        ptr3150->renderFlags = 2;
        ptr3150->gfxSetId = 9;
        ptr3150->paletteId = 9;
        ptr3150->facingDir = 0;
        ptr3150->x = (gCameraPosX + (arg0 * 5 + 5) * 8);
        ptr3150->y = (gCameraPosY + 0x28);
        ptr3150->field_A = 0;
        ptr3150->field_B = 0;
        ptr3150->field_C = 0;
        ptr3150->field_D = 0;
        ptr3150->field_F = 0;
        ptr3150->field_13 = 0x80;
        ptr3150->cmdStream = 0;
        ptr3150->animTimer = 0;
        ptr3150->targetFacing = 0;
        ptr3150->stepTimer = 1;
        ptr3150->field_11 = 0;
        ptr3150->stateFlags = 0x20;
        ptr3150->cmdPc = 0;
        ptr3150->z = 0;
        ptr3150->subSprNodeIdx = 0;
        ptr3150->field_19 = 0;
        ptr3150->field_14 = 0;
        ptr3150->animIdx = 0xFF;
    }
}

// @ 0x080037DC
void Chara_InitEffect(u8 arg0)
{
    u8 idx;
    Actor *charaObj;
    SpriteNode *sprNode;

    charaObj = &gActors[arg0];

    idx = Sprite_AllocNode();
    if (idx < 0x70)
    {
        sprNode = &gSpriteNodePool[idx];
        charaObj->sprNodeIdx = idx;
        charaObj->renderFlags = 2;
        charaObj->gfxSetId = 5;
        charaObj->paletteId = 5;
        charaObj->facingDir = 0;
        charaObj->field_A = 0;
        charaObj->field_B = 0;
        charaObj->field_C = 0;
        charaObj->field_D = 0;
        charaObj->field_F = 0;
        charaObj->field_13 = 0;
        charaObj->cmdStream = 0;
        charaObj->animTimer = 0;
        charaObj->targetFacing = 0;
        charaObj->stepTimer = 1;
        charaObj->field_11 = 0;
        charaObj->stateFlags = 32;
        charaObj->cmdPc = 0;
        charaObj->z = 0;
        charaObj->subSprNodeIdx = 0;
        charaObj->field_19 = 0;

        sprNode->flags = 0;
        sprNode->animStep = 0;
        sprNode->next = 0;
    }
}

// @ 0x0800384C
void Chara_InitEffectAtPlayer(void)
{
    u8 temp_r1;
    Actor *ptr3150;
    struct SpriteNode *sprNode;

    ptr3150 = &gEffectActor;
    temp_r1 = Sprite_AllocNode();
    if (temp_r1 < 0x70)
    {
        sprNode = &gSpriteNodePool[temp_r1];
        ptr3150->sprNodeIdx = temp_r1;
        ptr3150->renderFlags = 2;
        ptr3150->gfxSetId = 0xA;
        ptr3150->paletteId = 0xA;
        ptr3150->facingDir = 0;
        ptr3150->x = (gCameraTargetX + 8);
        ptr3150->y = (gCameraTargetY + 0xC);
        ptr3150->field_A = 0;
        ptr3150->field_B = 0;
        ptr3150->field_C = 0;
        ptr3150->field_D = 0;
        ptr3150->field_F = 0;
        ptr3150->field_13 = 0x80;
        ptr3150->cmdStream = 0;
        ptr3150->animTimer = 0;
        ptr3150->targetFacing = 0;
        ptr3150->stepTimer = 1;
        ptr3150->field_11 = 0;
        ptr3150->stateFlags = 0x20;
        ptr3150->cmdPc = 0;
        ptr3150->z = 0;
        ptr3150->subSprNodeIdx = 0;
        ptr3150->field_19 = 0;

        sprNode->flags = 128;
        sprNode->animStep = 0;
        sprNode->next = 0;
    }
}
/* 延迟装载的消费者: SetSlotGfxId / SetSlotPalId 只记参数 + 置 gPendingSpriteLoad 位,
 * 真正的搬运在这里做, 做完整体清零。
 * ⚠ 三个必须保持的形态:
 *   1) 两个 if 各读一次 gPendingSpriteLoad (目标是两条独立的 ldrb, 不能提到外面缓存);
 *   2) 位测试写成 `CONST & flags` —— 常量在左(规则 5/78), 换成 `flags & CONST` 会变形态;
 *   3) 装载体必须留在 static inline 的小函数里。把局部变量合并进本函数会让
 *      GCC2 的寄存器分配跑偏(实测: helper 版 5/140 字节差=只剩链接器 thunk,
 *      合并版 59/140)。 */
extern u8 *gUnk_087E8430[];      /* 248 项 LZ77 压缩精灵图块指针表 */
extern u8 gUnk_080B9DFC[][32];  /* 精灵 OBJ 调色板, 每项 16 色 BGR555 */

static inline void Inl_LoadSpriteSheetGfx(u8 slot, u16 gfxId)
{
    u8 *dst = (void *)0x06011400 + slot * 0x900;

    LZ77UnCompVram(gUnk_087E8430[gfxId], dst);
}

static inline void Inl_LoadSpriteSheetPal(u8 slot, u16 palId)
{
    const u8 *src;
    u8 *dst;

    src = gUnk_080B9DFC[palId];
    dst = (void *)0x05000200 + slot * 32;
    DmaCopy16(3, src, dst, 0x20);
}

// @ 0x080038CC
void PendingSpriteLoad_Flush(void)
{
    if (PENDING_SPRITE_GFX & gPendingSpriteLoad)
        Inl_LoadSpriteSheetGfx(gPendingGfxSlot, gPendingGfxId);

    if (PENDING_SPRITE_PAL & gPendingSpriteLoad)
        Inl_LoadSpriteSheetPal(gPendingPalSlot, gPendingPalId);

    gPendingSpriteLoad = 0;
}

// @ 0x08003958
INCLUDE_ASM("asm/nonmatchings", Chara_SetWalkPath);
// @ 0x08003B08
void Chara_ProcessCmdStream(u16 arg0)
{
    u8 var_r5;
    u8 *temp_r2;
    Actor *chara;
    u8 cmd;

    chara = &gActors[arg0];

    if (chara->cmdStream != 0)
    {
        var_r5 = 0;
        while (var_r5 == 0)
        {
            temp_r2 = chara->cmdStream + chara->cmdPc;
            cmd = *temp_r2++;
            switch (cmd)
            {
                case 0xFE:
                    chara->cmdPc = 0;
                    break;
                case 0xFD:
                    chara->stateFlags |= 0x20;
                    chara->stateFlags &= 0x7F;
                    chara->cmdStream = NULL;
                    return;
                case 0xFF:
                    chara->stateFlags &= 0x7B;
                    chara->cmdStream = NULL;
                    var_r5++;
                    break;
                case 3:
                    chara->targetFacing = temp_r2[0];
                    chara->cmdPc += 2;
                    break;
                case 1:
                    chara->cmdPc += 3;
                    chara->targetFacing = temp_r2[0];
                    chara->facingDir = chara->targetFacing;
                    chara->field_F = 0;
                    chara->stepTimer = cmd;
                    chara->field_11 = temp_r2[1];
                    var_r5++;
                    break;

                case 2:
                    chara->stateFlags |= 0x10;
                    chara->cmdPc += 4;

                    chara->targetFacing = *temp_r2++;
                    chara->targetFacing &= 7;

                    chara->field_F = temp_r2[0];
                    chara->stepTimer = temp_r2[1] + 1;
                    return;

                default:
                    chara->cmdPc += 4;
                    chara->targetFacing = temp_r2[0];
                    temp_r2++;
                    chara->field_F = temp_r2[0];
                    chara->stepTimer = temp_r2[1] + 1;
                    var_r5++;
                    break;
            }
            chara->targetFacing &= 7;
            chara->facingDir = chara->targetFacing;
        }
        return;
    }

    if (gDialogueActive == 0)
    {
        switch ((Rand_TableNext() & 7))
        {
            case 1:
            case 4:
            case 5:
            case 6:
                chara->field_11 = 0x10;
                chara->stepTimer = 1;
                break;
            case 2:
                chara->targetFacing++;
                break;
            case 3:
                chara->targetFacing--;
                break;
            case 7:
                break;
        }

        chara->targetFacing &= 7;
        chara->facingDir = chara->targetFacing;
    }
}
// @ 0x08003C54
INCLUDE_ASM("asm/nonmatchings", Chara_StepMove);
// @ 0x08003F40
INCLUDE_ASM("asm/matchings", CheckFacingEvent);
// @ 0x080040E4
INCLUDE_ASM("asm/nonmatchings", Party_FollowAnim);
// INCLUDE_ASM("asm/matchings", Followers_ResetHistory);

// @ 0x08004358
void Followers_ResetHistory(void) {
    u16 i;

    if(!(gPartyFollowFlags & 1))
    {
        for(i = 0; i < 8; i++)
        {
            gFollowerHistX[i] = gActors[0].x;
            gFollowerHistY[i] = gActors[0].y;
            gFollowerHistDir[i] = gActors[0].facingDir & 7;
        }

        gActors[1].x = gActors[0].x;
        gActors[1].y = gActors[0].y;
        gActors[1].facingDir = gActors[0].facingDir & 7;
    }
}

// INCLUDE_ASM("asm/matchings", Followers_SyncToTail);

// @ 0x080043D4
void Followers_SyncToTail(void) {
    u16 i;

    for(i = 0; i < 8; i++)
    {
        gFollowerHistX[i] = gActors[0].x;
        gFollowerHistY[i] = gActors[0].y;
        gFollowerHistDir[i] = gActors[0].facingDir;
    }

    gActors[1].x = gFollowerHistX[7];
    gActors[1].y = gFollowerHistY[7];
    gActors[1].facingDir = gFollowerHistDir[7];
    gPartyFollowFlags &= 0x80;
}
// @ 0x0800445C
INCLUDE_ASM("asm/matchings", Party_FollowStep);
/*
// @ 0x0800445C
void Party_FollowStep(void) {
    Actor* chara;
    u16 i;

    u8 a;
    chara = &gActors[0];
    if(chara->sprNodeIdx != 0)
    {
        a = (chara->field_12 & 0x80);
        if(a != 0)
        {
            if(Chara_StepMove(0) < 2)
            {
                Chara_ProcessCmdStream(0);
            }

            for(i = 7; i > 0; i--)
            {
                gFollowerHistX[i] = gFollowerHistX[i - 1];
                gFollowerHistY[i] = gFollowerHistY[i - 1];
                gFollowerHistDir[i] = gFollowerHistDir[i - 1];
            }

            gFollowerHistX[0] = chara->x;
            gFollowerHistY[0] = chara->y;
            gFollowerHistDir[0] = chara->facingDir & 7;

            gPlayerMoveDir = chara->facingDir;
            gCameraTargetX = chara->x;
            gCameraTargetY = chara->y - 8;

        }

        else
        {
            if((u8)(gWarpAnimState - 6) < 2 || gWarpAnimState == 9 || gWarpAnimState == 10)
                return;

            if(chara->field_12 & 0x40)
            {
                chara->field_11 = 0 ;

                for(i = 7; i > 0; i--)
                {
                    gFollowerHistX[i] = gFollowerHistX[i - 1];
                    gFollowerHistY[i] = gFollowerHistY[i - 1];
                    gFollowerHistDir[i] = gFollowerHistDir[i - 1];
                }
                gFollowerHistX[0] = chara->x;
                gFollowerHistY[0] = chara->y;
                gFollowerHistDir[0] = chara->facingDir & 7;

            }
            else
            {
                chara->field_11 = 1;
            }
            chara->facingDir = gPlayerMoveDir;
            chara->x = gCameraTargetX;
            chara->y = gCameraTargetY + 8;

        }

        if((chara->field_1 & 1) == 0)
        {
            Sprite_UpdateCharaAnim(0);
            Sprite_EnqueueRender(chara->x, chara->y, chara->sprNodeIdx, chara->field_1A, chara->field_1 );
            if(chara->field_18 != 0)
            {
                gSpriteNodePool[chara->field_18].field_0 = 0;
                gSpriteNodePool[chara->field_18].subObject = 0;
                chara->field_18 = 0;
            }

            Sprite_SetupDialogArrow(0);
        }
    }

    chara++;
    if(chara->sprNodeIdx != 0)
    {
        if((gPartyFollowFlags & 1) == 0)
        {
            if((u8)( gWarpAnimState - 6) < 2 || gWarpAnimState == 9 || gWarpAnimState == 10)
                return;
            {
                chara->facingDir = gFollowerHistDir[7];
                chara->x = gFollowerHistX[7];
                chara->y = gFollowerHistY[7];
            }

        }
        else
        {
            if(chara->field_12 & 0x80 && Chara_StepMove(1) < 2)
            {
                Chara_ProcessCmdStream(1);
            }
        }

        if((chara->field_1 & 1) == 0)
        {
            Sprite_UpdateCharaAnim(1);
            Sprite_EnqueueRender(chara->x, chara->y, chara->sprNodeIdx, chara->field_1A, chara->field_1 );
            if(chara->field_18 != 0)
            {
                gSpriteNodePool[chara->field_18].field_0 = 0;
                gSpriteNodePool[chara->field_18].subObject = 0;
                chara->field_18 = 0;
            }

            Sprite_SetupDialogArrow(1);
        }
    }


}
*/



extern u8 gUnk_0838EEF4[];

#define CUTSCENE_ANIM_BASE  ((u8*)0x02020000)
/* 把一个过场动画加载到一个缓冲槽。
 *   animId   : gCutsceneAnimConfigTable 下标 (脚本参数 data[1]|data[2]<<8)
 *   slot     : 0..N 缓冲槽, 每槽占 CUTSCENE_ANIM_BASE + slot*0x1000 的 4 KB VRAM 区
 *   slotSel  : 十进制编码 —— ≥100 表示 "减 100 存为动画槽号, 并额外置 flags 的 bit6"
 */
// @ 0x080046DC
void CutsceneAnim_Load(u16 animId, u8 slot, u8 slotSel) {
        u8 extraFlags;
    u8 animSlot;

    gCutsceneAnimScripts[slot] = gUnk_087E860C[gCutsceneAnimConfigTable[animId].scriptIdx];
    gVramBufferPointers[slot] = (u32)(CUTSCENE_ANIM_BASE + slot * 0x1000);

    if(slotSel > 99)
    {
        extraFlags = 0x40;
        animSlot = slotSel - 100;
    }
    else
    {
        extraFlags = 0;
        animSlot = slotSel;
    }
    gCutsceneAnimFlags[slot] = extraFlags | gCutsceneAnimConfigTable[animId].loopFlag;
    gCutsceneAnimSlots[slot] = animSlot;
    gCutsceneAnimPals[slot] = &gUnk_0838EEF4[gCutsceneAnimConfigTable[animId].palIdx * 32];
    LZ77UnCompWram((void*)gUnk_087E8D84[gCutsceneAnimConfigTable[animId].gfxIdx], (void*)(CUTSCENE_ANIM_BASE + slot * 0x1000));
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

extern u32 gCutsceneAnimScripts[];
extern u32 gCutsceneAnimVram[];
extern u8 gCutsceneAnimFlags[];
extern u8 gCutsceneAnimSlots[];
extern u8* gCutsceneAnimPals[];

#define VRAM_BASE  ((u8*)0x02020000)
#define VRAM_STRIDE 0x1000

// @ 0x080046DC
void CutsceneAnim_Load(u16 arg0, u8 arg1, u8 arg2) {
    u8 a;
    u8 b;

    gCutsceneAnimScripts[arg1] = gUnk_087E860C[gUnk_0805888C[arg0].field_0];
    gCutsceneAnimVram[arg1] = (u32)(VRAM_BASE + arg1 * VRAM_STRIDE);

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

    gCutsceneAnimFlags[arg1] = a | gUnk_0805888C[arg0].loopFlag;
    gCutsceneAnimSlots[arg1] = b;

    gCutsceneAnimPals[arg1] = &gUnk_0838EEF4[gUnk_0805888C[arg0].field_4 * 32];
    LZ77UnCompWram(gUnk_087E8D84[gUnk_0805888C[arg0].field_2], (u32)(VRAM_BASE + arg1 * VRAM_STRIDE));

}


*/

// @ 0x0800478C
INCLUDE_ASM("asm/nonmatchings", CutsceneAnim_PlayFrame);


// @ 0x08004980
void MapGroup_Lookup(void) {
    u8 i;

    gPendingCharaSwitch = 0xFF;

    for(i = 0; i < 22; i++)
    {
        if(gUnk_087E94FC[i].field_0 == gCurrentMapId)
        {
            gUnk_03004618 = i + 1;
            return;
        }
    }
    gUnk_03004618 = 0;

}

// @ 0x080049C8
void Chara_SetTilePos(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
{

    Actor *ptr = &gActors[arg0];

    if (arg1)
    {
        ptr->y = ((arg2 + 1) << 3) + arg3;
    }
    else
    {
        ptr->x = (arg2 << 3) + arg3;
    }
}

// @ 0x08004A00
INCLUDE_ASM("asm/matchings", Chara_MoveBy);
// void Chara_MoveBy(u8 arg0, u8 arg1, u8 arg2, u8 arg3)
// {
//     s16 val;
//     Actor *ptr2E80;

//     if (arg2 != 0)
//     {
//         val = arg3;
//     }
//     else
//     {
//         val = -arg3;
//     }

//     ptr2E80 = &gActors[arg0];

//     if (arg1 != 0)
//     {
//         ptr2E80->y += val;
//     }
//     else
//     {
//         ptr2E80->x += val;
//     }
// }

// @ 0x08004A44
u16 VramTransfer_AllocSlot(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        if (gVramTransferCounts[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

// @ 0x08004A6C
u8 PalTransfer_AllocSlot()
{
    u8 i;

    for (i = 0; i < 32; i++)
    {
        if (gPalTransferQueue[i].field_1 == 0)
        {
            return i;
        }
    }
    return -1;
}

// @ 0x08004A94
void PalTransfer_Enqueue(u8 arg0, u32 arg1, s8 arg2, u8 arg3)
{

    gPalTransferQueue[arg0].field_0 = arg2;
    gPalTransferQueue[arg0].field_4 = arg1;

    if (arg3 != 0)
    {
        gPalTransferQueue[arg0].field_1 = 2;
    }
    else
    {
        gPalTransferQueue[arg0].field_1 = 1;
    }
}

// @ 0x08004AC0
void VramTransfer_Clear(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        gVramTransferCounts[i] = 0;
    }
}

// @ 0x08004ADC
void VramTransfer_Flush(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        if (gVramTransferCounts[i] != 0)
        {
            DmaCopy16(3, gVramTransferQueue[i].src, gVramTransferQueue[i].dest, gVramTransferCounts[i] << 5);
            gVramTransferCounts[i] = 0;
        }
    }
}

// @ 0x08004B2C
void VramTransfer_Enqueue(u16 arg0, void *arg1, void *arg2, u8 arg3)
{

    if (arg0 < 32)
    {
        gVramTransferQueue[arg0].src = arg1;
        gVramTransferQueue[arg0].dest = arg2;
        gVramTransferCounts[arg0] = arg3;
    }
}

// @ 0x08004B60
void PalTransfer_Clear()
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        gPalTransferQueue[i].field_1 = 0;
        gPalTransferQueue[i].field_0 = 0;
        gPalTransferQueue[i].field_4 = 0;
    }
}

// @ 0x08004B8C
void SpritePool_Clear()
{
    u16 i;

    for (i = 0; i < 128; i++)
    {
        gSpriteNodePool[i].flags = 0;
        gSpriteNodePool[i].next = 0;
    }
}

// @ 0x08004BBC
void Queue34C0_Clear(void)
{
    u16 i;

    for (i = 0; i < 32; i++)
    {
        gOamAffineBuf[i].field_0 = 0;
        gOamAffineBuf[i].field_2 = 0;
        gOamAffineBuf[i].field_4 = 0;
        gOamAffineBuf[i].field_6 = 0;
    }
}

// @ 0x08004BE0
void RenderQueue_Clear(void)
{
    u16 i;
    for (i = 0; i < 128; i++)
    {
        gSpriteRenderQueue[i] = 0;
    }
}

// @ 0x08004BFC
u8 Sprite_AllocNode(void)
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

// @ 0x08004C28
SpriteNode *Sprite_InitChainNode(SpriteNode *sprNode, u8 arg1, u16 arg2, u16 arg3, u16 arg4)
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
/* 精灵表槽位布局 (共 12 个槽, 见 ReloadAllSpriteSheets 的 `i < 12`):
 *   OBJ 图块区 VRAM 0x06011400 + slot * 0x900   每槽 2304 B = 72 个 4bpp 8×8 图块
 *   OBJ 调色板   PLTT 0x05000200 + slot * 32      每槽 16 色
 * gfxId / palId 是角色图形编号(来自 gPartyMemberIds / gSlotGfxId / gSlotPalId)。
 *
 * ⚠ dst 必须先算好放进变量: 直接 `LZ77UnCompVram(tbl[id], 0x06011400 + slot*0x900)` 会让
 * GCC2 先算 src 再算 dst, 尾部多一条 `adds r0, r2, #0` 把 src 拷回 r0。 */
extern u8 *gUnk_087E8430[];   /* 248 项 LZ77 压缩图块指针表 */

// @ 0x08004C8C
void LoadSpriteSheetGfx(u8 slot, u16 gfxId)
{
    void *dst;

    dst = (void *)0x06011400 + slot * 0x900;
    LZ77UnCompVram(gUnk_087E8430[gfxId], dst);
}

/* 同上: src/dst 先各自算好再交给 DmaCopy16, 否则 `vu32 *dmaRegs` 会被 CSE 提到最前面,
 * 目标里它是在 src/dst 之后才 `ldr r2, =0x040000D4` 的。 */
extern u8 gUnk_080B9DFC[][32];   /* 每帧 16 色 BGR555 调色板 */

// @ 0x08004CB8
void LoadSpriteSheetPal(u8 slot, u16 palId)
{
    const u8 *src;
    u8 *dst;

    src = gUnk_080B9DFC[palId];
    dst = (void *)0x05000200 + slot * 32;
    DmaCopy16(3, src, dst, 0x20);
}

/* OBJ(精灵) 图块槽位 146~149 留给“箭头/滚动条”字形, 槽位 150 起是 10 个数字字形
 * (后者由 LoadDigitFontObjTiles 连同 OBJ 调色板一起装入 0x060112C0 / 0x050003C0)。 */
#define UI_ARROW_TILES_2  ((const u8 *)0x08393728) /* ◀ ▶      2 块 =  64 B */
#define UI_ARROW_TILES_4  ((const u8 *)0x08393768) /* ◀ ▬ ▶ ▫  4 块 = 128 B */
#define UI_ARROW_OBJ_VRAM ((void *)0x06011240)     /* OBJ 图块基 + 146*32 */

/* 按 arg0 的符号位(= bit7)选一套箭头/滚动条图块, 用 DMA3 以 16 位宽装入 OBJ 图块区。
 * 调用方传的是 gObjGraphicsSetId 的最低字节(按 s8 看), 其 bit7 是图形变体标志:
 *   bit7 = 0  → 2 块(64B), 与 LoadDigitFontObjTiles 的数字字体一起用
 *   bit7 = 1  → 4 块(128B), 此时 LoadDigitFontObjTiles 直接 return 不装数字
 * 注意形参必须是 s8: 目标入口只有 `lsls r0,#0x18` 而没有配对的 asrs,
 * 因为左移已把 bit7 送到符号位, 直接 `cmp r0,#0; blt` 就能完成有符号比较。 */
// @ 0x08004CE8
void LoadArrowObjTiles(s8 arg0)
{
    const u8 *src;
    u16 size;

    if (arg0 >= 0)
    {
        src = UI_ARROW_TILES_2;
        size = 0x40;
    }
    else
    {
        src = UI_ARROW_TILES_4;
        size = 0x80;
    }

    DmaCopy16(3, src, UI_ARROW_OBJ_VRAM, size);
}

// @ 0x08004D20
void Chara_SetGfxPal(u8 arg0, u8 arg1, u8 arg2)
{
    Actor *p;
    p = &gActors[arg0];

    p->gfxSetId = arg1;
    p->paletteId = arg2;

    // gActors[arg0].unk2 = arg1;
    // gActors[arg0].unk3 = arg2;
}

// @ 0x08004D38
void Chara_FreeSprite(u8 arg0)
{
    Actor *ptr2E80;
    struct SpriteNode *node;
    struct SpriteNode *next;

    ptr2E80 = &gActors[arg0];

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
// @ 0x08004D8C
void Chara_SetCmdPtr(u8 arg0, u8 *arg1)
{
    Actor *ptr2E80;
    ptr2E80 = &gActors[arg0];
    ptr2E80->cmdStream = arg1;
}
// @ 0x08004DA4
void Chara_StartMoving(u8 arg0)
{
    Actor *ptr2E80;
    ptr2E80 = &gActors[arg0];
    ptr2E80->stateFlags |= 0x80;
    ptr2E80->stateFlags &= 0xDF;
    ptr2E80->stepTimer = 1;
    ptr2E80->cmdPc = 0;
    ptr2E80->field_11 = 0;
}
// @ 0x08004DD0
u8 Chara_AnyMoving(void)
{
    u8 i;
    Actor *ptr2E80;
    ptr2E80 = gActors;

    for (i = 0; i < 0x18; i++)
    {
        if (ptr2E80->sprNodeIdx != 0 && ptr2E80->stateFlags & 0x80)
            return 1;
        ptr2E80++;
    }

    return 0;
}
// @ 0x08004E04
void Party_SetFollowMode(void)
{
    gPartyFollowFlags |= 1;
}
/* 请求把 gfxId 这套图块装到精灵表槽 slot: 先记入 gSlotGfxId[], 再把单槽参数
 * (gPendingGfxSlot / gPendingGfxId) 写好并置 PENDING_SPRITE_GFX, 由 PendingSpriteLoad_Flush 延迟消费。 */
// @ 0x08004E14
void SetSlotGfxId(u8 slot, u16 gfxId)
{
    gSlotGfxId[slot] = gfxId;

    gPendingGfxSlot = slot;
    gPendingGfxId = gfxId;
    gPendingSpriteLoad |= PENDING_SPRITE_GFX;
}

/* 同上, 调色板版本(置 PENDING_SPRITE_PAL)。 */
// @ 0x08004E48
void SetSlotPalId(u8 slot, u16 palId)
{
    gSlotPalId[slot] = palId;
    gPendingPalSlot = slot;
    gPendingPalId = palId;
    gPendingSpriteLoad |= PENDING_SPRITE_PAL;
}
/* 当前待处理的精灵装载请求位图; 调用方用 PENDING_SPRITE_GFX / PENDING_SPRITE_PAL 测位。 */
// @ 0x08004E7C
u8 GetPendingSpriteLoad(void)
{
    return gPendingSpriteLoad;
}
// @ 0x08004E88
void Chara_SetPosDir(u8 arg0, s32 arg1, s32 arg2, u8 arg3)
{
    Actor *ptr2E80;
    ptr2E80 = &gActors[arg0];

    ptr2E80->x = arg1 * 8;
    ptr2E80->y = arg2 * 8;
    ptr2E80->field_11 = 0;
    ptr2E80->facingDir = arg3;
    ptr2E80->targetFacing = arg3;
}

// @ 0x08004EB8
u16 Chara_GetDrawZ(Actor *arg0)
{
    if (arg0->stateFlags & 1)
    {
        return arg0->z + Camera_GetDrawOffset();
    }

    return arg0->z;
}
// @ 0x08004EDC
s16 Chara_GetDrawX(Actor *arg0)
{
    if (arg0->stateFlags & 1)
    {
        switch (gCameraDrawMode)
        {
            case 2:
                return arg0->x - (gDrawCamX - 256);
            case 5:
                return arg0->x - (gDrawCamX - gCameraPosX);
        }
    }
    return arg0->x;
}
// @ 0x08004F3C
void Sprite_FreeChain(struct SpriteNode *arg0)
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
// @ 0x08004F64
INCLUDE_ASM("asm/matchings", Sprite_WriteOam);
/* Sprite_WriteOam - 把一个精灵链节点渲染进 OAM 缓冲, 并推进 OAM 写入游标。
 *
 * 语义 (与 ROM 逐条对应, 已用 scripts/bytecmp.sh 定档):
 *   SpriteNode *Sprite_WriteOam(u16 *oamIdx, SpriteNode *node)
 *   {
 *       u16 idx = *oamIdx;
 *
 *       if ((s8)node->flags < 0)        // 负数 = 该节点不渲染 (flags 按有符号链计数用)
 *           return node->next;
 *       if (idx > 0x7F)                 // OAM 缓冲已满
 *           return node->next;
 *       gOamBuffer[*oamIdx].attrs[0] = node->attr0 + (node->attr1 << 16);
 *       gOamBuffer[*oamIdx].attrs[1] = node->attr2;
 *       *oamIdx = idx + 1;
 *       return node->next;              // 链尾为 NULL
 *   }
 *
 * 已确证的代码生成要点:
 *   - `(s8)node->flags < 0` 一击命中 `movs r0,#0; ldrsb r0,[r4,r0]` —— 该形态来自
 *     thumb.md *extendqisi2_insn 的 "地址就是裸寄存器" 分支 (见该分支的 mov+ldrsb 输出)。
 *     flags 在 iwram.h 里是 u8, 写成 u8 的 `< 0` 会被整条折掉 (规则 65), 必须显式 (s8)。
 *   - attrs[0] 用 `+` 不是 `|`: 目标是 `adds r1,r1,r0` (规则 36)。
 *   - 游标自增用的是**第一次**读到的 *oamIdx (r6), 而两处取地址各有一条独立 ldrh。
 *
 * 未合入的原因 (纯 C 复现不了, 已穷举 60+ 形态 + -O1/-Os/-g/-fno-gcse 变体):
 *   上面这份写法的 `idx` 会被 GCC2 CSE 折进第一处取地址 -> 少一条 `ldrh r2,[r5]`,
 *   并连带 r5/r6 互换 (44/68 字节差)。要阻止折叠, 在 cse.c 里只有
 *   `do_not_record`(volatile) 或"中间插入一次真正的 store"两条路, 本函数两者都没有。
 *   唯一逐字节一致的写法是把两处下标写成 `*(volatile u16 *)oamIdx` (bytecmp OK 68B),
 *   但那违反规则 79: 调用方 OAM_FlushFromQueue 传的是它自己的栈上 u16, 无异步共享语义,
 *   volatile 在这里纯粹是代码生成工具 -> 不合入, 保留 INCLUDE_ASM。
 */

// @ 0x08004FA8
void Chara_StartScriptAnim(u8 arg0, u8 arg1)
{
    Actor *ptr2E80;
    ptr2E80 = &gActors[arg0];
    ptr2E80->renderFlags |= 1;
    ptr2E80->field_14 = 0;
    ptr2E80->animIdx = arg1;
}
// @ 0x08004FD0
s32 Chara_AnimWaitDone(u8 arg0)
{
    Actor *ptr;

    if (arg0 < 0x64)
    {
        ptr = &gActors[arg0];

        gCutsceneAnimFlags[ptr->animIdx] &= 0x7F;

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
