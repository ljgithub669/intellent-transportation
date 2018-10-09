#include <QtWidgets/QApplication>
#include "CountryCreate.h"
//测试头文件开始

//#include"ListForm.h"
//#include"MenuTreeForm.h"
//#include"StatisticstForm.h"
//#include"VideoPlayForm.h"
//#include"DrawStatisct.h"
//#include"buttonForm.h"
//#include<qcalendarwidget>
////测试头文件结束

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	CountryCreate w;
	w.show();

	/*ListForm l;
	l.show();*/

	//MenuTreeForm m;
	//m.show();

	//StatisticstForm s;
	//s.show();

	/*VideoPlayForm v;
	v.show();*/

	return a.exec();
}
