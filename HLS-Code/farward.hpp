#ifndef _FARWARD_HPP_
#define _FARWARD_HPP_
#include "network.hpp"

void forward(network_t *net,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM,char classes[num_classes][max_char]);

#endif
