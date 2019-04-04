#include "VideoPlayForm.h"

VideoPlayForm::VideoPlayForm(CFWidget *parent): CFWidget(parent)
{
	timeLabel = new QLabel();
	videoLabel = new QLabel();
	informationLabel = new QLabel();

	//设置文字排版
	timeLabel->setAlignment(Qt::AlignLeft | Qt::AlignVCenter);
	informationLabel->setAlignment(Qt::AlignRight | Qt::AlignVCenter);
	videoLabel->setAlignment(Qt::AlignCenter | Qt::AlignVCenter);
	videoLabel->setScaledContents(true);

	//界面布局
	QHBoxLayout *hbox = new QHBoxLayout();
	hbox->addWidget(timeLabel);
	hbox->addWidget(informationLabel);
	QVBoxLayout *vbox = new QVBoxLayout();
	vbox->addWidget(videoLabel);
	vbox->addLayout(hbox);
	vbox->setStretchFactor(videoLabel, 1);
	vbox->setStretchFactor(hbox, 0);
	this->setLayout(vbox);

	//设置控件基本色彩
	this->setStyleSheet("VideoPlayForm{background-color: rgb(0, 0, 0);}");
	timeLabel->setStyleSheet("QLabel{font: 12pt \"宋体\";color: rgb(57, 173, 0);}");
	informationLabel->setStyleSheet("QLabel{font: 10pt \"宋体\";color: rgb(57, 173, 0);}");

	//设置文字内容
	timeLabel->setText("时间：xxxx年xx月xx日 xx:xx:xx");
	informationLabel->setText("平均车速：xxx.xxkm/s  平均识别精度：xx.xx%");

	QPixmap pixmap("./picture/11.jpg");
	videoLabel->setPixmap(pixmap.scaled(800, 600, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
	
}


