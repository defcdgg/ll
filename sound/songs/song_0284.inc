	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0284_1
song_0284_1:	@ 0x087E7BCC
	.byte	KEYSH	, 0
	.byte	TEMPO	, 60
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W01
	.byte	VOICE	, 6
	.byte	VOL	, v094
	.byte	W01
	.byte	PAN	, c_v
	.byte	W04
song_0284_1_4:
	.byte	TEMPO	, 39
	.byte	W72
	.byte	W72
	.byte		N36	, Dn3, v120
	.byte	W36
	.byte		N11	, Cs3
	.byte	W12
	.byte		N12	, Dn3
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte		N23	, An3
	.byte	W24
	.byte		N22	, Dn4
	.byte	W24
	.byte		N11	, En4
	.byte	W12
	.byte		N12	, Fs4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte		N20	, Gn4
	.byte	W18
	.byte		N05	, Dn4
	.byte	W06
	.byte		N36	, Gn4
	.byte	W36
	.byte		N32	, Fs4
	.byte	W36
	.byte			En4
	.byte	W32
	.byte	W03
	.byte		N44	, An3
	.byte	W01
	.byte	W44
	.byte	W02
	.byte		N19	, Dn4
	.byte	W19
	.byte		N06	, Cs4
	.byte	W06
	.byte		N48	, Dn4
	.byte	W01
	.byte	W68
	.byte	W03
	.byte			Fs4
	.byte	W01
	.byte	W44
	.byte	W03
	.byte		N11	, En4
	.byte	W11
	.byte		N07	, Dn4
	.byte	W11
	.byte		N36	
	.byte	W03
	.byte	W32
	.byte	W03
	.byte		N32	, Cs4
	.byte	W36
	.byte		TIE	, Bn3
	.byte	W01
	.byte	W72
	.byte	W68
	.byte	W03
	.byte		EOT	
	.byte	W01
song_0284_1_1:
	.byte		N12	, Bn1, v100
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			An1
	.byte	W12
	.byte		N24	, Fs3
	.byte	W24
	.byte	PEND
song_0284_1_2:
	.byte		N12	, Gn1, v100
	.byte	W12
	.byte			Dn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte		N24	, Fs3
	.byte	W24
	.byte	PEND
