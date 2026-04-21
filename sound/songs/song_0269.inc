	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0269_1
song_0269_1:	@ 0x087E7800
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 54
	.byte	VOL	, v120
	.byte		N32	, Cn3, v120
	.byte	W32
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0269
song_0269:	@ 0x087E7810
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0269_1		@ track
