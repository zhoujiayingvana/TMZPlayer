#include "testmainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    try {
        QApplication a(argc, argv);
        TestMainWindow w;
        w.show();
        return a.exec();
        
    } catch (MyErrors e) {
        qDebug()<<getErrorType(e);
    }{
        
    }
   
    
}
