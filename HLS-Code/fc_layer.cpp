#include "fc_layer.hpp"
#include "compute_unit.hpp"
#include "fpga_top.hpp"

void fc_layer(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM)
{
	std::cout<<"[INFO] "<<" Executing "<<layer->name<<std::endl;
	int type=1;
	static int ci_start=0;
	static int ci_end=0;
	static int co_start=0;
	static int co_end=0;
	int count=0;
	data_t* SHRED_DRAM = (data_t*) malloc(sizeof(data_t) * (( TD_IN )+( TD_OUT )));
	data_t* WEGHTS_DRAM = (data_t*) malloc(sizeof(data_t) * (TD_IN * TD_OUT));
	for(int s=0; s<layer->set; s++){
		ci_end   = ci_start + (layer->ch_in/layer->set);
		co_end   = co_start + (layer->ch_out/layer->set);
		//-----------------------------------------------------------------------------------
		layer->ci_start = ci_start;
		layer->ci_end   = ci_end;
		layer->co_start = co_start;
		layer->co_end   = co_end;
		fpga_top_f(layer,SHARED_DRAM,WEIGHTS_DRAM);
		//-----------------------------------------------------------------------------------
		tile_specs dot_t;
		dot_t.R_min=0;
		dot_t.R_max=0;
		dot_t.C_min=0;
		dot_t.C_max=0;
		for(int to=layer->co_start; to<std::min(to+TD_OUT,layer->co_end); to+=TD_OUT){
		    for(int ti=layer->ci_start; ti<std::min(ti+TD_IN,layer->ci_end); ti+=TD_IN){
				std::cout<<"[INFO]: "<<count++;
				dot_t.M_min=0;
				dot_t.M_max=TD_OUT;
				dot_t.N_min=0;
				dot_t.N_max=TD_IN;
				fpga_top(layer,dot_t,SHRED_DRAM,WEGHTS_DRAM,type);
			}
		}
		//-----------------------------------------------------------------------------------
		ci_start = ci_end + 1;
		co_start = co_end + 1;
	}
	ci_start=0;
	ci_end=0;
	co_start=0;
	co_end=0;
	free(SHRED_DRAM);
	free(WEGHTS_DRAM);
}
