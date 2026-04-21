	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0088_1
song_0088_1:	@ 0x087E63B8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 1
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W44
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0088
song_0088:	@ 0x087E63C8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0088_1		@ track
