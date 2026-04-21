	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0173_1
song_0173_1:	@ 0x087E6D40
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 86
	.byte	VOL	, v120
	.byte		N05	, Cn3, v120
	.byte	W06
	.byte	FINE

	.align 2
	.global song_0173
song_0173:	@ 0x087E6D50
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0173_1		@ track
