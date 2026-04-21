	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0046_1
song_0046_1:	@ 0x087E0DFC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 68
	.byte	VOICE	, 8
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W06
song_0046_1_6:
	.byte		N96	, Gn4, v127
	.byte	W96
song_0046_1_1:
	.byte		N24	, As4, v127
	.byte	W24
	.byte			Gs4
	.byte	W24
	.byte			Gn4
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte	PEND
	.byte		N96	, Gn4
	.byte	W96
	.byte		N24	, Ds4
	.byte	W24
	.byte			Dn4
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte			Ds4
	.byte	W24
	.byte		N96	, Gn4
	.byte	W96
	.byte	PATT	
		.word	song_0046_1_1
	.byte		N96	, Gn4, v127
	.byte	W96
	.byte		N24	, Ds4
	.byte	W24
	.byte		N12	, Dn4
	.byte	W12
	.byte			Fn4
	.byte	W60
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96	, Gn4
	.byte	W96
song_0046_1_2:
	.byte		N72	, Fn4, v127
	.byte	W72
	.byte		N24	, Dn4
	.byte	W24
	.byte	PEND
	.byte		N96	, Cn4
	.byte	W96
	.byte		N48	, Dn4
	.byte	W48
	.byte		N16	, Fn4
	.byte	W16
	.byte		N30	
	.byte	W32
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0046_1_3:
	.byte	W24
	.byte		N24	, Gn4, v127
	.byte	W24
	.byte			Fn5
	.byte	W24
	.byte			Ds5
	.byte	W24
	.byte	PEND
song_0046_1_4:
	.byte		N24	, Cn4, v127
	.byte	W24
	.byte		N08	
	.byte	W72
	.byte	PEND
	.byte	W96
	.byte	W24
	.byte			Cn5
	.byte	W72
	.byte	W48
	.byte		N24	, Dn4
	.byte	W24
	.byte			As3
	.byte	W24
song_0046_1_5:
	.byte		N24	, Ds4, v127
	.byte	W24
	.byte		N08	, Cn4
	.byte	W72
	.byte	PEND
	.byte	W96
	.byte	W24
	.byte			Cn5
	.byte	W72
	.byte	W72
	.byte		N22	, As3
	.byte	W24
	.byte		N96	, Gn5
	.byte	W96
	.byte			Gs5
	.byte	W96
	.byte			Gn5
	.byte	W96
	.byte		N24	, Ds5
	.byte	W24
	.byte			Dn5
	.byte	W24
	.byte			Cn5
	.byte	W24
	.byte			Dn5
	.byte	W24
	.byte		N96	, Gn5
	.byte	W96
	.byte			Gs5
	.byte	W96
	.byte			Fn5
	.byte	W96
	.byte		N48	, Gn5
	.byte	W96
	.byte		N96	, Gn4
	.byte	W96
	.byte	PATT	
		.word	song_0046_1_2
	.byte		N96	, Cn4, v127
	.byte	W96
	.byte		N48	, Dn4
	.byte	W48
	.byte			Fn4
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0046_1_3
	.byte	PATT	
		.word	song_0046_1_4
	.byte	W96
	.byte	W24
	.byte		N08	, Cn5, v127
	.byte	W72
	.byte	W48
	.byte		N48	, Dn4
	.byte	W48
	.byte	PATT	
		.word	song_0046_1_5
	.byte	W96
	.byte	W24
	.byte		N08	, Cn5, v127
	.byte	W72
	.byte	W72
	.byte		N20	, As3
	.byte	W24
	.byte	GOTO	
		.word	song_0046_1_6
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0046_2
song_0046_2:	@ 0x087E0EE1
	.byte	KEYSH	, 0
	.byte	VOICE	, 4
	.byte	VOL	, v100
	.byte	PAN	, c_v
	.byte	W06
song_0046_2_8:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0046_2_1:
	.byte	W24
	.byte		N12	, Cn3, v127
	.byte	W18
	.byte		N78	, Gn3
	.byte	W54
	.byte	PEND
song_0046_2_2:
	.byte	W24
	.byte		N12	, Cn3, v127
	.byte	W18
	.byte		N30	, Gs3
	.byte	W36
	.byte		N06	
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Gs3
	.byte	W06
	.byte	PEND
song_0046_2_3:
	.byte		N06	, Gn3, v127
	.byte	W06
	.byte			Fn3
	.byte	W12
	.byte		TIE	, Ds3
	.byte	W78
	.byte	PEND
	.byte	W24
	.byte		EOT	
	.byte	W72
	.byte	PATT	
		.word	song_0046_2_1
	.byte	PATT	
		.word	song_0046_2_2
