/*********************************************************
 **
 ** 在这个类中实现收藏夹对象的构建
 ** 注意不支持改路径
 ** 若用户要更改路径, 则允许使用全新的对象
 **
 *********************************************************/

#ifndef FOLDERCONTENT_H
#define FOLDERCONTENT_H

#include <QObject>
#include "util/helper.h"
#include <QMediaContent>
#include <QUrl>

class FolderContent : public QObject
{
    Q_OBJECT
public:
    explicit FolderContent(QObject* parent=nullptr,
                           const QString& _folderName="",
                           const QString& _fileName="",
                           const QString& _filePath="",
                           const bool& _isLocal=true,
                           const int& _rank=-1,
                           QMediaContent* _mediaContent=nullptr);
    FolderContent(const FolderContent& other);
    FolderContent& operator=(const FolderContent& other);
    ~FolderContent();
    // 测试输出
    void testPrint()const;
signals:

public slots:
    // 判断路径是否有效, 若为 url 则恒定有效
    bool isAccessibleFilePath()const;
    // 析构对笑
    void makeContentEmpty();
    // 析构所有new出来的对象
    void makeEmpty();
    // 根据 path 重构对象
    void rebuildContent();
    // 获取所属收藏夹的名字
    QString getFolderName() const;
    // 设置所属收藏夹的名字
    void setFolderName(const QString& value);
    // 获取文件名字
    QString getFileName() const;
    // 设置文件名字
    void setFileName(const QString& value);
    // 获取文件的绝对路径
    QString getFilePath() const;
//    void setFilePath(const QString& value);  // 注意不提供改变路径的方法
                                               // 若要改变路径则重新构建一个对象
    // 获取是否为本地文件
    bool getIsLocal() const;
    // 获取文件在收藏夹中的位置
    int getRank() const;
    // 设置文件在收藏夹中的位置
    void setRank(int value);
    // 获取用于构建的播放的实体
    QMediaContent* getMediaContent() const;
    // 获取文件的类型
    MediaType getMediaType() const;
protected:
    // 收藏夹名
    QString folderName;
    // 文件名
    QString fileName;
    // 文件路径
    QString filePath;
    // 判断是否为本地文件
    bool isLocal;
    // 文件在收藏夹中的排序
    int rank;
    // 用于构建的实体
    QMediaContent* mediaContent;
};

#endif // FOLDERCONTENT_H
