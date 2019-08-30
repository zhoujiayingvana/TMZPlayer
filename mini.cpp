#include "mini.h"
#include "ui_mini.h"

#include <QDrag>
#include <QDebug>
#include <QWidget>
#include <QSlider>
#include <QMouseEvent>
#include <QPushButton>


/* Author: zyt
 * Name: Mini
 * Function: mini窗口显示的初始化
 * Parameters: parent
 */
Mini::Mini(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Mini)
{
  ui->setupUi(this);
  drag = false;

  setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowTitleHint|Qt::WindowStaysOnTopHint); //无边框、在最前
  setMouseTracking(true);
  ui->albumPic->setMouseTracking(true);

  ui->lastSongBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->playOrPauseBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->nextSongBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->likeBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->volumeBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->listBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->closeBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->maxModeBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->albumPic->setCursor(QCursor(Qt::PointingHandCursor));

  ui->lastSongBtn->setStyleSheet("border-image: url(:/image/image/mini_last.jpg)");
  ui->playOrPauseBtn->setStyleSheet("border-image: url(:/image/image/mini_play.jpg)");
  ui->nextSongBtn->setStyleSheet("border-image: url(:/image/image/mini_next.jpg)");
  ui->likeBtn->setStyleSheet("border-image: url(:/image/image/musicform/btn_like_n.png)");
  ui->volumeBtn->setStyleSheet("border-image: url(:/image/image/horn.png)");
  ui->listBtn->setStyleSheet("border-image: url(:/image/image/musiclist.png)");
  ui->closeBtn->setStyleSheet("border-image: url(:/image/image/btn_close_n.png)");
  ui->maxModeBtn->setStyleSheet("border-image: url(:/image/image/btn_max_n.png)");

  //测试：添加专辑封面
  ui->albumPic->setStyleSheet("border-image: url(:/image/image/test.png)");

  ui->lastSongBtn->setVisible(false);
  ui->playOrPauseBtn->setVisible(false);
  ui->nextSongBtn->setVisible(false);

  ui->lastSongBtn->setText("");
  ui->playOrPauseBtn->setText("");
  ui->nextSongBtn->setText("");
}

Mini::~Mini()
{
  delete ui;
}

/* Author: zyt
 * Name: mousePressEvent
 * Function: 检测鼠标点击了mini界面，记录mini界面初始位置
 */
void Mini::mousePressEvent(QMouseEvent *event)
{
  if(event->button() == Qt::LeftButton)
    {
      drag = true;
      mouseStartPos = event->globalPos();
      windowStartPos = this->frameGeometry().topLeft();
    }
}

/* Author: zyt
 * Name: mouseMoveEvent
 * Function: 实现mini移动
 */
void Mini::mouseMoveEvent(QMouseEvent *event)
{
  Q_UNUSED(event);
  if(drag)
    {
      QPoint distance = event->globalPos() - mouseStartPos;
      this->move(windowStartPos + distance);
    }
  else
    return QWidget::mouseMoveEvent(event);
}

/* Author: zyt
 * Name: mouseReleaseEvent
 * Function: 记录使用者不再移动窗口
 */
void Mini::mouseReleaseEvent(QMouseEvent *event)
{
  if(event->button() == Qt::LeftButton)
   {
      drag = false;
    }
}

/* Author: zyt
 * Name: enterEvent
 * Function: 检测鼠标进入mini界面，显示上一曲/暂停/下一曲按钮
 */
void Mini::enterEvent(QEvent *event)
{
  Q_UNUSED(event);
  ui->songLabel->setVisible(false);
  ui->singerLabel->setVisible(false);
  ui->lastSongBtn->setVisible(true);
  ui->playOrPauseBtn->setVisible(true);
  ui->nextSongBtn->setVisible(true);
}

void Mini::leaveEvent(QEvent *event)
{
  Q_UNUSED(event);
  ui->songLabel->setVisible(true);
  ui->singerLabel->setVisible(true);
  ui->lastSongBtn->setVisible(false);
  ui->playOrPauseBtn->setVisible(false);
  ui->nextSongBtn->setVisible(false);
}

/* Author: zyt
 * Name: on_maxModeBtn_clicked
 * Function: 槽：发送信号：mini模式->窗口模式
 */
void Mini::on_maxModeBtn_clicked()
{
  emit miniToMaxSignal();
}

/* Author: zyt
 * Name: on_closeBtn_clicked
 * Function: 槽：发送信号：mini模式->托盘模式
 */
void Mini::on_closeBtn_clicked()
{
  emit miniToTraySignal();
}

/* Author: zyt
 * Name: on_volumeBtn_clicked
 * Function: 槽：显示音量条
 */
void Mini::on_volumeBtn_clicked()
{
  QSlider *volumeChange = new QSlider;
  volumeChange->setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowTitleHint);
  volumeChange->setMinimum(0);
  volumeChange->setMaximum(100);
  //volumeChange->setValue(50);
  connect(volumeChange,SIGNAL(valueChanged(int)),this,SLOT(setVolume(int)));

  volumeChange->show();
}
