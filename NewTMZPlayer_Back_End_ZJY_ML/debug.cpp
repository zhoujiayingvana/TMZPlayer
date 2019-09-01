/**
  调试用，统一管理调试所需变量
  */
#include "debug.h"

Debug::Debug(QWidget *parent) : QWidget(parent)
{
    QUrl url;
    url.setUrl("../vid/t3.avi");//
    this->mediaContent=new QMediaContent(url);
}
