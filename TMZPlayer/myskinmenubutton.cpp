/**
* @projectName   TMZPlayer
* @brief         换肤下拉菜单
* @author        涂晴昊
* @date          2019-08-30
*/
#include "myskinmenubutton.h"

MySkinMenuButton::MySkinMenuButton(QWidget *parent):
    QPushButton (parent)
{
    title=parent;
    skinMenu = new QMenu(this);
    black = skinMenu->addAction("black");
    blue = skinMenu->addAction("blue");
    pink = skinMenu->addAction("pink");
    own = skinMenu->addAction("fromFile");
    connect(this,SIGNAL(clicked()),this,SLOT(popSkinMenu()));
}

/**
* @method        MySkinMenuButton::popSkinMenu
* @brief         弹出换肤菜单
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-01
*/
void MySkinMenuButton::popSkinMenu()
{
    QPoint pos; //获取按键菜单的坐标

    //int x = pos.x();

    int y = pos.y();
    //pos.setX(x - this->geometry().width()/2);

    pos.setY(y+this->geometry().height());

    skinMenu->exec(this->mapToGlobal(pos));


}
