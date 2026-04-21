	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0235_1
song_0235_1:	@ 0x087E743C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 20
	.byte	VOL	, v120
	.byte		N68	, Cn3, v120
	.byte	W68
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0235
song_0235:	@ 0x087E744C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0235_1		@ track
