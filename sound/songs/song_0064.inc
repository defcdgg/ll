	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0064_1
song_0064_1:	@ 0x087E6118
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 1
	.byte		N23	, Cn3, v100
	.byte	W23
	.byte	FINE

	.align 2
	.global song_0064
song_0064:	@ 0x087E6128
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0064_1		@ track
