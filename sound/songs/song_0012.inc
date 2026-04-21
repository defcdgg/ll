	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0012_1
song_0012_1:	@ 0x087D6770
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 8
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	TEMPO	, 57
	.byte	W03
	.byte		N03	, Fs3, v127
	.byte	W03
	.byte			Gs3
	.byte	W03
	.byte			As3
	.byte	W03
	.byte			Bn3
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte			Ds4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte		N90	, Fs4
	.byte	W92
	.byte	W01
	.byte		N03	, Fn4
	.byte	W03
	.byte		N22	, Fs4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte			Ds4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N68	, Fs4
	.byte	W96
	.byte	VOICE	, 3
	.byte	W60
	.byte		N12	, Fs3
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
song_0012_1_7:
	.byte		N24	, Cs4, v127
	.byte	W24
	.byte		N12	, Bn3
	.byte	W12
	.byte		TIE	, Ds4
	.byte	W60
	.byte	W48
	.byte		EOT	
	.byte	W12
	.byte		N12	, Gs3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte			Ds4
	.byte	W12
song_0012_1_1:
	.byte		N24	, Ds4, v127
	.byte	W24
	.byte		N12	, En4
	.byte	W12
	.byte		TIE	, Cs4
	.byte	W60
	.byte	PEND
	.byte	W48
	.byte		EOT	
	.byte	W12
	.byte		N12	, Fs3
	.byte	W12
	.byte			Fs4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte		N24	, Ds4
	.byte	W24
	.byte		N12	, Cs4
	.byte	W12
	.byte		TIE	, Ds4
	.byte	W60
	.byte	W48
	.byte		EOT	
	.byte	W12
	.byte		N12	, Gs3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte	PATT	
		.word	song_0012_1_1
	.byte	W48
	.byte		EOT	, Cs4
	.byte	VOICE	, 8
	.byte	W12
	.byte		N12	, Fs4, v127
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			As4
	.byte	W12
song_0012_1_2:
	.byte		N24	, As4, v127
	.byte	W24
	.byte		N12	, Bn4
	.byte	W12
	.byte		N24	, Gs4
	.byte	W24
	.byte		N12	, Cs5
	.byte	W12
	.byte		N24	, Bn4
	.byte	W24
	.byte	PEND
song_0012_1_3:
	.byte		N24	, As4, v127
	.byte	W24
	.byte		N12	, Gs4
	.byte	W12
	.byte		N24	, Fs4
	.byte	W24
	.byte		N12	, Ds4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fs4
	.byte	W12
	.byte	PEND
	.byte		N24	
	.byte	W24
	.byte		N12	, En4
	.byte	W12
	.byte		N24	, Gs4
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte			Fs4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte		N48	, Fs4
	.byte	W60
	.byte		N12	
	.byte	W12
	.byte			Gs4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte	PATT	
		.word	song_0012_1_2
	.byte	PATT	
		.word	song_0012_1_3
	.byte		N12	, Fs4, v127
	.byte	W12
	.byte		N20	, En4
	.byte	W20
	.byte		N08	, Ds4
	.byte	W08
	.byte			En4
	.byte	W08
	.byte		N72	, Bn4
	.byte	W48
	.byte	W24
	.byte		N24	, Gs4
	.byte	W24
	.byte			As4
	.byte	W24
	.byte			Bn4
	.byte	W24
	.byte		TIE	, Cs5
	.byte	W96
	.byte	W44
	.byte	W02
	.byte		EOT	
	.byte	W24
	.byte	W02
	.byte	VOICE	, 6
	.byte	W24
song_0012_1_4:
	.byte		N44	, Bn3, v127
	.byte		N44	, Ds4
	.byte	W48
	.byte			Fs3
	.byte		N44	, Bn3
	.byte	W48
	.byte	PEND
song_0012_1_5:
	.byte		N22	, Ds4, v127
	.byte		N22	, Fs4
	.byte	W24
	.byte		N11	, Cs4
	.byte		N11	, En4
	.byte	W12
	.byte		N56	, Bn3
	.byte		N56	, Ds4
	.byte	W60
	.byte	PEND