song_0046_2_4:
	.byte		N06	, Gn3, v127
	.byte	W06
	.byte			Fn3
	.byte	W12
	.byte		TIE	, Dn4
	.byte	W78
	.byte	PEND
	.byte	W24
	.byte		EOT	
	.byte	W72
	.byte		N72	, Cn4
	.byte	W72
	.byte		N12	
	.byte	W12
	.byte			Dn4
	.byte	W12
song_0046_2_6:
	.byte		N12	, Ds4, v127
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N18	, Ds4
	.byte	W18
	.byte			Dn4
	.byte	W18
	.byte		N36	, As3
	.byte	W36
	.byte	PEND
	.byte	W24
	.byte		N18	, Cn4
	.byte	W18
	.byte		N66	, Gn4
	.byte	W54
	.byte	W12
	.byte		N06	, Fn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte		N36	, Dn4
	.byte	W36
	.byte	W01
	.byte		N01	, Ds4
	.byte	W02
	.byte			En4
	.byte	W03
	.byte			Fs4
	.byte	W01
	.byte			Gn4
	.byte	W02
	.byte			Gs4
	.byte	W01
	.byte			An4
	.byte	W02
	.byte		N48	, As4
	.byte	W24
	.byte	PATT	
		.word	song_0046_2_1
	.byte	PATT	
		.word	song_0046_2_2
	.byte	PATT	
		.word	song_0046_2_3
	.byte	W24
	.byte		EOT	, Ds3
	.byte	W72
	.byte	PATT	
		.word	song_0046_2_1
	.byte	PATT	
		.word	song_0046_2_2
	.byte	PATT	
		.word	song_0046_2_4
	.byte	W24
	.byte		N24	, Gn3, v127
	.byte	W12
	.byte		EOT	, Dn4
	.byte	W12
	.byte		N24	, Fn4
	.byte	W24
	.byte			Ds4
	.byte	W24
	.byte	W84
	.byte		N12	, Cn4
	.byte	W12
song_0046_2_5:
	.byte		N04	, Gn4, v127
	.byte	W12
	.byte		TIE	, Fn4
	.byte	W84
	.byte	PEND
	.byte	W24
	.byte		EOT	
	.byte	W60
	.byte		N12	, Cn4
	.byte	W12
	.byte		N10	, Gn4
	.byte	W12
	.byte		N60	, Fn4
	.byte	W84
	.byte	W84
	.byte		N12	, Cn4
	.byte	W12
	.byte	PATT	
		.word	song_0046_2_5
	.byte	W24
	.byte		EOT	, Fn4
	.byte	W60
	.byte		N12	, Cn4, v127
	.byte	W12
song_0046_2_7:
	.byte		N04	, Gn4, v127
	.byte	W12
	.byte		N60	, Fn4
	.byte	W84
	.byte	PEND
	.byte	PATT	
		.word	song_0046_2_1
	.byte	PATT	
		.word	song_0046_2_2
	.byte	PATT	
		.word	song_0046_2_3
	.byte	W24
	.byte		EOT	, Ds3
	.byte	W72
	.byte	PATT	
		.word	song_0046_2_1
	.byte	PATT	
		.word	song_0046_2_2
	.byte	PATT	
		.word	song_0046_2_4
	.byte	W24
	.byte		EOT	, Dn4
	.byte	W72
	.byte		N24	, Ds4, v127
	.byte	W24
	.byte		N48	, Cn4
	.byte	W48
	.byte		N12	
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte	PATT	
		.word	song_0046_2_6
	.byte		N24	, Gn3, v127
	.byte	W24
	.byte		N18	, Cn4
	.byte	W18
	.byte		N66	, Gn4
	.byte	W54
	.byte	W12
	.byte		N06	, Fn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte		N36	, Dn4
	.byte	W36
	.byte	W01
	.byte		N01	, Ds4
	.byte	W02
	.byte			En4
	.byte	W01
	.byte			Fn4
	.byte	W02
	.byte			Fs4
	.byte	W01
	.byte			Gn4
	.byte	W02
	.byte			Gs4
	.byte	W01
	.byte			An4
	.byte	W02
	.byte		N48	, As4
	.byte	W24
	.byte	PATT	
		.word	song_0046_2_1
	.byte	PATT	
		.word	song_0046_2_2
	.byte	PATT	
		.word	song_0046_2_3
	.byte	W24
	.byte		EOT	, Ds3
	.byte	W72
	.byte	PATT	
		.word	song_0046_2_1
	.byte	PATT	
		.word	song_0046_2_2
	.byte	PATT	
		.word	song_0046_2_4
	.byte	W24
	.byte		N24	, Gn3, v127
	.byte	W12
	.byte		EOT	, Dn4
	.byte	W12
	.byte		N24	, Fn4
	.byte	W24
	.byte			Ds4
	.byte	W24
	.byte	W84
	.byte		N12	, Cn4
	.byte	W12
	.byte	PATT	
		.word	song_0046_2_5
	.byte	W24
	.byte		EOT	, Fn4
	.byte	W60
	.byte		N12	, Cn4, v127
	.byte	W12
	.byte		N08	, Gn4
	.byte	W12
	.byte		N60	, Fn4
	.byte	W60
	.byte		N23	, Dn4
	.byte	W24
	.byte		N24	, Cn5
	.byte	W84
	.byte		N12	, Cn4
	.byte	W12
	.byte	PATT	
		.word	song_0046_2_5
	.byte	W24
	.byte		EOT	, Fn4
	.byte	W60
	.byte		N12	, Cn4, v127
	.byte	W12
	.byte	PATT	
		.word	song_0046_2_7
	.byte	GOTO	
		.word	song_0046_2_8
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0046_3
song_0046_3:	@ 0x087E1088
	.byte	KEYSH	, 0
	.byte	VOICE	, 14
	.byte	VOL	, v070
	.byte	PAN	, c_v
	.byte	W06
