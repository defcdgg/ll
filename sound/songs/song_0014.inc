	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0014_1
song_0014_1:	@ 0x087D772C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 4
	.byte	VOL	, v078
	.byte	PAN	, c_v
	.byte	W06
song_0014_1_2:
	.byte	TEMPO	, 44
	.byte	W96
	.byte	W24
	.byte		N72	, En3, v127
	.byte		N72	, An3
	.byte	W72
	.byte	W96
	.byte	W24
	.byte			En3
	.byte		N72	, An3
	.byte	W72
	.byte	W36
	.byte		N60	, En3
	.byte		N60	, Cn4
	.byte	W60
song_0014_1_1:
	.byte	W36
	.byte		N20	, En3, v127
	.byte		N20	, Cn4
	.byte	W24
	.byte			En3
	.byte		N20	, Cn4
	.byte	W24
	.byte		N12	, En3
	.byte		N12	, Cn4
	.byte	W12
	.byte	PEND
	.byte	W96
	.byte	W24
	.byte		N72	, En3
	.byte		N72	, An3
	.byte	W72
	.byte	W96
	.byte	W24
	.byte			En3
	.byte		N72	, An3
	.byte	W72
	.byte	W96
	.byte	W24
	.byte			En3
	.byte		N72	, An3
	.byte	W72
	.byte	W36
	.byte		N60	, En3
	.byte		N60	, Cn4
	.byte	W60
	.byte	PATT	
		.word	song_0014_1_1
	.byte	W96
	.byte	W24
	.byte		N72	, En3, v127
	.byte		N72	, An3
	.byte	W72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N84	
	.byte		N84	, Dn4
	.byte	W96
	.byte	GOTO	
		.word	song_0014_1_2
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0014_2
song_0014_2:	@ 0x087D7791
	.byte	KEYSH	, 0
	.byte	VOICE	, 5
	.byte	VOL	, v100
	.byte	PAN	, c_v
	.byte	W06
song_0014_2_4:
	.byte		N16	, En3, v127
	.byte		N16	, An3
	.byte	W96
song_0014_2_1:
	.byte	W72
	.byte		N12	, Dn4, v127
	.byte	W12
	.byte		N04	, En4
	.byte	W12
	.byte	PEND
	.byte		N16	, En3
	.byte		N16	, An3
	.byte	W96
	.byte	PATT	
		.word	song_0014_2_1
song_0014_2_2:
	.byte	W36
	.byte		N60	, An3, v127
	.byte		N60	, Fs4
	.byte	W60
	.byte	PEND
song_0014_2_3:
	.byte	W36
	.byte		N20	, An3, v127
	.byte		N20	, Fs4
	.byte	W24
	.byte			An3
	.byte		N20	, Fs4
	.byte	W24
	.byte		N12	, An3
	.byte		N12	, Fs4
	.byte	W12
	.byte	PEND
	.byte		N16	, En3
	.byte		N16	, An3
	.byte	W96
	.byte	PATT	
		.word	song_0014_2_1
	.byte		N16	, En3, v127
	.byte		N16	, An3
	.byte	W96
	.byte	PATT	
		.word	song_0014_2_1
	.byte		N16	, En3, v127
	.byte		N16	, An3
	.byte	W96
	.byte	PATT	
		.word	song_0014_2_1
	.byte	PATT	
		.word	song_0014_2_2
	.byte	PATT	
		.word	song_0014_2_3
	.byte		N16	, En3, v127
	.byte		N16	, An3
	.byte	W96
	.byte	PATT	
		.word	song_0014_2_1
	.byte	W96
	.byte	W96
	.byte		TIE	, En4, v127
	.byte		TIE	, Fs4
	.byte	W96
	.byte	W84
	.byte		EOT	, En4
	.byte			Fs4
	.byte	W12
	.byte	GOTO	
		.word	song_0014_2_4
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0014_3
song_0014_3:	@ 0x087D7814
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v100
	.byte	PAN	, c_v
	.byte	W06
