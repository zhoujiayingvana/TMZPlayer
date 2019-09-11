/****************************************************************************
** Meta object code from reading C++ file 'settingwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../settingwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'settingwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SettingWindow_t {
    QByteArrayData data[68];
    char stringdata0[1487];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SettingWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SettingWindow_t qt_meta_stringdata_SettingWindow = {
    {
QT_MOC_LITERAL(0, 0, 13), // "SettingWindow"
QT_MOC_LITERAL(1, 14, 11), // "sigFontType"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 6), // "QFont*"
QT_MOC_LITERAL(4, 34, 4), // "font"
QT_MOC_LITERAL(5, 39, 19), // "sigChangeBackGround"
QT_MOC_LITERAL(6, 59, 20), // "sigPictureBackGround"
QT_MOC_LITERAL(7, 80, 17), // "sigActionShortcut"
QT_MOC_LITERAL(8, 98, 15), // "sigLastShortcut"
QT_MOC_LITERAL(9, 114, 15), // "sigNextShortcut"
QT_MOC_LITERAL(10, 130, 17), // "sigLouderShortcut"
QT_MOC_LITERAL(11, 148, 16), // "sigLowerShortcut"
QT_MOC_LITERAL(12, 165, 15), // "sigLikeShortcut"
QT_MOC_LITERAL(13, 181, 22), // "sigVolumeOnOffShortcut"
QT_MOC_LITERAL(14, 204, 24), // "sigSpeedUpScreenShortcut"
QT_MOC_LITERAL(15, 229, 26), // "sigSpeedDownScreenShortcut"
QT_MOC_LITERAL(16, 256, 18), // "sigLuminUpShortcut"
QT_MOC_LITERAL(17, 275, 20), // "sigLuminDownShortcut"
QT_MOC_LITERAL(18, 296, 19), // "sigOpenFileShortcut"
QT_MOC_LITERAL(19, 316, 20), // "sigCloseFileShortcut"
QT_MOC_LITERAL(20, 337, 21), // "sigScreenshotShortcut"
QT_MOC_LITERAL(21, 359, 14), // "sigSpeedChange"
QT_MOC_LITERAL(22, 374, 14), // "sigCloseChange"
QT_MOC_LITERAL(23, 389, 19), // "sigDefinitionChange"
QT_MOC_LITERAL(24, 409, 16), // "sigPlayDirChange"
QT_MOC_LITERAL(25, 426, 20), // "sigDownloadDirChange"
QT_MOC_LITERAL(26, 447, 16), // "sigShotDirChange"
QT_MOC_LITERAL(27, 464, 18), // "sigRecordDirChange"
QT_MOC_LITERAL(28, 483, 23), // "on_pushButton_1_clicked"
QT_MOC_LITERAL(29, 507, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(30, 531, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(31, 555, 22), // "on_colorButton_clicked"
QT_MOC_LITERAL(32, 578, 24), // "on_palyDirButton_clicked"
QT_MOC_LITERAL(33, 603, 28), // "on_downloadDirButton_clicked"
QT_MOC_LITERAL(34, 632, 16), // "on_back1_clicked"
QT_MOC_LITERAL(35, 649, 16), // "on_back2_clicked"
QT_MOC_LITERAL(36, 666, 16), // "on_back3_clicked"
QT_MOC_LITERAL(37, 683, 17), // "on_myBack_clicked"
QT_MOC_LITERAL(38, 701, 24), // "on_shotDirButton_clicked"
QT_MOC_LITERAL(39, 726, 26), // "on_recordDirButton_clicked"
QT_MOC_LITERAL(40, 753, 33), // "on_actionShortcutEdit_textCha..."
QT_MOC_LITERAL(41, 787, 4), // "arg1"
QT_MOC_LITERAL(42, 792, 31), // "on_lastShortcutEdit_textChanged"
QT_MOC_LITERAL(43, 824, 31), // "on_nextShortcutEdit_textChanged"
QT_MOC_LITERAL(44, 856, 33), // "on_louderShortcutEdit_textCha..."
QT_MOC_LITERAL(45, 890, 32), // "on_lowerShortcutEdit_textChanged"
QT_MOC_LITERAL(46, 923, 31), // "on_likeShortcutEdit_textChanged"
QT_MOC_LITERAL(47, 955, 30), // "on_volumeOnOffEdit_textChanged"
QT_MOC_LITERAL(48, 986, 32), // "on_speedUpScreenEdit_textChanged"
QT_MOC_LITERAL(49, 1019, 34), // "on_speedDownScreenEdit_textCh..."
QT_MOC_LITERAL(50, 1054, 26), // "on_luminUpEdit_textChanged"
QT_MOC_LITERAL(51, 1081, 28), // "on_luminDownEdit_textChanged"
QT_MOC_LITERAL(52, 1110, 27), // "on_openFileEdit_textChanged"
QT_MOC_LITERAL(53, 1138, 28), // "on_closeFileEdit_textChanged"
QT_MOC_LITERAL(54, 1167, 29), // "on_screenShotEdit_textChanged"
QT_MOC_LITERAL(55, 1197, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(56, 1220, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(57, 1245, 24), // "on_radioButton_3_clicked"
QT_MOC_LITERAL(58, 1270, 24), // "on_radioButton_4_clicked"
QT_MOC_LITERAL(59, 1295, 24), // "on_toCloseButton_clicked"
QT_MOC_LITERAL(60, 1320, 25), // "on_toBottomButton_clicked"
QT_MOC_LITERAL(61, 1346, 11), // "speedChange"
QT_MOC_LITERAL(62, 1358, 22), // "on_lv1Button_2_clicked"
QT_MOC_LITERAL(63, 1381, 22), // "on_lv2Button_2_clicked"
QT_MOC_LITERAL(64, 1404, 22), // "on_lv3Button_2_clicked"
QT_MOC_LITERAL(65, 1427, 19), // "lv1DefinitionChange"
QT_MOC_LITERAL(66, 1447, 19), // "lv2DefinitionChange"
QT_MOC_LITERAL(67, 1467, 19) // "lv3DefinitionChange"

    },
    "SettingWindow\0sigFontType\0\0QFont*\0"
    "font\0sigChangeBackGround\0sigPictureBackGround\0"
    "sigActionShortcut\0sigLastShortcut\0"
    "sigNextShortcut\0sigLouderShortcut\0"
    "sigLowerShortcut\0sigLikeShortcut\0"
    "sigVolumeOnOffShortcut\0sigSpeedUpScreenShortcut\0"
    "sigSpeedDownScreenShortcut\0"
    "sigLuminUpShortcut\0sigLuminDownShortcut\0"
    "sigOpenFileShortcut\0sigCloseFileShortcut\0"
    "sigScreenshotShortcut\0sigSpeedChange\0"
    "sigCloseChange\0sigDefinitionChange\0"
    "sigPlayDirChange\0sigDownloadDirChange\0"
    "sigShotDirChange\0sigRecordDirChange\0"
    "on_pushButton_1_clicked\0on_pushButton_2_clicked\0"
    "on_pushButton_3_clicked\0on_colorButton_clicked\0"
    "on_palyDirButton_clicked\0"
    "on_downloadDirButton_clicked\0"
    "on_back1_clicked\0on_back2_clicked\0"
    "on_back3_clicked\0on_myBack_clicked\0"
    "on_shotDirButton_clicked\0"
    "on_recordDirButton_clicked\0"
    "on_actionShortcutEdit_textChanged\0"
    "arg1\0on_lastShortcutEdit_textChanged\0"
    "on_nextShortcutEdit_textChanged\0"
    "on_louderShortcutEdit_textChanged\0"
    "on_lowerShortcutEdit_textChanged\0"
    "on_likeShortcutEdit_textChanged\0"
    "on_volumeOnOffEdit_textChanged\0"
    "on_speedUpScreenEdit_textChanged\0"
    "on_speedDownScreenEdit_textChanged\0"
    "on_luminUpEdit_textChanged\0"
    "on_luminDownEdit_textChanged\0"
    "on_openFileEdit_textChanged\0"
    "on_closeFileEdit_textChanged\0"
    "on_screenShotEdit_textChanged\0"
    "on_radioButton_clicked\0on_radioButton_2_clicked\0"
    "on_radioButton_3_clicked\0"
    "on_radioButton_4_clicked\0"
    "on_toCloseButton_clicked\0"
    "on_toBottomButton_clicked\0speedChange\0"
    "on_lv1Button_2_clicked\0on_lv2Button_2_clicked\0"
    "on_lv3Button_2_clicked\0lv1DefinitionChange\0"
    "lv2DefinitionChange\0lv3DefinitionChange"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SettingWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      63,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      24,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  329,    2, 0x06 /* Public */,
       5,    1,  332,    2, 0x06 /* Public */,
       6,    1,  335,    2, 0x06 /* Public */,
       7,    1,  338,    2, 0x06 /* Public */,
       8,    1,  341,    2, 0x06 /* Public */,
       9,    1,  344,    2, 0x06 /* Public */,
      10,    1,  347,    2, 0x06 /* Public */,
      11,    1,  350,    2, 0x06 /* Public */,
      12,    1,  353,    2, 0x06 /* Public */,
      13,    1,  356,    2, 0x06 /* Public */,
      14,    1,  359,    2, 0x06 /* Public */,
      15,    1,  362,    2, 0x06 /* Public */,
      16,    1,  365,    2, 0x06 /* Public */,
      17,    1,  368,    2, 0x06 /* Public */,
      18,    1,  371,    2, 0x06 /* Public */,
      19,    1,  374,    2, 0x06 /* Public */,
      20,    1,  377,    2, 0x06 /* Public */,
      21,    1,  380,    2, 0x06 /* Public */,
      22,    1,  383,    2, 0x06 /* Public */,
      23,    1,  386,    2, 0x06 /* Public */,
      24,    1,  389,    2, 0x06 /* Public */,
      25,    1,  392,    2, 0x06 /* Public */,
      26,    1,  395,    2, 0x06 /* Public */,
      27,    1,  398,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      28,    0,  401,    2, 0x08 /* Private */,
      29,    0,  402,    2, 0x08 /* Private */,
      30,    0,  403,    2, 0x08 /* Private */,
      31,    0,  404,    2, 0x08 /* Private */,
      32,    0,  405,    2, 0x08 /* Private */,
      33,    0,  406,    2, 0x08 /* Private */,
      34,    0,  407,    2, 0x08 /* Private */,
      35,    0,  408,    2, 0x08 /* Private */,
      36,    0,  409,    2, 0x08 /* Private */,
      37,    0,  410,    2, 0x08 /* Private */,
      38,    0,  411,    2, 0x08 /* Private */,
      39,    0,  412,    2, 0x08 /* Private */,
      40,    1,  413,    2, 0x08 /* Private */,
      42,    1,  416,    2, 0x08 /* Private */,
      43,    1,  419,    2, 0x08 /* Private */,
      44,    1,  422,    2, 0x08 /* Private */,
      45,    1,  425,    2, 0x08 /* Private */,
      46,    1,  428,    2, 0x08 /* Private */,
      47,    1,  431,    2, 0x08 /* Private */,
      48,    1,  434,    2, 0x08 /* Private */,
      49,    1,  437,    2, 0x08 /* Private */,
      50,    1,  440,    2, 0x08 /* Private */,
      51,    1,  443,    2, 0x08 /* Private */,
      52,    1,  446,    2, 0x08 /* Private */,
      53,    1,  449,    2, 0x08 /* Private */,
      54,    1,  452,    2, 0x08 /* Private */,
      55,    0,  455,    2, 0x08 /* Private */,
      56,    0,  456,    2, 0x08 /* Private */,
      57,    0,  457,    2, 0x08 /* Private */,
      58,    0,  458,    2, 0x08 /* Private */,
      59,    0,  459,    2, 0x08 /* Private */,
      60,    0,  460,    2, 0x08 /* Private */,
      61,    1,  461,    2, 0x08 /* Private */,
      62,    0,  464,    2, 0x08 /* Private */,
      63,    0,  465,    2, 0x08 /* Private */,
      64,    0,  466,    2, 0x08 /* Private */,
      65,    0,  467,    2, 0x08 /* Private */,
      66,    0,  468,    2, 0x08 /* Private */,
      67,    0,  469,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SettingWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<SettingWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sigFontType((*reinterpret_cast< QFont*(*)>(_a[1]))); break;
        case 1: _t->sigChangeBackGround((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->sigPictureBackGround((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sigActionShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sigLastShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sigNextShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->sigLouderShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->sigLowerShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 8: _t->sigLikeShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->sigVolumeOnOffShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->sigSpeedUpScreenShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 11: _t->sigSpeedDownScreenShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 12: _t->sigLuminUpShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->sigLuminDownShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->sigOpenFileShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->sigCloseFileShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->sigScreenshotShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->sigSpeedChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->sigCloseChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->sigDefinitionChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->sigPlayDirChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 21: _t->sigDownloadDirChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 22: _t->sigShotDirChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 23: _t->sigRecordDirChange((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 24: _t->on_pushButton_1_clicked(); break;
        case 25: _t->on_pushButton_2_clicked(); break;
        case 26: _t->on_pushButton_3_clicked(); break;
        case 27: _t->on_colorButton_clicked(); break;
        case 28: _t->on_palyDirButton_clicked(); break;
        case 29: _t->on_downloadDirButton_clicked(); break;
        case 30: _t->on_back1_clicked(); break;
        case 31: _t->on_back2_clicked(); break;
        case 32: _t->on_back3_clicked(); break;
        case 33: _t->on_myBack_clicked(); break;
        case 34: _t->on_shotDirButton_clicked(); break;
        case 35: _t->on_recordDirButton_clicked(); break;
        case 36: _t->on_actionShortcutEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 37: _t->on_lastShortcutEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 38: _t->on_nextShortcutEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 39: _t->on_louderShortcutEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 40: _t->on_lowerShortcutEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 41: _t->on_likeShortcutEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 42: _t->on_volumeOnOffEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 43: _t->on_speedUpScreenEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 44: _t->on_speedDownScreenEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 45: _t->on_luminUpEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 46: _t->on_luminDownEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 47: _t->on_openFileEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 48: _t->on_closeFileEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 49: _t->on_screenShotEdit_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 50: _t->on_radioButton_clicked(); break;
        case 51: _t->on_radioButton_2_clicked(); break;
        case 52: _t->on_radioButton_3_clicked(); break;
        case 53: _t->on_radioButton_4_clicked(); break;
        case 54: _t->on_toCloseButton_clicked(); break;
        case 55: _t->on_toBottomButton_clicked(); break;
        case 56: _t->speedChange((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 57: _t->on_lv1Button_2_clicked(); break;
        case 58: _t->on_lv2Button_2_clicked(); break;
        case 59: _t->on_lv3Button_2_clicked(); break;
        case 60: _t->lv1DefinitionChange(); break;
        case 61: _t->lv2DefinitionChange(); break;
        case 62: _t->lv3DefinitionChange(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (SettingWindow::*)(QFont * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigFontType)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigChangeBackGround)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigPictureBackGround)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigActionShortcut)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigLastShortcut)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigNextShortcut)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigLouderShortcut)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigLowerShortcut)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigLikeShortcut)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigVolumeOnOffShortcut)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigSpeedUpScreenShortcut)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigSpeedDownScreenShortcut)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigLuminUpShortcut)) {
                *result = 12;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigLuminDownShortcut)) {
                *result = 13;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigOpenFileShortcut)) {
                *result = 14;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigCloseFileShortcut)) {
                *result = 15;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigScreenshotShortcut)) {
                *result = 16;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigSpeedChange)) {
                *result = 17;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigCloseChange)) {
                *result = 18;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigDefinitionChange)) {
                *result = 19;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigPlayDirChange)) {
                *result = 20;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigDownloadDirChange)) {
                *result = 21;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigShotDirChange)) {
                *result = 22;
                return;
            }
        }
        {
            using _t = void (SettingWindow::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SettingWindow::sigRecordDirChange)) {
                *result = 23;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject SettingWindow::staticMetaObject = { {
    &QDialog::staticMetaObject,
    qt_meta_stringdata_SettingWindow.data,
    qt_meta_data_SettingWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SettingWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SettingWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SettingWindow.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SettingWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 63)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 63;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 63)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 63;
    }
    return _id;
}

