	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0199_1
song_0199_1:	@ 0x087E7028
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 112
	.byte		N17	, Cn3, v100
	.byte	W17
	.byte	FINE

	.align 2
	.global song_0199
song_0199:	@ 0x087E7038
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0199_1		@ track
