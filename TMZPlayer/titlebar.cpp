#include "titlebar.h"

#include <QLabel>
#include <QPushButton>
#include<QDebug>
#include <QHBoxLayout>
#include<QMouseEvent>

#ifdef Q_OS_WIN
#pragma comment(lib, "user32.lib")
#include <qt_windows.h>
#endif

/*
 *Author:LY
 *Function:实现标题栏
 */


TitleBar::TitleBar(QWidget *parent) : QWidget(parent)
{

    this->setAttribute(Qt::WA_StyledBackground);
    //固定高度
    setFixedHeight(40);

    p=parent;
    settingWindow = new SettingWindow(this);


    iconLabel = new QLabel(this); //标题栏图标
    titleLabel = new QLabel(this); //标题栏标题
    SettingsButton = new QPushButton(this); //设置按钮
    SkinButton = new MySkinMenuButton(this); //换肤按钮
    miniButton = new QPushButton(this); //迷你模式按钮
    minimizeButton = new QPushButton(this); //最小化按钮
    maximizeButton = new QPushButton(this); //最大化/还原按钮
    closeButton = new QPushButton(this);//关闭窗口按钮

    SettingsButton->setFocusPolicy(Qt::NoFocus);
    SkinButton->setFocusPolicy(Qt::NoFocus);
    miniButton->setFocusPolicy(Qt::NoFocus);
    minimizeButton->setFocusPolicy(Qt::NoFocus);
    maximizeButton->setFocusPolicy(Qt::NoFocus);
    closeButton->setFocusPolicy(Qt::NoFocus);


    iconLabel->setObjectName("iconLabel");
    titleLabel->setObjectName("titleLabel");
    SettingsButton->setObjectName("settingsButton");
    SkinButton->setObjectName("SkinButton");
    miniButton->setObjectName("miniButton");
    minimizeButton->setObjectName("minimizeButton");
    maximizeButton->setObjectName("maximizeButton");
    closeButton->setObjectName("closeButton");

    //固定按钮大小
	iconLabel->setFixedSize(30, 30);
	titleLabel->setFixedSize(30, 30);
	SettingsButton->setFixedSize(30, 30);
	SkinButton->setFixedSize(30, 30);
	miniButton->setFixedSize(30, 30);
	minimizeButton->setFixedSize(30, 30);
	maximizeButton->setFixedSize(30, 30);
	closeButton->setFixedSize(30, 30);

    //去除按钮边框
    SettingsButton->setFlat(true);
    SkinButton->setFlat(true);
    miniButton->setFlat(true);
    minimizeButton->setFlat(true);
    maximizeButton->setFlat(true);
    closeButton->setFlat(true);


    //test
    SettingsButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/settings.png); }");
    SkinButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/skin.png); }");
    miniButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/mini.png); }");
    minimizeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/minimize.png); }");
    maximizeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/maximize.png); }");
    closeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/close.png); }");


    //鼠标悬停在按钮上显示提示条
    SettingsButton->setToolTip(QStringLiteral("设置"));
    SkinButton->setToolTip(QStringLiteral("换肤"));
    miniButton->setToolTip(QStringLiteral("迷你模式"));
    minimizeButton->setToolTip(QStringLiteral("最小化"));
    maximizeButton->setToolTip(QStringLiteral("最大化"));
    closeButton->setToolTip(QStringLiteral("关闭"));

    //改变光标样式
    SettingsButton->setCursor(Qt::PointingHandCursor);
    SkinButton->setCursor(Qt::PointingHandCursor);
    miniButton->setCursor(Qt::PointingHandCursor);
    minimizeButton->setCursor(Qt::PointingHandCursor);
    maximizeButton->setCursor(Qt::PointingHandCursor);
    closeButton->setCursor(Qt::PointingHandCursor);


    QLabel * space =new QLabel (this);


    QHBoxLayout *TitleBarLayout = new QHBoxLayout(this);
    TitleBarLayout->addWidget(iconLabel);
    TitleBarLayout->addWidget(titleLabel);
    TitleBarLayout->addWidget(space);
    TitleBarLayout->addWidget(SkinButton);
    TitleBarLayout->addWidget(SettingsButton);
    TitleBarLayout->addWidget(miniButton);
    TitleBarLayout->addWidget(minimizeButton);
    TitleBarLayout->addWidget(maximizeButton);
    TitleBarLayout->addWidget(closeButton);
    TitleBarLayout->setSpacing(0);
    TitleBarLayout->setContentsMargins(5,0,5,0);
    setLayout(TitleBarLayout);

    closeStatus=1;//关闭界面

    connectSettingAndTitle();

    //打开设置界面
    connect(SettingsButton,SIGNAL(clicked()),this,SLOT(on_SettingsButton_clicked()));
    connect(SkinButton->black,SIGNAL(triggered()),settingWindow,SLOT(on_back1_clicked()));
    connect(SkinButton->blue,SIGNAL(triggered()),settingWindow,SLOT(on_back2_clicked()));
    connect(SkinButton->pink,SIGNAL(triggered()),settingWindow,SLOT(on_back3_clicked()));
    connect(SkinButton->own,SIGNAL(triggered()),settingWindow,SLOT(on_myBack_clicked()));


    //连接信号
    connect(minimizeButton,SIGNAL(clicked(bool)),this,SLOT(on_minimizeButton_clicked()));
    connect(maximizeButton,SIGNAL(clicked(bool)),this,SLOT(on_maximizeButton_clicked()));
    connect(closeButton,SIGNAL(clicked(bool)),this,SLOT(on_closeButton_clicked()));
    connect(miniButton,SIGNAL(clicked(bool)),this,SLOT(on_miniButton_clicked()));
    qDebug()<<p;
}

