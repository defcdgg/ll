#ifndef GUARD_DATA_805769C_H
#define GUARD_DATA_805769C_H

#include "gba/types.h"

typedef void (*IntrFunc)(void);

extern IntrFunc const gIntrTable[];

/* 128 项正弦表 (幅值 ±100), 逐扫描线水波效果的源数据 —— 仅被 HBlankWave_BuildTables 读。
 * 类型是 u8 不是 s8, 且必须保持 u8 (依赖 ldrb 零扩展 + 无符号除法)。 */
extern const u8 gWaveSineTable[];

extern const u8 gRandShuffleTable[];

/* 129-entry monotonic 0..128 scanline profile for the WIN0H iris transition. */
extern const u8 gWindowTransitionCurve[];

/* ScreenIdleIcons 的 bit→地图ID 对照表 (bit i = 进入地图 [i] 时置位
 * gScreenIdleEventFlags 的 bit i, 由地图装载 MapScene_Load 写入);
 * [13]=0x78 特例: 不在进入时置位, 由事件标志 0xFD 解锁; [15]=0 结束符 */
extern const u8 gScreenIdleIconPageMap[];

/* 16 项 "页号 -> 道具 id" 表: {0xDD..0xE4} 连续 8 个 + {0x19,0x1A,0x1F,0x2D..0x31}。
 * 围绕它的五个函数构成一组"按页浏览这 16 个道具"的逻辑:
 *   Inv_FindFirstHeld / Inv_FindPrevHeld  翻页 (用 gSkillMenuPage 作当前页)
 *   Inv_FindHeldItemOnPage                本页道具 id, 未持有则 0xFF
 *   sub_804DE20                           压缩成 {id, count} 列表写 gUnk_03000D48
 *   sub_804F050                           反向: 道具 id -> 页号
 * 注意: 必须保持 extern 数组形式, 不要写成 ((const u8 *)0x0839CFAA) 强转宏 ——
 * GCC2 对 const_int 与 symbol_ref 的 local-alloc 结果不同, 强转会换掉暂存寄存器。 */
extern const u8 gInvPageItemIds[];

extern const u16 gDialogPortraitPalettes[];
extern const u8 gDialogPortraitPaletteIds[];
extern const u32 gDialogPortraitGfxTable[]; /* 88 项, 定义在 src/data_87E83F0.c */
extern const u32 gDialogPortraitTilemapPtrs[];

/* 菜单实体 OBJ 调色板表 (0x0808A234): 124 项 × 0x20 字节。
 * 每项第一个半字为保留值，MenuEnt_FlushPalettes 从 +2 DMA 15 色。 */
extern const u8 gMenuEntityPaletteTable[];

extern const u8 pltt_08057854[];
extern const u8 tilemap_08057874[];
extern const u8 tileset_1_08057A80[];
extern const u8 tileset_2_08057EEC[];
extern const u8 tileset_3_080583C4[];

extern const u8 gWalkMoveDirLut[];
extern const u8 gWalkAnimFrameMapping[];
extern const u8 gWalkAnimDimTable[];
extern const u8 gWalkDirectionMapping[];
extern const u8 gSpriteTileCountTable[];

/* 0x0805888C: 过场动画配置表, 481 条 × 8B (字节数 3848 已核) —— 全部结论已逐项验证:
 *   scriptIdx → gUnk_087E860C[帧命令流指针]      范围 0..477, **不等于**条目下标 (是真查找索引)
 *   gfxIdx    → gUnk_087E8D84[LZ77 图形指针]      与 scriptIdx 在 481/481 项里完全相等
 *   palIdx    → &gUnk_0838EEF4[palIdx*32]          范围 0..62 ✓
 *   loopFlag  ∈ {0x00, 0x80}                       → 实为位标志: bit7 = 循环播放
 *   pad_6     在 481/481 项里全为 0               → 填充, 非数据
 * 消费者: CutsceneAnim_Load(animId, slot, slotSel) (src/code_80002A0.c),
 *   其中 slotSel ≥ 100 时减去 100 并额外置 flags 的 bit6。
 *   脚本侧入口: code_804F0B8.c 的 opcode 处理器直接传 data[1]|(data[2]<<8), data[3], data[4]。
 */
typedef struct
{
    /* 0x00 */ u16 scriptIdx; ///< → gUnk_087E860C[]
    /* 0x02 */ u16 gfxIdx; ///< → gUnk_087E8D84[] (实测永远 == scriptIdx)
    /* 0x04 */ u8 palIdx; ///< 0..62, → gUnk_0838EEF4[palIdx*32]
    /* 0x05 */ u8 loopFlag; ///< bit7 = 循环播放 (只有 0x00 / 0x80 两种取值)
    /* 0x06 */ u16 pad_6; ///< 481/481 全为 0
} CutsceneAnimConfig;

