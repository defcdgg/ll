#ifndef _DATA_87E83F0_H
#define _DATA_87E83F0_H

#include "gba/types.h"

typedef void (*MainTaskFunc)(void);

extern const MainTaskFunc gMainTasks[];

typedef void (*UnkFunc)(void);

extern const UnkFunc gUnk_087E83F8[];

extern const u8 *const gGfxSpriteSheetWalk_PtrTable[];


extern const u32 gUnk_087E860C[];
extern const u32 gUnk_087E8D84[];

typedef struct{
    u8 field_0;
    u8 field_1;
    u8 tileX;
    u8 tileY;
}Unk_087E94FC;

extern const Unk_087E94FC gUnk_087E94FC[];

#endif