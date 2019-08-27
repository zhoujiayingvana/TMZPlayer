#include "videoplayer.h"
#include <QDebug>
#include <QByteArray>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

extern "C"
{
    #include <libavformat/avformat.h>
}

VideoPlayer::VideoPlayer(QObject *parent) : QObject(parent)
{

}

const char *VideoPlayer::toChars(const QString &qString)
{
    // 实现 QString 到 Chars 的转换
    char* p = nullptr;
    string str = qString.toStdString();
    p = new char[str.size() + 1];
    strcpy(p, str.c_str());
    return p;
}

void VideoPlayer::translate(const QString &_inFileAbsPath, const QString &_outFileAbsPath)
{
    // 在这个类中完成对视频格式封装的转换
    // 注意：不会改变视频的编码格式
    // 输入的文件的绝对路径以及输出的文件的绝对路径
    const char* inFileAbsPath = VideoPlayer::toChars(_inFileAbsPath);
    const char* outFileAbsPath = VideoPlayer::toChars(_outFileAbsPath);
    // 输出的视频格式
    AVOutputFormat *outFmt = nullptr;
    // 输入的视频内容，输出的视频内容
    AVFormatContext *inFmtCtx = nullptr, *outFmtCtx = nullptr;
    // 注册所有的
    // av_register_all();
    // 输入的初始工作
    int retVal = -1;
    // 打开输入文件
    retVal = avformat_open_input(&inFmtCtx, inFileAbsPath, nullptr, nullptr);
    if (retVal < 0)
    {
        // 打开失败
        cout << "无法打开输入文件!" << endl;
        cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
        return;
    }
    // 查找打开输入文件的信息
    retVal = avformat_find_stream_info(inFmtCtx, nullptr);
    if (retVal < 0)
    {
        // 查找信息失败
        cout << "无法获取输入文件的信息!" << endl;
        cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
        return;
    }
    // 打印信息
    av_dump_format(inFmtCtx, 0, inFileAbsPath, 0);
    // 输出的初始工作
    avformat_alloc_output_context2(&outFmtCtx, nullptr, nullptr, outFileAbsPath);
    if (!outFmtCtx)
    {
        cout << "无法创建输出封装!" << endl;
        retVal = AVERROR_UNKNOWN;
        cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
        return;
    }
    outFmt = outFmtCtx->oformat;
    for (int i = 0; i < inFmtCtx->nb_streams; ++i)
    {
        // 根据输入流创建输出流
        AVStream* inStream = inFmtCtx->streams[i];
        AVCodec* inDecoder = avcodec_find_decoder(inStream->codecpar->codec_id);
        // 给输出的 FormatContext 创建一个与当前输入流的编码格式一样的流，但是还没有参数
        // 注意这个输出流是绑定在 输出 FormatContext 实体上的
        AVStream* outStream = avformat_new_stream(outFmtCtx, inDecoder);
        if (!outStream)
        {
            cout << "无法创建输出流!" << endl;
            retVal = AVERROR_UNKNOWN;
            cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
            return;
        }
        // 把输入的流的编码格式复制到输出的流的编码格式
        // 分配一个与输入的流的编码格式一样的 编码格式Context(封装了的实体)
        AVCodecContext* pCdcCtx = avcodec_alloc_context3(inDecoder);
        // 再将输入的流的编码格式的参数传入
        retVal = avcodec_parameters_to_context(pCdcCtx, inStream->codecpar);
        if (retVal < 0)
        {
            cout << "复制格式失败!" << endl;
            cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
            return;
        }
        pCdcCtx->codec_tag = 0;
        if (outFmtCtx->oformat->flags & AVFMT_GLOBALHEADER)
        {
            pCdcCtx->flags |= AV_CODEC_FLAG_GLOBAL_HEADER;
        }
        // 再将这个临时的编码实体复制到输出的流的编码参数中
        retVal = avcodec_parameters_from_context(outStream->codecpar, pCdcCtx);  // 把编码内容复制到当前的流
        if (retVal < 0)
        {
            cout << "复制格式失败!" << endl;
            cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
            return;
        }
    }
    // 初始化 bit stream filter 用于过滤之后的每个 packet
    // 创建一个过滤器, 其是为了从 mp4 中提取 h264
    const AVBitStreamFilter* filter = av_bsf_get_by_name("h264_mp4toannexb");
    // 创建一个分装过的过滤器内容
    AVBSFContext* h264BSFCtx = nullptr;
    // 给 filter 分配空间
    retVal = av_bsf_alloc(filter, &h264BSFCtx);
    if (retVal < 0)
    {
        cout << "给字节过滤器分配空间失败!" << endl;
        cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
        return;
    }
    // 获取视频流的index
    int videoStreamIndex = VideoPlayer::getVStreamIndex(inFmtCtx);
    retVal = videoStreamIndex;
    if (retVal < 0)
    {
        cout << "获取视频流的序号失败!" << endl;
        cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
        return;
    }
    // 给音视频编码器的参数进行复制
    // 将输入视频流的编码格式分配给过滤器的输入端的编码格式
    avcodec_parameters_copy(h264BSFCtx->par_in, inFmtCtx->streams[videoStreamIndex]->codecpar);
    // 初始化过滤器内容
    av_bsf_init(h264BSFCtx);

    // 输出一下输出的格式
    av_dump_format(outFmtCtx, 0, outFileAbsPath, 1);
    cout << endl << "***************************************" << endl;

    // 打开输出文件
    if (!(outFmt->flags & AVFMT_NOFILE))
    {
        retVal = avio_open(&outFmtCtx->pb, outFileAbsPath, AVIO_FLAG_WRITE);
        if (retVal < 0)
        {
            cout << "无法打开输出文件!" << endl;
            cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
            return;
        }
    }
    // 写入文件头
    retVal = avformat_write_header(outFmtCtx, nullptr);
    if (retVal < 0)
    {
        cout << "无法写入输出文件的头文件!" << endl;
        cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
        return;
    }
    int frameIndex = 0;
    bool isFirstPkt = true;
    // 一帧视频的内容变量
    AVPacket *pkt = av_packet_alloc();
    while (true)
    {
        // 一帧一帧地读取信息
        AVStream* inStream, *outStream;
        retVal = av_read_frame(inFmtCtx, pkt);
        if (retVal < 0)
        {
            // 读完了
            break;
        }
        if (isFirstPkt && AV_NOPTS_VALUE == pkt->pts)
        {
            /**
             * 如果是第一个帧, 并且视频的展示时间戳为空的话
             * 则对其播放时间戳和解码时间戳
             */
            pkt->pts = pkt->dts;
            isFirstPkt = false;
        }
        // 确定当前是那个流(视频还是音频)
        inStream = inFmtCtx->streams[pkt->stream_index];
        outStream = outFmtCtx->streams[pkt->stream_index];
        // 复制这一帧的信息
        pkt->pts = av_rescale_q_rnd(pkt->pts, inStream->time_base, outStream->time_base,
                                   AV_ROUND_NEAR_INF);  // 用于表示什么时候播放视频的 stamp
        pkt->dts = av_rescale_q_rnd(pkt->dts, inStream->time_base, outStream->time_base,
                                   AV_ROUND_NEAR_INF);  // 用于表示什么时候解码视频的 stamp
        // 重新定位这一帧的持续时间
        pkt->duration = av_rescale_q(pkt->duration, inStream->time_base, outStream->time_base);
        pkt->pos = -1;  // 不知道这一帧的播放位置
        // 在写入之前进行过滤
        if (pkt->stream_index == videoStreamIndex)
        {
            // 如果当前帧所在的流索引即为视频流
            retVal = av_bsf_send_packet(h264BSFCtx, pkt);
            if (retVal < 0)
            {
                cout << "发送失败!" << endl;
                cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx) << endl;
                return;
            }
            while ((retVal = av_bsf_receive_packet(h264BSFCtx, pkt)) >= 0)
            {
                // 接受成功, 说明 1帧 中还有过滤完的数据要接受
                if ((retVal = av_interleaved_write_frame(outFmtCtx, pkt)) < 0)
                {
                    // 写入失败
                    cout << "写入一帧失败!" << endl;
                    break;
                }
            }
            cout << "######" << frameIndex + 1 << "######" << endl;
            av_packet_unref(pkt);  // 释放掉当前已经用过的 pkt
            ++frameIndex;
            continue;
        }
        // 写入这一祯到输出文件中去
        retVal = av_interleaved_write_frame(outFmtCtx, pkt);
        if (retVal < 0)
        {
            cout << "写入一帧失败!" << endl;
            break;
        }
        cout << "######" << frameIndex + 1 << "######" << endl;
        av_packet_unref(pkt);  // 释放掉当前已经用过的 pkt
        ++frameIndex;
    }
    // 写入文件尾
    av_write_trailer(outFmtCtx);
    // 结束
    cout << "ending..." << endl;
    cout << VideoPlayer::endTranslation(retVal, outFmt, &inFmtCtx, outFmtCtx);
    return;
}

int VideoPlayer::endTranslation(
        const int & retVal,
        AVOutputFormat *outFmt,
        AVFormatContext **inFmtCtx,
        AVFormatContext *outFmtCtx)
{
    avformat_close_input(inFmtCtx);
    if (outFmtCtx && !(outFmt->flags & AVFMT_NOFILE))
    {
        avio_close(outFmtCtx->pb);
    }
    avformat_free_context(outFmtCtx);
    if (retVal < 0 && retVal != AVERROR_EOF)
    {
        cout << "error!!!" << endl;
        return -1;
    }
    return 0;
}

int VideoPlayer::getVStreamIndex(const AVFormatContext *avFmtCtx)
{
    // 在这个方法中可以获取 AVFormatContext 的视频流的索引
    for (int i = 0; i < avFmtCtx->nb_streams; ++i)
    {
        AVStream *pStream = avFmtCtx->streams[i];
        if (pStream->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            // 如果当前是视频流
            return i;
        }
    }
    // 获取视频流失败
    return -1;
}
