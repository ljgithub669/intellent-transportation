#pragma once
#pragma execution_character_set("utf-8")
#include<QtWidgets/QWidget>
#include<qboxlayout>
#include<qstringlist>
#include<qstring>
#include<qtreewidget>
#include"ConfigInformation.h"
#include"CFWidget.h"

class MenuTreeForm :public CFWidget
{
	Q_OBJECT
public:
	MenuTreeForm(CFWidget  *parent = Q_NULLPTR);
	~MenuTreeForm();
public:
	//“文件”树 信号定义
	signals:void pictureViewCliked();
	signals:void logViewCliked();
	signals:void violateInformationViewClicked();

			//“设置”树 信号定义
	signals:void backGroundColorSetClicked();
	signals:void listFontSetCliked();
	signals:void listFontColorSetCliked();

			//"帮助"树 信号定义
	signals:void copyrightCliked();
	signals:void helpButtonCliked();
	signals:void aboutUSButtonClicked();

			//"开关"树 信号定义
	signals:void closeSoftwareClicked();
	signals:void mixSoftwareClicked();
	signals:void screenStatusChangeClicked();

public slots:void createClickSignal(QTreeWidgetItem*, int);//发出点击信号
public:
	void loadColorOrFont(ConfigInformation);

private:
	void createMenuTree();
private:
	QTreeWidget * functionTree;
	QVBoxLayout *vBoxLayout;
};
