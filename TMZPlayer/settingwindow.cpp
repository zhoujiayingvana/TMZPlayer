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
SettingWindow::SettingWindow(QWidget *parent,Media * m) :
    QDialog(parent),
    ui(new Ui::SettingWindow),media(m)
{
    ui->setupUi(this);

    this->setWindowTitle("设置");

    QKeySequenceEdit s;

    //连接recordSizeSpinBox和recordSizeSlider互相修改
    connect(ui->recordSizeSpinBox, SIGNAL(valueChanged(int)), ui->recordSizeSlider, SLOT(setValue(int)));
    connect(ui->recordSizeSlider, SIGNAL(valueChanged(int)), ui->recordSizeSpinBox, SLOT(setValue(int)));
    ui->recordSizeSpinBox->setMinimum(0);
    ui->recordSizeSpinBox->setMaximum(300);
    ui->recordSizeSlider->setMinimum(0);
    ui->recordSizeSlider->setMaximum(300);
    ui->recordSizeSpinBox->setSuffix("s");
    ui->recordSizeSpinBox->setWrapping(true);

    //连接quickMoveSpinBox和quickMoveSlider互相修改
    connect(ui->quickMoveSpinBox,SIGNAL(valueChanged(int)),ui->quickMoveSlider,SLOT(setValue(int)));
    connect(ui->quickMoveSlider,SIGNAL(valueChanged(int)),ui->quickMoveSpinBox,SLOT(setValue(int)));
    ui->quickMoveSlider->setMinimum(0);
    ui->quickMoveSlider->setMaximum(30);
    ui->quickMoveSpinBox->setMinimum(0);
    ui->quickMoveSpinBox->setMaximum(30);
    ui->quickMoveSpinBox->setSpecialValueText(tr("Automatic"));
    ui->quickMoveSlider->setValue(5);
    ui->quickMoveSpinBox->setValue(5);
    ui->quickMoveSpinBox->setSuffix("s");
    ui->quickMoveSpinBox->setWrapping(true);

    //字体SpinBox
    ui->fontSpinBox->setMinimum(9);
    ui->fontSpinBox->setMaximum(26);
    ui->fontSpinBox->setSingleStep(1);

    //调整滚动条
    ui->page2ScrollAreaWidgetContents->resize(489, 770);

    //鼠标悬停在按钮上显示提示条
    ui->pushButton_1->setToolTip(QStringLiteral("常规"));
    ui->pushButton_2->setToolTip(QStringLiteral("工具"));
    ui->pushButton_3->setToolTip(QStringLiteral("播放和下载"));
    ui->toBottomButton->setToolTip(QStringLiteral("最小化到系统托盘"));
    ui->toCloseButton->setToolTip(QStringLiteral("关闭TMZPlayer"));
    ui->colorButton->setToolTip(QStringLiteral("选择字体颜色"));
    ui->back1->setToolTip(QStringLiteral("黑色"));
    ui->back2->setToolTip(QStringLiteral("蓝色"));
    ui->back3->setToolTip(QStringLiteral("粉色"));
    ui->myBack->setToolTip(QStringLiteral("选择背景图片"));
    ui->radioButton->setToolTip(QStringLiteral("0.5"));
    ui->radioButton_2->setToolTip(QStringLiteral("1.0"));
    ui->radioButton_3->setToolTip(QStringLiteral("1.5"));
    ui->radioButton_4->setToolTip(QStringLiteral("2.0"));
    ui->shotDirButton->setToolTip(QStringLiteral("更改目录"));
    ui->recordDirButton->setToolTip(QStringLiteral("更改目录"));
    ui->checkBox->setToolTip(QStringLiteral("是"));
    ui->lv1Button->setToolTip(QStringLiteral("普通"));
    ui->lv2Button->setToolTip(QStringLiteral("清晰"));
    ui->lv3Button->setToolTip(QStringLiteral("高清"));
    ui->lv1Button_2->setToolTip(QStringLiteral("普通"));
    ui->lv2Button_2->setToolTip(QStringLiteral("清晰"));
    ui->lv3Button_2->setToolTip(QStringLiteral("高清"));
    ui->palyDirButton->setToolTip(QStringLiteral("更改目录"));
    ui->downloadDirButton->setToolTip(QStringLiteral("更改目录"));
    ui->picJpgButton->setToolTip(QStringLiteral(".jpg"));
    ui->picPngButton->setToolTip(QStringLiteral(".png"));
    ui->picWebpButton->setToolTip(QStringLiteral(".webp"));

    //改变光标样式
    ui->pushButton_1->setCursor(Qt::PointingHandCursor);
    ui->pushButton_2->setCursor(Qt::PointingHandCursor);
    ui->pushButton_3->setCursor(Qt::PointingHandCursor);
    ui->toCloseButton->setCursor(Qt::PointingHandCursor);
    ui->toBottomButton->setCursor(Qt::PointingHandCursor);
    ui->colorButton->setCursor(Qt::PointingHandCursor);
    ui->back1->setCursor(Qt::PointingHandCursor);
    ui->back2->setCursor(Qt::PointingHandCursor);
    ui->back3->setCursor(Qt::PointingHandCursor);
    ui->myBack->setCursor(Qt::PointingHandCursor);
    ui->radioButton->setCursor(Qt::PointingHandCursor);
    ui->radioButton_2->setCursor(Qt::PointingHandCursor);
    ui->radioButton_3->setCursor(Qt::PointingHandCursor);
    ui->radioButton_4->setCursor(Qt::PointingHandCursor);
    ui->shotDirButton->setCursor(Qt::PointingHandCursor);
    ui->recordDirButton->setCursor(Qt::PointingHandCursor);
    ui->checkBox->setCursor(Qt::PointingHandCursor);
    ui->recordSizeSlider->setCursor(Qt::PointingHandCursor);
    ui->quickMoveSlider->setCursor(Qt::PointingHandCursor);
    ui->lv1Button->setCursor(Qt::PointingHandCursor);
    ui->lv2Button->setCursor(Qt::PointingHandCursor);
    ui->lv3Button->setCursor(Qt::PointingHandCursor);
    ui->lv1Button_2->setCursor(Qt::PointingHandCursor);
    ui->lv2Button_2->setCursor(Qt::PointingHandCursor);
    ui->lv3Button_2->setCursor(Qt::PointingHandCursor);
    ui->palyDirButton->setCursor(Qt::PointingHandCursor);
    ui->downloadDirButton->setCursor(Qt::PointingHandCursor);
    ui->picJpgButton->setCursor(Qt::PointingHandCursor);
    ui->picPngButton->setCursor(Qt::PointingHandCursor);
    ui->picWebpButton->setCursor(Qt::PointingHandCursor);



    //设置窗口固定大小
    setFixedSize(this->width(),this->height());


    //设置按键背景颜色
    ui->back1->setStyleSheet("background-color:black");
    ui->back2->setStyleSheet("background-color:#55aaff");
    ui->back3->setStyleSheet("background-color:#ff99c0");

    //修改buttonBox，英译中
    ui->buttonBox->button(QDialogButtonBox::Yes)->setText("确定");

    //取消tab
    ui->toBottomButton->setFocusPolicy(Qt::NoFocus);
    ui->toCloseButton->setFocusPolicy(Qt::NoFocus);
    ui->colorButton->setFocusPolicy(Qt::NoFocus);
    ui->back1->setFocusPolicy(Qt::NoFocus);
    ui->back2->setFocusPolicy(Qt::NoFocus);
    ui->back3->setFocusPolicy(Qt::NoFocus);
    ui->myBack->setFocusPolicy(Qt::NoFocus);
    ui->shotDirButton->setFocusPolicy(Qt::NoFocus);
    ui->recordDirButton->setFocusPolicy(Qt::NoFocus);
    ui->radioButton->setFocusPolicy(Qt::NoFocus);
    ui->radioButton_2->setFocusPolicy(Qt::NoFocus);
    ui->radioButton_3->setFocusPolicy(Qt::NoFocus);
    ui->radioButton_4->setFocusPolicy(Qt::NoFocus);
    ui->downloadDirButton->setFocusPolicy(Qt::NoFocus);
    ui->lv1Button->setFocusPolicy(Qt::NoFocus);
    ui->lv2Button->setFocusPolicy(Qt::NoFocus);
    ui->lv3Button->setFocusPolicy(Qt::NoFocus);
    ui->lv1Button_2->setFocusPolicy(Qt::NoFocus);
    ui->lv2Button_2->setFocusPolicy(Qt::NoFocus);
    ui->lv3Button_2->setFocusPolicy(Qt::NoFocus);
    ui->palyDirButton->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_1->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_2->setFocusPolicy(Qt::NoFocus);
    ui->pushButton_3->setFocusPolicy(Qt::NoFocus);
    ui->fontComboBox->setFocusPolicy(Qt::NoFocus);
    ui->fontSpinBox->setFocusPolicy(Qt::NoFocus);
    ui->recordSizeSpinBox->setFocusPolicy(Qt::NoFocus);
    ui->checkBox->setFocusPolicy(Qt::NoFocus);
    ui->buttonBox->setFocusPolicy(Qt::NoFocus);
    ui->quickMoveSpinBox->setFocusPolicy(Qt::NoFocus);

    QString back1Str=":/new/prefix1/myQss/style2.qss";
    QFile qssfile(":/new/prefix1/myQss/style2.qss");
    qssfile.open(QFile::ReadOnly);
    if(!qssfile.exists())
        qDebug() <<"no file";
    QString qss;
    qss = qssfile.readAll();
    this->setStyleSheet(qss);

    //设置按键初始颜色
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
* @param         VOID
* @return        VOID
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
* @param         VOID
* @return        VOID
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
* @param         VOID
* @return        VOID
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
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-08-23
*/
void SettingWindow::on_colorButton_clicked()
{
    QColor col;
    //弹出颜色对话框
    colDia=new QColorDialog(col,this);
    colDia->setWindowTitle("选择字体颜色");
    colDia->setFocusPolicy(Qt::NoFocus);
    int ret =colDia->exec();
    if(QDialog::Accepted == ret)
    {
        qDebug() << "修改颜色";
        QColor color=colDia->currentColor();
        QString c=color.name();
        qDebug()<<c;
        ui->colorButton->setStyleSheet("background-color:"+c+";");

        //修改字幕颜色
        //        QPalette p=ui->colorButton->palette();//读原字体颜色
        //        p.setColor(QPalette::Button,color);
        //        ui->colorButton->setPalette(p);s
        //p.setColor(字体,color);改
        //emit(颜色修改信号)写
    }
}

/**
* @method        SettingWindow::on_palyDirButton_clicked
* @brief         选择播放媒体库目录 修改时同时更改playDirLabel内容
*                修改播放路径 未与TMZPlayer界面connect
* @param         VOID
* @return        VOID
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
        emit sigPlayDirChange(dirName);
    }
}

/**
* @method        SettingWindow::on_downloadDirButton_clicked
* @brief         选择下载路径 修改时同时更改downloadDirLabel内容
*                修改下载路径 未与TMZPlayer界面connect
* @param         VOID
* @return        VOID
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
        emit sigDownloadDirChange(dirName);
    }
}

/**
* @method        SettingWindow::on_shotDirButton_clicked
* @brief         更改截屏保存目录
* @param         VOID
* @return        VOID
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
        emit sigShotDirChange(dirName);
    }
}

/**
* @method        SettingWindow::on_recordDirButton_clicked
* @brief         更改录屏保存目录
* @param         VOID
* @return        VOID
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
        emit sigRecordDirChange(dirName);
    }
}

/**
* @method        SettingWindow::on_back1_clicked
* @brief         修改默认纯色背景1信号
* @param         VOID
* @return        VOID
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
* @param         VOID
* @return        VOID
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
* @param         VOID
* @return        VOID
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
* @param         VOID
* @return        VOID
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
* @param         STRING
* @return        VOID
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
* @param         STRING
* @return        VOID
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
* @param         STRING
* @return        VOID
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
* @param         STRING
* @return        VOID
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
* @param         STRING
* @return        VOID
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
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-08-29
*/
void SettingWindow::on_likeShortcutEdit_textChanged(const QString &arg1)
{
    emit sigLikeShortcut(arg1);
}

/**
* @method        SettingWindow::on_volumeOnOffEdit_textChanged
* @brief         静音复音快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_volumeOnOffEdit_textChanged(const QString &arg1)
{
    emit sigVolumeOnOffShortcut(arg1);
}

/**
* @method        SettingWindow::on_speedUpScreenEdit_textChanged
* @brief         快进快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_speedUpScreenEdit_textChanged(const QString &arg1)
{
    emit sigSpeedUpScreenShortcut(arg1);
}

/**
* @method        SettingWindow::on_speedDownScreenEdit_textChanged
* @brief         快退快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_speedDownScreenEdit_textChanged(const QString &arg1)
{
    emit sigSpeedDownScreenShortcut(arg1);
}

/**
* @method        SettingWindow::on_luminUpEdit_textChanged
* @brief         亮度增快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_luminUpEdit_textChanged(const QString &arg1)
{
    emit sigLuminUpShortcut(arg1);
}

/**
* @method        SettingWindow::on_luminDownEdit_textChanged
* @brief         亮度减快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_luminDownEdit_textChanged(const QString &arg1)
{
    emit sigLuminDownShortcut(arg1);
}

/**
* @method        SettingWindow::on_openFileEdit_textChanged
* @brief         打开文件快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_openFileEdit_textChanged(const QString &arg1)
{
    emit sigOpenFileShortcut(arg1);
}

/**
* @method        SettingWindow::on_closeFileEdit_textChanged
* @brief         停止/关闭文件快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_closeFileEdit_textChanged(const QString &arg1)
{
    emit sigCloseFileShortcut(arg1);
}

/**
* @method        SettingWindow::on_screenShotEdit_textChanged
* @brief         截图快捷键修改
* @param         STRING
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_screenShotEdit_textChanged(const QString &arg1)
{
    emit sigScreenshotShortcut(arg1);
}


/**
* @method        SettingWindow::on_radioButton_clicked
* @brief         0.5倍速播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-03
*/
void SettingWindow::on_radioButton_clicked()
{
    emit sigSpeedChange(1);
}

/**
* @method        SettingWindow::on_radioButton_2_clicked
* @brief         1倍速播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-03
*/
void SettingWindow::on_radioButton_2_clicked()
{
    emit sigSpeedChange(2);
}

/**
* @method        SettingWindow::on_radioButton_3_clicked
* @brief         1.5倍速播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-03
*/
void SettingWindow::on_radioButton_3_clicked()
{
    emit sigSpeedChange(3);
}

/**
* @method        SettingWindow::on_radioButton_4_clicked
* @brief         2倍速播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-03
*/
void SettingWindow::on_radioButton_4_clicked()
{
    emit sigSpeedChange(4);
}

/**
* @method        SettingWindow::on_toCloseButton_clicked
* @brief         关闭窗口
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-03
*/
void SettingWindow::on_toCloseButton_clicked()
{
    emit sigCloseChange(1);
}

/**
* @method        SettingWindow::on_toBottomButton_clicked
* @brief         最小化托盘
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-03
*/
void SettingWindow::on_toBottomButton_clicked()
{
    emit sigCloseChange(2);
}

/**
* @method        SettingWindow::speedChange
* @brief         主界面修改设置界面倍速
* @param         INT
* @return        VOID
* @author        涂晴昊
* @date          2019-09-04
*/
void SettingWindow::speedChange(int s)
{
    if(s==0)
        ui->radioButton->setChecked(true);
    else if(s==1)
        ui->radioButton_2->setChecked(true);
    else if(s==2)
        ui->radioButton_3->setChecked(true);
    else ui->radioButton_4->setChecked(true);
}

/**
* @method        SettingWindow::on_lv1Button_2_clicked
* @brief         普通播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_lv1Button_2_clicked()
{
    emit sigDefinitionChange(1);
}

/**
* @method        SettingWindow::on_lv2Button_2_clicked
* @brief         清晰播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_lv2Button_2_clicked()
{
    emit sigDefinitionChange(2);
}

/**
* @method        SettingWindow::on_lv3Button_2_clicked
* @brief         高清播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::on_lv3Button_2_clicked()
{
    emit sigDefinitionChange(3);
}

/**
* @method        SettingWindow::lv1DefinitionChange
* @brief         主界面->设置界面普通清晰播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::lv1DefinitionChange()
{
    ui->lv1Button_2->setChecked(true);
}

/**
* @method        SettingWindow::lv2DefinitionChange
* @brief         主界面->设置界面清晰清晰播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::lv2DefinitionChange()
{
    ui->lv2Button_2->setChecked(true);
}

/**
* @method        SettingWindow::lv3DefinitionChange
* @brief         主界面->设置界面高清清晰播放
* @param         VOID
* @return        VOID
* @author        涂晴昊
* @date          2019-09-05
*/
void SettingWindow::lv3DefinitionChange()
{
    ui->lv3Button_2->setChecked(true);
}
