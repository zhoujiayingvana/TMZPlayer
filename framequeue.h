#ifndef FRAMEQUEUE_H
#define FRAMEQUEUE_H

#include <iostream>
#include <cstdlib>
#include <queue>
#include <QMutex>
#include <QWaitCondition>

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

class FrameQueue
{
public:
    FrameQueue(const unsigned int&_maxSize=30);
    ~FrameQueue();
    unsigned int getSize()const;
    unsigned int getMaxSize() const;
    bool enQueue(const AVFrame*);
    AVFrame* deQueue();
    void makeEmpty();
private:
    queue<AVFrame*> frames;
    const unsigned int maxSize;
    QMutex mutex;
    QWaitCondition waitCondition;
};

#endif // FRAMEQUEUE_H
