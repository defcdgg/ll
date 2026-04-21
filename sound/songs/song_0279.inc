	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0279_1
song_0279_1:	@ 0x087E7918
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 64
	.byte	VOL	, v120
	.byte		N48	, Cn3, v120
	.byte	W48
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0279
song_0279:	@ 0x087E7928
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0279_1		@ track
