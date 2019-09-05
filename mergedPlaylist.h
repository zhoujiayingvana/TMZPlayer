#ifndef MERGEDPLAYLIST_H
#define MERGEDPLAYLIST_H

#include "playlist.h"
#include "playlistbtn.h"

#include <QWidget>

class mergedPlaylist : public QWidget
{
  Q_OBJECT
public:
  explicit mergedPlaylist(QWidget *parent = nullptr);

signals:
  void givingTempSNAndFiles(int,QList<QString>);
  void showChangedListSignal(int,QList<QString>);
  void givingListName(QString);

public slots:
  void showOrHideListContentSlot(bool);
  void recevingTempSN(int);
  void changeFilesInListSlot(int currentSN,QList<QString> temp_filesInList);
  void leftBarListFilesChangeSlot(int,QList<QString>);
  void wantingNameSlot(QString);

private:
  playlistBtn* listBtn;
  playList* listContent;
  QList<QString> filesInList;

  static int serialNumber;
  int SN;
};

#endif // MERGEDPLAYLIST_H
