	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0124_1
song_0124_1:	@ 0x087E67CC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 37
	.byte	VOL	, v120
	.byte		N20	, Cn3, v120
	.byte	W21
	.byte	FINE

	.align 2
	.global song_0124
song_0124:	@ 0x087E67DC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0124_1		@ track
