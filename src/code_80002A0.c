#include "main.h"




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


    DmaCopy16(3, &gUnk_030035C0, 0x07000000, 0x400);

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



void sub_80005A8(u16 arg0) 
{
    switch (gUnk_03004610)
    {   
        case 1:
        case 2:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + arg0) & 0xFF] + (gUnk_030025B4 & 0x1F);
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + arg0) & 0xFF] + (gUnk_030025FC & 0x1F);
            break;

        case 3:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + arg0) & 0xFF];
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + arg0) & 0xFF]; 
            break;

        case 4:
            REG_BG1HOFS = gUnk_03001B60[(gUnk_03001B54 + arg0) & 0xFF];
            REG_BG1VOFS = gUnk_030019C0[(gUnk_03001B54 + arg0) & 0xFF]; 
            break;
    }
}

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
    
    if (gUnk_03001948 <= 0x0CDFD7EE) 
    {
        gUnk_03001948++;
    } 
    else 
    {
        gUnk_03001948 = 0x0CDFD7F0;
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
    REG_DISPCNT |= 0x80;
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

    gUnk_03001948 = 0;
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
        gUnk_030035C0[i].all.unk0 = 0;
        gUnk_030035C0[i].all.unk4 = 0;
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
    s8 mul1, mul2;
    s8 div1, div2;
    
    mask = 0x7F;
    switch (arg0)
    {
        case 1:
            div1 = 12;
            mul1 = 32;
            div2 = 12;
            mul2 = 16;
            break;
        case 2:
            div1 = 16;
            mul1 = 8;
            div2 = 4;
            mul2 = 16;
            mask = 0x3F;
            break;
        case 3:
            div1 = 16;
            mul1 = 32;
            div2 = 32;
            mul2 = 4;
            break;
        case 4:
            div1 = 4;
            mul1 = 1;
            div2 = 16;  
            mul2 = 1;
            mask = 0x3F;
            break;
        default:
            return;
    }
    
    for (i = 0; i < 255; i++)
    {
        gUnk_03001B60[i] = gUnk_080576D0[ (i * mul1) & mask] / div1;
        gUnk_030019C0[i] = gUnk_080576D0[ (i * mul2) & mask] / div2;
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
    REG_DISPCNT = 0x37C0;
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


// void sub_800128C(void) {
//     gUnk_03001AC0 = 0;
//     sub_8001128();

//     while(1)
//     {
//         gGameFuncTable[gUnk_03001AC0]();
//         VBlankIntrWait();
//         sub_80533F0();  
//     }
// }