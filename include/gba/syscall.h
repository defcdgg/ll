/********************************************************************/
/*          AgbSystemCall.h                                         */
/*            AGB System Call                                       */
/*                                                                  */
/*          Copyright (C) 1999-2001 NINTENDO Co.,Ltd.               */
/********************************************************************/
#ifndef _AGB_SYSTEM_CALL_H
#define _AGB_SYSTEM_CALL_H

#include "types.h"

#define CPU_SET_SRC_FIXED 0x01000000
#define CPU_SET_16BIT     0x00000000
#define CPU_SET_32BIT     0x04000000

/*------------------------------------------------------------------*/
/*                   System Call No.                             */
/*------------------------------------------------------------------*/

#define SWI_NO_RESTART                  0       // SoftReset()
#define SWI_NO_REGISTER_RAM_RESET       1       // SoftReset()/RegisterRamReset()
#define SWI_NO_HALT                     2       // Halt()
#define SWI_NO_STOP                     3       // Stop()

#define SWI_NO_INTR_WAIT                4       // IntrWait()
#define SWI_NO_VBLANK_INTR_WAIT         5       // VBlankIntrWait()

#define SWI_NO_DIV                      6       // Div()/DivRem()
#define SWI_NO_DIV_ARM                  7       // DivArm()/DivRemArm()
#define SWI_NO_SQRT                     8       // Sqrt()
#define SWI_NO_ARCTAN                   9       // ArcTan()
#define SWI_NO_ARCTAN2                  10      // ArcTan2()

#define SWI_NO_CPU_SET                  11      // CpuSet()
#define SWI_NO_CPU_FAST_SET             12      // CpuFastSet()
#define SWI_NO_BG_AFFINE_SET            14      // BgAffineSet()
#define SWI_NO_OBJ_AFFINE_SET           15      // ObjAffineSet()
#define SWI_NO_BIT_UNPACK               16      // BitUnPack()
#define SWI_NO_LZ77_UNCOMP_WRAM         17      // LZ77UnCompWram()
#define SWI_NO_LZ77_UNCOMP_VRAM         18      // LZ77UnCompVram()
#define SWI_NO_HUFF_UNCOMP              19      // HuffUnComp()
#define SWI_NO_RL_UNCOMP_WRAM           20      // RLUnCompWram()
#define SWI_NO_RL_UNCOMP_VRAM           21      // RLUnCompVram()
#define SWI_NO_DIFF_8BIT_UNFILTER_WRAM  22      // Diff8bitUnFilterWram()
#define SWI_NO_DIFF_8BIT_UNFILTER_VRAM  23      // Diff8bitUnFilterVram()
#define SWI_NO_DIFF_16BIT_UNFILTER      24      // Diff16bitUnFilter()

#define SWI_NO_SOUND_BIAS_CHANGE        25      // SoundBiasSet()/SoundBiasReset()
#define SWI_NO_SOUND_DRIVER_INIT        26      // SoundDriverInit()
#define SWI_NO_SOUND_DRIVER_MODE        27      // SoundDriverMode()
#define SWI_NO_SOUND_DRIVER_MAIN        28      // SoundDriverMain()
#define SWI_NO_SOUND_DRIVER_VSYNC       29      // SoundDriverVSync()
#define SWI_NO_SOUND_DRIVER_VSYNC_OFF   40      // SoundDriverVSyncOff()
#define SWI_NO_SOUND_DRIVER_VSYNC_ON    41      // SoundDriverVSyncOn()
#define SWI_NO_SOUND_CHANNEL_CLEAR      30      // SoundChannelClear()
#define SWI_NO_MIDI_KEY_2_FREQ          31      // MidiKey2Freq()

#define SWI_NO_MULTI_BOOT               37      // MultiBoot()



/*------------------------------------------------------------------*/
/*               Register & RAM Reset                               */
/*------------------------------------------------------------------*/

extern void RegisterRamReset(u32 ResetFlags);

// Reset the register and RAM that are specified in ResetFlags.
// However, do not clear the area 0x3007e00~0x3007fff of CPU internal RAM.
//
// Arguments:
//    u32 ResetFlags      Specify register and RAM that are to be reset 
//                        (Refer to AgbDefine.h).



extern void IntrWait(u8 InitCheckClear, u16 IntrFlags);

// Continue to wait in Halt status until interrupt specified in IntrFlags is 
// generated.
// Set the flag that corresponds to INTR_CHECK_BUF(0x3007ff8) using an interrupt// process.
// Overhead to call for system call can be reduced by using multiple 
// interrupts at the same time when compared with the case where Halt() 
// is called back repeatedly.
//
// Arguments:
//    u8  InitCheckClear  Specify whether or not to clear when 
//                        applicable flag has already been set.
//    u16 IntrFlags       Specify wait interrupt (refer to AgbDefine.h)

