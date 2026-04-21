	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0040_1
song_0040_1:	@ 0x087DF058
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 8
	.byte	VOL	, v110
	.byte	PAN	, c_v
	.byte	W24
song_0040_1_1:
	.byte	TEMPO	, 50
	.byte	W01
	.byte		TIE	, An4, v127
	.byte	W06
	.byte			As4
	.byte	W08
	.byte			En5
	.byte	W80
	.byte	W01
	.byte	W84
	.byte	W03
	.byte		EOT	, An4
	.byte	W01
	.byte			En5
	.byte	W02
	.byte			As4
	.byte	W06
	.byte		TIE	, Gn4
	.byte	W07
	.byte			Gs4
	.byte	W08
	.byte			Dn5
	.byte	W80
	.byte	W01
	.byte	W90
	.byte		EOT	, Gn4
	.byte	W01
	.byte			Gs4
	.byte			Dn5
	.byte	W05
	.byte	W02
	.byte		TIE	, An4
	.byte	W06
	.byte			As4
	.byte	W09
	.byte			En5
	.byte	W78
	.byte	W01
	.byte	W90
	.byte		EOT	, An4
	.byte	W01
	.byte			En5
	.byte	W01
	.byte			As4
	.byte	W04
	.byte	W01
	.byte		TIE	, Gn4
	.byte	W07
	.byte			Gs4
	.byte	W06
	.byte			Dn5
	.byte	W80
	.byte	W02
	.byte	W96
	.byte		EOT	, Gs4
	.byte	W01
	.byte			Dn5
	.byte	W01
	.byte			Gn4
	.byte	W44
	.byte	W02
	.byte		TIE	, Ds4
	.byte		TIE	, An4
	.byte		TIE	, Dn5
	.byte	W48
	.byte	W48
	.byte		N18	, Cs5
	.byte	W01
	.byte		EOT	, Ds4
	.byte			An4
	.byte			Dn5
	.byte		N18	, Dn4
	.byte		N19	, Gs4
	.byte	W18
	.byte		N21	, Cs4
	.byte		N20	, Gn4
	.byte		N13	, Cn5
	.byte	W18
	.byte		TIE	, Cn4
	.byte		TIE	, Fs4
	.byte	W01
	.byte			Bn4
	.byte	W10
	.byte	W96
	.byte	W32
	.byte	W02
	.byte			Cs4
	.byte	W01
	.byte			Gn4
	.byte		TIE	, Cn5
	.byte	W01
	.byte		EOT	, Cn4
	.byte			Fs4
	.byte	W02
	.byte			Bn4
	.byte	W56
	.byte	W02
	.byte	W96
	.byte	W96
	.byte	W80
	.byte	W02
	.byte			Cs4
	.byte			Cn5
	.byte	W01
	.byte			Gn4
	.byte	W13
	.byte	GOTO	
		.word	song_0040_1_1
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0040_2
song_0040_2:	@ 0x087DF0EB
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v110
	.byte	PAN	, c_v
	.byte	W24
song_0040_2_1:
	.byte		N01	, Fs7, v127
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte		N01	
	.byte	W12
	.byte	PEND
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	PATT	
		.word	song_0040_2_1
	.byte	GOTO	
		.word	song_0040_2_1
	.byte	FINE

	.align 2
	.global song_0040
song_0040:	@ 0x087DF154
	.byte	2		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0040_1		@ track
	.word	song_0040_2		@ track
