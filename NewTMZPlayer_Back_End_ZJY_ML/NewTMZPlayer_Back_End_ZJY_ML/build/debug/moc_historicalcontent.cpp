/****************************************************************************
** Meta object code from reading C++ file 'historicalcontent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../util/historicalcontent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'historicalcontent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HistoricalContent_t {
    QByteArrayData data[22];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HistoricalContent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HistoricalContent_t qt_meta_stringdata_HistoricalContent = {
    {
QT_MOC_LITERAL(0, 0, 17), // "HistoricalContent"
QT_MOC_LITERAL(1, 18, 16), // "makeContentEmpty"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 9), // "makeEmpty"
QT_MOC_LITERAL(4, 46, 20), // "isAccessibleFilePath"
QT_MOC_LITERAL(5, 67, 14), // "rebuildContent"
QT_MOC_LITERAL(6, 82, 11), // "getFileName"
QT_MOC_LITERAL(7, 94, 11), // "setFileName"
QT_MOC_LITERAL(8, 106, 5), // "value"
QT_MOC_LITERAL(9, 112, 11), // "getFilePath"
QT_MOC_LITERAL(10, 124, 11), // "setFilePath"
QT_MOC_LITERAL(11, 136, 10), // "getIsLocal"
QT_MOC_LITERAL(12, 147, 10), // "setIsLocal"
QT_MOC_LITERAL(13, 158, 7), // "getRank"
QT_MOC_LITERAL(14, 166, 7), // "setRank"
QT_MOC_LITERAL(15, 174, 15), // "getMediaContent"
QT_MOC_LITERAL(16, 190, 14), // "QMediaContent*"
QT_MOC_LITERAL(17, 205, 22), // "getProgressMilliSecond"
QT_MOC_LITERAL(18, 228, 7), // "int64_t"
QT_MOC_LITERAL(19, 236, 22), // "setProgressMilliSecond"
QT_MOC_LITERAL(20, 259, 12), // "getMediaType"
QT_MOC_LITERAL(21, 272, 9) // "MediaType"

    },
    "HistoricalContent\0makeContentEmpty\0\0"
    "makeEmpty\0isAccessibleFilePath\0"
    "rebuildContent\0getFileName\0setFileName\0"
    "value\0getFilePath\0setFilePath\0getIsLocal\0"
    "setIsLocal\0getRank\0setRank\0getMediaContent\0"
    "QMediaContent*\0getProgressMilliSecond\0"
    "int64_t\0setProgressMilliSecond\0"
    "getMediaType\0MediaType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HistoricalContent[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   94,    2, 0x0a /* Public */,
       3,    0,   95,    2, 0x0a /* Public */,
       4,    0,   96,    2, 0x0a /* Public */,
       5,    0,   97,    2, 0x0a /* Public */,
       6,    0,   98,    2, 0x0a /* Public */,
       7,    1,   99,    2, 0x0a /* Public */,
       9,    0,  102,    2, 0x0a /* Public */,
      10,    1,  103,    2, 0x0a /* Public */,
      11,    0,  106,    2, 0x0a /* Public */,
      12,    1,  107,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    1,  111,    2, 0x0a /* Public */,
      15,    0,  114,    2, 0x0a /* Public */,
      17,    0,  115,    2, 0x0a /* Public */,
      19,    1,  116,    2, 0x0a /* Public */,
      20,    0,  119,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    8,
    0x80000000 | 16,
    0x80000000 | 18,
    QMetaType::Void, 0x80000000 | 18,    8,
    0x80000000 | 21,

       0        // eod
};

void HistoricalContent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<HistoricalContent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->makeContentEmpty(); break;
        case 1: _t->makeEmpty(); break;
        case 2: { bool _r = _t->isAccessibleFilePath();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->rebuildContent(); break;
        case 4: { QString _r = _t->getFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: { QString _r = _t->getFilePath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setFilePath((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { bool _r = _t->getIsLocal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 9: _t->setIsLocal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: { int _r = _t->getRank();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setRank((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { QMediaContent* _r = _t->getMediaContent();
            if (_a[0]) *reinterpret_cast< QMediaContent**>(_a[0]) = std::move(_r); }  break;
        case 13: { int64_t _r = _t->getProgressMilliSecond();
            if (_a[0]) *reinterpret_cast< int64_t*>(_a[0]) = std::move(_r); }  break;
        case 14: _t->setProgressMilliSecond((*reinterpret_cast< const int64_t(*)>(_a[1]))); break;
        case 15: { MediaType _r = _t->getMediaType();
            if (_a[0]) *reinterpret_cast< MediaType*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject HistoricalContent::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_HistoricalContent.data,
    qt_meta_data_HistoricalContent,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *HistoricalContent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HistoricalContent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HistoricalContent.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int HistoricalContent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
