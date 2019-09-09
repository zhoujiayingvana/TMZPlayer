#include "util/media.h"

Media::Media()
    : media_Histories(nullptr, "Retina", 12),
      media_Folders(nullptr, "Retina"),
      pyPath(QFileInfo("../util/get_urls.py").absoluteFilePath()),
      username("Retina"), mediaStateInfos(), hasAVPlaying(false)
{
    // 初始化私有成员
    this->media_StartThread = false;
    this->media_Player = new Player();
    this->media_Controller = new Controller();
    this->media_Order = PlayOrder::ORDER_PLAY;  // 默认播放顺序为顺序播放
    this->media_playWhere = PlayArea::UNSURE;  // 默认不选中区域
    this->media_Histories.startInit();
    this->media_Folders.startInit();
    //连接信号槽
    //获取视频信息
    //获取视频长度
    connect(this->media_Controller,SIGNAL(needGetDuration()),this->media_Player,SLOT(needGetDuration()));
    connect(this->media_Player,SIGNAL(returnDuration(qint64)),this->media_Controller,SLOT(receiveDuration(qint64)));
    //获取视频播放位置
    connect(this->media_Controller,SIGNAL(needGetPosition()),this->media_Player,SLOT(needGetPosition()));
    //获取视频播放状态
    connect(this->media_Controller,SIGNAL(needGetStatus()),this->media_Player,SLOT(needGetStatus()));
    connect(this->media_Player,SIGNAL(returnStatus(QMediaPlayer::State)),this->media_Controller,SLOT(receiveStatus(QMediaPlayer::State)));

    //获取播放顺序
    connect(this->media_Controller,SIGNAL(needGetOrder()),this,SLOT(needGetOrder()));
    
    //控制视频
    //恢复播放
    connect(this->media_Controller,SIGNAL(needRestorePlay()),this->media_Player,SLOT(needRestorePlay()));
    //暂停
    connect(this->media_Controller,SIGNAL(needPauseVideo()),this->media_Player,SLOT(needPauseVideo()));
    //停止
    connect(this->media_Controller,SIGNAL(needTerminateVideo()),this->media_Player,SLOT(needTerminateVideo()));
    //跳转
    connect(this->media_Controller,SIGNAL(needSeekPosition(qint64)),this->media_Player,SLOT(needSetPosition(qint64)));
    //设置音量
    connect(this->media_Controller,SIGNAL(needSetVolume(int)),this->media_Player,SLOT(needSetVolume(int)));
    //设置静音
    connect(this->media_Controller,SIGNAL(needSetMuted(bool)),this->media_Player,SLOT(needSetMuted(bool)));
    //设置播放速率
    connect(this->media_Controller,SIGNAL(needSetPlaybackRate(qreal)),this->media_Player,SLOT(needSetPlaybackRate(qreal)));
    //快进快退
    connect(this->media_Controller,SIGNAL(needJump(int)),this->media_Player,SLOT(needJump(int)));
    
    //高级功能
    //截屏
    connect(this->media_Controller,SIGNAL(needCutScreen(WId ,QString,QString,QString,int)),this->media_Player,SLOT(needCutScreen(WId,QString,QString,QString,int)));
    connect(this->media_Player,SIGNAL(returnScreenCut(QString)),this->media_Controller,SLOT(receiveScreenCut(QString)));
    //自动播放
    connect(this->media_Player->getPlayer(),SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(playNextByAuto(QMediaPlayer::State)));
    //设置播放顺序
    connect(this->media_Controller,SIGNAL(needSetOrder(PlayOrder)),this,SLOT(needSetOrder(PlayOrder)));
    connect(this,SIGNAL(returnOrder(PlayOrder)),this->media_Controller,SLOT(receiveOrder(PlayOrder)));
}

Media::~Media()
{

}

QMediaPlayer *Media::getPlayWindow()
{
    return this->media_Player->getPlayWindow();
}

Controller *Media::getController()
{
    return this->media_Controller;
}

Histories& Media::getHistories()
{
    return media_Histories;
}

