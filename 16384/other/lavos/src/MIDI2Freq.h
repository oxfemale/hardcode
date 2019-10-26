//	MIDI2Freq.h - An array with the frequencies for all MIDI notes.
//	--------------------------------------------------------------------------
//	Copyright (c) 2005 Niall Moody
//	
//	Permission is hereby granted, free of charge, to any person obtaining a
//	copy of this software and associated documentation files (the "Software"),
//	to deal in the Software without restriction, including without limitation
//	the rights to use, copy, modify, merge, publish, distribute, sublicense,
//	and/or sell copies of the Software, and to permit persons to whom the
//	Software is furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
//	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
//	THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
//	FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
//	DEALINGS IN THE SOFTWARE.
//	--------------------------------------------------------------------------

#ifndef MIDI2FREQ_H_
#define MIDI2FREQ_H_

///	This is a useful array I have where the indexed value corresponds to the
///	frequency for that MIDI note.
const float MIDI2Freq[128] = {
	8.1757989156f, //0
	8.6619572180f,
	9.1770239974f,
	9.7227182413f,
	10.3008611535f,
	10.9133822323f,
	11.5623257097f,
	12.2498573744f,
	12.9782717994f,
	13.7500000000f,
	14.5676175474f,
	15.4338531643f,
	16.3515978313f, //12
	17.3239144361f,
	18.3540479948f,
	19.4454364826f,
	20.6017223071f,
	21.8267644646f,
	23.1246514195f,
	24.4997147489f,
	25.9565435987f,
	27.5000000000f,
	29.1352350949f,
	30.8677063285f,
	32.7031956626f, //24
	34.6478288721f,
	36.7080959897f,
	38.8908729653f,
	41.2034446141f,
	43.6535289291f,
	46.2493028390f,
	48.9994294977f,
	51.9130871975f,
	55.0000000000f,
	58.2704701898f,
	61.7354126570f,
	65.4063913251f, //36
	69.2956577442f,
	73.4161919794f,
	77.7817459305f,
	82.4068892282f,
	87.3070578583f,
	92.4986056779f,
	97.9988589954f,
	103.8261743950f,
	110.0000000000f,
	116.5409403795f,
	123.4708253140f,
	130.8127826503f, //48
	138.5913154884f,
	146.8323839587f,
	155.5634918610f,
	164.8137784564f,
	174.6141157165f,
	184.9972113558f,
	195.9977179909f,
	207.6523487900f,
	220.0000000000f,
	233.0818807590f,
	246.9416506281f,
	261.6255653006f, //60
	277.1826309769f,
	293.6647679174f,
	311.1269837221f,
	329.6275569129f,
	349.2282314330f,
	369.9944227116f,
	391.9954359817f,
	415.3046975799f,
	440.0000000000f,
	466.1637615181f,
	493.8833012561f,
	523.2511306012f, //72
	554.3652619537f,
	587.3295358348f,
	622.2539674442f,
	659.2551138257f,
	698.4564628660f,
	739.9888454233f,
	783.9908719635f,
	830.6093951599f,
	880.0000000000f,
	932.3275230362f,
	987.7666025122f,
	1046.5022612024f, //84
	1108.7305239075f,
	1174.6590716696f,
	1244.5079348883f,
	1318.5102276515f,
	1396.9129257320f,
	1479.9776908465f,
	1567.9817439270f,
	1661.2187903198f,
	1760.0000000000f,
	1864.6550460724f,
	1975.5332050245f,
	2093.0045224048f, //96
	2217.4610478150f,
	2349.3181433393f,
	2489.0158697766f,
	2637.0204553030f,
	2793.8258514640f,
	2959.9553816931f,
	3135.9634878540f,
	3322.4375806396f,
	3520.0000000000f,
	3729.3100921447f,
	3951.0664100490f,
	4186.009044809f, //108
	4434.922095630f,
	4698.636286678f,
	4978.031739553f,
	5274.040910605f,
	5587.651702928f,
	5919.910763386f,
	6271.926975708f,
	6644.875161279f,
	7040.000000000f,
	7458.620234756f,
	7902.132834658f,
	8372.0180896192f, //120
	8869.8441912599f,
	9397.2725733570f,
	9956.0634791066f,
	10548.0818212118f,
	11175.3034058561f,
	11839.8215267723f,
	12543.8539514160f };

#endif
