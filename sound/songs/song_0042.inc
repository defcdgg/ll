	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0042_1
song_0042_1:	@ 0x087DF3E4
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 4
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	TEMPO	, 39
	.byte	W72
song_0042_1_6:
	.byte	VOICE	, 0
	.byte		N68	, Dn6, v127
	.byte	W72
song_0042_1_1:
	.byte		N60	, An5, v127
	.byte	W60
	.byte		N12	, Gn5
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0042_1_1
	.byte		N30	, Fn5, v127
	.byte	W36
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn6
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte		N72	, Dn6
	.byte	W72
	.byte		N48	, Cn6
	.byte	W48
	.byte		N24	, En6
	.byte	W24
	.byte		N88	, Dn6
	.byte	W72
	.byte	W48
	.byte	VOICE	, 4
	.byte	W12
	.byte		N12	, An3
	.byte	W12
song_0042_1_2:
	.byte		N24	, Dn4, v127
	.byte	W30
	.byte		N04	, An4
	.byte	W06
	.byte		N30	
	.byte	W36
	.byte	PEND
song_0042_1_3:
	.byte		N18	, En4, v127
	.byte	W18
	.byte		N06	, Fn4
	.byte	W06
	.byte		N12	, Gn4
	.byte	W12
	.byte		N24	, En4
	.byte	W36
	.byte	PEND
	.byte		N12	, Dn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N24	, Gn4
	.byte	W24
	.byte		N12	, Fn4
	.byte	W12
	.byte		N18	, An4
	.byte	W18
	.byte		N06	, Gn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte		N24	, An4
	.byte	W36
	.byte	PATT	
		.word	song_0042_1_2
	.byte	PATT	
		.word	song_0042_1_3
	.byte		N12	, Dn4, v127
	.byte	W12
	.byte			En4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N01	, En4
	.byte	W01
	.byte			Fn4
	.byte	W02
	.byte		N18	, En4
	.byte	W15
	.byte		N06	, Dn4
	.byte	W06
	.byte		N12	, En4
	.byte	W12
	.byte		N60	, Dn4
	.byte	W72
	.byte		N48	, An4
	.byte	W48
	.byte		N12	, Gn4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N40	, An4
	.byte	W48
	.byte		N12	, Gn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte		N40	
	.byte	W48
	.byte		N12	, Dn5
	.byte	W12
	.byte			En5
	.byte	W12
	.byte		N60	, Cn5
	.byte	W72
	.byte		N18	, Dn5
	.byte	W18
	.byte		N06	, Cn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cn5
	.byte	W12
	.byte		N12	, Gn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte		N18	, As4
	.byte	W18
	.byte		N06	, An4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			An4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte		N06	, Gn4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte		N18	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte		TIE	, An4
	.byte	W72
	.byte	W48
	.byte		EOT	
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
song_0042_1_4:
	.byte		N42	, Dn5, v127
	.byte	W48
	.byte		N18	, Gn4
	.byte	W18
	.byte		N06	, Dn5
	.byte	W06
	.byte	PEND
song_0042_1_5:
	.byte		N42	, Dn5, v127
	.byte	W48
	.byte		N12	, Cn5
	.byte	W12
	.byte		N06	, As4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte	PEND
	.byte		N24	, Dn5
	.byte	W24
	.byte		N12	, Cn5
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		N12	, Dn5
	.byte	W12
	.byte		N30	, As4
	.byte	W36
	.byte		N12	, Gn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte		N06	, As4
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte	PATT	
		.word	song_0042_1_4
	.byte	PATT	
		.word	song_0042_1_5
	.byte		N24	, Dn5, v127
	.byte	W24
	.byte			Cn5
	.byte	W24
	.byte		N18	, Fn5
	.byte	W18
	.byte		N06	, An4
	.byte	W06
	.byte		N60	, As4
	.byte	W72
	.byte		N12	, Gn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte		N36	, Cn5
	.byte	W36
	.byte		N18	, An4
	.byte	W18
	.byte		N06	, Gn4
	.byte	W06
	.byte		N12	, An4
	.byte	W12
	.byte		N30	, As4
	.byte	W36
	.byte		N12	
	.byte	W12
	.byte			An4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N24	, Fn4
	.byte	W24
	.byte		N12	, Dn4
	.byte	W12
	.byte		N60	, Gn4
	.byte	W72
	.byte	GOTO	
		.word	song_0042_1_6
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0042_2
song_0042_2:	@ 0x087DF546
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v080
	.byte	PAN	, c_v
	.byte	W24
	.byte	W72
