#include "bottombar.h"
#include<QDebug>
#include<QToolTip>

/*
 *Author:LY
 *Function:实现底部栏
 */

BottomBar::BottomBar(QWidget *parent) : QWidget(parent)
{
    this->setAttribute(Qt::WA_StyledBackground);


    multiplyingPower=1;//倍速播放，默认1倍速

    setFixedHeight(60);
    lastButton = new QPushButton(this);//上一个按钮
    pauseButton = new QPushButton(this);//暂停/播放按钮
    nextButton = new QPushButton(this);//下一个按钮
    currentPos = new QLabel(this);//播放到的时间
    playSlider = new MySlider(this);//播放条
    totalTime = new QLabel(this);//总时长
    volumeButton = new BottomButton(this);//静音/恢复音量按钮
    volumeSlider = new MySlider(this);//音量条
    volumeSlider->setValue(10);
    playModeButton = new QPushButton(this);//播放模式按钮
    switchModeButton = new QPushButton(this);//切换音乐/视频模式按钮
    space = new QLabel ();//底部空白
    definitionButton = new BottomButton();//清晰度按钮
    settingsButton = new BottomButton();//视频设置按钮
    full_screenButton = new QPushButton();//全屏/恢复按钮


    //使Button、Slider不接受由Tab、鼠标中键产生焦点
    lastButton->setFocusPolicy(Qt::NoFocus);
    pauseButton->setFocusPolicy(Qt::NoFocus);
    nextButton->setFocusPolicy(Qt::NoFocus);
    playSlider->setFocusPolicy(Qt::NoFocus);
    volumeButton->setFocusPolicy(Qt::NoFocus);
    volumeSlider->setFocusPolicy(Qt::NoFocus);
    playModeButton->setFocusPolicy(Qt::NoFocus);
    switchModeButton->setFocusPolicy(Qt::NoFocus);
    definitionButton->setFocusPolicy(Qt::NoFocus);
    settingsButton->setFocusPolicy(Qt::NoFocus);
    full_screenButton->setFocusPolicy(Qt::NoFocus);


    currentPos->setAlignment(Qt::AlignRight|Qt::AlignVCenter);
    playSlider->setOrientation(Qt::Horizontal);
    volumeSlider->setOrientation(Qt::Horizontal);
    /*
     * playSlider还需设最大值
     */
    playSlider->setMaximum(6009); //test
    volumeSlider->setMaximum(100);


    lastButton->setObjectName("lastButton");
    pauseButton->setObjectName("pauseButton");
    nextButton->setObjectName("nextButton");
    currentPos->setObjectName("currentPos");
    playSlider->setObjectName("playSlider");
    totalTime->setObjectName("totalTime");
    volumeButton->setObjectName("volumeButton");
    volumeSlider->setObjectName("volumeScrollBar");
    playModeButton->setObjectName("playModeButton");
    switchModeButton->setObjectName("switchModeButton");
    definitionButton->setObjectName("definitionButton");
    settingsButton->setObjectName("settingsButton");
    full_screenButton->setObjectName("full_screenButton");


    //固定按钮大小
	lastButton->setFixedSize(40, 40);
	pauseButton->setFixedSize(40, 40);
	nextButton->setFixedSize(40, 40);
	currentPos->setFixedSize(36, 30);
	playSlider->setFixedHeight(20);
	totalTime->setFixedSize(42, 30);
	volumeButton->setFixedSize(30, 30);
	volumeSlider->setFixedSize(60, 20);
	playModeButton->setFixedSize(30, 30);
	switchModeButton->setFixedSize(30, 30);
	definitionButton->setFixedSize(30, 30);
	settingsButton->setFixedSize(30, 30);
	full_screenButton->setFixedSize(30, 30);


    lastButton->setFlat(true);
    pauseButton->setFlat(true);
    nextButton->setFlat(true);
    volumeButton->setFlat(true);
    playModeButton->setFlat(true);
    switchModeButton->setFlat(true);
    definitionButton->setFlat(true);
    settingsButton->setFlat(true);
    full_screenButton->setFlat(true);



	lastButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/last.png); }");
	pauseButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/pause.png); }");
	nextButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/next.png); }");
	currentPos->setText(QStringLiteral("00:00"));
	totalTime->setText(QStringLiteral("4:00"));
	volumeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/volume.png); }");
	playModeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/order.png); }");
	switchModeButton->setText(QStringLiteral("切换"));
	definitionButton->setText(QStringLiteral("清晰度"));
	settingsButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/settings.png); }");
	full_screenButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/fullScreen.png); }");
	//TEST
	volume = 10;


    //鼠标悬停在按钮上显示提示条
    lastButton->setToolTip(QStringLiteral("上一个"));
    pauseButton->setToolTip(QStringLiteral("播放"));
    nextButton->setToolTip(QStringLiteral("下一个"));
    volumeButton->setToolTip(QStringLiteral("静音"));
    volumeSlider->setToolTip(QStringLiteral("音量调节(Up/Down)"));
    playModeButton->setToolTip(QStringLiteral("播放模式"));
    switchModeButton->setToolTip(QStringLiteral("全屏"));
    definitionButton->setToolTip(QStringLiteral("清晰度"));
    settingsButton->setToolTip(QStringLiteral("设置"));
    full_screenButton->setToolTip(QStringLiteral("全屏"));


    //改变光标样式
    lastButton->setCursor(Qt::PointingHandCursor);
    pauseButton->setCursor(Qt::PointingHandCursor);
    nextButton->setCursor(Qt::PointingHandCursor);
    playSlider->setCursor(Qt::PointingHandCursor);
    volumeButton->setCursor(Qt::PointingHandCursor);
    volumeSlider->setCursor(Qt::PointingHandCursor);
    playModeButton->setCursor(Qt::PointingHandCursor);
    switchModeButton->setCursor(Qt::PointingHandCursor);
    definitionButton->setCursor(Qt::PointingHandCursor);
    settingsButton->setCursor(Qt::PointingHandCursor);
    full_screenButton->setCursor(Qt::PointingHandCursor);


    BottomLayout = new QVBoxLayout(this);
    BmBottomLayout = new QHBoxLayout();
    BmBottomLayout->addWidget(lastButton);
    BmBottomLayout->addWidget(pauseButton);
    BmBottomLayout->addWidget(nextButton);
    BmBottomLayout->addWidget(currentPos);
    BmBottomLayout->addWidget(playSlider);
    BmBottomLayout->addWidget(totalTime);
    BmBottomLayout->addWidget(volumeButton);
    BmBottomLayout->addWidget(volumeSlider);
    BmBottomLayout->addWidget(playModeButton);
    BmBottomLayout->addWidget(switchModeButton);
    BmBottomLayout->setContentsMargins(0, 5, 0, 5);
    BmBottomLayout->setSpacing(0);
    BottomLayout->addLayout(BmBottomLayout);
	BottomLayout->setContentsMargins(0, 0, 0, 0);
	BottomLayout->setSpacing(0);


    volumeWidget = new Widget(parent);//视频模式音量窗口
    volumeWidget->setObjectName(QString::fromUtf8("volumeWidget"));
    volumeWidget->setAutoFillBackground(true);//test
    volumeWidget->setPalette(QPalette(Qt::black));//test
    volumeWidget->setGeometry(200, 200, 30, 70);//test
    volumeWidget->hide();
    volumeLayout =new QVBoxLayout(volumeWidget);//视频模式音量窗口的布局
    volumeLayout->setContentsMargins(5, 5, 5, 5);


    definitionWidget = new Widget(parent);//视频模式清晰度窗口
    definitionWidget->setObjectName(QString::fromUtf8("definitionWidget"));
    definitionWidget->setAutoFillBackground(true);//test
    definitionWidget->setPalette(QPalette(Qt::black));//test
    definitionWidget->setGeometry(200, 200, 40, 90);//test
    definitionWidget->hide();
    //视频模式清晰度窗口下各清晰度按钮
    autoDefinitionButton = new QPushButton(definitionWidget);
    p360DefinitionButton = new QPushButton(definitionWidget);
    p480DefinitionButton = new QPushButton(definitionWidget);
    p720DefinitionButton = new QPushButton(definitionWidget);
    autoDefinitionButton->setFocusPolicy(Qt::NoFocus);
    p360DefinitionButton->setFocusPolicy(Qt::NoFocus);
    p480DefinitionButton->setFocusPolicy(Qt::NoFocus);
    p720DefinitionButton->setFocusPolicy(Qt::NoFocus);
    autoDefinitionButton->setObjectName("autoDefinitionButton");
    p360DefinitionButton->setObjectName("p360DefinitionButton");
    p480DefinitionButton->setObjectName("p480DefinitionButton");
    p720DefinitionButton->setObjectName("p720DefinitionButton");
    autoDefinitionButton->setFixedSize(30,20);
    p360DefinitionButton->setFixedSize(30,20);
    p480DefinitionButton->setFixedSize(30,20);
    p720DefinitionButton->setFixedSize(30,20);
    autoDefinitionButton->setFlat(true);
    p360DefinitionButton->setFlat(true);
    p480DefinitionButton->setFlat(true);
    p720DefinitionButton->setFlat(true);
    autoDefinitionButton->setText(QStringLiteral("自动"));//TEST
    p360DefinitionButton->setText(QStringLiteral("普通"));//TEST
    p480DefinitionButton->setText(QStringLiteral("清晰"));//TEST
    p720DefinitionButton->setText(QStringLiteral("高清"));//TEST
    definitionLayout =new QVBoxLayout(definitionWidget);//视频模式清晰度窗口的布局
    definitionLayout->addWidget(p720DefinitionButton);
    definitionLayout->addWidget(p480DefinitionButton);
    definitionLayout->addWidget(p360DefinitionButton);
    definitionLayout->addWidget(autoDefinitionButton);
    definitionLayout->setContentsMargins(5, 5, 5, 5);
    definitionLayout->setSpacing(0);



    settingsWidget = new Widget(parent);//视频模式设置窗口
    settingsWidget->setObjectName(QString::fromUtf8("settingsWidget"));
    settingsWidget->setAutoFillBackground(true);//test
    settingsWidget->setPalette(QPalette(Qt::black));//test
    settingsWidget->setGeometry(200, 200, 100, 165);//test
    settingsWidget->hide();
    //视频模式设置窗口下各按钮
    playModeLabel = new QLabel(settingsWidget);
    playModeButton_1 = new QPushButton(settingsWidget);
    playModeButton_2 = new QPushButton(settingsWidget);
    playModeButton_3 = new QPushButton(settingsWidget);
    playSpeedLabel = new QLabel(settingsWidget);
    multiplyingPowerLabel = new QLabel(settingsWidget);
    playSpeedSlider = new MySlider(settingsWidget);
    videoRatioLabel = new QLabel(settingsWidget);
    autoRatioButton = new QPushButton(settingsWidget);
    ratio4_3Button = new QPushButton(settingsWidget);
    ratio16_9Button = new QPushButton(settingsWidget);
    othersLabel = new QLabel(settingsWidget);
    someFunctionButton = new QPushButton(settingsWidget);//test

    playSpeedSlider->setMaximum(3);
    playSpeedSlider->setValue(1);//倍速播放默认一倍速

    playModeButton_1->setFocusPolicy(Qt::NoFocus);
    playModeButton_2->setFocusPolicy(Qt::NoFocus);
    playModeButton_3->setFocusPolicy(Qt::NoFocus);
    playSpeedSlider->setFocusPolicy(Qt::NoFocus);
    autoRatioButton->setFocusPolicy(Qt::NoFocus);
    ratio4_3Button->setFocusPolicy(Qt::NoFocus);
    ratio16_9Button->setFocusPolicy(Qt::NoFocus);
    someFunctionButton->setFocusPolicy(Qt::NoFocus);

    playSpeedSlider->setOrientation(Qt::Horizontal);

    playModeLabel->setObjectName("playModeLabel");
    playModeButton_1->setObjectName("playModeButton_1");
    playModeButton_2->setObjectName("playModeButton_2");
    playModeButton_3->setObjectName("playModeButton_3");
    playSpeedLabel->setObjectName("playSpeedLabel");
    multiplyingPowerLabel->setObjectName("multiplyingPowerLabel");
    playSpeedSlider->setObjectName("playSpeedSlider");
    videoRatioLabel->setObjectName("videoRatioLabel");
    autoRatioButton->setObjectName("autoRatioButton");
    ratio4_3Button->setObjectName("ratio4_3Button");
    ratio16_9Button->setObjectName("ratio16_9Button");
    othersLabel->setObjectName("othersLabel");
    someFunctionButton->setObjectName("someFunctionButton");

    playModeLabel->setFixedSize(90,15);
    playModeButton_1->setFixedSize(30,20);
    playModeButton_2->setFixedSize(30,20);
    playModeButton_3->setFixedSize(30,20);
    playSpeedLabel->setFixedSize(90,15);
    multiplyingPowerLabel->setFixedSize(90,15);
    playSpeedSlider->setFixedSize(90,20);
    videoRatioLabel->setFixedSize(30,15);
    autoRatioButton->setFixedSize(30,20);
    ratio4_3Button->setFixedSize(30,20);
    ratio16_9Button->setFixedSize(30,20);
    othersLabel->setFixedSize(30,15);
    someFunctionButton->setFixedSize(30,20);




    playModeButton_1->setFlat(true);
    playModeButton_2->setFlat(true);
    playModeButton_3->setFlat(true);
    autoRatioButton->setFlat(true);
    ratio4_3Button->setFlat(true);
    ratio16_9Button->setFlat(true);
    someFunctionButton->setFlat(true);

    playModeLabel->setText(QStringLiteral("播放方式"));
    playModeButton_1->setText(QStringLiteral("默认"));
    playModeButton_2->setText(QStringLiteral("循环"));
    playModeButton_3->setText(QStringLiteral("播完暂停"));
    playSpeedLabel->setText(QStringLiteral("播放速度"));
    multiplyingPowerLabel->setText(QStringLiteral("0.5 1.0 1.25 1.5 2.0"));
    videoRatioLabel->setText(QStringLiteral("视频比例"));
    autoRatioButton->setText(QStringLiteral("自动"));
    ratio4_3Button->setText(QStringLiteral("4:3"));
    ratio16_9Button->setText(QStringLiteral("16:9"));
    othersLabel->setText(QStringLiteral("其他"));
    someFunctionButton->setText(QStringLiteral("其他"));

    settingsLayout =new QVBoxLayout(settingsWidget);//视频模式设置窗口的布局
    settingsLayout->addWidget(playModeLabel);
    QHBoxLayout * playModeLayout = new QHBoxLayout();
    playModeLayout->addWidget(playModeButton_1);
    playModeLayout->addWidget(playModeButton_2);
    playModeLayout->addWidget(playModeButton_3);
    playModeLayout->setContentsMargins(0, 0, 0, 0);
    playModeLayout->setSpacing(0);
    settingsLayout->addLayout(playModeLayout);
    settingsLayout->addWidget(playSpeedLabel);
    settingsLayout->addWidget(multiplyingPowerLabel);
    settingsLayout->addWidget(playSpeedSlider);
    settingsLayout->addWidget(videoRatioLabel);
    QHBoxLayout * videoRatioLayout = new QHBoxLayout();
    videoRatioLayout->addWidget(autoRatioButton);
    videoRatioLayout->addWidget(ratio4_3Button);
    videoRatioLayout->addWidget(ratio16_9Button);
    videoRatioLayout->setContentsMargins(0, 0, 0, 0);
    videoRatioLayout->setSpacing(0);
    settingsLayout->addLayout(videoRatioLayout);
    settingsLayout->addWidget(othersLabel);
    settingsLayout->addWidget(someFunctionButton);
    settingsLayout->setContentsMargins(5, 5, 5, 5);
    settingsLayout->setSpacing(0);





    connect(playSlider,SIGNAL(valueChanged(int)),this,SLOT(on_playSlider_valueChanged(int)));
    connect(volumeButton,SIGNAL(clicked(bool)),this,SLOT(on_volumeButton_clicked()));
    connect(volumeSlider,SIGNAL(valueChanged(int)),this,SLOT(on_volumeSlider_valueChanged(int)));
    connect(switchModeButton,SIGNAL(clicked(bool)),this,SLOT(on_switchModeButton_clicked()));
    connect(volumeButton,SIGNAL(leaveSignal()),this,SLOT(volumeWidgetDetection()));
    connect(definitionButton,SIGNAL(enterSignal(int ,int)),definitionWidget,SLOT(display(int,int)));
    connect(definitionButton,SIGNAL(leaveSignal()),this,SLOT(definitionWidgetDetection()));
    connect(settingsButton,SIGNAL(enterSignal(int ,int)),settingsWidget,SLOT(display(int,int)));
    connect(settingsButton,SIGNAL(leaveSignal()),this,SLOT(settingsWidgetDetection()));
    connect(full_screenButton,SIGNAL(clicked(bool)),this,SLOT(on_full_screenButton_clicked()));
	connect(full_screenButton, SIGNAL(clicked(bool)), this, SLOT(changeButtonSize()));
	connect(this, SIGNAL(wheelMoving(int, int)), volumeWidget, SLOT(display(int, int)));




}

