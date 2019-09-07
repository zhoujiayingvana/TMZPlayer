/******************************************************
 **
 ** 在这个文件夹中构建收藏夹类
 ** 实现之后对收藏夹的管理
 **
 ******************************************************/
#ifndef FOLDER_H
#define FOLDER_H

#include <QObject>
#include <QMap>
#include <QStringList>
#include <QList>
#include "util/foldercontent.h"
#include <QMapIterator>
#include <QMutableMapIterator>
#include <QSet>
#include <QtGlobal>
#include <QRandomGenerator>

using namespace std;

class Folder : public QObject
{
    Q_OBJECT
public:
    explicit Folder(QObject* parent=nullptr,
                    const QString& _folderName="", const int& _rank=-1);
    Folder(const Folder& other);
    Folder& operator=(const Folder& other);
    ~Folder();
    // 用于测试
    void testPrint() const;
signals:

public slots:
    // 获取一个文件, 通过文件的位置
    FolderContent& getFolderContent(const int&) const;
    // 获取指定位置的文件的名字
    QString getFileName(const int&)const;
    // 获取收藏中所有文件的名字
    QList<QString> getFileNames() const;
    // 析构收藏夹容器这个对象
    void makeContainerEmpty();
    // 析构文件名集合
    void makeFileNamesEmpty();
    // 清空被选中的记录
    void makePChosenEmpty();
    // 析构所有new出来的对象
    void makeEmpty();
    // 判断一个文件名字是不是在收藏夹中
    bool hasFile(const QString&)const;
    // 增加一个文件到收藏夹中
    void addAndSetRankContent(FolderContent&);
    // 删除一个文件从收藏夹中
    // 根据位置来删除
    void removeContent(const int&);
    // 获取收藏夹的名字
    QString getFolderName() const;
    // 设置收藏夹的名字
    // 注意设置收藏夹中名字后, 应该更新所有的content的收藏夹名字
    void setFolderName(const QString& value);
    // 获取container which is a map
    QMap<int, FolderContent>* getContainer() const;
    // 实现移动某一条记录从哪里的index到哪里的index
    void moveContent(const int& _toIndex, const int& _fromIndex);
    // 更新所有的content的rank
    void updateRanks(const int& _fromIndex);
    // 获取本收藏夹在所有的收藏夹中的rank
    int getRank() const;
    // 设置本收藏夹在所有收藏夹中的rank
    void setRank(int value);
    // 获取所有的 folder content 对象
    QList<FolderContent> getFolderContents()const;
    // 获取选中的指针
    int getPChosen() const;
    // 设置选中的指针
    void setPChosen(int value);
    // 判断是否有被选中
    bool hasChosen() const;
    // 将选中的文件指针指向下一个
    void moveChosen2Next();
    // 指向上一个
    void moveChosen2Last();
    // 获取选中的folderContent
    FolderContent& getPointedContent();
    // 判断是不是空收藏夹
    bool isEmptyFolder()const;
    // 根据选择的 PlayOrder 来确定下一首媒体的索引
    // 注意使用 error 来表示, 出现异常错误
    // 使用 -1 表示没有下一首了
    int getNextRankByPlayOrder(const PlayOrder& playOrder) const;
protected:
    // 收藏夹名字
    QString folderName;
    // 收藏夹容器
    QMap<int, FolderContent>* container;
    // 需要一个数字来记录目前加入的content属于folder中的第几个
    int pNext;
    // 一个集合用于存储所有的文件名
    QSet<QString>* fileNames;
    // 收藏夹位于所有收藏夹中的位置
    int rank;
    // 设置一个用以表针选中收藏夹中哪一个
    int pChosen;
};

#endif // FOLDER_H
