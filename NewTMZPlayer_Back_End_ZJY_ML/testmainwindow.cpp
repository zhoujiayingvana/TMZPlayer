#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include "debug.h"
#include <QUrl>
//Debug *myDebug=new Debug();
TestMainWindow::TestMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestMainWindow)
{
    ui->setupUi(this);
    this->media=new Media();
    myVideoWidget=new QVideoWidget();
    myVideoWidget->setParent(this);
    myVideoWidget->resize(291,151);
    myVideoWidget->move(80,25);
    media->getPlayWindow()->setVideoOutput(myVideoWidget);
    //设置播放窗口背景色
    QPalette palette(myVideoWidget->palette());
    palette.setColor(QPalette::Background, Qt::black);
    myVideoWidget->setPalette(palette);
    QString str("CTRL+A");
    ui->pauseButton->setShortcut(QKeySequence(str.toLatin1().data()));
    
    
    //测试收藏夹功能
    //添加收藏夹
    this->media->testRun();
    //播放视频
    this->media->play(0,0);
    
    
    
//    //测试历史记录功能
//    this->media->play("../vid/t3.avi");
    
//    //测试播放速度功能

}

TestMainWindow::~TestMainWindow()
{
    delete ui;
}

void TestMainWindow::on_playButton_clicked()
{
    media->getController()->restorePlay();
}

void TestMainWindow::on_pauseButton_clicked()
{
    media->getController()->pauseVideo();
}

void TestMainWindow::on_terminateButton_clicked()
{
    media->getController()->terminateVideo();
}

void TestMainWindow::on_nextButton_clicked()
{
    media->playNext();
}



void TestMainWindow::on_forwardButton_clicked()
{
    media->getController()->jump(2);
}

void TestMainWindow::on_volumeUpButton_clicked()
{
    media->getController()->setVolume(80);
}

void TestMainWindow::on_volumeDownButton_clicked()
{
    media->getController()->setVolume(40);
}

void TestMainWindow::on_jumpButton_clicked()
{
    media->getController()->seekPosition(media->getController()->getDuration()/2);    
    
}

void TestMainWindow::on_muteButton_clicked()
{
    media->getController()->setMuted(true);
}

void TestMainWindow::on_nonMuteButton_clicked()
{
    media->getController()->setMuted(false);
}

void TestMainWindow::on_screenCutButton_clicked()
{
    QDateTime local(QDateTime::currentDateTime());
    QString localTime = local.toString("yyMMddhhmmss");
    QString fileName="ScreenCutByTMZPlayer"+localTime;
    QString filePath="../output/";
    media->getController()->cutScreen(this->myVideoWidget->winId(),fileName,filePath,"jpg",-1);
}
