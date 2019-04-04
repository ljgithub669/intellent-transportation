#pragma once
#pragma execution_character_set("utf-8")
#include<qrect>
#include<qpainter>
#include<qpen>
#include<qmath.h>
#include<qbrush>
#include<qlabel>
#include<qboxlayout>
#include<qpixmap>
#include"CFWidget.h"

class DrawStatisct:public CFWidget
{
	Q_OBJECT
public:
	DrawStatisct(CFWidget *parent = Q_NULLPTR);
	void paintCircle(int level1, int level2, int level3);
	void paintCircle(int level1, int level2, int level3, int level4, int level5, int level6);
	void paintRectangle(int level1, int level2, int level3);
	void paintRectangle(int level1, int level2, int level3, int level4, int level5, int level6);

private:
	QLabel *pictureBox;
};

