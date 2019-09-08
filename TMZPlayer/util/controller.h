#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QUrl>
#include "util/helper.h"
#include "debug.h"


class Controller : public QWidget
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller();
        
    //调试用
    void testPlay(QMediaContent * content);
    
    //获取视频信息
    //获取时长
    qint64 getDuration();
    //获取当前进度时间
    qint64 getPosition();
    //获取当前视频状态
    QMediaPlayer::State getStatus();
    
    //设置视频
    //播放/恢复播放
    void restorePlay();
    //暂停播放
    void pauseVideo();
    //停止播放
    void terminateVideo();
    //跳转到指定位置，
    void seekPosition(qint64);
    //设置视频音量
    void setVolume(int vol);
    //设置静音,true为静音，false为取消静音
    void setMuted(bool m);
    //快进、快退,跳转指定秒
    void jump(int second);
    //player播放速率自带槽函数
    void setPlaybackRate(qreal rate);
    
    
    //高级功能
    //截图
    QString cutScreen(WId wId,QString fileName="ScreenCutByTMZPlayer",QString filePath="../output",QString fmt="jpg",int qua=-1);
    //调整播放顺序
    void setOrder(PlayOrder);
    //获取播放顺序
    PlayOrder getOrder();
signals:
    //获取视频信息
    //获取时长
    void needGetDuration();
    //获取当前进度时间
    void needGetPosition();
    //获取视频状态
    void needGetStatus();
    //获取当前播放顺序
    void needGetOrder();
    
    //设置视频
    //打开并播放视频
    void needPlay(QMediaContent *content);
    //播放/恢复播放
    void needRestorePlay();
    //暂停播放
    void needPauseVideo();
    //停止播放
    void needTerminateVideo();
    //跳转到指定位置，player自带槽函数
    void needSeekPosition(qint64);
    //设置视频音量,player自带槽函数
    void needSetVolume(int vol);
    //设置静音,true为静音，false为取消静音,player自带槽函数
    void needSetMuted(bool m);
    //倍速播放，player自带槽函数
    void needSetPlaybackRate(qreal rate);
    //快进、快退,跳转指定秒
    void needJump(int second);
    
    //高级功能
    //截图
    void needCutScreen(WId wId,QString fileName,QString filePath,QString fmt,int qua);
    //设置播放顺序
    void needSetOrder(PlayOrder);
public slots:
    
    //获取Player传递的Position
    void receivePosition(qint64);
    //获取Player传递的Duration
    void receiveDuration(qint64);
    //获取Player传递的State
    void receiveStatus(QMediaPlayer::State);
    //获取截图路径
    void receiveScreenCut(QString);
    //获取播放顺序
    void receiveOrder(PlayOrder);
    
private:
    QMediaPlayer::State m_CtrlPlayState;//播放状态，默认为StoppedState
    qint64 m_CtrlCurrentPosition;//当前播放的时间进度
    qint64 m_CtrlDuration;//视频总时长
    QString m_CutScreenFile;//截图路径
    PlayOrder m_order;//播放顺序
};

#endif // CONTROLLER_H
