#ifndef _OUTPUT_LAYER_HPP_
#define _OUTPUT_LAYER_HPP_

#include "network.hpp"


void output_layer(layer_t *layer,data_t* SHARED_DRAM,char classes[num_classes][max_char]);
void read_outcome(char classes[num_classes][max_char],int max);
void read_output_vector(layer_t* layer, data_t* SHARED_DRAM,data_t output_vector[num_classes]);
void softmax(data_t output_vector[num_classes],data_t soft_vector[num_classes]);
#endif
