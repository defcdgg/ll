	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0243_1
song_0243_1:	@ 0x087E751C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 28
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W22
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0243
song_0243:	@ 0x087E752C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0243_1		@ track
