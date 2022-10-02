#ifndef _ACTIVATIONS_HPP_
#define _ACTIVATIONS_HPP_

#include "network.hpp"
void activation(layer_t *layer,data_t* SHARED_DRAM);
data_t relu(data_t x);


#endif
