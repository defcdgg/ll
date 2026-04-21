	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0136_1
song_0136_1:	@ 0x087E6924
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 49
	.byte	VOL	, v120
	.byte		N52	, Cn3, v120
	.byte	W52
	.byte	FINE

	.align 2
	.global song_0136
song_0136:	@ 0x087E6934
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0136_1		@ track
