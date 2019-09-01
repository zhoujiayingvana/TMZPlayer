/**
  调试用，统一管理调试所需变量
  */
#ifndef DEBUG_H
#define DEBUG_H

#include <QWidget>
#include <QMediaPlayer>
#include <QUrl>

class Debug : public QWidget
{
    Q_OBJECT
public:


    explicit Debug(QWidget *parent = nullptr);
    QMediaContent *mediaContent;
    
signals:
    
public slots:
};

#endif // DEBUG_H
