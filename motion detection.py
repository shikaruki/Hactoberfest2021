import cv2
import numpy as np

cap = cv2.VideoCapture('vtest.avi')

ret,frame1 = cap.read()
ret,frame2 = cap.read()

while True:
    cv2.imshow("Original", frame2)

    diff = cv2.absdiff(frame1,frame2)
    gray = cv2.cvtColor(diff,cv2.COLOR_BGR2GRAY)
    # To find the contours is easier in case of gray scale image.
    blur = cv2.GaussianBlur(gray,(5,5),0)
    _,thres = cv2.threshold(blur,20,255,cv2.THRESH_BINARY)
    dilated = cv2.dilate(thres,None,iterations=3)
    contours,_ = cv2.findContours(dilated,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)

    for contour in contours:
        # saving the coordinates of the found contour
        (x,y,w,h) = cv2.boundingRect(contour)
        # now, code for noise removal
        if cv2.contourArea(contour) < 900:
            continue
        cv2.rectangle(frame1,(x,y),(x+w,y+h),(0,255,0),2)
        #printing message on screen
        cv2.putText(frame1,"Movement observed",(10,20),
                    cv2.FONT_HERSHEY_SIMPLEX,1,(0,243,255),3)
    # Now, we will just draw the contours...
    # cv2.drawContours(frame1,contours,-1,(0,255,0),2)

    cv2.imshow("feed",frame1)

    frame1 = frame2

    # reading the new frame in the var frame 2.
    ret,frame2 = cap.read()

    if cv2.waitKey(40)&0xff == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
