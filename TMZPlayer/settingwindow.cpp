/**
* @projectName   TMZPlayer
* @brief         设置界面
* @author        涂晴昊
* @date          2019-08-23
*/

#include "settingwindow.h"
#include "ui_settingwindow.h"
#include<QDebug>

/**
* @method        SettingWindow::SettingWindow
* @brief         创建SettingWindow，添加资源文件，建立内部连接
* @author        涂晴昊
* @date          2019-08-23
*/
SettingWindow::SettingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingWindow)
{
    ui->setupUi(this);

    //连接recordSizeSpinBox和recordSizeSlider互相修改
    connect(ui->recordSizeSpinBox, SIGNAL(valueChanged(int)), ui->recordSizeSlider, SLOT(setValue(int)));
    connect(ui->recordSizeSlider, SIGNAL(valueChanged(int)), ui->recordSizeSpinBox, SLOT(setValue(int)));

    //调整滚动条
    ui->page2ScrollAreaWidgetContents->resize(489, 770);

    //鼠标悬停在按钮上显示提示条
    ui->pushButton_1->setToolTip(QStringLiteral("常规"));
    ui->pushButton_2->setToolTip(QStringLiteral("工具"));
    ui->pushButton_3->setToolTip(QStringLiteral("播放和下载"));

    //设置窗口固定大小
    setFixedSize(this->width(),this->height());


    //设置按键背景颜色
    ui->back1->setStyleSheet("background-color:black");
    ui->back2->setStyleSheet("background-color:#55aaff");
    ui->back3->setStyleSheet("background-color:#ff99c0");

    //修改buttonBox，英译中
    ui->buttonBox->button(QDialogButtonBox::Yes)->setText("确定");
    ui->buttonBox->button(QDialogButtonBox::Cancel)->setText("取消");

    QString back1Str=":/new/prefix1/myQss/style1.qss";
    QFile qssfile(":/new/prefix1/myQss/style1.qss");
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);

    ui->colorButton->setStyleSheet("background-color:white");
    ui->myBack->setStyleSheet("background-color:white");
}

SettingWindow::~SettingWindow()
{
    delete ui;
}

SettingWindow *SettingWindow::getSettingWindow()
{
    return this;
}

/**
* @method        SettingWindow::on_pushButton_1_clicked
* @brief         切换至常规页面1
* @author        涂晴昊
* @date          2019-08-23
*/
void SettingWindow::on_pushButton_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

/**
* @method        SettingWindow::on_pushButton_2_clicked
* @brief         切换至工具页面2
* @author        涂晴昊
* @date          2019-08-23
*/
void SettingWindow::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

/**
* @method        SettingWindow::on_pushButton_3_clicked
* @brief         切换至下载页面3
* @author        涂晴昊
* @date          2019-08-23
*/
void SettingWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

/**
* @method        SettingWindow::on_colorButton_clicked
* @brief         弹出颜色对话框 修改字体颜色 需与MainWindow字幕关联
* @author        涂晴昊
* @date          2019-08-23
*/
void SettingWindow::on_colorButton_clicked()
{
    QColor col;
    //弹出颜色对话框
    QColorDialog dlg(col,this);
    int ret =dlg.exec();
    if(QDialog::Accepted == ret)
    {
        qDebug() << "修改颜色";
        QColor color=dlg.currentColor();
        QPalette p;//读原字体颜色
        //p.setColor(字体,color);改
        //emit(颜色修改信号)写
    }
}

/**
* @method        SettingWindow::on_palyDirButton_clicked
* @brief         选择播放媒体库目录 修改时同时更改playDirLabel内容
*                修改播放路径 未与TMZPlayer界面connect
* @author        涂晴昊
* @date          2019-08-23
*/
void SettingWindow::on_palyDirButton_clicked()
{
    QLabel * playDir = ui->playDirLabel;
    QString dirName =QFileDialog::getExistingDirectory(this,"选择目录","C:/CloudMusic");
    if(dirName!="")
    {
    playDir->setText(dirName);
    ui->playDirLabel->setText(playDir->text());
    //emit
    }
}

/**
* @method        SettingWindow::on_downloadDirButton_clicked
* @brief         选择下载路径 修改时同时更改downloadDirLabel内容
*                修改下载路径 未与TMZPlayer界面connect
* @author        涂晴昊
* @date          2019-08-23
*/
void SettingWindow::on_downloadDirButton_clicked()
{
    QLabel * downloadDir = ui->downloadDirLabel;
    QString dirName =QFileDialog::getExistingDirectory(this,"选择目录","C:/CloudMusic");
    if(dirName!="")
    {
    downloadDir->setText(dirName);
    ui->downloadDirLabel->setText(downloadDir->text());
    //emit
    }
}

