import cv2
import numpy as np


def thresholding(img):
    imghsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV);
    # edged= cv2.Canny(imghsv,30,200);
    lowerwhite = np.array([0, 0, 79])
    upperwhite = np.array([78, 72, 117])
    maskwhite = cv2.inRange(imghsv, lowerwhite, upperwhite)
    return maskwhite;

def warpImg (img,points,w,h,inv=False):
    pts1 = np.float32(points);
    pts2 = np.float32([[0,0],[w,0],[0,h],[w,h]]);
    if inv:
        matrix = cv2.getPerspectiveTransform(pts2,pts1);
    else:
        matrix = cv2.getPerspectiveTransform(pts1,pts2);
    imgWarp = cv2.warpPerspective(img,matrix,(w,h));
    return imgWarp;

def nothing(a):
    pass

def initializeTrackbars(intialTracbarVals,wT=480, hT=240):
    cv2.namedWindow("Trackbars")
    cv2.resizeWindow("Trackbars", 360, 240)
    cv2.createTrackbar("Width Top", "Trackbars", intialTracbarVals[0],wT//2, nothing)
    cv2.createTrackbar("Height Top", "Trackbars", intialTracbarVals[1], hT, nothing)
    cv2.createTrackbar("Width Bottom", "Trackbars", intialTracbarVals[2],wT//2, nothing)
    cv2.createTrackbar("Height Bottom", "Trackbars", intialTracbarVals[3], hT, nothing)

def valTrackbars(wT=480, hT=240):
    widthTop = cv2.getTrackbarPos("Width Top", "Trackbars")
    heightTop = cv2.getTrackbarPos("Height Top", "Trackbars")
    widthBottom = cv2.getTrackbarPos("Width Bottom", "Trackbars")
    heightBottom = cv2.getTrackbarPos("Height Bottom", "Trackbars")
    points = np.float32([(widthTop, heightTop), (wT-widthTop, heightTop),
                      (widthBottom , heightBottom ), (wT-widthBottom, heightBottom)])
    return points

def drawPoints(img,points):
    for x in range(4):
        cv2.circle(img, (int(points[x][0]), int(points[x][1])), 15, (0,255,0), cv2.FILLED);
    return img;