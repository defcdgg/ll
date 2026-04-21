	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0047_1
song_0047_1:	@ 0x087E175C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 11
	.byte	VOL	, v100
	.byte	PAN	, c_v
	.byte	W24
song_0047_1_1:
	.byte	TEMPO	, 72
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N96	, En3, v127
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W96
	.byte			Gn3
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W72
	.byte		N24	, Fn3
	.byte	W24
	.byte		N96	, Gn3
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W72
	.byte		N24	, Fn3
	.byte	W24
	.byte		N96	, Gn3
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W72
	.byte		N24	, Fn3
	.byte	W24
	.byte		N96	, Gn3
	.byte	W96
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte	W72
	.byte		N24	, Fn3
	.byte	W24
	.byte	GOTO	
		.word	song_0047_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0047_2
song_0047_2:	@ 0x087E17B4
	.byte	KEYSH	, 0
	.byte	VOICE	, 2
	.byte	VOL	, v100
	.byte	PAN	, c_v
	.byte	W24
song_0047_2_5:
	.byte		TIE	, En1, v127
	.byte	W96
	.byte	W96
	.byte		EOT	
	.byte		TIE	
	.byte	W96
	.byte	W40
	.byte		EOT	
	.byte	W08
	.byte		N40	, Dn1
	.byte	W48
song_0047_2_1:
	.byte		N40	, En1, v127
	.byte	W48
	.byte		N40	
	.byte	W48
	.byte	PEND
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_1
song_0047_2_2:
	.byte		N40	, En1, v127
	.byte	W48
	.byte		N12	, Dn1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_2
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_2
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_1
	.byte	PATT	
		.word	song_0047_2_2
song_0047_2_3:
	.byte		N40	, Gn1, v127
	.byte	W48
	.byte		N40	
	.byte	W48
	.byte	PEND
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_3
song_0047_2_4:
	.byte		N40	, Gn1, v127
	.byte	W48
	.byte		N12	, Fn1
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_4
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_4
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_3
	.byte	PATT	
		.word	song_0047_2_4
	.byte	GOTO	
		.word	song_0047_2_5
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0047_3
song_0047_3:	@ 0x087E1887
	.byte	KEYSH	, 0
	.byte	VOICE	, 5
	.byte	VOL	, v100
	.byte	PAN	, c_v-40
	.byte	W24
song_0047_3_9:
	.byte		N08	, En2, v127
	.byte		N08	, Bn2
	.byte	W12
	.byte			En2
	.byte		N08	, Bn2
	.byte	W12
	.byte			En2
	.byte		N08	, Bn2
	.byte	W24
	.byte			En2
	.byte		N08	, Bn2
	.byte	W24
	.byte			En2
	.byte		N08	, Bn2
	.byte	W12
	.byte			En2
	.byte		N08	, Bn2
	.byte	W12
	.byte			Gn2
	.byte		N08	, Dn3
	.byte	W12
	.byte			Gn2
	.byte		N08	, Dn3
	.byte	W12
	.byte			Gn2
	.byte		N08	, Dn3
	.byte	W24
	.byte			Gn2
	.byte		N08	, Dn3
	.byte	W24
	.byte			Gn2
	.byte		N08	, Dn3
	.byte	W12
	.byte			Gn2
	.byte		N08	, Dn3
	.byte	W12
	.byte			Fs2
	.byte		N08	, Cs3
	.byte	W12
	.byte			Fs2
	.byte		N08	, Cs3
	.byte	W12
	.byte			Fs2
	.byte		N08	, Cs3
	.byte	W24
	.byte			Fs2
	.byte		N08	, Cs3
	.byte	W24
	.byte			Fs2
	.byte		N08	, Cs3
	.byte	W12
	.byte			Fs2
	.byte		N08	, Cs3
	.byte	W12
	.byte			Dn2
	.byte		N08	, An2
	.byte	W12
	.byte			Dn2
	.byte		N08	, An2
	.byte	W12
	.byte			Dn2
	.byte		N08	, An2
	.byte	W24
	.byte			Dn2
	.byte		N08	, An2
	.byte	W12
	.byte			Dn2
	.byte		N08	, An2
	.byte	W12
	.byte			Dn2
	.byte		N08	, An2
	.byte	W12
	.byte			Dn2
	.byte		N08	, An2
	.byte	W12
