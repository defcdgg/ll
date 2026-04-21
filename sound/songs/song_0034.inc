	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0034_1
song_0034_1:	@ 0x087DD230
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 21
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
song_0034_1_2:
	.byte	TEMPO	, 56
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N16	, Gs3, v127
	.byte	W44
	.byte	W03
	.byte		N12	, An3
	.byte	W12
	.byte		N05	, Gs3
	.byte	W06
	.byte		N08	, An3
	.byte	W12
	.byte		N18	, Bn3
	.byte	W18
	.byte		N13	, Gs3
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N11	, Fs3
	.byte	W12
	.byte		N04	, En3
	.byte	W06
	.byte		N08	, Fs3
	.byte	W12
	.byte		N19	, Gs3
	.byte	W18
	.byte		N24	, En3
	.byte	W01
	.byte	W54
	.byte		N05	, Fs3
	.byte	W05
	.byte		N13	, Gn3
	.byte	W12
	.byte		N10	, Fs3
	.byte	W12
	.byte		N15	, En3
	.byte	W13
	.byte		N42	, Cs3
	.byte	W92
	.byte	W03
	.byte		N14	, Ds3
	.byte	W01
	.byte	W23
	.byte		N16	, En3
	.byte	W24
	.byte			Fs3
	.byte	W24
	.byte		N01	, An3
	.byte		N22	, Bn3
	.byte	W24
	.byte		N12	, An3
	.byte	W01
	.byte	W17
	.byte		N05	
	.byte	W18
	.byte		N24	
	.byte	W36
	.byte		N12	
	.byte	W12
	.byte		N04	, Bn3
	.byte	W12
	.byte		N19	, An3
	.byte	W01
	.byte	W18
	.byte		N04	, Gs3
	.byte	W18
	.byte		N36	
	.byte	W60
	.byte	W56
	.byte	W03
	.byte		N02	, En3
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N14	, Fs3
	.byte	W12
	.byte		N15	, Gs3
	.byte	W01
	.byte	W18
	.byte		N12	
	.byte	W17
	.byte		N04	
	.byte	W12
	.byte		N16	
	.byte	W18
	.byte		N05	, Cs4
	.byte	W18
	.byte		N06	, En3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte		N12	, Gs3
	.byte	W01
	.byte	W17
	.byte		N12	
	.byte	W18
	.byte		N04	
	.byte	W12
	.byte		N17	
	.byte	W18
	.byte		N06	, Cs4
	.byte	W30
	.byte		N12	, Gs3
	.byte	W01
	.byte	W11
	.byte		N03	, Fs3
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N04	, En3
	.byte	W12
	.byte		N11	, Fs3
	.byte	W12
	.byte		N03	, En3
	.byte	W12
	.byte		N12	, Fs3
	.byte	W12
	.byte		N06	, Gs3
	.byte	W06
	.byte		N32	, En3
	.byte	W07
	.byte	W68
	.byte	W03
	.byte		N12	, Cs3
	.byte	W12
	.byte		N05	, En3
	.byte	W12
	.byte		N11	, Gs3
	.byte	W01
	.byte	W11
	.byte		N03	, Fs3
	.byte	W12
	.byte		N11	
	.byte	W13
	.byte		N06	, En3
	.byte	W05
	.byte		N19	, Fs3
	.byte	W54
	.byte		N13	, An3
	.byte	W01
	.byte	W11
	.byte		N04	, Gs3
	.byte	W12
	.byte		N13	
	.byte	W12
	.byte		N04	, En3
	.byte	W12
	.byte		N14	
	.byte	W12
	.byte		N13	, Fs3
	.byte	W12
	.byte		N12	, Gs3
	.byte	W12
	.byte		N13	, An3
	.byte	W12
	.byte		N92	, Bn3
	.byte	W01
	.byte	W92
	.byte	W03
	.byte		N05	, As3
	.byte	W01
	.byte		N12	, Bn3
	.byte	W24
	.byte		N14	
	.byte	W23
	.byte		N14	
	.byte	W24
	.byte		N18	
	.byte	W24
	.byte	W01
