	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0151_1
song_0151_1:	@ 0x087E6AD0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 64
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W42
	.byte	FINE

	.align 2
	.global song_0151
song_0151:	@ 0x087E6AE0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0151_1		@ track
