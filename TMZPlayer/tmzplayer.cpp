#include "tmzplayer.h"

#include<QApplication>
#include<QVBoxLayout>

#include <QDebug>
#ifdef Q_OS_WIN
#include <qt_windows.h>
#include <windowsx.h>
#endif

TMZPlayer::TMZPlayer(QWidget *parent,Media* m) :
    QMainWindow(parent),
    ui(new Ui::TMZPlayer),media(m)
{
    ui->setupUi(this);
    resize(1032,718);
    this->setWindowFlags(Qt::FramelessWindowHint|Qt::WindowMinimizeButtonHint);

    widget = new QWidget();
    this->setCentralWidget(widget);


    pTitleBar = new TitleBar(this);
    //    pTitleBar->setAutoFillBackground(true);//test
    //    pTitleBar->setPalette(QPalette(Qt::black));//test
    pBottomBar = new BottomBar(this);
    //    pBottomBar->setAutoFillBackground(true);//test
    //    pBottomBar->setPalette(QPalette(Qt::black));//test
    space = new QVideoWidget(this);//test
    //    space->setAutoFillBackground(true);//test
    //    space->setPalette(QPalette(Qt::gray));//test
    space->hide();
    //设置播放窗口匹配
    media->getPlayWindow()->setVideoOutput(this->space);


    ui->showLeftBarBtn->setVisible(false);
    ui->showRightBarBtn->setVisible(false);


    mini = new Mini(this);
    sysTrayIcon = new QSystemTrayIcon(this);

    

    downloadListBtn = new QPushButton(this);
    downloadListBtn->setFlat(true);
    downloadListBtn->setText(QStringLiteral(" 我的下载"));
    downloadListBtn->setFixedHeight(35);
    QFont downloadListBtnFont = downloadListBtn->font();
    downloadListBtnFont.setPointSize(11);
    downloadListBtn->setStyleSheet("text-align: left;");
    downloadListBtn->setFont(downloadListBtnFont);
    QIcon downloadIcon(":/image/image/musiclist.png");
    downloadListBtn->setIcon(downloadIcon);
    downloadListBtn->setIconSize(QSize(20,20));


    listBox = new QGroupBox(this);
    listBox->setTitle(QStringLiteral("列表"));
    listBox->setStyleSheet("QGroupBox { border: none; font-size: 15px; }");
    addListBtn = new QPushButton(this);
    addListBtn->setText(QStringLiteral("+ 新建播放列表"));
    QFont addListBtnFont = addListBtn->font();
    addListBtnFont.setPointSize(11);
    addListBtn->setFont(addListBtnFont);
    addListBtn->setFlat(true);

    ui->leftsideBarLayout->setAlignment(Qt::AlignTop);
    ui->leftsideBar->setLayout(ui->leftsideBarLayout);
    ui->leftsideBarLayout->addWidget(downloadListBtn);
    ui->leftsideBarLayout->addWidget(listBox);

    ui->showLeftBarBtn->setFixedSize(21,21);
    ui->showRightBarBtn->setFixedSize(21,21);
    ui->hideLeftBarBtn->setFixedSize(21,21);
    ui->hideRightBarBtn->setFixedSize(21,21);


    listBoxLayout = new QVBoxLayout();
    listBoxLayout->setAlignment(Qt::AlignTop);
    listBoxLayout->setContentsMargins(0,20,0,0);
    listBox->setLayout(listBoxLayout);
    listBoxLayout->addWidget(addListBtn);


	QIcon icon = QIcon(":/image/image/test.png");
	sysTrayIcon->setIcon(icon);
	sysTrayIcon->setToolTip("TMZPlayer");

	historyContainer.append(new history);
	ui->historyLayout->addWidget(historyContainer.last());
	ui->rightsideBar->setLayout(ui->historyLayout);

	creatActions();
	creatMenu();

	sysTrayIcon->show();


	middleBarLayout = new QHBoxLayout();
	leftWidget = new QWidget(this);
	leftLayout = new QHBoxLayout(leftWidget);
	rightWidget = new QWidget(this);
	rightLayout = new QHBoxLayout(rightWidget);
	middleWidget = new QWidget(this);
	middleLayout = new QVBoxLayout(middleWidget);
	leftLayout->addWidget(ui->scrollArea);
	leftLayout->addWidget(ui->hideLeftBarBtn);
	leftLayout->addWidget(ui->showLeftBarBtn);
	rightLayout->addWidget(ui->hideRightBarBtn);
	rightLayout->addWidget(ui->historyList);
	rightLayout->addWidget(ui->showRightBarBtn);
//	mMiddleLayout = new QVBoxLayout(space);
//	QWidget * a = new QWidget(space);//test
//	a->setAutoFillBackground(true);//test
//	QHBoxLayout *b = new QHBoxLayout(a);//test
//	b->addWidget(ui->listNameLabel);//test
//	b->setContentsMargins(0, 0, 0, 0);//test
	ui->listNameLabel->setFixedHeight(50);
	ui->listNameLabel->setCursor(Qt::ArrowCursor);
	ui->displayList->setCursor(Qt::ArrowCursor);

//	mMiddleLayout->setContentsMargins(0, 0, 0, 0);
//	mMiddleLayout->setSpacing(0);
//	mMiddleLayout->addWidget(a);
//	mMiddleLayout->addWidget(ui->displayList);
	space->show();
	middleLayout->addWidget(space);



	leftLayout->setContentsMargins(0, 0, 0, 0);
	rightLayout->setContentsMargins(0, 0, 0, 0);
	middleLayout->setContentsMargins(0, 0, 0, 0);
	leftLayout->setSpacing(0);
	rightLayout->setSpacing(0);
	middleLayout->setSpacing(0);
	leftWidget->setFixedWidth(180);
	rightWidget->setFixedWidth(160);
	middleBarLayout->addWidget(leftWidget);
	middleBarLayout->addWidget(middleWidget);
	middleBarLayout->addWidget(rightWidget);


    pLayout = new QVBoxLayout();
    pLayout->addWidget(pTitleBar);
    pLayout->addLayout(middleBarLayout);
    pLayout->addWidget(pBottomBar);

    pLayout->setSpacing(0);
    pLayout->setContentsMargins(5, 5, 5, 5);

    widget->setLayout(pLayout);



	volumeAdd = new QShortcut(this);
	volumeAdd->setKey(tr("up"));
	volumeAdd->setAutoRepeat(true);
	volumeSub = new QShortcut(this);
	volumeSub->setKey(tr("down"));
	volumeSub->setAutoRepeat(true);
	connect(volumeAdd, SIGNAL(activated()), pBottomBar, SLOT(volumeSliderValueAdd()));
	connect(volumeSub, SIGNAL(activated()), pBottomBar, SLOT(volumeSliderValueSub()));
    connect(mini,SIGNAL(miniToMaxSignal()),this,SLOT(miniToMaxSlot()));
    connect(mini,SIGNAL(miniToTraySignal()),this,SLOT(miniToTraySlot()));
    connect(addListBtn,SIGNAL(clicked()),this,SLOT(addListSlot()));
    connect(pBottomBar,SIGNAL(full_screenButton_clicked()),this,SLOT(fullScreenMode()));
	connect(this, SIGNAL(maximizeButton_clicked()), pTitleBar, SLOT(on_maximizeButton_clicked()));
    connect(space,SIGNAL(full_screenButton_clicked()),this,SLOT(fullScreenMode()));
    connect(space,SIGNAL(wheelMoved(QWheelEvent *)),pBottomBar,SLOT(wheelMoved(QWheelEvent *)));
	connect(space, SIGNAL(bottomBarHide()), pBottomBar, SLOT(hide()));
	connect(space, SIGNAL(volumeWidgetHide()), pBottomBar, SLOT(hideVolumeWidget()));
	connect(space, SIGNAL(bottomBarShow()), pBottomBar, SLOT(show()));
    connect(pTitleBar,SIGNAL(systemTrayMode()),this,SLOT(on_systemTrayModeBtn_clicked()));
    connect(pTitleBar,SIGNAL(miniMode()),this,SLOT(on_miniMode_clicked()));
	connect(sysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)), this, SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));
	connect(mini, SIGNAL(volumeChanged(int)), pBottomBar, SLOT(changeVolume(int)));
	connect(pBottomBar, SIGNAL(volumeChanged(int)), mini, SLOT(changeVolume(int)));
	connect(downloadListBtn, SIGNAL(clicked()), this, SLOT(showDownloadList()));
	connect(ui->displayList, SIGNAL(downloadFilesChangesSignal(int, QList<QString>)),
		this, SLOT(downloadFilesChangesSlot(int, QList<QString>)));

    //    connect(settingAction,SIGNAL(triggered()),//托盘模式打开设置窗口
    //            pTitleBar->settingWindow,SLOT(setVisible(true)));
    //    connect(pTitleBar->settingWindow,SIGNAL(sigPlayDirChange(QString)),//修改媒体库目录
    //            )
    //    connect(pTitleBar->settingWindow,SIGNAL(sigDownloadDirChange(QString)),
    //            )//修改下载路径

    //连接设置与BottomBar
    pBottomBar->connectSettingAndBottom(pTitleBar->settingWindow);


    currentQss=":/new/prefix1/myQss/style2.qss";
    //蓝色风格
    QFile qssfile(currentQss);
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);
    qDebug()<<this;
    





}

