#include "pool_layer.hpp"

void pool_layer(layer_t *layer,data_t* SHARED_DRAM)
{
	std::cout<<"[INFO] "<<" Executing "<<layer->name<<std::endl;
	int offset_in=0;
	int offset_out=0;
	int win_size = layer->kernal * layer->kernal;
	data_t* window = (data_t*) malloc(sizeof(data_t) * win_size);
	data_t input_pixel=0;
	data_t output_pixel=0;
	for(int co=0;co<layer->ch_out;co++){
		for(int row=0;row<layer->row_out; row++){
			for(int col=0;col<layer->col_out; col++){
				int count=0;
				POOL_KI:for(int i=0;i<layer->kernal;i++){
					POOL_KJ:for(int j=0;j<layer->kernal;j++){
						//read input pixel
						int RoW = layer->stride * row + i;
						int CoL = layer->stride * col + j;
						//std::cout<<"Input Pixel: "<<co <<"  "<< RoW <<"  "<<CoL <<std::endl;
						offset_in = ( RoW * layer->col_in * layer->ch_in ) + ( CoL * layer->ch_in ) + co;
						input_pixel = SHARED_DRAM[layer->input_offset+offset_in];
						window[count]=input_pixel;
						count++;
				}}
				//std::cout<<std::endl;std::cout<<std::endl;
				//std::cout<<"Input Pixel: "<<co<<"  "<<row<<"  "<<col<<std::endl;
				data_t output_pixel = pool_array(window,win_size);
				offset_out=(row * layer->col_out * layer->ch_out) + (col * layer->ch_out) + co;
				SHARED_DRAM[layer->output_offset+offset_out]=output_pixel;
				//std::cout<<output_pixel<<std::endl;
	}}}
	free(window);
	//std::cout<<"[INFO] "<<layer->name<<" Execution Ends..."<<std::endl;
}
//-----------------------------------------------------------------------------------
data_t pool_array(data_t* window,int win_size)
{
	data_t max_elem=0;
    for(int i=0;i<win_size; ++i)
    {
       // Change < to > if you want to find the smallest element
       if(window[0] < window[i])
    	   window[0] = window[i];
    }
    max_elem=window[0];
	return max_elem;
}
