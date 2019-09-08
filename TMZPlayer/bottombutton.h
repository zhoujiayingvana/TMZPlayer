#ifndef BOTTOMBUTTON_H
#define BOTTOMBUTTON_H

#include<QObject>
#include <QWidget>
#include<QPushButton>
#include"widget.h"
#include<QLayout>
#include<QDebug>
#include<QMouseEvent>
#include<QEvent>

class BottomButton : public QPushButton
{
    Q_OBJECT
public:
    BottomButton(QWidget *parent = nullptr);
    ~BottomButton();
signals:
    void enterSignal(int,int);
    void leaveSignal();
protected:
    virtual void enterEvent(QEvent *event);
    virtual void leaveEvent(QEvent *event);

private:


};

#endif // BOTTOMBUTTON_H
