#include "ConfigInformation.h"

ConfigInformation::ConfigInformation(){}

ConfigInformation::ConfigInformation(int backgroundRedValue, int backgroundGreenValue, int backgroundBlueValue, int fontRedValue, int fontGreenValue, int fontBlueValue, QString fontKind, QString fontType, int fontSize)
{
	this->backgroundRedValue = backgroundRedValue;
	this->backgroundGreenValue = backgroundGreenValue;
	this->backgroundBlueValue = backgroundBlueValue;
	this->fontRedValue = fontRedValue;
	this->fontGreenValue = fontGreenValue;
	this->fontBlueValue = fontBlueValue;
	this->fontKind = fontKind;
	this->fontType = fontType;
	this->fontSize = fontSize;
}

ConfigInformation::ConfigInformation(int backgroundRedValue, int backgroundGreenValue, int backgroundBlueValue, int fontRedValue, int fontGreenValue, int fontBlueValue, QString fontConfig)
{
	this->backgroundRedValue = backgroundRedValue;
	this->backgroundGreenValue = backgroundGreenValue;
	this->backgroundBlueValue = backgroundBlueValue;
	this->fontRedValue = fontRedValue;
	this->fontGreenValue = fontGreenValue;
	this->fontBlueValue = fontBlueValue;
	QStringList fontList = fontConfig.split(',');
	this->fontKind = fontList[0];
	this->fontType = fontList[10];
	this->fontSize = fontList[1].toInt();
}

void ConfigInformation::getConfigFileInformation()
{
	QTextStream fileIO;
	QFile configFile("config");
	if (configFile.open(QFile::ReadOnly | QIODevice::Text))
	{
		QTextStream fileIO(&configFile);
		this->backgroundRedValue = fileIO.readLine().toInt();
		this->backgroundGreenValue = fileIO.readLine().toInt();
		this->backgroundBlueValue = fileIO.readLine().toInt();//读取背景色
		this->fontRedValue = fileIO.readLine().toInt();
		this->fontGreenValue = fileIO.readLine().toInt();
		this->fontBlueValue = fileIO.readLine().toInt();;//读取字体色
		this->fontKind = fileIO.readLine();
		this->fontType = fileIO.readLine();
		this->fontSize = fileIO.readLine().toInt();//读取字体样式
	}
	else
	{
		QMessageBox::information(NULL, "错误", "读取配置文件出错");
	}
}

int ConfigInformation::getBackgroundRedValue()
{
	return this->backgroundRedValue;
}

int ConfigInformation::getBackgroundGreenValue()
{
	return this->backgroundGreenValue;
}

int ConfigInformation::getBackgroundBlueValue()
{
	return this->backgroundBlueValue;
}

int ConfigInformation::getFontRedValue()
{
	return this->fontRedValue;
}

int ConfigInformation::getFontGreenValue()
{
	return this->fontGreenValue;
}

int ConfigInformation::getFontBlueValue()
{
	return this->fontBlueValue;
}

QString ConfigInformation::getFontKind()
{
	return this->fontKind;
}

QString ConfigInformation::getFontType()
{
	return this->fontType;
}

int ConfigInformation::getFontSize()
{
	return this->fontSize;
}

void ConfigInformation::setBackgroundColor(QColor value)
{
	value = value.toRgb();
	this->backgroundRedValue = value.toRgb().red();
	this->backgroundGreenValue = value.toRgb().green();
	this->backgroundBlueValue = value.toRgb().blue();
}

void ConfigInformation::setFontColor(QColor value)
{
	value = value.toRgb();
	this->fontRedValue = value.toRgb().red();
	this->fontGreenValue = value.toRgb().green();
	this->fontBlueValue = value.toRgb().blue();
}

void ConfigInformation::setFont(QString value)
{
	QStringList stringList = value.split(',');
	this->fontKind = stringList[0];
	this->fontType = stringList[10];
	this->fontSize = stringList[1].toInt();

}

