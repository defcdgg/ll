	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0007_1
song_0007_1:	@ 0x087D3EF0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 3
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W06
song_0007_1_3:
	.byte	TEMPO	, 43
	.byte		N13	, Fs4, v127
	.byte	W12
	.byte		N08	, Gn4
	.byte	W06
	.byte		N30	, Fs4
	.byte	W42
	.byte		N13	
	.byte	W12
	.byte		N12	, Gn4
	.byte	W12
	.byte		N09	, An4
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N08	, Gn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte		N32	, Gn4
	.byte	W48
	.byte		N12	
	.byte	W12
	.byte		N07	, An4
	.byte	W06
	.byte		N32	, Gn4
	.byte	W42
	.byte		N13	
	.byte	W12
	.byte		N12	, An4
	.byte	W12
	.byte		N08	, Bn4
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N07	, An4
	.byte	W06
	.byte		N06	, Gs4
	.byte	W06
	.byte		N07	, An4
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte			Bn4
	.byte	W12
	.byte		N08	, Cs5
	.byte	W12
	.byte		N42	
	.byte	W42
	.byte		N07	, Dn5
	.byte	W06
	.byte		N05	, Bn4
	.byte	W12
	.byte		N13	
	.byte	W12
	.byte		N11	, Cs5
	.byte	W12
	.byte		N10	, Dn5
	.byte	W12
	.byte		N44	, Fs5
	.byte	W48
	.byte		N24	, En5
	.byte	W36
	.byte		N06	, Bn4
	.byte	W12
song_0007_1_1:
	.byte		N48	, Bn4, v127
	.byte	W48
	.byte			An4
	.byte	W48
	.byte	PEND
	.byte		N44	, Gn4
	.byte	W48
	.byte		N36	, En4
	.byte	W48
	.byte		N12	, Fs4
	.byte	W12
	.byte		N07	, Gn4
	.byte	W06
	.byte		N36	, Fs4
	.byte	W42
	.byte		N13	
	.byte	W12
	.byte		N12	, Gn4
	.byte	W12
	.byte		N11	, An4
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N07	, Gn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte		N40	, Gn4
	.byte	W48
	.byte		N12	
	.byte	W12
	.byte		N06	, An4
	.byte	W06
	.byte		N32	, Gn4
	.byte	W42
	.byte		N14	
	.byte	W12
	.byte		N12	, An4
	.byte	W12
	.byte		N09	, Bn4
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N04	, An4
	.byte	W06
	.byte		N08	, Gs4
	.byte	W06
	.byte		N09	, An4
	.byte	W12
	.byte		N14	
	.byte	W12
	.byte		N10	, Bn4
	.byte	W12
	.byte		N08	, Cs5
	.byte	W12
	.byte		N40	
	.byte	W42
	.byte		N06	, Dn5
	.byte	W06
	.byte		N07	, Bn4
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte			Cs5
	.byte	W12
	.byte			Dn5
	.byte	W12
	.byte		N44	, Fs5
	.byte	W48
	.byte		N28	, En5
	.byte	W36
	.byte		N05	, Bn4
	.byte	W12
	.byte	PATT	
		.word	song_0007_1_1
	.byte		N48	, Gn4, v127
	.byte	W48
	.byte		N36	, En4
	.byte	W48
