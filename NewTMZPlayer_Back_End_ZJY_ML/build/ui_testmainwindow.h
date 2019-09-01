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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestMainWindow
{
public:
    QWidget *centralWidget;
    QToolButton *toolButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *nextButton;
    QSlider *horizontalSlider;
    QPushButton *terminateButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestMainWindow)
    {
        if (TestMainWindow->objectName().isEmpty())
            TestMainWindow->setObjectName(QString::fromUtf8("TestMainWindow"));
        TestMainWindow->resize(453, 288);
        centralWidget = new QWidget(TestMainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        toolButton = new QToolButton(centralWidget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setGeometry(QRect(30, 200, 32, 16));
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
        toolButton->setText(QApplication::translate("TestMainWindow", "...", nullptr));
        playButton->setText(QApplication::translate("TestMainWindow", "play", nullptr));
        pauseButton->setText(QApplication::translate("TestMainWindow", "pause", nullptr));
        nextButton->setText(QApplication::translate("TestMainWindow", "next", nullptr));
        terminateButton->setText(QApplication::translate("TestMainWindow", "terminate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TestMainWindow: public Ui_TestMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTMAINWINDOW_H
