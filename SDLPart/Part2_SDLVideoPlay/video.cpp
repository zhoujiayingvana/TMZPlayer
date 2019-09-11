#include "video.h"
#include "helper.h"
#include "errors.h"

Video::Video(const char* _inAbsPath)
    : absPath(_inAbsPath), vFmtCtx(nullptr),
      vStream(nullptr), vStreamIndex(-1),
      vCdcCtx(nullptr), swsCtx(nullptr),
      frames(), isPlaying(false), isTerminated(false), decodedFrameNum(0)
{
    this->vFmtCtx = Helper::getAVFmtCtx(this->absPath);

    if (!vFmtCtx)
        throw Errors::DECODE_ERROR;
    this->vStream = Helper::getAVStream(AVMediaType::AVMEDIA_TYPE_VIDEO,
                                        this->vFmtCtx,
                                        this->vStreamIndex);
    if (!this->vStream || this->vStreamIndex < 0)
    {
        avformat_free_context(this->vFmtCtx);
        throw Errors::DECODE_ERROR;
    }
    this->vCdcCtx = Helper::getAVCdcCtx(this->vStream);
    if (!this->vCdcCtx)
    {
        avformat_free_context(this->vFmtCtx);
        throw Errors::DECODE_ERROR;
    }
    this->swsCtx = Helper::getSwsCtx(this->vCdcCtx);
}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      完成析构的操作
 */
Video::~Video()
{
    if (!this->absPath)
        delete this->absPath;
    if (!this->vFmtCtx)
        avformat_free_context(this->vFmtCtx);
    if (!this->vCdcCtx)
        avcodec_free_context(&this->vCdcCtx);
    if(!this->vStream)
        this->vStream = nullptr;
    if (!this->swsCtx)
        sws_freeContext(this->swsCtx);
}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      在这个方法中实现强制清空改视频对象的帧队列
 */
void Video::makeFramesEmpty()
{
    this->frames.makeEmpty();
}

/**
 * @author       ParanoidRoot
 * @method       Video::run
 * @param        void
 * @return       void
 * @details      实现run方法, 从而做到多线程解码.
 *               索要做的事情是: 解码并向frames中放解码完的视频帧.
 */
void Video::run()
{
    while (true)
    {
        if (this->isTerminated)  // 这个解码过程被人为地终止了
        {
            cout << "decoding is terminated..." << endl;
//            this->makeFramesEmpty();  // 清空自己剩余未播放的帧
            this->isPlaying = false;
            return;
        }
        else  // 当前解码线程仍然需要被执行
        {
            AVPacket* pkt = av_packet_alloc();  // 保存的未解码的包
            AVFrame* decodedFrame = av_frame_alloc();  // 解码后的帧
            AVFrame* yuvFrame = av_frame_alloc();  // 转信息格式为yuv后的帧
            if ((av_read_frame(this->vFmtCtx, pkt)) >= 0)  // 解码成功
            {
                if (pkt->stream_index == this->vStreamIndex)  // 判断确实为视频流
                {
                    if (avcodec_send_packet(this->vCdcCtx, pkt) < 0)  // 发送包失败
                    {
                        cout << "send packet fail when decoding" << endl;
                        cout << "ending..." << endl;
//                        this->makeFramesEmpty();
                        this->isPlaying = false;
                        return;
                    }
                    if (avcodec_receive_frame(this->vCdcCtx, decodedFrame) < 0)
                    {
                        cout << "receive frame fail when decoding" << endl;
                        cout << "ending..." << endl;
//                        this->makeFramesEmpty();
                        this->isPlaying = false;
                        return;
                    }
                    sws_scale(this->swsCtx,
                              (const uint8_t* const*)decodedFrame->data,
                              decodedFrame->linesize, 0, this->vCdcCtx->height,
                              yuvFrame->data, yuvFrame->linesize);
                    ++this->decodedFrameNum;
                    cout << "has decoded " << this->decodedFrameNum << " frames" << endl;
                    this->addVFrame(yuvFrame);
                    cout << "the " << this->decodedFrameNum << " is added" << endl;
                }
                av_packet_free(&pkt);
            }
            else  // 读取失败
            {
                this->isPlaying = false;  // 解码完成最后一帧
                return ;
            }
        }
    }
}

bool Video::getIsPlaying() const
{
    return this->isPlaying;
}

void Video::setIsPlaying(bool value)
{
    isPlaying = value;
}

bool Video::getIsTerminated() const
{
    return isTerminated;
}

void Video::setIsTerminated(bool value)
{
    isTerminated = value;
}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      获取需要的头部的解码完的一帧
 */
AVFrame* Video::popVFrame()
{
    return this->frames.deQueue();
}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      获取视频的宽高
 */
int Video::getHeight() const
{
    return this->vCdcCtx->width;
}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      获取视频的高
 */
int Video::getWidth() const
{
    return this->vCdcCtx->height;
}

/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      实现外部对frames中添加解码完的frame
 */
void Video::addVFrame(const AVFrame* vFrame)
{
    this->frames.enQueue(vFrame);
}

