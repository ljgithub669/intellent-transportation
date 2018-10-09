#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include<qtextedit>
#include<qboxlayout>
#include<qgroupbox>
#include<qstring>
#include"CFWidget.h"

class ListForm :public CFWidget
{
	Q_OBJECT
public:
	ListForm(CFWidget  *parent = Q_NULLPTR);
	void getForm();
	void appendTxt(int index, QString value, bool addEndl = false);
private:
	QTextEdit *roadOne;
	QTextEdit *roadTwo;
	QTextEdit *roadThree;
};