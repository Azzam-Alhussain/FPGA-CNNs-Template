#include "fpga_compute_unit.hpp"

void fpga_compute(data_t input[CH_IN],data_t weights[CH_OUT][CH_IN],data_t output[CH_OUT])
{
data_t factor = 0.12;
#pragma HLS INLINE
CONV_CO:for(int co=0;co<CH_OUT;co++){
#pragma HLS LOOP_TRIPCOUNT  max=40
	data_t output_pixel=0;
	CONV_CI:for(int ci=0;ci<CH_IN;ci++){
#pragma HLS LOOP_TRIPCOUNT  max=20
		data_t input_pixel = input[ci];
		data_t weight_value =  weights[co][ci];
		output_pixel += input_pixel * weight_value;
		}
	output[co]= (data_t) output_pixel;
	}
}
