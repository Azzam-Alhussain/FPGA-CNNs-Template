#include "network_config.hpp"

network_t* get_network_configurations(){
	network_t* net = new network_t(22); //AlexNet
							//name		      type				ch_in	ch_out	 Ker    str    pad	set
	add_layers(net,layer_t( "conv1",       "Convolution",           3,       64,    11,     4,   2,	  1));
	add_layers(net,layer_t("relu_1",        "Activation",          64,       64,     1,     1,   1,	  1));
	add_layers(net,layer_t( "norm1",     "Normalization",          64,       64,     3,     1,   0,	  1));
	add_layers(net,layer_t( "pool1",           "Pooling",          64,       64,     3,     2,   0,	  1));
	add_layers(net,layer_t( "conv2",       "Convolution",          64,      192,     5,     1,   2,	  2));
	add_layers(net,layer_t(  "relu_1",      "Activation",         192,      192,     1,     1,   1,	  1));
	add_layers(net,layer_t( "norm2",     "Normalization",         192,      192,     3,     1,   0,	  0));
	add_layers(net,layer_t( "pool2",           "Pooling",         192,      192,     3,     2,   0,	  1));
	add_layers(net,layer_t( "conv3",       "Convolution",         192,      384,     3,     1,   1,	  2));
	add_layers(net,layer_t(  "relu_1",      "Activation",         384,      384,     1,     1,   1,	  1));
	add_layers(net,layer_t( "conv4",       "Convolution",         384,      256,     3,     1,   1,	  2));
	add_layers(net,layer_t(  "relu_1",    	  "Activation",       256,      256,     1,     1,   1,	  1));
	add_layers(net,layer_t( "conv5",       "Convolution",         256,      256,     3,     1,   1,	  2));
	add_layers(net,layer_t(  "relu_1",        "Activation",       256,      256,     1,     1,   1,	  1));
	add_layers(net,layer_t( "pool3",           "Pooling",         256,      256,     3,     2,   0,	  1));
	add_layers(net,layer_t( "flat1",           "Flatten",         256,        0,     0,     1,   0,	  1));
	add_layers(net,layer_t(   "fc1",   "Fully_Connected",           0,     4096,     1,     1,   0,	  1));
	add_layers(net,layer_t(  "relu_2",        "Activation",      4096,     4096,     1,     1,   1,	  1));
	add_layers(net,layer_t(   "fc2",    "Fully_Connected",          0,     4096,     1,     1,   0,	  1));
	add_layers(net,layer_t(  "relu_2",        "Activation",      4096,     4096,     1,     1,   1,	  1));
	add_layers(net,layer_t(   "fc3",   "Fully_Connected",           0,     1000,     1,     1,   0,	  1));
	add_layers(net,layer_t(  "output",            "Output",         0,     1000,     1,     1,   0,	  1));
	return net;
	/*
	network_t* net = new network_t(39); //VGG16
							//name		      type				ch_in	    ch_out	 Ker     str  pad    set
	add_layers(net,layer_t( "conv1_1",       "Convolution",          3,        64,    3,     1,     1,	  1));
	add_layers(net,layer_t(  "relu_1",        "Activation",         64,        64,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv1_2",       "Convolution",         64,        64,    3,     1,     1,	  1));
	add_layers(net,layer_t(  "relu_1",        "Activation",         64,        64,    1,     1,     0,    1));
	add_layers(net,layer_t(   "pool1",           "Pooling",         64,        64,    2,     2,     0,	  1));
	add_layers(net,layer_t( "conv2_1",       "Convolution",         64,       128,    3,     1,     1,	  1));
	add_layers(net,layer_t(  "relu_1",        "Activation",        128,       128,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv2_2",       "Convolution",        128,       128,    3,     1,     1,	  1));
	add_layers(net,layer_t(  "relu_1",        "Activation",        128,       128,    1,     1,     0,    1));
	add_layers(net,layer_t(   "pool2",           "Pooling",        128,       128,    2,     2,     0,	  1));
	add_layers(net,layer_t( "conv3_1",       "Convolution",        128,       256,    3,     1,     1,	  1));
	add_layers(net,layer_t(  "relu_1",        "Activation",        256,       256,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv3_2",       "Convolution",        256,       256,    3,     1,     1,	  1));
	add_layers(net,layer_t(  "relu_1",        "Activation",        256,       256,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv3_3",       "Convolution",        256,       256,    3,     1,     1,	  1));
	add_layers(net,layer_t(  "relu_1",        "Activation",        256,       256,    1,     1,     0,    1));
	add_layers(net,layer_t(   "pool3",           "Pooling",        256,       256,    2,     2,     0,	  1));
	add_layers(net,layer_t( "conv4_1",       "Convolution",        256,       512,    3,     1,     1,	  2));
	add_layers(net,layer_t(  "relu_1",        "Activation",        512,       512,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv4_2",       "Convolution",        512,       512,    3,     1,     1,	  2));
	add_layers(net,layer_t(  "relu_1",        "Activation",        512,       512,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv4_3",       "Convolution",        512,       512,    3,     1,     1,	  2));
	add_layers(net,layer_t(  "relu_1",        "Activation",        512,       512,    1,     1,     0,    1));
	add_layers(net,layer_t(   "pool4",           "Pooling",        512,       512,    2,     2,     0,	  1));
	add_layers(net,layer_t( "conv5_1",       "Convolution",        512,       512,    3,     1,     1,	  2));
	add_layers(net,layer_t(  "relu_1",        "Activation",        512,       512,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv5_2",       "Convolution",        512,       512,    3,     1,     1, 	  2));
	add_layers(net,layer_t(  "relu_1",        "Activation",        512,       512,    1,     1,     0,    1));
	add_layers(net,layer_t( "conv5_3",       "Convolution",        512,       512,    3,     1,     1,	  2));
	add_layers(net,layer_t(  "relu_1",        "Activation",        512,       512,    1,     1,     0,    1));
	add_layers(net,layer_t(   "pool5",           "Pooling",        512,       512,    2,     2,     0,	  1));
	add_layers(net,layer_t(   "flat1",           "Flatten",        512,         0,    0,     1,     0,    1));
	add_layers(net,layer_t(     "fc1",   "Fully_Connected",          0,      4096,    1,     1,     0,	  1));
	add_layers(net,layer_t(  "relu_2",        "Activation",       4096,      4096,    1,     1,     1,	  1));
	add_layers(net,layer_t(     "fc1",   "Fully_Connected",          0,      4096,    1,     1,     0,	  1));
	add_layers(net,layer_t(  "relu_2",        "Activation",       4096,      4096,    1,     1,     1,	  1));
	add_layers(net,layer_t(      "f3",   "Fully_Connected",          0,      1000,    1,     1,     0,	  1));
	//add_layers(net,layer_t(  "relu_2",        "Activation",       1000,      1000,    1,     1,     1,	  1));
	add_layers(net,layer_t(    "soft",            "Output",          0,      1000,    1,     1,     0,	  1));
	return net;*/
}

