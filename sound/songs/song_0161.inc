	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0161_1
song_0161_1:	@ 0x087E6BEC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 74
	.byte	VOL	, v120
	.byte		N16	, Cn3, v120
	.byte	W16
	.byte	FINE

	.align 2
	.global song_0161
song_0161:	@ 0x087E6BFC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0161_1		@ track
