	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0048_1
song_0048_1:	@ 0x087E1BDC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 4
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
song_0048_1_1:
	.byte	TEMPO	, 74
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N84	, Ds4, v127
	.byte	W96
	.byte		N72	, Dn4
	.byte	W84
	.byte		N06	, Cn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte		TIE	, Cn4
	.byte	W96
	.byte	W24
	.byte	W01
	.byte		EOT	
	.byte	W11
	.byte		N16	
	.byte	W24
	.byte		N04	
	.byte	W12
	.byte		N24	, Dn4
	.byte	W24
	.byte		N44	, Ds4
	.byte	W48
	.byte		TIE	, Gn4
	.byte	W48
	.byte	W72
	.byte	W02
	.byte		EOT	
	.byte	W10
	.byte		N06	, Ds4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		TIE	, Gn4
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W36
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N48	
	.byte	W48
	.byte	W36
	.byte		N04	, As4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N30	
	.byte	W36
	.byte		N06	, Gn4
	.byte	W12
	.byte		N16	, Cn5
	.byte	W96
	.byte	W96
	.byte		N96	, Cn4
	.byte	W96
	.byte			As3
	.byte	W96
	.byte		TIE	, Gs3
	.byte	W96
	.byte	W60
	.byte		EOT	
	.byte	W36
	.byte		N96	, Cn4
	.byte	W96
	.byte			As3
	.byte	W96
	.byte			Cn4
	.byte	W96
	.byte		N12	, As3
	.byte	W18
	.byte		N12	
	.byte	W18
	.byte		N12	
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		N18	
	.byte	W24
	.byte		N96	, Cn4
	.byte	W96
	.byte			As3
	.byte	W96
	.byte		TIE	, Gs3
	.byte	W96
	.byte	W88
	.byte		EOT	
	.byte	W08
	.byte		N96	, Cn4
	.byte	W96
	.byte			As3
	.byte	W96
	.byte		TIE	, Cn4
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte		N18	, Gs4
	.byte	W18
	.byte			Gn4
	.byte	W18
	.byte		N66	, Fn4
	.byte	W60
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N16	, Gn4
	.byte	W16
	.byte			As4
	.byte	W16
	.byte			Gs4
	.byte	W16
	.byte		N18	
	.byte	W18
	.byte			Gn4
	.byte	W18
	.byte		N48	, Fn4
	.byte	W48
	.byte		N12	, Dn4
	.byte	W12
	.byte		N06	, Ds4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		N84	, Gn4
	.byte	W84
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0048_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0048_2
song_0048_2:	@ 0x087E1C9E
	.byte	KEYSH	, 0
	.byte	VOICE	, 5
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
song_0048_2_1:
	.byte	W24
	.byte		N08	, Gn3, v127
	.byte	W19
	.byte		N03	
	.byte	W05
	.byte		TIE	, Gn4
	.byte	W48
	.byte	PEND
	.byte	W60
	.byte		EOT	
	.byte	W36
	.byte	PATT	
		.word	song_0048_2_1
	.byte	W60
	.byte		EOT	, Gn4
	.byte	W36
	.byte		N84	, Gn3, v127
	.byte	W96
	.byte		N72	, Fn3
	.byte	W84
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		TIE	, Ds3
	.byte	W96
	.byte	W24
	.byte	W01
	.byte		EOT	
	.byte	W11
	.byte		N16	
	.byte	W24
	.byte		N04	
	.byte	W12
	.byte		N24	, Fn3
	.byte	W24
	.byte		N92	, Gn3
	.byte	W96
	.byte		N72	, Dn4
	.byte	W84
	.byte		N06	, Fn3
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		TIE	, Ds3
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte	W12
	.byte		N01	, Fn2
	.byte	W12
	.byte		N12	, Cn3
	.byte	W12
	.byte		N01	, Fn2
	.byte	W12
	.byte		N12	, Cn3
	.byte	W12
	.byte		N01	, Fn2
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte			Fs2
	.byte	W06
song_0048_2_2:
	.byte		N12	, Fn3, v127
	.byte	W12
	.byte		N01	, As2
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N12	, Fn3
	.byte	W12
	.byte		N01	, As2
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N12	, Fn3
	.byte	W12
	.byte		N01	, As2
	.byte	W12
	.byte	PEND
	.byte			Cn3
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N12	, Gn3
	.byte	W12
	.byte		N01	, Cn3
	.byte	W12
	.byte		N12	, Gn3
	.byte	W12
	.byte		N01	, Cn3
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte	PATT	
		.word	song_0048_2_2
	.byte		N01	, Gs2, v127
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N12	, Ds3
	.byte	W12
	.byte		N01	, Gs2
	.byte	W12
	.byte		N12	, Ds3
	.byte	W12
	.byte		N01	, Gs2
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte	PATT	
		.word	song_0048_2_2
	.byte	W96
	.byte	W36
	.byte		N12	, Gn4, v127
	.byte		N12	, Ds5
	.byte	W24
	.byte			Fn4
	.byte		N12	, Dn5
	.byte	W24
	.byte			Dn4
	.byte		N12	, As4
	.byte	W12
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96	, Gs2
	.byte		N96	, Ds3
	.byte	W96
	.byte			As2
	.byte		N96	, Dn3
	.byte	W96
	.byte			Gs2
	.byte		N96	, Cn3
	.byte	W96
	.byte		N48	, As2
	.byte		N48	, Dn3
	.byte	W48
	.byte			As2
	.byte		N48	, Dn3
	.byte	W48
	.byte		N18	, Ds3
	.byte	W18
	.byte			Dn3
	.byte	W18
	.byte		N66	, Cn3
	.byte	W60
	.byte	W12
	.byte		N36	, As2
	.byte	W36
	.byte		N24	, Gs2
	.byte	W24
	.byte			Gn2
	.byte	W24
	.byte		N36	, Gs2
	.byte	W36
	.byte		N06	, Gn2
	.byte	W06
	.byte			Gs2
	.byte	W06
	.byte		N48	, Ds3
	.byte	W48
	.byte		N72	, Dn3
	.byte	W72
	.byte		N24	, Fn3
	.byte	W24
	.byte		TIE	, Ds3
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte	W96
	.byte	GOTO	
		.word	song_0048_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0048_3
