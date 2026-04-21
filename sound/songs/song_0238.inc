	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0238_1
song_0238_1:	@ 0x087E7490
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 23
	.byte		N72	, Cn3, v100
	.byte	W72
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0238
song_0238:	@ 0x087E74A0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0238_1		@ track
