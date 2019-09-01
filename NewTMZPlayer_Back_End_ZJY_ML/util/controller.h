#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QWidget>
#include <QMediaPlayer>
#include <QUrl>


class Controller : public QWidget
{
    Q_OBJECT
public:
    explicit Controller(QWidget *parent = nullptr);
    ~Controller();
    

    //播放本地文件/网络文件,与folderContent连接
    void play(QUrl*);
    //播放收藏夹文件，与folderContent连接
    void play(QString*,QString*);
    
    //调试用
    void testPlay(QMediaContent * content);
    

    
    //设置视频
    //播放/恢复播放
    void restorePlay();
    //暂停播放
    void pauseVideo();
    //停止播放
    void terminateVideo();
    //跳转到指定位置
    void seekPosition(qint64);
    //设置视频音量
    void setVolume(int vol);
    //设置静音,true为静音，false为取消静音
    void setMute(bool m);
    
    //player自带槽函数
    void setPlaybackRate(int rate);
    //
signals:
    //获取视频信息
    //获取时长
    void getDuration();
    //获取当前进度时间
    void getPosition();
    //获取视频状态
    void getStatus();
    
    //设置视频
    //打开并播放视频
    void needPlay(QMediaContent *content);
    

    //播放/恢复播放
    void needRestorePlay();
    //暂停播放
    void needPauseVideo();
    //停止播放
    void needTerminateVideo();
    //跳转到指定位置
public slots:
    
//    //获取Player传递的Position
//    void receivePosition(qint64);
//    //获取Player传递的Duration
//    void receiveDuration(qint64);
//    //获取Player传递的State
//    void receiveState(QMediaPlayer::State);//参数异步传递的问题
    

private:
    QMediaPlayer::State m_CtrlPlayState;//播放状态，默认为StoppedState
    qint64 m_CtrlCurrentPosition;//当前播放的时间进度
    qint64 m_CtrlDureation;//视频总时长
};

#endif // CONTROLLER_H
