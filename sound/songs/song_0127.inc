	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0127_1
song_0127_1:	@ 0x087E6824
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 40
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W24
	.byte	W02
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0127
song_0127:	@ 0x087E6838
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0127_1		@ track
