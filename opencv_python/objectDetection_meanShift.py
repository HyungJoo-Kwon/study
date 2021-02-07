import cv2

print(cv2.__version__)

# https://deep-learning-study.tistory.com/275
# https://darkpgmr.tistory.com/64
# https://vision0814.tistory.com/70
# mean_shift 는 스케일에 대한 조절이 없어 cam_shift를 사용하면 스케일 조정 가능
# https://www.youtube.com/watch?v=1FJWXOO1SRI

# 비디오 파일 열기
cap = cv2.VideoCapture('Testvideo.mp4')

if not cap.isOpened():
    print('Video open failed!')
    sys.exit()

# 초기 사각형 영역: (x, y, w, h)
# ROI로 선택해도 되지만 강제로 입력함
x, y, w, h = 0, 350, 70, 200
rc = (x, y, w, h)

# 영상의 정보 받아오기
ret, frame = cap.read()

if not ret:
    print('frame read failed!')
    sys.exit
    
roi = frame[y:y+h, x:x+w]
roi_hsv = cv2.cvtColor(roi, cv2.COLOR_BGR2HSV)

# HS 히스토그램 계산
channels = [0,1] # H와 S만 이용. V는 안씀(조명에 따라 v값이 마구잡이로 변하여서)
ranges = [0, 180, 0, 256]
hist = cv2.calcHist([roi_hsv], channels, None, [90, 128], ranges)

# Mean Shift 알고리즘 종료 기준
term_crit = (cv2.TERM_CRITERIA_EPS | cv2.TERM_CRITERIA_COUNT, 10, 1) # 10: 반지름, 1: threshold 설정값

# #비디오 매 프레임 처리

while True:
    ret, frame = cap.read()
    if not ret:
        break
        
    # HS 히스토그램에 대한 역투영
    # frame을 HSV로 변환
    frame_hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)
    # 히스토그램 역투영 확률 데이터 얻기
    backproj = cv2.calcBackProject([frame_hsv], channels, hist, ranges, 1)
    
    # Mean Shift
    # 역투영 확률값을 Mean shift 인자에 입력
  
    print("before", rc)
    cv2.rectangle(frame, rc, (0, 0, 255), 2)
    _, rc = cv2.meanShift(backproj, rc, term_crit)
    print("after", rc)
    print()
    # 추적 결과 화면 출력
    
    
    cv2.rectangle(frame, (x,y), (x+w, y+h), (0,255,0), 1)

    cv2.imshow('frame', frame)

    if cv2.waitKey(60) == 27:
        break

        
cv2.waitKey(0)
cap.release()
cv2.destroyAllWindows()

