#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include<qboxlayout>
#include<qgroupbox>
#include"DrawStatisct.h"
#include"showColorForm.h"
#include"CFWidget.h"
#include"buttonForm.h"

class StatisticstForm :public CFWidget
{
	Q_OBJECT
public:
	StatisticstForm(CFWidget  *parent = Q_NULLPTR);
	virtual void loadColorOrFont(ConfigInformation);


private slots:void setSpeed();
private slots:void setRoad();

private:
	DrawStatisct * myCircle;
	ShowColorForm *colorForm;
	ButtonForm *buttonForm;
};
