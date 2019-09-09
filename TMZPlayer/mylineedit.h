#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include<QLineEdit>
#include<QKeyEvent>
#include<QKeySequence>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent=0);

protected:
    virtual void keyPressEvent(QKeyEvent *event);
    QString keyEventToString(QKeyEvent *e);
};

#endif // MYLINEEDIT_H