song_0048_3:	@ 0x087E1DB2
	.byte	KEYSH	, 0
	.byte	VOICE	, 2
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
song_0048_3_1:
	.byte		N16	, Cn2, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte	PEND
song_0048_3_2:
	.byte		N16	, Cn2, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0048_3_1
	.byte	PATT	
		.word	song_0048_3_2
	.byte	PATT	
		.word	song_0048_3_1
	.byte	PATT	
		.word	song_0048_3_2
	.byte	PATT	
		.word	song_0048_3_1
	.byte	PATT	
		.word	song_0048_3_2
	.byte	PATT	
		.word	song_0048_3_1
	.byte	PATT	
		.word	song_0048_3_2
	.byte	PATT	
		.word	song_0048_3_1
	.byte	PATT	
		.word	song_0048_3_2
	.byte		N16	, Fn1, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			As1
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PATT	
		.word	song_0048_3_1
	.byte		N16	, As1, v127
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			As1
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte			Gn1
	.byte	W24
	.byte		N16	
	.byte	W24
song_0048_3_3:
	.byte		N08	, Cn2, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte	PATT	
		.word	song_0048_3_3
song_0048_3_4:
	.byte		N08	, As1, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0048_3_5:
	.byte		N08	, Gs1, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
song_0048_3_6:
	.byte		N08	, As1, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0048_3_3
	.byte	PATT	
		.word	song_0048_3_4
	.byte	PATT	
		.word	song_0048_3_5
song_0048_3_7:
	.byte		N08	, Gn1, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0048_3_3
	.byte	PATT	
		.word	song_0048_3_4
	.byte	PATT	
		.word	song_0048_3_5
	.byte	PATT	
		.word	song_0048_3_6
	.byte	PATT	
		.word	song_0048_3_3
	.byte	PATT	
		.word	song_0048_3_4
	.byte	PATT	
		.word	song_0048_3_5
	.byte		N08	, Gs1, v127
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte			Fn1
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte	PATT	
		.word	song_0048_3_7
	.byte	PATT	
		.word	song_0048_3_5
	.byte	PATT	
		.word	song_0048_3_7
	.byte	PATT	
		.word	song_0048_3_5
	.byte	PATT	
		.word	song_0048_3_4
	.byte	PATT	
		.word	song_0048_3_5
	.byte	PATT	
		.word	song_0048_3_4
	.byte		TIE	, Gs1, v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte		N16	
	.byte	W24
	.byte		N16	
	.byte	W24
	.byte		N24	
	.byte	W36
	.byte		N12	, Gn1
	.byte	W12
	.byte	GOTO	
		.word	song_0048_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0048_4
song_0048_4:	@ 0x087E1F39
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
song_0048_4_1:
	.byte		N08	, Cn5, v127
	.byte	W12
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N08	
	.byte	W12
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N08	
	.byte	W12
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N08	
	.byte	W12
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0048_4_1
	.byte	PATT	
		.word	song_0048_4_1
	.byte	PATT	
		.word	song_0048_4_1
song_0048_4_2:
	.byte		N06	, Gn4, v127
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte	PEND
song_0048_4_3:
	.byte		N06	, Fn4, v127
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte	PEND
song_0048_4_4:
	.byte		N06	, Gn4, v127
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte	PEND
	.byte			Cn5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte	PATT	
		.word	song_0048_4_2
	.byte	PATT	
		.word	song_0048_4_3
	.byte	PATT	
		.word	song_0048_4_4
	.byte		N06	, Cn5, v127
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		N96	, Gn4
	.byte	W96
	.byte		N36	, Fn4
	.byte	W36
	.byte			Ds4
	.byte	W36
	.byte		N24	, Dn4
	.byte	W24
	.byte		N96	, Ds4
	.byte	W96
	.byte		N36	, Dn4
	.byte	W36
	.byte			Ds4
	.byte	W36
	.byte		N24	, Fn4
	.byte	W23
	.byte		N92	, Gs4
	.byte	W01
	.byte	W96
	.byte			As4
	.byte	W96
	.byte		N16	, Cn5
	.byte	W24
	.byte		N06	, Gn3
	.byte	W06
	.byte			Ds3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			As2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Fn2
	.byte	W06
	.byte			Ds2
	.byte	W06
	.byte		N08	, Cn2
	.byte		N06	, Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Ds3
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			As2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Ds3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			As2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte		N12	, Gn4
	.byte	W12
	.byte		N04	, Gs4
	.byte	W03
	.byte			As4
	.byte	W03
	.byte			Cn5
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte		N96	, Ds5
	.byte	W96
