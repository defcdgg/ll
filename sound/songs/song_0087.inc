	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0087_1
song_0087_1:	@ 0x087E639C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 0
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W88
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0087
song_0087:	@ 0x087E63AC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0087_1		@ track
