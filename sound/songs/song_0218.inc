	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0218_1
song_0218_1:	@ 0x087E725C
	.byte	VOL	, v127
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	VOICE	, 3
	.byte		N60	, Cn3, v100
	.byte	W60
	.byte	W03
	.byte	FINE

	.align 2
	.global song_0218
song_0218:	@ 0x087E726C
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	0		@ reverb

	.word	voicegroup004		@ voicegroup/tone

	.word	song_0218_1		@ track
