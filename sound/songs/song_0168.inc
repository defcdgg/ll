	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0168_1
song_0168_1:	@ 0x087E6CB0
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 81
	.byte		N76	, Cn3, v100
	.byte	W76
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0168
song_0168:	@ 0x087E6CC0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0168_1		@ track
