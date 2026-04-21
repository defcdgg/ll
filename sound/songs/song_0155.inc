	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0155_1
song_0155_1:	@ 0x087E6B44
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 68
	.byte	VOL	, v120
	.byte		N14	, Cn3, v120
	.byte	W15
	.byte	FINE

	.align 2
	.global song_0155
song_0155:	@ 0x087E6B54
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0155_1		@ track