Folders& Media::getFolders()
{
    return media_Folders;
}


/**
 * @author       ParanoidRoot
 * @method
 * @param
 * @return
 * @details      实现提供给 ui 的高级封装, 是打开了文件或者选择了 url, 注意实现的步骤
 *               0. 获取当前的播放记录并加入历史信息栈中
 *               1. 加入历史记录
 *               2. 选中历史记录的第一条
 *               3. 开始播放
 *               4. 设置播放状态为 true
 */
void Media::play(const bool& _isLocal, const QString& _fileName, const QString& _filePath)
{
    // 加入当前的媒体状态
    this->pushCurrentMediaStateInfo2Stack();

    // 加入历史记录
    this->media_Histories.addContent(_fileName,
                                     _filePath, _isLocal, 0);

    // 选中历史记录的第一条
    this->setPlayWhere(PlayArea::HISTORIES);
    this->setFirstRank(0);
    this->setSecondRank(-1);

    // 请求播放
    this->media_Player->needPlay(this->media_Histories.getPointedMediaContent());

    // 设置播放状态
    this->hasAVPlaying = true;

//    // 尝试跳转
//    this->back2Last();
}


/**
 * @brief Media::play
 * @param _isLocal
 * @param _filePath
 * 无名的播放视频, 提供默认的视频名
 */
void Media::play(const bool& _isLocal, const QString& _filePath)
{
    QString defaultFileName = "";
    if (_isLocal)  // 是本地文件
        defaultFileName = QFileInfo(_filePath).fileName();
    else
    {
        QDateTime cdt = QDateTime::currentDateTime();
        QString timeString = cdt.toString("yyyy/MM/dd-hh:mm:ss");
        defaultFileName = QString("web-%1").arg(timeString);
    }
    this->play(_isLocal, defaultFileName, _filePath);
}


/**
 * @brief Media::play
 * @param playArea
 * @param _firstRank
 * @param _secondRank
 * 从指定的地方开始来播放视频
 *
 * 注意实现步骤
 * 0. 先加入之前的到信息栈
 * 1. 选定当前要播放的位置
 * 2. 请求播放视频
 * 3. 将播放的视频信息存入历史记录中
 */
void Media::play(const PlayArea& _playArea, const int& _firstRank, const int& _secondRank)
{
    // 将之前的内容加入信息栈
    this->pushCurrentMediaStateInfo2Stack();

    // 选定新的要播放的视频
    this->setPlayWhere(_playArea);
    this->setFirstRank(_firstRank);
    this->setSecondRank(_secondRank);

    // 请求播放视频
    if (this->media_playWhere == PlayArea::FOLDERS)
        this->media_Player->needPlay(this->media_Folders.getPointedMediaContent());
    else if (this->media_playWhere == PlayArea::HISTORIES)
        this->media_Player->needPlay(this->media_Histories.getPointedMediaContent());
    else
        throw MyErrors::UNKNOWN_PLAY_AREA_ERROR;

    // 如果是收藏夹的内容还应该要添加到历史记录中去
    if (this->media_playWhere == PlayArea::FOLDERS)
    {
        this->media_Folders.addChosenFolderContent2Histories(this->media_Histories);
        this->media_Histories.setPChosen(0);  // 同时非显示设置当前历史记录的选中为 0
    }
    this->hasAVPlaying = true;

    // 指定位置的播放, 需要判断跳转
    this->back2Last();
}

void Media::makeContainerEmpty()
{
    this->media_Histories.makeEmpty();
    this->media_Folders.makeEmpty();
}


/**
 * @brief Media::playNextByHand
 * 手动请求播放下一首
 * 0. 特别注意: 应该判断是否存在当前选中的一首
 * 1. 终止并且保存视频的播放位置
 * 2. 获取下一次要播放的位置的三个参数
 * 3. 请求播放
 * 4. 判断如果是收藏夹中的内容还应该加入到历史记录中去
 * 5. 设置有东西正在播放
 */
