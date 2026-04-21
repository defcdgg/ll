	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0264_1
song_0264_1:	@ 0x087E776C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 49
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W64
	.byte	W01
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0264
song_0264:	@ 0x087E7780
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0264_1		@ track
