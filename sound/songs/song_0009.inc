	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0009_1
song_0009_1:	@ 0x087D4D98
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 3
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0009_1_3:
	.byte	TEMPO	, 63
	.byte		N48	, Gs4, v127
	.byte	W48
	.byte		N12	, Fs4
	.byte	W12
	.byte		N24	, Gs4
	.byte	W24
	.byte		N36	, Bn3
	.byte	W12
	.byte	W24
	.byte		N24	, Cs4
	.byte	W24
	.byte			Ds4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N48	, Gs4
	.byte	W48
	.byte		N12	, Fs4
	.byte	W12
	.byte		N24	, Gs4
	.byte	W24
	.byte		N84	, Cs4
	.byte	W12
	.byte	W96
song_0009_1_1:
	.byte		N24	, Cs4, v127
	.byte	W24
	.byte			Ds4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte			Fs4
	.byte	W24
	.byte	PEND
	.byte			An4
	.byte	W24
	.byte			Gs4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N12	, Gs4
	.byte	W12
	.byte		TIE	, Fs4
	.byte	W12
	.byte	W96
	.byte		EOT	
	.byte	W96
	.byte		N24	, Bn4
	.byte	W24
	.byte			An4
	.byte	W24
	.byte		N12	, Gs4
	.byte	W12
	.byte		N24	, Fs4
	.byte	W24
	.byte		N72	, En4
	.byte	W12
	.byte	W96
	.byte		N24	, Bn4
	.byte	W24
	.byte			An4
	.byte	W24
	.byte		N12	, Gs4
	.byte	W12
	.byte		N24	, Fs4
	.byte	W24
	.byte		N84	, En4
	.byte	W12
	.byte	W96
	.byte	PATT	
		.word	song_0009_1_1
	.byte		N24	, Gs4, v127
	.byte	W24
	.byte			Fs4
	.byte	W24
	.byte		N12	, En4
	.byte	W12
	.byte		N24	, Ds4
	.byte	W24
	.byte		TIE	, En4
	.byte	W12
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte		N36	, Fs4
	.byte	W36
	.byte			En4
	.byte	W36
	.byte		N24	, Fs4
	.byte	W24
	.byte			An4
	.byte	W24
	.byte		N12	, Gs4
	.byte	W12
	.byte		N24	, Fs4
	.byte	W24
	.byte		N36	, En4
	.byte	W36
	.byte		N24	, Gs4
	.byte	W24
	.byte		N12	, En4
	.byte	W12
	.byte		TIE	, Bn3
	.byte	W60
	.byte	W78
	.byte		EOT	
	.byte	W18
	.byte		N48	, En4
	.byte	W48
	.byte		N12	, Ds4
	.byte	W12
	.byte		N36	, En4
	.byte	W36
	.byte		N24	, Fs4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N12	, Ds4
	.byte	W12
	.byte		N36	, Cs4
	.byte	W36
	.byte		TIE	, Fs4
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte		N36	, Bn4
	.byte	W36
	.byte			En4
	.byte	W36
	.byte		N24	, Bn4
	.byte	W24
	.byte		N36	
	.byte	W36
	.byte		N24	, Cs5
	.byte	W24
	.byte		N12	, An4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N72	, An4
	.byte	W12
song_0009_1_2:
	.byte	W72
	.byte		N12	, Fs4, v127
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte	PEND
	.byte			An4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N08	, Fs4
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		N12	, Gs4
	.byte	W12
	.byte		N24	, An4
	.byte	W24
	.byte		N36	, Bn4
	.byte	W36
	.byte			Gs4
	.byte	W36
	.byte		N24	, Bn4
	.byte	W24
	.byte		N36	, Cs5
	.byte	W36
	.byte		N24	, Bn4
	.byte	W24
	.byte		N12	, An4
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N60	, An4
	.byte	W12
	.byte	PATT	
		.word	song_0009_1_2
	.byte		N12	, An4, v127
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte		N08	, Fs4
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N12	, Ds4
	.byte	W12
	.byte		TIE	, En4
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	GOTO	
		.word	song_0009_1_3
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0009_2
song_0009_2:	@ 0x087D4EB3
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v069
	.byte	PAN	, c_v
	.byte	W24
song_0009_2_2:
	.byte		N12	, En1, v127
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N22	, Gs2
	.byte	W24
