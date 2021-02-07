# Qt Designer 사용
# opencv는 BGR, Qt는 RGB 색체계 
# https://opencv-python.readthedocs.io/en/latest/doc/09.imageThresholding/imageThresholding.html
# https://076923.github.io//posts/Python-opencv-12/
# qt.py -> qt_copy.py -> qt_test.py -> qt_test_copy.py 순으로 수업
from PyQt5 import QtWidgets, uic, QtGui
import sys
import cv2
import numpy as np

class MyApp(QtWidgets.QDialog):
    def __init__(self):
        super(MyApp, self).__init__()
        uic.loadUi('./qt/qt.ui', self)
        self.count = 0

        #버튼
        self.loadBtn = self.findChild(QtWidgets.QPushButton, 'loadBtn')
        self.loadBtn.clicked.connect(self.loadBtnClicked) 
        self.procBtn = self.findChild(QtWidgets.QPushButton, 'procBtn')
        self.procBtn.clicked.connect(self.procBtnClicked) 
        self.src = self.findChild(QtWidgets.QLabel, 'imgSrc')     
        self.dst = self.findChild(QtWidgets.QLabel, 'imgDst')     
        self.filePath = self.findChild(QtWidgets.QLineEdit,'filePath')
        self.filePath.clear()
        self.show()

    # 이미지 로드(Image load)
    def loadBtnClicked(self):
        path = './images'
        filter = "All Images(*.jpg; *.png; *.bmp);;JPG (*.jpg);;PNG(*.png);;BMP(*.bmp)"
        fname = QtWidgets.QFileDialog.getOpenFileName(self, "파일불러오기", path, filter)
        
        self.filename = str(fname[0])
        self.filePath.setText(self.filename)
        self.src.setPixmap(QtGui.QPixmap(self.filename))    # 
        self.src.setScaledContents(True)
        self.count += 1 

    
    #결과 이미지 출력
    def displayOutputImage(self, outImage):
        img_info = outImage.shape
        if outImage.ndim == 2 : # 그래이 영상
            qImg = QtGui.QImage(outImage, img_info[1], img_info[0], 
                            img_info[1]*1, QtGui.QImage.Format_Grayscale8)
        else :
            qImg = QtGui.QImage(outImage, img_info[1], img_info[0], 
                            img_info[1]*img_info[2], QtGui.QImage.Format_RGB888)
        pixmap = QtGui.QPixmap.fromImage(qImg)
        self.dst.setPixmap(pixmap)
        self.dst.setScaledContents(True)

    #한글 포함된 이미지 파일 읽어오기
    def imread(self, filename, flags=cv2.IMREAD_COLOR, dtype=np.uint8): 
        try: 
            n = np.fromfile(filename, dtype) 
            img = cv2.imdecode(n, flags) 
            return img 
        except Exception as e: 
            print(e) 
            return None

    def procBtnClicked(self):
        if self.count != 0:
            img = self.imread(self.filename) #opencv는 한글 지원 안함
            img_rgb = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)          # Qt에서는 RGB형식 사용
            img_gray = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            outImg = self.processingImage(img_rgb)
            self.displayOutputImage(outImg)
        else:
            self.filename = "파일을 로드 하세요"
            self.filePath.setText(self.filename)

    def processingImage(self, img_rgb):
        #여기에 여러분이 작성할 코드를 넣으시면 됩니다.

        hsv = cv2.cvtColor(img_rgb, cv2.COLOR_RGB2HSV)
        gray = cv2.cvtColor(img_rgb, cv2.COLOR_RGB2GRAY)

        lower_blue = (100, 40, 40)
        upper_blue = (140, 255, 255)
        mask = cv2.inRange(hsv, lower_blue, upper_blue)

        contours, hierarchy = cv2.findContours(mask, cv2.RETR_EXTERNAL, cv2.CHAIN_APPROX_SIMPLE)
        c = max(contours, key= cv2.contourArea)  

        mask = np.zeros_like(img_rgb, dtype="uint8")              # image 크기만큼 zero 행렬
        mask = cv2.drawContours(mask, [c], -1, (255, 255, 255), -1) # mask에 제일 큰 contour을 흰색으로 채워넣음 (-1 : 음수값이면 채워넣기)
        
        for i in range(mask.shape[0]):
            for j in range(mask.shape[1]):
                for k in range(mask.shape[2]):
                    if (mask[i,j,k] != 0):
                        img_rgb[i,j] = gray[i, j]

        outImg = img_rgb
        return outImg

app = QtWidgets.QApplication(sys.argv)
window = MyApp()
app.exec_()