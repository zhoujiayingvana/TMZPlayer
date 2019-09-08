#include "histories.h"

Histories::Histories(QObject* parent,
                     const QString& _userName,
                     const int& _maxSize)
    : QObject(parent), userName(_userName), maxSize(_maxSize),
      pNext(0), rank2content(nullptr), pChosen(-1)
{
    this->checkMaxNumber();
    this->rank2content = new QMap<int, HistoricalContent>();
}

Histories::Histories(const Histories& other)
    : QObject(nullptr), userName(other.userName), maxSize(other.maxSize),
      pNext(other.pNext), rank2content(nullptr), pChosen(other.pChosen)
{
    this->rank2content = new QMap<int, HistoricalContent>(*other.rank2content);
}

Histories& Histories::operator =(const Histories& other)
{
    this->makeMapEmpty();
    this->userName = other.userName;
    this->maxSize = other.maxSize;
    this->pNext = other.pNext;
    this->pChosen = other.pChosen;
    this->rank2content = new QMap<int, HistoricalContent>(*other.rank2content);
}

void Histories::testPrint() const
{
    for (int i = 0; i < this->pNext; ++i)
        (*this->rank2content)[i].testPrint();
}

void Histories::makeMapEmpty()
{
    if (this->rank2content)
        delete this->rank2content;
    this->rank2content = nullptr;
}

void Histories::makeEmpty()
{
    this->makeMapEmpty();
}

void Histories::checkMaxNumber() const
{
    if (this->maxSize <= 0)
        throw MyErrors::HISTORIES_MAX_NUMBER_ERROR;
}

bool Histories::hasRemainedPlace() const
{
    return this->pNext < this->maxSize;
}

void Histories::addContent(const QString& _fileName,
                           const QString& _filePath,
                           const bool& _isLocal,
                           const int64_t& _progressMillisecond)
{
    HistoricalContent temp(nullptr, _fileName, _filePath, _isLocal, 0, _progressMillisecond);
    int maxIndex = -1;
    if (this->hasRemainedPlace())
    {
        maxIndex = this->pNext;
        ++this->pNext;
    }
    else
        maxIndex = this->pNext - 1;
    for (int i = maxIndex; i > 0; --i)
    {
        this->rank2content->insert(i, (*this->rank2content)[i - 1]);
        (*this->rank2content)[i].setRank(i);
    }
    this->rank2content->insert(0, temp);
}

void Histories::addContent(const HistoricalContent& _historicalContent)
{
    const QString _fileName = _historicalContent.getFileName();
    const QString _filePath = _historicalContent.getFilePath();
    const bool _isLocal = _historicalContent.getIsLocal();
    const int64_t _progressMillisecond = _historicalContent.getProgressMilliSecond();
    this->addContent(_fileName, _filePath, _isLocal, _progressMillisecond);
}

void Histories::removeContent(const int& _rank)
{
    if (_rank < 0 || _rank >= this->pNext)
        throw MyErrors::CONTENT_INDEX_ERROR;
    for (int i = _rank; i < this->pNext - 1; ++i)
    {
        (*this->rank2content)[i] = (*this->rank2content)[i + 1];
        (*this->rank2content)[i].setRank(i);
    }
    this->rank2content->remove(this->pNext - 1);
    --this->pNext;
}

HistoricalContent& Histories::getHistoricalContent(const int& _rank) const
{
    if (_rank < 0 || _rank >= this->pNext)
        throw MyErrors::CONTENT_INDEX_ERROR;
    return (*this->rank2content)[_rank];
}

QString Histories::getUserName() const
{
    return userName;
}

void Histories::setUserName(const QString& value)
{
    userName = value;
}

int Histories::getMaxSize() const
{
    return maxSize;
}

QList<HistoricalContent> Histories::getAllContents() const
{
    QList<HistoricalContent> ansList;
    for (int i = 0; i < this->pNext; ++i)
        ansList.append(this->getHistoricalContent(i));
    return ansList;
}