song_0009_2_1:
	.byte		N12	, En1, v127
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, Gs2
	.byte	W24
	.byte	PEND
	.byte		N12	, An1
	.byte	W11
	.byte			En2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N23	, Cs3
	.byte	W24
	.byte		N12	, An2
	.byte	W12
	.byte		N24	, En2
	.byte	W24
	.byte	W01
	.byte		N12	, An1
	.byte	W11
	.byte			En2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N23	, Cs3
	.byte	W24
	.byte		N12	, An2
	.byte	W12
	.byte		N23	, En2
	.byte	W24
	.byte	W01
	.byte		N12	, Fs1
	.byte	W11
	.byte			Fs2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N23	, Cs3
	.byte	W24
	.byte		N12	, An2
	.byte	W12
	.byte		N23	, Fs2
	.byte	W24
	.byte	W01
	.byte		N12	, An1
	.byte	W11
	.byte			Fs2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, An2
	.byte	W12
	.byte		N24	, Fs2
	.byte	W24
	.byte	W01
	.byte		N12	, Bn1
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, An2
	.byte	W12
	.byte		N23	, Fs2
	.byte	W24
	.byte		N12	, Bn1
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N24	, Ds3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, Fs2
	.byte	W24
	.byte		N12	, Gs1
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N22	, Ds3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, Gs2
	.byte	W24
	.byte		N12	, Cs2
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Cs3
	.byte	W12
	.byte		N23	, Gs2
	.byte	W24
	.byte		N12	, Gs1
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N21	, Ds3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte			Gs2
	.byte	W14
	.byte		N21	, En3
	.byte	W10
	.byte	W12
	.byte		N12	, En2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N22	, Cs3
	.byte	W24
	.byte		N12	, An2
	.byte	W12
	.byte		N23	, En2
	.byte	W24
	.byte		N12	, Fs1
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Cs3
	.byte	W12
	.byte		N23	, Fs2
	.byte	W24
	.byte		N12	, Bn1
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N23	, Ds3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, Fs2
	.byte	W24
	.byte		N12	, En1
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N24	, En3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, En2
	.byte	W24
	.byte		N12	, En1
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, En2
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0009_2_1
	.byte		N12	, An1, v127
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Cs3
	.byte	W12
	.byte		N24	, An2
	.byte	W24
	.byte		N12	, Fs1
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Cs3
	.byte	W12
	.byte		N22	, An2
	.byte	W24
	.byte		N12	, Cs3
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N32	, Ds3
	.byte	W36
	.byte		N23	, An1
	.byte	W24
	.byte		N12	, Gs1
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N23	, Ds3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, Gs2
	.byte	W24
	.byte		N12	, Cs2
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N24	, Fn3
	.byte	W24
	.byte		N12	, Cs3
	.byte	W12
	.byte		N23	, Gs2
	.byte	W24
	.byte		N12	, Fs1
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N12	, Cs3
	.byte	W12
	.byte		N23	, An2
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte			Cs3
	.byte	W11
	.byte			Ds3
	.byte	W60
	.byte	W01
	.byte			En1
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N24	, En3
	.byte	W24
	.byte		N12	, Bn2
	.byte	W12
	.byte		N23	, Gs2
	.byte	W24
	.byte	PATT	
		.word	song_0009_2_1
	.byte	GOTO	
		.word	song_0009_2_2
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0009_3
song_0009_3:	@ 0x087D504E
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0009_3_1:
	.byte		N24	, En2, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Bn1
	.byte	W12
	.byte	PEND
	.byte		N24	, En2
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Gs1
	.byte	W12
	.byte		N24	, An1
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, En2
	.byte	W12
song_0009_3_3:
	.byte		N24	, An1, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N24	, Gs1
	.byte	W24
	.byte	PEND
song_0009_3_4:
	.byte		N24	, Fs1, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Gs1
	.byte	W12
	.byte	PEND
	.byte		N24	, An1
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	
	.byte	W12
song_0009_3_2:
	.byte		N24	, Bn1, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Fs2
	.byte	W12
	.byte	PEND
	.byte		N24	, Bn1
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N24	, An1
	.byte	W24
