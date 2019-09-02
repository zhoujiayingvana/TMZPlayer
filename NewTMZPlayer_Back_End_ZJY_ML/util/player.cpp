#include "util/player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
    this->m_Player=new QMediaPlayer(this);
    //设置player依附的播放窗口
}

Player::~Player(){}

QMediaPlayer *Player::getPlayWindow()
{
    return this->m_Player;
}

void Player::needPlay( QMediaContent *content)
{
    this->m_Player->setMedia(*content);
    this->m_Player->play();
}

void Player::needGetDuration()
{
    this->m_Duration=this->m_Player->duration();
    qDebug()<<this->m_Duration;
    emit returnDuration(this->m_Duration);
}

void Player::needGetPosition()
{
    this->m_CurrentPosition=this->m_Player->position();
    emit returnPosition(this->m_CurrentPosition);
}

void Player::needGetStatus()
{
    this->m_PlayState=this->m_Player->state();
    emit returnStatus(this->m_PlayState);
}

void Player::needRestorePlay()
{
    this->m_Player->play();
}

void Player::needPauseVideo()
{
    this->m_Player->pause();
}

void Player::needTerminateVideo()
{
    this->m_Player->stop();
}


void Player::needJump(int second)
{
    qint64 currentPosition=this->m_Player->position();
    this->m_Player->setPosition(currentPosition+second*1000);
}

void Player::needSetPosition(qint64 pos)
{
    //判断是否超过视频开头或结尾
    this->m_Player->setPosition(pos);
}

void Player::needSetMuted(bool m)
{
    this->m_Player->setMuted(m);
}

void Player::needSetVolume(int vol)
{
    this->m_Player->setVolume(vol);
}

void Player::needSetPlaybackRate(qreal rate)
{
    this->m_Player->setPlaybackRate(rate);
};
