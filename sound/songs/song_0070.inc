	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0070_1
song_0070_1:	@ 0x087E61C0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 7
	.byte	VOL	, v120
	.byte		N24	, Cn3, v120
	.byte	W24
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0070
song_0070:	@ 0x087E61D0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0070_1		@ track
