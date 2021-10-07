#include "TriwalkmaVersio_2dbeta_2dmid_2dalways.h"

namespace TriwalkmaVersio_2dbeta_2dmid_2dalways {

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
	t_sample m_sw_34;
	t_sample m_ctrl_35;
	t_sample m_history_5;
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
		__m_slide_70 = 0;
		__m_phasor_73.reset(0);
		__m_slide_109 = 0;
		__m_phasor_112.reset(0);
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
		t_sample sub_58070 = (switch_27169 - ((int)0));
		t_sample scale_58067 = ((safepow((sub_58070 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample choice_58 = int(scale_58067);
		t_sample choice_59 = int(scale_58067);
		t_sample choice_60 = int(scale_58067);
		int neq_26972 = (scale_58067 != ((int)2));
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
		t_sample sub_58126 = (switch_27163 - ((int)0));
		t_sample scale_58123 = ((safepow((sub_58126 * ((t_sample)1)), ((int)1)) * ((int)2)) + ((int)1));
		t_sample iup_71 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_72 = (1 / maximum(1, abs(((int)4000))));
		t_sample choice_89 = int(scale_58123);
		t_sample choice_90 = int(scale_58123);
		bool chan_ignore_101 = ((1 < 0) || (1 >= loopM_channels));
		t_sample choice_107 = int(scale_58123);
		t_sample choice_108 = int(scale_58123);
		t_sample iup_110 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_111 = (1 / maximum(1, abs(((int)4000))));
		int min_128 = (-1);
		int min_129 = (-1);
		bool chan_ignore_142 = ((1 < 0) || (1 >= loopR_channels));
		int min_148 = (-1);
		int min_149 = (-1);
		bool chan_ignore_150 = ((((int)1) < 0) || (((int)1) >= loopR_channels));
		t_sample iup_154 = (1 / maximum(1, abs(((int)4000))));
		t_sample idown_155 = (1 / maximum(1, abs(((int)4000))));
		int min_172 = (-1);
		int min_173 = (-1);
		t_sample choice_176 = int(scale_58123);
		int min_177 = (-1);
		int min_178 = (-1);
		int min_181 = (-1);
		bool chan_ignore_192 = ((1 < 0) || (1 >= loopL_channels));
		int min_198 = (-1);
		int min_199 = (-1);
		bool chan_ignore_200 = ((((int)1) < 0) || (((int)1) >= loopL_channels));
		int min_203 = (-1);
		t_sample choice_204 = int(scale_58123);
		int min_205 = (-1);
		int min_206 = (-1);
		bool chan_ignore_207 = ((((int)1) < 0) || (((int)1) >= loopM_channels));
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
			t_sample mix_58054 = (m_history_21 + (((t_sample)0.0019634941468452) * (m_ctrl_23 - m_history_21)));
			t_sample mix_27177 = mix_58054;
			t_sample mix_58055 = (m_history_20 + (((t_sample)0.0019634941468452) * (mix_27177 - m_history_20)));
			t_sample mix_27175 = mix_58055;
			t_sample mix_58056 = (m_history_19 + (((t_sample)0.0019634941468452) * (mix_27175 - m_history_19)));
			t_sample mix_27173 = mix_58056;
			t_sample gen_27183 = mix_27173;
			t_sample history_27178_next_27180 = fixdenorm(mix_27177);
			t_sample history_27176_next_27181 = fixdenorm(mix_27175);
			t_sample history_27174_next_27182 = fixdenorm(mix_27173);
			t_sample sub_58060 = (gen_27183 - ((int)0));
			t_sample scale_58057 = ((safepow((sub_58060 * ((t_sample)1)), ((int)1)) * ((t_sample)0.9)) + ((int)0));
			__m_slide_43 = fixdenorm((__m_slide_43 + (((scale_58057 > __m_slide_43) ? iup_44 : idown_45) * (scale_58057 - __m_slide_43))));
			t_sample slide_27069 = __m_slide_43;
			t_sample mix_58061 = (m_history_18 + (((t_sample)0.0019634941468452) * (m_ctrl_35 - m_history_18)));
			t_sample mix_57352 = mix_58061;
			t_sample mix_58062 = (m_history_17 + (((t_sample)0.0019634941468452) * (mix_57352 - m_history_17)));
			t_sample mix_57351 = mix_58062;
			t_sample mix_58063 = (m_history_16 + (((t_sample)0.0019634941468452) * (mix_57351 - m_history_16)));
			t_sample mix_57350 = mix_58063;
			t_sample gen_27189 = mix_57350;
			t_sample history_27178_next_57346 = fixdenorm(mix_57352);
			t_sample history_27176_next_57354 = fixdenorm(mix_57351);
			t_sample history_27174_next_57348 = fixdenorm(mix_57350);
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
			t_sample mix_58064 = (m_history_15 + (((t_sample)0.0019634941468452) * (m_ctrl_24 - m_history_15)));
			t_sample mix_57361 = mix_58064;
			t_sample mix_58065 = (m_history_14 + (((t_sample)0.0019634941468452) * (mix_57361 - m_history_14)));
			t_sample mix_57359 = mix_58065;
			t_sample mix_58066 = (m_history_13 + (((t_sample)0.0019634941468452) * (mix_57359 - m_history_13)));
			t_sample mix_57367 = mix_58066;
			t_sample gen_27188 = mix_57367;
			t_sample history_27178_next_57360 = fixdenorm(mix_57361);
			t_sample history_27176_next_57368 = fixdenorm(mix_57359);
			t_sample history_27174_next_57366 = fixdenorm(mix_57367);
			__m_slide_55 = fixdenorm((__m_slide_55 + (((gen_27188 > __m_slide_55) ? iup_56 : idown_57) * (gen_27188 - __m_slide_55))));
			t_sample slide_29196 = __m_slide_55;
			t_sample selector_27044 = ((choice_58 >= 3) ? gt_26995 : ((choice_58 >= 2) ? ((int)1) : ((choice_58 >= 1) ? gt_26998 : 0)));
			t_sample selector_26992 = ((choice_59 >= 3) ? gt_26995 : ((choice_59 >= 2) ? ((int)1) : ((choice_59 >= 1) ? gt_26998 : 0)));
			t_sample selector_27013 = ((choice_60 >= 3) ? gt_26995 : ((choice_60 >= 2) ? ((int)1) : ((choice_60 >= 1) ? gt_26998 : 0)));
			t_sample mix_58071 = (m_history_12 + (((t_sample)0.0019634941468452) * (m_ctrl_31 - m_history_12)));
			t_sample mix_57374 = mix_58071;
			t_sample mix_58072 = (m_history_11 + (((t_sample)0.0019634941468452) * (mix_57374 - m_history_11)));
			t_sample mix_57372 = mix_58072;
			t_sample mix_58073 = (m_history_10 + (((t_sample)0.0019634941468452) * (mix_57372 - m_history_10)));
			t_sample mix_57378 = mix_58073;
			t_sample gen_27184 = mix_57378;
			t_sample history_27178_next_57373 = fixdenorm(mix_57374);
			t_sample history_27176_next_57379 = fixdenorm(mix_57372);
			t_sample history_27174_next_57377 = fixdenorm(mix_57378);
			t_sample sub_58077 = (gen_27184 - ((int)0));
			t_sample scale_58074 = ((safepow((sub_58077 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample gtep_27057 = ((scale_58074 >= ((int)0)) ? scale_58074 : 0);
			__m_slide_61 = fixdenorm((__m_slide_61 + (((gtep_27057 > __m_slide_61) ? iup_62 : idown_63) * (gtep_27057 - __m_slide_61))));
			t_sample slide_27054 = __m_slide_61;
			t_sample ceil_26976 = ceil(slide_27054);
			t_sample switch_26981 = (neq_26972 ? ceil_26976 : ((int)1));
			t_sample mul_26980 = (counter_27119 * switch_26981);
			t_sample switch_27042 = (selector_27044 ? mul_26980 : ((int)0));
			t_sample mul_26979 = (counter_27119 * switch_26981);
			t_sample switch_27039 = (selector_27044 ? mul_26979 : ((int)0));
			t_sample add_26946 = (fold_27008 + gtep_27057);
			t_sample sub_58081 = (gen_27184 - ((int)0));
			t_sample scale_58078 = ((safepow((sub_58081 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_27062 = fabs(scale_58078);
			t_sample sub_58085 = (abs_27062 - ((int)1));
			t_sample scale_58082 = ((safepow((sub_58085 * ((t_sample)-1)), ((int)1)) * ((int)1)) + ((int)0));
			__m_slide_64 = fixdenorm((__m_slide_64 + (((scale_58082 > __m_slide_64) ? iup_65 : idown_66) * (scale_58082 - __m_slide_64))));
			t_sample slide_27055 = __m_slide_64;
			t_sample ceil_26977 = ceil(slide_27055);
			t_sample switch_26983 = (neq_26972 ? ceil_26977 : ((int)1));
			t_sample mul_26984 = (switch_26983 * counter_27123);
			t_sample switch_27041 = (selector_27044 ? mul_26984 : ((int)0));
			t_sample mul_26982 = (switch_26983 * counter_27123);
			t_sample switch_27040 = (selector_27044 ? mul_26982 : ((int)0));
			t_sample add_26944 = (add_26946 + scale_58082);
			t_sample sub_26941 = (add_26944 - ((t_sample)0.3));
			t_sample switch_27015 = (selector_27013 ? rsub_27014 : sub_26941);
			t_sample out4 = switch_27015;
			t_sample sub_58089 = (gen_27184 - ((int)0));
			t_sample scale_58086 = ((safepow((sub_58089 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample ltep_27059 = ((scale_58086 <= ((int)0)) ? scale_58086 : 0);
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
			t_sample add_26943 = (add_26945 + scale_58082);
			t_sample sub_26942 = (add_26943 - ((t_sample)0.3));
			t_sample switch_26994 = (selector_26992 ? rsub_26993 : sub_26942);
			t_sample out3 = switch_26994;
			t_sample mix_58090 = (m_history_9 + (((t_sample)0.0019634941468452) * (m_ctrl_25 - m_history_9)));
			t_sample mix_57389 = mix_58090;
			t_sample mix_58091 = (m_history_8 + (((t_sample)0.0019634941468452) * (mix_57389 - m_history_8)));
			t_sample mix_57392 = mix_58091;
			t_sample mix_58092 = (m_history_7 + (((t_sample)0.0019634941468452) * (mix_57392 - m_history_7)));
			t_sample mix_57387 = mix_58092;
			t_sample gen_27185 = mix_57387;
			t_sample history_27178_next_57388 = fixdenorm(mix_57389);
			t_sample history_27176_next_57394 = fixdenorm(mix_57392);
			t_sample history_27174_next_57386 = fixdenorm(mix_57387);
			t_sample sub_58096 = (gen_27185 - ((int)0));
			t_sample scale_58093 = ((safepow((sub_58096 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_27002 = fabs(scale_58093);
			t_sample sub_58100 = (abs_27002 - ((int)1));
			t_sample scale_58097 = ((safepow((sub_58100 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_55398 = (scale_58097 > ((int)2));
			t_sample mix_58101 = (m_history_6 + (((t_sample)0.0019634941468452) * (m_ctrl_30 - m_history_6)));
			t_sample mix_57402 = mix_58101;
			t_sample mix_58102 = (m_history_5 + (((t_sample)0.0019634941468452) * (mix_57402 - m_history_5)));
			t_sample mix_57405 = mix_58102;
			t_sample mix_58103 = (m_history_4 + (((t_sample)0.0019634941468452) * (mix_57405 - m_history_4)));
			t_sample mix_57400 = mix_58103;
			t_sample gen_27186 = mix_57400;
			t_sample history_27178_next_57401 = fixdenorm(mix_57402);
			t_sample history_27176_next_57407 = fixdenorm(mix_57405);
			t_sample history_27174_next_57399 = fixdenorm(mix_57400);
			t_sample sub_58107 = (gen_27186 - ((int)0));
			t_sample scale_58104 = ((safepow((sub_58107 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_27018 = fabs(scale_58104);
			t_sample sub_58111 = (abs_27018 - ((int)1));
			t_sample scale_58108 = ((safepow((sub_58111 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int gt_55814 = (scale_58108 > ((int)2));
			t_sample mix_58112 = (m_history_3 + (((t_sample)0.0019634941468452) * (m_ctrl_26 - m_history_3)));
			t_sample mix_57415 = mix_58112;
			t_sample mix_58113 = (m_history_2 + (((t_sample)0.0019634941468452) * (mix_57415 - m_history_2)));
			t_sample mix_57418 = mix_58113;
			t_sample mix_58114 = (m_history_1 + (((t_sample)0.0019634941468452) * (mix_57418 - m_history_1)));
			t_sample mix_57413 = mix_58114;
			t_sample gen_27187 = mix_57413;
			t_sample history_27178_next_57414 = fixdenorm(mix_57415);
			t_sample history_27176_next_57420 = fixdenorm(mix_57418);
			t_sample history_27174_next_57412 = fixdenorm(mix_57413);
			t_sample sub_58118 = (gen_27187 - ((int)0));
			t_sample scale_58115 = ((safepow((sub_58118 * ((t_sample)1)), ((int)1)) * ((int)2)) + (-1));
			t_sample abs_36993 = fabs(scale_58115);
			t_sample sub_58122 = (abs_36993 - ((int)1));
			t_sample scale_58119 = ((safepow((sub_58122 * ((t_sample)-1)), ((int)1)) * ((t_sample)3.5)) + ((t_sample)0.5));
			int lt_56073 = (scale_58119 < ((int)2));
			int gt_38546 = (scale_58115 > ((int)0));
			t_sample mul_44483 = (scale_58119 * (-1));
			t_sample switch_37252 = (gt_38546 ? scale_58119 : mul_44483);
			t_sample rdiv_27110 = safediv(((int)1), switch_37252);
			__m_slide_70 = fixdenorm((__m_slide_70 + (((rdiv_27110 > __m_slide_70) ? iup_71 : idown_72) * (rdiv_27110 - __m_slide_70))));
			t_sample slide_27004 = __m_slide_70;
			t_sample phasor_27111 = __m_phasor_73(slide_27004, samples_to_seconds);
			t_sample mul_27108 = (phasor_27111 * ((int)2));
			t_sample sub_27107 = (mul_27108 - ((int)1));
			t_sample cos_27106 = cos(sub_27107);
			t_sample sub_27105 = (cos_27106 - ((t_sample)0.5));
			t_sample mul_27104 = (sub_27105 * ((int)10));
			t_sample clamp_27103 = ((mul_27104 <= ((int)0)) ? ((int)0) : ((mul_27104 >= ((int)1)) ? ((int)1) : mul_27104));
			t_sample fold_27096 = fold(phasor_27111, ((int)0), ((int)1));
			double sample_index_74 = (fold_27096 * loopM_dim);
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
			double read_loopM_84 = m_loopM_36.read(index_wrap_80, 0);
			double read_loopM_85 = m_loopM_36.read(index_wrap_81, 0);
			double read_loopM_86 = m_loopM_36.read(index_wrap_82, 0);
			double read_loopM_87 = m_loopM_36.read(index_wrap_83, 0);
			double readinterp_88 = spline_interp(index_fract_76, read_loopM_84, read_loopM_85, read_loopM_86, read_loopM_87);
			t_sample sample_loopM_30268 = readinterp_88;
			t_sample index_loopM_30269 = sample_index_74;
			t_sample mul_27095 = (sample_loopM_30268 * clamp_27103);
			t_sample selector_26937 = ((choice_89 >= 3) ? mul_27095 : ((choice_89 >= 2) ? in1 : ((choice_89 >= 1) ? mul_27095 : 0)));
			t_sample selector_26939 = ((choice_90 >= 3) ? in1 : ((choice_90 >= 2) ? in1 : ((choice_90 >= 1) ? mul_27095 : 0)));
			double sample_index_91 = (fold_27096 * loopM_dim);
			int index_trunc_92 = fixnan(floor(sample_index_91));
			double index_fract_93 = (sample_index_91 - index_trunc_92);
			int index_trunc_94 = (index_trunc_92 - 1);
			int index_trunc_95 = (index_trunc_92 + 1);
			int index_trunc_96 = (index_trunc_92 + 2);
			int index_wrap_97 = ((index_trunc_94 < 0) ? ((loopM_dim - 1) + ((index_trunc_94 + 1) % loopM_dim)) : (index_trunc_94 % loopM_dim));
			int index_wrap_98 = ((index_trunc_92 < 0) ? ((loopM_dim - 1) + ((index_trunc_92 + 1) % loopM_dim)) : (index_trunc_92 % loopM_dim));
			int index_wrap_99 = ((index_trunc_95 < 0) ? ((loopM_dim - 1) + ((index_trunc_95 + 1) % loopM_dim)) : (index_trunc_95 % loopM_dim));
			int index_wrap_100 = ((index_trunc_96 < 0) ? ((loopM_dim - 1) + ((index_trunc_96 + 1) % loopM_dim)) : (index_trunc_96 % loopM_dim));
			// phase loopM channel 1;
			double read_loopM_102 = (chan_ignore_101 ? 0 : m_loopM_36.read(index_wrap_97, 1));
			double read_loopM_103 = (chan_ignore_101 ? 0 : m_loopM_36.read(index_wrap_98, 1));
			double read_loopM_104 = (chan_ignore_101 ? 0 : m_loopM_36.read(index_wrap_99, 1));
			double read_loopM_105 = (chan_ignore_101 ? 0 : m_loopM_36.read(index_wrap_100, 1));
			double readinterp_106 = spline_interp(index_fract_93, read_loopM_102, read_loopM_103, read_loopM_104, read_loopM_105);
			t_sample sample_loopM_30600 = readinterp_106;
			t_sample index_loopM_30601 = sample_index_91;
			t_sample mul_27094 = (sample_loopM_30600 * clamp_27103);
			t_sample selector_26932 = ((choice_107 >= 3) ? mul_27094 : ((choice_107 >= 2) ? in2 : ((choice_107 >= 1) ? mul_27094 : 0)));
			t_sample selector_26934 = ((choice_108 >= 3) ? in2 : ((choice_108 >= 2) ? in2 : ((choice_108 >= 1) ? mul_27094 : 0)));
			int gt_39063 = (scale_58093 > ((int)0));
			t_sample mul_45258 = (scale_58097 * (-1));
			t_sample switch_37770 = (gt_39063 ? scale_58097 : mul_45258);
			t_sample rdiv_27089 = safediv(((int)1), switch_37770);
			__m_slide_109 = fixdenorm((__m_slide_109 + (((rdiv_27089 > __m_slide_109) ? iup_110 : idown_111) * (rdiv_27089 - __m_slide_109))));
			t_sample slide_27000 = __m_slide_109;
			t_sample phasor_27090 = __m_phasor_112(slide_27000, samples_to_seconds);
			t_sample mul_27087 = (phasor_27090 * ((int)2));
			t_sample sub_27086 = (mul_27087 - ((int)1));
			t_sample cos_27085 = cos(sub_27086);
			t_sample sub_27084 = (cos_27085 - ((t_sample)0.5));
			t_sample mul_27083 = (sub_27084 * ((int)10));
			t_sample clamp_27082 = ((mul_27083 <= ((int)0)) ? ((int)0) : ((mul_27083 >= ((int)1)) ? ((int)1) : mul_27083));
			t_sample fold_27075 = fold(phasor_27090, ((int)0), ((int)1));
			double sample_index_113 = (fold_27075 * loopR_dim);
			int index_trunc_114 = fixnan(floor(sample_index_113));
			double index_fract_115 = (sample_index_113 - index_trunc_114);
			int index_trunc_116 = (index_trunc_114 - 1);
			int index_trunc_117 = (index_trunc_114 + 1);
			int index_trunc_118 = (index_trunc_114 + 2);
			int index_wrap_119 = ((index_trunc_116 < 0) ? ((loopR_dim - 1) + ((index_trunc_116 + 1) % loopR_dim)) : (index_trunc_116 % loopR_dim));
			int index_wrap_120 = ((index_trunc_114 < 0) ? ((loopR_dim - 1) + ((index_trunc_114 + 1) % loopR_dim)) : (index_trunc_114 % loopR_dim));
			int index_wrap_121 = ((index_trunc_117 < 0) ? ((loopR_dim - 1) + ((index_trunc_117 + 1) % loopR_dim)) : (index_trunc_117 % loopR_dim));
			int index_wrap_122 = ((index_trunc_118 < 0) ? ((loopR_dim - 1) + ((index_trunc_118 + 1) % loopR_dim)) : (index_trunc_118 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_123 = m_loopR_28.read(index_wrap_119, 0);
			double read_loopR_124 = m_loopR_28.read(index_wrap_120, 0);
			double read_loopR_125 = m_loopR_28.read(index_wrap_121, 0);
			double read_loopR_126 = m_loopR_28.read(index_wrap_122, 0);
			double readinterp_127 = spline_interp(index_fract_115, read_loopR_123, read_loopR_124, read_loopR_125, read_loopR_126);
			t_sample sample_loopR_31098 = readinterp_127;
			t_sample index_loopR_31099 = sample_index_113;
			t_sample mul_27074 = (sample_loopR_31098 * clamp_27082);
			t_sample mix_58127 = (selector_26937 + (slide_29196 * (mul_27074 - selector_26937)));
			t_sample clamp_26936 = ((mix_58127 <= min_128) ? min_128 : ((mix_58127 >= ((int)1)) ? ((int)1) : mix_58127));
			t_sample mul_27051 = (clamp_26936 * slide_27054);
			t_sample clamp_27030 = ((mul_27051 <= min_129) ? min_129 : ((mul_27051 >= ((int)1)) ? ((int)1) : mul_27051));
			int index_trunc_130 = fixnan(floor(switch_27042));
			int index_wrap_131 = ((index_trunc_130 < 0) ? ((loopR_dim - 1) + ((index_trunc_130 + 1) % loopR_dim)) : (index_trunc_130 % loopR_dim));
			m_loopR_28.write((clamp_27030 + (m_loopR_28.read(index_wrap_131, 0) * slide_27069)), index_wrap_131, 0);
			double sample_index_132 = (fold_27075 * loopR_dim);
			int index_trunc_133 = fixnan(floor(sample_index_132));
			double index_fract_134 = (sample_index_132 - index_trunc_133);
			int index_trunc_135 = (index_trunc_133 - 1);
			int index_trunc_136 = (index_trunc_133 + 1);
			int index_trunc_137 = (index_trunc_133 + 2);
			int index_wrap_138 = ((index_trunc_135 < 0) ? ((loopR_dim - 1) + ((index_trunc_135 + 1) % loopR_dim)) : (index_trunc_135 % loopR_dim));
			int index_wrap_139 = ((index_trunc_133 < 0) ? ((loopR_dim - 1) + ((index_trunc_133 + 1) % loopR_dim)) : (index_trunc_133 % loopR_dim));
			int index_wrap_140 = ((index_trunc_136 < 0) ? ((loopR_dim - 1) + ((index_trunc_136 + 1) % loopR_dim)) : (index_trunc_136 % loopR_dim));
			int index_wrap_141 = ((index_trunc_137 < 0) ? ((loopR_dim - 1) + ((index_trunc_137 + 1) % loopR_dim)) : (index_trunc_137 % loopR_dim));
			// phase loopR channel 1;
			double read_loopR_143 = (chan_ignore_142 ? 0 : m_loopR_28.read(index_wrap_138, 1));
			double read_loopR_144 = (chan_ignore_142 ? 0 : m_loopR_28.read(index_wrap_139, 1));
			double read_loopR_145 = (chan_ignore_142 ? 0 : m_loopR_28.read(index_wrap_140, 1));
			double read_loopR_146 = (chan_ignore_142 ? 0 : m_loopR_28.read(index_wrap_141, 1));
			double readinterp_147 = spline_interp(index_fract_134, read_loopR_143, read_loopR_144, read_loopR_145, read_loopR_146);
			t_sample sample_loopR_30932 = readinterp_147;
			t_sample index_loopR_30933 = sample_index_132;
			t_sample mul_27073 = (sample_loopR_30932 * clamp_27082);
			t_sample mix_58128 = (selector_26932 + (slide_29196 * (mul_27073 - selector_26932)));
			t_sample clamp_27022 = ((mix_58128 <= min_148) ? min_148 : ((mix_58128 >= ((int)1)) ? ((int)1) : mix_58128));
			t_sample mul_27048 = (clamp_27022 * slide_27054);
			t_sample clamp_27027 = ((mul_27048 <= min_149) ? min_149 : ((mul_27048 >= ((int)1)) ? ((int)1) : mul_27048));
			int index_trunc_151 = fixnan(floor(switch_27039));
			int index_wrap_152 = ((index_trunc_151 < 0) ? ((loopR_dim - 1) + ((index_trunc_151 + 1) % loopR_dim)) : (index_trunc_151 % loopR_dim));
			if ((!chan_ignore_150)) {
				m_loopR_28.write((clamp_27027 + (m_loopR_28.read(index_wrap_152, ((int)1)) * slide_27069)), index_wrap_152, ((int)1));
				
			};
			int gt_38029 = (scale_58104 > ((int)0));
			t_sample mul_43708 = (scale_58108 * (-1));
			t_sample switch_37511 = (gt_38029 ? scale_58108 : mul_43708);
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
			t_sample mix_58129 = (selector_26939 + (slide_29196 * (mul_27139 - selector_26939)));
			t_sample clamp_27034 = ((mix_58129 <= min_172) ? min_172 : ((mix_58129 >= ((int)1)) ? ((int)1) : mix_58129));
			t_sample mul_27053 = (clamp_27034 * slide_27056);
			t_sample clamp_27032 = ((mul_27053 <= min_173) ? min_173 : ((mul_27053 >= ((int)1)) ? ((int)1) : mul_27053));
			int index_trunc_174 = fixnan(floor(switch_27045));
			int index_wrap_175 = ((index_trunc_174 < 0) ? ((loopL_dim - 1) + ((index_trunc_174 + 1) % loopL_dim)) : (index_trunc_174 % loopL_dim));
			m_loopL_33.write((clamp_27032 + (m_loopL_33.read(index_wrap_175, 0) * slide_27069)), index_wrap_175, 0);
			t_sample selector_26938 = ((choice_176 >= 3) ? mul_27139 : ((choice_176 >= 2) ? in1 : ((choice_176 >= 1) ? in1 : 0)));
			t_sample mix_58130 = (selector_26938 + (slide_29196 * (mul_27095 - selector_26938)));
			t_sample clamp_27033 = ((mix_58130 <= min_177) ? min_177 : ((mix_58130 >= ((int)1)) ? ((int)1) : mix_58130));
			t_sample mul_27052 = (clamp_27033 * slide_27055);
			t_sample clamp_27031 = ((mul_27052 <= min_178) ? min_178 : ((mul_27052 >= ((int)1)) ? ((int)1) : mul_27052));
			int index_trunc_179 = fixnan(floor(switch_27041));
			int index_wrap_180 = ((index_trunc_179 < 0) ? ((loopM_dim - 1) + ((index_trunc_179 + 1) % loopM_dim)) : (index_trunc_179 % loopM_dim));
			m_loopM_36.write((clamp_27031 + (m_loopM_36.read(index_wrap_180, 0) * slide_27069)), index_wrap_180, 0);
			t_sample mix_58131 = (mul_27139 + (((t_sample)0.5) * (mul_27074 - mul_27139)));
			t_sample mix_58132 = (mix_58131 + (((t_sample)0.33) * (mul_27095 - mix_58131)));
			t_sample mul_27047 = (mix_58132 * ((int)3));
			t_sample mix_58133 = (in1 + (gen_27189 * (mul_27047 - in1)));
			t_sample clamp_27067 = ((mix_58133 <= min_181) ? min_181 : ((mix_58133 >= ((int)1)) ? ((int)1) : mix_58133));
			t_sample out1 = clamp_27067;
			t_sample fold_27010 = fold(clamp_27067, (-1), ((int)0));
			t_sample abs_26962 = fabs(clamp_27067);
			t_sample add_26961 = (abs_26962 + ((t_sample)0.0001));
			t_sample rsub_26963 = (((int)1) - add_26961);
			t_sample mul_26950 = (mul_26949 * rsub_26963);
			t_sample switch_26953 = (lt_56073 ? rsub_26963 : mul_26950);
			t_sample switch_26964 = (gt_55814 ? switch_26953 : fold_27010);
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
			t_sample mix_58134 = (selector_26934 + (slide_29196 * (mul_27140 - selector_26934)));
			t_sample clamp_27026 = ((mix_58134 <= min_198) ? min_198 : ((mix_58134 >= ((int)1)) ? ((int)1) : mix_58134));
			t_sample mul_27050 = (clamp_27026 * slide_27056);
			t_sample clamp_27029 = ((mul_27050 <= min_199) ? min_199 : ((mul_27050 >= ((int)1)) ? ((int)1) : mul_27050));
			int index_trunc_201 = fixnan(floor(switch_27043));
			int index_wrap_202 = ((index_trunc_201 < 0) ? ((loopL_dim - 1) + ((index_trunc_201 + 1) % loopL_dim)) : (index_trunc_201 % loopL_dim));
			if ((!chan_ignore_200)) {
				m_loopL_33.write((clamp_27029 + (m_loopL_33.read(index_wrap_202, ((int)1)) * slide_27069)), index_wrap_202, ((int)1));
				
			};
			t_sample mix_58135 = (mul_27140 + (((t_sample)0.5) * (mul_27073 - mul_27140)));
			t_sample mix_58136 = (mix_58135 + (((t_sample)0.33) * (mul_27094 - mix_58135)));
			t_sample mul_27046 = (mix_58136 * ((int)3));
			t_sample mix_58137 = (in2 + (gen_27189 * (mul_27046 - in2)));
			t_sample clamp_27066 = ((mix_58137 <= min_203) ? min_203 : ((mix_58137 >= ((int)1)) ? ((int)1) : mix_58137));
			t_sample out2 = clamp_27066;
			t_sample fold_27009 = fold(clamp_27066, (-1), ((int)0));
			t_sample abs_26957 = fabs(clamp_27066);
			t_sample add_26956 = (abs_26957 + ((t_sample)0.0001));
			t_sample rsub_26958 = (((int)1) - add_26956);
			t_sample mul_26947 = (rsub_26958 * mul_26949);
			t_sample switch_26948 = (lt_56073 ? rsub_26958 : mul_26947);
			t_sample switch_26959 = (gt_55398 ? switch_26948 : fold_27009);
			t_sample out6 = switch_26959;
			t_sample selector_26933 = ((choice_204 >= 3) ? mul_27140 : ((choice_204 >= 2) ? in2 : ((choice_204 >= 1) ? in2 : 0)));
			t_sample mix_58138 = (selector_26933 + (slide_29196 * (mul_27094 - selector_26933)));
			t_sample clamp_27024 = ((mix_58138 <= min_205) ? min_205 : ((mix_58138 >= ((int)1)) ? ((int)1) : mix_58138));
			t_sample mul_27049 = (clamp_27024 * slide_27055);
			t_sample clamp_27028 = ((mul_27049 <= min_206) ? min_206 : ((mul_27049 >= ((int)1)) ? ((int)1) : mul_27049));
			int index_trunc_208 = fixnan(floor(switch_27040));
			int index_wrap_209 = ((index_trunc_208 < 0) ? ((loopM_dim - 1) + ((index_trunc_208 + 1) % loopM_dim)) : (index_trunc_208 % loopM_dim));
			if ((!chan_ignore_207)) {
				m_loopM_36.write((clamp_27028 + (m_loopM_36.read(index_wrap_209, ((int)1)) * slide_27069)), index_wrap_209, ((int)1));
				
			};
			m_history_22 = history_27198_next_27202;
			m_history_21 = history_27178_next_27180;
			m_history_19 = history_27174_next_27182;
			m_history_20 = history_27176_next_27181;
			m_history_18 = history_27178_next_57346;
			m_history_16 = history_27174_next_57348;
			m_history_17 = history_27176_next_57354;
			m_history_15 = history_27178_next_57360;
			m_history_13 = history_27174_next_57366;
			m_history_14 = history_27176_next_57368;
			m_history_12 = history_27178_next_57373;
			m_history_10 = history_27174_next_57377;
			m_history_11 = history_27176_next_57379;
			m_history_9 = history_27178_next_57388;
			m_history_7 = history_27174_next_57386;
			m_history_8 = history_27176_next_57394;
			m_history_6 = history_27178_next_57401;
			m_history_4 = history_27174_next_57399;
			m_history_5 = history_27176_next_57407;
			m_history_3 = history_27178_next_57414;
			m_history_1 = history_27174_next_57412;
			m_history_2 = history_27176_next_57420;
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


} // TriwalkmaVersio_2dbeta_2dmid_2dalways::
