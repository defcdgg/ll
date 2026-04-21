	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0247_1
song_0247_1:	@ 0x087E7590
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 32
	.byte	VOL	, v120
	.byte		N54	, Cn3, v120
	.byte	W54
	.byte	FINE

	.align 2
	.global song_0247
song_0247:	@ 0x087E75A0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0247_1		@ track
