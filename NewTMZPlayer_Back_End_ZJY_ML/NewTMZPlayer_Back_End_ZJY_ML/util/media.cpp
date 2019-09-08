#include "util/media.h"

Media::Media()
    : media_Histories(nullptr, "Retina", 12),
      media_Folders(nullptr, "Retina"),
      pyPath(QFileInfo("../util/get_urls.py").absoluteFilePath()),
      username("Retina")
{
    //初始化私有成员
    this->media_StartThread=false;
    this->media_Player=new Player();
    this->media_Controller=new Controller();
//    this->media_NetworkModel=new NetworkModel();
    this->media_Order=PlayOrder::ORDER_PLAY;//默认播放顺序为顺序播放
    this->media_isFolders=false;
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
    connect(this->media_Player->getPlayer(),SIGNAL(stateChanged(QMediaPlayer::State)),this,SLOT(playNext(QMediaPlayer::State)));
    //设置播放顺序
    connect(this->media_Controller,SIGNAL(needSetOrder(PlayOrder)),this,SLOT(needSetOrder(PlayOrder)));
    connect(this,SIGNAL(returnOrder(PlayOrder)),this->media_Controller,SLOT(receiveOrder(PlayOrder)));
    //记录播放时间
    connect(this->media_Player,SIGNAL(returnPositionToHis(qint64)),this,SLOT(receivePosition(qint64)));
}

/////////////
Media::~Media(){

}


QMediaPlayer *Media::getPlayWindow()
{
    return this->media_Player->getPlayWindow();
}

Controller *Media::getController()
{
    return this->media_Controller;
}

void Media::testRun()
{
    // 选中收藏夹
    media_Folders.setPChosen(0);
}

Histories& Media::getHistories()
{
    return media_Histories;
}

void Media::setHistories(const Histories& value)
{
    media_Histories = value;
}

Folders& Media::getFolders()
{
    return media_Folders;
}

void Media::setFolders(const Folders& value)
{
    media_Folders = value;
}
//播放本地视频，并添加历史记录
void Media::play(QString url)
{
    this->media_isFolders=false;
    QFileInfo tempInfo(url);
    QString fileName=tempInfo.fileName();
    
    //添加到历史记录
    this->media_Histories.addContent(fileName, url, true, 0);
    this->media_Histories.setPChosen(0);
    this->media_Player->needPlay(this->media_Histories.getPointedMediaContent());
}
//播放收藏夹视频，并添加到历史记录
void Media::play(int folderNum, int fileNum)
{
    this->media_isFolders=true;
    this->media_Folders.setPChosen(folderNum);
    this->media_Folders.getPointedFolder().setPChosen(fileNum);
    this->media_Player->needPlay(this->media_Folders.getPointedMediaContent());
    //添加到历史记录
    this->media_Folders.addChosenFolderContent2Histories(this->media_Histories);
}
//手动播放下一首
void Media::playNext()
{
    //停止当前视频，自动记录播放位置
    this->media_Player->needTerminateVideo();
    //在收藏夹中播放下一首
    if(this->media_isFolders==true){
        int nextIndex=media_Folders.getNextRankOfPointedFolder(this->media_Order);
        if(nextIndex==-1){
            //结束播放
            this->media_Player->needTerminateVideo();
            
        }
        else{

            media_Folders.getPointedFolder().setPChosen(nextIndex);
            
            this->media_Player->needPlay(media_Folders.getPointedMediaContent());
            // 添加到历史记录
            this->media_Folders.addChosenFolderContent2Histories(this->media_Histories);
        }
        
    }
    //在历史记录中播放下一首
    else {
        int nextIndex=media_Histories.getNextRankByPlayOrder(PlayOrder::ORDER_PLAY);
        if(nextIndex==-1){
            //结束播放
            this->media_Player->needTerminateVideo();
        }
        else{
            media_Histories.setPChosen(nextIndex);
            this->media_Player->needPlay(media_Histories.getPointedMediaContent());
        }
    }
    
}
//记录播放位置
void Media::receivePosition(qint64 pos)
{
    this->media_Histories.setPChosen(0);
    this->media_Histories.getPointedHistoricalContent().setProgressMilliSecond(pos);
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

//自动播放下一首，私有槽函数
void Media::playNext(QMediaPlayer::State state)
{
    if(state==QMediaPlayer::StoppedState){
    //自动播放下一首
    if(this->media_Player->getPlayer()->position()==this->media_Player->getPlayer()->duration()){
        //在收藏夹中自动播放
        if(this->media_isFolders==true){
            int nextIndex=media_Folders.getNextRankOfPointedFolder(this->media_Order);
            if(nextIndex==-1){
                //结束播放
                this->media_Player->needTerminateVideo();
                
            }
            else{
                media_Folders.getPointedFolder().setPChosen(nextIndex);
                
                this->media_Player->needPlay(media_Folders.getPointedMediaContent());
            }
            
        }
        //在历史记录中自动播放
        else {
            int nextIndex=media_Histories.getNextRankByPlayOrder(PlayOrder::ORDER_PLAY);
            if(nextIndex==-1){
                //结束播放
                this->media_Player->needTerminateVideo();
            }
            else{
                media_Histories.setPChosen(nextIndex);
                this->media_Player->needPlay(media_Histories.getPointedMediaContent());
            }
        }
    }
    }
    
}

void Media::makeSelfEmpty()
{
    this->media_Player->needTerminateVideo();
    this->media_Histories.startClose();
    this->media_Folders.startClose();
}
//手动播放下一首

void Media::StartCreateGif(WId wid, QString fileName, QString filePath)
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
