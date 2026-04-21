	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0066_1
song_0066_1:	@ 0x087E6150
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 3
	.byte	VOL	, v120
	.byte		N16	, Cn3, v120
	.byte	W17
	.byte	FINE

	.align 2
	.global song_0066
song_0066:	@ 0x087E6160
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0066_1		@ track
