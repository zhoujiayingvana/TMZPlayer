#include "dbfinisherthread.h"

DBFinisherThread::DBFinisherThread(QSqlQuery* _query,
                                   const QString& _tableName,
                                   const bool& _emptyRequested)
    : tableName(_tableName), query(_query),
      emptyRequested(_emptyRequested)
{

}

void DBFinisherThread::emptyTable()
{
    QString sqlString = "DELETE FROM %1";
    sqlString = sqlString.arg(this->tableName);
    if (!this->query->exec(sqlString))
    {
        qDebug() << this->query->lastError().text();
        throw MyErrors::EMPTY_TABLE_ERROR;
    }
}

void DBFinisherThread::run()
{
    if (this->emptyRequested)
        this->emptyTable();
}