song_0034_1_1:
	.byte	W56
	.byte	W03
	.byte		N05	, Fs3, v127
	.byte	W12
	.byte		N12	, Gs3
	.byte	W12
	.byte		N05	, An3
	.byte	W12
	.byte		N13	, Bn3
	.byte	W01
	.byte	PEND
	.byte	W18
	.byte		N18	
	.byte	W17
	.byte		N05	, Gs3
	.byte	W12
	.byte		N17	, Bn3
	.byte	W18
	.byte		N07	, Cs4
	.byte	W18
	.byte		N04	, Gs3
	.byte	W13
	.byte		N15	, Bn3
	.byte	W18
	.byte		N17	
	.byte	W17
	.byte		N04	, Gs3
	.byte	W12
	.byte		N20	, Bn3
	.byte	W18
	.byte		N08	, Cs4
	.byte	W30
	.byte		N05	, Ds4
	.byte	W01
	.byte	W11
	.byte		N07	, En4
	.byte	W12
	.byte		N06	, Ds4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte		N19	, Ds4
	.byte	W18
	.byte		N18	, En4
	.byte	W18
	.byte		N06	, Ds4
	.byte	W13
	.byte		N64	, Cs4
	.byte	W80
	.byte	W03
	.byte		N06	, Bn3
	.byte	W07
	.byte			Cs4
	.byte	W06
	.byte		N12	, En4
	.byte	W17
	.byte		N15	
	.byte	W18
	.byte		N21	, Cs4
	.byte	W48
	.byte		N05	
	.byte	W12
	.byte		N23	, Bn3
	.byte	W01
	.byte	W23
	.byte		N24	, An3
	.byte	W24
	.byte			Gs3
	.byte	W24
	.byte			An3
	.byte	W24
	.byte		N52	, Gs3
	.byte	W01
	.byte	W56
	.byte	W03
	.byte		N10	
	.byte		N14	, An3
	.byte	W12
	.byte		N21	, Gs3
	.byte	W24
	.byte		N48	, Fs3
	.byte	W01
	.byte	PATT	
		.word	song_0034_1_1
	.byte	W18
	.byte		N18	, Bn3, v127
	.byte	W18
	.byte		N04	, Gs3
	.byte	W11
	.byte		N20	, Bn3
	.byte	W18
	.byte		N07	, Cs4
	.byte	W19
	.byte		N03	, Gs3
	.byte	W12
	.byte		N14	, Bn3
	.byte	W18
	.byte		N18	
	.byte	W17
	.byte		N04	, Gs3
	.byte	W12
	.byte		N21	, Bn3
	.byte	W18
	.byte		N08	, Cs4
	.byte	W30
	.byte		N05	, Ds4
	.byte	W01
	.byte	W11
	.byte		N06	, En4
	.byte	W12
	.byte			Ds4
	.byte	W12
	.byte		N05	, En4
	.byte	W12
	.byte		N20	, Fs4
	.byte	W18
	.byte			En4
	.byte	W18
	.byte		N13	, Ds4
	.byte	W12
	.byte		N60	, Cs4
	.byte	W01
	.byte	W80
	.byte	W03
	.byte		N07	, Bn3
	.byte	W06
	.byte		N06	, Cs4
	.byte	W06
	.byte		N13	, En4
	.byte	W01
	.byte	W18
	.byte		N19	
	.byte	W17
	.byte		N03	, Cs4
	.byte	W12
	.byte		N05	, En4
	.byte	W12
	.byte		N04	, Fs4
	.byte	W12
	.byte		N36	, Gs4
	.byte	W24
	.byte	W01
	.byte	W11
	.byte		N04	, Fs4
	.byte	W12
	.byte		N13	
	.byte	W12
	.byte		N03	, En4
	.byte	W12
	.byte		N14	
	.byte	W13
	.byte		N04	, Cs4
	.byte	W11
	.byte		N14	, Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte		TIE	, En4
	.byte	W01
	.byte	W96
	.byte	W92
	.byte	W03
	.byte		EOT	
	.byte	W01
	.byte	GOTO	
		.word	song_0034_1_2
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0034_2
song_0034_2:	@ 0x087DD408
	.byte	KEYSH	, 0
	.byte	VOICE	, 1
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	BEND	, c_v
	.byte	W24
