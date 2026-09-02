	.include "asm/macros.inc"
	.include "constants/gba_constants.inc"

	.section .rodata

	.equiv MPLAY_SIZE, 12
	.equiv SONG_SIZE, 8
	

@ gUnk_08057854: @ 08057854
@	.incbin "baserom.gba", 0x57854, 0x6AF214 - 0x57854

@gUnk_08059794: @ 0805881C
@	.incbin "baserom.gba", 0x59794, 0x6AF214 - 0x59794

rom_data:
	/* 0x0808760C..0x0808A04C (10820 B) 已搬到 src/data_805769C.c:
	   gCharNameTextBlock_* + gCharaCmdStream_* + gChestSpawnTable +
	   gDigitFontObjPalettes + gDigitFontObjTiles + gMapSceneDescriptors +
	   gSaveMapUnlockFlags + gMapViewportBoundsTable */
	.incbin "baserom.gba", 0x8A04C, 0x38EEF4 - 0x8A04C

	.global gUnk_0838EEF4
gUnk_0838EEF4:
	.incbin "baserom.gba", 0x38EEF4, 0x6AF214 - 0x38EEF4
