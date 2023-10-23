import cv2
import numpy as np
import utils


def GetLaneCurve(img):

    ### STEP 1
    imgThres = utils.thresholding(img);

    ### STEP 2
    h,w,c = img.shape;
    points = utils.valTrackbars();
    imgwarp = utils.warpImg(imgThres,points,w,h);
    imgWrapPoint = utils.drawPoints(img, points)

    cv2.imshow('Thres', imgThres);
    cv2.imshow('Warp', imgwarp);
    cv2.imshow('Warppoints', imgWrapPoint);
    return None;



if __name__ == '__main__':
    cap = cv2.VideoCapture('vid1.mp4')
    intialTrackBarVal = [163, 150, 129, 194];
    utils.initializeTrackbars(intialTrackBarVal);
    while True:
        success, img = cap.read();
        img = cv2.resize(img, (480, 240));
        GetLaneCurve(img);
        cv2.imshow('Vid', img);
        cv2.waitKey(50);
