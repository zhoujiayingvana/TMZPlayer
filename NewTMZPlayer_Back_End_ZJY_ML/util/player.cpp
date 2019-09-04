#include "util/player.h"

Player::Player(QWidget *parent) : QWidget(parent)
{
    //初始化
    this->m_Player=new QMediaPlayer(this);
    this->m_PlayState=QMediaPlayer::StoppedState;
    this->m_Duration=0;
    this->m_CurrentPosition=0;
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
}

void Player::needCutScreen(WId wId, QString fileName,QString fmt,int qua)
{
    
    QScreen *screen = QGuiApplication::primaryScreen();
    int quality=-1;
    QString format("jpg");
    //检查参数范围
    if(qua>=0&&qua<=100){
        quality=qua;
    }
    
    if(fmt.compare(QString("jpg"))){
        format=fmt;
    }
    else if(fmt.compare(QString("png"))){
        format=fmt;
    }
    else if(fmt.compare((QString("webp")))){
        format=fmt;
    }
    
    fileName=fileName+"."+fmt;
    qDebug()<<fileName;
    char*  ch;
    QByteArray ba = format.toUtf8();    
    ch=ba.data();
    screen->grabWindow(wId).save(fileName,ch,quality);
    emit this->returnScreenCut(fileName);
};