void BottomBar::on_playSlider_valueChanged(int val)
{
    if(val/60>=10&&val%60>=10)
    {
        currentPos->setText(QString::number(val/60) + ":" + QString::number(val%60));
    }
    else if (val/60<10&&val%60>=10)
    {
        currentPos->setText("0" + QString::number(val/60) + ":" + QString::number(val%60));
    }
    else if (val/60>=10&&val%60<10)
    {
        currentPos->setText(QString::number(val/60) + ":" + "0" + QString::number(val%60));
    }
    else
    {
        currentPos->setText("0" + QString::number(val/60) + ":" + "0" + QString::number(val%60));
    }
    
}

void BottomBar::on_pauseButton_clicked()
{
    
}



void BottomBar::on_volumeButton_clicked()//点击按钮实现静音与恢复音量
{

    if(volumeSlider->value() == 0)
    {
        volume = 10;
        volumeSlider->setValue(10);
		volumeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/volume.png); }");
		volumeButton->setToolTip(QStringLiteral("静音"));

    }
    
    else
    {
        volume = 0;
		volumeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/mute.png); }");
		volumeButton->setToolTip(QStringLiteral("恢复音量"));
    }
    emit volumeSlider->valueChanged(volume);
}

void BottomBar::on_volumeSlider_valueChanged(int vol)//拖拽改变音量时用tooltip显示当前音量
{
	QToolTip::showText(QCursor::pos(), "音量:" + QString::number(vol), this);
	if (vol == 0)
	{
		volumeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/mute.png); }");
	}
	else
	{
		volumeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/bottomBar/volume.png); }");

	}
}

