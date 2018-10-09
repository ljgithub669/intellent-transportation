#include "CountryCreate.h"

CountryCreate::CountryCreate(CFWidget *parent):CFWidget(parent)
{
	setDefaultConfig();
	getDefaultForm();
	connectSignalAndSlot();
}

void CountryCreate::getDefaultForm()
{
	menuTreeForm = new MenuTreeForm();
	errorListForm = new QTextEdit();
	errorListForm->setToolTip("犯规日志");
	errorListForm->setReadOnly(true);
	videoPlayForm = new VideoPlayForm();
	listForm = new ListForm();
	statisticstForm = new StatisticstForm();

	QVBoxLayout *vboxLeft = new QVBoxLayout();
	vboxLeft->addWidget(menuTreeForm);
	vboxLeft->addWidget(errorListForm);
	QVBoxLayout *vboxRight = new QVBoxLayout();
	vboxRight->addWidget(listForm);
	vboxRight->addWidget(statisticstForm);
	QHBoxLayout *hboxMain = new QHBoxLayout();
	hboxMain->addLayout(vboxLeft, 1);
	hboxMain->addWidget(videoPlayForm, 6);
	hboxMain->addLayout(vboxRight, 2);

	this->setLayout(hboxMain);

	ConfigInformation Config;
	Config.getConfigFileInformation();
	this->loadColorOrFont(Config);
}


void CountryCreate::setDefaultConfig()
{
	this->setWindowState(Qt::WindowMaximized);
	this->setWindowFlags(Qt::Window);//隐藏边框
	this->setWindowTitle("高速公路监控系统");
	this->setWindowIcon(QIcon("./Icon/software.ico"));
	this->showFullScreen();
	this->installEventFilter(this);
}

void CountryCreate::connectSignalAndSlot()
{
	//绑定开关树
	connect(menuTreeForm, SIGNAL(closeSoftwareClicked()), this, SLOT(closeSoftware()));
	connect(menuTreeForm, SIGNAL(mixSoftwareClicked()), this, SLOT(mixSoftware()));
	connect(menuTreeForm, SIGNAL(screenStatusChangeClicked()), this, SLOT(screenStatusChange()));
	connect(menuTreeForm, SIGNAL(copyrightCliked()), this, SLOT(copyright()));
	connect(menuTreeForm, SIGNAL(aboutUSButtonClicked()), this, SLOT(aboutUSButton()));
	connect(menuTreeForm, SIGNAL(helpButtonCliked()), this, SLOT(helpButton()));
	connect(menuTreeForm, SIGNAL(listFontColorSetCliked()), this, SLOT(listFontColorSet()));
	connect(menuTreeForm, SIGNAL(listFontSetCliked()), this, SLOT(listFontSet()));
	connect(menuTreeForm, SIGNAL(backGroundColorSetClicked()), this, SLOT(backGroundColorSet()));
	connect(menuTreeForm, SIGNAL(violateInformationViewClicked()), this, SLOT(violateInformationView()));
	connect(menuTreeForm, SIGNAL(logViewCliked()), this, SLOT(logView()));
	connect(menuTreeForm, SIGNAL(pictureViewCliked()), this, SLOT(pictureView()));
}

void CountryCreate::pictureView()
{

}

void CountryCreate::logView()
{

}

void CountryCreate::violateInformationView()
{
	
}  



void CountryCreate::copyright()
{
	if (_copyright == NULL)
	{
		_copyright = new MyDialog(QString("版权说明"), QString("./picture/copyright.png"), NULL);
		connect(_copyright, SIGNAL(close()), this, SLOT(delete_copyright()));
	}
	else
	{
		_copyright->show();
	}
}

void CountryCreate::helpButton()
{
	if (_help == NULL)
	{
		_help = new MyDialog(QString("帮助"), QString("./picture/help.png"), NULL);
		connect(_help, SIGNAL(close()), this, SLOT(delete_help()));
	}
	else
	{
		_help->show();
	}
}

void CountryCreate::aboutUSButton()
{
	if (_aboutUs == NULL)
	{
		_aboutUs = new MyDialog(QString("关于我们"), QString("./picture/aboutUs.png"), NULL);
		connect(_aboutUs, SIGNAL(close()), this, SLOT(delete_aboutUs()));
	}
	else
	{
		_aboutUs->show();
	}
}

