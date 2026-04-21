	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0031_1
song_0031_1:	@ 0x087DC28C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 5
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
	.byte	TEMPO	, 70
	.byte	W24
song_0031_1_2:
	.byte		N16	, En3, v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0031_1_1:
	.byte		N08	, Bn2, v127
	.byte		N08	, Fs3
	.byte	W36
	.byte			Bn2
	.byte		N08	, Fs3
	.byte	W36
	.byte			Bn2
	.byte		N08	, Fs3
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0031_1_1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0031_1_1
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		TIE	, Gn2, v127
	.byte		TIE	, Dn3
	.byte	W72
	.byte	W72
	.byte		EOT	, Gn2
	.byte			Dn3
	.byte		N72	, Gn2
	.byte	W24
	.byte	W12
	.byte		N84	, Cn3
	.byte	W36
	.byte		N48	, En3
	.byte	W48
	.byte	GOTO	
		.word	song_0031_1_2
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0031_2
song_0031_2:	@ 0x087DC2DE
	.byte	KEYSH	, 0
	.byte	VOICE	, 8
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
	.byte		N03	, Fs2, v127
	.byte	W03
	.byte			Bn2
	.byte	W03
	.byte			Cs3
	.byte	W03
	.byte			En3
	.byte	W03
	.byte			Fs3
	.byte	W03
	.byte			Bn3
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte			En4
	.byte	W03
song_0031_2_2:
	.byte		N24	, Fs4, v127
	.byte	W96
	.byte	W96
	.byte	W96
song_0031_2_1:
	.byte	W72
	.byte		N03	, Fs2, v127
	.byte	W03
	.byte			Bn2
	.byte	W03
	.byte			Cs3
	.byte	W03
	.byte			En3
	.byte	W03
	.byte			Fs3
	.byte	W03
	.byte			Bn3
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte	PEND
	.byte		N24	, Fs4
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W72
	.byte		N03	, Fs5
	.byte	W03
	.byte			En5
	.byte	W03
	.byte			Cs5
	.byte	W03
	.byte			Bn4
	.byte	W03
	.byte			Fs4
	.byte	W03
	.byte			En4
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte			Bn3
	.byte	W03
	.byte		N24	, Fs3
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0031_2_1
	.byte		N24	, Fs4, v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	PATT	
		.word	song_0031_2_1
	.byte	GOTO	
		.word	song_0031_2_2
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0031_3
song_0031_3:	@ 0x087DC348
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
song_0031_3_1:
	.byte		N06	, Fs2, v127
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	, En3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	, Cs4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	, Bn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs5
	.byte	W06
	.byte		N04	, Bn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs5
	.byte	W06
	.byte		N04	, Bn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs5
	.byte	W06
	.byte		N04	, Bn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs6
	.byte	W06
	.byte		N04	, Bn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs6
	.byte	W06
	.byte		N04	, Bn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs6
	.byte	W06
	.byte		N04	, Bn4
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N48	, Fs2
	.byte	W48
	.byte			Gn2
	.byte	W48
	.byte		N72	, Cs2
	.byte	W72
	.byte		N24	, Dn2
	.byte	W24
	.byte		N96	, As1
	.byte	W96
	.byte		N06	, Bn3
	.byte		N08	, Fs5
	.byte	W06
	.byte		N04	, Bn3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs5
	.byte	W06
	.byte		N04	, Bn3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N06	
	.byte		N08	, Fs5
	.byte	W06
	.byte		N04	, Bn3
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N04	
	.byte	W06
	.byte		N48	, Fs3
	.byte	W48
	.byte			Gn3
	.byte	W48
	.byte		N72	, Cs3
	.byte	W72
	.byte		N24	, Dn3
	.byte	W24
	.byte			En4
	.byte	W24
	.byte			Cs4
	.byte	W24
	.byte			Dn4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte			Fs4
	.byte	W24
	.byte			Dn4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte			Fs4
	.byte	W24
	.byte		N16	, Gn4
	.byte	W24
	.byte		N48	, Dn3
	.byte		N48	, Fs3
	.byte	W48
	.byte		N48	
	.byte		N24	, Bn3
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N48	
	.byte		N48	, Dn4
	.byte	W48
	.byte		N24	, Ds4
	.byte		N24	, Gn4
	.byte	W24
	.byte	W96
	.byte	GOTO	
		.word	song_0031_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0031_4
song_0031_4:	@ 0x087DC4DA
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
	.byte	W24