song_0046_3_8:
	.byte		N96	, As2, v127
	.byte		N96	, Ds3
	.byte	W96
song_0046_3_1:
	.byte		N48	, Cn3, v127
	.byte		N48	, Ds3
	.byte	W48
	.byte		N12	, Dn3
	.byte		N12	, Fn3
	.byte	W12
	.byte		N06	, Dn3
	.byte		N06	, Gn3
	.byte	W06
	.byte			Dn3
	.byte		N06	, Fn3
	.byte	W12
	.byte		N18	, As2
	.byte		N18	, Ds3
	.byte	W18
	.byte	PEND
	.byte		N96	, As2
	.byte		N96	, Ds3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_1
	.byte		N96	, As2, v127
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_1
	.byte		N96	, As2, v127
	.byte		N96	, Dn3
	.byte	W96
	.byte		N36	, Cn3
	.byte		N36	, Ds3
	.byte	W36
	.byte		N12	, Dn4
	.byte		N12	, Fn4
	.byte	W18
	.byte		N06	, Gn2
	.byte	W06
	.byte			Dn4
	.byte		N06	, Gn4
	.byte	W06
	.byte			Dn4
	.byte		N06	, Fn4
	.byte	W12
	.byte		N18	, As3
	.byte		N18	, Ds4
	.byte	W18
	.byte		N96	, As2
	.byte		N96	, Dn3
	.byte	W96
song_0046_3_2:
	.byte		N48	, Cn3, v127
	.byte		N48	, Ds3
	.byte	W48
	.byte			Dn3
	.byte		N48	, Fn3
	.byte	W48
	.byte	PEND
	.byte		N96	, Ds3
	.byte		N96	, Gn3
	.byte	W96
song_0046_3_3:
	.byte		N48	, Cn3, v127
	.byte		N48	, Ds3
	.byte	W54
	.byte		N06	, Dn3
	.byte		N06	, Fn3
	.byte	W12
	.byte			Dn3
	.byte		N06	, Fn3
	.byte	W12
	.byte		N18	, Dn3
	.byte		N18	, Fn3
	.byte	W18
	.byte	PEND
	.byte		N96	, As2
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_2
	.byte		N96	, Ds3, v127
	.byte		N96	, Gn3
	.byte	W96
	.byte		N48	, Dn3
	.byte		N48	, Gn3
	.byte	W54
	.byte		N06	, Fn3
	.byte		N06	, As3
	.byte	W12
	.byte			Fn3
	.byte		N06	, As3
	.byte	W12
	.byte		N18	, Dn3
	.byte		N18	, Fn3
	.byte	W18
	.byte		N96	, Ds3
	.byte		N96	, Gn3
	.byte	W96
	.byte			Dn3
	.byte		N96	, Fn3
	.byte	W96
	.byte			Ds3
	.byte		N96	, Gn3
	.byte	W96
