	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0204_1
song_0204_1:	@ 0x087E70B4
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 117
	.byte		N56	, Cn3, v100
	.byte	W56
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0204
song_0204:	@ 0x087E70C4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0204_1		@ track