song_0014_3_1:
	.byte		N06	, An2, v127
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W84
	.byte	PEND
	.byte	W96
	.byte	PATT	
		.word	song_0014_3_1
	.byte	W96
	.byte	PATT	
		.word	song_0014_3_1
	.byte	PATT	
		.word	song_0014_3_1
	.byte	PATT	
		.word	song_0014_3_1
	.byte	W96
	.byte	PATT	
		.word	song_0014_3_1
	.byte	W96
	.byte	PATT	
		.word	song_0014_3_1
	.byte	W96
	.byte	PATT	
		.word	song_0014_3_1
	.byte	PATT	
		.word	song_0014_3_1
	.byte	PATT	
		.word	song_0014_3_1
	.byte	W96
	.byte	W06
	.byte		N06	, Cn3, v127
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Dn3
	.byte	W06
	.byte			Gs3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Gs3
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Bn3
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			En4
	.byte	W06
	.byte			Dn4
	.byte	W06
	.byte	W06
	.byte			Cs3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Ds3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Fs3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte			Cs4
	.byte	W06
	.byte			Cn4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Ds4
	.byte	W06
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0014_3_1
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0014_4
song_0014_4:	@ 0x087D78A1
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v086
	.byte	PAN	, c_v
	.byte	W06
song_0014_4_1:
	.byte		N06	, Dn1, v080
	.byte		N24	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte		N12	, En4, v127
	.byte	W12
	.byte		N06	, Dn1, v080
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte		N12	, Gn3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N04	
	.byte		N06	, En4, v127
	.byte	W04
	.byte		N04	, Dn1, v080
	.byte	W02
	.byte		N06	, En4, v127
	.byte	W02
	.byte		N04	, Dn1, v080
	.byte	W04
	.byte		N06	
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte	PEND
song_0014_4_2:
	.byte		N06	, Dn1, v080
	.byte		N12	, Gn3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
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
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0014_4_1
	.byte	PATT	
		.word	song_0014_4_2
song_0014_4_3:
	.byte		N06	, Dn1, v080
	.byte		N06	, An3, v127
	.byte	W06
	.byte			Dn1, v080
	.byte		N06	, An3, v127
	.byte	W06
	.byte			Dn1, v080
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
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
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0014_4_3
	.byte		N24	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte		N12	, En4, v127
	.byte	W12
	.byte		N06	, Dn1, v080
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte		N12	, Gn3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N04	
	.byte		N06	, En4, v127
	.byte	W04
	.byte		N04	, Dn1, v080
	.byte	W02
	.byte		N06	, En4, v127
	.byte	W02
	.byte		N04	, Dn1, v080
	.byte	W04
	.byte		N06	
	.byte		N12	, An3, v127
	.byte	W06
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte	PATT	
		.word	song_0014_4_2
	.byte	PATT	
		.word	song_0014_4_1
	.byte	PATT	
		.word	song_0014_4_2
	.byte	PATT	
		.word	song_0014_4_1
	.byte	PATT	
		.word	song_0014_4_2
	.byte	PATT	
		.word	song_0014_4_3
	.byte	PATT	
		.word	song_0014_4_3
	.byte	PATT	
		.word	song_0014_4_1
	.byte	PATT	
		.word	song_0014_4_2
	.byte		N96	, An3, v127
	.byte	W96
	.byte		N96	
	.byte	W96
song_0014_4_4:
	.byte		N06	, Dn1, v080
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N06	
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
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0014_4_4
	.byte	GOTO	
		.word	song_0014_4_1
	.byte	FINE

	.align 2
	.global song_0014
song_0014:	@ 0x087D7A0C
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	188		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0014_1		@ track
	.word	song_0014_2		@ track
	.word	song_0014_3		@ track
	.word	song_0014_4		@ track
