	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0116_1
song_0116_1:	@ 0x087E66EC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 29
	.byte	VOL	, v120
	.byte		N13	, Cn3, v120
	.byte	W13
	.byte	FINE

	.align 2
	.global song_0116
song_0116:	@ 0x087E66FC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0116_1		@ track
