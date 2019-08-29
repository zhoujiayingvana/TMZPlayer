/* Author: zyt
 * Name: clickablelabel.cpp
 * Function: 更完善地实现label的点击功能
 */
#include "mini.h"
#include "mainwindow.h"
#include <QSlider>
#include <QAbstractSlider>
#include "clickablelabel.h"


clickableLabel::clickableLabel(QWidget *parent) : QLabel(parent)
{
  connect(this,SIGNAL(clicked()),this,SLOT(slotClicked()));
}

/* Author: zyt
 * Name: slotClicked()
 * Function: 识别不同的被点击标签(label)，完成相应的操作
 */
void clickableLabel::slotClicked()
{
  //显示音量条
  if (this->objectName() == "volumeBtn")
    {
      QSlider *volumeChange = new QSlider;
      volumeChange->setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowTitleHint);
      volumeChange->setMinimum(0);
      volumeChange->setMaximum(100);
      //volumeChange->setValue(50);
      connect(volumeChange,SIGNAL(valueChanged(int)),this,SLOT(setVolume(int)));

      volumeChange->show();
    }
  //显示主界面
  else if(this->objectName() == "closeBtn")
    {

    }
}

/* Author: zyt
 * Name: mousePressEvent
 * Function: 重写，发送鼠标点击信号
 * Parameters: event
 */
void clickableLabel::mousePressEvent(QMouseEvent *event)
{
  Q_UNUSED(event);
  emit clicked();
}
