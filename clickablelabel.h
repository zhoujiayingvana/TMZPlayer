/* Author: zyt
 * Name: clickablelabel.h
 * Function: 更完善地实现label的点击功能
 */

#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QWidget>

class clickableLabel : public QLabel
{
  Q_OBJECT
public:
  explicit clickableLabel(QWidget *parent = nullptr);

signals:
  void clicked();

public slots:
  void slotClicked();

protected:
  void mousePressEvent(QMouseEvent*);
};

#endif // CLICKABLELABEL_H
