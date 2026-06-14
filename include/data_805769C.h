#ifndef GUARD_DATA_805769C_H
#define GUARD_DATA_805769C_H

#include "gba/types.h"

typedef void (*IntrFunc)(void);

extern IntrFunc const gIntrTable[];

extern const u8 gUnk_080576D0[];

extern const u8 gUnk_08057750[];


extern const u8 pltt_08057854[];
extern const u8 tilemap_08057874[];
extern const u8 tileset_1_08057A80[];
extern const u8 tileset_2_08057EEC[];
extern const u8 tileset_3_080583C4[];

extern const u8 gUnk_0805881C[];
extern const u8 gUnk_0805882C[];
extern const u8 gUnk_08058834[];
extern const u8 gUnk_08058864[]; 
extern const u8 gUnk_0805887C[];


typedef struct{
    u16 scriptIdx;
    u16 gfxIdx;
    u8 palIdx;
    u8 field_5;
    u16 field_6;
}CutsceneAnimConfig;

extern const CutsceneAnimConfig gCutsceneAnimConfigTable[];

extern const u16 gUnk_08059794[];

// extern const u8 unk_80A1314[];

#endif