song_0046_3_6:
	.byte		N48	, Dn3, v127
	.byte		N48	, Fn3
	.byte	W48
	.byte			Dn3
	.byte		N48	, Fn3
	.byte	W48
	.byte	PEND
	.byte		N96	, As2
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_2
	.byte		N96	, Ds3, v127
	.byte		N96	, Gn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_3
	.byte		N96	, As2, v127
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_2
	.byte		N96	, Ds3, v127
	.byte		N96	, Gn3
	.byte	W96
song_0046_3_7:
	.byte		N48	, Dn3, v127
	.byte		N48	, Gn3
	.byte	W54
	.byte		N06	, Fn3
	.byte		N06	, As3
	.byte	W12
	.byte			Fn3
	.byte		N06	, As3
	.byte	W12
	.byte		N18	, Fn3
	.byte		N18	, As3
	.byte	W18
	.byte	PEND
song_0046_3_4:
	.byte		N18	, Gn3, v127
	.byte		N18	, Cn4
	.byte	W18
	.byte		N06	, Cn2
	.byte	W06
	.byte		N12	, As2
	.byte		N12	, Dn3
	.byte	W12
	.byte		N06	, Cn2
	.byte	W06
	.byte		N12	, As2
	.byte		N12	, Fn3
	.byte	W12
	.byte		N06	, Cn2
	.byte	W06
	.byte			As2
	.byte		N06	, Ds3
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte			As2
	.byte		N06	, Fn3
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte		N24	, Fn3
	.byte		N24	, As3
	.byte	W12
	.byte	PEND
	.byte	W12
	.byte		N06	, Dn4
	.byte		N06	, Fn4
	.byte	W06
	.byte			Dn4
	.byte		N06	, Fn4
	.byte	W12
	.byte			As3
	.byte		N06	, Dn4
	.byte	W06
	.byte			As3
	.byte		N06	, Dn4
	.byte	W12
	.byte			Fn3
	.byte		N06	, As3
	.byte	W06
	.byte			Fn3
	.byte		N06	, As3
	.byte	W06
	.byte			As2
	.byte		N06	, Dn3
	.byte	W06
	.byte		N12	, As2
	.byte		N12	, Fn3
	.byte	W12
	.byte			As2
	.byte		N12	, Dn3
	.byte	W12
	.byte		N06	, Gn1
	.byte	W06
	.byte	PATT	
		.word	song_0046_3_4
song_0046_3_5:
	.byte	W12
	.byte		N06	, Dn4, v127
	.byte		N06	, Fn4
	.byte	W06
	.byte			Dn4
	.byte		N06	, Fn4
	.byte	W12
	.byte			As3
	.byte		N06	, Dn4
	.byte	W06
	.byte			As3
	.byte		N06	, Dn4
	.byte	W12
	.byte			Fn3
	.byte		N06	, As3
	.byte	W06
	.byte			Fn3
	.byte		N06	, As3
	.byte	W06
	.byte			As2
	.byte		N06	, Dn3
	.byte	W06
	.byte		N12	, As2
	.byte		N12	, Fn3
	.byte	W12
	.byte			As2
	.byte		N12	, Dn3
	.byte	W18
	.byte	PEND
	.byte	PATT	
		.word	song_0046_3_4
	.byte	PATT	
		.word	song_0046_3_5
	.byte	PATT	
		.word	song_0046_3_4
	.byte	PATT	
		.word	song_0046_3_5
	.byte		N96	, As2, v127
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_2
	.byte		N96	, Ds3, v127
	.byte		N96	, Gn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_3
	.byte		N96	, As2, v127
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_2
	.byte		N96	, Ds3, v127
	.byte		N96	, Gn3
	.byte	W96
	.byte		N48	, Dn3
	.byte		N48	, Gn3
	.byte	W54
	.byte		N06	, Fn3
	.byte		N06	, As3
	.byte	W12
	.byte			Fn3
	.byte		N06	, As3
	.byte	W12
	.byte			Fn3
	.byte		N06	, As3
	.byte	W12
	.byte			Fn3
	.byte		N06	, As3
	.byte	W06
	.byte		N96	, Ds3
	.byte		N96	, Gn3
	.byte	W96
	.byte			Dn3
	.byte		N96	, Fn3
	.byte	W96
	.byte			Ds3
	.byte		N96	, Gn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_6
	.byte		N96	, As2, v127
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_2
	.byte		N96	, Ds3, v127
	.byte		N96	, Gn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_3
	.byte		N96	, As2, v127
	.byte		N96	, Dn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_2
	.byte		N96	, Ds3, v127
	.byte		N96	, Gn3
	.byte	W96
	.byte	PATT	
		.word	song_0046_3_7
	.byte	PATT	
		.word	song_0046_3_4
	.byte	PATT	
		.word	song_0046_3_5
	.byte	PATT	
		.word	song_0046_3_4
	.byte	PATT	
		.word	song_0046_3_5
	.byte	PATT	
		.word	song_0046_3_4
	.byte	PATT	
		.word	song_0046_3_5
	.byte	PATT	
		.word	song_0046_3_4
	.byte	PATT	
		.word	song_0046_3_5
	.byte	GOTO	
		.word	song_0046_3_8
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0046_4
song_0046_4:	@ 0x087E12C6
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W06
song_0046_4_1:
	.byte		N12	, Cn2, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N06	, As1
	.byte	W06
	.byte		N12	, Cn2
	.byte	W12
	.byte		N02	, Cn3
	.byte	W06
	.byte		N12	, As1
	.byte	W12
	.byte		N06	, Gn1
	.byte	W06
	.byte			As1
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte	PEND
song_0046_4_2:
	.byte		N12	, Gs1, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	, Ds1
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Gs1
	.byte	W06
	.byte		N12	, As1
	.byte	W18
	.byte		N06	, Fn1
	.byte	W06
	.byte		N01	, As1
	.byte	W06
	.byte		N06	, Fn1
	.byte	W06
	.byte			Gs1
	.byte	W06
	.byte			As1
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte		N12	, Gs1, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N18	
	.byte	W18
	.byte		N08	, As1
	.byte	W54
	.byte		N06	, Gn1
	.byte	W06
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
song_0046_4_4:
	.byte		N18	, Fn1, v127
	.byte	W18
	.byte		N12	, Fn2
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N06	, Ds2
	.byte	W06
	.byte			Fn2
	.byte	W06
	.byte		N01	, Fn1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	, Cn2
	.byte	W06
	.byte			Ds2
	.byte	W06
	.byte			Fn2
	.byte	W06
	.byte	PEND
