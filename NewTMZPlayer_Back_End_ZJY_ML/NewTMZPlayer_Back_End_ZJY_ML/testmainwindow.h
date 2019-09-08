/**
  用于测试的临时窗口
  **/
#ifndef TESTMAINWINDOW_H
#define TESTMAINWINDOW_H
#include <QKeySequence>
#include <QMainWindow>
#include <QVideoWidget>
#include "util/media.h"
#include "util/histories.h"
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
    QVideoWidget *myVideoWidget;
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
    void on_volumeUpButton_clicked();
    void on_volumeDownButton_clicked();
    void on_jumpButton_clicked();
    void on_muteButton_clicked();
    void on_nonMuteButton_clicked();
    void on_screenCutButton_clicked();
    void on_gifStartButton_clicked();
    void on_gifEndButton_clicked();
    void closeEvent(QCloseEvent *event);
};

#endif // TESTMAINWINDOW_H