song_0042_2_4:
	.byte		N48	, Gn1, v127
	.byte	W48
	.byte		N01	
	.byte	W06
	.byte		N03	, Cs2
	.byte	W03
	.byte			Dn2
	.byte	W03
	.byte		N12	, Gn2
	.byte	W12
	.byte		N18	, An2
	.byte	W18
	.byte			En2
	.byte	W18
	.byte		N24	, An1
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte		N06	, Dn2
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N18	, As1
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N12	, Fn2
	.byte	W12
	.byte			As1
	.byte	W12
	.byte		N18	, Cn2
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte		N12	, Gn2
	.byte	W12
	.byte			Cn2
	.byte	W12
	.byte		N18	, Dn2
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			An1
	.byte	W12
	.byte		N16	, Dn2
	.byte	W60
	.byte		N12	, Cn2
	.byte	W12
	.byte			As1
	.byte	W24
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W36
	.byte			An1
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N12	, Dn2
	.byte	W36
song_0042_2_1:
	.byte		N12	, As1, v127
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N12	, Cn2
	.byte	W36
	.byte	PEND
	.byte			Fn2
	.byte	W24
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, An1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Dn2
	.byte	W24
	.byte		N01	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W36
	.byte	PATT	
		.word	song_0042_2_1
	.byte	PATT	
		.word	song_0042_2_1
	.byte		N36	, Dn2, v127
	.byte	W36
	.byte			Cn2
	.byte	W36
	.byte			As1
	.byte	W36
	.byte		N36	
	.byte	W36
	.byte			An1
	.byte	W36
	.byte		N36	
	.byte	W36
	.byte			Gn1
	.byte	W36
	.byte		N36	
	.byte	W36
	.byte			Fn1
	.byte	W36
	.byte		N24	
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N36	, Gn1
	.byte	W36
	.byte			An1
	.byte	W36
	.byte			Ds2
	.byte	W36
	.byte			Dn2
	.byte	W36
	.byte			As1
	.byte	W36
	.byte		N24	
	.byte	W24
	.byte		N12	, Gn1
	.byte	W12
	.byte			An2
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Dn3
	.byte	W36
song_0042_2_2:
	.byte		N30	, Ds2, v127
	.byte	W30
	.byte		N06	, As1
	.byte	W06
	.byte			Ds2
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N18	
	.byte	W18
	.byte		N06	, As1
	.byte	W06
	.byte	PEND
	.byte		N30	, Ds2
	.byte	W30
	.byte		N06	, As1
	.byte	W06
	.byte			Ds2
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	
	.byte	W24
song_0042_2_3:
	.byte		N30	, Dn2, v127
	.byte	W30
	.byte		N06	, An1
	.byte	W06
	.byte		N24	, Dn2
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte	PEND
	.byte		N18	, Gn2
	.byte	W18
	.byte		N06	, Gn1
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte		N12	, Fn2
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte	PATT	
		.word	song_0042_2_2
	.byte		N30	, Ds2, v127
	.byte	W30
	.byte		N06	, As1
	.byte	W06
	.byte			Ds2
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N18	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0042_2_3
	.byte		N24	, Gn2, v127
	.byte	W24
	.byte		N12	, Gn1
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte		N24	, Cn2
	.byte	W24
	.byte		N06	
	.byte	W06
	.byte			Dn2
	.byte	W06
	.byte		N24	, Ds2
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N24	, Dn2
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N24	, Gn1
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N24	, Cn2
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N24	, Dn2
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N24	, Gn1
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			An1
	.byte	W12
	.byte	GOTO	
		.word	song_0042_2_4
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0042_3
song_0042_3:	@ 0x087DF6C2
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	W72
song_0042_3_1:
	.byte		N10	, An3, v127
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N12	, Gn3
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N12	, Fn3
	.byte	W12
	.byte		N06	, Gn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte	PEND
song_0042_3_2:
	.byte		N09	, An3, v127
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N12	, Gn3
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N12	, Fn3
	.byte	W12
	.byte		N06	, Gn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0042_3_1
	.byte		N48	, An3, v127
	.byte	W60
	.byte		N02	, Dn3
	.byte	W03
	.byte			En3
	.byte	W03
	.byte		N03	, Fn3
	.byte	W03
	.byte			Gn3
	.byte	W03
	.byte	PATT	
		.word	song_0042_3_1
	.byte	PATT	
		.word	song_0042_3_2
	.byte		N68	, An3, v127
	.byte	W72
	.byte	W60
	.byte		N12	, En3
	.byte	W12
