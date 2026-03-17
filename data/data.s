	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.equiv MPLAY_SIZE, 12
	.equiv SONG_SIZE, 8

gUnk_08057750:: @ 08057750
	.incbin "baserom.gba", 0x57750, 0x6AF214 - 0x57750
