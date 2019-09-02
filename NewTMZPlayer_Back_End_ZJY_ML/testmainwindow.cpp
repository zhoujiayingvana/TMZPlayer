﻿#include "testmainwindow.h"
#include "ui_testmainwindow.h"
#include "debug.h"
#include <QUrl>
//Debug *myDebug=new Debug();
QUrl url("../vid/t3.avi");
QMediaContent *mediaContent=new QMediaContent(url);

TestMainWindow::TestMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TestMainWindow)
{
    ui->setupUi(this);
    this->media=new Media();
    

    //添加视频播放窗口
    //media->getPlayWindow()->setVideoOutput(ui->);//ui里面找不到videoWidget
    QVideoWidget *myVideoWidget=new QVideoWidget();
    myVideoWidget->setParent(this);
    myVideoWidget->resize(291,151);
    myVideoWidget->move(80,25);
    media->getPlayWindow()->setVideoOutput(myVideoWidget);
    //设置播放窗口背景色
    QPalette palette(myVideoWidget->palette());
    palette.setColor(QPalette::Background, Qt::black);
    myVideoWidget->setPalette(palette);
    media->getController()->testPlay(mediaContent);

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
    
}