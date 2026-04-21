	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0246_1
song_0246_1:	@ 0x087E7574
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 31
	.byte		N68	, Cn3, v100
	.byte	W72
	.byte	FINE

	.align 2
	.global song_0246
song_0246:	@ 0x087E7584
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0246_1		@ track
