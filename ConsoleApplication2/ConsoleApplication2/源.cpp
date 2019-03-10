#include<opencv.hpp>

using namespace cv;
/*
int main()
{
	Mat src = imread("C:\\Users\\SZJ\\Desktop\\1.jpg");
	Mat dst;
	//blur(src, src, Size(3,3));
	cvtColor(src, dst, COLOR_BGR2HSV);

	for (int i = 0; i < dst.rows; ++i) {
		for (int j = 0; j < dst.cols; ++j) {
			Vec3b& pix = dst.at<Vec3b>(i, j); //指针或引用
			std::swap(pix[0], pix[2]);
		}
	}
	imshow("dst", dst);
	waitKey(0);
	return 0;
	
}
*/
int main()
{
	Mat srcMat=imread("C:\\Users\\SZJ\\Desktop\\22.jpg",1);
	Mat dst;
	cvtColor(srcMat, dst, COLOR_BGR2HSV);
	int weight = srcMat.cols;
	int height = srcMat.rows;
	
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < weight; j++)
		{
			float p = dst.at<Vec3b>(i, j)[0] * (-2) + 240;
			if (p < 0)
			{
				p = p + 360;
			}
			int t = p / 360 * 255;
			dst.at<Vec3b>(i, j)[0] = p / 360 * 255;
		}
	}
	/*
	for (int i = 0; i < dst.rows; ++i) {
		for (int j = 0; j < dst.cols; ++j) {
			Vec3b& pix = dst.at<Vec3b>(i, j); //指针或引用
			std::swap(pix[0], pix[2]);
		}
	}
	*/
	imshow("dst", dst);
	waitKey(0);
	return 0;
}

/*
#include <vector>
#include <iostream>
#include "opencv2/opencv.hpp"
int main()
{
	using std::cout;
	using std::endl;

	uchar dat[] = { 1, 7,13,  2, 8,14,  3, 9,15,
		4,10,16,  5,11,17,  6,12,18 };

	Mat m(2, 3, CV_8UC3, dat);   // 2x3, 3

	cout << m << endl;
	//[  1,   7,  13,   2,   8,  14,   3,   9,  15;
	//    4,  10,  16,   5,  11,  17,   6,  12,  18]

	for (int i = 0; i < m.rows; ++i) {
		for (int j = 0; j < m.cols; ++j) {
			Vec3b& pix = m.at<Vec3b>(i, j); //指针或引用
			std::swap(pix[0], pix[2]);
		}
	}

	cout << m << endl;
	//[ 13,   7,   1,  14,   8,   2,  15,   9,   3;
	//   16,  10,   4,  17,  11,   5,  18,  12,   6]

	return 0;
}
*/