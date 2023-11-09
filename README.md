# FPGA template based-CNN on Xilinx boards 
### [Azzam Alhussain](http://azzam.page/), [Mingjie Lin](https://www.ece.ucf.edu/person/mingjie-lin/)
___
**This is the official HW/SW Co-design efficient implementation of a 16-bit quantized fixed point Convolutional Neural Network accelerator (CNNA) on Xilinx SoC-FPGAs, which is accepted and will be published soon as a conference paper in the IEEE Xplore Digital Library as [Hardware-Efficient Template-Based Deep CNNs Accelerator Design](https://arxiv.org/abs/2207.10723), and will be presented in Oct 2022 at the [16th International Conference on Networking, Architecture, and Storage (NAS 2022)](http://www.nas-conference.org/NAS-2022/index.html).**

![The proposed FPGA template-based design](https://user-images.githubusercontent.com/74447207/186279477-416012e7-1a22-494f-aaa2-d455c4cca74a.png)


## Description

This paper proposed a HW/SW co-design approach for quantized 16-bit CNN scalable accelerator design implemented on SoC-FPGAs capable of achieving higher performance versus resource utilization trade-off. The developed accelerator converts the convolutional and fully connected layers into vector multiplication between inputs and outputs features map on a single on-chip compute unit. Lastly, ImageNet dataset alongside with AlexNet, VGG16, and LeNet networks were wxamined for higher frequency of 200-MHz with 230 GOP/s depending on ZYNQ boards.

## Contributions
- Developed a scalable accelerator on top of [ZynqNet](https://github.com/dgschwend/zynqnet). 
- Provided an open-source project for investigating the effect differents networks and boards. 
- Demonstrated that the proposed methodology achieved superior performance up to 230 GOP/s under 200-MHz with minimum data execution time.
- The community can build upon our code, explore, and search an efficient implementation for real-time applications. 

## Getting Started

### Requirement
* Linux Ubuntu 18.04
* Xilinx SDK 2018.3+ 
* Vivado 2018.3+ 
* PetaLinux
* Xilinx SoC-FPGAs (ex: Ultra96 & ZCU104)

## License

All source code is made available under a BSD 3-clause license. You can freely use and modify the code, without warranty, so long as you provide attribution
to the authors. See `LICENSE.md` for the full license text.

## Citation

Please use the below citation till it updated from IEEE Xplore Digital Library,

**2.	A. Alhussain and M. Lin, "Hardware-Efficient Template-Based Deep CNNs Accelerator Design," in 2022 IEEE International Conference on Networking, Architecture and Storage (NAS), Philadelphia, PA, USA, 2022 pp. 1-4.
doi: 10.1109/NAS55553.2022.9925552**

## Acknowledgments

Inspiration, code snippets, references, etc.

* [FINN: A Framework for Fast, Scalable Binarized Neural Network Inference](https://xilinx.github.io/finn/)
* [Xilinx/finn-hlslib](https://github.com/Xilinx/finn-hlslib)
* [Convolutional Neural Network Accelerator (CNNA)](https://github.com/jonathan93sh/CNNA)
* [ZynqNet](https://github.com/dgschwend/zynqnet)

