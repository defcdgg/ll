	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0271_1
song_0271_1:	@ 0x087E7838
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 56
	.byte	VOL	, v120
	.byte		N78	, Cn3, v120
	.byte	W78
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0271
song_0271:	@ 0x087E7848
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0271_1		@ track