extern const CutsceneAnimConfig gCutsceneAnimConfigTable[];

extern const u16 gFacingEventOffsets[];

// extern const u8 unk_80A1314[];

/* ==== 从 data/data.s 的 rom_data blob 搬出的项 (见 src/data_805769C.c) ==== */
extern const u8 gCharNameTextBlock_4[];
extern const u8 gCharNameTextBlock_Catarina[];
extern const u8 gCharNameTextBlock_Homel[];
extern const u8 gCharNameTextBlock_Marius[];
extern const u8 gCharNameTextBlock_Stadjus[];
extern const u8 gCharaCmdStream_87742[];
extern const u8 gCharaCmdStream_87756[];
extern const u8 gCharaCmdStream_8776A[];
extern const u8 gCharaCmdStream_8777E[];
extern const u8 gCharaCmdStream_87792[];
extern const u8 gCharaCmdStream_877A2[];
extern const u8 gCharaCmdStream_877B2[];
extern const u8 gCharaCmdStream_877CE[];
extern const u8 gCharaCmdStream_877EA[];
extern const u8 gCharaCmdStream_8781A[];
extern const u8 gCharaCmdStream_8784A[];
extern const u8 gCharaCmdStream_8786A[];
extern const u8 gCharaCmdStream_8788A[];
extern const u8 gCharaCmdStream_8789E[];
extern const u8 gCharaCmdStream_878B2[];
extern const u8 gCharaCmdStream_878CA[];
extern const u8 gCharaCmdStream_878E2[];
extern const u8 gCharaCmdStream_8791E[];
extern const u8 gCharaCmdStream_8795A[];
extern const u8 gCharaCmdStream_8799E[];
extern const u8 gCharaCmdStream_879E2[];
extern const u8 gCharaCmdStream_87A0A[];
extern const u8 gCharaCmdStream_87A32[];
extern const u8 gCharaCmdStream_87A56[];
extern const u8 gCharaCmdStream_87A7A[];
extern const u8 gCharaCmdStream_87A9A[];
extern const u8 gCharaCmdStream_87ABA[];
extern const u8 gCharaCmdStream_87AE6[];
extern const u8 gCharaCmdStream_87B12[];
extern const u8 gCharaCmdStream_87B46[];
extern const u8 gCharaCmdStream_87B7A[];
extern const u8 gCharaCmdStream_87B8A[];
extern const u8 gCharaCmdStream_87B9A[];
extern const u8 gCharaCmdStream_87BBA[];
extern const u8 gCharaCmdStream_87BC6[];
extern const u8 gCharaCmdStream_87BFE[];
extern const u8 gCharaCmdStream_87C3A[];
extern const u8 gCharaCmdStream_87C72[];
extern const u8 gCharaCmdStream_87C92[];
extern const u8 gCharaCmdStream_87CB6[];
extern const u8 gCharaCmdStream_87CDE[];
extern const u8 gCharaCmdStream_87D02[];
extern const u8 gCharaCmdStream_87D0E[];
extern const u8 gCharaCmdStream_87D46[];
extern const u8 gCharaCmdStream_87D6A[];
extern const u8 gCharaCmdStream_87D82[];
extern const u8 gCharaCmdStream_87D96[];
extern const u8 gCharaCmdStream_87DD2[];
extern const u8 gCharaCmdStream_87DFA[];
extern const u8 gCharaCmdStream_87E12[];
extern const u8 gCharaCmdStream_87E22[];
extern const u8 gCharaCmdStream_87E5A[];
extern const u8 gCharaCmdStream_87E7E[];
extern const u8 gCharaCmdStream_87E92[];
extern const u8 gCharaCmdStream_87EA2[];
extern const u8 gCharaCmdStream_87EB2[];
extern const u8 gCharaCmdStream_87EC2[];
extern const u8 gCharaCmdStream_87EDE[];
extern const u8 gCharaCmdStream_87F12[];
extern const u8 gCharaCmdStream_87F4E[];
extern const u8 gCharaCmdStream_87F6A[];
extern const u8 gCharaCmdStream_87F8E[];
extern const u8 gCharaCmdStream_87FBA[];
extern const u8 gCharaCmdStream_87FEE[];
extern const u8 gCharaCmdStream_88012[];
extern const u8 gCharaCmdStream_8802E[];
extern const u8 gCharaCmdStream_8806A[];
extern const u8 gCharaCmdStream_88096[];
extern const u8 gCharaCmdStream_880B2[];
extern const u8 gCharaCmdStream_880D2[];
extern const u8 gCharaCmdStream_880F2[];
extern const u8 gCharaCmdStream_8810E[];
extern const u8 gCharaCmdStream_8812A[];
extern const u8 gCharaCmdStream_88146[];
extern const u8 gCharaCmdStream_8815A[];
extern const u8 gCharaCmdStream_88176[];
extern const u8 gCharaCmdStream_8818A[];
extern const u8 gCharaCmdStream_8819A[];
extern const u8 gCharaCmdStream_881AA[];
extern const u8 gCharaCmdStream_881C2[];
extern const u8 gCharaCmdStream_881DE[];
extern const u8 gCharaCmdStream_881F6[];
extern const u8 gCharaCmdStream_8820A[];
extern const u8 gCharaCmdStream_88226[];
extern const u8 gChoiceDestTable[]; /* 0x08087648 分组变长目的地表 */
extern const u8 gChoiceDataBase[];
extern const u8 gChoiceGroupPairTable[]; /* 0x0808823A, 84 项 × 2 B */
extern const u8 gChoiceMapSpawnRecordStream[]; /* 0x080882E2..0x08088400 */

