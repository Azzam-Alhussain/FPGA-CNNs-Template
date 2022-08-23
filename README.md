# FPGA template based-CNN on Xilinx boards 
### [Azzam Alhussain](http://azzam.page/), [Mingjie Lin](https://www.ece.ucf.edu/person/mingjie-lin/)
___
**This is the official HW/SW Co-design efficient implementation of a 16-bit quantized fixed point Convolutional Neural Network accelerator (CNNA) on Xilinx SoC-FPGAs, which is accepted and will be published soon as a conference paper in the IEEE Xplore Digital Library as [Hardware-Efficient Template-Based Deep CNNs Accelerator Design](https://arxiv.org/abs/2207.10723), and will be presented in Oct 2022 at the [16th International Conference on Networking, Architecture, and Storage (NAS 2022)](http://www.nas-conference.org/NAS-2022/index.html).**

## Description

This paper proposed a HW/SW co-design approach for quantized 16-bit CNN scalable accelerator design implemented on SoC-FPGAs capable of achieving higher performance versus resource utilization trade-off. The developed accelerator converts the convolutional and fully connected layers into vector multiplication between inputs and outputs features map on a single on-chip compute unit. Lastly, ImageNet dataset alongside with AlexNet, VGG16, and LeNet networks were wxamined for higher frequency of 200-MHz with 230 GOP/s depending on ZYNQ boards.
