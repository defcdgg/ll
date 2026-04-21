	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0091_1
song_0091_1:	@ 0x087E6410
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 4
	.byte	VOL	, v120
	.byte		N10	, Cn3, v120
	.byte	W10
	.byte	FINE

	.align 2
	.global song_0091
song_0091:	@ 0x087E6420
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0091_1		@ track
