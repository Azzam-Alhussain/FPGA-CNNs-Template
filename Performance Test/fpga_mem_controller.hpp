#ifndef _FPGA_MEM_CONTROLLER_HPP_
#define _FPGA_MEM_CONTROLLER_HPP_

#include "fpga_top.hpp"

void read_input_pixels( layer_t *layer,tile_specs tile, data_t *dram_in, data_t input_buffer [ROW][COL][CH_IN]);
void read_weight_vector( layer_t *layer,tile_specs tile, data_t *dram_w, data_t weights_buffer[CH_OUT][CH_IN][KER][KER]);
void read_output_pixels(layer_t *layer,tile_specs tile,  data_t *dram_out, data_t output_buffer[ROW][COL][CH_OUT]);
void write_output_pixels(layer_t *layer,tile_specs tile,  data_t *dram_out,data_t output_buffer[ROW][COL][CH_OUT]);
//----------------------------------------------------------------------------------------------------------
void read_input_pixels_fc( layer_t *layer,tile_specs tile, data_t *dram_in, data_t input_buffer [TD_IN]);
void read_output_pixels_fc(layer_t *layer,tile_specs tile, data_t *dram_out, data_t output_buffer[TD_OUT]);
void read_weight_vector_fc( layer_t *layer,tile_specs tile, data_t *dram_w, data_t weights_buffer[TD_OUT][TD_IN]);
void write_output_pixels_fc(layer_t *layer,tile_specs tile,  data_t *dram_out,data_t output_buffer[TD_OUT]);


#endif
