#include "compute_unit.hpp"

void fpga_top_f(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM){
	int weight_offset=0;
	data_t input_neuron=0;
	data_t output_neuron=0;
	for(int co=layer->co_start;co< layer->co_end; co++){
		data_t dot_product = 0;
		for(int ci=layer->ci_start;ci<layer->ci_end ;ci++){
			//read input neuron
			input_neuron = SHARED_DRAM[layer->input_offset + ci];
			//read weight value
			weight_offset = co * layer->ch_in + ci;
			data_t weight_value = WEIGHTS_DRAM[layer->weights_offset + weight_offset];
			//perform dot product
			dot_product += input_neuron * weight_value;
		}
		//write output neuron
		output_neuron = dot_product + WEIGHTS_DRAM[layer->bais_offset + co];
		SHARED_DRAM[layer->output_offset + co] = output_neuron;
		//std::cout<<output_neuron<<std::endl;
		//std::cout<<"Output: "<<co<<" = "<<output_neuron<<std::endl;
	}
}
void fpga_top_c(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM){
	int offset_out=0;
	int offset_in=0;
	data_t input_pixel=0;
	data_t weight_value=0;
	for(int row=0; row < layer->row_out; row++){
		for(int col=0; col < layer->col_out; col++){
		    for(int co=layer->co_start; co < layer->co_end; co++){
		    	data_t output_pixel=0;
		    	data_t dot_product=0;
		    	for(int ci=layer->ci_start; ci < layer->ci_end;ci++){
				   for(int i= -(layer->kernal/2); i<= (layer->kernal/2); i++){
					   for(int j= -(layer->kernal/2);j<= (layer->kernal/2); j++){
						   int RoW = layer->stride * row + i + layer->kernal/2;
						   int CoL = layer->stride * col + j + layer->kernal/2;
						   offset_in = RoW * layer->col_in * layer->ch_in + CoL * layer->ch_in + ci;
						   input_pixel = SHARED_DRAM[layer->input_offset+offset_in];
						   int K_I = layer->kernal - ((layer->kernal / 2)+i) - 1; //rotate the filter
						   int K_J = layer->kernal - ((layer->kernal / 2)+j) - 1; // by 180 degree
						   int offset_we = (co * layer->ch_in * layer->kernal * layer->kernal) +
										   (ci * layer->kernal * layer->kernal) +
										   (K_I * layer->kernal) + K_J;
						   weight_value = WEIGHTS_DRAM[layer->weights_offset+offset_we];
						   //std::cout<<input_pixel<<"  "<<weight_value<<std::endl;
						   //std::cout<<"Input Pixel: "<<RoW<<"  "<<CoL<<"  "<<ci<<"  Weight Value:"<<co<<"  "<<ci<<"  "<<K_I<<"  "<<K_J<<std::endl;
						   //----------------------- Dot Product --------------------------------------
						   dot_product += input_pixel * weight_value;
						}
				    }
		    	}
 				output_pixel = dot_product + WEIGHTS_DRAM[layer->bais_offset + co];
		    	offset_out = (row * layer->col_out * layer->ch_out)+(col * layer->ch_out) + co;
			   	SHARED_DRAM[layer->output_offset + offset_out] = output_pixel;
			   	//std::cout<<"Output: "<<row<<"  "<<col<<"  "<<co<<" = "<<output_pixel<<std::endl;
			}
		}
	}
}