song_0042_3_3:
	.byte		N12	, Fn3, v127
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W36
	.byte	PEND
	.byte			En3
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N12	, Dn3
	.byte	W36
song_0042_3_4:
	.byte		N12	, Fn3, v127
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N12	, En3
	.byte	W36
	.byte	PEND
	.byte			Fn3
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N12	, En3
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PATT	
		.word	song_0042_3_3
	.byte	PATT	
		.word	song_0042_3_4
	.byte	PATT	
		.word	song_0042_3_4
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte		N24	, Fn3
	.byte	W24
	.byte		N12	, Cn2
	.byte	W12
	.byte		N24	, Fn3
	.byte	W24
	.byte	VOICE	, 0
	.byte		N72	, Dn4
	.byte	W72
	.byte			Cn4
	.byte	W72
	.byte			As3
	.byte	W72
	.byte			Cn4
	.byte	W72
	.byte		N36	, Dn4
	.byte	W36
	.byte			En4
	.byte	W36
	.byte			Gn4
	.byte	W36
	.byte			Fn4
	.byte	W36
	.byte			Dn4
	.byte	W36
	.byte		N32	
	.byte	W36
	.byte		N06	, An3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Ds5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Cs5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			An5
	.byte	W06
	.byte		N04	, Dn4
	.byte	W04
	.byte			En4
	.byte	W04
	.byte			Fs4
	.byte	W04
	.byte			Gn4
	.byte	W04
	.byte			An4
	.byte	W04
	.byte			As4
	.byte	W04
	.byte		N03	, Cn5
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte			En5
	.byte	W03
	.byte		N02	, Fs5
	.byte	W03
	.byte	VOICE	, 1
	.byte		N12	, Gn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Fn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
song_0042_3_5:
	.byte		N12	, Gn3, v127
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			An3
	.byte	W18
	.byte		N05	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
song_0042_3_6:
	.byte		N12	, Fn3, v127
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte	PEND
song_0042_3_7:
	.byte		N10	, As3, v127
	.byte	W18
	.byte		N05	, Gn3
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N10	, An3
	.byte	W12
	.byte		N12	, Fn3
	.byte	W12
	.byte			An3
	.byte	W12
	.byte	PEND
	.byte			Gn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Fn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte	PATT	
		.word	song_0042_3_5
	.byte	PATT	
		.word	song_0042_3_6
	.byte	PATT	
		.word	song_0042_3_7
	.byte		N12	, Gn3, v127
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Fs3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Fn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Gn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Ds3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Fn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Gn3
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte	GOTO	
		.word	song_0042_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0042_4
song_0042_4:	@ 0x087DF84A
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte		N03	, Dn6, v127
	.byte	W02
	.byte			Cn6
	.byte	W02
	.byte			An5
	.byte	W02
	.byte			Gn5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			Dn5
	.byte	W02
	.byte			Cn5
	.byte	W02
	.byte			An4
	.byte	W02
	.byte			Gn4
	.byte	W02
	.byte			Fn4
	.byte	W02
	.byte			Dn4
	.byte	W02
	.byte			Cn4
	.byte	W02
	.byte			An3
	.byte	W02
	.byte			Gn3
	.byte	W02
	.byte			Fn3
	.byte	W02
	.byte			Dn3
	.byte	W02
	.byte			Dn2
	.byte	W02
	.byte			Fn2
	.byte	W03
	.byte			An2
	.byte	W02
	.byte			Cn3
	.byte	W03
	.byte			Dn3
	.byte	W02
	.byte			Fn3
	.byte	W03
	.byte			An3
	.byte	W02
	.byte			Cn4
	.byte	W03
	.byte			Dn3
	.byte	W02
	.byte			Fn3
	.byte	W02
	.byte			An3
	.byte	W02
	.byte			Cn4
	.byte	W02
	.byte			Dn4
	.byte	W02
	.byte			Fn4
	.byte	W02
	.byte			An4
	.byte	W02
	.byte			Cn5
	.byte	W02
	.byte			Dn5
	.byte	W02
	.byte			Fn5
	.byte	W02
