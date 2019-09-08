/****************************************************************************
** Meta object code from reading C++ file 'testmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../testmainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestMainWindow_t {
    QByteArrayData data[18];
    char stringdata0[365];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestMainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestMainWindow_t qt_meta_stringdata_TestMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 14), // "TestMainWindow"
QT_MOC_LITERAL(1, 15, 21), // "on_playButton_clicked"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 22), // "on_pauseButton_clicked"
QT_MOC_LITERAL(4, 61, 26), // "on_terminateButton_clicked"
QT_MOC_LITERAL(5, 88, 21), // "on_nextButton_clicked"
QT_MOC_LITERAL(6, 110, 24), // "on_forwardButton_clicked"
QT_MOC_LITERAL(7, 135, 25), // "on_volumeUpButton_clicked"
QT_MOC_LITERAL(8, 161, 27), // "on_volumeDownButton_clicked"
QT_MOC_LITERAL(9, 189, 21), // "on_jumpButton_clicked"
QT_MOC_LITERAL(10, 211, 21), // "on_muteButton_clicked"
QT_MOC_LITERAL(11, 233, 24), // "on_nonMuteButton_clicked"
QT_MOC_LITERAL(12, 258, 26), // "on_screenCutButton_clicked"
QT_MOC_LITERAL(13, 285, 25), // "on_gifStartButton_clicked"
QT_MOC_LITERAL(14, 311, 23), // "on_gifEndButton_clicked"
QT_MOC_LITERAL(15, 335, 10), // "closeEvent"
QT_MOC_LITERAL(16, 346, 12), // "QCloseEvent*"
QT_MOC_LITERAL(17, 359, 5) // "event"

    },
    "TestMainWindow\0on_playButton_clicked\0"
    "\0on_pauseButton_clicked\0"
    "on_terminateButton_clicked\0"
    "on_nextButton_clicked\0on_forwardButton_clicked\0"
    "on_volumeUpButton_clicked\0"
    "on_volumeDownButton_clicked\0"
    "on_jumpButton_clicked\0on_muteButton_clicked\0"
    "on_nonMuteButton_clicked\0"
    "on_screenCutButton_clicked\0"
    "on_gifStartButton_clicked\0"
    "on_gifEndButton_clicked\0closeEvent\0"
    "QCloseEvent*\0event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestMainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x08 /* Private */,
       3,    0,   85,    2, 0x08 /* Private */,
       4,    0,   86,    2, 0x08 /* Private */,
       5,    0,   87,    2, 0x08 /* Private */,
       6,    0,   88,    2, 0x08 /* Private */,
       7,    0,   89,    2, 0x08 /* Private */,
       8,    0,   90,    2, 0x08 /* Private */,
       9,    0,   91,    2, 0x08 /* Private */,
      10,    0,   92,    2, 0x08 /* Private */,
      11,    0,   93,    2, 0x08 /* Private */,
      12,    0,   94,    2, 0x08 /* Private */,
      13,    0,   95,    2, 0x08 /* Private */,
      14,    0,   96,    2, 0x08 /* Private */,
      15,    1,   97,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 16,   17,

       0        // eod
};

void TestMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TestMainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_playButton_clicked(); break;
        case 1: _t->on_pauseButton_clicked(); break;
        case 2: _t->on_terminateButton_clicked(); break;
        case 3: _t->on_nextButton_clicked(); break;
        case 4: _t->on_forwardButton_clicked(); break;
        case 5: _t->on_volumeUpButton_clicked(); break;
        case 6: _t->on_volumeDownButton_clicked(); break;
        case 7: _t->on_jumpButton_clicked(); break;
        case 8: _t->on_muteButton_clicked(); break;
        case 9: _t->on_nonMuteButton_clicked(); break;
        case 10: _t->on_screenCutButton_clicked(); break;
        case 11: _t->on_gifStartButton_clicked(); break;
        case 12: _t->on_gifEndButton_clicked(); break;
        case 13: _t->closeEvent((*reinterpret_cast< QCloseEvent*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TestMainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_TestMainWindow.data,
    qt_meta_data_TestMainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TestMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestMainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int TestMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
