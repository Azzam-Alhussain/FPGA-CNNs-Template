#include "farward.hpp"
#include "conv_layer.hpp"
#include "pool_layer.hpp"
#include "fc_layer.hpp"
#include "flatten_layer.hpp"
#include "output_layer.hpp"
#include "normalization.hpp"
#include "activations.hpp"

void forward(network_t *net,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM,char classes[num_classes][max_char])
{
	std::cout<<"[INFO] Forward Execution Starts..."<<std::endl;
	for (int i = 0; i < net->num_layers; i++)
	{
		layer_t *layer = &net->layers[i];
		//-----------------------------------------------------------------------------------------
		if(!(strcmp(layer->type,"Convolution"))){
			conv_layer(layer,SHARED_DRAM,WEIGHTS_DRAM);
		}
		if(!(strcmp(layer->type,"Activation"))){
			activation(layer, SHARED_DRAM);
		}
		if(!(strcmp(layer->type,"Normalization"))){
			normalization(layer, SHARED_DRAM,WEIGHTS_DRAM);
		}
		if(!(strcmp(layer->type,"Pooling"))){
			pool_layer(layer, SHARED_DRAM);
		}
		if(!(strcmp(layer->type,"Fully_Connected"))){
			fc_layer(layer, SHARED_DRAM, WEIGHTS_DRAM);
		}
		if(!(strcmp(layer->type,"Flatten"))){
			flatten_layer(layer, SHARED_DRAM);
		}
		if(!(strcmp(layer->type,"Output"))){
			output_layer(layer, SHARED_DRAM,classes);
		}
		//-----------------------------------------------------------------------------------------
	}
	//std::cout<<"[INFO] Forward Execution Ends..."<<std::endl;
}