song_0007_1_2:
	.byte		N28	, Dn4, v127
	.byte	W36
	.byte		N13	
	.byte	W12
	.byte		N32	, En4
	.byte	W32
	.byte		N09	, Fs4
	.byte	W08
	.byte		N08	, Gn4
	.byte	W08
	.byte	PEND
	.byte		N24	, An4
	.byte	W24
	.byte			Fs4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N13	, Dn4
	.byte	W12
	.byte		N12	, Cs4
	.byte	W12
	.byte	PATT	
		.word	song_0007_1_2
	.byte		N24	, An4, v127
	.byte	W24
	.byte			En5
	.byte	W24
	.byte		N08	, Dn5
	.byte	W06
	.byte		N07	, Cs5
	.byte	W12
	.byte		N17	, Bn4
	.byte	W18
	.byte		N12	, Cs5
	.byte	W12
	.byte		N60	, Dn5
	.byte	W72
	.byte		N15	, Bn4
	.byte	W12
	.byte		N06	, Cs5
	.byte	W06
	.byte		N36	, Dn5
	.byte	W06
	.byte	W36
	.byte		N14	
	.byte	W12
	.byte		N24	, En5
	.byte	W24
	.byte		N22	, Dn5
	.byte	W24
	.byte		N32	, An4
	.byte	W36
	.byte		N14	, Fs4
	.byte	W12
	.byte		N36	, Bn4
	.byte	W36
	.byte		N08	, Fs4
	.byte	W12
	.byte		N07	
	.byte	W06
	.byte		N12	, Gn4
	.byte	W12
	.byte		N19	, Bn3
	.byte	W18
	.byte		N08	, Dn4
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		TIE	, Dn4
	.byte	W96
	.byte	W23
	.byte		EOT	
	.byte	W24
	.byte	W01
	.byte		N23	, Fs4
	.byte	W24
	.byte		N22	, Gn4
	.byte	W24
	.byte		N04	, An4
	.byte	W12
	.byte		N13	
	.byte	W12
	.byte			Fs4
	.byte	W12
	.byte		N08	, Bn4
	.byte	W06
	.byte		N17	, An4
	.byte	W18
	.byte		N14	, Fs4
	.byte	W12
	.byte		N13	, En4
	.byte	W12
	.byte		N12	, Dn4
	.byte	W12
	.byte		N20	, En4
	.byte	W18
	.byte		N18	, Bn3
	.byte	W18
	.byte		N28	, Dn4
	.byte	W36
	.byte		N13	, Fs4
	.byte	W12
	.byte		N12	, Gn4
	.byte	W12
	.byte		N06	, An4
	.byte	W12
	.byte		N13	
	.byte	W12
	.byte		N15	, Fs4
	.byte	W12
	.byte		N07	, Bn4
	.byte	W06
	.byte		N13	, An4
	.byte	W18
	.byte		N12	
	.byte	W12
	.byte		N13	, Bn4
	.byte	W12
	.byte		N12	, Cn5
	.byte	W12
	.byte		N56	, Bn4
	.byte	W72
	.byte		N14	, Gn4
	.byte	W12
	.byte		N12	, An4
	.byte	W12
	.byte		N07	, Bn4
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N07	, Dn5
	.byte	W06
	.byte		N14	, Cs5
	.byte	W18
	.byte		N13	
	.byte	W12
	.byte		N12	, Dn5
	.byte	W12
	.byte		N11	, En5
	.byte	W12
	.byte		N24	, Fs5
	.byte	W24
	.byte			En5
	.byte	W24
	.byte		N36	, Dn5
	.byte	W48
	.byte		N12	, Bn4
	.byte	W12
	.byte		N07	, Cs5
	.byte	W06
	.byte		N18	, Dn5
	.byte	W18
	.byte		N12	, Bn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte		N06	, Cs5
	.byte	W06
	.byte		N16	, Dn5
	.byte	W18
	.byte		N12	, An4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte		N08	, An4
	.byte	W06
	.byte		N19	, Bn4
	.byte	W18
	.byte		N12	, Gn4
	.byte	W12
	.byte		N13	, En4
	.byte	W12
	.byte		N07	, Fs4
	.byte	W06
	.byte		N18	, Gn4
	.byte	W18
	.byte		N12	, En4
	.byte	W12
	.byte	GOTO	
		.word	song_0007_1_3
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0007_2
song_0007_2:	@ 0x087D40C8
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W06
song_0007_2_1:
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte	PEND
song_0007_2_2:
	.byte		N12	, En2, v127
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte	PEND
song_0007_2_3:
	.byte		N12	, An1, v127
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En2
	.byte	W12
	.byte	PEND
song_0007_2_4:
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Cs2
	.byte	W12
	.byte			An2
	.byte	W12
	.byte	PEND
	.byte			Dn3
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fs2
	.byte	W12
song_0007_2_5:
	.byte		N12	, En1, v127
	.byte	W12
	.byte			En2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gs2
	.byte	W12
	.byte	PEND
song_0007_2_6:
	.byte		N12	, An1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	PEND
song_0007_2_7:
	.byte		N12	, An1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0007_2_1
	.byte	PATT	
		.word	song_0007_2_2
	.byte	PATT	
		.word	song_0007_2_3
	.byte	PATT	
		.word	song_0007_2_4
	.byte		N12	, Fs3, v127
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte	PATT	
		.word	song_0007_2_5
	.byte	PATT	
		.word	song_0007_2_6
	.byte	PATT	
		.word	song_0007_2_7
song_0007_2_8:
	.byte		N12	, Gn1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte	PEND
