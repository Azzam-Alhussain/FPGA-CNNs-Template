#include "conv_layer.hpp"
#include "compute_unit.hpp"
#include "fpga_top.hpp"

void conv_layer(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM)
{
	std::cout<<"[INFO] "<<" Executing "<<layer->name<<std::endl;
	int type=0;
	//data_t* SHARED_DRAM_OUT = (data_t*) malloc(sizeof(data_t) * ROW * COL * CH_OUT);
	static int ci_start=0;
	static int ci_end=0;
	static int co_start=0;
	static int co_end=0;
	int count=0;
	data_t* SHRED_DRAM = (data_t*) malloc(sizeof(data_t) * (( ROW * COL * CH_IN )+( ROW * COL* CH_OUT )));
	data_t* WEGHTS_DRAM = (data_t*) malloc(sizeof(data_t) * (CH_IN * CH_OUT * KER * KER));
	for(int s=0; s<layer->set; s++){
		ci_end   = ci_start + (layer->ch_in/layer->set);
		co_end   = co_start + (layer->ch_out/layer->set);
		//-----------------------------------------------------------------------------------
		layer->ci_start = ci_start;
		layer->ci_end   = ci_end;
		layer->co_start = co_start;
		layer->co_end   = co_end;
		fpga_top_c(layer,SHARED_DRAM,WEIGHTS_DRAM);
		//-----------------------------------------------------------------------------------
		tile_specs conv_t;
		int t=0;
		for(int tr=0; tr<std::min(tr+ROW,layer->row_out) ; tr+=ROW){
			for(int tc=0; tc<std::min(tc+COL,layer->col_out);tc+=COL){
				for(int to=layer->co_start;to<std::min(to+CH_OUT,layer->ch_out);to+=CH_OUT){
					for(int ti=layer->ci_start;ti<std::min(ti+CH_IN,layer->ci_end);ti+=CH_IN){
					std::cout<<"[INFO]: "<<count++;
					conv_t.R_min=0;
					conv_t.R_max=ROW;
					conv_t.C_min=0;
					conv_t.C_max=COL;
					conv_t.M_max=0;
					conv_t.N_max=CH_OUT;
					conv_t.N_min=0;
					conv_t.N_max=CH_IN;
					fpga_top(layer,conv_t,SHRED_DRAM,WEGHTS_DRAM,type);
					}
				}
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
