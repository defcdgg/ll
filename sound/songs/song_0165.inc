	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0165_1
song_0165_1:	@ 0x087E6C5C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 78
	.byte	VOL	, v120
	.byte		N40	, Cn3, v120
	.byte	W40
	.byte	FINE

	.align 2
	.global song_0165
song_0165:	@ 0x087E6C6C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0165_1		@ track
