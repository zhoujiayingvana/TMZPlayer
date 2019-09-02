/* Author: zyt
 * 类：mergedPlaylist
 * Function: 将模块化编程的【列表按钮】、【列表】、【表头】结合起来，形成一个完整的部件
 *           即为具有完全功能的列表
 */

#ifndef MERGEDPLAYLIST_H
#define MERGEDPLAYLIST_H

#include "playlist.h"
#include "newLineEdit.h"
#include "playlistbtn.h"

#include <QWidget>

class mergedPlaylist : public QWidget
{
  Q_OBJECT
public:
  explicit mergedPlaylist(QWidget *parent = nullptr);

signals:

public slots:
  void showOrHideListContentSlot(bool);

private:
  playlistBtn* listBtn;
  playList* listContent;
};

#endif // MERGEDPLAYLIST_H