song_0046_4_5:
	.byte		N18	, Gn1, v127
	.byte	W18
	.byte		N12	, Gn2
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte		N06	, Fn2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	, Gn2
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
song_0046_4_3:
	.byte		N18	, Gs1, v127
	.byte	W18
	.byte			Ds2
	.byte	W18
	.byte		N12	, Gn1
	.byte	W12
	.byte		N06	, Gs1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	, Gs2
	.byte	W06
	.byte		N01	, Gs1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			As1
	.byte	W06
	.byte			Gs1
	.byte	W06
	.byte	PEND
song_0046_4_10:
	.byte		N18	, As1, v127
	.byte	W18
	.byte			Fn2
	.byte	W18
	.byte		N12	, Gs1
	.byte	W12
	.byte		N06	, As1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Gs1
	.byte	W06
	.byte			As1
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0046_4_3
song_0046_4_11:
	.byte		N18	, As1, v127
	.byte	W18
	.byte			Fn2
	.byte	W18
	.byte		N12	, As1
	.byte	W12
	.byte		N06	, Gn1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	, Gn2
	.byte	W06
	.byte		N01	, Gn1
	.byte	W06
	.byte		N06	, Dn2
	.byte	W06
	.byte		N12	, Gn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_4
	.byte	PATT	
		.word	song_0046_4_5
song_0046_4_6:
	.byte		N12	, Cn2, v127
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N06	, As1
	.byte	W06
	.byte		N12	, Cn2
	.byte	W12
	.byte		N02	, Cn3
	.byte	W06
	.byte		N12	, Cn2
	.byte	W12
	.byte		N06	, Gn1
	.byte	W06
	.byte		N18	, As1
	.byte	W12
	.byte	PEND
song_0046_4_7:
	.byte	W18
	.byte		N06	, As1, v127
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Gs1
	.byte	W12
	.byte		N06	, As1
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Gs1
	.byte	W06
	.byte			As1
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0046_4_6
	.byte	PATT	
		.word	song_0046_4_7
	.byte	PATT	
		.word	song_0046_4_6
	.byte	PATT	
		.word	song_0046_4_7
	.byte	PATT	
		.word	song_0046_4_6
	.byte	PATT	
		.word	song_0046_4_7
song_0046_4_9:
	.byte		N84	, Cn2, v127
	.byte	W84
	.byte		N04	, Bn1
	.byte	W04
	.byte			As1
	.byte	W04
	.byte			An1
	.byte	W04
	.byte	PEND
