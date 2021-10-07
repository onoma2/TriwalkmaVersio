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
	Data m_loopL_24;
	Data m_loopR_36;
	Data m_loopM_25;
	Delta __m_delta_37;
	Phasor __m_phasor_167;
	Phasor __m_phasor_73;
	Phasor __m_phasor_54;
	Phasor __m_phasor_112;
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
	t_sample m_ctrl_34;
	t_sample m_sw_35;
	t_sample m_gate_33;
	t_sample __m_count_50;
	t_sample samples_to_seconds;
	t_sample __m_slide_70;
	t_sample samplerate;
	t_sample __m_slide_109;
	t_sample __m_carry_52;
	t_sample __m_slide_67;
	t_sample __m_slide_61;
	t_sample __m_slide_64;
	t_sample m_history_1;
	t_sample __m_slide_58;
	t_sample m_history_7;
	t_sample m_ctrl_32;
	t_sample m_sw_30;
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
	t_sample m_button_31;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample __m_slide_164;
	t_sample m_ctrl_28;
	t_sample m_ctrl_29;
	t_sample m_history_20;
	t_sample m_ctrl_26;
	t_sample m_history_6;
	t_sample m_history_5;
	t_sample m_history_22;
	t_sample m_ctrl_23;
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
		m_ctrl_23 = ((int)0);
		m_loopL_24.reset("loopL", ((int)192000), ((int)2));
		m_loopM_25.reset("loopM", ((int)192000), ((int)2));
		m_ctrl_26 = ((int)0);
		m_ctrl_27 = ((int)0);
		m_ctrl_28 = ((int)0);
		m_ctrl_29 = ((int)0);
		m_sw_30 = ((int)0);
		m_button_31 = ((int)0);
		m_ctrl_32 = ((int)0);
		m_gate_33 = ((int)0);
		m_ctrl_34 = ((int)0);
		m_sw_35 = ((int)0);
		m_loopR_36.reset("loopR", ((int)192000), ((int)2));
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
		__m_slide_58 = 0;
		__m_slide_61 = 0;
		__m_slide_64 = 0;
		__m_slide_67 = 0;
		__m_slide_70 = 0;
		__m_phasor_73.reset(0);
		__m_slide_109 = 0;
		__m_phasor_112.reset(0);
		__m_slide_164 = 0;
		__m_phasor_167.reset(0);
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
		int loopR_dim = m_loopR_36.dim;
		int loopR_channels = m_loopR_36.channels;
		int loopR_dim_198 = loopR_dim;
		int loopM_dim = m_loopM_25.dim;
		int loopM_channels = m_loopM_25.channels;
		int loopM_dim_200 = loopM_dim;
		int loopL_dim = m_loopL_24.dim;
		int loopL_channels = m_loopL_24.channels;
		int loopL_dim_208 = loopL_dim;
		int or_277 = (m_gate_33 || m_button_31);
		int gt_71 = (or_277 > ((int)0));
		t_sample iup_44 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)4000))));
		int eq_240 = (m_sw_30 == ((int)0));
		samples_to_seconds = (1 / samplerate);
		int eq_244 = (m_sw_30 == ((t_sample)0.5));
		t_sample switch_243 = (eq_244 ? ((int)0) : m_sw_30);
		t_sample switch_241 = (eq_240 ? ((t_sample)0.5) : switch_243);
		t_sample sub_661 = (switch_241 - ((int)0));
		t_sample scale_658 = ((safepow((sub_661 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_55 = int(scale_658);
		t_sample choice_56 = int(scale_658);
		t_sample choice_57 = int(scale_658);
		int neq_46 = (scale_658 != ((int)2));
		t_sample iup_59 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_60 = (1 / maximum(1, abs(((int)3000))));
		t_sample iup_62 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_65 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_66 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_68 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_69 = (1 / maximum(1, abs(((int)4000))));
		int eq_234 = (m_sw_35 == ((int)0));
		int eq_238 = (m_sw_35 == ((t_sample)0.5));
		t_sample switch_237 = (eq_238 ? ((int)0) : m_sw_35);
		t_sample switch_235 = (eq_234 ? ((t_sample)0.5) : switch_237);
		t_sample sub_720 = (switch_235 - ((int)0));
		t_sample scale_717 = ((safepow((sub_720 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_84 = ((1 < 0) || (1 >= loopM_channels));
		t_sample choice_90 = int(scale_717);
		t_sample choice_91 = int(scale_717);
		t_sample choice_107 = int(scale_717);
		t_sample choice_108 = int(scale_717);
		t_sample iup_110 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_111 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_123 = ((1 < 0) || (1 >= loopL_channels));
		int min_129 = (-1);
		int min_130 = (-1);
		bool chan_ignore_131 = ((((int)1) < 0) || (((int)1) >= loopL_channels));
		t_sample choice_134 = int(scale_717);
		int min_135 = (-1);
		int min_136 = (-1);
		bool chan_ignore_137 = ((((int)1) < 0) || (((int)1) >= loopM_channels));
		int min_155 = (-1);
		int min_156 = (-1);
		t_sample choice_159 = int(scale_717);
		int min_160 = (-1);
		int min_161 = (-1);
		t_sample iup_165 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_166 = (1 / maximum(1, abs(((int)4000))));
		int min_183 = (-1);
		int min_184 = (-1);
		int min_187 = (-1);
		bool chan_ignore_198 = ((1 < 0) || (1 >= loopR_channels));
		int min_204 = (-1);
		int min_205 = (-1);
		bool chan_ignore_206 = ((((int)1) < 0) || (((int)1) >= loopR_channels));
		int min_209 = (-1);
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out7 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out8 = ((int)0);
			t_sample out10 = ((int)0);
			int delta_273 = __m_delta_37(or_277);
			int gtep_272 = ((delta_273 >= ((int)1)) ? delta_273 : 0);
			t_sample plusequals_271 = __m_pluseq_38.post(gtep_272, m_history_22, 0);
			t_sample gen_276 = plusequals_271;
			int eq_269 = (plusequals_271 == ((int)2));
			t_sample history_270_next_274 = fixdenorm(eq_269);
			int gt_68 = (gen_276 > ((int)0));
			t_sample abs_64 = fabs(in1);
			t_sample add_63 = (abs_64 + ((t_sample)0.0001));
			t_sample rsub_66 = (((int)1) - add_63);
			t_sample mix_648 = (m_history_21 + (((t_sample)0.0042742627044161) * (m_ctrl_26 - m_history_21)));
			t_sample mix_249 = mix_648;
			t_sample mix_649 = (m_history_20 + (((t_sample)0.0042742627044161) * (mix_249 - m_history_20)));
			t_sample mix_247 = mix_649;
			t_sample mix_650 = (m_history_19 + (((t_sample)0.0042742627044161) * (mix_247 - m_history_19)));
			t_sample mix_245 = mix_650;
			t_sample gen_261 = mix_245;
			t_sample history_250_next_252 = fixdenorm(mix_249);
			t_sample history_248_next_253 = fixdenorm(mix_247);
			t_sample history_246_next_254 = fixdenorm(mix_245);
			__m_count_39 = (((int)0) ? 0 : (fixdenorm(__m_count_39 + ((int)1))));
			int carry_40 = 0;
			if ((((int)0) != 0)) {
				__m_count_39 = 0;
				__m_carry_41 = 0;
				
			} else if (((loopL_dim_208 > 0) && (__m_count_39 >= loopL_dim_208))) {
				int wraps_42 = (__m_count_39 / loopL_dim_208);
				__m_carry_41 = (__m_carry_41 + wraps_42);
				__m_count_39 = (__m_count_39 - (wraps_42 * loopL_dim_208));
				carry_40 = 1;
				
			};
			int counter_203 = __m_count_39;
			int counter_204 = carry_40;
			int counter_205 = __m_carry_41;
			t_sample mix_651 = (m_history_18 + (((t_sample)0.0042742627044161) * (m_ctrl_32 - m_history_18)));
			t_sample mix_303 = mix_651;
			t_sample mix_652 = (m_history_17 + (((t_sample)0.0042742627044161) * (mix_303 - m_history_17)));
			t_sample mix_301 = mix_652;
			t_sample mix_653 = (m_history_16 + (((t_sample)0.0042742627044161) * (mix_301 - m_history_16)));
			t_sample mix_304 = mix_653;
			t_sample gen_255 = mix_304;
			t_sample history_250_next_307 = fixdenorm(mix_303);
			t_sample history_248_next_306 = fixdenorm(mix_301);
			t_sample history_246_next_305 = fixdenorm(mix_304);
			t_sample sub_657 = (gen_255 - ((int)0));
			t_sample scale_654 = ((safepow((sub_657 * ((t_sample)1)), ((int)1)) * ((t_sample)0.9)) + ((int)0));
			__m_slide_43 = fixdenorm((__m_slide_43 + (((scale_654 > __m_slide_43) ? iup_44 : idown_45) * (scale_654 - __m_slide_43))));
			t_sample slide_141 = __m_slide_43;
			t_sample abs_85 = fabs(in2);
			t_sample add_84 = (abs_85 + ((t_sample)0.0001));
			t_sample rsub_87 = (((int)1) - add_84);
			__m_count_46 = (((int)0) ? 0 : (fixdenorm(__m_count_46 + ((int)1))));
			int carry_47 = 0;
			if ((((int)0) != 0)) {
				__m_count_46 = 0;
				__m_carry_48 = 0;
				
			} else if (((loopM_dim_200 > 0) && (__m_count_46 >= loopM_dim_200))) {
				int wraps_49 = (__m_count_46 / loopM_dim_200);
				__m_carry_48 = (__m_carry_48 + wraps_49);
				__m_count_46 = (__m_count_46 - (wraps_49 * loopM_dim_200));
				carry_47 = 1;
				
			};
			int counter_195 = __m_count_46;
			int counter_196 = carry_47;
			int counter_197 = __m_carry_48;
			__m_count_50 = (((int)0) ? 0 : (fixdenorm(__m_count_50 + ((int)1))));
			int carry_51 = 0;
			if ((((int)0) != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((loopR_dim_198 > 0) && (__m_count_50 >= loopR_dim_198))) {
				int wraps_53 = (__m_count_50 / loopR_dim_198);
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * loopR_dim_198));
				carry_51 = 1;
				
			};
			int counter_191 = __m_count_50;
			int counter_192 = carry_51;
			int counter_193 = __m_carry_52;
			t_sample fold_62 = fold(in1, (-1), ((int)0));
			t_sample fold_81 = fold(in2, (-1), ((int)0));
			t_sample phasor_32 = __m_phasor_54(((int)1), samples_to_seconds);
			t_sample mul_29 = (phasor_32 * ((t_sample)0.2));
			t_sample selector_65 = ((choice_55 >= 3) ? gt_68 : ((choice_55 >= 2) ? ((int)1) : ((choice_55 >= 1) ? gt_71 : 0)));
			t_sample selector_116 = ((choice_56 >= 3) ? gt_68 : ((choice_56 >= 2) ? ((int)1) : ((choice_56 >= 1) ? gt_71 : 0)));
			t_sample selector_86 = ((choice_57 >= 3) ? gt_68 : ((choice_57 >= 2) ? ((int)1) : ((choice_57 >= 1) ? gt_71 : 0)));
			t_sample mix_662 = (m_history_15 + (((t_sample)0.0042742627044161) * (m_ctrl_23 - m_history_15)));
			t_sample mix_319 = mix_662;
			t_sample mix_663 = (m_history_14 + (((t_sample)0.0042742627044161) * (mix_319 - m_history_14)));
			t_sample mix_315 = mix_663;
			t_sample mix_664 = (m_history_13 + (((t_sample)0.0042742627044161) * (mix_315 - m_history_13)));
			t_sample mix_317 = mix_664;
			t_sample gen_258 = mix_317;
			t_sample history_250_next_313 = fixdenorm(mix_319);
			t_sample history_248_next_314 = fixdenorm(mix_315);
			t_sample history_246_next_322 = fixdenorm(mix_317);
			t_sample sub_668 = (gen_258 - ((int)0));
			t_sample scale_665 = ((safepow((sub_668 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_91 = fabs(scale_665);
			t_sample sub_672 = (abs_91 - ((int)1));
			t_sample scale_669 = ((safepow((sub_672 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_40 = (scale_669 > ((int)2));
			t_sample mix_673 = (m_history_12 + (((t_sample)0.0042742627044161) * (m_ctrl_27 - m_history_12)));
			t_sample mix_332 = mix_673;
			t_sample mix_674 = (m_history_11 + (((t_sample)0.0042742627044161) * (mix_332 - m_history_11)));
			t_sample mix_328 = mix_674;
			t_sample mix_675 = (m_history_10 + (((t_sample)0.0042742627044161) * (mix_328 - m_history_10)));
			t_sample mix_330 = mix_675;
			t_sample gen_260 = mix_330;
			t_sample history_250_next_326 = fixdenorm(mix_332);
			t_sample history_248_next_327 = fixdenorm(mix_328);
			t_sample history_246_next_335 = fixdenorm(mix_330);
			__m_slide_58 = fixdenorm((__m_slide_58 + (((gen_260 > __m_slide_58) ? iup_59 : idown_60) * (gen_260 - __m_slide_58))));
			t_sample slide_93 = __m_slide_58;
			t_sample mix_676 = (m_history_9 + (((t_sample)0.0042742627044161) * (m_ctrl_28 - m_history_9)));
			t_sample mix_348 = mix_676;
			t_sample mix_677 = (m_history_8 + (((t_sample)0.0042742627044161) * (mix_348 - m_history_8)));
			t_sample mix_346 = mix_677;
			t_sample mix_678 = (m_history_7 + (((t_sample)0.0042742627044161) * (mix_346 - m_history_7)));
			t_sample mix_347 = mix_678;
			t_sample gen_256 = mix_347;
			t_sample history_250_next_339 = fixdenorm(mix_348);
			t_sample history_248_next_345 = fixdenorm(mix_346);
			t_sample history_246_next_341 = fixdenorm(mix_347);
			t_sample sub_682 = (gen_256 - ((int)0));
			t_sample scale_679 = ((safepow((sub_682 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_129 = ((scale_679 >= ((int)0)) ? scale_679 : 0);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((gtep_129 > __m_slide_61) ? iup_62 : idown_63) * (gtep_129 - __m_slide_61))));
			t_sample slide_126 = __m_slide_61;
			t_sample ceil_50 = ceil(slide_126);
			t_sample switch_55 = (neq_46 ? ceil_50 : ((int)1));
			t_sample mul_54 = (counter_191 * switch_55);
			t_sample switch_114 = (selector_116 ? mul_54 : ((int)0));
			t_sample mul_53 = (counter_191 * switch_55);
			t_sample switch_111 = (selector_116 ? mul_53 : ((int)0));
			t_sample add_26 = (fold_81 + gtep_129);
			t_sample sub_686 = (gen_256 - ((int)0));
			t_sample scale_683 = ((safepow((sub_686 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_134 = fabs(scale_683);
			t_sample sub_690 = (abs_134 - ((int)1));
			t_sample scale_687 = ((safepow((sub_690 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			t_sample add_24 = (add_26 + scale_687);
			t_sample sub_21 = (add_24 - ((t_sample)0.3));
			t_sample switch_88 = (selector_86 ? rsub_87 : sub_21);
			t_sample out4 = switch_88;
			__m_slide_64 = fixdenorm((__m_slide_64 + (((scale_687 > __m_slide_64) ? iup_65 : idown_66) * (scale_687 - __m_slide_64))));
			t_sample slide_127 = __m_slide_64;
			t_sample ceil_51 = ceil(slide_127);
			t_sample switch_57 = (neq_46 ? ceil_51 : ((int)1));
			t_sample mul_56 = (switch_57 * counter_195);
			t_sample switch_112 = (selector_116 ? mul_56 : ((int)0));
			t_sample mul_58 = (switch_57 * counter_195);
			t_sample switch_113 = (selector_116 ? mul_58 : ((int)0));
			t_sample sub_694 = (gen_256 - ((int)0));
			t_sample scale_691 = ((safepow((sub_694 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_131 = ((scale_691 <= ((int)0)) ? scale_691 : 0);
			t_sample abs_132 = fabs(ltep_131);
			__m_slide_67 = fixdenorm((__m_slide_67 + (((abs_132 > __m_slide_67) ? iup_68 : idown_69) * (abs_132 - __m_slide_67))));
			t_sample slide_128 = __m_slide_67;
			t_sample ceil_52 = ceil(slide_128);
			t_sample switch_60 = (neq_46 ? ceil_52 : ((int)1));
			t_sample mul_59 = (switch_60 * counter_203);
			t_sample switch_115 = (selector_116 ? mul_59 : ((int)0));
			t_sample mul_61 = (switch_60 * counter_203);
			t_sample switch_117 = (selector_116 ? mul_61 : ((int)0));
			t_sample add_25 = (fold_62 + abs_132);
			t_sample add_23 = (add_25 + scale_687);
			t_sample sub_22 = (add_23 - ((t_sample)0.3));
			t_sample switch_67 = (selector_65 ? rsub_66 : sub_22);
			t_sample out3 = switch_67;
			t_sample mix_695 = (m_history_6 + (((t_sample)0.0042742627044161) * (m_ctrl_34 - m_history_6)));
			t_sample mix_361 = mix_695;
			t_sample mix_696 = (m_history_5 + (((t_sample)0.0042742627044161) * (mix_361 - m_history_5)));
			t_sample mix_359 = mix_696;
			t_sample mix_697 = (m_history_4 + (((t_sample)0.0042742627044161) * (mix_359 - m_history_4)));
			t_sample mix_360 = mix_697;
			t_sample gen_257 = mix_360;
			t_sample history_250_next_352 = fixdenorm(mix_361);
			t_sample history_248_next_358 = fixdenorm(mix_359);
			t_sample history_246_next_354 = fixdenorm(mix_360);
			t_sample sub_701 = (gen_257 - ((int)0));
			t_sample scale_698 = ((safepow((sub_701 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_75 = fabs(scale_698);
			t_sample sub_705 = (abs_75 - ((int)1));
			t_sample scale_702 = ((safepow((sub_705 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_35 = (scale_702 > ((int)2));
			t_sample mix_706 = (m_history_3 + (((t_sample)0.0042742627044161) * (m_ctrl_29 - m_history_3)));
			t_sample mix_374 = mix_706;
			t_sample mix_707 = (m_history_2 + (((t_sample)0.0042742627044161) * (mix_374 - m_history_2)));
			t_sample mix_372 = mix_707;
			t_sample mix_708 = (m_history_1 + (((t_sample)0.0042742627044161) * (mix_372 - m_history_1)));
			t_sample mix_373 = mix_708;
			t_sample gen_259 = mix_373;
			t_sample history_250_next_365 = fixdenorm(mix_374);
			t_sample history_248_next_371 = fixdenorm(mix_372);
			t_sample history_246_next_367 = fixdenorm(mix_373);
			t_sample sub_712 = (gen_259 - ((int)0));
			t_sample scale_709 = ((safepow((sub_712 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_79 = fabs(scale_709);
			t_sample sub_716 = (abs_79 - ((int)1));
			t_sample scale_713 = ((safepow((sub_716 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int lt_34 = (scale_713 < ((int)2));
			int gt_5 = (scale_709 > ((int)0));
			t_sample mul_2 = (scale_713 * (-1));
			t_sample switch_9 = (gt_5 ? scale_713 : mul_2);
			t_sample rdiv_182 = safediv(((int)1), switch_9);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((rdiv_182 > __m_slide_70) ? iup_71 : idown_72) * (rdiv_182 - __m_slide_70))));
			t_sample slide_77 = __m_slide_70;
			t_sample phasor_183 = __m_phasor_73(slide_77, samples_to_seconds);
			t_sample mul_180 = (phasor_183 * ((int)2));
			t_sample sub_179 = (mul_180 - ((int)1));
			t_sample cos_178 = cos(sub_179);
			t_sample sub_177 = (cos_178 - ((t_sample)0.5));
			t_sample mul_176 = (sub_177 * ((int)10));
			t_sample clamp_175 = ((mul_176 <= ((int)0)) ? ((int)0) : ((mul_176 >= ((int)1)) ? ((int)1) : mul_176));
			t_sample fold_168 = fold(phasor_183, ((int)0), ((int)1));
			double sample_index_74 = (fold_168 * loopM_dim);
			int index_trunc_75 = fixnan(floor(sample_index_74));
			double index_fract_76 = (sample_index_74 - index_trunc_75);
			int index_trunc_77 = (index_trunc_75 - 1);
			int index_trunc_78 = (index_trunc_75 + 1);
			int index_trunc_79 = (index_trunc_75 + 2);
			int index_wrap_80 = ((index_trunc_77 < 0) ? ((loopM_dim - 1) + ((index_trunc_77 + 1) % loopM_dim)) : (index_trunc_77 % loopM_dim));
			int index_wrap_81 = ((index_trunc_75 < 0) ? ((loopM_dim - 1) + ((index_trunc_75 + 1) % loopM_dim)) : (index_trunc_75 % loopM_dim));
			int index_wrap_82 = ((index_trunc_78 < 0) ? ((loopM_dim - 1) + ((index_trunc_78 + 1) % loopM_dim)) : (index_trunc_78 % loopM_dim));
			int index_wrap_83 = ((index_trunc_79 < 0) ? ((loopM_dim - 1) + ((index_trunc_79 + 1) % loopM_dim)) : (index_trunc_79 % loopM_dim));
			// phase loopM channel 1;
			double read_loopM_85 = (chan_ignore_84 ? 0 : m_loopM_25.read(index_wrap_80, 1));
			double read_loopM_86 = (chan_ignore_84 ? 0 : m_loopM_25.read(index_wrap_81, 1));
			double read_loopM_87 = (chan_ignore_84 ? 0 : m_loopM_25.read(index_wrap_82, 1));
			double read_loopM_88 = (chan_ignore_84 ? 0 : m_loopM_25.read(index_wrap_83, 1));
			double readinterp_89 = spline_interp(index_fract_76, read_loopM_85, read_loopM_86, read_loopM_87, read_loopM_88);
			t_sample sample_loopM_171 = readinterp_89;
			t_sample index_loopM_172 = sample_index_74;
			t_sample mul_166 = (sample_loopM_171 * clamp_175);
			t_sample selector_14 = ((choice_90 >= 3) ? in2 : ((choice_90 >= 2) ? in2 : ((choice_90 >= 1) ? mul_166 : 0)));
			t_sample selector_12 = ((choice_91 >= 3) ? mul_166 : ((choice_91 >= 2) ? in2 : ((choice_91 >= 1) ? mul_166 : 0)));
			double sample_index_92 = (fold_168 * loopM_dim);
			int index_trunc_93 = fixnan(floor(sample_index_92));
			double index_fract_94 = (sample_index_92 - index_trunc_93);
			int index_trunc_95 = (index_trunc_93 - 1);
			int index_trunc_96 = (index_trunc_93 + 1);
			int index_trunc_97 = (index_trunc_93 + 2);
			int index_wrap_98 = ((index_trunc_95 < 0) ? ((loopM_dim - 1) + ((index_trunc_95 + 1) % loopM_dim)) : (index_trunc_95 % loopM_dim));
			int index_wrap_99 = ((index_trunc_93 < 0) ? ((loopM_dim - 1) + ((index_trunc_93 + 1) % loopM_dim)) : (index_trunc_93 % loopM_dim));
			int index_wrap_100 = ((index_trunc_96 < 0) ? ((loopM_dim - 1) + ((index_trunc_96 + 1) % loopM_dim)) : (index_trunc_96 % loopM_dim));
			int index_wrap_101 = ((index_trunc_97 < 0) ? ((loopM_dim - 1) + ((index_trunc_97 + 1) % loopM_dim)) : (index_trunc_97 % loopM_dim));
			// phase loopM channel 1;
			double read_loopM_102 = m_loopM_25.read(index_wrap_98, 0);
			double read_loopM_103 = m_loopM_25.read(index_wrap_99, 0);
			double read_loopM_104 = m_loopM_25.read(index_wrap_100, 0);
			double read_loopM_105 = m_loopM_25.read(index_wrap_101, 0);
			double readinterp_106 = spline_interp(index_fract_94, read_loopM_102, read_loopM_103, read_loopM_104, read_loopM_105);
			t_sample sample_loopM_173 = readinterp_106;
			t_sample index_loopM_174 = sample_index_92;
			t_sample mul_167 = (sample_loopM_173 * clamp_175);
			t_sample selector_17 = ((choice_107 >= 3) ? mul_167 : ((choice_107 >= 2) ? in1 : ((choice_107 >= 1) ? mul_167 : 0)));
			t_sample selector_19 = ((choice_108 >= 3) ? in1 : ((choice_108 >= 2) ? in1 : ((choice_108 >= 1) ? mul_167 : 0)));
			int gt_6 = (scale_665 > ((int)0));
			t_sample mul_3 = (scale_669 * (-1));
			t_sample switch_8 = (gt_6 ? scale_669 : mul_3);
			t_sample rdiv_229 = safediv(((int)1), switch_8);
			__m_slide_109 = fixdenorm((__m_slide_109 + (((rdiv_229 > __m_slide_109) ? iup_110 : idown_111) * (rdiv_229 - __m_slide_109))));
			t_sample slide_89 = __m_slide_109;
			t_sample phasor_230 = __m_phasor_112(slide_89, samples_to_seconds);
			t_sample mul_218 = (phasor_230 * ((int)2));
			t_sample sub_217 = (mul_218 - ((int)1));
			t_sample cos_216 = cos(sub_217);
			t_sample sub_215 = (cos_216 - ((t_sample)0.5));
			t_sample mul_214 = (sub_215 * ((int)10));
			t_sample clamp_213 = ((mul_214 <= ((int)0)) ? ((int)0) : ((mul_214 >= ((int)1)) ? ((int)1) : mul_214));
			t_sample fold_220 = fold(phasor_230, ((int)0), ((int)1));
			double sample_index_113 = (fold_220 * loopL_dim);
			int index_trunc_114 = fixnan(floor(sample_index_113));
			double index_fract_115 = (sample_index_113 - index_trunc_114);
			int index_trunc_116 = (index_trunc_114 - 1);
			int index_trunc_117 = (index_trunc_114 + 1);
			int index_trunc_118 = (index_trunc_114 + 2);
			int index_wrap_119 = ((index_trunc_116 < 0) ? ((loopL_dim - 1) + ((index_trunc_116 + 1) % loopL_dim)) : (index_trunc_116 % loopL_dim));
			int index_wrap_120 = ((index_trunc_114 < 0) ? ((loopL_dim - 1) + ((index_trunc_114 + 1) % loopL_dim)) : (index_trunc_114 % loopL_dim));
			int index_wrap_121 = ((index_trunc_117 < 0) ? ((loopL_dim - 1) + ((index_trunc_117 + 1) % loopL_dim)) : (index_trunc_117 % loopL_dim));
			int index_wrap_122 = ((index_trunc_118 < 0) ? ((loopL_dim - 1) + ((index_trunc_118 + 1) % loopL_dim)) : (index_trunc_118 % loopL_dim));
			// phase loopL channel 1;
			double read_loopL_124 = (chan_ignore_123 ? 0 : m_loopL_24.read(index_wrap_119, 1));
			double read_loopL_125 = (chan_ignore_123 ? 0 : m_loopL_24.read(index_wrap_120, 1));
			double read_loopL_126 = (chan_ignore_123 ? 0 : m_loopL_24.read(index_wrap_121, 1));
			double read_loopL_127 = (chan_ignore_123 ? 0 : m_loopL_24.read(index_wrap_122, 1));
			double readinterp_128 = spline_interp(index_fract_115, read_loopL_124, read_loopL_125, read_loopL_126, read_loopL_127);
			t_sample sample_loopL_224 = readinterp_128;
			t_sample index_loopL_225 = sample_index_113;
			t_sample mul_212 = (sample_loopL_224 * clamp_213);
			t_sample mix_721 = (selector_14 + (slide_93 * (mul_212 - selector_14)));
			t_sample clamp_99 = ((mix_721 <= min_129) ? min_129 : ((mix_721 >= ((int)1)) ? ((int)1) : mix_721));
			t_sample mul_122 = (clamp_99 * slide_128);
			t_sample clamp_102 = ((mul_122 <= min_130) ? min_130 : ((mul_122 >= ((int)1)) ? ((int)1) : mul_122));
			int index_trunc_132 = fixnan(floor(switch_115));
			int index_wrap_133 = ((index_trunc_132 < 0) ? ((loopL_dim - 1) + ((index_trunc_132 + 1) % loopL_dim)) : (index_trunc_132 % loopL_dim));
			if ((!chan_ignore_131)) {
				m_loopL_24.write((clamp_102 + (m_loopL_24.read(index_wrap_133, ((int)1)) * slide_141)), index_wrap_133, ((int)1));
				
			};
			t_sample selector_13 = ((choice_134 >= 3) ? mul_212 : ((choice_134 >= 2) ? in2 : ((choice_134 >= 1) ? in2 : 0)));
			t_sample mix_722 = (selector_13 + (slide_93 * (mul_166 - selector_13)));
			t_sample clamp_97 = ((mix_722 <= min_135) ? min_135 : ((mix_722 >= ((int)1)) ? ((int)1) : mix_722));
			t_sample mul_121 = (clamp_97 * slide_127);
			t_sample clamp_101 = ((mul_121 <= min_136) ? min_136 : ((mul_121 >= ((int)1)) ? ((int)1) : mul_121));
			int index_trunc_138 = fixnan(floor(switch_112));
			int index_wrap_139 = ((index_trunc_138 < 0) ? ((loopM_dim - 1) + ((index_trunc_138 + 1) % loopM_dim)) : (index_trunc_138 % loopM_dim));
			if ((!chan_ignore_137)) {
				m_loopM_25.write((clamp_101 + (m_loopM_25.read(index_wrap_139, ((int)1)) * slide_141)), index_wrap_139, ((int)1));
				
			};
			double sample_index_140 = (fold_220 * loopL_dim);
			int index_trunc_141 = fixnan(floor(sample_index_140));
			double index_fract_142 = (sample_index_140 - index_trunc_141);
			int index_trunc_143 = (index_trunc_141 - 1);
			int index_trunc_144 = (index_trunc_141 + 1);
			int index_trunc_145 = (index_trunc_141 + 2);
			int index_wrap_146 = ((index_trunc_143 < 0) ? ((loopL_dim - 1) + ((index_trunc_143 + 1) % loopL_dim)) : (index_trunc_143 % loopL_dim));
			int index_wrap_147 = ((index_trunc_141 < 0) ? ((loopL_dim - 1) + ((index_trunc_141 + 1) % loopL_dim)) : (index_trunc_141 % loopL_dim));
			int index_wrap_148 = ((index_trunc_144 < 0) ? ((loopL_dim - 1) + ((index_trunc_144 + 1) % loopL_dim)) : (index_trunc_144 % loopL_dim));
			int index_wrap_149 = ((index_trunc_145 < 0) ? ((loopL_dim - 1) + ((index_trunc_145 + 1) % loopL_dim)) : (index_trunc_145 % loopL_dim));
			// phase loopL channel 1;
			double read_loopL_150 = m_loopL_24.read(index_wrap_146, 0);
			double read_loopL_151 = m_loopL_24.read(index_wrap_147, 0);
			double read_loopL_152 = m_loopL_24.read(index_wrap_148, 0);
			double read_loopL_153 = m_loopL_24.read(index_wrap_149, 0);
			double readinterp_154 = spline_interp(index_fract_142, read_loopL_150, read_loopL_151, read_loopL_152, read_loopL_153);
			t_sample sample_loopL_226 = readinterp_154;
			t_sample index_loopL_227 = sample_index_140;
			t_sample mul_211 = (sample_loopL_226 * clamp_213);
			t_sample mix_723 = (selector_19 + (slide_93 * (mul_211 - selector_19)));
			t_sample clamp_107 = ((mix_723 <= min_155) ? min_155 : ((mix_723 >= ((int)1)) ? ((int)1) : mix_723));
			t_sample mul_125 = (clamp_107 * slide_128);
			t_sample clamp_105 = ((mul_125 <= min_156) ? min_156 : ((mul_125 >= ((int)1)) ? ((int)1) : mul_125));
			int index_trunc_157 = fixnan(floor(switch_117));
			int index_wrap_158 = ((index_trunc_157 < 0) ? ((loopL_dim - 1) + ((index_trunc_157 + 1) % loopL_dim)) : (index_trunc_157 % loopL_dim));
			m_loopL_24.write((clamp_105 + (m_loopL_24.read(index_wrap_158, 0) * slide_141)), index_wrap_158, 0);
			t_sample selector_18 = ((choice_159 >= 3) ? mul_211 : ((choice_159 >= 2) ? in1 : ((choice_159 >= 1) ? in1 : 0)));
			t_sample mix_724 = (selector_18 + (slide_93 * (mul_167 - selector_18)));
			t_sample clamp_106 = ((mix_724 <= min_160) ? min_160 : ((mix_724 >= ((int)1)) ? ((int)1) : mix_724));
			t_sample mul_124 = (clamp_106 * slide_127);
			t_sample clamp_104 = ((mul_124 <= min_161) ? min_161 : ((mul_124 >= ((int)1)) ? ((int)1) : mul_124));
			int index_trunc_162 = fixnan(floor(switch_113));
			int index_wrap_163 = ((index_trunc_162 < 0) ? ((loopM_dim - 1) + ((index_trunc_162 + 1) % loopM_dim)) : (index_trunc_162 % loopM_dim));
			m_loopM_25.write((clamp_104 + (m_loopM_25.read(index_wrap_163, 0) * slide_141)), index_wrap_163, 0);
			int gt_4 = (scale_698 > ((int)0));
			t_sample mul_1 = (scale_702 * (-1));
			t_sample switch_7 = (gt_4 ? scale_702 : mul_1);
			t_sample rdiv_161 = safediv(((int)1), switch_7);
			__m_slide_164 = fixdenorm((__m_slide_164 + (((rdiv_161 > __m_slide_164) ? iup_165 : idown_166) * (rdiv_161 - __m_slide_164))));
			t_sample slide_73 = __m_slide_164;
			t_sample phasor_162 = __m_phasor_167(slide_73, samples_to_seconds);
			t_sample mul_159 = (phasor_162 * ((int)2));
			t_sample sub_158 = (mul_159 - ((int)1));
			t_sample cos_157 = cos(sub_158);
			t_sample sub_156 = (cos_157 - ((t_sample)0.5));
			t_sample mul_155 = (sub_156 * ((int)10));
			t_sample clamp_154 = ((mul_155 <= ((int)0)) ? ((int)0) : ((mul_155 >= ((int)1)) ? ((int)1) : mul_155));
			t_sample fold_147 = fold(phasor_162, ((int)0), ((int)1));
			double sample_index_168 = (fold_147 * loopR_dim);
			int index_trunc_169 = fixnan(floor(sample_index_168));
			double index_fract_170 = (sample_index_168 - index_trunc_169);
			int index_trunc_171 = (index_trunc_169 - 1);
			int index_trunc_172 = (index_trunc_169 + 1);
			int index_trunc_173 = (index_trunc_169 + 2);
			int index_wrap_174 = ((index_trunc_171 < 0) ? ((loopR_dim - 1) + ((index_trunc_171 + 1) % loopR_dim)) : (index_trunc_171 % loopR_dim));
			int index_wrap_175 = ((index_trunc_169 < 0) ? ((loopR_dim - 1) + ((index_trunc_169 + 1) % loopR_dim)) : (index_trunc_169 % loopR_dim));
			int index_wrap_176 = ((index_trunc_172 < 0) ? ((loopR_dim - 1) + ((index_trunc_172 + 1) % loopR_dim)) : (index_trunc_172 % loopR_dim));
			int index_wrap_177 = ((index_trunc_173 < 0) ? ((loopR_dim - 1) + ((index_trunc_173 + 1) % loopR_dim)) : (index_trunc_173 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_178 = m_loopR_36.read(index_wrap_174, 0);
			double read_loopR_179 = m_loopR_36.read(index_wrap_175, 0);
			double read_loopR_180 = m_loopR_36.read(index_wrap_176, 0);
			double read_loopR_181 = m_loopR_36.read(index_wrap_177, 0);
			double readinterp_182 = spline_interp(index_fract_170, read_loopR_178, read_loopR_179, read_loopR_180, read_loopR_181);
			t_sample sample_loopR_152 = readinterp_182;
			t_sample index_loopR_153 = sample_index_168;
			t_sample mul_146 = (sample_loopR_152 * clamp_154);
			t_sample mix_725 = (selector_17 + (slide_93 * (mul_146 - selector_17)));
			t_sample clamp_16 = ((mix_725 <= min_183) ? min_183 : ((mix_725 >= ((int)1)) ? ((int)1) : mix_725));
			t_sample mul_123 = (clamp_16 * slide_126);
			t_sample clamp_103 = ((mul_123 <= min_184) ? min_184 : ((mul_123 >= ((int)1)) ? ((int)1) : mul_123));
			int index_trunc_185 = fixnan(floor(switch_114));
			int index_wrap_186 = ((index_trunc_185 < 0) ? ((loopR_dim - 1) + ((index_trunc_185 + 1) % loopR_dim)) : (index_trunc_185 % loopR_dim));
			m_loopR_36.write((clamp_103 + (m_loopR_36.read(index_wrap_186, 0) * slide_141)), index_wrap_186, 0);
			t_sample mix_726 = (mul_211 + (((t_sample)0.5) * (mul_146 - mul_211)));
			t_sample mix_727 = (mix_726 + (((t_sample)0.33) * (mul_167 - mix_726)));
			t_sample mul_119 = (mix_727 * ((int)3));
			t_sample mix_728 = (in1 + (gen_261 * (mul_119 - in1)));
			t_sample clamp_139 = ((mix_728 <= min_187) ? min_187 : ((mix_728 >= ((int)1)) ? ((int)1) : mix_728));
			t_sample out1 = clamp_139;
			t_sample fold_83 = fold(clamp_139, (-1), ((int)0));
			t_sample abs_42 = fabs(clamp_139);
			t_sample add_41 = (abs_42 + ((t_sample)0.0001));
			t_sample rsub_43 = (((int)1) - add_41);
			t_sample mul_30 = (mul_29 * rsub_43);
			t_sample switch_33 = (lt_34 ? rsub_43 : mul_30);
			t_sample switch_44 = (gt_40 ? switch_33 : fold_83);
			t_sample out5 = switch_44;
			double sample_index_188 = (fold_147 * loopR_dim);
			int index_trunc_189 = fixnan(floor(sample_index_188));
			double index_fract_190 = (sample_index_188 - index_trunc_189);
			int index_trunc_191 = (index_trunc_189 - 1);
			int index_trunc_192 = (index_trunc_189 + 1);
			int index_trunc_193 = (index_trunc_189 + 2);
			int index_wrap_194 = ((index_trunc_191 < 0) ? ((loopR_dim - 1) + ((index_trunc_191 + 1) % loopR_dim)) : (index_trunc_191 % loopR_dim));
			int index_wrap_195 = ((index_trunc_189 < 0) ? ((loopR_dim - 1) + ((index_trunc_189 + 1) % loopR_dim)) : (index_trunc_189 % loopR_dim));
			int index_wrap_196 = ((index_trunc_192 < 0) ? ((loopR_dim - 1) + ((index_trunc_192 + 1) % loopR_dim)) : (index_trunc_192 % loopR_dim));
			int index_wrap_197 = ((index_trunc_193 < 0) ? ((loopR_dim - 1) + ((index_trunc_193 + 1) % loopR_dim)) : (index_trunc_193 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_199 = (chan_ignore_198 ? 0 : m_loopR_36.read(index_wrap_194, 1));
			double read_loopR_200 = (chan_ignore_198 ? 0 : m_loopR_36.read(index_wrap_195, 1));
			double read_loopR_201 = (chan_ignore_198 ? 0 : m_loopR_36.read(index_wrap_196, 1));
			double read_loopR_202 = (chan_ignore_198 ? 0 : m_loopR_36.read(index_wrap_197, 1));
			double readinterp_203 = spline_interp(index_fract_190, read_loopR_199, read_loopR_200, read_loopR_201, read_loopR_202);
			t_sample sample_loopR_150 = readinterp_203;
			t_sample index_loopR_151 = sample_index_188;
			t_sample mul_145 = (sample_loopR_150 * clamp_154);
			t_sample mix_729 = (selector_12 + (slide_93 * (mul_145 - selector_12)));
			t_sample clamp_95 = ((mix_729 <= min_204) ? min_204 : ((mix_729 >= ((int)1)) ? ((int)1) : mix_729));
			t_sample mul_120 = (clamp_95 * slide_126);
			t_sample clamp_100 = ((mul_120 <= min_205) ? min_205 : ((mul_120 >= ((int)1)) ? ((int)1) : mul_120));
			int index_trunc_207 = fixnan(floor(switch_111));
			int index_wrap_208 = ((index_trunc_207 < 0) ? ((loopR_dim - 1) + ((index_trunc_207 + 1) % loopR_dim)) : (index_trunc_207 % loopR_dim));
			if ((!chan_ignore_206)) {
				m_loopR_36.write((clamp_100 + (m_loopR_36.read(index_wrap_208, ((int)1)) * slide_141)), index_wrap_208, ((int)1));
				
			};
			t_sample mix_730 = (mul_212 + (((t_sample)0.5) * (mul_145 - mul_212)));
			t_sample mix_731 = (mix_730 + (((t_sample)0.33) * (mul_166 - mix_730)));
			t_sample mul_118 = (mix_731 * ((int)3));
			t_sample mix_732 = (in2 + (gen_261 * (mul_118 - in2)));
			t_sample clamp_138 = ((mix_732 <= min_209) ? min_209 : ((mix_732 >= ((int)1)) ? ((int)1) : mix_732));
			t_sample out2 = clamp_138;
			t_sample fold_82 = fold(clamp_138, (-1), ((int)0));
			t_sample abs_37 = fabs(clamp_138);
			t_sample add_36 = (abs_37 + ((t_sample)0.0001));
			t_sample rsub_38 = (((int)1) - add_36);
			t_sample mul_27 = (rsub_38 * mul_29);
			t_sample switch_28 = (lt_34 ? rsub_38 : mul_27);
			t_sample switch_39 = (gt_35 ? switch_28 : fold_82);
			t_sample out6 = switch_39;
			m_history_22 = history_270_next_274;
			m_history_21 = history_250_next_252;
			m_history_19 = history_246_next_254;
			m_history_20 = history_248_next_253;
			m_history_18 = history_250_next_307;
			m_history_16 = history_246_next_305;
			m_history_17 = history_248_next_306;
			m_history_15 = history_250_next_313;
			m_history_13 = history_246_next_322;
			m_history_14 = history_248_next_314;
			m_history_12 = history_250_next_326;
			m_history_10 = history_246_next_335;
			m_history_11 = history_248_next_327;
			m_history_9 = history_250_next_339;
			m_history_7 = history_246_next_341;
			m_history_8 = history_248_next_345;
			m_history_6 = history_250_next_352;
			m_history_4 = history_246_next_354;
			m_history_5 = history_248_next_358;
			m_history_3 = history_250_next_365;
			m_history_1 = history_246_next_367;
			m_history_2 = history_248_next_371;
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
	inline void set_ctrl2(t_param _value) {
		m_ctrl_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopL(void * _value) {
		m_loopL_24.setbuffer(_value);
	};
	inline void set_loopM(void * _value) {
		m_loopM_25.setbuffer(_value);
	};
	inline void set_ctrl1(t_param _value) {
		m_ctrl_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_28 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw1(t_param _value) {
		m_sw_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_button(t_param _value) {
		m_button_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl7(t_param _value) {
		m_ctrl_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_33 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_35 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopR(void * _value) {
		m_loopR_36.setbuffer(_value);
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
		case 0: *value = self->m_button_31; break;
		case 1: *value = self->m_ctrl_26; break;
		case 2: *value = self->m_ctrl_23; break;
		case 3: *value = self->m_ctrl_29; break;
		case 4: *value = self->m_ctrl_28; break;
		case 5: *value = self->m_ctrl_27; break;
		case 6: *value = self->m_ctrl_34; break;
		case 7: *value = self->m_ctrl_32; break;
		case 8: *value = self->m_gate_33; break;
		
		
		
		case 12: *value = self->m_sw_30; break;
		case 13: *value = self->m_sw_35; break;
		
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
	// initialize parameter 0 ("m_button_31")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 1 ("m_ctrl_26")
	pi = self->__commonstate.params + 1;
	pi->name = "ctrl1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_26;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 2 ("m_ctrl_23")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_23;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 3 ("m_ctrl_29")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_28")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_28;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_27")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
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
	// initialize parameter 6 ("m_ctrl_34")
	pi = self->__commonstate.params + 6;
	pi->name = "ctrl6";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 7 ("m_ctrl_32")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_33")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_33;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loopL_24")
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
	// initialize parameter 10 ("m_loopM_25")
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
	// initialize parameter 11 ("m_loopR_36")
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
	// initialize parameter 12 ("m_sw_30")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_30;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_35")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_35;
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
