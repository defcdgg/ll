	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0187_1
song_0187_1:	@ 0x087E6ED0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 100
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W40
	.byte	FINE

	.align 2
	.global song_0187
song_0187:	@ 0x087E6EE0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0187_1		@ track
