	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section .rodata

	.equiv MPLAY_SIZE, 12
	.equiv SONG_SIZE, 8
	.equiv TONE_SIZE, 12

gToneTable:: @ 086AF4EC
    .incbin "baserom.gba", 0x6AF4EC, TONE_SIZE * 518

gUnk_086B0D34:: @ 086B0D34
    .incbin "baserom.gba", 0x6B0D34, 0x110

gMPlayTable:: @ 086B0E44
	.incbin "baserom.gba", 0x6B0E44, MPLAY_SIZE * 5

gSongTable:: @ 086B0E80
	.incbin "baserom.gba", 0x6B0E80, SONG_SIZE * 285

gUnk_086B1768:: @ 086B1768
	.incbin "baserom.gba", 0x6B1768, 0x14E800       @ 0x14E894

