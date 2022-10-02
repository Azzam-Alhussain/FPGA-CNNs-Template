#include "fpga_fc.hpp"
#include "fpga_compute_unit.hpp"

void fully_connected(data_t input[TD_IN],data_t weights[TD_OUT][TD_IN],data_t output[TD_OUT])
{
//std::cout<<"Executing Compute Unit for Fully Connected"<<std::endl;
#pragma HLS INLINE
data_t input_vec[CH_IN];
data_t weights_vec[CH_OUT][CH_IN];
data_t output_vec[CH_OUT];
	CONV_CO:for(int co=0;co<TD_OUT;co+=CH_OUT){
		CONV_CI:for(int ci=0;ci<TD_IN;ci+=CH_IN){
		#pragma HLS PIPELINE
			int co_min = co;
			int co_max = co+CH_OUT;
			int ci_min = ci;
			int ci_max = ci+CH_IN;
			// read input vector
			read_input_vector_fc(input,input_vec,ci_min,ci_max);
			//read weight vector
			read_weight_vector_fc(weights,weights_vec,co_min,co_max,ci_min,ci_max);
			//perform computation
			compute(input_vec,weights_vec,output_vec);
			//write output vector
			write_output_vector_fc(output,output_vec,co_min,co_max);

		}
	}
}
//--------------------------------------------------------------------------------------------------------------------
void read_input_vector_fc(data_t input[TD_IN],data_t input_vec[CH_IN],int ci_min,int ci_max)
{
#pragma HLS INLINE
	int idx=0;
	for(int ci=ci_min;ci<ci_max;ci++)
	{
		input_vec[idx] = input[ci];
		idx++;
	}
}
void read_weight_vector_fc(data_t weights[TD_OUT][TD_IN],data_t weights_vec[CH_OUT][CH_IN],int co_min,int co_max,int ci_min,int ci_max)
{
#pragma HLS INLINE
	int idx1=0;
	for(int co=co_min;co<co_max;co++){
		int idx2=0;
		for(int ci=ci_min;ci<ci_max;ci++){
			weights_vec[idx1][idx2] = weights[co][ci];
			idx2++;
			}
		idx1++;
	}
}
void write_output_vector_fc(data_t output[TD_OUT],data_t output_vec[CH_OUT],int co_min,int co_max)
{
#pragma HLS INLINE
	int idx=0;
	for(int co=co_min;co<co_max;co++)
	{
		output_vec[idx] = output[co];
		idx++;
	}
}
