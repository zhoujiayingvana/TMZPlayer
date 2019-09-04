#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "playlistbtn.h"

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
  void setCurrentSN(int);

signals:
  void sendDirSignal(QDir);

/* Name: changeFilesInListSignal
 * Function: 发射该可视列表的sn和文件信号，匹配对应的sn就可以复制文件过去
 */
  void changeFilesInListSignal(int sn,QList<QString> filesList);


public slots:

  void on_playlist_customContextMenuRequested(QPoint);

  void addFiles();

  void deleteFileFromList();

  void deleteFileFromDisk();

  void recevingSNAndFiles(int,QList<QString>);


private:
  int currentSN;
  QList<QString> toBeAddedFiles; //挑选出可以添加的文件的临时存储位置

  /* name：QList<QString> temp_filesInList
   * 临时存储指向currentSN的列表的内容本地地址
   */
  QList<QString> temp_filesInList;

  QPushButton* likeBtn; //没做

protected:
  void dragEnterEvent(QDragEnterEvent*);
  void dragMoveEvent(QDragMoveEvent*);
  void dropEvent(QDropEvent*);

};

#endif // PLAYLIST_H