song_0284_1_3:
	.byte		N12	, Gn1, v100
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Bn2
	.byte	W12
	.byte			An1
	.byte	W12
	.byte		N24	, En3
	.byte	W24
	.byte	PEND
	.byte		N12	, Dn2
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Cs2
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte	PATT	
		.word	song_0284_1_1
	.byte	PATT	
		.word	song_0284_1_2
	.byte	PATT	
		.word	song_0284_1_3
	.byte		N12	, Bn1, v100
	.byte	W12
	.byte			Fs2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte		N36	, Fs3
	.byte	W36
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		N32	, Cs4
	.byte	W36
	.byte			Ds4
	.byte	W36
	.byte		N06	, As4, v127
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte		N12	, As4
	.byte	W12
	.byte			Bn4
	.byte	W12
	.byte			Cs5
	.byte	W12
	.byte	W72
	.byte		N36	, Ds3, v120
	.byte	W36
	.byte			Cs3
	.byte	W36
	.byte			Ds3
	.byte	W36
	.byte			Fs3
	.byte	W36
	.byte			Gs3
	.byte	W36
	.byte		N36	
	.byte	W36
	.byte			Fs3
	.byte	W36
	.byte			Ds3
	.byte	W36
	.byte			Gs3
	.byte	W36
	.byte			Gn3
	.byte	W36
	.byte			Fs3
	.byte	W36
	.byte		N12	, Gs3
	.byte	W12
	.byte		N10	, As3
	.byte	W12
	.byte		N08	, Bn3
	.byte	W12
	.byte		N68	
	.byte	W72
	.byte		N36	
	.byte	W36
	.byte			As3
	.byte	W36
	.byte		N92	, Bn3
	.byte	W72
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N13	
	.byte	W12
	.byte		N12	, Cs4
	.byte	W12
	.byte		N13	, Ds4
	.byte	W12
	.byte		N11	, Fs4
	.byte	W12
	.byte		N19	, En4
	.byte	W18
	.byte		N05	, Gs3
	.byte	W06
	.byte		N36	, En4
	.byte	W36
	.byte		N32	, Ds4
	.byte	W36
	.byte			Fs4
	.byte	W36
	.byte		N72	
	.byte	W36
	.byte	TEMPO	, 38
	.byte	W03
	.byte	TEMPO	, 37
	.byte	W03
	.byte	TEMPO	, 37
	.byte	W03
	.byte	TEMPO	, 36
	.byte	W03
	.byte	TEMPO	, 35
	.byte	W03
	.byte	TEMPO	, 34
	.byte	W02
	.byte	TEMPO	, 34
	.byte	W03
	.byte	TEMPO	, 33
	.byte	W03
	.byte	TEMPO	, 32
	.byte	W02
	.byte	TEMPO	, 32
	.byte	W03
	.byte	TEMPO	, 31
	.byte	W03
	.byte	TEMPO	, 30
	.byte	W02
	.byte	TEMPO	, 30
	.byte	W03
	.byte	TEMPO	, 29
	.byte		N60	, Ds4
	.byte	W02
	.byte	TEMPO	, 29
	.byte	W03
	.byte	TEMPO	, 28
	.byte	W02
	.byte	TEMPO	, 28
	.byte	W03
	.byte	TEMPO	, 27
	.byte	W02
	.byte	TEMPO	, 26
	.byte	W03
	.byte	TEMPO	, 26
	.byte	W02
	.byte	TEMPO	, 25
	.byte	W02
	.byte	TEMPO	, 25
	.byte	W03
	.byte	TEMPO	, 24
	.byte	W02
	.byte	TEMPO	, 24
	.byte	W02
	.byte	TEMPO	, 23
	.byte	W02
	.byte	TEMPO	, 23
	.byte	W03
	.byte	TEMPO	, 22
	.byte	W02
	.byte	TEMPO	, 22
	.byte	W02
	.byte	TEMPO	, 22
	.byte	W02
	.byte	TEMPO	, 21
	.byte	W02
	.byte	TEMPO	, 21
	.byte	W02
	.byte	TEMPO	, 20
	.byte	W02
	.byte	TEMPO	, 20
	.byte	W02
	.byte	TEMPO	, 19
	.byte	W02
	.byte	TEMPO	, 19
	.byte	W02
	.byte	TEMPO	, 19
	.byte	W02
	.byte	TEMPO	, 18
	.byte	W02
	.byte	TEMPO	, 18
	.byte	W02
	.byte	TEMPO	, 18
	.byte	W02
	.byte	TEMPO	, 17
	.byte	W02
	.byte	TEMPO	, 17
	.byte	W02
	.byte	TEMPO	, 16
	.byte	W02
	.byte	TEMPO	, 16
	.byte	W03
	.byte	TEMPO	, 15
	.byte	W02
	.byte	TEMPO	, 15
	.byte	W02
	.byte	TEMPO	, 15
	.byte	W02
	.byte	GOTO	
		.word	song_0284_1_4
	.byte	TEMPO	, 15
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0284_2
song_0284_2:	@ 0x087E7D82
	.byte	KEYSH	, 0
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W01
	.byte	VOICE	, 19
	.byte	VOL	, v100
	.byte	W01
	.byte	PAN	, c_v
	.byte	W04
song_0284_2_3:
	.byte	W72
	.byte	W72
	.byte		N12	, Dn2, v100
	.byte	W12
	.byte			An2
	.byte	W24
	.byte			Cs2
	.byte	W12
	.byte			An2
	.byte	W24
	.byte			Bn1
	.byte	W12
	.byte			Fs2
	.byte	W24
	.byte			An1
	.byte	W12
	.byte			Fs2
	.byte	W24
	.byte			Gn2
	.byte	W12
	.byte			Dn3
	.byte	W24
	.byte			Fs2
	.byte	W12
	.byte			Dn3
	.byte	W24
	.byte			En2
	.byte	W12
	.byte			Bn2
	.byte	W24
	.byte			An2
	.byte	W36
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W36
	.byte		N12	
	.byte	W36
song_0284_2_1:
	.byte		N12	, Gn2, v100
	.byte	W36
	.byte			Fs2
	.byte	W36
	.byte	PEND
