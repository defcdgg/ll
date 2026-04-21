	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0157_1
song_0157_1:	@ 0x087E6B7C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 70
	.byte	VOL	, v120
	.byte		N52	, Cn3, v120
	.byte	W52
	.byte	FINE

	.align 2
	.global song_0157
song_0157:	@ 0x087E6B8C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0157_1		@ track
