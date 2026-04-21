	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0069_1
song_0069_1:	@ 0x087E61A4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 6
	.byte	VOL	, v120
	.byte		N23	, Cn3, v120
	.byte	W24
	.byte	FINE

	.align 2
	.global song_0069
song_0069:	@ 0x087E61B4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0069_1		@ track