song_0046_4_8:
	.byte		N48	, Gs1, v127
	.byte	W48
	.byte			As1
	.byte	W48
	.byte	PEND
	.byte		N96	, Cn2
	.byte	W96
	.byte	PATT	
		.word	song_0046_4_8
	.byte	PATT	
		.word	song_0046_4_9
	.byte	PATT	
		.word	song_0046_4_8
	.byte		N96	, Fn1, v127
	.byte	W96
	.byte		N42	, Gn1
	.byte	W42
	.byte		N03	, Fn1
	.byte	W03
	.byte			Fs1
	.byte	W03
	.byte		N06	, Gn1
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte		N01	, Gn1
	.byte	W06
	.byte		N06	, Gn2
	.byte	W06
	.byte		N01	, Gn1
	.byte	W06
	.byte		N06	, Gn2
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0046_4_3
	.byte	PATT	
		.word	song_0046_4_10
	.byte	PATT	
		.word	song_0046_4_3
	.byte	PATT	
		.word	song_0046_4_11
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_1
	.byte	PATT	
		.word	song_0046_4_2
	.byte	PATT	
		.word	song_0046_4_4
	.byte	PATT	
		.word	song_0046_4_5
	.byte	PATT	
		.word	song_0046_4_6
	.byte	PATT	
		.word	song_0046_4_7
	.byte	PATT	
		.word	song_0046_4_6
	.byte	PATT	
		.word	song_0046_4_7
	.byte	PATT	
		.word	song_0046_4_6
	.byte	PATT	
		.word	song_0046_4_7
	.byte	PATT	
		.word	song_0046_4_6
	.byte	PATT	
		.word	song_0046_4_7
	.byte	GOTO	
		.word	song_0046_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0046_5
song_0046_5:	@ 0x087E1513
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W06
song_0046_5_1:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W18
	.byte		N06	
	.byte	W60
	.byte			Cn1
	.byte		N21	, Cs2
	.byte	W18
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Fn1
	.byte	W12
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Cn1
	.byte		N30	, Cs2
	.byte	W18
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
song_0046_5_5:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte	PEND
	.byte		N06	
	.byte		N36	, An2
	.byte	W18
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
song_0046_5_6:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			Fn1
	.byte	W12
	.byte	PEND
song_0046_5_7:
	.byte		N06	, Cn1, v127
	.byte		N32	, Cs2
	.byte	W18
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
song_0046_5_2:
	.byte	W12
	.byte		N06	, Cn1, v127
	.byte	W12
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PEND
song_0046_5_3:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0046_5_2
	.byte	PATT	
		.word	song_0046_5_3
	.byte	PATT	
		.word	song_0046_5_2
	.byte	PATT	
		.word	song_0046_5_3
song_0046_5_8:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte	PEND
	.byte			Cn1
	.byte		N36	, Cs2
	.byte	W42
	.byte		N06	, Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W36
song_0046_5_4:
	.byte		N06	, Cn1, v127
	.byte	W42
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W36
	.byte	PEND
	.byte	PATT	
		.word	song_0046_5_4
	.byte		N06	, Cn1, v127
	.byte	W42
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte		N40	, An2
	.byte	W42
	.byte		N06	, Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W36
	.byte	PATT	
		.word	song_0046_5_4
	.byte	PATT	
		.word	song_0046_5_4
	.byte		N06	, Cn1, v127
	.byte	W42
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N24	, An2
	.byte	W18
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_5
	.byte		N06	, Cn1, v127
	.byte		N44	, An2
	.byte	W18
	.byte		N06	, Dn1
	.byte	W24
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W24
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_1
	.byte	PATT	
		.word	song_0046_5_6
	.byte	PATT	
		.word	song_0046_5_7
	.byte	PATT	
		.word	song_0046_5_2
	.byte	PATT	
		.word	song_0046_5_3
	.byte	PATT	
		.word	song_0046_5_2
	.byte	PATT	
		.word	song_0046_5_3
	.byte	PATT	
		.word	song_0046_5_2
	.byte	PATT	
		.word	song_0046_5_3
	.byte	PATT	
		.word	song_0046_5_8
	.byte	GOTO	
		.word	song_0046_5_1
	.byte	FINE

	.align 2
	.global song_0046
song_0046:	@ 0x087E1740
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0046_1		@ track
	.word	song_0046_2		@ track
	.word	song_0046_3		@ track
	.word	song_0046_4		@ track
	.word	song_0046_5		@ track
