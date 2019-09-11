/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QWidget>
#include "mylineedit.h"

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QDialogButtonBox *buttonBox;
    QStackedWidget *stackedWidget;
    QWidget *page_1;
    QScrollArea *scrollArea_3;
    QWidget *page1ScrollAreaWidgetContents;
    QWidget *controlCloseWidget;
    QRadioButton *toBottomButton;
    QRadioButton *toCloseButton;
    QLabel *label_5;
    QGroupBox *fontBox;
    QFontComboBox *fontComboBox;
    QLabel *fontType;
    QLabel *fontSize;
    QSpinBox *fontSpinBox;
    QLabel *fontColor;
    QPushButton *colorButton;
    QGroupBox *uiBox;
    QLabel *defaultBack;
    QLabel *chooseBack;
    QPushButton *back1;
    QPushButton *back2;
    QPushButton *back3;
    QPushButton *myBack;
    QWidget *page_2;
    QScrollArea *scrollArea_2;
    QWidget *page2ScrollAreaWidgetContents;
    QGroupBox *groupBox;
    QLabel *shotDirLabel;
    QPushButton *shotDirButton;
    QLabel *label_7;
    QRadioButton *picPngButton;
    QRadioButton *picWebpButton;
    QRadioButton *picJpgButton;
    QLabel *label_31;
    QGroupBox *groupBox_2;
    QLabel *label_8;
    QLabel *recordDirLabel;
    QPushButton *recordDirButton;
    QLabel *label_9;
    QLabel *label_10;
    QSlider *recordSizeSlider;
    QSpinBox *recordSizeSpinBox;
    QLabel *label_12;
    QCheckBox *checkBox;
    QLabel *label_13;
    QGroupBox *groupBox_3;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    MyLineEdit *actionShortcutEdit;
    MyLineEdit *lastShortcutEdit;
    QLabel *label_17;
    QLabel *label_18;
    MyLineEdit *nextShortcutEdit;
    MyLineEdit *louderShortcutEdit;
    MyLineEdit *lowerShortcutEdit;
    MyLineEdit *likeShortcutEdit;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_11;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    MyLineEdit *volumeOnOffEdit;
    MyLineEdit *speedUpScreenEdit;
    MyLineEdit *speedDownScreenEdit;
    MyLineEdit *luminUpEdit;
    MyLineEdit *luminDownEdit;
    MyLineEdit *openFileEdit;
    MyLineEdit *closeFileEdit;
    MyLineEdit *screenShotEdit;
    QWidget *widget_2;
    QLabel *label_6;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QWidget *page_3;
    QScrollArea *scrollArea;
    QWidget *page3ScrollAreaWidgetContents;
    QGroupBox *playBox;
    QLabel *label;
    QWidget *pixelWidget_2;
    QHBoxLayout *horizontalLayout;
    QRadioButton *lv1Button_2;
    QRadioButton *lv2Button_2;
    QRadioButton *lv3Button_2;
    QLabel *label_2;
    QLabel *playDirLabel;
    QPushButton *palyDirButton;
    QLabel *label_22;
    QLabel *label_23;
    QSpinBox *quickMoveSpinBox;
    QSlider *quickMoveSlider;
    QGroupBox *downloadBox;
    QLabel *label_3;
    QWidget *pixelWidget;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *lv1Button;
    QRadioButton *lv2Button;
    QRadioButton *lv3Button;
    QLabel *label_4;
    QLabel *downloadDirLabel;
    QPushButton *downloadDirButton;
    QWidget *widget;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->resize(630, 640);
        SettingWindow->setStyleSheet(QString::fromUtf8(""));
        buttonBox = new QDialogButtonBox(SettingWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 580, 389, 41));
        buttonBox->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\342\200\234Segoe UI\342\200\235"));
        buttonBox->setFont(font);
        buttonBox->setCursor(QCursor(Qt::ArrowCursor));
        buttonBox->setMouseTracking(false);
        buttonBox->setAutoFillBackground(false);
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Yes);
        buttonBox->setCenterButtons(false);
        stackedWidget = new QStackedWidget(SettingWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(150, 10, 481, 571));
        page_1 = new QWidget();
        page_1->setObjectName(QString::fromUtf8("page_1"));
        scrollArea_3 = new QScrollArea(page_1);
        scrollArea_3->setObjectName(QString::fromUtf8("scrollArea_3"));
        scrollArea_3->setGeometry(QRect(-1, 0, 481, 571));
        scrollArea_3->setWidgetResizable(true);
        page1ScrollAreaWidgetContents = new QWidget();
        page1ScrollAreaWidgetContents->setObjectName(QString::fromUtf8("page1ScrollAreaWidgetContents"));
        page1ScrollAreaWidgetContents->setGeometry(QRect(0, 0, 479, 569));
        controlCloseWidget = new QWidget(page1ScrollAreaWidgetContents);
        controlCloseWidget->setObjectName(QString::fromUtf8("controlCloseWidget"));
        controlCloseWidget->setGeometry(QRect(10, 30, 271, 71));
        toBottomButton = new QRadioButton(controlCloseWidget);
        toBottomButton->setObjectName(QString::fromUtf8("toBottomButton"));
        toBottomButton->setGeometry(QRect(10, 0, 211, 31));
        toCloseButton = new QRadioButton(controlCloseWidget);
        toCloseButton->setObjectName(QString::fromUtf8("toCloseButton"));
        toCloseButton->setGeometry(QRect(10, 30, 171, 31));
        toCloseButton->setAutoFillBackground(false);
        toCloseButton->setChecked(true);
        label_5 = new QLabel(page1ScrollAreaWidgetContents);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 10, 121, 21));
        fontBox = new QGroupBox(page1ScrollAreaWidgetContents);
        fontBox->setObjectName(QString::fromUtf8("fontBox"));
        fontBox->setGeometry(QRect(10, 120, 461, 161));
        fontComboBox = new QFontComboBox(fontBox);
        fontComboBox->setObjectName(QString::fromUtf8("fontComboBox"));
        fontComboBox->setGeometry(QRect(110, 30, 101, 31));
        fontType = new QLabel(fontBox);
        fontType->setObjectName(QString::fromUtf8("fontType"));
        fontType->setGeometry(QRect(10, 30, 91, 31));
        fontSize = new QLabel(fontBox);
        fontSize->setObjectName(QString::fromUtf8("fontSize"));
        fontSize->setGeometry(QRect(10, 77, 101, 21));
        fontSpinBox = new QSpinBox(fontBox);
        fontSpinBox->setObjectName(QString::fromUtf8("fontSpinBox"));
        fontSpinBox->setGeometry(QRect(110, 70, 101, 31));
        fontSpinBox->setMinimum(9);
        fontSpinBox->setMaximum(26);
        fontColor = new QLabel(fontBox);
        fontColor->setObjectName(QString::fromUtf8("fontColor"));
        fontColor->setGeometry(QRect(10, 120, 101, 21));
        colorButton = new QPushButton(fontBox);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));
        colorButton->setGeometry(QRect(110, 120, 31, 31));
        uiBox = new QGroupBox(page1ScrollAreaWidgetContents);
        uiBox->setObjectName(QString::fromUtf8("uiBox"));
        uiBox->setGeometry(QRect(10, 310, 461, 121));
        defaultBack = new QLabel(uiBox);
        defaultBack->setObjectName(QString::fromUtf8("defaultBack"));
        defaultBack->setGeometry(QRect(10, 30, 101, 31));
        chooseBack = new QLabel(uiBox);
        chooseBack->setObjectName(QString::fromUtf8("chooseBack"));
        chooseBack->setGeometry(QRect(10, 77, 121, 21));
        back1 = new QPushButton(uiBox);
        back1->setObjectName(QString::fromUtf8("back1"));
        back1->setGeometry(QRect(110, 30, 31, 31));
        back2 = new QPushButton(uiBox);
        back2->setObjectName(QString::fromUtf8("back2"));
        back2->setGeometry(QRect(160, 30, 31, 31));
        back3 = new QPushButton(uiBox);
        back3->setObjectName(QString::fromUtf8("back3"));
        back3->setGeometry(QRect(210, 30, 31, 31));
        myBack = new QPushButton(uiBox);
        myBack->setObjectName(QString::fromUtf8("myBack"));
        myBack->setGeometry(QRect(130, 70, 31, 31));
        scrollArea_3->setWidget(page1ScrollAreaWidgetContents);
        stackedWidget->addWidget(page_1);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        scrollArea_2 = new QScrollArea(page_2);
        scrollArea_2->setObjectName(QString::fromUtf8("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(-1, -1, 491, 571));
        scrollArea_2->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea_2->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        scrollArea_2->setWidgetResizable(true);
        page2ScrollAreaWidgetContents = new QWidget();
        page2ScrollAreaWidgetContents->setObjectName(QString::fromUtf8("page2ScrollAreaWidgetContents"));
        page2ScrollAreaWidgetContents->setGeometry(QRect(0, 0, 489, 569));
        page2ScrollAreaWidgetContents->setMinimumSize(QSize(489, 569));
        groupBox = new QGroupBox(page2ScrollAreaWidgetContents);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 70, 461, 151));
        shotDirLabel = new QLabel(groupBox);
        shotDirLabel->setObjectName(QString::fromUtf8("shotDirLabel"));
        shotDirLabel->setGeometry(QRect(130, 67, 331, 31));
        shotDirButton = new QPushButton(groupBox);
        shotDirButton->setObjectName(QString::fromUtf8("shotDirButton"));
        shotDirButton->setGeometry(QRect(130, 27, 101, 31));
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(20, 27, 111, 31));
        picPngButton = new QRadioButton(groupBox);
        picPngButton->setObjectName(QString::fromUtf8("picPngButton"));
        picPngButton->setGeometry(QRect(205, 110, 91, 21));
        picWebpButton = new QRadioButton(groupBox);
        picWebpButton->setObjectName(QString::fromUtf8("picWebpButton"));
        picWebpButton->setGeometry(QRect(290, 110, 81, 21));
        picJpgButton = new QRadioButton(groupBox);
        picJpgButton->setObjectName(QString::fromUtf8("picJpgButton"));
        picJpgButton->setGeometry(QRect(120, 110, 81, 21));
        picJpgButton->setChecked(true);
        label_31 = new QLabel(groupBox);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(20, 110, 71, 21));
        groupBox_2 = new QGroupBox(page2ScrollAreaWidgetContents);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(10, 250, 461, 241));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(20, 26, 111, 31));
        recordDirLabel = new QLabel(groupBox_2);
        recordDirLabel->setObjectName(QString::fromUtf8("recordDirLabel"));
        recordDirLabel->setGeometry(QRect(130, 66, 331, 31));
        recordDirButton = new QPushButton(groupBox_2);
        recordDirButton->setObjectName(QString::fromUtf8("recordDirButton"));
        recordDirButton->setGeometry(QRect(130, 26, 101, 31));
        label_9 = new QLabel(groupBox_2);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(20, 100, 111, 21));
        label_10 = new QLabel(groupBox_2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(140, 100, 191, 21));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\342\200\234Segoe UI\342\200\235"));
        font1.setItalic(true);
        label_10->setFont(font1);
        recordSizeSlider = new QSlider(groupBox_2);
        recordSizeSlider->setObjectName(QString::fromUtf8("recordSizeSlider"));
        recordSizeSlider->setGeometry(QRect(130, 130, 181, 16));
        recordSizeSlider->setMaximum(300);
        recordSizeSlider->setSingleStep(1);
        recordSizeSlider->setValue(60);
        recordSizeSlider->setSliderPosition(60);
        recordSizeSlider->setOrientation(Qt::Horizontal);
        recordSizeSpinBox = new QSpinBox(groupBox_2);
        recordSizeSpinBox->setObjectName(QString::fromUtf8("recordSizeSpinBox"));
        recordSizeSpinBox->setGeometry(QRect(30, 126, 71, 22));
        recordSizeSpinBox->setMaximum(300);
        recordSizeSpinBox->setSingleStep(1);
        recordSizeSpinBox->setValue(60);
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(20, 170, 151, 21));
        checkBox = new QCheckBox(groupBox_2);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setGeometry(QRect(30, 198, 81, 21));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(140, 170, 301, 21));
        label_13->setFont(font1);
        groupBox_3 = new QGroupBox(page2ScrollAreaWidgetContents);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 510, 461, 661));
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(30, 30, 81, 21));
        label_14->setFont(font);
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(140, 30, 91, 21));
        label_15->setFont(font);
        label_16 = new QLabel(groupBox_3);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(30, 60, 111, 21));
        actionShortcutEdit = new MyLineEdit(groupBox_3);
        actionShortcutEdit->setObjectName(QString::fromUtf8("actionShortcutEdit"));
        actionShortcutEdit->setGeometry(QRect(120, 60, 113, 20));
        lastShortcutEdit = new MyLineEdit(groupBox_3);
        lastShortcutEdit->setObjectName(QString::fromUtf8("lastShortcutEdit"));
        lastShortcutEdit->setGeometry(QRect(120, 100, 113, 20));
        label_17 = new QLabel(groupBox_3);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(30, 100, 91, 21));
        label_18 = new QLabel(groupBox_3);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(30, 140, 91, 21));
        nextShortcutEdit = new MyLineEdit(groupBox_3);
        nextShortcutEdit->setObjectName(QString::fromUtf8("nextShortcutEdit"));
        nextShortcutEdit->setGeometry(QRect(120, 140, 113, 20));
        louderShortcutEdit = new MyLineEdit(groupBox_3);
        louderShortcutEdit->setObjectName(QString::fromUtf8("louderShortcutEdit"));
        louderShortcutEdit->setGeometry(QRect(120, 180, 113, 20));
        lowerShortcutEdit = new MyLineEdit(groupBox_3);
        lowerShortcutEdit->setObjectName(QString::fromUtf8("lowerShortcutEdit"));
        lowerShortcutEdit->setGeometry(QRect(120, 220, 113, 20));
        likeShortcutEdit = new MyLineEdit(groupBox_3);
        likeShortcutEdit->setObjectName(QString::fromUtf8("likeShortcutEdit"));
        likeShortcutEdit->setGeometry(QRect(120, 580, 113, 20));
        label_19 = new QLabel(groupBox_3);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(30, 180, 91, 21));
        label_20 = new QLabel(groupBox_3);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(30, 220, 91, 21));
        label_21 = new QLabel(groupBox_3);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(30, 580, 91, 21));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(30, 260, 91, 21));
        label_24 = new QLabel(groupBox_3);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(30, 300, 51, 21));
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(30, 340, 61, 20));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(30, 540, 61, 21));
        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(30, 460, 51, 21));
        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(30, 500, 81, 21));
        label_29 = new QLabel(groupBox_3);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(30, 380, 51, 16));
        label_30 = new QLabel(groupBox_3);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(30, 420, 51, 21));
        volumeOnOffEdit = new MyLineEdit(groupBox_3);
        volumeOnOffEdit->setObjectName(QString::fromUtf8("volumeOnOffEdit"));
        volumeOnOffEdit->setGeometry(QRect(120, 260, 113, 20));
        speedUpScreenEdit = new MyLineEdit(groupBox_3);
        speedUpScreenEdit->setObjectName(QString::fromUtf8("speedUpScreenEdit"));
        speedUpScreenEdit->setGeometry(QRect(120, 300, 113, 20));
        speedDownScreenEdit = new MyLineEdit(groupBox_3);
        speedDownScreenEdit->setObjectName(QString::fromUtf8("speedDownScreenEdit"));
        speedDownScreenEdit->setGeometry(QRect(120, 340, 113, 20));
        luminUpEdit = new MyLineEdit(groupBox_3);
        luminUpEdit->setObjectName(QString::fromUtf8("luminUpEdit"));
        luminUpEdit->setGeometry(QRect(120, 380, 113, 20));
        luminDownEdit = new MyLineEdit(groupBox_3);
        luminDownEdit->setObjectName(QString::fromUtf8("luminDownEdit"));
        luminDownEdit->setGeometry(QRect(120, 420, 113, 20));
        openFileEdit = new MyLineEdit(groupBox_3);
        openFileEdit->setObjectName(QString::fromUtf8("openFileEdit"));
        openFileEdit->setGeometry(QRect(120, 460, 113, 20));
        closeFileEdit = new MyLineEdit(groupBox_3);
        closeFileEdit->setObjectName(QString::fromUtf8("closeFileEdit"));
        closeFileEdit->setGeometry(QRect(120, 500, 113, 20));
        screenShotEdit = new MyLineEdit(groupBox_3);
        screenShotEdit->setObjectName(QString::fromUtf8("screenShotEdit"));
        screenShotEdit->setGeometry(QRect(120, 540, 113, 20));
        widget_2 = new QWidget(page2ScrollAreaWidgetContents);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        widget_2->setGeometry(QRect(10, 10, 461, 51));
        label_6 = new QLabel(widget_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(0, 0, 81, 21));
        radioButton = new QRadioButton(widget_2);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setGeometry(QRect(20, 20, 71, 21));
        radioButton_2 = new QRadioButton(widget_2);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setGeometry(QRect(120, 20, 71, 21));
        radioButton_2->setChecked(true);
        radioButton_3 = new QRadioButton(widget_2);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setGeometry(QRect(230, 20, 71, 21));
        radioButton_4 = new QRadioButton(widget_2);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setGeometry(QRect(330, 20, 81, 21));
        scrollArea_2->setWidget(page2ScrollAreaWidgetContents);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        scrollArea = new QScrollArea(page_3);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(0, 0, 481, 571));
        scrollArea->setFrameShape(QFrame::NoFrame);
        scrollArea->setLineWidth(0);
        scrollArea->setWidgetResizable(true);
        page3ScrollAreaWidgetContents = new QWidget();
        page3ScrollAreaWidgetContents->setObjectName(QString::fromUtf8("page3ScrollAreaWidgetContents"));
        page3ScrollAreaWidgetContents->setGeometry(QRect(0, 0, 481, 571));
        playBox = new QGroupBox(page3ScrollAreaWidgetContents);
        playBox->setObjectName(QString::fromUtf8("playBox"));
        playBox->setGeometry(QRect(10, 10, 461, 241));
        label = new QLabel(playBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 100, 81, 31));
        pixelWidget_2 = new QWidget(playBox);
        pixelWidget_2->setObjectName(QString::fromUtf8("pixelWidget_2"));
        pixelWidget_2->setGeometry(QRect(90, 85, 261, 61));
        horizontalLayout = new QHBoxLayout(pixelWidget_2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lv1Button_2 = new QRadioButton(pixelWidget_2);
        lv1Button_2->setObjectName(QString::fromUtf8("lv1Button_2"));
        lv1Button_2->setChecked(true);

        horizontalLayout->addWidget(lv1Button_2);

        lv2Button_2 = new QRadioButton(pixelWidget_2);
        lv2Button_2->setObjectName(QString::fromUtf8("lv2Button_2"));

        horizontalLayout->addWidget(lv2Button_2);

        lv3Button_2 = new QRadioButton(pixelWidget_2);
        lv3Button_2->setObjectName(QString::fromUtf8("lv3Button_2"));

        horizontalLayout->addWidget(lv3Button_2);

        label_2 = new QLabel(playBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 155, 111, 31));
        playDirLabel = new QLabel(playBox);
        playDirLabel->setObjectName(QString::fromUtf8("playDirLabel"));
        playDirLabel->setGeometry(QRect(130, 195, 331, 31));
        palyDirButton = new QPushButton(playBox);
        palyDirButton->setObjectName(QString::fromUtf8("palyDirButton"));
        palyDirButton->setGeometry(QRect(130, 155, 101, 31));
        label_22 = new QLabel(playBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(20, 30, 101, 31));
        label_23 = new QLabel(playBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(130, 30, 141, 31));
        QFont font2;
        font2.setItalic(true);
        label_23->setFont(font2);
        quickMoveSpinBox = new QSpinBox(playBox);
        quickMoveSpinBox->setObjectName(QString::fromUtf8("quickMoveSpinBox"));
        quickMoveSpinBox->setGeometry(QRect(30, 60, 42, 22));
        quickMoveSlider = new QSlider(playBox);
        quickMoveSlider->setObjectName(QString::fromUtf8("quickMoveSlider"));
        quickMoveSlider->setGeometry(QRect(110, 62, 160, 16));
        quickMoveSlider->setOrientation(Qt::Horizontal);
        downloadBox = new QGroupBox(page3ScrollAreaWidgetContents);
        downloadBox->setObjectName(QString::fromUtf8("downloadBox"));
        downloadBox->setGeometry(QRect(10, 280, 461, 181));
        label_3 = new QLabel(downloadBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(20, 40, 81, 21));
        pixelWidget = new QWidget(downloadBox);
        pixelWidget->setObjectName(QString::fromUtf8("pixelWidget"));
        pixelWidget->setGeometry(QRect(90, 20, 261, 61));
        horizontalLayout_2 = new QHBoxLayout(pixelWidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lv1Button = new QRadioButton(pixelWidget);
        lv1Button->setObjectName(QString::fromUtf8("lv1Button"));
        lv1Button->setChecked(true);

        horizontalLayout_2->addWidget(lv1Button);

        lv2Button = new QRadioButton(pixelWidget);
        lv2Button->setObjectName(QString::fromUtf8("lv2Button"));

        horizontalLayout_2->addWidget(lv2Button);

        lv3Button = new QRadioButton(pixelWidget);
        lv3Button->setObjectName(QString::fromUtf8("lv3Button"));

        horizontalLayout_2->addWidget(lv3Button);

        label_4 = new QLabel(downloadBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(20, 96, 91, 21));
        downloadDirLabel = new QLabel(downloadBox);
        downloadDirLabel->setObjectName(QString::fromUtf8("downloadDirLabel"));
        downloadDirLabel->setGeometry(QRect(110, 130, 341, 31));
        downloadDirButton = new QPushButton(downloadBox);
        downloadDirButton->setObjectName(QString::fromUtf8("downloadDirButton"));
        downloadDirButton->setGeometry(QRect(110, 90, 101, 31));
        scrollArea->setWidget(page3ScrollAreaWidgetContents);
        stackedWidget->addWidget(page_3);
        widget = new QWidget(SettingWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 10, 141, 131));
        widget->setAutoFillBackground(false);
        pushButton_1 = new QPushButton(widget);
        pushButton_1->setObjectName(QString::fromUtf8("pushButton_1"));
        pushButton_1->setGeometry(QRect(10, 10, 121, 31));
        pushButton_1->setFont(font);
        pushButton_1->setStyleSheet(QString::fromUtf8(""));
        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(10, 50, 121, 31));
        pushButton_2->setFont(font);
        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 90, 121, 31));
        pushButton_3->setFont(font);

        retranslateUi(SettingWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingWindow, SLOT(reject()));

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingWindow)
    {
        SettingWindow->setWindowTitle(QApplication::translate("SettingWindow", "Dialog", nullptr));
        toBottomButton->setText(QApplication::translate("SettingWindow", "\346\234\200\345\260\217\345\214\226\345\210\260\347\263\273\347\273\237\346\211\230\347\233\230", nullptr));
        toCloseButton->setText(QApplication::translate("SettingWindow", "\345\205\263\351\227\255TMZPlayer", nullptr));
        label_5->setText(QApplication::translate("SettingWindow", "\345\205\263\351\227\255\344\270\273\347\225\214\351\235\242\357\274\232", nullptr));
        fontBox->setTitle(QApplication::translate("SettingWindow", "\345\255\227\344\275\223", nullptr));
        fontType->setText(QApplication::translate("SettingWindow", "\345\255\227\344\275\223\351\200\211\346\213\251\357\274\232", nullptr));
        fontSize->setText(QApplication::translate("SettingWindow", "\345\255\227\344\275\223\345\244\247\345\260\217\357\274\232", nullptr));
        fontColor->setText(QApplication::translate("SettingWindow", "\345\255\227\344\275\223\351\242\234\350\211\262\357\274\232", nullptr));
        colorButton->setText(QString());
        uiBox->setTitle(QApplication::translate("SettingWindow", "UI\350\207\252\345\256\232\344\271\211", nullptr));
        defaultBack->setText(QApplication::translate("SettingWindow", "\347\272\257\350\211\262\350\203\214\346\231\257\357\274\232", nullptr));
        chooseBack->setText(QApplication::translate("SettingWindow", "\350\207\252\345\256\232\344\271\211\350\203\214\346\231\257\357\274\232", nullptr));
        back1->setText(QString());
        back2->setText(QString());
        back3->setText(QString());
        myBack->setText(QString());
        groupBox->setTitle(QApplication::translate("SettingWindow", "\346\210\252\345\261\217\350\256\276\347\275\256", nullptr));
        shotDirLabel->setText(QApplication::translate("SettingWindow", "C:/CloudMusic/image", nullptr));
        shotDirButton->setText(QApplication::translate("SettingWindow", "\346\233\264\346\224\271\347\233\256\345\275\225", nullptr));
        label_7->setText(QApplication::translate("SettingWindow", "\344\277\235\345\255\230\347\233\256\345\275\225\357\274\232", nullptr));
        picPngButton->setText(QApplication::translate("SettingWindow", ".png", nullptr));
        picWebpButton->setText(QApplication::translate("SettingWindow", ".webp", nullptr));
        picJpgButton->setText(QApplication::translate("SettingWindow", ".jpg", nullptr));
        label_31->setText(QApplication::translate("SettingWindow", "\344\277\235\345\255\230\346\240\274\345\274\217:", nullptr));
        groupBox_2->setTitle(QApplication::translate("SettingWindow", "\345\275\225\345\261\217\350\256\276\347\275\256", nullptr));
        label_8->setText(QApplication::translate("SettingWindow", "\344\277\235\345\255\230\347\233\256\345\275\225\357\274\232", nullptr));
        recordDirLabel->setText(QApplication::translate("SettingWindow", "C:/CloudMusic/record", nullptr));
        recordDirButton->setText(QApplication::translate("SettingWindow", "\346\233\264\346\224\271\347\233\256\345\275\225", nullptr));
        label_9->setText(QApplication::translate("SettingWindow", "\345\275\225\345\203\217\346\226\207\344\273\266\346\227\266\351\225\277\357\274\232", nullptr));
        label_10->setText(QApplication::translate("SettingWindow", "\345\215\225\344\270\252\345\275\225\345\203\217\346\234\200\345\244\247\346\227\266\351\225\277", nullptr));
        label_12->setText(QApplication::translate("SettingWindow", "\350\207\252\345\212\250\345\210\206\345\211\262\345\233\276\345\203\217\357\274\232", nullptr));
        checkBox->setText(QApplication::translate("SettingWindow", "\346\230\257", nullptr));
        label_13->setText(QApplication::translate("SettingWindow", "\345\275\223\345\275\225\345\203\217\350\266\205\350\277\207\346\234\200\345\244\247\346\227\266\351\225\277\346\227\266\350\207\252\345\212\250\345\210\206\345\211\262", nullptr));
        groupBox_3->setTitle(QApplication::translate("SettingWindow", "\345\277\253\346\215\267\351\224\256\350\256\276\347\275\256", nullptr));
        label_14->setText(QApplication::translate("SettingWindow", "\345\212\237\350\203\275\350\257\264\346\230\216", nullptr));
        label_15->setText(QApplication::translate("SettingWindow", "\345\277\253\346\215\267\351\224\256", nullptr));
        label_16->setText(QApplication::translate("SettingWindow", "\346\222\255\346\224\276/\346\232\202\345\201\234", nullptr));
        actionShortcutEdit->setText(QString());
        label_17->setText(QApplication::translate("SettingWindow", "\344\270\212\344\270\200\344\270\252", nullptr));
        label_18->setText(QApplication::translate("SettingWindow", "\344\270\213\344\270\200\344\270\252", nullptr));
        label_19->setText(QApplication::translate("SettingWindow", "\351\237\263\351\207\217\345\212\240", nullptr));
        label_20->setText(QApplication::translate("SettingWindow", "\351\237\263\351\207\217\345\207\217", nullptr));
        label_21->setText(QApplication::translate("SettingWindow", "\346\224\266\350\227\217", nullptr));
        label_11->setText(QApplication::translate("SettingWindow", "\351\235\231\351\237\263/\345\244\215\351\237\263", nullptr));
        label_24->setText(QApplication::translate("SettingWindow", "\345\277\253\350\277\233", nullptr));
        label_25->setText(QApplication::translate("SettingWindow", "\345\277\253\351\200\200", nullptr));
        label_26->setText(QApplication::translate("SettingWindow", "\346\210\252\345\233\276", nullptr));
        label_27->setText(QApplication::translate("SettingWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        label_28->setText(QApplication::translate("SettingWindow", "\345\201\234\346\255\242/\345\205\263\351\227\255", nullptr));
        label_29->setText(QApplication::translate("SettingWindow", "\344\272\256\345\272\246\345\242\236", nullptr));
        label_30->setText(QApplication::translate("SettingWindow", "\344\272\256\345\272\246\345\207\217", nullptr));
        label_6->setText(QApplication::translate("SettingWindow", "\345\200\215\351\200\237\346\222\255\346\224\276", nullptr));
        radioButton->setText(QApplication::translate("SettingWindow", "0.5", nullptr));
        radioButton_2->setText(QApplication::translate("SettingWindow", "1.0", nullptr));
        radioButton_3->setText(QApplication::translate("SettingWindow", "1.5", nullptr));
        radioButton_4->setText(QApplication::translate("SettingWindow", "2.0", nullptr));
        playBox->setTitle(QApplication::translate("SettingWindow", "\346\222\255\346\224\276\350\256\276\347\275\256", nullptr));
        label->setText(QApplication::translate("SettingWindow", "\347\224\273\350\264\250\351\200\211\346\213\251\357\274\232", nullptr));
        lv1Button_2->setText(QApplication::translate("SettingWindow", "\346\231\256\351\200\232", nullptr));
        lv2Button_2->setText(QApplication::translate("SettingWindow", "\346\270\205\346\231\260", nullptr));
        lv3Button_2->setText(QApplication::translate("SettingWindow", "\351\253\230\346\270\205", nullptr));
        label_2->setText(QApplication::translate("SettingWindow", "\345\252\222\344\275\223\345\272\223\347\233\256\345\275\225\357\274\232", nullptr));
        playDirLabel->setText(QApplication::translate("SettingWindow", "C:/CloudMusic", nullptr));
        palyDirButton->setText(QApplication::translate("SettingWindow", "\346\233\264\346\224\271\347\233\256\345\275\225", nullptr));
        label_22->setText(QApplication::translate("SettingWindow", "\345\277\253\350\277\233/\345\277\253\351\200\200\346\227\266\351\225\277:", nullptr));
        label_23->setText(QApplication::translate("SettingWindow", "\345\215\225\346\254\241\345\277\253\350\277\233\345\277\253\351\200\200\346\227\266\351\225\277\351\231\220\345\210\266\343\200\202", nullptr));
        downloadBox->setTitle(QApplication::translate("SettingWindow", "\344\270\213\350\275\275\350\256\276\347\275\256", nullptr));
        label_3->setText(QApplication::translate("SettingWindow", "\347\224\273\350\264\250\351\200\211\346\213\251\357\274\232", nullptr));
        lv1Button->setText(QApplication::translate("SettingWindow", "\346\231\256\351\200\232", nullptr));
        lv2Button->setText(QApplication::translate("SettingWindow", "\346\270\205\346\231\260", nullptr));
        lv3Button->setText(QApplication::translate("SettingWindow", "\351\253\230\346\270\205", nullptr));
        label_4->setText(QApplication::translate("SettingWindow", "\344\270\213\350\275\275\347\233\256\345\275\225\357\274\232", nullptr));
        downloadDirLabel->setText(QApplication::translate("SettingWindow", "C:/CloudMusic", nullptr));
        downloadDirButton->setText(QApplication::translate("SettingWindow", "\346\233\264\346\224\271\347\233\256\345\275\225", nullptr));
        pushButton_1->setText(QApplication::translate("SettingWindow", "\345\270\270\350\247\204", nullptr));
        pushButton_2->setText(QApplication::translate("SettingWindow", "\345\267\245\345\205\267", nullptr));
        pushButton_3->setText(QApplication::translate("SettingWindow", "\346\222\255\346\224\276\345\222\214\344\270\213\350\275\275", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
