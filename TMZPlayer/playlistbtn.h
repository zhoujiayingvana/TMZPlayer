/* Author: zyt
 * playlistBtn类：主要实现每个播放列表上面的列表名字的修改/图标的切换
 *                及点击显示/隐藏列表
 */

#ifndef PLAYLISTBTN_H
#define PLAYLISTBTN_H

#include <QTimer>
#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

#include "newLineEdit.h"

class QTimer;

class playlistBtn : public QPushButton
{
  Q_OBJECT
public:
  explicit playlistBtn(int sn, QWidget *parent = nullptr);
  int getSN();
  bool getIsClicked();
  void setIsClicked(bool);

signals:
  void showOrHideListContentSignal(bool);
  void hideOtherContentsSignal(int);
  void deleteListRequest();
  void singleClickedSignal();
  void doubleClickedSignal();
  void givingSN(int);
  void wantingName(QString);

public slots:
  void renameSlot();
  void deleteListSlot();
  void showListSlot();
  void hideContentSlot();
  void displayListSlot();
  void editingFinishedSlot();
  void listNameCallMenuSlot(QPoint);
  void doubleClickedSlot();

private:
  bool isClicked;
  QLabel* statusPix;
  newLineEdit* listName;
  int btn_SN;

  bool doubleClicked;
  QTimer* singleClickedTimer;

protected:
  void mousePressEvent(QMouseEvent*);
  void contextMenuEvent(QContextMenuEvent*);
  bool event(QEvent*); //单击双击识别
};

#endif // PLAYLISTBTN_H
