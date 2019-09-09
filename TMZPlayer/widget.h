#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

protected:
    virtual void leaveEvent(QEvent *event);



signals:


public slots:
    void display(int, int);
private:
    QWidget *pParent;



};

#endif // WIDGET_H
