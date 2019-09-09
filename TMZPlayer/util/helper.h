#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>
#include <QFileInfo>
#include <QString>
#include <QRegExp>
#include <iostream>
#include <QSet>
#include <QString>

using namespace std;

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);
    // 判断文件的目录是否为合法的本地文件
    static bool isLocalFile(const QString&);
    // 是合法的文件或者收藏夹名字
    static bool isLegalName(const QString&);
    // 转换本地文件的路径为绝对路径
    static QString toAbsPath(const QString&);
    // 检查收藏夹下标是否合法
    static bool isLegalIndex(const int&pNext, const int&index);
signals:

public slots:

private:
    static void testShowAll(const QString& _databaseName="Retina.db");
    static bool testCreateDatabase(const QString& _databaseName="Retina.db");
};

enum MyErrors
{
    FILE_PATH_ERROR, NAME_ERROR, CONTENT_INDEX_ERROR,
    FOLDER_INDEX_ERROR, DB_PARAM_ERROR, HISTORIES_MAX_NUMBER_ERROR,
    PROGRESS_MILLI_SECOND_ERROR,
    FOLDER_UNCHOSEN_ERROR, NO_NEXT_FOLDER_ERROR, FOLDER_CONTENT_SELECT_ERROR,
    FOLDER_CONTENT_UNCHOSEN_ERROR, NO_NEXT_FOLDER_CONTENT_ERROR,
    HISTORICAL_CONTENT_UNCHOSEN_ERROR, NO_NEXT_HISTORICAL_CONTENT_ERROR,
    HISTORICAL_CONTENT_SELECT_ERROR, PLAY_ORDER_ERROR,
    WEB_SEARCH_ERROR, EMPTY_TABLE_ERROR, UNKNOWN_PLAY_AREA_ERROR,
    MEDIA_STATE_ERROR, GET_LAST_AV_ERROR
};

enum PlayOrder
{
    SINGLE_CYCLE,  // 单曲循环
    SHUFFLE,  // 随机播放
    ORDER_PLAY,  // 顺序播放
    ORDER_CYCLE  // 列表循环
};

enum MediaType
{
    VIDEO, AUDIO, UNKNOWN
};

enum PlayArea
{
    FOLDERS=-3, HISTORIES=-2, UNSURE=-1
};

QString playArea2String(const PlayArea& playArea);

class MediaTypeHelper
{
public:
    static const QSet<QString> videoTypes;
    static const QSet<QString> audioTypes;
    MediaTypeHelper();
    static MediaType getType(const QString& _suffix);
};

const QString getErrorType(const MyErrors& _error);

#endif // HELPER_H