TMZPlayer::~TMZPlayer()
{
    delete ui;
}

bool TMZPlayer::nativeEvent(const QByteArray &eventType, void *message, long *result)//实现窗口缩放
{
    Q_UNUSED(eventType);

    const int HIT_BORDER = 5;
    const MSG *msg=static_cast<MSG*>(message);
    if(msg->message == WM_NCHITTEST)
    {
        int xPos = GET_X_LPARAM(msg->lParam) - this->geometry().x();
        int yPos = GET_Y_LPARAM(msg->lParam) - this->geometry().y();

        if(this->centralWidget()->childAt(xPos,yPos) != nullptr)//鼠标在子对象上则不处理
        {
            return QWidget::nativeEvent(eventType, message, result);
        }

        *result = HTCAPTION;

        //鼠标在边框上则缩放
        if(xPos > 0 && xPos < HIT_BORDER)
        {
            *result = HTLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < this->width())
        {
            *result = HTRIGHT;
        }
        if(yPos > 0 && yPos < HIT_BORDER)
        {
            *result = HTTOP;
        }
        if(yPos > (this->height() - HIT_BORDER) && yPos < this->height())
        {
            *result = HTBOTTOM;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > 0 && yPos < HIT_BORDER)
        {
            *result = HTTOPLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < this->width() && yPos > 0 && yPos < HIT_BORDER)
        {
            *result = HTTOPRIGHT;
        }
        if(xPos > 0 && xPos < HIT_BORDER && yPos > (this->height() - HIT_BORDER) && yPos < this->height())
        {
            *result = HTBOTTOMLEFT;
        }
        if(xPos > (this->width() - HIT_BORDER) && xPos < this->width() && yPos > (this->height() - HIT_BORDER) && yPos < this->height())
        {
            *result = HTBOTTOMRIGHT;
        }
        return true;
    }
    return QWidget::nativeEvent(eventType, message, result);

}