song_0284_2_2:
	.byte		N12	, Gn2, v100
	.byte	W36
	.byte			An2
	.byte	W36
	.byte	PEND
	.byte			Dn3
	.byte	W36
	.byte			Cs3
	.byte	W24
	.byte			Fs2
	.byte	W12
	.byte			Bn2
	.byte	W36
	.byte			An2
	.byte	W36
	.byte	PATT	
		.word	song_0284_2_1
	.byte	PATT	
		.word	song_0284_2_2
	.byte		N12	, Bn2, v100
	.byte	W36
	.byte		N06	, Bn3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Fs2
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			En2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Gn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Bn2
	.byte	W06
	.byte			Gn2
	.byte	W06
	.byte			Dn2
	.byte	W06
	.byte			Fs2
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte			An2
	.byte	W06
	.byte			Fs2
	.byte	W06
	.byte	W12
	.byte		N12	, Gn2
	.byte	W12
	.byte			En3
	.byte	W24
	.byte			An2
	.byte	W12
	.byte			Cs3
	.byte	W12
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			En3
	.byte	W24
	.byte			Fs3
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			Bn2
	.byte	W24
	.byte			En3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	W72
	.byte	W72
	.byte	W36
	.byte		N03	, Fs2
	.byte	W03
	.byte			As2
	.byte	W03
	.byte			Cs3
	.byte	W03
	.byte			Fs3
	.byte	W03
	.byte			As3
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte			Fs4
	.byte	W18
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
	.byte	W12
	.byte			Bn2
	.byte	W03
	.byte			Ds3
	.byte	W03
	.byte			Fs3
	.byte	W03
	.byte			Bn3
	.byte	W03
	.byte			Ds4
	.byte	W03
	.byte			Fs4
	.byte	W03
	.byte			Bn4
	.byte	W03
	.byte			Ds5
	.byte	W03
	.byte			Fs5
	.byte	W03
	.byte			Bn5
	.byte	W32
	.byte	W01
	.byte	GOTO	
		.word	song_0284_2_3
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0284_3
song_0284_3:	@ 0x087E7EA6
	.byte	KEYSH	, 0
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W01
	.byte	VOICE	, 22
	.byte	VOL	, v094
	.byte	W01
	.byte	PAN	, c_v
	.byte	W04
song_0284_3_2:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W48
	.byte		N09	, An0, v120
	.byte	W12
	.byte		N10	
	.byte	W12
	.byte		N15	, Dn1
	.byte	W18
	.byte		N02	
	.byte	W06
	.byte		N11	
	.byte	W12
	.byte		N09	, Cs1
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte			Fs0
	.byte	W12
	.byte		N15	, Bn0
	.byte	W18
	.byte		N02	
	.byte	W06
	.byte		N11	
	.byte	W18
	.byte		N01	, An0
	.byte	W06
	.byte		N08	
	.byte	W12
	.byte		N10	
	.byte	W12
	.byte		N14	, Gn0
	.byte	W18
	.byte		N02	
	.byte	W06
	.byte		N08	
	.byte	W12
	.byte		N08	
	.byte	W12
	.byte		N09	
	.byte	W12
	.byte		N10	
	.byte	W12
	.byte		N15	, An0
	.byte	W18
	.byte		N02	
	.byte	W06
	.byte		N12	
	.byte	W24
	.byte		N08	
	.byte	W12
	.byte		N10	
	.byte	W12
	.byte		N14	, Gn0
	.byte	W18
	.byte		N02	
	.byte	W06
	.byte		N12	
	.byte	W18
	.byte		N02	
	.byte	W06
	.byte		N09	
	.byte	W12
	.byte		N10	
	.byte	W12
	.byte		N68	
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W60
	.byte		N12	, Fs0
	.byte	W12
	.byte		N48	, Gn0
	.byte	W60
	.byte		N12	
	.byte	W12
	.byte		N48	, Fs0
	.byte	W60
	.byte		N12	
	.byte	W12
	.byte		N48	, En0
	.byte	W60
	.byte		N12	
	.byte	W12
	.byte		N48	, Dn1
	.byte	W60
	.byte		N12	, An0
	.byte	W12
	.byte		N36	, En1
	.byte	W36
	.byte			Fs1
	.byte	W36
	.byte			Cn1
	.byte	W36
	.byte			Bn0
	.byte	W36
	.byte			Gn0
	.byte	W36
	.byte		N24	, Gn1
	.byte	W24
	.byte		N12	, En1
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte			Fs0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte			Fs0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Fs1
	.byte	W12
	.byte			Fs0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N06	, Fs1
	.byte	W06
	.byte			Fs0
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	W72
	.byte			Bn0
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			As0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Gs0
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Fs0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			En0
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Ds1
	.byte	W18
	.byte		N06	, Fs0
	.byte	W06
	.byte			As0
	.byte	W06
	.byte			Ds1
	.byte	W06
	.byte		N12	, Gs0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			En1
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte			Fs0
	.byte	W06
	.byte		N12	, Gn0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Fs0
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Gs0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
song_0284_3_1:
	.byte		N12	, En1, v120
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PEND
	.byte			Fs0
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Bn1
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, As1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, Gs1
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	, Fs1
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PATT	
		.word	song_0284_3_1
	.byte		N12	, Fs1, v120
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Fs0
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Bn0
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N56	
	.byte	W72
	.byte	GOTO	
		.word	song_0284_3_2
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0284_4
song_0284_4:	@ 0x087E8009
	.byte	KEYSH	, 0
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W01
	.byte	VOICE	, 3
	.byte	VOL	, v094
	.byte	W01
	.byte	PAN	, c_v
	.byte	W04
