#include "playlist.h"

#include <QDir>
#include <QMenu>
#include <QDebug>
#include <QPixmap>
#include <QPainter>
#include <QMimeData>
#include <QHeaderView>
#include <QFileDialog>
#include <QMessageBox>
#include <QTableWidget>
#include <QDragEnterEvent>
#include <QTableWidgetItem>

/* Author: zyt
 * Name: Playlist
 * Function: 初始化列表
 * Parameters: parent
 */
playList::playList(QWidget *parent) : QTableWidget(parent)
{
  currentSN = -1;
  previousRow = -1;
  previousRowColor = QColor(0x00,0xff,0x00,0x00);
  int temp = this->rowCount();
  QString tempStr = QString::number(temp);

  //允许右键点击事件
  this->setEditTriggers(QAbstractItemView::NoEditTriggers);
  this->setContextMenuPolicy(Qt::CustomContextMenu);

  //允许拖拽文件进入
  this->setAcceptDrops(true);
  setAcceptDrops(true);

  //设置可捕获鼠标移动事件
  this->setMouseTracking(true);

  /* NOTICE:
   * 存放歌曲/视频的tableWidget
   * 第0列是序号
   * 第1列是文件名字
   * 第2列是文件地址
   */
  QStringList headers;
  headers << "" << "名字" << "地址";
  this->setColumnCount(3);
  this->verticalHeader()->hide();
  this->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
  this->horizontalHeader()->setStretchLastSection(true);
  this->setHorizontalHeaderLabels(headers);
  this->setColumnWidth(0,35);
  this->setColumnWidth(1,350);
  this->setColumnWidth(2,100);
  this->setSelectionBehavior(QAbstractItemView::SelectRows);
  this->setSelectionMode(QAbstractItemView::SingleSelection);
  this->setEditTriggers(QAbstractItemView::NoEditTriggers);

  //不显示竖直方向的分割线
  this->setShowGrid(false);

  this->setSelectionBehavior(QAbstractItemView::SelectRows);
  this->setSelectionMode(QAbstractItemView::SingleSelection);

  connect(this, SIGNAL(customContextMenuRequested(QPoint)),
          this, SLOT(on_playlist_customContextMenuRequested(QPoint)));
  connect(this,SIGNAL(cellEntered(int,int)),this,SLOT(cellEntered(int,int)));
  connect(this,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(getFileAddress(int,int)));

  this->setFocusPolicy(Qt::NoFocus);

  this->setStyleSheet("QTableWidget::item:selected { background-color: rgb(198, 241, 255) }");
}

/* Author: zyt
 * Name: leaveEvent
 * Function: 当鼠标离开后，还原该行的颜色
 */
void playList::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);
  QTableWidgetItem *item = nullptr;

  //还原上一行的颜色
  item = this->item(previousRow, 0);
  if (item != nullptr)
    {
      this->setRowColor(previousRow, previousRowColor);
    }
}

/* Author: zyt
 * Name: cellEnter
 * Function: 进入新一行，改变当前行颜色，还原上一行颜色，设置当前行索引以待做为下一次操作的“上一行”
 */
void playList::cellEntered(int row, int column)
{
  QTableWidgetItem *item = nullptr;

  //还原上一行的颜色
  item = this->item(previousRow, 0);
  if (item != nullptr)
    {
      this->setRowColor(previousRow, previousRowColor);
    }

  //设置当前行的颜色
  item = this->item(row, column);
  if (item != nullptr && !item->isSelected())
    {
      this->setRowColor(row, QColor(221,246,255));
    }

  previousRow = row;
}

/* Author: zyt
 * Name: setRowColor
 * Function: 设置row行的背景颜色为color
 */
void playList::setRowColor(int row, QColor color)
{
  for (int col = 0; col < this->columnCount(); col++)
    {
      QTableWidgetItem *item = this->item(row, col);
      item->setBackgroundColor(color);
    }
}

/* Author: zyt
 * Name: getFileAddress
 * Function: 双击单元行时获取该行文件地址
 */
