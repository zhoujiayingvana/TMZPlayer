#ifndef HISTORIES_H
#define HISTORIES_H

#include <QObject>
#include <QMap>
#include "util/historicalcontent.h"
#include "io/historieshandler.h"
#include <QStack>

class Histories : public QObject
{
    Q_OBJECT
public:
    explicit Histories(QObject* parent=nullptr,
                       const QString& _userName="Retina",
                       const int& _maxSize=12);
    Histories(const Histories& other);
    Histories& operator=(const Histories& other);
    // 测试输出
    void testPrint()const;
    // 获取容器
    QMap<int, HistoricalContent>* getRank2content() const;
signals:

public slots:
    // 析构转换map
    void makeMapEmpty();
    // 析构所有
    void makeEmpty();
    // 自检maxNumber是否合法
    void checkMaxNumber() const;
    // 判断是否还有空余
    bool hasRemainedPlace() const;
    // 添加一个历史记录到历史记录表中
    // 注意每次在打开的时候, 调用add
    // 新 open 的才会在历史记录中置顶
    void addContent(const QString& _fileName,
                    const QString& _filePath,
                    const bool& _isLocal,
                    const int64_t& _progressMillisecond);
    void addContent(const HistoricalContent&);
    // 删除一个历史记录
    void removeContent(const int&);
    // 获取指定位置的记录content
    HistoricalContent& getHistoricalContent(const int&) const;
    // 获取用户名
    QString getUserName() const;
    // 设置用户名
    void setUserName(const QString& value);
    // 获取历史记录最大条目数量
    int getMaxSize() const;
    // 获取所有的contents
    QList<HistoricalContent> getAllContents()const;
    // 完成初始化
    void startInit();
    // 完成关闭时的写回
    void startClose();
    // 实现历史记录的上下移动
    void moveContent(const int& _toContentIndex, const int& _fromContentIndex);
    // 获取当前选择的历史记录
    int getPChosen() const;
    // 设置当前选择的历史记录
    void setPChosen(int value);
    // 判断是否有上一次的选中历史记录
    bool hasChosen() const;
    // 移到下一个
    void moveChosen2Next();
    // 移到上一个
    void moveChosen2Last();
    // 试图播放时, 调用getPointed
    HistoricalContent& getPointedHistoricalContent();
    // 试图获取mediacontent
    QMediaContent* getPointedMediaContent();
    // 判断是不是空的历史记录
    bool isEmpty()const;
    // 根据选择的 PlayOrder 来确定下一首媒体的索引
    // 注意使用 error 来表示, 出现异常错误
    // 使用 -1 表示没有下一首了
    int getNextRankByPlayOrder(const PlayOrder& playOrder) const;
    // 获取所有的文件路径
    QStringList getAllPaths() const;
    // 根据指定路径名移动到第一个
    void move2First(const QString& _filePath);
protected:
    // 用户名
    QString userName;
    // 最大个数
    int maxSize;
    // 指向下一个
    int pNext;
    // 建立历史记录的位置到内容的连接
    QMap<int, HistoricalContent>* rank2content;
    // 指向当前的历史记录的rank数
    int pChosen;
};

#endif // HISTORIES_H
