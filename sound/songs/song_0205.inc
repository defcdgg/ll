	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0205_1
song_0205_1:	@ 0x087E70D0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 118
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W32
	.byte	W02
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0205
song_0205:	@ 0x087E70E0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0205_1		@ track
