#include "widget.h"

Widget::Widget(QWidget *parent) : QWidget(parent)
{
    pParent=parent;

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
    setGeometry(x+10,pParent->height()-109+y,geometry().width(),geometry().height());
    show();
}
