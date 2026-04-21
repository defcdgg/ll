	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0081_1
song_0081_1:	@ 0x087E62F4
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 19
	.byte		N19	, Cn3, v100
	.byte	W19
	.byte	FINE

	.align 2
	.global song_0081
song_0081:	@ 0x087E6304
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0081_1		@ track
