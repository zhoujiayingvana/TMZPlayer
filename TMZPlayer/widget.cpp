#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    pParent=parent;
    this->setAttribute(Qt::WA_StyledBackground);
}

Widget::~Widget()
{

}



void Widget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    hide();
}





void Widget::display(int x,int y)
{
    if(this->window()->isFullScreen())
    {
        qDebug()<<pParent->height();
        setGeometry(x+20-this->width()/2,pParent->height()-70+y-this->height(),geometry().width(),geometry().height());
    }
    else
    {
        setGeometry(x+20-this->width()/2,pParent->height()-75+y-this->height(),geometry().width(),geometry().height());
    }
    show();


}
