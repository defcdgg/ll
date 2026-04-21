	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0254_1
song_0254_1:	@ 0x087E7654
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 39
	.byte	VOL	, v120
	.byte		N32	, Cn3, v120
	.byte	W36
	.byte	FINE

	.align 2
	.global song_0254
song_0254:	@ 0x087E7664
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0254_1		@ track