void playList::getFileAddress(int row, int column)
{
  QTableWidgetItem * fileAddressItem = new QTableWidgetItem;
  fileAddressItem = this->item(row,2);
  QString fileAddress = fileAddressItem->text();

  emit sendFileAddress(fileAddress);

  qDebug() << fileAddress;
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
 * Name: setCurrentSN
 * Function: 设置当前列表的SN
 * Parameters: sn:想设置的的序列号
 */
void playList::setCurrentSN(int sn)
{
  currentSN = sn;
}

/* Author: zyt
 * Name: on_playlist_customContestMenuRequested
 * Function: 实现在列表点击右键出现菜单
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
 * Function: 实现列表右键菜单中添加文件的功能
 */
void playList::addFiles()
{
  QFileDialog* selectDialog = new QFileDialog(this);
  selectDialog->setFileMode(QFileDialog::ExistingFiles);
  selectDialog->setNameFilter("所有(*.mp3 *.flac *.wav *.wma *.m4a *.avi *.mov *.rmvb *.mp4);;"
                              "音乐文件(*.mp3 *.flac *.wav *.wma *.m4a);;"
                              "视频文件(*.avi *.mov *.rmvb *.mp4);;");
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

      //以private：QList<QString>存储该列表的文件地址
      temp_filesInList.append(fileNames.at(i));

      //第2列存放地址QString
      QTableWidgetItem *item = new QTableWidgetItem(fileNames.at(i));
      this->setItem(row, 2, item);
      this->item(row, 2)->setFont(QFont("宋体",-1,-1,true));
      this->item(row, 2)->setForeground(QBrush(QColor(105, 105, 105)));

      //第0列存放行数
      int temp = this->rowCount();
      QString tempStr = QString::number(temp);
      item = new QTableWidgetItem(tempStr);//第几行
      this->setItem(row, 0, item);

      //第1列存放名字
      item = new QTableWidgetItem(getFileName(fileNames.at(i)));
      this->setItem(row, 1, item);
    }
  emit changeFilesInListSignal(currentSN,temp_filesInList);
}

/* Author: zyt
 * Name: deleteFileFromList
 * Function: 在列表中删除选中的文件（从列表中删除）
 */
void playList::deleteFileFromList()
{  
  int row = this->currentRow();
  QTableWidgetItem *itemToBeDeleted = this->item(row,2);
  temp_filesInList.removeOne(itemToBeDeleted->text());
  this->removeRow(row);

  //对序号重新排序
  for(int i = 0; i < this->rowCount(); i++)
    {
      int temp = i + 1;
      QString tempStr = QString::number(temp);
      QTableWidgetItem* item = new QTableWidgetItem(tempStr);//第几行
      this->setItem(i, 0, item);
    }

  emit changeFilesInListSignal(currentSN,temp_filesInList);
  emit leftBarListFilesChangeSignal(currentSN,temp_filesInList);
  emit downloadFilesChangesSignal(currentSN,temp_filesInList);
}

/* Author: zyt
 * Name: deleteFileFromDisk
 * Function: 在列表中删除选中的文件（从列表、本地删除）
 */
void playList::deleteFileFromDisk()
{
  // get path
  int row = this->currentRow();
  QTableWidgetItem *itemToBeDeleted = this->item(row, 2);

  QFile file(itemToBeDeleted->text());
  QMessageBox doubleCheckBox;
  doubleCheckBox.setText("本地文件将被永久删除");
  doubleCheckBox.setInformativeText("确定?");
  doubleCheckBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  doubleCheckBox.setDefaultButton(QMessageBox::Cancel);

  if (doubleCheckBox.exec() == QMessageBox::Ok)
    {
      if(file.exists())
        {
          if (file.remove())
            {
              this->removeRow(row);
            }
        }
      else if(!file.exists())
        {
          QMessageBox noticeBox(QMessageBox::NoIcon, "提示", "      文件位置已被移动");
          QPixmap hintBoxPixmap(":/image/image/test.png");
          noticeBox.setIconPixmap(hintBoxPixmap.scaled(80,80));
          noticeBox.exec();
          this->removeRow(row);
        }
      temp_filesInList.removeOne(itemToBeDeleted->text());
    }

  //对序号重新排序
  for(int i = 0; i < this->rowCount(); i++)
    {
      int temp = i + 1;
      QString tempStr = QString::number(temp);
      QTableWidgetItem* item = new QTableWidgetItem(tempStr);//第几行
      this->setItem(i, 0, item);
    }

  emit changeFilesInListSignal(currentSN,temp_filesInList);
  emit leftBarListFilesChangeSignal(currentSN,temp_filesInList);
}

/* Author: zyt
 * Name: recivingSN
 * Function: 槽：获取点击按钮（列表）对应的序列号，绑定该列表与屏幕中的显示列表
 * Parameters: sn：获取到的sn
 */
void playList::recevingSNAndFiles(int sn,QList<QString> files)
{
  //清空列表显示内容
  int row = this->rowCount();
  for(int i = 0; i < row; i++)
    {
      this->removeRow(0);
    }
  temp_filesInList.clear();

  currentSN = sn;

  for (int i = 0;i < files.length(); i++)
    {
      int row = this->rowCount();
      this->insertRow(row);

      //以private：QList<QString>存储该列表的文件地址
      temp_filesInList.append(files.at(i));

      //第2列存放地址QString
      QTableWidgetItem *item = new QTableWidgetItem(files.at(i));
      this->setItem(row, 2, item);
      this->item(row, 2)->setFont(QFont("宋体",-1,-1,true));
      this->item(row, 2)->setForeground(QBrush(QColor(105, 105, 105)));

      //第0列存放行数
      int temp = this->rowCount();
      QString tempStr = QString::number(temp);
      item = new QTableWidgetItem(tempStr);//第几行
      this->setItem(row, 0, item);

      //第1列存放名字
      item = new QTableWidgetItem(getFileName(files.at(i)));
      this->setItem(row, 1, item);
    }
}

