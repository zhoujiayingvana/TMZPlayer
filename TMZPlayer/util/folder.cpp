#include "folder.h"

Folder::Folder(QObject *parent, const QString& _folderName, const int& _rank)
    : QObject(parent), folderName(_folderName), container(nullptr), pNext(0),
      fileNames(nullptr), rank(_rank), pChosen(-1)
{
    if (!Helper::isLegalName(this->folderName))
        throw MyErrors::NAME_ERROR;
    this->container = new QMap<int, FolderContent>();
    this->fileNames = new QSet<QString>();
}

Folder::Folder(const Folder& other)
    : QObject(nullptr), folderName(other.folderName), container(nullptr), pNext(other.pNext),
      fileNames(nullptr), rank(other.rank), pChosen(other.pChosen)
{
    this->container = new QMap<int, FolderContent>(*other.container);  // 深拷贝
    this->fileNames = new QSet<QString>(*other.fileNames);
}

Folder& Folder::operator=(const Folder& other)
{
    this->makeEmpty();
    this->folderName = other.folderName;
    this->pNext = other.pNext;
    this->rank = other.rank;
    this->pChosen = other.pChosen;
    this->container = new QMap<int, FolderContent>(*other.container);
    this->fileNames = new QSet<QString>(*other.fileNames);
    return *this;
}

Folder::~Folder()
{
    this->makeEmpty();
}

void Folder::testPrint() const
{
    for (int i = 0; i < this->pNext; ++i)
        (*this->container)[i].testPrint();
}

FolderContent& Folder::getFolderContent(const int& _index) const
{
    if (!this->container->keys().contains(_index))
        throw MyErrors::CONTENT_INDEX_ERROR;
    return (*this->container)[_index];
}

QString Folder::getFileName(const int& _index) const
{
    FolderContent folderContent = this->getFolderContent(_index);
    return folderContent.getFileName();
}

QList<QString> Folder::getFileNames() const
{
    return this->fileNames->toList();
}

void Folder::makeContainerEmpty()
{
    if (this->container)
    {
        this->container->clear();
        delete this->container;
    }
    this->container = nullptr;
}

void Folder::makeFileNamesEmpty()
{
    if (this->fileNames)
    {
        this->fileNames->clear();
        delete  this->fileNames;
    }
    this->fileNames = nullptr;
}

void Folder::makePChosenEmpty()
{
    this->pChosen = -1;
}

void Folder::makeEmpty()
{
    this->makeContainerEmpty();
    this->makeFileNamesEmpty();
    this->makePChosenEmpty();
}

bool Folder::hasFile(const QString& fileName) const
{
    return this->fileNames->contains(fileName);
}

void Folder::addAndSetRankContent(FolderContent& folderContent)
{
    const QString _fileName(folderContent.getFileName());
    const QString _folderName(folderContent.getFolderName());
    if (this->hasFile(_fileName))  // 文件同名或者收藏夹不匹配都不接受加入
        throw MyErrors::NAME_ERROR;
    if (this->folderName.compare(_folderName, Qt::CaseSensitive) != 0)
        throw MyErrors::CONTENT_INDEX_ERROR;
    folderContent.setRank(this->pNext);
    this->fileNames->insert(_fileName);
    this->container->insert(this->pNext, folderContent);
    ++this->pNext;
}

void Folder::removeContent(const int& index)
{
    // 根据在收藏夹中的相对位置来删除文件
    if (!this->container->keys().contains(index))
        throw MyErrors::CONTENT_INDEX_ERROR;
    this->fileNames->remove((*this->container)[index].getFileName());
    for (int i = index; i < this->pNext - 1; ++i)
    {
        (*this->container)[i] = (*this->container)[i + 1];
        (*this->container)[i].setRank(i);
    }
    this->container->remove(this->pNext - 1);  // 移除最后一个元素
    --this->pNext;
}

QString Folder::getFolderName() const
{
    return folderName;
}

void Folder::setFolderName(const QString& value)
{
    this->folderName = value;
    for (int i = 0; i < this->pNext; ++i)
        (*this->container)[i].setFolderName(this->folderName);
}

QMap<int, FolderContent>* Folder::getContainer() const
{
    return container;
}

