	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0137_1
song_0137_1:	@ 0x087E6940
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 50
	.byte	VOL	, v120
	.byte		N16	, Cn3, v120
	.byte	W16
	.byte	FINE

	.align 2
	.global song_0137
song_0137:	@ 0x087E6950
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0137_1		@ track
