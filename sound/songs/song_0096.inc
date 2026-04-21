	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0096_1
song_0096_1:	@ 0x087E649C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 9
	.byte	VOL	, v120
	.byte		N68	, Cn3, v120
	.byte	W68
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0096
song_0096:	@ 0x087E64AC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0096_1		@ track
