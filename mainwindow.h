#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "mini.h"

#include <QAction>
#include <QWidget>
#include <QTableWidget>
#include <QSystemTrayIcon>
#include <QStringListModel>
#include <QStandardItemModel>

namespace Ui {
  class mainWindow;
}

class mainWindow : public QWidget
{
  Q_OBJECT

public:
  explicit mainWindow(QWidget *parent = nullptr);
  bool whetherInitializeListButton();
  ~mainWindow();

  void creatActions();
  void creatMenu();
  QString getFileName(QString);

private:
  Ui::mainWindow *ui;
  bool whetherHide = false;

  QMenu *sysTrayMenu;
  QSystemTrayIcon *sysTrayIcon;

  //托盘的功能
  QAction* exitAction;
  QAction* settingAction;
  QAction* lastSongAction;
  QAction* nextSongAction;
  QAction* showStatusAction;
  QAction* playOrPauseAction;
  QAction* whetherShowLyricAction;
  QAction* whetherLockLyricAction;

  QMenu* playOrderMenu;
  QAction* playOrder_orderAction; //顺序播放
  QAction* playOrder_repeatAction; //重复播放
  QAction* playOrder_shuffleAction; //随机播放
  QAction* playOrder_listOrderAction; //列表循环

  QMenu* displayModeMenu;
  QAction* displayMode_maxAction;
  QAction* displayMode_miniAction;
  QAction* displayMode_trayAction;

  bool isPlaying;

  Mini* mini;

private slots:

  void on_addListBtn_clicked();

  void on_hideBtn_clicked();

  void on_showBtn_clicked();

  void on_systemTrayModeBtn_clicked();

  void on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason);

  void on_showMainAction();

  void on_playOrPauseAction();

  void on_displayMode_maxAction();

  void on_displayMode_miniAction();

  void on_exitAction();

  void on_playlist_customContextMenuRequested(const QPoint &pos);

  void addFiles();

  void deleteFileFromList();

  void deleteFileFromDisk();

  void on_miniMode_clicked();

  void switchToMax();


protected:

};

#endif // MAINWINDOW_H
