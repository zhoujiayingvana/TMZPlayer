/**
  封装所有后端组件的容器
  可能具有控制功能
  **/
#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>
#include "util/player.h"
#include "util/controller.h"

class Media : public QWidget
{
    Q_OBJECT
public:
    explicit Media(QWidget *parent = nullptr);
    ~Media();
    QMediaPlayer* getPlayWindow();//获取播放窗口
    Controller* getController();//获取控制模块
signals:
    
public slots:
    
private:
    Player* media_Player;
    Controller* media_Controller;
    
};

#endif // MEDIA_H
