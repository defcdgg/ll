	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0175_1
song_0175_1:	@ 0x087E6D78
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 88
	.byte	VOL	, v120
	.byte		N20	, Cn3, v120
	.byte	W21
	.byte	FINE

	.align 2
	.global song_0175
song_0175:	@ 0x087E6D88
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0175_1		@ track
