	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0050_1
song_0050_1:	@ 0x087E2378
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 5
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0050_1_4:
	.byte	TEMPO	, 38
	.byte		N72	, En3, v127
	.byte		N72	, En4
	.byte	W72
song_0050_1_1:
	.byte		N72	, Dn3, v127
	.byte		N72	, Fn3
	.byte		N72	, En4
	.byte	W72
	.byte	PEND
song_0050_1_2:
	.byte		N72	, Cs3, v127
	.byte		N72	, Fs3
	.byte		N72	, En4
	.byte	W72
	.byte	PEND
song_0050_1_3:
	.byte		N72	, Cn3, v127
	.byte		N72	, Gn3
	.byte		N72	, En4
	.byte	W72
	.byte	PEND
	.byte			En3
	.byte		N72	, En4
	.byte	W72
	.byte	PATT	
		.word	song_0050_1_1
	.byte	PATT	
		.word	song_0050_1_2
	.byte	PATT	
		.word	song_0050_1_3
	.byte		TIE	, Bn2, v127
	.byte		TIE	, An3
	.byte		TIE	, En4
	.byte	W72
	.byte	W72
	.byte		EOT	, Bn2
	.byte			An3
	.byte			En4
	.byte	GOTO	
		.word	song_0050_1_4
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0050_2
song_0050_2:	@ 0x087E23CC
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0050_2_1:
	.byte	W72
	.byte	W72
	.byte	W72
	.byte	W72
	.byte		N54	, En3, v127
	.byte	W54
	.byte		N03	, Fn3
	.byte	W03
	.byte			Gn3
	.byte	W03
	.byte			An3
	.byte	W03
	.byte			Bn3
	.byte	W03
	.byte			Cn4
	.byte	W03
	.byte			Dn4
	.byte	W03
	.byte		N54	, En4
	.byte	W54
	.byte		N03	, Fn4
	.byte	W03
	.byte			Gn4
	.byte	W03
	.byte			An4
	.byte	W03
	.byte			Bn4
	.byte	W03
	.byte			Cn5
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte		N84	, En5
	.byte	W72
	.byte	W12
	.byte		N06	
	.byte	W06
	.byte		N05	, Fn5
	.byte	W05
	.byte		N04	, En5
	.byte	W04
	.byte			Fn5
	.byte	W04
	.byte		N03	, En5
	.byte	W04
	.byte			Fn5
	.byte	W03
	.byte		N02	, En5
	.byte	W02
	.byte			Fn5
	.byte	W03
	.byte			En5
	.byte	W02
	.byte			Fn5
	.byte	W03
	.byte			En5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			En5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			En5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			En5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			En5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte			En5
	.byte	W02
	.byte			Fn5
	.byte	W02
	.byte		TIE	, En5
	.byte	W72
	.byte	W72
	.byte		EOT	
	.byte	GOTO	
		.word	song_0050_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0050_3
song_0050_3:	@ 0x087E2439
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0050_3_1:
	.byte		N24	, En4, v127
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte	PEND
	.byte	PATT	
		.word	song_0050_3_1
	.byte	PATT	
		.word	song_0050_3_1
	.byte	PATT	
		.word	song_0050_3_1
	.byte	PATT	
		.word	song_0050_3_1
	.byte	PATT	
		.word	song_0050_3_1
	.byte	PATT	
		.word	song_0050_3_1
	.byte	PATT	
		.word	song_0050_3_1
	.byte		N32	, En4, v127
	.byte	W72
	.byte	W72
	.byte	GOTO	
		.word	song_0050_3_1
	.byte	FINE

	.align 2
	.global song_0050
song_0050:	@ 0x087E247C
	.byte	3		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0050_1		@ track
	.word	song_0050_2		@ track
	.word	song_0050_3		@ track