/**
* @method        SettingWindow::on_shotDirButton_clicked
* @brief         更改截屏保存目录
* @author        涂晴昊
* @date          2019-08-27
*/
void SettingWindow::on_shotDirButton_clicked()
{
    QLabel * shotDir = ui->shotDirLabel;
    QString dirName =QFileDialog::getExistingDirectory(this,"选择目录","C:/CloudMusic/image");
    if(dirName!="")
    {
    shotDir->setText(dirName);
    ui->shotDirLabel->setText(shotDir->text());
    //emit
    }
}

/**
* @method        SettingWindow::on_recordDirButton_clicked
* @brief         更改录屏保存目录
* @author        涂晴昊
* @date          2019-08-27
*/
void SettingWindow::on_recordDirButton_clicked()
{
    QLabel * shotDir = ui->shotDirLabel;
    QString dirName =QFileDialog::getExistingDirectory(this,"选择目录","C:/CloudMusic/record");
    if(dirName!="")
    {
    shotDir->setText(dirName);
    ui->shotDirLabel->setText(shotDir->text());
    //emit
    }
}

/**
* @method        SettingWindow::on_back1_clicked
* @brief         修改默认纯色背景1信号
* @author        涂晴昊
* @date          2019-08-26
*/
void SettingWindow::on_back1_clicked()
{
    QString back1Str=":/new/prefix1/myQss/style1.qss";
    QFile qssfile(":/new/prefix1/myQss/style1.qss");
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);
    emit sigChangeBackGround(back1Str);
}

/**
* @method        SettingWindow::on_back2_clicked
* @brief         修改默认纯色背景2信号
* @author        涂晴昊
* @date          2019-08-28
*/
void SettingWindow::on_back2_clicked()
{
    QString back2Str=":/new/prefix1/myQss/style2.qss";
    QFile qssfile(":/new/prefix1/myQss/style2.qss");
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);
    emit sigChangeBackGround(back2Str);
}

/**
* @method        SettingWindow::on_back3_clicked
* @brief         修改默认纯色背景3信号
* @author        涂晴昊
* @date          2019-08-28
*/
void SettingWindow::on_back3_clicked()
{
    QString back3Str=":/new/prefix1/myQss/style3.qss";
    QFile qssfile(":/new/prefix1/myQss/style3.qss");
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);
    emit sigChangeBackGround(back3Str);
}

/**
* @method        SettingWindow::on_myBack_clicked
* @brief         更换自定义图片背景
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_myBack_clicked()
{
    QString fileName =QFileDialog::getOpenFileName(this,"选择图片","C:/CloudMusic",
                                                   tr("Images (*.png *.bmp *.jpg *.tif *.GIF )"));
    if(fileName.isEmpty())
    {
        return;
    }
    else
    {
        this->setStyleSheet("QDialog{background-image:url("+fileName+")}");
        emit sigPictureBackGround(fileName);
    }
}

/**
* @method        SettingWindow::on_actionShortcutEdit_textChanged
* @brief         播放暂停快捷键修改
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_actionShortcutEdit_textChanged(const QString &arg1)
{
    emit sigActionShortcut(arg1);
}

/**
* @method        SettingWindow::on_lastShortcutEdit_textChanged
* @brief         上一首快捷键修改
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_lastShortcutEdit_textChanged(const QString &arg1)
{
    emit sigLastShortcut(arg1);
}

/**
* @method        SettingWindow::on_nextShortcutEdit_textChanged
* @brief         下一首快捷键修改
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_nextShortcutEdit_textChanged(const QString &arg1)
{
    emit sigNextShortcut(arg1);
}

/**
* @method        SettingWindow::on_louderShortcutEdit_textChanged
* @brief         音量增快捷键修改
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_louderShortcutEdit_textChanged(const QString &arg1)
{
    emit sigLouderShortcut(arg1);
}

/**
* @method        SettingWindow::on_lowerShortcutEdit_textChanged
* @brief         音量减快捷键修改
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_lowerShortcutEdit_textChanged(const QString &arg1)
{
    emit sigLowerShortcut(arg1);
}

/**
* @method        SettingWindow::on_likeShortcutEdit_textChanged
* @brief         收藏快捷键修改
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_likeShortcutEdit_textChanged(const QString &arg1)
{
    emit sigLikeShortcut(arg1);
}

