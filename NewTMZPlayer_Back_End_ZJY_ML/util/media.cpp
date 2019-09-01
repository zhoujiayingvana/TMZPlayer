﻿#include "util/media.h"

Media::Media(QWidget *parent) : QWidget(parent)
{
    //初始化私有成员
    this->media_Player=new Player();
    this->media_Controller=new Controller();
    
    //连接信号槽
    //调试用
    connect(this->media_Controller,SIGNAL(needPlay(QMediaContent*)),this->media_Player,SLOT(needPlay(QMediaContent*)));
    connect(this->media_Controller,SIGNAL(needRestorePlay()),this->media_Player,SLOT(needRestorePlay()));
    connect(this->media_Controller,SIGNAL(needPauseVideo()),this->media_Player,SLOT(needPauseVideo()));
    connect(this->media_Controller,SIGNAL(needTerminateVideo()),this->media_Player,SLOT(needTerminateVideo()));
}

/////////////
Media::~Media(){}


QMediaPlayer *Media::getPlayWindow()
{
    return this->media_Player->getPlayWindow();
}

Controller *Media::getController()
{
    return this->media_Controller;
};