bool Media::playNextByHand()
{
    // 首先判断当前是有在播放
    if (!this->hasAVPlaying)
        return false;

    // 保存并且终止视频的播放位置
    this->terminateAndSaveCurrentAV();  // 当前已经有一瞬间不再有东西再播放了

    // 获取下一次要播放的位置的三个参数
    PlayArea nextPlayArea = this->media_playWhere;
    int nextFirstRank = -1, nextSecondRank = -1;
    if (this->media_playWhere == PlayArea::FOLDERS)  // 如果是收藏夹正在播放
    {
        nextFirstRank = this->media_Folders.getPChosen();  // 收藏夹不动
        nextSecondRank = this->media_Folders.getNextRankOfPointedFolder(this->media_Order);
        if (-1 == nextSecondRank)
        {
            qDebug() << "在收藏夹中已经没有下一个媒体了";
            return false;
        }
    }
    else if (this->media_playWhere == PlayArea::HISTORIES)  // 如果是历史记录正在播放
    {
        nextFirstRank = this->media_Histories.getNextRankByPlayOrder(this->media_Order);
        if (-1 == nextFirstRank)
        {
            qDebug() << "在历史记录中已经没有下一个媒体了";
            return false;
        }
        nextSecondRank = -1;
    }
    else
    {
        qDebug() << "没有选中区域却想要切换到下一个视频" << endl;
        throw MyErrors::UNKNOWN_PLAY_AREA_ERROR;
    }

    // 请求播放
    this->play(nextPlayArea, nextFirstRank, nextSecondRank);  // 在这个方法中会置一边 hasAVPlaying
    this->hasAVPlaying = true;  // 再补一手

    // 尝试跳转
    this->back2Last();
    return true;
}


/**
 * @brief Media::playNextByAuto
 * 自动播放下一首
 */
bool Media::playNextByAuto(QMediaPlayer::State state)
{
    if (QMediaPlayer::StoppedState == state &&  // 确实是终止状态
        this->media_Player->getPlayer()->position()
        == this->media_Player->getPlayer()->duration()  // 并且已经放到结尾了
    )
        return this->playNextByHand();  // 等同于手动播放下一首
    else
        return false;
}

void Media::needSetOrder(PlayOrder order)
{
    this->media_Order=order;
}

void Media::needGetOrder()
{
    emit returnOrder(this->media_Order);
}

void Media::download2SongsTable(const QString& _what)
{
    QStringList args;
    args.append(this->pyPath);
    args.append(_what);
    QString where("../user/%1.db");
    where = where.arg(this->username);
    QFileInfo fileInfo(where);
    where = fileInfo.absoluteFilePath();
    args.append(where);
    QProcess::execute(QString("Python.exe"), args);
}

QList<QMap<QString, QString> > Media::songWebSearch(const QString& _what)
{
    // 第一步先下载所有的搜索词与之相关的曲目
    this->download2SongsTable(_what);
    // 第二步访问 db 获取所有内容
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");  // 使用默认方式读取db
    db.setDatabaseName(QString("../user/%1.db").arg(this->username));
    if (!db.open())  // 打开错误则显示
    {
        qDebug() << db.lastError().text();
        throw MyErrors::WEB_SEARCH_ERROR;
    }
    QSqlQuery* query = new QSqlQuery(db);
    QString sqlString("SELECT * FROM songs");
    if (!query->exec(sqlString))
    {
        qDebug() << query->lastError().text();
        throw MyErrors::WEB_SEARCH_ERROR;
    }
    QList<QMap<QString, QString> > ansList;
    while (query->next())
    {
        QString songName = *(QString*)query->value("song_name").data();
        QString songUrl = *(QString*)query->value("song_path").data();
        QMap<QString, QString> map;
        map.insert(songName, songUrl);
        ansList.append(map);
    }
    if (ansList.length() <= 0)
    {
        qDebug() << "none map in the list" << endl;
        throw MyErrors::WEB_SEARCH_ERROR;
    }
    DBFinisherThread* pThread = new DBFinisherThread(query, "songs", true);
    pThread->run();
    return ansList;
}

