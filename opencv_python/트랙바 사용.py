# 트랙바 사용으로 더 쉽게 원하는 색을 추출

# https://076923.github.io/posts/Python-opencv-35/
# https://076923.github.io/posts/Python-opencv-16/
# https://t1.daumcdn.net/cfile/tistory/2705763659488FB401

import cv2
import numpy as np
import function

def onChange(pos):
    pass

image = function.imread("./orange.png")
tomato = function.imread("./tomato.jpg")
image = tomato

hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)


cv2.namedWindow("Trackbar Windows", cv2.WINDOW_NORMAL) # 트랙바 윈도우 생성

cv2.createTrackbar("hsv1 max", "Trackbar Windows", 0, 180, onChange)        # 빨간색은 hsv 0~5, 170~180이기에 두개의 hsv범위가 필요
cv2.createTrackbar("hsv1 min", "Trackbar Windows", 0, 180, onChange)

cv2.setTrackbarPos("hsv1 max", "Trackbar Windows", 180)
cv2.setTrackbarPos("hsv1 min", "Trackbar Windows", 0)

cv2.createTrackbar("hsv2 max", "Trackbar Windows", 0, 180, onChange)
cv2.createTrackbar("hsv2 min", "Trackbar Windows", 0, 180, onChange)

cv2.setTrackbarPos("hsv2 max", "Trackbar Windows", 180)
cv2.setTrackbarPos("hsv2 min", "Trackbar Windows", 180)

cv2.createTrackbar("saturation max", "Trackbar Windows", 0, 255, onChange)
cv2.createTrackbar("saturation min", "Trackbar Windows", 0, 255, onChange)

cv2.setTrackbarPos("saturation max", "Trackbar Windows", 255)
cv2.setTrackbarPos("saturation min", "Trackbar Windows", 0)

cv2.createTrackbar("lightness max", "Trackbar Windows", 0, 255, onChange)
cv2.createTrackbar("lightness min", "Trackbar Windows", 0, 255, onChange)

cv2.setTrackbarPos("lightness max", "Trackbar Windows", 255)
cv2.setTrackbarPos("lightness min", "Trackbar Windows", 0)



while cv2.waitKey(1) != ord('q'):  # 1ms 마다 값이 q가 눌러졌는지 확인하며, q가 눌러지면 반복문이 종료됩니다.
    ilowH1 = cv2.getTrackbarPos("hsv1 min", "Trackbar Windows")
    ihighH1 = cv2.getTrackbarPos("hsv1 max", "Trackbar Windows")
    ilowH2 = cv2.getTrackbarPos("hsv2 min", "Trackbar Windows")
    ihighH2 = cv2.getTrackbarPos("hsv2 max", "Trackbar Windows")
    ilowS = cv2.getTrackbarPos("saturation min", "Trackbar Windows")
    ihighS = cv2.getTrackbarPos("saturation max", "Trackbar Windows")
    ilowV = cv2.getTrackbarPos("lightness min", "Trackbar Windows")
    ihighV = cv2.getTrackbarPos("lightness max", "Trackbar Windows")
    
    lower1 = (ilowH1, ilowS, ilowV)
    upper1 = (ihighH1, ihighS, ihighV)

    lower2 = (ilowH2, ilowS, ilowV)
    upper2 = (ihighH2, ihighS, ihighV)
    # Apply the cv2.inrange method to create a mask
    mask1 = cv2.inRange(hsv, lower1, upper1)
    print("mask1.shape", mask1.shape)
    mask2 = cv2.inRange(hsv, lower2, upper2)
    add_mask = cv2.addWeighted(mask1, 1.0, mask2, 1.0, 0.0)
    # Apply the mask on the image to extract the original color
    image2 = image.copy()
    image2 = cv2.bitwise_and(image2, image2, mask=add_mask)
 
    cv2.imshow("Trackbar Windows", image2)


cv2.destroyAllWindows()