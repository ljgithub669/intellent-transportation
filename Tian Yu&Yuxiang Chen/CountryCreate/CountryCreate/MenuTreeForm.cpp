#include "MenuTreeForm.h"

MenuTreeForm::MenuTreeForm(CFWidget *parent): CFWidget(parent)
{
	createMenuTree();
	connect(functionTree, SIGNAL(itemClicked(QTreeWidgetItem*, int)), this, SLOT(createClickSignal(QTreeWidgetItem *, int)));
}

void MenuTreeForm::createMenuTree()
{
	//实例化垂直布局盒子
	this->vBoxLayout = new QVBoxLayout(this);

	//定义一棵树
	this->functionTree = new QTreeWidget(this);
	this->functionTree->setColumnCount(1);
	this->functionTree->setHeaderLabel("控制台");
	this->functionTree->setHeaderHidden(true);
	//存储树
	QTreeWidgetItem *fileView = new QTreeWidgetItem(functionTree, QStringList() << "存储");
	QTreeWidgetItem *pictureView = new QTreeWidgetItem(fileView, QStringList() << "抓拍图片");
	QTreeWidgetItem *logView = new QTreeWidgetItem(fileView, QStringList() << "日志信息");
	QTreeWidgetItem *violateInformationView = new QTreeWidgetItem(fileView, QStringList() << "违章信息");
	//设置"存储树"图标
	fileView->setIcon(0, QIcon("./Icon/fileView.ico"));
	pictureView->setIcon(0, QIcon("./Icon/pictureView.ico"));
	logView->setIcon(0, QIcon("./Icon/logView.ico"));
	violateInformationView->setIcon(0, QIcon("./Icon/violateInformationView.ico"));

	//设置树
	QTreeWidgetItem *softwareSet = new QTreeWidgetItem(functionTree, QStringList() << "设置");
	QTreeWidgetItem *backGroundColorSet = new QTreeWidgetItem(softwareSet, QStringList() << "背景颜色设置");
	QTreeWidgetItem *listFontSet = new QTreeWidgetItem(softwareSet, QStringList() << "输出字体大小设置");
	QTreeWidgetItem *listFontColorSet = new QTreeWidgetItem(softwareSet, QStringList() << "输出文字颜色设置");
	//设置"设置树"图标
	softwareSet->setIcon(0, QIcon("./Icon/softwareSet.ico"));
	backGroundColorSet->setIcon(0, QIcon("./Icon/backGroundColorSet.ico"));
	listFontSet->setIcon(0, QIcon("./Icon/listFontSet.ico"));
	listFontColorSet->setIcon(0, QIcon("./Icon/listFontColorSet.ico"));

	//帮助树
	QTreeWidgetItem *softwareHelp = new QTreeWidgetItem(functionTree, QStringList() << "帮助");
	QTreeWidgetItem *helpButton = new QTreeWidgetItem(softwareHelp, QStringList() << "查看帮助");
	QTreeWidgetItem *copyright = new QTreeWidgetItem(softwareHelp, QStringList() << "版权说明");
	QTreeWidgetItem *aboutUSButton = new QTreeWidgetItem(softwareHelp, QStringList() << "关于我们");
	//设置"帮助树"图标
	softwareHelp->setIcon(0, QIcon("./Icon/softwareHelp.ico"));
	helpButton->setIcon(0, QIcon("./Icon/helpButton.ico"));
	copyright->setIcon(0, QIcon("./Icon/copyright.ico"));
	aboutUSButton->setIcon(0, QIcon("./Icon/aboutUsButton.ico"));

	//开关树
	QTreeWidgetItem *softwareSwitch = new QTreeWidgetItem(functionTree, QStringList() << "开关");
	QTreeWidgetItem *screenStatusChange = new QTreeWidgetItem(softwareSwitch, QStringList() << "全屏/退出全屏");
	QTreeWidgetItem *MixSoftware = new QTreeWidgetItem(softwareSwitch, QStringList() << "程序最小化");
	QTreeWidgetItem *closeSoftware = new QTreeWidgetItem(softwareSwitch, QStringList() << "退出程序");
	//设置"开关树"图标
	softwareSwitch->setIcon(0, QIcon("./Icon/softwareSwitch.ico"));
	screenStatusChange->setIcon(0, QIcon("./Icon/screenStatusChange.ico"));
	MixSoftware->setIcon(0, QIcon("./Icon/MixSoftware.ico"));
	closeSoftware->setIcon(0, QIcon("./Icon/closeSoftware.ico"));

	functionTree->expandAll();
	vBoxLayout->addWidget(functionTree);
	this->setLayout(vBoxLayout);
}

void MenuTreeForm::createClickSignal(QTreeWidgetItem *item, int column)
{
	if (item->text(0) == "抓拍图片"&&item->parent()->text(0) == "存储")
	{
		emit pictureViewCliked();
	}
	else if (item->text(0) == "日志信息"&&item->parent()->text(0) == "存储")
	{
		emit logViewCliked();
	}
	else if (item->text(0) == "违章信息"&&item->parent()->text(0) == "存储")
	{
		emit violateInformationViewClicked();
	}
	else if (item->text(0) == "背景颜色设置"&&item->parent()->text(0) == "设置")
	{
		emit backGroundColorSetClicked();
	}

	else if (item->text(0) == "输出字体大小设置"&&item->parent()->text(0) == "设置")
	{
		emit listFontSetCliked();
	}
	else if (item->text(0) == "输出文字颜色设置"&&item->parent()->text(0) == "设置")
	{
		emit listFontColorSetCliked();
	}
	else if (item->text(0) == "查看帮助"&&item->parent()->text(0) == "帮助")
	{
		emit helpButtonCliked();
	}
	else if (item->text(0) == "版权说明"&&item->parent()->text(0) == "帮助")
	{
		emit copyrightCliked();
	}
	else if (item->text(0) == "关于我们"&&item->parent()->text(0) == "帮助")
	{
		emit aboutUSButtonClicked();
	}
	else if (item->text(0) == "全屏/退出全屏"&&item->parent()->text(0) == "开关")
	{
		emit screenStatusChangeClicked();
	}
	else if (item->text(0) == "程序最小化"&&item->parent()->text(0) == "开关")
	{
		emit mixSoftwareClicked();
	}
	else if (item->text(0) == "退出程序"&&item->parent()->text(0) == "开关")
	{
		emit closeSoftwareClicked();
	}
}

void MenuTreeForm::loadColorOrFont(ConfigInformation config)
{
	this->setAttribute(Qt::WA_StyledBackground,true);
	this->setStyleSheet(QString("background-color: rgb(%1,%2, %3);color:rgb(%4,%5,%6);font: %7pt \"%8\";").arg(config.getBackgroundRedValue()).arg(config.getBackgroundGreenValue()).arg(config.getBackgroundBlueValue()).arg(config.getFontRedValue()).arg(config.getFontGreenValue()).arg(config.getFontBlueValue()).arg(config.getFontSize()).arg(config.getFontKind()));
}

MenuTreeForm::~MenuTreeForm()
{
	delete this->functionTree;
}