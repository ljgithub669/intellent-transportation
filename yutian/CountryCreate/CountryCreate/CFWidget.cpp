#include "CFWidget.h"

CFWidget::CFWidget(QWidget *parent):QWidget(parent)
{

}

void CFWidget::loadColorOrFont(ConfigInformation config)
{
	this->setAttribute(Qt::WA_StyledBackground, true);
	this->setStyleSheet(QString("background-color: rgb(%1,%2, %3);color:rgb(%4,%5,%6);font: %7pt \"%8\";").arg(config.getBackgroundRedValue()).arg(config.getBackgroundGreenValue()).arg(config.getBackgroundBlueValue()).arg(config.getFontRedValue()).arg(config.getFontGreenValue()).arg(config.getFontBlueValue()).arg(config.getFontSize()).arg(config.getFontKind()));
}