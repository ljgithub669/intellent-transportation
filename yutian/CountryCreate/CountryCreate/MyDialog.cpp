#include "MyDialog.h"

MyDialog::MyDialog(QString title,QString pass, QWidget *parent) : QWidget(parent)
{
	QHBoxLayout *box = new QHBoxLayout(this);
	QLabel *label = new QLabel(this);
	QPixmap infomation(pass);
	label->setPixmap(infomation);
	label->show();
	box->addWidget(label);
	this->setLayout(box);
	this->setWindowFlags(Qt::WindowCloseButtonHint | Qt::WindowStaysOnTopHint);
	this->setWindowTitle(title);
	this->show();
	this->setFixedSize(this->width(), this->height());
}
