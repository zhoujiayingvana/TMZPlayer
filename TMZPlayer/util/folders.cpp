#include "folders.h"

Folders::Folders(QObject *parent, const QString& _userName)
    : QObject(parent), rank2Folder(nullptr), folderName2Rank(nullptr), pNext(0),
      userName(_userName), pChosen(-1)
{
    this->rank2Folder = new QMap<int, Folder>();
    this->folderName2Rank = new QMap<QString, int>();
}

Folders::Folders(const Folders& other)
    : QObject(nullptr), rank2Folder(nullptr), folderName2Rank(nullptr), pNext(other.pNext),
      userName(other.userName), pChosen(other.pChosen)
{
    this->rank2Folder = new QMap<int, Folder>(*other.rank2Folder);
    this->folderName2Rank = new QMap<QString, int>(*other.folderName2Rank);
}

Folders& Folders::operator=(const Folders& other)
{
    this->makeEmpty();
    this->pNext = other.pNext;
    this->userName = other.userName;
    this->pChosen = other.pChosen;
    this->rank2Folder = new QMap<int, Folder>(*other.rank2Folder);
    this->folderName2Rank = new QMap<QString, int>(*other.folderName2Rank);
}

Folders::~Folders()
{
    this->makeEmpty();
}

void Folders::startInit()
{
    FoldersIniter* pThread = new FoldersIniter(this);
    pThread->run();
}

void Folders::startClose()
{
    FoldersCloser* pThread = new FoldersCloser(this);
    pThread->run();
}

void Folders::removeContentFromFolder(const int& _folderIndex,
                                      const int& _contentIndex)
{
    if (!this->rank2Folder->keys().contains(_folderIndex))
        throw MyErrors::FOLDER_INDEX_ERROR;
    (*this->rank2Folder)[_folderIndex].removeContent(_contentIndex);
}

void Folders::moveFolderContent(const int& _folderIndex,
                                const int& _toFolderContentIndex,
                                const int& _fromFolderContentIndex)
{
    if (!this->rank2Folder->keys().contains(_folderIndex))
        throw MyErrors::FOLDER_INDEX_ERROR;
    (*this->rank2Folder)[_folderIndex].moveContent(_toFolderContentIndex,
                                                    _fromFolderContentIndex);
}

void Folders::moveFolder(const int& _toFolderIndex, const int& _fromFolderIndex)
{
    if (!this->rank2Folder->keys().contains(_toFolderIndex) ||
        !this->rank2Folder->keys().contains(_fromFolderIndex))
        throw MyErrors::FOLDER_INDEX_ERROR;
    int biggerIndex = -1, smallerIndex = -1;
    if (_toFolderIndex < _fromFolderIndex)
    {
        biggerIndex = _fromFolderIndex;
        smallerIndex = _toFolderIndex;
        Folder temp((*this->rank2Folder)[biggerIndex]);
        for (int i = biggerIndex; i > smallerIndex; --i)
        {
            (*this->rank2Folder)[i] = (*this->rank2Folder)[i - 1];
            (*this->rank2Folder)[i].setRank(i);
        }
        (*this->rank2Folder)[smallerIndex] = temp;
        (*this->rank2Folder)[smallerIndex].setRank(smallerIndex);
    }
    else
    {
        biggerIndex = _toFolderIndex;
        smallerIndex = _fromFolderIndex;
        Folder temp((*this->rank2Folder)[smallerIndex]);
        for (int i = smallerIndex; i < biggerIndex; ++i)
        {
            (*this->rank2Folder)[i] = (*this->rank2Folder)[i + 1];
            (*this->rank2Folder)[i].setRank(i);
        }
        (*this->rank2Folder)[biggerIndex] = temp;
        (*this->rank2Folder)[biggerIndex].setRank(biggerIndex);
    }
}

void Folders::addContent2Folder(const QString& _folderName,
                                const FolderContent& _folderContent)
{
    const QString _fileName = _folderContent.getFolderName();
    const QString _filePath = _folderContent.getFilePath();
    const bool _isLocal = _folderContent.getIsLocal();
    this->addContent2Folder(_folderName, _fileName, _filePath, _isLocal);
}

QMap<QString, int>* Folders::getFolderName2Index() const
{
    return folderName2Rank;
}

void Folders::testPrint() const
{
    for (int i = 0; i < this->pNext; ++i)
        (*this->rank2Folder)[i].testPrint();
}

void Folders::makeIndex2FolderEmpty()
{
    if (this->rank2Folder)
    {
        this->rank2Folder->clear();
        delete this->rank2Folder;
    }
    this->rank2Folder = nullptr;
}

void Folders::makeFolderName2IndexEmpty()
{
    if (this->folderName2Rank)
    {
        this->folderName2Rank->clear();
        delete this->folderName2Rank;
    }
    this->folderName2Rank = nullptr;
}

void Folders::makePChosenEmpty()
{
    this->pChosen = -1;
}

void Folders::makeEmpty()
{
    this->makeIndex2FolderEmpty();
    this->makeFolderName2IndexEmpty();
    this->makePChosenEmpty();
}

bool Folders::hasFolderName(const QString& _folderName)
{
    return this->folderName2Rank->keys().contains(_folderName);
}

void Folders::addNewFolder(const QString& _folderName)
{
    if (!Helper::isLegalName(_folderName) ||
        this->hasFolderName(_folderName))
        throw MyErrors::NAME_ERROR;
    this->folderName2Rank->insert(_folderName, this->pNext);
    Folder tempFolder(nullptr, _folderName, this->pNext);
    this->rank2Folder->insert(this->pNext, tempFolder);
    ++this->pNext;
}

