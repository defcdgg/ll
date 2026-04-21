	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0028_1
song_0028_1:	@ 0x087DB16C
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 4
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0028_1_1:
	.byte	TEMPO	, 36
	.byte	W23
	.byte		N14	, Fn3, v127
	.byte	W13
	.byte			Gs3
	.byte	W13
	.byte		N36	, Ds4
	.byte	W32
	.byte	W03
	.byte		N11	, Cs4
	.byte	W12
	.byte		N92	, Cn4
	.byte	W96
	.byte	W24
	.byte		N13	, Fn3
	.byte	W11
	.byte		N14	, Gs3
	.byte	W13
	.byte		N36	, Ds4
	.byte	W36
	.byte		N10	, Cs4
	.byte	W12
	.byte	W01
	.byte		N30	, Fn4
	.byte	W32
	.byte		N08	, Fs4
	.byte	W07
	.byte		N05	, Fn4
	.byte	W09
	.byte		N23	
	.byte	W23
	.byte		N21	, Ds4
	.byte	W24
	.byte	W01
	.byte		N32	
	.byte	W32
	.byte		N09	, Fn4
	.byte	W08
	.byte		N10	, Ds4
	.byte	W08
	.byte		N13	, Cs4
	.byte	W12
	.byte		N11	, Ds4
	.byte	W11
	.byte		N13	, Fn4
	.byte	W01
	.byte		N01	, En4
	.byte	W11
	.byte		N13	, Gs4
	.byte	W12
	.byte		N30	, As4
	.byte	W32
	.byte	W03
	.byte		N11	, Ds4
	.byte	W14
	.byte		N12	
	.byte	W12
	.byte		N21	, Fn4
	.byte	W19
	.byte		N08	, Gn4
	.byte	W07
	.byte		N09	, As4
	.byte	W08
	.byte		N96	, Cn5
	.byte	W01
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W96
	.byte	W12
	.byte		N19	, As3
	.byte	W20
	.byte		N09	, Cn4
	.byte	W08
	.byte		N05	, Cs4
	.byte	W08
	.byte		N11	
	.byte	W12
	.byte		N14	, Cn4
	.byte	W12
	.byte		N13	, As3
	.byte	W12
	.byte		N11	, An3
	.byte	W12
	.byte		N28	, As3
	.byte	W24
	.byte		N10	, Cs4
	.byte	W12
	.byte		N60	, Cn4
	.byte	W60
	.byte		N11	, Cs4
	.byte	W12
	.byte		N19	, Cn4
	.byte	W20
	.byte		N07	, Cs4
	.byte	W08
	.byte			Fn4
	.byte	W08
	.byte		N30	, Ds4
	.byte	W36
	.byte		N11	
	.byte	W12
	.byte		N30	, Cs4
	.byte	W32
	.byte		N07	, Cn4
	.byte	W08
	.byte			Cs4
	.byte	W08
	.byte		N32	, Fn4
	.byte	W36
	.byte		N11	
	.byte	W12
	.byte		TIE	, Ds4
	.byte	W96
	.byte	W44
	.byte	W02
	.byte		EOT	
	.byte	W48
	.byte	W02
	.byte	GOTO	
		.word	song_0028_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0028_2
