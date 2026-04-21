	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0108_1
song_0108_1:	@ 0x087E6608
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 21
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W40
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0108
song_0108:	@ 0x087E661C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0108_1		@ track
