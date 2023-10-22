import cv2
import numpy as np


def thresholding(img):
    imghsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)
    lowerwhite = np.array([0, 0, 61])
    upperwhite = np.array([19, 78, 131])
    maskwhite = cv2.inRange(imghsv, lowerwhite, upperwhite)

    return maskwhite

