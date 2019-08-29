#include "mini.h"
#include "ui_mini.h"

#include <QDebug>
#include <QWidget>
#include <QMouseEvent>

/* Author: zyt
 * Name: Mini
 * Function: 使音乐播放以mini窗口显示
 * Parameters: parent
 */
Mini::Mini(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::Mini)
{
  ui->setupUi(this);

  //初始化，取消边框，添加图标，显示可点击手势
  setWindowFlags(Qt::Window|Qt::FramelessWindowHint|Qt::WindowTitleHint);
  QImage *likeImage = new QImage(":/image/image/musicform/btn_like_n.png");
  QImage *volumeImage = new QImage(":/image/image/horn.png");
  QImage *listImage = new QImage(":/image/image/musiclist.png");
  QImage *closeImage = new QImage(":/image/image/btn_close_n.png");
  QImage *switchImage = new QImage(":/image/image/btn_max_n.png");

  ui->likeBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->volumeBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->listBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->closeBtn->setCursor(QCursor(Qt::PointingHandCursor));
  ui->switchBackBtn->setCursor(QCursor(Qt::PointingHandCursor));

  ui->likeBtn->setPixmap(QPixmap::fromImage(likeImage->scaled(ui->likeBtn->width(),
                                                                 ui->likeBtn->height(),
                                                                 Qt::KeepAspectRatio,
                                                                 Qt::SmoothTransformation)));

  ui->volumeBtn->setPixmap(QPixmap::fromImage(volumeImage->scaled(ui->volumeBtn->width(),
                                                                 ui->volumeBtn->height(),
                                                                 Qt::KeepAspectRatio,
                                                                 Qt::SmoothTransformation)));

  ui->listBtn->setPixmap(QPixmap::fromImage(listImage->scaled(ui->listBtn->width(),
                                                                 ui->listBtn->height(),
                                                                 Qt::KeepAspectRatio,
                                                                 Qt::SmoothTransformation)));

  ui->closeBtn->setPixmap(QPixmap::fromImage(closeImage->scaled(ui->closeBtn->width(),
                                                                 ui->closeBtn->height(),
                                                                 Qt::KeepAspectRatio,
                                                                 Qt::SmoothTransformation)));

  ui->switchBackBtn->setPixmap(QPixmap::fromImage(switchImage->scaled(ui->switchBackBtn->width(),
                                                                 ui->switchBackBtn->height(),
                                                                 Qt::KeepAspectRatio,
                                                                 Qt::SmoothTransformation)));

  //测试：添加专辑封面
  QImage *album = new QImage;
  album->load(":/image/image/test.png");
  ui->albumPicLabel->setPixmap(QPixmap::fromImage(album->scaled(ui->albumPicLabel->width(),
                                                                 ui->albumPicLabel->height(),
                                                                 Qt::KeepAspectRatio,
                                                                 Qt::SmoothTransformation)));

}

Mini::~Mini()
{
  delete ui;
}

//设置播放器音量
void Mini::setVolume(int vol)
{
  //槽不能被识别?
  qDebug() << "changed";
}



