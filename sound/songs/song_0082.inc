	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0082_1
song_0082_1:	@ 0x087E6310
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 20
	.byte		N30	, Cn3, v100
	.byte	W32
	.byte	FINE

	.align 2
	.global song_0082
song_0082:	@ 0x087E6320
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0082_1		@ track
