#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QLayout>
#include "myslider.h"
#include "bottombutton.h"
#include "widget.h"




/*
 *Author:LY
 *Function:实现底部栏
 */

class BottomBar : public QWidget
{
    Q_OBJECT
public:
    explicit BottomBar(QWidget *parent = nullptr);

signals:

public slots:

    //静音/恢复音量
    void on_volumeButton_clicked();
    //拖拽改变音量时用tooltip显示当前音量
    void on_volumeSlider_valueChanged(int);
    //点击切换音乐/视频模式
    void on_switchmodeButton_clicked();



private:
    QPushButton * lastButton;//上一个按钮
    QPushButton * pauseButton;//暂停/播放按钮
    QPushButton * nextButton;//下一个按钮
    QLabel * currentPos;//播放到的时间
    MySlider * playSlider;//播放条
    QLabel * totalTime;//总时长
    BottomButton *  volumeButton;//静音/恢复音量按钮  
    MySlider * volumeSlider;//音量条
    QPushButton *  playmodeButton;//播放模式按钮
    QPushButton * switchmodeButton;//切换模式按钮

    QLabel * space ;//底部空白
    QPushButton * definitionButton;//清晰度按钮
    QPushButton * settingsButton;//视频设置按钮
    QPushButton * full_screenButton;//全屏/恢复按钮

    QVBoxLayout * BottomLayout;//底部栏总布局
    QHBoxLayout * BmBottomLayout;//底部栏最下端的水平布局

    Widget * volumeWidget;//视频模式音量窗口
    QVBoxLayout * volumeLayout;//视频模式音量窗口的布局
    Widget * definitionWidget;//视频模式清晰度窗口
    QVBoxLayout * definitionLayout;//视频模式清晰度窗口的布局
    Widget * settingsWidget;//视频模式设置窗口
    QVBoxLayout * settingsLayout;//视频模式设置窗口的布局

    int volume;//TEST

};

#endif // BOTTOMBAR_H