song_0028_2:	@ 0x087DB220
	.byte	KEYSH	, 0
	.byte	VOICE	, 0
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0028_2_1:
	.byte	VOICE	, 0
	.byte		N96	, Gs2, v127
	.byte	W96
	.byte		N56	, An2
	.byte	W56
	.byte		N08	, Fn2
	.byte	W08
	.byte			Gn2
	.byte	W08
	.byte			An2
	.byte	W08
	.byte			As2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte		N72	, Cs3
	.byte	W84
	.byte		N10	, As2
	.byte	W12
	.byte		N48	, Fs2
	.byte		N24	, As2
	.byte	W24
	.byte			Cs3
	.byte	W24
	.byte		N44	, Gs2
	.byte		N44	, Cn3
	.byte	W48
	.byte		N48	, Gs2
	.byte		N24	, Cn3
	.byte	W24
	.byte			Ds3
	.byte	W24
	.byte		N48	, As2
	.byte		N36	, Cs3
	.byte	W36
	.byte		N12	, Cn3
	.byte	W12
	.byte		N48	, As2
	.byte		N96	, Cs3
	.byte	W48
	.byte		N48	, Gn2
	.byte	W48
	.byte			Gs2
	.byte		N48	, Cn3
	.byte	W48
	.byte			An2
	.byte		N48	, Ds3
	.byte	W48
	.byte	VOICE	, 3
	.byte		N16	, As3
	.byte	W24
	.byte		N12	, Fn3
	.byte	W12
	.byte		N60	, Gs3
	.byte	W60
	.byte		N12	, Fs3
	.byte	W12
	.byte		N20	, Fn3
	.byte	W20
	.byte		N08	, Fs3
	.byte	W08
	.byte			As3
	.byte	W08
	.byte		N30	, Gs3
	.byte	W48
	.byte		N16	, As3
	.byte	W24
	.byte		N12	, Fn3
	.byte	W12
	.byte		N20	, Gs3
	.byte	W24
	.byte		N21	
	.byte	W21
	.byte		N08	, Fs3
	.byte	W08
	.byte		N09	, Fn3
	.byte	W07
	.byte	W02
	.byte		N72	, Ds3
	.byte	W92
	.byte	W02
	.byte		N16	, As3
	.byte	W24
	.byte		N12	, Fn3
	.byte	W12
	.byte		N60	, Gs3
	.byte	W60
	.byte		N12	, Fs3
	.byte	W12
	.byte		N20	, Fn3
	.byte	W20
	.byte		N08	, Fs3
	.byte	W08
	.byte			As3
	.byte	W08
	.byte		N30	, Gs3
	.byte	W36
	.byte		N12	
	.byte	W12
	.byte		N36	, As3
	.byte	W36
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N12	
	.byte	W12
	.byte		N24	
	.byte	W24
	.byte		TIE	, Cn4
	.byte	W96
	.byte	W48
	.byte		EOT	
	.byte	W48
	.byte	GOTO	
		.word	song_0028_2_1
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0028_3
song_0028_3:	@ 0x087DB2CD
	.byte	KEYSH	, 0
	.byte	VOICE	, 19
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0028_3_3:
	.byte		N12	, Cs2, v127
	.byte	W12
	.byte		N03	, Gs2
	.byte	W03
	.byte			Cs3
	.byte	W03
	.byte			Gs3
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte		N12	, Fn4
	.byte	W72
	.byte			An1
	.byte	W12
	.byte		N03	, Fn2
	.byte	W03
	.byte			Cn3
	.byte	W03
	.byte			An3
	.byte	W03
	.byte			Cn4
	.byte	W03
	.byte		N12	, Fn4
	.byte	W72
	.byte			As1
	.byte	W12
	.byte		N03	, Fn2
	.byte	W03
	.byte			Cs3
	.byte	W03
	.byte			As3
	.byte	W03
	.byte			Cs4
	.byte	W03
	.byte		N12	, Fn4
	.byte	W72
	.byte			Fs1
	.byte	W06
	.byte		N03	, Fs2
	.byte	W06
	.byte			Cs3
	.byte	W04
	.byte			As3
	.byte	W04
	.byte			Cs4
	.byte	W04
	.byte		N12	, Fn4
	.byte	W24
	.byte			Fs1
	.byte	W06
	.byte		N03	, Fs2
	.byte	W06
	.byte			Ds3
	.byte	W04
	.byte			Gs3
	.byte	W04
	.byte			Cn4
	.byte	W04
	.byte		N12	, Ds4
	.byte	W24
	.byte			Fn1
	.byte	W06
	.byte		N03	, Fn2
	.byte	W06
	.byte			Cn3
	.byte	W04
	.byte			Gs3
	.byte	W04
	.byte			Cn4
	.byte	W04
	.byte		N12	, Ds4
	.byte	W24
	.byte			As1
	.byte	W06
	.byte		N03	, Fn2
	.byte	W06
	.byte			Cs3
	.byte	W04
	.byte			Fn3
	.byte	W04
	.byte			As3
	.byte	W04
	.byte		N12	, Fn4
	.byte	W24
	.byte			Gn1
	.byte	W06
	.byte		N03	, Gn2
	.byte	W06
	.byte			As2
	.byte	W04
	.byte			Gn3
	.byte	W04
	.byte			As3
	.byte	W04
	.byte		N12	, Ds4
	.byte	W24
	.byte			Ds1
	.byte	W06
	.byte		N03	, Gn2
	.byte	W06
	.byte			As2
	.byte	W04
	.byte			Ds3
	.byte	W04
	.byte			As3
	.byte	W04
	.byte		N12	, Ds4
	.byte	W24
	.byte			Gs1
	.byte	W06
	.byte		N03	, Gs2
	.byte	W06
	.byte			Cn3
	.byte	W04
	.byte			Ds3
	.byte	W04
	.byte			Gs3
	.byte	W04
	.byte		N12	, Ds4
	.byte	W24
	.byte			Fn1
	.byte	W06
	.byte		N03	, Fn2
	.byte	W06
	.byte			An2
	.byte	W04
	.byte			Ds3
	.byte	W04
	.byte			Cn4
	.byte	W04
	.byte		N12	, Ds4
	.byte	W24
