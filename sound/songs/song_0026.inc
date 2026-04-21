	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0026_1
song_0026_1:	@ 0x087DAC84
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 3
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0026_1_1:
	.byte	TEMPO	, 42
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte	TEMPO	, 41
	.byte	W06
	.byte	TEMPO	, 40
	.byte	W06
	.byte	TEMPO	, 38
	.byte	W06
	.byte	TEMPO	, 36
	.byte	W06
	.byte	TEMPO	, 34
	.byte	W06
	.byte	TEMPO	, 36
	.byte	W06
	.byte	TEMPO	, 39
	.byte	W06
	.byte	TEMPO	, 42
	.byte	W06
	.byte		N72	, Dn4, v127
	.byte	W24
	.byte	TEMPO	, 40
	.byte	W12
	.byte	TEMPO	, 39
	.byte	W12
	.byte	TEMPO	, 38
	.byte	W12
	.byte	TEMPO	, 36
	.byte	W12
	.byte	TEMPO	, 42
	.byte		N24	, An3
	.byte	W24
	.byte		N96	, An4
	.byte	W96
	.byte		N72	, Gn4
	.byte	W72
	.byte		N12	, Fn4
	.byte	W12
	.byte			En4
	.byte	W12
	.byte		N90	, Dn4
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte		N48	
	.byte	W48
	.byte		N64	, An4
	.byte	W48
	.byte	W24
	.byte		N24	, En4
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte			Gn4
	.byte	W24
	.byte		N48	, An4
	.byte	W48
	.byte			Fn5
	.byte	W48
	.byte			En5
	.byte	W48
	.byte			Cn5
	.byte	W48
	.byte		N96	, Dn5
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0026_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0026_2
song_0026_2:	@ 0x087DAD00
	.byte	KEYSH	, 0
	.byte	VOICE	, 4
	.byte	VOL	, v062
	.byte	PAN	, c_v
	.byte	W24
song_0026_2_1:
	.byte		TIE	, Dn3, v127
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W78
	.byte		EOT	
	.byte	W06
	.byte		N16	, En3
	.byte	W12
	.byte	W04
	.byte		N10	, Gn3
	.byte	W09
	.byte		N07	, Fs3
	.byte	W10
	.byte		N72	
	.byte	W72
	.byte	W01
	.byte		N48	, An3
	.byte	W48
	.byte			Gn3
	.byte	W48
	.byte		N96	, Fs3
	.byte	W96
	.byte			Fn3
	.byte	W96
	.byte			En3
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte		N60	, Dn3
	.byte	W60
	.byte		N12	, En3
	.byte	W12
	.byte			Fs3
	.byte	W12
	.byte			Gn3
	.byte	W12
	.byte		N80	, An3
	.byte	W84
	.byte		N12	
	.byte	W12
	.byte		N10	
	.byte	W10
	.byte		N09	, Gn3
	.byte	W10
	.byte		N60	
	.byte	W60
	.byte	W03
	.byte		N12	, Fn3
	.byte	W13
	.byte	W01
	.byte		N11	
	.byte	W10
	.byte		N07	, En3
	.byte	W08
	.byte		N72	
	.byte	W76
	.byte	W01
	.byte	W96
	.byte	W96
	.byte		N48	, An2
	.byte	W48
	.byte		N72	, Dn3
	.byte	W48
	.byte	W24
	.byte		N24	, En3
	.byte	W24
	.byte			Fn3
	.byte	W24
	.byte			Gn3
	.byte	W24
	.byte		N48	, An3
	.byte	W48
	.byte	W01
	.byte		N68	, Dn3
	.byte	W44
	.byte	W03
	.byte	W24
	.byte		N24	, En3
	.byte	W24
	.byte			Fn3
	.byte	W24
	.byte			En3
	.byte	W24
	.byte		N06	, Fn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte		N36	, Fn3
	.byte	W36
	.byte		N32	, An3
	.byte	W36
	.byte		N06	, En3
	.byte	W06
	.byte			Fn3
	.byte	W06
	.byte		N24	, En3
	.byte	W23
	.byte			Gn3
	.byte	W24
	.byte	W01
	.byte			Fn3
	.byte	W24
	.byte			Gn3
	.byte	W24
	.byte		N48	, An3
	.byte	W48
	.byte		N72	, Dn4
	.byte	W48
	.byte	W24
	.byte		N48	, Cn4
	.byte	W48
	.byte		N24	, As3
	.byte	W24
	.byte		N07	, An3
	.byte	W07
	.byte			Gn3
	.byte	W06
	.byte		TIE	, An3
	.byte	W80
	.byte	W03
	.byte	W44
	.byte	W03
	.byte		EOT	
	.byte	W48
	.byte	W01
	.byte		N72	, Fs3
	.byte	W72
	.byte		N24	, Dn3
	.byte	W24
	.byte		N90	, An3
	.byte	W96
	.byte		N96	, Gn3
	.byte	W96
	.byte		N90	, En3
	.byte	W96
	.byte	GOTO	
		.word	song_0026_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0026_3
