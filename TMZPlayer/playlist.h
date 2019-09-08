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
  void updateRow(int);

signals:
  /* Name: changeFilesInListSignal
 * Function: 发射该可视列表的sn和文件信号，匹配对应的sn就可以复制文件过去
 */
  void changeFilesInListSignal(int,QList<QString>);

  /* Name: leftBarListFilesChangeSignal
 * Function: 实现左边列表内容改变时，若displayList的sn指向该列表，则同样发生改变
 */
  void leftBarListFilesChangeSignal(int,QList<QString>);

  /* Name: downloadFilesChangesSignal
   * Function: 发射该可视列表的sn和文件信号，若为下载列表（sn = 0），修改下载文件列表
   */
  void downloadFilesChangesSignal(int,QList<QString>);

  void sendFileAddress(QString);

public slots:

  void on_playlist_customContextMenuRequested(QPoint);

  void addFiles();

  void deleteFileFromList();

  void deleteFileFromDisk();

  void recevingSNAndFiles(int,QList<QString>);

  void showChangedListSlot(int,QList<QString>);

  void cellEntered(int,int);

  void getFileAddress(int,int);

private:

  int currentSN;

  QList<QString> toBeAddedFiles; //挑选出可以添加的文件的临时存储位置

  /* name：QList<QString> temp_filesInList
   * 临时存储指向currentSN的列表的内容本地地址
   */
  QList<QString> temp_filesInList;

  int previousRow;// 鼠标移动过的上一行的行号
  QColor previousRowColor;//存储item之前的颜色
  void setRowColor(int,QColor);

protected:
  void dragEnterEvent(QDragEnterEvent*);
  void dragMoveEvent(QDragMoveEvent*);
  void dropEvent(QDropEvent*);
  void leaveEvent(QEvent *event);


};

#endif // PLAYLIST_H
