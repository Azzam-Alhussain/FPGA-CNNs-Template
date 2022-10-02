#ifndef _NORMALIZATION_HPP_
#define _NORMALIZATION_HPP_
#include "network.hpp"
void normalization(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);
void inter_lrn(layer_t* layer,data_t* SHARED_DRAM);
//void intra_lrn(layer_t* layer,data_t* SHARED_DRAM);
//void batch_norm(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM);
#endif