MediaStateInfo Media::popLastState()
{
    if (!this->mediaStateInfos.empty())
        return this->mediaStateInfos.pop();
    else
    {
        qDebug() << "empty media state infos stack" << endl;
        throw MyErrors::GET_LAST_AV_ERROR;
    }
}

bool Media::lastAVAccessible(const MediaStateInfo& lmsi)
{
    try
    {
        QString currFilePath = "";
        if (lmsi.getWhere() == PlayArea::FOLDERS)  // 是收藏夹
        {
            currFilePath =
                    this->media_Folders.getFolder(lmsi.getFirstRank()).getFolderContent(lmsi.getSecondRank()).getFilePath();
            return currFilePath == lmsi.getFilePath();
        }
        else  // 就是历史记录
        {
            currFilePath = this->media_Histories.getHistoricalContent(lmsi.getFirstRank()).getFilePath();
            return currFilePath == lmsi.getFilePath();
        }
    }
    catch (const MyErrors& e)
    {
        qDebug() << "文件不再存在或者已经改变路径" << endl;
        qDebug() << getErrorType(e) << endl;
        return false;
    }
}

bool Media::playLast()
{
    MediaStateInfo lmsi;
    try
    {
        lmsi = this->popLastState();
    }
    catch (const MyErrors& e)
    {
        qDebug() << getErrorType(e) << endl;
        return false;
    }
    if (this->lastAVAccessible(lmsi))  // 上一个可以访问且正确路径
    {
//        if (this->hasAVPlaying)  // 有 AV 占用窗口, 应该终止并保存历史记录
//            this->terminateAndSaveCurrentAV();

        PlayArea _playArea = lmsi.getWhere();
        int _firstRank = lmsi.getFirstRank();
        int _secondRank = lmsi.getSecondRank();

        // 选定新的要播放的视频
        this->setPlayWhere(_playArea);
        this->setFirstRank(_firstRank);
        this->setSecondRank(_secondRank);

        // 请求播放视频
        if (this->media_playWhere == PlayArea::FOLDERS)
            this->media_Player->needPlay(this->media_Folders.getPointedMediaContent());
        else if (this->media_playWhere == PlayArea::HISTORIES)
            this->media_Player->needPlay(this->media_Histories.getPointedMediaContent());
        else
            throw MyErrors::UNKNOWN_PLAY_AREA_ERROR;

        // 如果是收藏夹的内容还应该要添加到历史记录中去
        if (this->media_playWhere == PlayArea::FOLDERS)
        {
            this->media_Folders.addChosenFolderContent2Histories(this->media_Histories);
            this->media_Histories.setPChosen(0);  // 同时非显示设置当前历史记录的选中为 0
        }
        this->hasAVPlaying = true;

        // 尝试跳转
        this->back2Last();
        return true;
    }
    else
        return false;
}


/**
 * @brief Media::back2Last
 */
void Media::back2Last()
{
    if (this->media_playWhere == PlayArea::FOLDERS)  // 在收藏夹中播放
        return ;
    else  // 在历史记录中播放
        this->media_Controller->seekPosition(
            this->media_Histories.getPointedHistoricalContent().getProgressMilliSecond()
        );
}

void Media::closeSelf()
{
    // 保存历史位置并且终止视频
    this->terminateAndSaveCurrentAV();
    this->hasAVPlaying = false;
    // 刷新内容并保存
    this->media_Histories.startClose();
    this->media_Folders.startClose();
    // 清空析构容器
    this->makeContainerEmpty();
}

void Media::startCreateGif(WId wid, QString fileName, QString filePath)
{
    //检查图片路径是否合法
    if(!Debug::isFileDirExits(filePath)){
        qDebug()<<"Media StartCreateGif() "<<Debug::getDebugErrorType(Debug::MyErrors::FILE_PATH_ERROR);
        return;
    }
    this->media_GifFullPath=filePath+fileName+".gif";
    //开始gif录制线程
    this->media_WId=wid;
    this->start();
}

void Media::endCreateGif()
{
    //结束gif录制线程
    this->media_StartThread=false;
}

