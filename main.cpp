#include <QCoreApplication>
#include <QDebug>
#include <QDir>
#include <videoplayer.h>

using namespace std;
extern "C"
{
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
}
extern "C" {
    #include "SDL2/SDL.h"
    #undef main
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QDir inPath("../vid/testyuv.yuv"), outPath("../vid/out.avi");
    VideoPlayer::translate(inPath.absolutePath(), outPath.absolutePath());
    return a.exec();
}
