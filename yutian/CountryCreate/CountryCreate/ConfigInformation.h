#pragma once
#pragma execution_character_set("utf-8")
#include<qstring>
#include<qstringlist>
#include<qtextstream>
#include<qfile>
#include<qmessagebox>
#include<qicon>

class ConfigInformation
{
public:
	ConfigInformation();
	ConfigInformation(int, int, int, int, int, int, QString, QString, int);
	ConfigInformation(int, int, int, int, int, int, QString);

	void getConfigFileInformation();
	int getBackgroundRedValue();
	int getBackgroundGreenValue();
	int getBackgroundBlueValue();
	int getFontRedValue();
	int getFontGreenValue();
	int getFontBlueValue();
	QString getFontKind();
	QString getFontType();
	int getFontSize();

	void setBackgroundColor(QColor);
	void setFontColor(QColor);
	void setFont(QString);

private:
	int backgroundRedValue=255; 
	int backgroundGreenValue=255;
	int backgroundBlueValue=255;
	int fontRedValue=0;
	int fontGreenValue=0;
	int fontBlueValue=0;
	QString fontKind="Î¢ÈíÑÅºÚ";
	QString fontType= "Regular";
	int fontSize = 12;
};