song_0034_2_9:
	.byte		N04	, En2, v127
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N10	, Bn2
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, En3
	.byte	W06
	.byte		N17	
	.byte		N17	, An3
	.byte		N17	, En4
	.byte	W18
	.byte		N40	, En3
	.byte		N40	, Gs3
	.byte		N40	, En4
	.byte	W42
	.byte		N12	, Bn2
	.byte	W12
	.byte		N05	, En2
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N12	, Bn2
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, En3
	.byte	W06
	.byte		N17	
	.byte		N17	, An3
	.byte		N17	, En4
	.byte	W18
	.byte		N40	, En3
	.byte		N40	, Gs3
	.byte		N40	, En4
	.byte	W42
	.byte		N12	, Bn2
	.byte	W12
	.byte		N04	, En1
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N11	, Bn1
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, En2
	.byte	W06
	.byte		N12	, Bn2
	.byte	W06
	.byte	BEND	, c_v-64
	.byte	W06
	.byte		c_v
	.byte		N06	, En2
	.byte	W06
	.byte		N12	, An2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte		N06	, En2
	.byte	W06
	.byte		N12	, Bn1
	.byte	W06
	.byte	BEND	, c_v-64
	.byte	W06
	.byte		c_v
	.byte		N06	, En1
	.byte	W06
	.byte			Bn1
	.byte	W06
	.byte			An1
	.byte	W12
song_0034_2_1:
	.byte		N06	, En1, v127
	.byte	W06
	.byte		N02	
	.byte	W06
	.byte		N06	, Bn2
	.byte		N06	, Dn3
	.byte	W06
	.byte		N01	, En1
	.byte	W06
	.byte		N06	, Bn2
	.byte		N06	, Dn3
	.byte	W06
	.byte		N01	, En1
	.byte	W06
	.byte		N06	, Bn2
	.byte		N06	, Cs3
	.byte	W06
	.byte			Bn2
	.byte		N06	, Dn3
	.byte	W06
	.byte		N01	, En1
	.byte	W06
	.byte		N06	, Bn2
	.byte		N06	, Dn3
	.byte	W06
	.byte		N01	, En1
	.byte	W06
	.byte		N06	, Bn2
	.byte		N06	, Cs3
	.byte	W06
	.byte			Bn2
	.byte		N06	, Dn3
	.byte	W06
	.byte		N01	, En1
	.byte	W06
	.byte		N12	, Bn2
	.byte		N12	, En3
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0034_2_1
	.byte	PATT	
		.word	song_0034_2_1
	.byte	PATT	
		.word	song_0034_2_1
song_0034_2_2:
	.byte		N06	, En1, v127
	.byte	W06
	.byte			Bn1
	.byte	W06
	.byte		N04	, En2
	.byte		N04	, Bn2
	.byte	W12
	.byte		N06	, An2
	.byte		N06	, Dn3
	.byte	W06
	.byte			Bn2
	.byte		N06	, En3
	.byte	W06
	.byte		N01	, Bn2
	.byte	W06
	.byte		N06	
	.byte		N06	, En3
	.byte	W54
	.byte	PEND
	.byte	PATT	
		.word	song_0034_2_2
song_0034_2_3:
	.byte		N06	, An1, v127
	.byte	W06
	.byte			En2
	.byte	W06
	.byte		N04	, An2
	.byte		N04	, En3
	.byte	W12
	.byte		N06	, Dn3
	.byte		N06	, Gn3
	.byte	W06
	.byte			En3
	.byte		N06	, An3
	.byte	W06
	.byte		N01	, En3
	.byte	W06
	.byte		N06	
	.byte		N06	, An3
	.byte	W54
	.byte	PEND
	.byte	PATT	
		.word	song_0034_2_3
	.byte		N06	, Bn1, v127
	.byte	W06
	.byte			Fs2
	.byte	W06
	.byte		N04	, Bn2
	.byte		N04	, Fs3
	.byte	W12
	.byte		N06	, En3
	.byte		N06	, An3
	.byte	W06
	.byte			Fs3
	.byte		N06	, Bn3
	.byte	W06
	.byte		N01	, Fs3
	.byte	W06
	.byte		N06	
	.byte		N06	, Bn3
	.byte	W54
	.byte	PATT	
		.word	song_0034_2_3
	.byte	PATT	
		.word	song_0034_2_2
	.byte	PATT	
		.word	song_0034_2_2