song_0031_4_4:
	.byte		N08	, Fs1, v127
	.byte	W96
song_0031_4_1:
	.byte		N08	, Fs1, v127
	.byte	W36
	.byte		N08	
	.byte	W36
	.byte		N08	
	.byte	W24
	.byte	PEND
	.byte		N08	
	.byte	W96
	.byte	PATT	
		.word	song_0031_4_1
	.byte		N08	, Fs1, v127
	.byte	W96
	.byte	PATT	
		.word	song_0031_4_1
	.byte		N08	, Fs1, v127
	.byte	W96
	.byte	PATT	
		.word	song_0031_4_1
song_0031_4_2:
	.byte		N48	, Fs2, v127
	.byte	W48
	.byte			Gn2
	.byte	W48
	.byte	PEND
song_0031_4_3:
	.byte		N72	, Cs2, v127
	.byte	W72
	.byte		N24	, Dn2
	.byte	W24
	.byte	PEND
	.byte		N96	, As1
	.byte	W96
	.byte	PATT	
		.word	song_0031_4_1
	.byte	PATT	
		.word	song_0031_4_2
	.byte	PATT	
		.word	song_0031_4_3
	.byte		N24	, En2, v127
	.byte	W24
	.byte			Cs2
	.byte	W24
	.byte			Dn2
	.byte	W24
	.byte			En2
	.byte	W24
	.byte			Fs2
	.byte	W24
	.byte			Dn2
	.byte	W24
	.byte			En2
	.byte	W24
	.byte			Fs2
	.byte	W24
	.byte		N16	, Gn2
	.byte	W24
	.byte		TIE	, Gn1
	.byte	W72
	.byte	W72
	.byte		EOT	
	.byte		N24	, Gs1
	.byte	W24
	.byte	W96
	.byte	GOTO	
		.word	song_0031_4_4
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0031_5
song_0031_5:	@ 0x087DC54F
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v103
	.byte	PAN	, c_v
	.byte	W24
	.byte	W12
	.byte		N05	, Fs4, v127
	.byte	W06
	.byte		N05	
	.byte	W06
song_0031_5_3:
	.byte		N96	, Bn2, v127
	.byte		N96	, Fs3
	.byte	W96
song_0031_5_1:
	.byte		N36	, Cn5, v127
	.byte	W36
	.byte		N36	
	.byte	W36
	.byte		N24	
	.byte	W12
	.byte		N05	, Fs4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte	PEND
	.byte		N96	, Fs3
	.byte		N96	, Cn5
	.byte	W96
	.byte	PATT	
		.word	song_0031_5_1
	.byte		N96	, Bn2, v127
	.byte		N96	, Fs3
	.byte		N96	, Cn5
	.byte	W96
	.byte	PATT	
		.word	song_0031_5_1
	.byte		N36	, Fs3, v127
	.byte		N36	, Cn5
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N36	, Fs3
	.byte		N36	, Cn5
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Fs3
	.byte		N24	, Cn5
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
song_0031_5_2:
	.byte		N36	, Fs3, v127
	.byte		N36	, Cn5
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N36	, Fs3
	.byte		N36	, Cn5
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Fs3
	.byte		N24	, Cn5
	.byte		N01	, Dn5
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte	PEND
	.byte			Bn2
	.byte		N96	, Gn3
	.byte		N01	, Cn5
	.byte		N01	, Dn5
	.byte	W96
	.byte	W96
	.byte	W84
	.byte		N05	, Fs4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte	PATT	
		.word	song_0031_5_2
	.byte		N01	, Bn2, v127
	.byte		N01	, Cn5
	.byte		N01	, Dn5
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W24
	.byte		N24	, Gn3
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Gn3
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Gn3
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Gn3
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Gn3
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Gn3
	.byte		N01	, Dn5
	.byte	W12
	.byte		N01	
	.byte	W06
	.byte		N01	
	.byte	W06
	.byte		N24	, Cn5
	.byte		N01	, Dn5
	.byte	W24
	.byte	W12
	.byte		N24	, Cn5
	.byte	W36
	.byte		N24	
	.byte	W36
	.byte		N05	, Fs4
	.byte	W06
	.byte		N05	
	.byte	W06
	.byte	GOTO	
		.word	song_0031_5_3
	.byte	FINE

	.align 2
	.global song_0031
song_0031:	@ 0x087DC650
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0031_1		@ track
	.word	song_0031_2		@ track
	.word	song_0031_3		@ track
	.word	song_0031_4		@ track
	.word	song_0031_5		@ track
