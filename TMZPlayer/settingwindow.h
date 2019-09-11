#ifndef SETTINGWINDOW_H
#define SETTINGWINDOW_H
#include<QHBoxLayout>
#include<QLayout>
#include<QPushButton>
#include <QDialog>
#include<QLabel>
#include<QWidget>
#include<QFrame>
#include<QStackedWidget>
#include<QColor>
#include<QColorDialog>
#include<QLabel>
#include<QFileDialog>
#include<QImage>
#include<QPalette>
#include<QMessageBox>
#include<QKeySequenceEdit>
#include "util/media.h"

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr, Media *m=nullptr);
    ~SettingWindow();
    SettingWindow * getSettingWindow();

signals:
    //修改字体类型信号 返回主页面
    void sigFontType(QFont *font) ;

    //修改主界面背景
    void sigChangeBackGround(QString);

    //修改主界面自定义背景
    void sigPictureBackGround(QString);

    //暂停播放快捷键更改
    void sigActionShortcut(QString);

    //上一首快捷键更改
    void sigLastShortcut(QString);

    //下一首快捷键更改
    void sigNextShortcut(QString);

    //音量增快捷键更改
    void sigLouderShortcut(QString);

    //音量减快捷键更改
    void sigLowerShortcut(QString);

    //收藏快捷键更改
    void sigLikeShortcut(QString);

    //静音复音快捷键更改
    void sigVolumeOnOffShortcut(QString);

    //快进快捷键更改
    void sigSpeedUpScreenShortcut(QString);

    //快退快捷键更改
    void sigSpeedDownScreenShortcut(QString);

    //亮度增快捷键更改
    void sigLuminUpShortcut(QString);

    //亮度减快捷键更改
    void sigLuminDownShortcut(QString);

    //打开文件快捷键更改
    void sigOpenFileShortcut(QString);

    //关闭文件快捷键更改
    void sigCloseFileShortcut(QString);

    //截图快捷键更改
    void sigScreenshotShortcut(QString);

    //倍速播放,连接bottomBar
    void sigSpeedChange(int);

    //关闭/最小化托盘,连接titleBar
    void sigCloseChange(int);

    //修改清晰度，连接bottomBar
    void sigDefinitionChange(int);

    //修改媒体库目录
    void sigPlayDirChange(QString);

    //修改下载路径
    void sigDownloadDirChange(QString);

    //修改截屏目录
    void sigShotDirChange(QString);

    //修改录屏目录
    void sigRecordDirChange(QString);

private slots:
    //切换页面1
    void on_pushButton_1_clicked();

    //切换页面2
    void on_pushButton_2_clicked();

    //切换页面3
    void on_pushButton_3_clicked();

    //修改字体颜色
    void on_colorButton_clicked();

    //修改媒体库路径
    void on_palyDirButton_clicked();

    //修改下载路径
    void on_downloadDirButton_clicked();

    //选择默认背景2
    void on_back1_clicked();

    //选择纯色背景2
    void on_back2_clicked();

    //选择纯色背景3
    void on_back3_clicked();

    //选择自定义图片背景
    void on_myBack_clicked();

    //截屏保存目录
    void on_shotDirButton_clicked();

    //录像保存目录
    void on_recordDirButton_clicked();

    //播放暂停快捷键
    void on_actionShortcutEdit_textChanged(const QString &arg1);

    //上一首快捷键
    void on_lastShortcutEdit_textChanged(const QString &arg1);

    //下一首快捷键
    void on_nextShortcutEdit_textChanged(const QString &arg1);

    //音量增快捷键
    void on_louderShortcutEdit_textChanged(const QString &arg1);

    //音量减快捷键
    void on_lowerShortcutEdit_textChanged(const QString &arg1);

    //收藏快捷键
    void on_likeShortcutEdit_textChanged(const QString &arg1);

    //静音复音快捷键
    void on_volumeOnOffEdit_textChanged(const QString &arg1);

    //快进快捷键
    void on_speedUpScreenEdit_textChanged(const QString &arg1);

    //快退快捷键
    void on_speedDownScreenEdit_textChanged(const QString &arg1);

    //亮度增快捷键
    void on_luminUpEdit_textChanged(const QString &arg1);

    //亮度减快捷键
    void on_luminDownEdit_textChanged(const QString &arg1);

    //打开文件快捷键
    void on_openFileEdit_textChanged(const QString &arg1);

    //关闭文件快捷键
    void on_closeFileEdit_textChanged(const QString &arg1);

    //截图快捷键
    void on_screenShotEdit_textChanged(const QString &arg1);

    //0.5倍速播放
    void on_radioButton_clicked();

    //1.0倍速播放
    void on_radioButton_2_clicked();

    //1.5倍速播放
    void on_radioButton_3_clicked();

    //2.0倍速播放
    void on_radioButton_4_clicked();

    //关闭->关闭TMZPlayer
    void on_toCloseButton_clicked();

    //关闭->最小化系统托盘
    void on_toBottomButton_clicked();

    //主界面修改设置界面倍速
    void speedChange(int);

    //普通清晰播放
    void on_lv1Button_2_clicked();

    //清晰清晰播放
    void on_lv2Button_2_clicked();

    //高清清晰播放
    void on_lv3Button_2_clicked();

    //主界面设置普通清晰播放
    void lv1DefinitionChange();

    //主界面设置清晰清晰播放
    void lv2DefinitionChange();

    //主界面设置高清清晰播放
    void lv3DefinitionChange();

private:
    Ui::SettingWindow *ui;
    QColorDialog * colDia;//调色盘窗口
    //播放模块zjy&ml
    Media* media;
};

#endif // SETTINGWINDOW_H
