	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0217_1
song_0217_1:	@ 0x087E7240
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 2
	.byte		N40	, Cn3, v100
	.byte	W42
	.byte	FINE

	.align 2
	.global song_0217
song_0217:	@ 0x087E7250
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0217_1		@ track
