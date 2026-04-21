	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0080_1
song_0080_1:	@ 0x087E62D8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 17
	.byte	VOL	, v120
	.byte		N52	, Cn3, v120
	.byte	W54
	.byte	FINE

	.align 2
	.global song_0080
song_0080:	@ 0x087E62E8
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0080_1		@ track