MediaStateInfo Media::getCurrentMediaStateInfo()
{
    PlayArea where = this->media_playWhere;
    int firstRank = -1, secondRank = -1;
    QString filePath = "";
    if (where == PlayArea::FOLDERS)  // 如果当前选中的是收藏夹
    {
        firstRank = this->media_Folders.getPChosen();
        secondRank = this->media_Folders.getPointedFolder().getPChosen();
        filePath = this->media_Folders.getPointedFolderContent().getFilePath();
    }
    else if (where == PlayArea::HISTORIES)
    {
        firstRank = this->media_Histories.getPChosen();
        secondRank = -1;
        filePath = this->media_Histories.getPointedHistoricalContent().getFilePath();
    }
    else
        throw MyErrors::UNKNOWN_PLAY_AREA_ERROR;
    return MediaStateInfo(where, firstRank, secondRank, filePath);
}

void Media::setPlayWhere(const PlayArea& playArea)
{
    this->media_playWhere = playArea;
}

void Media::setFirstRank(const int& _firstRank)
{
    if (this->media_playWhere == PlayArea::FOLDERS)
        this->media_Folders.setPChosen(_firstRank);
    else if (this->media_playWhere == PlayArea::HISTORIES)
        this->media_Histories.setPChosen(_firstRank);
    else
        throw MyErrors::UNKNOWN_PLAY_AREA_ERROR;
}

void Media::setSecondRank(const int& _secondRank)
{
    if (this->media_playWhere == PlayArea::FOLDERS)
        this->media_Folders.getPointedFolder().setPChosen(_secondRank);
    else if (this->media_playWhere == PlayArea::HISTORIES)
        return;
    else
    {
        qDebug() << "you cannot set pChosen for an unknown area!";
        throw MyErrors::UNKNOWN_PLAY_AREA_ERROR;
    }
}

void Media::pushCurrentMediaStateInfo2Stack()
{
    if (this->hasGoodAreaAndRanks())
    {
        MediaStateInfo msi = this->getCurrentMediaStateInfo();  // 获取当前的信息集
        this->mediaStateInfos.push(msi);
    }
    else
    {
        qDebug() << "unable get current media state info" << endl
                 << "perhaps you are at a starting state and unchosen anything" << endl;
    }
}

bool Media::hasGoodAreaAndRanks()
{
    try
    {
        this->getCurrentMediaStateInfo();
        return true;
    }
    catch (const MyErrors& e)
    {
        return false;
    }
}


/**
 * @brief Media::terminateAndSaveCurrentAV
 * 设置当前播放的视频终止, 注意步骤
 * 0. 获取当前的播放停止的位置, 并且终止其播放, 在 player 中完成
 * 1. 若是历史记录中的视频正在 _选中_ 播放
 *      1. 注意应该直接历史记录播放视频的位置, 注意不一定为第一个
 * 2. 若是收藏夹中的视频正在 _选中_ 播放
 *      1. 注意其要么已经在历史记录中了, 那么他会被移到第一个, 这在之前的 play 中完成了
 *      2. 要么不再历史记录中, 初次在 play 中被加入, 那么他还是在第一个
 */
void Media::terminateAndSaveCurrentAV()
{
    // 首先应该判断是否有视频正在播放
    if (!this->hasAVPlaying)
        return ;

    // 获取位置, 关闭视频
    qint64 currentPosition = this->media_Player->needTerminateVideo();

    // 判断如何存储
    if (this->media_playWhere == PlayArea::HISTORIES)  // 历史记录中选中正在播放
        this->media_Histories.getPointedHistoricalContent().setProgressMilliSecond(currentPosition);
    else if (this->media_playWhere == PlayArea::FOLDERS)  // 收藏夹中的内容被选中了正在播放
    {
        this->media_Histories.setPChosen(0);  // 选中第一个
        this->media_Histories.getPointedHistoricalContent().setProgressMilliSecond(currentPosition);
    }
    else
    {
        qDebug() << "没有选中区域, 却试图终止视频" << endl;
        throw MyErrors::UNKNOWN_PLAY_AREA_ERROR;
    }

    this->hasAVPlaying = false;
}

