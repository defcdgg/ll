	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0125_1
song_0125_1:	@ 0x087E67E8
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 38
	.byte		N92	, Cn3, v100
	.byte	W92
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0125
song_0125:	@ 0x087E67F8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0125_1		@ track
