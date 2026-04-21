	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0227_1
song_0227_1:	@ 0x087E735C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 12
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W20
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0227
song_0227:	@ 0x087E736C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0227_1		@ track
