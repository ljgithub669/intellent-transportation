#pragma once
#pragma execution_character_set("utf-8")
#include<QtWidgets/QWidget>
#include<qboxlayout>
#include<qlabel>
#include<qpixmap>
#include"CFWidget.h"

class ShowColorForm:public CFWidget
{
	Q_OBJECT
public:
	ShowColorForm(CFWidget  *parent = Q_NULLPTR);
public:
	void setShowKind(int signal);

private:
	QLabel * label;
};