song_0047_3_1:
	.byte		N08	, En3, v127
	.byte		N08	, Bn3
	.byte	W12
	.byte			En3
	.byte		N08	, Bn3
	.byte	W12
	.byte			En3
	.byte		N08	, Bn3
	.byte	W24
	.byte			En3
	.byte		N08	, Bn3
	.byte	W24
	.byte			En3
	.byte		N08	, Bn3
	.byte	W12
	.byte			En3
	.byte		N08	, Bn3
	.byte	W12
	.byte	PEND
song_0047_3_2:
	.byte		N08	, Gn3, v127
	.byte		N08	, Dn4
	.byte	W12
	.byte			Gn3
	.byte		N08	, Dn4
	.byte	W12
	.byte			Gn3
	.byte		N08	, Dn4
	.byte	W24
	.byte			Gn3
	.byte		N08	, Dn4
	.byte	W24
	.byte			Gn3
	.byte		N08	, Dn4
	.byte	W12
	.byte			Gn3
	.byte		N08	, Dn4
	.byte	W12
	.byte	PEND
song_0047_3_3:
	.byte		N08	, Fs3, v127
	.byte		N08	, Cs4
	.byte	W12
	.byte			Fs3
	.byte		N08	, Cs4
	.byte	W12
	.byte			Fs3
	.byte		N08	, Cs4
	.byte	W24
	.byte			Fs3
	.byte		N08	, Cs4
	.byte	W24
	.byte			Fs3
	.byte		N08	, Cs4
	.byte	W12
	.byte			Fs3
	.byte		N08	, Cs4
	.byte	W12
	.byte	PEND
song_0047_3_4:
	.byte		N08	, Dn3, v127
	.byte		N08	, An3
	.byte	W12
	.byte			Dn3
	.byte		N08	, An3
	.byte	W12
	.byte			Dn3
	.byte		N08	, An3
	.byte	W24
	.byte			Dn3
	.byte		N08	, An3
	.byte	W12
	.byte			Dn3
	.byte		N08	, An3
	.byte	W12
	.byte			Dn3
	.byte		N08	, An3
	.byte	W12
	.byte			Dn3
	.byte		N08	, An3
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0047_3_1
	.byte	PATT	
		.word	song_0047_3_2
	.byte	PATT	
		.word	song_0047_3_3
	.byte	PATT	
		.word	song_0047_3_4
	.byte	PATT	
		.word	song_0047_3_1
	.byte	PATT	
		.word	song_0047_3_2
	.byte	PATT	
		.word	song_0047_3_3
	.byte	PATT	
		.word	song_0047_3_4
	.byte	PATT	
		.word	song_0047_3_1
	.byte	PATT	
		.word	song_0047_3_2
	.byte	PATT	
		.word	song_0047_3_3
	.byte	PATT	
		.word	song_0047_3_4
song_0047_3_5:
	.byte		N08	, Dn4, v127
	.byte		N08	, Gn4
	.byte	W12
	.byte			Dn4
	.byte		N08	, Gn4
	.byte	W12
	.byte			Dn4
	.byte		N08	, Gn4
	.byte	W24
	.byte			Dn4
	.byte		N08	, Gn4
	.byte	W24
	.byte			Dn4
	.byte		N08	, Gn4
	.byte	W12
	.byte			Dn4
	.byte		N08	, Gn4
	.byte	W12
	.byte	PEND
song_0047_3_6:
	.byte		N08	, Fn4, v127
	.byte		N08	, As4
	.byte	W12
	.byte			Fn4
	.byte		N08	, As4
	.byte	W12
	.byte			Fn4
	.byte		N08	, As4
	.byte	W24
	.byte			Fn4
	.byte		N08	, As4
	.byte	W24
	.byte			Fn4
	.byte		N08	, As4
	.byte	W12
	.byte			Fn4
	.byte		N08	, As4
	.byte	W12
	.byte	PEND
song_0047_3_7:
	.byte		N08	, En4, v127
	.byte		N08	, An4
	.byte	W12
	.byte			En4
	.byte		N08	, An4
	.byte	W12
	.byte			En4
	.byte		N08	, An4
	.byte	W24
	.byte			En4
	.byte		N08	, An4
	.byte	W24
	.byte			En4
	.byte		N08	, An4
	.byte	W12
	.byte			En4
	.byte		N08	, An4
	.byte	W12
	.byte	PEND