song_0009_3_5:
	.byte		N24	, Gs1, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PEND
	.byte		N24	, Cs2
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Fs1
	.byte	W12
	.byte		N24	, Gs1
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N36	, An1
	.byte	W12
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N12	, En1
	.byte	W12
	.byte		N24	, An1
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte			Fs1
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	, Cs2
	.byte	W36
	.byte		N01	, Fs1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N24	, Bn1
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	, Fs2
	.byte	W36
	.byte		N01	, Bn1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PATT	
		.word	song_0009_3_1
	.byte		N24	, En2, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N84	, An2
	.byte	W84
	.byte		N12	, Bn2
	.byte	W12
	.byte		N96	, Cn3
	.byte	W96
	.byte			Bn2
	.byte	W96
	.byte		N48	, En2
	.byte	W48
	.byte			Ds2
	.byte	W48
	.byte			Cs2
	.byte	W48
	.byte			Bn1
	.byte	W48
	.byte			As1
	.byte	W48
	.byte			Fs1
	.byte	W48
	.byte	PATT	
		.word	song_0009_3_2
	.byte		N24	, Bn1, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N24	
	.byte	W24
	.byte			En2
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N24	, Gs1
	.byte	W24
	.byte	PATT	
		.word	song_0009_3_3
	.byte	PATT	
		.word	song_0009_3_4
	.byte		N24	, An1, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	, Bn1
	.byte	W36
	.byte		N01	, An1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PATT	
		.word	song_0009_3_5
	.byte		N24	, Cs2, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Fn1
	.byte	W12
	.byte	PATT	
		.word	song_0009_3_4
	.byte		N24	, An1, v127
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N60	, Bn1
	.byte	W60
	.byte		N24	, En2
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	, En1
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Bn1
	.byte	W12
	.byte		N24	, En1
	.byte	W24
	.byte		N01	
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N12	, Bn1
	.byte	W12
	.byte	GOTO	
		.word	song_0009_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0009_4
song_0009_4:	@ 0x087D519B
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0009_4_1:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N24	, Bn2, v127
	.byte	W24
	.byte			Fs3
	.byte	W24
	.byte			En3
	.byte	W24
	.byte			Ds3
	.byte	W24
	.byte		N12	, En3
	.byte	W12
	.byte		N56	, Fs3
	.byte	W60
	.byte	W84
	.byte		N42	, Cs4
	.byte	W12
	.byte	W36
	.byte		N12	, Ds4
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fs4
	.byte	W12
	.byte		N80	, Gs4
	.byte	W80
	.byte	W03
	.byte		N52	, An4
	.byte	W13
	.byte	W48
	.byte		N24	, Cs4
	.byte	W24
	.byte			Bn3
	.byte	W24
	.byte		N54	, An3
	.byte	W60
	.byte		N12	, Fs3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte		N48	, Bn3
	.byte	W48
	.byte			An3
	.byte	W48
	.byte		TIE	, Gs3
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	VOICE	, 19
	.byte	W12
	.byte		N12	, Cs3
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Cs4
	.byte	W60
	.byte	W12
	.byte			Cn3
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Cn4
	.byte	W60
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Bn3
	.byte	W60
	.byte		N11	, Gs2
	.byte	W12
	.byte		N12	, Bn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte		N10	, Fs2
	.byte	W48
	.byte		N09	, En2
	.byte	W12
	.byte		N12	, Cs3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte		N10	, Ds2
	.byte	W48
	.byte			Cs2
	.byte	W12
	.byte		N12	, Cs3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte			Cs4
	.byte	W60
	.byte		N11	, An2
	.byte	W12
	.byte		N12	, Bn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Bn3
	.byte	W24
	.byte		N09	, Gs2
	.byte	W12
	.byte			An2
	.byte	W24
	.byte			Fs2
	.byte	W12
	.byte		N12	, Bn2
	.byte	W12
	.byte			Ds3
	.byte	W12
	.byte			Bn3
	.byte	W36
	.byte	VOICE	, 0
	.byte		N24	, An3
	.byte	W24
	.byte		N60	, Gs3
	.byte	W60
	.byte		N12	, En3
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte		N48	, An3
	.byte	W48
	.byte			Cs4
	.byte	W48
	.byte		N72	
	.byte	W72
	.byte		N12	, An3
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		N12	, Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte		N48	, Ds4
	.byte	W48
	.byte			Gs3
	.byte	W48
	.byte		N60	, Fn3
	.byte	W60
	.byte		N12	
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Gs3
	.byte	W12
	.byte		N96	, An3
	.byte	W96
	.byte		N36	, Cs4
	.byte	W36
	.byte		N24	
	.byte	W24
	.byte		N12	, Bn3
	.byte	W12
	.byte		N24	, An3
	.byte	W24
	.byte		TIE	, Gs3
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	GOTO	
		.word	song_0009_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0009_5
