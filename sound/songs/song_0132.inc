	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0132_1
song_0132_1:	@ 0x087E68B4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 45
	.byte	VOL	, v120
	.byte		N23	, Cn3, v120
	.byte	W24
	.byte	FINE

	.align 2
	.global song_0132
song_0132:	@ 0x087E68C4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0132_1		@ track