song_0034_2_4:
	.byte	W12
	.byte		N05	, Cs3, v127
	.byte		N05	, En3
	.byte	W18
	.byte			Cs3
	.byte		N05	, En3
	.byte	W18
	.byte		N18	, Cs3
	.byte		N18	, En3
	.byte	W18
	.byte		N05	, Cs3
	.byte		N05	, En3
	.byte	W30
	.byte	PEND
	.byte	PATT	
		.word	song_0034_2_4
	.byte	W12
	.byte		N05	, Cn3, v127
	.byte		N05	, Ds3
	.byte	W18
	.byte			Cn3
	.byte		N05	, Ds3
	.byte	W18
	.byte		N18	, Cn3
	.byte		N18	, Ds3
	.byte	W18
	.byte		N05	, Cn3
	.byte		N05	, Ds3
	.byte	W30
	.byte	PATT	
		.word	song_0034_2_4
	.byte	PATT	
		.word	song_0034_2_4
	.byte	PATT	
		.word	song_0034_2_4
	.byte	W12
	.byte		N05	, Ds3, v127
	.byte		N05	, Fs3
	.byte	W18
	.byte			Ds3
	.byte		N05	, Fs3
	.byte	W18
	.byte		N18	, Ds3
	.byte		N18	, Fs3
	.byte	W18
	.byte		N05	, Ds3
	.byte		N05	, Fs3
	.byte	W30
	.byte		N12	, Ds3
	.byte		N12	, Fs3
	.byte	W24
	.byte			Ds3
	.byte		N12	, Fs3
	.byte	W24
	.byte			Ds3
	.byte		N12	, Fs3
	.byte	W24
	.byte			Ds3
	.byte		N12	, Fs3
	.byte	W24
	.byte	W96
song_0034_2_5:
	.byte		N17	, Bn2, v127
	.byte		N17	, En3
	.byte	W18
	.byte		N06	, Bn2
	.byte		N06	, En3
	.byte	W18
	.byte			Bn2
	.byte		N06	, En3
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N06	, Bn2
	.byte		N06	, En3
	.byte	W18
	.byte		N24	, Bn2
	.byte		N24	, En3
	.byte	W24
	.byte	PEND
song_0034_2_6:
	.byte		N17	, Cs3, v127
	.byte		N17	, En3
	.byte	W18
	.byte		N06	, Cs3
	.byte		N06	, En3
	.byte	W18
	.byte			Cs3
	.byte		N06	, En3
	.byte	W18
	.byte			Cs3
	.byte		N06	, En3
	.byte	W18
	.byte		N24	, Cs3
	.byte		N24	, En3
	.byte	W24
	.byte	PEND
song_0034_2_7:
	.byte		N17	, Ds3, v127
	.byte		N17	, Fs3
	.byte	W18
	.byte		N06	, Ds3
	.byte		N06	, Fs3
	.byte	W18
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W18
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W18
	.byte		N24	, Ds3
	.byte		N24	, Fs3
	.byte	W24
	.byte	PEND
	.byte		N17	, En3
	.byte		N17	, Gs3
	.byte	W18
	.byte		N06	, En3
	.byte		N06	, Gs3
	.byte	W18
	.byte			En3
	.byte		N06	, Gs3
	.byte	W18
	.byte			En3
	.byte		N06	, Gs3
	.byte	W18
	.byte		N24	, En3
	.byte		N24	, Gs3
	.byte	W24
	.byte		N17	, En3
	.byte		N17	, An3
	.byte	W18
	.byte		N06	, En3
	.byte		N06	, An3
	.byte	W18
	.byte			En3
	.byte		N06	, An3
	.byte	W18
	.byte			En3
	.byte		N06	, An3
	.byte	W18
	.byte		N24	, En3
	.byte		N24	, An3
	.byte	W24
