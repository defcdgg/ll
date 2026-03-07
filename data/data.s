	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.equiv MPLAY_SIZE, 12
	.equiv SONG_SIZE, 8

gUnk_0805769C:: @ 0805769C
	.incbin "baserom.gba", 0x5769C, 0x657B78
