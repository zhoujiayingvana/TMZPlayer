/****************************************************************************
** Meta object code from reading C++ file 'player.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../util/player.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'player.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Player_t {
    QByteArrayData data[18];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Player_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Player_t qt_meta_stringdata_Player = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Player"
QT_MOC_LITERAL(1, 7, 14), // "returnDuration"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "dur"
QT_MOC_LITERAL(4, 27, 14), // "returnPosition"
QT_MOC_LITERAL(5, 42, 3), // "pos"
QT_MOC_LITERAL(6, 46, 12), // "returnStatus"
QT_MOC_LITERAL(7, 59, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(8, 79, 3), // "stu"
QT_MOC_LITERAL(9, 83, 8), // "needPlay"
QT_MOC_LITERAL(10, 92, 14), // "QMediaContent*"
QT_MOC_LITERAL(11, 107, 7), // "content"
QT_MOC_LITERAL(12, 115, 15), // "needGetDuration"
QT_MOC_LITERAL(13, 131, 15), // "needGetPosition"
QT_MOC_LITERAL(14, 147, 13), // "needGetStatus"
QT_MOC_LITERAL(15, 161, 15), // "needRestorePlay"
QT_MOC_LITERAL(16, 177, 14), // "needPauseVideo"
QT_MOC_LITERAL(17, 192, 18) // "needTerminateVideo"

    },
    "Player\0returnDuration\0\0dur\0returnPosition\0"
    "pos\0returnStatus\0QMediaPlayer::State\0"
    "stu\0needPlay\0QMediaContent*\0content\0"
    "needGetDuration\0needGetPosition\0"
    "needGetStatus\0needRestorePlay\0"
    "needPauseVideo\0needTerminateVideo"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,
       6,    1,   70,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   73,    2, 0x0a /* Public */,
      12,    0,   76,    2, 0x0a /* Public */,
      13,    0,   77,    2, 0x0a /* Public */,
      14,    0,   78,    2, 0x0a /* Public */,
      15,    0,   79,    2, 0x0a /* Public */,
      16,    0,   80,    2, 0x0a /* Public */,
      17,    0,   81,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Player::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Player *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnDuration((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 1: _t->returnPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->returnStatus((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 3: _t->needPlay((*reinterpret_cast< QMediaContent*(*)>(_a[1]))); break;
        case 4: _t->needGetDuration(); break;
        case 5: _t->needGetPosition(); break;
        case 6: _t->needGetStatus(); break;
        case 7: _t->needRestorePlay(); break;
        case 8: _t->needPauseVideo(); break;
        case 9: _t->needTerminateVideo(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
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
            using _t = void (Player::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::returnDuration)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Player::*)(qint64 );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::returnPosition)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Player::*)(QMediaPlayer::State );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::returnStatus)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Player::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Player.data,
    qt_meta_data_Player,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Player::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Player::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Player.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Player::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Player::returnDuration(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Player::returnPosition(qint64 _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Player::returnStatus(QMediaPlayer::State _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE