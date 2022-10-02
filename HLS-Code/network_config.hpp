#ifndef _NETWORK_CONFIG_H_
#define _NETWORK_CONFIG_H_

#include "network.hpp"
/*
#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
*/
network_t* get_network_configurations();
void add_layers(network_t* my_network,layer_t layer);

void print_layer(layer_t layer);
void print_network_config(network_t* net);
/*void load_rgb_image(cv::Mat image,data_t *input_dram);
void load_grey_image(cv::Mat image,data_t *input_dram);
float calculate_std(cv::Mat image,float mean);
float calculate_mean(cv::Mat image);*/
void normalize_image(data_t *input_dram,data_t mean,data_t std);
float normalize_pixel(float input, float mean,float std);
void load_all_input_parameters(network_t* net);
void load_weights_from_file(const char *filename,data_t *weights_dram);
void read_input_image(const char *filename,data_t *input_dram);
void load_input_image(network_t* net,const char *filename);
void load_classes_from_file(const char *filename,char classes[num_classes][max_char]);
void load_image_from_file(const char* image_name,data_t *input_dram);


#endif