void TMZPlayer::fullScreenMode()
{
    if(isFullScreen())
    {
        emit maximizeButton_clicked();
        pTitleBar->show();
        pBottomBar->show();
        pLayout->removeItem(middleBarLayout);
        pLayout->addWidget(pTitleBar);
        pLayout->addLayout(middleBarLayout);
        pLayout->addWidget(pBottomBar);
        pLayout->setContentsMargins(5, 5, 5, 5);
        showNormal();
        emit ui->showLeftBarBtn->click();
        emit ui->showRightBarBtn->click();



    }
	else
	{
		emit maximizeButton_clicked();
		pLayout->setContentsMargins(0, 0, 0, 0);
		this->showFullScreen();
		pBottomBar->setWindowOpacity(0.5);
		pLayout->removeWidget(pBottomBar);
		pLayout->removeWidget(pTitleBar);
		pBottomBar->raise();
		pTitleBar->hide();
		emit ui->hideLeftBarBtn->click();
		emit ui->hideRightBarBtn->click();
	}
}

/* Author: zyt
 * Name: whetherInitializeListButton
 * Function:（未实现） 检测用户的历史播放列表记录
 * Return:false：未创建
 *        true：创建过，按照历史纪录初始化
 */
bool TMZPlayer::whetherInitializeListButton()
{
    return false;
    Q_UNUSED(true);
    return true;
}

