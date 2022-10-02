#ifndef _CONV_Layer_HPP_
#define _CONV_Layer_HPP_

#include "network.hpp"

void conv_layer(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);
void fpga_top_c(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);

#endif