song_0007_2_9:
	.byte		N12	, Fs1, v127
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0007_2_8
	.byte	PATT	
		.word	song_0007_2_9
	.byte		N12	, En1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			En1
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Gn2
	.byte	W13
	.byte			Dn3
	.byte	W24
	.byte			En3
	.byte	W23
	.byte	PATT	
		.word	song_0007_2_1
	.byte		N12	, Fs3, v127
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte		N06	, An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte		N11	, Dn2
	.byte	W12
	.byte		N06	, An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte		N11	
	.byte	W12
	.byte		N06	, Gn1
	.byte	W06
	.byte		N11	, Dn3
	.byte	W12
	.byte		N06	, Gn1
	.byte	W06
	.byte		N21	, Dn3
	.byte	W24
	.byte		N06	, Bn2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte		N12	, Dn2
	.byte	W12
	.byte		N06	, An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte		N12	, Fs3
	.byte	W12
	.byte		N06	, An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte		N12	, Gn1
	.byte	W12
	.byte		N06	, Gn2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Dn2
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte		N12	, Gn1
	.byte	W12
	.byte		N06	, Gn2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Fs1
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte		N12	, En1
	.byte	W12
	.byte		N06	, Gn2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			En2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte		N12	, An1
	.byte	W12
	.byte		N06	, An2
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte			En2
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			As2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N06	, Fs2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte		N12	, Dn3
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			Gn1
	.byte	W12
	.byte		N06	, Gn2
	.byte	W06
	.byte		N18	, Dn3
	.byte	W18
	.byte		N12	, Gn2
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte		N06	, An2
	.byte	W06
	.byte		N18	, Fs3
	.byte	W18
	.byte		N12	, An2
	.byte	W12
	.byte			En1
	.byte	W12
	.byte		N06	, Gn2
	.byte	W06
	.byte		N18	, Dn3
	.byte	W18
	.byte		N12	, Gn2
	.byte	W12
	.byte		N30	, Gn3
	.byte	W48
	.byte	GOTO	
		.word	song_0007_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0007_3
song_0007_3:	@ 0x087D42F8
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W06
song_0007_3_1:
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N24	, An3
	.byte	W24
	.byte			Fs3
	.byte	W24
	.byte			An3
	.byte	W24
	.byte	PEND
song_0007_3_2:
	.byte		N12	, En2, v127
	.byte	W12
	.byte			En3
	.byte	W12
	.byte		N24	, Bn3
	.byte	W24
	.byte			Gn3
	.byte	W24
	.byte			Bn3
	.byte	W24
	.byte	PEND
song_0007_3_3:
	.byte		N12	, An1, v127
	.byte	W12
	.byte			En3
	.byte	W12
	.byte		N24	, Bn3
	.byte	W24
	.byte			Gn3
	.byte	W24
	.byte			Bn3
	.byte	W24
	.byte	PEND
song_0007_3_4:
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N24	, An3
	.byte	W24
	.byte			Fs3
	.byte	W24
	.byte			Cs2
	.byte	W24
	.byte	PEND
song_0007_3_5:
	.byte		N12	, Bn1, v127
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N24	, Bn3
	.byte	W24
	.byte			Fs3
	.byte	W24
	.byte			Bn3
	.byte	W24
	.byte	PEND
song_0007_3_6:
	.byte		N12	, En1, v127
	.byte	W12
	.byte			En3
	.byte	W12
	.byte		N24	, Bn3
	.byte	W24
	.byte			Gs3
	.byte	W24
	.byte			Bn3
	.byte	W24
	.byte	PEND
	.byte	W24
	.byte			Dn3
	.byte	W48
	.byte			En3
	.byte	W24
	.byte	W24
	.byte			Gn3
	.byte	W36
	.byte		N12	, An1
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte			Cs2
	.byte	W12
	.byte	PATT	
		.word	song_0007_3_1
	.byte	PATT	
		.word	song_0007_3_2
	.byte	PATT	
		.word	song_0007_3_3
	.byte	PATT	
		.word	song_0007_3_4
	.byte	PATT	
		.word	song_0007_3_5
	.byte	PATT	
		.word	song_0007_3_6
	.byte	W24
	.byte		N24	, Bn3, v127
	.byte	W48
	.byte			Cs4
	.byte	W24
	.byte	W24
	.byte			Bn3
	.byte	W48
	.byte		N12	, Cs4
	.byte	W24
song_0007_3_7:
	.byte		N12	, Gn1, v127
	.byte	W48
	.byte		N12	
	.byte	W48
	.byte	PEND