/* 地图宝箱表 (0x08088400): 256 项 × 8B。
 * 装载器按 mapId 选出当前地图的项；itemId 作为交互脚本号，
 * specialFlag=1 的项还受事件标志 0x40 门控。坐标是地图 tile 坐标。 */
typedef struct
{
    /* 0x00 */ u8 mapId;
    /* 0x01 */ u8 itemId;
    /* 0x02 */ u8 specialFlag;
    /* 0x03 */ u8 pad_3;
    /* 0x04 */ u16 tileX;
    /* 0x06 */ u16 tileY;
} ChestSpawnEntry;

extern const ChestSpawnEntry gChestSpawnTable[];

/* 地图场景描述符 (0x08088D80): 180 项 × 0x14 字节。
 * 记录场景的资源集、显示/特效参数、NPC 槽组及 BG 数据索引。 */
typedef struct
{
    /* 0x00 */ u8 bgLoadMode; /* MapScene_Load 的背景/特殊场景分支 */
    /* 0x01 */ u8 gfxSetId; /* OBJ 图形资源集/模式 */
    /* 0x02 */ u8 hBlankMode; /* HBlank 波形模式 */
    /* 0x03 */ u8 sceneSubState; /* 场景子状态 */
    /* 0x04 */ u8 bgScrollMode; /* BG1 滚动模式 */
    /* 0x05 */ u8 reserved_5;
    /* 0x06 */ u8 menuEntitySetId; /* 菜单实体描述集 */
    /* 0x07 */ u8 spriteAnimSetId; /* 场景动画组 */
    /* 0x08 */ u8 bg3Mode; /* BG3/显示模式参数 */
    /* 0x09 */ u8 npcSlotGroupId; /* NPC 图形/调色板槽组 */
    /* 0x0A */ u8 bg2Mode; /* BG2/场景附加模式参数 */
    /* 0x0B */ u8 sceneFlag; /* 场景标志 */
    /* 0x0C */ u16 collisionTileMax; /* 地图碰撞判定阈值 */
    /* 0x0E */ u16 tilemapId; /* 地图 tilemap 资源索引 */
    /* 0x10 */ u16 tileSetId; /* 地图 tile 资源索引 */
    /* 0x12 */ u16 bgPaletteId; /* BG 调色板资源索引 */
} MapSceneDescriptor;

extern const MapSceneDescriptor gMapSceneDescriptors[];

/* 场景选择项对应的存档解锁标志编号表 (0x08089B90)，前 49 项由存档 UI
 * 扫描，末尾 3 个零为表尾填充。 */
extern const u8 gSaveMapUnlockFlags[];

/* 地图视口边界表 (0x08089BC4): 每项对应一个移动命令集。
 * 四个值均以 64 像素为单位，依次为摄像机 X/Y 最小坐标和地图宽/高。 */
typedef struct
{
    /* 0x00 */ u8 cameraMinXBlocks;
    /* 0x01 */ u8 cameraMinYBlocks;
    /* 0x02 */ u8 mapWidthBlocks;
    /* 0x03 */ u8 mapHeightBlocks;
} MapViewportBounds;

extern const MapViewportBounds gMapViewportBoundsTable[290];

