#include "bottombutton.h"

BottomButton::BottomButton(QWidget *parent):QPushButton (parent)
{

}

BottomButton::~BottomButton()
{

}


void BottomButton::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    this->pos();
    emit enterSignal(x(),y());
}

void BottomButton::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    emit leaveSignal();
}
