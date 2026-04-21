	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0073_1
song_0073_1:	@ 0x087E6214
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 11
	.byte		N44	, Cn3, v100
	.byte	W48
	.byte	FINE

	.align 2
	.global song_0073
song_0073:	@ 0x087E6224
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0073_1		@ track