void BottomBar::on_switchModeButton_clicked()//点击切换音乐/视频模式
{
    if(volumeSlider->orientation()==Qt::Horizontal)
    {
        setFixedHeight(70);

        definitionButton->show();
        settingsButton->show();
        full_screenButton->show();
        playModeButton->hide();
        volumeSlider->setOrientation(Qt::Vertical);
        volumeSlider->setFixedSize(20,50);


        totalTime->setText("/04:00");//test
        BmBottomLayout->removeWidget(switchModeButton);
        BmBottomLayout->removeWidget(playSlider);
        BmBottomLayout->removeWidget(volumeButton);
        BottomLayout->removeItem(BmBottomLayout);
        BottomLayout->addWidget(playSlider);
        BottomLayout->addLayout(BmBottomLayout);
        BmBottomLayout->addWidget(space);
        BmBottomLayout->addWidget(volumeButton);
        BmBottomLayout->addWidget(definitionButton);
        BmBottomLayout->addWidget(settingsButton);
        BmBottomLayout->addWidget(switchModeButton);
        BmBottomLayout->addWidget(full_screenButton);

        volumeLayout->addWidget(volumeSlider);
        connect(volumeButton,SIGNAL(enterSignal(int ,int)),volumeWidget,SLOT(display(int,int)));

    }
    else if (volumeSlider->orientation()==Qt::Vertical)
    {
        setFixedHeight(50);

        playModeButton->show();
        definitionButton->hide();
        settingsButton->hide();
        full_screenButton->hide();
        volumeSlider->setOrientation(Qt::Horizontal);
        volumeSlider->setFixedSize(60,20);


        totalTime->setText("04:00");//test
        BottomLayout->removeWidget(playSlider);
        BmBottomLayout->removeWidget(switchModeButton);
        BmBottomLayout->removeWidget(volumeButton);
        BmBottomLayout->removeWidget(space);
        BmBottomLayout->removeWidget(totalTime);
        BmBottomLayout->addWidget(playSlider);
        BmBottomLayout->addWidget(totalTime);
        BmBottomLayout->addWidget(volumeButton);
        BmBottomLayout->addWidget(volumeSlider);
        BmBottomLayout->addWidget(playModeButton);
        BmBottomLayout->addWidget(switchModeButton);

        disconnect(volumeButton,SIGNAL(enterSignal(int ,int)),volumeWidget,SLOT(display(int,int)));

    }
    else
    {

    }
}

