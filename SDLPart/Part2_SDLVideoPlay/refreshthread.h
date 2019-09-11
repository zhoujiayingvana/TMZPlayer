#ifndef REFRESHTHREAD_H
#define REFRESHTHREAD_H
#include <QThread>
#include "config.h"
#define REFRESH_EVENT  (SDL_USEREVENT + 1)
class RefreshThread:public QThread
{
public:
    RefreshThread(int dly=40);
    void run();
    int getSdlDelay() const;
    void setSdlDelay(int value);
    
private:
    int sdlDelay;
};

#endif // REFRESHTHREAD_H