void Folder::moveContent(const int& _toIndex, const int& _fromIndex)
{
    if (!this->container->keys().contains(_toIndex) ||
        !this->container->keys().contains(_fromIndex) ||
        _toIndex == _fromIndex)
        throw MyErrors::CONTENT_INDEX_ERROR;
    int biggerIndex = -1, smallerIndex = -1;
    if (_toIndex < _fromIndex)
    {
        biggerIndex = _fromIndex;
        smallerIndex = _toIndex;
        FolderContent temp((*this->container)[biggerIndex]);
        for (int i = biggerIndex; i > smallerIndex; --i)
        {
            (*this->container)[i] = (*this->container)[i - 1];
            (*this->container)[i].setRank(i);
        }
        (*this->container)[smallerIndex] = temp;
        (*this->container)[smallerIndex].setRank(smallerIndex);
    }
    else
    {
        biggerIndex = _toIndex;
        smallerIndex = _fromIndex;
        FolderContent temp((*this->container)[smallerIndex]);
        for (int i = smallerIndex; i < biggerIndex; ++i)
        {
            (*this->container)[i] = (*this->container)[i + 1];
            (*this->container)[i].setRank(i);
        }
        (*this->container)[biggerIndex] = temp;
        (*this->container)[biggerIndex].setRank(biggerIndex);
    }
}

void Folder::updateRanks(const int& _fromIndex)
{
    if (!this->container->keys().contains(_fromIndex))
        throw MyErrors::CONTENT_INDEX_ERROR;
    for (int i = _fromIndex; i < this->pNext; ++i)
        (*this->container)[i].setRank(i);
}

int Folder::getRank() const
{
    return rank;
}

void Folder::setRank(int value)
{
    rank = value;
}

QList<FolderContent> Folder::getFolderContents() const
{
    QList<FolderContent> ansList;
    for (int i = 0; i < this->pNext; ++i)
        ansList.append(this->getFolderContent(i));
    return ansList;
}

int Folder::getPChosen() const
{
    return pChosen;
}

void Folder::setPChosen(int value)
{
    if (value < 0 || value >= this->pNext)
        throw MyErrors::FOLDER_CONTENT_SELECT_ERROR;
    pChosen = value;
}

bool Folder::hasChosen() const
{
    return this->pChosen >= 0 && this->pChosen < this->pNext;
}

void Folder::moveChosen2Next()
{
    if (!this->hasChosen())
        throw MyErrors::FOLDER_CONTENT_UNCHOSEN_ERROR;
    if (this->pChosen == this->pNext - 1)
        throw MyErrors::NO_NEXT_FOLDER_CONTENT_ERROR;
    else
        ++this->pChosen;
}

void Folder::moveChosen2Last()
{
    if (!this->hasChosen())
        throw MyErrors::FOLDER_UNCHOSEN_ERROR;
    if (0 == this->pChosen)
        throw MyErrors::NO_NEXT_FOLDER_CONTENT_ERROR;
    else
        --this->pChosen;
}

FolderContent& Folder::getPointedContent()
{
    if (!this->hasChosen())
        throw MyErrors::FOLDER_CONTENT_UNCHOSEN_ERROR;
    else
        return this->getFolderContent(this->pChosen);
}

bool Folder::isEmptyFolder() const
{
    return 0 == this->pNext;
}

int Folder::getNextRankByPlayOrder(const PlayOrder& playOrder) const
{
    if (!this->hasChosen())  // 如果当前未被选中
        throw MyErrors::FOLDER_CONTENT_UNCHOSEN_ERROR;
    if (PlayOrder::ORDER_PLAY == playOrder)  // 如果是列表一次顺序播放, 不会播完循环, 会返回 -1
    {
        if (this->pChosen >= this->pNext - 1)
            return -1;
        else
            return this->pChosen + 1;
    }
    else if (PlayOrder::ORDER_CYCLE == playOrder)  // 列表循环的方式来播放, 会循环, 无 -1
    {
        if (this->pChosen >= this->pNext - 1)
            return 0;
        else
            return this->pChosen + 1;
    }
    else if (PlayOrder::SHUFFLE == playOrder)  // 随机播放不会返回 -1
        return QRandomGenerator::global()->bounded(this->pNext);
    else if (PlayOrder::SINGLE_CYCLE == playOrder)  // 单曲循环
        return this->pChosen;
    else
        throw MyErrors::PLAY_ORDER_ERROR;
}
