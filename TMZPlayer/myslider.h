#ifndef MYSLIDER_H
#define MYSLIDER_H
#include <QObject>
#include<QSlider>

class MySlider : public QSlider
{

public:
    MySlider(QWidget *parent = nullptr);
    ~MySlider();
protected:
    void mousePressEvent(QMouseEvent *event);
    void wheelEvent(QWheelEvent *event);

};

#endif // MYSLIDER_H
