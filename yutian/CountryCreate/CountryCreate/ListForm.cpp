#include "ListForm.h"

ListForm::ListForm(CFWidget *parent): CFWidget(parent)
{
	getForm();
	/*this->appendTxt(2, "");
	this->appendTxt(1, "fhiugew", true);
	this->appendTxt(2, "afhiu",false);
	this->appendTxt(1, "fhiugew", true);
	this->appendTxt(2, "afhiu");
	this->appendTxt(3, "fhiugew", true);*/
	roadOne->append("<img src=C:/11.jpg>");//<img src=
}

void ListForm::getForm()
{
	roadOne = new QTextEdit(this);
	roadTwo = new QTextEdit(this);
	roadThree = new QTextEdit(this);

	roadOne->setToolTip("道路1");
	roadTwo->setToolTip("道路2");
	roadThree->setToolTip("道路3");

	roadOne->setReadOnly(true);
	roadTwo->setReadOnly(true);
	roadThree->setReadOnly(true);

	QHBoxLayout *hbox = new QHBoxLayout(this);
	hbox->addWidget(roadOne);
	hbox->addWidget(roadTwo);
	hbox->addWidget(roadThree);	
}

void ListForm::appendTxt(int index, QString value,bool addEndl)
{
	if (index == 1)
	{
		roadOne->append(value);
		if (addEndl == true)
		{
			roadOne->append("\n");
		}
	}
	else if (index == 2)
	{
		roadTwo->append(value);
		if (addEndl == true)
		{
			roadTwo->append("\n");
		}
	}
	else if (index == 3)
	{
		roadThree->append(value);
		if (addEndl == true)
		{
			roadThree->append("\n");
		}
	}
	
}