song_0012_1_6:
	.byte		N44	, Gs3, v127
	.byte		N44	, Cs4
	.byte	W48
	.byte			En3
	.byte		N44	, Gs3
	.byte	W48
	.byte	PEND
	.byte		N22	
	.byte		N22	, Bn3
	.byte	W24
	.byte		N11	, Fs3
	.byte		N11	, As3
	.byte	W12
	.byte		N23	, Fs3
	.byte		N23	, As3
	.byte	W24
	.byte		N11	, Gs3
	.byte		N11	, Bn3
	.byte	W12
	.byte		N22	, As3
	.byte		N22	, Cs4
	.byte	W24
	.byte	PATT	
		.word	song_0012_1_4
	.byte	PATT	
		.word	song_0012_1_5
	.byte	PATT	
		.word	song_0012_1_6
	.byte		N22	, Fs3, v127
	.byte		N22	, Bn3
	.byte	W24
	.byte			Fs3
	.byte		N22	, As3
	.byte	W24
	.byte			En3
	.byte		N22	, Gs3
	.byte	W24
	.byte			En3
	.byte		N22	, As3
	.byte	W24
	.byte		N96	, Ds3
	.byte		TIE	, Bn3
	.byte	W96
	.byte		N92	, En3
	.byte	W92
	.byte	W03
	.byte		EOT	, Bn3
	.byte	W01
	.byte		N92	, As2
	.byte		N92	, Ds3
	.byte	W96
	.byte		N44	, Gs2
	.byte		N44	, Cs3
	.byte	W60
	.byte		N12	, Fs3
	.byte	W12
	.byte			Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte	GOTO	
		.word	song_0012_1_7
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0012_2
song_0012_2:	@ 0x087D68E3
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
song_0012_2_6:
	.byte	W24
	.byte		N12	, Ds3, v127
	.byte		N12	, Fs3
	.byte	W36
	.byte			Ds3
	.byte		N12	, Fs3
	.byte	W36
	.byte	PEND
	.byte	W24
	.byte			En3
	.byte		N12	, Gs3
	.byte	W36
	.byte			En3
	.byte		N12	, Gs3
	.byte	W36
	.byte	W24
	.byte			Fs3
	.byte		N12	, As3
	.byte	W36
	.byte			Fs3
	.byte		N12	, As3
	.byte	W36
	.byte	W24
	.byte			En3
	.byte		N12	, Gs3
	.byte	W24
	.byte	W02
	.byte		N44	, Cs3
	.byte	W01
	.byte			Fs3
	.byte	W44
	.byte	W01
song_0012_2_1:
	.byte		N11	, Bn1, v127
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte		N23	, Ds3
	.byte	W24
	.byte		N11	, Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Ds3
	.byte	W06
	.byte	BEND	, c_v+34
	.byte	W06
	.byte	PEND
song_0012_2_2:
	.byte	BEND	, c_v
	.byte		N11	, Ds3, v127
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte		N23	, Bn1
	.byte	W24
	.byte		N11	, Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte	PEND
song_0012_2_3:
	.byte		N11	, Cs2, v127
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N23	, En3
	.byte	W24
	.byte		N11	, Gs2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte			En3
	.byte	W12
	.byte	PEND
