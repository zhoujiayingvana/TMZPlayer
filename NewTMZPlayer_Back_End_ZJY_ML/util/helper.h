#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlError>
#include <QDebug>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);
    static bool createDatabase(const QString& _databaseName="Retina.db");
signals:

public slots:

private:
    static void testShowAll(const QString& _databaseName="Retina.db");
};

#endif // HELPER_H
