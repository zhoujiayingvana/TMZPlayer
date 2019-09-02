#include "util/controller.h"
#include <QDebug>
Controller::Controller(QWidget *parent) : QWidget(parent)
{
    //设置播放状态为停止
    this->m_CtrlPlayState=QMediaPlayer::StoppedState;
    
}

Controller::~Controller()
{
    
}

void Controller::terminateVideo()
{
    emit this->needTerminateVideo();
}

void Controller::seekPosition(qint64 pos)
{   
    qint64 tempPos;
    //跳转到视频结尾
    if(pos>this->getDuration()){
        tempPos=this->getDuration();
    }
    //跳转到视频开头
    else if(pos<0){
        tempPos=0;
    }
    else{
        tempPos=pos;
    }
    emit this->needSeekPosition(tempPos);
}

void Controller::setVolume(int vol)
{
    int tempVol;
    //音量大于100
    if(vol>100){
        tempVol=100;
    }
    //音量小于0
    else if(vol<0){
        tempVol=0;
    }
    else {
        tempVol=vol;
    }
    emit this->needSetVolume(tempVol);
}


void Controller::setMuted(bool m)
{
    emit this->needSetMuted(m);
}

void Controller::jump(int second)
{
    qint64 tempPos=this->getPosition();
    qDebug()<<"tempPos "<<tempPos;
    
    //跳转到视频结尾
    if(tempPos+second*1000>this->getDuration()){
        emit this->needSeekPosition(this->getDuration());
    }
    //跳转到视频开头
    else if(tempPos+second*1000<0){
        emit this->needSeekPosition(0);
    }
    else {
        emit this->needJump(second);
    }

}

void Controller::setPlaybackRate(qreal rate)
{
    emit needSetPlaybackRate(rate);
}

void Controller::receivePosition(qint64 pos)
{
    this->m_CtrlCurrentPosition=pos;
}

void Controller::receiveDuration(qint64 dur)
{
    this->m_CtrlDuration=dur;   
}

void Controller::receiveStatus(QMediaPlayer::State stus)
{
    this->m_CtrlPlayState=stus;
}

//测试用函数
void Controller::testPlay(QMediaContent *content)
{
    emit this->needPlay(content);
}

qint64 Controller::getDuration()
{
    emit needGetDuration();
    //等待player发送信号
    return this->m_CtrlDuration;
}

qint64 Controller::getPosition()
{
    emit needGetPosition();
    return this->m_CtrlCurrentPosition;
}

QMediaPlayer::State Controller::getStatus()
{
    emit needGetStatus();
    return this->m_CtrlPlayState;
}

void Controller::restorePlay()
{
    if(this->getStatus()!=QMediaPlayer::StoppedState){
        emit this->needRestorePlay();        
    }

}

void Controller::pauseVideo()
{
    if(this->getStatus()!=QMediaPlayer::StoppedState){
        emit this->needPauseVideo();       
    }

}