song_0048_4_5:
	.byte		N84	, Dn5, v127
	.byte	W84
	.byte	W01
	.byte		N06	, Cn5
	.byte	W06
	.byte			As4
	.byte	W05
	.byte	PEND
	.byte		TIE	, Cn5
	.byte	W96
	.byte	W60
	.byte		EOT	
	.byte	W12
	.byte		N12	, Gn4
	.byte	W15
	.byte		N04	, As4
	.byte	W03
	.byte			Cn5
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte		N96	, Ds5
	.byte	W96
song_0048_4_6:
	.byte		N84	, Dn5, v127
	.byte	W84
	.byte	W01
	.byte		N06	, Ds5
	.byte	W06
	.byte			Fn5
	.byte	W05
	.byte	PEND
	.byte		N96	, Gn5
	.byte	W96
	.byte		N12	, Fn5
	.byte	W18
	.byte		N12	
	.byte	W18
	.byte		N12	
	.byte	W12
	.byte		N18	
	.byte	W24
	.byte		N12	, Gn4
	.byte	W12
	.byte		N03	, Gs4
	.byte	W03
	.byte		N02	, As4
	.byte	W03
	.byte		N03	, Cn5
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte		N96	, Ds5
	.byte	W96
	.byte	PATT	
		.word	song_0048_4_5
	.byte		TIE	, Cn5, v127
	.byte	W96
	.byte	W60
	.byte		EOT	
	.byte	W12
	.byte		N12	, Gn4
	.byte	W12
	.byte		N02	, Gs4
	.byte	W03
	.byte			As4
	.byte	W03
	.byte		N04	, Cn5
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte		N96	, Ds5
	.byte	W96
	.byte	PATT	
		.word	song_0048_4_6
	.byte		N96	, Gn5, v127
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N18	, Ds5
	.byte	W18
	.byte			Dn5
	.byte	W18
	.byte		N66	, Cn5
	.byte	W60
	.byte	W12
	.byte		N36	, As4
	.byte	W36
	.byte		N24	, Gs4
	.byte	W24
	.byte			Gn4
	.byte	W24
	.byte		N36	, Gs4
	.byte	W36
	.byte		N06	, Gn4
	.byte	W06
	.byte			Gs4
	.byte	W06
	.byte		N48	, Ds5
	.byte	W48
	.byte		N72	, Dn5
	.byte	W72
	.byte		N24	, As4
	.byte	W24
	.byte		TIE	, Cn5
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte		N12	, Cn4
	.byte	W12
	.byte		N06	, Dn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte		N04	, Fn4
	.byte	W04
	.byte			Fs4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			Gs4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			As4
	.byte	W04
	.byte		N24	, Cn5
	.byte	W48
	.byte	GOTO	
		.word	song_0048_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0048_5
song_0048_5:	@ 0x087E213F
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v070
	.byte	PAN	, c_v
	.byte	W24
song_0048_5_1:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0048_5_1
	.byte	PATT	
		.word	song_0048_5_1
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Cn2
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			An1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Fn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Cs2
	.byte	W18
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
song_0048_5_2:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte	PATT	
		.word	song_0048_5_2
	.byte		N06	, Cn1, v127
	.byte		N20	, Cs2
	.byte	W18
	.byte		N06	, Cn1
	.byte	W06
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte		N06	, Dn1
	.byte	W18
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte		N22	, Cs2
	.byte	W24
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W24
song_0048_5_3:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Dn1
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
	.byte	PATT	
		.word	song_0048_5_3
song_0048_5_4:
	.byte		N06	, Cn1, v127
	.byte	W84
	.byte		N06	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0048_5_4
	.byte	PATT	
		.word	song_0048_5_4
	.byte	PATT	
		.word	song_0048_5_4
song_0048_5_5:
	.byte		N06	, Cn1, v127
	.byte	W48
	.byte			Dn1
	.byte	W36
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0048_5_5
	.byte	PATT	
		.word	song_0048_5_5
	.byte	PATT	
		.word	song_0048_5_5
	.byte		N06	, Dn1, v127
	.byte		N21	, Cs2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte	PATT	
		.word	song_0048_5_1
	.byte	PATT	
		.word	song_0048_5_1
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W48
	.byte	GOTO	
		.word	song_0048_5_1
	.byte	FINE

	.align 2
	.global song_0048
song_0048:	@ 0x087E22AC
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0048_1		@ track
	.word	song_0048_2		@ track
	.word	song_0048_3		@ track
	.word	song_0048_4		@ track
	.word	song_0048_5		@ track
