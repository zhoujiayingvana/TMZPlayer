/****************************************************************************
** Meta object code from reading C++ file 'playlist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../playlist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'playlist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_playList_t {
    QByteArrayData data[15];
    char stringdata0[273];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_playList_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_playList_t qt_meta_stringdata_playList = {
    {
QT_MOC_LITERAL(0, 0, 8), // "playList"
QT_MOC_LITERAL(1, 9, 23), // "changeFilesInListSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 14), // "QList<QString>"
QT_MOC_LITERAL(4, 49, 28), // "leftBarListFilesChangeSignal"
QT_MOC_LITERAL(5, 78, 26), // "downloadFilesChangesSignal"
QT_MOC_LITERAL(6, 105, 15), // "sendFileAddress"
QT_MOC_LITERAL(7, 121, 38), // "on_playlist_customContextMenu..."
QT_MOC_LITERAL(8, 160, 8), // "addFiles"
QT_MOC_LITERAL(9, 169, 18), // "deleteFileFromList"
QT_MOC_LITERAL(10, 188, 18), // "deleteFileFromDisk"
QT_MOC_LITERAL(11, 207, 18), // "recevingSNAndFiles"
QT_MOC_LITERAL(12, 226, 19), // "showChangedListSlot"
QT_MOC_LITERAL(13, 246, 11), // "cellEntered"
QT_MOC_LITERAL(14, 258, 14) // "getFileAddress"

    },
    "playList\0changeFilesInListSignal\0\0"
    "QList<QString>\0leftBarListFilesChangeSignal\0"
    "downloadFilesChangesSignal\0sendFileAddress\0"
    "on_playlist_customContextMenuRequested\0"
    "addFiles\0deleteFileFromList\0"
    "deleteFileFromDisk\0recevingSNAndFiles\0"
    "showChangedListSlot\0cellEntered\0"
    "getFileAddress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_playList[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   74,    2, 0x06 /* Public */,
       4,    2,   79,    2, 0x06 /* Public */,
       5,    2,   84,    2, 0x06 /* Public */,
       6,    1,   89,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   92,    2, 0x0a /* Public */,
       8,    0,   95,    2, 0x0a /* Public */,
       9,    0,   96,    2, 0x0a /* Public */,
      10,    0,   97,    2, 0x0a /* Public */,
      11,    2,   98,    2, 0x0a /* Public */,
      12,    2,  103,    2, 0x0a /* Public */,
      13,    2,  108,    2, 0x0a /* Public */,
      14,    2,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 3,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,

       0        // eod
};

void playList::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<playList *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeFilesInListSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 1: _t->leftBarListFilesChangeSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 2: _t->downloadFilesChangesSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 3: _t->sendFileAddress((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_playlist_customContextMenuRequested((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 5: _t->addFiles(); break;
        case 6: _t->deleteFileFromList(); break;
        case 7: _t->deleteFileFromDisk(); break;
        case 8: _t->recevingSNAndFiles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 9: _t->showChangedListSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 10: _t->cellEntered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->getFileAddress((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (playList::*)(int , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playList::changeFilesInListSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (playList::*)(int , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playList::leftBarListFilesChangeSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (playList::*)(int , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playList::downloadFilesChangesSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (playList::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&playList::sendFileAddress)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject playList::staticMetaObject = { {
    &QTableWidget::staticMetaObject,
    qt_meta_stringdata_playList.data,
    qt_meta_data_playList,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *playList::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *playList::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_playList.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int playList::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    }
    return _id;
}

// SIGNAL 0
void playList::changeFilesInListSignal(int _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void playList::leftBarListFilesChangeSignal(int _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void playList::downloadFilesChangesSignal(int _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void playList::sendFileAddress(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