void TitleBar::on_minimizeButton_clicked()//最小化
{
    QWidget *pWindow = this->window();
    pWindow->showMinimized();
}

void TitleBar::on_maximizeButton_clicked()//最大化/恢复按钮切换
{

    if(this->window()->isMaximized() || this->window()->isFullScreen())
    {
        this->window()->showNormal();
		maximizeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/maximize.png); }");
		maximizeButton->setToolTip(QStringLiteral("最大化"));
    }
    else
    {
        this->window()->showMaximized();
		maximizeButton->setStyleSheet("QPushButton{ border-image: url(:/image/image/titleBar/recover.png); }");
		maximizeButton->setToolTip(QStringLiteral("恢复"));
    }

}

void TitleBar::on_closeButton_clicked()//关闭
{
    if(closeStatus==1)
    {
        QWidget *pWindow = this->window();
        pWindow->close();
    }
    else
    {
        emit systemTrayMode();
    }
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)//双击标题栏进行界面的最大化/还原
{
    Q_UNUSED(event);

    emit maximizeButton->clicked();

}
void TitleBar::mousePressEvent(QMouseEvent *event)//拖拽界面
{
    Q_UNUSED(event);

    if(this->window()->isMaximized())
    {

    }
    else
    {
#ifdef Q_OS_WIN
        if (ReleaseCapture())
        {
            QWidget *pWindow = this->window();
            if (pWindow->isTopLevel())
            {
                SendMessage(HWND(pWindow->winId()), WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
            }
        }

#else
#endif
    }
}

void TitleBar::on_miniButton_clicked()
{
    emit miniMode();
}

/**
* @method        TitleBar::on_SettingsButton_clicked
* @brief         打开设置界面
* @author        涂晴昊
* @date          2019-08-26
*/
void TitleBar::on_SettingsButton_clicked()
{

    settingWindow->exec();

}

/**
* @method        TitleBar::connectSettingAndTMZ
* @brief         建立所有设置与主界面的connect
* @author        涂晴昊
* @date          2019-08-30
*/
void TitleBar::connectSettingAndTitle()
{
    connect(settingWindow,SIGNAL(sigChangeBackGround(QString)),
            p,SLOT(changeBackGround(QString)));//换纯色背景
    connect(settingWindow,SIGNAL(sigPictureBackGround(QString)),
            p,SLOT(changePicBackGround(QString)));//换图片背景
    connect(settingWindow,SIGNAL(sigCloseChange(int)),
            this,SLOT(changeCloseStatus(int)));//关闭/最小化托盘
    connect(settingWindow,SIGNAL(sigLikeShortcut(QString)),
            this,SLOT(changeLikeShortcut(QString)));//换收藏快捷键
}

/**
* @method        TitleBar::changeFontType
* @brief         修改歌词字体类型
* @param         QFont
* @return        VOID
* @author        涂晴昊
* @date          2019-09-03
*/
void TitleBar::changeFontType(QFont *font)
{

}


/**
* @method        TitleBar::changeLikeShortcut
* @brief         收藏快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void TitleBar::changeLikeShortcut(QString str)
{

}

/**
* @method        TitleBar::changeCloseStatus
* @brief         选择最小化/关闭界面
* @param         INT
* @return        VOID
* @author        涂晴昊
* @date          2019-09-04
*/
void TitleBar::changeCloseStatus(int s)
{
    if(s==1)//关闭
        closeStatus=1;
    else closeStatus=2;
}

