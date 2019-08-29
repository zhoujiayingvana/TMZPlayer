#include "playlist.h"

#include <QMenu>
#include <QMimeData>
#include <QHeaderView>
#include <QFileDialog>
#include <QTableWidget>
#include <QDragEnterEvent>

/* Author: zyt
 * Name: Playlist
 * Function: 初始化播放列表
 * Parameters: parent
 */
playList::playList(QWidget *parent) : QTableWidget(parent)
{
  //允许右键点击事件
  this->setEditTriggers(QAbstractItemView::NoEditTriggers);
  this->setContextMenuPolicy(Qt::CustomContextMenu);

  //设置表头
  QStringList headers;
  headers<<"文件"<<"表演者"<<"专辑";
  this->setColumnCount(3);
  this->verticalHeader()->hide();
  this->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
  this->horizontalHeader()->setStretchLastSection(true);
  this->setHorizontalHeaderLabels(headers);
  this->setColumnWidth(0,250);
  this->setColumnWidth(1,250);
  this->setSelectionBehavior(QAbstractItemView::SelectRows);
  this->setSelectionMode(QAbstractItemView::SingleSelection);
  this->setEditTriggers(QAbstractItemView::NoEditTriggers);

  //不显示竖直方向的分割线
  this->setShowGrid(false);

}


