#ifndef MERGEDPLAYLIST_H
#define MERGEDPLAYLIST_H

#include "playlist.h"
#include "playlistbtn.h"

#include <QWidget>

class mergedPlaylist : public QWidget
{
  Q_OBJECT
public:
  playlistBtn* listBtn;
  explicit mergedPlaylist(QWidget *parent = nullptr);

signals:
  void givingSN(int);

public slots:
  void showOrHideListContentSlot(bool);
  void changeFilesInListSlot(int currentSN,QList<QString> temp_filesInList);

private:
  playList* listContent;
  QList<QString> filesInList;

  static int serialNumber;
  int SN;
};

#endif // MERGEDPLAYLIST_H
