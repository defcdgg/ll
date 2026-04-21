	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0086_1
song_0086_1:	@ 0x087E6380
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 24
	.byte		N60	, Cn3, v100
	.byte	W60
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0086
song_0086:	@ 0x087E6390
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0086_1		@ track
