	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0079_1
song_0079_1:	@ 0x087E62BC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 16
	.byte	VOL	, v120
	.byte		N54	, Cn3, v120
	.byte	W56
	.byte	FINE

	.align 2
	.global song_0079
song_0079:	@ 0x087E62CC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0079_1		@ track
