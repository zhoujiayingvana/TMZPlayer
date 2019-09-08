/**
  调试用，统一管理调试所需变量
  */
#include "debug.h"

Debug::Debug(QWidget *parent) : QWidget(parent)
{
    QUrl url;
    url.setUrl("../vid/t3.avi");//
    this->mediaContent=new QMediaContent(url);
}

bool Debug::isFileDirExits(QString filePath)
{
    QFileInfo fileInfo(filePath);
    if(fileInfo.isDir())
    {
        return true;
    }
        return false;
}

bool Debug::isFileExits(QString fullPath)
{
    QFileInfo fileInfo(fullPath);
    if(fileInfo.isFile()){
        return true;
    }
    return false;
}

bool Debug::isScresenCutFormatLegal(QString format)
{
    if(format.compare(QString("jpg"))||
            format.compare(QString("png"))||
            format.compare((QString("webp")))){
        return true;
    }
    return false;
}

char* Debug::QString2Char(QString str)
{
    char* ch;
    QByteArray ba=str.toUtf8();
    ch=ba.data();
    return ch;
}



const QString Debug::getDebugErrorType(const MyErrors& err)
{
    switch(err)
    {
    case MyErrors::FILE_PATH_ERROR:
        return QString("File path Error");
    case MyErrors::FILE_NAME_ERROR:
        return QString("File name Error");
    case MyErrors::NULLPTR_ERROR:
        return QString("Nullptr Error");
    case MyErrors::TIMEOUT_ERROR:
        return QString("Time out Error");
    case MyErrors::SCREEN_CUT_FORMAT_ERROR:
        return QString("Screen cur format Error");
    case MyErrors::FILE_EXIT_ERROR:
        return QString("File exit Error");
    case MyErrors::GIF_IMAGE_EXIT_ERROR:
        return QString("Gif image exit Error");
    default:
        return QString("Unknown Error");
    }
}





