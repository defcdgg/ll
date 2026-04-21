	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0166_1
song_0166_1:	@ 0x087E6C78
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 79
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W42
	.byte	FINE

	.align 2
	.global song_0166
song_0166:	@ 0x087E6C88
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0166_1		@ track
