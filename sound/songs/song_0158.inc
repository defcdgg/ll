	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0158_1
song_0158_1:	@ 0x087E6B98
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 71
	.byte	VOL	, v120
	.byte		N14	, Cn3, v120
	.byte	W15
	.byte	FINE

	.align 2
	.global song_0158
song_0158:	@ 0x087E6BA8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0158_1		@ track
