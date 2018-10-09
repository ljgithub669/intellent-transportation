#include "StatisticstForm.h"

StatisticstForm::StatisticstForm(CFWidget *parent): CFWidget(parent)
{
	myCircle = new DrawStatisct();
	buttonForm = new ButtonForm();
	colorForm = new ShowColorForm();
	QVBoxLayout *vbox = new QVBoxLayout();
	vbox->addWidget(myCircle);
	vbox->addWidget(colorForm);
	QHBoxLayout *hbox = new QHBoxLayout();
	hbox->addLayout(vbox);
	hbox->addWidget(buttonForm);
	this->setLayout(hbox);
	
	myCircle->paintRectangle(100, 200, 100,100,200,100);
	connect(buttonForm->speedChoosed, SIGNAL(clicked(bool)), this, SLOT(setSpeed()));
	connect(buttonForm->roadChoosed, SIGNAL(clicked(bool)), this, SLOT(setRoad()));
}

void StatisticstForm::setSpeed()
{
	this->colorForm->setShowKind(1);
}

void StatisticstForm::setRoad()
{
	this->colorForm->setShowKind(0);
}

void StatisticstForm::loadColorOrFont(ConfigInformation config)
{
	this->setAttribute(Qt::WA_StyledBackground, true);
	this->setStyleSheet(QString("background-color: rgb(%1,%2, %3);color:rgb(%4,%5,%6);font: %7pt \"%8\";").arg(config.getBackgroundRedValue()).arg(config.getBackgroundGreenValue()).arg(config.getBackgroundBlueValue()).arg(config.getFontRedValue()).arg(config.getFontGreenValue()).arg(config.getFontBlueValue()).arg(config.getFontSize()).arg(config.getFontKind()));
	myCircle->setStyleSheet(QString("background-color: rgb(%1,%2, %3);color:rgb(%4,%5,%6);font: %7pt \"%8\";").arg(config.getBackgroundRedValue()).arg(config.getBackgroundGreenValue()).arg(config.getBackgroundBlueValue()).arg(config.getFontRedValue()).arg(config.getFontGreenValue()).arg(config.getFontBlueValue()).arg(config.getFontSize()).arg(config.getFontKind()));
	colorForm->setStyleSheet(QString("background-color: rgb(%1,%2, %3);color:rgb(%4,%5,%6);font: %7pt \"%8\";").arg(config.getBackgroundRedValue()).arg(config.getBackgroundGreenValue()).arg(config.getBackgroundBlueValue()).arg(config.getFontRedValue()).arg(config.getFontGreenValue()).arg(config.getFontBlueValue()).arg(config.getFontSize()).arg(config.getFontKind()));
	buttonForm->setStyleSheet(QString("background-color: rgb(%1,%2, %3);color:rgb(%4,%5,%6);font: %7pt \"%8\";").arg(config.getBackgroundRedValue()).arg(config.getBackgroundGreenValue()).arg(config.getBackgroundBlueValue()).arg(config.getFontRedValue()).arg(config.getFontGreenValue()).arg(config.getFontBlueValue()).arg(config.getFontSize()).arg(config.getFontKind()));

}

