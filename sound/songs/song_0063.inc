	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0063_1
song_0063_1:	@ 0x087E60FC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 0
	.byte	VOL	, v120
	.byte		N04	, Cn3, v120
	.byte	W05
	.byte	FINE

	.align 2
	.global song_0063
song_0063:	@ 0x087E610C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0063_1		@ track
