#include <sys/stat.h>
#include<opencv2/opencv.hpp>
#include <algorithm>
#include <functional>
#include <string>
#include "../include/Pipeline.h"
#include"./putText.h"
#include <iostream>

#define DEFAULT_DISPLAY_WIDTH (800)
#define DEFAULT_DISPLAT_HEIGHT (600)


void TEST_CAM(char* pszImagePath);
std::vector<std::string> CH_PLATE_CODE{ "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "³", "ԥ", "��", "��", "��", "��",
"��", "��", "��", "��", "��", "��", "��", "��", "��", "��", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A",
"B", "C", "D", "E", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
"Y", "Z","��","ѧ","ʹ","��","��","��","��","��","��","��","��","��","��","��","��","��","��","��" };



using namespace std;

template<class T>
static unsigned int levenshtein_distance(const T &s1, const T &s2) {
	const size_t len1 = s1.size(), len2 = s2.size();
	std::vector<unsigned int> col(len2 + 1), prevCol(len2 + 1);

	for (unsigned int i = 0; i < prevCol.size(); i++) prevCol[i] = i;
	for (unsigned int i = 0; i < len1; i++) {
		col[0] = i + 1;
		for (unsigned int j = 0; j < len2; j++)
			col[j + 1] = min(
				min(prevCol[1 + j] + 1, col[j] + 1),
				prevCol[j] + (s1[i] == s2[j] ? 0 : 1));
		col.swap(prevCol);
	}
	return prevCol[len2];
}

bool compare(const pr::PlateInfo & m1, const pr::PlateInfo & m2) {
	return m1.confidence > m2.confidence;
}




////ͼƬ����
void TEST_PIPELINE(char* pszImagePath, int default_width)
{
	////�ж�����·���Ƿ�Ϊ��
	if (pszImagePath == NULL)
	{
		std::cout << "NULL plate image!" << std::endl;
		return;
	}

	struct _stat fileStat;
	int ret = _stat(pszImagePath, &fileStat);
	if (ret != 0) //�ļ�������
	{
		std::cout << "Image " << pszImagePath << " do not exist!" << std::endl;
		return;
	}

	////����ģ��
	pr::PipelinePR prc(
		"model/cascade.xml",
		"model/HorizonalFinemapping.prototxt",
		"model/HorizonalFinemapping.caffemodel",
		"model/Segmentation.prototxt",
		"model/Segmentation.caffemodel",
		"model/CharacterRecognization.prototxt",
		"model/CharacterRecognization.caffemodel",
		"model/SegmentationFree.prototxt",
		"model/SegmentationFree.caffemodel"
		);

	std::cout << "Processing " << pszImagePath << std::endl;
	////�����ж�ȡͼƬ
	cv::Mat image = cv::imread(pszImagePath);

	////���ͼƬ�ߴ�
	std::cout << "Source Image size (w*h): " << image.cols << " * " << image.rows << std::endl;
	////
	cv::Mat image2;
	bool bScaled = false;
	if (image.cols > image.rows) //w>h �д�����
	{
		if (image.cols > DEFAULT_DISPLAY_WIDTH)////800
		{
			////����ͼƬ�ߴ�
			cv::resize(image, image2, cv::Size(DEFAULT_DISPLAY_WIDTH, image.rows * DEFAULT_DISPLAY_WIDTH / image.cols), cv::INTER_LINEAR);
			bScaled = true;
		}
	}
	else
	{
		if (image.rows > DEFAULT_DISPLAT_HEIGHT)////600
		{
			cv::resize(image, image2, cv::Size(image.cols * DEFAULT_DISPLAT_HEIGHT / image.rows, DEFAULT_DISPLAT_HEIGHT), cv::INTER_LINEAR);
			bScaled = true;
		}
	}

	//�Ƿ���Ҫ���ͷֱ��ʽ���ʶ��
	if (default_width != 0)
	{
		if (image.cols > image.rows) //w>h
		{
			if (image.cols > default_width)
				cv::resize(image, image, cv::Size(default_width, image.rows * default_width / image.cols), cv::INTER_LINEAR);
		}
		else
		{
			if (image.rows > default_width)
				cv::resize(image, image, cv::Size(image.cols * default_width / image.rows, default_width), cv::INTER_LINEAR);
		}
		std::cout << "Scaled image size (w*h): " << image.cols << " * " << image.rows << std::endl;
	}


	std::vector<pr::PlateInfo> res = prc.RunPiplineAsImage(image, pr::SEGMENTATION_FREE_METHOD);


	/**

	//�����ŶȽ��дӴ�С�������
	std::sort(res.begin(), res.end(), compare);
	for (auto st : res) {
	if (st.confidence>0.75) {
	cout << endl;
	std::cout << st.getPlateName() << " " << st.confidence << std::endl;
	cv::Rect region = st.getPlateRect();
	cv::rectangle(image, cv::Point(region.x, region.y), cv::Point(region.x + region.width, region.y + region.height), cv::Scalar(255, 255, 0), 2);
	}
	}
	*/


	for (auto st : res)
	{
		if (st.confidence > 0.75)
		{
			std::cout << "Plate: " << st.getPlateName() << "\t׼ȷ��: " << st.confidence << std::endl;
			cv::Rect region = st.getPlateRect();
			cv::rectangle(image, cv::Point(region.x, region.y), cv::Point(region.x + region.width, region.y + region.height), cv::Scalar(255, 255, 0), 2);
			//��cv::stringת��Ϊconst char*
			String result = st.getPlateName();
			const char *tmp;
			tmp = (char*)result.c_str();
			putTextZH(image, tmp, Point(region.x, region.y), Scalar(0, 0, 255), 30, "Arial");
			//cv::putText(image, st.getPlateName(), cv::Point(region.x + region.width, region.y + region.height), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(255, 255, 0), 6, 4, false);
			//ȡ��������
			string  name = "./result_plate/" + result + ".jpg";
			cv::Mat rio = image(region);
			cv::imwrite(name, rio);
		}
	}
	cv::imshow("recognize result", image);
	cvWaitKey(0);

}





