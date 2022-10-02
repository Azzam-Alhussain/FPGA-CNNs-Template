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

f = open('vgg_param.txt', "w")
print("Loading Parameters...")
# Print model's state_dict
for param_tensor in model_dict: 
    out_torch = model_dict[param_tensor]
    Size = np.shape(out_torch)
    value = param_tensor + ' :' + str(Size)
    print(value)
    f.write(f"{value}\n")
f.close()
