#ifndef MEDIA_H
#define MEDIA_H
#include <QString>
#include <QDebug>
#include "config.h"
#include "Video.h"
#include "helper.h"

//Refresh Event
#define REFRESH_EVENT  (SDL_USEREVENT + 1)
//Break
#define BREAK_EVENT  (SDL_USEREVENT + 2)


//音视频播放
class Media
{
public:
    Media(const char* f);
    ~Media();
    bool isFileValid();//检查是否有视频传入，才能对视频操作
    double getCurrentVideoTime();//获取当前视频时间，可用于输出到屏幕显示
    double getCurrentAudioTime();
    bool isDifference();//判断是否画音同步
    int videoPlay();//视频播放
    int audioPlay();//音频播放
    void synchronize();//实现画音同步
    void play();//播放视频
    
    const char *getFileName() const;
    void setFileName(char *value);
    
    int getTotaltime() const;
    void setTotaltime(int value);
    
    Uint32 getSdlDelay() const;
    void setSdlDelay(int dly);//设置视频延迟时间
    static int freshEventThread(void *opaque);//sdl线程函数
    
private:
    //    Audio *audio;
    Video *video;
    const int bpp=12;//??????
    int pixel_w,pixel_h;//??????????
    const char* fileName;//输入视频的文件名
    static int thread_exit;//控制刷新视频的线程
    
    int totaltime;//获取的视频总时长
    int screen_w;
    int screen_h;
    
   
    int videoSts;//判断视频播放状态，0播放，1暂停，-1退出
    int videoFlag;//判断视频状态是否发生改变，0不改变，1改变
    Uint32 pixformat;
    Uint32 sdlDelay;
    
    
    SDL_Window *screen; //创建播放窗口
    SDL_Rect sdlRect;//创建图像
    SDL_Renderer* sdlRenderer;//创建渲染
    SDL_Texture *sdlTexture;//创建纹理

};

#endif // MEDIA_H
