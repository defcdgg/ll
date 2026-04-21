	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0027_1
song_0027_1:	@ 0x087DB05C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 3
	.byte	VOL	, v100
	.byte	PAN	, c_v
	.byte	W24
song_0027_1_3:
	.byte	TEMPO	, 40
	.byte		N48	, Ds4, v112
	.byte	W48
	.byte		N22	, As4
	.byte	W24
	.byte	W02
	.byte		N68	
	.byte	W68
	.byte	W01
	.byte		N36	, Fn4
	.byte	W01
	.byte	W32
	.byte	W03
	.byte		N14	, Fs4
	.byte	W13
	.byte		N24	, Gs4
	.byte	W23
	.byte		N66	, Fn4
	.byte	W01
	.byte	W72
	.byte	W02
	.byte		N20	, Ds4
	.byte	W20
	.byte		N24	, Fn4
	.byte	W23
	.byte			Fs4
	.byte	W24
	.byte		N48	, Gs4
	.byte	W03
song_0027_1_1:
	.byte	W44
	.byte	W03
	.byte		N22	, Fs4, v112
	.byte	W24
	.byte		N36	, As4
	.byte	W01
	.byte	PEND
	.byte	W32
	.byte	W03
	.byte		N14	, Gs4
	.byte	W14
	.byte		N12	, Fs4
	.byte	W10
	.byte			Gs4
	.byte	W12
	.byte		N60	, As4
	.byte	W01
	.byte	W72
	.byte	W01
	.byte		N44	, Ds4
	.byte	W44
	.byte		N23	, As4
	.byte	W24
	.byte	W02
	.byte		N66	
	.byte	W01
	.byte	W72
	.byte		N32	, Fn4
	.byte	W32
	.byte	W02
	.byte		N14	, Fs4
	.byte	W13
	.byte		N24	, Gs4
	.byte	W24
	.byte		N56	, Fn4
	.byte	W01
	.byte	W68
	.byte	W02
	.byte		N24	, Ds4
	.byte	W02
	.byte	W23
	.byte			Fn4
	.byte	W23
	.byte			Fs4
	.byte	W24
	.byte	W01
	.byte		N36	, Fn4
	.byte	W01
	.byte	W36
	.byte		N13	, Ds4
	.byte	W12
	.byte		N14	, Cs4
	.byte	W13
	.byte		N10	, Ds4
	.byte	W11
song_0027_1_2:
	.byte	W01
	.byte		TIE	, Ds4, v112
	.byte	W68
	.byte	W03
	.byte	PEND
	.byte	W36
	.byte	W01
	.byte		EOT	
	.byte	W12
	.byte		N24	, As3
	.byte	W22
	.byte		N48	, Ds4
	.byte	W01
	.byte	W48
	.byte		N21	, As4
	.byte	W24
	.byte		N68	
	.byte	W72
	.byte	W01
	.byte		N32	, Fn4
	.byte	W32
	.byte	W01
	.byte		N13	, Fs4
	.byte	W12
	.byte		N24	, Gs4
	.byte	W24
	.byte		N54	, Fn4
	.byte	W02
	.byte	W56
	.byte	W03
	.byte		N13	, Cs4
	.byte	W11
	.byte		N24	, Ds4
	.byte	W02
	.byte	W24
	.byte			Fn4
	.byte	W23
	.byte			Fs4
	.byte	W24
	.byte		N48	, Gs4
	.byte	W01
	.byte	PATT	
		.word	song_0027_1_1
	.byte	W32
	.byte	W02
	.byte		N14	, Gs4, v112
	.byte	W13
	.byte		N13	, Fs4
	.byte	W11
	.byte		N14	, Gs4
	.byte	W13
	.byte		N64	, As4
	.byte	W01
	.byte	W72
	.byte	W01
	.byte		N44	, Ds4
	.byte	W44
	.byte	W01
	.byte		N22	, As4
	.byte	W24
	.byte	W02
	.byte		N66	
	.byte	W72
	.byte		N36	, Fn4
	.byte	W32
	.byte	W03
	.byte		N14	, Fs4
	.byte	W13
	.byte		N24	, Gs4
	.byte	W24
	.byte		N36	, Fn4
	.byte	W44
	.byte	W03
	.byte		N24	, Cs4
	.byte	W23
	.byte			Ds4
	.byte	W02
	.byte	W23
	.byte			Fn4
	.byte	W24
	.byte	W01
	.byte			Fs4
	.byte	W24
	.byte		N36	, Fn4
	.byte	W36
	.byte		N13	, Ds4
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte		N10	, Ds4
	.byte	W12
	.byte	PATT	
		.word	song_0027_1_2
	.byte	W68
	.byte	W02
	.byte		EOT	, Ds4
	.byte	W02
	.byte	GOTO	
		.word	song_0027_1_3
	.byte	FINE

	.align 2
	.global song_0027
song_0027:	@ 0x087DB160
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	208		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0027_1		@ track
