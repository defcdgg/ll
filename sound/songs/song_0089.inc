	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0089_1
song_0089_1:	@ 0x087E63D4
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 2
	.byte		N92	, Cn3, v100
	.byte	W92
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0089
song_0089:	@ 0x087E63E4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0089_1		@ track