song_0012_2_5:
	.byte		N11	, Fs1, v127
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N23	, Fs3
	.byte	W24
	.byte		N11	, As2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte			En3
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0012_2_1
	.byte	PATT	
		.word	song_0012_2_2
	.byte	PATT	
		.word	song_0012_2_3
	.byte		N11	, Fs1, v127
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte		N32	, Fs3
	.byte	W36
	.byte		N22	, Fs2
	.byte	W24
	.byte			En2
	.byte	W24
	.byte		N12	, En3
	.byte		N12	, Gs3
	.byte	W36
	.byte			En3
	.byte		N12	, Gs3
	.byte	W24
	.byte		N11	, En2
	.byte	W12
	.byte		N22	, Ds2
	.byte	W24
	.byte		N12	, Ds3
	.byte		N12	, Fs3
	.byte	W36
	.byte			Ds3
	.byte		N12	, Fs3
	.byte	W24
	.byte		N11	, Ds2
	.byte	W12
	.byte		N22	, Cs2
	.byte	W24
	.byte		N12	, En3
	.byte		N12	, Gs3
	.byte	W36
	.byte			En3
	.byte		N12	, Gs3
	.byte	W24
	.byte		N11	, Cs2
	.byte	W12
	.byte		N22	, Bn1
	.byte	W24
	.byte		N12	, Bn2
	.byte		N12	, Ds3
	.byte	W36
	.byte			Bn2
	.byte		N12	, Ds3
	.byte	W24
	.byte		N11	, Bn1
	.byte	W12
	.byte		N22	, En2
	.byte	W24
	.byte		N12	, Bn2
	.byte		N12	, En3
	.byte	W36
	.byte			Bn2
	.byte		N12	, En3
	.byte	W24
	.byte		N11	, En2
	.byte	W12
	.byte		N22	, Ds2
	.byte	W24
	.byte		N12	, Cs3
	.byte		N12	, Ds3
	.byte	W36
	.byte			Cs3
	.byte		N12	, Ds3
	.byte	W24
	.byte		N11	, Ds2
	.byte	W12
song_0012_2_4:
	.byte		N22	, Cs2, v127
	.byte	W24
	.byte		N12	, Bn2
	.byte		N12	, En3
	.byte	W36
	.byte			Bn2
	.byte		N12	, En3
	.byte	W24
	.byte		N11	, Cs2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0012_2_4
	.byte		N22	, Fs1, v127
	.byte	W24
	.byte		N12	, Bn2
	.byte		N12	, Cs3
	.byte	W36
	.byte			Bn2
	.byte		N12	, Cs3
	.byte	W24
	.byte		N11	, Cs2
	.byte	W12
	.byte		N22	, Fs1
	.byte	W23
	.byte		N12	, Fs3
	.byte	W01
	.byte			As2
	.byte	W24
	.byte	W03
	.byte		N44	
	.byte		N44	, Fs3
	.byte	W44
	.byte	W01
	.byte	PATT	
		.word	song_0012_2_1
	.byte	PATT	
		.word	song_0012_2_2
	.byte	PATT	
		.word	song_0012_2_3
	.byte	PATT	
		.word	song_0012_2_5
	.byte	PATT	
		.word	song_0012_2_1
	.byte	PATT	
		.word	song_0012_2_2
	.byte	PATT	
		.word	song_0012_2_3
	.byte		N11	, Fs1, v127
	.byte	W12
	.byte			As2
	.byte	W12
	.byte		N22	, Cs3
	.byte	W24
	.byte	W02
	.byte		N48	
	.byte	W01
	.byte			Fs3
	.byte	W44
	.byte	W01
	.byte	W24
	.byte		N12	, Bn2
	.byte		N12	, Ds3
	.byte	W36
	.byte			Bn2
	.byte		N12	, Ds3
	.byte	W36
	.byte	W24
	.byte			Cs3
	.byte		N12	, En3
	.byte	W36
	.byte			Cs3
	.byte		N12	, En3
	.byte	W36
	.byte	PATT	
		.word	song_0012_2_6
	.byte	W24
	.byte		N12	, Cs3, v127
	.byte		N12	, En3
	.byte	W24
	.byte	W01
	.byte		N44	, Cs3
	.byte	W01
	.byte			Fs3
	.byte	W44
	.byte	W02
	.byte	GOTO	
		.word	song_0012_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0012_3
song_0012_3:	@ 0x087D6A70
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
	.byte		N92	, Ds3, v127
	.byte	W96
	.byte		N90	, En3
	.byte	W96
	.byte		N92	, Fs3
	.byte	W84
	.byte		N12	, Ds4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte		N22	, En4
	.byte	W24
	.byte		N32	, Cs4
	.byte	W48
