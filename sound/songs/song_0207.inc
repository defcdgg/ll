	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0207_1
song_0207_1:	@ 0x087E7108
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 120
	.byte	VOL	, v120
	.byte		N92	, Cn3, v120
	.byte	W92
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0207
song_0207:	@ 0x087E7118
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0207_1		@ track
