#ifndef _FPGA_TOP_HPP_
#define _FPGA_TOP_HPP_

#include "network.hpp"
//------------------------------------------
const int ROW=10;
const int COL=10;
const int KER=11;
const int CH_IN=30;
const int CH_OUT=55;
const int TD_IN=200;
const int TD_OUT=200;
//------------------------------------------
void fpga_top(layer_t *layer,tile_specs tile, data_t *dram_in,data_t *dram_out, data_t *dram_w,int type);

#endif