song_0012_3_2:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N92	, Gs3, v127
	.byte	W96
	.byte			Fs3
	.byte	W96
	.byte			Gs3
	.byte	W96
	.byte			Fs3
	.byte	W96
	.byte			Gs3
	.byte	W96
	.byte			Fs3
	.byte	W96
	.byte			Gs3
	.byte	W96
	.byte		N92	
	.byte	W96
	.byte			Fs3
	.byte	W96
	.byte		N56	
	.byte	W60
	.byte		N12	, Fs4
	.byte	W12
	.byte			Bn4
	.byte	W12
	.byte			Cs5
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		N12	, Bn4
	.byte	W12
	.byte		TIE	, Ds5
	.byte	W60
	.byte	W48
	.byte		EOT	
	.byte	W12
	.byte		N12	, Gs4
	.byte	W12
	.byte			Cs5
	.byte	W12
	.byte			Ds5
	.byte	W12
song_0012_3_1:
	.byte		N24	, Ds5, v127
	.byte	W24
	.byte		N12	, En5
	.byte	W12
	.byte		TIE	, Cs5
	.byte	W60
	.byte	PEND
	.byte	W48
	.byte		EOT	
	.byte	W12
	.byte		N12	, Fs4
	.byte	W12
	.byte			Fs5
	.byte	W12
	.byte			En5
	.byte	W12
	.byte		N24	, Ds5
	.byte	W24
	.byte		N12	, Cs5
	.byte	W12
	.byte		TIE	, Ds5
	.byte	W60
	.byte	W48
	.byte		EOT	
	.byte	W12
	.byte		N12	, Gs4
	.byte	W12
	.byte			Cs5
	.byte	W12
	.byte			Ds5
	.byte	W12
	.byte	PATT	
		.word	song_0012_3_1
	.byte	W48
	.byte		EOT	, Cs5
	.byte		N24	, Bn4, v127
	.byte	W24
	.byte			As4
	.byte	W24
	.byte		TIE	, Bn4
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0012_3_2
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0012_4
song_0012_4:	@ 0x087D6B0B
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N44	, Fs1, v127
	.byte	W48
song_0012_4_1:
	.byte		N28	, Bn1, v127
	.byte	W36
	.byte		N36	
	.byte	W48
	.byte		N11	, Fs1
	.byte	W12
	.byte	PEND
song_0012_4_3:
	.byte		N28	, Bn1, v127
	.byte	W36
	.byte		N36	
	.byte	W48
	.byte		N11	
	.byte	W12
	.byte	PEND
song_0012_4_4:
	.byte		N28	, Cs2, v127
	.byte	W36
	.byte		N36	
	.byte	W48
	.byte		N11	, Gs1
	.byte	W12
	.byte	PEND
song_0012_4_5:
	.byte		N28	, Fs1, v127
	.byte	W36
	.byte		N36	
	.byte	W48
	.byte		N11	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0012_4_1
song_0012_4_6:
	.byte		N28	, Bn1, v127
	.byte	W36
	.byte		N36	
	.byte	W48
	.byte		N06	
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte	PEND
song_0012_4_7:
	.byte		N28	, Cs2, v127
	.byte	W36
	.byte		N36	
	.byte	W48
	.byte		N06	, Gs1
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte	PEND
	.byte		N36	, Fs1
	.byte	W36
	.byte		N05	, Bn1
	.byte	W06
	.byte			Cs2
	.byte	W06
	.byte		N22	, Fs2
	.byte	W24
	.byte			Fn2
	.byte	W24
