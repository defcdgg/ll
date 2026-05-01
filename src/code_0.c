#include "gba/defines.h"
#include "gba/gba.h"
#include "include_asm.h"
#include "globals.h"
#include "m4a.h"
#include "code_0.h"

/*
    MultiSioIntr
    VBlankIntr
    HBlankIntr
    VCountIntr
*/
IntrFunc const gIntrTable[] = {
    sub_8016FC0,
    sub_800065C,
    sub_800124C,
    DummyIntr4,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
    DummyIntr3,
};


u8 const gUnk_080576D0[] = {
  0x00, 0x04, 0x09, 0x0e, 0x13, 0x18, 0x1d, 0x21, 0x26, 0x2a, 0x2f, 0x33,
  0x37, 0x3b, 0x3f, 0x43, 0x46, 0x4a, 0x4d, 0x50, 0x53, 0x55, 0x58, 0x5a,
  0x5c, 0x5e, 0x5f, 0x61, 0x62, 0x62, 0x63, 0x63, 0x64, 0x63, 0x63, 0x62,
  0x62, 0x61, 0x5f, 0x5e, 0x5c, 0x5a, 0x58, 0x55, 0x53, 0x50, 0x4d, 0x4a,
  0x46, 0x43, 0x3f, 0x3b, 0x37, 0x33, 0x2f, 0x2a, 0x26, 0x21, 0x1d, 0x18,
  0x13, 0x0e, 0x09, 0x04, 0x00, 0xfc, 0xf7, 0xf2, 0xed, 0xe8, 0xe3, 0xdf,
  0xda, 0xd6, 0xd1, 0xcd, 0xc9, 0xc5, 0xc1, 0xbd, 0xba, 0xb6, 0xb3, 0xb0,
  0xad, 0xab, 0xa8, 0xa6, 0xa4, 0xa2, 0xa1, 0x9f, 0x9e, 0x9e, 0x9d, 0x9d,
  0x9c, 0x9d, 0x9d, 0x9e, 0x9e, 0x9f, 0xa1, 0xa2, 0xa4, 0xa6, 0xa8, 0xab,
  0xad, 0xb0, 0xb3, 0xb6, 0xba, 0xbd, 0xc1, 0xc5, 0xc9, 0xcd, 0xd1, 0xd6,
  0xda, 0xdf, 0xe3, 0xe8, 0xed, 0xf2, 0xf7, 0xfc
};

u8 const gUnk_08057750[] = 
{
  0xe8, 0x86, 0xe1, 0x87, 0xdf, 0x8f, 0xed, 0x82, 0x23, 0x45, 0x05, 0x49,
  0x1a, 0x71, 0x0a, 0x8b, 0x24, 0x40, 0x3d, 0x4f, 0x29, 0x36, 0x32, 0x4e,
  0xff, 0x85, 0x9f, 0x92, 0x98, 0x30, 0xf1, 0x35, 0x2a, 0xfe, 0x79, 0xfa,
  0x80, 0x89, 0x06, 0x9d, 0x43, 0x74, 0x3f, 0x8a, 0x48, 0xf5, 0x5e, 0xe9,
  0xfc, 0x13, 0x77, 0x03, 0x76, 0x61, 0x16, 0x75, 0x27, 0x3c, 0xd6, 0x4a,
  0xc1, 0x02, 0xbe, 0x0c, 0x0e, 0x4c, 0xcc, 0x34, 0xc5, 0x25, 0x00, 0x38,
  0xee, 0xa2, 0xc6, 0x14, 0xe0, 0x58, 0xef, 0x5d, 0x1e, 0x9e, 0xec, 0x8c,
  0xea, 0x97, 0x1f, 0x83, 0x31, 0x91, 0x8d, 0xa4, 0x88, 0x2f, 0x5a, 0xa9,
  0x9b, 0x53, 0x21, 0x56, 0x4d, 0x78, 0x9a, 0x6f, 0x73, 0x68, 0xfd, 0x52,
  0xf9, 0x6b, 0x8e, 0x5f, 0x37, 0x41, 0x09, 0x5b, 0x08, 0x44, 0x3a, 0x5c,
  0x39, 0x67, 0x42, 0x6a, 0x4b, 0x3b, 0x33, 0x1d, 0x22, 0xad, 0xaa, 0x94,
  0x84, 0x60, 0x20, 0x65, 0x55, 0x11, 0x95, 0xa6, 0x90, 0xa0, 0x62, 0x81,
  0x59, 0x1b, 0x57, 0x2d, 0x50, 0x2e, 0x6d, 0x19, 0x99, 0x7b, 0x96, 0x66,
  0xab, 0x04, 0x93, 0xaf, 0x9c, 0x7c, 0xae, 0x7f, 0x28, 0x54, 0xa8, 0x6e,
  0x01, 0x7d, 0x72, 0x64, 0x7e, 0x69, 0x1c, 0x63, 0xf3, 0xd1, 0xc9, 0xd8,
  0xc4, 0x12, 0xf7, 0x17, 0xa7, 0xfb, 0xdc, 0x15, 0xd7, 0xac, 0xa1, 0x2b,
  0xb3, 0xdb, 0xb1, 0xc7, 0xc2, 0xcf, 0xb2, 0xd0, 0xe6, 0x26, 0xf6, 0xba,
  0x0f, 0xc0, 0xc3, 0xd3, 0x0d, 0xd5, 0xd2, 0xda, 0xb7, 0xbc, 0xf4, 0xa3,
  0x07, 0xbd, 0xe3, 0xca, 0xde, 0xd4, 0x2c, 0xcb, 0x6c, 0xf8, 0x10, 0x0b,
  0x3e, 0xb4, 0x7a, 0xb5, 0x70, 0xe7, 0xa5, 0xd9, 0xb8, 0xe4, 0x51, 0xe5,
  0xe2, 0xb9, 0x47, 0xbf, 0x46, 0xce, 0xdd, 0xbb, 0xc8, 0x18, 0xb6, 0xeb,
  0xb0, 0xf2, 0xcd, 0xf0, 
  0xff, 0xff, 0xff, 0xff
};
static inline void ClearBuffer(u16* buf, u8 w, u8 h)
{
    u16 x, y;
    u16* temp_buf;
    for (y = 0; y < h; y++) {
        temp_buf = buf;
    
        for (x = 0; x < w; x++) {
            *buf++ = 0xB001;
        }
        buf = temp_buf + 0x20;
    }
}
void sub_80002A0(void) {
    u16 val;

    sub_8004ADC();
    
    switch (gUnk_03004698) 
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
            REG_BG1HOFS = (s16) ((u8) gUnk_030025B4 >> 3);
            REG_BG1VOFS = 0;
            break;
        case 6: 
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0x1E;
            break;
        default:
            REG_BG1HOFS =(0x1F &  gUnk_030025B4);
            REG_BG1VOFS = (0x1F & gUnk_030025FC);
            break;
    }
    
    REG_BG2HOFS = gUnk_03004848;
    REG_BG2VOFS = gUnk_03004828;
    REG_BG3HOFS = gUnk_0300484C;
    REG_BG3VOFS = gUnk_03004648;


    DmaCopy16(3, &gUnk_030035C0, OAM, OAM_SIZE);

    sub_8002F6C();
    sub_8008D18();
    
    if (gUnk_03002604 == 0) {
        sub_805008C();
    }
    
    sub_800B14C();
    
    if (gUnk_03004800[13] != 0) {
        DmaCopy16(3, gUnk_02005380, 0x0600F380, 0x100);
        gUnk_03004800[13] = 0U;
    }

    REG_BLDCNT = gUnk_03004658;
    if(gUnk_03004658 & 0x80)
    {
        REG_BLDY = gUnk_03004550;
    }
    else
    {
        REG_BLDALPHA = gUnk_03004550;
    }

    sub_8005020();
    sub_80038CC();
    
    switch (gUnk_03004610) 
    {
        case 0:
        default:
            break;
        case 1:  
        case 3:  
            val = (gUnk_03001988 - 1) & 0x3FF;
            gUnk_03001988 = val;
            gUnk_03001B54 = (val >> 2) + gUnk_030025FC;
            break;
        case 2:  
        case 4:  
            val = (gUnk_03001988 - 1) & 0x7FF;
            gUnk_03001988 = val;
            gUnk_03001B54 = (val >> 3) + gUnk_030025FC;
    }
}

void sub_80004F8(void) {
    u16 val;

    REG_BG0HOFS = 0;
    REG_BG0VOFS = 0;
    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;

    DmaCopy16(3, &gUnk_030035C0, OAM, 0x400);

    REG_BLDCNT = gUnk_03004658;
    REG_BLDALPHA = gUnk_03004550;
    
    DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);

    sub_8005020();
    val = (gUnk_03001988 - 1) & 0x3FF;
    gUnk_03001988 = val;
    gUnk_03001B54 = (val >> 2) + gUnk_030025FC;
}

void sub_80005A8(u16 scanline) 
{
    switch (gUnk_03004610)
    {   
        case 1:
        case 2:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + scanline) & 0xFF] + (gUnk_030025B4 & 0x1F);
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + scanline) & 0xFF] + (gUnk_030025FC & 0x1F);
            break;

        case 3:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + scanline) & 0xFF];
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + scanline) & 0xFF]; 
            break;

        case 4:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + scanline) & 0xFF];
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + scanline) & 0xFF]; 
            break;
    }
}

