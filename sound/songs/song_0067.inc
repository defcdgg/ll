	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0067_1
song_0067_1:	@ 0x087E616C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 4
	.byte	VOL	, v120
	.byte		N05	, Cn3, v120
	.byte	W06
	.byte	FINE

	.align 2
	.global song_0067
song_0067:	@ 0x087E617C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup002		@ voicegroup/tone

	.word	song_0067_1		@ track
