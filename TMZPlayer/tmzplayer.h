#ifndef TMZPLAYER_H
#define TMZPLAYER_H

#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QMouseEvent>
#include"settingwindow.h"

namespace Ui {
class TMZPlayer;
}

class TMZPlayer : public QMainWindow
{
    Q_OBJECT

public:
    explicit TMZPlayer(QWidget *parent = nullptr);
    ~TMZPlayer();

    bool nativeEvent(const QByteArray &eventType, void *message, long *result);


public slots:
    /*
     * 修改主界面背景
     * 设置界面三个button分别emit传QString
     * */
    void changeBackGround(QString);

    //修改主界面自定义图片背景
    void changePicBackGround(QString);



private:
    Ui::TMZPlayer *ui;


};

#endif // TMZPLAYER_H
