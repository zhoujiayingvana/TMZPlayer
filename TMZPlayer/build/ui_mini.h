/********************************************************************************
** Form generated from reading UI file 'mini.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINI_H
#define UI_MINI_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mini
{
public:
    QLabel *songLabel;
    QLabel *singerLabel;
    QPushButton *likeBtn;
    QPushButton *volumeBtn;
    QPushButton *listBtn;
    QPushButton *closeBtn;
    QPushButton *maxModeBtn;
    QPushButton *albumPic;
    QPushButton *lastSongBtn;
    QPushButton *playOrPauseBtn;
    QPushButton *nextSongBtn;

    void setupUi(QWidget *Mini)
    {
        if (Mini->objectName().isEmpty())
            Mini->setObjectName(QString::fromUtf8("Mini"));
        Mini->resize(408, 64);
        QPalette palette;
        QBrush brush(QColor(246, 246, 246, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush);
        Mini->setPalette(palette);
        songLabel = new QLabel(Mini);
        songLabel->setObjectName(QString::fromUtf8("songLabel"));
        songLabel->setGeometry(QRect(80, 10, 171, 21));
        songLabel->setAlignment(Qt::AlignCenter);
        singerLabel = new QLabel(Mini);
        singerLabel->setObjectName(QString::fromUtf8("singerLabel"));
        singerLabel->setGeometry(QRect(81, 40, 171, 21));
        singerLabel->setAlignment(Qt::AlignCenter);
        likeBtn = new QPushButton(Mini);
        likeBtn->setObjectName(QString::fromUtf8("likeBtn"));
        likeBtn->setGeometry(QRect(260, 20, 25, 25));
        likeBtn->setFlat(true);
        volumeBtn = new QPushButton(Mini);
        volumeBtn->setObjectName(QString::fromUtf8("volumeBtn"));
        volumeBtn->setGeometry(QRect(300, 20, 25, 25));
        volumeBtn->setFlat(true);
        listBtn = new QPushButton(Mini);
        listBtn->setObjectName(QString::fromUtf8("listBtn"));
        listBtn->setGeometry(QRect(340, 20, 25, 25));
        listBtn->setFlat(true);
        closeBtn = new QPushButton(Mini);
        closeBtn->setObjectName(QString::fromUtf8("closeBtn"));
        closeBtn->setGeometry(QRect(390, 0, 20, 20));
        closeBtn->setFlat(true);
        maxModeBtn = new QPushButton(Mini);
        maxModeBtn->setObjectName(QString::fromUtf8("maxModeBtn"));
        maxModeBtn->setGeometry(QRect(390, 20, 20, 20));
        maxModeBtn->setFlat(true);
        albumPic = new QPushButton(Mini);
        albumPic->setObjectName(QString::fromUtf8("albumPic"));
        albumPic->setGeometry(QRect(0, 0, 64, 64));
        lastSongBtn = new QPushButton(Mini);
        lastSongBtn->setObjectName(QString::fromUtf8("lastSongBtn"));
        lastSongBtn->setGeometry(QRect(110, 22, 18, 18));
        playOrPauseBtn = new QPushButton(Mini);
        playOrPauseBtn->setObjectName(QString::fromUtf8("playOrPauseBtn"));
        playOrPauseBtn->setGeometry(QRect(150, 15, 34, 34));
        nextSongBtn = new QPushButton(Mini);
        nextSongBtn->setObjectName(QString::fromUtf8("nextSongBtn"));
        nextSongBtn->setGeometry(QRect(203, 23, 18, 18));

        retranslateUi(Mini);

        QMetaObject::connectSlotsByName(Mini);
    } // setupUi

    void retranslateUi(QWidget *Mini)
    {
        Mini->setWindowTitle(QApplication::translate("Mini", "Form", nullptr));
        songLabel->setText(QApplication::translate("Mini", "\346\232\202\346\227\240\346\255\214\346\233\262\346\222\255\346\224\276", nullptr));
        singerLabel->setText(QApplication::translate("Mini", "~", nullptr));
        likeBtn->setText(QString());
        volumeBtn->setText(QString());
        listBtn->setText(QString());
        closeBtn->setText(QString());
        maxModeBtn->setText(QString());
        albumPic->setText(QString());
        lastSongBtn->setText(QApplication::translate("Mini", "PushButton", nullptr));
        playOrPauseBtn->setText(QApplication::translate("Mini", "PushButton", nullptr));
        nextSongBtn->setText(QApplication::translate("Mini", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mini: public Ui_Mini {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINI_H
