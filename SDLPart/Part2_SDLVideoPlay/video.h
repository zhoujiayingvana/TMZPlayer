#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "framequeue.h"
#include <QThread>

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

class Video: public QThread
{
public:
    Video(const char* _inAbsPath);
    ~Video();
    void makeFramesEmpty();
    void run();
    bool getIsPlaying() const;
    void setIsPlaying(bool value);
    bool getIsTerminated() const;
    void setIsTerminated(bool value);
    AVFrame* popVFrame();  // 获取frames头部的一个帧
    int getHeight() const;
    int getWidth() const;
private:
    const char* absPath;  // 视频路径
    AVFormatContext* vFmtCtx;
    AVStream* vStream;
    int vStreamIndex;
    AVCodecContext* vCdcCtx;
    SwsContext* swsCtx;
    FrameQueue frames;
    bool isPlaying;
    bool isTerminated;
    int decodedFrameNum;
    void addVFrame(const AVFrame*);
};

#endif // VIDEO_H
