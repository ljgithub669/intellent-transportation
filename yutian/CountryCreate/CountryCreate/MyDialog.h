#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include<qboxlayout>
#include<QString>
#include<qlabel>
#include<qpixmap>

class MyDialog : public QWidget
{
	Q_OBJECT
public:
	MyDialog(QString,QString, QWidget *parent = Q_NULLPTR);
};

