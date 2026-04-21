	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0223_1
song_0223_1:	@ 0x087E72E8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 8
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W96
	.byte	W64
	.byte	W01
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0223
song_0223:	@ 0x087E72FC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0223_1		@ track
