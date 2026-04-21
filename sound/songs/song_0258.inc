	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0258_1
song_0258_1:	@ 0x087E76C4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 43
	.byte	VOL	, v120
	.byte		N60	, Cn3, v120
	.byte	W60
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0258
song_0258:	@ 0x087E76D4
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0258_1		@ track
