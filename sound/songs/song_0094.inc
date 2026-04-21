	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0094_1
song_0094_1:	@ 0x087E6464
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 7
	.byte		N56	, Cn3, v100
	.byte	W56
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0094
song_0094:	@ 0x087E6474
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0094_1		@ track
