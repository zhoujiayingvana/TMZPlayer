/****************************************************************************
** Meta object code from reading C++ file 'media.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../CodingFromML/0908_finalNewTMZPlayer_Back_End_ZJY_ML/NewTMZPlayer_Back_End_ZJY_ML/util/media.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'media.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Media_t {
    QByteArrayData data[17];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Media_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Media_t qt_meta_stringdata_Media = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Media"
QT_MOC_LITERAL(1, 6, 11), // "returnOrder"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 9), // "PlayOrder"
QT_MOC_LITERAL(4, 29, 19), // "hasGoodAreaAndRanks"
QT_MOC_LITERAL(5, 49, 25), // "terminateAndSaveCurrentAV"
QT_MOC_LITERAL(6, 75, 14), // "playNextByHand"
QT_MOC_LITERAL(7, 90, 14), // "playNextByAuto"
QT_MOC_LITERAL(8, 105, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(9, 125, 5), // "state"
QT_MOC_LITERAL(10, 131, 12), // "needSetOrder"
QT_MOC_LITERAL(11, 144, 5), // "order"
QT_MOC_LITERAL(12, 150, 12), // "needGetOrder"
QT_MOC_LITERAL(13, 163, 19), // "download2SongsTable"
QT_MOC_LITERAL(14, 183, 5), // "_what"
QT_MOC_LITERAL(15, 189, 13), // "songWebSearch"
QT_MOC_LITERAL(16, 203, 29) // "QList<QMap<QString,QString> >"

    },
    "Media\0returnOrder\0\0PlayOrder\0"
    "hasGoodAreaAndRanks\0terminateAndSaveCurrentAV\0"
    "playNextByHand\0playNextByAuto\0"
    "QMediaPlayer::State\0state\0needSetOrder\0"
    "order\0needGetOrder\0download2SongsTable\0"
    "_what\0songWebSearch\0QList<QMap<QString,QString> >"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Media[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   62,    2, 0x0a /* Public */,
       5,    0,   63,    2, 0x0a /* Public */,
       6,    0,   64,    2, 0x0a /* Public */,
       7,    1,   65,    2, 0x0a /* Public */,
      10,    1,   68,    2, 0x0a /* Public */,
      12,    0,   71,    2, 0x0a /* Public */,
      13,    1,   72,    2, 0x0a /* Public */,
      15,    1,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Bool, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    0x80000000 | 16, QMetaType::QString,   14,

       0        // eod
};

void Media::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Media *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnOrder((*reinterpret_cast< PlayOrder(*)>(_a[1]))); break;
        case 1: { bool _r = _t->hasGoodAreaAndRanks();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->terminateAndSaveCurrentAV(); break;
        case 3: { bool _r = _t->playNextByHand();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->playNextByAuto((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->needSetOrder((*reinterpret_cast< PlayOrder(*)>(_a[1]))); break;
        case 6: _t->needGetOrder(); break;
        case 7: _t->download2SongsTable((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { QList<QMap<QString,QString> > _r = _t->songWebSearch((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<QMap<QString,QString> >*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
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
            using _t = void (Media::*)(PlayOrder );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Media::returnOrder)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Media::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_Media.data,
    qt_meta_data_Media,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Media::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Media::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Media.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int Media::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Media::returnOrder(PlayOrder _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
