	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0130_1
song_0130_1:	@ 0x087E687C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 43
	.byte	VOL	, v120
	.byte		N08	, Cn3, v120
	.byte	W09
	.byte	FINE

	.align 2
	.global song_0130
song_0130:	@ 0x087E688C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0130_1		@ track
