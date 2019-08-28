#ifndef CONFIG_H
#define CONFIG_H
extern "C"
{
    //ffmpeg库函数
    #include <libavcodec/avcodec.h>
    #include <libavformat/avformat.h>
    #include <libswscale/swscale.h>
    #include <libavdevice/avdevice.h>
    #include <libavformat/version.h>
    #include <libavutil/time.h>
    #include <libavutil/mathematics.h>
    #include <libavutil/pixfmt.h>
    
    //SDL2库函数
    #include <SDL2/SDL.h>
    #undef main
}
#endif // CONFIG_H
