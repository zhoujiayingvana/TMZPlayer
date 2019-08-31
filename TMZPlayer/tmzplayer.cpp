#include "tmzplayer.h"
#include "ui_tmzplayer.h"
#include"titlebar.h"
#include"bottombar.h"

#include<QDebug>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include<QVBoxLayout>

#include <QDebug>

#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <windowsx.h>
#endif

TMZPlayer::TMZPlayer(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TMZPlayer)
{
    ui->setupUi(this);
    resize(1032,718);
    this->setWindowFlags(Qt::FramelessWindowHint);

    QWidget *widget = new QWidget();
    this->setCentralWidget(widget); 
//    widget->setAutoFillBackground(true);//test
//    widget->setPalette(QPalette(Qt::black));//test


    TitleBar * pTitleBar = new TitleBar(this);
//    pTitleBar->setAutoFillBackground(true);//test
//    pTitleBar->setPalette(QPalette(Qt::black));//test
    BottomBar * pBottomBar = new BottomBar(this);
//    pBottomBar->setAutoFillBackground(true);//test
//    pBottomBar->setPalette(QPalette(Qt::black));//test
    QWidget * space = new QWidget(this);//test
//    space->setAutoFillBackground(true);//test
//    space->setPalette(QPalette(Qt::gray));//test




    QVBoxLayout *pLayout = new QVBoxLayout();

    pLayout->addWidget(pTitleBar);
    pLayout->addWidget(space);//test
    pLayout->addWidget(pBottomBar);

    pLayout->setSpacing(0);
    pLayout->setContentsMargins(5, 5, 5, 5);




    widget->setLayout(pLayout);

    //连接设置与BottomBar
    pBottomBar->connectSettingAndBottom(pTitleBar->settingWindow);

    //黑色风格
    QFile qssfile(":/new/prefix1/myQss/style1.qss");
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);
   qDebug()<<this;









}

TMZPlayer::~TMZPlayer()
{
    delete ui;
}

bool TMZPlayer::nativeEvent(const QByteArray &eventType, void *message, long *result)//实现窗口移动拖拽
{
    Q_UNUSED(eventType);

    const int HIT_BORDER = 5;
    const MSG *msg=static_cast<MSG*>(message);
    if(msg->message == WM_NCHITTEST)
    {
        int xPos = GET_X_LPARAM(msg->lParam) - this->geometry().x();
        int yPos = GET_Y_LPARAM(msg->lParam) - this->geometry().y();

        if(this->centralWidget()->childAt(xPos,yPos) != nullptr)//鼠标在子对象上则不处理
        {
            return QWidget::nativeEvent(eventType, message, result);
        }

        *result = HTCAPTION;

        //鼠标在边框上则缩放
        if(xPos > 0 && xPos < HIT_BORDER) {
            *result = HTLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0)) {
            *result = HTRIGHT;
        }
        if(yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOP;
        }
        if(yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOM;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > 0 && yPos < HIT_BORDER) {
            *result = HTTOPRIGHT;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < (this->width() - 0) && yPos > (this->height() - HIT_BORDER) && yPos < (this->height() - 0)) {
            *result = HTBOTTOMRIGHT;
        }
        return true;
    }
    return QWidget::nativeEvent(eventType, message, result);

}


/**
* @method        TMZPlayer::changeBackGround
* @brief         修改主界面背景 设置界面三个button分别emit传QString
* @author        涂晴昊
* @date          2019-08-26
*/
void TMZPlayer::changeBackGround(QString back)
{
    QFile qssfile(back);
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);

}

/**
* @method        TMZPlayer::changePicBackGround
* @brief         修改自定义图片背景
* @author        涂晴昊
* @date          2019-08-29
*/
void TMZPlayer::changePicBackGround(QString back)
{

//    QPixmap pix=QPixmap(back);
//    qDebug()<<back;
//    QPalette pal;
//    pal.setBrush(QPalette::Window,QBrush(pix.scaled(this->size())));
//    setPalette(pal);

   /* QImage* img=new QImage;
    img->load(back);
    QPixmap pix=QPixmap(QPixmap::fromImage(*img));
    QPalette pal;
    pal.setBrush(QPalette::Window,QBrush(pix.scaled(this->size())));
    setPalette(pal);*/
    //qDebug()<<back;
    this->setStyleSheet("QWidget#centralWidget{background-image:url("+back+")}");
}









