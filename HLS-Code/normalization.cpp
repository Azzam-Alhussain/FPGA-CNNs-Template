#include "normalization.hpp"
void normalization(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM)
{
	inter_lrn(layer, SHARED_DRAM);
	/*	if(!(strcmp(layer->name,"LRN1"))){
		inter_lrn(layer, SHARED_DRAM);
	}
	if(!(strcmp(layer->name,"LRN2"))){
		intra_lrn(layer, SHARED_DRAM);
	}
	if(!(strcmp(layer->name,"B_NORM"))){
		batch_norm(layer, SHARED_DRAM,WEIGHTS_DRAM);
	}*/
}
void inter_lrn(layer_t* layer,data_t* SHARED_DRAM)
{
	std::cout<<"[INFO] "<<layer->name<<" Execution Starts..."<<std::endl;
	//------------------------------------------
	double k =2;
	double alpha = 0.0004;
	double  beta = 0.75;
	const int  c_n =5;
	//------------------------------------------
	int offset_in=0;
	int offset_out=0;
	for(int row=0;row<layer->row_out; row++){
		for(int col=0;col<layer->col_out; col++){
			for(int co=0;co<layer->ch_out;co++){
				offset_in = row * layer->col_out * layer->ch_out + col * layer->ch_out + co;
				double input_pix_i= (double) SHARED_DRAM[layer->input_offset + offset_in];
				double sum_input_square=0;
				if(c_n%2==0){
					for(int j=std::max(0,co-c_n/2); j<std::min(layer->ch_out,co+c_n/2); j++){
						offset_in = row * layer->col_out * layer->ch_out + col * layer->ch_out + j;
						double input_pix_j= (double) SHARED_DRAM[layer->input_offset + offset_in];
						double input_square=input_pix_j*input_pix_j;
						sum_input_square +=input_square;
					}
				}
				if(c_n%2!=0){
					for(int j=std::max(0,co-c_n/2); j<=std::min(layer->ch_out,co+c_n/2); j++){
						offset_in = row * layer->col_out * layer->ch_out + col * layer->ch_out + j;
						double input_pix_j= (double) SHARED_DRAM[layer->input_offset + offset_in];
						double input_square=input_pix_j*input_pix_j;
						sum_input_square +=input_square;
					}
				}
				double val =  k + alpha * sum_input_square;
				double output_pix = input_pix_i / (pow(val,beta));
				offset_out = row * layer->col_out * layer->ch_out + col * layer->ch_out + co;
				SHARED_DRAM[layer->output_offset + offset_out] = (data_t) output_pix;
			}
		}
	}
	//std::cout<<"[INFO] "<<layer->name<<" Execution Ends..."<<std::endl;
}





/*
void intra_lrn(layer_t* layer,data_t* SHARED_DRAM)
{
	std::cout<<"[INFO] "<<layer->name<<" Not Coded as Yet..."<<std::endl;
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
void batch_norm(layer_t* layer,data_t* SHARED_DRAM,data_t* WEIGHTS_DRAM)
{
	std::cout<<"[INFO] "<<layer->name<<" Not Coded as Yet..."<<std::endl;
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
*/
