#include "foldershandler.h"
#include "util/folders.h"

FoldersIniter::FoldersIniter(Folders* _folders)
    : folders(_folders)
{

}

void FoldersIniter::run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(this->folders->getUserName()));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QSqlQuery query(db);
    // 首先应该执行读取所有收藏夹
    QString sqlString("SELECT folderName, rank FROM folders WHERE fileName IS NULL ORDER BY rank ASC");
    if (!query.exec(sqlString))
    {
        qDebug() << query.lastError().text();
        return ;
    }
    while (query.next())
    {
        QString* folderName = (QString*)query.value("folderName").data();
        this->folders->addNewFolder(*folderName);
    }
    // 然后应该按顺序读取完成所有的收藏夹中的文件
    sqlString = "SELECT fileName, filePath, isLocal, rank FROM folders WHERE folderName = '%1' AND fileName IS NOT NULL ORDER BY rank";
    for (QString folderName: this->folders->getFolderNames())
    {
        QString tempSqlString = sqlString.arg(folderName);
        if (!query.exec(tempSqlString))
        {
            qDebug() << query.lastError().text();
            break;
        }
        while (query.next())
        {
            QString* fileName = (QString*)query.value("fileName").data();
            QString* filePath = (QString*)query.value("filePath").data();
            int* isLocal = (int*)query.value("isLocal").data();
            this->folders->addContent2Folder(folderName, *fileName, *filePath, *isLocal);
        }
    }
    db.close();
}

void FoldersHandler::insertFolder2Database(const QString& _userName,
                                        const QString& _folderName,
                                        const int& _rank)
{
    if (_rank < 0)
        throw MyErrors::DB_PARAM_ERROR;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(_userName));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QString sqlString(
        "INSERT INTO folders (folderName, fileName, filePath, isLocal, rank)"
        "VALUES ('%1', NULL, NULL, NULL, %2);"
    );
    sqlString = sqlString.arg(_folderName).arg(_rank);
    QSqlQuery sqlQuery(db);
    if (!sqlQuery.exec(sqlString))
    {
        qDebug() << sqlQuery.lastError().text();
        return;
    }
    db.close();
}

void FoldersHandler::insertContent2Database(const QString& _userName,
                                         const QString& _folderName,
                                         const QString& _fileName,
                                         const QString& _filePath,
                                         const int& _isLocal, const int& _rank)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(_userName));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QString sqlString(
        "INSERT INTO folders (folderName, fileName, filePath, isLocal, rank)"
        "VALUES ('%1', '%2', '%3', %4, %5);"
    );
    sqlString =
            sqlString.arg(_folderName).arg(_fileName).arg(_filePath).arg(_isLocal).arg(_rank);
    QSqlQuery sqlQuery(db);
    if (!sqlQuery.exec(sqlString))
    {
        qDebug() << sqlQuery.lastError().text();
        return;
    }
    db.close();
}

void FoldersHandler::insertContent2Database(const QString& _userName,
                                         const FolderContent* _folderContent)
{
    const QString _folderName = _folderContent->getFolderName();
    const QString _fileName = _folderContent->getFileName();
    const QString _filePath = _folderContent->getFilePath();
    const int _isLocal = (int)_folderContent->getIsLocal();
    const int _rank = _folderContent->getRank();
    FoldersHandler::insertContent2Database(_userName,
                                        _folderName, _fileName, _filePath,
                                        _isLocal, _rank);
}

void FoldersHandler::deleteContentFromDatabase(const QString& _userName,
                                               const QString& _folderName,
                                               const int& _rank)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(_userName));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QString sqlString(
        "DELETE FROM folders"
        " WHERE folderName = '%1' AND fileName IS NOT NULL AND rank = %2"
    );
    sqlString = sqlString.arg(_folderName).arg(_rank);
    QSqlQuery sqlQuery(db);
    if (!sqlQuery.exec(sqlString))
    {
        qDebug() << sqlQuery.lastError().text();
        return;
    }
    db.close();
}

void FoldersHandler::deleteFolderFromDatabase(const QString& _userName,
                                              const QString& _folderName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(_userName));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    QString sqlString(
        "DELETE FROM folders WHERE folderName = '%1'"
    );
    sqlString = sqlString.arg(_folderName);
    QSqlQuery sqlQuery(db);
    if (!sqlQuery.exec(sqlString))
    {
        qDebug() << sqlQuery.lastError().text();
        return;
    }
    db.close();
}

FoldersCloser::FoldersCloser(Folders* _folders)
    : folders(_folders)
{

}

void FoldersCloser::run()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    const QString userName = this->folders->getUserName();
    db.setDatabaseName(QString("../user/%1.db").arg(userName));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        return ;
    }
    // 清空整张表
    QString sqlString("DELETE FROM folders");
    QSqlQuery sqlQuery(db);
    if (!sqlQuery.exec(sqlString))
    {
        qDebug() << sqlQuery.lastError().text();
        return;
    }
    // 全部写回
    QMapIterator<QString, int> iter(*this->folders->getFolderName2Index());
    while (iter.hasNext())
    {
        iter.next();
        const QString folderName = iter.key();
        const int rank = iter.value();
        FoldersHandler::insertFolder2Database(userName, folderName, rank);
        Folder folder = this->folders->getFolder(rank);
        QList<FolderContent> folderContents = folder.getFolderContents();
        for (FolderContent folderContent: folderContents)
            FoldersHandler::insertContent2Database(userName, &folderContent);
    }
    db.close();
}