song_0028_3_2:
	.byte		N08	, As1, v127
	.byte	W08
	.byte			Fn2
	.byte	W08
	.byte			As2
	.byte	W08
	.byte			Fn3
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte			As3
	.byte	W08
	.byte			Gs1
	.byte	W08
	.byte			Ds2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			Ds3
	.byte	W08
	.byte			Gs2
	.byte	W08
	.byte			Gs3
	.byte	W08
	.byte	PEND
song_0028_3_1:
	.byte		N08	, Fs1, v127
	.byte	W08
	.byte			Fs2
	.byte	W08
	.byte			As2
	.byte	W08
	.byte			Fn3
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte			As3
	.byte	W08
	.byte			Gs1
	.byte	W08
	.byte			Ds2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			An1
	.byte	W08
	.byte			Ds3
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte	PEND
	.byte			As1
	.byte	W08
	.byte			Fn2
	.byte	W08
	.byte			Gs2
	.byte	W08
	.byte			Fn3
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte			As3
	.byte	W08
	.byte			Gs1
	.byte	W08
	.byte			Ds2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			Ds3
	.byte	W08
	.byte			Gs2
	.byte	W08
	.byte			Gs3
	.byte	W08
	.byte	PATT	
		.word	song_0028_3_1
	.byte	PATT	
		.word	song_0028_3_2
	.byte		N08	, Fs1, v127
	.byte	W08
	.byte			Fs2
	.byte	W08
	.byte			As2
	.byte	W08
	.byte			Fn3
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte			As3
	.byte	W08
	.byte			Gs1
	.byte	W08
	.byte			Ds2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			Gs2
	.byte	W08
	.byte			Ds3
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			Fs1
	.byte	W08
	.byte			Fn2
	.byte	W08
	.byte			Fs2
	.byte	W08
	.byte			As2
	.byte	W08
	.byte			Fs2
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte			Cs4
	.byte	W08
	.byte			As3
	.byte	W08
	.byte			Fn3
	.byte	W08
	.byte			As3
	.byte	W08
	.byte			Fn3
	.byte	W08
	.byte			Cs3
	.byte	W08
	.byte			Gs1
	.byte	W08
	.byte			Ds2
	.byte	W08
	.byte			Gs2
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte			Gs2
	.byte	W08
	.byte			Ds3
	.byte	W08
	.byte			Cn4
	.byte	W08
	.byte			Gs3
	.byte	W08
	.byte			Ds3
	.byte	W08
	.byte			Gs3
	.byte	W08
	.byte			Ds3
	.byte	W08
	.byte			Cn3
	.byte	W08
	.byte		N04	, Gs1
	.byte	W04
	.byte			Ds2
	.byte	W04
	.byte			Gs2
	.byte	W04
	.byte			Cn3
	.byte	W04
	.byte			Ds3
	.byte	W04
	.byte			Gs3
	.byte	W04
	.byte			Gs2
	.byte	W04
	.byte			As2
	.byte	W04
	.byte			Cs3
	.byte	W04
	.byte			Fn3
	.byte	W04
	.byte			As3
	.byte	W04
	.byte			Cs4
	.byte	W04
	.byte			Gs2
	.byte	W04
	.byte			Cn3
	.byte	W04
	.byte			Ds3
	.byte	W04
	.byte			Gs3
	.byte	W04
	.byte			Cn4
	.byte	W04
	.byte			Ds4
	.byte	W04
	.byte			Gs4
	.byte	W04
	.byte			Fs4
	.byte	W04
	.byte			Ds4
	.byte	W04
	.byte			Cn4
	.byte	W04
	.byte			Gs3
	.byte	W04
	.byte			Gs2
	.byte	W04
	.byte	GOTO	
		.word	song_0028_3_3
	.byte	FINE

	@********************** Track  4 **********************@

	.global song_0028_4
