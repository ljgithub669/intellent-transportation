#include "DrawStatisct.h"

DrawStatisct::DrawStatisct(CFWidget *parent):CFWidget(parent)
{
	this->resize(260, 260);
	pictureBox = new QLabel(this);
	QHBoxLayout *hbox = new QHBoxLayout(this);
	hbox->addWidget(pictureBox);
	this->setLayout(hbox);
}

void DrawStatisct::paintRectangle(int level1, int level2, int level3)
{
	QPixmap pixmap = QPixmap(260, 260);
	pixmap.fill(QColor(0, 0, 0, 0));
	QPainter painter(&pixmap);

	int maxLevel = qMax(qMax(level1, level2), level3);
	int height1 = level1 * 200 / maxLevel;
	int height2 = level2 * 200 / maxLevel;
	int height3 = level3 * 200 / maxLevel;

	QPen pen = QPen(QColor(201, 35, 53), 2);//橙红色
	QPen pen1 = QPen(QColor(0, 0, 0, 0), 2);//透明色
	QPen pen2 = QPen(QColor(236, 113, 20), 1);//橙黄色
	QBrush brush1 = QBrush(Qt::red);
	QBrush brush2 = QBrush(QColor(232, 184, 48));
	QBrush brush3 = QBrush(Qt::blue);

	//绘制纵坐标
	painter.setPen(pen);
	painter.drawLine(30.0, 230.0, 30.0, 10.0);
	painter.drawLine(30.0, 10.0, 25.0, 20.0);
	painter.drawLine(30.0, 10.0, 35.0, 20.0);
	//绘制纵坐标标题
	painter.drawText(37.0, 10.0, "车辆数/辆 归一化");
	//绘制纵坐标标度
	painter.drawLine(30.0, 30.0, 25.0, 30.0);
	painter.drawText(0.0, 33.0, "1.0");
	painter.drawLine(30.0, 80.0, 25.0, 80.0);
	painter.drawText(0.0, 83.0, "0.75");
	painter.drawLine(30.0, 130.0, 25.0, 130.0);
	painter.drawText(0.0, 133.0, "0.5");
	painter.drawLine(30.0, 180.0, 25.0, 180.0);
	painter.drawText(0.0, 183.0, "0.25");
	//painter.drawLine(30.0, 230.0, 25.0, 230.0);
	painter.drawText(15.0, 233.0, "0");

	//绘制柱状
	painter.setPen(pen1);
	painter.setBrush(brush1);
	painter.drawRect(50.0, 230.0 - height1, 40.0, height1);
	painter.setBrush(brush2);
	painter.drawRect(110.0, 230 - height2, 40, height2);
	painter.setBrush(brush3);
	painter.drawRect(170.0, 230 - height3, 40, height3);

	//绘制横坐标
	painter.setPen(pen);
	painter.drawLine(30.0, 230.0, 250.0, 230.0);
	painter.drawLine(250.0, 230.0, 240.0, 235.0);
	painter.drawLine(250.0, 230.0, 240.0, 225.0);
	painter.drawText(230.0, 250.0, "道路");
	painter.drawText(60.0, 250.0, "左侧");
	painter.drawText(120.0, 250.0, "中间");
	painter.drawText(180.0, 250.0, "右侧");

	//标上数字
	painter.setPen(pen2);
	painter.drawText(60.0, 220.0 - height1, QString::number(level1));
	painter.drawText(120.0, 220.0 - height2, QString::number(level2));
	painter.drawText(180.0, 220.0 - height3, QString::number(level3));

	painter.setRenderHint(QPainter::Antialiasing, true);
	this->pictureBox->setPixmap(pixmap);
}

