#ifndef _NETWORK_HPP_
#define _NETWORK_HPP_


#include <iostream>
#include <string>
#include "fstream"
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <math.h>



#include <ap_fixed.h>

//------------------------------------------
typedef ap_fixed<16, 2> data_t;
//typedef float data_t;
//------------------------------------------
const int Height=224;
const int Width =224;
const int Dimension=3;
//------------------------------------------
const int Total_Layers = 7;  //MNIST
//------------------------------------------
const int NAME_LEN=10;
const int TYPE_LEN=20;
//-----------------------------------------
const int num_classes=1000;
const int max_char = 100;
//-------------------------------------------
const bool FPGA = true;
//-------------------------------------------
struct tile_specs
{
	int R_min;
	int R_max;
	int C_min;
	int C_max;
	int M_min;
	int M_max;
	int N_min;
	int N_max;
	tile_specs():R_min(0),R_max(0),C_min(0),C_max(0),M_min(0),M_max(0),N_min(0),N_max(0){}
	tile_specs (int rMin,int rMax,int cMin,int cMax,int mMin,int mMax,int nMin,int nMax):
		R_min(rMin),R_max(rMax),C_min(cMin),C_max(cMax),M_min(mMin),M_max(mMax),N_min(nMin),N_max(nMax)
	{}
};

struct layer_t
{
	char name[NAME_LEN];
	char type[TYPE_LEN];
	int ch_in;
	int ch_out;
	int kernal;
	int stride;
	int pad;
	int row_out;
	int col_out;
	int row_in;
	int col_in;
	int set;
	int weights_offset;
	int bais_offset;
	int input_offset;
	int output_offset;
	int ci_start;
	int ci_end;
	int co_start;
	int co_end;
	layer_t():ch_in(0),ch_out(0),kernal(0),stride(0),pad(0),
		row_out(0),col_out(0),row_in(0),col_in(0),weights_offset(0),bais_offset(0),input_offset(0),output_offset(0),set(0),
		ci_start(0),ci_end(0),co_start(0),co_end(0){}
	layer_t(const char *n,const char *t,int chin,int chout,int ker,int str,int p,int s):
		ch_in(chin),ch_out(chout),kernal(ker),stride(str),pad(p),set(s)
		{
			for(int i=0;i<NAME_LEN;i++){
				name[i]=n[i];
			}
			for(int i=0;i<TYPE_LEN;i++){
				type[i]=t[i];
			}
			row_out=0;
			col_out=0;
			row_in=0;
			col_in=0;
			weights_offset=0;
			bais_offset=0;
			input_offset=0;
			output_offset=0;
			ci_start=0;
			ci_end=0;
			co_start=0;
			co_end=0;
		}
};
struct network_t
{
	layer_t*  layers;
	int       num_layers;
	int 	  total_neurons;
	int 	  total_weights;
	network_t(int max_layers):num_layers(0),total_neurons(0),total_weights(0)
	{
		layers  =  (layer_t*) malloc((sizeof(layer_t)) * max_layers);
	}
};


#endif
