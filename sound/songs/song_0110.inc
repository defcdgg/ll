	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0110_1
song_0110_1:	@ 0x087E6644
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 23
	.byte	VOL	, v120
	.byte		N11	, Cn3, v120
	.byte	W12
	.byte	FINE

	.align 2
	.global song_0110
song_0110:	@ 0x087E6654
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0110_1		@ track
