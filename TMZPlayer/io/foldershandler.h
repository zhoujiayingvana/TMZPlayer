#ifndef FOLDERSHANDLER_H
#define FOLDERSHANDLER_H

#include <QThread>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <util/helper.h>
#include <util/foldercontent.h>
#include <QMapIterator>

class Folders;

class FoldersHandler : public QThread
{
public:
    static void insertFolder2Database(const QString& _userName="Retina",
                                      const QString& _folderName="",
                                      const int& _rank=-1);
    static void insertContent2Database(const QString& _userName="Retina",
                                       const QString& _folderName="",
                                       const QString& _fileName="",
                                       const QString& _filePath="",
                                       const int& _isLocal=0,
                                       const int& _rank=-1);
    static void insertContent2Database(const QString& _userName="Retina",
                                       const FolderContent* _folderContent=nullptr);
private:
    static void deleteContentFromDatabase(const QString& _userName,
                                          const QString& _folderName,
                                          const int& _rank);
    static void deleteFolderFromDatabase(const QString& _userName,
                                         const QString& _folderName);
};

class FoldersIniter: public QThread
{
protected:
    Folders* folders;
public:
    FoldersIniter(Folders* _folders=nullptr);
    // 实现异步访问数据库, 在初始化folders的时候一次全读入
    // 注意数据库的结构设计
    // 注意每个字段, 以及使用 null 来作为收藏夹的头表示
    void run();
};

class FoldersCloser: public QThread
{
protected:
    Folders* folders;
public:
    FoldersCloser(Folders* _folders=nullptr);
    // 实现异步关闭数据库时刷新整个表
    void run();
};

#endif // FOLDERSHANDLER_H
