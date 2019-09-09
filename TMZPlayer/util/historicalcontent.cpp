#include "historicalcontent.h"

HistoricalContent::HistoricalContent(QObject* parent,
                                     const QString& _fileName,
                                     const QString& _filePath,
                                     const bool& _isLocal,
                                     const int& _rank, const int64_t& _progressMillisecond)
    : QObject(parent), fileName(_fileName), filePath(_filePath),
      isLocal(_isLocal), rank(_rank), progressMilliSecond(_progressMillisecond),
      mediaContent(nullptr)
{
    this->checkFileName();
    this->rebuildContent();
}

void HistoricalContent::checkFileName()
{
    if (!Helper::isLegalName(this->fileName))
        throw MyErrors::NAME_ERROR;
}

void HistoricalContent::checkProgressMilliSecond()
{
    if (this->progressMilliSecond < 0)
        throw MyErrors::PROGRESS_MILLI_SECOND_ERROR;
}

HistoricalContent::~HistoricalContent()
{
    this->makeEmpty();
}

HistoricalContent::HistoricalContent(const HistoricalContent& other)
    : fileName(other.fileName), filePath(other.filePath), isLocal(other.isLocal),
      rank(other.rank), progressMilliSecond(other.progressMilliSecond), mediaContent(nullptr)
{
    this->rebuildContent();
}

HistoricalContent& HistoricalContent::operator=(const HistoricalContent& other)
{
    this->makeContentEmpty();
    this->fileName = other.fileName;
    this->filePath = other.filePath;
    this->isLocal = other.isLocal;
    this->rank = other.rank;
    this->progressMilliSecond = other.progressMilliSecond;
    this->rebuildContent();
    return *this;
}

void HistoricalContent::testPrint() const
{
    qDebug() << this->fileName << endl
             << this->filePath << endl
             << this->isLocal << endl
             << this->rank << endl
             << this->progressMilliSecond << endl;
}

void HistoricalContent::makeContentEmpty()
{
    if (this->mediaContent)
        delete this->mediaContent;
    this->mediaContent = nullptr;
}

void HistoricalContent::makeEmpty()
{
    this->makeContentEmpty();
}

bool HistoricalContent::isAccessibleFilePath()
{
    if (this->isLocal)
        return this->filePath != nullptr && Helper::isLocalFile(this->filePath);
    else
        return this->filePath != nullptr;
}

void HistoricalContent::rebuildContent()
{
    this->makeContentEmpty();
    if (this->isAccessibleFilePath())  // 文件合法可以访问
        if (this->isLocal)  // 本地文件
        {
//            this->filePath = Helper::toAbsPath(this->filePath);
            this->mediaContent = new QMediaContent(QUrl::fromLocalFile(this->filePath));
        }
        else  // 网络 url
            this->mediaContent = new QMediaContent(QUrl(this->filePath));
    else
        throw MyErrors::FILE_PATH_ERROR;
}

QMediaContent* HistoricalContent::getMediaContent() const
{
    return mediaContent;
}

int64_t HistoricalContent::getProgressMilliSecond() const
{
    return progressMilliSecond;
}

void HistoricalContent::setProgressMilliSecond(const int64_t& value)
{
    progressMilliSecond = value;
}

MediaType HistoricalContent::getMediaType() const
{
    QFileInfo fileInfo(this->filePath);
    return MediaTypeHelper::getType(fileInfo.suffix());
}

int HistoricalContent::getRank() const
{
    return rank;
}

void HistoricalContent::setRank(int value)
{
    rank = value;
}

bool HistoricalContent::getIsLocal() const
{
    return isLocal;
}

void HistoricalContent::setIsLocal(bool value)
{
    isLocal = value;
}

QString HistoricalContent::getFilePath() const
{
    return filePath;
}

void HistoricalContent::setFilePath(const QString& value)
{
    filePath = value;
}

QString HistoricalContent::getFileName() const
{
    return fileName;
}

void HistoricalContent::setFileName(const QString& value)
{
    fileName = value;
}
