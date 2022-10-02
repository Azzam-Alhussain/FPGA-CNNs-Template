#include "fpga_mem_controller.hpp"

void read_input_pixels(layer_t *layer,tile_specs tile,  data_t *sharedDram,data_t input_buffer [ROW][COL][CH_IN]){
//std::cout<<"Loading IFM for  "<<layer->type<<std::endl;
#pragma HLS INLINE
int dram_offset_input=0;//layer->input_offset;
int offset_in=0;
int trr_in=0;
TR_IN:for(int tr=tile.R_min;tr<tile.R_max;tr++){
#pragma HLS LOOP_TRIPCOUNT min=10 max=20
		int tcc_in=0;
		TC_IN:for(int tc=tile.C_min;tc<tile.C_max;tc++){
#pragma HLS LOOP_TRIPCOUNT min=10 max=20
			int tii_in=0;
			TI_IN:for(int ci=tile.N_min;ci<tile.N_max;ci++){
#pragma HLS PIPELINE
#pragma HLS LOOP_TRIPCOUNT  max=20
				offset_in++;//=( tr * layer->col_in * layer->ch_in ) + ( tc * layer->ch_in ) + ci;
				input_buffer[trr_in][tcc_in][tii_in] = sharedDram[dram_offset_input + offset_in];
				tii_in++;
			}tcc_in++;
		}trr_in++;
	}
}

void read_weight_vector( layer_t *layer,tile_specs tile, data_t *weightDram,data_t weights_buffer[CH_OUT][CH_IN][KER][KER]){
//std::cout<<"Loading Weights for  "<<layer->type<<std::endl;
#pragma HLS INLINE
int dram_offset_weight=0;//layer->weights_offset;
int offset_w=0;
int too_w=0;
TO_W:for(int co=tile.M_min;co<tile.M_min;co++){
	#pragma HLS LOOP_TRIPCOUNT  max=40
		int tii_w=0;
		TI_W:for(int ci=tile.N_min;ci<tile.N_max;ci++){
	#pragma HLS LOOP_TRIPCOUNT  max=20
			int ki_w=0;
			KI_W:for(int i=0;i<KER;i++){
	#pragma HLS LOOP_TRIPCOUNT min=3 max=11
				int kj_w=0;
				K_W:for(int j=0;j<KER;j++){
	#pragma HLS LOOP_TRIPCOUNT min=3 max=11
					#pragma HLS PIPELINE
					offset_w++;/* = ( co * layer->ch_out * layer->kernal * layer->kernal )+
							( ci * layer->kernal * layer->kernal ) + i * layer->kernal + j;*/
					weights_buffer[too_w][tii_w][ki_w][kj_w] = weightDram[dram_offset_weight+offset_w];
					kj_w++;
				}ki_w++;
			}tii_w++;
		}too_w++;
	}
}
void write_output_pixels( layer_t *layer,tile_specs tile, data_t *sharedDram,data_t output_buffer[ROW][COL][CH_OUT]){
//std::cout<<"Storing OFM for  "<<layer->type<<std::endl;
#pragma HLS INLINE
int offset_out=0;
int dram_output_offset=0;//layer->output_offset;
int trr_out=0;
TR_OUT:for(int tr=tile.R_min;tr<tile.R_max;tr++){
#pragma HLS LOOP_TRIPCOUNT  max=20
		int tcc_out=0;
		TC_OUT:for(int tc=tile.C_min;tc<tile.C_max;tc++){
#pragma HLS LOOP_TRIPCOUNT max=20
			int too_out=0;
			TO_OUT:for(int co=tile.M_min;co<tile.M_max;co++){
#pragma HLS LOOP_TRIPCOUNT  max=40
#pragma HLS PIPELINE
					offset_out++; //= (tr * layer->col_out * layer->ch_out)+(tc * layer->ch_out)+co;
					sharedDram[dram_output_offset+offset_out]=output_buffer[trr_out][tcc_out][too_out];
					too_out++;
				}tcc_out++;
		}trr_out++;
	}
}

