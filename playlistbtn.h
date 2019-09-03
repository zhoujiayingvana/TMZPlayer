/* Author: zyt
 * playlistBtn类：主要实现每个播放列表上面的列表名字的修改/图标的切换
 *                及点击显示/隐藏列表
 */

#ifndef PLAYLISTBTN_H
#define PLAYLISTBTN_H

#include <QLabel>
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>

#include "newLineEdit.h"


class playlistBtn : public QPushButton
{
  Q_OBJECT
public:
  explicit playlistBtn(QWidget *parent = nullptr);
  int getSN();

signals:
  void showOrHideListContentSignal(bool);
  void deleteListRequest();
  void singleClickedSignal();
  void doubleClickedSignal();
  void givingSN(int);

public slots:
  void renameSlot();
  void deleteListSlot();
  void showListSlot();
  void editingFinishedSlot();
  void listNameCallMenuSlot(QPoint);

private:
  static int serialNumber;
  int SN;

  bool isClicked;
  QLabel* statusPix;
  newLineEdit* listName;
  QList<QString> filesInList;

protected:
  void mousePressEvent(QMouseEvent*);
  void contextMenuEvent(QContextMenuEvent*);
};

#endif // PLAYLISTBTN_H