void add_layers(network_t* my_network,layer_t layer){
	//std::cout<<"adding layer:"<<layer.name<<std::endl;
	static int row_in =Width;
	static int col_in =Height;
	static int chin;// = Dimension;
	static int layer_input_offset=0;
	static int layer_weight_offset=0;
/*
	int pad;
	if(layer.pad==true)
	{
		pad = round(layer.kernal/2)-1;
	}
	else
	{
		pad = 0;
	}
	std::cout<<pad<<std::endl;
*/
	//------------------------------------------------------------------------------------
	int row_out = 1 +round(((row_in + 2 * layer.pad - layer.kernal)/layer.stride));
	int col_out = 1 +round(((col_in + 2 * layer.pad - layer.kernal) /layer.stride));
	//------------------------------------------------------------------------------------
	if(!(strcmp(layer.type,"Convolution"))){
		//std::cout<<"Convolution"<<std::endl;
		layer.row_in  = row_in;
		layer.col_in  = col_in;
		layer.row_out = row_out;
		layer.col_out = col_out;
		//------------------------------------------------------------------------------------
		layer.input_offset = layer_input_offset;
		int layer_input_neurons = layer.row_in * layer.col_in * layer.ch_in;
		layer.output_offset = layer.input_offset + layer_input_neurons;
		//------------------------------------------------------------------------------------
		layer.weights_offset = layer_weight_offset;
		int total_weights = layer.ch_out * layer.ch_in * layer.kernal * layer.kernal;
		layer_weight_offset += total_weights;
		layer.bais_offset = layer_weight_offset;
		int total_baises = layer.ch_out;
		layer_weight_offset += total_baises;
		//------------------------------------------------------------------------------------
		row_in = row_out;
		col_in = col_out;
		chin = layer.ch_out;
		layer_input_offset = layer.output_offset;
	}
	if(!(strcmp(layer.type,"Activation"))){
		//std::cout<<"Convolution"<<std::endl;
		layer.row_in  = row_in;
		layer.col_in  = col_in;
		layer.row_out = layer.row_in;
		layer.col_out = layer.col_in;
		//------------------------------------------------------------------------------------
		layer.input_offset = layer_input_offset;
		int layer_input_neurons = layer.row_in * layer.col_in * layer.ch_in;
		layer.output_offset = layer.input_offset + layer_input_neurons;
		//------------------------------------------------------------------------------------
		row_in = layer.row_out;
		col_in = layer.col_out;
		chin = layer.ch_out;
		layer_input_offset = layer.output_offset;
	}
	if(!(strcmp(layer.type,"Normalization"))){
		//std::cout<<"Pooling"<<std::endl;
		layer.row_in  = row_in;
		layer.col_in  = col_in;
		layer.row_out = layer.row_in;
		layer.col_out = layer.col_in;
		//------------------------------------------------------------------------------------
		layer.input_offset = layer_input_offset;
		int layer_input_neurons = layer.row_in * layer.col_in * layer.ch_in;
		layer.output_offset = layer.input_offset + layer_input_neurons;
		//------------------------------------------------------------------------------------
		row_in = layer.row_out;
		col_in = layer.col_out;
		chin = layer.ch_out;
		layer_input_offset = layer.output_offset;
	}
	if(!(strcmp(layer.type,"Pooling"))){
		//std::cout<<"Pooling"<<std::endl;
		layer.row_in  = row_in;
		layer.col_in  = col_in;
		layer.row_out = row_out;
		layer.col_out = col_out;
		//------------------------------------------------------------------------------------
		layer.input_offset = layer_input_offset;
		int layer_input_neurons = layer.row_in * layer.col_in * layer.ch_in;
		layer.output_offset = layer.input_offset + layer_input_neurons;
		//------------------------------------------------------------------------------------
		row_in = row_out;
		col_in = col_out;
		chin = layer.ch_out;
		layer_input_offset = layer.output_offset;
	}
	if(!(strcmp(layer.type,"Flatten"))){
		layer.row_in  = row_in;
		layer.col_in  = col_in;
		layer.ch_in = chin;
		layer.row_out = 1;
		layer.col_out = 1;
		layer.ch_out  = layer.row_in * layer.col_in * layer.ch_in;
		//------------------------------------------------------------------------------------
		layer.input_offset = layer_input_offset;
		int layer_input_neurons = layer.row_in * layer.col_in * layer.ch_in;
		layer.output_offset = layer.input_offset + layer_input_neurons;
		//------------------------------------------------------------------------------------
		chin = layer.ch_out;
		row_in = 1;
		col_in = 1;
		layer_input_offset = layer.output_offset;
	}
	if(!(strcmp(layer.type,"Fully_Connected"))){
		//std::cout<<"Dot_Product"<<std::endl;
		layer.row_in  = 1;
		layer.col_in  = 1;
		layer.row_out = 1;
		layer.col_out = 1;
		layer.ch_in = chin;
		//------------------------------------------------------------------------------------
		layer.input_offset = layer_input_offset;
		int layer_input_neurons = layer.row_in * layer.col_in * layer.ch_in;
		layer.output_offset = layer.input_offset + layer_input_neurons;
		//------------------------------------------------------------------------------------
		layer.weights_offset = layer_weight_offset;
		int total_weights = layer.ch_out * layer.ch_in * layer.kernal * layer.kernal;
		layer_weight_offset += total_weights;
		layer.bais_offset = layer_weight_offset;
		int total_baises = layer.ch_out;
		layer_weight_offset += total_baises;
		//------------------------------------------------------------------------------------
		row_in = row_out;
		col_in = col_out;
		chin = layer.ch_out;
		layer_input_offset = layer.output_offset;
	}
	if(!(strcmp(layer.type,"Output"))){
		layer.row_in  = 1;
		layer.col_in  = 1;
		layer.row_out = 1;
		layer.col_out = 1;
		layer.ch_in = chin;
		//------------------------------------------------------------------------------------
		layer.input_offset = layer_input_offset;
		int layer_input_neurons = layer.row_in * layer.col_in * layer.ch_in;
		layer.output_offset = layer.input_offset + layer_input_neurons;
		//------------------------------------------------------------------------------------
		layer_input_offset = layer.output_offset;
	}
//------------------------------------------------------------------------------------
	my_network->total_neurons = layer_input_offset;
	my_network->total_weights = layer_weight_offset;
	my_network->layers[my_network->num_layers] = layer;
	my_network->num_layers++;

}


