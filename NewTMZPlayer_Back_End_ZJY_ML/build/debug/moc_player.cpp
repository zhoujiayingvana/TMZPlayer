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
    QByteArrayData data[34];
    char stringdata0[356];
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
QT_MOC_LITERAL(9, 83, 15), // "returnScreenCut"
QT_MOC_LITERAL(10, 99, 8), // "needPlay"
QT_MOC_LITERAL(11, 108, 14), // "QMediaContent*"
QT_MOC_LITERAL(12, 123, 7), // "content"
QT_MOC_LITERAL(13, 131, 15), // "needGetDuration"
QT_MOC_LITERAL(14, 147, 15), // "needGetPosition"
QT_MOC_LITERAL(15, 163, 13), // "needGetStatus"
QT_MOC_LITERAL(16, 177, 15), // "needRestorePlay"
QT_MOC_LITERAL(17, 193, 14), // "needPauseVideo"
QT_MOC_LITERAL(18, 208, 18), // "needTerminateVideo"
QT_MOC_LITERAL(19, 227, 8), // "needJump"
QT_MOC_LITERAL(20, 236, 6), // "second"
QT_MOC_LITERAL(21, 243, 15), // "needSetPosition"
QT_MOC_LITERAL(22, 259, 12), // "needSetMuted"
QT_MOC_LITERAL(23, 272, 1), // "m"
QT_MOC_LITERAL(24, 274, 13), // "needSetVolume"
QT_MOC_LITERAL(25, 288, 3), // "vol"
QT_MOC_LITERAL(26, 292, 19), // "needSetPlaybackRate"
QT_MOC_LITERAL(27, 312, 4), // "rate"
QT_MOC_LITERAL(28, 317, 13), // "needCutScreen"
QT_MOC_LITERAL(29, 331, 3), // "WId"
QT_MOC_LITERAL(30, 335, 3), // "wId"
QT_MOC_LITERAL(31, 339, 8), // "fileName"
QT_MOC_LITERAL(32, 348, 3), // "fmt"
QT_MOC_LITERAL(33, 352, 3) // "qua"

    },
    "Player\0returnDuration\0\0dur\0returnPosition\0"
    "pos\0returnStatus\0QMediaPlayer::State\0"
    "stu\0returnScreenCut\0needPlay\0"
    "QMediaContent*\0content\0needGetDuration\0"
    "needGetPosition\0needGetStatus\0"
    "needRestorePlay\0needPauseVideo\0"
    "needTerminateVideo\0needJump\0second\0"
    "needSetPosition\0needSetMuted\0m\0"
    "needSetVolume\0vol\0needSetPlaybackRate\0"
    "rate\0needCutScreen\0WId\0wId\0fileName\0"
    "fmt\0qua"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Player[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   99,    2, 0x06 /* Public */,
       4,    1,  102,    2, 0x06 /* Public */,
       6,    1,  105,    2, 0x06 /* Public */,
       9,    1,  108,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,  111,    2, 0x0a /* Public */,
      13,    0,  114,    2, 0x0a /* Public */,
      14,    0,  115,    2, 0x0a /* Public */,
      15,    0,  116,    2, 0x0a /* Public */,
      16,    0,  117,    2, 0x0a /* Public */,
      17,    0,  118,    2, 0x0a /* Public */,
      18,    0,  119,    2, 0x0a /* Public */,
      19,    1,  120,    2, 0x0a /* Public */,
      21,    1,  123,    2, 0x0a /* Public */,
      22,    1,  126,    2, 0x0a /* Public */,
      24,    1,  129,    2, 0x0a /* Public */,
      26,    1,  132,    2, 0x0a /* Public */,
      28,    4,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::LongLong,    3,
    QMetaType::Void, QMetaType::LongLong,    5,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   20,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Bool,   23,
    QMetaType::Void, QMetaType::Int,   25,
    QMetaType::Void, QMetaType::QReal,   27,
    QMetaType::Void, 0x80000000 | 29, QMetaType::QString, QMetaType::QString, QMetaType::Int,   30,   31,   32,   33,

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
        case 3: _t->returnScreenCut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->needPlay((*reinterpret_cast< QMediaContent*(*)>(_a[1]))); break;
        case 5: _t->needGetDuration(); break;
        case 6: _t->needGetPosition(); break;
        case 7: _t->needGetStatus(); break;
        case 8: _t->needRestorePlay(); break;
        case 9: _t->needPauseVideo(); break;
        case 10: _t->needTerminateVideo(); break;
        case 11: _t->needJump((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->needSetPosition((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 13: _t->needSetMuted((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->needSetVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->needSetPlaybackRate((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 16: _t->needCutScreen((*reinterpret_cast< WId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
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
        {
            using _t = void (Player::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Player::returnScreenCut)) {
                *result = 3;
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
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
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

// SIGNAL 3
void Player::returnScreenCut(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
