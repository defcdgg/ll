	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0221_1
song_0221_1:	@ 0x087E72B0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 6
	.byte	VOL	, v120
	.byte		TIE	, Cn3, v120
	.byte	W96
	.byte	W60
	.byte	W01
	.byte		EOT	
	.byte	FINE

	.align 2
	.global song_0221
song_0221:	@ 0x087E72C0
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0221_1		@ track