song_0047_3_8:
	.byte		N08	, Cn4, v127
	.byte		N08	, Fn4
	.byte	W12
	.byte			Cn4
	.byte		N08	, Fn4
	.byte	W12
	.byte			Cn4
	.byte		N08	, Fn4
	.byte	W24
	.byte			Cn4
	.byte		N08	, Fn4
	.byte	W12
	.byte			Cn4
	.byte		N08	, Fn4
	.byte	W12
	.byte			Cn4
	.byte		N08	, Fn4
	.byte	W12
	.byte			Cn4
	.byte		N08	, Fn4
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0047_3_5
	.byte	PATT	
		.word	song_0047_3_6
	.byte	PATT	
		.word	song_0047_3_7
	.byte	PATT	
		.word	song_0047_3_8
	.byte	PATT	
		.word	song_0047_3_5
	.byte	PATT	
		.word	song_0047_3_6
	.byte	PATT	
		.word	song_0047_3_7
	.byte	PATT	
		.word	song_0047_3_8
	.byte	PATT	
		.word	song_0047_3_5
	.byte	PATT	
		.word	song_0047_3_6
	.byte	PATT	
		.word	song_0047_3_7
	.byte	PATT	
		.word	song_0047_3_8
	.byte	GOTO	
		.word	song_0047_3_9
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0047_4
song_0047_4:	@ 0x087E1A54
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v078
	.byte	PAN	, c_v
	.byte	W24
song_0047_4_6:
	.byte		N24	, Bn2, v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N20	
	.byte		N12	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
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
song_0047_4_1:
	.byte		N12	, Dn5, v127
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
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
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte		N04	
	.byte	W04
	.byte	PEND
song_0047_4_2:
	.byte		N12	, Dn5, v127
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
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
	.byte	PEND
song_0047_4_3:
	.byte		N12	, Dn5, v127
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
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
	.byte	PEND
	.byte		N19	, Bn2
	.byte		N12	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
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
	.byte	PATT	
		.word	song_0047_4_1
	.byte	PATT	
		.word	song_0047_4_2
	.byte	PATT	
		.word	song_0047_4_3
song_0047_4_4:
	.byte		N17	, Bn2, v127
	.byte		N12	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
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
	.byte	PEND
	.byte	PATT	
		.word	song_0047_4_1
	.byte	PATT	
		.word	song_0047_4_2
	.byte	PATT	
		.word	song_0047_4_3
	.byte	PATT	
		.word	song_0047_4_4
	.byte	PATT	
		.word	song_0047_4_1
	.byte	PATT	
		.word	song_0047_4_2
	.byte	PATT	
		.word	song_0047_4_3
	.byte		N15	, Bn2, v127
	.byte		N15	, Gn3
	.byte	W48
	.byte		N12	
	.byte	W48
	.byte		N12	
	.byte	W48
	.byte		N10	
	.byte	W48
	.byte		N10	
	.byte	W48
	.byte		N10	
	.byte	W48
	.byte		N12	
	.byte	W48
	.byte			Fn3
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
song_0047_4_5:
	.byte		N15	, Bn2, v127
	.byte		N12	, Dn5
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N06	
	.byte	W06
	.byte		N12	
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
	.byte	PEND
	.byte	PATT	
		.word	song_0047_4_1
	.byte	PATT	
		.word	song_0047_4_2
	.byte	PATT	
		.word	song_0047_4_3
	.byte	PATT	
		.word	song_0047_4_5
	.byte	PATT	
		.word	song_0047_4_1
	.byte	PATT	
		.word	song_0047_4_2
	.byte	PATT	
		.word	song_0047_4_3
	.byte	PATT	
		.word	song_0047_4_5
	.byte	PATT	
		.word	song_0047_4_1
	.byte	PATT	
		.word	song_0047_4_2
	.byte	PATT	
		.word	song_0047_4_3
	.byte	GOTO	
		.word	song_0047_4_6
	.byte	FINE

	.align 2
	.global song_0047
song_0047:	@ 0x087E1BC4
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0047_1		@ track
	.word	song_0047_2		@ track
	.word	song_0047_3		@ track
	.word	song_0047_4		@ track
