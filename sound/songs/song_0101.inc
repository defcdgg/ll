	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0101_1
song_0101_1:	@ 0x087E652C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 14
	.byte	VOL	, v120
	.byte		N78	, Cn3, v120
	.byte	W78
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0101
song_0101:	@ 0x087E653C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0101_1		@ track
