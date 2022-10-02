#ifndef _FPGA_COMPUTE_UNIT_HPP_
#define _FPGA_COMPUTE_UNIT_HPP_

#include "fpga_top.hpp"

void fpga_compute(data_t input[CH_IN],data_t weights[CH_OUT][CH_IN],data_t output[CH_OUT]);

#endif
