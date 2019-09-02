#include "mini.h"
#include "playlist.h"
#include "mainwindow.h"
#include "playlistbtn.h"
#include "mergedPlaylist.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  mainWindow *w = new mainWindow;

  w->show();

  return a.exec();
}
