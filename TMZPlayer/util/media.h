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
#include <QFileInfo>
#include <QProcess>
#include <QMap>
#include <QList>
#include "io/dbfinisherthread.h"
#include <QThread>
#include "tools/gif.h"
#include <QStack>
#include <QFileInfo>
#include <QDateTime>

class MediaStateInfo;

class Media : public QThread
{
    Q_OBJECT
public:
    explicit Media();
    ~Media();
    // 获取播放窗口
    QMediaPlayer* getPlayWindow();
    // 获取控制模块
    Controller* getController();
    // 获取历史记录
    Histories& getHistories();
    // 获取收藏夹组
    Folders& getFolders();
    // 打开文件播放视频, 并且为文件去了名字
    void play(const bool& _isLocal, const QString& _fileName, const QString& _filePath);
    // 打开文件或输入了网址来播放视频, 没有为其取名字
    void play(const bool& _isLocal, const QString& _filePath);
    // 从已有的空间上获取位置索引, 来播放视频
    void play(const PlayArea& _playArea, const int& _firstRank, const int& _secondRank=-1);
    // 清空当前的容器
    void makeContainerEmpty();
    // 开始关闭
    void closeSelf();
    // 开始录制gif图像
    void startCreateGif(WId,QString fileName,QString filePath);
    // 结束录制gif图像
    void endCreateGif();
    // 分析当前的 media 状态获取一个 currentInfo 的对象
    MediaStateInfo getCurrentMediaStateInfo();
    // 选中区域
    void setPlayWhere(const PlayArea& playArea);
    // 选中一级目录, 收藏夹和历史记录都有
    void setFirstRank(const int& _firstRank);
    // 只有收藏夹才有
    void setSecondRank(const int& _secondRank);
    // 添加上一次的播放信息加入到
    void pushCurrentMediaStateInfo2Stack();
    // 获取当前是否有视频正在播放
    bool getHasAVPlaying() const;
    // 测试函数
    void mock();
signals:
    void returnOrder(PlayOrder);
public slots:
    // 判断是否有选中的位置
    bool hasGoodAreaAndRanks();
    // 停止并保存当前的视频位置
    void terminateAndSaveCurrentAV();
    // 手动请求播放下一首
    bool playNextByHand();
    // 自动播放下一首
    bool playNextByAuto(QMediaPlayer::State state);
    // 设置播放顺序
    void needSetOrder(PlayOrder order);
    // 获取播放顺序
    void needGetOrder();
    // 获取下载网络的音频到数据库中
    void download2SongsTable(const QString& _what);
    // 网络搜索请求完成
    QList<QMap<QString, QString> > songWebSearch(const QString& _what);
    // 获取上一个播放的信息
    MediaStateInfo popLastState();
    // 对指定的位置的媒体文件进行比对, 判断是否存在或者地址正确
    bool lastAVAccessible(const MediaStateInfo& lmsi);
    // 设置并且播放上一首
    bool playLast();
    // 读取历史记录播放的话, 应该跳转时间
    void back2Last();
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
    PlayArea media_playWhere;
    QString pyPath;  // 用以获取 url 地址的脚本文件
    QString username;  // 用户名
    // zjy
    // 图像缓存队列
    QList<QImage> media_QImageList;
    //捕捉图像窗口
    WId media_WId;
    //线程状态控制
    bool media_StartThread;
    void run();
    //gif fullpath
    QString media_GifFullPath;
    // 记录之前播放的信息
    QStack<MediaStateInfo> mediaStateInfos;
    // 记录是否有正在播放的视频
    bool hasAVPlaying;
};


class MediaStateInfo
{
protected:
    PlayArea where;
    int firstRank;
    int secondRank;
    QString filePath;
public:
    MediaStateInfo(const PlayArea& _where=PlayArea::UNSURE,
                   const int& _firstRank=-1,
                   const int& _secondRank=-1,
                   const QString& _filePath="");
    MediaStateInfo(const MediaStateInfo& other);
    MediaStateInfo& operator=(const MediaStateInfo& other);
    int getFirstRank() const;
    void setFirstRank(int value);
    int getSecondRank() const;
    void setSecondRank(int value);
    void testPrint() const;
    PlayArea getWhere() const;
    void setWhere(const PlayArea& value);
    QString getFilePath() const;
    void setFilePath(const QString& value);
};


#endif // MEDIA_H
