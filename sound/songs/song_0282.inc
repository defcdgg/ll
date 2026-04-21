	.include "MPlayDef.s"

	.section .rodata

	@********************** Track  1 **********************@

	.align 2
	.global song_0282_1
song_0282_1:	@ 0x087E79F0
	.byte	KEYSH	, 0
	.byte	TEMPO	, 37
	.byte	MOD	, 0
	.byte	BEND	, c_v
	.byte	W01
	.byte	VOICE	, 3
	.byte	VOL	, v094
	.byte	W01
	.byte	PAN	, c_v
	.byte	W04
	.byte		N56	, Fs4, v080
	.byte	W60
	.byte	W01
	.byte		N11	
	.byte	W12
	.byte		N10	, Gn4
	.byte	W11
	.byte		N14	, Fs4
	.byte	W12
	.byte	W01
	.byte		N48	, En4
	.byte	W60
	.byte		N12	
	.byte	W13
	.byte		N13	, Fs4
	.byte	W12
	.byte		N08	, En4
	.byte	W10
	.byte	W03
	.byte		N12	
	.byte	W11
	.byte		N18	, Dn4
	.byte	W18
	.byte		N07	, Cs4
	.byte	W08
	.byte		N10	, Dn4
	.byte	W10
	.byte		N32	, Bn4
	.byte	W22
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte		N09	, Dn4
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W01
	.byte		N36	
	.byte	W01
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W02
	.byte		N32	, Cs4
	.byte	W01
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W02
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W03
	.byte	W01
	.byte	FINE

	.align 2
	.global song_0282
song_0282:	@ 0x087E7A60
	.byte	1		@ trackCount
	.byte	0		@ blockCount
	.byte	255		@ priority
	.byte	188		@ reverb

	.word	voicegroup000		@ voicegroup/tone

	.word	song_0282_1		@ track
