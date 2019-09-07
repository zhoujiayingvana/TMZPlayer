#include "util/media.h"

Media::Media(QWidget *parent)
    : QWidget(parent), media_Histories(nullptr, "Retina", 12),
      media_Folders(nullptr, "Retina")
{
    //初始化私有成员
    this->media_Player=new Player();
    this->media_Controller=new Controller();
    this->media_NetworkModel=new NetworkModel();
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
    this->media_Histories.startClose();
    this->media_Folders.startClose();
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
    // 创建新的收藏夹
    media_Folders.addNewFolder("王力宏");
    // 选中收藏夹
    media_Folders.setPChosen(0);
    // 向其中添加歌曲
    media_Folders.addContent2Folder(0, "w1", "../vid/t1.flv", true);
    media_Folders.addContent2Folder(0, "w2", "../vid/t2.mov", true);
    media_Folders.addContent2Folder(0, "w3", "../vid/t3.avi", true);
    // 选中收藏夹下的曲目
    //media_Folders.getPointedFolder().setPChosen(0);
    //播放
//    this->play(0,0);
    // 跳转到下一个随机的视频
    //media_Folders.getPointedFolder().setPChosen(media_Folders.getNextRankOfPointedFolder(PlayOrder::SHUFFLE));
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
//手动播放下一首