/* Author: zyt
 * Name: addListSlot
 * Function: 槽：实现添加列表操作，建立连接
 */
void TMZPlayer::addListSlot()
{
	playlistsContainer.append(new mergedPlaylist);
	listBoxLayout->addWidget(playlistsContainer.at(playlistsContainer.length() - 1));
	connect(playlistsContainer.at(playlistsContainer.length() - 1),
		SIGNAL(givingTempSNAndFiles(int, QList<QString>)),
		ui->displayList,
		SLOT(recevingSNAndFiles(int, QList<QString>)));

	connect(ui->displayList,
		SIGNAL(changeFilesInListSignal(int, QList<QString>)),
		playlistsContainer.at(playlistsContainer.length() - 1),
		SLOT(changeFilesInListSlot(int, QList<QString>)));

	connect(playlistsContainer.at(playlistsContainer.length() - 1),
		SIGNAL(showChangedListSignal(int, QList<QString>)),
		ui->displayList,
		SLOT(showChangedListSlot(int, QList<QString>)));

	connect(playlistsContainer.at(playlistsContainer.length() - 1),
		SIGNAL(givingListName(QString)),
		this,
		SLOT(receivingListName(QString)));

	connect(playlistsContainer.at(playlistsContainer.length() - 1),
		SIGNAL(hideContentsExceptThisSignal(int)),
		this,
		SLOT(hideContentsExceptThisSlot(int)));

	connect(playlistsContainer.at(playlistsContainer.length() - 1),
		SIGNAL(allowDragAndMenuSignal()),
		this,
		SLOT(allowDragAndMenuSlot()));
}

/* Author: zyt
 * Name: showDownloadList
 * Function: 槽：显示我的下载列表
 */
void TMZPlayer::showDownloadList()
{
	qDebug() << ui->listNameLabel->text();

	ui->listNameLabel->setText(QStringLiteral("我的下载"));
	//我的下载SN为0
	ui->displayList->recevingSNAndFiles(0, downloadSongs);


	//不允许右键点击事件
	ui->displayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->displayList->setContextMenuPolicy(Qt::NoContextMenu);

	//不允许拖拽文件进入
	ui->displayList->setAcceptDrops(false);
}

/* Author: zyt
 * Name: downloadFilesChangesSlot
 * Function: 若我的下载列表内文件发生改变，修改存储列表内的对应文件
 */
void TMZPlayer::downloadFilesChangesSlot(int sn, QList<QString> files)
{
	if (sn == 0)
	{
		downloadSongs = files;
	}
}

/* Author: zyt
 * Name: receivingListName
 * Function: 双击我的列表时，显示displayList指向对应的列表名字
 */
void TMZPlayer::receivingListName(QString listName)
{
	ui->listNameLabel->setText(listName);


}

/* Author: zyt
 * Name: hideContentsExceptThisSlot
 * Function: 收起除了该exceptSN的左侧列表
 */
void TMZPlayer::hideContentsExceptThisSlot(int exceptSN)
{
	for (int i = 0; i < playlistsContainer.length(); i++)
	{
		if (playlistsContainer.at(i)->getSN() != exceptSN)
		{
			emit playlistsContainer.at(i)->hideContentSignal();
		}
	}
}

