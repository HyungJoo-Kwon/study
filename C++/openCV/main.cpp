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
		cout << "�̹��� ������ ���� �� �����ϴ�." << endl;
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

	


	/*	// �׷��� �̹�����
	Mat img_color, img_gray;

	cout << "�̹����� ���δ� : " << img_color.cols << endl;  // = img_color.size().width
	cout << "�̹����� ���δ� : " << img_color.rows << endl; // = img_color.size().height
	cout << "�̹����� ä���� : " << img_color.channels() << endl;

	//pyrUp(img_color, img_color); // �̹��� 2��� Ű��
	pyrDown(img_color, img_color); // �̹��� ���� ũ��� ����
	pyrDown(img_color, img_color);
	cvtColor(img_color, img_gray, COLOR_BGR2GRAY); // �׷��� �̹�����
	*/
	/* // R,G,B �� ������
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
	/*   �̹��� ��Ī
	flip(img_src, img_dst, 0); // 0: ���� ��Ī
	flip(img_src, img_dst, 1); // 1: �¿� ��Ī
	flip(img_src, img_dst, -1); // -1: �¿�,���� ��Ī
	*/
	/* // ������ ����
		pyrUp(img_src, img_dst, Size(width*2,height*2)); // �̹��� 2��� Ű��
			// ���� ����Ʈ https://docs.opencv.org/3.4/d4/d1f/tutorial_pyramids.html
		resize(img_src, img_dst, Size(), 3, 3, INTER_CUBIC);  // 3�� Ű��� , INTER_CUBIC : ������ // = resize(img_src, img_dst, Size(width*3, height*3), INTER_CUBIC);
		resize(img_src, img_dst, Size(), 0.5, 0.5, INTER_CUBIC); // 0.5��
	*/
	/* // �ݽð� ���� ȸ��
	int width = img_src.cols;
	int height = img_src.rows;

	Mat N = getRotationMatrix2D(
		Point(img_src.cols / 2.0, img_src.rows / 2.0),		// ȸ�� �� �߽���
		90, // ȸ�� ����
		1 ); // �̹��� ����(1: ���� ũ��)

	warpAffine(img_src, img_dst, N, Size(width, height));
	*/
	//vconcat(img_src, img_dst, img_src); // src�� dst�� �Ʒ��� ���̱�
	//hconcat(img_src, img_dst, img_src); // src�� dst�� ���� ���̱�
	/* Ư������ �ڸ��� // ���ɿ��� ROI-> set ROI(x, y, w, h)
	Rect rect(10, 30, 100, 150);
	img_dst = img_src(rect);
	*/
	/*  // Ư�� ������ �߶� ȸ������
	int start_x = 35, start_y = 180, rect_w = 200, rect_h = 440;
	Rect rect(start_x, start_y, rect_w, rect_h);
	img_dst = img_src(rect);

	//	// �ڸ� Ư�� ������ ����������
	//Mat zeroMat = Mat::zeros(img_dst.size(), CV_8UC1);
	//Mat onesMat = Mat::ones(img_dst.size(), CV_8UC1);
	//onesMat = onesMat * 255;
	//Mat tmp[] = { zeroMat, zeroMat, onesMat };


	cvtColor(img_dst, img_dst, COLOR_BGR2GRAY);
	Mat tmp[] = { img_dst, img_dst, img_dst };
	merge(tmp, 3, img_dst);
	img_dst.copyTo(img_src(Rect(start_x, start_y, rect_w, rect_h)));
	*/
	/*// �̹����� ����ȭ
	cvtColor(img_src, img_gray, COLOR_BGR2GRAY);
	threshold(img_gray, img_dst, 127, 255, THRESH_BINARY); // 127���� ũ�� 255�� �ٲ��,
	//THRESH_BINARY : �Ӱ谪 �̻��� �ִ밪 ���ϴ� 0����/ THRESH_BINARY_IMV: �Ӱ谪 �̻� 0, ���ϴ� �ִ밪 / THRESH_TRUNC :�Ӱ谪 �̻� = �ִ밪, ���ϴ� ������/ THRESH_TOZERO: �Ӱ谪 �̻�: ������ ,���ϴ� 0
	//THRESH_TOZERO_IMV: �Ӱ谪 �̻� =0, ���ϴ� ������ / THRESH_OTSU : OTSU �˰��� ���� / THRESH_TRIANGLE: Triangle �˰��� ����
	*/
	//bitwise_not(img_src, img_dst); // rgb �� ����, 255���� x,y,z ���� ���� ��
	//blur(img_src, img_dst, Size(9, 9), Point(-1, -1), BORDER_DEFAULT); // �ȼ� �ܻ��, �̹����� �񽺵��ϰ�, ���ڱ� Ƣ�� ������ ���ֱ�����, ������� Ȧ����
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
	/* // ���ö�þ�
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
	////   �����
	//int width = 640;
	//int height = 480;
	//Mat img(height, width, CV_8UC3, Scalar(0, 0, 0)); // CV_8UC3 : ä�� 3��,  Scalar(0,0,0): ���
	////	//����Ȯ��
	////int img_h = img.rows;
	////int img_w = img.cols;
	////int img_bpp = img.channels();
	////cout << img_h << " " << img_w << " " << img_bpp;      
	////	 //���׸���
	////int radious = 10;
	////circle(img, Point(100, 300), radious, Scalar(0, 255, 255)); // BGR ���� -> ����� �� ���, img: ���� �׸� �̹���, center:���� �߽���ǥ, radius:���ǹ�����, color:���ǻ���, thickness : ���Ǳ��� , -1 : ���θ� ä��
	////    //�簢�� �׸���
	////rectangle(img, Point(50, 100), Point(400, 450), Scalar(0, 0, 255), 3); // (50,100), (400,450) ������3 ������
	////rectangle(img, Point(50, 100), Point(200, 300), Scalar(0, 255, 0), -1);	// (150,200), (250,300), �ʷϻ� ä����
	////rectangle(img, Rect(300,150, 50,100), Scalar(255, 0, 255), -1);
	////       //�� �׸���, line(�̹���, ������, ����, ����, ���β�);
	////line(img, Point(0, 0), Point(width - 1, height - 1), Scalar(0, 0, 255), 3); 
	////line(img, Point(width-1, 0), Point(0, height - 1), Scalar(0, 255, 0), 3); // ���� ���� ����
	////		// Ÿ�� �׸���
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

/*//// ���� ����
//int center_x = width / 2;
//int center_y = height / 2;
//
//Point location(center_x - 200, center_y - 100);
//int font = FONT_HERSHEY_PLAIN;
//double fontScale = 2;
//putText(img, "OpenCV", location, font, fontScale, green , 3); 
//line(img, Point(0, center_y - 100), Point(width - 1, center_y - 100),red, 1);
//line(img, Point(center_x-200,0), Point(center_x-200, height -1),red, 1);

   //FONT_HERSHEY_SIMPLEX   ���� ũ���� �꼼���� �۲� -
   //FONT_HERSHEY_PLAIN   ���� ũ���� �꼼���� �۲� -
   //FONT_HERSHEY_DUPLEX   ���� ũ���� �꼼���� �۲�   ������
   //FONT_HERSHEY_COMPLEX   ���� ũ���� ������ �۲� -
   //FONT_HERSHEY_TRIPLEX   ���� ũ���� ������ �۲�   ������
   //FONT_HERSHEY_COMPLEX_SMALL   ���� ũ���� �ձ۾� �۲� -
   //FONT_HERSHEY_SCRIPT_SIMPLEX   ���� ũ���� �ձ۾� �۲� -
   //FONT_HERSHEY_SCRIPT_COMPLEX   ���� ũ���� �ձ۾� �۲�   ������
   //FONT_ITALIC   ����� ��
   */
