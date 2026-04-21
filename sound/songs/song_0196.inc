	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0196_1
song_0196_1:	@ 0x087E6FD4
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 109
	.byte		N24	, Cn3, v100
	.byte	W24
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0196
song_0196:	@ 0x087E6FE4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0196_1		@ track
