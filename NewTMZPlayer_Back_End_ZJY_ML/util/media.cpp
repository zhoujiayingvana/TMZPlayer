#include "util/media.h"

Media::Media(QWidget *parent) : QWidget(parent)
{
    //初始化私有成员
    this->media_Player=new Player();
    this->media_Controller=new Controller();
    this->media_NetworkModel=new NetworkModel();
    
    //连接信号槽
    //获取视频信息
    connect(this->media_Controller,SIGNAL(needGetDuration()),this->media_Player,SLOT(needGetDuration()));
    connect(this->media_Player,SIGNAL(returnDuration(qint64)),this->media_Controller,SLOT(receiveDuration(qint64)));
    connect(this->media_Controller,SIGNAL(needGetPosition()),this->media_Player,SLOT(needGetPosition()));
    connect(this->media_Player,SIGNAL(returnPosition(qint64)),this->media_Controller,SLOT(receivePosition(qint64)));
    connect(this->media_Controller,SIGNAL(needGetStatus()),this->media_Player,SLOT(needGetStatus()));
    connect(this->media_Player,SIGNAL(returnStatus(QMediaPlayer::State)),this->media_Controller,SLOT(receiveStatus(QMediaPlayer::State)));
    //控制视频
    //调试用
    connect(this->media_Controller,SIGNAL(needPlay(QMediaContent*)),this->media_Player,SLOT(needPlay(QMediaContent*)));
    connect(this->media_Controller,SIGNAL(needRestorePlay()),this->media_Player,SLOT(needRestorePlay()));
    connect(this->media_Controller,SIGNAL(needPauseVideo()),this->media_Player,SLOT(needPauseVideo()));
    connect(this->media_Controller,SIGNAL(needTerminateVideo()),this->media_Player,SLOT(needTerminateVideo()));
    connect(this->media_Controller,SIGNAL(needSeekPosition(qint64)),this->media_Player,SLOT(needSetPosition(qint64)));
    connect(this->media_Controller,SIGNAL(needSetVolume(int)),this->media_Player,SLOT(needSetVolume(int)));
    connect(this->media_Controller,SIGNAL(needSetMuted(bool)),this->media_Player,SLOT(needSetMuted(bool)));
    connect(this->media_Controller,SIGNAL(needSetPlaybackRate(qreal)),this->media_Player,SLOT(needSetPlaybackRate(qreal)));
    connect(this->media_Controller,SIGNAL(needJump(int)),this->media_Player,SLOT(needJump(int)));
    
    //高级功能
    connect(this->media_Controller,SIGNAL(needCutScreen(WId ,QString,QString,int)),this->media_Player,SLOT(needCutScreen(WId,QString,QString,int)));
    connect(this->media_Player,SIGNAL(returnScreenCut(QString)),this->media_Controller,SLOT(receiveScreenCut(QString)));

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
