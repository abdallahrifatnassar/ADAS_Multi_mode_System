import cv2
import numpy as np
import config


def GetLaneCurve(img):
    imgThres = config.thresholding(img)

    cv2.imshow('Thres', imgThres)
    return None


cap = cv2.VideoCapture('vid1.mp4')
while True:
    success, img = cap.read()
    img = cv2.resize(img, (480, 240))
    GetLaneCurve(img)
    cv2.imshow('Vid', img)
    cv2.waitKey(10)
