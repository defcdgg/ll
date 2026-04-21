	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0263_1
song_0263_1:	@ 0x087E7750
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 48
	.byte	VOL	, v120
	.byte		N72	, Cn3, v120
	.byte	W72
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0263
song_0263:	@ 0x087E7760
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0263_1		@ track
