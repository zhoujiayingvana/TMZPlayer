/****************************************************************************
** Meta object code from reading C++ file 'controller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../util/controller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'controller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Controller_t {
    QByteArrayData data[24];
    char stringdata0[297];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Controller_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Controller_t qt_meta_stringdata_Controller = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Controller"
QT_MOC_LITERAL(1, 11, 15), // "needGetDuration"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 15), // "needGetPosition"
QT_MOC_LITERAL(4, 44, 13), // "needGetStatus"
QT_MOC_LITERAL(5, 58, 8), // "needPlay"
QT_MOC_LITERAL(6, 67, 14), // "QMediaContent*"
QT_MOC_LITERAL(7, 82, 7), // "content"
QT_MOC_LITERAL(8, 90, 15), // "needRestorePlay"
QT_MOC_LITERAL(9, 106, 14), // "needPauseVideo"
QT_MOC_LITERAL(10, 121, 18), // "needTerminateVideo"
QT_MOC_LITERAL(11, 140, 16), // "needSeekPosition"
QT_MOC_LITERAL(12, 157, 13), // "needSetVolume"
QT_MOC_LITERAL(13, 171, 3), // "vol"
QT_MOC_LITERAL(14, 175, 12), // "needSetMuted"
QT_MOC_LITERAL(15, 188, 1), // "m"
QT_MOC_LITERAL(16, 190, 19), // "needSetPlaybackRate"
QT_MOC_LITERAL(17, 210, 4), // "rate"
QT_MOC_LITERAL(18, 215, 8), // "needJump"
QT_MOC_LITERAL(19, 224, 6), // "second"
QT_MOC_LITERAL(20, 231, 15), // "receivePosition"
QT_MOC_LITERAL(21, 247, 15), // "receiveDuration"
QT_MOC_LITERAL(22, 263, 13), // "receiveStatus"
QT_MOC_LITERAL(23, 277, 19) // "QMediaPlayer::State"

    },
    "Controller\0needGetDuration\0\0needGetPosition\0"
    "needGetStatus\0needPlay\0QMediaContent*\0"
    "content\0needRestorePlay\0needPauseVideo\0"
    "needTerminateVideo\0needSeekPosition\0"
    "needSetVolume\0vol\0needSetMuted\0m\0"
    "needSetPlaybackRate\0rate\0needJump\0"
    "second\0receivePosition\0receiveDuration\0"
    "receiveStatus\0QMediaPlayer::State"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Controller[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      12,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    1,   92,    2, 0x06 /* Public */,
       8,    0,   95,    2, 0x06 /* Public */,
       9,    0,   96,    2, 0x06 /* Public */,
      10,    0,   97,    2, 0x06 /* Public */,
      11,    1,   98,    2, 0x06 /* Public */,
      12,    1,  101,    2, 0x06 /* Public */,
      14,    1,  104,    2, 0x06 /* Public */,
      16,    1,  107,    2, 0x06 /* Public */,
      18,    1,  110,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      20,    1,  113,    2, 0x0a /* Public */,
      21,    1,  116,    2, 0x0a /* Public */,
      22,    1,  119,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Bool,   15,
    QMetaType::Void, QMetaType::QReal,   17,
    QMetaType::Void, QMetaType::Int,   19,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, 0x80000000 | 23,    2,

       0        // eod
};

void Controller::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Controller *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->needGetDuration(); break;
        case 1: _t->needGetPosition(); break;
        case 2: _t->needGetStatus(); break;
        case 3: _t->needPlay((*reinterpret_cast< QMediaContent*(*)>(_a[1]))); break;
        case 4: _t->needRestorePlay(); break;
        case 5: _t->needPauseVideo(); break;
        case 6: _t->needTerminateVideo(); break;
        case 7: _t->needSeekPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 8: _t->needSetVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->needSetMuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->needSetPlaybackRate((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 11: _t->needJump((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->receivePosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 13: _t->receiveDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 14: _t->receiveStatus((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 14:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needGetDuration)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needGetPosition)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needGetStatus)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Controller::*)(QMediaContent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needPlay)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needRestorePlay)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needPauseVideo)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Controller::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needTerminateVideo)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Controller::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needSeekPosition)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needSetVolume)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Controller::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needSetMuted)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (Controller::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needSetPlaybackRate)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (Controller::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Controller::needJump)) {
                *result = 11;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Controller::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Controller.data,
    qt_meta_data_Controller,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Controller::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Controller::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Controller.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Controller::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Controller::needGetDuration()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Controller::needGetPosition()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Controller::needGetStatus()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Controller::needPlay(QMediaContent * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Controller::needRestorePlay()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Controller::needPauseVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Controller::needTerminateVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Controller::needSeekPosition(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Controller::needSetVolume(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Controller::needSetMuted(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void Controller::needSetPlaybackRate(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Controller::needJump(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