song_0042_4_1:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		N03	, Dn6, v127
	.byte	W02
	.byte			Cn6
	.byte	W02
	.byte			An5
	.byte	W02
	.byte			Gn5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			Dn5
	.byte	W02
	.byte			Cn5
	.byte	W02
	.byte			An4
	.byte	W02
	.byte			Gn4
	.byte	W02
	.byte			Fn4
	.byte	W02
	.byte			Dn4
	.byte	W02
	.byte			Cn4
	.byte	W02
	.byte			An5
	.byte	W02
	.byte			Gn5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			Dn5
	.byte	W02
	.byte			Cn5
	.byte	W02
	.byte			An4
	.byte	W02
	.byte			Gn4
	.byte	W02
	.byte			Fn4
	.byte	W02
	.byte			Dn4
	.byte	W02
	.byte			Cn4
	.byte	W02
	.byte			An3
	.byte	W02
	.byte			Gn3
	.byte	W02
	.byte			An3
	.byte	W02
	.byte			Gn3
	.byte	W02
	.byte			Fn3
	.byte	W02
	.byte			Dn3
	.byte	W02
	.byte			Fn3
	.byte	W02
	.byte			Dn3
	.byte	W02
	.byte			An2
	.byte	W02
	.byte			Dn2
	.byte	W10
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W36
	.byte		N06	
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			As1
	.byte	W06
	.byte			Fn2
	.byte	W06
	.byte			As2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			En2
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte			Dn2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			As2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			As2
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte			Fn2
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Cn3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte		N12	, Gn1
	.byte	W12
	.byte		N20	, As3
	.byte	W24
	.byte		N12	, An1
	.byte	W12
	.byte		N20	, Cn4
	.byte	W24
	.byte		N12	, Ds1
	.byte	W12
	.byte		N19	, As3
	.byte	W24
	.byte		N12	, Dn1
	.byte	W12
	.byte		N19	, Dn4
	.byte	W24
	.byte		N12	, As1
	.byte	W12
	.byte		N19	, As3
	.byte	W24
	.byte		N12	, As1
	.byte	W12
	.byte		N19	, Dn4
	.byte	W24
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	GOTO	
		.word	song_0042_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0042_5
song_0042_5:	@ 0x087DF98E
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
	.byte	W72
song_0042_5_1:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W24
	.byte	PEND
	.byte			Cn1
	.byte	W18
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte	PATT	
		.word	song_0042_5_1
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte			Cn2
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fn1
	.byte	W06
song_0042_5_2:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0042_5_2
	.byte	PATT	
		.word	song_0042_5_2
	.byte		N06	, Dn1, v127
	.byte	W60
	.byte			Cn1
	.byte	W12
song_0042_5_3:
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0042_5_3
	.byte	PATT	
		.word	song_0042_5_3
	.byte		N06	, Cn1, v127
	.byte	W18
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte	PATT	
		.word	song_0042_5_3
	.byte	PATT	
		.word	song_0042_5_3
	.byte	PATT	
		.word	song_0042_5_3
	.byte	PATT	
		.word	song_0042_5_3
song_0042_5_4:
	.byte		N06	, Cn1, v127
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W24
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0042_5_4
	.byte	PATT	
		.word	song_0042_5_4
	.byte	PATT	
		.word	song_0042_5_4
	.byte	PATT	
		.word	song_0042_5_4
	.byte	PATT	
		.word	song_0042_5_4
	.byte		N06	, Cn1, v127
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W24
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W30
	.byte			Cn1
	.byte	W06
	.byte		N06	
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W36
	.byte			Cn1
	.byte		N22	, Cs2
	.byte	W24
	.byte		N06	, Cn1
	.byte	W12
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte	W06
song_0042_5_5:
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0042_5_5
	.byte		N06	, Cn1, v127
	.byte	W30
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte	PATT	
		.word	song_0042_5_5
	.byte	PATT	
		.word	song_0042_5_5
	.byte	PATT	
		.word	song_0042_5_5
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte			Cn2
	.byte	W12
	.byte			An1
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Cn1
	.byte	W06
	.byte	PATT	
		.word	song_0042_5_5
	.byte	PATT	
		.word	song_0042_5_5
	.byte	PATT	
		.word	song_0042_5_5
	.byte		N06	, Cn1, v127
	.byte	W24
	.byte		N06	
	.byte	W12
	.byte			Dn1
	.byte	W18
	.byte			Cn1
	.byte		N06	, Cn2
	.byte	W06
	.byte			An1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	GOTO	
		.word	song_0042_5_1
	.byte	FINE

	.align 2
	.global song_0042
song_0042:	@ 0x087DFADC
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0042_1		@ track
	.word	song_0042_2		@ track
	.word	song_0042_3		@ track
	.word	song_0042_4		@ track
	.word	song_0042_5		@ track
