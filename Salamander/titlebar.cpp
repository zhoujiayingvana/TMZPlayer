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
    //固定高度
    setFixedHeight(40);

    IconLabel = new QLabel(this); //标题栏图标
    TitleLabel = new QLabel(this); //标题栏标题
    FilesButton = new QPushButton(this); //文件按钮
    SettingsButton = new QPushButton(this); //设置按钮
    SkinButton = new QPushButton(this); //换肤按钮
    MiniButton = new QPushButton(this); //迷你模式按钮
    MinimizeButton = new QPushButton(this); //最小化按钮
    MaximizeButton = new QPushButton(this); //最大化/还原按钮
    CloseButton = new QPushButton(this);//关闭窗口按钮

    IconLabel->setObjectName("IconLabel");
    TitleLabel->setObjectName("TitleLabel");
    FilesButton->setObjectName("FilesButton");
    SettingsButton->setObjectName("SettingsButton");
    SkinButton->setObjectName("SkinButton");
    MiniButton->setObjectName("MiniButton");
    MinimizeButton->setObjectName("MinimizeButton");
    MaximizeButton->setObjectName("MaximizeButton");
    CloseButton->setObjectName("CloseButton");

    //固定按钮大小
    IconLabel->setFixedSize(50,50);
    TitleLabel->setFixedSize(50,50);
    FilesButton->setFixedSize(75,50);
    SettingsButton->setFixedSize(50,50);
    SkinButton->setFixedSize(50,50);
    MiniButton->setFixedSize(75,50);
    MinimizeButton->setFixedSize(50,50);
    MaximizeButton->setFixedSize(50,50);
    CloseButton->setFixedSize(50,50);

    //去除按钮边框
    FilesButton->setFlat(true);
    SettingsButton->setFlat(true);
    SkinButton->setFlat(true);
    MiniButton->setFlat(true);
    MinimizeButton->setFlat(true);
    MaximizeButton->setFlat(true);
    CloseButton->setFlat(true);


    //test
    FilesButton->setText(QStringLiteral("打开文件"));
    SettingsButton->setText(QStringLiteral("设置"));
    SkinButton->setText(QStringLiteral("换肤"));
    MiniButton->setText(QStringLiteral("迷你模式"));
    MinimizeButton->setText(QStringLiteral("最小化"));
    MaximizeButton->setText(QStringLiteral("最大化"));
    CloseButton->setText(QStringLiteral("关闭"));

    //鼠标悬停在按钮上显示提示条
    FilesButton->setToolTip(QStringLiteral("打开文件"));
    SettingsButton->setToolTip(QStringLiteral("设置"));
    SkinButton->setToolTip(QStringLiteral("换肤"));
    MiniButton->setToolTip(QStringLiteral("迷你模式"));
    MinimizeButton->setToolTip(QStringLiteral("最小化"));
    MaximizeButton->setToolTip(QStringLiteral("最大化"));
    CloseButton->setToolTip(QStringLiteral("关闭"));

    //改变光标样式
    FilesButton->setCursor(Qt::PointingHandCursor);
    SettingsButton->setCursor(Qt::PointingHandCursor);
    SkinButton->setCursor(Qt::PointingHandCursor);
    MiniButton->setCursor(Qt::PointingHandCursor);
    MinimizeButton->setCursor(Qt::PointingHandCursor);
    MaximizeButton->setCursor(Qt::PointingHandCursor);
    CloseButton->setCursor(Qt::PointingHandCursor);


    QLabel * space =new QLabel (this);


    QHBoxLayout *TitleBarLayout = new QHBoxLayout(this);
    TitleBarLayout->addWidget(IconLabel);
    TitleBarLayout->addWidget(TitleLabel);
    TitleBarLayout->addWidget(space);
    TitleBarLayout->addWidget(FilesButton);
    TitleBarLayout->addWidget(SettingsButton);
    TitleBarLayout->addWidget(SkinButton);
    TitleBarLayout->addWidget(MiniButton);
    TitleBarLayout->addWidget(MinimizeButton);
    TitleBarLayout->addWidget(MaximizeButton);
    TitleBarLayout->addWidget(CloseButton);
    TitleBarLayout->setSpacing(0);
    TitleBarLayout->setContentsMargins(5,0,5,0);
    setLayout(TitleBarLayout);

    //连接信号
    connect(MinimizeButton,SIGNAL(clicked(bool)),this,SLOT(on_MinimizeButton_clicked()));
    connect(MaximizeButton,SIGNAL(clicked(bool)),this,SLOT(on_MaximizeButton_clicked()));
    connect(CloseButton,SIGNAL(clicked(bool)),this,SLOT(on_CloseButton_clicked()));









}

void TitleBar::on_MinimizeButton_clicked()//最小化
{
    QWidget *pWindow = this->window();
    pWindow->showMinimized();
}

void TitleBar::on_MaximizeButton_clicked()//最大化/恢复按钮切换
{
    QWidget *pWindow = this->window();
    if(this->window()->isMaximized())
    {
        pWindow->showNormal();
        MaximizeButton->setText(QStringLiteral("最大化"));
        MaximizeButton->setToolTip(QStringLiteral("最大化"));
    }
    else
    {
        pWindow->showMaximized();
        MaximizeButton->setText(QStringLiteral("恢复"));
         MaximizeButton->setToolTip(QStringLiteral("恢复"));
    }

}

void TitleBar::on_CloseButton_clicked()//关闭
{
    QWidget *pWindow = this->window();
    pWindow->close();
}

void TitleBar::mouseDoubleClickEvent(QMouseEvent *event)//双击标题栏进行界面的最大化/还原
{
    Q_UNUSED(event);

    emit MaximizeButton->clicked();
}

void TitleBar::mousePressEvent(QMouseEvent *event)//拖拽界面
{
    Q_UNUSED(event);
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


