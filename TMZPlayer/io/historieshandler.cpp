#include "historieshandler.h"
#include <util/histories.h>

HistoriesHandler::HistoriesHandler()
{

}

void HistoriesHandler::addContent2Database(const QString& _userName,
                                           const HistoricalContent& historicalContent)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(_userName));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QSqlQuery query(db);
    QString sqlString = (
        "INSERT INTO histories (fileName, filePath, isLocal, rank, progressMillisecond)"
        " VALUES ('%1', '%2', %3, %4, %5)"
    );
    const QString fileName = historicalContent.getFileName();
    const QString filePath = historicalContent.getFilePath();
    const int isLocal = (int)historicalContent.getIsLocal();
    const int rank = historicalContent.getRank();
    const int64_t progressMillisecond = historicalContent.getProgressMilliSecond();
    sqlString = sqlString.arg(fileName).arg(filePath).arg(isLocal).arg(rank).arg(progressMillisecond);
    if (!query.exec(sqlString))
    {
        qDebug() << query.lastError().text();
        return ;
    }
    db.close();
}

HistoriesIniter::HistoriesIniter(Histories* _histories)
    : histories(_histories)
{

}

void HistoriesIniter::run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(this->histories->getUserName()));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QSqlQuery query(db);
    // 首先应该读取所有的构造
    QString sqlString = (
        "SELECT * FROM histories ORDER BY rank DESC"
    );
    if (!query.exec(sqlString))
    {
        qDebug() << query.lastError().text();
        return ;
    }
    while (query.next())
    {
        QString* fileName = (QString*)query.value("fileName").data();
        QString* filePath = (QString*)query.value("filePath").data();
        bool* isLocal = (bool*)query.value("isLocal").data();
        int64_t* progressMillisecond = (int64_t*)query.value("progressMillisecond").data();
        this->histories->addContent(*fileName, *filePath, *isLocal, *progressMillisecond);
    }
    db.close();
}

HistoriesCloser::HistoriesCloser(Histories* _histories)
    : histories(_histories)
{

}

void HistoriesCloser::run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(this->histories->getUserName()));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QSqlQuery sqlQuery(db);
    QString sqlString("DELETE FROM histories");
    if (!sqlQuery.exec(sqlString))
    {
        qDebug() << sqlQuery.lastError().text();
        return;
    }
    // 全部写回
    QMapIterator<int, HistoricalContent> iter(*this->histories->getRank2content());
    while (iter.hasNext())
    {
        iter.next();
        HistoricalContent temp = iter.value();
        HistoriesHandler::addContent2Database(this->histories->getUserName(), temp);
    }
    db.close();
}
