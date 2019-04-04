#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include<qlabel>
#include<qpixmap>
#include<qboxlayout>
#include"CFWidget.h"

class VideoPlayForm :public CFWidget
{
	Q_OBJECT

public:
	VideoPlayForm(CFWidget *parent = Q_NULLPTR);


private:
	QLabel * timeLabel;
	QLabel *videoLabel;
	QLabel *informationLabel;

};