song_0034_2_8:
	.byte		N17	, Cs3, v127
	.byte		N17	, Fs3
	.byte	W18
	.byte		N06	, Cs3
	.byte		N06	, Fs3
	.byte	W18
	.byte			Cs3
	.byte		N06	, Fs3
	.byte	W18
	.byte			Cs3
	.byte		N06	, Fs3
	.byte	W18
	.byte		N24	, Cs3
	.byte		N24	, Fs3
	.byte	W24
	.byte	PEND
	.byte		N17	, En3
	.byte		N17	, Gs3
	.byte	W18
	.byte		N06	, En3
	.byte		N06	, Gs3
	.byte	W18
	.byte			En3
	.byte		N06	, Gs3
	.byte	W18
	.byte			En3
	.byte		N06	, Gs3
	.byte	W18
	.byte		N23	, En3
	.byte		N23	, Gs3
	.byte	W24
	.byte		N06	, Ds3
	.byte		N06	, Fs3
	.byte	W06
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W12
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W12
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W06
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W06
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W06
	.byte		N12	, Ds3
	.byte		N12	, Fs3
	.byte	W24
	.byte		N24	, Ds3
	.byte		N24	, Fs3
	.byte	W24
	.byte	PATT	
		.word	song_0034_2_5
	.byte	PATT	
		.word	song_0034_2_6
	.byte	PATT	
		.word	song_0034_2_7
	.byte		N17	, Fn3, v127
	.byte		N17	, Gs3
	.byte	W18
	.byte		N06	, Fn3
	.byte		N06	, Gs3
	.byte	W18
	.byte			Fn3
	.byte		N06	, Gs3
	.byte	W18
	.byte			Fn3
	.byte		N06	, Gs3
	.byte	W18
	.byte		N24	, Fn3
	.byte		N24	, Gs3
	.byte	W24
	.byte	PATT	
		.word	song_0034_2_8
	.byte		N17	, Ds3, v127
	.byte		N17	, Fs3
	.byte	W18
	.byte		N06	, Ds3
	.byte		N06	, Fs3
	.byte	W18
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W18
	.byte			Ds3
	.byte		N06	, Fs3
	.byte	W18
	.byte		N23	, Ds3
	.byte		N23	, Fs3
	.byte	W24
	.byte		N17	, En3
	.byte		N17	, An3
	.byte	W18
	.byte		N06	, Cs3
	.byte		N06	, En3
	.byte	W18
	.byte			Cs3
	.byte		N06	, En3
	.byte	W18
	.byte			Cs3
	.byte		N06	, En3
	.byte	W18
	.byte		N23	, Cs3
	.byte		N23	, En3
	.byte	W24
	.byte	W01
	.byte		N92	, Gs2
	.byte	W01
	.byte			Bn2
	.byte		N92	, En3
	.byte	W92
	.byte	W02
	.byte	GOTO	
		.word	song_0034_2_9
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0034_3
song_0034_3:	@ 0x087DD6D8
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v090
	.byte	PAN	, c_v
	.byte	BEND	, c_v
	.byte	W24
song_0034_3_7:
	.byte		N72	, En2, v127
	.byte	W84
	.byte		N12	, Bn1
	.byte	W12
	.byte		N96	, En1
	.byte	W96
	.byte		N06	
	.byte	W06
	.byte	BEND	, c_v-64
	.byte		N12	, Bn1
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N06	, En2
	.byte	W06
	.byte		N12	, Bn2
	.byte	W06
	.byte	BEND	, c_v-64
	.byte	W06
	.byte		c_v
	.byte		N06	, En2
	.byte	W06
	.byte		N12	, An2
	.byte	W06
	.byte	BEND	, c_v-35
	.byte	W06
	.byte		c_v
	.byte		N06	, En2
	.byte	W06
	.byte		N12	, Bn1
	.byte	W06
	.byte	BEND	, c_v-64
	.byte	W06
	.byte		c_v
	.byte		N06	, En1
	.byte	W06
	.byte			Bn1
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Gs1
	.byte	W06
song_0034_3_1:
	.byte		N06	, En1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Gs1
	.byte	W12
	.byte		N06	, An1
	.byte	W06
	.byte			Bn1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N18	, An1
	.byte	W18
	.byte		N12	, Gs1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0034_3_1
	.byte	PATT	
		.word	song_0034_3_1
	.byte	PATT	
		.word	song_0034_3_1
	.byte	PATT	
		.word	song_0034_3_1
	.byte	PATT	
		.word	song_0034_3_1
song_0034_3_2:
	.byte		N06	, An1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Cs2
	.byte	W12
	.byte		N06	, Ds2
	.byte	W06
	.byte			En2
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N18	, Ds2
	.byte	W18
	.byte		N12	, Cs2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0034_3_2
	.byte		N06	, Bn1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte		N06	, En2
	.byte	W06
	.byte			Fs2
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N18	, En2
	.byte	W18
	.byte		N12	, Ds2
	.byte	W12
	.byte	PATT	
		.word	song_0034_3_2
	.byte	PATT	
		.word	song_0034_3_1
	.byte	PATT	
		.word	song_0034_3_1
