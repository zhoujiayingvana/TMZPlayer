/**
  封装所有后端组件的容器
  可能具有控制功能
  **/
#ifndef MEDIA_H
#define MEDIA_H

#include <QScreen>
#include <QThread>
#include "util/player.h"
#include "util/controller.h"
#include "util/networkmodel.h"
#include "util/histories.h"
#include "util/folders.h"
#include "tools/gif.h"
#include "io/dbfinisherthread.h"

class Media :public QThread
{
    Q_OBJECT
public:
    explicit Media();
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
    //录制gif图像
    void StartCreateGif(WId,QString fileName,QString filePath);
    void endCreateGif();
    // 获取下载网络的音频到数据库中
    void download2SongsTable(const QString& _what);
    // 网络搜索请求完成
    QList<QMap<QString, QString> > songWebSearch(const QString& _what);
    
signals:
    void returnOrder(PlayOrder);
public slots:
    void playNext();
    void receivePosition(qint64);
    void needSetOrder(PlayOrder order);
    void needGetOrder();
    //关闭保存记录
    void makeSelfEmpty();    
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
    //录制gif图像
    // 图像缓存队列
    QList<QImage> media_QImageList;
    //捕捉图像窗口
    WId media_WId;
    //线程状态控制
    bool media_StartThread;
    void run();
    //gif fullpath
    QString media_GifFullPath;
    //网络功能
    QString pyPath;  // 用以获取 url 地址的脚本文件
    QString username;  // 用户名
    
};

#endif // MEDIA_H
