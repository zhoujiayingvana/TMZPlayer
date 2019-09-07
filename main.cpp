#include "mainwindow.h"
#include "history.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  mainWindow w;
  w.show();

//  history h;
//  h.show();
  return a.exec();
}
