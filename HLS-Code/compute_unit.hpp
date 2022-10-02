#ifndef _COMPUTE_UNIT_HPP_
#define _COMPUTE_UNIT_HPP_
#include "network.hpp"
void fpga_top_c(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);
void fpga_top_f(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);
#endif
