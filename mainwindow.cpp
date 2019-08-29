#include "playlist.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMenu>
#include <QDebug>
#include <QWidget>
#include <QAction>
#include <QLayout>
#include <QPalette>
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
 * Function: 初始化侧边栏
 * Parameters: parent
 */
mainWindow::mainWindow(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::mainWindow)
{
  ui->setupUi(this);

  mini = new Mini;

  // Setting layouts for each box
  ui->scrollArea->widget()->setLayout(ui->ScrollLayout);
  ui->Online->setLayout(ui->OnlineLayout);
  ui->Local->setLayout(ui->LocalLayout);
  ui->List->setLayout(ui->ListLayout);
  ui->ListLayout->setAlignment(Qt::AlignTop);
  ui->ListLayout->setContentsMargins(0, 6, 0, 0);

  ui->showBtn->setVisible(false);


  if(mainWindow::whetherInitializeListButton())
    {
    // 显示用户的播放列表记录
    }
  else {
       // 什么都不显示
    }

}

mainWindow::~mainWindow()
{
  delete ui;
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
  connect(displayMode_miniAction,SIGNAL(thiggered()),this,SLOT(on_displayMode_miniAction()));

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
 * Name: getFileName
 * Function: 将文件路径以文件名称返回
 * Parameters: filePath: 文件路径
 */
QString mainWindow::getFileName(QString filePath)
{
  QFileInfo fileInfo(filePath);
  return fileInfo.fileName();
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
 * Name: on_addListBtn_clicked
 * Function: 打开播放列表的右键菜单
 */
void mainWindow::on_addListBtn_clicked()
{
   QPushButton *newList = new QPushButton("新建列表");
   ui->ListLayout->addWidget(newList);
   newList->setFlat(true);
   newList->setCursor(Qt::PointingHandCursor);
}

/* Author: zyt
 * Name: on_hideBtn_clicked
 * Function: 隐藏侧边栏
 */
void mainWindow::on_hideBtn_clicked()
{
    whetherHide = true; //用来调节主页面布局情况，隐藏则使右侧全屏显示（未实现）
    ui->scrollArea->setVisible(false);
    ui->showBtn->setVisible(true);
    ui->hideBtn->setVisible(false);
}

/* Author: zyt
 * Name: on_showBtn.clicked
 * Function: 显示侧边栏
 */
void mainWindow::on_showBtn_clicked()
{
    whetherHide = false;
    ui->scrollArea->setVisible(true);
    ui->showBtn->setVisible(false);
    ui->hideBtn->setVisible(true);
}

/* Author: zyt
 * Name: on_systemTrayModeBtn_clicked
 * Function: 使播放器转变为托盘模式
 */
void mainWindow::on_systemTrayModeBtn_clicked()
{
  this->hide();
  sysTrayIcon = new QSystemTrayIcon(this);
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
}

/* Author: zyt
 * Name: on_displayMode_miniAction
 * Function: 槽，以mini模式显示
 */
void mainWindow::on_displayMode_miniAction()
{
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
 * Name: on_playlist_customContestMenuRequested
 * Function: 实现在播放列表点击右键出现菜单
 * Parameters: pos（记录点击的位置，使右键菜单在那里出现）
 */
void mainWindow::on_playlist_customContextMenuRequested(const QPoint &pos)
{
  Q_UNUSED(pos);
  QMenu *pPopMenu = new QMenu(this);
  pPopMenu->addAction("添加文件",this,SLOT(addFiles()));

  //判断右键位置有没有文件
  if (ui->playlist->currentRow() > -1)
    {
      pPopMenu->addAction("从列表中删除",this,SLOT(deleteFileFromList()));
      pPopMenu->addAction("从电脑中删除",this,SLOT(deleteFileFromDisk()));
    }
  pPopMenu->exec(QCursor::pos());
}

/* Author: zyt
 * Name: addFiles
 * Function: 实现播放列表右键菜单中添加文件的功能
 */
void mainWindow::addFiles()
{
  QFileDialog* selectDialog = new QFileDialog(this);
  selectDialog->setFileMode(QFileDialog::ExistingFiles);
  selectDialog->setNameFilter("音乐文件(*.mp3 *.flac *.wav *.wma);;"
                              "视频文件(*.avi *.mov *.rmvb *.mp4)");
  selectDialog->setViewMode(QFileDialog::Detail);

  QStringList fileNames;
  if ( selectDialog->exec() == QDialog::Accepted )
  {
    fileNames = selectDialog->selectedFiles();
  }

  for (int i = 0;i < fileNames.length(); i++)
  {
    int row = ui->playlist->rowCount();
    ui->playlist->insertRow(row);
    QTableWidgetItem *item = new QTableWidgetItem(fileNames.at(i));
   // ui->playlist->setItem(row, 0, pItemInfo);
    item = new QTableWidgetItem(getFileName(fileNames.at(i)));
    ui->playlist->setItem(row, 0, item);
    }
}

/* Author: zyt
 * Name: deleteFileFromList
 * Function: 在播放列表中删除选中的文件（从列表中删除）
 */
void mainWindow::deleteFileFromList()
{
  int row = ui->playlist->currentRow();
  ui->playlist->removeRow(row);
}

/* Author: zyt
 * Name: deleteFileFromDisk
 * Function: 在播放列表中删除选中的文件（从列表、本地删除）（从磁盘中删除未实现）
 */
void mainWindow::deleteFileFromDisk()
{
  // get path
  int row = ui->playlist->currentRow();
  QTableWidgetItem *pItem = ui->playlist->item(row, 0);

  QFile file(pItem->text());
  QMessageBox doubleCheckBox;
  doubleCheckBox.setText("本地文件将删除");
  doubleCheckBox.setInformativeText("确定?");
  doubleCheckBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
  doubleCheckBox.setDefaultButton(QMessageBox::Cancel);

  if (doubleCheckBox.exec() == QMessageBox::Ok)
  {
    if (file.remove())
    {
      //文件位置改变，只需要从列表中删除
      ui->playlist->removeRow(row);
     }
  }
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
 * Name: switchToMax
 * Function: 槽：从mini模式切换到窗口模式
 */
void mainWindow::switchToMax()
{
  mini->hide();
  this->show();
}

