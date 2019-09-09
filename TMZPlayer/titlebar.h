#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include"myskinmenubutton.h"
#include"settingwindow.h"


/*
 *Author:LY
 *Function:实现标题栏
 */

class TitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit TitleBar(QWidget *parent = nullptr);


signals:
    void systemTrayMode();
    void miniMode();

public slots:
    void on_miniButton_clicked();//mini
    void on_minimizeButton_clicked();//最小化
    void on_maximizeButton_clicked();//最大化/还原
    void on_closeButton_clicked();//关闭
    void on_SettingsButton_clicked();//打开设置界面
    /* currentFontChanged(const QFont &font)为Qt自带
     * connect(settingwindow->fontComboBox,SIGNAL(currentFontChanged(const QFont &font)),
     * 字幕,SLOT(changeFontType(QFont * font));
     * */
    void changeFontType(QFont * font);

    //收藏快捷键修改
    void changeLikeShortcut(QString);

    void changeCloseStatus(int);
protected:
    //双击标题栏进行界面的最大化/还原
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    //拖拽界面
    virtual void mousePressEvent(QMouseEvent *event);

private:
    QLabel *iconLabel; //标题栏图标
    QLabel *titleLabel; //标题栏标题
    QPushButton *SettingsButton; //设置按钮
    MySkinMenuButton *SkinButton; //换肤按钮
    QPushButton *skinButton; //换肤按钮
    QPushButton *miniButton; //迷你模式按钮
    QPushButton *minimizeButton; //最小化按钮
    QPushButton *maximizeButton; //最大化/还原按钮
    QPushButton *closeButton; //关闭按钮
    QWidget *p;
    int closeStatus;//关闭/最小化界面

    void connectSettingAndTitle();
public:
    SettingWindow * settingWindow;//设置界面


};

#endif // TITLEBAR_H
