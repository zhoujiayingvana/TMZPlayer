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

namespace Ui {
class SettingWindow;
}

class SettingWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingWindow(QWidget *parent = nullptr);
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

    void on_shotDirButton_clicked();

    void on_recordDirButton_clicked();

    void on_actionShortcutEdit_textChanged(const QString &arg1);

    void on_lastShortcutEdit_textChanged(const QString &arg1);

    void on_nextShortcutEdit_textChanged(const QString &arg1);

    void on_louderShortcutEdit_textChanged(const QString &arg1);

    void on_lowerShortcutEdit_textChanged(const QString &arg1);

    void on_likeShortcutEdit_textChanged(const QString &arg1);



private:
    Ui::SettingWindow *ui;
};

#endif // SETTINGWINDOW_H