/*
void read_input_image(const char *filename,data_t *input_dram){
	printf("[INFO] Reading Input Image from %s \n",filename);
	cv::Mat image;
	if(Dimension==1){
		image= cv::imread(filename,0);
		if(!image.data){
			std::cout<<"[ERROR]: "<< filename <<"  Not Loaded:"<<std::endl;
		}
		else{
			std::cout<<"[INFO]: Displaying input Image:"<<std::endl;
			cv::namedWindow("Input Image", CV_WINDOW_AUTOSIZE);
			cv::imshow("Input Image",image);
			cv::waitKey(1000);
			load_grey_image(image,input_dram);
		}
	}
	if(Dimension==3){
		image= cv::imread(filename,1);
		if(!image.data){
			std::cout<<"[ERROR]: "<< filename <<"  Not Loaded:"<<std::endl;
		}
		else{
			std::cout<<"[INFO]: Displaying input Image:"<<std::endl;
			cv::namedWindow("Input Image", CV_WINDOW_AUTOSIZE);
			cv::imshow("Input Image",image);
			cv::waitKey(2000);
			load_rgb_image(image,input_dram);
		}
	}
}
void load_grey_image(cv::Mat image,data_t *input_dram)
{
	float mean = calculate_mean(image);
	float std  = calculate_std(image,mean);
	//data_t mean = 0.1307*255;
	//data_t std  = 0.3081*255;
	//data_t mean = 0.5*255;
	//data_t std  = 0.5*255;
	unsigned int offset_in = 0;
	for(int i=0; i<image.rows; i++){
		for(int j=0; j<image.cols; j++){
			float input=(float)image.at<unsigned char>(i,j);
			float output =  normalize_pixel(input,mean,std);
			//std::cout<<output<<std::endl;
			input_dram[offset_in] = (data_t)output;
			offset_in++;
		}
	}
}
void load_rgb_image(cv::Mat image,data_t *input_dram)
{
	std::cout<<"[INFO]: Writing input Image to DRAM:"<<std::endl;
	unsigned int offset_in = 0;
	data_t pix=0;
	float _Mean[3] = {0.1307,0.1307,0.1307};
	float _Std[3]  = {0.3081,0.3081,0.3081};
	//float _Mean[3];
	//float _Std[3];
	for(int i=0; i<image.rows; i++){
		for(int j=0; j<image.cols; j++){
			cv::Point3_<uchar>* p = image.ptr< cv::Point3_<uchar> >(i,j);
			for(int k=0; k<Dimension; k++){
				if(k==0){
					float Ch1 = p->x;
					//float Ch1_V = normalize_pixel(Ch1,_Mean[k],_Std[k]);
					pix =  Ch1;
				}
				if(k==1){
					float Ch2 = p->x; //B
					//float Ch2_V = normalize_pixel(Ch2,_Mean[k],_Std[k]);
					pix = Ch2;
				}
				if(k==2){
					float Ch3 = p->x; //B
					//float Ch3_V = normalize_pixel(Ch3,_Mean[k],_Std[k]);
					pix = Ch3;
				}
				input_dram[offset_in] = (data_t) pix;
				//std::cout<<offset_in<<"   "<<pix<<std::endl;
				offset_in++;
			}
		}
	}
}
float calculate_mean(cv::Mat image){
	float sum= 0.0;
	float mean=0.0;
	float total = image.rows * image.cols;
	for(int i=0; i<image.rows; i++){
		for(int j=0; j<image.cols; j++){
			float input=(float)image.at<unsigned char>(i,j);
			sum+= input;
		}
	}
	mean = sum / total;
	return mean;
}
float calculate_std(cv::Mat image,float mean){
	float std=0.0;
	float sum=0.0;
	float total = image.rows * image.cols;
	for(int i=0; i<image.rows; i++){
		for(int j=0; j<image.cols; j++){
			float input=(float)image.at<unsigned char>(i,j);
			sum+= (input - mean) * (input - mean);
		}
	}
	std = sqrt(sum / total);
	return std;
}

*/
void normalize_image(data_t *input_dram,data_t mean,data_t std){
	data_t pix_in =0.0;
	int total = Height*Width;
	for(int i = 0; i < total; i++){
		pix_in= input_dram[i];
		pix_in = (pix_in-mean)/std;
		//std::cout<<pix_in<<std::endl;
		input_dram[i] = pix_in;
	}
}

