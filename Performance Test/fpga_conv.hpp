#ifndef _FPGA_CONV_HPP_
#define _FPGA_CONV_HPP_

#include "fpga_top.hpp"

void convolution(data_t input[ROW][COL][CH_IN],data_t weights[CH_OUT][CH_IN][KER][KER],data_t output[ROW][COL][CH_OUT]);
void read_input_vector_conv(data_t input[ROW][COL][CH_IN],data_t input_vec[CH_IN],int row,int col,int i, int j);
void read_weight_vector_conv(data_t weights[CH_OUT][CH_IN][KER][KER],data_t weights_vec[CH_OUT][CH_IN],int i,int j);
void write_output_vector_conv(data_t output[ROW][COL][CH_OUT],data_t output_vec[CH_OUT],int row,int col);

#endif
