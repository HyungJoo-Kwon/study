import cv2
import numpy as np
#image = cv2.imread("pcb\gate1_1.bmp", cv2.IMREAD_ANYCOLOR)        # opencv는 경로나 파일 이름 한글은 안먹힘

# https://076923.github.io/posts/#Python-OpenCV

def imread(filename, flags=cv2.IMREAD_COLOR, dtype=np.uint8):       # numpy로 파일을 우회하여야 업로드
    try: 
        n = np.fromfile(filename, dtype) 
        img = cv2.imdecode(n, flags) 
        return img 
    except Exception as e: 
        print(e) 
        return None

def FitToWindowSize(image): # image resize https://076923.github.io/posts/Python-opencv-8/
    #윈도우 크기 얻기
    from win32api import GetSystemMetrics
    # print("Width =", GetSystemMetrics(0))
    # print("Height =", GetSystemMetrics(1))
    #이미지 크기 얻기
    print('image {}'.format(image.shape))
    win_w=GetSystemMetrics(0)
    win_h=GetSystemMetrics(1)
    img_h, img_w = image.shape[:2]

    if(img_h > win_h or img_w > win_w):   
        rate_width =  (win_w / img_w)*0.95
        rate_height =  (win_h / img_h)*0.95
        scale = rate_width if (rate_width < rate_height) else rate_height

    image_resized = cv2.resize(image, dsize=(0, 0), fx=scale, fy=scale, interpolation=cv2.INTER_LINEAR)
    # cv2.imshow('image_resize',image_resized)
    return image_resized


image = imread('./소세지.jpg')

if image is  None:                              # 예외 처리
    print("이미지를 읽을 수 없습니다.")
    exit(1)

#image = cv2.pyrDown(image)                      # 이미지 절반 사이즈 줄임
image = FitToWindowSize(image)
#==============================================================================
# 채널 분리 및 병합   https://076923.github.io/posts/Python-opencv-17/
b, g, r = cv2.split(image)          # 분리
inversebgr = cv2.merge((r, g, b))   # 병합
# b = src[:,:,0]
# g = src[:,:,1]
# r = src[:,:,2]

# cv2.imshow("b", b)      #   image[:,:,0]
# cv2.imshow("g", g)      #   image[:,:,1]
# cv2.imshow("r", r)      #   image[:,:,2]
# cv2.imshow("inverse", inversebgr)

height, width, channel = image.shape
zero = np.zeros((height, width, 1), dtype = np.uint8)
image = cv2.merge((b,g,r))
cyan = cv2.merge((b,g,zero))
magenta = cv2.merge((b,zero,r))
yellow = cv2.merge((zero,g,r))

cv2.imshow("image", image)
cv2.imshow("cyan", cyan)
cv2.imshow("magenta", magenta)
cv2.imshow("yellow", yellow)

# =============================================================================


cv2.waitKey(0)
cv2.destroyAllWindows()