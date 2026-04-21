	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0076_1
song_0076_1:	@ 0x087E6268
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 14
	.byte		N36	, Cn3, v100
	.byte	W36
	.byte	FINE

	.align 2
	.global song_0076
song_0076:	@ 0x087E6278
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0076_1		@ track
