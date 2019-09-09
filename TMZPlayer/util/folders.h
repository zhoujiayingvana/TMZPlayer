/******************************************************
 **
 ** 在这个文件中构建收藏夹群
 ** 注意要完成与数据库的交互
 **
 ******************************************************/

#ifndef FOLDERS_H
#define FOLDERS_H

#include <QObject>
#include <QMap>
#include <QSet>
#include "util/folder.h"
#include "util/helper.h"
#include "io/foldershandler.h"
#include <QMutex>
#include <QWaitCondition>
#include "util/histories.h"

class Folders : public QObject
{
    Q_OBJECT
public:
    explicit Folders(QObject *parent = nullptr, const QString& _userName="Retina");
    Folders(const Folders& other);
    Folders& operator=(const Folders& other);
    ~Folders();
    // 测试输出
    void testPrint() const;
    QMap<QString, int>* getFolderName2Index() const;    
signals:

public slots:
    // 析构index到folder的map对象
    void makeIndex2FolderEmpty();
    // 析构收藏夹名到索引的map对象
    void makeFolderName2IndexEmpty();
    // 清空选中
    void makePChosenEmpty();
    // 析构所有
    void makeEmpty();
    // 判断收藏夹名是否存在
    bool hasFolderName(const QString&);
    // 添加一个新的收藏夹
    void addNewFolder(const QString& _folderName);
    // 添加新的content到一个收藏夹中
    QList<QString> getFolderNames() const;
    // 根据索引获取folder
    // 根据收藏夹名字获取folder
    Folder& getFolder(const int&);
    Folder& getFolder(const QString&);
    // 删除指定的位置的收藏夹
    void removeFolder(const int&);
    // 重命名folder
    void renameFolder(const int& _index, const QString& _newFolderName);
    // 向指定位置的 folder 中添加一个新的 content
    // 使用index
    void addContent2Folder(const int& _index, const QString& _fileName,
                           const QString& _filePath, const bool& _isLocal);
    // 使用folderName
    void addContent2Folder(const QString& _folderName, const QString& _fileName,
                           const QString& _filePath, const bool& _isLocal);
    // 提供对用户名的获取
    QString getUserName() const;
    // 设置用户名
    void setUserName(const QString& value);
    // 开始初始化工作
    void startInit();
    // 开始关闭的存储工作
    void startClose();
    // 删除指定收藏夹中的content
    void removeContentFromFolder(const int& _folderIndex, const int& _contentIndex);
    // 移动指定收藏夹中的内容
    void moveFolderContent(const int& _folderIndex,
                           const int& _toFolderContentIndex,
                           const int& _fromFolderContentIndex);
    // 移动收藏夹
    void moveFolder(const int& _toFolderIndex, const int& _fromFolderIndex);
    // 加入到收藏夹中一个content
    void addContent2Folder(const QString& _folderName, const FolderContent& _folderContent);
    // 获取当前正在使用的收藏夹的位置指针
    int getPChosen() const;
    // 用以设置当前正在播放收藏夹的位置指针
    // 注意若要设置新的chosen, 则应该清楚上一个folder的chosen设置为-1
    void setPChosen(int value);
    // 判断是否开始被选择
    bool hasChosen() const;
    // 获取下一个chosen
    void moveChosen2Next();
    // 获取上一个chosen
    void moveChosen2Last();
    // 获取指定收藏夹中指定的content
    FolderContent& getPointedFolderContent();
    // 获取指定收藏夹中的最终mediacontent
    QMediaContent* getPointedMediaContent();
    // 获取被当前被选中的收藏夹
    Folder& getPointedFolder();
    // 获取当前选中收藏夹下的下一首曲目的索引
    int getNextRankOfPointedFolder(const PlayOrder& playOrder) const;
    // move chosen to histories
    void addChosenFolderContent2Histories(Histories& _histories);
protected:
    // 实现存储映射表
    QMap<int, Folder>* rank2Folder;
    // 实现存储收藏夹名字的映射
    QMap<QString, int>* folderName2Rank;
    // 用以存储下一个的索引下标
    int pNext;
    // 用以存储使用这些收藏夹的用户
    QString userName;
    // 用以指向当前的收藏夹组下的哪一个收藏夹
    int pChosen;
};

#endif // FOLDERS_H
