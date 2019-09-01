#include "helper.h"

Helper::Helper(QObject *parent) : QObject(parent)
{

}

bool Helper::createDatabase(const QString& _databaseName)
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
        int what = *(int*)query.value("id").data();
        QString words = *(QString*)query.value("fileName").data();
        qDebug() << what << words << endl;
    }
    db.close();
}