/* Author: zyt
 * Name: allowDragAndMenuSlot
 * Function: 槽：允许列表的文件拖拽和右键事件
 */
void TMZPlayer::allowDragAndMenuSlot()
{
	//允许右键点击事件
	ui->displayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->displayList->setContextMenuPolicy(Qt::CustomContextMenu);

	//允许拖拽文件进入
    ui->displayList->setAcceptDrops(true);
}

/**
* @method        TMZPlayer::changeLouderShortcut
* @brief         音量增快捷键修改
* @param         QSTRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void TMZPlayer::changeLouderShortcut(QString str)
{
    volumeAdd->setKey(str);
}

/**
* @method        TMZPlayer::changeLowerShortcut
* @brief         音量减快捷键修改
* @param         QSTRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void TMZPlayer::changeLowerShortcut(QString str)
{
    volumeSub->setKey(str);
}



/* Author: zyt
 * Name: on_hideLeftBarBtn_clicked
 * Function: 隐藏左侧边栏
 */
void TMZPlayer::on_hideLeftBarBtn_clicked()
{

    ui->scrollArea->setVisible(false);
    ui->hideLeftBarBtn->setVisible(false);
    ui->showLeftBarBtn->setVisible(true);
    leftWidget->setFixedWidth(21);

}

/* Author: zyt
 * Name: on_showLeftBarBtn_clicked
 * Function: 显示左侧边栏
 */
void TMZPlayer::on_showLeftBarBtn_clicked()
{
    ui->scrollArea->setVisible(true);
    ui->showLeftBarBtn->setVisible(false);
    ui->hideLeftBarBtn->setVisible(true);
    leftWidget->setFixedWidth(180);

}

/* Author: zyt
 * Name: on_hideRightBarBtn_clicked
 * Function: 隐藏右侧边栏
 */
void TMZPlayer::on_hideRightBarBtn_clicked()
{
    ui->historyList->setVisible(false);
    ui->showRightBarBtn->setVisible(true);
    ui->hideRightBarBtn->setVisible(false);
    rightWidget->setFixedWidth(21);

}

/* Author: zyt
 * Name: on_showRightBarBtn_clicked
 * Function: 显示右侧边栏
 */
void TMZPlayer::on_showRightBarBtn_clicked()
{
    ui->historyList->setVisible(true);
    ui->showRightBarBtn->setVisible(false);
    ui->hideRightBarBtn->setVisible(true);
    rightWidget->setFixedWidth(160);

}

/* Author: zyt
 * Name: creatActions
 * Function: 创建右键托盘菜单及图标的功能，并进行信号与槽的连接
 */
