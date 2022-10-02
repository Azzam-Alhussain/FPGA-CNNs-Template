#include "network.hpp"
#include "network_config.hpp"
#include "farward.hpp"
int main()
{
	network_t* trained_net = get_network_configurations();
	//print_network_config(trained_net);
	std::cout<<"[INFO] Total Neurons in Network: "<<trained_net->total_neurons<<std::endl;
	std::cout<<"[INFO] Total Weights in Network: "<<trained_net->total_weights<<std::endl;
	data_t* WEIGHTS_DRAM = (data_t*) malloc(sizeof(data_t) * trained_net->total_weights);
	data_t* SHARED_DRAM = (data_t*) malloc(sizeof(data_t) * trained_net->total_neurons);
	const char* image_name = "test4.txt";
	load_image_from_file(image_name,SHARED_DRAM);
	const char* weights_file = "alexnet_weights.txt";
	load_weights_from_file(weights_file,WEIGHTS_DRAM);
	char classes[num_classes][max_char];
	const char* classes_file = "Classes.txt";
	load_classes_from_file(classes_file,classes);
	forward(trained_net,SHARED_DRAM,WEIGHTS_DRAM,classes);/**/
	free(WEIGHTS_DRAM);
	free(SHARED_DRAM);
	return 0;
}

