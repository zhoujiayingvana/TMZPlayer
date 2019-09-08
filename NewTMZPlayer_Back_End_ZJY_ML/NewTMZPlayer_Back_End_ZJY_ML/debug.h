/**
  调试用，统一管理调试所需变量
  */
#ifndef DEBUG_H
#define DEBUG_H

#include <QWidget>
#include <QMediaPlayer>
#include <QUrl>
#include <QFileInfo>

class Debug : public QWidget
{
    Q_OBJECT
public:


    explicit Debug(QWidget *parent = nullptr);
    QMediaContent *mediaContent;
    //判断文件路径是否错误，需要文件夹路径，不包含文件
    static bool isFileDirExits(QString filePath);
    //判断文件是否存在，需要文件完整路径
    static bool isFileExits(QString fullPath);
    //判断截图保存格式是否合法，仅支持常用图片格式jpg，png，webp
    static bool isScresenCutFormatLegal(QString format);
    static char* QString2Char(QString str);
    
    
    
    //文件路径错误，文件名错误，空指针错误，超时错误
    enum MyErrors{
        FILE_PATH_ERROR,FILE_NAME_ERROR,FILE_EXIT_ERROR,
        NULLPTR_ERROR,TIMEOUT_ERROR,
        SCREEN_CUT_FORMAT_ERROR,GIF_IMAGE_EXIT_ERROR
    };
    //返回错误
    const static QString getDebugErrorType(const MyErrors& err);

signals:
    
public slots:
};

#endif // DEBUG_H