void BottomBar::volumeWidgetDetection()
{
    isatWidget(volumeWidget);
}

void BottomBar::definitionWidgetDetection()
{
    isatWidget(definitionWidget);
}

void BottomBar::settingsWidgetDetection()
{
    isatWidget(settingsWidget);
}

void BottomBar::on_full_screenButton_clicked()
{
    emit full_screenButton_clicked();
	volumeWidget->hide();
}

void BottomBar::wheelMoved(QWheelEvent *event)//滚轮改变音量
{
	if (volumeSlider->orientation() == Qt::Vertical)
	{
		emit wheelMoving(volumeButton->x(), volumeButton->y());
	}
	else
	{

	}

	int max = volumeSlider->maximum();
	int min = volumeSlider->minimum();
	int value = volumeSlider->value();
	int change;
	if ((max - min) <= 10)
	{
		change = 1;
	}
	else if ((max - min) <= 100)
	{
		change = 3;
	}
	else
	{
		change = 5;
	}
	//滚轮向上滚动增加vlaue
	if (event->delta() >= 120)
	{
		value = volumeSlider->value() + change;
		if (value > max)
			value = max;
		volumeSlider->setValue(value);

	}
	//滚轮向下滚动减少vlaue
	else if (event->delta() <= -120)
	{
		value = volumeSlider->value() - change;
		if (value < min)
			value = min;
		volumeSlider->setValue(value);
	}
	else
	{

	}
}

