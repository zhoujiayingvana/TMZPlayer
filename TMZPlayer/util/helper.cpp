#include "helper.h"

Helper::Helper(QObject *parent) : QObject(parent)
{

}

bool Helper::isLocalFile(const QString& _filePath)
{
    QFileInfo fileInfo(_filePath);
    return fileInfo.isFile();
}

bool Helper::isLegalName(const QString& _fileName)
{
    // 不包含 @ 且 #
    return (_fileName != nullptr &&
            _fileName.size() > 0 &&
            !_fileName.contains("@") &&
            !_fileName.contains("#"));

}

QString Helper::toAbsPath(const QString& relPath)
{
    QFileInfo fileInfo(relPath);
    return fileInfo.absoluteFilePath();
}

bool Helper::isLegalIndex(const int& pNext, const int& index)
{
    return index < pNext && index >= 0;
}




/**************************************************************
 **
 ** 以下代码用于测试
 **
 **************************************************************/

bool Helper::testCreateDatabase(const QString& _databaseName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString("../user/%1").arg(_databaseName));  // 根据用户名创建一个 .db
    bool ans = db.open();
    db.close();
    return ans;
}

void Helper::testShowAll(const QString& _databaseName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(QString("../user/%1").arg(_databaseName));
    if (!db.open())
    {
        qDebug() << db.lastError().text() << endl;
        return ;
    }
    QString order("SELECT * FROM histories");
    QSqlQuery query(db);
    if (!query.exec(order))
    {
        qDebug() << db.lastError().text() << endl;
        return ;
    }
    while (query.next())
    {
        qDebug() << query.value("id") << endl
                 << query.value("fileName") << endl
                 << query.value("filePath") << endl
                 << query.value("isLocal") << endl
                 << query.value("progressSecond") << endl;
    }
    db.close();
}

/**************************************************************
 **
 ** 以上代码用于测试
 **
 **************************************************************/

const QString getErrorType(const MyErrors& _error)
{
    switch (_error)
    {
    case MyErrors::FILE_PATH_ERROR:
        return QString("file path error");
    case MyErrors::NAME_ERROR:
        return QString("file or folder name error");
    case MyErrors::CONTENT_INDEX_ERROR:
        return QString("search content index error");
    case MyErrors::FOLDER_INDEX_ERROR:
        return QString("search folder index error");
    case MyErrors::DB_PARAM_ERROR:
        return QString("paramerters error when io with database");
    case MyErrors::HISTORIES_MAX_NUMBER_ERROR:
        return QString("histories max number error");
    case MyErrors::PROGRESS_MILLI_SECOND_ERROR:
        return QString("progress million second error");
    case MyErrors::FOLDER_UNCHOSEN_ERROR:
        return QString("folder unchosen error");
    case MyErrors::NO_NEXT_FOLDER_ERROR:
        return QString("no more folder in folders");
    case MyErrors::FOLDER_CONTENT_SELECT_ERROR:
        return QString("selecting an error folder content");
    case MyErrors::FOLDER_CONTENT_UNCHOSEN_ERROR:
        return QString("folder content of a folder unchosen error");
    case MyErrors::NO_NEXT_FOLDER_CONTENT_ERROR:
        return QString("no more folder content of a folder error");
    case MyErrors::NO_NEXT_HISTORICAL_CONTENT_ERROR:
        return QString("no more historical content error");
    case MyErrors::HISTORICAL_CONTENT_UNCHOSEN_ERROR:
        return QString("historical content unchosen error");
    case MyErrors::HISTORICAL_CONTENT_SELECT_ERROR:
        return QString("selecting an error historical content");
    case MyErrors::PLAY_ORDER_ERROR:
        return QString("play order out of expectation");
    case MyErrors::WEB_SEARCH_ERROR:
        return QString("web search error");
    case MyErrors::EMPTY_TABLE_ERROR:
        return QString("empty table error");
    case MyErrors::UNKNOWN_PLAY_AREA_ERROR:
        return QString("unknown play area error");
    case MyErrors::MEDIA_STATE_ERROR:
        return QString("media state error");
    case MyErrors::GET_LAST_AV_ERROR:
        return QString("get last av error, perhaps: empty infos stack or the file has been removed");
    default:
        return QString("unknown error");
    }
}

const QSet<QString> MediaTypeHelper::audioTypes =
                QSet<QString>() << "mp4" << "m4v" << "3gp" << "mpg"
                                << "flv" << "f4v" << "swf"
                                << "avi" << "gif" << "wmv" << "rmvb"
                                << "mov" << "mts" << "m2t";
const QSet<QString> MediaTypeHelper::videoTypes =
                QSet<QString>() << "mp3" << "aac" << "m4a" << "ape"
                                << "flac" << "wav" << "wma" << "amr"
                                << "mid";

MediaTypeHelper::MediaTypeHelper()
{
}

MediaType MediaTypeHelper::getType(const QString& _suffix)
{
    for (QString videoTypeStr: MediaTypeHelper::videoTypes)
        if (0 == videoTypeStr.compare(_suffix, Qt::CaseInsensitive))
            return MediaType::VIDEO;
    for (QString audioTypeStr: MediaTypeHelper::audioTypes)
        if (0 == audioTypeStr.compare(_suffix, Qt::CaseInsensitive))
            return MediaType::AUDIO;
    return MediaType::UNKNOWN;
}

QString playArea2String(const PlayArea& playArea)
{
    switch (playArea)
    {
    case PlayArea::UNSURE:
        return QString("area unsure");
    case PlayArea::FOLDERS:
        return QString("area at folders");
    case PlayArea::HISTORIES:
        return QString("area at histories");
    default:
        return QString("area error!!!");
    }
}
