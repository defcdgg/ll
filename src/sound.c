
#include "sound.h"
#include "code_0.h"
#include "gba/gba.h"
#include "globals.h"
#include "include_asm.h"
#include "m4a.h"

// extern struct SongHeader sfx0;

// struct SongHeader* gSfxSongHeaderTable[1] =
// {
//     &sfx0
// };

// const struct MusicPlayerInfo* gMPlayInfos2[4] =
// {
//     &gMPlayInfo_1,
//     &gMPlayInfo_2,
//     &gMPlayInfo_3,
//     &gMPlayInfo_4
// };

void sub_80533F0(void)
{
    u16 volume;
    if (gUnk_03000F38 & 2)
    {
        volume = sub_801768C(gUnk_03000F3E, 0x100, gUnk_03000F40, gUnk_03000F41, 0);
        sub_805369C(volume);
        if (gUnk_03000F41 < gUnk_03000F40)
        {
            gUnk_03000F41++;
        }
        else
        {
            gUnk_03000F38 &= ~2;
        }
    }
    else if (gUnk_03000F38 & 4)
    {
        volume = sub_801768C(gUnk_03000F3E, -gUnk_03000F3E, gUnk_03000F40, gUnk_03000F41, 0);
        sub_805369C(volume);
        if (gUnk_03000F41 < gUnk_03000F40)
        {
            gUnk_03000F41++;
        }
        else
        {
            gUnk_03000F38 &= ~4;
        }
    }

    m4aSoundMain();
    sub_80534B4();
}

INCLUDE_ASM("asm/nonmatchings", sub_80534B4); // Matched

// void sub_80534B4(void) {
//     u8 i;
//     u16 songNum;

//     for(i = 0; i <= 3; i++)
//     {
//         if((gUnk_03000F42 >> i) & 1)
//         {
//             if((u16)gMPlayInfos2[i]->status == 0)
//             {
//                 gUnk_03000F42 &= ~(1 << (i));

//                 if((gUnk_03000F43 >> i) & 1)
//                 {
//                     songNum = gUnk_03000F48[i];
//                     MPlayStart(gMPlayInfos2[i], gSongHeaderTable[songNum]);
//                     gUnk_03000F42 |= (1 << (i));
//                     gUnk_03000F48[i] = songNum;

//                     if((gUnk_03000F43 >> i) & 1)
//                     {
//                         gUnk_03000F43 &= ~(1 << i);
//                     }
//                     gUnk_03000F43 |= (1 << i);
//                 }

//                 if((gUnk_03000F50 >> i) & 1)
//                 {
//                     m4aMPlayFadeIn((struct MusicPlayerInfo* )0x03005AB0, 2);
//                     gUnk_03000F50 &= ~(1 << (i));
//                 }
//             }
//         }

//     }

// }

void sub_805359C()
{
    m4aSoundInit();
    gUnk_03000F38 = 0;
    gUnk_03000F3A = 0;
    gUnk_03000F3C = 0x100;
    gUnk_03000F40 = 0;
    gUnk_03000F42 = 0;
    gUnk_03000F43 = 0;
    gUnk_03000F50 = 0;
}

u16 sub_80535E8(void)
{
    return gUnk_03000F38;
}

void sub_80535F4(void)
{
    m4aSoundVSyncOff();
    gUnk_03000F38 |= 1;
}

void sub_805360C(void)
{
    m4aSoundVSyncOn();
    gUnk_03000F38 &= 0xFFFE;
}

void sub_8053628(u8 arg0, u16 arg1)
{
    gUnk_03000F3A = arg0;
    switch (gUnk_03000F3A)
    {
        case 0x3F:
            gUnk_03000F3A = 0x11B;
            break;
        case 0x40:
            gUnk_03000F3A = 0x11C;
            break;
        case 0x41:
            gUnk_03000F3A = 0x11A;
            break;
    }
    m4aSongNumStart(gUnk_03000F3A);
    m4aMPlayImmInit((struct MusicPlayerInfo *)0x03005AB0);
    sub_805369C(arg1);
}

void sub_8053688(void)
{
    m4aSongNumStop(gUnk_03000F3A);
}

void sub_805369C(u16 volume)
{

    if (volume < 2)
    {
        volume = 2;
    }
    *(u16 *)0x03000F3C = volume;
    m4aMPlayVolumeControl((struct MusicPlayerInfo *)0x03005AB0, 0xFF, volume);
}

void sub_80536C0(u8 arg0)
{
    gUnk_03000F3E = 0;
    gUnk_03000F40 = arg0;
    gUnk_03000F41 = 0;
    gUnk_03000F38 |= 2;
}

void sub_80536EC(u8 arg0)
{
    gUnk_03000F3E = gUnk_03000F3C;
    gUnk_03000F40 = arg0;
    gUnk_03000F41 = 0;
    gUnk_03000F38 |= 4;
}

void sub_8053720(void)
{
    m4aSongNumContinue(gUnk_03000F3A);
}

u8 sub_8053734(u8 arg0)
{
    return (gUnk_03000F42 >> arg0) & 1;
}

INCLUDE_ASM("asm/nonmatchings", sub_805374C); // Matched
// void sub_805374C(u16 arg0, u8 arg1, u8 arg2) {

//     MPlayStart(gMPlayInfos2[arg1], gSfxSongHeaderTable[arg0]);
//     gUnk_03000F42 |= 1 << arg1;
//     gUnk_03000F48[arg1] = arg0;
//     if((gUnk_03000F43 >> arg1) & 1)
//     {
//         gUnk_03000F43 &= ~(1 << arg1);
//     }
//     gUnk_03000F43 |= arg2 << arg1;
// }

INCLUDE_ASM("asm/nonmatchings", sub_80537C0); // Matched
// void sub_80537C0(u16 arg0, u8 arg1) {

//     MPlayStart(gMPlayInfos2[arg1], gSfxSongHeaderTable[arg0]);
//     gUnk_03000F42 |= 1 << arg1;
//     gUnk_03000F48[arg1] = arg0;

//     if( (gUnk_03000F50 >> arg1) & 1)
//     {
//         gUnk_03000F50 &= ~(1 << arg1);
//     }
//     gUnk_03000F50 |= (1 << arg1);

//     m4aMPlayFadeOutTemporarily((struct MusicPlayerInfo* )0x03005AB0, 2);
// }

INCLUDE_ASM("asm/nonmatchings", sub_8053838); // Matched

// void sub_8053838(u8 arg0) {
//     m4aMPlayStop(gMPlayInfos2[arg0]);

//     gUnk_03000F42 &= ~(1 << arg0);

//     if((gUnk_03000F43 >> arg0) & 1)
//     {
//         gUnk_03000F43 &= ~(1 << arg0);
//     }
// }

s32 sub_8053884(u8 arg0)
{
    return (gUnk_03000F43 >> arg0) & 1;
}