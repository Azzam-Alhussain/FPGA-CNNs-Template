#ifndef _FPGA_TOP_HPP_
#define _FPGA_TOP_HPP_

#include "network.hpp"
//------------------------------------------------------------------------------------------------------
const int ROW=10;
const int COL=10;
const int KER=11;
const int CH_IN=30;
const int CH_OUT=40;
const int TD_IN=400;
const int TD_OUT=400;
//------------------------------------------------------------------------------------------------------
void fpga_top(layer_t *layer,tile_specs tile,data_t *sharedDram, data_t *weightDram,int type);
//------------------------------------------------------------------------------------------------------

#endif
