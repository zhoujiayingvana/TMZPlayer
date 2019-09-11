#include "tmzplayer.h"
#include <QApplication>
#include "util/networkmodel.h"
#include <QFileInfo>
#include "util/media.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Media* main_Media=new Media();
    try {
        TMZPlayer* w = new TMZPlayer(nullptr,main_Media);
        w->show();
    } catch (MyErrors e) {
        qDebug() << getErrorType(e);
    }
//    Media media;
//    qDebug() << media.songWebSearch("小幸运");
//    qDebug() << "****************************************" << endl;
    return a.exec();
}
