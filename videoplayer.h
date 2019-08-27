#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QObject>

extern "C"
{
    #include <libavformat/avformat.h>
    #include <libavcodec/avcodec.h>
}

class VideoPlayer : public QObject
{
    Q_OBJECT
public:
    explicit VideoPlayer(QObject *parent = nullptr);
    static const char* toChars(const QString&);
    static void translate(const QString& _inFileAbsPath, const QString& _outFileAbsPath);
    static int endTranslation(const int&, AVOutputFormat*, AVFormatContext**, AVFormatContext*);
    static int getVStreamIndex(const AVFormatContext *avFmtCtx);
signals:

public slots:
};

#endif // VIDEOPLAYER_H
