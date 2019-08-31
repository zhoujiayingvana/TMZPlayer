/**
* @projectName   TMZPlayer
* @brief         换肤下拉菜单
* @author        涂晴昊
* @date          2019-08-30
*/
#ifndef MYSKINMENUBUTTON_H
#define MYSKINMENUBUTTON_H
#include<QPushButton>
#include<QMenu>

class MySkinMenuButton : public QPushButton
{
    Q_OBJECT

public:
    explicit MySkinMenuButton(QWidget *parent=0);
public slots:
    void popSkinMenu();

private:
    QMenu *skinMenu;
    QWidget *title;
public:
    QAction * black;
    QAction * blue;
    QAction * pink;
    QAction * own;

};

#endif // MYSKINMENUBUTTON_H
