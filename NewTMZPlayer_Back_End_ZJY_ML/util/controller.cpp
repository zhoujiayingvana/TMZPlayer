#include "util/controller.h"
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

//测试用函数
void Controller::testPlay(QMediaContent *content)
{
    emit this->needPlay(content);
}

void Controller::restorePlay()
{
    emit this->needRestorePlay();
}

void Controller::pauseVideo()
{
    emit this->needPauseVideo();
}
