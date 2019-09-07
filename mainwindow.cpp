#include "playlist.h"
#include "mainwindow.h"
#include "playlistbtn.h"
#include "ui_mainwindow.h"

#include <QIcon>
#include <QMenu>
#include <QDebug>
#include <QWidget>
#include <QAction>
#include <QLayout>
#include <QGroupBox>
#include <QListView>
#include <QMessageBox>
#include <QFileDialog>
#include <QScrollArea>
#include <QPushButton>
#include <QMouseEvent>
#include <QTableWidget>
#include <QAbstractButton>
#include <QSystemTrayIcon>

/* Author: zyt
 * Name: mainWindow
 * Function: 初始化侧边栏，建立前往mini模式/托盘模式的连接
 * Parameters: parent
 */
mainWindow::mainWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::mainWindow)
{
  ui->setupUi(this);

  mini = new Mini(this);
  sysTrayIcon = new QSystemTrayIcon(this);

  downloadListBtn = new QPushButton(this);
  downloadListBtn->setFlat(true);
  downloadListBtn->setText(" 我的下载");
  downloadListBtn->setFixedHeight(35);
  QFont downloadListBtnFont = downloadListBtn->font();
  downloadListBtnFont.setPointSize(11);
  downloadListBtn->setStyleSheet("text-align: left;");
  downloadListBtn->setFont(downloadListBtnFont);
  QIcon downloadIcon(":/image/image/musiclist.png");
  downloadListBtn->setIcon(downloadIcon);
  downloadListBtn->setIconSize(QSize(20,20));

  listBox = new QGroupBox(this);
  listBox->setTitle("列表");
  listBox->setStyleSheet("QGroupBox { border: none; font-size: 15px; }");
  addListBtn = new QPushButton(this);
  addListBtn->setText("+ 新建播放列表");
  QFont addListBtnFont = addListBtn->font();
  addListBtnFont.setPointSize(11);
  addListBtn->setFont(addListBtnFont);
  addListBtn->setFlat(true);

  ui->leftsideBarLayout->setAlignment(Qt::AlignTop);
  ui->leftsideBarLayout->addWidget(downloadListBtn);
  ui->leftsideBarLayout->addWidget(listBox);
  ui->leftsideBar->setLayout(ui->leftsideBarLayout);

  listBoxLayout = new QVBoxLayout;
  listBoxLayout->setAlignment(Qt::AlignTop);
  listBoxLayout->setContentsMargins(0,20,0,0);
  listBox->setLayout(listBoxLayout);
  listBoxLayout->addWidget(addListBtn);

  ui->showLeftBarBtn->setVisible(false);
  ui->showRightBarBtn->setVisible(false);

  historyContainer.append(new history);
  ui->historyLayout->setAlignment(Qt::AlignTop);
  ui->historyLayout->addWidget(historyContainer.last());
  ui->rightsideBar->setLayout(ui->historyLayout);

  if(whetherInitializeListButton())
    {
      // 显示用户的播放列表记录
    }
  else {
      // 什么都不显示
    }

  connect(mini,SIGNAL(miniToMaxSignal()),this,SLOT(miniToMaxSlot()));
  connect(mini,SIGNAL(miniToTraySignal()),this,SLOT(miniToTraySlot()));
  connect(addListBtn,SIGNAL(clicked()),this,SLOT(addListSlot()));
  connect(downloadListBtn,SIGNAL(clicked()),this,SLOT(showDownloadList()));
  connect(ui->displayList,SIGNAL(downloadFilesChangesSignal(int,QList<QString>)),
          this,SLOT(downloadFilesChangesSlot(int,QList<QString>)));
}

mainWindow::~mainWindow()
{
  delete ui;
}

/* Author: zyt
 * Name: whetherInitializeListButton
 * Function:（未实现） 检测用户的历史播放列表记录
 * Return:false：未创建
 *        true：创建过，按照历史纪录初始化
 */
bool mainWindow::whetherInitializeListButton()
{
  return false;
  Q_UNUSED(true);
  return true;
}

/* Author: zyt
 * Name: addListSlot
 * Function: 槽：实现添加列表操作，建立连接
 */
