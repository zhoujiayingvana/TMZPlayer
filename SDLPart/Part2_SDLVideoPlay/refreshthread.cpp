#include "refreshthread.h"
#include <QDebug>
RefreshThread::RefreshThread(int dly)
{
    sdlDelay=dly;
}
void RefreshThread::run(){
    while (1) {
        qDebug()<<"Thread run";
        SDL_Event event;
        event.type = REFRESH_EVENT;
        SDL_PushEvent(&event);
        SDL_Delay(sdlDelay);
        QThread::msleep(1000);
    }
}

int RefreshThread::getSdlDelay() const
{
    return sdlDelay;
}

void RefreshThread::setSdlDelay(int value)
{
    sdlDelay = value;
}