song_0026_3:	@ 0x087DADBA
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0026_3_4:
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W48
	.byte		N03	, As1, v127
	.byte	W04
	.byte			Fn2
	.byte	W04
	.byte			As2
	.byte	W04
	.byte			Dn3
	.byte	W03
	.byte			Fn3
	.byte	W04
	.byte			Gn3
	.byte	W03
	.byte			As3
	.byte	W04
	.byte			Dn4
	.byte	W03
	.byte			Fn4
	.byte	W04
	.byte			Gn4
	.byte	W03
	.byte			As4
	.byte	W03
	.byte			Dn5
	.byte	W03
	.byte			Fn5
	.byte	W03
	.byte			As5
	.byte	W03
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
song_0026_3_2:
	.byte		N12	, As1, v127
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			As3
	.byte	W12
	.byte			Fn4
	.byte	W12
	.byte			As3
	.byte	W12
	.byte			Dn3
	.byte	W12
	.byte			Fn2
	.byte	W12
	.byte	PEND
song_0026_3_3:
	.byte		N12	, As1, v127
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte			Gn4
	.byte	W12
	.byte			Cn4
	.byte	W12
	.byte			En3
	.byte	W12
	.byte			Gn2
	.byte	W12
	.byte	PEND
song_0026_3_1:
	.byte		N12	, Dn2, v127
	.byte	W12
	.byte			An2
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte			An4
	.byte	W12
	.byte			Dn4
	.byte	W12
	.byte			Fn3
	.byte	W12
	.byte			An2
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0026_3_1
	.byte	PATT	
		.word	song_0026_3_2
	.byte	PATT	
		.word	song_0026_3_3
	.byte	PATT	
		.word	song_0026_3_1
	.byte	PATT	
		.word	song_0026_3_1
	.byte	PATT	
		.word	song_0026_3_2
	.byte	PATT	
		.word	song_0026_3_3
	.byte	PATT	
		.word	song_0026_3_1
	.byte	PATT	
		.word	song_0026_3_1
	.byte		N02	, Dn2, v127
	.byte	W02
	.byte			An2
	.byte	W03
	.byte			Dn3
	.byte	W02
	.byte			Fs3
	.byte	W03
	.byte			An3
	.byte	W02
	.byte			Dn4
	.byte	W03
	.byte			Fs4
	.byte	W02
	.byte			An4
	.byte	W03
	.byte		N04	, Dn5
	.byte	W76
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0026_3_4
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0026_4
song_0026_4:	@ 0x087DAE73
	.byte	KEYSH	, 0
	.byte	VOICE	, 6
	.byte	VOL	, v075
	.byte	PAN	, c_v
	.byte	W24
song_0026_4_1:
	.byte	W96
	.byte	W96
	.byte		N72	, Fs3, v127
	.byte	W72
	.byte		N24	, Dn3
	.byte	W24
	.byte		N80	, An3
	.byte	W84
	.byte		N16	, Gn3
	.byte	W12
	.byte	W04
	.byte		N10	, Bn3
	.byte	W09
	.byte		N07	, An3
	.byte	W10
	.byte		N72	
	.byte	W72
	.byte	W01
	.byte		N92	, Fn3
	.byte	W96
	.byte		N96	, An2
	.byte	W96
	.byte		N96	
	.byte	W96
	.byte			Gn2
	.byte	W96
	.byte		N68	, An2
	.byte	W72
	.byte		N24	, Cs3
	.byte	W24
	.byte		N96	, An2
	.byte	W96
	.byte			Dn3
	.byte	W96
	.byte			Cn3
	.byte	W96
	.byte		N72	
	.byte	W72
	.byte		N24	, Cs3
	.byte	W24
	.byte		N48	, Dn2
	.byte	W48
	.byte		N64	, An2
	.byte	W48
	.byte	W24
	.byte		N24	, En2
	.byte	W24
	.byte			Fn2
	.byte	W24
	.byte			Gn2
	.byte	W18
	.byte		N03	, Fn3
	.byte	W03
	.byte			En3
	.byte	W03
	.byte		N48	, Dn3
	.byte	W48
	.byte		N64	, An3
	.byte	W48
	.byte	W24
	.byte		N24	, En4
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte			Gn4
	.byte	W24
	.byte		N48	, An4
	.byte	W48
	.byte	W01
	.byte		N60	, Dn4
	.byte	W44
	.byte	W03
	.byte	W24
	.byte		N24	, En4
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte			En4
	.byte	W24
	.byte		N08	, Fn4
	.byte	W07
	.byte		N07	, En4
	.byte	W07
	.byte		N72	, Fn4
	.byte	W68
	.byte	W02
	.byte		N08	, En4
	.byte	W07
	.byte		N10	, Fn4
	.byte	W05
	.byte	W02
	.byte		N66	, En4
	.byte	W68
	.byte	W02
	.byte		N24	, Cn4
	.byte	W24
	.byte		N48	, Dn4
	.byte	W48
	.byte		N64	, An4
	.byte	W48
	.byte	W24
	.byte		N24	, En4
	.byte	W24
	.byte			Fn4
	.byte	W24
	.byte	W01
	.byte			Gn4
	.byte	W23
	.byte	W01
	.byte		N08	, Fn4
	.byte	W08
	.byte		N06	, En4
	.byte	W06
	.byte		TIE	, Fn4
	.byte	W80
	.byte	W01
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	GOTO	
		.word	song_0026_4_1
	.byte	FINE

	@********************** Track  5 **********************@

	.global song_0026_5
