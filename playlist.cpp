#include "playlist.h"

#include <QMenu>
#include <QMimeData>
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QDragEnterEvent>
#include <QTableWidgetItem>

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

  connect(this, SIGNAL(customContextMenuRequested(QPoint)),
          this, SLOT(on_playlist_customContextMenuRequested(QPoint)));
}

/* Author: zyt
 * Name: getFileName
 * Function: 将文件路径以文件名称返回
 * Parameters: filePath: 文件路径
 */
QString playList::getFileName(QString filePath)
{
  QFileInfo fileInfo(filePath);
  return fileInfo.fileName();
}

/* Author: zyt
 * Name: on_playlist_customContestMenuRequested
 * Function: 实现在播放列表点击右键出现菜单
 * Parameters: pos（记录点击的位置，使右键菜单在那里出现）
 */
void playList::on_playlist_customContextMenuRequested(QPoint pos)
{
  Q_UNUSED(pos);
  QMenu *pPopMenu = new QMenu(this);
  pPopMenu->addAction("添加文件",this,SLOT(addFiles()));

  //判断右键位置有没有文件
  if (this->currentRow() > -1)
    {
      pPopMenu->addAction("从列表中删除",this,SLOT(deleteFileFromList()));
      pPopMenu->addAction("从电脑中删除",this,SLOT(deleteFileFromDisk()));
    }
  pPopMenu->exec(QCursor::pos());
}

/* Author: zyt
 * Name: addFiles
 * Function: 实现播放列表右键菜单中添加文件的功能
 */
void playList::addFiles()
{
  QFileDialog* selectDialog = new QFileDialog(this);
  selectDialog->setFileMode(QFileDialog::ExistingFiles);
  selectDialog->setNameFilter("音乐文件(*.mp3 *.flac *.wav *.wma);;"
                              "视频文件(*.avi *.mov *.rmvb *.mp4)");
  selectDialog->setViewMode(QFileDialog::Detail);

  QStringList fileNames;
  if ( selectDialog->exec() == QDialog::Accepted )
  {
    fileNames = selectDialog->selectedFiles();
  }

  for (int i = 0;i < fileNames.length(); i++)
  {
    int row = this->rowCount();
    this->insertRow(row);
    QTableWidgetItem *item = new QTableWidgetItem(fileNames.at(i));
    item = new QTableWidgetItem(getFileName(fileNames.at(i)));
    this->setItem(row, 0, item);
    }
}

/* Author: zyt
 * Name: deleteFileFromList
 * Function: 在播放列表中删除选中的文件（从列表中删除）
 */
void playList::deleteFileFromList()
{
  int row = this->currentRow();
  this->removeRow(row);
}

/* Author: zyt
 * Name: deleteFileFromDisk
 * Function: 在播放列表中删除选中的文件（从列表、本地删除）（从磁盘中删除未实现）
 */
void playList::deleteFileFromDisk()
{
  // get path
  int row = this->currentRow();
  QTableWidgetItem *pItem = this->item(row, 0);

  QFile file(pItem->text());
  QMessageBox doubleCheckBox;
  doubleCheckBox.setText("本地文件将删除");
  doubleCheckBox.setInformativeText("确定?");
  doubleCheckBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  doubleCheckBox.setDefaultButton(QMessageBox::Cancel);

  if (doubleCheckBox.exec() == QMessageBox::Ok)
  {
    if (file.remove())
    {
      //文件位置改变，只需要从列表中删除
      this->removeRow(row);
     }
  }
}

