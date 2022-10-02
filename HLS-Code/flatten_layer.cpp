#include "flatten_layer.hpp"

void flatten_layer(layer_t *layer,data_t* SHARED_DRAM)
{
	std::cout<<"[INFO] "<<" Executing "<<layer->name<<std::endl;
	int offset_in =0;
	int offset_out=0;
	for(int r=0;r<layer->row_in;r++){
		for(int c=0;c<layer->col_in;c++){
			for(int ci=0;ci<layer->ch_in;ci++){
				//read input_pixel
				offset_in = r * layer->col_in * layer->ch_in + c * layer->ch_in + ci;
				data_t input_pix= SHARED_DRAM[layer->input_offset + offset_in];
				//write output_pixel
				//std::cout<<"Input: "<<offset_in<<" Offset: "<<offset_out<<" Pixal Value: "<<input_pix<<std::endl;
				SHARED_DRAM[layer->output_offset + offset_out]=input_pix;
				offset_out++;
			}
		}
	}
}

