#ifndef HISTORICALCONTENT_H
#define HISTORICALCONTENT_H

#include <QObject>
#include <QMediaContent>
#include "util/helper.h"

class HistoricalContent : public QObject
{
    Q_OBJECT
public:
    explicit HistoricalContent(QObject* parent=nullptr,
                               const QString& _fileName="",
                               const QString& _filePath="",
                               const bool& _isLocal=false,
                               const int& _rank=-1,
                               const int64_t& _progressMillisecond=0);
    // 实现自检判断是否为合法的文件名
    void checkFileName();
    // 检查progressMillSecond是否合法
    void checkProgressMilliSecond();
    // 析构函数
    ~HistoricalContent();
    // 实现复制构造函数
    HistoricalContent(const HistoricalContent& other);
    // 实现赋值重载
    HistoricalContent& operator=(const HistoricalContent& other);
    // 测试输出
    void testPrint() const;
signals:

public slots:
    // 析构content对象
    void makeContentEmpty();
    // 析构所有
    void makeEmpty();
    // 判断文件路径是否可以被访问
    bool isAccessibleFilePath();
    // 重新构建content
    void rebuildContent();
    // 获取文件名
    QString getFileName() const;
    // 设置文件名
    void setFileName(const QString& value);
    // 获取文件路径
    QString getFilePath() const;
    // 设置文件路径
    void setFilePath(const QString& value);
    // 判断是否为本地文件
    bool getIsLocal() const;
    // 设置是否为本地文件
    void setIsLocal(bool value);
    // 获取所在历史列表中的位置
    int getRank() const;
    // 设置所在历史列表中的位置
    void setRank(int value);
    // 获取content指针
    QMediaContent* getMediaContent() const;
    // 获取历史播放的毫秒数位置
    int64_t getProgressMilliSecond() const;
    // 设置里时播放的毫秒数位置
    void setProgressMilliSecond(const int64_t& value);
    // 获取文件类型
    MediaType getMediaType() const;
protected:
    // 文件名
    QString fileName;
    // 文件路径
    QString filePath;
    // 是否为本地文件
    bool isLocal;
    // 处于整个历史记录表中的第几个
    int rank;
    // 用于存储此视频的上次浏览秒数
    int64_t progressMilliSecond;
    // 用于播放的content
    QMediaContent* mediaContent;
};

#endif // HISTORICALCONTENT_H
