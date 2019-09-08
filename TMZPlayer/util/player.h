/**
  播放视频模块
  接收controller的信号
  视频格式设置
  播放及控制
  安全性检查
  **/
#ifndef PLAYER_H
#define PLAYER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QScreen>
#include <QGuiApplication>
#include <QDebug>
#include "debug.h"
class Player : public QWidget
{
    Q_OBJECT
public:
    explicit Player(QWidget *parent = nullptr);
    ~Player();
    QMediaPlayer* getPlayWindow();//获取播放窗口
    qint64 getDuration();
    QMediaPlayer* getPlayer();
    
signals:
    //返回视频信息
    //返回时长
    void returnDuration(qint64 dur);
    //返回当前进度时间
    void returnPosition(qint64 pos);
    //返回视频状态
    void returnStatus(QMediaPlayer::State stu);
    //返回截图
    void returnScreenCut(QString);
    //向历史记录返回当前时间
    void returnPositionToHis(qint64 pos);
public slots:
    //播放文件
    void needPlay(QMediaContent *content);
    
    //获取视频信息
    //获取时长
    void needGetDuration();
    //获取当前进度时间
    void needGetPosition();
    //获取视频状态
    void needGetStatus();
    
    //设置视频
    //播放/恢复播放
    void needRestorePlay();
    //暂停播放
    void needPauseVideo();
    // 停止播放 ml 修改为拒绝连接!! 防止异步出错
    qint64 needTerminateVideo();
    //快进、快退
    void needJump(int second);
    //跳转到指定位置
    void needSetPosition(qint64);
    //设置静音
    void needSetMuted(bool m);
    //设置音量
    void needSetVolume(int vol);
    //设置播放速率
    void needSetPlaybackRate(qreal rate);
    
    //高级功能
    //截图
    void needCutScreen(WId wId,QString fileName,QString filePath,QString fmt,int qua);
private:
    QMediaPlayer *m_Player;//播放窗口主体
    QMediaPlayer::State m_PlayState;//播放状态，默认为StoppedState
    qint64 m_CurrentPosition;//当前播放的时间进度
    qint64 m_Duration;//视频总时长

};

#endif // PLAYER_H
