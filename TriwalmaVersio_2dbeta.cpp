#include "TriwalmaVersio_2dbeta.h"

namespace TriwalmaVersio_2dbeta {

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
	Data m_loopR_28;
	Data m_loopM_36;
	Data m_loopL_33;
	Delta __m_delta_37;
	Phasor __m_phasor_156;
	Phasor __m_phasor_75;
	Phasor __m_phasor_54;
	Phasor __m_phasor_121;
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
	t_sample m_sw_34;
	t_sample m_ctrl_35;
	t_sample m_history_5;
	t_sample __m_count_50;
	t_sample samples_to_seconds;
	t_sample __m_slide_72;
	t_sample samplerate;
	t_sample __m_slide_118;
	t_sample __m_carry_52;
	t_sample __m_slide_67;
	t_sample __m_slide_61;
	t_sample __m_slide_64;
	t_sample m_history_1;
	t_sample __m_slide_55;
	t_sample m_history_7;
	t_sample m_sw_32;
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
	t_sample m_ctrl_31;
	t_sample m_history_19;
	t_sample m_history_21;
	t_sample __m_slide_153;
	t_sample m_history_6;
	t_sample m_button_29;
	t_sample m_history_20;
	t_sample m_ctrl_26;
	t_sample m_ctrl_24;
	t_sample m_ctrl_25;
	t_sample m_history_22;
	t_sample m_ctrl_23;
	t_sample m_gate_27;
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
		m_ctrl_24 = ((int)0);
		m_ctrl_25 = ((int)0);
		m_ctrl_26 = ((int)0);
		m_gate_27 = ((int)0);
		m_loopR_28.reset("loopR", ((int)192000), ((int)2));
		m_button_29 = ((int)0);
		m_ctrl_30 = ((int)0);
		m_ctrl_31 = ((int)0);
		m_sw_32 = ((int)0);
		m_loopL_33.reset("loopL", ((int)192000), ((int)2));
		m_sw_34 = ((int)0);
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
		__m_slide_61 = 0;
		__m_slide_64 = 0;
		__m_slide_67 = 0;
		__m_slide_72 = 0;
		__m_phasor_75.reset(0);
		__m_slide_118 = 0;
		__m_phasor_121.reset(0);
		__m_slide_153 = 0;
		__m_phasor_156.reset(0);
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
		int loopM_dim_27128 = loopM_dim;
		int loopL_dim = m_loopL_33.dim;
		int loopL_channels = m_loopL_33.channels;
		int loopL_dim_27136 = loopL_dim;
		int loopR_dim = m_loopR_28.dim;
		int loopR_channels = m_loopR_28.channels;
		int loopR_dim_27126 = loopR_dim;
		int or_27205 = (m_gate_27 || m_button_29);
		int gt_26998 = (or_27205 > ((int)0));
		t_sample iup_44 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_45 = (1 / maximum(1, abs(((int)4000))));
		int eq_27168 = (m_sw_34 == ((int)0));
		samples_to_seconds = (1 / samplerate);
		t_sample iup_56 = (1 / maximum(1, abs(((int)3000))));
		t_sample idown_57 = (1 / maximum(1, abs(((int)3000))));
		int eq_27172 = (m_sw_34 == ((t_sample)0.5));
		t_sample switch_27171 = (eq_27172 ? ((int)0) : m_sw_34);
		t_sample switch_27169 = (eq_27168 ? ((t_sample)0.5) : switch_27171);
		t_sample sub_45443 = (switch_27169 - ((int)0));
		t_sample scale_45440 = ((safepow((sub_45443 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_58 = int(scale_45440);
		t_sample choice_59 = int(scale_45440);
		t_sample choice_60 = int(scale_45440);
		int neq_26972 = (scale_45440 != ((int)2));
		t_sample iup_62 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_63 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_65 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_66 = (1 / maximum(1, abs(((int)4000))));
		t_sample iup_68 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_69 = (1 / maximum(1, abs(((int)4000))));
		int eq_27162 = (m_sw_32 == ((int)0));
		int eq_27166 = (m_sw_32 == ((t_sample)0.5));
		t_sample switch_27165 = (eq_27166 ? ((int)0) : m_sw_32);
		t_sample switch_27163 = (eq_27162 ? ((t_sample)0.5) : switch_27165);
		t_sample sub_45499 = (switch_27163 - ((int)0));
		t_sample scale_45496 = ((safepow((sub_45499 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_70 = int(scale_45496);
		t_sample choice_71 = int(scale_45496);
		t_sample iup_73 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_74 = (1 / maximum(1, abs(((int)4000))));
		int min_91 = (-1);
		int min_92 = (-1);
		t_sample choice_95 = int(scale_45496);
		bool chan_ignore_106 = ((1 < 0) || (1 >= loopM_channels));
		int min_112 = (-1);
		int min_113 = (-1);
		bool chan_ignore_114 = ((((int)1) < 0) || (((int)1) >= loopM_channels));
		t_sample choice_117 = int(scale_45496);
		t_sample iup_119 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_120 = (1 / maximum(1, abs(((int)4000))));
		bool chan_ignore_147 = ((1 < 0) || (1 >= loopR_channels));
		t_sample iup_154 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_155 = (1 / maximum(1, abs(((int)4000))));
		int min_172 = (-1);
		int min_173 = (-1);
		t_sample choice_176 = int(scale_45496);
		int min_177 = (-1);
		int min_178 = (-1);
		int min_181 = (-1);
		bool chan_ignore_192 = ((1 < 0) || (1 >= loopL_channels));
		int min_198 = (-1);
		int min_199 = (-1);
		bool chan_ignore_200 = ((((int)1) < 0) || (((int)1) >= loopL_channels));
		int min_203 = (-1);
		t_sample choice_204 = int(scale_45496);
		int min_205 = (-1);
		int min_206 = (-1);
		bool chan_ignore_207 = ((((int)1) < 0) || (((int)1) >= loopR_channels));
		// the main sample loop;
		while ((__n--)) {
			const t_sample in1 = (*(__in1++));
			const t_sample in2 = (*(__in2++));
			t_sample out8 = ((int)0);
			t_sample out10 = ((int)0);
			t_sample out9 = ((int)0);
			t_sample out7 = ((int)0);
			int delta_27201 = __m_delta_37(or_27205);
			int gtep_27200 = ((delta_27201 >= ((int)1)) ? delta_27201 : 0);
			t_sample plusequals_27199 = __m_pluseq_38.post(gtep_27200, m_history_22, 0);
			t_sample gen_27204 = plusequals_27199;
			int eq_27197 = (plusequals_27199 == ((int)2));
			t_sample history_27198_next_27202 = fixdenorm(eq_27197);
			int gt_26995 = (gen_27204 > ((int)0));
			__m_count_39 = (((int)0) ? 0 : (fixdenorm(__m_count_39 + ((int)1))));
			int carry_40 = 0;
			if ((((int)0) != 0)) {
				__m_count_39 = 0;
				__m_carry_41 = 0;
				
			} else if (((loopM_dim_27128 > 0) && (__m_count_39 >= loopM_dim_27128))) {
				int wraps_42 = (__m_count_39 / loopM_dim_27128);
				__m_carry_41 = (__m_carry_41 + wraps_42);
				__m_count_39 = (__m_count_39 - (wraps_42 * loopM_dim_27128));
				carry_40 = 1;
				
			};
			int counter_27123 = __m_count_39;
			int counter_27124 = carry_40;
			int counter_27125 = __m_carry_41;
			t_sample mix_45427 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_ctrl_23 - m_history_21)));
			t_sample mix_27177 = mix_45427;
			t_sample mix_45428 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_27177 - m_history_20)));
			t_sample mix_27175 = mix_45428;
			t_sample mix_45429 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_27175 - m_history_19)));
			t_sample mix_27173 = mix_45429;
			t_sample gen_27183 = mix_27173;
			t_sample history_27178_next_27180 = fixdenorm(mix_27177);
			t_sample history_27176_next_27181 = fixdenorm(mix_27175);
			t_sample history_27174_next_27182 = fixdenorm(mix_27173);
			t_sample sub_45433 = (gen_27183 - ((int)0));
			t_sample scale_45430 = ((safepow((sub_45433 * ((t_sample)1)), ((int)1)) * ((t_sample)0.9)) + ((int)0));
			__m_slide_43 = fixdenorm((__m_slide_43 + (((scale_45430 > __m_slide_43) ? iup_44 : idown_45) * (scale_45430 - __m_slide_43))));
			t_sample slide_27069 = __m_slide_43;
			t_sample mix_45434 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_ctrl_35 - m_history_18)));
			t_sample mix_45265 = mix_45434;
			t_sample mix_45435 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_45265 - m_history_17)));
			t_sample mix_45264 = mix_45435;
			t_sample mix_45436 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_45264 - m_history_16)));
			t_sample mix_45263 = mix_45436;
			t_sample gen_27189 = mix_45263;
			t_sample history_27178_next_45259 = fixdenorm(mix_45265);
			t_sample history_27176_next_45267 = fixdenorm(mix_45264);
			t_sample history_27174_next_45261 = fixdenorm(mix_45263);
			__m_count_46 = (((int)0) ? 0 : (fixdenorm(__m_count_46 + ((int)1))));
			int carry_47 = 0;
			if ((((int)0) != 0)) {
				__m_count_46 = 0;
				__m_carry_48 = 0;
				
			} else if (((loopR_dim_27126 > 0) && (__m_count_46 >= loopR_dim_27126))) {
				int wraps_49 = (__m_count_46 / loopR_dim_27126);
				__m_carry_48 = (__m_carry_48 + wraps_49);
				__m_count_46 = (__m_count_46 - (wraps_49 * loopR_dim_27126));
				carry_47 = 1;
				
			};
			int counter_27119 = __m_count_46;
			int counter_27120 = carry_47;
			int counter_27121 = __m_carry_48;
			t_sample abs_26991 = fabs(in1);
			t_sample add_26990 = (abs_26991 + ((t_sample)0.0001));
			t_sample rsub_26993 = (((int)1) - add_26990);
			__m_count_50 = (((int)0) ? 0 : (fixdenorm(__m_count_50 + ((int)1))));
			int carry_51 = 0;
			if ((((int)0) != 0)) {
				__m_count_50 = 0;
				__m_carry_52 = 0;
				
			} else if (((loopL_dim_27136 > 0) && (__m_count_50 >= loopL_dim_27136))) {
				int wraps_53 = (__m_count_50 / loopL_dim_27136);
				__m_carry_52 = (__m_carry_52 + wraps_53);
				__m_count_50 = (__m_count_50 - (wraps_53 * loopL_dim_27136));
				carry_51 = 1;
				
			};
			int counter_27131 = __m_count_50;
			int counter_27132 = carry_51;
			int counter_27133 = __m_carry_52;
			t_sample abs_27012 = fabs(in2);
			t_sample add_27011 = (abs_27012 + ((t_sample)0.0001));
			t_sample rsub_27014 = (((int)1) - add_27011);
			t_sample fold_26989 = fold(in1, (-1), ((int)0));
			t_sample fold_27008 = fold(in2, (-1), ((int)0));
			t_sample phasor_26952 = __m_phasor_54(((int)1), samples_to_seconds);
			t_sample mul_26949 = (phasor_26952 * ((t_sample)0.2));
			t_sample mix_45437 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_ctrl_24 - m_history_15)));
			t_sample mix_45274 = mix_45437;
			t_sample mix_45438 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_45274 - m_history_14)));
			t_sample mix_45272 = mix_45438;
			t_sample mix_45439 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_45272 - m_history_13)));
			t_sample mix_45279 = mix_45439;
			t_sample gen_27188 = mix_45279;
			t_sample history_27178_next_45273 = fixdenorm(mix_45274);
			t_sample history_27176_next_45280 = fixdenorm(mix_45272);
			t_sample history_27174_next_45277 = fixdenorm(mix_45279);
			__m_slide_55 = fixdenorm((__m_slide_55 + (((gen_27188 > __m_slide_55) ? iup_56 : idown_57) * (gen_27188 - __m_slide_55))));
			t_sample slide_29196 = __m_slide_55;
			t_sample selector_27044 = ((choice_58 >= 3) ? gt_26995 : ((choice_58 >= 2) ? ((int)1) : ((choice_58 >= 1) ? gt_26998 : 0)));
			t_sample selector_26992 = ((choice_59 >= 3) ? gt_26995 : ((choice_59 >= 2) ? ((int)1) : ((choice_59 >= 1) ? gt_26998 : 0)));
			t_sample selector_27013 = ((choice_60 >= 3) ? gt_26995 : ((choice_60 >= 2) ? ((int)1) : ((choice_60 >= 1) ? gt_26998 : 0)));
			t_sample mix_45444 = (m_history_12 + (((t_sample)0.0019634941468452) * (m_ctrl_31 - m_history_12)));
			t_sample mix_45287 = mix_45444;
			t_sample mix_45445 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_45287 - m_history_11)));
			t_sample mix_45285 = mix_45445;
			t_sample mix_45446 = (m_history_10 + (((t_sample)0.0019634941468452) * (mix_45285 - m_history_10)));
			t_sample mix_45292 = mix_45446;
			t_sample gen_27184 = mix_45292;
			t_sample history_27178_next_45286 = fixdenorm(mix_45287);
			t_sample history_27176_next_45293 = fixdenorm(mix_45285);
			t_sample history_27174_next_45291 = fixdenorm(mix_45292);
			t_sample sub_45450 = (gen_27184 - ((int)0));
			t_sample scale_45447 = ((safepow((sub_45450 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_27057 = ((scale_45447 >= ((int)0)) ? scale_45447 : 0);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((gtep_27057 > __m_slide_61) ? iup_62 : idown_63) * (gtep_27057 - __m_slide_61))));
			t_sample slide_27054 = __m_slide_61;
			t_sample ceil_26976 = ceil(slide_27054);
			t_sample switch_26981 = (neq_26972 ? ceil_26976 : ((int)1));
			t_sample mul_26980 = (counter_27119 * switch_26981);
			t_sample switch_27042 = (selector_27044 ? mul_26980 : ((int)0));
			t_sample mul_26979 = (counter_27119 * switch_26981);
			t_sample switch_27039 = (selector_27044 ? mul_26979 : ((int)0));
			t_sample add_26946 = (fold_27008 + gtep_27057);
			t_sample sub_45454 = (gen_27184 - ((int)0));
			t_sample scale_45451 = ((safepow((sub_45454 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_27062 = fabs(scale_45451);
			t_sample sub_45458 = (abs_27062 - ((int)1));
			t_sample scale_45455 = ((safepow((sub_45458 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_64 = fixdenorm((__m_slide_64 + (((scale_45455 > __m_slide_64) ? iup_65 : idown_66) * (scale_45455 - __m_slide_64))));
			t_sample slide_27055 = __m_slide_64;
			t_sample ceil_26977 = ceil(slide_27055);
			t_sample switch_26983 = (neq_26972 ? ceil_26977 : ((int)1));
			t_sample mul_26984 = (switch_26983 * counter_27123);
			t_sample switch_27041 = (selector_27044 ? mul_26984 : ((int)0));
			t_sample mul_26982 = (switch_26983 * counter_27123);
			t_sample switch_27040 = (selector_27044 ? mul_26982 : ((int)0));
			t_sample add_26944 = (add_26946 + scale_45455);
			t_sample sub_26941 = (add_26944 - ((t_sample)0.3));
			t_sample switch_27015 = (selector_27013 ? rsub_27014 : sub_26941);
			t_sample out4 = switch_27015;
			t_sample sub_45462 = (gen_27184 - ((int)0));
			t_sample scale_45459 = ((safepow((sub_45462 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_27059 = ((scale_45459 <= ((int)0)) ? scale_45459 : 0);
			t_sample abs_27060 = fabs(ltep_27059);
			__m_slide_67 = fixdenorm((__m_slide_67 + (((abs_27060 > __m_slide_67) ? iup_68 : idown_69) * (abs_27060 - __m_slide_67))));
			t_sample slide_27056 = __m_slide_67;
			t_sample ceil_26978 = ceil(slide_27056);
			t_sample switch_26986 = (neq_26972 ? ceil_26978 : ((int)1));
			t_sample mul_26987 = (switch_26986 * counter_27131);
			t_sample switch_27045 = (selector_27044 ? mul_26987 : ((int)0));
			t_sample mul_26985 = (switch_26986 * counter_27131);
			t_sample switch_27043 = (selector_27044 ? mul_26985 : ((int)0));
			t_sample add_26945 = (fold_26989 + abs_27060);
			t_sample add_26943 = (add_26945 + scale_45455);
			t_sample sub_26942 = (add_26943 - ((t_sample)0.3));
			t_sample switch_26994 = (selector_26992 ? rsub_26993 : sub_26942);
			t_sample out3 = switch_26994;
			t_sample mix_45463 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_ctrl_25 - m_history_9)));
			t_sample mix_45303 = mix_45463;
			t_sample mix_45464 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_45303 - m_history_8)));
			t_sample mix_45298 = mix_45464;
			t_sample mix_45465 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_45298 - m_history_7)));
			t_sample mix_45301 = mix_45465;
			t_sample gen_27185 = mix_45301;
			t_sample history_27178_next_45302 = fixdenorm(mix_45303);
			t_sample history_27176_next_45306 = fixdenorm(mix_45298);
			t_sample history_27174_next_45300 = fixdenorm(mix_45301);
			t_sample sub_45469 = (gen_27185 - ((int)0));
			t_sample scale_45466 = ((safepow((sub_45469 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_27002 = fabs(scale_45466);
			t_sample sub_45473 = (abs_27002 - ((int)1));
			t_sample scale_45470 = ((safepow((sub_45473 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_26955 = (scale_45470 > ((int)2));
			t_sample mix_45474 = (m_history_6 + (((t_sample)0.0019634941468452) * (m_ctrl_30 - m_history_6)));
			t_sample mix_45316 = mix_45474;
			t_sample mix_45475 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_45316 - m_history_5)));
			t_sample mix_45311 = mix_45475;
			t_sample mix_45476 = (m_history_4 + (((t_sample)0.0019634941468452) * (mix_45311 - m_history_4)));
			t_sample mix_45314 = mix_45476;
			t_sample gen_27186 = mix_45314;
			t_sample history_27178_next_45315 = fixdenorm(mix_45316);
			t_sample history_27176_next_45319 = fixdenorm(mix_45311);
			t_sample history_27174_next_45313 = fixdenorm(mix_45314);
			t_sample sub_45480 = (gen_27186 - ((int)0));
			t_sample scale_45477 = ((safepow((sub_45480 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_27018 = fabs(scale_45477);
			t_sample sub_45484 = (abs_27018 - ((int)1));
			t_sample scale_45481 = ((safepow((sub_45484 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_26960 = (scale_45481 > ((int)2));
			t_sample mix_45485 = (m_history_3 + (((t_sample)0.0019634941468452) * (m_ctrl_26 - m_history_3)));
			t_sample mix_45329 = mix_45485;
			t_sample mix_45486 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_45329 - m_history_2)));
			t_sample mix_45324 = mix_45486;
			t_sample mix_45487 = (m_history_1 + (((t_sample)0.0019634941468452) * (mix_45324 - m_history_1)));
			t_sample mix_45327 = mix_45487;
			t_sample gen_27187 = mix_45327;
			t_sample history_27178_next_45328 = fixdenorm(mix_45329);
			t_sample history_27176_next_45332 = fixdenorm(mix_45324);
			t_sample history_27174_next_45326 = fixdenorm(mix_45327);
			t_sample sub_45491 = (gen_27187 - ((int)0));
			t_sample scale_45488 = ((safepow((sub_45491 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_36993 = fabs(scale_45488);
			t_sample sub_45495 = (abs_36993 - ((int)1));
			t_sample scale_45492 = ((safepow((sub_45495 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int lt_26954 = (scale_45492 < ((int)2));
			t_sample selector_26938 = ((choice_70 >= 3) ? in1 : ((choice_70 >= 2) ? in1 : ((choice_70 >= 1) ? in1 : 0)));
			t_sample selector_26933 = ((choice_71 >= 3) ? in2 : ((choice_71 >= 2) ? in2 : ((choice_71 >= 1) ? in2 : 0)));
			int gt_38546 = (scale_45488 > ((int)0));
			t_sample mul_44483 = (scale_45492 * (-1));
			t_sample switch_37252 = (gt_38546 ? scale_45492 : mul_44483);
			t_sample rdiv_27110 = safediv(((int)1), switch_37252);
			__m_slide_72 = fixdenorm((__m_slide_72 + (((rdiv_27110 > __m_slide_72) ? iup_73 : idown_74) * (rdiv_27110 - __m_slide_72))));
			t_sample slide_27004 = __m_slide_72;
			t_sample phasor_27111 = __m_phasor_75(slide_27004, samples_to_seconds);
			t_sample mul_27108 = (phasor_27111 * ((int)2));
			t_sample sub_27107 = (mul_27108 - ((int)1));
			t_sample cos_27106 = cos(sub_27107);
			t_sample sub_27105 = (cos_27106 - ((t_sample)0.5));
			t_sample mul_27104 = (sub_27105 * ((int)10));
			t_sample clamp_27103 = ((mul_27104 <= ((int)0)) ? ((int)0) : ((mul_27104 >= ((int)1)) ? ((int)1) : mul_27104));
			t_sample fold_27096 = fold(phasor_27111, ((int)0), ((int)1));
			double sample_index_76 = (fold_27096 * loopM_dim);
			int index_trunc_77 = fixnan(floor(sample_index_76));
			double index_fract_78 = (sample_index_76 - index_trunc_77);
			int index_trunc_79 = (index_trunc_77 - 1);
			int index_trunc_80 = (index_trunc_77 + 1);
			int index_trunc_81 = (index_trunc_77 + 2);
			int index_wrap_82 = ((index_trunc_79 < 0) ? ((loopM_dim - 1) + ((index_trunc_79 + 1) % loopM_dim)) : (index_trunc_79 % loopM_dim));
			int index_wrap_83 = ((index_trunc_77 < 0) ? ((loopM_dim - 1) + ((index_trunc_77 + 1) % loopM_dim)) : (index_trunc_77 % loopM_dim));
			int index_wrap_84 = ((index_trunc_80 < 0) ? ((loopM_dim - 1) + ((index_trunc_80 + 1) % loopM_dim)) : (index_trunc_80 % loopM_dim));
			int index_wrap_85 = ((index_trunc_81 < 0) ? ((loopM_dim - 1) + ((index_trunc_81 + 1) % loopM_dim)) : (index_trunc_81 % loopM_dim));
			// phase loopM channel 1;
			double read_loopM_86 = m_loopM_36.read(index_wrap_82, 0);
			double read_loopM_87 = m_loopM_36.read(index_wrap_83, 0);
			double read_loopM_88 = m_loopM_36.read(index_wrap_84, 0);
			double read_loopM_89 = m_loopM_36.read(index_wrap_85, 0);
			double readinterp_90 = spline_interp(index_fract_78, read_loopM_86, read_loopM_87, read_loopM_88, read_loopM_89);
			t_sample sample_loopM_30268 = readinterp_90;
			t_sample index_loopM_30269 = sample_index_76;
			t_sample mul_27095 = (sample_loopM_30268 * clamp_27103);
			t_sample mix_45500 = (selector_26938 + (slide_29196 * (mul_27095 - selector_26938)));
			t_sample clamp_27033 = ((mix_45500 <= min_91) ? min_91 : ((mix_45500 >= ((int)1)) ? ((int)1) : mix_45500));
			t_sample mul_27052 = (clamp_27033 * slide_27055);
			t_sample clamp_27031 = ((mul_27052 <= min_92) ? min_92 : ((mul_27052 >= ((int)1)) ? ((int)1) : mul_27052));
			int index_trunc_93 = fixnan(floor(switch_27041));
			int index_wrap_94 = ((index_trunc_93 < 0) ? ((loopM_dim - 1) + ((index_trunc_93 + 1) % loopM_dim)) : (index_trunc_93 % loopM_dim));
			m_loopM_36.write((clamp_27031 + (m_loopM_36.read(index_wrap_94, 0) * slide_27069)), index_wrap_94, 0);
			t_sample selector_26939 = ((choice_95 >= 3) ? mul_27095 : ((choice_95 >= 2) ? in1 : ((choice_95 >= 1) ? mul_27095 : 0)));
			double sample_index_96 = (fold_27096 * loopM_dim);
			int index_trunc_97 = fixnan(floor(sample_index_96));
			double index_fract_98 = (sample_index_96 - index_trunc_97);
			int index_trunc_99 = (index_trunc_97 - 1);
			int index_trunc_100 = (index_trunc_97 + 1);
			int index_trunc_101 = (index_trunc_97 + 2);
			int index_wrap_102 = ((index_trunc_99 < 0) ? ((loopM_dim - 1) + ((index_trunc_99 + 1) % loopM_dim)) : (index_trunc_99 % loopM_dim));
			int index_wrap_103 = ((index_trunc_97 < 0) ? ((loopM_dim - 1) + ((index_trunc_97 + 1) % loopM_dim)) : (index_trunc_97 % loopM_dim));
			int index_wrap_104 = ((index_trunc_100 < 0) ? ((loopM_dim - 1) + ((index_trunc_100 + 1) % loopM_dim)) : (index_trunc_100 % loopM_dim));
			int index_wrap_105 = ((index_trunc_101 < 0) ? ((loopM_dim - 1) + ((index_trunc_101 + 1) % loopM_dim)) : (index_trunc_101 % loopM_dim));
			// phase loopM channel 1;
			double read_loopM_107 = (chan_ignore_106 ? 0 : m_loopM_36.read(index_wrap_102, 1));
			double read_loopM_108 = (chan_ignore_106 ? 0 : m_loopM_36.read(index_wrap_103, 1));
			double read_loopM_109 = (chan_ignore_106 ? 0 : m_loopM_36.read(index_wrap_104, 1));
			double read_loopM_110 = (chan_ignore_106 ? 0 : m_loopM_36.read(index_wrap_105, 1));
			double readinterp_111 = spline_interp(index_fract_98, read_loopM_107, read_loopM_108, read_loopM_109, read_loopM_110);
			t_sample sample_loopM_30600 = readinterp_111;
			t_sample index_loopM_30601 = sample_index_96;
			t_sample mul_27094 = (sample_loopM_30600 * clamp_27103);
			t_sample mix_45501 = (selector_26933 + (slide_29196 * (mul_27094 - selector_26933)));
			t_sample clamp_27024 = ((mix_45501 <= min_112) ? min_112 : ((mix_45501 >= ((int)1)) ? ((int)1) : mix_45501));
			t_sample mul_27049 = (clamp_27024 * slide_27055);
			t_sample clamp_27028 = ((mul_27049 <= min_113) ? min_113 : ((mul_27049 >= ((int)1)) ? ((int)1) : mul_27049));
			int index_trunc_115 = fixnan(floor(switch_27040));
			int index_wrap_116 = ((index_trunc_115 < 0) ? ((loopM_dim - 1) + ((index_trunc_115 + 1) % loopM_dim)) : (index_trunc_115 % loopM_dim));
			if ((!chan_ignore_114)) {
				m_loopM_36.write((clamp_27028 + (m_loopM_36.read(index_wrap_116, ((int)1)) * slide_27069)), index_wrap_116, ((int)1));
				
			};
			t_sample selector_26934 = ((choice_117 >= 3) ? mul_27094 : ((choice_117 >= 2) ? in2 : ((choice_117 >= 1) ? mul_27094 : 0)));
			int gt_39063 = (scale_45466 > ((int)0));
			t_sample mul_45258 = (scale_45470 * (-1));
			t_sample switch_37770 = (gt_39063 ? scale_45470 : mul_45258);
			t_sample rdiv_27089 = safediv(((int)1), switch_37770);
			__m_slide_118 = fixdenorm((__m_slide_118 + (((rdiv_27089 > __m_slide_118) ? iup_119 : idown_120) * (rdiv_27089 - __m_slide_118))));
			t_sample slide_27000 = __m_slide_118;
			t_sample phasor_27090 = __m_phasor_121(slide_27000, samples_to_seconds);
			t_sample mul_27087 = (phasor_27090 * ((int)2));
			t_sample sub_27086 = (mul_27087 - ((int)1));
			t_sample cos_27085 = cos(sub_27086);
			t_sample sub_27084 = (cos_27085 - ((t_sample)0.5));
			t_sample mul_27083 = (sub_27084 * ((int)10));
			t_sample clamp_27082 = ((mul_27083 <= ((int)0)) ? ((int)0) : ((mul_27083 >= ((int)1)) ? ((int)1) : mul_27083));
			t_sample fold_27075 = fold(phasor_27090, ((int)0), ((int)1));
			double sample_index_122 = (fold_27075 * loopR_dim);
			int index_trunc_123 = fixnan(floor(sample_index_122));
			double index_fract_124 = (sample_index_122 - index_trunc_123);
			int index_trunc_125 = (index_trunc_123 - 1);
			int index_trunc_126 = (index_trunc_123 + 1);
			int index_trunc_127 = (index_trunc_123 + 2);
			int index_wrap_128 = ((index_trunc_125 < 0) ? ((loopR_dim - 1) + ((index_trunc_125 + 1) % loopR_dim)) : (index_trunc_125 % loopR_dim));
			int index_wrap_129 = ((index_trunc_123 < 0) ? ((loopR_dim - 1) + ((index_trunc_123 + 1) % loopR_dim)) : (index_trunc_123 % loopR_dim));
			int index_wrap_130 = ((index_trunc_126 < 0) ? ((loopR_dim - 1) + ((index_trunc_126 + 1) % loopR_dim)) : (index_trunc_126 % loopR_dim));
			int index_wrap_131 = ((index_trunc_127 < 0) ? ((loopR_dim - 1) + ((index_trunc_127 + 1) % loopR_dim)) : (index_trunc_127 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_132 = m_loopR_28.read(index_wrap_128, 0);
			double read_loopR_133 = m_loopR_28.read(index_wrap_129, 0);
			double read_loopR_134 = m_loopR_28.read(index_wrap_130, 0);
			double read_loopR_135 = m_loopR_28.read(index_wrap_131, 0);
			double readinterp_136 = spline_interp(index_fract_124, read_loopR_132, read_loopR_133, read_loopR_134, read_loopR_135);
			t_sample sample_loopR_31098 = readinterp_136;
			t_sample index_loopR_31099 = sample_index_122;
			t_sample mul_27074 = (sample_loopR_31098 * clamp_27082);
			double sample_index_137 = (fold_27075 * loopR_dim);
			int index_trunc_138 = fixnan(floor(sample_index_137));
			double index_fract_139 = (sample_index_137 - index_trunc_138);
			int index_trunc_140 = (index_trunc_138 - 1);
			int index_trunc_141 = (index_trunc_138 + 1);
			int index_trunc_142 = (index_trunc_138 + 2);
			int index_wrap_143 = ((index_trunc_140 < 0) ? ((loopR_dim - 1) + ((index_trunc_140 + 1) % loopR_dim)) : (index_trunc_140 % loopR_dim));
			int index_wrap_144 = ((index_trunc_138 < 0) ? ((loopR_dim - 1) + ((index_trunc_138 + 1) % loopR_dim)) : (index_trunc_138 % loopR_dim));
			int index_wrap_145 = ((index_trunc_141 < 0) ? ((loopR_dim - 1) + ((index_trunc_141 + 1) % loopR_dim)) : (index_trunc_141 % loopR_dim));
			int index_wrap_146 = ((index_trunc_142 < 0) ? ((loopR_dim - 1) + ((index_trunc_142 + 1) % loopR_dim)) : (index_trunc_142 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_148 = (chan_ignore_147 ? 0 : m_loopR_28.read(index_wrap_143, 1));
			double read_loopR_149 = (chan_ignore_147 ? 0 : m_loopR_28.read(index_wrap_144, 1));
			double read_loopR_150 = (chan_ignore_147 ? 0 : m_loopR_28.read(index_wrap_145, 1));
			double read_loopR_151 = (chan_ignore_147 ? 0 : m_loopR_28.read(index_wrap_146, 1));
			double readinterp_152 = spline_interp(index_fract_139, read_loopR_148, read_loopR_149, read_loopR_150, read_loopR_151);
			t_sample sample_loopR_30932 = readinterp_152;
			t_sample index_loopR_30933 = sample_index_137;
			t_sample mul_27073 = (sample_loopR_30932 * clamp_27082);
			int gt_38029 = (scale_45477 > ((int)0));
			t_sample mul_43708 = (scale_45481 * (-1));
			t_sample switch_37511 = (gt_38029 ? scale_45481 : mul_43708);
			t_sample rdiv_27157 = safediv(((int)1), switch_37511);
			__m_slide_153 = fixdenorm((__m_slide_153 + (((rdiv_27157 > __m_slide_153) ? iup_154 : idown_155) * (rdiv_27157 - __m_slide_153))));
			t_sample slide_27016 = __m_slide_153;
			t_sample phasor_27158 = __m_phasor_156(slide_27016, samples_to_seconds);
			t_sample mul_27146 = (phasor_27158 * ((int)2));
			t_sample sub_27145 = (mul_27146 - ((int)1));
			t_sample cos_27144 = cos(sub_27145);
			t_sample sub_27143 = (cos_27144 - ((t_sample)0.5));
			t_sample mul_27142 = (sub_27143 * ((int)10));
			t_sample clamp_27141 = ((mul_27142 <= ((int)0)) ? ((int)0) : ((mul_27142 >= ((int)1)) ? ((int)1) : mul_27142));
			t_sample fold_27148 = fold(phasor_27158, ((int)0), ((int)1));
			double sample_index_157 = (fold_27148 * loopL_dim);
			int index_trunc_158 = fixnan(floor(sample_index_157));
			double index_fract_159 = (sample_index_157 - index_trunc_158);
			int index_trunc_160 = (index_trunc_158 - 1);
			int index_trunc_161 = (index_trunc_158 + 1);
			int index_trunc_162 = (index_trunc_158 + 2);
			int index_wrap_163 = ((index_trunc_160 < 0) ? ((loopL_dim - 1) + ((index_trunc_160 + 1) % loopL_dim)) : (index_trunc_160 % loopL_dim));
			int index_wrap_164 = ((index_trunc_158 < 0) ? ((loopL_dim - 1) + ((index_trunc_158 + 1) % loopL_dim)) : (index_trunc_158 % loopL_dim));
			int index_wrap_165 = ((index_trunc_161 < 0) ? ((loopL_dim - 1) + ((index_trunc_161 + 1) % loopL_dim)) : (index_trunc_161 % loopL_dim));
			int index_wrap_166 = ((index_trunc_162 < 0) ? ((loopL_dim - 1) + ((index_trunc_162 + 1) % loopL_dim)) : (index_trunc_162 % loopL_dim));
			// phase loopL channel 1;
			double read_loopL_167 = m_loopL_33.read(index_wrap_163, 0);
			double read_loopL_168 = m_loopL_33.read(index_wrap_164, 0);
			double read_loopL_169 = m_loopL_33.read(index_wrap_165, 0);
			double read_loopL_170 = m_loopL_33.read(index_wrap_166, 0);
			double readinterp_171 = spline_interp(index_fract_159, read_loopL_167, read_loopL_168, read_loopL_169, read_loopL_170);
			t_sample sample_loopL_30434 = readinterp_171;
			t_sample index_loopL_30435 = sample_index_157;
			t_sample mul_27139 = (sample_loopL_30434 * clamp_27141);
			t_sample mix_45502 = (selector_26939 + (slide_29196 * (mul_27139 - selector_26939)));
			t_sample clamp_27034 = ((mix_45502 <= min_172) ? min_172 : ((mix_45502 >= ((int)1)) ? ((int)1) : mix_45502));
			t_sample mul_27053 = (clamp_27034 * slide_27056);
			t_sample clamp_27032 = ((mul_27053 <= min_173) ? min_173 : ((mul_27053 >= ((int)1)) ? ((int)1) : mul_27053));
			int index_trunc_174 = fixnan(floor(switch_27045));
			int index_wrap_175 = ((index_trunc_174 < 0) ? ((loopL_dim - 1) + ((index_trunc_174 + 1) % loopL_dim)) : (index_trunc_174 % loopL_dim));
			m_loopL_33.write((clamp_27032 + (m_loopL_33.read(index_wrap_175, 0) * slide_27069)), index_wrap_175, 0);
			t_sample selector_26937 = ((choice_176 >= 3) ? mul_27139 : ((choice_176 >= 2) ? in1 : ((choice_176 >= 1) ? mul_27095 : 0)));
			t_sample mix_45503 = (selector_26937 + (slide_29196 * (mul_27074 - selector_26937)));
			t_sample clamp_26936 = ((mix_45503 <= min_177) ? min_177 : ((mix_45503 >= ((int)1)) ? ((int)1) : mix_45503));
			t_sample mul_27051 = (clamp_26936 * slide_27054);
			t_sample clamp_27030 = ((mul_27051 <= min_178) ? min_178 : ((mul_27051 >= ((int)1)) ? ((int)1) : mul_27051));
			int index_trunc_179 = fixnan(floor(switch_27042));
			int index_wrap_180 = ((index_trunc_179 < 0) ? ((loopR_dim - 1) + ((index_trunc_179 + 1) % loopR_dim)) : (index_trunc_179 % loopR_dim));
			m_loopR_28.write((clamp_27030 + (m_loopR_28.read(index_wrap_180, 0) * slide_27069)), index_wrap_180, 0);
			t_sample mix_45504 = (mul_27139 + (((t_sample)0.5) * (mul_27074 - mul_27139)));
			t_sample mix_45505 = (mix_45504 + (((t_sample)0.33) * (mul_27095 - mix_45504)));
			t_sample mul_27047 = (mix_45505 * ((int)3));
			t_sample mix_45506 = (in1 + (gen_27189 * (mul_27047 - in1)));
			t_sample clamp_27067 = ((mix_45506 <= min_181) ? min_181 : ((mix_45506 >= ((int)1)) ? ((int)1) : mix_45506));
			t_sample out1 = clamp_27067;
			t_sample fold_27010 = fold(clamp_27067, (-1), ((int)0));
			t_sample abs_26962 = fabs(clamp_27067);
			t_sample add_26961 = (abs_26962 + ((t_sample)0.0001));
			t_sample rsub_26963 = (((int)1) - add_26961);
			t_sample mul_26950 = (mul_26949 * rsub_26963);
			t_sample switch_26953 = (lt_26954 ? rsub_26963 : mul_26950);
			t_sample switch_26964 = (gt_26960 ? switch_26953 : fold_27010);
			t_sample out5 = switch_26964;
			double sample_index_182 = (fold_27148 * loopL_dim);
			int index_trunc_183 = fixnan(floor(sample_index_182));
			double index_fract_184 = (sample_index_182 - index_trunc_183);
			int index_trunc_185 = (index_trunc_183 - 1);
			int index_trunc_186 = (index_trunc_183 + 1);
			int index_trunc_187 = (index_trunc_183 + 2);
			int index_wrap_188 = ((index_trunc_185 < 0) ? ((loopL_dim - 1) + ((index_trunc_185 + 1) % loopL_dim)) : (index_trunc_185 % loopL_dim));
			int index_wrap_189 = ((index_trunc_183 < 0) ? ((loopL_dim - 1) + ((index_trunc_183 + 1) % loopL_dim)) : (index_trunc_183 % loopL_dim));
			int index_wrap_190 = ((index_trunc_186 < 0) ? ((loopL_dim - 1) + ((index_trunc_186 + 1) % loopL_dim)) : (index_trunc_186 % loopL_dim));
			int index_wrap_191 = ((index_trunc_187 < 0) ? ((loopL_dim - 1) + ((index_trunc_187 + 1) % loopL_dim)) : (index_trunc_187 % loopL_dim));
			// phase loopL channel 1;
			double read_loopL_193 = (chan_ignore_192 ? 0 : m_loopL_33.read(index_wrap_188, 1));
			double read_loopL_194 = (chan_ignore_192 ? 0 : m_loopL_33.read(index_wrap_189, 1));
			double read_loopL_195 = (chan_ignore_192 ? 0 : m_loopL_33.read(index_wrap_190, 1));
			double read_loopL_196 = (chan_ignore_192 ? 0 : m_loopL_33.read(index_wrap_191, 1));
			double readinterp_197 = spline_interp(index_fract_184, read_loopL_193, read_loopL_194, read_loopL_195, read_loopL_196);
			t_sample sample_loopL_30766 = readinterp_197;
			t_sample index_loopL_30767 = sample_index_182;
			t_sample mul_27140 = (sample_loopL_30766 * clamp_27141);
			t_sample mix_45507 = (selector_26934 + (slide_29196 * (mul_27140 - selector_26934)));
			t_sample clamp_27026 = ((mix_45507 <= min_198) ? min_198 : ((mix_45507 >= ((int)1)) ? ((int)1) : mix_45507));
			t_sample mul_27050 = (clamp_27026 * slide_27056);
			t_sample clamp_27029 = ((mul_27050 <= min_199) ? min_199 : ((mul_27050 >= ((int)1)) ? ((int)1) : mul_27050));
			int index_trunc_201 = fixnan(floor(switch_27043));
			int index_wrap_202 = ((index_trunc_201 < 0) ? ((loopL_dim - 1) + ((index_trunc_201 + 1) % loopL_dim)) : (index_trunc_201 % loopL_dim));
			if ((!chan_ignore_200)) {
				m_loopL_33.write((clamp_27029 + (m_loopL_33.read(index_wrap_202, ((int)1)) * slide_27069)), index_wrap_202, ((int)1));
				
			};
			t_sample mix_45508 = (mul_27140 + (((t_sample)0.5) * (mul_27073 - mul_27140)));
			t_sample mix_45509 = (mix_45508 + (((t_sample)0.33) * (mul_27094 - mix_45508)));
			t_sample mul_27046 = (mix_45509 * ((int)3));
			t_sample mix_45510 = (in2 + (gen_27189 * (mul_27046 - in2)));
			t_sample clamp_27066 = ((mix_45510 <= min_203) ? min_203 : ((mix_45510 >= ((int)1)) ? ((int)1) : mix_45510));
			t_sample out2 = clamp_27066;
			t_sample fold_27009 = fold(clamp_27066, (-1), ((int)0));
			t_sample abs_26957 = fabs(clamp_27066);
			t_sample add_26956 = (abs_26957 + ((t_sample)0.0001));
			t_sample rsub_26958 = (((int)1) - add_26956);
			t_sample mul_26947 = (rsub_26958 * mul_26949);
			t_sample switch_26948 = (lt_26954 ? rsub_26958 : mul_26947);
			t_sample switch_26959 = (gt_26955 ? switch_26948 : fold_27009);
			t_sample out6 = switch_26959;
			t_sample selector_26932 = ((choice_204 >= 3) ? mul_27140 : ((choice_204 >= 2) ? in2 : ((choice_204 >= 1) ? mul_27094 : 0)));
			t_sample mix_45511 = (selector_26932 + (slide_29196 * (mul_27073 - selector_26932)));
			t_sample clamp_27022 = ((mix_45511 <= min_205) ? min_205 : ((mix_45511 >= ((int)1)) ? ((int)1) : mix_45511));
			t_sample mul_27048 = (clamp_27022 * slide_27054);
			t_sample clamp_27027 = ((mul_27048 <= min_206) ? min_206 : ((mul_27048 >= ((int)1)) ? ((int)1) : mul_27048));
			int index_trunc_208 = fixnan(floor(switch_27039));
			int index_wrap_209 = ((index_trunc_208 < 0) ? ((loopR_dim - 1) + ((index_trunc_208 + 1) % loopR_dim)) : (index_trunc_208 % loopR_dim));
			if ((!chan_ignore_207)) {
				m_loopR_28.write((clamp_27027 + (m_loopR_28.read(index_wrap_209, ((int)1)) * slide_27069)), index_wrap_209, ((int)1));
				
			};
			m_history_22 = history_27198_next_27202;
			m_history_21 = history_27178_next_27180;
			m_history_19 = history_27174_next_27182;
			m_history_20 = history_27176_next_27181;
			m_history_18 = history_27178_next_45259;
			m_history_16 = history_27174_next_45261;
			m_history_17 = history_27176_next_45267;
			m_history_15 = history_27178_next_45273;
			m_history_13 = history_27174_next_45277;
			m_history_14 = history_27176_next_45280;
			m_history_12 = history_27178_next_45286;
			m_history_10 = history_27174_next_45291;
			m_history_11 = history_27176_next_45293;
			m_history_9 = history_27178_next_45302;
			m_history_7 = history_27174_next_45300;
			m_history_8 = history_27176_next_45306;
			m_history_6 = history_27178_next_45315;
			m_history_4 = history_27174_next_45313;
			m_history_5 = history_27176_next_45319;
			m_history_3 = history_27178_next_45328;
			m_history_1 = history_27174_next_45326;
			m_history_2 = history_27176_next_45332;
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
	inline void set_ctrl7(t_param _value) {
		m_ctrl_23 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl5(t_param _value) {
		m_ctrl_24 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl6(t_param _value) {
		m_ctrl_25 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl3(t_param _value) {
		m_ctrl_26 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_gate(t_param _value) {
		m_gate_27 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopR(void * _value) {
		m_loopR_28.setbuffer(_value);
	};
	inline void set_button(t_param _value) {
		m_button_29 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl2(t_param _value) {
		m_ctrl_30 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_ctrl4(t_param _value) {
		m_ctrl_31 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_sw2(t_param _value) {
		m_sw_32 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
	};
	inline void set_loopL(void * _value) {
		m_loopL_33.setbuffer(_value);
	};
	inline void set_sw1(t_param _value) {
		m_sw_34 = (_value < 0 ? 0 : (_value > 1 ? 1 : _value));
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
		case 0: *value = self->m_button_29; break;
		case 1: *value = self->m_ctrl_35; break;
		case 2: *value = self->m_ctrl_30; break;
		case 3: *value = self->m_ctrl_26; break;
		case 4: *value = self->m_ctrl_31; break;
		case 5: *value = self->m_ctrl_24; break;
		case 6: *value = self->m_ctrl_25; break;
		case 7: *value = self->m_ctrl_23; break;
		case 8: *value = self->m_gate_27; break;
		
		
		
		case 12: *value = self->m_sw_34; break;
		case 13: *value = self->m_sw_32; break;
		
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
	// initialize parameter 0 ("m_button_29")
	pi = self->__commonstate.params + 0;
	pi->name = "button";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_button_29;
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
	// initialize parameter 2 ("m_ctrl_30")
	pi = self->__commonstate.params + 2;
	pi->name = "ctrl2";
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
	// initialize parameter 3 ("m_ctrl_26")
	pi = self->__commonstate.params + 3;
	pi->name = "ctrl3";
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
	// initialize parameter 4 ("m_ctrl_31")
	pi = self->__commonstate.params + 4;
	pi->name = "ctrl4";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_31;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 5 ("m_ctrl_24")
	pi = self->__commonstate.params + 5;
	pi->name = "ctrl5";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_ctrl_24;
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
	// initialize parameter 7 ("m_ctrl_23")
	pi = self->__commonstate.params + 7;
	pi->name = "ctrl7";
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
	// initialize parameter 8 ("m_gate_27")
	pi = self->__commonstate.params + 8;
	pi->name = "gate";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_gate_27;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 9 ("m_loopL_33")
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
	// initialize parameter 11 ("m_loopR_28")
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
	// initialize parameter 12 ("m_sw_34")
	pi = self->__commonstate.params + 12;
	pi->name = "sw1";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_34;
	pi->defaultref = 0;
	pi->hasinputminmax = false;
	pi->inputmin = 0;
	pi->inputmax = 1;
	pi->hasminmax = true;
	pi->outputmin = 0;
	pi->outputmax = 1;
	pi->exp = 0;
	pi->units = "";		// no units defined
	// initialize parameter 13 ("m_sw_32")
	pi = self->__commonstate.params + 13;
	pi->name = "sw2";
	pi->paramtype = GENLIB_PARAMTYPE_FLOAT;
	pi->defaultvalue = self->m_sw_32;
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


} // TriwalmaVersio_2dbeta::