void Media::run()
{
    int i=0;
    QScreen *screen = QGuiApplication::primaryScreen();
    this->media_StartThread=true;
    //录制gif
    while(this->media_StartThread){
        QImage image=screen->grabWindow(this->media_WId).toImage();
        //加入缓存图像队列中
        this->media_QImageList.push_back(image);
        //休眠13ms
        QThread::msleep(100);
        i++;
    }
    qDebug()<<"图片张数"<<i;
    //生成gif

    if(!this->media_QImageList.isEmpty()){
        //获取图片宽高和生成路径
        QImage tempImage=this->media_QImageList.at(0);
        uint32_t width=tempImage.width();
        uint32_t height=tempImage.height();


        //初始化gif生成工具
        Gif_H m_Gif;
        Gif_H::GifWriter m_GifWriter;
        if(!m_Gif.GifBegin(&m_GifWriter,Debug::QString2Char(this->media_GifFullPath),
                           width,height,10)){
            qDebug()<<"Media run() "<<Debug::getDebugErrorType(Debug::MyErrors::GIF_IMAGE_EXIT_ERROR);
            this->quit();
        }
        //绘制gif
        while(!this->media_QImageList.isEmpty()){
            QImage image=this->media_QImageList.at(0);
            //格式转换
            image = image.convertToFormat(QImage::Format_RGBA8888);
            this->media_QImageList.pop_front();//出队一个图片
            //写入图片信息
            m_Gif.GifWriteFrame(&m_GifWriter, image.constBits(), width, height, 10);
        }
        m_Gif.GifEnd(&m_GifWriter);
        qDebug()<<"Gif create over.";
    }
    else {
        qDebug()<<"Media run() "<<Debug::getDebugErrorType(Debug::MyErrors::GIF_IMAGE_EXIT_ERROR);
    }
    //退出线程
    this->quit();
}

bool Media::getHasAVPlaying() const
{
    return hasAVPlaying;
}

void Media::mock()
{
    return;
}

int MediaStateInfo::getFirstRank() const
{
    return firstRank;
}

void MediaStateInfo::setFirstRank(int value)
{
    firstRank = value;
}

int MediaStateInfo::getSecondRank() const
{
    return secondRank;
}

void MediaStateInfo::setSecondRank(int value)
{
    secondRank = value;
}

void MediaStateInfo::testPrint() const
{
    qDebug() << playArea2String(this->where) << endl
             << this->firstRank << endl
             << this->secondRank << endl;
}

PlayArea MediaStateInfo::getWhere() const
{
    return where;
}

void MediaStateInfo::setWhere(const PlayArea& value)
{
    where = value;
}

QString MediaStateInfo::getFilePath() const
{
    return filePath;
}

void MediaStateInfo::setFilePath(const QString& value)
{
    filePath = value;
}

MediaStateInfo::MediaStateInfo(const PlayArea& _where,
                               const int& _firstRank,
                               const int& _secondRank,
                               const QString& _filePath)
    : where(_where), firstRank(_firstRank), secondRank(_secondRank),
      filePath(_filePath)
{
    if (this->where == PlayArea::UNSURE || this->firstRank == -1)
    {
        qDebug() << "unsure area or undecided first rank";
        throw MyErrors::MEDIA_STATE_ERROR;
    }
    if (this->where == PlayArea::FOLDERS && this->secondRank == -1)
    {
        qDebug() << "has selected first ranked folder but without second rank";
        throw MyErrors::MEDIA_STATE_ERROR;
    }
    if (this->where == PlayArea::HISTORIES)  // 历史记录不需要二级rank
        this->secondRank = -1;
}

MediaStateInfo::MediaStateInfo(const MediaStateInfo& other)
    : where(other.where), firstRank(other.firstRank),
      secondRank(other.secondRank), filePath(other.filePath)
{

}

MediaStateInfo& MediaStateInfo::operator=(const MediaStateInfo& other)
{
    this->where = other.where;
    this->firstRank = other.firstRank;
    this->secondRank = other.secondRank;
    this->filePath = other.filePath;
}
