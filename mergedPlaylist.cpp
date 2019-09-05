#include "mergedPlaylist.h"

#include <QDebug>
#include <QVBoxLayout>

/* Parameter: serialNumber
 * Function: 新建每个列表的时候都会生成一个独一无二的序列号
 * 根据序列号来分辨存储在主界面中的不同列表
 */
int mergedPlaylist::serialNumber = 0;

mergedPlaylist::mergedPlaylist(QWidget *parent) : QWidget(parent)
{
  serialNumber++;
  SN = serialNumber;

  listBtn = new playlistBtn(SN,this);
  listBtn->setFixedWidth(240);
  listContent = new playList(this);
  listContent->setVisible(false);

  listContent->setCurrentSN(SN);

  listContent->setColumnHidden(1,false);
  listContent->setColumnHidden(3,false);

  QVBoxLayout* playlistLayout = new QVBoxLayout;
  playlistLayout->addWidget(listBtn);
  playlistLayout->addWidget(listContent);
  playlistLayout->setAlignment(Qt::AlignTop);
  this->setLayout(playlistLayout);

  connect(listBtn,SIGNAL(showOrHideListContentSignal(bool)),
          this,SLOT(showOrHideListContentSlot(bool)));

  connect(listContent,SIGNAL(changeFilesInListSignal(int,QList<QString>)),
          this,SLOT(changeFilesInListSlot(int,QList<QString>)));

  connect(listBtn,SIGNAL(givingSN(int)),this,SLOT(recevingTempSN(int)));

  connect(listContent,SIGNAL(leftBarListFilesChangeSignal(int,QList<QString>)),
          this,SLOT(leftBarListFilesChangeSlot(int,QList<QString>)));

  connect(listBtn,SIGNAL(wantingName(QString)),this,SLOT(wantingNameSlot(QString)));

}

/* Author: zyt
 * Name: showOrHideListContentSignal
 * Function: 槽：根据点击情况显示/隐藏列表
 * Parameters: bool isClicked:是否点击了显示/隐藏列表按钮
 *             true:点击了显示 / false:点击了隐藏
 */
void mergedPlaylist::showOrHideListContentSlot(bool isClicked)
{
  if(isClicked)
    {
      listContent->setVisible(true);
    }
  else if(!isClicked)
    {
      listContent->setVisible(false);
    }
}

/* Author: zyt
 * Name: recevingTempSN
 * Function: 槽：点击按钮的时候发送一个序列号，先由包含按钮的类接收信号，再由其发送给mainWindow内的displayList
 */
void mergedPlaylist::recevingTempSN(int sn)
{
  emit givingTempSNAndFiles(sn,filesInList);
}

/* Author: zyt
 * Name: changeFilesInListSlot
 * Function: 更新对应sn的文件列表
 */
void mergedPlaylist::changeFilesInListSlot(int currentSN, QList<QString> temp_filesInList)
{
  if(currentSN == SN)
    {
      filesInList = temp_filesInList;

      //清空列表显示内容
      int row = listContent->rowCount();
      for(int i = 0; i < row; i++)
        {
          listContent->removeRow(0);
        }

      for (int i = 0;i < filesInList.length(); i++)
        {
          int row = listContent->rowCount();
          listContent->insertRow(row);

          //第0列存放地址QString
          QTableWidgetItem *item = new QTableWidgetItem(filesInList.at(i));
          listContent->setItem(row, 0, item);

          //第1列存放行数
          int temp = listContent->rowCount();
          QString tempStr = QString::number(temp);
          item = new QTableWidgetItem(tempStr);//第几行
          listContent->setItem(row, 1, item);

          //第2列存放名字
          item = new QTableWidgetItem(listContent->getFileName(filesInList.at(i)));
          listContent->setItem(row, 2, item);
        }

    }
}

/* Author: zyt
 * Name: leftBarListFilesChangeSlot
 * Function: 接收到左边列表文件改变信号，并且发出一个信号，给displayList
 *           若displayList的currentSN与此一致
 *           则更新displayList内容
 */
void mergedPlaylist::leftBarListFilesChangeSlot(int sn, QList<QString> files)
{
  emit showChangedListSignal(sn,files);
}

/* Author: zyt
 * Name: wantingNameSLot
 * Function: 槽：发射包含该列表名字的信号
 */
void mergedPlaylist::wantingNameSlot(QString name)
{
  emit givingListName(name);
}