//VBlankIntr
void sub_800065C(void) {

    switch (gUnk_0300259C) 
    {
        case 1:
            m4aSoundVSync();
            sub_80002A0();
            break;
        case 2:
            m4aSoundVSync();
            sub_8018070();
            break;
        case 3:
            m4aSoundVSync();
            sub_80004F8();
            break;
        case 4:
            m4aSoundVSync();
            sub_8004ADC();
            
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 4;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 4;
            REG_BG3VOFS = 0;
    
            REG_BLDCNT = gUnk_03004658;
            REG_BLDALPHA = gUnk_03004550;
    
            DmaCopy16(3, gUnk_030035C0, OAM, 0x400);
            DmaCopy16(3, VRAM_BUF_2005800, 0x0600F800, 0x800);
    
            if (gUnk_03004DC0 != 0)
            {
                DmaCopy16(3, VRAM_BUF_2005000, 0x0600F000, 0x800);
                gUnk_03004DC0 = 0;
            }
            
            sub_8005020();
            break;
        case 5:
            sub_8016F30();
            m4aSoundVSync();
            sub_8004ADC();
            sub_8003264();
            
            // CpuFastCopy(gUnk_030035C0, (u32*)0x07000000, 0x400);
            inl_cpufastset(gUnk_030035C0, (void*)0x07000000, 0x400);
    
            REG_BG1HOFS = 0;
            REG_BG1VOFS = 0;
            REG_BG2HOFS = 0;
            REG_BG2VOFS = 0;
            REG_BG3HOFS = 0;
            REG_BG3VOFS = 0;
            REG_BLDCNT = gUnk_03004658;
            REG_BLDALPHA = gUnk_03004550;
            
            // CpuFastCopy(gUnk_02005800, 0x0600F800, 0x800);
            inl_cpufastset(VRAM_BUF_2005800, (void*)0x0600F800, 0x800);
    
            if (gUnk_03004DC0 != 0) 
            {
                // CpuFastCopy(gUnk_02005000, 0x0600F000, 0x800);
                inl_cpufastset(VRAM_BUF_2005000, (void*)0x0600F000,  0x800);
                gUnk_03004DC0 = 0;
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
            
            sub_8004ADC();
            DmaCopy16(3, gUnk_030035C0, OAM, 0x400);
    
            sub_8008E94();
            sub_805008C();
            
            REG_BLDCNT = gUnk_03004658;
            if(gUnk_03004658 & 0x80)
            {
                REG_BLDY = gUnk_03004550;
            }
            else
            {
                REG_BLDALPHA = gUnk_03004550;
            }
            
            sub_8005020();
            sub_80038CC();
            break;
        default:
            m4aSoundVSync();
            break;
    }
        
    gUnk_030025A4++;
    
    if (gGameTimer <= 0x0CDFD7EE) 
    {
        gGameTimer++;
    } 
    else 
    {
        gGameTimer = 0x0CDFD7F0;
    }

    gUnk_030025A0++;
    REG_IME = 0;
    gUnk_03007FF8 |= 1;
    REG_IME = 1;

}


void sub_80008CC(void) {

    sub_8053838(0);
    sub_8053838(1);
    sub_8053838(2);
    sub_8053838(3);
    sub_805369C(0);
    VBlankIntrWait();

    while ( REG_DISPSTAT & 1 );
 
    sub_80533F0();
    sub_8053688();
    VBlankIntrWait();

    while ( REG_DISPSTAT & 1 );

    sub_80533F0();
    sub_80535F4();
    VBlankIntrWait();
    while ( REG_DISPSTAT & 1 );

    sub_80533F0();
    VBlankIntrWait();
    REG_DISPCNT |= DISPCNT_FORCED_BLANK;
}


s32 sub_800096C(void) {

    switch (gUnk_03001B50) 
    {
        case 0:
            REG_RCNT = 0xC000;
            VBlankIntrWait();
            sub_8017600(&gUnk_03001AD0, &gUnk_03001CB0, 0x10, 0);
            gUnk_03004F20.unk5E = 1;
            gUnk_03004F20.unk2 = 1;
            gUnk_03001B50++;
        case 1:
            gUnk_03001940 = sub_80171E4();
            
            if (gUnk_03001940 == -1) 
            {
                gUnk_030025A8 = 5;
                gUnk_03001B50 = 6;
                break;
            }
            
            if ((sub_8017588() == 0) && ( gUnk_03001940 <= 0xFF))
            {
                if (gUnk_03001D30 == 0) {
                    sub_801761C();
                    gUnk_03001B50 = 4;
                    gUnk_030025A8 = 2;
                }
                gUnk_03001D30--;
                break;
            }

            switch (gUnk_03001940)
            {
                case 0:
                case 1:
                    if (gUnk_03001D30 == 0) 
                    {
                        sub_801761C();
                        gUnk_03001B50 = 4;
                        gUnk_030025A8 = 2;
                    }
                    else 
                    {
                        gUnk_03001D30--;
                    }
                    break;
                
                case 2:
                    if (sub_8017588() == 0) 
                    {
                        sub_801761C();
                        gUnk_03001B50 = 5;
                        gUnk_030025A8 = 3;
                    }
                    else if (gUnk_030025A8 == 0) 
                    {
                        gUnk_03004F20.unk5E = 1;
                        gUnk_03004F20.unk2 = 1;
                        gUnk_030025A8 = 1;
                    }
                    break;
                
                case 0x101:
                case 0x102:
                case 0x103:
                case 0x104:
                    gUnk_030025A8 = 3;
                    gUnk_03001B50 = 5;
                    break;
                
                default:
                break;
            }

            break;
        case 2:
        case 3:
        case 4:
            sub_801761C();
            gUnk_03001B50 = 9;
            break;
        case 5:
            sub_801761C();
            gUnk_03001B50 = 9;
            break;
        case 6:
            gUnk_03001B50 = 0;
            break;
        case 7:
            sub_801761C();
            break;
        case 8:
            if (gUnk_030025A8 == 0) 
            {
                sub_801761C();
                gUnk_03001B50 = 0;
            }
            break;
        case 9:
            sub_801761C();
            gUnk_03001B50 = 8;
            break;
    }
    
    return sub_8017588();
}

void sub_8000B58(u32 arg0) {
    u16 i;

    DmaFill16(3, 0, (void*)VRAM, VRAM_SIZE);
    DmaFill32(3, 0, (void*)OAM, OAM_SIZE);
    DmaFill16(3, 0, (void*)PLTT, PLTT_SIZE);
    DmaFill16(3, 0, &gUnk_02004000, 0x2000);
    
    sub_8004B8C();
    sub_8004BBC();

    gGameTimer = 0;
    gUnk_030032D0 = 0;
    gUnk_03002604 = 0;
    gUnk_03004910 = 0;
    gUnk_03004840 = 0;
    gUnk_0300465C = 0;
    gUnk_030025F4 = 0xFF;


    for (i = 0; i < 16; i++)
    {
        gUnk_03004800[i] = 0;
    }
    
    for (i = 0; i < 128; i++)
    {
        gUnk_030035C0[i].attrs[0] = 0;
        gUnk_030035C0[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8009A5C();
    sub_8001090();
    sub_8001014();
    sub_8009168();
    
    gUnk_0300259C = 0;
    gUnk_03004D4C = 0;
    gUnk_03004D40 = 0;
    gUnk_03004854 = 0;
    gUnk_030025D8 = 0;
    gUnk_0300483C = 0;
    gUnk_03002C48 = 0;
}

void sub_8000C98(u16 arg0) {

    u16 i;
    u8 mask;
    s8 stepH, stepV;
    s8 divH, divV;
    
    mask = 0x7F;
    switch (arg0)
    {
        case 1:
            divH = 12;
            stepH = 32;
            divV = 12;
            stepV = 16;
            break;
        case 2:
            divH = 16;
            stepH = 8;
            divV = 4;
            stepV = 16;
            mask = 0x3F;
            break;
        case 3:
            divH = 16;
            stepH = 32;
            divV = 32;
            stepV = 4;
            break;
        case 4:
            divH = 4;
            stepH = 1;
            divV = 16;  
            stepV = 1;
            mask = 0x3F;
            break;
        default:
            return;
    }
    
    for (i = 0; i < 255; i++)
    {
        gUnk_03001B60[i] = gUnk_080576D0[ (i * stepH) & mask] / divH;
        gUnk_030019C0[i] = gUnk_080576D0[ (i * stepV) & mask] / divV;
    }

}

u32 sub_8000D5C(void) {
    u8 flag;
    u32 bit_offset;
    u16 lz_token;
    s32 match_length;
    s32 match_offset;
    s32 i;

    if ( gLzContext.size > gLzContext.remainingSize) 
    {
        gLzContext.size = gLzContext.remainingSize;
    }
    
    gLzContext.processedSize = 0;
    
    if (gLzContext.size >= 0)
    {
        while(  gLzContext.size > gLzContext.processedSize )
        {
            flag = gLzContext.flags[gLzContext.bitIndex >> 3];
            bit_offset = gLzContext.bitIndex & 7;

            if((flag >> bit_offset) & 1)
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

    if (gLzContext.remainingSize > gLzContext.size) {
        gLzContext.remainingSize -= gLzContext.processedSize;
        return gLzContext.remainingSize;
    }
    
    return 0;
    

}


void sub_8000E1C(u8 arg0) {
    
    REG_IME = 0;

    if (arg0 == 0)
    {
        gUnk_0300259C = 4;
        DmaCopy16(3, IntrMain, gIntrMainBuf, sizeof(gIntrMainBuf));
        REG_IE = INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_GAMEPAK; 
        REG_DISPSTAT = REG_DISPSTAT | 0x10;
    }
    else
    {
        gUnk_0300259C = 5;
        DmaCopy16(3, sub_8000170, gIntrMainBuf, sizeof(gIntrMainBuf));
        REG_IE = 0xFFFD & REG_IE; 
        REG_DISPSTAT = 0xFFEF & REG_DISPSTAT ;
    }
    
    INTR_VECTOR = &gIntrMainBuf;
    REG_IME = 1;
}

void sub_8000ED8(void) {
    
    while ( (REG_VCOUNT & 0xFF ) > 0xC8);

    REG_DISPCNT &= 0xFF7F;
    VBlankIntrWait();
    
    while ( REG_DISPSTAT & DISPSTAT_VBLANK );
    
    sub_805360C();
    sub_805369C(0);
    VBlankIntrWait();
    
    while ( REG_DISPSTAT & DISPSTAT_VBLANK );
    
    sub_80533F0();
}

void sub_8000F54(void) {
    gUnk_0300259C = 0;
    gUnk_03001944 = 0xB;
    gUnk_03002600 = 0;
    sub_8053688();
    VBlankIntrWait();
    sub_80533F0();
    sub_80535F4();
    VBlankIntrWait();
    sub_80533F0();
}

void nullsub_5(){}

void sub_8000F94(void) {
    VBlankIntrWait();
    sub_80533F0();
}

void sub_8000FA4(void) {
    VBlankIntrWait();
    while ( REG_DISPSTAT & DISPSTAT_VBLANK );
    sub_80533F0();
}



void sub_8000FD0(u8* dest, struct Unk_LzData* arg1, u32 arg2) {
    u8* ptr;

    gLzContext.unkC = arg1->uncompressedSize;
    gLzContext.remainingSize = gLzContext.unkC;
    gLzContext.dest = dest;
    ptr = arg1->data;
    gLzContext.src = ptr;
    gLzContext.flags = ptr + arg1->size;
    gLzContext.bitIndex = 0;
    gLzContext.size = arg2;
}

u8 sub_8000FF8(void) {
    return gUnk_08057750[gUnk_030025A4++];
}

void sub_8001014(void) {
    u16 i;

    for(i = 0; i < 0x40; i++)
    {
        gUnk_03001C60[i] = 0;
    }
}

u8 sub_8001030(u16 arg0) {
    return gUnk_03001C60[arg0 >> 3] & (1 << (arg0 & 7));
}


void sub_8001050(u16 arg0) {
    gUnk_03001C60[arg0 >> 3] |= (1 <<  (arg0 & 7));
}

void sub_8001070(u16 arg0) {
    gUnk_03001C60[arg0 >> 3] &= ~(1 <<  (arg0 & 7));
}

void sub_8001090(void) {
    u16 i;

    for(i = 0; i < 0x50; i++)
    {
        gUnk_030018F0[i] = 0;
    }
}


u8 sub_80010AC(u16 arg0) {
    return gUnk_030018F0[arg0 >> 3] & (1 << (arg0 & 7));
}

void sub_80010CC(u16 arg0) {
    gUnk_030018F0[arg0 >> 3] |= 1 <<  (arg0 & 7);
}

void sub_80010EC(u16 arg0) {
    gUnk_030018F0[arg0 >> 3] &= ~(1 <<  (arg0 & 7));
}

void sub_800110C(void) {
    u16 i;

    for(i = 0x3D; i < 0x50; i++)
    {
        gUnk_030018F0[i] = 0;
    }
}


void sub_8001128(void) {
    RegisterRamReset(3);
    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_N_3 | WAITCNT_WS0_S_1;
    gUnk_03001AC0 = 0;
    sub_8009B64();
    DmaCopy32(3, gIntrTable, gUnk_03001950, sizeof(gUnk_03001950) );
    DmaCopy16(3, IntrMain, gIntrMainBuf, sizeof(gIntrMainBuf));
 
    INTR_VECTOR = gIntrMainBuf;
    gUnk_03001944 = 0xB;
    gUnk_03002600 = 0;
    
    REG_IE = INTR_FLAG_VBLANK | INTR_FLAG_HBLANK | INTR_FLAG_GAMEPAK; 
    REG_DISPSTAT = DISPSTAT_HBLANK_INTR | DISPSTAT_VBLANK_INTR;
    REG_IME   = 1;
        
    VBlankIntrWait();
    REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_FORCED_BLANK
        | DISPCNT_BG0_ON | DISPCNT_BG1_ON | DISPCNT_BG2_ON | DISPCNT_OBJ_ON | DISPCNT_WIN0_ON;;
    sub_8000B58(0);
    sub_805359C();
    sub_8021130();
    gUnk_03002600 = 0;
}

void sub_80011F0(void) {
    u16 key;

    key = ~REG_KEYINPUT;
    gUnk_03001CA0 = key & ~gUnk_030019B0;
    gUnk_030019B0 = key;
}

void sub_800121C(void) {
    u16 key;

    key = ~REG_KEYINPUT;
    gUnk_03001CA0 = key & ~gUnk_030019B0;
    gUnk_030019B0 = key;
}

void DummyIntr3(){}


void sub_800124C(void) {
    switch (gUnk_0300259C) 
    {
        case 1:
        case 3:
            sub_80005A8(0xFF & REG_VCOUNT);
            break;
        case 2:
            sub_801887C();
            break;
    }
}

void DummyIntr4(){}

void DummyIntr5(){}

INCLUDE_ASM("asm/nonmatchings", sub_800128C); // Matched

void sub_80012B8(void) {
    sub_8016F30();
    m4aSoundVSync();
    sub_8004ADC();
    sub_8003264();
    CpuFastSet(gUnk_030035C0, (void*)0x07000000, 0x100);


    REG_BG1HOFS = 0;
    REG_BG1VOFS = 0;
    REG_BG2HOFS = 0;
    REG_BG2VOFS = 0;
    REG_BG3HOFS = 0;
    REG_BG3VOFS = 0;
    REG_BLDCNT = gUnk_03004658;
    REG_BLDALPHA = gUnk_03004550;

    CpuFastSet(VRAM_BUF_2005800, (void*)0x0600F800, 0x200);
    if (gUnk_03004DC0 != 0) 
    {
        CpuFastSet(VRAM_BUF_2005000, (void*)0x0600F000, 0x200);
        gUnk_03004DC0 = 0;
    }
}

void sub_8001354(void) {
    u16 i;
    u8 temp_r6;
    s32 temp_r7;

    sub_80008CC();
    temp_r6 = gUnk_0300259C;
    gUnk_0300259C = 0;
    temp_r7 = gUnk_03004608;
    gUnk_03004610 = 0;
    sub_8009A5C();
    gUnk_030025F8 = gUnk_0300468C * 8;
    gUnk_03002C3C = gUnk_03004638 * 8;
    if (gUnk_03004854 != 0) 
    {
        gUnk_030025B4 = gUnk_030025F8;
        gUnk_030025FC = gUnk_03002C3C;
    }
    sub_8004B8C();
    sub_8004BBC();
    sub_8004BE0();

    for (i = 0; i < 128; i++)
    {
        gUnk_030035C0[i].attrs[0] = 0;
        gUnk_030035C0[i].attrs[1] = 0;
    }
    
    sub_8004AC0();
    sub_8004B60();
    sub_8008A3C();
    sub_8009F48();
    sub_8003348();
    gUnk_030025B0 = gUnk_030047A4;
    sub_80040E4();
    sub_800445C();
    sub_800661C(gUnk_030047E4);
    sub_800729C(gUnk_030047E4);
    sub_80033E8(gUnk_030047E4);
    sub_8008B14(gUnk_03004614);
    sub_8008F28(gUnk_030047E4);
    sub_8009BF0(gUnk_03004920);
    sub_8009C84(gUnk_03004920);
    
    gUnk_0300259C = temp_r6;

    if( ( sub_8052574() & 1 ) == 0)
    {
        sub_80526A0(0xFF, 2);
        sub_8050014();
    }

    sub_8002154();

    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if( ( sub_8052574()  & 1) == 0)
    {
        sub_8009B44();
        sub_80089E0(3);
    }
    
    gUnk_03002C50 = 2;
    gUnk_03001944 = 1;
    gUnk_03002600 = 0;
    sub_8000ED8();
    
    if (gUnk_030025F4 != 0xFF || gUnk_03004608 == 0)
        return;
    
        
    if (temp_r7 == gUnk_03004608) 
    {
        sub_805369C(0);
        sub_8000FA4();
        sub_8053720();
        sub_8000FA4();
        sub_80536C0(4);
    }else
    {
        sub_805369C(0);
        sub_8000FA4();
        sub_8053688();
        sub_8000FA4();
        sub_8053628(gUnk_03004608, 0);
        sub_8000FA4();
        sub_80536C0(4); 
    }
}

void sub_8001538(void) {
    u8 i;
    u16 i1;

    gUnk_030025F4 = 0xFF;
    gUnk_030025D8 = 0;
    gUnk_03000000 = 0;
    gUnk_03000002 = 0;
    gUnk_03002600 = 0;
    gUnk_03002C4C = 0;
    gUnk_03002608 = 0;
    gUnk_03002C44 = 0;
    gUnk_0300260C = 0;
    gUnk_03004624.unk0 = 0;
    gUnk_03004624.unk1 = 0;

    gUnk_0300259C = 1;
    gUnk_030047E4 = 0x82;
    gUnk_0300468C = 0;
    gUnk_03004638 = 0;
    gUnk_030047A4 = 0;
    gUnk_03004614 = 0;
    gUnk_03004AA0[0] = 0;
    gUnk_03004AA0[1] |= 0xFF;
    gUnk_03004AA0[2] |= 0xFF;
    gUnk_03004AA0[3] |= 0xFF;
    gUnk_03004AA0[4] |= 0xFF;
    gUnk_03004AA0[5] |= 0xFF;
    gUnk_03004A88[0] = 0;
    gUnk_03004A88[1] |= 0xFF;
    gUnk_03004A88[2] |= 0xFF;
    gUnk_03004A88[3] |= 0xFF;
    gUnk_03004A88[4] |= 0xFF;
    gUnk_03004A88[5] |= 0xFF;
    
    sub_800A924();

    for( i = 0; i < 11; i++)
    {
        sub_800A664(i);
        sub_800A79C(i);
    }

    gUnk_03004980[0xDD] = 2;
    gUnk_03002C38 = 0x12C;
    gGameTimer = 0;
    gUnk_030025F8 = 0x60;
    gUnk_03002C3C = 0x50;
    
    sub_8052580();
    
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;

    if (gUnk_030025F0 == 0) 
    {
        gUnk_03004634 = 1;
        gUnk_03004850 = 1;
        sub_80525E8(1, 0, 1);

        for( i1 = 0; i1 < 16; i1++)
        {
            sub_8000FA4();
        }

    }
    else 
    {
        sub_80525E8(0, 0, 1);
        for( i1 = 0; i1 < 4; i1++)
        {
            sub_8000FA4();
        }
    }
    sub_80526A0(1, 2);
    gUnk_03001944 = 1;
    gUnk_03002600 = 0;
}

void sub_8001708(void) {
    u16 i;
    
    if (gUnk_03004840 == 0 && gUnk_03002600 == 1) {
        gUnk_030025F8 = gUnk_0300468C << 3;
        gUnk_03002C3C = gUnk_03004638 << 3;

        if (gUnk_03004854 != 0) 
        {
            gUnk_030025B4 = gUnk_030025F8;
            gUnk_030025FC = gUnk_03002C3C;
        }

        sub_8008B14(gUnk_03004614);
        gUnk_030025B0 = gUnk_030047A4;
        sub_800445C();

        for ( i = 0; i < 8; i++) {
            gUnk_030025C0[i] = gUnk_03002E80[0].field_6;
            gUnk_030025E0[i] = gUnk_03002E80[0].field_8;
            gUnk_03002C58[i] = gUnk_03002E80[0].field_4;
        }

        gUnk_03002E80[1].field_6 = gUnk_03002E80[0].field_6;
        gUnk_03002E80[1].field_8 = gUnk_03002E80[0].field_8;    
        gUnk_03002E80[1].field_4 = gUnk_03002E80[0].field_4;


        sub_80089E0(3);
        gUnk_03002C50 = 2;
        gUnk_03001944 = 1;
        gUnk_03002600 = 0;

    } 
    else 
    {

        if (gUnk_03002600 != 1) {
            gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
            gUnk_03002600 = 1;
            sub_8009B44();
            sub_80089E0(4);
        }
    }

    sub_8002154();
}

void sub_8001828(void) {
    u16 i;
    u8 val;
    val = gUnk_03004840;
    
    if (val == 0 && gUnk_03002600 == 1) {
        sub_80008CC();
        gUnk_0300259C = val;
        gUnk_03002600 = val;

        if (gUnk_03002C48 != 0) 
        {
            gUnk_03002C48++;
            sub_8017FA4(gUnk_030025B8);
        }
        else
        {
            sub_8017FA4(gUnk_03004820);
        }

        gUnk_03001AC0 = 1;
        gUnk_0300259C = 2;
    } 
    else 
    {
        if (gUnk_03002600 != 1) {
            gUnk_03002600 = 1;
            sub_8009B44();
            sub_80089E0(4);
            sub_805374C(0x16, 0, 0);
            sub_80536EC(0x2E);
        }
        sub_8002154();
    }
}

void sub_80018D4(void) {
    s16 i;
    
    REG_IME = 0;
    sub_8009A5C();
    gUnk_0300259C = 0;
    sub_8004BE0();
    
    for(i = 0; i < 0x80; i++)
    {
        gUnk_030035C0[i].attrs[0] = 0;
        gUnk_030035C0[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    if (gUnk_03002C48 != 0) {
        gUnk_03002C48++;
        
        if (gUnk_03002C34 == 2) 
        {
            sub_8008DD8();
            REG_WIN0H = 0xF0;
            REG_WIN0V = 0xA0;
            REG_DISPCNT |= DISPCNT_WIN0_ON;
            REG_WININ = 0;
            REG_WINOUT = 0;
            gUnk_0300259C = 1;
            gUnk_03001944 = 1;
            gUnk_03002600 = 0;
            REG_IME = 1;
            sub_8000ED8();
            return;
        }
    }
    sub_800445C();
    gUnk_0300259C = 1;
    REG_IME = 1;
    sub_800661C(gUnk_030047E4);
    
    if (!(1 & sub_8052574())) 
    {
        sub_80525E8(gUnk_03004850, 0, 1);
    }
    
    sub_8008C70();
    sub_8008B14(gUnk_03004614);
    sub_8009BF0(gUnk_03004920);
    
    gUnk_03001944 = 1;
    gUnk_03002600 = 0;
    REG_WIN0H = 0xF0;
    REG_WIN0V = 0xA0;
    REG_DISPCNT |= DISPCNT_WIN0_ON;
    REG_WININ = 0;
    REG_WINOUT = 0;
    
    if (gUnk_03002C48 == 0 || (gUnk_03002C34 != 1)) 
    {
        sub_8009B44();
        sub_80089E0(3);
    }
    
    sub_8000ED8();
    
    if (gUnk_03004608 != 0) 
    {
        sub_8000FA4();
        sub_8053628(gUnk_03004608, 0);
        sub_8000FA4();
        sub_80536C0(4);
    }
    
    sub_8002154();
}

void sub_8001A7C(void) {
    s32 var_r4;

    if (gUnk_03004840 == 0 && gUnk_03002600 == 1)
    {
            sub_80008CC();
            sub_8009A5C();
            sub_8004B8C();
            sub_8004BBC();
            sub_8004BE0();
            sub_8007D5C(gUnk_030047BC);
            sub_8008B5C();
            sub_80040E4();
            gUnk_030025B4 = 0;
            gUnk_030025FC = 0;
            gUnk_030025B0 = 4;
            sub_8009B44();
            sub_80089E0(3);
            gUnk_03002600 = 0;
            gUnk_03001944 = 9;
            sub_8004E04();
            sub_8008124();

            sub_8008CC0(*(u8*)(gUnk_0300462C + gUnk_0300466C) & 0xF);

            gUnk_030025F8 = gUnk_03004824;
            gUnk_03002C3C = gUnk_030047B8;
            gUnk_03002E80[1].field_6 = gUnk_03004824;
            gUnk_03002E80[1].field_8 = gUnk_030047B8 - 8;
            gUnk_03002E80[1].field_12 |= 0x10u;
            gUnk_03002E80[1].field_4 = 4;
            sub_80081C0();
            sub_8000ED8();
            gUnk_03004608 = 0;

            var_r4 = sub_8001030(0x39) != 0 ? 6 : 5;

            sub_8000FA4();
            sub_8053628(var_r4, 0);
            sub_8000FA4();
            sub_80536C0(4);
            return;
    }

    if (gUnk_03002600 != 1)
    {
        gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
        gUnk_03002600 = 1;
        sub_8009B44();
        sub_80089E0(4);
        sub_80536EC(0x2E);  
    }

    sub_8002154();

}
void sub_8001BD0(void) {
    s16 i;

    sub_8009A5C();
    sub_8004BE0();

    for( i = 0; i < 128; i++)
    {
        gUnk_030035C0[i].attrs[0] = 0;
        gUnk_030035C0[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8008A3C();
    sub_8009F48();
    sub_8052580();
    
    gUnk_0300260C = 0;
    gUnk_03004854 = 0;
    gUnk_030025F4 = 0xFF;
    
    DmaCopy16(3, (void*)0x0203F000, (void*)0x03003AC0, 0xA00);
    DmaCopy16(3, (void*)0x0203FE00, (void*)0x030034C0, 0x100);

    sub_800445C();
    sub_8004358();
    sub_800661C(gUnk_030047E4);
    sub_80525E8(gUnk_03004850, 0, 1);
    sub_8008C70();
    sub_8008B14(gUnk_03004614);
    sub_8009BF0(gUnk_03004920);
    sub_8009C84(gUnk_03004920);
    
    gUnk_03001944 = 1;
    gUnk_03002600 = 0;
    
    sub_8009B44();
    sub_80089E0(3);
    
    gUnk_03002C50 = 2;
    
    sub_8000ED8();
    
    if (gUnk_03004608 != 0)
    {
        sub_8053628(gUnk_03004608, 0);
        sub_8002154();
        sub_8000FA4();
        sub_80536C0(4);
    }
    sub_8002154();
}

INCLUDE_ASM("asm/nonmatchings", sub_8001D08); //Matched

void sub_8002154(void) {
    u16 i;
    u16 ret0;
    Unk_03002E80* ptr03002E80;
    Unk_03004890* ptr03004890;

    sub_8005C70();
    sub_8008A60();
    sub_80053B4(gUnk_030025B4, gUnk_030025FC);

    if(gUnk_0300467C != 0xFF)
    {
        if ( (gUnk_0300467C & 0x80) != 0 && gUnk_0300467C < 0xFE )
        {
            i = 0;
            ptr03002E80 = gUnk_03002E80;
            do
            // for(; i < 19; i++)
            {
                if(ptr03002E80->field_0 && (ptr03002E80->field_1 & 1) != 0)
                {
                    ret0 = sub_8003C54(i);
                    if(ret0 == 1 && ptr03002E80->field_24)
                    {
                        ptr03002E80->field_10++;
                        ret0 = 2;
                    }
                    if(ret0 <= 1)
                    {
                        sub_8003B08(i);
                    }
                    sub_800271C(i);
                    sub_800243C(sub_8004EDC(ptr03002E80), ptr03002E80->field_8, ptr03002E80->field_0, sub_8004EB8(ptr03002E80), ptr03002E80->field_1);
                    if ( ptr03002E80->field_18 )
                    {
                        gUnk_03003AC0[ptr03002E80->field_18].field_0 = 0;
                        gUnk_03003AC0[ptr03002E80->field_18].field_C = 0;
                        ptr03002E80->field_18 = 0;
                    }
                    sub_8002380(i);
                }
                ptr03002E80++;
                i++;
            }while(i < 19);
        }
         else
        {
            sub_800445C();
            i = 2;
            ptr03002E80 = &gUnk_03002E80[i];
            do
            // for( ; i < 19; i++)
            {
                if(ptr03002E80->field_0)
                {
                    if ( !gUnk_03004D4C && (!gUnk_0300260C || gUnk_0300260C == 9) && (ptr03002E80->field_12 & 0x88) != 8 )
                    {
                        ret0 = sub_8003C54(i);
                        if(ret0 == 1 && ptr03002E80->field_24)
                        {
                            ptr03002E80->field_10++;
                            ret0 = 2;
                        }
                        if(ret0 <= 1)
                        {
                            sub_8003B08(i);
                        }
                        
                    }
                    sub_800271C(i);
                    if ( ptr03002E80->field_18 )
                    {
                        gUnk_03003AC0[ptr03002E80->field_18].field_0 = 0;
                        gUnk_03003AC0[ptr03002E80->field_18].field_C = 0;
                        ptr03002E80->field_18 = 0;
                    }
                    if ( sub_800243C(ptr03002E80->field_6, ptr03002E80->field_8, ptr03002E80->field_0, ptr03002E80->field_1A, ptr03002E80->field_1)  )
                    {
                        ptr03002E80->field_12 |= 8;
                    }
                    else
                    {
                        ptr03002E80->field_12 &= ~8;
                        sub_8002380(i);
                    }
              
                }
                ptr03002E80++;
                i++;
            }while(i < 19);
        }
    
        for ( i = 0; i < 16; i++)
        {
            if(gUnk_03004890[i].field_2)
            {
                sub_800243C(gUnk_03004890[i].field_4, gUnk_03004890[i].field_6, gUnk_03004890[i].field_2, 0, 255);
            }
        }
    }

    sub_8009D34();
    sub_80032BC();
    sub_80091C4();
}

void sub_8002380(u8 arg0) {
    Unk_03002E80* temp_r4;
    struct Unk_03003AC0* temp_r0;
    u8 flag;

    if ((gUnk_030025A0 & 1) == (arg0 & 1)) 
    {
        temp_r4 = &gUnk_03002E80[arg0];
        if ( !(temp_r4->field_1 & 2) ) 
        {
            if (temp_r4->field_18 == 0) 
            {
                temp_r4->field_18 = sub_8004BFC();
            }
            temp_r0 = &gUnk_03003AC0[temp_r4->field_18];

            flag = (temp_r4->field_1 & 1);

            if(flag != 0)
            {
                temp_r0->field_2 = 0x4000;
                temp_r0->field_4 = 0x4000;
                temp_r0->field_6 = 0x892;
                temp_r0->field_10 = 0x1F4;
                temp_r0->field_12 = 0xFC;
            }
            else
            {
                temp_r0->field_2 = 0x4000;
                temp_r0->field_4 = flag;
                temp_r0->field_6 = 0x892;
                temp_r0->field_10 = flag;
                temp_r0->field_12 = 0xFA;
            }
            temp_r0->field_0 = 1;
            temp_r0->field_1 = 0;

            sub_800243C(sub_8004EDC(temp_r4), temp_r4->field_8 - 0xA0, temp_r4->field_18, -0xA0, 0xFE);
        }
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_800243C);
INCLUDE_ASM("asm/nonmatchings", sub_800271C);
INCLUDE_ASM("asm/nonmatchings", sub_80029D8);
INCLUDE_ASM("asm/nonmatchings", sub_8002B54);
u8 sub_8002D54(void) {

    if(gUnk_03004820 == 0)
        return 0;

    if(gUnk_030019B0 & DPAD_ANY)
    {
        if(sub_8001030(0xBB) == 0)
        {
            gUnk_030025D4--;
            if(gUnk_030025D4 == 0)
            {
                gUnk_030025D4 = ((sub_8000FF8() & 7) << 5) + 0xE8; 
                if(gUnk_030047B0 == 0x7B)
                {
                    gUnk_030025D4 >>= 1;
                }
                return 1;
            }
        }
        else
        {
            if(gUnk_030025D4 < 0xE8)
            {
                gUnk_030025D4 = 0xE8;
                
                if(gUnk_030047B0 == 0x7B)
                {
                    gUnk_030025D4 = 0x74;
                }
            }
        }
    }
    
    return 0;
}

void sub_8002DDC(void) {

    if (gUnk_03002604 == 0) {
        return;
    }
    switch (gUnk_03002604) 
    {
    case 1:
        REG_DISPCNT &= 0xFEFF;
        gUnk_03004658 = 0x1E41;
        gUnk_03004550 = 0xF00;
        gUnk_03000004 = 0;
        return;
        
    case 2:
    case 3:
    case 4:
    case 10:
        break;
        
    case 5:
        REG_DISPCNT |= 0x100;
        gUnk_03004550 = 0xF00;
        gUnk_03002604++;
        break;
        
    case 6:
        gUnk_03000004++;
        gUnk_03004550 &= 0xF00;
        gUnk_03004550 |= (gUnk_03000004 >> 2) & 0x1F;
        if((gUnk_03000004 >> 2) == 0x1F)
        {
            gUnk_03002604++;
            gUnk_03000004 = 0;
        }
        break;

    case 7:
        gUnk_03000004++;
        if( !(gUnk_03000004 & 3))
        {
            gUnk_03004550 -= 0x100;
            if(!(gUnk_03004550 & 0xFF00))
            {
                gUnk_03002604++;
                gUnk_03000004 = gUnk_03004550 & 0xFF00;
            }
        }
        break;

    case 8:
        gUnk_03000004++;
        if(gUnk_03000004 > 0x1B3)
        {
            gUnk_03002604++;
            gUnk_03000004 = 0;
        }
        break;
    case 9:
        gUnk_03000004++;
        gUnk_03004550 = (((gUnk_03000004 >> 2) & 0x1F) << 8) | ((0x1F - (gUnk_03000004 >> 2)) & 0x1F);
        if(gUnk_03004550 == 0x1F00)
        {
            gUnk_03002604++;
            gUnk_03000004 = 0;
        }
        break;

    }
}

extern u8 pltt_08057854[];
extern u8 tilemap_08057874[];
extern u8 tileset_1_08057A80[];
extern u8 tileset_2_08057EEC[];
extern u8 tileset_3_080583C4[];
#define GET_PLTT(n)     ((n) + 0)
#define GET_TILEMAP(n)  ((n) + 32)
// INCLUDE_ASM("asm/nonmatchings", sub_8002F6C); //Matched

void sub_8002F6C(void) {

    switch (gUnk_03002604) 
    {
        case 1:
            REG_BG0CNT = BGCNT_SCREENBASE(31) | BGCNT_CHARBASE(2);
            DmaCopy16(3, (void*)GET_PLTT(pltt_08057854), (void*)0x050001C0, 0x20);
            LZ77UnCompVram( (void*)GET_TILEMAP(pltt_08057854), (void *)BG_SCREEN_ADDR(31));
            gUnk_03002604++;
            break;
        case 2:
            LZ77UnCompVram(tileset_1_08057A80, (void*)0x06008000);
            gUnk_03002604++;
            break;
        case 3:
            LZ77UnCompVram(tileset_2_08057EEC, (void*)0x06008800);
            gUnk_03002604++;
            break;
        case 4:
            LZ77UnCompVram(tileset_3_080583C4, (void*)0x06009000);
            gUnk_03002604++;
            break;
        case 10:
            REG_DISPCNT &= 0xFEFF;
            gUnk_03004658 = 0x1C12;
            gUnk_03004550 = 0xC07;
            CpuFill16(0, (void*)0x0600F800, 0x800);
    
            gUnk_03002604 = 0;
        default:
            return;
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_8003088); //Matched

void sub_80030B0() {
    if (gUnk_03004840 == 0 && gUnk_03002600 == 1)
    {
        gUnk_03001944 = 2;
        gUnk_0300259C = 1;
    }
    else if (gUnk_03002600 != 1)
    {
        gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
        gUnk_03002600 = 1;
        sub_8009B44();
        sub_80089E0(4U);
    }
    sub_8002154();
}

void sub_8003114(void) {
    sub_800ACC8();
    sub_800C194();
    sub_80032BC();
}

void sub_8003128(void) {
    if (!(0x80 & gUnk_0300465C) && (gUnk_03004840 == 0)) {
        sub_8008254(gUnk_03001CA0);
    }
    sub_80081C0();
    sub_800445C();
    sub_80032BC();
    sub_80091C4();
}

void sub_8003168() {
    if (gUnk_03004840 == 0 && gUnk_03002600 == 1)
    {
        sub_80043D4();
        gUnk_03001944 = 2;
        gUnk_0300259C = 1;
    }
    else if (gUnk_03002600 != 1)
    {
        gUnk_03002C4C = (gUnk_03002C4C + 1) & 1;
        gUnk_03002600 = 1;
        sub_8009B44();
        sub_80089E0(4);
        sub_80536EC(0x2E);
    }
    sub_80081C0();
    sub_800445C();
    sub_80032BC();
    sub_80091C4();
}

void sub_80031E4() {
    sub_8011454();
    sub_80091C4();
    sub_80032BC();
}

void sub_80031F8() {
    sub_801417C();
    sub_80032BC();
}

void sub_8003208(void) {
    u16 i;

    sub_8003348();
    sub_8004BE0();
    sub_8004B8C();
    sub_8004BBC();

    for( i = 0; i < 128; i++ )
    {
        gUnk_030035C0[i].attrs[0] = 0;
        gUnk_030035C0[i].attrs[1] = 0;
    }

    sub_8004AC0();
    sub_8004B60();
    sub_8008A3C();
    sub_8009F48();
    sub_80032BC();
}

void sub_8003254(u8 arg0) {
    sub_80029D8(arg0);
}

void sub_8003264() {
    u16 i;
    u32 var_r3;

    for( i = 0; i < 32; i++)
    {
        if(gUnk_03003380[i].field_1 != 0)
        {
            var_r3 = gUnk_03003380[i].field_1 == 2 ? 0x40 : 0x20;
            DmaCopy16(3, gUnk_03003380[i].field_4, 0x05000000 + (gUnk_03003380[i].field_0 << 5), var_r3);
            gUnk_03003380[i].field_1 = 0;
        }
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_80032BC); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_8003348);
INCLUDE_ASM("asm/nonmatchings", sub_80033E8);
INCLUDE_ASM("asm/nonmatchings", sub_800345C);
INCLUDE_ASM("asm/nonmatchings", sub_800375C);

void sub_80037DC(u8 arg0) {
    u8 temp_r3;
    Unk_03002E80* ptr03002E80;
    struct Unk_03003AC0* ptr03003AC0;

    ptr03002E80 = &gUnk_03002E80[arg0];

    temp_r3 = sub_8004BFC();
    if(temp_r3 < 0x70)
    {
        ptr03003AC0 = &gUnk_03003AC0[temp_r3];
        ptr03002E80->field_0 = temp_r3;
        ptr03002E80->field_1 = 2;
        ptr03002E80->field_2 = 5;
        ptr03002E80->field_3 = 5;
        ptr03002E80->field_4 = 0;
        ptr03002E80->field_A = 0;
        ptr03002E80->field_B = 0;
        ptr03002E80->field_C = 0;
        ptr03002E80->field_D = 0;
        ptr03002E80->field_F = 0;
        ptr03002E80->field_13 = 0;
        ptr03002E80->field_24 = 0;
        ptr03002E80->field_5 = 0;
        ptr03002E80->field_E = 0;
        ptr03002E80->field_10 = 1;
        ptr03002E80->field_11 = 0;
        ptr03002E80->field_12 = 32;
        ptr03002E80->field_17 = 0;
        ptr03002E80->field_1A = 0;
        ptr03002E80->field_18 = 0;
        ptr03002E80->field_19 = 0;
        
        ptr03003AC0->field_0 = 0;
        ptr03003AC0->field_1 = 0;
        ptr03003AC0->field_C = 0;
    }
}

void sub_800384C(void) {
    u8 temp_r1;
    Unk_03003150* ptr03003150;
    struct Unk_03003AC0* ptr03003AC0;

    ptr03003150 = &gUnk_03003150;
    temp_r1 = sub_8004BFC();
    if ( temp_r1 < 0x70) {
        ptr03003AC0 = &gUnk_03003AC0[temp_r1];
        ptr03003150->field_0 = temp_r1;
        ptr03003150->field_1 = 2;
        ptr03003150->field_2 = 0xA;
        ptr03003150->field_3 = 0xA;
        ptr03003150->field_4 = 0;
        ptr03003150->field_6 = (gUnk_030025F8 + 8);
        ptr03003150->field_8 = (gUnk_03002C3C + 0xC);
        ptr03003150->field_A = 0;
        ptr03003150->field_B = 0;
        ptr03003150->field_C = 0;
        ptr03003150->field_D = 0;
        ptr03003150->field_F = 0;
        ptr03003150->field_13 = 0x80;
        ptr03003150->field_24 = 0;
        ptr03003150->field_5 = 0;
        ptr03003150->field_E = 0;
        ptr03003150->field_10 = 1;
        ptr03003150->field_11 = 0;
        ptr03003150->field_12 = 0x20;
        ptr03003150->field_17 = 0;
        ptr03003150->field_1A = 0;
        ptr03003150->field_18 = 0;
        ptr03003150->field_19 = 0;
        ptr03003AC0->field_0 = 128;
        ptr03003AC0->field_1 = 0;
        ptr03003AC0->field_C = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80038CC); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_8003958);
INCLUDE_ASM("asm/nonmatchings", sub_8003B08);
INCLUDE_ASM("asm/nonmatchings", sub_8003C54);
INCLUDE_ASM("asm/nonmatchings", sub_8003F40);
INCLUDE_ASM("asm/nonmatchings", sub_80040E4);
INCLUDE_ASM("asm/nonmatchings", sub_8004358);
INCLUDE_ASM("asm/nonmatchings", sub_80043D4);
INCLUDE_ASM("asm/nonmatchings", sub_800445C);
INCLUDE_ASM("asm/nonmatchings", sub_80046DC);
INCLUDE_ASM("asm/nonmatchings", sub_800478C);

INCLUDE_ASM("asm/nonmatchings", sub_8004980); //Matched

void sub_80049C8(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {

    Unk_03002E80* ptr = &gUnk_03002E80[arg0];
    
    if(arg1)
    {
        ptr->field_8 = ((arg2 + 1) << 3 )+ arg3;
    }
    else
    {
        ptr->field_6 = (arg2 << 3) + arg3;
    }

}

void sub_8004A00(u8 arg0, u8 arg1, u8 arg2, u8 arg3) {
    s16 val ;
    Unk_03002E80 *ptr2E80;

    if (arg2 != 0) 
    {
        val = arg3;
    }else
    {
        val = -arg3;
    }

    ptr2E80 = &gUnk_03002E80[arg0];

    if (arg1 != 0) {
        ptr2E80->field_8 += val;
    } else {
        ptr2E80->field_6 += val;
    }
}

u16 sub_8004A44(void) {
    u16 i;

    for(i = 0; i < 32; i++)
    {
        if(gUnk_03003360[i] == 0)
        {
            return i;
        }
    }
    return -1;
}

u8 sub_8004A6C() {
    u8 i;

    for(i = 0; i < 32; i++)
    {
        if(gUnk_03003380[i].field_1 == 0)
        {
            return i;
        }
    }
    return -1;
}

void sub_8004A94(u8 arg0, u32 arg1, s8 arg2, u8 arg3) {

    gUnk_03003380[arg0].field_0 = arg2;
    gUnk_03003380[arg0].field_4 = arg1;

    if(arg3  != 0)
    {
        gUnk_03003380[arg0].field_1 = 2;
    }
    else
    {
        gUnk_03003380[arg0].field_1 = 1;
    }
}

void sub_8004AC0(void) {
    u16 i;

    for( i = 0; i < 32; i++)
    {
        gUnk_03003360[i] = 0;
    }
}

void sub_8004ADC(void) {
    u16 i;

    for( i = 0; i < 32; i++)
    {
        if(gUnk_03003360[i] != 0)
        {
            DmaCopy16(3, gUnk_030039C0[i].field_0, gUnk_030039C0[i].field_4, gUnk_03003360[i] << 5 );
            gUnk_03003360[i] = 0;
        }
    }
}

void sub_8004B2C(u16 arg0, s32 arg1, s32 arg2, u8 arg3) {

    if( arg0 < 32)
    {
        gUnk_030039C0[arg0].field_0 = arg1;
        gUnk_030039C0[arg0].field_4 = arg2;
        gUnk_03003360[arg0] = arg3;
    }
}

void sub_8004B60() {
    u16 i;

    for( i = 0; i < 32; i++)
    {
        gUnk_03003380[i].field_1 = 0;
        gUnk_03003380[i].field_0 = 0;
        gUnk_03003380[i].field_4 = 0;
    }
}

void sub_8004B8C() {
    u16 i;
    
    for( i = 0; i < 128; i++)
    {
        gUnk_03003AC0[i].field_0 = 0;
        gUnk_03003AC0[i].field_C = 0;
    }
}

void sub_8004BBC(void) {
    u16 i;
    
    for( i = 0; i < 32; i++)
    {
        gUnk_030034C0[i].field_0 = 0;
        gUnk_030034C0[i].field_2 = 0;
        gUnk_030034C0[i].field_4 = 0;
        gUnk_030034C0[i].field_6 = 0;
    }
}

void sub_8004BE0(void) {
    u16 i;
    for( i = 0; i < 128; i++)
    {
        gUnk_03002C80[i] = 0;
    }
}

u8 sub_8004BFC(void) {
    u16 i;
    
    for( i = 2; i < 0x70; i++)
    {
        if(gUnk_03003AC0[i].field_0 == 0)
        {
            return i;
        }
    }
    return 0;   
}
static inline u8 findEmpty_Inl()
{
    u16 i;
    for ( i = 2; i < 0x70; i++) 
    {
        if (gUnk_03003AC0[i].field_0 == 0 ) 
        {
            return i;
        }
    }
    return 0;
}

struct Unk_03003AC0* sub_8004C28(struct Unk_03003AC0* arg0, u8 arg1, u16 arg2, u16 arg3, u16 arg4) {
    u8 foundIndex;

    arg0->field_0 = arg1;
    arg0->field_2 = arg2;
    arg0->field_4 = arg3;
    arg0->field_6 = arg4;
    arg0->field_1 = 0;

    if((arg1 & 0x7F) == 1)
        return 0;
    
    foundIndex = findEmpty_Inl();
    
    if(foundIndex == 0)
    {
        return 0;
    } 

    arg0->field_C = &gUnk_03003AC0[foundIndex];
    return &gUnk_03003AC0[foundIndex]; 
}
INCLUDE_ASM("asm/nonmatchings", sub_8004C8C); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_8004CB8); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_8004CE8); //Matched

void sub_8004D20(u8 arg0, u8 arg1, u8 arg2) {
    Unk_03002E80* p;
    p = &gUnk_03002E80[arg0];

    p->field_2 = arg1;
    p->field_3 = arg2;

    // gUnk_03002E80[arg0].unk2 = arg1;
    // gUnk_03002E80[arg0].unk3 = arg2;
}

void sub_8004D38(u8 arg0) {
    Unk_03002E80* ptr2E80;
    struct Unk_03003AC0* node;
    struct Unk_03003AC0* next;

    ptr2E80 = &gUnk_03002E80[arg0];

    node = &gUnk_03003AC0[ptr2E80->field_0];

    if(node->field_0 != 0 )
    {
        node->field_0 = 0;

        next = node->field_C;
        if(next != 0)
        {
            do
            {
                node->field_C = 0;
                node = next;
                if (node->field_0 == 0) break;
                node->field_0 = 0;
                next = node->field_C;
            }
            while (next != 0);   
        }
    }
    
    ptr2E80->field_0 = 0;
}
void sub_8004D8C(u8 arg0, u32 arg1) {
    Unk_03002E80* ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];
    ptr2E80->field_24 = arg1;
}
void sub_8004DA4(u8 arg0) {
    Unk_03002E80* ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];
    ptr2E80->field_12 |= 0x80;
    ptr2E80->field_12 &= 0xDF;
    ptr2E80->field_10 = 1;
    ptr2E80->field_17 = 0; 
    ptr2E80->field_11 = 0; 
}
s32 sub_8004DD0(void) {
    u8 i;
    Unk_03002E80* ptr2E80;
    ptr2E80 = gUnk_03002E80;
    
    for(i = 0; i < 0x18; i++)
    {
        if(ptr2E80->field_0 != 0 && ptr2E80->field_12 & 0x80)
           return 1;
        ptr2E80++;
    }
    
    return 0;
}
void sub_8004E04(void) {
    gUnk_03002C44 |= 1;
}
void sub_8004E14(u8 arg0, u16 arg1) {
    gUnk_03004670[arg0] = arg1;

    gUnk_03004540 = arg0;
    gUnk_030032D4 = arg1;
    gUnk_030032D0 |= 1;
}

void sub_8004E48(u8 arg0, u16 arg1) {
    gUnk_030047D0[arg0] = arg1;
    gUnk_030034B0 = arg0;
    gUnk_03003240 = arg1;
    gUnk_030032D0 |= 2;
}
u8 sub_8004E7C(void) {
    return gUnk_030032D0;
}
void sub_8004E88(u8 arg0, s32 arg1, s32 arg2, u8 arg3) {
    Unk_03002E80* ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];
    
    ptr2E80->field_6 = arg1 * 8;
    ptr2E80->field_8 = arg2 * 8;
    ptr2E80->field_11 = 0;
    ptr2E80->field_4 = arg3;
    ptr2E80->field_E = arg3;
}

u16 sub_8004EB8(Unk_03002E80* arg0) {
    if(arg0->field_12 & 1)
    {
        return  arg0->field_1A + sub_8008D78();
    }
    
    return arg0->field_1A ;
}
s16 sub_8004EDC(Unk_03002E80* arg0) {
    if (arg0->field_12 & 1) 
    {
        switch (gUnk_0300460C) 
        {                          /* irregular */
            case 2:
                return arg0->field_6 - (gUnk_030047C0 - 256);
            case 5:
                return arg0->field_6 - (gUnk_030047C0 - gUnk_030025B4);

        }
    }
    return arg0->field_6;
}
void sub_8004F3C(struct Unk_03003AC0* arg0) {

    struct Unk_03003AC0* node;
    struct Unk_03003AC0* next;

    if(arg0->field_0 == 0)
        return;

    arg0->field_0 = 0;

    node = arg0->field_C;

    if(node == 0)
        return;
    
    do
    {
        arg0->field_C = 0;
        arg0 = node;
        if (node->field_0 == 0) break;
        node->field_0 = 0;
        node = arg0->field_C;
    }
    while (node != 0);
}
INCLUDE_ASM("asm/nonmatchings", sub_8004F64);

void sub_8004FA8(u8 arg0, u8 arg1) {
    Unk_03002E80* ptr2E80;
    ptr2E80 = &gUnk_03002E80[arg0];
    ptr2E80->field_1 |= 1;
    ptr2E80->field_14 = 0;
    ptr2E80->field_16 = arg1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8004FD0);
INCLUDE_ASM("asm/nonmatchings", sub_8005020);
INCLUDE_ASM("asm/nonmatchings", sub_80051D0);
INCLUDE_ASM("asm/nonmatchings", sub_800526C);
INCLUDE_ASM("asm/nonmatchings", sub_80052F8);
INCLUDE_ASM("asm/nonmatchings", sub_80053B4);
INCLUDE_ASM("asm/nonmatchings", sub_80055E8);
INCLUDE_ASM("asm/nonmatchings", sub_8005B2C);
INCLUDE_ASM("asm/nonmatchings", sub_8005BB4);
INCLUDE_ASM("asm/nonmatchings", sub_8005C70);
INCLUDE_ASM("asm/nonmatchings", sub_80064AC);
INCLUDE_ASM("asm/nonmatchings", sub_8006520);
INCLUDE_ASM("asm/nonmatchings", sub_800661C);
INCLUDE_ASM("asm/nonmatchings", sub_80071EC);
INCLUDE_ASM("asm/nonmatchings", sub_800729C); //Matched
// void sub_800729C(u8 arg0) {
//     u16 i;

//     if(gUnk_0300467C & 0x80)
//         return;
    
//     gUnk_03004670[0] = gUnk_03004AA0[0];
//     gUnk_030047D0[0] = gUnk_03004AA0[0];
//     sub_8004C8C(0, gUnk_03004AA0[0]);
//     sub_8004CB8(0, gUnk_03004AA0[0]);
//     gUnk_03004670[1] = 11;
//     gUnk_030047D0[1] = 11;
//     sub_8004C8C(1, 11);
//     sub_8004CB8(1, 11);

//     if(gUnk_08088D80[arg0].field_9 != 0)
//     {
//         for(i = 0; i < 8; i++)
//         {
//             if(gUnk_03004670[i + 2] != 0xFF)
//             {
//                 sub_8004C8C(i + 2, gUnk_03004670[i + 2]);
//             }
//         }

//         for(i = 0; i < 8; i++)
//         {
//             if(gUnk_030047D0[i + 2] != 0xFF)
//             {
//                 sub_8004CB8(i + 2, gUnk_030047D0[i + 2]);
//             }
//         }
//     }
// }
INCLUDE_ASM("asm/nonmatchings", sub_8007350);
INCLUDE_ASM("asm/nonmatchings", sub_8007964);
INCLUDE_ASM("asm/nonmatchings", sub_80079BC);
INCLUDE_ASM("asm/nonmatchings", sub_8007A1C);
INCLUDE_ASM("asm/nonmatchings", sub_8007ADC);
INCLUDE_ASM("asm/nonmatchings", sub_8007BD0);
INCLUDE_ASM("asm/nonmatchings", sub_8007D5C);
INCLUDE_ASM("asm/nonmatchings", sub_8007FB8);
INCLUDE_ASM("asm/nonmatchings", sub_8008124);
INCLUDE_ASM("asm/nonmatchings", sub_80081C0);
INCLUDE_ASM("asm/nonmatchings", sub_8008254);
INCLUDE_ASM("asm/nonmatchings", sub_8008620);
INCLUDE_ASM("asm/nonmatchings", sub_80086FC);
INCLUDE_ASM("asm/nonmatchings", sub_8008788);
INCLUDE_ASM("asm/nonmatchings", sub_80088B4);
INCLUDE_ASM("asm/nonmatchings", sub_80088F4);
INCLUDE_ASM("asm/nonmatchings", sub_8008978);
void sub_80089E0(u16 arg0) {

    switch(arg0)
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
             sub_8009428(arg0 - 3);
            break;
    }

    gUnk_03004840 = arg0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8008A3C);
void sub_8008A60(void) {
    s16 i;

    for( i = 0; i < 16; i++)
    {
        sub_8007A1C(i);
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8008A80);
INCLUDE_ASM("asm/nonmatchings", sub_8008B14);
void sub_8008B5C(void) {
    // gUnk_03004670.field_0 = gUnk_03004AA0[0];
    gUnk_03004670[0] = gUnk_03004AA0[0];
    gUnk_030047D0[0] = gUnk_03004AA0[0];

    sub_8004C8C(0, gUnk_03004AA0[0]);
    sub_8004CB8(0, gUnk_03004AA0[0]);
    // gUnk_03004670.field_1 = 11;
    gUnk_03004670[1] = 11;
    gUnk_030047D0[1] = 11;
    sub_8004C8C(1, 0xBU);
    sub_8004CB8(1, 0xBU);
}
INCLUDE_ASM("asm/nonmatchings", sub_8008BA4);

void sub_8008BE4(u8 arg0) {
    gUnk_030046A0[arg0].field_3 |= 2;
}

void sub_8008BFC(u8 arg0) {
    gUnk_030046A0[arg0].field_3 &= 0xFD;
}

u8 sub_8008C14(u8 arg0) {
    return gUnk_030046A0[arg0].field_0;
}

INCLUDE_ASM("asm/nonmatchings", sub_8008C24);
INCLUDE_ASM("asm/nonmatchings", sub_8008C70);
INCLUDE_ASM("asm/nonmatchings", sub_8008CC0);
INCLUDE_ASM("asm/nonmatchings", sub_8008D18); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_8008D78);

void sub_8008DCC(u8 arg0) {
    gUnk_03004850 = arg0;
}


void sub_8008DD8(void) {
    DmaCopy16(3, (void*)0x08087216, (void*)0x05000000, 2);
}

INCLUDE_ASM("asm/nonmatchings", sub_8008DF8);
INCLUDE_ASM("asm/nonmatchings", sub_8008E44);
INCLUDE_ASM("asm/nonmatchings", sub_8008E94);
INCLUDE_ASM("asm/nonmatchings", sub_8008F28);
INCLUDE_ASM("asm/nonmatchings", sub_8008FD0);

void sub_800908C(u8 arg0) {
    u8 idx;

    if( gUnk_03004890[arg0].field_0 & 1)
    {
        sub_805374C(9, 0, 0);
    }
    else
    {
        sub_805374C(8, 0, 0);
    }

    gUnk_03004890[arg0].field_0 ^= 1;

    idx = gUnk_03004890[arg0].field_1;

    gUnk_03004870[idx >> 3] ^= (1 << (idx & 7));

    sub_8004F3C(&gUnk_03003AC0[gUnk_03004890[arg0].field_2]);
    sub_8008FD0(arg0);
    gUnk_03004860 = arg0;
}

void sub_8009114(void) {
    if (!(0x80 & gUnk_0300467C)) {
        nullsub_5();
        DmaCopy16(3, 0x08088C40, 0x060112C0, 0xA0*2);
        DmaCopy16(3, 0x08088C00, 0x050003C0, 0x20*2);
    }
}
void sub_8009168() {
    u8 i = 0;
    // do{gUnk_03004870[i++] = 0;}while(i < 0x20);
    while(i < 0x20){ gUnk_03004870[i++] = 0; }
}
void sub_8009184(u8 arg0)
{
    gUnk_03004870[arg0>>3] ^= (1 << (arg0 & 7));
}
u8 sub_80091A4(u8 arg0)
{
    u8 val;
    val = gUnk_03004870[(arg0 >> 3) & 0x1F];
    return (val >> (arg0 & 7)) & 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_80091C4);
INCLUDE_ASM("asm/nonmatchings", sub_8009370);
INCLUDE_ASM("asm/nonmatchings", sub_8009428);
INCLUDE_ASM("asm/nonmatchings", sub_80094FC);
INCLUDE_ASM("asm/nonmatchings", sub_8009600);
void sub_8009A5C(void) {
    s16 i;

    for( i = 0; i < 4; i++)
    {
        gUnk_03000010[i] = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8009A7C);
INCLUDE_ASM("asm/nonmatchings", sub_8009AC4);
void sub_8009B04(u8 arg0) {
    gUnk_03000010[arg0] &= 0xFB;
}
void sub_8009B1C(u8 arg0) {
    gUnk_03000010[arg0] |= 4;
}

u8 sub_8009B34(u8 arg0) {
    return gUnk_03000010[arg0];
}

void sub_8009B44(void) {
    DmaCopy16(3, PLTT, 0x0203EA00, PLTT_SIZE);
}

void sub_8009B64(void) {
    u16 i;
    u16* dst;
    i = 0x200;
    dst = (u16* )0x05000000;

    while(i > 0)
    {
        *dst = 0x7FFF;
        dst++;
        i--;
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_8009B84);
INCLUDE_ASM("asm/nonmatchings", sub_8009BF0);
INCLUDE_ASM("asm/nonmatchings", sub_8009C84);
INCLUDE_ASM("asm/nonmatchings", sub_8009D34);
INCLUDE_ASM("asm/nonmatchings", sub_8009E80);
INCLUDE_ASM("asm/nonmatchings", sub_8009F48);
INCLUDE_ASM("asm/nonmatchings", sub_8009F70);
INCLUDE_ASM("asm/nonmatchings", sub_800A048);
INCLUDE_ASM("asm/nonmatchings", sub_800A0E4);
INCLUDE_ASM("asm/nonmatchings", sub_800A1B4);
INCLUDE_ASM("asm/nonmatchings", sub_800A3C8);
INCLUDE_ASM("asm/nonmatchings", sub_800A534);
INCLUDE_ASM("asm/nonmatchings", sub_800A664);
INCLUDE_ASM("asm/nonmatchings", sub_800A79C);
INCLUDE_ASM("asm/nonmatchings", sub_800A86C);
INCLUDE_ASM("asm/nonmatchings", sub_800A8A0);
INCLUDE_ASM("asm/nonmatchings", sub_800A8D0);
INCLUDE_ASM("asm/nonmatchings", sub_800A924);
INCLUDE_ASM("asm/nonmatchings", sub_800A958); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_800A970); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_800A978);//Matched
void sub_800A980(void) {
    u8 i;
    u8 charaId;
    Unk_03004AC0* ptr;

    for(i = 0; i < 6; i++)
    {
        charaId = gUnk_03004AA0[i];
        if(charaId == 0xFF) continue;
        if(charaId != 0)
            charaId--;

        ptr = &gUnk_03004AC0[charaId];
        ptr->hp = ptr->max_hp;
        ptr->mp = ptr->max_mp;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_800A9C0);
INCLUDE_ASM("asm/nonmatchings", sub_800AA60);
INCLUDE_ASM("asm/nonmatchings", sub_800AA84);
void sub_800AAA4(s32 arg0) {
    gUnk_03002C38 += arg0;

    if(gUnk_03002C38 > 999999)
    {
        gUnk_03002C38 = 999999;
    }
}
void sub_800AAC0(s32 arg0) {
    gUnk_03002C38 -= arg0;
    
    if (gUnk_03002C38 > 999999) {
        gUnk_03002C38 = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_800AADC);
INCLUDE_ASM("asm/nonmatchings", sub_800AAF8);
INCLUDE_ASM("asm/nonmatchings", sub_800AB18);
u8 sub_800AB3C(void) {

    u16 i;
    u8 charaId;
    Unk_03004AC0* ptr;

    for(i = 0; i < 5; i++)
    {
        charaId = gUnk_03004AA0[i];
        if(charaId == 0xFF) continue;
        if(charaId != 0)
            charaId--;

        ptr = &gUnk_03004AC0[charaId];

        if(ptr->equip_slot1 != 0)
            return 1;

    }
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_800AB7C);
INCLUDE_ASM("asm/nonmatchings", sub_800ABBC);
INCLUDE_ASM("asm/nonmatchings", sub_800AC08);
void sub_800ACA4(u8 arg0) {
    Unk_03004AC0* ptr;

    if (arg0 != 0) {
        arg0--;
    }

    ptr = &gUnk_03004AC0[arg0];
    ptr->hp = ptr->max_hp;
    ptr->mp = ptr->max_mp;
}
INCLUDE_ASM("asm/nonmatchings", sub_800ACC8);
INCLUDE_ASM("asm/nonmatchings", sub_800B14C);
void sub_800B2D0(void) {
    u8 i;
    gUnk_03000186 = 0;
    gUnk_03000187 = 0;

    gUnk_03000048.field_0 = 1;
    gUnk_03000048.field_1 = 0;
    gUnk_03000048.field_2 = 0;
    gUnk_03000048.field_3 = 0;
    gUnk_03000048.field_4 = 0x18;
    gUnk_03000048.field_6 = 8;

    for(i = 0; i < 16; i++)
    {
        gUnk_03000188[i] = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_800B314);
INCLUDE_ASM("asm/nonmatchings", sub_800B374);
INCLUDE_ASM("asm/nonmatchings", sub_800BEE4);
INCLUDE_ASM("asm/nonmatchings", sub_800BF5C);
INCLUDE_ASM("asm/nonmatchings", sub_800BFF8);
INCLUDE_ASM("asm/nonmatchings", sub_800C0D8);
INCLUDE_ASM("asm/nonmatchings", sub_800C194);
INCLUDE_ASM("asm/nonmatchings", sub_800C2F8);


void sub_800E170(u8 arg0, u8 arg1, u8 arg2) {

    switch (arg0) {
    case 0:
        gUnk_03000058[arg2].field_4 = arg2 * 0x28 + 0x48;
        gUnk_03000058[arg2].field_6 = 8;
        break;
    case 1:
        gUnk_03000058[arg2].field_4 = 0x28;
        gUnk_03000058[arg2].field_6 = 8;

        break;
    case 2:
        gUnk_03000058[arg2].field_4 = 0x30;
        gUnk_03000058[arg2].field_6 = 16;
        break;
    }
    switch (arg1) {
    case 2:
        gUnk_03000058[arg2].field_0 &= 0xBF;
        gUnk_03000058[arg2].field_0 &= 0xFE;
        break;
    case 1: 
        gUnk_03000058[arg2].field_0 &= 0xBF;
        gUnk_03000058[arg2].field_0 |= 1;
        break;
    case 0: 
        gUnk_03000058[arg2].field_0 |= 0x40;
        gUnk_03000058[arg2].field_0 &= 0xFE;
        break;
    }
}

INCLUDE_ASM("asm/nonmatchings", sub_800E244);
INCLUDE_ASM("asm/nonmatchings", sub_800E668); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_800E71C); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_800E7BC);
INCLUDE_ASM("asm/nonmatchings", sub_800E8F8);
INCLUDE_ASM("asm/nonmatchings", sub_800EAE4);
INCLUDE_ASM("asm/nonmatchings", sub_800EB98);
INCLUDE_ASM("asm/nonmatchings", sub_800EC54);
INCLUDE_ASM("asm/nonmatchings", sub_800F128);
INCLUDE_ASM("asm/nonmatchings", sub_800F3AC);
INCLUDE_ASM("asm/nonmatchings", sub_800F4A8);
INCLUDE_ASM("asm/nonmatchings", sub_800F670);
INCLUDE_ASM("asm/nonmatchings", sub_800F70C);
INCLUDE_ASM("asm/nonmatchings", sub_800FA24);
INCLUDE_ASM("asm/nonmatchings", sub_800FB2C);
INCLUDE_ASM("asm/nonmatchings", sub_800FDEC);
INCLUDE_ASM("asm/nonmatchings", sub_800FF10);
INCLUDE_ASM("asm/nonmatchings", sub_8010170);
INCLUDE_ASM("asm/nonmatchings", sub_801026C);
INCLUDE_ASM("asm/nonmatchings", sub_8010300);
INCLUDE_ASM("asm/nonmatchings", sub_8010434);
INCLUDE_ASM("asm/nonmatchings", sub_80104F8);
INCLUDE_ASM("asm/nonmatchings", sub_8010624);
INCLUDE_ASM("asm/nonmatchings", sub_8010770);
INCLUDE_ASM("asm/nonmatchings", sub_8010978);
s32 sub_80109F8(u8 arg0) {

    switch (gUnk_03004D44) {

        case 0x1:
            ReadSram( (u8*)SRAM +(gUnk_03004DD0 << 0xB) , (u8*)0x02021000 + (gUnk_03004DD0 << 0xB) , 0x800);
            gUnk_03004D44++;
            return 1;
            
        case 0x2:
            if (VerifySram((u8*)(gUnk_03004DD0 << 0xB) + 0x02021000, (u8*)SRAM + (gUnk_03004DD0 << 0xB), 0x800) != 0) 
            {
                gUnk_03004D44 = 0xFD;
            } 
            else 
            {
                if ( gUnk_03004DD0 <= 0xE) 
                {
                    gUnk_03004D44--;
                } 
                else 
                {
                    gUnk_03004D44 = 0xF9;
                }
                gUnk_03004DD0++;
            }
            return 1;
            
        case 0x3:
            WriteSram((u8*)(gUnk_03004DD0 << 0xB) + 0x02021000, (u8*)SRAM + (gUnk_03004DD0 << 0xB) , 0x800);
            gUnk_03004D44++;
            return 1;
            
        case 0x4:
            if (VerifySram((u8*)(gUnk_03004DD0 << 0xB) + 0x02021000, (u8*)SRAM + (gUnk_03004DD0 << 0xB) , 0x800) != 0) 
            {
                gUnk_03004D44 = 0xFD;
                sub_8016508(0x27, 0xB);
                if (gUnk_03000187 > 5U) 
                {
                    gUnk_03000187 = gUnk_03000220 + 3;
                    sub_800E668(0xFF);
                }
            }
            else
            {
                if (gUnk_03004DD0 <= 0xE) 
                {
                    gUnk_03004D44--;
                } 
                else 
                {
                    gUnk_03004D44 = 0xFF;
                    sub_8016508(0x19, 0xB);
                    if (gUnk_03000187 > 5)
                    {
                        gUnk_03000187 = gUnk_03000220 + 3;
                        sub_800E668(0xFF);
                    }
                }
                gUnk_03004DD0++;
            }
            return 1;
    
        case 0xF9:
            sub_8010BEC(0);
            gUnk_03004D44 = 0xFA;
            return 1;
    
        case 0xFA:
            sub_8010BEC(1);
            gUnk_03004D44 = 0xFB;
            return 1;
            
        case 0xFB:
            sub_8010BEC(2);
            gUnk_03004D44 = 0xFC;
            return 1;
            
        case 0xFC:
            sub_8010BEC(3);
            gUnk_03004D44 = 0xFF;
            return 1;
            
        case 0xFD:
            *(u8* )0x02021000 = 0xFF;
            *(u8* )0x02023000 = 0xFF;
            *(u8* )0x02025000 = 0xFF;
            *(u8* )0x02027000 = 0xFF;
            gUnk_03004D44 = 0xFF;
            return 1;
    
        case 0xFF:
            if (arg0 == 0) 
            {
                sub_8015F14();
            }
            gUnk_03004D44 = 0xFE;
            return 1;
    
        default:
            return 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8010BEC);
INCLUDE_ASM("asm/nonmatchings", sub_8010CCC);
INCLUDE_ASM("asm/nonmatchings", sub_8010D80);
INCLUDE_ASM("asm/nonmatchings", sub_8010E58);
INCLUDE_ASM("asm/nonmatchings", sub_8010F10);
INCLUDE_ASM("asm/nonmatchings", sub_801114C);
INCLUDE_ASM("asm/nonmatchings", sub_8011268);
INCLUDE_ASM("asm/nonmatchings", sub_80113CC);
INCLUDE_ASM("asm/nonmatchings", sub_8011454);
INCLUDE_ASM("asm/nonmatchings", sub_8012530);
INCLUDE_ASM("asm/nonmatchings", sub_8012790);
INCLUDE_ASM("asm/nonmatchings", sub_8013870);
INCLUDE_ASM("asm/nonmatchings", sub_8013934);
INCLUDE_ASM("asm/nonmatchings", sub_8013B0C);
INCLUDE_ASM("asm/nonmatchings", sub_8013C00);
INCLUDE_ASM("asm/nonmatchings", sub_8013F3C);
INCLUDE_ASM("asm/nonmatchings", sub_8013FE8);
INCLUDE_ASM("asm/nonmatchings", sub_8014084);
INCLUDE_ASM("asm/nonmatchings", sub_80140D0);
INCLUDE_ASM("asm/nonmatchings", sub_8014124);
INCLUDE_ASM("asm/nonmatchings", sub_801417C);
INCLUDE_ASM("asm/nonmatchings", sub_8014488);
INCLUDE_ASM("asm/nonmatchings", sub_801455C);
INCLUDE_ASM("asm/nonmatchings", sub_80146A8);
INCLUDE_ASM("asm/nonmatchings", sub_8014A68);
INCLUDE_ASM("asm/nonmatchings", sub_801543C); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_80154E8);
INCLUDE_ASM("asm/nonmatchings", sub_8015658);
INCLUDE_ASM("asm/nonmatchings", sub_8015AF0);
INCLUDE_ASM("asm/nonmatchings", sub_8015B90);
INCLUDE_ASM("asm/nonmatchings", sub_8015C18);
INCLUDE_ASM("asm/nonmatchings", sub_8015E1C);
void sub_8015E88(void) {
    gUnk_03004D44 = 1;
    gUnk_03004DD0 = 0;
}
void sub_8015EA0(void) {
    sub_8013FE8();
    gUnk_03004D44 = 3;
    gUnk_03004DD0 = 0;
    *(u8* )0x03000221 = 1;
    sub_8016508(0x18, 0xB);
}

INCLUDE_ASM("asm/nonmatchings", sub_8015ED0); //Matched
void sub_8015F14(void) {
    u8 var_r3;
    u8 i;

    for(i = 0; i < 3; i++)
    {
        sub_8010E58(i);

        var_r3 = *(u8* )0x03000220 == i ? 0xD : 0xB;

        sub_8010F10(i, 8, i*2+5, var_r3);
    }
}
u32 sub_8015F50(u8 arg0) {
    u8 temp_r2;
    temp_r2 = gUnk_03004D60[arg0 >> 1];

    return (arg0 & 1) != 0 ? (temp_r2 >> 4) : (temp_r2 & 15);
}
void sub_8015F74(u8 x) {
    gUnk_03004DC8[x >> 3] |= (1 << (x & 7));
}
int sub_8015F94(u8 arg0) {
    return (gUnk_03004DC8[arg0 >> 3] >> (arg0 & 7)) & 1;
}
void sub_8015FB4(u8 arg0) {
    gUnk_03004DD4 = arg0;
    gUnk_03004D40 = 0x28;
    gUnk_03004DD8 = 0;
    gUnk_03004DC4 = 1;
    gUnk_03001944 = 0xD;

    ClearBuffer((u16* )0x02005800,0x1e,0x14);
}
INCLUDE_ASM("asm/nonmatchings", sub_8016038); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_8016068); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_80160CC); //Matched
void sub_80160F4(void) {
    DmaCopy32(3, 0x02020000, 0x06013800, 0x800);
    DmaCopy16(3, 0x0809E644, 0x05000240, 0x20);
    DmaCopy32(3, 0x02020800, 0x06017000, 0x1000);
    DmaCopy16(3, 0x080A12D0, 0x05000340, 0x40);
    DmaCopy16(3, 0x0808B7D4, 0x050001C0, 0x40);
}
INCLUDE_ASM("asm/nonmatchings", sub_8016178); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_80161F4); //Matched

void sub_801624C(s16 arg0, u16* dest) {
    sub_800BFF8(arg0, dest, 0xB000);
}

void sub_8016260(u8 arg0, u8 x, u8 y) {
    u16* dest;
    
    if (arg0 != 0) arg0--;

    dest = (u16*)0x02005800 + x + y * 32;
    *dest = 0xB257;
    dest += 3;

    sub_801624C(gUnk_03004AC0[arg0].lv + 1, dest);
}

void sub_80162A8(u8 arg0, u8 x, u8 y) {
    u16* dest;
    u32 unk;

    if (arg0 != 0) arg0--;

    dest = (u16*)0x02005800 + x + y * 32;
    *dest = 0xB258;
    dest += 3;

    unk = gUnk_03004AC0[arg0].hp == gUnk_03004AC0[arg0].max_hp ? 0xF000 : 0xB000;

    sub_800BFF8(gUnk_03004AC0[arg0].hp,  dest, unk);
}

void sub_8016308(u8 arg0, u8 x, u8 y) {
    u16* dest;
    u32 unk; //color

    if (arg0 != 0) arg0--;
    
    dest = (u16*)0x02005800 + x + y * 32;
    *dest = 0xB259;
    dest += 3;

    unk = gUnk_03004AC0[arg0].mp == gUnk_03004AC0[arg0].max_mp ? 0xF000 : 0xB000;

    sub_800BFF8(gUnk_03004AC0[arg0].mp,  dest, unk);
}

INCLUDE_ASM("asm/nonmatchings", sub_8016368); //Matched

void sub_80163CC(u8* src) {
    u16* dest;
    u8 x;
    u8 y;
    u8 paletteId;
    u8 charCode;

    while((x = *src++) != 0xFF)
    {
        y = *src++;
        paletteId = *src++;
        dest = (u16*)0x02005800 + x + (y * 32);

        while((charCode = *src++) != 0xFF)
        {
            if(charCode == 0xFE)
            {
                charCode = *src++;
                sub_8016368(dest, (charCode << 8) | 0xFE, paletteId);
            }
            else
            {
                sub_8016368(dest, charCode, paletteId);
            }
            dest++;
        }
    }
}

u8 sub_8016424(s32 *ptr, s32 divisor) {
    u8 count = 0;
    while (1) {
        *ptr -= divisor;
        if (*ptr < 0) {
            *ptr += divisor;
            break;
        }
        count++;
    }
    return count;
}

void sub_8016444(u16* arg0, u16 arg1, u8 arg2) {
    sub_8016368(sub_8016460(arg0, arg1, arg2), 0xC9, 0xB);
}
INCLUDE_ASM("asm/nonmatchings", sub_8016460);
INCLUDE_ASM("asm/nonmatchings", sub_80164C0);
void sub_80164F8(u16 arg0) {
    sub_8016508(arg0, 0xB);
}
void sub_8016508(u16 arg0, u8 arg1) {
    u16 i;
    u32 target;
    u8* ptr;

    ptr = gUnk_030001D0[ arg0 >> 6 ];

    target = arg0  & 0x3F;

    i = 0;

    while( i != target )
    {
        if( *ptr++ == 0xFF) i++;
    }

    sub_800BEE4(ptr, arg1);
}

s32 sub_801654C(u8* arg0, u8 arg1, u8 arg2) {
    u8 x, y;
    u16* dest;
    u8 len;

    x = *arg0++;
    y = *arg0++;

    dest = (u16*)0x02005800 + x + y * 32;

  
    if( arg2 == 0)
    {
        len = 0;
        while(*arg0 != 0xFF)
        {
            arg0++;
            len++;
        }
        while(len > 0)
        {
            sub_8016368(dest++, 0, 0x0B);
            len--;
        }
    }
    else
    {
         while (*arg0 != 0xFF) {
            sub_8016368(dest++, *arg0++, arg1);
        }
    }

    //No Return?
}

u8 sub_80165B8(void) {
    return gUnk_03000188[0] - 1;
}
void sub_80165C8(u8 x, u8 y, u8 width, u8 height) {
    u16* temp_buf;
    u16* buf;
    u16 row, col;
    buf = ( u16 *)(0x02005800) + x + y * 32;
    for (row = 0; row < height; row++) {
        temp_buf = buf;
        for (col = 0; col < width; col++) {
            *buf++ = 0xB001;
        }
        buf = temp_buf + 0x20;
    }
}
void sub_8016628(u8 arg0, u8 arg1) {
    u8 i;
    Unk_03000058* p;

    if(gUnk_03004D40 != 0 && arg0 == 0xFF)
    {
        arg0 = 5;
    }

    p = gUnk_03000058;
    for(i = 0; i < 15; i++)
    {
        if(p->field_0 != 0 && i != arg0)
        {
            if(arg1 != 0)
            {
                p->field_0 &= 0xBF;
            }
            else
            {
                p->field_0 |=0x40;
            }
        }
        p++;
    }
}

void sub_801667C(void) {
    u8 temp_r0;
    u8 i;
    Unk_03000058* p;

    p = gUnk_030000BC;

    for(i = 5; i < 15; i++)
    {
        if(p->field_0 != 0)
            p->field_0 |= 0x40;
        p++;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80166A4);
INCLUDE_ASM("asm/nonmatchings", sub_80166FC);
INCLUDE_ASM("asm/nonmatchings", sub_8016758);
void sub_80167D4(u8 arg0, u8 arg1) {
    u8 ret = sub_80165B8();
    if (ret != 0xFF) 
    {
        sub_800E170(arg0, arg1, ret);
    }
}
u8 sub_80167F8(u8 arg0) {
    u8 i;
    u8 val;

    val = gUnk_03004A88[arg0];

    i = 0;
    while(gUnk_03004AA0[i] != val )
    {
        i++;
        if( i > 4)
            return i;
    }

    return i;

}
void sub_801682C(void) {
    u8 var_r2;

    var_r2 = gUnk_03004AA0[(u8)(gUnk_03000188[0] - 1)];
    if (var_r2 != 0) {
        var_r2--;
    }
    sub_800FF10(gUnk_030001B4[gUnk_03000187 - 6], gUnk_03000188[gUnk_03000186], var_r2);
}
s32 sub_8016878(void) {
    return sub_8010170(gUnk_03000188[gUnk_03000186], gUnk_030001B4[gUnk_03000187 - 6] );
}
void sub_80168A8(void) {
    u8 var_r0;

    var_r0 = gUnk_03004AA0[gUnk_03000226];

    if(var_r0 != 0)
    {
        var_r0--;
    }

    gUnk_03000224 = gUnk_03004AC0[var_r0].field_unk[2];
    gUnk_03000225 = gUnk_03004AC0[var_r0].field_unk[3];
}

void sub_80168EC(void) {
    u8 var_r0;

    var_r0 = gUnk_03004AA0[gUnk_03000226];

    if(var_r0 != 0)
    {
        var_r0--;
    }

    gUnk_03004AC0[var_r0].field_unk[2] = gUnk_03000224 ;
    gUnk_03004AC0[var_r0].field_unk[3] = gUnk_03000225;
}

u8 sub_8016930(u8 arg0) {
    s32 temp_r2;
    u8 var_r0;
    u8 ret;

    temp_r2 = gUnk_03000227 + arg0;;

    if( temp_r2 < 8)
    {
        var_r0 = gUnk_03004AA0[gUnk_03000226];
        if(var_r0 != 0) var_r0--;

        ret = gUnk_03004AC0[var_r0].skills[temp_r2];
        
        if(ret != 0x26)
            return ret;
    }
    
    return 0xFF;
}
INCLUDE_ASM("asm/nonmatchings", sub_8016978);
INCLUDE_ASM("asm/nonmatchings", sub_80169AC);
INCLUDE_ASM("asm/nonmatchings", sub_80169EC);
INCLUDE_ASM("asm/nonmatchings", sub_8016A14);
void sub_8016A6C(void) {
    u8 i;

    for (i = 1; i <= 0xFD; i++) 
    {
        if(gUnk_03004980[i] != 0)
        {
            gUnk_03000199 = i;
            return;
        }
    }
    gUnk_03000199 = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8016AA0);
INCLUDE_ASM("asm/nonmatchings", sub_8016AD4);
INCLUDE_ASM("asm/nonmatchings", sub_8016B30);
INCLUDE_ASM("asm/nonmatchings", sub_8016BB0);
INCLUDE_ASM("asm/nonmatchings", sub_8016BE0);
INCLUDE_ASM("asm/nonmatchings", sub_8016C10);
u16* sub_8016C2C(u8 x, u8 y) {
    return (u16*) 0x2005800 + ((y * 32) + x);
}
INCLUDE_ASM("asm/nonmatchings", sub_8016C44); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_8016C88);
INCLUDE_ASM("asm/nonmatchings", sub_8016D24);
INCLUDE_ASM("asm/nonmatchings", sub_8016E30);
INCLUDE_ASM("asm/nonmatchings", sub_8016E80);
INCLUDE_ASM("asm/nonmatchings", sub_8016F30);
INCLUDE_ASM("asm/nonmatchings", sub_8016FC0);
void sub_80170BC(void) {
    if(gUnk_03004DF0[0] != 0)
    {
        gUnk_03004DF0[6] = 1;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80170D0);
INCLUDE_ASM("asm/nonmatchings", sub_8017120);
INCLUDE_ASM("asm/nonmatchings", sub_80171E4);
INCLUDE_ASM("asm/nonmatchings", sub_8017588);
INCLUDE_ASM("asm/nonmatchings", sub_80175C0);
void sub_8017600(u32* arg0, u32* arg1, u32 arg2, u32 arg3) {
    gUnk_03004F80.field_4 = arg0;
    gUnk_03004F80.field_0 = arg1;
    gUnk_03004F80.field_8 = arg2 >> 4;
    gUnk_03004F80.field_A = 0;
    gUnk_03004F80.field_C = arg3;
}
INCLUDE_ASM("asm/nonmatchings", sub_801761C);
INCLUDE_ASM("asm/nonmatchings", sub_8017640);
INCLUDE_ASM("asm/nonmatchings", sub_801768C);
INCLUDE_ASM("asm/nonmatchings", sub_80177AC);
INCLUDE_ASM("asm/nonmatchings", sub_8017FA4);
INCLUDE_ASM("asm/nonmatchings", sub_8018070);
INCLUDE_ASM("asm/nonmatchings", sub_80182A8);
INCLUDE_ASM("asm/nonmatchings", sub_80184A8);
INCLUDE_ASM("asm/nonmatchings", sub_801869C);
void sub_8018744(void) {
    gUnk_03000316 = 10;
}
INCLUDE_ASM("asm/nonmatchings", sub_8018750);
u32 sub_801878C(void) {
    return gUnk_03000340;
}
void sub_8018798(u8 index, u16 value)
{
    gUnk_03000330[index] = value;
}

u8 sub_80187A8()
{
    return gUnk_0300032E;
}
u16 sub_80187B4()
{
    return gUnk_03000324;
}
void sub_80187C0(u16 arg0)
{
    gUnk_03000324 |= arg0;
}
void sub_80187D4(u16 arg0)
{
    gUnk_03000324 &= ~arg0;
}
u16 sub_80187E8()
{
    return gUnk_03000314;
}
u16 sub_80187F4()
{
    return gUnk_03000312;
}
void sub_8018800(UnkNode* node) {
    node->prev = node;
    node->next = node;
    node->key = -1;
}
void sub_801880C(UnkNode* node, u8 arg1) {
    node->prev = 0;
    node->next = 0;
    node->key = arg1;
}
void sub_8018818(UnkNode *head, UnkNode *new_node) {
    UnkNode *cur = head->next;

    while (cur->key < new_node->key) {
        cur = cur->next;
    }
    new_node->next = cur;
    new_node->prev = cur->prev;
    cur->prev->next = new_node;
    cur->prev = new_node;
}
void sub_8018838(u32 arg0)
{
    gUnk_03000328 = arg0;
}
/*
    LCG（linear congruential generator）线性同余算法
*/ 
u16 sub_8018844(void) {
    u32 seed ;
    seed = gUnk_03000328 * 0x41C64E6D + 0x3039;
    gUnk_03000328 = seed;
    return (seed / 0x10000) & 0x7FFF;
}

u32 sub_8018864()
{
    return 0x02037028;
}
u32 sub_801886C()
{
    return 0x03000248;
}
u32 sub_8018874()
{
    return 0x02037410;
}

void sub_801887C(void) {
    if (!(gUnk_03000324 & 8)) 
    {
        sub_80199E0();
        sub_804AF60();
    }
}
void sub_801889C(void) {
    sub_8019784();
    if (!(gUnk_03000324 & 8)) 
    {
        sub_804AE2C();
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_80188BC);
INCLUDE_ASM("asm/nonmatchings", sub_8018928);
INCLUDE_ASM("asm/nonmatchings", sub_8018A58);
INCLUDE_ASM("asm/nonmatchings", sub_8018BF8);
INCLUDE_ASM("asm/nonmatchings", sub_8018D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8018E34);
INCLUDE_ASM("asm/nonmatchings", sub_8018EA8);
INCLUDE_ASM("asm/nonmatchings", sub_8018FC0);
INCLUDE_ASM("asm/nonmatchings", sub_8019148);
INCLUDE_ASM("asm/nonmatchings", sub_80191CC);
INCLUDE_ASM("asm/nonmatchings", sub_8019304);
INCLUDE_ASM("asm/nonmatchings", sub_801933C);
INCLUDE_ASM("asm/nonmatchings", sub_80196D4);
INCLUDE_ASM("asm/nonmatchings", sub_8019748);
INCLUDE_ASM("asm/nonmatchings", sub_8019784);
INCLUDE_ASM("asm/nonmatchings", sub_80199E0);
INCLUDE_ASM("asm/nonmatchings", sub_8019AD0);
INCLUDE_ASM("asm/nonmatchings", sub_8019B98);
void sub_8019DF8()
{
    gUnk_03000510 = 0;
}
void sub_8019E04(u16 arg0)
{
    gUnk_03000510 |= arg0;
}
u16 sub_8019E18()
{
    return gUnk_03000510 ;
}
void sub_8019E24(u16 mask)
{

    gUnk_03000510 &= ~mask;
}
void sub_8019E38(void)
{
    REG_DISPCNT &= 0xF7FF;
}
void sub_8019E4C(void)
{
    REG_DISPCNT |= 0x800;
}
INCLUDE_ASM("asm/nonmatchings", sub_8019E60);
void sub_8019ECC(void)
{
    REG_DISPCNT &= 0xFEFF;
}

INCLUDE_ASM("asm/nonmatchings", sub_8019EE0);
INCLUDE_ASM("asm/nonmatchings", sub_8019F08);
INCLUDE_ASM("asm/nonmatchings", sub_8019F78);
u8 sub_801A05C(u8 index)
{
    return gUnk_03000348[index].field_C;
}
INCLUDE_ASM("asm/nonmatchings", sub_801A074);
INCLUDE_ASM("asm/nonmatchings", sub_801A0F0);
void sub_801A13C()
{
    gUnk_03000384 = 0;
}
u16 sub_801A148()
{
    return gUnk_03000384 ;
}
void sub_801A154(u16 mask)
{

    gUnk_03000384 &= ~mask;
}
INCLUDE_ASM("asm/nonmatchings", sub_801A168);
INCLUDE_ASM("asm/nonmatchings", sub_801A1DC);
INCLUDE_ASM("asm/nonmatchings", sub_801A218);
INCLUDE_ASM("asm/nonmatchings", sub_801A270);
INCLUDE_ASM("asm/nonmatchings", sub_801A2AC);
INCLUDE_ASM("asm/nonmatchings", sub_801A2EC);
void sub_801A324(void)
{
    gUnk_030004F8 = 0;
    return;
}
void sub_801A330(void)
{
    gUnk_030004F8 = 4;
}
u8 sub_801A33C(void)
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

void sub_801A36C(void) {

    REG_BG0HOFS = gUnk_03000500.field_0;
    REG_BG0VOFS = gUnk_03000500.field_2;
    REG_BG1HOFS = gUnk_03000500.field_4;
    REG_BG1VOFS = gUnk_03000500.field_6;
    REG_BG2HOFS = gUnk_03000500.field_8;
    REG_BG2VOFS = gUnk_03000500.field_A;
    REG_BG3HOFS = gUnk_03000500.field_C;
    REG_BG3VOFS = gUnk_03000500.field_E;
}
INCLUDE_ASM("asm/nonmatchings", sub_801A3A8); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_801A3C4);
INCLUDE_ASM("asm/nonmatchings", sub_801A5EC);
INCLUDE_ASM("asm/nonmatchings", sub_801A684);
INCLUDE_ASM("asm/nonmatchings", sub_801A6F4);
INCLUDE_ASM("asm/nonmatchings", sub_801A884);
INCLUDE_ASM("asm/nonmatchings", sub_801AD0C);
INCLUDE_ASM("asm/nonmatchings", sub_801B0B8);
INCLUDE_ASM("asm/nonmatchings", sub_801B570);
INCLUDE_ASM("asm/nonmatchings", sub_801B688); //Matched
INCLUDE_ASM("asm/nonmatchings", sub_801B760);
INCLUDE_ASM("asm/nonmatchings", sub_801B790);
INCLUDE_ASM("asm/nonmatchings", sub_801B7B8);
INCLUDE_ASM("asm/nonmatchings", sub_801B81C);
INCLUDE_ASM("asm/nonmatchings", sub_801B878);
INCLUDE_ASM("asm/nonmatchings", sub_801B8AC);
u16* sub_801B8E8(u16* ptr, u16 value)
{
    u16* current = (u16*)((u8*)ptr + 2);
    
    while (*(current + 1) <= value) {
        current += 2;
    }
    return current;
}
INCLUDE_ASM("asm/nonmatchings", sub_801B8FC);
void sub_801B920(void) {
    u8 i;

    GameOamData* oamPtr;
    Unk_030034C0* srcPtr;

    oamPtr = &gUnk_030035C0[0];
    srcPtr = gUnk_030034C0;


    for(i = 0; i < 32; i++)
    {
        oamPtr->fields.AffineParam = srcPtr->field_0;
        oamPtr++;
        oamPtr->fields.AffineParam = srcPtr->field_2;
        oamPtr++;
        oamPtr->fields.AffineParam = srcPtr->field_4;
        oamPtr++;
        oamPtr->fields.AffineParam = srcPtr->field_6;
        oamPtr++;
        srcPtr++;
     }

    // do {
    //     oamPtr[0].fields.AffineParam = srcPtr->field_0;
    //     oamPtr++;
    //     oamPtr[0].fields.AffineParam = srcPtr->field_2;
    //     oamPtr++;
    //     oamPtr[0].fields.AffineParam = srcPtr->field_4;
    //     oamPtr++;
    //     oamPtr[0].fields.AffineParam = srcPtr->field_6;

    //     oamPtr++;
    //     srcPtr++;
    //     i++;
    // } while (i < 32);


}
u8 sub_801B954(void** ptr)
{
    return *((u8*)(*ptr + 2));
}
u16 sub_801B95C(void** ptr)
{
    void* p = *(ptr + 1);  // ptr偏移4字节（一个指针大小），等价于ptr[1]
    return *(u16*)((u8*)p + 2);
}
INCLUDE_ASM("asm/nonmatchings", sub_801B964);
INCLUDE_ASM("asm/nonmatchings", sub_801BE34);
INCLUDE_ASM("asm/nonmatchings", sub_801C484);
INCLUDE_ASM("asm/nonmatchings", sub_801CA08);
INCLUDE_ASM("asm/nonmatchings", sub_801CBA4);
INCLUDE_ASM("asm/nonmatchings", sub_801CE80);
INCLUDE_ASM("asm/nonmatchings", sub_801CF90);
INCLUDE_ASM("asm/nonmatchings", sub_801D12C);
INCLUDE_ASM("asm/nonmatchings", sub_801D19C);
INCLUDE_ASM("asm/nonmatchings", sub_801D214);
INCLUDE_ASM("asm/nonmatchings", sub_801D378);
INCLUDE_ASM("asm/nonmatchings", sub_801D468);
INCLUDE_ASM("asm/nonmatchings", sub_801D568);
INCLUDE_ASM("asm/nonmatchings", sub_801D710);
INCLUDE_ASM("asm/nonmatchings", sub_801D984);
INCLUDE_ASM("asm/nonmatchings", sub_801DAA0);
INCLUDE_ASM("asm/nonmatchings", sub_801DB3C);
INCLUDE_ASM("asm/nonmatchings", sub_801DC20);
INCLUDE_ASM("asm/nonmatchings", sub_801DD04);
INCLUDE_ASM("asm/nonmatchings", sub_801DDB0);
INCLUDE_ASM("asm/nonmatchings", sub_801DE44);
INCLUDE_ASM("asm/nonmatchings", sub_801DEDC);
INCLUDE_ASM("asm/nonmatchings", sub_801DF90);
INCLUDE_ASM("asm/nonmatchings", sub_801E040);
INCLUDE_ASM("asm/nonmatchings", sub_801E1D8);
INCLUDE_ASM("asm/nonmatchings", sub_801E30C);
INCLUDE_ASM("asm/nonmatchings", sub_801E4D4);
INCLUDE_ASM("asm/nonmatchings", sub_801E690);
INCLUDE_ASM("asm/nonmatchings", sub_801E848);
INCLUDE_ASM("asm/nonmatchings", sub_801EA70);
INCLUDE_ASM("asm/nonmatchings", sub_801EC3C);
INCLUDE_ASM("asm/nonmatchings", sub_801ED40);
INCLUDE_ASM("asm/nonmatchings", sub_801EE6C);
INCLUDE_ASM("asm/nonmatchings", sub_801EEE4);
INCLUDE_ASM("asm/nonmatchings", sub_801F3FC);
INCLUDE_ASM("asm/nonmatchings", sub_801F76C);
INCLUDE_ASM("asm/nonmatchings", sub_801F884);
INCLUDE_ASM("asm/nonmatchings", sub_801FA10);
INCLUDE_ASM("asm/nonmatchings", sub_801FAB8);
INCLUDE_ASM("asm/nonmatchings", sub_801FEBC);
INCLUDE_ASM("asm/nonmatchings", sub_801FF40);
INCLUDE_ASM("asm/nonmatchings", sub_80200E8);
INCLUDE_ASM("asm/nonmatchings", sub_8020228);
INCLUDE_ASM("asm/nonmatchings", sub_802031C);
INCLUDE_ASM("asm/nonmatchings", sub_8020648);
u8 sub_8020798(void)
{
    return gUnk_03000744;
}
void sub_80207A4(void)
{
    gUnk_03000630--;
}
INCLUDE_ASM("asm/nonmatchings", sub_80207B4);
INCLUDE_ASM("asm/nonmatchings", sub_80207DC);
INCLUDE_ASM("asm/nonmatchings", sub_8020840);
INCLUDE_ASM("asm/nonmatchings", sub_80208A4);
INCLUDE_ASM("asm/nonmatchings", sub_8020914);
INCLUDE_ASM("asm/nonmatchings", sub_802093C);
INCLUDE_ASM("asm/nonmatchings", sub_8020974);
INCLUDE_ASM("asm/nonmatchings", sub_80209C8);
INCLUDE_ASM("asm/nonmatchings", sub_80209EC);
INCLUDE_ASM("asm/nonmatchings", sub_8020A0C);
INCLUDE_ASM("asm/nonmatchings", sub_8020A7C);
INCLUDE_ASM("asm/nonmatchings", sub_8020AB0);
INCLUDE_ASM("asm/nonmatchings", sub_8020AE4);
INCLUDE_ASM("asm/nonmatchings", sub_8020B04);
u32 sub_8020B48(void)
{
    return gUnk_03000718;
}
INCLUDE_ASM("asm/nonmatchings", sub_8020B54);
INCLUDE_ASM("asm/nonmatchings", sub_8020B90);
INCLUDE_ASM("asm/nonmatchings", sub_8020BC0);
INCLUDE_ASM("asm/nonmatchings", sub_8020BF0);
INCLUDE_ASM("asm/nonmatchings", sub_8020C2C);
INCLUDE_ASM("asm/nonmatchings", sub_8020C58);
INCLUDE_ASM("asm/nonmatchings", sub_8020CC4);
INCLUDE_ASM("asm/nonmatchings", sub_8020D50);
INCLUDE_ASM("asm/nonmatchings", sub_8020DA0);
void sub_8020DE4(void)
{
    gUnk_0300071C = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8020DF0);
u32* sub_8020E54(void)
{
    return &gUnk_03000730;
}
u8 sub_8020E5C(void)
{
    return gUnk_0300073D;
}
u32 sub_8020E68(void)
{
    return gUnk_0300062C;
}
void sub_8020E74(void)
{
    u8 i;
    for (i = 0; i <= 10; i++) {
        gUnk_03000748[i] = 0;
    }
}
INCLUDE_ASM("asm/nonmatchings", sub_8020E90);
INCLUDE_ASM("asm/nonmatchings", sub_8020EAC);

INCLUDE_ASM("asm/nonmatchings", sub_8020EC8);
void sub_8020EEC(u8 value)
{
    gUnk_03000758[gUnk_03000763] = value;
    gUnk_03000763++;
}
INCLUDE_ASM("asm/nonmatchings", sub_8020F08);
INCLUDE_ASM("asm/nonmatchings", sub_8020F4C);
INCLUDE_ASM("asm/nonmatchings", sub_8020FB8);
INCLUDE_ASM("asm/nonmatchings", sub_802103C);
INCLUDE_ASM("asm/nonmatchings", sub_8021064);
INCLUDE_ASM("asm/nonmatchings", sub_80210C0);

void sub_8021130(void) {
    u8 i;

    for ( i = 0; i < 10; i++ )
    {
        gUnk_03000788[i][0] = 0;
        gUnk_03000788[i][1] = 0;
        gUnk_03000788[i][2] = 0;
        gUnk_03000788[i][3] = 0;
        gUnk_03000788[i][4] = 0;
    } 
    gUnk_030007BA = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8021184);
INCLUDE_ASM("asm/nonmatchings", sub_80212B4);
INCLUDE_ASM("asm/nonmatchings", sub_802151C);
INCLUDE_ASM("asm/nonmatchings", sub_8021700);
INCLUDE_ASM("asm/nonmatchings", sub_8021788);
INCLUDE_ASM("asm/nonmatchings", sub_802181C);
INCLUDE_ASM("asm/nonmatchings", sub_802192C);
INCLUDE_ASM("asm/nonmatchings", sub_8022458);
INCLUDE_ASM("asm/nonmatchings", sub_8022550);
INCLUDE_ASM("asm/nonmatchings", sub_8022710);
INCLUDE_ASM("asm/nonmatchings", sub_8022F2C);
INCLUDE_ASM("asm/nonmatchings", sub_80230BC);
INCLUDE_ASM("asm/nonmatchings", sub_8023320);
INCLUDE_ASM("asm/nonmatchings", sub_8023414);
INCLUDE_ASM("asm/nonmatchings", sub_8023820);
INCLUDE_ASM("asm/nonmatchings", sub_80244BC);
INCLUDE_ASM("asm/nonmatchings", sub_8024618);
INCLUDE_ASM("asm/nonmatchings", sub_80246E8);
INCLUDE_ASM("asm/nonmatchings", sub_8024820);
INCLUDE_ASM("asm/nonmatchings", sub_8024940);
void sub_802550C(u8 value)
{
    gUnk_03000816 = value;
}
INCLUDE_ASM("asm/nonmatchings", sub_8025518);
void sub_8025638(void)
{
    gUnk_03000814 = -1;
    gUnk_03000815 = -1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8025650);
INCLUDE_ASM("asm/nonmatchings", sub_80256E4);
INCLUDE_ASM("asm/nonmatchings", sub_802576C);
INCLUDE_ASM("asm/nonmatchings", sub_80257D8);
INCLUDE_ASM("asm/nonmatchings", sub_8025994);
INCLUDE_ASM("asm/nonmatchings", sub_8025DA8);
INCLUDE_ASM("asm/nonmatchings", sub_80260BC);
INCLUDE_ASM("asm/nonmatchings", sub_80264C0);
INCLUDE_ASM("asm/nonmatchings", sub_802698C);
INCLUDE_ASM("asm/nonmatchings", sub_8026D08);
INCLUDE_ASM("asm/nonmatchings", sub_8026F88);
INCLUDE_ASM("asm/nonmatchings", sub_802723C);
INCLUDE_ASM("asm/nonmatchings", sub_802761C);
INCLUDE_ASM("asm/nonmatchings", sub_8027760);
INCLUDE_ASM("asm/nonmatchings", sub_8027A20);
INCLUDE_ASM("asm/nonmatchings", sub_8027D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8028098);
INCLUDE_ASM("asm/nonmatchings", sub_80282EC);
INCLUDE_ASM("asm/nonmatchings", sub_80285A0);
INCLUDE_ASM("asm/nonmatchings", sub_80287EC);
INCLUDE_ASM("asm/nonmatchings", sub_8028AD8);
INCLUDE_ASM("asm/nonmatchings", sub_8029268);
INCLUDE_ASM("asm/nonmatchings", sub_8029510);
INCLUDE_ASM("asm/nonmatchings", sub_8029784);
INCLUDE_ASM("asm/nonmatchings", sub_80299C8);
INCLUDE_ASM("asm/nonmatchings", sub_8029BF8);
INCLUDE_ASM("asm/nonmatchings", sub_802A154);
INCLUDE_ASM("asm/nonmatchings", sub_802A86C);
INCLUDE_ASM("asm/nonmatchings", sub_802ADC4);
INCLUDE_ASM("asm/nonmatchings", sub_802B0F0);
INCLUDE_ASM("asm/nonmatchings", sub_802B608);
INCLUDE_ASM("asm/nonmatchings", sub_802B8BC);
INCLUDE_ASM("asm/nonmatchings", sub_802BB24);
INCLUDE_ASM("asm/nonmatchings", sub_802BD94);
INCLUDE_ASM("asm/nonmatchings", sub_802C0EC);
INCLUDE_ASM("asm/nonmatchings", sub_802C490);
INCLUDE_ASM("asm/nonmatchings", sub_802C714);
INCLUDE_ASM("asm/nonmatchings", sub_802C9E8);
INCLUDE_ASM("asm/nonmatchings", sub_802CE90);
INCLUDE_ASM("asm/nonmatchings", sub_802D1FC);
INCLUDE_ASM("asm/nonmatchings", sub_802D454);
INCLUDE_ASM("asm/nonmatchings", sub_802D728);
INCLUDE_ASM("asm/nonmatchings", sub_802DA78);
INCLUDE_ASM("asm/nonmatchings", sub_802DE04);
INCLUDE_ASM("asm/nonmatchings", sub_802DFDC);
INCLUDE_ASM("asm/nonmatchings", sub_802E234);
INCLUDE_ASM("asm/nonmatchings", sub_802E49C);
INCLUDE_ASM("asm/nonmatchings", sub_802E6C8);
INCLUDE_ASM("asm/nonmatchings", sub_802EAC4);
INCLUDE_ASM("asm/nonmatchings", sub_802EDD8);
INCLUDE_ASM("asm/nonmatchings", sub_802F100);
INCLUDE_ASM("asm/nonmatchings", sub_802F480);
INCLUDE_ASM("asm/nonmatchings", sub_802F6D8);
INCLUDE_ASM("asm/nonmatchings", sub_802F9EC);
INCLUDE_ASM("asm/nonmatchings", sub_802FE98);
INCLUDE_ASM("asm/nonmatchings", sub_803029C);
INCLUDE_ASM("asm/nonmatchings", sub_8030664);
INCLUDE_ASM("asm/nonmatchings", sub_80309B0);
INCLUDE_ASM("asm/nonmatchings", sub_8030C08);
INCLUDE_ASM("asm/nonmatchings", sub_8030D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8030F30);
INCLUDE_ASM("asm/nonmatchings", sub_80310C4);
INCLUDE_ASM("asm/nonmatchings", sub_8031258);
INCLUDE_ASM("asm/nonmatchings", sub_80313EC);
INCLUDE_ASM("asm/nonmatchings", sub_8031580);
INCLUDE_ASM("asm/nonmatchings", sub_8031714);
INCLUDE_ASM("asm/nonmatchings", sub_80318A8);
INCLUDE_ASM("asm/nonmatchings", sub_8031A3C);
INCLUDE_ASM("asm/nonmatchings", sub_8031BD0);
INCLUDE_ASM("asm/nonmatchings", sub_8031D64);
INCLUDE_ASM("asm/nonmatchings", sub_8031EF8);
INCLUDE_ASM("asm/nonmatchings", sub_803208C);
INCLUDE_ASM("asm/nonmatchings", sub_8032220);
INCLUDE_ASM("asm/nonmatchings", sub_80323B4);
INCLUDE_ASM("asm/nonmatchings", sub_8032548);
INCLUDE_ASM("asm/nonmatchings", sub_803272C);
INCLUDE_ASM("asm/nonmatchings", sub_8032948);
INCLUDE_ASM("asm/nonmatchings", sub_8032D74);
INCLUDE_ASM("asm/nonmatchings", sub_8032EA0);
INCLUDE_ASM("asm/nonmatchings", sub_80334B8);
INCLUDE_ASM("asm/nonmatchings", sub_8033988);
INCLUDE_ASM("asm/nonmatchings", sub_8033E2C);
INCLUDE_ASM("asm/nonmatchings", sub_8034440);
INCLUDE_ASM("asm/nonmatchings", sub_80345AC);
INCLUDE_ASM("asm/nonmatchings", sub_8034718);
INCLUDE_ASM("asm/nonmatchings", sub_80348A8);
INCLUDE_ASM("asm/nonmatchings", sub_8034BFC);
INCLUDE_ASM("asm/nonmatchings", sub_8034D94);
INCLUDE_ASM("asm/nonmatchings", sub_8034F00);
INCLUDE_ASM("asm/nonmatchings", sub_8035130);
INCLUDE_ASM("asm/nonmatchings", sub_8035360);
INCLUDE_ASM("asm/nonmatchings", sub_803586C);
INCLUDE_ASM("asm/nonmatchings", sub_8035B04);
INCLUDE_ASM("asm/nonmatchings", sub_8035D9C);
INCLUDE_ASM("asm/nonmatchings", sub_8036034);
INCLUDE_ASM("asm/nonmatchings", sub_80362CC);
INCLUDE_ASM("asm/nonmatchings", sub_8036564);
INCLUDE_ASM("asm/nonmatchings", sub_80368FC);
INCLUDE_ASM("asm/nonmatchings", sub_8036B30);
INCLUDE_ASM("asm/nonmatchings", sub_8036EA4);
INCLUDE_ASM("asm/nonmatchings", sub_8037078);
INCLUDE_ASM("asm/nonmatchings", sub_8037388);
INCLUDE_ASM("asm/nonmatchings", sub_8037868);
INCLUDE_ASM("asm/nonmatchings", sub_8037C40);
INCLUDE_ASM("asm/nonmatchings", sub_8037E14);
INCLUDE_ASM("asm/nonmatchings", sub_8037FE8);
INCLUDE_ASM("asm/nonmatchings", sub_80381BC);
INCLUDE_ASM("asm/nonmatchings", sub_8038390);
INCLUDE_ASM("asm/nonmatchings", sub_8038568);
INCLUDE_ASM("asm/nonmatchings", sub_803874C);
INCLUDE_ASM("asm/nonmatchings", sub_8038920);
INCLUDE_ASM("asm/nonmatchings", sub_8038C84);
INCLUDE_ASM("asm/nonmatchings", sub_8038E44);
INCLUDE_ASM("asm/nonmatchings", sub_8039024);
INCLUDE_ASM("asm/nonmatchings", sub_80392C0);
INCLUDE_ASM("asm/nonmatchings", sub_80393E0);
INCLUDE_ASM("asm/nonmatchings", sub_8039724);
INCLUDE_ASM("asm/nonmatchings", sub_8039C38);
INCLUDE_ASM("asm/nonmatchings", sub_8039C6C);
INCLUDE_ASM("asm/nonmatchings", sub_803A478);
INCLUDE_ASM("asm/nonmatchings", sub_803A8D0);
INCLUDE_ASM("asm/nonmatchings", sub_803AF60);
INCLUDE_ASM("asm/nonmatchings", sub_803B484);
INCLUDE_ASM("asm/nonmatchings", sub_803BBEC);
INCLUDE_ASM("asm/nonmatchings", sub_803C328);
INCLUDE_ASM("asm/nonmatchings", sub_803CE0C);
INCLUDE_ASM("asm/nonmatchings", sub_803D20C);
INCLUDE_ASM("asm/nonmatchings", sub_803D60C);
INCLUDE_ASM("asm/nonmatchings", sub_803DECC);
INCLUDE_ASM("asm/nonmatchings", sub_803E58C);
INCLUDE_ASM("asm/nonmatchings", sub_803ED34);
INCLUDE_ASM("asm/nonmatchings", sub_803F21C);
INCLUDE_ASM("asm/nonmatchings", sub_803F328);
INCLUDE_ASM("asm/nonmatchings", sub_803F444);
INCLUDE_ASM("asm/nonmatchings", sub_803F5B4);
INCLUDE_ASM("asm/nonmatchings", sub_803F658);
INCLUDE_ASM("asm/nonmatchings", sub_803FF54);
INCLUDE_ASM("asm/nonmatchings", sub_80401AC);
INCLUDE_ASM("asm/nonmatchings", sub_80405A4);
INCLUDE_ASM("asm/nonmatchings", sub_8040690);
INCLUDE_ASM("asm/nonmatchings", sub_8040EE8);
INCLUDE_ASM("asm/nonmatchings", sub_8041308);
INCLUDE_ASM("asm/nonmatchings", sub_80416F0);
INCLUDE_ASM("asm/nonmatchings", sub_80419E0);
INCLUDE_ASM("asm/nonmatchings", sub_8041EDC);
INCLUDE_ASM("asm/nonmatchings", sub_8042200);
INCLUDE_ASM("asm/nonmatchings", sub_80422B8);
INCLUDE_ASM("asm/nonmatchings", sub_8042784);
INCLUDE_ASM("asm/nonmatchings", sub_8042AB4);
INCLUDE_ASM("asm/nonmatchings", sub_8042B90);
INCLUDE_ASM("asm/nonmatchings", sub_8042E70);
INCLUDE_ASM("asm/nonmatchings", sub_8043554);
INCLUDE_ASM("asm/nonmatchings", sub_8043938);
INCLUDE_ASM("asm/nonmatchings", sub_8043B5C);
INCLUDE_ASM("asm/nonmatchings", sub_8043F90);
INCLUDE_ASM("asm/nonmatchings", sub_8044394);
void sub_8044414(void)
{
    gUnk_03000889 = 0;
}
u16 sub_8044420(void)
{
    return gUnk_03000882;
}
INCLUDE_ASM("asm/nonmatchings", sub_804442C);
void sub_804448C(void)
{
    gUnk_03000865 = 0;
}
u8 sub_8044498(void)
{
    return gUnk_03000865;
}
INCLUDE_ASM("asm/nonmatchings", sub_80444A4);
INCLUDE_ASM("asm/nonmatchings", sub_80444E8);
INCLUDE_ASM("asm/nonmatchings", sub_8044514);
INCLUDE_ASM("asm/nonmatchings", sub_8044574);
u8* sub_80445E0() {
    return gUnk_03004F90;
}
INCLUDE_ASM("asm/nonmatchings", sub_80445E8);
INCLUDE_ASM("asm/nonmatchings", sub_8044680);
INCLUDE_ASM("asm/nonmatchings", sub_80446A4);
INCLUDE_ASM("asm/nonmatchings", sub_80446BC);
s32 sub_8044728() {
    return 2;
}
s32 sub_804472C() {
    return 0;
}
s32 sub_8044730() {
    return 0;
}
s32 sub_8044734() {
    return 0;
}
s32 sub_8044738() {
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_804473C);
INCLUDE_ASM("asm/nonmatchings", sub_80448A8);
INCLUDE_ASM("asm/nonmatchings", sub_8044A40);
INCLUDE_ASM("asm/nonmatchings", sub_8044F4C);
INCLUDE_ASM("asm/nonmatchings", sub_8045098);
INCLUDE_ASM("asm/nonmatchings", sub_804519C);
INCLUDE_ASM("asm/nonmatchings", sub_8045328);
INCLUDE_ASM("asm/nonmatchings", sub_80453D8);
INCLUDE_ASM("asm/nonmatchings", sub_804542C);
INCLUDE_ASM("asm/nonmatchings", sub_80454A4);
INCLUDE_ASM("asm/nonmatchings", sub_80455A0);
INCLUDE_ASM("asm/nonmatchings", sub_8045688);
INCLUDE_ASM("asm/nonmatchings", sub_80457AC);
INCLUDE_ASM("asm/nonmatchings", sub_8045860);
INCLUDE_ASM("asm/nonmatchings", sub_8045940);
INCLUDE_ASM("asm/nonmatchings", sub_8045A10);
INCLUDE_ASM("asm/nonmatchings", sub_8045A74);
INCLUDE_ASM("asm/nonmatchings", sub_8045B90);
INCLUDE_ASM("asm/nonmatchings", sub_8045BF4);
INCLUDE_ASM("asm/nonmatchings", sub_8045D00);
INCLUDE_ASM("asm/nonmatchings", sub_8045EB8);
INCLUDE_ASM("asm/nonmatchings", sub_8045F10);
INCLUDE_ASM("asm/nonmatchings", sub_8045F94);
INCLUDE_ASM("asm/nonmatchings", sub_8046060);
INCLUDE_ASM("asm/nonmatchings", sub_804612C);
INCLUDE_ASM("asm/nonmatchings", sub_804621C);
INCLUDE_ASM("asm/nonmatchings", sub_80462E4);
INCLUDE_ASM("asm/nonmatchings", sub_8046480);
INCLUDE_ASM("asm/nonmatchings", sub_8046558);
INCLUDE_ASM("asm/nonmatchings", sub_804666C);
INCLUDE_ASM("asm/nonmatchings", sub_80466F0);
INCLUDE_ASM("asm/nonmatchings", sub_8046C50);
INCLUDE_ASM("asm/nonmatchings", sub_8046CD4);
INCLUDE_ASM("asm/nonmatchings", sub_8046E18);
INCLUDE_ASM("asm/nonmatchings", sub_8046F0C);
INCLUDE_ASM("asm/nonmatchings", sub_8047024);
INCLUDE_ASM("asm/nonmatchings", sub_80471AC);
INCLUDE_ASM("asm/nonmatchings", sub_80472E8);
INCLUDE_ASM("asm/nonmatchings", sub_804753C);
INCLUDE_ASM("asm/nonmatchings", sub_80476DC);
INCLUDE_ASM("asm/nonmatchings", sub_8047B1C);
INCLUDE_ASM("asm/nonmatchings", sub_8047D28);
INCLUDE_ASM("asm/nonmatchings", sub_8047DC8);
INCLUDE_ASM("asm/nonmatchings", sub_8047FCC);
INCLUDE_ASM("asm/nonmatchings", sub_80480EC);
INCLUDE_ASM("asm/nonmatchings", sub_80481B8);
INCLUDE_ASM("asm/nonmatchings", sub_8048310);
INCLUDE_ASM("asm/nonmatchings", sub_8048458);
INCLUDE_ASM("asm/nonmatchings", sub_80485A4);
INCLUDE_ASM("asm/nonmatchings", sub_8048690);
INCLUDE_ASM("asm/nonmatchings", sub_8048764);
INCLUDE_ASM("asm/nonmatchings", sub_804877C);
INCLUDE_ASM("asm/nonmatchings", sub_80487A4);
INCLUDE_ASM("asm/nonmatchings", sub_80487CC);
INCLUDE_ASM("asm/nonmatchings", sub_8048818);
INCLUDE_ASM("asm/nonmatchings", sub_8048868);
INCLUDE_ASM("asm/nonmatchings", sub_80488CC);
INCLUDE_ASM("asm/nonmatchings", sub_8048934);
INCLUDE_ASM("asm/nonmatchings", sub_8048984);
INCLUDE_ASM("asm/nonmatchings", sub_80489A4);
INCLUDE_ASM("asm/nonmatchings", sub_80489C8);
INCLUDE_ASM("asm/nonmatchings", sub_80489E8);
INCLUDE_ASM("asm/nonmatchings", sub_8048A68);
INCLUDE_ASM("asm/nonmatchings", sub_8048A88);
INCLUDE_ASM("asm/nonmatchings", sub_8048ACC);
void sub_8048B30(u8 param1, u8 param2, u16 param3)
{
    gUnk_030008F1 = 0;
    gUnk_030008F2 = param1;
    gUnk_030008F3 = param2;
    gUnk_03000906 = param3;
}
INCLUDE_ASM("asm/nonmatchings", sub_8048B5C);
INCLUDE_ASM("asm/nonmatchings", sub_8048B88);
INCLUDE_ASM("asm/nonmatchings", sub_8048BAC);
INCLUDE_ASM("asm/nonmatchings", sub_8048BD0);
INCLUDE_ASM("asm/nonmatchings", sub_8048C30);
INCLUDE_ASM("asm/nonmatchings", sub_8048C80);
INCLUDE_ASM("asm/nonmatchings", sub_8048CEC);
INCLUDE_ASM("asm/nonmatchings", sub_8048D40);
INCLUDE_ASM("asm/nonmatchings", sub_8048D64);
INCLUDE_ASM("asm/nonmatchings", sub_8048D84);
INCLUDE_ASM("asm/nonmatchings", sub_8048DA4);
INCLUDE_ASM("asm/nonmatchings", sub_8048F0C);
INCLUDE_ASM("asm/nonmatchings", sub_8048FB8);
INCLUDE_ASM("asm/nonmatchings", sub_80492C0);
INCLUDE_ASM("asm/nonmatchings", sub_80494F0);
INCLUDE_ASM("asm/nonmatchings", sub_80497B0);
INCLUDE_ASM("asm/nonmatchings", sub_80498E0);
INCLUDE_ASM("asm/nonmatchings", sub_8049958);
INCLUDE_ASM("asm/nonmatchings", sub_8049AD8);
INCLUDE_ASM("asm/nonmatchings", sub_8049B70);
INCLUDE_ASM("asm/nonmatchings", sub_8049C1C);
INCLUDE_ASM("asm/nonmatchings", sub_8049D58);
INCLUDE_ASM("asm/nonmatchings", sub_8049DF8);
INCLUDE_ASM("asm/nonmatchings", sub_804A148);
INCLUDE_ASM("asm/nonmatchings", sub_804A368);
INCLUDE_ASM("asm/nonmatchings", sub_804AA2C);
INCLUDE_ASM("asm/nonmatchings", sub_804AB10);
INCLUDE_ASM("asm/nonmatchings", sub_804AB40);
INCLUDE_ASM("asm/nonmatchings", sub_804ABD0);
INCLUDE_ASM("asm/nonmatchings", sub_804ABF8);
INCLUDE_ASM("asm/nonmatchings", sub_804AC60);
INCLUDE_ASM("asm/nonmatchings", sub_804ACC0);
INCLUDE_ASM("asm/nonmatchings", sub_804AD24);
void sub_804AD54(u16* ptr)
{
    *(ptr + 0x5B) = 0xB000;
}
INCLUDE_ASM("asm/nonmatchings", sub_804AD60);
void sub_804ADE0(void)
{
    gUnk_03000910 = 0;
    gUnk_03000948 = 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_804ADF8);
INCLUDE_ASM("asm/nonmatchings", sub_804AE2C);
INCLUDE_ASM("asm/nonmatchings", sub_804AF60);
INCLUDE_ASM("asm/nonmatchings", sub_804B080);
void sub_804B1EC(void)
{
    gUnk_03000ADE = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_804B1F8);
INCLUDE_ASM("asm/nonmatchings", sub_804B224);
INCLUDE_ASM("asm/nonmatchings", sub_804B288);
INCLUDE_ASM("asm/nonmatchings", sub_804B3C0);
INCLUDE_ASM("asm/nonmatchings", sub_804B458);
INCLUDE_ASM("asm/nonmatchings", sub_804B4D0);
INCLUDE_ASM("asm/nonmatchings", sub_804B56C);
INCLUDE_ASM("asm/nonmatchings", sub_804B654);
INCLUDE_ASM("asm/nonmatchings", sub_804B7B0);
INCLUDE_ASM("asm/nonmatchings", sub_804B834);
INCLUDE_ASM("asm/nonmatchings", sub_804B8E8);
INCLUDE_ASM("asm/nonmatchings", sub_804B96C);
INCLUDE_ASM("asm/nonmatchings", sub_804BB64);
INCLUDE_ASM("asm/nonmatchings", sub_804BBDC);
INCLUDE_ASM("asm/nonmatchings", sub_804BD54);
INCLUDE_ASM("asm/nonmatchings", sub_804BDD8);
INCLUDE_ASM("asm/nonmatchings", sub_804BE90);
INCLUDE_ASM("asm/nonmatchings", sub_804BF14);
INCLUDE_ASM("asm/nonmatchings", sub_804C10C);
void sub_804C184(void) {
    sub_804C45C();
    sub_804C6B0();
}
INCLUDE_ASM("asm/nonmatchings", sub_804C194);
INCLUDE_ASM("asm/nonmatchings", sub_804C1B4);
INCLUDE_ASM("asm/nonmatchings", sub_804C1E4);
INCLUDE_ASM("asm/nonmatchings", sub_804C214);
INCLUDE_ASM("asm/nonmatchings", sub_804C250);
INCLUDE_ASM("asm/nonmatchings", sub_804C278);
INCLUDE_ASM("asm/nonmatchings", sub_804C2A0);
u16 sub_804C2F0(void) {
    return gUnk_03000AE0;

}
INCLUDE_ASM("asm/nonmatchings", sub_804C2FC);
INCLUDE_ASM("asm/nonmatchings", sub_804C364);
INCLUDE_ASM("asm/nonmatchings", sub_804C3A4);
INCLUDE_ASM("asm/nonmatchings", sub_804C3E4);
INCLUDE_ASM("asm/nonmatchings", sub_804C420);
INCLUDE_ASM("asm/nonmatchings", sub_804C45C);
INCLUDE_ASM("asm/nonmatchings", sub_804C4D8);
u16 sub_804C53C(void) {
    return gUnk_03000AE2;
}
INCLUDE_ASM("asm/nonmatchings", sub_804C548);
INCLUDE_ASM("asm/nonmatchings", sub_804C5B8);
INCLUDE_ASM("asm/nonmatchings", sub_804C5F8);
INCLUDE_ASM("asm/nonmatchings", sub_804C638);
INCLUDE_ASM("asm/nonmatchings", sub_804C674);
INCLUDE_ASM("asm/nonmatchings", sub_804C6B0);
INCLUDE_ASM("asm/nonmatchings", sub_804C728);
INCLUDE_ASM("asm/nonmatchings", sub_804C78C);
INCLUDE_ASM("asm/nonmatchings", sub_804C890);
INCLUDE_ASM("asm/nonmatchings", sub_804C8E0);
INCLUDE_ASM("asm/nonmatchings", sub_804C9B4);
INCLUDE_ASM("asm/nonmatchings", sub_804CA2C);
INCLUDE_ASM("asm/nonmatchings", sub_804CAA0);
INCLUDE_ASM("asm/nonmatchings", sub_804CB18);
INCLUDE_ASM("asm/nonmatchings", sub_804CB8C);
INCLUDE_ASM("asm/nonmatchings", sub_804CC00);
INCLUDE_ASM("asm/nonmatchings", sub_804CC78);
INCLUDE_ASM("asm/nonmatchings", sub_804CCEC);
INCLUDE_ASM("asm/nonmatchings", sub_804CD60);
INCLUDE_ASM("asm/nonmatchings", sub_804CDD4);
INCLUDE_ASM("asm/nonmatchings", sub_804CE48);
INCLUDE_ASM("asm/nonmatchings", sub_804CEBC);
INCLUDE_ASM("asm/nonmatchings", sub_804CEE0);
INCLUDE_ASM("asm/nonmatchings", sub_804D0F8);
INCLUDE_ASM("asm/nonmatchings", sub_804D1B4);
INCLUDE_ASM("asm/nonmatchings", sub_804D260);
INCLUDE_ASM("asm/nonmatchings", sub_804D310);
INCLUDE_ASM("asm/nonmatchings", sub_804D3A0);
INCLUDE_ASM("asm/nonmatchings", sub_804D44C);
INCLUDE_ASM("asm/nonmatchings", sub_804D4FC);
INCLUDE_ASM("asm/nonmatchings", sub_804D5B4);
INCLUDE_ASM("asm/nonmatchings", sub_804D708);
INCLUDE_ASM("asm/nonmatchings", sub_804D798);
INCLUDE_ASM("asm/nonmatchings", sub_804D840);
INCLUDE_ASM("asm/nonmatchings", sub_804D8F4);
INCLUDE_ASM("asm/nonmatchings", sub_804DA04);
INCLUDE_ASM("asm/nonmatchings", sub_804DABC);
INCLUDE_ASM("asm/nonmatchings", sub_804DB64);
INCLUDE_ASM("asm/nonmatchings", sub_804DC24);
INCLUDE_ASM("asm/nonmatchings", sub_804DCD8);
INCLUDE_ASM("asm/nonmatchings", sub_804DD70);
INCLUDE_ASM("asm/nonmatchings", sub_804DD90);
INCLUDE_ASM("asm/nonmatchings", sub_804DE20);
INCLUDE_ASM("asm/nonmatchings", sub_804DE8C);
INCLUDE_ASM("asm/nonmatchings", sub_804DF14);
INCLUDE_ASM("asm/nonmatchings", sub_804DF74);
INCLUDE_ASM("asm/nonmatchings", sub_804DFD8);
INCLUDE_ASM("asm/nonmatchings", sub_804E0E4);
INCLUDE_ASM("asm/nonmatchings", sub_804E2AC);
INCLUDE_ASM("asm/nonmatchings", sub_804E6DC);
INCLUDE_ASM("asm/nonmatchings", sub_804E76C);
INCLUDE_ASM("asm/nonmatchings", sub_804E7EC);
INCLUDE_ASM("asm/nonmatchings", sub_804E85C);
INCLUDE_ASM("asm/nonmatchings", sub_804E9DC);
INCLUDE_ASM("asm/nonmatchings", sub_804EC04);
INCLUDE_ASM("asm/nonmatchings", sub_804EEC4);
INCLUDE_ASM("asm/nonmatchings", sub_804EF00);
INCLUDE_ASM("asm/nonmatchings", sub_804EF50);
INCLUDE_ASM("asm/nonmatchings", sub_804EF90);
INCLUDE_ASM("asm/nonmatchings", sub_804EFDC);
INCLUDE_ASM("asm/nonmatchings", sub_804F050);
void sub_804F07C(void) {
    gUnk_03000DDE = 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_804F088);
INCLUDE_ASM("asm/nonmatchings", sub_804F0B8);
INCLUDE_ASM("asm/nonmatchings", sub_804F10C);
INCLUDE_ASM("asm/nonmatchings", sub_804F17C);
INCLUDE_ASM("asm/nonmatchings", sub_804F210);
u8 sub_804F244() {
    return gUnk_03000E04;
}
INCLUDE_ASM("asm/nonmatchings", sub_804F250);
INCLUDE_ASM("asm/nonmatchings", sub_804F280);
INCLUDE_ASM("asm/nonmatchings", sub_804F64C);
INCLUDE_ASM("asm/nonmatchings", sub_804F768);
INCLUDE_ASM("asm/nonmatchings", sub_804F7F8);
INCLUDE_ASM("asm/nonmatchings", sub_804F8D8);
INCLUDE_ASM("asm/nonmatchings", sub_804F974);
INCLUDE_ASM("asm/nonmatchings", sub_804FA04);
INCLUDE_ASM("asm/nonmatchings", sub_804FA94);
INCLUDE_ASM("asm/nonmatchings", sub_804FB24);
INCLUDE_ASM("asm/nonmatchings", sub_8050014);
INCLUDE_ASM("asm/nonmatchings", sub_805008C);
INCLUDE_ASM("asm/nonmatchings", sub_80501B8);
INCLUDE_ASM("asm/nonmatchings", sub_8050434);
INCLUDE_ASM("asm/nonmatchings", sub_805063C);
INCLUDE_ASM("asm/nonmatchings", sub_8050720);
INCLUDE_ASM("asm/nonmatchings", sub_80511A0);
INCLUDE_ASM("asm/nonmatchings", sub_8051230);
INCLUDE_ASM("asm/nonmatchings", sub_80512C4);
INCLUDE_ASM("asm/nonmatchings", sub_80513A0);
INCLUDE_ASM("asm/nonmatchings", sub_805144C);
INCLUDE_ASM("asm/nonmatchings", sub_8051A1C);
INCLUDE_ASM("asm/nonmatchings", sub_8051AEC);
INCLUDE_ASM("asm/nonmatchings", sub_8051BE4);

u16 sub_8052574(void) {
    return gUnk_03000E70;
}

INCLUDE_ASM("asm/nonmatchings", sub_8052580);
INCLUDE_ASM("asm/nonmatchings", sub_80525E8);
INCLUDE_ASM("asm/nonmatchings", sub_80526A0);
INCLUDE_ASM("asm/nonmatchings", sub_8052728);
INCLUDE_ASM("asm/nonmatchings", sub_8052758);
INCLUDE_ASM("asm/nonmatchings", sub_8052780);
INCLUDE_ASM("asm/nonmatchings", sub_80527AC);
u16 sub_80527F4(u32* arg0) {
    *arg0 = 0x03000EE8;
    return *(u16* )0x03000F24;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052808);
INCLUDE_ASM("asm/nonmatchings", sub_8052858);
INCLUDE_ASM("asm/nonmatchings", sub_8052878);
void nullsub_7(){}
INCLUDE_ASM("asm/nonmatchings", sub_80528C8);
INCLUDE_ASM("asm/nonmatchings", sub_805291C);
INCLUDE_ASM("asm/nonmatchings", sub_80529B8);
INCLUDE_ASM("asm/nonmatchings", sub_8052A14);

u32 sub_8052A38(u32* ptr)
{
    sub_8053688();
    (*ptr)++;
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052A50);
u32 sub_8052A70(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_80536C0(param);
    
    
    *ptr += 2;
    
    return 0;
}u32 sub_8052A8C(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_80536EC(param);
    
    
    *ptr += 2;
    
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052AA8);
u32 sub_8052ACC(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_8053838(param);
    
    
    *ptr += 2;
    
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052AE8);
INCLUDE_ASM("asm/nonmatchings", sub_8052B34);
INCLUDE_ASM("asm/nonmatchings", sub_8052B80);
INCLUDE_ASM("asm/nonmatchings", sub_8052BA0);
INCLUDE_ASM("asm/nonmatchings", sub_8052BE0);
INCLUDE_ASM("asm/nonmatchings", sub_8052C04);
INCLUDE_ASM("asm/nonmatchings", sub_8052C24);
INCLUDE_ASM("asm/nonmatchings", sub_8052C90);
INCLUDE_ASM("asm/nonmatchings", sub_8052CD0);
INCLUDE_ASM("asm/nonmatchings", sub_8052CF0);
INCLUDE_ASM("asm/nonmatchings", sub_8052D4C);
INCLUDE_ASM("asm/nonmatchings", sub_8052D8C);
INCLUDE_ASM("asm/nonmatchings", sub_8052DAC);
INCLUDE_ASM("asm/nonmatchings", sub_8052DCC);
INCLUDE_ASM("asm/nonmatchings", sub_8052E0C);
INCLUDE_ASM("asm/nonmatchings", sub_8052E2C);
u32 sub_8052E4C(u32* ptr)
{

    gUnk_03004854 = 1;
    gUnk_030047B4 = 0;
    (*ptr)++;
    return 1;
}s32 sub_8052E6C(u32* ptr)
{

    gUnk_03004854 = 0;
    (*ptr)++;
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8052E80);
INCLUDE_ASM("asm/nonmatchings", sub_8052E9C);
INCLUDE_ASM("asm/nonmatchings", sub_8052EC0);
INCLUDE_ASM("asm/nonmatchings", sub_8052F20);
INCLUDE_ASM("asm/nonmatchings", sub_8052F44);
u32 sub_8052FAC(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param1 = data[1];
    u8 param2 = data[2];
    
    
    sub_8008BA4(param1, param2);
    
    
    *ptr += 3;
    
    return 1;
}

u32 sub_8052FC8(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_8008BFC(param);
    
    
    *ptr += 2;
    
    return 1;
}
u32 sub_8052FE4(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_8008BE4(param);
    
    
    *ptr += 2;
    
    return 1;
}

u32 sub_8053000(u32* arg0) {
    u8* data = (u8*)*arg0;

    if(!sub_8008C14(data[1]))
    {
        *arg0 += 2;
        return 1;
    }

   return 0;
}
u32 sub_8053024(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param1 = data[1];
    u8 param2 = data[2];
    
    
    sub_8009AC4(param1, param2);
    
    
    *ptr += 3;
    
    return 1;
}
u32 sub_8053040(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_8009B04(param);
    
    
    *ptr += 2;
    
    return 1;
}

u32 sub_805305C(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_8009B1C(param);
    
    
    *ptr += 2;
    
    return 1;
}

u32 sub_8053078(u32* arg0) {
    u8* data = (u8*)*arg0;

    if(!sub_8009B34(data[1]))
    {
        *arg0 += 2;
        return 1;
    }

   return 0;
}

u32 sub_805309C(u32* ptr)
{
    sub_800A980();
    (*ptr)++;
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_80530B4);
INCLUDE_ASM("asm/nonmatchings", sub_80530D4);
INCLUDE_ASM("asm/nonmatchings", sub_8053104);
INCLUDE_ASM("asm/nonmatchings", sub_8053138);
u32 sub_805316C(u32* ptr)
{
    // 读取外部变量的值作为参数
    u8 param = gUnk_03004860;
    
    
    sub_800908C(param);
    
    // 递增指针指向的值
    (*ptr)++;
    
    return 0;
}
u32 sub_805318C(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_8015FB4(param);
    
    
    *ptr += 2;
    
    return 0;
}
INCLUDE_ASM("asm/nonmatchings", sub_80531A8);
u32 sub_80531E4(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    
    u8 param = data[1];
    
    
    sub_80140D0(param);
    
    
    *ptr += 2;
    
    return 1;
}
u32 sub_8053200(u32* ptr)
{
    u8* data = (u8*)*ptr;
    
    u8 param = data[1];
    
    sub_8014124(param);
    
    *ptr += 2;
    
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_805321C);
u32 sub_8053254(u32* ptr)
{
    
    u8* data = (u8*)*ptr;
    
    u8 param = data[1];
    
    sub_8015F74(param);
    
    *ptr += 2;
    
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8053270);
INCLUDE_ASM("asm/nonmatchings", sub_80532DC);
u32 sub_8053348(u32* ptr)
{

    sub_800110C();
    (*ptr)++;
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_8053360);
u32 sub_80533A0(u32* ptr)
{

    gUnk_03002604 = 1;
    (*ptr)++;
    return 0;
}
u32 sub_80533B4(u32* arg0) {
    if (gUnk_03002604 == 0) {
        *arg0 += 1;
        return 1;
    }
    return 0;
}
u32 sub_80533D4(u32* ptr)
{
    u8* data = (u8*)*ptr;
    
    u8 param1 = data[1];
    u8 param2 = data[2];
    
    sub_800A3C8(param1, param2);
    
    *ptr += 3;
    
    return 1;
}
INCLUDE_ASM("asm/nonmatchings", sub_80533F0);


INCLUDE_ASM("asm/nonmatchings", sub_80534B4);

void sub_805359C() {
    m4aSoundInit();
    gUnk_03000F38 = 0;
    gUnk_03000F3A = 0;
    gUnk_03000F3C = 0x100;
    gUnk_03000F40 = 0;
    gUnk_03000F42 = 0;
    gUnk_03000F43 = 0;
    gUnk_03000F50 = 0;
}

u16 sub_80535E8(void) {
    return gUnk_03000F38;
}

void sub_80535F4(void) {
    m4aSoundVSyncOff();
    gUnk_03000F38 |= 1;
}

void sub_805360C(void) {
    m4aSoundVSyncOn();
    gUnk_03000F38 &= 0xFFFE;
}

void sub_8053628(u8 arg0, u16 arg1) {
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
    m4aMPlayImmInit((struct MusicPlayerInfo* )0x03005AB0);
    sub_805369C(arg1);
}


void sub_8053688(void) {
    m4aSongNumStop(gUnk_03000F3A);
}

void sub_805369C(u16 volume) {

    if (volume < 2) 
    {
        volume = 2;
    }
    *(u16* )0x03000F3C = volume;
    m4aMPlayVolumeControl((struct MusicPlayerInfo* )0x03005AB0, 0xFF, volume);
}

void sub_80536C0(u8 arg0) {
    gUnk_03000F3E = 0;
    gUnk_03000F40 = arg0;
    gUnk_03000F41 = 0;
    gUnk_03000F38 |= 2;
}

void sub_80536EC(u8 arg0) {
    gUnk_03000F3E = gUnk_03000F3C;
    gUnk_03000F40 = arg0;
    gUnk_03000F41 = 0;
    gUnk_03000F38 |= 4;
}

void sub_8053720(void) {
    m4aSongNumContinue(gUnk_03000F3A);
}

u8 sub_8053734(u8 arg0) {
    return (gUnk_03000F42 >> arg0) & 1;
}

INCLUDE_ASM("asm/nonmatchings", sub_805374C);
INCLUDE_ASM("asm/nonmatchings", sub_80537C0);
INCLUDE_ASM("asm/nonmatchings", sub_8053838); //Matched

s32 sub_8053884(u8 arg0) {
    return (gUnk_03000F43 >> arg0) & 1;
}


