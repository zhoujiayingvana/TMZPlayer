/****************************************************************************
** Meta object code from reading C++ file 'mini.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mini.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mini.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mini_t {
    QByteArrayData data[16];
    char stringdata0[265];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Mini_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Mini_t qt_meta_stringdata_Mini = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Mini"
QT_MOC_LITERAL(1, 5, 15), // "miniToMaxSignal"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "closeSignal"
QT_MOC_LITERAL(4, 34, 14), // "sendLastSignal"
QT_MOC_LITERAL(5, 49, 14), // "sendNextSignal"
QT_MOC_LITERAL(6, 64, 13), // "volumeChanged"
QT_MOC_LITERAL(7, 78, 21), // "sendPlayOrPauseSignal"
QT_MOC_LITERAL(8, 100, 14), // "sendLikeSignal"
QT_MOC_LITERAL(9, 115, 21), // "on_maxModeBtn_clicked"
QT_MOC_LITERAL(10, 137, 19), // "on_closeBtn_clicked"
QT_MOC_LITERAL(11, 157, 20), // "on_volumeBtn_clicked"
QT_MOC_LITERAL(12, 178, 28), // "on_volumeSlider_valueChanged"
QT_MOC_LITERAL(13, 207, 25), // "on_playOrPauseBtn_clicked"
QT_MOC_LITERAL(14, 233, 18), // "on_likeBtn_clicked"
QT_MOC_LITERAL(15, 252, 12) // "changeVolume"

    },
    "Mini\0miniToMaxSignal\0\0closeSignal\0"
    "sendLastSignal\0sendNextSignal\0"
    "volumeChanged\0sendPlayOrPauseSignal\0"
    "sendLikeSignal\0on_maxModeBtn_clicked\0"
    "on_closeBtn_clicked\0on_volumeBtn_clicked\0"
    "on_volumeSlider_valueChanged\0"
    "on_playOrPauseBtn_clicked\0on_likeBtn_clicked\0"
    "changeVolume"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mini[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   84,    2, 0x06 /* Public */,
       3,    0,   85,    2, 0x06 /* Public */,
       4,    0,   86,    2, 0x06 /* Public */,
       5,    0,   87,    2, 0x06 /* Public */,
       6,    1,   88,    2, 0x06 /* Public */,
       7,    1,   91,    2, 0x06 /* Public */,
       8,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   97,    2, 0x0a /* Public */,
      10,    0,   98,    2, 0x0a /* Public */,
      11,    0,   99,    2, 0x0a /* Public */,
      12,    1,  100,    2, 0x0a /* Public */,
      13,    0,  103,    2, 0x0a /* Public */,
      14,    0,  104,    2, 0x0a /* Public */,
      15,    1,  105,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Mini::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mini *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->miniToMaxSignal(); break;
        case 1: _t->closeSignal(); break;
        case 2: _t->sendLastSignal(); break;
        case 3: _t->sendNextSignal(); break;
        case 4: _t->volumeChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->sendPlayOrPauseSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->sendLikeSignal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_maxModeBtn_clicked(); break;
        case 8: _t->on_closeBtn_clicked(); break;
        case 9: _t->on_volumeBtn_clicked(); break;
        case 10: _t->on_volumeSlider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->on_playOrPauseBtn_clicked(); break;
        case 12: _t->on_likeBtn_clicked(); break;
        case 13: _t->changeVolume((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mini::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mini::miniToMaxSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Mini::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mini::closeSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Mini::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mini::sendLastSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Mini::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mini::sendNextSignal)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Mini::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mini::volumeChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Mini::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mini::sendPlayOrPauseSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Mini::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mini::sendLikeSignal)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Mini::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Mini.data,
    qt_meta_data_Mini,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Mini::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mini::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mini.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Mini::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Mini::miniToMaxSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Mini::closeSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Mini::sendLastSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Mini::sendNextSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Mini::volumeChanged(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Mini::sendPlayOrPauseSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Mini::sendLikeSignal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
