#pragma once
#pragma execution_character_set("utf-8")
#include<QtWidgets/QWidget>
#include<qradiobutton>
#include<qboxlayout>
#include<qgroupbox>
#include"CFWidget.h"

class ButtonForm:public CFWidget
{
	Q_OBJECT
public:
	ButtonForm(CFWidget *parent = Q_NULLPTR);
public slots:void setTimeModelChoose();
public slots:void setKindModelChoose();
public slots:void setStatisticstModelChoose();

public:

	int timeModelChoose = 2;//signal==1: 历史  ;  signal==2: 当前;
	int kindModelChoose = 2;//signal==1: 车速分布  ;  signal==2: 车道分布
	int statisticstChoose = 2;//signal==1: 柱状图  ;  signal==2: 饼状图

	QRadioButton * todayChoosed;
	QRadioButton *NowChoosed;
	QRadioButton *speedChoosed;
	QRadioButton *roadChoosed;
	QRadioButton *circleChoose;
	QRadioButton *rectangleChoose;
};

