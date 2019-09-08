/********************************************************************************
** Form generated from reading UI file 'testmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTMAINWINDOW_H
#define UI_TESTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *nextButton;
    QSlider *horizontalSlider;
    QPushButton *terminateButton;
    QPushButton *forwardButton;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QPushButton *volumeUpButton;
    QPushButton *volumeDownButton;
    QPushButton *jumpButton;
    QPushButton *muteButton;
    QPushButton *nonMuteButton;
    QPushButton *screenCutButton;
    QPushButton *gifStartButton;
    QPushButton *gifEndButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestMainWindow)
    {
        if (TestMainWindow->objectName().isEmpty())
            TestMainWindow->setObjectName(QString::fromUtf8("TestMainWindow"));
        TestMainWindow->resize(453, 450);
        centralWidget = new QWidget(TestMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        playButton = new QPushButton(centralWidget);
        playButton->setObjectName(QString::fromUtf8("playButton"));
        playButton->setGeometry(QRect(90, 190, 61, 31));
        pauseButton = new QPushButton(centralWidget);
        pauseButton->setObjectName(QString::fromUtf8("pauseButton"));
        pauseButton->setGeometry(QRect(160, 190, 61, 31));
        nextButton = new QPushButton(centralWidget);
        nextButton->setObjectName(QString::fromUtf8("nextButton"));
        nextButton->setGeometry(QRect(300, 190, 61, 31));
        horizontalSlider = new QSlider(centralWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setGeometry(QRect(80, 170, 291, 20));
        horizontalSlider->setOrientation(Qt::Horizontal);
        terminateButton = new QPushButton(centralWidget);
        terminateButton->setObjectName(QString::fromUtf8("terminateButton"));
        terminateButton->setGeometry(QRect(230, 190, 61, 31));
        forwardButton = new QPushButton(centralWidget);
        forwardButton->setObjectName(QString::fromUtf8("forwardButton"));
        forwardButton->setGeometry(QRect(370, 190, 51, 31));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 0, 61, 181));
        tableWidget_2 = new QTableWidget(centralWidget);
        tableWidget_2->setObjectName(QString::fromUtf8("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(380, 0, 61, 181));
        volumeUpButton = new QPushButton(centralWidget);
        volumeUpButton->setObjectName(QString::fromUtf8("volumeUpButton"));
        volumeUpButton->setGeometry(QRect(90, 230, 61, 31));
        volumeDownButton = new QPushButton(centralWidget);
        volumeDownButton->setObjectName(QString::fromUtf8("volumeDownButton"));
        volumeDownButton->setGeometry(QRect(160, 230, 61, 31));
        jumpButton = new QPushButton(centralWidget);
        jumpButton->setObjectName(QString::fromUtf8("jumpButton"));
        jumpButton->setGeometry(QRect(230, 230, 61, 31));
        muteButton = new QPushButton(centralWidget);
        muteButton->setObjectName(QString::fromUtf8("muteButton"));
        muteButton->setGeometry(QRect(300, 230, 61, 31));
        nonMuteButton = new QPushButton(centralWidget);
        nonMuteButton->setObjectName(QString::fromUtf8("nonMuteButton"));
        nonMuteButton->setGeometry(QRect(370, 230, 51, 31));
        screenCutButton = new QPushButton(centralWidget);
        screenCutButton->setObjectName(QString::fromUtf8("screenCutButton"));
        screenCutButton->setGeometry(QRect(90, 270, 61, 31));
        gifStartButton = new QPushButton(centralWidget);
        gifStartButton->setObjectName(QString::fromUtf8("gifStartButton"));
        gifStartButton->setGeometry(QRect(160, 270, 61, 31));
        gifEndButton = new QPushButton(centralWidget);
        gifEndButton->setObjectName(QString::fromUtf8("gifEndButton"));
        gifEndButton->setGeometry(QRect(230, 270, 61, 31));
        TestMainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestMainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 453, 17));
        TestMainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestMainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TestMainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestMainWindow->setStatusBar(statusBar);

        retranslateUi(TestMainWindow);

        QMetaObject::connectSlotsByName(TestMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestMainWindow)
    {
        TestMainWindow->setWindowTitle(QApplication::translate("TestMainWindow", "TestMainWindow", nullptr));
        playButton->setText(QApplication::translate("TestMainWindow", "play", nullptr));
        pauseButton->setText(QApplication::translate("TestMainWindow", "pause", nullptr));
        nextButton->setText(QApplication::translate("TestMainWindow", "next", nullptr));
        terminateButton->setText(QApplication::translate("TestMainWindow", "terminate", nullptr));
        forwardButton->setText(QApplication::translate("TestMainWindow", "\345\211\215\350\277\233", nullptr));
        volumeUpButton->setText(QApplication::translate("TestMainWindow", "\351\237\263\351\207\217+", nullptr));
        volumeDownButton->setText(QApplication::translate("TestMainWindow", "\351\237\263\351\207\217-", nullptr));
        jumpButton->setText(QApplication::translate("TestMainWindow", "\350\267\263\344\270\255\351\227\264", nullptr));
        muteButton->setText(QApplication::translate("TestMainWindow", "\351\235\231\351\237\263", nullptr));
        nonMuteButton->setText(QApplication::translate("TestMainWindow", "\345\217\226\346\266\210\351\235\231\351\237\263", nullptr));
        screenCutButton->setText(QApplication::translate("TestMainWindow", "\346\210\252\345\233\276", nullptr));
        gifStartButton->setText(QApplication::translate("TestMainWindow", "GIF\345\274\200\345\247\213", nullptr));
        gifEndButton->setText(QApplication::translate("TestMainWindow", "GIF\347\273\223\346\235\237", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestMainWindow: public Ui_TestMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
