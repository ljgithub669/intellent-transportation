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
std::vector<std::string> CH_PLATE_CODE{ "京", "沪", "津", "渝", "冀", "晋", "蒙", "辽", "吉", "黑", "苏", "浙", "皖", "闽", "赣", "鲁", "豫", "鄂", "湘", "粤", "桂",
"琼", "川", "贵", "云", "藏", "陕", "甘", "青", "宁", "新", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A",
"B", "C", "D", "E", "F", "G", "H", "J", "K", "L", "M", "N", "P", "Q", "R", "S", "T", "U", "V", "W", "X",
"Y", "Z","港","学","使","警","澳","挂","军","北","南","广","沈","兰","成","济","海","民","航","空" };



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


////图片测试
void TEST_PIPELINE(char* pszImagePath, int default_width)
{
	////判断输入路径是否为空
	if (pszImagePath == NULL)
	{
		std::cout << "NULL plate image!" << std::endl;
		return;
	}

	struct _stat fileStat;
	int ret = _stat(pszImagePath, &fileStat);
	if (ret != 0) //文件不存在
	{
		std::cout << "Image " << pszImagePath << " do not exist!" << std::endl;
		return;
	}

	////载入模型
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
	////命令行读取图片
	cv::Mat image = cv::imread(pszImagePath);

	////输出图片尺寸
	std::cout << "Source Image size (w*h): " << image.cols << " * " << image.rows << std::endl;
	////
	cv::Mat image2;
	bool bScaled = false;
	if (image.cols > image.rows) //w>h 列大于行
	{
		if (image.cols > DEFAULT_DISPLAY_WIDTH)////800
		{
			////更改图片尺寸
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

	//是否需要降低分辨率进行识别
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

	//按置信度进行从大到小排序输出
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
			std::cout << "Plate: " << st.getPlateName() << "\t准确度: " << st.confidence << std::endl;
			cv::Rect region = st.getPlateRect();
			cv::rectangle(image, cv::Point(region.x, region.y), cv::Point(region.x + region.width, region.y + region.height), cv::Scalar(255, 255, 0), 2);
			//将cv::string转化为const char*
			String result = st.getPlateName();
			const char *tmp;
			tmp=(char*)result.c_str();
			putTextZH(image, tmp, Point(region.x, region.y), Scalar(0, 0, 255), 30, "Arial");
			//cv::putText(image, st.getPlateName(), cv::Point(region.x + region.width, region.y + region.height), cv::FONT_HERSHEY_SIMPLEX, 2, cv::Scalar(255, 255, 0), 6, 4, false);
			//取车牌区域
			string  name ="./result_plate/"+ result + ".jpg";
			cv::Mat rio = image(region);
			cv::imwrite(name, rio);
		}
	}
	cv::imshow("recognize result", image);
	cvWaitKey(0);
	
}


////识别单张图片的主函数
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

	TEST_PIPELINE(argv[1], default_width);
	system("pause");
	return 0;
}

