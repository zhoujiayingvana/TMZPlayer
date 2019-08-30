#include "bottombar.h"
#include<QDebug>
#include<QToolTip>

/*
 *Author:LY
 *Function:实现底部栏
 */

BottomBar::BottomBar(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(50);
    lastButton = new QPushButton(this);//上一个按钮
    pauseButton = new QPushButton(this);//暂停/播放按钮
    nextButton = new QPushButton(this);//下一个按钮
    currentPos = new QLabel(this);//播放到的时间
    playSlider = new MySlider(this);//播放条
    totalTime = new QLabel(this);//总时长
    volumeButton = new BottomButton(this);//静音/恢复音量按钮
    volumeSlider = new MySlider(this);//音量条
    volumeSlider->setValue(10);
    playmodeButton = new QPushButton(this);//播放模式按钮
    switchmodeButton = new QPushButton(this);//切换音乐/视频模式按钮
    space = new QLabel ();//底部空白
    definitionButton = new QPushButton();//清晰度按钮
    settingsButton = new QPushButton();//视频设置按钮
    full_screenButton = new QPushButton();//全屏/恢复按钮







    playSlider->setOrientation(Qt::Horizontal);
    volumeSlider->setOrientation(Qt::Horizontal);
    /*
     * playSlider还需设最大值
     */
    volumeSlider->setMaximum(100);


    lastButton->setObjectName("lastButton");
    pauseButton->setObjectName("pauseButton");
    nextButton->setObjectName("nextButton");
    currentPos->setObjectName("currentPos");
    playSlider->setObjectName("playScrollBar");
    totalTime->setObjectName("totalTime");
    volumeButton->setObjectName("volumeButton");
    volumeSlider->setObjectName("volumeScrollBar");
    playmodeButton->setObjectName("playmodeButton");
    switchmodeButton->setObjectName("full_screenButton");
    definitionButton->setObjectName("definitionButton");
    settingsButton->setObjectName("settingsButton");
    full_screenButton->setObjectName("full_screenButton");


    //固定按钮大小
    lastButton->setFixedSize(60,30);
    pauseButton->setFixedSize(30,30);
    nextButton->setFixedSize(60,30);
    currentPos->setFixedSize(30,30);
    playSlider->setFixedHeight(20);
    totalTime->setFixedSize(30,30);
    volumeButton->setFixedSize(30,30);
    volumeSlider->setFixedSize(60,20);
    playmodeButton->setFixedSize(30,30);
    switchmodeButton->setFixedSize(30,30);
    definitionButton->setFixedSize(30,30);
    settingsButton->setFixedSize(30,30);
    full_screenButton->setFixedSize(30,30);


    lastButton->setFlat(true);
    pauseButton->setFlat(true);
    nextButton->setFlat(true);
    volumeButton->setFlat(true);
    playmodeButton->setFlat(true);
    switchmodeButton->setFlat(true);
    definitionButton->setFlat(true);
    settingsButton->setFlat(true);
    full_screenButton->setFlat(true);



    //TEST
    lastButton->setText(QStringLiteral("上一个"));
    pauseButton->setText(QStringLiteral("播放"));
    nextButton->setText(QStringLiteral("下一个"));
    currentPos->setText(QStringLiteral("0.00"));
    totalTime->setText(QStringLiteral("4.00"));
    volumeButton->setText(QStringLiteral("静音"));
    playmodeButton->setText(QStringLiteral("播放模式"));
    switchmodeButton->setText(QStringLiteral("切换"));
    definitionButton->setText(QStringLiteral("清晰度"));
    settingsButton->setText(QStringLiteral("设置"));
    full_screenButton->setText(QStringLiteral("全屏"));
    //TEST
    volume=10;


    //鼠标悬停在按钮上显示提示条
    lastButton->setToolTip(QStringLiteral("上一个"));
    pauseButton->setToolTip(QStringLiteral("播放"));
    nextButton->setToolTip(QStringLiteral("下一个"));
    volumeButton->setToolTip(QStringLiteral("静音"));
    volumeSlider->setToolTip(QStringLiteral("音量调节(Up/Down)"));
    playmodeButton->setToolTip(QStringLiteral("播放模式"));
    switchmodeButton->setToolTip(QStringLiteral("全屏"));
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
    playmodeButton->setCursor(Qt::PointingHandCursor);
    switchmodeButton->setCursor(Qt::PointingHandCursor);
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
    BmBottomLayout->addWidget(playmodeButton);
    BmBottomLayout->addWidget(switchmodeButton);
    BmBottomLayout->setContentsMargins(0, 5, 0, 5);
    BmBottomLayout->setSpacing(0);
    BottomLayout->addLayout(BmBottomLayout);


    volumeWidget = new Widget(parent);//视频模式音量窗口
    volumeWidget->setObjectName(QString::fromUtf8("volumeWidget"));
    volumeWidget->setAutoFillBackground(true);//test
    volumeWidget->setPalette(QPalette(Qt::yellow));//test
    volumeWidget->setGeometry(220, 200, 20, 60);//test

    volumeWidget->setWindowFlags(Qt::WindowStaysOnBottomHint);
    volumeWidget->hide();
    volumeLayout =new QVBoxLayout(volumeWidget);    
    volumeLayout->setContentsMargins(0, 0, 0, 0);


    definitionWidget = new Widget(parent);//视频模式清晰度窗口
    definitionLayout =new QVBoxLayout(definitionWidget);//视频模式清晰度窗口的布局
    settingsWidget = new Widget(parent);//视频模式设置窗口
    settingsLayout =new QVBoxLayout(settingsWidget);//视频模式设置窗口的布局






    connect(volumeButton,SIGNAL(clicked(bool)),this,SLOT(on_volumeButton_clicked()));
    connect(volumeSlider,SIGNAL(valueChanged(int)),this,SLOT(on_volumeSlider_valueChanged(int)));
    connect(switchmodeButton,SIGNAL(clicked(bool)),this,SLOT(on_switchmodeButton_clicked()));
    connect(volumeButton,SIGNAL(leaveSignal()),volumeWidget,SLOT(hide()));





}

