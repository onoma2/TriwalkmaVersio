#include "TriwalkmaVersio_2dworking_2dmid_2dalways.h"

namespace TriwalkmaVersio_2dworking_2dmid_2dalways {

/*******************************************************************************************************************
Cycling '74 License for Max-Generated Code for Export
Copyright (c) 2016 Cycling '74
The code that Max generates automatically and that end users are capable of exporting and using, and any
  associated documentation files (the “Software”) is a work of authorship for which Cycling '74 is the author
  and owner for copyright purposes.  A license is hereby granted, free of charge, to any person obtaining a
  copy of the Software (“Licensee”) to use, copy, modify, merge, publish, and distribute copies of the Software,
  and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The Software is licensed to Licensee only for non-commercial use. Users who wish to make commercial use of the
  Software must contact the copyright owner to determine if a license for commercial use is available, and the
  terms and conditions for same, which may include fees or royalties. For commercial use, please send inquiries
  to licensing (at) cycling74.com.  The determination of whether a use is commercial use or non-commercial use is based
  upon the use, not the user. The Software may be used by individuals, institutions, governments, corporations, or
  other business whether for-profit or non-profit so long as the use itself is not a commercialization of the
  materials or a use that generates or is intended to generate income, revenue, sales or profit.
The above copyright notice and this license shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO
  THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO EVENT SHALL
  THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
  CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
  DEALINGS IN THE SOFTWARE.
*******************************************************************************************************************/

// global noise generator
Noise noise;
static const int GENLIB_LOOPCOUNT_BAIL = 100000;


// The State struct contains all the state and procedures for the gendsp kernel
typedef struct State {
	CommonState __commonstate;
	Data m_loopL_23;
	Data m_loopM_36;
	Data m_loopR_26;
	Delta __m_delta_37;
	Phasor __m_phasor_145;
	Phasor __m_phasor_73;
	Phasor __m_phasor_54;
	Phasor __m_phasor_108;
	PlusEquals __m_pluseq_38;
	int __exception;
	int vectorsize;
	t_sample __m_carry_41;
	t_sample m_history_8;
	t_sample __m_count_39;
	t_sample __m_slide_43;
	t_sample __m_count_46;
	t_sample __m_carry_48;
	t_sample m_history_2;
	t_sample m_history_4;
	t_sample m_history_3;
	t_sample m_button_34;
	t_sample m_ctrl_35;
	t_sample m_ctrl_33;
	t_sample __m_count_50;
	t_sample samples_to_seconds;
	t_sample __m_slide_70;
	t_sample samplerate;
	t_sample __m_slide_105;
	t_sample __m_carry_52;
	t_sample __m_slide_64;
	t_sample __m_slide_58;
	t_sample __m_slide_61;
	t_sample m_history_1;
	t_sample __m_slide_55;
	t_sample m_history_7;
	t_sample m_ctrl_32;
	t_sample m_ctrl_30;
	t_sample m_history_15;
	t_sample m_history_14;
	t_sample m_history_16;
	t_sample m_history_17;
	t_sample m_history_18;
	t_sample m_history_13;
	t_sample m_history_11;
	t_sample m_history_12;
	t_sample m_history_9;
	t_sample m_history_10;
	t_sample m_sw_31;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample __m_slide_142;
	t_sample m_gate_28;
	t_sample m_ctrl_29;
	t_sample m_history_20;
	t_sample m_history_5;
	t_sample m_sw_24;
	t_sample m_ctrl_25;
	t_sample m_history_22;
	t_sample m_history_6;
	t_sample m_ctrl_27;
	// re-initialize all member variables;
	inline void reset(t_param __sr, int __vs) {
		__exception = 0;
		vectorsize = __vs;
		samplerate = __sr;
		m_history_1 = ((int)0);
		m_history_2 = ((int)0);
		m_history_3 = ((int)0);
		m_history_4 = ((int)0);
		m_history_5 = ((int)0);
		m_history_6 = ((int)0);
		m_history_7 = ((int)0);
		m_history_8 = ((int)0);
		m_history_9 = ((int)0);
		m_history_10 = ((int)0);
		m_history_11 = ((int)0);
		m_history_12 = ((int)0);
		m_history_13 = ((int)0);
		m_history_14 = ((int)0);
		m_history_15 = ((int)0);
		m_history_16 = ((int)0);
		m_history_17 = ((int)0);
		m_history_18 = ((int)0);
		m_history_19 = ((int)0);
		m_history_20 = ((int)0);
		m_history_21 = ((int)0);
		m_history_22 = ((int)0);
		m_loopL_23.reset("loopL", ((int)192000), ((int)2));
		m_sw_24 = ((int)0);
		m_ctrl_25 = ((int)0);
		m_loopR_26.reset("loopR", ((int)192000), ((int)2));
		m_ctrl_27 = ((int)0);
		m_gate_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_sw_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_ctrl_33 = ((int)0);
		m_button_34 = ((int)0);
		m_ctrl_35 = ((int)0);
		m_loopM_36.reset("loopM", ((int)192000), ((int)2));
		__m_delta_37.reset(0);
		__m_pluseq_38.reset(0);
		__m_count_39 = 0;
		__m_carry_41 = 0;
		__m_slide_43 = 0;
		__m_count_46 = 0;
		__m_carry_48 = 0;
		__m_count_50 = 0;
		__m_carry_52 = 0;
		samples_to_seconds = (1 / samplerate);
		__m_phasor_54.reset(0);
		__m_slide_55 = 0;
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_slide_64 = 0;
		__m_slide_70 = 0;
		__m_phasor_73.reset(0);
		__m_slide_105 = 0;
		__m_phasor_108.reset(0);
		__m_slide_142 = 0;
		__m_phasor_145.reset(0);
		genlib_reset_complete(this);
		
	};
	// the signal processing routine;
	inline int perform(t_sample ** __ins, t_sample ** __outs, int __n) {
		vectorsize = __n;
		const t_sample * __in1 = __ins[0];
		const t_sample * __in2 = __ins[1];
		t_sample * __out1 = __outs[0];
		t_sample * __out2 = __outs[1];
		t_sample * __out3 = __outs[2];
		t_sample * __out4 = __outs[3];
		t_sample * __out5 = __outs[4];
		t_sample * __out6 = __outs[5];
		t_sample * __out7 = __outs[6];
		t_sample * __out8 = __outs[7];
		t_sample * __out9 = __outs[8];
		t_sample * __out10 = __outs[9];
		if (__exception) {
			return __exception;
			
		} else if (( (__in1 == 0) || (__in2 == 0) || (__out1 == 0) || (__out2 == 0) || (__out3 == 0) || (__out4 == 0) || (__out5 == 0) || (__out6 == 0) || (__out7 == 0) || (__out8 == 0) || (__out9 == 0) || (__out10 == 0) )) {
			__exception = GENLIB_ERR_NULL_BUFFER;
			return __exception;
			
		};
		int loopM_dim = m_loopM_36.dim;
		int loopM_channels = m_loopM_36.channels;
		int loopM_dim_290 = loopM_dim;
		int loopR_dim = m_loopR_26.dim;
		int loopR_channels = m_loopR_26.channels;
		int loopR_dim_288 = loopR_dim;
		int loopL_dim = m_loopL_23.dim;
		int loopL_channels = m_loopL_23.channels;
		int loopL_dim_298 = loopL_dim;
		int or_367 = (m_gate_28 || m_button_34);
		int gt_161 = (or_367 > ((int)0));
		t_sample iup_44 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)4000))));
		samples_to_seconds = (1 / samplerate);
		int eq_330 = (m_sw_31 == ((int)0));
		t_sample iup_56 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_57 = (1 / maximum(1, abs(((int)3000))));
		t_sample iup_59 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_65 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_66 = (1 / maximum(1, abs(((int)4000))));
		int eq_334 = (m_sw_31 == ((t_sample)0.5));
		t_sample switch_333 = (eq_334 ? ((int)0) : m_sw_31);
		t_sample switch_331 = (eq_330 ? ((t_sample)0.5) : switch_333);
		t_sample sub_1533 = (switch_331 - ((int)0));
		t_sample scale_1530 = ((safepow((sub_1533 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_67 = int(scale_1530);
		t_sample choice_68 = int(scale_1530);
		t_sample choice_69 = int(scale_1530);
		int neq_136 = (scale_1530 != ((int)2));
		int eq_324 = (m_sw_24 == ((int)0));
		int eq_328 = (m_sw_24 == ((t_sample)0.5));
		t_sample switch_327 = (eq_328 ? ((int)0) : m_sw_24);
		t_sample switch_325 = (eq_324 ? ((t_sample)0.5) : switch_327);
		t_sample sub_1548 = (switch_325 - ((int)0));
		t_sample scale_1545 = ((safepow((sub_1548 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_99 = ((1 < 0) || (1 >= loopR_channels));
		t_sample iup_106 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_107 = (1 / maximum(1, abs(((int)4000))));
		t_sample choice_124 = int(scale_1545);
		bool chan_ignore_135 = ((1 < 0) || (1 >= loopL_channels));
		t_sample choice_141 = int(scale_1545);
		t_sample iup_143 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_144 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_156 = ((1 < 0) || (1 >= loopM_channels));
		int min_162 = (-1);
		int min_163 = (-1);
		bool chan_ignore_164 = ((((int)1) < 0) || (((int)1) >= loopM_channels));
		int min_167 = (-1);
		t_sample choice_168 = int(scale_1545);
		int min_169 = (-1);
		int min_170 = (-1);
		bool chan_ignore_171 = ((((int)1) < 0) || (((int)1) >= loopR_channels));
		t_sample choice_174 = int(scale_1545);
		int min_175 = (-1);
		int min_176 = (-1);
		bool chan_ignore_177 = ((((int)1) < 0) || (((int)1) >= loopL_channels));
		int min_195 = (-1);
		int min_196 = (-1);
		int min_197 = (-1);
		t_sample choice_200 = int(scale_1545);
		int min_201 = (-1);
		int min_202 = (-1);
		t_sample choice_205 = int(scale_1545);
		int min_206 = (-1);
		int min_207 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out10 = ((int)0);
			t_sample out7 = ((int)0);
			t_sample out8 = ((int)0);
			t_sample out9 = ((int)0);
			int delta_363 = __m_delta_37(or_367);
			int gtep_362 = ((delta_363 >= ((int)1)) ? delta_363 : 0);
			t_sample plusequals_361 = __m_pluseq_38.post(gtep_362, m_history_22, 0);
			t_sample gen_366 = plusequals_361;
			int eq_359 = (plusequals_361 == ((int)2));
			t_sample history_360_next_364 = fixdenorm(eq_359);
			int gt_158 = (gen_366 > ((int)0));
			__m_count_39 = (((int)0) ? 0 : (fixdenorm(__m_count_39 + ((int)1))));
			int carry_40 = 0;
			if ((((int)0) != 0)) {
				__m_count_39 = 0;
				__m_carry_41 = 0;
				
			} else if (((loopR_dim_288 > 0) && (__m_count_39 >= loopR_dim_288))) {
				int wraps_42 = (__m_count_39 / loopR_dim_288);
				__m_carry_41 = (__m_carry_41 + wraps_42);
				__m_count_39 = (__m_count_39 - (wraps_42 * loopR_dim_288));
				carry_40 = 1;
				
			};
			int counter_281 = __m_count_39;
			int counter_282 = carry_40;
			int counter_283 = __m_carry_41;
			t_sample mix_1476 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_ctrl_29 - m_history_21)));
			t_sample mix_339 = mix_1476;
			t_sample mix_1477 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_339 - m_history_20)));
			t_sample mix_337 = mix_1477;
			t_sample mix_1478 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_337 - m_history_19)));
			t_sample mix_335 = mix_1478;
			t_sample gen_345 = mix_335;
			t_sample history_340_next_342 = fixdenorm(mix_339);
			t_sample history_338_next_343 = fixdenorm(mix_337);
			t_sample history_336_next_344 = fixdenorm(mix_335);
			t_sample sub_1482 = (gen_345 - ((int)0));
			t_sample scale_1479 = ((safepow((sub_1482 * ((t_sample)1)), ((int)1)) * ((t_sample)0.9)) + ((int)0));
			__m_slide_43 = fixdenorm((__m_slide_43 + (((scale_1479 > __m_slide_43) ? iup_44 : idown_45) * (scale_1479 - __m_slide_43))));
			t_sample slide_231 = __m_slide_43;
			__m_count_46 = (((int)0) ? 0 : (fixdenorm(__m_count_46 + ((int)1))));
			int carry_47 = 0;
			if ((((int)0) != 0)) {
				__m_count_46 = 0;
				__m_carry_48 = 0;
				
			} else if (((loopL_dim_298 > 0) && (__m_count_46 >= loopL_dim_298))) {
				int wraps_49 = (__m_count_46 / loopL_dim_298);
				__m_carry_48 = (__m_carry_48 + wraps_49);
				__m_count_46 = (__m_count_46 - (wraps_49 * loopL_dim_298));
				carry_47 = 1;
				
			};
			int counter_293 = __m_count_46;
			int counter_294 = carry_47;
			int counter_295 = __m_carry_48;
			__m_count_50 = (((int)0) ? 0 : (fixdenorm(__m_count_50 + ((int)1))));
			int carry_51 = 0;
			if ((((int)0) != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((loopM_dim_290 > 0) && (__m_count_50 >= loopM_dim_290))) {
				int wraps_53 = (__m_count_50 / loopM_dim_290);
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * loopM_dim_290));
				carry_51 = 1;
				
			};
			int counter_285 = __m_count_50;
			int counter_286 = carry_51;
			int counter_287 = __m_carry_52;
			t_sample abs_154 = fabs(in1);
			t_sample add_153 = (abs_154 + ((t_sample)0.0001));
			t_sample rsub_156 = (((int)1) - add_153);
			t_sample abs_175 = fabs(in2);
			t_sample add_174 = (abs_175 + ((t_sample)0.0001));
			t_sample rsub_177 = (((int)1) - add_174);
			t_sample mix_1483 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_ctrl_35 - m_history_18)));
			t_sample mix_1315 = mix_1483;
			t_sample mix_1484 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_1315 - m_history_17)));
			t_sample mix_1316 = mix_1484;
			t_sample mix_1485 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_1316 - m_history_16)));
			t_sample mix_1309 = mix_1485;
			t_sample gen_351 = mix_1309;
			t_sample history_340_next_1308 = fixdenorm(mix_1315);
			t_sample history_338_next_1312 = fixdenorm(mix_1316);
			t_sample history_336_next_1313 = fixdenorm(mix_1309);
			t_sample fold_152 = fold(in1, (-1), ((int)0));
			t_sample fold_171 = fold(in2, (-1), ((int)0));
			t_sample phasor_122 = __m_phasor_54(((int)1), samples_to_seconds);
			t_sample mul_119 = (phasor_122 * ((t_sample)0.2));
			t_sample mix_1486 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_ctrl_25 - m_history_15)));
			t_sample mix_1328 = mix_1486;
			t_sample mix_1487 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_1328 - m_history_14)));
			t_sample mix_1322 = mix_1487;
			t_sample mix_1488 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_1322 - m_history_13)));
			t_sample mix_1329 = mix_1488;
			t_sample gen_347 = mix_1329;
			t_sample history_340_next_1321 = fixdenorm(mix_1328);
			t_sample history_338_next_1325 = fixdenorm(mix_1322);
			t_sample history_336_next_1326 = fixdenorm(mix_1329);
			t_sample sub_1492 = (gen_347 - ((int)0));
			t_sample scale_1489 = ((safepow((sub_1492 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_165 = fabs(scale_1489);
			t_sample sub_1496 = (abs_165 - ((int)1));
			t_sample scale_1493 = ((safepow((sub_1496 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_125 = (scale_1493 > ((int)2));
			t_sample mix_1497 = (m_history_12 + (((t_sample)0.0019634941468452) * (m_ctrl_33 - m_history_12)));
			t_sample mix_1338 = mix_1497;
			t_sample mix_1498 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_1338 - m_history_11)));
			t_sample mix_1335 = mix_1498;
			t_sample mix_1499 = (m_history_10 + (((t_sample)0.0019634941468452) * (mix_1335 - m_history_10)));
			t_sample mix_1341 = mix_1499;
			t_sample gen_348 = mix_1341;
			t_sample history_340_next_1334 = fixdenorm(mix_1338);
			t_sample history_338_next_1339 = fixdenorm(mix_1335);
			t_sample history_336_next_1340 = fixdenorm(mix_1341);
			t_sample sub_1503 = (gen_348 - ((int)0));
			t_sample scale_1500 = ((safepow((sub_1503 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_181 = fabs(scale_1500);
			t_sample sub_1507 = (abs_181 - ((int)1));
			t_sample scale_1504 = ((safepow((sub_1507 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_130 = (scale_1504 > ((int)2));
			t_sample mix_1508 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_ctrl_30 - m_history_9)));
			t_sample mix_1349 = mix_1508;
			t_sample mix_1509 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_1349 - m_history_8)));
			t_sample mix_1348 = mix_1509;
			t_sample mix_1510 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_1348 - m_history_7)));
			t_sample mix_1351 = mix_1510;
			t_sample gen_350 = mix_1351;
			t_sample history_340_next_1347 = fixdenorm(mix_1349);
			t_sample history_338_next_1353 = fixdenorm(mix_1348);
			t_sample history_336_next_1355 = fixdenorm(mix_1351);
			__m_slide_55 = fixdenorm((__m_slide_55 + (((gen_350 > __m_slide_55) ? iup_56 : idown_57) * (gen_350 - __m_slide_55))));
			t_sample slide_183 = __m_slide_55;
			t_sample mix_1511 = (m_history_6 + (((t_sample)0.0019634941468452) * (m_ctrl_32 - m_history_6)));
			t_sample mix_1368 = mix_1511;
			t_sample mix_1512 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_1368 - m_history_5)));
			t_sample mix_1365 = mix_1512;
			t_sample mix_1513 = (m_history_4 + (((t_sample)0.0019634941468452) * (mix_1365 - m_history_4)));
			t_sample mix_1360 = mix_1513;
			t_sample gen_346 = mix_1360;
			t_sample history_340_next_1367 = fixdenorm(mix_1368);
			t_sample history_338_next_1363 = fixdenorm(mix_1365);
			t_sample history_336_next_1364 = fixdenorm(mix_1360);
			t_sample sub_1517 = (gen_346 - ((int)0));
			t_sample scale_1514 = ((safepow((sub_1517 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_219 = ((scale_1514 >= ((int)0)) ? scale_1514 : 0);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((gtep_219 > __m_slide_58) ? iup_59 : idown_60) * (gtep_219 - __m_slide_58))));
			t_sample slide_216 = __m_slide_58;
			t_sample ceil_140 = ceil(slide_216);
			t_sample add_116 = (fold_171 + gtep_219);
			t_sample sub_1521 = (gen_346 - ((int)0));
			t_sample scale_1518 = ((safepow((sub_1521 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_221 = ((scale_1518 <= ((int)0)) ? scale_1518 : 0);
			t_sample abs_222 = fabs(ltep_221);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((abs_222 > __m_slide_61) ? iup_62 : idown_63) * (abs_222 - __m_slide_61))));
			t_sample slide_218 = __m_slide_61;
			t_sample ceil_142 = ceil(slide_218);
			t_sample add_115 = (fold_152 + abs_222);
			t_sample sub_1525 = (gen_346 - ((int)0));
			t_sample scale_1522 = ((safepow((sub_1525 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_224 = fabs(scale_1522);
			t_sample sub_1529 = (abs_224 - ((int)1));
			t_sample scale_1526 = ((safepow((sub_1529 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_64 = fixdenorm((__m_slide_64 + (((scale_1526 > __m_slide_64) ? iup_65 : idown_66) * (scale_1526 - __m_slide_64))));
			t_sample slide_217 = __m_slide_64;
			t_sample ceil_141 = ceil(slide_217);
			t_sample add_113 = (add_115 + scale_1526);
			t_sample sub_112 = (add_113 - ((t_sample)0.3));
			t_sample add_114 = (add_116 + scale_1526);
			t_sample sub_111 = (add_114 - ((t_sample)0.3));
			t_sample selector_206 = ((choice_67 >= 3) ? gt_158 : ((choice_67 >= 2) ? ((int)1) : ((choice_67 >= 1) ? gt_161 : 0)));
			t_sample selector_155 = ((choice_68 >= 3) ? gt_158 : ((choice_68 >= 2) ? ((int)1) : ((choice_68 >= 1) ? gt_161 : 0)));
			t_sample switch_157 = (selector_155 ? rsub_156 : sub_112);
			t_sample out3 = switch_157;
			t_sample selector_176 = ((choice_69 >= 3) ? gt_158 : ((choice_69 >= 2) ? ((int)1) : ((choice_69 >= 1) ? gt_161 : 0)));
			t_sample switch_178 = (selector_176 ? rsub_177 : sub_111);
			t_sample out4 = switch_178;
			t_sample switch_145 = (neq_136 ? ceil_140 : ((int)1));
			t_sample mul_144 = (counter_281 * switch_145);
			t_sample switch_204 = (selector_206 ? mul_144 : ((int)0));
			t_sample mul_143 = (counter_281 * switch_145);
			t_sample switch_201 = (selector_206 ? mul_143 : ((int)0));
			t_sample switch_150 = (neq_136 ? ceil_142 : ((int)1));
			t_sample mul_151 = (switch_150 * counter_293);
			t_sample switch_207 = (selector_206 ? mul_151 : ((int)0));
			t_sample mul_149 = (switch_150 * counter_293);
			t_sample switch_205 = (selector_206 ? mul_149 : ((int)0));
			t_sample switch_147 = (neq_136 ? ceil_141 : ((int)1));
			t_sample mul_146 = (switch_147 * counter_285);
			t_sample switch_202 = (selector_206 ? mul_146 : ((int)0));
			t_sample mul_148 = (switch_147 * counter_285);
			t_sample switch_203 = (selector_206 ? mul_148 : ((int)0));
			t_sample mix_1534 = (m_history_3 + (((t_sample)0.0019634941468452) * (m_ctrl_27 - m_history_3)));
			t_sample mix_1381 = mix_1534;
			t_sample mix_1535 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_1381 - m_history_2)));
			t_sample mix_1378 = mix_1535;
			t_sample mix_1536 = (m_history_1 + (((t_sample)0.0019634941468452) * (mix_1378 - m_history_1)));
			t_sample mix_1373 = mix_1536;
			t_sample gen_349 = mix_1373;
			t_sample history_340_next_1379 = fixdenorm(mix_1381);
			t_sample history_338_next_1376 = fixdenorm(mix_1378);
			t_sample history_336_next_1377 = fixdenorm(mix_1373);
			t_sample sub_1540 = (gen_349 - ((int)0));
			t_sample scale_1537 = ((safepow((sub_1540 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_169 = fabs(scale_1537);
			t_sample sub_1544 = (abs_169 - ((int)1));
			t_sample scale_1541 = ((safepow((sub_1544 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int lt_124 = (scale_1541 < ((int)2));
			int gt_94 = (scale_1489 > ((int)0));
			t_sample mul_91 = (scale_1493 * (-1));
			t_sample switch_97 = (gt_94 ? scale_1493 : mul_91);
			t_sample rdiv_251 = safediv(((int)1), switch_97);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((rdiv_251 > __m_slide_70) ? iup_71 : idown_72) * (rdiv_251 - __m_slide_70))));
			t_sample slide_163 = __m_slide_70;
			t_sample phasor_252 = __m_phasor_73(slide_163, samples_to_seconds);
			t_sample mul_249 = (phasor_252 * ((int)2));
			t_sample sub_248 = (mul_249 - ((int)1));
			t_sample cos_247 = cos(sub_248);
			t_sample sub_246 = (cos_247 - ((t_sample)0.5));
			t_sample mul_245 = (sub_246 * ((int)10));
			t_sample clamp_244 = ((mul_245 <= ((int)0)) ? ((int)0) : ((mul_245 >= ((int)1)) ? ((int)1) : mul_245));
			t_sample fold_237 = fold(phasor_252, ((int)0), ((int)1));
			double sample_index_74 = (fold_237 * loopR_dim);
			int index_trunc_75 = fixnan(floor(sample_index_74));
			double index_fract_76 = (sample_index_74 - index_trunc_75);
			int index_trunc_77 = (index_trunc_75 - 1);
			int index_trunc_78 = (index_trunc_75 + 1);
			int index_trunc_79 = (index_trunc_75 + 2);
			int index_wrap_80 = ((index_trunc_77 < 0) ? ((loopR_dim - 1) + ((index_trunc_77 + 1) % loopR_dim)) : (index_trunc_77 % loopR_dim));
			int index_wrap_81 = ((index_trunc_75 < 0) ? ((loopR_dim - 1) + ((index_trunc_75 + 1) % loopR_dim)) : (index_trunc_75 % loopR_dim));
			int index_wrap_82 = ((index_trunc_78 < 0) ? ((loopR_dim - 1) + ((index_trunc_78 + 1) % loopR_dim)) : (index_trunc_78 % loopR_dim));
			int index_wrap_83 = ((index_trunc_79 < 0) ? ((loopR_dim - 1) + ((index_trunc_79 + 1) % loopR_dim)) : (index_trunc_79 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_84 = m_loopR_26.read(index_wrap_80, 0);
			double read_loopR_85 = m_loopR_26.read(index_wrap_81, 0);
			double read_loopR_86 = m_loopR_26.read(index_wrap_82, 0);
			double read_loopR_87 = m_loopR_26.read(index_wrap_83, 0);
			double readinterp_88 = spline_interp(index_fract_76, read_loopR_84, read_loopR_85, read_loopR_86, read_loopR_87);
			t_sample sample_loopR_242 = readinterp_88;
			t_sample index_loopR_243 = sample_index_74;
			t_sample mul_236 = (sample_loopR_242 * clamp_244);
			double sample_index_89 = (fold_237 * loopR_dim);
			int index_trunc_90 = fixnan(floor(sample_index_89));
			double index_fract_91 = (sample_index_89 - index_trunc_90);
			int index_trunc_92 = (index_trunc_90 - 1);
			int index_trunc_93 = (index_trunc_90 + 1);
			int index_trunc_94 = (index_trunc_90 + 2);
			int index_wrap_95 = ((index_trunc_92 < 0) ? ((loopR_dim - 1) + ((index_trunc_92 + 1) % loopR_dim)) : (index_trunc_92 % loopR_dim));
			int index_wrap_96 = ((index_trunc_90 < 0) ? ((loopR_dim - 1) + ((index_trunc_90 + 1) % loopR_dim)) : (index_trunc_90 % loopR_dim));
			int index_wrap_97 = ((index_trunc_93 < 0) ? ((loopR_dim - 1) + ((index_trunc_93 + 1) % loopR_dim)) : (index_trunc_93 % loopR_dim));
			int index_wrap_98 = ((index_trunc_94 < 0) ? ((loopR_dim - 1) + ((index_trunc_94 + 1) % loopR_dim)) : (index_trunc_94 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_100 = (chan_ignore_99 ? 0 : m_loopR_26.read(index_wrap_95, 1));
			double read_loopR_101 = (chan_ignore_99 ? 0 : m_loopR_26.read(index_wrap_96, 1));
			double read_loopR_102 = (chan_ignore_99 ? 0 : m_loopR_26.read(index_wrap_97, 1));
			double read_loopR_103 = (chan_ignore_99 ? 0 : m_loopR_26.read(index_wrap_98, 1));
			double readinterp_104 = spline_interp(index_fract_91, read_loopR_100, read_loopR_101, read_loopR_102, read_loopR_103);
			t_sample sample_loopR_240 = readinterp_104;
			t_sample index_loopR_241 = sample_index_89;
			t_sample mul_235 = (sample_loopR_240 * clamp_244);
			int gt_96 = (scale_1500 > ((int)0));
			t_sample mul_93 = (scale_1504 * (-1));
			t_sample switch_98 = (gt_96 ? scale_1504 : mul_93);
			t_sample rdiv_319 = safediv(((int)1), switch_98);
			__m_slide_105 = fixdenorm((__m_slide_105 + (((rdiv_319 > __m_slide_105) ? iup_106 : idown_107) * (rdiv_319 - __m_slide_105))));
			t_sample slide_179 = __m_slide_105;
			t_sample phasor_320 = __m_phasor_108(slide_179, samples_to_seconds);
			t_sample mul_308 = (phasor_320 * ((int)2));
			t_sample sub_307 = (mul_308 - ((int)1));
			t_sample cos_306 = cos(sub_307);
			t_sample sub_305 = (cos_306 - ((t_sample)0.5));
			t_sample mul_304 = (sub_305 * ((int)10));
			t_sample clamp_303 = ((mul_304 <= ((int)0)) ? ((int)0) : ((mul_304 >= ((int)1)) ? ((int)1) : mul_304));
			t_sample fold_310 = fold(phasor_320, ((int)0), ((int)1));
			double sample_index_109 = (fold_310 * loopL_dim);
			int index_trunc_110 = fixnan(floor(sample_index_109));
			double index_fract_111 = (sample_index_109 - index_trunc_110);
			int index_trunc_112 = (index_trunc_110 - 1);
			int index_trunc_113 = (index_trunc_110 + 1);
			int index_trunc_114 = (index_trunc_110 + 2);
			int index_wrap_115 = ((index_trunc_112 < 0) ? ((loopL_dim - 1) + ((index_trunc_112 + 1) % loopL_dim)) : (index_trunc_112 % loopL_dim));
			int index_wrap_116 = ((index_trunc_110 < 0) ? ((loopL_dim - 1) + ((index_trunc_110 + 1) % loopL_dim)) : (index_trunc_110 % loopL_dim));
			int index_wrap_117 = ((index_trunc_113 < 0) ? ((loopL_dim - 1) + ((index_trunc_113 + 1) % loopL_dim)) : (index_trunc_113 % loopL_dim));
			int index_wrap_118 = ((index_trunc_114 < 0) ? ((loopL_dim - 1) + ((index_trunc_114 + 1) % loopL_dim)) : (index_trunc_114 % loopL_dim));
			// phase loopL channel 1;
			double read_loopL_119 = m_loopL_23.read(index_wrap_115, 0);
			double read_loopL_120 = m_loopL_23.read(index_wrap_116, 0);
			double read_loopL_121 = m_loopL_23.read(index_wrap_117, 0);
			double read_loopL_122 = m_loopL_23.read(index_wrap_118, 0);
			double readinterp_123 = spline_interp(index_fract_111, read_loopL_119, read_loopL_120, read_loopL_121, read_loopL_122);
			t_sample sample_loopL_316 = readinterp_123;
			t_sample index_loopL_317 = sample_index_109;
			t_sample mul_301 = (sample_loopL_316 * clamp_303);
			t_sample mix_1549 = (mul_301 + (((t_sample)0.5) * (mul_236 - mul_301)));
			t_sample selector_108 = ((choice_124 >= 3) ? mul_301 : ((choice_124 >= 2) ? in1 : ((choice_124 >= 1) ? in1 : 0)));
			double sample_index_125 = (fold_310 * loopL_dim);
			int index_trunc_126 = fixnan(floor(sample_index_125));
			double index_fract_127 = (sample_index_125 - index_trunc_126);
			int index_trunc_128 = (index_trunc_126 - 1);
			int index_trunc_129 = (index_trunc_126 + 1);
			int index_trunc_130 = (index_trunc_126 + 2);
			int index_wrap_131 = ((index_trunc_128 < 0) ? ((loopL_dim - 1) + ((index_trunc_128 + 1) % loopL_dim)) : (index_trunc_128 % loopL_dim));
			int index_wrap_132 = ((index_trunc_126 < 0) ? ((loopL_dim - 1) + ((index_trunc_126 + 1) % loopL_dim)) : (index_trunc_126 % loopL_dim));
			int index_wrap_133 = ((index_trunc_129 < 0) ? ((loopL_dim - 1) + ((index_trunc_129 + 1) % loopL_dim)) : (index_trunc_129 % loopL_dim));
			int index_wrap_134 = ((index_trunc_130 < 0) ? ((loopL_dim - 1) + ((index_trunc_130 + 1) % loopL_dim)) : (index_trunc_130 % loopL_dim));
			// phase loopL channel 1;
			double read_loopL_136 = (chan_ignore_135 ? 0 : m_loopL_23.read(index_wrap_131, 1));
			double read_loopL_137 = (chan_ignore_135 ? 0 : m_loopL_23.read(index_wrap_132, 1));
			double read_loopL_138 = (chan_ignore_135 ? 0 : m_loopL_23.read(index_wrap_133, 1));
			double read_loopL_139 = (chan_ignore_135 ? 0 : m_loopL_23.read(index_wrap_134, 1));
			double readinterp_140 = spline_interp(index_fract_127, read_loopL_136, read_loopL_137, read_loopL_138, read_loopL_139);
			t_sample sample_loopL_314 = readinterp_140;
			t_sample index_loopL_315 = sample_index_125;
			t_sample mul_302 = (sample_loopL_314 * clamp_303);
			t_sample selector_103 = ((choice_141 >= 3) ? mul_302 : ((choice_141 >= 2) ? in2 : ((choice_141 >= 1) ? in2 : 0)));
			t_sample mix_1550 = (mul_302 + (((t_sample)0.5) * (mul_235 - mul_302)));
			int gt_95 = (scale_1537 > ((int)0));
			t_sample mul_92 = (scale_1541 * (-1));
			t_sample switch_99 = (gt_95 ? scale_1541 : mul_92);
			t_sample rdiv_272 = safediv(((int)1), switch_99);
			__m_slide_142 = fixdenorm((__m_slide_142 + (((rdiv_272 > __m_slide_142) ? iup_143 : idown_144) * (rdiv_272 - __m_slide_142))));
			t_sample slide_167 = __m_slide_142;
			t_sample phasor_273 = __m_phasor_145(slide_167, samples_to_seconds);
			t_sample mul_270 = (phasor_273 * ((int)2));
			t_sample sub_269 = (mul_270 - ((int)1));
			t_sample cos_268 = cos(sub_269);
			t_sample sub_267 = (cos_268 - ((t_sample)0.5));
			t_sample mul_266 = (sub_267 * ((int)10));
			t_sample clamp_265 = ((mul_266 <= ((int)0)) ? ((int)0) : ((mul_266 >= ((int)1)) ? ((int)1) : mul_266));
			t_sample fold_258 = fold(phasor_273, ((int)0), ((int)1));
			double sample_index_146 = (fold_258 * loopM_dim);
			int index_trunc_147 = fixnan(floor(sample_index_146));
			double index_fract_148 = (sample_index_146 - index_trunc_147);
			int index_trunc_149 = (index_trunc_147 - 1);
			int index_trunc_150 = (index_trunc_147 + 1);
			int index_trunc_151 = (index_trunc_147 + 2);
			int index_wrap_152 = ((index_trunc_149 < 0) ? ((loopM_dim - 1) + ((index_trunc_149 + 1) % loopM_dim)) : (index_trunc_149 % loopM_dim));
			int index_wrap_153 = ((index_trunc_147 < 0) ? ((loopM_dim - 1) + ((index_trunc_147 + 1) % loopM_dim)) : (index_trunc_147 % loopM_dim));
			int index_wrap_154 = ((index_trunc_150 < 0) ? ((loopM_dim - 1) + ((index_trunc_150 + 1) % loopM_dim)) : (index_trunc_150 % loopM_dim));
			int index_wrap_155 = ((index_trunc_151 < 0) ? ((loopM_dim - 1) + ((index_trunc_151 + 1) % loopM_dim)) : (index_trunc_151 % loopM_dim));
			// phase loopM channel 1;
			double read_loopM_157 = (chan_ignore_156 ? 0 : m_loopM_36.read(index_wrap_152, 1));
			double read_loopM_158 = (chan_ignore_156 ? 0 : m_loopM_36.read(index_wrap_153, 1));
			double read_loopM_159 = (chan_ignore_156 ? 0 : m_loopM_36.read(index_wrap_154, 1));
			double read_loopM_160 = (chan_ignore_156 ? 0 : m_loopM_36.read(index_wrap_155, 1));
			double readinterp_161 = spline_interp(index_fract_148, read_loopM_157, read_loopM_158, read_loopM_159, read_loopM_160);
			t_sample sample_loopM_261 = readinterp_161;
			t_sample index_loopM_262 = sample_index_146;
			t_sample mul_256 = (sample_loopM_261 * clamp_265);
			t_sample mix_1551 = (selector_103 + (slide_183 * (mul_256 - selector_103)));
			t_sample clamp_187 = ((mix_1551 <= min_162) ? min_162 : ((mix_1551 >= ((int)1)) ? ((int)1) : mix_1551));
			t_sample mul_211 = (clamp_187 * slide_217);
			t_sample clamp_191 = ((mul_211 <= min_163) ? min_163 : ((mul_211 >= ((int)1)) ? ((int)1) : mul_211));
			int index_trunc_165 = fixnan(floor(switch_202));
			int index_wrap_166 = ((index_trunc_165 < 0) ? ((loopM_dim - 1) + ((index_trunc_165 + 1) % loopM_dim)) : (index_trunc_165 % loopM_dim));
			if ((!chan_ignore_164)) {
				m_loopM_36.write((clamp_191 + (m_loopM_36.read(index_wrap_166, ((int)1)) * slide_231)), index_wrap_166, ((int)1));
				
			};
			t_sample mix_1552 = (mix_1550 + (((t_sample)0.33) * (mul_256 - mix_1550)));
			t_sample mul_208 = (mix_1552 * ((int)3));
			t_sample mix_1553 = (in2 + (gen_351 * (mul_208 - in2)));
			t_sample clamp_228 = ((mix_1553 <= min_167) ? min_167 : ((mix_1553 >= ((int)1)) ? ((int)1) : mix_1553));
			t_sample out2 = clamp_228;
			t_sample fold_172 = fold(clamp_228, (-1), ((int)0));
			t_sample abs_127 = fabs(clamp_228);
			t_sample add_126 = (abs_127 + ((t_sample)0.0001));
			t_sample rsub_128 = (((int)1) - add_126);
			t_sample mul_117 = (rsub_128 * mul_119);
			t_sample switch_118 = (lt_124 ? rsub_128 : mul_117);
			t_sample switch_129 = (gt_125 ? switch_118 : fold_172);
			t_sample out6 = switch_129;
			t_sample selector_102 = ((choice_168 >= 3) ? mul_256 : ((choice_168 >= 2) ? in2 : ((choice_168 >= 1) ? mul_256 : 0)));
			t_sample mix_1554 = (selector_102 + (slide_183 * (mul_235 - selector_102)));
			t_sample clamp_185 = ((mix_1554 <= min_169) ? min_169 : ((mix_1554 >= ((int)1)) ? ((int)1) : mix_1554));
			t_sample mul_210 = (clamp_185 * slide_216);
			t_sample clamp_190 = ((mul_210 <= min_170) ? min_170 : ((mul_210 >= ((int)1)) ? ((int)1) : mul_210));
			int index_trunc_172 = fixnan(floor(switch_201));
			int index_wrap_173 = ((index_trunc_172 < 0) ? ((loopR_dim - 1) + ((index_trunc_172 + 1) % loopR_dim)) : (index_trunc_172 % loopR_dim));
			if ((!chan_ignore_171)) {
				m_loopR_26.write((clamp_190 + (m_loopR_26.read(index_wrap_173, ((int)1)) * slide_231)), index_wrap_173, ((int)1));
				
			};
			t_sample selector_104 = ((choice_174 >= 3) ? in2 : ((choice_174 >= 2) ? in2 : ((choice_174 >= 1) ? mul_256 : 0)));
			t_sample mix_1555 = (selector_104 + (slide_183 * (mul_302 - selector_104)));
			t_sample clamp_189 = ((mix_1555 <= min_175) ? min_175 : ((mix_1555 >= ((int)1)) ? ((int)1) : mix_1555));
			t_sample mul_212 = (clamp_189 * slide_218);
			t_sample clamp_192 = ((mul_212 <= min_176) ? min_176 : ((mul_212 >= ((int)1)) ? ((int)1) : mul_212));
			int index_trunc_178 = fixnan(floor(switch_205));
			int index_wrap_179 = ((index_trunc_178 < 0) ? ((loopL_dim - 1) + ((index_trunc_178 + 1) % loopL_dim)) : (index_trunc_178 % loopL_dim));
			if ((!chan_ignore_177)) {
				m_loopL_23.write((clamp_192 + (m_loopL_23.read(index_wrap_179, ((int)1)) * slide_231)), index_wrap_179, ((int)1));
				
			};
			double sample_index_180 = (fold_258 * loopM_dim);
			int index_trunc_181 = fixnan(floor(sample_index_180));
			double index_fract_182 = (sample_index_180 - index_trunc_181);
			int index_trunc_183 = (index_trunc_181 - 1);
			int index_trunc_184 = (index_trunc_181 + 1);
			int index_trunc_185 = (index_trunc_181 + 2);
			int index_wrap_186 = ((index_trunc_183 < 0) ? ((loopM_dim - 1) + ((index_trunc_183 + 1) % loopM_dim)) : (index_trunc_183 % loopM_dim));
			int index_wrap_187 = ((index_trunc_181 < 0) ? ((loopM_dim - 1) + ((index_trunc_181 + 1) % loopM_dim)) : (index_trunc_181 % loopM_dim));
			int index_wrap_188 = ((index_trunc_184 < 0) ? ((loopM_dim - 1) + ((index_trunc_184 + 1) % loopM_dim)) : (index_trunc_184 % loopM_dim));
			int index_wrap_189 = ((index_trunc_185 < 0) ? ((loopM_dim - 1) + ((index_trunc_185 + 1) % loopM_dim)) : (index_trunc_185 % loopM_dim));
			// phase loopM channel 1;
			double read_loopM_190 = m_loopM_36.read(index_wrap_186, 0);
			double read_loopM_191 = m_loopM_36.read(index_wrap_187, 0);
			double read_loopM_192 = m_loopM_36.read(index_wrap_188, 0);
			double read_loopM_193 = m_loopM_36.read(index_wrap_189, 0);
			double readinterp_194 = spline_interp(index_fract_182, read_loopM_190, read_loopM_191, read_loopM_192, read_loopM_193);
			t_sample sample_loopM_263 = readinterp_194;
			t_sample index_loopM_264 = sample_index_180;
			t_sample mul_257 = (sample_loopM_263 * clamp_265);
			t_sample mix_1556 = (mix_1549 + (((t_sample)0.33) * (mul_257 - mix_1549)));
			t_sample mul_209 = (mix_1556 * ((int)3));
			t_sample mix_1557 = (in1 + (gen_351 * (mul_209 - in1)));
			t_sample clamp_229 = ((mix_1557 <= min_195) ? min_195 : ((mix_1557 >= ((int)1)) ? ((int)1) : mix_1557));
			t_sample out1 = clamp_229;
			t_sample fold_173 = fold(clamp_229, (-1), ((int)0));
			t_sample abs_132 = fabs(clamp_229);
			t_sample add_131 = (abs_132 + ((t_sample)0.0001));
			t_sample rsub_133 = (((int)1) - add_131);
			t_sample mul_120 = (mul_119 * rsub_133);
			t_sample switch_123 = (lt_124 ? rsub_133 : mul_120);
			t_sample switch_134 = (gt_130 ? switch_123 : fold_173);
			t_sample out5 = switch_134;
			t_sample mix_1558 = (selector_108 + (slide_183 * (mul_257 - selector_108)));
			t_sample clamp_196 = ((mix_1558 <= min_196) ? min_196 : ((mix_1558 >= ((int)1)) ? ((int)1) : mix_1558));
			t_sample mul_214 = (clamp_196 * slide_217);
			t_sample clamp_194 = ((mul_214 <= min_197) ? min_197 : ((mul_214 >= ((int)1)) ? ((int)1) : mul_214));
			int index_trunc_198 = fixnan(floor(switch_203));
			int index_wrap_199 = ((index_trunc_198 < 0) ? ((loopM_dim - 1) + ((index_trunc_198 + 1) % loopM_dim)) : (index_trunc_198 % loopM_dim));
			m_loopM_36.write((clamp_194 + (m_loopM_36.read(index_wrap_199, 0) * slide_231)), index_wrap_199, 0);
			t_sample selector_107 = ((choice_200 >= 3) ? mul_257 : ((choice_200 >= 2) ? in1 : ((choice_200 >= 1) ? mul_257 : 0)));
			t_sample mix_1559 = (selector_107 + (slide_183 * (mul_236 - selector_107)));
			t_sample clamp_106 = ((mix_1559 <= min_201) ? min_201 : ((mix_1559 >= ((int)1)) ? ((int)1) : mix_1559));
			t_sample mul_213 = (clamp_106 * slide_216);
			t_sample clamp_193 = ((mul_213 <= min_202) ? min_202 : ((mul_213 >= ((int)1)) ? ((int)1) : mul_213));
			int index_trunc_203 = fixnan(floor(switch_204));
			int index_wrap_204 = ((index_trunc_203 < 0) ? ((loopR_dim - 1) + ((index_trunc_203 + 1) % loopR_dim)) : (index_trunc_203 % loopR_dim));
			m_loopR_26.write((clamp_193 + (m_loopR_26.read(index_wrap_204, 0) * slide_231)), index_wrap_204, 0);
			t_sample selector_109 = ((choice_205 >= 3) ? in1 : ((choice_205 >= 2) ? in1 : ((choice_205 >= 1) ? mul_257 : 0)));
			t_sample mix_1560 = (selector_109 + (slide_183 * (mul_301 - selector_109)));
			t_sample clamp_197 = ((mix_1560 <= min_206) ? min_206 : ((mix_1560 >= ((int)1)) ? ((int)1) : mix_1560));
			t_sample mul_215 = (clamp_197 * slide_218);
			t_sample clamp_195 = ((mul_215 <= min_207) ? min_207 : ((mul_215 >= ((int)1)) ? ((int)1) : mul_215));
			int index_trunc_208 = fixnan(floor(switch_207));
			int index_wrap_209 = ((index_trunc_208 < 0) ? ((loopL_dim - 1) + ((index_trunc_208 + 1) % loopL_dim)) : (index_trunc_208 % loopL_dim));
			m_loopL_23.write((clamp_195 + (m_loopL_23.read(index_wrap_209, 0) * slide_231)), index_wrap_209, 0);
			m_history_22 = history_360_next_364;
			m_history_21 = history_340_next_342;
			m_history_19 = history_336_next_344;
			m_history_20 = history_338_next_343;
			m_history_18 = history_340_next_1308;
			m_history_16 = history_336_next_1313;
			m_history_17 = history_338_next_1312;
			m_history_15 = history_340_next_1321;
			m_history_13 = history_336_next_1326;
			m_history_14 = history_338_next_1325;
			m_history_12 = history_340_next_1334;
			m_history_10 = history_336_next_1340;
			m_history_11 = history_338_next_1339;
			m_history_9 = history_340_next_1347;
			m_history_7 = history_336_next_1355;
			m_history_8 = history_338_next_1353;
			m_history_6 = history_340_next_1367;
			m_history_4 = history_336_next_1364;
			m_history_5 = history_338_next_1363;
			m_history_3 = history_340_next_1379;
			m_history_1 = history_336_next_1377;
			m_history_2 = history_338_next_1376;
			// assign results to output buffer;
			(*(__out1++)) = out1;
			(*(__out2++)) = out2;
			(*(__out3++)) = out3;
			(*(__out4++)) = out4;
			(*(__out5++)) = out5;
			(*(__out6++)) = out6;
			(*(__out7++)) = out7;
			(*(__out8++)) = out8;
			(*(__out9++)) = out9;
			(*(__out10++)) = out10;
			
		};
		return __exception;
		
	};
	inline void set_loopL(void * _value) {
		m_loopL_23.setbuffer(_value);
	};
	inline void set_sw2(t_param _value) {
		m_sw_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopR(void * _value) {
		m_loopR_26.setbuffer(_value);
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopM(void * _value) {
		m_loopM_36.setbuffer(_value);
	};
	
} State;


///
///	Configuration for the genlib API
///

/// Number of signal inputs and outputs

int gen_kernel_numins = 2;
int gen_kernel_numouts = 10;

int num_inputs() { return gen_kernel_numins; }
int num_outputs() { return gen_kernel_numouts; }
int num_params() { return 14; }

/// Assistive lables for the signal inputs and outputs

const char *gen_kernel_innames[] = { "in1", "in2" };
const char *gen_kernel_outnames[] = { "out1", "out2", "led1", "led2", "led3", "led4", "out7", "out8", "out9", "out10" };

/// Invoke the signal process of a State object

int perform(CommonState *cself, t_sample **ins, long numins, t_sample **outs, long numouts, long n) {
	State* self = (State *)cself;
	return self->perform(ins, outs, n);
}

/// Reset all parameters and stateful operators of a State object

void reset(CommonState *cself) {
	State* self = (State *)cself;
	self->reset(cself->sr, cself->vs);
}

/// Set a parameter of a State object

void setparameter(CommonState *cself, long index, t_param value, void *ref) {
	State *self = (State *)cself;
	switch (index) {
		case 0: self->set_button(value); break;
		case 1: self->set_ctrl1(value); break;
		case 2: self->set_ctrl2(value); break;
		case 3: self->set_ctrl3(value); break;
		case 4: self->set_ctrl4(value); break;
		case 5: self->set_ctrl5(value); break;
		case 6: self->set_ctrl6(value); break;
		case 7: self->set_ctrl7(value); break;
		case 8: self->set_gate(value); break;
		case 9: self->set_loopL(ref); break;
		case 10: self->set_loopM(ref); break;
		case 11: self->set_loopR(ref); break;
		case 12: self->set_sw1(value); break;
		case 13: self->set_sw2(value); break;
		
		default: break;
	}
}

/// Get the value of a parameter of a State object

void getparameter(CommonState *cself, long index, t_param *value) {
	State *self = (State *)cself;
	switch (index) {
		case 0: *value = self->m_button_34; break;
		case 1: *value = self->m_ctrl_35; break;
		case 2: *value = self->m_ctrl_33; break;
		case 3: *value = self->m_ctrl_27; break;
		case 4: *value = self->m_ctrl_32; break;
		case 5: *value = self->m_ctrl_30; break;
		case 6: *value = self->m_ctrl_25; break;
		case 7: *value = self->m_ctrl_29; break;
		case 8: *value = self->m_gate_28; break;
		
		
		
		case 12: *value = self->m_sw_31; break;
		case 13: *value = self->m_sw_24; break;
		
		default: break;
	}
}

/// Get the name of a parameter of a State object

const char *getparametername(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].name;
	}
	return 0;
}

/// Get the minimum value of a parameter of a State object

t_param getparametermin(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmin;
	}
	return 0;
}

/// Get the maximum value of a parameter of a State object

t_param getparametermax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].outputmax;
	}
	return 0;
}

/// Get parameter of a State object has a minimum and maximum value

char getparameterhasminmax(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].hasminmax;
	}
	return 0;
}

/// Get the units of a parameter of a State object

const char *getparameterunits(CommonState *cself, long index) {
	if (index >= 0 && index < cself->numparams) {
		return cself->params[index].units;
	}
	return 0;
}

/// Get the size of the state of all parameters of a State object

size_t getstatesize(CommonState *cself) {
	return genlib_getstatesize(cself, &getparameter);
}

/// Get the state of all parameters of a State object

short getstate(CommonState *cself, char *state) {
	return genlib_getstate(cself, state, &getparameter);
}

/// set the state of all parameters of a State object

short setstate(CommonState *cself, const char *state) {
	return genlib_setstate(cself, state, &setparameter);
}

/// Allocate and configure a new State object and it's internal CommonState:

void *create(t_param sr, long vs) {
	State *self = new State;
	self->reset(sr, vs);
	ParamInfo *pi;
	self->__commonstate.inputnames = gen_kernel_innames;
	self->__commonstate.outputnames = gen_kernel_outnames;
	self->__commonstate.numins = gen_kernel_numins;
	self->__commonstate.numouts = gen_kernel_numouts;
	self->__commonstate.sr = sr;
	self->__commonstate.vs = vs;
	self->__commonstate.params = (ParamInfo *)genlib_sysmem_newptr(14 * sizeof(ParamInfo));
	self->__commonstate.numparams = 14;
	// initialize parameter 0 ("m_button_34")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_35")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_35;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_33")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_27")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 4 ("m_ctrl_32")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_32;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_30")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 6 ("m_ctrl_25")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_25;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_29")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_29;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 8 ("m_gate_28")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loopL_23")
	pi = self->__commonstate.params + 9;
	pi->name = "loopL";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 10 ("m_loopM_36")
	pi = self->__commonstate.params + 10;
	pi->name = "loopM";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 11 ("m_loopR_26")
	pi = self->__commonstate.params + 11;
	pi->name = "loopR";
	pi->paramtype = GENLIB_PARAMTYPE_SYM;
	pi->defaultvalue = 0.;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = false;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 12 ("m_sw_31")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_24")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_24;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	
	return self;
}

/// Release all resources and memory used by a State object:

void destroy(CommonState *cself) {
	State *self = (State *)cself;
	genlib_sysmem_freeptr(cself->params);
		
	delete self;
}


} // TriwalkmaVersio_2dworking_2dmid_2dalways::