song_0012_4_2:
	.byte		N32	, En2, v127
	.byte	W36
	.byte			Bn1
	.byte	W36
	.byte		N22	, En2
	.byte	W24
	.byte	PEND
	.byte		N32	, Ds2
	.byte	W36
	.byte			As2
	.byte	W36
	.byte		N22	, Ds2
	.byte	W24
	.byte		N32	, Cs2
	.byte	W36
	.byte			Gs2
	.byte	W36
	.byte		N22	, Cs2
	.byte	W24
	.byte			Bn1
	.byte	W24
	.byte			Cs2
	.byte	W24
	.byte			Ds2
	.byte	W24
	.byte			Fs2
	.byte	W24
	.byte	PATT	
		.word	song_0012_4_2
	.byte		N32	, Ds2, v127
	.byte	W36
	.byte			As1
	.byte	W36
	.byte		N22	, Ds2
	.byte	W24
	.byte		N32	, Cs2
	.byte	W36
	.byte		N32	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N11	, Gs2
	.byte	W12
	.byte		N06	, Cs3
	.byte	W06
	.byte			Gs2
	.byte	W06
	.byte		N22	, Cs2
	.byte	W24
	.byte		N32	
	.byte	W36
	.byte		N01	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte		N28	, Fs2
	.byte	W36
	.byte		N32	
	.byte	W36
	.byte		N01	, Cs2
	.byte	W12
	.byte	BEND	, c_v-64
	.byte		N12	
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
song_0012_4_8:
	.byte		N44	, Fs1, v127
	.byte	W48
	.byte		N44	
	.byte	W48
	.byte	PEND
	.byte	PATT	
		.word	song_0012_4_1
	.byte	PATT	
		.word	song_0012_4_3
	.byte	PATT	
		.word	song_0012_4_4
	.byte	PATT	
		.word	song_0012_4_5
	.byte	PATT	
		.word	song_0012_4_1
	.byte	PATT	
		.word	song_0012_4_6
	.byte	PATT	
		.word	song_0012_4_7
	.byte	PATT	
		.word	song_0012_4_8
song_0012_4_9:
	.byte		N68	, Bn1, v127
	.byte	W72
	.byte		N01	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0012_4_9
	.byte	PATT	
		.word	song_0012_4_9
	.byte		N32	, Bn1, v127
	.byte	W36
	.byte		N11	
	.byte	W12
	.byte		N44	, Fs1
	.byte	W48
	.byte	GOTO	
		.word	song_0012_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0012_5
song_0012_5:	@ 0x087D6C14
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
song_0012_5_1:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W36
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte		N06	, Cn1, v127
	.byte	W48
	.byte		N06	
	.byte	W48
song_0012_5_4:
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte		N01	, Dn1
	.byte	W01
	.byte		N06	
	.byte	W11
	.byte			Cn1
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Cn1
	.byte		N06	, Fn1
	.byte	W12
song_0012_5_2:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0012_5_2
	.byte	PATT	
		.word	song_0012_5_2
	.byte	PATT	
		.word	song_0012_5_2
	.byte	PATT	
		.word	song_0012_5_2
	.byte	PATT	
		.word	song_0012_5_2
	.byte	PATT	
		.word	song_0012_5_2
	.byte	PATT	
		.word	song_0012_5_2
	.byte	PATT	
		.word	song_0012_5_2
	.byte		N06	, Cn1, v127
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte		N17	, Gn2
	.byte	W48
song_0012_5_3:
	.byte		N06	, Cn1, v127
	.byte	W36
	.byte		N06	
	.byte	W36
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0012_5_3
	.byte	PATT	
		.word	song_0012_5_3
	.byte	PATT	
		.word	song_0012_5_3
	.byte	PATT	
		.word	song_0012_5_3
	.byte	PATT	
		.word	song_0012_5_3
	.byte	PATT	
		.word	song_0012_5_3
	.byte		N06	, Cn1, v127
	.byte	W36
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W48
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	PATT	
		.word	song_0012_5_1
	.byte	GOTO	
		.word	song_0012_5_4
	.byte	FINE

	.align 2
	.global song_0012
song_0012:	@ 0x087D6D04
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0012_1		@ track
	.word	song_0012_2		@ track
	.word	song_0012_3		@ track
	.word	song_0012_4		@ track
	.word	song_0012_5		@ track
