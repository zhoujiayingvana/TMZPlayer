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

void Player::needSeekPosition(qint64 pos)
{
    this->m_Player->setPosition(pos);
}

void Player::needJump(int second)
{
    qint64 currentPosition=this->m_Player->position();
    this->m_Player->setPosition(currentPosition+second*1000);
};