/*------------------------------------------------------------------*/
/*                    V Blank Interrupt Wait                        */
/*------------------------------------------------------------------*/

extern void VBlankIntrWait(void);

// Continue to wait in Halt status until V blank interrupt occurs.
// Set flag that corresonds to INTR_CHECK_BUF(0x3007ff8) in interrupt process.
// Overhead to call for system call can be reduced by using multiple interrupts at
// the same time when compared to the case where Halt() is called back repeatedly.
// It is equivalent to IntrWait(1, V_BLANK_INTR_FLAG).



/*------------------------------------------------------------------*/
/*                        Set CPU                                   */
/*------------------------------------------------------------------*/

extern void CpuSet(void *Srcp, void *Destp, u32 DmaCntData);

// Clear or copy RAM with a parameter which is compatible with DmaSet macro.
//* At 32-bit transfer, RAM is accessed forcefully by 4 byte boundary, and 
// at 16-bit transfer, arguments need to be set by 2 byte boundary 
// to access RAM. 
//
// Arguments:
//    void *Srcp          Source Address
//    void *Destp         Destination Address
//    u32 DmaCntData      Only DMA_SRC_FIX/DMA_32BIT_BUS/DMA_COUNT_MASK is valid
//          DMA_SRC_FIX(  0, 1) = (Source Address Increment, Source Address Fixed)
//          DMA_32BIT_BUS(0, 1) = (16bit Transfer, 32bit Transfer)
//          DMA_COUNT_MASK & DmaCntData = Transfer Count
//
// Upper Macro:
//  CpuClear, CpuArrayClear, CpuCopy, CpuArrayCopy

/*------------------------------------------------------------------*/
/*                   High Speed Set CPU                             */
/*------------------------------------------------------------------*/

extern void CpuFastSet(void *Srcp, void *Destp, u32 DmaCntData);

// Clear or copy RAM in high speed with a parameter which is compatible with 
// the DmaSet macro.
//* However, it is a 32-bit transfer by 32 bytes (8 words).
//* Even if arguments other than 4 byte boundary are given, RAM is 
// accessed by 4 byte boundary forcefully.
//
// Arguments:
//    void *Srcp          Source Address
//    void *Destp         Destination Address
//    u32 DmaCntData      Only DMA_SRC_FIX/DMA_COUNT_MASK is valid
//          DMA_SRC_FIX(0, 1) = (Source Address Increment, Source Address Fixed)
//          DMA_COUNT_MASK & DmaCntData = Transfer Count
//
// Upper Macro:
//  CpuFastClear, CpuFastArrayClear, CpuFastCopy, CpuFastArrayCopy

/*------------------------------------------------------------------*/
/*                   Set BG Affine Transformation                   */
/*------------------------------------------------------------------*/

extern void BgAffineSet(BgAffineSrcData *Srcp, BgAffineDestData *Destp, s32 Num);

// Calculate and set the BG affine parameter.
//
// Arguments:
//  BgAffineSrcData  *Srcp      Source Address
//  BgAffineDestData *Destp     Destination Address
//              s32   Num       Number of times calculated
//
// BgAffineSrcData Structure
//    s32 SrcCenterX            Source Data Center Coordinate (8bits after decimal
//                               point)
//    s32 SrcCenterY
//    s16 DispCenterX           Display Center Coordinate
//    s16 DispCenterY
//    s16 RatioX                Scaling Ratio (8 bits after decimal point)
//    s16 RatioY
//    u16 Theta                 Rotation Angle (8bits after decimal point)
//                                  Valid Range    0 - 0xffff
// BgAffineDestData Structure
//    s16 H_DiffX               Line Direction X Coordinate Difference
//    s16 V_DiffX                 Vertical Direction X Coordinate Difference
//    s16 H_DiffY               Line Direction Y Coordinate Difference
//    s16 V_DiffY                 Vertical Direction Y Coordinate Difference
//    s32 StartX                Start X Coordinate
//    s32 StartY                Start Y Coordinate

/*------------------------------------------------------------------*/
/*                   Set OBJ Affine Transformation                   */
/*------------------------------------------------------------------*/

extern void ObjAffineSet(ObjAffineSrcData *Srcp, void *Destp, s32 Num, s32 Offset);

