	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0083_1
song_0083_1:	@ 0x087E632C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 20
	.byte	VOL	, v120
	.byte		N48	, Cn3, v120
	.byte	W48
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0083
song_0083:	@ 0x087E633C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0083_1		@ track
