	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0122_1
song_0122_1:	@ 0x087E6794
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 35
	.byte	VOL	, v120
	.byte		N08	, Cn3, v120
	.byte	W09
	.byte	FINE

	.align 2
	.global song_0122
song_0122:	@ 0x087E67A4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0122_1		@ track