song_0034_3_3:
	.byte		N06	, An1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			En1
	.byte	W12
	.byte		N06	, Gs1
	.byte	W06
	.byte			An1
	.byte	W12
	.byte		N12	, En1
	.byte	W12
	.byte		N18	, An1
	.byte	W18
	.byte		N12	, Bn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0034_3_3
	.byte		N06	, Gs1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Ds2
	.byte	W12
	.byte		N06	, Fs2
	.byte	W18
	.byte		N12	, Gs1
	.byte	W30
	.byte		N12	
	.byte	W12
	.byte		N06	, Cs2
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Gs1
	.byte	W12
	.byte		N06	, Bn1
	.byte	W06
	.byte			Cs2
	.byte	W12
	.byte		N12	
	.byte	W24
	.byte		N06	, Fs2
	.byte	W06
	.byte			En2
	.byte	W06
	.byte			Cs2
	.byte	W06
song_0034_3_4:
	.byte		N06	, Fs1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Cs2
	.byte	W12
	.byte		N06	, En2
	.byte	W06
	.byte			Fs2
	.byte	W12
	.byte		N12	, Fs1
	.byte	W12
	.byte		N18	, Fs2
	.byte	W18
	.byte		N12	, Fs1
	.byte	W12
	.byte	PEND
	.byte		N06	, An1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			En2
	.byte	W18
	.byte		N06	, An2
	.byte	W12
	.byte		N12	, An1
	.byte	W12
	.byte		N18	, An2
	.byte	W18
	.byte		N12	, An1
	.byte	W12
	.byte		N06	, Bn1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte		N06	, An2
	.byte	W06
	.byte			Bn2
	.byte	W12
	.byte		N12	, Bn1
	.byte	W12
	.byte		N18	, Bn2
	.byte	W18
	.byte		N12	, Bn1
	.byte	W12
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte		N12	
	.byte	W24
	.byte	W96
song_0034_3_5:
	.byte		N06	, En1, v127
	.byte	W12
	.byte		N12	, En2
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte		N06	, Cs2
	.byte	W06
	.byte			En2
	.byte	W12
	.byte		N12	, Bn1
	.byte	W12
	.byte		N18	, Cs2
	.byte	W18
	.byte		N12	, En2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0034_3_2
