#include "playlistbtn.h"
#include "newLineEdit.h"

#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QKeyEvent>
#include <QMouseEvent>
#include <QContextMenuEvent>

/* Parameter: serialNumber
 * Function: 新建每个列表的时候都会生成一个独一无二的序列号
 * 根据序列号来分辨存储在主界面中的不同列表
 */
int playlistBtn::serialNumber = 0;

/* Author: zyt
 * playlistBtn类：主要实现每个播放列表上面的列表名字的修改/图标的切换
 *               点击显示/隐藏列表
 *               发送序列号
 * Function: 初始化
 */
playlistBtn::playlistBtn(QWidget *parent) : QPushButton(parent)
{
  serialNumber++;
  SN = serialNumber;

  isClicked = false;

  this->setStyleSheet("QPushButton {background-color : white; }");

  statusPix = new QLabel(this);
  statusPix->setFixedSize(17,17);
  statusPix->setScaledContents(true);
  statusPix->setPixmap(QPixmap(":/image/image/btn_down_n.png"));
  statusPix->move(0,0);

  listName = new newLineEdit(this);
  listName->setText("新建列表");
  listName->setFixedHeight(17);
  listName->move(17,0);
  listName->setReadOnly(true);
  listName->setToolTip(listName->text());
  listName->setStyleSheet("QLineEdit {border-width: 0;"
                          "border-style:outset; };");

  connect(listName,SIGNAL(listNameClickedSignal()),this,SLOT(showListSlot()));
  connect(listName,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(listNameCallMenuSlot(QPoint)));
  connect(listName,SIGNAL(editingFinished()),this,SLOT(editingFinishedSlot()));
}

/* Author: zyt
 * Name: getSN
 * Function: 获取序列号
 * Return: 序列号（int）
 */
int playlistBtn::getSN()
{
  return SN;
}

/* Author: zyt
 * Name: contextMenuEvent
 * Function: 实现右键播放列表表头进行改名
 */
void playlistBtn::contextMenuEvent(QContextMenuEvent *event)
{
  QMenu *menu = new QMenu;
  QAction *rename = menu->addAction("修改列表名称");
  QAction *deleteList = menu->addAction("删除列表");

  connect(rename,SIGNAL(triggered()),this,SLOT(renameSlot()));
  connect(deleteList,SIGNAL(triggered()),this,SLOT(deleteListSlot()));

  menu->exec(event->globalPos());

}

/* Author: zyt
 * Name: renameSlot
 * Function: 槽：实现列表改名
 */
void playlistBtn::renameSlot()
{
  listName->setReadOnly(false);
}

/* Author: zyt
 * Name: deleteListSlot
 * Function: 槽：删除列表
 */
void playlistBtn::deleteListSlot()
{
  emit deleteListRequest();
}

/* Author: zyt
 * Name: showListSlot
 * Function: 实现点击列表名字（lineEdit）的时候也能响应mousePressEvent
 */
void playlistBtn::showListSlot()
{
  isClicked = !isClicked;
  if(isClicked)
    {
      statusPix->setPixmap(QPixmap(":/image/image/btn_down_n.png"));
      emit showOrHideListContentSignal(isClicked);
      emit givingSN(getSN());
    }
  else if(!isClicked)
    {
      statusPix->setPixmap(QPixmap(":/image/image/btn_right_1_n.png"));
      emit showOrHideListContentSignal(isClicked);
    }
}

/* Author: zyt
 * Name: editingFinishedSlot
 * Function: 当编辑播放列表名字出现输入回车或失去焦点时，使名字变为只读
 */
void playlistBtn::editingFinishedSlot()
{
  listName->setReadOnly(true);
}

/* Author: zyt
 * Name: listNameCallMenuSlot
 * Function: 实现右键播放列表名字的时候也能出现对应的右键菜单，而不是复制粘贴等
 */
void playlistBtn::listNameCallMenuSlot(QPoint pos)
{
  Q_UNUSED(pos);
  QMenu *menu = new QMenu;
  QAction *rename = menu->addAction("修改列表名称");
  QAction *deleteList = menu->addAction("删除列表");

  connect(rename,SIGNAL(triggered()),this,SLOT(renameSlot()));

  menu->exec(QCursor::pos());
}

/* Author: zyt
 * Name: mousePressEvent
 * Function: 点击列表名显示/隐藏列表，改变图标（向左/向下)
 */
void playlistBtn::mousePressEvent(QMouseEvent *event)
{
  Q_UNUSED(event);
  if(event->button() == Qt::LeftButton)
    {
      isClicked = !isClicked;
      if(isClicked)
        {
          statusPix->setPixmap(QPixmap(":/image/image/btn_down_n.png"));
          emit showOrHideListContentSignal(isClicked);
          emit givingSN(getSN());
        }
      else if(!isClicked)
        {
          statusPix->setPixmap(QPixmap(":/image/image/btn_right_1_n.png"));
          emit showOrHideListContentSignal(isClicked);
        }
    }
}
