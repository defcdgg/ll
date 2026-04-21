	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0185_1
song_0185_1:	@ 0x087E6E98
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 98
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W22
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0185
song_0185:	@ 0x087E6EA8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0185_1		@ track
