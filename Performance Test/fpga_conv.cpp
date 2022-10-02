#include "fpga_conv.hpp"
#include "fpga_compute_unit.hpp"

void convolution(data_t input[ROW][COL][CH_IN],data_t weights[CH_OUT][CH_IN][KER][KER],data_t output[ROW][COL][CH_OUT]){
	//std::cout<<"Executing Compute Unit for Convolution"<<std::endl;
	#pragma HLS INLINE
	data_t input_vec[CH_IN];
	data_t weights_vec[CH_OUT][CH_IN];
	data_t output_vec[CH_OUT];
	int S=1;
	CONV_KI:for(int i=0;i<KER;i++){
		#pragma HLS LOOP_TRIPCOUNT min=3 max=11
		CONV_KJ:for(int j=0;j<KER;j++){
			#pragma HLS LOOP_TRIPCOUNT min=3 max=11
			CONV_R:for(int row=0;row<ROW;row++){
				#pragma HLS LOOP_TRIPCOUNT min=4 max=20
				CONV_C:for(int col=0;col<COL;col++){
					#pragma HLS PIPELINE
					#pragma HLS LOOP_TRIPCOUNT min=4 max=20
					// read input vector
					read_input_vector_conv(input,input_vec,row,col,i,j);
					//read weight vector
					read_weight_vector_conv(weights,weights_vec,i,j);
					//perform computation
					compute(input_vec,weights_vec,output_vec);
					//write output vector
					write_output_vector_conv(output,output_vec,row,col);
					}
				}
			}
		}
}

//-----------------------------------------------------------------------------------
void read_input_vector_conv(data_t input[ROW][COL][CH_IN],data_t input_vec[CH_IN],int row,int col,int i, int j)
{
	#pragma HLS INLINE
	int row_fixed = row+i;
	int col_fixed = col+j;
	for (int idx=0;idx<CH_IN;idx++){
	#pragma HLS LOOP_TRIPCOUNT min=4 max=20
		data_t temp =  input[row_fixed][col_fixed][idx];
		input_vec[idx] = temp;
	}
}
//-----------------------------------------------------------------------------------
void read_weight_vector_conv(data_t weights[CH_OUT][CH_IN][KER][KER],data_t weights_vec[CH_OUT][CH_IN],int i,int j)
{
#pragma HLS INLINE
	int ki_fixed = i;
	int kj_fixed = j;
	for (int idx1=0;idx1<CH_OUT;idx1++){
		#pragma HLS LOOP_TRIPCOUNT min=1 max=64
		for (int idx2=0;idx2<CH_IN;idx2++){
			#pragma HLS LOOP_TRIPCOUNT min=1 max=7
			data_t temp =  weights[idx1][idx2][ki_fixed][kj_fixed];
			weights_vec[idx1][idx2] = temp;
		}
	}
}
//-----------------------------------------------------------------------------------
void write_output_vector_conv(data_t output[ROW][COL][CH_OUT],data_t output_vec[CH_OUT],int row,int col){
	#pragma HLS INLINE
	int row_fixed = row;
	int col_fixed = col;
	for (int idx=0;idx<CH_OUT;idx++){
		#pragma HLS LOOP_TRIPCOUNT min=1 max=64
		data_t temp =  output_vec [idx];
		output[row_fixed][col_fixed][idx] = temp;
	}
}
