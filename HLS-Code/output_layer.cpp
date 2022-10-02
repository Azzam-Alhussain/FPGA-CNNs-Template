#include "output_layer.hpp"
void output_layer(layer_t *layer,data_t* SHARED_DRAM,char classes[num_classes][max_char])
{
	std::cout<<"[INFO] "<<" Executing "<<layer->name<<std::endl;
	data_t output_vector[num_classes];
	data_t soft_vector[num_classes];
	read_output_vector(layer,SHARED_DRAM,output_vector);
/*	if(!(strcmp(layer->name,"soft"))){
		softmax(output_vector,soft_vector);
	}
	if(!(strcmp(layer->name,"dot"))){
		for(int i=0; i<num_classes; i++){
			soft_vector[i] = output_vector[i];
		}
	}*/
	const int N = sizeof(output_vector) / sizeof(data_t);
	int max = std::distance(output_vector, std::max_element(output_vector, output_vector + N));
	//int max =  std::max_element(soft_vector, soft_vector + num_classes) - soft_vector;
	read_outcome(classes,max);
}
void read_output_vector(layer_t* layer, data_t* SHARED_DRAM,data_t output_vector[num_classes]){
	for(int i=0; i<num_classes;i++){
		data_t output= SHARED_DRAM[layer->input_offset + i];
		//std::cout<<i<<"  "<<output<<std::endl;
		output_vector[i]=output;
	}
}
void softmax(data_t output_vector[num_classes],data_t soft_vector[num_classes]){
	float total_expf=0;
	for(int i=0; i<num_classes; i++){
		total_expf += std::exp((float) output_vector[i]);
	}
	for(int i=0; i<num_classes; i++){
		float output =  (exp((float) output_vector[i])/total_expf);
		//std::cout<<i<<"   "<<output<<std::endl;
		soft_vector[i] = (data_t) output;
	}
}
void logsoftmax(data_t output_vector[num_classes],data_t soft_vector[num_classes]){
	float total_expf=0;
	for(int i=0; i<num_classes; i++){
		total_expf += std::exp((float) output_vector[i]);
	}
	for(int i=0; i<num_classes; i++){
		double output = log((double)exp((float) output_vector[i])/total_expf);
		//double output = log10((double)exp((float) output_vector[i])/total_expf);
		std::cout<<i<<"   "<<output<<std::endl;
		soft_vector[i] = (data_t) output;
	}
}
void read_outcome(char classes[num_classes][max_char],int max){
	std::cout<<"[INFO] Prediction: ";
	for(int i=0;i<max_char;i++){
		char out = classes[max][i];
		std::cout<<out;
	}
	std::cout<<std::endl;
}
