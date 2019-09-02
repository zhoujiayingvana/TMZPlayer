#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <QDir>
#include <QWidget>
#include <QPushButton>
#include <QListWidget>
#include <QTableWidget>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QStringListModel>


class playList : public QTableWidget
{
  Q_OBJECT
public:
  explicit playList(QWidget *parent = nullptr);

  QString getFileName(QString file_path);

signals:
  void sendDirSignal(QDir);

public slots:

  void on_playlist_customContextMenuRequested(QPoint);

  void addFiles();

  void deleteFileFromList();

  void deleteFileFromDisk();

private:

  QList<QString> toBeAddedFiles; //挑选出可以添加的文件的临时存储位置
  QPushButton* likeBtn;

protected:
  void dragEnterEvent(QDragEnterEvent*);
  void dragMoveEvent(QDragMoveEvent*);
  void dropEvent(QDropEvent*);

};

#endif // PLAYLIST_H
