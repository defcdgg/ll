	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0234_1
song_0234_1:	@ 0x087E7420
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 19
	.byte		N30	, Cn3, v100
	.byte	W30
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0234
song_0234:	@ 0x087E7430
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0234_1		@ track
