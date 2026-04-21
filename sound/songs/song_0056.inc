	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0056_1
song_0056_1:	@ 0x087E35A8
	.byte	KEYSH	, 0
	.byte	TEMPO	, 125
	.byte	VOICE	, 5
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
	.byte	TEMPO	, 66
	.byte		N16	, Bn3, v127
	.byte		N16	, Dn4
	.byte	W24
	.byte		N04	, Bn3
	.byte		N04	, Dn4
	.byte	W08
	.byte			Dn3
	.byte		N04	, Gn3
	.byte	W08
	.byte			Bn3
	.byte		N04	, Dn4
	.byte		N04	, Gn4
	.byte	W08
	.byte		N16	, As3
	.byte		N16	, Dn4
	.byte	W24
	.byte		TIE	, Bn3
	.byte		TIE	, Gn4
	.byte	W96
	.byte	W24
	.byte		EOT	, Bn3
	.byte			Gn4
	.byte	FINE

	@********************** Track  2 **********************@

	.global song_0056_2
song_0056_2:	@ 0x087E35D9
	.byte	KEYSH	, 0
	.byte	VOICE	, 4
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
	.byte		N24	, Bn2, v127
	.byte		N24	, Dn3
	.byte	W48
	.byte		N04	
	.byte		N04	, Fn3
	.byte	W08
	.byte			Fn2
	.byte		N04	, As2
	.byte	W08
	.byte			Dn3
	.byte		N04	, Fn3
	.byte		N04	, As3
	.byte	W08
	.byte		TIE	, Dn3
	.byte		TIE	, Gn3
	.byte	W96
	.byte	W24
	.byte		EOT	, Dn3
	.byte			Gn3
	.byte	FINE

	@********************** Track  3 **********************@

	.global song_0056_3
song_0056_3:	@ 0x087E3600
	.byte	KEYSH	, 0
	.byte	VOICE	, 126
	.byte	VOL	, v085
	.byte	PAN	, c_v
	.byte	W24
	.byte		N22	, Cs2, v127
	.byte		N24	, Gn3
	.byte	W48
	.byte			Dn4
	.byte	W24
	.byte			An2
	.byte		N24	, Gn3
	.byte	W24
	.byte	W02
	.byte	FINE

	.align 2
	.global song_0056
song_0056:	@ 0x087E3618
	.byte	3		@ trackCount
	.byte	0		@ blockCount
	.byte	10		@ priority
	.byte	168		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0056_1		@ track
	.word	song_0056_2		@ track
	.word	song_0056_3		@ track
