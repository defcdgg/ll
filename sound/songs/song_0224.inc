	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0224_1
song_0224_1:	@ 0x087E7308
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 9
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W40
	.byte	FINE

	.align 2
	.global song_0224
song_0224:	@ 0x087E7318
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0224_1		@ track