////��Ƶ����
void TEST_CAM(char* pszImagePath)
{
	if (pszImagePath == NULL)
	{
		std::cout << "NULL plate video file path name!" << std::endl;
		return;
	}

	struct _stat fileStat;

	int ret = _stat(pszImagePath, &fileStat);
	if (ret != 0) //�ļ�������
	{
		std::cout << "Video " << pszImagePath << " do not exist!" << std::endl;
		return;
	}

	cv::VideoCapture capture(pszImagePath);
	cv::Mat frame;

	pr::PipelinePR prc(
		"model/cascade.xml",
		"model/HorizonalFinemapping.prototxt",
		"model/HorizonalFinemapping.caffemodel",
		"model/Segmentation.prototxt",
		"model/Segmentation.caffemodel",
		"model/CharacterRecognization.prototxt",
		"model/CharacterRecognization.caffemodel",
		"model/SegmentationFree.prototxt",
		"model/SegmentationFree.caffemodel"
		);

	while (1)
	{
		//��ȡ��һ֡
		if (!capture.read(frame))
		{
			std::cout << "��ȡ��Ƶʧ��" << std::endl;
			exit(1);
		}

		std::vector<pr::PlateInfo> res = prc.RunPiplineAsImage(frame, pr::SEGMENTATION_FREE_METHOD);

		for (auto st : res)
		{
			if (st.confidence > 0.75)
			{
				std::cout << st.getPlateName() << "  " << st.confidence << std::endl;
				cv::Rect region = st.getPlateRect();
	
				cv::rectangle(frame, cv::Point(region.x, region.y), cv::Point(region.x + region.width, region.y + region.height), cv::Scalar(255, 255, 0), 2);
				//��cv::stringת��Ϊconst char*
				String result = st.getPlateName();
				const char *tmp;
				tmp = (char*)result.c_str();
				putTextZH(frame, tmp, Point(region.x, region.y-23), Scalar(0, 0, 255), 25, "Arial");
				//���ƴ洢
				string  name = "./result_plate/" + result + ".jpg";
				cv::Mat rio = frame(region);
				cv::imwrite(name, rio);
			}
		}

		cv::imshow("image", frame);
		cvWaitKey(5);

	}
}



////����ʶ��������
int main(int argc, char** argv)
{
	if (argc < 2 || argc > 3)
	{
		std::cout << "Usage:" << argv[0] << " plate_image_path [SCALE_MAX_IMAGE_WIDTH|0]" << std::endl;
		return 1;
	}

	int default_width = 0;

	if (argc == 3)
		default_width = atoi(argv[2]);
	//ͼƬʶ��
	//TEST_PIPELINE(argv[1], default_width);
	//��Ƶʶ��1s����Ƶʶ����������Ҫ22s��
	TEST_CAM(argv[1]);
	system("pause");
	return 0;
}

