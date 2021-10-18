import numpy as np
import cv2 as cv
import matplotlib.pyplot as plt
import math
def findBiggestContour(contours):
    k = []
    for i in contours:
        k.append(cv.contourArea(i))
    k.remove(max(k))
    return contours[k.index(max(k))]

def findpts(cnt):
    topLeftPt = []
    topRightPt = []
    bottomleft = []
    bottomright = []
    for i in cnt:
        topLeftPt.append(math.sqrt((i[0][0]**2 + i[0][1]**2)))
    for i in cnt:
        topRightPt.append(math.sqrt(((i[0][0] - 512)**2 + i[0][1]**2)))    
    for i in cnt:
        bottomleft.append(math.sqrt((i[0][0]**2 + (i[0][1]-512)**2)))
    for i in cnt:
        bottomright.append(math.sqrt(((i[0][0] - 512)**2 + (i[0][1]-512)**2)))
    a = cnt[topLeftPt.index(min(topLeftPt))][0]
    b = cnt[topRightPt.index(min(topRightPt))][0]
    c = cnt[bottomleft.index(min(bottomleft))][0]
    d = cnt[bottomright.index(min(bottomright))][0]
    return a,b,c,d

def applyPerspectiveTransform(img):
    img1 = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
    blur = cv.GaussianBlur(img1,(5,5),0)
    ret3,thresh = cv.threshold(blur,0,255,cv.THRESH_BINARY+cv.THRESH_OTSU)
    contours, hei = cv.findContours(thresh,cv.RETR_TREE,2)
    a,b,c,d = findpts(contours[2])
    pts1 = np.float32([a,b,c,d])
    pts2 = np.float32([[0,0],[500,0],[0,500],[512,500]])
    M = cv.getPerspectiveTransform(pts1,pts2)
    dst = cv.warpPerspective(img,M,(500,500))
    return dst

def detectMaze(img):
    img1 = cv.cvtColor(img,cv.COLOR_BGR2GRAY)
    imgArray = np.array(img1)
    outputArr = np.zeros((10,10))
    left = 1
    top = 2
    right = 4
    bottom = 8
    for i in range(0,500):
        for j in range(0,500):
            if(imgArray[i][j]<140):
                imgArray[i][j] = 1
            else:
                imgArray[i][j] = 0
    p=-1
    q=-1
    newArray = np.zeros((500,500))
    
    for j in range(0,500,50):
        p+=1
        q=-1
        for i in range(0,500,50):
            q+=1
            midpointX = i+25
            midpointY = j+25
            if i==1:
                outputArr[p][q]+=left
            elif imgArray[midpointX-25][midpointY] == 1:
                outputArr[p][q]+=left
            if i==499:
                outputArr[p][q]+=right
            elif imgArray[midpointX+24][midpointY] == 1:
                outputArr[p][q]+=right
            if j==1:
                outputArr[p][q]+=top
            elif imgArray[midpointX][midpointY-25] == 1:
                outputArr[p][q]+=top
            if j==499:
                outputArr[p][q]+=bottom
            elif imgArray[midpointX][midpointY+24] == 1:
                outputArr[p][q]+=bottom
       
    print(outputArr)
   
img = cv.imread(r"Downloads\\task_1b_detect_and_encode_maze\\test_cases\\maze05.jpg",1)
wrapped_img = applyPerspectiveTransform(img)
detectMaze(wrapped_img)
cv.destroyAllWindows()