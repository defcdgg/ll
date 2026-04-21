	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0195_1
song_0195_1:	@ 0x087E6FB8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 108
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W96
	.byte	W10
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0195
song_0195:	@ 0x087E6FC8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0195_1		@ track