void read_output_pixels( layer_t *layer,tile_specs tile, data_t *sharedDram,data_t output_buffer[ROW][COL][CH_OUT]){
//std::cout<<"Storing OFM for  "<<layer->type<<std::endl;
#pragma HLS INLINE
int offset_out=0;
int dram_output_offset= 0;//layer->output_offset;
int trr_out=0;
TR_OUT:for(int tr=tile.R_min;tr<tile.R_max;tr++){
#pragma HLS LOOP_TRIPCOUNT  max=20
		int tcc_out=0;
		TC_OUT:for(int tc=tile.C_min;tc<tile.C_max;tc++){
#pragma HLS LOOP_TRIPCOUNT max=20
			int too_out=0;
			TO_OUT:for(int co=tile.M_min;co<tile.M_max;co++){
#pragma HLS LOOP_TRIPCOUNT  max=40
#pragma HLS PIPELINE
					offset_out++;// = (tr * layer->col_out * layer->ch_out)+(tc * layer->ch_out)+co;
					output_buffer[trr_out][tcc_out][too_out]=sharedDram[dram_output_offset+offset_out];
					too_out++;
				}tcc_out++;
		}trr_out++;
	}
}
//-----------------------------------------------------------------------------------------------------------------------
void read_input_pixels_fc( layer_t *layer,tile_specs tile, data_t *sharedDram, data_t input_buffer[TD_IN]){
//std::cout<<"Loading IFM for "<<layer->type<<std::endl;
#pragma HLS INLINE
	int offset_in=0;
	int dram_input_offset = 0;// layer->input_offset;
	int temp=0;
	TI_IN_FC:for(int ci=tile.N_min;ci<tile.N_max;ci++){
#pragma HLS LOOP_TRIPCOUNT  max=200
#pragma HLS PIPELINE
		input_buffer[temp] = sharedDram[dram_input_offset+ci];
		temp++;
	}
}
void read_weight_vector_fc( layer_t *layer,tile_specs tile, data_t *weightDram, data_t weights_buffer[TD_OUT][TD_IN]){
//std::cout<<"Loading Weights for "<<layer->type<<std::endl;
#pragma HLS INLINE
	int dram_offset_weight =0;// layer->weights_offset;
	int offset_w = 0;
	int temp1=0;
	TO_W_FC:for(int co=tile.M_min;co<tile.M_max;co++){
		int temp2=0;
#pragma HLS LOOP_TRIPCOUNT  max=200
		TI_W_FC:for(int ci=tile.N_min;ci<tile.N_max;ci++){
#pragma HLS PIPELINE
#pragma HLS LOOP_TRIPCOUNT min=96 max=200
			offset_w++;// = co * layer->ch_in + ci;
			weights_buffer[temp1][temp2] = weightDram[dram_offset_weight+offset_w];
			temp2++;
		}temp1++;
	}
}
void write_output_pixels_fc(layer_t *layer,tile_specs tile,  data_t *sharedDram,data_t output_buffer[TD_OUT]){
//std::cout<<"Storing OFM for  "<<layer->type<<std::endl;
#pragma HLS INLINE
	int offset_out=0;
	int temp=0;
	int dram_output_offset =0;// layer->output_offset;
	TI_OUT_FC:for(int co=tile.M_min;co<tile.M_max;co++){
#pragma HLS LOOP_TRIPCOUNT max=200
#pragma HLS PIPELINE
		sharedDram[dram_output_offset+co]=output_buffer[temp];
		temp++;
	}
}
void read_output_pixels_fc(layer_t *layer,tile_specs tile,  data_t *sharedDram,data_t output_buffer[TD_OUT]){
//std::cout<<"Storing OFM for  "<<layer->type<<std::endl;
#pragma HLS INLINE
	int offset_out=0;
	int temp=0;
	int dram_output_offset = 0;// layer->output_offset;
	TI_OUT_FC:for(int co=tile.M_min;co<tile.M_max;co++){
#pragma HLS LOOP_TRIPCOUNT max=200
#pragma HLS PIPELINE
		output_buffer[temp] = sharedDram[dram_output_offset+co];
		temp++;
	}
}