void mainWindow::addListSlot()
{
  playlistsContainer.append(new mergedPlaylist);
  listBoxLayout->addWidget(playlistsContainer.at(playlistsContainer.length()-1));
  connect(playlistsContainer.at(playlistsContainer.length()-1),
          SIGNAL(givingTempSNAndFiles(int,QList<QString>)),
          ui->displayList,
          SLOT(recevingSNAndFiles(int,QList<QString>)));

  connect(ui->displayList,
          SIGNAL(changeFilesInListSignal(int,QList<QString>)),
          playlistsContainer.at(playlistsContainer.length()-1),
          SLOT(changeFilesInListSlot(int,QList<QString>)));

  connect(playlistsContainer.at(playlistsContainer.length()-1),
          SIGNAL(showChangedListSignal(int,QList<QString>)),
          ui->displayList,
          SLOT(showChangedListSlot(int,QList<QString>)));

  connect(playlistsContainer.at(playlistsContainer.length()-1),
          SIGNAL(givingListName(QString)),
          this,
          SLOT(receivingListName(QString)));

  connect(playlistsContainer.at(playlistsContainer.length()-1),
          SIGNAL(hideContentsExceptThisSignal(int)),
          this,
          SLOT(hideContentsExceptThisSlot(int)));

  connect(playlistsContainer.at(playlistsContainer.length()-1),
          SIGNAL(allowDragAndMenuSignal()),
          this,
          SLOT(allowDragAndMenuSlot()));
}

/* Author: zyt
 * Name: showDownloadList
 * Function: 槽：显示我的下载列表
 */
void mainWindow::showDownloadList()
{
  //我的下载SN为0
  ui->displayList->recevingSNAndFiles(0,downloadSongs);
  ui->listNameLabel->setText("我的下载");

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
void mainWindow::downloadFilesChangesSlot(int sn, QList<QString> files)
{
  if(sn == 0)
    {
      downloadSongs = files;
    }
}

/* Author: zyt
 * Name: sendingFavoritesNameSlot
 * Function: 点击我的收藏时，显示displayList指向我的收藏
 */
void mainWindow::sendingFavoritesNameSlot(QString name)
{
  ui->listNameLabel->setText(name);
}

/* Author: zyt
 * Name: receivingListName
 * Function: 双击我的列表时，显示displayList指向对应的列表名字
 */
void mainWindow::receivingListName(QString listname)
{
  ui->listNameLabel->setText(listname);
}

/* Author: zyt
 * Name: hideContentsExceptThisSlot
 * Function: 收起除了该exceptSN的左侧列表
 */
void mainWindow::hideContentsExceptThisSlot(int exceptSN)
{
  for(int i = 0; i < playlistsContainer.length(); i++)
    {
      if(playlistsContainer.at(i)->getSN() != exceptSN)
        {
          emit playlistsContainer.at(i)->hideContentSignal();
        }
    }
}

/* Author: zyt
 * Name: allowDragAndMenuSlot
 * Function: 槽：允许列表的文件拖拽和右键事件
 */
void mainWindow::allowDragAndMenuSlot()
{
  //允许右键点击事件
  ui->displayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
  ui->displayList->setContextMenuPolicy(Qt::CustomContextMenu);

  //允许拖拽文件进入
  ui->displayList->setAcceptDrops(true);
}

/* Author: zyt
 * Name: on_hideLeftBarBtn_clicked
 * Function: 隐藏左侧边栏
 */
void mainWindow::on_hideLeftBarBtn_clicked()
{
  ui->scrollArea->setVisible(false);
  ui->showLeftBarBtn->setVisible(true);
  ui->hideLeftBarBtn->setVisible(false);
}

/* Author: zyt
 * Name: on_showLeftBarBtn_clicked
 * Function: 显示左侧边栏
 */
void mainWindow::on_showLeftBarBtn_clicked()
{
  ui->scrollArea->setVisible(true);
  ui->showLeftBarBtn->setVisible(false);
  ui->hideLeftBarBtn->setVisible(true);
}

/* Author: zyt
 * Name: on_hideRightBarBtn_clicked
 * Function: 隐藏右侧边栏
 */
void mainWindow::on_hideRightBarBtn_clicked()
{
  ui->historyList->setVisible(false);
  ui->showRightBarBtn->setVisible(true);
  ui->hideRightBarBtn->setVisible(false);
}

/* Author: zyt
 * Name: on_showRightBarBtn_clicked
 * Function: 显示右侧边栏
 */
void mainWindow::on_showRightBarBtn_clicked()
{
  ui->historyList->setVisible(true);
  ui->showRightBarBtn->setVisible(false);
  ui->hideRightBarBtn->setVisible(true);
}

/* Author: zyt
 * Name: creatActions
 * Function: 创建右键托盘菜单及图标的功能，并进行信号与槽的连接
 */
void mainWindow::creatActions()
{
  //为了测试，将默认播放状态设为真
  isPlaying = true;
  //实际情况待对接
  if(isPlaying)
    playOrPauseAction = new QAction("暂停");
  else if(!isPlaying)
    playOrPauseAction = new QAction("播放");

  showStatusAction = new QAction("暂无播放歌曲");
  lastSongAction = new QAction("上一首");
  nextSongAction = new QAction("下一首");

  playOrderMenu = new QMenu("播放模式");
  playOrder_orderAction = new QAction("顺序播放");
  playOrder_repeatAction = new QAction("单曲循环");
  playOrder_shuffleAction = new QAction("随机播放");
  playOrder_listOrderAction = new QAction("列表循环");
  playOrderMenu->addAction(playOrder_listOrderAction);
  playOrderMenu->addAction(playOrder_repeatAction);
  playOrderMenu->addAction(playOrder_shuffleAction);
  playOrderMenu->addAction(playOrder_orderAction);


  displayModeMenu = new QMenu("显示模式");
  displayMode_maxAction = new QAction("完整模式");
  displayMode_miniAction = new QAction("mini模式");
  displayMode_trayAction = new QAction("最小化");
  displayModeMenu->addAction(displayMode_maxAction);
  displayModeMenu->addAction(displayMode_miniAction);
  displayModeMenu->addAction(displayMode_trayAction);

  //testing checked
  displayMode_trayAction->setChecked(true);

  whetherShowLyricAction = new QAction("打开桌面歌词");
  whetherLockLyricAction = new QAction("锁定桌面歌词");

  settingAction = new QAction("设置");

  exitAction = new QAction("退出");

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

}

/* Author: zyt
 * Name: creatMenu
 * Function: 创建右键托盘图标的功能显示
 */
void mainWindow::creatMenu()
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
void mainWindow::on_systemTrayModeBtn_clicked()
{
  this->hide();

  QIcon icon = QIcon(":/image/image/test.png");
  sysTrayIcon->setIcon(icon);
  sysTrayIcon->setToolTip("TMZPlayer");

  creatActions();
  creatMenu();

  connect(sysTrayIcon,
          SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
          this,
          SLOT(on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason)));

  sysTrayIcon->show();

}

