#ifndef MEDIAWIDGET_H
#define MEDIAWIDGET_H

#include <QWidget>
#include <QDebug>
#include <QTimer>

class MediaWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MediaWidget(QWidget *parent = nullptr);

signals:
    void full_screenButton_clicked();
    void bottomBarHide();
    void volumeWidgetHide();
    void bottomBarShow();
    void wheelMoved(QWheelEvent *);
public slots:
    void hideBottomBar();


protected:
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);
    virtual void wheelEvent(QWheelEvent *event);

private:
   QTimer *timer;
};

#endif // MEDIAWIDGET_H