void TMZPlayer::creatActions()
{
    //为了测试，将默认播放状态设为真
    isPlaying = true;
    //实际情况待对接
    if(isPlaying)
        playOrPauseAction = new QAction(QStringLiteral("暂停"));
    else if(!isPlaying)
        playOrPauseAction = new QAction(QStringLiteral("播放"));

    showStatusAction = new QAction(QStringLiteral("暂无播放歌曲"));
    lastSongAction = new QAction(QStringLiteral("上一首"));
    nextSongAction = new QAction(QStringLiteral("下一首"));

    playOrderMenu = new QMenu(QStringLiteral("播放模式"));
    playOrder_orderAction = new QAction(QStringLiteral("顺序播放"));
    playOrder_repeatAction = new QAction(QStringLiteral("单曲循环"));
    playOrder_shuffleAction = new QAction(QStringLiteral("随机播放"));
    playOrder_listOrderAction = new QAction(QStringLiteral("列表循环"));
    playOrderMenu->addAction(playOrder_listOrderAction);
    playOrderMenu->addAction(playOrder_repeatAction);
    playOrderMenu->addAction(playOrder_shuffleAction);
    playOrderMenu->addAction(playOrder_orderAction);


    displayModeMenu = new QMenu(QStringLiteral("显示模式"));
    displayMode_maxAction = new QAction(QStringLiteral("完整模式"));
    displayMode_miniAction = new QAction(QStringLiteral("mini模式"));
    displayMode_trayAction = new QAction(QStringLiteral("最小化"));
    displayModeMenu->addAction(displayMode_maxAction);
    displayModeMenu->addAction(displayMode_miniAction);
    displayModeMenu->addAction(displayMode_trayAction);

   

    whetherShowLyricAction = new QAction(QStringLiteral("打开桌面歌词"));
    whetherLockLyricAction = new QAction(QStringLiteral("锁定桌面歌词"));

    settingAction = new QAction(QStringLiteral("设置"));

    exitAction = new QAction(QStringLiteral("退出"));

    if(isPlaying)
        playOrPauseAction->setIcon(QIcon(":/image/image/pause.jpg"));
    else if(!isPlaying)
        playOrPauseAction->setIcon(QIcon(":/image/image/play.jpg"));

    showStatusAction->setIcon(QIcon(":/image/image/status.png"));
    lastSongAction->setIcon(QIcon(":/image/image/last_song.png"));
    nextSongAction->setIcon(QIcon(":/image/image/next_song.png"));
    playOrder_orderAction->setIcon(QIcon(":/image/image/order.png"));
    playOrder_repeatAction->setIcon(QIcon(":/image/image/repeat.png"));
    playOrder_shuffleAction->setIcon(QIcon(":/image/image/shuffle.png"));
    playOrder_listOrderAction->setIcon(QIcon(":/image/image/listOrder.png"));
    displayMode_maxAction->setIcon(QIcon(":/image/image/max.png"));
    displayMode_miniAction->setIcon(QIcon(":/image/image/mini.png"));
    displayMode_trayAction->setIcon(QIcon(":/image/image/tray.png"));
    whetherShowLyricAction->setIcon(QIcon(":/image/image/show_lyric.png"));
    whetherLockLyricAction->setIcon(QIcon(":/image/image/lock_lyric.png"));
    settingAction->setIcon(QIcon(":/image/image/setting.png"));
    exitAction->setIcon(QIcon(":/image/image/exit.png"));

    connect(showStatusAction,SIGNAL(triggered()),this,SLOT(on_showMainAction()));
    connect(exitAction,SIGNAL(triggered()),this,SLOT(on_exitAction()));
    connect(playOrPauseAction,SIGNAL(triggered()),this,SLOT(on_playOrPauseAction()));
    connect(displayMode_maxAction,SIGNAL(triggered()),this,SLOT(on_displayMode_maxAction()));
    connect(displayMode_miniAction,SIGNAL(triggered()),this,SLOT(on_displayMode_miniAction()));
	connect(displayMode_trayAction, SIGNAL(triggered()), this, SLOT(on_displayMode_trayAction()));

}

/* Author: zyt
 * Name: creatMenu
 * Function: 创建右键托盘图标的功能显示
 */
void TMZPlayer::creatMenu()
{
    sysTrayMenu = new QMenu(this);
    QList<QAction*> addActions;
    addActions << showStatusAction << playOrPauseAction << lastSongAction << nextSongAction;
    sysTrayMenu->addActions(addActions);
    addActions.clear();
    sysTrayMenu->addSeparator();

    sysTrayMenu->addMenu(playOrderMenu);
    sysTrayMenu->addMenu(displayModeMenu);
    addActions << whetherShowLyricAction << whetherLockLyricAction;
    sysTrayMenu->addActions(addActions);
    addActions.clear();
    sysTrayMenu->addSeparator();

    sysTrayMenu->addAction(settingAction);

    sysTrayMenu->addSeparator();
    sysTrayMenu->addAction(exitAction);
    QPalette palette = sysTrayMenu->palette();
    palette.setColor(QPalette::Window,QColor(250,250,250));
    sysTrayMenu->setPalette(palette);

    sysTrayIcon->setContextMenu(sysTrayMenu);
}



/* Author: zyt
 * Name: on_systemTrayModeBtn_clicked
 * Function: 使播放器转变为托盘模式
 */
