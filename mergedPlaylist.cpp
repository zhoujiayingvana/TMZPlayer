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

  QVBoxLayout* playlistLayout = new QVBoxLayout;
  playlistLayout->addWidget(listBtn);
  playlistLayout->addWidget(listContent);
  playlistLayout->setAlignment(Qt::AlignTop);
  this->setLayout(playlistLayout);

  connect(listBtn,SIGNAL(showOrHideListContentSignal(bool)),
          this,SLOT(showOrHideListContentSlot(bool)));

  connect(listContent,SIGNAL(changeFilesInListSignal(int,QList<QString>)),
          this,SLOT(changeFilesInListSlot(int,QList<QString>)));
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
 * Name: changeFilesInListSlot
 * Function: 更新对应sn的文件列表
 */
void mergedPlaylist::changeFilesInListSlot(int currentSN, QList<QString> temp_filesInList)
{
  if(currentSN == SN)
    {
      filesInList = temp_filesInList;
    }
}
