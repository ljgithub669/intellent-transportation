#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include<qstring>
#include"ConfigInformation.h"

class CFWidget:public QWidget
{
	Q_OBJECT
public:
	CFWidget(QWidget *parent = Q_NULLPTR);
	virtual void loadColorOrFont(ConfigInformation);
};

