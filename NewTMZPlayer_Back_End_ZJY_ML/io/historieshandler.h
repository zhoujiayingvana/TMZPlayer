#ifndef HISTORIESREADER_H
#define HISTORIESREADER_H

#include <QThread>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include "util/historicalcontent.h"

class Histories;

class HistoriesHandler : public QThread
{
public:
    HistoriesHandler();
    static void addContent2Database(const QString& _userName, const HistoricalContent& historicalContent);
};

class HistoriesIniter: public QThread
{
protected:
    Histories* histories;
public:
    HistoriesIniter(Histories* _histories=nullptr);
    void run();
};

class HistoriesCloser: public QThread
{
protected:
    Histories* histories;
public:
    HistoriesCloser(Histories* _histories=nullptr);
    void run();
};

#endif // HISTORIESREADER_H