void CountryCreate::closeSoftware()
{
	this->close();
}

void CountryCreate::mixSoftware()
{
	this->showMinimized();
}

//
void CountryCreate::screenStatusChange()
{
	if (this->isFullScreen())
	{
		this->showNormal();
	}
	else
	{
		this->showFullScreen();
	}
}

//背景颜色设置
void CountryCreate::backGroundColorSet()
{
	ConfigInformation Config;
	Config.getConfigFileInformation();
	QColor newBackgroundColor = QColorDialog::getColor(QColor(Config.getBackgroundRedValue(), Config.getBackgroundGreenValue(), Config.getBackgroundBlueValue()), this, "选择程序背景色");

	if (!newBackgroundColor.isValid())
	{
		return;
	}
	Config.setBackgroundColor(newBackgroundColor);
	//设置配置信息
	this->loadColorOrFont(Config);
	//设置其他界面
	configEdit(Config);//记录配置信息
}

//字体设置
void CountryCreate::listFontSet()
{
	ConfigInformation Config;
	Config.getConfigFileInformation();
	bool chooseSuccessful = false;
	QFont newFont = QFontDialog::getFont(&chooseSuccessful, QFont(QString("%1 [%2]").arg(Config.getFontKind()).arg(Config.getFontType()), Config.getFontSize()), this, "选择字体");
	if (chooseSuccessful == false)
	{
		return;
	}
	Config.setFont(newFont.toString());
	//设置配置信息
	this->loadColorOrFont(Config);
	//设置其他界面
	configEdit(Config);//记录配置信息
}

//字体颜色设置
void CountryCreate::listFontColorSet()
{
	ConfigInformation Config;
	Config.getConfigFileInformation();
	QColor newFontColor = QColorDialog::getColor(QColor(Config.getFontRedValue(), Config.getFontGreenValue(), Config.getFontBlueValue()), this, "选择字体颜色");
	if (!newFontColor.isValid())
	{
		return;
	}
	Config.setFontColor(newFontColor);
	//设置配置信息
	this->loadColorOrFont(Config);
	//设置其他界面
	configEdit(Config);//记录配置信息
}

//记录配置信息
void CountryCreate::configEdit(ConfigInformation configInformation)
{
	QFile configFile("config");
	if (configFile.open(QFile::WriteOnly | QIODevice::Text))
	{
		QTextStream fileIO(&configFile);
		fileIO << configInformation.getBackgroundRedValue() << endl << configInformation.getBackgroundGreenValue() << endl << configInformation.getBackgroundBlueValue() << endl;//写入背景色
		fileIO << configInformation.getFontRedValue() << endl << configInformation.getFontGreenValue() << endl << configInformation.getFontBlueValue() <<endl;//写入文字色
		fileIO << configInformation.getFontKind() <<endl;
		fileIO << configInformation.getFontType() << endl;
		fileIO << configInformation.getFontSize() << endl;
	}
	else
	{
		QMessageBox::information(NULL, "错误", "配置信息写入时出错", QMessageBox::Close);
	}
}

void CountryCreate::closeDone()
{
	delete_aboutUs();
	delete_help();
	delete_copyright();
}

void CountryCreate::delete_aboutUs()
{
	if (this->_aboutUs != NULL)
	{
		disconnect(_aboutUs, SIGNAL(close()), this, SLOT(delete_aboutUs()));
		_aboutUs->close();
		delete _aboutUs;
		this->_aboutUs = NULL;
	}
}

void CountryCreate::delete_help()
{
	if (this->_help != NULL)
	{
		disconnect(_help, SIGNAL(close()), this, SLOT(delete_aboutUs()));
		_help->close();
		delete _help;
		this->_help = NULL;
	}
}

void CountryCreate::delete_copyright()
{
	if (this->_copyright != NULL)
	{
		disconnect(_copyright, SIGNAL(close()), this, SLOT(delete_aboutUs()));
		_copyright->close();
		delete _copyright;
		this->_copyright = NULL;

	}
}

bool CountryCreate::eventFilter(QObject *obj, QEvent *ev)
{
	if (obj == this)
	{
		if (ev->type() == QEvent::Close)
		{
			closeDone();
			return true;
		}
		return false;
	}
	return CountryCreate::eventFilter(obj, ev);
}