void DrawStatisct::paintRectangle(int level1, int level2, int level3, int level4, int level5,int level6)
{
	QPixmap pixmap = QPixmap(260, 260);
	pixmap.fill(QColor(0, 0, 0, 0));
	QPainter painter(&pixmap);

	int maxLevel = qMax(qMax(qMax(qMax(qMax(level1, level2), level3), level4), level5),level6);
	int height1 = level1 * 200 / maxLevel;
	int height2 = level2 * 200 / maxLevel;
	int height3 = level3 * 200 / maxLevel;
	int height4 = level4 * 200 / maxLevel;
	int height5 = level5 * 200 / maxLevel;
	int height6 = level6 * 200 / maxLevel;

	QPen pen = QPen(QColor(201, 35, 53), 3);//橙红色
	QPen pen1 = QPen(QColor(0, 0, 0, 0), 2);//透明色
	QPen pen2 = QPen(QColor(236, 113, 20), 1);//橙黄色
	QBrush brush1 = QBrush(Qt::red);
	QBrush brush2 = QBrush(QColor(232, 184, 48));
	QBrush brush3 = QBrush(Qt::blue);
	QBrush brush4 = QBrush(Qt::green);
	QBrush brush5 = QBrush(QColor(194, 40, 172));
	QBrush brush6 = QBrush(QColor(197, 90, 17));

	//绘制纵坐标
	painter.setPen(pen);
	painter.drawLine(30.0, 230.0, 30.0, 10.0);
	painter.drawLine(30.0, 10.0, 25.0, 20.0);
	painter.drawLine(30.0, 10.0, 35.0, 20.0);
	//绘制纵坐标标题
	painter.drawText(37.0, 10.0, "车辆数/辆 归一化");
	//绘制纵坐标标度
	painter.drawLine(30.0, 30.0, 25.0, 30.0);
	painter.drawText(0.0, 33.0, "1.0");
	painter.drawLine(30.0, 80.0, 25.0, 80.0);
	painter.drawText(0.0, 83.0, "0.75");
	painter.drawLine(30.0, 130.0, 25.0, 130.0);
	painter.drawText(0.0, 133.0, "0.5");
	painter.drawLine(30.0, 180.0, 25.0, 180.0);
	painter.drawText(0.0, 183.0, "0.25");
	//painter.drawLine(30.0, 230.0, 25.0, 230.0);
	painter.drawText(15.0, 233.0, "0");

	//绘制柱状
	painter.setPen(pen1);
	painter.setBrush(brush1);
	painter.drawRect(40.0, 230.0 - height1, 22.0, height1);
	painter.setBrush(brush2);
	painter.drawRect(72.0, 230.0 - height2, 22.0, height2);
	painter.setBrush(brush3);
	painter.drawRect(104.0, 230.0 - height3, 22.0, height3);
	painter.setBrush(brush4);
	painter.drawRect(136.0, 230.0 - height4, 22.0, height4);
	painter.setBrush(brush5);
	painter.drawRect(168.0, 230.0 - height5, 22.0, height5);
	painter.setBrush(brush6);
	painter.drawRect(200.0, 230.0 - height6, 22.0, height6);

	//绘制横坐标
	painter.setPen(pen);
	painter.drawLine(30.0, 230.0, 250.0, 230.0);
	painter.drawLine(250.0, 230.0, 240.0, 235.0);
	painter.drawLine(250.0, 230.0, 240.0, 225.0);
	painter.drawText(200.0, 250.0, "车速/ km/h");

	//标上数字
	painter.setPen(pen2);
	painter.drawText(40.0, 220.0 - height1, QString::number(level1));
	painter.drawText(72.0, 220.0 - height2, QString::number(level2));
	painter.drawText(104.0, 220.0 - height3, QString::number(level3));
	painter.drawText(136.0, 220.0 - height4, QString::number(level4));
	painter.drawText(168.0, 220.0 - height5, QString::number(level5));
	painter.drawText(200.0, 220.0 - height6, QString::number(level6));

	painter.setRenderHint(QPainter::Antialiasing, true);
	this->pictureBox->setPixmap(pixmap);
}

