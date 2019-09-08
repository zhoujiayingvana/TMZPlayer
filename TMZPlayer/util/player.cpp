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

qint64 Player::getDuration()
{
    return this->m_Duration;
}

QMediaPlayer *Player::getPlayer()
{
    return this->m_Player;
}

void Player::needPlay( QMediaContent *content)
{
    this->m_Player->setMedia(*content);
    this->needGetDuration();
    this->needGetPosition();
    this->needGetStatus();
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


qint64 Player::needTerminateVideo()
{
    // 记录当前播放的位置
    this->m_CurrentPosition=this->m_Player->position();
    // 如果播放完毕，则设为0
    if(this->m_CurrentPosition==this->m_Duration){
        this->m_CurrentPosition=0;
    }
    // 停止播放
    this->m_Player->stop();
    // 向media发送播放位置
    return this->m_CurrentPosition;
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

void Player::needCutScreen(WId wId, QString fileName, QString filePath, QString fmt, int qua)
{
    QScreen *screen = QGuiApplication::primaryScreen();
    int quality=-1;
    QString format("jpg");
    //检查参数范围
    if(qua>=0&&qua<=100){
        quality=qua;
    }
    //检查图片格式是否合法
    if(Debug::isScresenCutFormatLegal(fmt)){
        format=fmt;
    }
    else{
        qDebug()<<"Player needCutScreen() "<<Debug::getDebugErrorType(Debug::MyErrors::SCREEN_CUT_FORMAT_ERROR);
        return;
        }
    if(!Debug::isFileDirExits(filePath)){
        qDebug()<<"Player needCutScreen() "<<Debug::getDebugErrorType(Debug::MyErrors::FILE_PATH_ERROR);
        return;
    }
    QString fullPath=filePath+fileName+"."+fmt;
    screen->grabWindow(wId).save(fullPath,Debug::QString2Char(fmt),quality);
    emit this->returnScreenCut(fullPath);
};
