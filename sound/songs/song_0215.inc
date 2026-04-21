	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0215_1
song_0215_1:	@ 0x087E7200
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 0
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W96
	.byte	W13
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0215
song_0215:	@ 0x087E7210
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0215_1		@ track
