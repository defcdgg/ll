	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0114_1
song_0114_1:	@ 0x087E66B4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 27
	.byte	VOL	, v120
	.byte		N17	, Cn3, v120
	.byte	W18
	.byte	FINE

	.align 2
	.global song_0114
song_0114:	@ 0x087E66C4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0114_1		@ track