void BottomBar::on_volumeButton_clicked()//点击按钮实现静音与恢复音量
{
    if(volume == 0 && volumeSlider->value() == 0)
    {
        volume = 10;
        volumeSlider->setValue(10);
        volumeButton->setText(QStringLiteral("静音"));
        volumeButton->setToolTip(QStringLiteral("静音"));

    }
    else if(volume == 0)
    {
        volume = volumeSlider->value();
        volumeButton->setText(QStringLiteral("静音"));
        volumeButton->setToolTip(QStringLiteral("静音"));
    }
    else
    {
        volume = 0;
        volumeButton->setText(QStringLiteral("恢复音量"));
        volumeButton->setToolTip(QStringLiteral("恢复音量"));
    }
    emit volumeSlider->valueChanged(volume);
}

void BottomBar::on_volumeSlider_valueChanged(int vol)//拖拽改变音量时用tooltip显示当前音量
{
    QToolTip::showText(QCursor::pos(),QString::number(vol),this);
}

void BottomBar::on_switchmodeButton_clicked()//点击切换音乐/视频模式
{
    if(volumeSlider->orientation()==Qt::Horizontal)
    {
        setFixedHeight(70);

        definitionButton->show();
        settingsButton->show();
        full_screenButton->show();
        playmodeButton->hide();
        volumeSlider->hide();
        volumeSlider->setOrientation(Qt::Vertical);

        BmBottomLayout->removeWidget(switchmodeButton);
        BmBottomLayout->removeWidget(playSlider);
        BmBottomLayout->removeWidget(volumeButton);
        BottomLayout->removeItem(BmBottomLayout);
        BottomLayout->addWidget(playSlider);
        BottomLayout->addLayout(BmBottomLayout);        
        BmBottomLayout->addWidget(space);
        BmBottomLayout->addWidget(volumeButton);
        BmBottomLayout->addWidget(definitionButton);
        BmBottomLayout->addWidget(settingsButton);
        BmBottomLayout->addWidget(switchmodeButton);
        BmBottomLayout->addWidget(full_screenButton);
        disconnect(volumeButton,SIGNAL(enterSignal(int ,int)),volumeWidget,SLOT(display(int,int)));

    }
    else if (volumeSlider->orientation()==Qt::Vertical)
    {
        setFixedHeight(50);

        playmodeButton->show();
        volumeSlider->show();
        definitionButton->hide();
        settingsButton->hide();
        full_screenButton->hide();
        volumeSlider->setOrientation(Qt::Horizontal);

        BottomLayout->removeWidget(playSlider);
        BmBottomLayout->removeWidget(switchmodeButton);
        BmBottomLayout->removeWidget(volumeButton);
        BmBottomLayout->removeWidget(space);
        BmBottomLayout->removeWidget(totalTime);
        BmBottomLayout->addWidget(playSlider);
        BmBottomLayout->addWidget(totalTime);
        BmBottomLayout->addWidget(volumeButton);
        BmBottomLayout->addWidget(volumeSlider);
        BmBottomLayout->addWidget(playmodeButton);
        BmBottomLayout->addWidget(switchmodeButton);

        volumeWidget->setWindowFlags(Qt::WindowStaysOnBottomHint);
        connect(volumeButton,SIGNAL(enterSignal(int ,int)),volumeWidget,SLOT(display(int,int)));

    }
    else
    {
        
    }
}




