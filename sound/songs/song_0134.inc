	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0134_1
song_0134_1:	@ 0x087E68EC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 47
	.byte	VOL	, v120
	.byte		N16	, Cn3, v120
	.byte	W16
	.byte	FINE

	.align 2
	.global song_0134
song_0134:	@ 0x087E68FC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0134_1		@ track
