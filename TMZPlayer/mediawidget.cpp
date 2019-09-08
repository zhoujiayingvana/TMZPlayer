#include "mediawidget.h"

MediaWidget::MediaWidget(QWidget *parent) : QWidget(parent)
{

    this->setCursor(Qt::PointingHandCursor);
    this->setMouseTracking(true);
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(hideBottomBar()));

}

void MediaWidget::hideBottomBar()
{
    setCursor(Qt::BlankCursor);
    if(this->window()->isFullScreen())
    {
        emit bottomBarHide();
    }
    else
    {

    }
    emit volumeWidgetHide();


}

void MediaWidget::mouseDoubleClickEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    emit full_screenButton_clicked();
}

void MediaWidget::mouseMoveEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
    setCursor(Qt::PointingHandCursor);


    if(this->window()->isFullScreen())
    {
        emit bottomBarShow();
    }
    else
    {

    }

    timer->start(1000);


}

void MediaWidget::enterEvent(QEvent *event)
{
    Q_UNUSED(event);
    timer->start(1000);
}

void MediaWidget::leaveEvent(QEvent *event)
{
    Q_UNUSED(event);
    timer->stop();
}

void MediaWidget::wheelEvent(QWheelEvent *event)
{
    emit wheelMoved(event);
    if(this->window()->isFullScreen())
    {
        emit bottomBarShow();
    }
    else
    {

    }

    timer->start(1000);

}
