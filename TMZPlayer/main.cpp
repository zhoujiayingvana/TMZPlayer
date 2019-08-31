#include "tmzplayer.h"
#include <QApplication>
#include<QAbstractSlider>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TMZPlayer w;
    w.show();


    return a.exec();
}
