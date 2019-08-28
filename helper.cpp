#include "helper.h"

Helper::Helper(QObject *parent) : QObject(parent)
{

}


/**
 * @author       ParanoidRoot
 * @method       Helper::q2Chars
 * @param        输入的QString
 * @return       输出的字符指针
 * @description  实现数据类型的转换
 */
const char* Helper::q2Chars(const QString& qString)
{
    char* p = nullptr;
    string str = qString.toStdString();
    p = new char[str.size() + 1];
    strcpy(p, str.c_str());
    return p;
}

/**
 * @author       ParanoidRoot
 * @method       initAll
 * @param        void
 * @return       void
 * @description  初始化所有ffmpeg组件
 */
void Helper::initAll()
{
    avformat_network_init();
}

/**
 * @author       ParanoidRoot
 * @method       Helper::initAVFmtCtx
 * @param        输入的视频的绝对路径
 * @return       封装好的AVFormatContext
 * @description  用以初始话对象
 */
AVFormatContext* Helper::getAVFmtCtx(const char* absPath)
{
    AVFormatContext* pAVFmtCtx = avformat_alloc_context();
    int ans = -1;
    if ((ans = avformat_open_input(&pAVFmtCtx, absPath, nullptr, nullptr)) < 0)
    {
        cout << "open av fail" << endl;
        avformat_free_context(pAVFmtCtx);
        return nullptr;
    }
    if ((ans = avformat_find_stream_info(pAVFmtCtx, nullptr)) < 0)
    {
        cout << "find av fail" << endl;
        avformat_free_context(pAVFmtCtx);
        return nullptr;
    }
    return pAVFmtCtx;
}

/**
 * @author       ParanoidRoot
 * @method       Helper::getAVStream
 * @param        ...
 * @return       指定类型的AVStream
 * @description  获取指定类型的avStream
 */
AVStream* Helper::getAVStream(const AVMediaType& type,
                              const AVFormatContext* avFmtCtx,
                              int& index)
{
    for (unsigned int i = 0; i < avFmtCtx->nb_streams; ++i)
    {
        AVStream* currentStream = avFmtCtx->streams[i];
        if (type == currentStream->codecpar->codec_type)
        {
            index = i;
            return currentStream;
        }
    }
    index = -1;
    cout << "find stream fail" << endl;
    return nullptr;
}

/**
 * @author       ParanoidRoot
 * @method       Helper::getAVCdcCtx
 * @param        某种流
 * @return       流所对应的解码器
 * @description  获取解码上下文
 */
AVCodecContext* Helper::getAVCdcCtx(const AVStream* avStream)
{
    AVCodec* avCdc = avcodec_find_decoder(avStream->codecpar->codec_id);
    if (!avCdc)
    {
        cout << "find codec fail" << endl;
        return nullptr;
    }
    AVCodecContext* avCdcCtx = avcodec_alloc_context3(avCdc);
    if (!avCdcCtx)
    {
        cout << "alloc codec context fail" << endl;
        avcodec_free_context(&avCdcCtx);
        return nullptr;
    }
    if (avcodec_open2(avCdcCtx, avCdc, nullptr) < 0)
    {
        cout << "open codec context fail" << endl;
        avcodec_free_context(&avCdcCtx);
        return nullptr;
    }
    return avCdcCtx;
}

/**
 * @author       ParanoidRoot
 * @method       Helper::getSwsCtx
 * @param        视频流的解码器
 * @return       像素转换器
 * @description  专门用于视频像素格式的转换
 */
SwsContext* Helper::getSwsCtx(const AVCodecContext* vCdcCtx)
{
    SwsContext* imgCvtCtx = sws_getContext(vCdcCtx->width,
                                           vCdcCtx->height,
                                           vCdcCtx->pix_fmt,
                                           vCdcCtx->width,
                                           vCdcCtx->height,
                                           AV_PIX_FMT_YUV420P,
                                           SWS_BICUBIC,
                                           nullptr, nullptr, nullptr);
    return imgCvtCtx;
}
