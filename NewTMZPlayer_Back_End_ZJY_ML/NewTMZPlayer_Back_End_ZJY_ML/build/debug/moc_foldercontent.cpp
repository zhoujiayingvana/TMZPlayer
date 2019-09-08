/****************************************************************************
** Meta object code from reading C++ file 'foldercontent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../util/foldercontent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'foldercontent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FolderContent_t {
    QByteArrayData data[19];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FolderContent_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FolderContent_t qt_meta_stringdata_FolderContent = {
    {
QT_MOC_LITERAL(0, 0, 13), // "FolderContent"
QT_MOC_LITERAL(1, 14, 20), // "isAccessibleFilePath"
QT_MOC_LITERAL(2, 35, 0), // ""
QT_MOC_LITERAL(3, 36, 16), // "makeContentEmpty"
QT_MOC_LITERAL(4, 53, 9), // "makeEmpty"
QT_MOC_LITERAL(5, 63, 14), // "rebuildContent"
QT_MOC_LITERAL(6, 78, 13), // "getFolderName"
QT_MOC_LITERAL(7, 92, 13), // "setFolderName"
QT_MOC_LITERAL(8, 106, 5), // "value"
QT_MOC_LITERAL(9, 112, 11), // "getFileName"
QT_MOC_LITERAL(10, 124, 11), // "setFileName"
QT_MOC_LITERAL(11, 136, 11), // "getFilePath"
QT_MOC_LITERAL(12, 148, 10), // "getIsLocal"
QT_MOC_LITERAL(13, 159, 7), // "getRank"
QT_MOC_LITERAL(14, 167, 7), // "setRank"
QT_MOC_LITERAL(15, 175, 15), // "getMediaContent"
QT_MOC_LITERAL(16, 191, 14), // "QMediaContent*"
QT_MOC_LITERAL(17, 206, 12), // "getMediaType"
QT_MOC_LITERAL(18, 219, 9) // "MediaType"

    },
    "FolderContent\0isAccessibleFilePath\0\0"
    "makeContentEmpty\0makeEmpty\0rebuildContent\0"
    "getFolderName\0setFolderName\0value\0"
    "getFileName\0setFileName\0getFilePath\0"
    "getIsLocal\0getRank\0setRank\0getMediaContent\0"
    "QMediaContent*\0getMediaType\0MediaType"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FolderContent[] = {

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
       1,    0,   84,    2, 0x0a /* Public */,
       3,    0,   85,    2, 0x0a /* Public */,
       4,    0,   86,    2, 0x0a /* Public */,
       5,    0,   87,    2, 0x0a /* Public */,
       6,    0,   88,    2, 0x0a /* Public */,
       7,    1,   89,    2, 0x0a /* Public */,
       9,    0,   92,    2, 0x0a /* Public */,
      10,    1,   93,    2, 0x0a /* Public */,
      11,    0,   96,    2, 0x0a /* Public */,
      12,    0,   97,    2, 0x0a /* Public */,
      13,    0,   98,    2, 0x0a /* Public */,
      14,    1,   99,    2, 0x0a /* Public */,
      15,    0,  102,    2, 0x0a /* Public */,
      17,    0,  103,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::QString,
    QMetaType::Bool,
    QMetaType::Int,
    QMetaType::Void, QMetaType::Int,    8,
    0x80000000 | 16,
    0x80000000 | 18,

       0        // eod
};

void FolderContent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FolderContent *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->isAccessibleFilePath();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: _t->makeContentEmpty(); break;
        case 2: _t->makeEmpty(); break;
        case 3: _t->rebuildContent(); break;
        case 4: { QString _r = _t->getFolderName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setFolderName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: { QString _r = _t->getFileName();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->setFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: { QString _r = _t->getFilePath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 9: { bool _r = _t->getIsLocal();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: { int _r = _t->getRank();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->setRank((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: { QMediaContent* _r = _t->getMediaContent();
            if (_a[0]) *reinterpret_cast< QMediaContent**>(_a[0]) = std::move(_r); }  break;
        case 13: { MediaType _r = _t->getMediaType();
            if (_a[0]) *reinterpret_cast< MediaType*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FolderContent::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_FolderContent.data,
    qt_meta_data_FolderContent,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FolderContent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FolderContent::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FolderContent.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int FolderContent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
