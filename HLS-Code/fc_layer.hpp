#ifndef _FC_LAYER_HPP_
#define _FC_LAYER_HPP_

#include "network.hpp"

void fc_layer(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);
void fpga_top_f(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);


#endif
