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

image = imread('pawn.jpg')
image = cv2.pyrDown(image)

if image is  None:                              # 예외 처리
    print("이미지를 읽을 수 없습니다.")
    exit(1)

# HSV: Blue(120, 255, 255), Green(60, 255, 255), Red(0, 255, 255)

hsv_image = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
gray_image = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
print("gray_image", gray_image.shape)
lower_blue = np.array([100, 80, 80])
upper_blue = np.array([130, 255, 255])

start_point = (int(image.shape[1]/3), int(image.shape[0]/3))
end_point = (int(image.shape[1]/2), int(image.shape[0]*7/8))

slice_image = hsv_image[start_point[1]:end_point[1], start_point[0]:end_point[0]]
image_blue = cv2.inRange(slice_image, lower_blue, upper_blue)
check = image_blue

kernel = cv2.getStructuringElement(cv2.MORPH_CROSS, (9,9))
image_blue = cv2.morphologyEx(image_blue, cv2.MORPH_CLOSE, kernel, iterations=3)

origin_slice = image[start_point[1]:end_point[1], start_point[0]:end_point[0]]

print(image_blue[0,0]) # 0
print(image_blue.shape) # 370, 168
print(image_blue[int(image_blue.shape[0]/2), int(image_blue.shape[1]/2)]) # 255

image_blue = cv2.merge((image_blue, image_blue, image_blue))

print("image_blue.shape", image_blue.shape)
print("image_blue", image_blue[0,0])
print("image_blue.shape", image_blue[0,0].shape)
print(type(image_blue[0,0])) # 0
print(image_blue[0,0,0])

for i in range(image_blue.shape[0]):
    for j in range(image_blue.shape[1]):
        for k in range(image_blue.shape[2]):
            if (image_blue[i,j,k] != 0):
                image_blue[i,j] = [255, 0, 0]
                #image[start_point[1]+i, start_point[0]+j] = image_blue[i,j]
                image[start_point[1]+i, start_point[0]+j] = gray_image[start_point[1]+i, start_point[0]+j]

# contour 제일 큰거를 따와서 해야

cv2.imshow("image_blue", image_blue)
cv2.imshow("origin_slice", origin_slice)
cv2.imshow("image", image)
cv2.imshow("check", check)
     

#cv2.imshow("image", image)
cv2.waitKey(0)
cv2.destroyAllWindows()



# ilowH=98; ilowS=106; ilowV=106
# ihighH=110 ; ihighS=255; ihighV=255
# hsv = cv2.cvtColor(image, cv2.COLOR_BGR2HSV)
# lower_blue = (ilowH, ilowS, ilowV)
# upper_blue = (ihighH, ihighS, ihighV)
# # Apply the cv2.inrange method to create a mask
# mask = cv2.inRange(hsv, lower_blue, upper_blue)
# # Apply the mask on the image to extract the original color
# image = cv2.bitwise_and(image, image, mask=mask)              # 마스크에 지정한 색만 지정한 색으로 추출