/* 数字字体 OBJ 调色板 (0x08088C00): 2 组 × 16 色 BGR555，分别装入 OBJ
 * 调色板槽 14 和 15；LoadDigitFontObjTiles 从每组起始处 DMA 0x20 字节。 */
extern const u16 gDigitFontObjPalettes[2][16];

/* 数字字体 OBJ 图块 (0x08088C40): 10 个 4bpp 8x8 tile，共 0x140 字节，
 * LoadDigitFontObjTiles 装入 OBJ 图块槽 150~159。 */
extern const u8 gDigitFontObjTiles[];

extern const u32 gUnk_080597D8[];
extern const u32 gUnk_08059D48[];
extern const u32 gUnk_0805A2B4[];
extern const u32 gUnk_0805A830[];
extern const u32 gUnk_0805ADA0[];
extern const u32 gUnk_0805B30C[];
extern const u32 gUnk_0805B83C[];
extern const u32 gUnk_0805BE10[];
extern const u32 gUnk_0805C330[];
extern const u32 gUnk_0805C82C[];
extern const u32 gUnk_0805CD48[];
extern const u32 gUnk_0805D300[];
extern const u32 gUnk_0805D8FC[];
extern const u32 gUnk_0805DEE4[];
extern const u32 gUnk_0805E4DC[];
extern const u32 gUnk_0805EAF4[];
extern const u32 gUnk_0805EF98[];
extern const u32 gUnk_0805F4B0[];
extern const u32 gUnk_0805F970[];
extern const u32 gUnk_0805FE08[];
extern const u32 gUnk_080602BC[];
extern const u32 gUnk_08060818[];
extern const u32 gUnk_08060D80[];
extern const u32 gUnk_080612F4[];
extern const u32 gUnk_08061878[];
extern const u32 gUnk_08061DB0[];
extern const u32 gUnk_08062350[];
extern const u32 gUnk_080629D8[];
extern const u32 gUnk_080630A8[];
extern const u32 gUnk_08063794[];
extern const u32 gUnk_08063E3C[];
extern const u32 gUnk_08064548[];
extern const u32 gUnk_08064C28[];
extern const u32 gUnk_08065190[];
extern const u32 gUnk_0806574C[];
extern const u32 gUnk_08065CE8[];
extern const u32 gUnk_0806624C[];
extern const u32 gUnk_08066808[];
extern const u32 gUnk_08066D84[];
extern const u32 gUnk_080673C4[];
extern const u32 gUnk_080679B4[];
extern const u32 gUnk_08067FD4[];
extern const u32 gUnk_080685AC[];
extern const u32 gUnk_08068B48[];
extern const u32 gUnk_080690E4[];
extern const u32 gUnk_080696A8[];
extern const u32 gUnk_08069C94[];
extern const u32 gUnk_0806A2A8[];
extern const u32 gUnk_0806A8BC[];
extern const u32 gUnk_0806AE90[];
extern const u32 gUnk_0806B46C[];
extern const u32 gUnk_0806BA34[];
extern const u32 gUnk_0806C008[];
extern const u32 gUnk_0806C5D4[];
extern const u32 gUnk_0806CB50[];
extern const u32 gUnk_0806CFD8[];
extern const u32 gUnk_0806D468[];
extern const u32 gUnk_0806D8F4[];
extern const u32 gUnk_0806DDC8[];
extern const u32 gUnk_0806E294[];
extern const u32 gUnk_0806E7AC[];
extern const u32 gUnk_0806ED8C[];
extern const u32 gUnk_0806F3B4[];
extern const u32 gUnk_0806FA28[];
extern const u32 gUnk_08070018[];
extern const u32 gUnk_080706C8[];
extern const u32 gUnk_08070D9C[];
extern const u32 gUnk_080714B4[];
extern const u32 gUnk_08071B88[];
extern const u32 gUnk_080720BC[];
extern const u32 gUnk_08072774[];
extern const u32 gUnk_08072E5C[];
extern const u32 gUnk_080735F0[];
extern const u32 gUnk_08073BDC[];
extern const u32 gUnk_08074290[];
extern const u32 gUnk_08074934[];
extern const u32 gUnk_08074F64[];
extern const u32 gUnk_08075504[];
extern const u32 gUnk_08075B04[];
extern const u32 gUnk_08076104[];
extern const u32 gUnk_080767C8[];
extern const u32 gUnk_08076E00[];
extern const u32 gUnk_08077468[];
extern const u32 gUnk_08077A10[];
extern const u32 gUnk_08077FE0[];
extern const u32 gUnk_080786C8[];
extern const u32 gUnk_08078CAC[];
extern const u32 gUnk_08079294[];

#endif
