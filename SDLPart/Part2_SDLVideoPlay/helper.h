#ifndef HELPER_H
#define HELPER_H

#include <QObject>
#include <QString>
#include <iostream>
#include <cstdlib>

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
    #include <libswscale/swscale.h>
}
extern "C" {
    #include "SDL2/SDL.h"
    #undef main
}

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);
    static const char* q2Chars(const QString&);
    static void initAll();
    static AVFormatContext* getAVFmtCtx(const char* absPath);
    static AVStream* getAVStream(const AVMediaType&, const AVFormatContext*, int&);
    static AVCodecContext* getAVCdcCtx(const AVStream*);
    static SwsContext* getSwsCtx(const AVCodecContext*);
signals:

public slots:

};

#endif // HELPER_H