/* Author: zyt
 * Name: showChangedListSlot
 * Function: 槽：修改左侧播放列表时，若displayList的currentSN为修改列表的SN
 *              则更新displayList内容
 */
void playList::showChangedListSlot(int sn, QList<QString> files)
{
  if(currentSN == sn)
    {
      //清空列表显示内容
      int row = this->rowCount();
      for(int i = 0; i < row; i++)
        {
          this->removeRow(0);
        }
      temp_filesInList.clear();

      for (int i = 0;i < files.length(); i++)
        {
          int row = this->rowCount();
          this->insertRow(row);

          //以private：QList<QString>存储该列表的文件地址
          temp_filesInList.append(files.at(i));

          //第2列存放地址QString
          QTableWidgetItem *item = new QTableWidgetItem(files.at(i));
          this->setItem(row, 2, item);
          this->item(row, 2)->setFont(QFont("宋体",-1,-1,true));
          this->item(row, 2)->setForeground(QBrush(QColor(105, 105, 105)));

          //第0列存放行数
          int temp = this->rowCount();
          QString tempStr = QString::number(temp);
          item = new QTableWidgetItem(tempStr);//第几行
          this->setItem(row, 0, item);

          //第1列存放名字
          item = new QTableWidgetItem(getFileName(files.at(i)));
          this->setItem(row, 1, item);
        }
    }
}

/* Author: zyt
 * Name: dragEnterEvent
 * Function: 实现拖拽文件进入列表——识别是否可以拖入
 */
void playList::dragEnterEvent(QDragEnterEvent *event)
{
  QStringList acceptedTypes;
  acceptedTypes << "mp3" << "flac" << "wav" << "wma" << "m4a"
                << "avi" << "mov" << "rmvb" << "mp4";
  if (event->mimeData()->hasUrls())
    {
      QList<QUrl> fileUrls = event->mimeData()->urls();

      for (int i = 0; i < fileUrls.length(); i++)
        {
          QFileInfo file(event->mimeData()->urls().at(i).toLocalFile());
          if(acceptedTypes.contains(file.suffix().toLower()))
            {
              if(!temp_filesInList.contains(fileUrls.at(i).toLocalFile()))
                {
                  toBeAddedFiles.append(fileUrls.at(i).toLocalFile());
                }
            }
        }
      event->acceptProposedAction();
    }
}

/* Author: zyt
 * Name: dragMoveEvent
 * Function: 无功能，如果不重写将导致拖拽添加文件失败，亲测
 */
void playList::dragMoveEvent(QDragMoveEvent *event)
{
  Q_UNUSED(event);
  //do nothing
}

/* Author: zyt
 * Name: dropEvent
 * Function: 实现拖拽文件进入列表后的添加文件操作
 */
void playList::dropEvent(QDropEvent *event)
{
  Q_UNUSED(event);

  if (!toBeAddedFiles.empty())
    {
      for (int i = 0;i < toBeAddedFiles.length();i++)
        {
          int row = this->rowCount();
          this->insertRow(row);

          //以private：QList<QString>存储该列表的文件地址
          temp_filesInList.append(toBeAddedFiles.at(i));

          //第2列存放地址QString
          QTableWidgetItem *item = new QTableWidgetItem(toBeAddedFiles.at(i));
          this->setItem(row, 2, item);
          this->item(row, 2)->setFont(QFont("宋体",-1,-1,true));
          this->item(row, 2)->setForeground(QBrush(QColor(105, 105, 105)));

          //第0列存放行数
          int temp = this->rowCount();
          QString tempStr = QString::number(temp);
          item = new QTableWidgetItem(tempStr);//第几行
          this->setItem(row, 0, item);

          //第1列存放名字
          item = new QTableWidgetItem(getFileName(toBeAddedFiles.at(i)));
          this->setItem(row, 1, item);
        }

    }
  else if (toBeAddedFiles.empty())
    {
      QMessageBox hintBox(QMessageBox::NoIcon, "提示", "      请拖入有效文件");
      QPixmap hintBoxPixmap(":/image/image/test.png");
      hintBox.setIconPixmap(hintBoxPixmap.scaled(80,80));
      hintBox.exec();
    }

  toBeAddedFiles.clear();

  emit changeFilesInListSignal(currentSN,temp_filesInList);
  emit leftBarListFilesChangeSignal(currentSN,temp_filesInList);
}


