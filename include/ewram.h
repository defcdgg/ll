#ifndef _EWRAM_H
#define _EWRAM_H

#include "gba/types.h"

extern u8 gUnk_02004000[];
extern u8 gUnk_02005380[];
extern u8 gWindowBgBuf[];
extern u16 gUnk_02016000[];
extern u8 gUnk_02016200[];
extern u16 gUnk_020352C0[];
extern u16 gUnk_02035B04[]; /* 0x02035B04: 26 项 u16, 两处 (i / i+0x20) 填 0xB001 */
extern u8 gCharaWalkCmdBuf[];
extern u16 gMsgLineBuf[]; /* 0x02005C44: 单条消息行的 u16 瓦片缓冲 (29 项) */

#define VRAM_BUF_2005000 (u16 *)0x2005000
#define VRAM_BUF_2005800 (u16 *)0x2005800

#endif

/* 战斗备份/过场图形缓冲 (真名引用; 地址见 linker.ld) */
extern u8 gCutsceneGfxBuf[];
extern u8 gSpritePoolBackup[0xA00];
extern u8 gQueue34C0Backup[0x100];
extern u8 gUnk_02036EC0[];