void TMZPlayer::on_systemTrayModeBtn_clicked()
{
    this->setVisible(false);


    //清空qss

    changeBackGround(":/new/prefix1/myQss/style4.qss");

    sysTrayIcon->show();

}

/* Author: zyt
 * Name: on_activatedSysTrayIcon
 * Function: 实现托盘的左键/双击/右键对应操作
 * Parameters: reason:操作名（单击/双击/右键)
 */
void TMZPlayer::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
{
    switch (reason) {
    case QSystemTrayIcon::Trigger:
        break;
    case QSystemTrayIcon::DoubleClick:
        this->show();
        break;
    case QSystemTrayIcon::Unknown:
        break;
    case QSystemTrayIcon::Context:
        break;
    case QSystemTrayIcon::MiddleClick:
        break;
    }
}

/* Author: zyt
 * Name: on_showMainAction
 * Function: 槽：托盘菜单显示主界面的实现
 */
void TMZPlayer::on_showMainAction()
{
    changeBackGround(currentQss);
    this->show();
}

/* Author: zyt
 * Name: on_playOrPauseAction
 * Function: 槽：托盘菜单中播放/暂停键的切换
 */
void TMZPlayer::on_playOrPauseAction()
{
    if(isPlaying)
    {
        playOrPauseAction->setText(QStringLiteral("播放"));
        playOrPauseAction->setIcon(QIcon(":/image/image/play.png"));
    }
    else if(!isPlaying)
    {
        playOrPauseAction->setText(QStringLiteral("暂停"));
        playOrPauseAction->setIcon(QIcon(":/image/image/pause.jpg"));
    }
    isPlaying = !isPlaying;
}

/* Author: zyt
 * Name: on_displayMode_maxAction
 * Function: 槽，显示主界面
 */
void TMZPlayer::on_displayMode_maxAction()
{
    changeBackGround(currentQss);
    this->show();
    sysTrayIcon->hide();
}

/* Author: zyt
 * Name: on_displayMode_miniAction
 * Function: 槽，以mini模式显示
 */
void TMZPlayer::on_displayMode_miniAction()
{
    this->hide();
    changeBackGround(":/new/prefix1/myQss/style4.qss");
    on_miniMode_clicked();
}

void TMZPlayer::on_displayMode_trayAction()
{
	this->hide();
	mini->hide();
}
/* Author: zyt
 * Name: on_exitAction
 * Function: 槽：退出播放器
 */
void TMZPlayer::on_exitAction()
{
    exit(0);
}


/* Author: zyt
 * Name: on_miniMode_clicked
 * Function: 槽：使播放器以mini模式显示
 */
void TMZPlayer::on_miniMode_clicked()
{
    this->hide();
    changeBackGround(":/new/prefix1/myQss/style4.qss");
    mini->show();
}

/* Author: zyt
 * Name: miniToMaxSlot
 * Function: 槽：mini->窗口模式
 */
void TMZPlayer::miniToMaxSlot()
{
    mini->hide();
    changeBackGround(currentQss);
    this->show();
}

/* Author: zyt
 * Name: miniToTraySlot
 * Function: 槽：mini->托盘模式
 */
void TMZPlayer::miniToTraySlot()
{
    mini->hide();
    on_systemTrayModeBtn_clicked();
}

/**
* @method        TMZPlayer::changeBackGround
* @brief         修改主界面背景 设置界面三个button分别emit传QString
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-08-26
*/
void TMZPlayer::changeBackGround(QString back)
{
    if(back!=":/new/prefix1/myQss/style4.qss")
        currentQss=back;
    QFile qssfile(back);
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);

}

/**
* @method        TMZPlayer::changePicBackGround
* @brief         修改自定义图片背景
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void TMZPlayer::changePicBackGround(QString back)
{
    this->setStyleSheet("QMainWindow{background-image:url("+back+");}"
                        +"QTableWidget{background-color:rgba(255,255,255,200);}"
                        +"QScrollArea #scrollArea{background-color:rgba(255,255,255,200);}");

}









