#ifndef MERGEDPLAYLIST_H
#define MERGEDPLAYLIST_H

#include "playlist.h"
#include "playlistbtn.h"

#include <QWidget>
#include <QHeaderView>

class mergedPlaylist : public QWidget
{
  Q_OBJECT
public:
  explicit mergedPlaylist(QWidget *parent = nullptr);
  int getSN();

signals:
  void sendDirSignal(QDir);
  void givingTempSNAndFiles(int,QList<QString>);
  void showChangedListSignal(int,QList<QString>);
  void givingListName(QString);
  void hideContentsExceptThisSignal(int);
  void hideContentSignal();
  void allowDragAndMenuSignal();

public slots:
  void showOrHideListContentSlot(bool);
  void hideOtherContentsSlot(int);
  void recevingTempSN(int);
  void changeFilesInListSlot(int currentSN,QList<QString> temp_filesInList);
  void leftBarListFilesChangeSlot(int,QList<QString>);
  void wantingNameSlot(QString);
  void hideContentSlot();
  void deleteListRequestAnswering();

private:
  playlistBtn* listBtn;
  playList* listContent;
  QList<QString> filesInList;

  static int serialNumber;
  int SN;
};

#endif // MERGEDPLAYLIST_H
