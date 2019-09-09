#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QWidget>
#include<QPushButton>
#include<QLabel>
#include<QLayout>
#include<QShortcut>
#include "myslider.h"
#include "bottombutton.h"
#include "widget.h"
#include"settingwindow.h"



/*
 *Author:LY
 *Function:实现底部栏
 */

class BottomBar : public QWidget
{
    Q_OBJECT
public:
    explicit BottomBar(QWidget *parent = nullptr);
    //连接设置界面
    void connectSettingAndBottom(SettingWindow *);

signals:
    void full_screenButton_clicked();
    void volumeChanged(int);
    void wheelMoving(int,int);
public slots:

    //拖拽播放条时改变当前时间
    void on_playSlider_valueChanged(int);
    void on_pauseButton_clicked();
    
    //静音/恢复音量
    void on_volumeButton_clicked();
    //拖拽改变音量时用tooltip显示当前音量
    void on_volumeSlider_valueChanged(int);
    //点击切换音乐/视频模式
    void on_switchModeButton_clicked();
    //检测鼠标是否移至音量悬浮窗
    void volumeWidgetDetection ();
    //检测鼠标是否移至清晰度悬浮窗
    void definitionWidgetDetection ();
    //检测鼠标是否移至设置悬浮窗
    void settingsWidgetDetection ();
    //全屏发射信号
    void on_full_screenButton_clicked();
    //滚轮改变音量
    void wheelMoved(QWheelEvent *);
    //改变音量
    void changeVolume(int);
    //隐藏音量悬浮窗
    void hideVolumeWidget();

    //暂停播放快捷键修改
    void changeActionShortcut(QString);

    //上一首快捷键修改
    void changeLastShortcut(QString);

    //下一首快捷键修改
    void changeNextShortcut(QString);


    //静音复音快捷键修改
    void changeVolumeOnOffShortcut(QString);

    //改变播放倍速
    void changeMultiplyingPower(int);

    //改变清晰度
    void changeDefinition(int);

    //音量加
    void volumeSliderValueAdd();
    //音量减
    void volumeSliderValueSub();
    //全屏模式改变按钮大小
    void changeButtonSize();



private:
    void isatWidget(QWidget *);
    QPushButton * lastButton;//上一个按钮
    QPushButton * pauseButton;//暂停/播放按钮
    QPushButton * nextButton;//下一个按钮
    QLabel * currentPos;//播放到的时间
    MySlider * playSlider;//播放条
    QLabel * totalTime;//总时长
    BottomButton *  volumeButton;//静音/恢复音量按钮
    MySlider * volumeSlider;//音量条
    QPushButton *  playModeButton;//播放模式按钮
    QPushButton * switchModeButton;//切换模式按钮

    QLabel * space ;//底部空白
    BottomButton * definitionButton;//清晰度按钮
    BottomButton * settingsButton;//视频设置按钮

    QPushButton * full_screenButton;//全屏/恢复按钮

    QVBoxLayout * BottomLayout;//底部栏总布局
    QHBoxLayout * BmBottomLayout;//底部栏最下端的水平布局

    Widget * volumeWidget;//视频模式音量窗口
    QVBoxLayout * volumeLayout;//视频模式音量窗口的布局

    Widget * definitionWidget;//视频模式清晰度窗口
    QVBoxLayout * definitionLayout;//视频模式清晰度窗口的布局
    //视频模式清晰度窗口下各清晰度按钮
    QPushButton * autoDefinitionButton;
    QPushButton * p360DefinitionButton;
    QPushButton * p480DefinitionButton;
    QPushButton * p720DefinitionButton;




    Widget * settingsWidget;//视频模式设置窗口
    QVBoxLayout * settingsLayout;//视频模式设置窗口的布局
    //视频模式设置窗口内容
    QLabel * playModeLabel;
    QPushButton * playModeButton_1;
    QPushButton * playModeButton_2;
    QPushButton * playModeButton_3;
    QLabel * playSpeedLabel;
    QLabel * multiplyingPowerLabel;
    MySlider * playSpeedSlider;
    QLabel * videoRatioLabel;
    QPushButton * autoRatioButton;
    QPushButton * ratio4_3Button;
    QPushButton * ratio16_9Button;
    QLabel * othersLabel;
    QPushButton * someFunctionButton;//test

    int multiplyingPower;//倍速播放




    int volume;//TEST

};

#endif // BOTTOMBAR_H
