# -*- coding: utf-8 -*-
"""
Created on Wed Feb 16 11:21:03 2022

@author: S Computers
"""

import cv2
import numpy as np
import os

outpath = 'processed'

inpath = '/home/work/Load_Weights/alexin'
outpath = '/home/work/Load_Weights/alexout'
it=0
for item in os.listdir(inpath):
    file_in = os.path.join(inpath,item)
    print(item)
    it = it+1
    img_name = 'test'+ str(it) + '.PNG'
    file_out = os.path.join(outpath,img_name)
    img = cv2.resize(cv2.imread(file_in,0),(28,28))
    cv2.imwrite(file_out,img)
    temp = 'test'+ str(it) + '.txt'
    file_out = os.path.join(outpath, temp)
    (H,W,D) = np.shape(img)
    f = open(file_out, "w")
    for h in range(H):
       for w in range(W):
          for c in range(D):
              value = img[h,w,c]
              f.write(f"{value}\n")
    f.close()