song_0284_4_1:
	.byte		N02	, Dn4, v040
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			An3
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0284_4_1
	.byte	PATT	
		.word	song_0284_4_1
	.byte	PATT	
		.word	song_0284_4_1
	.byte	PATT	
		.word	song_0284_4_1
	.byte	PATT	
		.word	song_0284_4_1
	.byte		N36	, Dn3, v100
	.byte	W36
	.byte		N32	, Cs3
	.byte	W36
	.byte			Dn3
	.byte	W36
	.byte			An3
	.byte	W36
	.byte			Gn3
	.byte	W36
	.byte		N32	
	.byte	W36
	.byte		N36	, Fs3
	.byte	W36
	.byte		N32	, En3
	.byte	W36
	.byte			Fs3
	.byte	W36
	.byte		N32	
	.byte	W36
	.byte		N72	
	.byte	W72
	.byte		N21	, Bn3, v127
	.byte	W24
	.byte		N10	, Fs4
	.byte	W12
	.byte		N24	
	.byte	W36
	.byte		N17	, Cs4
	.byte	W18
	.byte		N05	, Dn4
	.byte	W06
	.byte		N12	, En4
	.byte	W12
	.byte		N23	, Cs4
	.byte	W36
	.byte		N10	, Bn3
	.byte	W12
	.byte		N11	, Cs4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte		N23	, En4
	.byte	W24
	.byte		N13	, Dn4
	.byte	W12
	.byte		N19	, Fs4
	.byte	W18
	.byte		N05	, En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte		N06	, En4
	.byte	W06
	.byte		N20	, Fs4
	.byte	W36
	.byte		N24	, Bn3
	.byte	W24
	.byte		N10	, Fs4
	.byte	W12
	.byte		N15	
	.byte	W36
	.byte		N19	, Cs4
	.byte	W18
	.byte		N04	, Dn4
	.byte	W06
	.byte		N11	, En4
	.byte	W12
	.byte		N14	, Cs4
	.byte	W36
	.byte		N11	, Bn3
	.byte	W12
	.byte			Cs4
	.byte	W12
	.byte		N13	, Dn4
	.byte	W12
	.byte		N17	, Cs4
	.byte	W18
	.byte		N05	, Bn3
	.byte	W06
	.byte		N12	, Cs4
	.byte	W12
	.byte		N52	, Bn3
	.byte	W72
	.byte		N44	, Fs4
	.byte	W48
	.byte		N11	, En4
	.byte	W12
	.byte		N13	, Dn4
	.byte	W12
	.byte		N48	, Fs4
	.byte	W48
	.byte		N13	, En4
	.byte	W12
	.byte		N09	, Fs4
	.byte	W12
	.byte		N44	
	.byte	W48
	.byte		N11	, Bn4
	.byte	W12
	.byte		N12	, Cs5
	.byte	W12
	.byte		N52	, An4
	.byte	W72
	.byte		N17	, Bn4
	.byte	W18
	.byte		N06	, An4
	.byte	W06
	.byte		N04	, Gn4
	.byte	W06
	.byte		N05	, Fs4
	.byte	W06
	.byte		N10	, An4
	.byte	W12
	.byte		N11	, En4
	.byte	W12
	.byte			Fs4
	.byte	W12
	.byte		N17	, Gn4
	.byte	W18
	.byte		N06	, Fs4
	.byte	W06
	.byte		N05	, En4
	.byte	W06
	.byte		N06	, Dn4
	.byte	W06
	.byte		N13	, Fs4
	.byte	W12
	.byte		N08	, Bn3
	.byte	W12
	.byte		N10	, Dn4
	.byte	W12
	.byte		N05	, En4
	.byte	W06
	.byte		N03	, Dn4
	.byte	W06
	.byte		N20	
	.byte	W24
	.byte		N12	
	.byte	W12
	.byte		N10	, En4
	.byte	W12
	.byte		N11	, Gn4
	.byte	W12
	.byte		N84	, Fs4
	.byte	W72
	.byte	W72
	.byte		N02	, Cs4, v040
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte		N11	, Fs4, v127
	.byte	W12
	.byte		N22	
	.byte	W24
	.byte		N09	
	.byte	W12
	.byte		N10	, Gn4
	.byte	W12
	.byte		N12	, Gs4
	.byte	W12
	.byte		N11	, As4
	.byte	W12
	.byte		N54	, Bn4
	.byte	W60
	.byte		N07	
	.byte	W12
	.byte		N11	
	.byte	W12
	.byte			As4
	.byte	W12
	.byte			Bn4
	.byte	W12
	.byte		N22	, Gs4
	.byte	W36
	.byte		N10	, As4
	.byte	W12
	.byte		N17	, Gs4
	.byte	W18
	.byte		N05	, As4
	.byte	W06
	.byte		N21	, Fs4
	.byte	W36
	.byte		N17	
	.byte	W18
	.byte		N05	, En4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte		N21	, Bn4
	.byte	W24
	.byte		N11	, Gn4
	.byte	W12
	.byte		N32	, Fs4
	.byte	W36
	.byte		N09	, Gs4
	.byte	W12
	.byte			As4
	.byte	W12
	.byte		N10	, Bn4
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N10	, Gs4
	.byte	W12
	.byte		N11	, As4
	.byte	W12
	.byte		N08	, Bn4
	.byte	W12
	.byte		N36	
	.byte	W36
	.byte		N23	, As4
	.byte	W24
	.byte		N08	, Bn4
	.byte	W12
	.byte		N88	
	.byte	W72
	.byte	W72
	.byte	W36
	.byte		N12	, Gs3, v100
	.byte	W12
	.byte		N11	, As3
	.byte	W12
	.byte		N10	, Bn3
	.byte	W12
	.byte		N32	, Fs4
	.byte	W36
	.byte		N30	, En4
	.byte	W36
	.byte		N72	
	.byte	W72
	.byte		N64	, Ds4
	.byte	W72
	.byte	GOTO	
		.word	song_0284_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0284_5