/* //-------------------------------------------------------------------------------------------------------------
	//cvtColor(img_src, img_gray, COLOR_BGR2GRAY);						//����������
	//threshold(img_gray, img_binary, 128, 255, THRESH_BINARY_INV);

	//vector<vector<Point> > contours;
	//findContours(img_binary, contours, RETR_LIST, CHAIN_APPROX_SIMPLE);
	// �˻���� 
	// RETR_EXTERNAL:�ܰ� �������� �����ϰ� ���������� ������������,
	// RETR_LIST:��� �������� �����ϸ� ���������� �������� ����,  
	// RETR_CCOOMP:��� ������ �����ϸ� ���������� 2�ܰ�� ����
	// RETR_TREE:��� �������� �����ϸ� ���������� ��� ����(TREE����)
	// �ٻ�ȭ ���
	//CHAIN_APPROX_NONE: ������������ ������� ��ȯ
	//CHAIN_APPROX_SIMPLE: ���������� �ܼ�ȭ ����, ���� �밢�� ��Ҹ� �����ϰ� ������ ����
	//CHAIN_APPROX_TC89_L1: ������ü���ڵ忡���� ������ ����
	//CHAIN_APPROX_TC89_KCOS: ������ ü���ڵ忡���� ������ ����
	
	for (size_t i = 0; i < contours.size(); i++)		//  contour.png ���
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


	//for (size_t i = 0; i < contours.size(); i++)		//  test.jpg ���
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

	//for (size_t i = 0; i < contours.size(); i++)   // �����߽� ���
	//{
	//	Moments mu;
	//	mu = moments(contours[i]);
	//	int cx = static_cast<float> (mu.m10 / (mu.m00 + 1e-5));
	//	int cy = static_cast<float> (mu.m01 / (mu.m00 + 1e-5));
	//	circle(img_src, Point(cx, cy), 5, Scalar(0, 255, 255), -1);
	//}
/*//-------------------------------------------------------- -------------------------------- 
pyrDown(img_src, img_src);								// zibera.jpg�̿�,erode�� dilate�� ���
cvtColor(img_src, img_gray, COLOR_BGR2GRAY);
Mat kernel = getStructuringElement(MORPH_RECT, Size(7,7));


int iteration = 3; //  ��� �ݺ��Ҳ���
//erode(img_gray, img_dst, kernel, Point(-1, -1), iteration);  // ������
//morphologyEx(img_gray, img_dst, MORPH_ERODE, kernel, Point(-1, -1), iteration); // ���� �ٰ� ����

//dilate(img_gray, img_dst, kernel, Point(-1, -1), iteration);  // ���̿÷��̼�
//morphologyEx(img_gray, img_dst, MORPH_DILATE, kernel, Point(-1, -1), iteration);  // ���� �ٰ� ����
	
//MORPH_OPEN : erode->dilate
//morphologyEx(img_gray, img_dst, MORPH_OPEN, kernel, Point(-1, -1), iteration);

//MORPH_CLOSE : dilate->erode
//morphologyEx(img_gray, img_dst, MORPH_CLOSE, kernel, Point(-1, -1), iteration);  
//     -- > ���������� ��� //Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));
							//morphologyEx(img_binary, img_binary, MORPH_OPEN, kernel, Point(-1, -1), 1);
*/

	imshow("src", img_src);
	imshow("dst", img_dst);
	


	waitKey(0);
	destroyAllWindows();
	return 0;
}