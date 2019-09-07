/**
  封装所有后端组件的容器
  可能具有控制功能
  **/
#ifndef MEDIA_H
#define MEDIA_H

#include <QWidget>
#include "util/player.h"
#include "util/controller.h"
#include "util/networkmodel.h"
#include "util/histories.h"
#include "util/folders.h"

class Media : public QWidget
{
    Q_OBJECT
public:
    explicit Media(QWidget *parent = nullptr);
    ~Media();
    QMediaPlayer* getPlayWindow();//获取播放窗口
    Controller* getController();//获取控制模块
    // 用于测试的流程
    void testRun();
    Histories& getHistories();
    void setHistories(const Histories& value);
    Folders& getFolders();
    void setFolders(const Folders& value);
    //播放本地文件/网络文件,与historicalContent连接
    void play(QString);
    //播放收藏夹文件，与folderContent连接
    void play(int ,int);
signals:
    void returnOrder(PlayOrder);
public slots:
    void playNext();
    void receivePosition(qint64);
    void needSetOrder(PlayOrder order);
    void needGetOrder();
private slots:
    void playNext(QMediaPlayer::State state);
    
private:
    Player* media_Player;
    Controller* media_Controller;
    NetworkModel* media_NetworkModel;
    // 用以控制用户界面的信息
    // 历史记录
    Histories media_Histories;
    // 收藏夹
    Folders media_Folders;
    //播放顺序
    PlayOrder media_Order;
    bool media_isFolders;
};

#endif // MEDIA_H