void BottomBar::isatWidget(QWidget *suspensionindow)
{
    if(this->window()->childAt(QPoint(QCursor::pos().x()-this->window()->x(),QCursor::pos().y()-this->window()->y()))==suspensionindow)
    {

    }
    else
    {
        suspensionindow->hide();
    }
}

void BottomBar::changeButtonSize()
{
	if (this->window()->isFullScreen())
	{
		volumeButton->setFixedSize(40, 40);
		volumeSlider->setFixedSize(30, 80);
		volumeWidget->setGeometry(0, 0, 40, 90);
		playModeButton->setFixedSize(40, 40);
		switchModeButton->setFixedSize(40, 40);
		definitionButton->setFixedSize(40, 40);
		settingsButton->setFixedSize(40, 40);
		full_screenButton->setFixedSize(40, 40);

	}
	else
	{
		volumeButton->setFixedSize(30, 30);
		volumeSlider->setFixedSize(20, 60);
		volumeWidget->setGeometry(0, 0, 30, 80);
		playModeButton->setFixedSize(30, 30);
		switchModeButton->setFixedSize(30, 30);
		definitionButton->setFixedSize(30, 30);
		settingsButton->setFixedSize(30, 30);
		full_screenButton->setFixedSize(30, 30);

	}
}


void BottomBar::changeVolume(int vol)//改变音量
{
	if (vol == volumeSlider->value())
	{

	}
	else
	{
		volumeSlider->setValue(vol);
	}

}

