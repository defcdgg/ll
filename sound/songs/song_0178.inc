	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0178_1
song_0178_1:	@ 0x087E6DCC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 16
	.byte	VOL	, v120
	.byte		N60	, Cn3, v120
	.byte	W60
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0178
song_0178:	@ 0x087E6DDC
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup003		@ voicegroup/tone

	.word	song_0178_1		@ track
