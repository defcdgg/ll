	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0152_1
song_0152_1:	@ 0x087E6AEC
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 65
	.byte		TIE	, Cn3, v100
	.byte	W96
	.byte	W32
	.byte	W03
	.byte		EOT	
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0152
song_0152:	@ 0x087E6B00
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0152_1		@ track
