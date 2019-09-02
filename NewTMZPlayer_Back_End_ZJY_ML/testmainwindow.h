﻿/**
  用于测试的临时窗口
  **/
#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H

#include <QMainWindow>
#include <QVideoWidget>
#include "util/media.h"
namespace Ui {
class TestMainWindow;
}

class TestMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit TestMainWindow(QWidget *parent = nullptr);
    ~TestMainWindow();
    
private:
    Ui::TestMainWindow *ui;
    Media* media;
private slots:
    
    //接收按钮的播放状态，前端实现
    //播放
//    void play();
//    //改变播放状态
//    void mediaStateChanged(QMediaPlayer::State state);
//    //改变播放位置
//    void positionChanged(qint64 position);
//    //获取播放位置
//    void setPosition(int position);
    void on_playButton_clicked();
    void on_pauseButton_clicked();
    void on_terminateButton_clicked();
    void on_nextButton_clicked();
    void on_forwardButton_clicked();
};

#endif // TESTMAINWINDOW_H