song_0026_5:	@ 0x087DAF21
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v062
	.byte	PAN	, c_v
	.byte	W24
song_0026_5_1:
	.byte		N06	, Fs5, v127
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Fs5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Fs5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte			Fs5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			An4
	.byte	W06
	.byte			Fs4
	.byte	W06
	.byte	PEND
song_0026_5_2:
	.byte		N06	, Fn5, v127
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte			Fn5
	.byte	W06
	.byte			Dn5
	.byte	W06
	.byte			As4
	.byte	W06
	.byte			Fn4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0026_5_1
	.byte	PATT	
		.word	song_0026_5_2
	.byte	PATT	
		.word	song_0026_5_1
	.byte	PATT	
		.word	song_0026_5_2
	.byte	PATT	
		.word	song_0026_5_1
	.byte	PATT	
		.word	song_0026_5_2
song_0026_5_3:
	.byte		N06	, Gn5, v127
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte	PEND
song_0026_5_4:
	.byte		N06	, Gn5, v127
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cn5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte			Gn5
	.byte	W06
	.byte			En5
	.byte	W06
	.byte			Cs5
	.byte	W06
	.byte			Gn4
	.byte	W06
	.byte	PEND
	.byte	PATT	
		.word	song_0026_5_1
	.byte	PATT	
		.word	song_0026_5_2
	.byte	PATT	
		.word	song_0026_5_3
	.byte	PATT	
		.word	song_0026_5_4
	.byte		N96	, Dn3, v127
	.byte	W96
	.byte	W96
	.byte		N48	
	.byte	W48
	.byte		TIE	, An3
	.byte	W48
	.byte	W66
	.byte		EOT	
	.byte	W06
	.byte		N24	
	.byte	W24
	.byte		N06	, As3
	.byte	W06
	.byte			An3
	.byte	W06
	.byte		N72	, As3
	.byte	W72
	.byte		N06	, An3
	.byte	W06
	.byte			As3
	.byte	W06
	.byte		N72	, Cn4
	.byte	W72
	.byte		N24	, As3
	.byte	W24
	.byte		TIE	, An3
	.byte	W96
	.byte	W68
	.byte	W03
	.byte		EOT	
	.byte	W01
	.byte		N24	, En4
	.byte	W24
	.byte		N96	, Dn4
	.byte	W96
	.byte		N24	, Gn4
	.byte	W24
	.byte			En3
	.byte	W24
	.byte			Fn3
	.byte	W24
	.byte			Gn3
	.byte	W24
	.byte		N06	, Fn3
	.byte	W06
	.byte			En3
	.byte	W06
	.byte		TIE	, Fn3
	.byte	W84
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte		N72	, Dn4
	.byte	W72
	.byte		N24	, An3
	.byte	W24
	.byte		N90	, Cs4
	.byte	W96
	.byte		N96	, Bn3
	.byte	W96
	.byte		N90	, As3
	.byte	W96
	.byte	GOTO	
		.word	song_0026_5_1
	.byte	FINE

	.align 2
	.global song_0026
song_0026:	@ 0x087DB040
	.byte	5		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0026_1		@ track
	.word	song_0026_2		@ track
	.word	song_0026_3		@ track
	.word	song_0026_4		@ track
	.word	song_0026_5		@ track