//车道人数分布
void DrawStatisct::paintCircle(int level1, int level2, int level3)
{
	QPixmap pixmap = QPixmap(260, 260);
	pixmap.fill(QColor(0, 0, 0, 0));
	int number = level1 + level2 + level3;
	double angle;
	int angle1;
	int angle2;
	int angle3;
	if (number == 0)
	{
		number = 3;
		angle = 0;
		angle1 = 1 * 360 * 16 / number;
		angle2 = 1 * 360 * 16 / number;
		angle3 = 360 * 16 - angle1 - angle2;
	}
	else
	{
		angle = 0;
		angle1 = level1 * 360 * 16 / number;
		angle2 = level2 * 360 * 16 / number;
		angle3 = 360 * 16 - angle1 - angle2;
	}
	QPen pen = QPen(QColor(0, 0, 0, 0), 1);
	QPen pen1= QPen(QColor(236,113, 20),1);

	QBrush brush1 = QBrush(Qt::red);
	QBrush brush2 = QBrush(QColor(232, 184, 48));
	QBrush brush3 = QBrush(Qt::blue);
	QRectF rect(50.0, 50.0, 160.0, 160.0);//设定扇形所在的矩形，扇形画在矩形内部
	QPainter painter(&pixmap);

	painter.setPen(pen);
	painter.setBrush(brush1);
	painter.drawPie(rect, 0, angle1);
	painter.setPen(pen1);
	angle = angle1 * 3.1415926 / 5760.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle),130.0+110*cos(angle), 130.0-110*sin(angle));
	painter.drawText(130.0 + 110*cos(angle), 130.0 - 110 * sin(angle), QString("%1辆").arg(level1));

	painter.setPen(pen);
	painter.setBrush(brush2);
	painter.drawPie(rect, angle1, angle2);
	painter.setPen(pen1);
	angle = (angle1 + angle2 / 2.0)*3.1415926 / 2880.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 110*cos(angle), 130.0 -110*sin(angle));
	painter.drawText(130.0 + 110*cos(angle), 130.0 - 110 * sin(angle), QString("%1辆").arg(level2));

	painter.setPen(pen);
	painter.setBrush(brush3);
	painter.drawPie(rect, angle1 + angle2, angle3);
	painter.setPen(pen1);
	angle = (angle1+angle2 + angle3/ 2.0)*3.1415926 / 2880.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 110*cos(angle), 130.0 -110*sin(angle));
	painter.drawText(130.0 + 110*cos(angle), 130.0 - 110 * sin(angle), QString("%1辆").arg(level3));

	painter.setRenderHint(QPainter::Antialiasing, true);
	this->pictureBox->setPixmap(pixmap);
}

