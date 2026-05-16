#ifndef _GLOBAL_TABLES_H
#define _GLOBAL_TABLES_H

#include "gba/types.h"

typedef void (*MainTaskFunc)(void);

extern const MainTaskFunc gMainTasks[];

typedef void (*UnkFunc)(void);

extern const UnkFunc gUnk_087E83F8[];

extern const u8 *const gGfxSpriteSheetWalk_PtrTable[];

#endif