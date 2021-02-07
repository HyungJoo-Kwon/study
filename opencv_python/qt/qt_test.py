# qt.py -> qt_copy.py -> qt_test.py -> qt_test_copy.py 순으로 수업
# https://has3ong.tistory.com/204
# https://pythonbasics.org/pyqt-combobox/
from PyQt5 import QtWidgets, uic, QtGui
import sys
import cv2
import numpy as np

class MyApp(QtWidgets.QDialog):
    def __init__(self):
        super(MyApp, self).__init__()
        uic.loadUi('./qt/qt_test.ui', self)
        self.count = 0
        self.filename = ""
        self.threshold_option = 0

        #버튼
        self.loadBtn = self.findChild(QtWidgets.QPushButton, 'loadBtn')
        self.loadBtn.clicked.connect(self.loadBtnClicked) 
        self.procBtn = self.findChild(QtWidgets.QPushButton, 'procBtn')
        self.procBtn.clicked.connect(self.procBtnClicked) 
        
        
        self.src = self.findChild(QtWidgets.QLabel, 'imgSrc')     
        self.dst = self.findChild(QtWidgets.QLabel, 'imgDst')     
        self.filePath = self.findChild(QtWidgets.QLineEdit,'filePath')
        self.filePath.clear()

        # 콤보박스
        self.comboThr = self.findChild(QtWidgets.QComboBox, "comboThr")

        # # 이진화 옵션번호가 0~5 OTSU가 8 TRIANGLE이16인 이유는 여러개를 같이 쓸수 있으므로.
        # # 숫자를 더해서 같은 값이 나오면 안된다.

        self.thrList = ["THRESH_BINARY : 0",
                    "THRESH_BINARY_INV : 1",
                    "THRESH_TRUNC : 2",
                    "THRESH_TOZERO : 3",
                    "THRESH_TOZERO_INV : 4",
                    "THRESH_MASK : 5",
                    "THRESH_OTSU : 8",
                    "THRESH_TRIANGLE : 16"]
        
        self.modelist = [cv2.THRESH_BINARY,
                         cv2.THRESH_BINARY_INV,
                         cv2.THRESH_TRUNC,
                         cv2.THRESH_TOZERO,
                         cv2.THRESH_TOZERO_INV,
                         cv2.THRESH_MASK,
                         cv2.THRESH_OTSU,
                         cv2.THRESH_TRIANGLE]

        self.comboThr.addItems(self.thrList)
        self.comboThr.activated[str].connect(self.ComboBoxEvent)
        
        
        self.thr_value = self.findChild(QtWidgets.QLabel, "label_threshold")
        
        # 슬라이더
        self.hSlider = self.findChild(QtWidgets.QSlider, "hSlider")
        self.hSlider.setTickPosition(QtWidgets.QSlider.TicksBelow)
        self.hSlider.setMinimum(0)
        self.hSlider.setMaximum(255)
        self.hSlider.setTickInterval(10)  # pageup, pagedown시 10씩 움직임
        self.hSlider.valueChanged.connect(self.hSliderChanged)

        self.show()

    def hSliderChanged(self):
        #self.filePath.setText(str(self.hSlider.value()))
        if self.filename != "":
            self.thr_value.setText("임계값 : "+str(self.hSlider.value()))
            img_gray = cv2.cvtColor(self.img, cv2.COLOR_BGR2GRAY)
            # https://076923.github.io//posts/Python-opencv-12/
            # https://opencv-python.readthedocs.io/en/latest/doc/09.imageThresholding/imageThresholding.html
            _, binary = cv2.threshold(img_gray, self.hSlider.value(), 255, self.threshold_option)
            self.displayOutputImage(binary, 'dst')
        else :
            self.filePath.setText("예외 발생 : 파일을 선택해 주세요")

    def ComboBoxEvent(self, text):
        print(text) # text가 thrList목록으로
        #self.filePath.setText(text)
        index = self.thrList.index(text)
        print(index) 
        self.threshold_option = self.modelist[index]

        self.hSliderChanged()
    
    #결과 이미지 출력
    def displayOutputImage(self, outImage, position):
        img_info = outImage.shape
        if outImage.ndim == 2 : # 그래이 영상
            qImg = QtGui.QImage(outImage, img_info[1], img_info[0], 
                            img_info[1]*1, QtGui.QImage.Format_Grayscale8)
        else :
            qImg = QtGui.QImage(outImage, img_info[1], img_info[0], 
                            img_info[1]*img_info[2], QtGui.QImage.Format_RGB888)
        pixmap = QtGui.QPixmap.fromImage(qImg)

        if position == 'src' :
            self.src.setPixmap(pixmap)
            self.src.setScaledContents(True)
        else :
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
            #img = self.imread(self.filename) #opencv는 한글 지원 안함
            img_rgb = cv2.cvtColor(self.img, cv2.COLOR_BGR2RGB)
            img_gray = cv2.cvtColor(self.img, cv2.COLOR_BGR2GRAY)
            outImg = self.processingImage(img_rgb)
            self.displayOutputImage(outImg,'dst')
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

    # 이미지 로드(Image load)
    def loadBtnClicked(self):
        #path = './images'
        path = './images/pcb'
        filter = "All Images(*.jpg; *.png; *.bmp);;JPG (*.jpg);;PNG(*.png);;BMP(*.bmp)"
        fname = QtWidgets.QFileDialog.getOpenFileName(self, "파일불러오기", path, filter)
        
        self.filename = str(fname[0])
        if fname[0] !='' : # 파일로드시 파일 선택하지 않고 취소할 때 예외처리
            filename = str(fname[0])
            self.img = self.imread(filename) #cv2.imread가 한글경로를 지원하지 않음
            img_rgb = cv2.cvtColor(self.img, cv2.COLOR_BGR2RGB)
            self.displayOutputImage(img_rgb, 'src') # 'src'(왼쪽) or 'dst'(오른쪽) 창
            self.count += 1
        else:
            self.filePath.setText("예외발생 : 파일을 선택해 주세요!!!!") 




app = QtWidgets.QApplication(sys.argv)
window = MyApp()
app.exec_()

import tensorflow as tf
tf.session()