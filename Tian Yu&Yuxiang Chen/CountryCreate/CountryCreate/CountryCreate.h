#pragma once
#pragma execution_character_set("utf-8")
#include <QtWidgets/QWidget>
#include<qcolordialog>
#include<qfontdialog>
#include<qfont>
#include<qcolor>
#include<qstring>
#include<qtextstream>
#include<qfile>
#include<qmessagebox>
#include<qdebug>
#include<qflags>
#include<qevent>
#include<qsplitter>
#include<qboxlayout>
#include<qtextedit>
#include"ConfigInformation.h"
#include"CFWidget.h"
#include"MyDialog.h"
#include"ListForm.h"
#include"MenuTreeForm.h"
#include"StatisticstForm.h"
#include"VideoPlayForm.h"
#include"DrawStatisct.h"
#include"buttonForm.h"

class CountryCreate : public CFWidget
{
	Q_OBJECT
public:
	CountryCreate(CFWidget *parent = Q_NULLPTR);	
public slots:void pictureView();
public slots:void logView();
public slots:void violateInformationView();
public slots:void backGroundColorSet();
public slots:void listFontSet();
public slots:void listFontColorSet();
public slots:void copyright();
public slots:void helpButton();
public slots:void aboutUSButton();
public slots:void closeSoftware();
public slots:void mixSoftware();
public slots:void screenStatusChange();
public slots:void delete_aboutUs();
public slots:void delete_help();
public slots:void delete_copyright();
public slots:void closeDone();

public:
	void setDefaultConfig();
	
private:
	void configEdit(ConfigInformation);
	void connectSignalAndSlot();
	bool eventFilter(QObject *, QEvent *);
	void getDefaultForm();

private:
	MyDialog * _aboutUs=NULL;
	MyDialog * _help=NULL;
	MyDialog * _copyright = NULL;

	MenuTreeForm *menuTreeForm;
	QTextEdit *errorListForm;
	VideoPlayForm *videoPlayForm;
	ListForm *listForm;
	StatisticstForm *statisticstForm;
};