// Calculate and set the OBJ affine parameter.
//
// Arguments:
//  ObjAffineSrcData *Srcp      Source Address
//              void *Destp     Destination Address
//              s32   Num       Number of times calculated
//              s32   Offset    Parameter address offset byte size 
//                              (Normally 2|8)
//                              Designate "8" when directly setting to OAM
//
// ObjAffineSrcData Structure
//    s16 RatioX                Scaling Ratio (8bits to the right of the decimal//                              point)
//    s16 RatioY
//    u16 Theta                 Rotation Angle (8bits after decimal point)
//                                  Valid Range    0 - 0xffff
// ObjAffineDestData Structure
//    s16 H_DiffX               Line Direction X Coordinate Difference
//    s16 V_DiffX                 Vertical Direction X Coordinate Difference
//    s16 H_DiffY               Line Direction Y Coordinate Difference
//    s16 V_DiffY                 Vertical Direction Y Coordinate Difference

/*------------------------------------------------------------------*/
/*             LZ77 Compressed Data Expansion (-> Work RAM)         */
/*------------------------------------------------------------------*/

extern void LZ77UnCompWram(void *Srcp, void *Destp);

// Expand LZ77 compressed data and write by 8 bits.
// Cannot expand directly to VRAM.
// When the compressed data size is not a multiple of 4, fill as much 
// as possible wtih 0 and adjust.
// Match the source address to a 4-byte boundary.
//
// Arguments:
//    void *Srcp              Source Address
//    void *Destp             Destination Address
//
// Data Header
//    u32 :4                  Reserve
//        CompType:4          Compressed Type (=1)
//        DestSize:24         Post-expansion data size
//
// Flag Data Format
//    u8  Flags               Compressed/Noncompressed flag
//                            (0, 1) = (Noncompressed data, compressed data)
// Code Data Format (Big Endian)
//    u16 Length:4            Expansion Data Length - 3 (Compress only when 
//                            matching length is 3 bytes or more.)
//        Offset:12           Matching Data Offset - 1

/*------------------------------------------------------------------*/
/*                   LZ77 Compressed Data Expansion (-> VRAM)       */
/*------------------------------------------------------------------*/

extern void LZ77UnCompVram(void *Srcp, void *Destp);

// Expand LZ77 compressed data and write with 16 bit units.
// Can expand to Work RAM as well, but slower than LZ77UnCompWram().
// The compressed data should be a matching character string of 2 bytes or more.
// When compressed data size is not a multiple of 4, fill as much as possible 
// with 0 and adjust.
// Match the source address to a 4 byte boundary.
//
// Arguments:
//    void *Srcp              Source Address
//    void *Destp             Destination Address
//
// Data Header
//    u32 :4                  Reserve
//        CompType:4          Compressed Type (=1)
//        DestSize:24         Post-expansion data size
//
// Flag Data Format
//    u8  Flags               Compressed/Noncompressed flag
//                            (0, 1) = (Noncompressed data, Compressed data)
// Code Data Format (Big Endian)
//    u16 Length:4            Expanded data length - 3 (Compress only when 
//                            matching length is 3 bytes or more)
//        Offset:12           Matching Data Offset ( >= 2) - 1

/*------------------------------------------------------------------*/
/*                   Huffman Compressed Data Expansion              */
/*------------------------------------------------------------------*/

extern void HuffUnComp(void *Srcp, void *Destp);

// Expand Huffman compressed data and write with 32 bit units.
// When compressed data size is not a multiple of 4, fill as much as possible 
// with 0 and adjust.
// Match the source address to a 4 byte boundary.
//
// Arguments:
//    void *Srcp              Source Address
//    void *Destp             Destination Address
//
// Data Header
//    u32 BitSize:4           1 Data Bit Size (Normally 4|8)
//        CompType:4          Compressed Type ( = 2)
//        DestSize:24         Post-expansion data size
//
// Tree Table
//    u8           TreeSize        Tree Table Size/2 - 1
//    TreeNodeData RootNode        Root Node
//
//    TreeNodeData LeftNode        Root Left Node
//    TreeNodeData RightNode       Root Right Node
//
//    TreeNodeData LeftleftNode    Left Left Node
//    TreeNodeData leftRightNode   Left Right Node
//
//    TreeNodeData RightLeftNode   Right Left Node
//    TreeNodeData RightRightNode  Right Right Node
//
//            .
//            .
//
// Following is Main Body of Compressed Data
//
// TreeNodeData Structure
//    u8  NextNodeOffset:6    Offset to next node data - 1 (2 byte unit)
//        RightEndFlag:1      Right node end flag
//        LeftEndFlag:1       Left node end flag
//                            When end flag is set
//                            Data in next node





#endif /* _AGB_SYSTEM_CALL_H */
