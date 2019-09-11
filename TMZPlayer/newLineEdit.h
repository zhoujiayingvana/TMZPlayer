/* Author: zyt
 * newLineEdit类：因Qt自带lineEdit没有clicked（）信号
 *               故重写lineEdit类，增加一个识别点击的信号与对应槽
 *               使单击lineEdit也可以实现展开列表的功能
 */

#ifndef NEWLINEEDIT_H
#define NEWLINEEDIT_H

#include <QWidget>
#include <QLineEdit>

class newLineEdit : public QLineEdit
{
  Q_OBJECT
public:
  explicit newLineEdit(QWidget *parent = nullptr);

signals:
  void listNameClickedSignal();

public slots:

protected:
  void mousePressEvent(QMouseEvent*);
};

#endif // NEWLINEEDIT_H
