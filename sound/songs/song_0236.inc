	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0236_1
song_0236_1:	@ 0x087E7458
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 21
	.byte	VOL	, v120
	.byte		N13	, Cn3, v120
	.byte	W13
	.byte	FINE

	.align 2
	.global song_0236
song_0236:	@ 0x087E7468
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0236_1		@ track
