#include "fpga_top.hpp"
#include "fpga_mem_controller.hpp"
#include "fpga_conv.hpp"
#include "fpga_fc.hpp"
void fpga_top(layer_t *layer,tile_specs tile, data_t *dram_in,data_t *dram_out, data_t *dram_w,int type)
{
//----------------------------------------------------------------------
#pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=type bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=layer bundle=CTRL_BUS
#pragma HLS INTERFACE s_axilite port=tile bundle=CTRL_BUS
#pragma HLS INTERFACE m_axi depth=18000 port=dram_in offset=slave bundle=DATA_BUS
#pragma HLS INTERFACE m_axi depth=18000 port=dram_out offset=slave bundle=DATA_BUS
#pragma HLS INTERFACE m_axi depth=1800 port=dram_w offset=slave bundle=DATA_BUS
//----------------------------------------------------------------------
data_t input_buffer[ROW][COL][CH_IN];
#pragma HLS ARRAY_PARTITION variable=input_buffer complete factor=20 dim=3
data_t weights_buffer[CH_OUT][CH_IN][KER][KER];
#pragma HLS ARRAY_PARTITION variable=weights_buffer complete factor=20 dim=2
data_t output_buffer[ROW][COL][CH_OUT];
#pragma HLS ARRAY_PARTITION variable=output_buffer1 complete factor=40 dim=3
data_t output_buffer2[ROW][COL][CH_OUT];
#pragma HLS ARRAY_PARTITION variable=output_buffer2 complete factor=40 dim=3
//----------------------------------------------------------------------
data_t input_buffer_fc[TD_IN];
#pragma HLS ARRAY_PARTITION variable=input_buffer_fc complete factor=20 dim=1
data_t weights_buffer_fc[TD_OUT][TD_IN];
#pragma HLS ARRAY_PARTITION variable=weights_buffer_fc complete factor=20 dim=2
data_t output_buffer_fc[TD_OUT];
#pragma HLS ARRAY_PARTITION variable=output_buffer_fc2 complete factor=40 dim=1
data_t output_buffer_fc1[TD_OUT];
#pragma HLS ARRAY_PARTITION variable=output_buffer_fc1 complete factor=40 dim=1
//----------------------------------------------------------------------
//std::cout<<"Top Function Starts for  "<<layer->name<<std::endl;
if(type==0){

	read_input_pixels(layer,tile,dram_in, input_buffer);
	read_weight_vector(layer,tile,dram_w, weights_buffer);
	convolution(input_buffer,weights_buffer,output_buffer);
	write_output_pixels(layer,tile,dram_out, output_buffer);

}
if(type==1){
	read_input_pixels_fc(layer,tile,dram_in, input_buffer_fc);
	read_weight_vector_fc(layer,tile,dram_w, weights_buffer_fc);
	fully_connected(input_buffer_fc,weights_buffer_fc,output_buffer_fc);
	write_output_pixels_fc(layer,tile,dram_out, output_buffer_fc);
}
//std::cout<<"Top Function Ends "<<layer->name<<std::endl;
}
