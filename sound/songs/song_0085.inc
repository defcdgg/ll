	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0085_1
song_0085_1:	@ 0x087E6364
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 23
	.byte		N78	, Cn3, v100
	.byte	W78
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0085
song_0085:	@ 0x087E6374
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0085_1		@ track
