	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0256_1
song_0256_1:	@ 0x087E768C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 41
	.byte	VOL	, v120
	.byte		N72	, Cn3, v120
	.byte	W72
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0256
song_0256:	@ 0x087E769C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0256_1		@ track
