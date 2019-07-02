//#include "stdafx.h"//此程序由人脸识别更改，准确率不错
#include "opencv2\opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
char a[1000], b[1000];
int main()
{
	string xmlPath = "cascade.xml";
	CascadeClassifier ccf;   //创建分类器对象
	cv::Mat imag;
	for (unsigned int i = 0;i < 236;i++) {
		sprintf_s(a, "car_with_plate/(%d).jpg", i);//路径可以是与源代码相同层或绝对路径
		Mat img = cv::imread(a, 3);
		//Mat img = imread("8.jpg");
		//imshow("原图", img);
		if (!ccf.load(xmlPath))   //加载训练文件
		{
			cout << "不能加载指定的xml文件" << endl;
			return 0;
		}
		vector<Rect> faces;  //创建一个容器保存检测出来的脸
		Mat gray;
		cvtColor(img, gray, CV_BGR2GRAY); //转换成灰度图，因为harr特征从灰度图中提取
		equalizeHist(gray, gray);  //直方图均衡行
		ccf.detectMultiScale(gray, faces, 1.1, 3, 0, Size(0, 10), Size(1000, 100)); //检测人脸
		for (vector<Rect>::const_iterator iter = faces.begin();iter != faces.end();iter++)
		{
			rectangle(img, *iter, Scalar(0, 0, 255), 2, 8); //画出脸部矩形
		}
		imshow("faces", img);
		waitKey(100);
		sprintf_s(b, "plate/%d.jpg", i);
		//imag = cv::imread(save, 3);
		cv::imwrite(b, img);
		//cv::imwrite("imwrite/1.jpg", imag);
		cv::waitKey(50);
		cout << "第" << i << "张图片" << endl;
	}
	return 0;
}
