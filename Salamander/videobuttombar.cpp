#include "videobuttombar.h"

VideoButtomBar::VideoButtomBar(QWidget *parent) : QWidget(parent)
{
    setFixedHeight(40);

    playSlider = new MySlider(this);//视频播放条
    lastButton = new QPushButton(this);//上一个（视频）按钮
    pauseButton = new QPushButton(this);//暂停按钮
    nextButton = new QPushButton(this);//下一个（视频）按钮
    currentPos = new QLabel(this);//视频播放到的时间
    totalTime = new QLabel(this);//视频总时长
    volumeButton = new QPushButton(this);//静音/恢复音量按钮
    volumeSlider = new MySlider(this);//音量条
    definitionButton = new QPushButton(this);//清晰度按钮
    settingsButton = new QPushButton(this);//视频设置按钮
    switchmodeButton = new QPushButton(this);//切换模式按钮
    full_screenButton = new QPushButton(this);//全屏/恢复按钮

    //固定按钮大小
    lastButton->setFixedSize(60,30);
    pauseButton->setFixedSize(30,30);
    nextButton->setFixedSize(60,30);
    currentPos->setFixedSize(30,30);
    totalTime->setFixedSize(30,30);
    volumeButton->setFixedSize(30,30);
    volumeSlider->setFixedSize(60,20);
    definitionButton->setFixedSize(30,30);
    settingsButton->setFixedSize(30,30);
    switchmodeButton->setFixedSize(30,30);
    full_screenButton->setFixedSize(30,30);






}
