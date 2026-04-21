	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0245_1
song_0245_1:	@ 0x087E7558
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 30
	.byte	VOL	, v120
	.byte		N54	, Cn3, v120
	.byte	W54
	.byte	FINE

	.align 2
	.global song_0245
song_0245:	@ 0x087E7568
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0245_1		@ track