song_0284_5:	@ 0x087E81A7
	.byte	KEYSH	, 0
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W01
	.byte	VOICE	, 126
	.byte	VOL	, v094
	.byte	W01
	.byte	PAN	, c_v
	.byte	W04
song_0284_5_5:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W54
	.byte		N06	, Bn1, v120
	.byte	W06
	.byte			An1
	.byte	W06
	.byte			Gn1
	.byte	W06
song_0284_5_1:
	.byte		N12	, Cn1, v120
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Dn1
	.byte	W36
	.byte	PEND
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
	.byte		N12	, Cn1, v120
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Dn1
	.byte	W18
	.byte		N12	
	.byte	W18
	.byte	PATT	
		.word	song_0284_5_1
	.byte	W72
song_0284_5_2:
	.byte		N12	, Cn1, v120
	.byte	W24
	.byte			Cs1
	.byte	W12
	.byte			Cn1
	.byte	W36
	.byte	PEND
	.byte	PATT	
		.word	song_0284_5_2
	.byte	PATT	
		.word	song_0284_5_2
	.byte	PATT	
		.word	song_0284_5_2
	.byte	PATT	
		.word	song_0284_5_2
	.byte	PATT	
		.word	song_0284_5_2
	.byte	PATT	
		.word	song_0284_5_2
	.byte	PATT	
		.word	song_0284_5_2
song_0284_5_3:
	.byte		N12	, Cn1, v120
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W12
	.byte		N12	, Cs1
	.byte	W24
	.byte			Cn1
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0284_5_3
	.byte	PATT	
		.word	song_0284_5_3
	.byte	PATT	
		.word	song_0284_5_3
	.byte	PATT	
		.word	song_0284_5_3
	.byte	PATT	
		.word	song_0284_5_3
	.byte	PATT	
		.word	song_0284_5_3
	.byte		N12	, Cn1, v120
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte			Cn1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	, Cn1
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Dn1
	.byte	W06
	.byte		N06	, Cn1
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Dn1
	.byte	W12
	.byte	W72
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
song_0284_5_4:
	.byte		N12	, Cn1, v120
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte			Dn1
	.byte	W18
	.byte		N06	
	.byte	W06
	.byte			Bn1
	.byte	W06
	.byte			Gn1
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_4
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_1
	.byte	PATT	
		.word	song_0284_5_4
	.byte	W72
	.byte	GOTO	
		.word	song_0284_5_5
	.byte	FINE

	.align 2
	.global song_0284
song_0284:	@ 0x087E82B8
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0284_1		@ track
	.word	song_0284_2		@ track
	.word	song_0284_3		@ track
	.word	song_0284_4		@ track
	.word	song_0284_5		@ track