float normalize_pixel(float input, float mean,float std){
	return((input-mean)/std);
}
void load_image_from_file(const char* filename,data_t *input_dram){
	std::cout<<"[INFO] Reading from "<<filename<<std::endl;
	double output;
	std::string in_str;
	std::fstream inFile;
	inFile.open (filename);
	if (!inFile) {
	    std::cout<<"[ERROR] Unable to open file:"<<filename<<std::endl;
	    exit(1);   // call system to stop
	}
	int inc=0;
	while (!inFile.eof()){
		getline(inFile,in_str);
		double temp = ::strtod(in_str.c_str(), 0);
		//std::cout<<inc<<" : "<<temp<<std::endl;
		input_dram[inc]= (data_t) temp/255;
	    inc++;
	}
	std::cout<<"[INFO] Succesfully read file: "<<filename<<std::endl;
	std::cout<<"[INFO] Pixel Count:"<<inc-1<<std::endl;
	inFile.close();
}
void load_classes_from_file(const char *filename,char classes[num_classes][max_char]){
	std::cout<<"[INFO] Reading Classes from "<<filename<<std::endl;
	std::string in_str;
	std::ifstream inFile;
	const char* file = "fconfig.txt";
	inFile.open (file);
	if (!inFile) {
	    std::cout<<"[ERROR] Unable to open file:"<<std::endl;
	    exit(1);   // call system to stop
	}
	int inc=0;
	while (!inFile.eof()){
		getline(inFile,in_str);
		for(int i=0;i<in_str.size();i++){
			classes[inc][i] = (char) in_str[i];
		}
	    inc++;
	}
	inFile.close();
}
void load_weights_from_file(const char *filename,data_t *weights_dram)
{
	std::cout<<"[INFO] Reading from "<<filename<<std::endl;
	double output;
	std::string in_str;
	std::fstream inFile;
	inFile.open (filename);
	if (!inFile) {
	    std::cout<<"[ERROR] Unable to open file:"<<filename<<std::endl;
	    exit(1);   // call system to stop
	}
	int inc=0;
	while (!inFile.eof()){
		getline(inFile,in_str);
		double temp = ::strtod(in_str.c_str(), 0);
		//std::cout<<temp<<std::endl;
		weights_dram[inc]= (data_t) temp;
	    inc++;
	}
	std::cout<<"[INFO] Succesfully read file: "<<filename<<std::endl;
	std::cout<<"[INFO] Weights Count:"<<inc-1<<std::endl;
	inFile.close();
}



void print_layer(layer_t layer){
	std::cout<<"[INFO] Name:"<<layer.name<<" Type:"<<layer.type<<std::endl;
	std::cout<<"[INFO] Input:"<<layer.row_in<<"x"<<layer.col_in<<"x"<<layer.ch_in<<"   Output:"<<layer.row_out<<"x"<<layer.col_out<<"x"<<layer.ch_out<<std::endl;
	std::cout<<"[INFO] Kernel:"<<layer.kernal<<" Stride:"<<layer.stride<<" Padding:"<<layer.pad<<" Sets: "<<layer.set<<std::endl;
	std::cout<<"[INFO] Input:"<<layer.input_offset<<"  Output:"<<layer.output_offset<<"  Weights:"<<layer.weights_offset<<"   "<<"Bais:"<<layer.bais_offset<<std::endl;
	std::cout<<std::endl;
}
void print_network_config(network_t* net){
	for (int i = 0; i < net->num_layers; i++){
	   layer_t layer = net->layers[i];
	   print_layer(layer);
	}
}




