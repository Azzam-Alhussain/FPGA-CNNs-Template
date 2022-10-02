#ifndef _FPGA_FC_HPP_
#define _FPGA_FC_HPP_

#include "fpga_top.hpp"

void fully_connected(tile_specs tile,data_t input[TD_IN],data_t weights[TD_OUT][TD_IN],data_t output[TD_OUT]);
void read_input_vector_fc(data_t input[TD_IN],data_t input_vec[CH_IN],int ci_min,int ci_max);
void write_output_vector_fc(data_t output[TD_OUT],data_t output_vec[CH_OUT],int co_min,int co_max);
void read_weight_vector_fc(data_t weights[TD_OUT][TD_IN],data_t weights_vec[CH_OUT][CH_IN],int co_min,int co_max,int ci_min,int ci_max);

#endif