song_0007_3_8:
	.byte		N12	, Fs1, v127
	.byte	W48
	.byte			Bn1
	.byte	W48
	.byte	PEND
	.byte	PATT	
		.word	song_0007_3_7
	.byte	PATT	
		.word	song_0007_3_8
	.byte		N12	, En1, v127
	.byte	W96
	.byte			Gn1
	.byte	W96
	.byte	PATT	
		.word	song_0007_3_8
	.byte		N12	, En2, v127
	.byte	W48
	.byte			An1
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte			Dn2
	.byte	W96
	.byte	W96
	.byte		N12	
	.byte	W42
	.byte		N06	, An1
	.byte	W06
	.byte		N12	, Dn2
	.byte	W48
	.byte			Gn1
	.byte	W18
	.byte		N12	
	.byte	W18
	.byte		N12	
	.byte	W36
	.byte		N12	
	.byte	W12
	.byte			An1
	.byte	W12
	.byte			Dn2
	.byte	W42
	.byte		N06	, An1
	.byte	W06
	.byte		N12	, Dn2
	.byte	W36
	.byte			Fs1
	.byte	W12
	.byte			Gn1
	.byte	W48
	.byte		N12	
	.byte	W24
	.byte			Fs1
	.byte	W24
	.byte			En1
	.byte	W48
	.byte			An1
	.byte	W48
	.byte			Fs1
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			Bn1
	.byte	W24
	.byte			An1
	.byte	W24
	.byte			Gn1
	.byte	W48
	.byte			Fs1
	.byte	W48
	.byte			En1
	.byte	W48
	.byte			An1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte			Cs2
	.byte	W12
	.byte	GOTO	
		.word	song_0007_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0007_4
song_0007_4:	@ 0x087D43FF
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v044
	.byte	PAN	, c_v
	.byte	W06
song_0007_4_1:
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte	PEND
song_0007_4_2:
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
song_0007_4_3:
	.byte		N06	, En6, v127
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W03
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte	PEND
song_0007_4_4:
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W03
	.byte		N03	, En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W03
	.byte			Ds6
	.byte	W03
	.byte		N03	, En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte	PEND
	.byte	PATT	
		.word	song_0007_4_1
	.byte	PATT	
		.word	song_0007_4_2
	.byte	PATT	
		.word	song_0007_4_3
	.byte	PATT	
		.word	song_0007_4_4
	.byte	PATT	
		.word	song_0007_4_1
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W07
	.byte		N05	
	.byte	W05
	.byte	PATT	
		.word	song_0007_4_3
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N03	, Dn6
	.byte	W03
	.byte			En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W03
	.byte			Ds6
	.byte	W04
	.byte		N02	, En6
	.byte	W02
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte	PATT	
		.word	song_0007_4_1
	.byte	PATT	
		.word	song_0007_4_2
	.byte	PATT	
		.word	song_0007_4_3
song_0007_4_5:
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N03	, Dn6
	.byte	W03
	.byte			En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W03
	.byte			Ds6
	.byte	W03
	.byte		N03	, En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte	PEND
	.byte	PATT	
		.word	song_0007_4_1
	.byte	PATT	
		.word	song_0007_4_2
	.byte	PATT	
		.word	song_0007_4_3
	.byte	PATT	
		.word	song_0007_4_5
	.byte	PATT	
		.word	song_0007_4_1
	.byte	PATT	
		.word	song_0007_4_2
	.byte	PATT	
		.word	song_0007_4_3
	.byte	PATT	
		.word	song_0007_4_5
	.byte	PATT	
		.word	song_0007_4_1
	.byte	PATT	
		.word	song_0007_4_2
song_0007_4_6:
	.byte		N06	, En6, v127
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W03
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Fs2
	.byte		N06	, Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte	PEND
song_0007_4_7:
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N02	, Dn6
	.byte	W03
	.byte		N03	, En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W03
	.byte			Fs2
	.byte		N06	, Ds6
	.byte	W03
	.byte		N03	, En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte	PEND
song_0007_4_8:
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Fs2
	.byte		N06	, Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte	PEND
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0007_4_6
	.byte	PATT	
		.word	song_0007_4_7
	.byte	PATT	
		.word	song_0007_4_8
	.byte		N06	, En6, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Fs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fs2
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N03	, Dn6
	.byte	W03
	.byte			En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W03
	.byte			Ds6
	.byte	W03
	.byte		N03	, En6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte	GOTO	
		.word	song_0007_4_1
	.byte	FINE

	.align 2
	.global song_0007
song_0007:	@ 0x087D4660
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0007_1		@ track
	.word	song_0007_2		@ track
	.word	song_0007_3		@ track
	.word	song_0007_4		@ track
