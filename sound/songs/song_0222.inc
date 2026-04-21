	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0222_1
song_0222_1:	@ 0x087E72CC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 7
	.byte	VOL	, v120
	.byte		N68	, Cn3, v120
	.byte	W68
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0222
song_0222:	@ 0x087E72DC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0222_1		@ track
