/***
  **
  ** 在这个类中实现多线程清空表, 关闭的操作
  **
  **
  **/
#ifndef DBFINISHERTHREAD_H
#define DBFINISHERTHREAD_H

#include <QThread>
#include <QString>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include "util/helper.h"

class DBFinisherThread : public QThread
{   
public:
    QString tableName;
    QSqlQuery* query;
    bool emptyRequested;
    DBFinisherThread(QSqlQuery* _query,
                     const QString& _tableName,
                     const bool& _emptyRequested);
    void emptyTable();
    void run();
};

#endif // DBFINISHERTHREAD_H