void Histories::startInit()
{
    HistoriesIniter* pIniter = new HistoriesIniter(this);
    pIniter->run();
}

void Histories::startClose()
{
    HistoriesCloser* pCloser = new HistoriesCloser(this);
    pCloser->run();
}

void Histories::moveContent(const int& _toContentIndex, const int& _fromContentIndex)
{
    if (_toContentIndex < 0 || _toContentIndex >= this->pNext ||
        _fromContentIndex < 0 || _fromContentIndex >= this->pNext ||
        _fromContentIndex == _toContentIndex)
        throw MyErrors::CONTENT_INDEX_ERROR;
    if (_fromContentIndex > _toContentIndex)
    {
        HistoricalContent temp = (*this->rank2content)[_fromContentIndex];
        for (int i = _fromContentIndex; i > _toContentIndex; --i)
        {
            (*this->rank2content)[i] = (*this->rank2content)[i - 1];
            (*this->rank2content)[i].setRank(i);
        }
        (*this->rank2content)[_toContentIndex] = temp;
        (*this->rank2content)[_toContentIndex].setRank(_toContentIndex);
    }
    else
    {
        HistoricalContent temp = (*this->rank2content)[_fromContentIndex];
        for (int i = _fromContentIndex; i < _toContentIndex; ++i)
        {
            (*this->rank2content)[i] = (*this->rank2content)[i + 1];
            (*this->rank2content)[i].setRank(i);
        }
        (*this->rank2content)[_toContentIndex] = temp;
        (*this->rank2content)[_toContentIndex].setRank(_toContentIndex);
    }
}

int Histories::getPChosen() const
{
    return pChosen;
}

void Histories::setPChosen(int value)
{
    if (value < 0 || value >= this->pNext)
        throw MyErrors::HISTORICAL_CONTENT_SELECT_ERROR;
    pChosen = value;
}

bool Histories::hasChosen() const
{
    return this->pChosen >= 0 && this->pChosen < this->pNext;
}

void Histories::moveChosen2Next()
{
    if (!this->hasChosen())
        throw MyErrors::HISTORICAL_CONTENT_UNCHOSEN_ERROR;
    if (this->pChosen == this->pNext - 1)
        throw MyErrors::NO_NEXT_HISTORICAL_CONTENT_ERROR;
    else
        ++this->pChosen;
}

void Histories::moveChosen2Last()
{
    if (!this->hasChosen())
        throw MyErrors::HISTORICAL_CONTENT_UNCHOSEN_ERROR;
    if (0 == this->pChosen)
        throw MyErrors::NO_NEXT_HISTORICAL_CONTENT_ERROR;
    else
        --this->pChosen;
}

HistoricalContent& Histories::getPointedHistoricalContent()
{
    if (this->hasChosen())
        return this->getHistoricalContent(this->pChosen);
    else
        throw MyErrors::HISTORICAL_CONTENT_UNCHOSEN_ERROR;
}

QMediaContent* Histories::getPointedMediaContent()
{
    return this->getPointedHistoricalContent().getMediaContent();
}

bool Histories::isEmpty() const
{
    return 0 == this->pNext;
}

int Histories::getNextRankByPlayOrder(const PlayOrder& playOrder) const
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

QStringList Histories::getAllPaths() const
{
    QStringList paths;
    for (int i = 0; i < this->pNext; ++i)
        paths.append((*this->rank2content)[i].getFilePath());
    return paths;
}

void Histories::move2First(const QString& _filePath)
{
    int wdWhere = -1;
    for (int i = 0; i < this->pNext; ++i)
        if (_filePath.compare((*this->rank2content)[i].getFilePath()) == 0)
            wdWhere = i;
    this->moveContent(0, wdWhere);
}

QMap<int, HistoricalContent>* Histories::getRank2content() const
{
    return rank2content;
}