song_0034_3_6:
	.byte		N06	, Gs1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Bn1
	.byte	W12
	.byte		N06	, Cs2
	.byte	W06
	.byte			Ds2
	.byte	W12
	.byte		N12	, Gs1
	.byte	W30
	.byte		N12	
	.byte	W12
	.byte	PEND
	.byte		N06	, Cs2
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Gs1
	.byte	W12
	.byte		N06	, Bn1
	.byte	W06
	.byte			Cs2
	.byte	W12
	.byte		N12	, Gs1
	.byte	W24
	.byte		N06	, Fs2
	.byte	W06
	.byte			En2
	.byte	W06
	.byte			Cs2
	.byte	W06
	.byte			An1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			En1
	.byte	W12
	.byte		N06	, Gs1
	.byte	W06
	.byte			An1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N18	, An2
	.byte	W18
	.byte		N12	, An1
	.byte	W12
	.byte	PATT	
		.word	song_0034_3_4
	.byte		N06	, Bn1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N18	, Bn2
	.byte	W18
	.byte		N12	, Bn1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte	BEND	, c_v-64
	.byte		N12	
	.byte	W06
	.byte	BEND	, c_v
	.byte	W06
	.byte		N24	
	.byte	W24
	.byte	PATT	
		.word	song_0034_3_5
	.byte	PATT	
		.word	song_0034_3_2
	.byte	PATT	
		.word	song_0034_3_6
	.byte		N06	, Cs2, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Gs1
	.byte	W12
	.byte		N06	, Bn1
	.byte	W06
	.byte			Cs2
	.byte	W12
	.byte		N12	, Gs1
	.byte	W24
	.byte		N06	, Fs2
	.byte	W06
	.byte			Fn2
	.byte	W06
	.byte			Cs2
	.byte	W06
	.byte	PATT	
		.word	song_0034_3_4
	.byte		N06	, Bn1, v127
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte		N06	, An1
	.byte	W06
	.byte			Bn1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N18	, Bn2
	.byte	W18
	.byte		N12	, Bn1
	.byte	W12
	.byte		N18	, An1
	.byte	W18
	.byte		N06	
	.byte	W18
	.byte		N24	
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte			Gs1
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte		N96	, En1
	.byte	W96
	.byte	GOTO	
		.word	song_0034_3_7
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0034_4
song_0034_4:	@ 0x087DD8F4
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
song_0034_4_1:
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0034_4_1
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Cn2
	.byte		N06	, Dn6
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fn1
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn1
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N96	, Cs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
song_0034_4_2:
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0034_4_2
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn2
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			An1
	.byte		N06	, Ds6
	.byte	W06
	.byte			An1
	.byte		N06	, En6
	.byte	W06
	.byte			Fn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, An2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0034_4_2
	.byte	PATT	
		.word	song_0034_4_2
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Dn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte	PATT	
		.word	song_0034_4_2
	.byte	PATT	
		.word	song_0034_4_2
	.byte	PATT	
		.word	song_0034_4_2
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn1
	.byte		N06	, En6
	.byte	W03
	.byte		N03	, Dn1
	.byte	W03
	.byte		N06	
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N96	, Cs2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
song_0034_4_3:
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0034_4_3
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Fn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N96	, An2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0034_4_3
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Ds6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N48	, Cs2
	.byte		N01	, Dn6
	.byte		N01	, En6
	.byte	W24
	.byte		N06	, Cn1
	.byte		N06	, An2
	.byte		N01	, Dn6
	.byte		N01	, En6
	.byte	W24
	.byte		N06	, Cn1
	.byte		N48	, Cs2
	.byte		N01	, Dn6
	.byte		N01	, En6
	.byte	W24
	.byte		N06	, Cn1
	.byte		N06	, An2
	.byte		N01	, Dn6
	.byte		N01	, En6
	.byte	W24
	.byte		N06	, Cn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Cn2
	.byte		N06	, Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Ds6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			An1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N03	, Dn6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Fn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn1
	.byte		N06	, En6
	.byte	W03
	.byte		N03	, Dn1
	.byte	W03
	.byte		N06	
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N96	, Cs2
	.byte		N06	, En6
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
song_0034_4_4:
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0034_4_4
song_0034_4_5:
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Dn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0034_4_4
	.byte	PATT	
		.word	song_0034_4_4
	.byte		N06	, Cn1, v127
	.byte		N06	, En6
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N03	, Dn1
	.byte		N06	, En6
	.byte	W03
	.byte		N03	, Dn1
	.byte	W03
	.byte		N06	, Cn1
	.byte		N06	, Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Dn1
	.byte		N06	, Ds6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N03	, Dn6
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	, Cn2
	.byte		N06	, En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			An1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			An1
	.byte		N06	, En6
	.byte	W06
	.byte			Fn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Fn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N96	, An2
	.byte		N06	, En6
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn1
	.byte		N06	, En6
	.byte	W06
	.byte			Cn1
	.byte		N06	, En6
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte			En6
	.byte	W06
	.byte			Dn6
	.byte	W06
	.byte			Cn1
	.byte		N06	, Dn1
	.byte		N06	, Dn6
	.byte	W06
	.byte			Ds6
	.byte	W06
	.byte			En6
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0034_4_4
	.byte	PATT	
		.word	song_0034_4_4
	.byte	PATT	
		.word	song_0034_4_5
	.byte	PATT	
		.word	song_0034_4_4
	.byte	PATT	
		.word	song_0034_4_4
	.byte	PATT	
		.word	song_0034_4_4
	.byte		N06	, Cn1, v127
	.byte		N96	, Cs2
	.byte		N06	, Dn6
	.byte		N06	, En6
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte		N06	
	.byte	W06
	.byte			Dn1
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Cn1
	.byte		N03	, Dn1
	.byte	W03
	.byte		N03	
	.byte	W03
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte		N01	, En6
	.byte	W06
	.byte		N06	, Dn1
	.byte	W06
	.byte	GOTO	
		.word	song_0034_4_1
	.byte	FINE

	.align 2
	.global song_0034
song_0034:	@ 0x087DDDA4
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0034_1		@ track
	.word	song_0034_2		@ track
	.word	song_0034_3		@ track
	.word	song_0034_4		@ track
