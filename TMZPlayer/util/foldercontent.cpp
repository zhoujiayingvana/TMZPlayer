#include "foldercontent.h"

FolderContent::FolderContent(QObject* parent,
                             const QString& _folderName, const QString& _fileName,
                             const QString& _filePath,
                             const bool& _isLocal, const int& _rank,
                             QMediaContent* _mediaContent)
    : QObject(parent),
      folderName(_folderName), fileName(_fileName), filePath(_filePath),
      isLocal(_isLocal), rank(_rank), mediaContent(_mediaContent)
{
    if (!Helper::isLegalName(this->fileName) || !Helper::isLegalName(this->folderName))
        throw MyErrors::NAME_ERROR;
    this->rebuildContent();
}

FolderContent::FolderContent(const FolderContent& other)
    : QObject (nullptr),
      folderName(other.folderName), fileName(other.fileName), filePath(other.filePath),
      isLocal(other.isLocal), rank(other.rank), mediaContent(nullptr)
{
    this->rebuildContent();
}

FolderContent& FolderContent::operator=(const FolderContent& other)
{
    this->makeContentEmpty();
    this->folderName = other.folderName;
    this->fileName = other.fileName;
    this->filePath = other.filePath;
    this->isLocal = other.isLocal;
    this->rank = other.rank;
    this->rebuildContent();
    return *this;
}

FolderContent::~FolderContent()
{
    this->makeEmpty();
}

void FolderContent::testPrint() const
{
    qDebug() << this->folderName << endl
             << this->fileName << endl
             << this->filePath << endl
             << this->isLocal << endl
             << this->rank << endl;
}

bool FolderContent::isAccessibleFilePath() const
{
    if (this->isLocal)
        return this->filePath != nullptr && Helper::isLocalFile(this->filePath);
    else
        return this->filePath != nullptr;
}

void FolderContent::makeContentEmpty()
{
    if (this->mediaContent)
        delete this->mediaContent;
    this->mediaContent = nullptr;
}

void FolderContent::makeEmpty()
{
    this->makeContentEmpty();
}

void FolderContent::rebuildContent()
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

int FolderContent::getRank() const
{
    return rank;
}

void FolderContent::setRank(int value)
{
    rank = value;
}

QMediaContent* FolderContent::getMediaContent() const
{
    return mediaContent;
}

MediaType FolderContent::getMediaType() const
{
    QFileInfo fileInfo(this->filePath);
    return MediaTypeHelper::getType(fileInfo.suffix());
}

bool FolderContent::getIsLocal() const
{
    return isLocal;
}

QString FolderContent::getFilePath() const
{
    return filePath;
}

QString FolderContent::getFileName() const
{
    return fileName;
}

void FolderContent::setFileName(const QString& value)
{
    fileName = value;
}

void FolderContent::setFolderName(const QString& value)
{
    folderName = value;
}

QString FolderContent::getFolderName() const
{
    return folderName;
}
