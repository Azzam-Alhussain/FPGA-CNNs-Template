#ifndef _POOL_LAYER_HPP_
#define _POOL_LAYER_HPP_

#include "network.hpp"

void pool_layer(layer_t *layer,data_t* SHARED_DRAM);
data_t pool_array(data_t* window,int win_size);

#endif
