#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>



/*
 *Author:LY
 *Function:实现标题栏
 */

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);

protected:
    //双击标题栏进行界面的最大化/还原
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    //拖拽界面
    virtual void mousePressEvent(QMouseEvent *event);



signals:

public slots:
    void on_MinimizeButton_clicked();//最小化
    void on_MaximizeButton_clicked();//最大化/还原
    void on_CloseButton_clicked();//关闭
private:
    QLabel *IconLabel; //标题栏图标
    QLabel *TitleLabel; //标题栏标题
    QPushButton *FilesButton; //文件按钮
    QPushButton *SettingsButton; //设置按钮
    QPushButton *SkinButton; //换肤按钮
    QPushButton *MiniButton; //迷你模式按钮
    QPushButton *MinimizeButton; //最小化按钮
    QPushButton *MaximizeButton; //最大化/还原按钮
    QPushButton *CloseButton; //关闭按钮




};

#endif // TITLEBAR_H
