#include "myslider.h"
#include<QMouseEvent>

MySlider::MySlider(QWidget *parent):QSlider (parent)
{

}

MySlider::~MySlider()
{

}

void MySlider::mousePressEvent(QMouseEvent *event)
{

    //使Slider能正常响应其他鼠标事件
    QSlider::mousePressEvent(event);
    //获取鼠标点击位置
    int currentX = event->pos().x();
    //获取鼠标点击的位置占整个Slider的百分比
    double per = currentX *1.0 /width();

    //利用算得的百分比得到具体数字
    int value = static_cast<int>(per*(this->maximum() - this->minimum()) + this->minimum());

    //设定滑动条位置
    this->setValue(value);



}

void MySlider::wheelEvent(QWheelEvent *event)
{
    //获取最大最小值
    int max = maximum();
    int min = minimum();
    int value = this->value();
    int change;
    if((max - min)<=10)
    {
        change = 1;
    }
    else if((max - min)<=100)
    {
        change = 3;
    }
    else
    {
        change = 5;
    }
    //滚轮向上滚动增加vlaue
    if (event->delta() >= 120)
    {
        value = this->value() + change;
        if (value > max)
            value = max;
        setValue(value);
    }
    //滚轮向下滚动减少vlaue
    else if (event->delta() <= -120)
    {
        value =this->value()- change;
        if (value < min)
            value = min;
        setValue(value);
    }
    else
    {

    }
}
