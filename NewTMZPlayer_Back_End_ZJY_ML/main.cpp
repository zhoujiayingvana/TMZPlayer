#include "testmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TestMainWindow w;
    try {
        
        w.show();
        
    } catch (MyErrors e) {
        qDebug()<<getErrorType(e);
    }{
        
    }
    return a.exec();
    
}
