#include "mergedPlaylist.h"

#include <QVBoxLayout>

mergedPlaylist::mergedPlaylist(QWidget *parent) : QWidget(parent)
{
   QVBoxLayout* playlistLayout = new QVBoxLayout;
   listBtn = new playlistBtn(this);
   listContent = new playList(this);
   listBtn->setFixedWidth(240);

   playlistLayout->addWidget(listBtn);
   playlistLayout->addWidget(listContent);
   playlistLayout->setAlignment(Qt::AlignTop);
   this->setLayout(playlistLayout);

   listContent->setVisible(false);

   connect(listBtn,SIGNAL(showOrHideListContentSignal(bool)),this,SLOT(showOrHideListContentSlot(bool)));
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
