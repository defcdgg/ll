	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0197_1
song_0197_1:	@ 0x087E6FF0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 110
	.byte	VOL	, v120
	.byte		N44	, Cn3, v120
	.byte	W48
	.byte	FINE

	.align 2
	.global song_0197
song_0197:	@ 0x087E7000
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0197_1		@ track
