import cv2
import numpy as np    
from win32api import GetSystemMetrics

def imread(filename, flags=cv2.IMREAD_COLOR, dtype=np.uint8): 
    try: 
        n = np.fromfile(filename, dtype) 
        img = cv2.imdecode(n, flags) 
        return img 
    except Exception as e: 
        print(e) 
        return None

def FitToWindowSize(image):
    GetSystemMetrics
    print('image {}'.format(image.shape))
    win_w=GetSystemMetrics(0)
    win_h=GetSystemMetrics(1)
    img_h, img_w = image.shape[:2]

    if(img_h > win_h or img_w > win_w):   
        rate_width =  (win_w / img_w)*0.95
        rate_height =  (win_h / img_h)*0.95
        scale = rate_width if (rate_width < rate_height) else rate_height
        image_resized = cv2.resize(image, dsize=(0, 0), fx=scale, fy=scale, interpolation=cv2.INTER_LINEAR)

        return image_resized, scale
    else:
        return image, 1

def map(x, in_min=0, in_max=255, out_min=0, out_max=100):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min)
    
def onMouse(event, x, y, flags, param):
    global isDragging, img, hsv
    img_h, img_w = img.shape[:2]
    if event == cv2.EVENT_LBUTTONDOWN:
        isDragging = True

    elif event == cv2.EVENT_MOUSEMOVE:
        if isDragging:
            img_draw = img.copy()
            print(img_draw.shape)
            if x <= 1026:
                cv2.line(img_draw, (x, 0), (x, img_h), blue, 2)
                cv2.line(img_draw, (0, y), (img_w, y), blue, 2)
            else:
                cv2.line(img_draw, (x, 0), (x, img_h), blue, 2)
            status = "x: " + str(x) + " y: " + str(y) + " BGR value: " + str(img[y,x]) #y,x로 되어있음!!!!!!!!!!!!!!!!!!!!!!!!
            point = (int(img_w/5*4-15),int(img_h/15*14))
            
            cv2.putText(img_draw, status, point, cv2.FONT_HERSHEY_PLAIN, 1, (255, 255, 255), 2, cv2.LINE_AA)
            cv2.putText(img_draw, "HSV value"+str(hsv[y,x]), (point[0],point[1]-30), cv2.FONT_HERSHEY_PLAIN, 1, (255, 255, 255), 2, cv2.LINE_AA)
            cv2.imshow('img', img_draw)
    elif event == cv2.EVENT_LBUTTONUP:
        if isDragging:
            isDragging = False
            #cv2.circle(img_draw,(x,y),100,blue,-1)
            cv2.imshow('img', img_draw)

isDragging = False
x0, y0, w, h = -1, -1, -1, -1
blue, red = (255, 0, 0), (0, 0, 255)

# cv2.imread가 아님/ 위에 정의한 imread()함수 사용
filename = '1211/image/chess.jpg'
image = imread(filename,cv2.IMREAD_COLOR)
if image is None:
    print("이미지를 읽을 수 없습니다.")
    exit(1)

img, scale = FitToWindowSize(image)
hsv = cv2.cvtColor(img, cv2.COLOR_BGR2HSV)

print(img.shape)
cv2.imshow('img', img)
cv2.setMouseCallback('img', onMouse)
cv2.waitKey()
cv2.destroyAllWindows()