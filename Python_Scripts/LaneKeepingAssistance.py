import cv2
import numpy as np
import utils


def GetLaneCurve(img):

    ### STEP 1
    imgThres = utils.thresholding(img);
    # cv2.imshow('Thres', imgThres);

    ### STEP 2
    h,w,c = img.shape;
    points = utils.valTrackbars();
    imgwarp = utils.warpImg(imgThres,points,w,h);
    imgWrapPoint = utils.drawPoints(img, points);

    ### STEP 3
    utils.getHistogram(imgwarp);

    cv2.imshow('Thres', imgThres);
    cv2.imshow('Warp', imgwarp);
    cv2.imshow('Warppoints', imgWrapPoint);
    return None;



if __name__ == '__main__':
    cap = cv2.VideoCapture('vid2.mp4');
    intialTrackBarVal = [132, 48, 13, 240];
    utils.initializeTrackbars(intialTrackBarVal);
    while True:
        success, img = cap.read();
        img = cv2.resize(img, (480, 240));
        GetLaneCurve(img);
        cv2.imshow('Vid', img);
        cv2.waitKey(50);
