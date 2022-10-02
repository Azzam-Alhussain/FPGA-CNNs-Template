#include "activations.hpp"
void activation(layer_t *layer,data_t* SHARED_DRAM)
{
	std::cout<<"[INFO] "<<" Executing "<<layer->name<<std::endl;
	int offset =0;
	data_t input_pix;
	if(!(strcmp(layer->name,"relu_1")))
	{
		for(int row=0;row<layer->row_in;row++){
			for(int col=0;col<layer->col_in;col++){
				for(int ci=0;ci<layer->ch_in;ci++){
					//read input_pixel
					offset = row * layer->col_in * layer->ch_in + col * layer->ch_in + ci;
					input_pix= SHARED_DRAM[layer->input_offset + offset];
					SHARED_DRAM[layer->output_offset + offset]= relu(input_pix);
					offset++;
				}
			}
		}
	}
	if(!(strcmp(layer->name,"relu_2")))
	{
		for(int co=0;co< layer->ch_out; co++)
		{
			input_pix= SHARED_DRAM[layer->input_offset + co];
			SHARED_DRAM[layer->output_offset + co]= relu(input_pix);
		}
	}

	//std::cout<<"[INFO] "<<layer->name<<" Execution Ends..."<<std::endl;
}
data_t relu(data_t x)
{
	if (x>0){
		return x;
	}
	else{
		return 0;
	}
}
