#include "favorites.h"

favorites::favorites(QWidget *parent) : QPushButton(parent)
{ 
  //规定收藏夹的序列号为-1
  SN = -1;

}

/* Author: zyt
 * Name: favoritesBtnClickedSlot
 * Function: 槽：响应收藏夹按钮被点击了，接下来让收藏夹发送他的序列号，让主界面的displayList接受
 *           并显示收藏夹内容，支持修改
 */
void favorites::favoritesBtnClickedSlot()
{
  emit sendingFavoritesSNAndFiles(-1,favoritesList);
  emit sendingFavoritesNameSignal("我的收藏");
}

/* Author: zyt
 * Name: changeFilesInListSlot
 * Function: 更新收藏夹的文件列表
 */
void favorites::changeFilesInListSlot(int currentSN, QList<QString> temp_filesInList)
{
  if(currentSN == -1)
    {
      favoritesList = temp_filesInList;
    }
}
