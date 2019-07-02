//#include "stdafx.h"//�˳���������ʶ����ģ�׼ȷ�ʲ���
#include "opencv2\opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;
char a[1000], b[1000];
int main()
{
	string xmlPath = "cascade.xml";
	CascadeClassifier ccf;   //��������������
	cv::Mat imag;
	for (unsigned int i = 0;i < 236;i++) {
		sprintf_s(a, "car_with_plate/(%d).jpg", i);//·����������Դ������ͬ������·��
		Mat img = cv::imread(a, 3);
		//Mat img = imread("8.jpg");
		//imshow("ԭͼ", img);
		if (!ccf.load(xmlPath))   //����ѵ���ļ�
		{
			cout << "���ܼ���ָ����xml�ļ�" << endl;
			return 0;
		}
		vector<Rect> faces;  //����һ�������������������
		Mat gray;
		cvtColor(img, gray, CV_BGR2GRAY); //ת���ɻҶ�ͼ����Ϊharr�����ӻҶ�ͼ����ȡ
		equalizeHist(gray, gray);  //ֱ��ͼ������
		ccf.detectMultiScale(gray, faces, 1.1, 3, 0, Size(0, 10), Size(1000, 100)); //�������
		for (vector<Rect>::const_iterator iter = faces.begin();iter != faces.end();iter++)
		{
			rectangle(img, *iter, Scalar(0, 0, 255), 2, 8); //������������
		}
		imshow("faces", img);
		waitKey(100);
		sprintf_s(b, "plate/%d.jpg", i);
		//imag = cv::imread(save, 3);
		cv::imwrite(b, img);
		//cv::imwrite("imwrite/1.jpg", imag);
		cv::waitKey(50);
		cout << "��" << i << "��ͼƬ" << endl;
	}
	return 0;
}
