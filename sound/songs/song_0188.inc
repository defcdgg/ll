	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0188_1
song_0188_1:	@ 0x087E6EEC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
song_0188_1_1:
	.byte	TEMPO	, 60
	.byte	VOICE	, 101
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W24
	.byte	GOTO	
		.word	song_0188_1_1
	.byte	W02
	.byte		EOT	, Cn3
	.byte	FINE

	.align 2
	.global song_0188
song_0188:	@ 0x087E6F04
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0188_1		@ track