// SIGNAL 0
void SettingWindow::sigFontType(QFont * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SettingWindow::sigChangeBackGround(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SettingWindow::sigPictureBackGround(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SettingWindow::sigActionShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void SettingWindow::sigLastShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void SettingWindow::sigNextShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void SettingWindow::sigLouderShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SettingWindow::sigLowerShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SettingWindow::sigLikeShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SettingWindow::sigVolumeOnOffShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void SettingWindow::sigSpeedUpScreenShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void SettingWindow::sigSpeedDownScreenShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void SettingWindow::sigLuminUpShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void SettingWindow::sigLuminDownShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void SettingWindow::sigOpenFileShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 14, _a);
}

// SIGNAL 15
void SettingWindow::sigCloseFileShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 15, _a);
}

// SIGNAL 16
void SettingWindow::sigScreenshotShortcut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 16, _a);
}

// SIGNAL 17
void SettingWindow::sigSpeedChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 17, _a);
}

// SIGNAL 18
void SettingWindow::sigCloseChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 18, _a);
}

// SIGNAL 19
void SettingWindow::sigDefinitionChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 19, _a);
}

// SIGNAL 20
void SettingWindow::sigPlayDirChange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 20, _a);
}

// SIGNAL 21
void SettingWindow::sigDownloadDirChange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 21, _a);
}

// SIGNAL 22
void SettingWindow::sigShotDirChange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 22, _a);
}

// SIGNAL 23
void SettingWindow::sigRecordDirChange(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 23, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
