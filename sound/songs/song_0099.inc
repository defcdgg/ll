	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0099_1
song_0099_1:	@ 0x087E64F0
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 12
	.byte		N52	, Cn3, v100
	.byte	W52
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0099
song_0099:	@ 0x087E6500
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0099_1		@ track
