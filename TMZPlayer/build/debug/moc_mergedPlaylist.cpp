/****************************************************************************
** Meta object code from reading C++ file 'mergedPlaylist.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mergedPlaylist.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mergedPlaylist.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_mergedPlaylist_t {
    QByteArrayData data[21];
    char stringdata0[376];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_mergedPlaylist_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_mergedPlaylist_t qt_meta_stringdata_mergedPlaylist = {
    {
QT_MOC_LITERAL(0, 0, 14), // "mergedPlaylist"
QT_MOC_LITERAL(1, 15, 13), // "sendDirSignal"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 4), // "QDir"
QT_MOC_LITERAL(4, 35, 20), // "givingTempSNAndFiles"
QT_MOC_LITERAL(5, 56, 14), // "QList<QString>"
QT_MOC_LITERAL(6, 71, 21), // "showChangedListSignal"
QT_MOC_LITERAL(7, 93, 14), // "givingListName"
QT_MOC_LITERAL(8, 108, 28), // "hideContentsExceptThisSignal"
QT_MOC_LITERAL(9, 137, 17), // "hideContentSignal"
QT_MOC_LITERAL(10, 155, 22), // "allowDragAndMenuSignal"
QT_MOC_LITERAL(11, 178, 25), // "showOrHideListContentSlot"
QT_MOC_LITERAL(12, 204, 21), // "hideOtherContentsSlot"
QT_MOC_LITERAL(13, 226, 14), // "recevingTempSN"
QT_MOC_LITERAL(14, 241, 21), // "changeFilesInListSlot"
QT_MOC_LITERAL(15, 263, 9), // "currentSN"
QT_MOC_LITERAL(16, 273, 16), // "temp_filesInList"
QT_MOC_LITERAL(17, 290, 26), // "leftBarListFilesChangeSlot"
QT_MOC_LITERAL(18, 317, 15), // "wantingNameSlot"
QT_MOC_LITERAL(19, 333, 15), // "hideContentSlot"
QT_MOC_LITERAL(20, 349, 26) // "deleteListRequestAnswering"

    },
    "mergedPlaylist\0sendDirSignal\0\0QDir\0"
    "givingTempSNAndFiles\0QList<QString>\0"
    "showChangedListSignal\0givingListName\0"
    "hideContentsExceptThisSignal\0"
    "hideContentSignal\0allowDragAndMenuSignal\0"
    "showOrHideListContentSlot\0"
    "hideOtherContentsSlot\0recevingTempSN\0"
    "changeFilesInListSlot\0currentSN\0"
    "temp_filesInList\0leftBarListFilesChangeSlot\0"
    "wantingNameSlot\0hideContentSlot\0"
    "deleteListRequestAnswering"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_mergedPlaylist[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    2,   92,    2, 0x06 /* Public */,
       6,    2,   97,    2, 0x06 /* Public */,
       7,    1,  102,    2, 0x06 /* Public */,
       8,    1,  105,    2, 0x06 /* Public */,
       9,    0,  108,    2, 0x06 /* Public */,
      10,    0,  109,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    1,  110,    2, 0x0a /* Public */,
      12,    1,  113,    2, 0x0a /* Public */,
      13,    1,  116,    2, 0x0a /* Public */,
      14,    2,  119,    2, 0x0a /* Public */,
      17,    2,  124,    2, 0x0a /* Public */,
      18,    1,  129,    2, 0x0a /* Public */,
      19,    0,  132,    2, 0x0a /* Public */,
      20,    0,  133,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,   15,   16,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 5,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void mergedPlaylist::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<mergedPlaylist *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendDirSignal((*reinterpret_cast< QDir(*)>(_a[1]))); break;
        case 1: _t->givingTempSNAndFiles((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 2: _t->showChangedListSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 3: _t->givingListName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->hideContentsExceptThisSignal((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->hideContentSignal(); break;
        case 6: _t->allowDragAndMenuSignal(); break;
        case 7: _t->showOrHideListContentSlot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->hideOtherContentsSlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->recevingTempSN((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->changeFilesInListSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 11: _t->leftBarListFilesChangeSlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QList<QString>(*)>(_a[2]))); break;
        case 12: _t->wantingNameSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 13: _t->hideContentSlot(); break;
        case 14: _t->deleteListRequestAnswering(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
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
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QString> >(); break;
            }
            break;
        case 11:
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
            using _t = void (mergedPlaylist::*)(QDir );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mergedPlaylist::sendDirSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (mergedPlaylist::*)(int , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mergedPlaylist::givingTempSNAndFiles)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (mergedPlaylist::*)(int , QList<QString> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mergedPlaylist::showChangedListSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (mergedPlaylist::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mergedPlaylist::givingListName)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (mergedPlaylist::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mergedPlaylist::hideContentsExceptThisSignal)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (mergedPlaylist::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mergedPlaylist::hideContentSignal)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (mergedPlaylist::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&mergedPlaylist::allowDragAndMenuSignal)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject mergedPlaylist::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_mergedPlaylist.data,
    qt_meta_data_mergedPlaylist,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *mergedPlaylist::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *mergedPlaylist::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_mergedPlaylist.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int mergedPlaylist::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void mergedPlaylist::sendDirSignal(QDir _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mergedPlaylist::givingTempSNAndFiles(int _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void mergedPlaylist::showChangedListSignal(int _t1, QList<QString> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void mergedPlaylist::givingListName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void mergedPlaylist::hideContentsExceptThisSignal(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void mergedPlaylist::hideContentSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void mergedPlaylist::allowDragAndMenuSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
