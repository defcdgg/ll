	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0241_1
song_0241_1:	@ 0x087E74E4
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 26
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W10
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0241
song_0241:	@ 0x087E74F4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0241_1		@ track
