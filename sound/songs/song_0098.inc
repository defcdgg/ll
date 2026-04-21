	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0098_1
song_0098_1:	@ 0x087E64D4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 11
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W44
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0098
song_0098:	@ 0x087E64E4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0098_1		@ track
