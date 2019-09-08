#include "testmainwindow.h"
#include <QApplication>
#include "util/networkmodel.h"
#include <QFileInfo>
#include "util/media.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    try {
        TestMainWindow* w = new TestMainWindow();
        w->show();
    } catch (MyErrors e) {
        qDebug() << getErrorType(e);
    }
//    Media media;
//    qDebug() << media.songWebSearch("小幸运");
//    qDebug() << "****************************************" << endl;
    return a.exec();
}