song_0028_4:	@ 0x087DB44B
	.byte	KEYSH	, 0
	.byte	VOICE	, 22
	.byte	VOL	, v094
	.byte	PAN	, c_v
	.byte	W24
song_0028_4_2:
	.byte		N24	, Cs1, v127
	.byte	W24
	.byte			Cs2
	.byte	W24
	.byte			Cn2
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			An1
	.byte	W24
	.byte			Fs1
	.byte	W24
	.byte			Fn1
	.byte	W24
	.byte			Fn0
	.byte	W24
song_0028_4_1:
	.byte		N24	, As0, v127
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte			Fn1
	.byte	W24
	.byte	PEND
	.byte			Fs1
	.byte	W24
	.byte			Cs1
	.byte	W24
	.byte			Fs1
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte			Fn1
	.byte	W24
	.byte		N24	
	.byte	W24
	.byte			As1
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte			Gn1
	.byte	W24
	.byte			Ds1
	.byte	W24
	.byte			As0
	.byte	W24
	.byte			Ds1
	.byte	W24
	.byte			Gs0
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte			An1
	.byte	W24
	.byte			Fn1
	.byte	W24
	.byte	PATT	
		.word	song_0028_4_1
	.byte		N24	, Fs1, v127
	.byte	W24
	.byte			Fn1
	.byte	W24
	.byte			Ds1
	.byte	W24
	.byte			An0
	.byte	W24
	.byte	PATT	
		.word	song_0028_4_1
	.byte		N24	, Fs1, v127
	.byte	W24
	.byte			Ds1
	.byte	W24
	.byte			Gs0
	.byte	W24
	.byte			An0
	.byte	W24
	.byte	PATT	
		.word	song_0028_4_1
	.byte		N24	, Fs1, v127
	.byte	W24
	.byte			Fn1
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte			Fn1
	.byte	W24
	.byte			Fs1
	.byte	W24
	.byte			Fs0
	.byte	W24
	.byte			As0
	.byte	W24
	.byte			Fs1
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte			Gs0
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Ds1
	.byte	W24
	.byte			Gs1
	.byte	W24
	.byte			Ds1
	.byte	W24
	.byte			Cn1
	.byte	W24
	.byte			Gs0
	.byte	W24
	.byte	GOTO	
		.word	song_0028_4_2
	.byte	FINE

	.align 2
	.global song_0028
song_0028:	@ 0x087DB4DC
	.byte	4		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0028_1		@ track
	.word	song_0028_2		@ track
	.word	song_0028_3		@ track
	.word	song_0028_4		@ track
