	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0202_1
song_0202_1:	@ 0x087E707C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 115
	.byte		N56	, Cn3, v100
	.byte	W56
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0202
song_0202:	@ 0x087E708C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0202_1		@ track
