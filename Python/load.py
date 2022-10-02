# -*- coding: utf-8 -*-

"""
Created on Sat Feb  5 19:04:19 2022
@author: S Computers
"""

import torchvision.models as models
import numpy as np
import os

path = "/home/work/Load_Weights"


model = models.vgg16(pretrained=True) #downloads pytorch model from pytorch HUB
print("Model Loaded")
model_dict = model.state_dict()

f = open('vgg_weights.txt', "w")
print("Loading Parameters...")
# Print model's state_dict
for param_tensor in model_dict: 
    out_torch = model_dict[param_tensor]
    Size = np.shape(out_torch)
    print(param_tensor,' :',Size)
    (DIM,) = np.shape(Size)
    if(DIM==4):
        (CO,CI,KI,KJ) = Size
        for co in range(CO):
            for ci in range (CI):
                for i in range(KI):
                    for j in range(KJ):
                        value = out_torch[co,ci,i,j].item()
                        f.write(f"{value}\n")
                        #weights.append(pix)
                        #layer_weights.append(pix)
                        
    if(DIM==1):
        for co in range(CO):
            value = out_torch[co].item()
            f.write(f"{value}\n")
            #eights.append(pix)
            #layer_weights.append(pix)
            
    if(DIM==2):
        (CO,CI) = Size
        for co in range(CO):
            for ci in range (CI):
                value = out_torch[co,ci].item()
                f.write(f"{value}\n")
                #weights.append(pix)
                #layer_weights.append(pix)
f.close()
