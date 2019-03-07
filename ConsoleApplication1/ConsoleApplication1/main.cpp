#include <opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;


int main()
{
	//读入待处理图像
	Mat src = imread("C:/Users/SZJ/Desktop/1.jpg",1);
	Mat drcimage;
	//创建仿射变换之后的图像
	drcimage = Mat::zeros(src.rows, src.cols, src.type());
	//描述仿射变换的三个点
	Point2f srcTri[3];//源图像点
	Point2f dstTri[3];//目标图像点
	Mat dst;
	Mat roi(src.rows, src.cols, src.type(), Scalar(0, 0, 0));

	//Rect2d r = selectROI(src);
	
	vector<vector<Point>> contour;
	vector<Point> pts;
	pts.push_back(Point(70, 50));
	pts.push_back(Point(200, 50));
	pts.push_back(Point(250, 200));
	pts.push_back(Point(120, 200));
	contour.push_back(pts);
	
	drawContours(roi, contour, 0, Scalar::all(255), -1);
	src.copyTo(dst, roi);
	//dst = src(r);
	//仿射变换矩阵
	Mat warp_mat(2, 3, CV_32FC1);
	//源坐标
	srcTri[0] = Point2f(70, 50);
	srcTri[1] = Point2f(200, 50);
	srcTri[2] = Point2f(120, 200);
	//目标坐标
	dstTri[0] = Point2f(70, 50);
	dstTri[1] = Point2f(180, 50);
	dstTri[2] = Point2f(70, 180);
	//求得仿射变换，即仿射变换的2*3数组
	warp_mat = getAffineTransform(srcTri, dstTri);
	//仿射变换
	warpAffine(dst, drcimage, warp_mat, drcimage.size(),INTER_LINEAR);

	Rect rect(70, 50, 110, 130);
	Mat drcimage_roi = drcimage(rect);
	//drcimage = imread("C:/Users/SZJ/Desktop/1.jpg", 0);
	//完成，显示图像
	imshow("dst", dst);
	imshow("Image", drcimage);
	imshow("drcimage_roi", drcimage_roi);
	
	waitKey(0);
	return 0;
}

/*
int main()
{
	Mat src = imread("C:/Users/SZJ/Desktop/1.jpg", 1);
	Mat dst;
	Mat roi(src.rows, src.cols, src.type(),Scalar(0,0,0));

	vector<vector<Point>> contour;
	vector<Point> pts;
	pts.push_back(Point(70, 50));
	pts.push_back(Point(200, 50));
	pts.push_back(Point(250, 200));
	pts.push_back(Point(120, 200));
	contour.push_back(pts);

	drawContours(roi, contour, 0, Scalar::all(255), -1);
	src.copyTo(dst, roi);
	imshow("roi", roi);
	imshow("img", src);
	imshow("dst", dst);

	waitKey(0);
	return 0;

}
*/
/*
int main()
{
	double xScale = 0.7;
	double yScale = 1;
	Mat src = imread("C:/Users/SZJ/Desktop/1.jpg", 1);
	Mat dst;
	Mat dst2;
	dst = cv::Mat(src.rows*yScale, src.cols*xScale, CV_8UC3);
	dst2 = cv::Mat(src.rows*yScale, src.cols*xScale, CV_8UC3);
	//创建仿射变换矩阵
	float scale[2][3] = { xScale,0,0,0,yScale,0 };   
	Mat scaleMat(2, 3, CV_32FC1, scale);
	warpAffine(src, dst, scaleMat,dst.size(),INTER_AREA);
	warpAffine(src, dst2, scaleMat, dst2.size(), INTER_LINEAR);

	imshow("dst", dst);
	imshow("dst2", dst2);
	waitKey(0);
	return 0;
}
*/