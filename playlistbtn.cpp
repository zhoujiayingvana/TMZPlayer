#include "playlistbtn.h"
#include "newLineEdit.h"

#include <QMenu>
#include <QDebug>
#include <QEvent>
#include <QAction>
#include <QKeyEvent>
#include <QVBoxLayout>
#include <QMouseEvent>
#include <QContextMenuEvent>

/* Author: zyt
 * playlistBtn类：主要实现每个播放列表上面的列表名字的修改/图标的切换
 *               点击显示/隐藏列表
 *               发送序列号
 *               进行pushButton识别单击/双击的信号连接
 * Function: 初始化
 * Parameter: 从mergedPlaylist继承过来的SN，这一步使得无论是mergedPlaylist还是playlistBtn自己
 *            都有统一的序列号，便于分辨和操作
 */
playlistBtn::playlistBtn(int sn,QWidget *parent) : QPushButton(parent)
{
  doubleClicked = false;
  singleClickedTimer = new QTimer(this);
  singleClickedTimer->setSingleShot(true);
  connect(singleClickedTimer,SIGNAL(timeout()),this,SIGNAL(singleClickedSignal()));
  connect(this,SIGNAL(singleClickedSignal()),this,SLOT(singleClickedSlot()));
  connect(this,SIGNAL(doubleClickedSignal()),this,SLOT(doubleClickedSlot()));

  btn_SN = sn;
  isClicked = false;

  this->setStyleSheet("QPushButton {background-color : white; }");

  statusPix = new QLabel(this);
  statusPix->setFixedSize(17,17);
  statusPix->setScaledContents(true);
  statusPix->setPixmap(QPixmap(":/image/image/btn_right_1_n.png"));
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
  return btn_SN;
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
 * Name: event
 * Function: 识别单击/双击按钮
 */
bool playlistBtn::event(QEvent *event)
{
  switch ( event->type() )
    {
    case QEvent::MouseButtonRelease:
      if(doubleClicked)
        {
          singleClickedTimer->start(10);
        }
      else
        {
          doubleClicked = false;
        }
      break;
    case QEvent::MouseButtonDblClick:
      singleClickedTimer->stop();
      doubleClicked = true;
      emit doubleClickedSignal();
      break;
    default:
      break;
    }
  return QPushButton::event(event);
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
 * Name: singleCilckedSlot
 * Function: 槽：识别单击后什么都不做
 */
void playlistBtn::singleClickedSlot()
{
  // do nothing
}

/* Author: zyt
 * Name: doubleClickedSlot
 * Function: 槽：识别双击后将该列表内容显示在右侧的displayList内
 */
void playlistBtn::doubleClickedSlot()
{
  emit givingSN(getSN());
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
        }
      else if(!isClicked)
        {
          statusPix->setPixmap(QPixmap(":/image/image/btn_right_1_n.png"));
          emit showOrHideListContentSignal(isClicked);
        }
    }
}
