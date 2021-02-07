# 제일 큰 윤곽이용

import cv2
import numpy as np

def imread(filename, flags=cv2.IMREAD_COLOR, dtype=np.uint8):      
    try: 
        n = np.fromfile(filename, dtype) 
        img = cv2.imdecode(n, flags) 
        return img 
    except Exception as e: 
        print(e) 
        return None

image = imread('./images/pawn.jpg')
image = cv2.pyrDown(image)

if image is  None:                              # 예외 처리
    print("이미지를 읽을 수 없습니다.")
    exit(1)

# HSV: Blue(120, 255, 255), Green(60, 255, 255), Red(0, 255, 255)

hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
print("gray.shape", gray.shape)
result = image.copy()

lower_blue = (100, 40, 40)
upper_blue = (140, 255, 255)
mask = cv2.inRange(hsv, lower_blue, upper_blue)

contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
c = max(contours, key= cv2.contourArea)          # contourArea 가장 큰 것
cc = max(hierarchy, key= cv2.contourArea)
cv2.drawContours(result, [c], 0, (0, 0, 255), 2)

mask = np.zeros_like(image, dtype="uint8")              # image 크기만큼 zero 행렬
mask = cv2.drawContours(mask, [c], -1, (255, 255, 255), -1) # mask에 제일 큰 contour을 흰색으로 채워넣음 (-1 : 음수값이면 채워넣기)
print("mask.shape", mask.shape)

# # ==================================================================================
# 비트연산으로 배경과 타겟 각각 구해서 더함
# mask = mask[:,:,0]
# print("gray.shape", gray.shape)

# target = cv2.bitwise_and(gray, gray, mask= mask) # gray와 mask and 연산
# print("target.shape", target.shape)
# cv2.imshow("target", target)

# background_mask = cv2.bitwise_not(mask) # mask를 not 연산하여 traget을 0, target이 아닌 요소들을 1로
# background = cv2.bitwise_and(image, image, mask=mask_inv) # 배경만 추출
# print("background.shape", background.shape)
# cv2.imshow("background", background)

# target = cv2.merge((target, target, target))  # 1차원을 3차원으로

# #final = cv2.bitwise_or(background, target) # background와 target or연산
# final = cv2.add(background, target)         # background와 target 더함, or 연산과 같아
# cv2.imshow("final", final)

# # ======================================================================
# # 마스크를 씌운 후 0값이 아니면 덮어쓰는 방법
# for i in range(mask.shape[0]):
#     for j in range(mask.shape[1]):
#         for k in range(mask.shape[2]):
#             if (mask[i,j,k] != 0):
#                 image[i,j] = gray[i, j]
# cv2.imshow("result ",image)

# # =======================================================================
#

print(c[0,0,0]) # x
print(c[0,0,1]) # y
print(cc)
#for i in range(len(c.shape[0])):

  

cv2.waitKey(0)
cv2.destroyAllWindows()


