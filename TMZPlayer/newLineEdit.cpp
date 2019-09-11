#include "newLineEdit.h"

#include <QMouseEvent>


/* Author: zyt
 * newLineEdit类：因Qt自带lineEdit没有clicked（）信号
 *               故重写lineEdit类，增加一个识别点击的信号与对应槽
 *               使单击lineEdit也可以实现展开列表的功能
 */
newLineEdit::newLineEdit(QWidget *parent) : QLineEdit(parent)
{
  this->setContextMenuPolicy(Qt::CustomContextMenu);
}

/* Author: zyt
 * Name: mousePressEvent
 * Function: 重写点击事件，实现点击列表姓名可展开列表
 */
void newLineEdit::mousePressEvent(QMouseEvent *event)
{
  if (event->button() == Qt::LeftButton)
    {
      emit listNameClickedSignal();
    }
}

//* Author: zyt
// * Name: mouseDoubleClickEvent
// * Function: 重写双击事件，实现双击列表姓名可将列表投影在右边
// */
//void newLineEdit::mouseDoubleClickEvent(QMouseEvent *event)
//{
//  Q_UNUSED(event);
//  emit displayOnRightSignal(this->text());
//}