/* Author: zyt
 * Name: on_activatedSysTrayIcon
 * Function: 实现托盘的左键/双击/右键对应操作
 * Parameters: reason:操作名（单击/双击/右键)
 */
void mainWindow::on_activatedSysTrayIcon(QSystemTrayIcon::ActivationReason reason)
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
void mainWindow::on_showMainAction()
{
  this->show();
}

/* Author: zyt
 * Name: on_playOrPauseAction
 * Function: 槽：托盘菜单中播放/暂停键的切换
 */
void mainWindow::on_playOrPauseAction()
{
  if(isPlaying)
    {
      playOrPauseAction->setText("播放");
      playOrPauseAction->setIcon(QIcon(":/image/image/play.png"));
    }
  else if(!isPlaying)
    {
      playOrPauseAction->setText("暂停");
      playOrPauseAction->setIcon(QIcon(":/image/image/pause.jpg"));
    }
  isPlaying = !isPlaying;
}

/* Author: zyt
 * Name: on_displayMode_maxAction
 * Function: 槽，显示主界面
 */
void mainWindow::on_displayMode_maxAction()
{
  this->show();
  sysTrayIcon->hide();
}

/* Author: zyt
 * Name: on_displayMode_miniAction
 * Function: 槽，以mini模式显示
 */
void mainWindow::on_displayMode_miniAction()
{
  this->hide();
  on_miniMode_clicked();
}

/* Author: zyt
 * Name: on_exitAction
 * Function: 槽：退出播放器
 */
void mainWindow::on_exitAction()
{
  exit(0);
}


/* Author: zyt
 * Name: on_miniMode_clicked
 * Function: 槽：使播放器以mini模式显示
 */
void mainWindow::on_miniMode_clicked()
{
  this->hide();
  mini->show();
}

/* Author: zyt
 * Name: miniToMaxSlot
 * Function: 槽：mini->窗口模式
 */
void mainWindow::miniToMaxSlot()
{
  mini->hide();
  this->show();
}

/* Author: zyt
 * Name: miniToTraySlot
 * Function: 槽：mini->托盘模式
 */
void mainWindow::miniToTraySlot()
{
  mini->hide();
  on_systemTrayModeBtn_clicked();
}