//车速分数绘制
void DrawStatisct::paintCircle(int level1, int level2, int level3, int level4, int level5, int level6)
{
	QPixmap pixmap = QPixmap(260, 260);
	pixmap.fill(QColor(0, 0, 0, 0));
	QPainter painter(&pixmap);

	int number = level1 + level2 + level3 + level4 + level5 + level6;
	double angle = 0;
	int angle1;
	int angle2;
	int angle3;
	int angle4;
	int angle5;
	int angle6;

	if (number == 0)
	{
		number = 5;
		angle = 0;
		angle1 = 1 * 360 * 16 / number;
		angle2 = 1 * 360 * 16 / number;
		angle3 = 1 * 360 * 16 / number;
		angle4 = 1 * 360 * 16 / number;
		angle5 = 1 * 360 * 16 / number;
		angle6 = 360 * 16 - angle1 - angle2 - angle3 - angle4 - angle5;
	}
	else
	{
		angle = 0;
		angle1 = level1 * 360 * 16 / number;
		angle2 = level2 * 360 * 16 / number;
		angle3 = level3 * 360 * 16 / number;
		angle4 = level4 * 360 * 16 / number;
		angle5 = level5 * 360 * 16 / number;
		angle6 = 360 * 16 - angle1 - angle2 - angle3 - angle4 - angle5;
	}

	QPen pen = QPen(QColor(0, 0, 0, 0), 1);
	QPen pen1 = QPen(QColor(236, 113, 20), 1);
	QBrush brush1 = QBrush(Qt::red);
	QBrush brush2 = QBrush(QColor(232, 184, 48));
	QBrush brush3 = QBrush(Qt::blue);
	QBrush brush4 = QBrush(Qt::green);
	QBrush brush5 = QBrush(QColor(194, 40, 172));
	QBrush brush6 = QBrush(QColor(197, 90, 17));

	QRectF rect(50.0, 50.0, 160.0, 160.0);//设定扇形所在的矩形，扇形画在矩形内部
	painter.setPen(pen);

	painter.setPen(pen);
	painter.setBrush(brush1);
	painter.drawPie(rect, 0, angle1);
	painter.setPen(pen1);
	angle = angle1 * 3.1415926 / 5760.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 100*cos(angle), 130.0 -100*sin(angle));
	painter.drawText(130.0 + 100*cos(angle), 130.0 - 100 * sin(angle), QString("%1辆").arg(level1));

	painter.setPen(pen);
	painter.setBrush(brush2);
	painter.drawPie(rect, angle1, angle2);
	painter.setPen(pen1);
	angle = (angle1 + angle2 / 2.0)*3.1415926 / 2880.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 100*cos(angle), 130.0 -100*sin(angle));
	painter.drawText(130.0 + 100*cos(angle), 130.0 - 100 * sin(angle), QString("%1辆").arg(level2));

	painter.setPen(pen);
	painter.setBrush(brush3);
	painter.drawPie(rect, angle1 + angle2, angle3);
	painter.setPen(pen1);
	angle = (angle1 + angle2 + angle3 / 2.0)*3.1415926 / 2880.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 100*cos(angle), 130.0 -100*sin(angle));
	painter.drawText(130.0 + 100*cos(angle), 130.0 - 100 * sin(angle), QString("%1辆").arg(level3));

	painter.setPen(pen);
	painter.setBrush(brush4);
	painter.drawPie(rect, angle1 + angle2 + angle3, angle4);
	painter.setPen(pen1);
	angle = (angle1 + angle2 + angle3 + angle4 / 2.0)*3.1415926 / 2880.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 100*cos(angle), 130.0 -100*sin(angle));
	painter.drawText(130.0 + 100*cos(angle), 130.0 - 100 * sin(angle), QString("%1辆").arg(level4));

	painter.setPen(pen);
	painter.setBrush(brush5);
	painter.drawPie(rect, angle1 + angle2 + angle3 + angle4, angle5);
	painter.setPen(pen1);
	angle = (angle1 + angle2 + angle3 + angle4 + angle5 / 2.0)*3.1415926 / 2880.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 100*cos(angle), 130.0 -100*sin(angle));
	painter.drawText(130.0 + 100*cos(angle), 130.0 - 100 * sin(angle), QString("%1辆").arg(level5));

	painter.setPen(pen);
	painter.setBrush(brush6);
	painter.drawPie(rect, angle1 + angle2 + angle3 + angle4 + angle5, angle6);
	painter.setPen(pen1);
	angle = (angle1 + angle2 + angle3 + angle4 + angle5 + angle6 / 2.0)*3.1415926 / 2880.0;
	painter.drawLine(130.0 + 80 * cos(angle), 130.0 - 80 * sin(angle), 130.0 + 100 * cos(angle), 130.0 -100*sin(angle));
	painter.drawText(130.0 + 100*cos(angle), 130.0 - 100 * sin(angle), QString("%1辆").arg(level6));

	painter.setRenderHint(QPainter::Antialiasing, true);

	this->pictureBox->setPixmap(pixmap);
}
