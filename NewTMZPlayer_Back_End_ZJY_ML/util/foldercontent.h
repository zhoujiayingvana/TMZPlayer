#ifndef FOLDERCONTENT_H
#define FOLDERCONTENT_H

#include <QObject>

class FolderContent : public QObject
{
    Q_OBJECT
public:
    explicit FolderContent(QObject *parent = nullptr);

signals:

public slots:
};

#endif // FOLDERCONTENT_H
