	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0159_1
song_0159_1:	@ 0x087E6BB4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 72
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W40
	.byte	FINE

	.align 2
	.global song_0159
song_0159:	@ 0x087E6BC4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0159_1		@ track
