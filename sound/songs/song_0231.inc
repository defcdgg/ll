	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0231_1
song_0231_1:	@ 0x087E73CC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 16
	.byte		N90	, Cn3, v100
	.byte	W90
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0231
song_0231:	@ 0x087E73DC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0231_1		@ track
