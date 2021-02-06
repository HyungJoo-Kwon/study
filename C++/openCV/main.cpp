#include <opencv2/opencv.hpp>
#include <iostream>


using namespace cv;
using namespace std;


int main()
{
	Mat img_src, img_dst, img_gray, img_binary;
	img_src = imread("images/zibera.jpg", IMREAD_COLOR);
	if (img_src.empty())
	{
		cout << "이미지 파일을 읽을 수 없습니다." << endl;
		return -1;
	}

	int width = img_src.cols;
	int height = img_src.rows;
	//int width = 640;
	//int height = 480;
	//Mat img(height, width, CV_8UC3);

	Scalar red(0, 0, 255);
	Scalar green(0, 255, 0);
	Scalar blue(255, 0, 0);

	


	/*	// 그레이 이미지로
	Mat img_color, img_gray;

	cout << "이미지의 가로는 : " << img_color.cols << endl;  // = img_color.size().width
	cout << "이미지의 세로는 : " << img_color.rows << endl; // = img_color.size().height
	cout << "이미지의 채널은 : " << img_color.channels() << endl;

	//pyrUp(img_color, img_color); // 이미지 2배로 키움
	pyrDown(img_color, img_color); // 이미지 절반 크기로 줄임
	pyrDown(img_color, img_color);
	cvtColor(img_color, img_gray, COLOR_BGR2GRAY); // 그레이 이미지로
	*/
	/* // R,G,B 색 입히기
	Mat img_color, img_gray;
	Mat bgr[3];

	resize(img_color, img_color, cv::Size(width, height), 0, 0, cv::INTER_LINEAR);
	Mat zeroMat = Mat::zeros(img_color.size(), CV_8UC1);

	split(img_color, bgr);
	Mat  B[] = { zeroMat, zeroMat, bgr[2] };
	Mat  G[] = { zeroMat, bgr[1], zeroMat };
	Mat  R[] = { bgr[0], zeroMat, zeroMat };

	merge(R, 3, bgr[2]);
	merge(G, 3, bgr[1]);
	merge(B, 3, bgr[0]);

	namedWindow("Color");
	imshow("Color", img_color);
	imshow("Blue", bgr[0]);
	imshow("Green", bgr[1]);
	imshow("Red", bgr[2]);
	*/
	/*   이미지 대칭
	flip(img_src, img_dst, 0); // 0: 상하 대칭
	flip(img_src, img_dst, 1); // 1: 좌우 대칭
	flip(img_src, img_dst, -1); // -1: 좌우,상하 대칭
	*/
	/* // 사이즈 조절
		pyrUp(img_src, img_dst, Size(width*2,height*2)); // 이미지 2배로 키움
			// 관련 사이트 https://docs.opencv.org/3.4/d4/d1f/tutorial_pyramids.html
		resize(img_src, img_dst, Size(), 3, 3, INTER_CUBIC);  // 3배 키우기 , INTER_CUBIC : 보간법 // = resize(img_src, img_dst, Size(width*3, height*3), INTER_CUBIC);
		resize(img_src, img_dst, Size(), 0.5, 0.5, INTER_CUBIC); // 0.5배
	*/
	/* // 반시계 방향 회전
	int width = img_src.cols;
	int height = img_src.rows;

	Mat N = getRotationMatrix2D(
		Point(img_src.cols / 2.0, img_src.rows / 2.0),		// 회전 시 중심점
		90, // 회전 각도
		1 ); // 이미지 배율(1: 원래 크기)

	warpAffine(img_src, img_dst, N, Size(width, height));
	*/
	//vconcat(img_src, img_dst, img_src); // src에 dst를 아래에 붙이기
	//hconcat(img_src, img_dst, img_src); // src에 dst를 옆에 붙이기
	/* 특정영역 자르기 // 관심영역 ROI-> set ROI(x, y, w, h)
	Rect rect(10, 30, 100, 150);
	img_dst = img_src(rect);
	*/
	/*  // 특정 부위를 잘라 회색으로
	int start_x = 35, start_y = 180, rect_w = 200, rect_h = 440;
	Rect rect(start_x, start_y, rect_w, rect_h);
	img_dst = img_src(rect);

	//	// 자른 특정 부위를 빨강색으로
	//Mat zeroMat = Mat::zeros(img_dst.size(), CV_8UC1);
	//Mat onesMat = Mat::ones(img_dst.size(), CV_8UC1);
	//onesMat = onesMat * 255;
	//Mat tmp[] = { zeroMat, zeroMat, onesMat };


	cvtColor(img_dst, img_dst, COLOR_BGR2GRAY);
	Mat tmp[] = { img_dst, img_dst, img_dst };
	merge(tmp, 3, img_dst);
	img_dst.copyTo(img_src(Rect(start_x, start_y, rect_w, rect_h)));
	*/
	/*// 이미지의 이진화
	cvtColor(img_src, img_gray, COLOR_BGR2GRAY);
	threshold(img_gray, img_dst, 127, 255, THRESH_BINARY); // 127보다 크면 255로 바꿔라,
	//THRESH_BINARY : 임계값 이상은 최대값 이하는 0으로/ THRESH_BINARY_IMV: 임계값 이상 0, 이하는 최대값 / THRESH_TRUNC :임계값 이상 = 최대값, 이하는 원본값/ THRESH_TOZERO: 임계값 이상: 원본값 ,이하는 0
	//THRESH_TOZERO_IMV: 임계값 이상 =0, 이하는 원본값 / THRESH_OTSU : OTSU 알고리즘 적용 / THRESH_TRIANGLE: Triangle 알고리즘 적용
	*/
	//bitwise_not(img_src, img_dst); // rgb 값 반전, 255에서 x,y,z 값을 각각 뺌
	//blur(img_src, img_dst, Size(9, 9), Point(-1, -1), BORDER_DEFAULT); // 픽셀 외사법, 이미지를 비스듬하게, 갑자기 튀는 값들을 없애기위해, 사이즈값은 홀수로
	//								// BORDER_DEFAULT : gfedcb | abcdefg | fedcb
	/* // canny, sobel
	Canny(img_src, img_dst, 100, 255);
	cvtColor(img_src, img_gray, COLOR_BGR2GRAY);
	Mat img_sobel_x, img_sobel_y;
	Sobel(img_gray, img_sobel_x, CV_64F, 1, 0, 3);
	convertScaleAbs(img_sobel_x, img_sobel_x);

	Sobel(img_gray, img_sobel_y, CV_64F, 1, 0, 3);
	convertScaleAbs(img_sobel_y, img_sobel_y);

	Mat img_sobel;
	addWeighted(img_sobel_x, 1, img_sobel_y, 1, 0, img_sobel);

	hconcat(img_gray, img_sobel_x, img_gray);
	hconcat(img_sobel_y, img_sobel, img_sobel);
	vconcat(img_gray, img_sobel, img_gray);

	imshow("Gray", img_gray);
	*/
	/* // 라플라시안
	cvtColor(img_src, img_gray, COLOR_BGR2GRAY);
	Laplacian(img_gray, img_dst, CV_8U, 3);
	hconcat(img_gray, img_dst, img_dst);
	*/
	/*Mat img_hsv, img_mask1, img_mask2, img_mask;
	cvtColor(img_src, img_hsv, COLOR_BGR2HSV);

	Vec3b lower_blue = Vec3b(20, 70, 100);
	Vec3b upper_blue = Vec3b(40, 255, 255);
	inRange(img_hsv, lower_blue, upper_blue, img_mask);
	bitwise_and(img_src, img_src, img_dst, img_mask);*/
	/*Vec3b lower_red1 = Vec3b(0, 100, 100);
	Vec3b upper_red1 = Vec3b(5, 255, 255);
	inRange(img_hsv, lower_red1, upper_red1, img_mask1);

	Vec3b lower_red2 = Vec3b(170, 100, 100);
	Vec3b upper_red2 = Vec3b(180, 255, 255);
	inRange(img_hsv, lower_red2, upper_red2, img_mask2);

	Mat img_mask = addWeighted(img_mask1, 1.0, img_mask2, 1.0, 0.0, img_mask);
	bitwise_and(img_src, img_src, img_dst, img_mask);

	bitwise_and(img_src, img_src, img_dst, img_mask);*/
	////   점찍기
	//int width = 640;
	//int height = 480;
	//Mat img(height, width, CV_8UC3, Scalar(0, 0, 0)); // CV_8UC3 : 채널 3개,  Scalar(0,0,0): 흑백
	////	//정보확인
	////int img_h = img.rows;
	////int img_w = img.cols;
	////int img_bpp = img.channels();
	////cout << img_h << " " << img_w << " " << img_bpp;      
	////	 //원그리기
	////int radious = 10;
	////circle(img, Point(100, 300), radious, Scalar(0, 255, 255)); // BGR 순서 -> 노랑색 점 찍기, img: 원을 그릴 이미지, center:원의 중심좌표, radius:원의반지름, color:원의색깔, thickness : 선의굵기 , -1 : 내부를 채움
	////    //사각형 그리기
	////rectangle(img, Point(50, 100), Point(400, 450), Scalar(0, 0, 255), 3); // (50,100), (400,450) 선굵기3 빨간색
	////rectangle(img, Point(50, 100), Point(200, 300), Scalar(0, 255, 0), -1);	// (150,200), (250,300), 초록색 채워짐
	////rectangle(img, Rect(300,150, 50,100), Scalar(255, 0, 255), -1);
	////       //선 그리기, line(이미지, 시작점, 끝점, 색깔, 선두께);
	////line(img, Point(0, 0), Point(width - 1, height - 1), Scalar(0, 0, 255), 3); 
	////line(img, Point(width-1, 0), Point(0, height - 1), Scalar(0, 255, 0), 3); // 위에 선을 덮음
	////		// 타원 그리기
	////Point center(int(width / 2), int(height / 2));
	////ellipse(img, center, Size(300, 100), 0, 90, 180, Scalar(0, 255, 255), -1);
	//imshow("result", img);

// // polylines
//int width = 640;
//int height = 480;
//Mat img(height, width, CV_8UC3);
//Scalar red(0, 0, 255);
//Scalar green(0, 255, 0);
//Scalar blue(255, 0, 0);
//
//vector<Point> contour;
//contour.push_back(Point(315, 40));
//contour.push_back(Point(570, 240));
//contour.push_back(Point(475, 550));
//contour.push_back(Point(150, 550));
//contour.push_back(Point(150, 240));
//
//const Point* pts1 = (const cv::Point*) Mat(contour).data;
//const Point* pts2 = (const cv::Point*) Mat(contour).data;
//int npts2 = Mat(contour).rows;
//polylines(img, &pts1, &npts2, 1, true, green);
//fillPoly(img, &pts3,&npts3, 1, yellow);

/*//// 글자 적기
//int center_x = width / 2;
//int center_y = height / 2;
//
//Point location(center_x - 200, center_y - 100);
//int font = FONT_HERSHEY_PLAIN;
//double fontScale = 2;
//putText(img, "OpenCV", location, font, fontScale, green , 3); 
//line(img, Point(0, center_y - 100), Point(width - 1, center_y - 100),red, 1);
//line(img, Point(center_x-200,0), Point(center_x-200, height -1),red, 1);

   //FONT_HERSHEY_SIMPLEX   보통 크기의 산세리프 글꼴 -
   //FONT_HERSHEY_PLAIN   작은 크기의 산세리프 글꼴 -
   //FONT_HERSHEY_DUPLEX   보통 크기의 산세리프 글꼴   정교함
   //FONT_HERSHEY_COMPLEX   보통 크기의 세리프 글꼴 -
   //FONT_HERSHEY_TRIPLEX   보통 크기의 세리프 글꼴   정교함
   //FONT_HERSHEY_COMPLEX_SMALL   작은 크기의 손글씨 글꼴 -
   //FONT_HERSHEY_SCRIPT_SIMPLEX   보통 크기의 손글씨 글꼴 -
   //FONT_HERSHEY_SCRIPT_COMPLEX   보통 크기의 손글씨 글꼴   정교함
   //FONT_ITALIC   기울임 꼴
   */
/* //-------------------------------------------------------------------------------------------------------------
	//cvtColor(img_src, img_gray, COLOR_BGR2GRAY);						//윤곽선검출
	//threshold(img_gray, img_binary, 128, 255, THRESH_BINARY_INV);

	//vector<vector<Point> > contours;
	//findContours(img_binary, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
	// 검색방법 
	// RETR_EXTERNAL:외곽 윤곽선만 검출하고 계층구조를 구성하지않음,
	// RETR_LIST:모든 윤곽선을 검출하며 계층구조를 구성하지 않음,  
	// RETR_CCOOMP:모든 육곽선 검출하며 계층구조는 2단계로 구성
	// RETR_TREE:모든 윤곽선을 검출하며 계층구조를 모두 형성(TREE구조)
	// 근사화 방법
	//CHAIN_APPROX_NONE: 윤곽선점들의 모든점을 반환
	//CHAIN_APPROX_SIMPLE: 윤곽선점들 단순화 수평, 수직 대각선 요소를 압축하고 끝점만 남김
	//CHAIN_APPROX_TC89_L1: 프리먼체인코드에서의 윤곽선 적용
	//CHAIN_APPROX_TC89_KCOS: 프리먼 체인코드에서의 윤곽선 적용
	
	for (size_t i = 0; i < contours.size(); i++)		//  contour.png 사용
	{
		double area = contourArea(contours[i]);
		cout << i << ":" << area << endl;
		if (area > 10000) 
		{
			drawContours(img_src, contours, i, Scalar(0, 0, 255), 2);
			Point aaa = contours[i][0];
			Point location(aaa.x, aaa.y);
			string strlocation = "("+to_string(aaa.x)+ ","+to_string(aaa.y)+")";
			putText(img_src, strlocation, location, FONT_HERSHEY_PLAIN, 1, blue, 1);
			cout << strlocation;
		}
		else
		{
			drawContours(img_src, contours, i, green, 2);
		}
	}


	//for (size_t i = 0; i < contours.size(); i++)		//  test.jpg 사용
	//{
	//	double area = contourArea(contours[i]);
	//	Rect rect = boundingRect(contours[i]);
	//	cout << i << ":" << area << endl;
	//	if (area > 10000)
	//	{
	//		/*drawContours(img_src, contours, i, Scalar(0, 0, 255), 2);
	//		Point aaa = contours[i][0];
	//		Point location(aaa.x, aaa.y);
	//		string strlocation = "(" + to_string(aaa.x) + "," + to_string(aaa.y) + ")";
	//		putText(img_src, strlocation, location, FONT_HERSHEY_PLAIN, 1, blue, 1);
	//		cout << strlocation;

	//		drawContours(img_src, contours, i, green, 2);
	//		Rect rect = boundingRect(contours[i]);
	//		rectangle(img_src, rect, blue, 2);
	//		Point2f points[4];
	//		RotatedRect box = minAreaRect(contours[i]);
	//		box.points(points);
	//		for (int n = 0; n < 4; n++)
	//			line(img_src, points[n], points[(n + 1) % 4], Scalar(255, 0, 255), 1);
	//	}
	//}       */

	//for (size_t i = 0; i < contours.size(); i++)   // 무게중심 찍기
	//{
	//	Moments mu;
	//	mu = moments(contours[i]);
	//	int cx = static_cast<float> (mu.m10 / (mu.m00 + 1e-5));
	//	int cy = static_cast<float> (mu.m01 / (mu.m00 + 1e-5));
	//	circle(img_src, Point(cx, cy), 5, Scalar(0, 255, 255), -1);
	//}
/*//-------------------------------------------------------- -------------------------------- 
pyrDown(img_src, img_src);								// zibera.jpg이용,erode와 dilate의 사용
cvtColor(img_src, img_gray, COLOR_BGR2GRAY);
Mat kernel = getStructuringElement(MORPH_RECT, Size(7,7));


int iteration = 3; //  몇번 반복할꺼냐
//erode(img_gray, img_dst, kernel, Point(-1, -1), iteration);  // 에로젼
//morphologyEx(img_gray, img_dst, MORPH_ERODE, kernel, Point(-1, -1), iteration); // 위에 줄과 같음

//dilate(img_gray, img_dst, kernel, Point(-1, -1), iteration);  // 다이올레이션
//morphologyEx(img_gray, img_dst, MORPH_DILATE, kernel, Point(-1, -1), iteration);  // 위에 줄과 같음
	
//MORPH_OPEN : erode->dilate
//morphologyEx(img_gray, img_dst, MORPH_OPEN, kernel, Point(-1, -1), iteration);

//MORPH_CLOSE : dilate->erode
//morphologyEx(img_gray, img_dst, MORPH_CLOSE, kernel, Point(-1, -1), iteration);  
//     -- > 모폴리지의 사용 //Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
							//morphologyEx(img_binary, img_binary, MORPH_OPEN, kernel, Point(-1, -1), 1);
*/

	imshow("src", img_src);
	imshow("dst", img_dst);
	


	waitKey(0);
	destroyAllWindows();
	return 0;
}