void BottomBar::hideVolumeWidget()
{
	volumeWidget->hide();
}

void BottomBar::volumeSliderValueAdd()
{
    volumeSlider->setValue(volumeSlider->value()+5);
}

void BottomBar::volumeSliderValueSub()
{
    volumeSlider->setValue(volumeSlider->value()-5);
}
/**
* @method        BottomBar::connectSettingAndBottom
* @brief         连接设置界面
* @author        涂晴昊
* @date          2019-08-31
*/
void BottomBar::connectSettingAndBottom(SettingWindow *settingWindow)
{
    connect(settingWindow,SIGNAL(sigActionShortcut(QString)),//换暂停播放快捷键
            this,SLOT(changeActionShortcut(QString)));
    connect(settingWindow,SIGNAL(sigLastShortcut(QString)),//换上一首快捷键
            this,SLOT(changeLastShortcut(QString)));
    connect(settingWindow,SIGNAL(sigNextShortcut(QString)),//换下一首快捷键
            this,SLOT(changeNextShortcut(QString)));
    connect(settingWindow,SIGNAL(sigLouderShortcut(QString)),//换音量增快捷键
            this,SLOT(changeLouderShortcut(QString)));
    connect(settingWindow,SIGNAL(sigLowerShortcut(QString)),//换音量减快捷键
            this,SLOT(changeLowerShortcut(QString)));
    connect(settingWindow,SIGNAL(sigVolumeOnOffShortcut(QString)),//换静音复音快捷键
            this,SLOT(changeVolumeOnOffShortcut(QString)));

    connect(settingWindow,SIGNAL(sigSpeedChange(int)),//设置界面修改主界面倍速
            this,SLOT(changeMultiplyingPower(int)));
    connect(settingWindow,SIGNAL(sigDefinitionChange(int)),//设置界面修改主界面清晰度
            this,SLOT(changeDefinition(int)));
    connect(p360DefinitionButton,SIGNAL(clicked()),//主界面->设置界面普通清晰度
            settingWindow,SLOT(lv1DefinitionChange()));
    connect(p480DefinitionButton,SIGNAL(clicked()),//主界面->设置界面清晰清晰度
            settingWindow,SLOT(lv2DefinitionChange()));
    connect(p720DefinitionButton,SIGNAL(clicked()),//主界面->设置界面高清清晰度
            settingWindow,SLOT(lv3DefinitionChange()));
    connect(autoDefinitionButton,SIGNAL(clicked()),//主界面->设置界面自动清晰度
            settingWindow,SLOT(lv1DefinitionChange()));
    connect(this->playSpeedSlider,SIGNAL(valueChanged(int)),//主界面修改设置界面倍速
            settingWindow,SLOT(speedChange(int)));
}



