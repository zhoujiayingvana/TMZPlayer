#include "media.h"
#include <stdio.h>
/**
 * @brief Media::Media
 * @param f
 */
int Media::thread_exit=0;
Media::Media(const char *f)
    : fileName(f)
{
    
    if(SDL_Init(SDL_INIT_VIDEO)) {  //初始化，加入音频则为"xxx | SDL_INIT_AUDIO"
        printf( "Could not initialize SDL - %s\n", SDL_GetError()); 
    } 
    //video=new Video(fileName);
    videoSts=-1;//未播放状态
    sdlDelay=40;//默认速度为1秒25fps
    
    
    //获取video传入的参数
//    screen_w=video->getWidth();
//    screen_h=video->getHeight();
    screen_w=500;
    screen_h=500;
    sdlRect.w = screen_w;  
    sdlRect.h = screen_h; 
    pixel_w=320;
    pixel_h=180;
    
    thread_exit=0;
    //SDL 2.0 Support for multiple windows
    screen = SDL_CreateWindow("Simplest Video Play SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              screen_w, screen_h,SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);//SDL_CreateWindow(窗口名称，位置x，位置y(最好默认)，窗口宽度，窗口高度，如何显示)
    if(!screen) {  
        printf("SDL: could not create window - exiting:%s\n",SDL_GetError());  
    }
    sdlRenderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);//硬件加速渲染
    
    //IYUV: Y + U + V  (3 planes)
    //YV12: Y + V + U  (3 planes)
    pixformat= SDL_PIXELFORMAT_IYUV;  
    
    sdlTexture = SDL_CreateTexture(sdlRenderer,pixformat, SDL_TEXTUREACCESS_STREAMING,pixel_w,pixel_h);
    
}
////////////
Media::~Media()
{
    
}

/**
 * @brief Media::videoPlay
 * @return 
 */
int Media::videoPlay()
{
    /**
     * @brief 测试文件
     */
    unsigned char buffer[pixel_w*pixel_h*bpp/8];

     videoSts=-1;//判断视频播放状态，0播放，1暂停，-1退出
     videoFlag=0;//判断视频状态是否发生改变，0不改变，1改变

         
         //文件读写，完整版无需此步骤
         FILE *fp=NULL;
         fp=fopen("E:/QT/QTITEM/QTFFMPEGTest/videos/test_yuv420p_320x180.yuv","rb+");
         
         if(fp==NULL){
             printf("cannot open this file\n");
             return -1;
         }
         //创建渲染线程
        SDL_Thread *refresh_thread = SDL_CreateThread(freshEventThread,NULL,NULL);
         //创建事件
         SDL_Event event;
         //死循环让视频停留在桌面上
         videoSts=1;
         
         
         
         while(1){
             //等待事件并响应
             SDL_WaitEvent(&event);
             if(videoSts==0){
                 //SDL_PauseAudio(1);//暂停音频
                 SDL_Delay(20);//暂停视频
                 //继续播放
             }else if(videoSts==1&&videoFlag==1){
                 //SDL_PauseAudio(0);//播放音频
                 videoFlag=0;            
                 
             }else if(videoSts==-1){
                 SDL_DestroyWindow(screen);
                 SDL_Quit();
             }
             //播放视频
             if(event.type==REFRESH_EVENT){
                 
//                 qDebug()<<thread->getSdlDelay();
                 
                 
                 videoSts=0;//视频处于播放状态
                 if (fread(buffer, 1, pixel_w*pixel_h*bpp/8, fp) != pixel_w*pixel_h*bpp/8){
                     // Loop
                     fseek(fp, 0, SEEK_SET);
                     fread(buffer, 1, pixel_w*pixel_h*bpp/8, fp);
                 }//处理delay的时间
                 
                 SDL_UpdateTexture( sdlTexture, NULL, buffer, pixel_w);  //将Texture更新
                 
                 //FIX: If window is resize
                 sdlRect.x = 0;  
                 sdlRect.y = 0;  
                 sdlRect.w = screen_w;  
                 sdlRect.h = screen_h;  
                 
                 SDL_RenderClear( sdlRenderer );//清除上一帧
                 SDL_RenderCopy( sdlRenderer, sdlTexture, NULL, &sdlRect);  //粘贴更新过的texture
                 SDL_RenderPresent( sdlRenderer );  //显示出来
                 
                 
//                 thread->setSdlDelay(40);
                 
             }else if(event.type==SDL_WINDOWEVENT){
                 //If Resize
                 SDL_GetWindowSize(screen,&screen_w,&screen_h);
             }else if(event.type==SDL_QUIT){//强制关闭窗口
                 qDebug()<<"退出";
//                 thread->quit();
                 SDL_DestroyWindow(screen);
                 SDL_Quit();
                 break;
             }else if(event.type==SDL_MOUSEBUTTONDOWN){
                 qDebug()<<"鼠标";
                 if(event.button.button==SDL_BUTTON_LEFT){
                     setSdlDelay(30);
                     if(videoSts==0){
                         videoSts=1;
                         videoFlag=1;
                     }else if(videoSts==1){
                         videoSts=0;
                         videoFlag=1;
                     }
                 }else if(event.button.button==SDL_BUTTON_LEFT){
                     //弹出菜单
                 }
                 continue;
             }else if(event.type==SDL_KEYDOWN){
                 qDebug()<<"键盘";
                 if(event.key.keysym.sym==SDLK_SPACE){
                     if(videoSts==0){
                         videoSts=1;
                         videoFlag=1;
                     }else if(videoSts==1){
                         videoSts=0;
                         videoFlag=1;
                     }
                 }
                 continue;
             }
         }
         SDL_DestroyTexture(sdlTexture);
         SDL_DestroyRenderer(sdlRenderer);
         SDL_DestroyWindow(screen);
         SDL_Quit();

        
        
        
    return 1;///
}
Uint32 Media::getSdlDelay() const
{
    return sdlDelay;
}

void Media::setSdlDelay(int dly)
{
    sdlDelay = dly;
}

int Media::freshEventThread(void *opaque)
{
    thread_exit=0;
    while (thread_exit==0) {
        SDL_Event event;
        event.type = REFRESH_EVENT;
        SDL_PushEvent(&event);
        SDL_Delay(40);
    }
    thread_exit=0;
    //Break
    SDL_Event event;
    event.type = BREAK_EVENT;
    SDL_PushEvent(&event);
    return 0;
}


////////////
bool Media::isFileValid()
{
    return 1;
}


////////////////
double Media::getCurrentVideoTime()
{
    return -100;
}

///////////////
double Media::getCurrentAudioTime()
{
    return -200;
}

/////////
bool Media::isDifference()
{
    return 1;
}



////////////
int Media::audioPlay()
{   
    
    return 1;
}
////////////
void Media::play()
{
    
}



const char *Media::getFileName() const
{
    return fileName;
}

void Media::setFileName(char *value)
{
    fileName = value;
}

int Media::getTotaltime() const
{
    return totaltime;
}

void Media::setTotaltime(int value)
{
    totaltime = value;
}
