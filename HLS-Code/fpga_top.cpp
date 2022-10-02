#include "fpga_top.hpp"
#include "fpga_mem_controller.hpp"
#include "fpga_conv.hpp"
#include "fpga_fc.hpp"
void fpga_top(layer_t *layer,tile_specs tile,data_t *sharedDram, data_t *weightDram,int type){
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=type bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=layer bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=tile bundle=CTRL_BUS
#pragma HLS INTERFACE m_axi depth=18000 port=sharedDram offset=slave bundle=DATA_BUS
#pragma HLS INTERFACE m_axi depth=1800 port=weightDram offset=slave bundle=WEIGHT_BUS
//----------------------------------------------------------------------------------------------------
data_t input_buffer_c[ROW][COL][CH_IN];
#pragma HLS ARRAY_PARTITION variable=input_buffer_c complete factor=20 dim=3
data_t weights_buffer_c[CH_OUT][CH_IN][KER][KER];
#pragma HLS ARRAY_PARTITION variable=weights_buffer_c complete factor=20 dim=2
data_t output_buffer_c[ROW][COL][CH_OUT];
#pragma HLS ARRAY_PARTITION variable=output_buffer_c complete factor=40 dim=3
//----------------------------------------------------------------------------------------------------
data_t input_buffer_f[TD_IN];
#pragma HLS ARRAY_PARTITION variable=input_buffer_f complete factor=20 dim=1
data_t weights_buffer_f[TD_OUT][TD_IN];
#pragma HLS ARRAY_PARTITION variable=weights_buffer_f complete factor=20 dim=2
data_t output_buffer_f[TD_OUT];
#pragma HLS ARRAY_PARTITION variable=output_buffer_f complete factor=40 dim=1
//----------------------------------------------------------------------------------------------------
std::cout<<" Top Function Starts for  "<<layer->name<<std::endl;
CONVOLUTION:if(type==0){
	PRE_PROCESS_C:{
		read_input_pixels(layer,tile,sharedDram, input_buffer_c);
		read_weight_vector(layer,tile,weightDram, weights_buffer_c);
		//read_output_pixels(layer,tile,sharedDram, output_buffer_c);
	}
	PROCESS_C:{
		convolution(tile,input_buffer_c,weights_buffer_c,output_buffer_c);
	}
	POST_PROCESS_C:{
		write_output_pixels(layer,tile,sharedDram, output_buffer_c);
	}
}
//----------------------------------------------------------------------------------------------------
FC_CONNECTED:if(type==1){
	PRE_PROCESS_F:{
		read_input_pixels_fc(layer,tile,sharedDram, input_buffer_f);
		read_weight_vector_fc(layer,tile,weightDram, weights_buffer_f);
		//read_output_pixels_fc(layer,tile,sharedDram, output_buffer_f);
	}
	PROCESS_F:{
		fully_connected(tile,input_buffer_f,weights_buffer_f,output_buffer_f);
	}
	POST_PROCESS_F:{
		write_output_pixels_fc(layer,tile,sharedDram, output_buffer_f);
	}
}
}