song_0009_5:	@ 0x087D5292
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0009_5_1:
	.byte		N06	, Cn1, v127
	.byte	W36
	.byte		N06	
	.byte	W36
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
song_0009_5_2:
	.byte		N06	, Cn1, v127
	.byte	W12
	.byte			En7, v080
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Cn1, v127
	.byte	W36
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0009_5_1
	.byte	PATT	
		.word	song_0009_5_2
	.byte	PATT	
		.word	song_0009_5_1
	.byte	PATT	
		.word	song_0009_5_2
	.byte	PATT	
		.word	song_0009_5_1
	.byte	PATT	
		.word	song_0009_5_2
	.byte	PATT	
		.word	song_0009_5_1
	.byte	PATT	
		.word	song_0009_5_2
	.byte	PATT	
		.word	song_0009_5_1
	.byte	W12
	.byte		N06	, En7, v080
	.byte	W12
	.byte			Cn1, v127
	.byte		N06	, En7, v080
	.byte	W12
	.byte			Cn1, v127
	.byte	W36
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PATT	
		.word	song_0009_5_1
	.byte	PATT	
		.word	song_0009_5_2
	.byte	PATT	
		.word	song_0009_5_1
	.byte	PATT	
		.word	song_0009_5_2
song_0009_5_3:
	.byte		N06	, Cn1, v127
	.byte	W84
	.byte		N06	
	.byte	W12
	.byte	PEND
song_0009_5_4:
	.byte		N06	, Cn1, v127
	.byte	W12
	.byte			En7, v080
	.byte	W12
	.byte		N06	
	.byte	W24
	.byte			Cs1, v127
	.byte	W12
	.byte		N06	
	.byte	W24
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0009_5_3
	.byte	PATT	
		.word	song_0009_5_4
	.byte	PATT	
		.word	song_0009_5_3
	.byte	PATT	
		.word	song_0009_5_4
	.byte	PATT	
		.word	song_0009_5_3
	.byte		N06	, Cn1, v127
	.byte	W12
	.byte			En7, v080
	.byte	W12
	.byte			Dn1, v127
	.byte		N06	, En7, v080
	.byte	W24
	.byte			Cn1, v127
	.byte		N06	, Dn1
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte			An1
	.byte	W12
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W12
	.byte			An1
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Cn1
	.byte		N44	, An2
	.byte	W24
	.byte		N06	, Dn1
	.byte	W12
	.byte			Cn1
	.byte	W36
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
song_0009_5_5:
	.byte		N06	, Cn1, v127
	.byte	W12
	.byte			En7, v080
	.byte	W12
	.byte			Dn1, v127
	.byte		N06	, En7, v080
	.byte	W12
	.byte			Cn1, v127
	.byte	W36
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
song_0009_5_6:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W36
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0009_5_5
	.byte	PATT	
		.word	song_0009_5_6
	.byte	PATT	
		.word	song_0009_5_5
	.byte	PATT	
		.word	song_0009_5_6
	.byte		N06	, Cn1, v127
	.byte		N24	, Cs2
	.byte	W12
	.byte		N06	, En7, v080
	.byte	W12
	.byte			Dn1, v127
	.byte		N06	, En7, v080
	.byte	W12
	.byte			Cn1, v127
	.byte		N52	, An2
	.byte	W60
	.byte	PATT	
		.word	song_0009_5_1
	.byte	PATT	
		.word	song_0009_5_2
	.byte	GOTO	
		.word	song_0009_5_1
	.byte	FINE

	.align 2
	.global song_0009
song_0009:	@ 0x087D53C4
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0009_1		@ track
	.word	song_0009_2		@ track
	.word	song_0009_3		@ track
	.word	song_0009_4		@ track
	.word	song_0009_5		@ track