/**
* @method        BottomBar::changeActionShortcut
* @brief         暂停播放快捷键修改
* @param         QSTRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void BottomBar::changeActionShortcut(QString str)
{
    pauseButton->setShortcut(QKeySequence(str.toLatin1().data()));
}

/**
* @method        BottomBar::changeLastShortcut
* @brief         上一首快捷键修改
* @param         QSTRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void BottomBar::changeLastShortcut(QString str)
{
    lastButton->setShortcut(QKeySequence(str.toLatin1().data()));
}

/**
* @method        BottomBar::changeNextShortcut
* @brief         下一首快捷键修改
* @param         QSTRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void BottomBar::changeNextShortcut(QString str)
{
    nextButton->setShortcut(QKeySequence(str.toLatin1().data()));
}


/**
* @method        BottomBar::changeVolumeOnOffShortcut
* @brief         静音复音快捷键修改
* @param         QSTRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void BottomBar::changeVolumeOnOffShortcut(QString str)
{
    volumeButton->setShortcut(QKeySequence(str.toLatin1().data()));
}

/**
* @method        BottomBar::changeMultiplyingPower
* @brief         改变主界面播放倍速
* @param         INT
* @return        VOID
* @author        涂晴昊
* @date          2019-09-04
*/
void BottomBar::changeMultiplyingPower(int mul)
{
    multiplyingPower=mul;
    playSpeedSlider->setValue(mul-1);
}

/**
* @method        BottomBar::changeDefinition
* @brief         改变主界面清晰度
* @param         INT
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void BottomBar::changeDefinition(int d)
{
    if(d==1)
        p360DefinitionButton->click();
    else if(d==2)
        p480DefinitionButton->click();
    else
        p720DefinitionButton->click();

}



