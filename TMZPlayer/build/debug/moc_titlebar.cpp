/****************************************************************************
** Meta object code from reading C++ file 'titlebar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../titlebar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'titlebar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TitleBar_t {
    QByteArrayData data[14];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TitleBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TitleBar_t qt_meta_stringdata_TitleBar = {
    {
QT_MOC_LITERAL(0, 0, 8), // "TitleBar"
QT_MOC_LITERAL(1, 9, 14), // "systemTrayMode"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 8), // "miniMode"
QT_MOC_LITERAL(4, 34, 21), // "on_miniButton_clicked"
QT_MOC_LITERAL(5, 56, 25), // "on_minimizeButton_clicked"
QT_MOC_LITERAL(6, 82, 25), // "on_maximizeButton_clicked"
QT_MOC_LITERAL(7, 108, 22), // "on_closeButton_clicked"
QT_MOC_LITERAL(8, 131, 25), // "on_SettingsButton_clicked"
QT_MOC_LITERAL(9, 157, 14), // "changeFontType"
QT_MOC_LITERAL(10, 172, 6), // "QFont*"
QT_MOC_LITERAL(11, 179, 4), // "font"
QT_MOC_LITERAL(12, 184, 18), // "changeLikeShortcut"
QT_MOC_LITERAL(13, 203, 17) // "changeCloseStatus"

    },
    "TitleBar\0systemTrayMode\0\0miniMode\0"
    "on_miniButton_clicked\0on_minimizeButton_clicked\0"
    "on_maximizeButton_clicked\0"
    "on_closeButton_clicked\0on_SettingsButton_clicked\0"
    "changeFontType\0QFont*\0font\0"
    "changeLikeShortcut\0changeCloseStatus"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TitleBar[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   66,    2, 0x0a /* Public */,
       5,    0,   67,    2, 0x0a /* Public */,
       6,    0,   68,    2, 0x0a /* Public */,
       7,    0,   69,    2, 0x0a /* Public */,
       8,    0,   70,    2, 0x0a /* Public */,
       9,    1,   71,    2, 0x0a /* Public */,
      12,    1,   74,    2, 0x0a /* Public */,
      13,    1,   77,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void TitleBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TitleBar *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->systemTrayMode(); break;
        case 1: _t->miniMode(); break;
        case 2: _t->on_miniButton_clicked(); break;
        case 3: _t->on_minimizeButton_clicked(); break;
        case 4: _t->on_maximizeButton_clicked(); break;
        case 5: _t->on_closeButton_clicked(); break;
        case 6: _t->on_SettingsButton_clicked(); break;
        case 7: _t->changeFontType((*reinterpret_cast< QFont*(*)>(_a[1]))); break;
        case 8: _t->changeLikeShortcut((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->changeCloseStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (TitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TitleBar::systemTrayMode)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (TitleBar::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&TitleBar::miniMode)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TitleBar::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_TitleBar.data,
    qt_meta_data_TitleBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TitleBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TitleBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TitleBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int TitleBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void TitleBar::systemTrayMode()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void TitleBar::miniMode()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