QList<QString> Folders::getFolderNames() const
{
    return this->folderName2Rank->keys();
}

Folder& Folders::getFolder(const int& _index)
{
    if (!this->rank2Folder->keys().contains(_index))
        throw MyErrors::FOLDER_INDEX_ERROR;
    return (*this->rank2Folder)[_index];
}

Folder& Folders::getFolder(const QString& _folderName)
{
    if (!this->folderName2Rank->keys().contains(_folderName))
        throw MyErrors::FOLDER_INDEX_ERROR;
    return this->getFolder((*this->folderName2Rank)[_folderName]);
}

void Folders::removeFolder(const int& _index)
{
    if (!this->rank2Folder->keys().contains(_index))
        throw MyErrors::FOLDER_INDEX_ERROR;
    this->folderName2Rank->remove((*this->rank2Folder)[_index].getFolderName());
    for (int i = _index; i < this->pNext - 1; ++i)
    {
        (*this->rank2Folder)[i] = (*this->rank2Folder)[i + 1];
        (*this->rank2Folder)[i].setRank(i);
    }
    this->rank2Folder->remove(this->pNext - 1);
    --this->pNext;
}

void Folders::renameFolder(const int& _index, const QString& _newFolderName)
{
    if (!Helper::isLegalName(_newFolderName))
        throw MyErrors::NAME_ERROR;
    if (!this->rank2Folder->keys().contains(_index))
        throw MyErrors::FOLDER_INDEX_ERROR;
    if (this->folderName2Rank->keys().contains(_newFolderName))
        throw MyErrors::NAME_ERROR;
    QString oldFolderName = (*this->rank2Folder)[_index].getFolderName();
    this->folderName2Rank->remove(oldFolderName);
    this->folderName2Rank->insert(_newFolderName, _index);
    (*this->rank2Folder)[_index].setFolderName(_newFolderName);
}

void Folders::addContent2Folder(const int& _index,
                                const QString& _fileName,
                                const QString& _filePath,
                                const bool& _isLocal)
{
    if (!this->rank2Folder->keys().contains(_index))
        throw MyErrors::FOLDER_INDEX_ERROR;
    const QString folderName = (*this->rank2Folder)[_index].getFolderName();
    FolderContent folderContent(nullptr,
                                folderName, _fileName, _filePath,
                                _isLocal, -1, nullptr);
    (*this->rank2Folder)[_index].addAndSetRankContent(folderContent);
}

void Folders::addContent2Folder(const QString& _folderName,
                                const QString& _fileName,
                                const QString& _filePath,
                                const bool& _isLocal)
{
    if (!this->folderName2Rank->keys().contains(_folderName))
        throw MyErrors::NAME_ERROR;
    int index = (*this->folderName2Rank)[_folderName];
    this->addContent2Folder(index, _fileName, _filePath, _isLocal);
}

QString Folders::getUserName() const
{
    return userName;
}

void Folders::setUserName(const QString& value)
{
    userName = value;
}

int Folders::getPChosen() const
{
    return pChosen;
}

void Folders::setPChosen(int value)
{
    if (this->hasChosen())
    {
        const int tempPChosen = this->pChosen;
        (*this->rank2Folder)[tempPChosen].makePChosenEmpty();  // 切换前清空上次
                                                               // 选中的收藏夹中的选中的内容
    }
    pChosen = value;
}

bool Folders::hasChosen() const
{
    return this->pChosen >= 0 && this->pChosen < this->pNext;
}

void Folders::moveChosen2Next()
{
    if (!this->hasChosen())
        throw MyErrors::FOLDER_UNCHOSEN_ERROR;
    if (this->pChosen >= this->pNext - 1)  // 是最后一个
        throw MyErrors::NO_NEXT_FOLDER_ERROR;
    else
        ++this->pChosen;
}

void Folders::moveChosen2Last()
{
    if (!this->hasChosen())
        throw MyErrors::FOLDER_UNCHOSEN_ERROR;
    if (0 == this->pChosen)
        throw MyErrors::NO_NEXT_FOLDER_ERROR;
    else
        --this->pChosen;
}

FolderContent& Folders::getPointedFolderContent()
{
    return this->getPointedFolder().getPointedContent();
}

QMediaContent* Folders::getPointedMediaContent()
{
    return this->getPointedFolderContent().getMediaContent();
}

Folder& Folders::getPointedFolder()
{
    if (!this->hasChosen())
        throw MyErrors::FOLDER_UNCHOSEN_ERROR;
    return this->getFolder(this->pChosen);
}

int Folders::getNextRankOfPointedFolder(const PlayOrder& playOrder) const
{
    return (*this->rank2Folder)[this->pChosen].getNextRankByPlayOrder(playOrder);
}

void Folders::addChosenFolderContent2Histories(Histories& _histories)
{
    const QString fileName = this->getPointedFolderContent().getFileName();
    const QString filePath = this->getPointedFolderContent().getFilePath();
    const bool isLocal = this->getPointedFolderContent().getIsLocal();
    const QStringList paths = _histories.getAllPaths();
    if (paths.contains(filePath))  // 如果存在则移动
        _histories.move2First(filePath);
    else  // 不存在则加入
        _histories.addContent(fileName, filePath, isLocal, 0);
}
