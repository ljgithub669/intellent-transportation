#include "ShowColorForm.h"

ShowColorForm::ShowColorForm(CFWidget *parent) : CFWidget(parent)
{
	QHBoxLayout *hbox = new QHBoxLayout(this);
	label = new QLabel(this);
	label->setPixmap(QPixmap("./picture/road"));
	hbox->addWidget(label);
	this->setLayout(hbox);
}

void ShowColorForm::setShowKind(int signal)
{
	if (signal == 0)//车道模式
	{
		label->setPixmap(QPixmap("./picture/road.png"));
	}
	else
	{
		label->setPixmap(QPixmap("./picture/speed.png"));
	}
}