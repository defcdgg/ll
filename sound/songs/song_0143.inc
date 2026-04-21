	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0143_1
song_0143_1:	@ 0x087E69E8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 56
	.byte	VOL	, v120
	.byte		N78	, Cn3, v120
	.byte	W78
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0143
song_0143:	@ 0x087E69F8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0143_1		@ track
