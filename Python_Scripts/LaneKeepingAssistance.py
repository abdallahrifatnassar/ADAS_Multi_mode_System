import cv2
import numpy as np
import utils


curveList = [];
avgVal = 10;

def GetLaneCurve(img,display=2):

    imgResult = img.copy();
    ### STEP 1
    imgThres = utils.thresholding(img);
    # cv2.imshow('Thres', imgThres);

    ### STEP 2
    hT,wT,c = img.shape;
    points = utils.valTrackbars();
    imgwarp = utils.warpImg(imgThres,points,wT,hT);
    imgWrapPoint = utils.drawPoints(img, points);

    ### STEP 3
    middlepoint,imgHist=utils.getHistogram(imgwarp,display=True,minper=0.5,region=4);
    curveAveragePoint,imgHist=utils.getHistogram(imgwarp,display=True,minper=0.9);
    CurveRaw=curveAveragePoint - middlepoint;


    ### STEP 4
    curveList.append (CurveRaw);
    
    if len(curveList)>avgVal:
        curveList.pop(0);
    curve = int(sum(curveList)/len(curveList));
    
    ### STEP 5
    if display != 0:
       imgInvWarp = utils.warpImg(imgwarp, points, wT, hT,inv = True)
       imgInvWarp = cv2.cvtColor(imgInvWarp,cv2.COLOR_GRAY2BGR)
       imgInvWarp[0:hT//3,0:wT] = 0,0,0
       imgLaneColor = np.zeros_like(img)
       imgLaneColor[:] = 0, 255, 0
       imgLaneColor = cv2.bitwise_and(imgInvWarp, imgLaneColor)
       imgResult = cv2.addWeighted(imgResult,1,imgLaneColor,1,0)
       midY = 450
       cv2.putText(imgResult,str(curve),(wT//2-80,85),cv2.FONT_HERSHEY_COMPLEX,2,(255,0,255),3)
       cv2.line(imgResult,(wT//2,midY),(wT//2+(curve*3),midY),(255,0,255),5)
       cv2.line(imgResult, ((wT // 2 + (curve * 3)), midY-25), (wT // 2 + (curve * 3), midY+25), (0, 255, 0), 5)
       for x in range(-30, 30):
           w = wT // 20
           cv2.line(imgResult, (w * x + int(curve//50 ), midY-10),
                    (w * x + int(curve//50 ), midY+10), (0, 0, 255), 2)
       #fps = cv2.getTickFrequency() / (cv2.getTickCount() - timer);
       #cv2.putText(imgResult, 'FPS '+str(int(fps)), (20, 40), cv2.FONT_HERSHEY_SIMPLEX, 1, (230,50,50), 3);
    if display == 2:
       imgStacked = utils.stackImages(0.7,([img,imgWrapPoint,imgwarp],
                                         [imgHist,imgLaneColor,imgResult]))
       cv2.imshow('ImageStack',imgStacked)
    elif display == 1:
       cv2.imshow('Resutlt',imgResult)


    # cv2.imshow('Thres', imgThres);
    # cv2.imshow('Warp', imgwarp);
    # cv2.imshow('Warppoints', imgWrapPoint);
    # cv2.imshow('Histogram', imgHist);
    return curve;



if __name__ == '__main__':
    cap = cv2.VideoCapture('vid2.mp4');
    intialTrackBarVal = [40, 80, 20, 214];
    utils.initializeTrackbars(intialTrackBarVal);
    while True:
        success, img = cap.read();
        img = cv2.resize(img, (480, 240));
        GetLaneCurve(img);
        #cv2.imshow('Vid', img);
        cv2.waitKey(1);
