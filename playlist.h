#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QWidget>
#include <QListWidget>
#include <QTableWidget>
#include <QStringListModel>

class playList : public QTableWidget
{
  Q_OBJECT
public:
  explicit playList(QWidget *parent = nullptr);

signals:

public slots:

private:

};

#endif // PLAYLIST_H
