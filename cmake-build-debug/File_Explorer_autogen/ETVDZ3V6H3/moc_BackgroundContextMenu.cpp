/****************************************************************************
** Meta object code from reading C++ file 'BackgroundContextMenu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../menu/BackgroundContextMenu.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BackgroundContextMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BackgroundContextMenu_t {
    const uint offsetsAndSize[36];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_BackgroundContextMenu_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_BackgroundContextMenu_t qt_meta_stringdata_BackgroundContextMenu = {
    {
QT_MOC_LITERAL(0, 21), // "BackgroundContextMenu"
QT_MOC_LITERAL(22, 5), // "Value"
QT_MOC_LITERAL(28, 0), // ""
QT_MOC_LITERAL(29, 5), // "value"
QT_MOC_LITERAL(35, 5), // "Total"
QT_MOC_LITERAL(41, 3), // "tot"
QT_MOC_LITERAL(45, 7), // "started"
QT_MOC_LITERAL(53, 5), // "fdone"
QT_MOC_LITERAL(59, 7), // "oniview"
QT_MOC_LITERAL(67, 7), // "onlview"
QT_MOC_LITERAL(75, 6), // "onsort"
QT_MOC_LITERAL(82, 10), // "_newFolder"
QT_MOC_LITERAL(93, 8), // "_newfile"
QT_MOC_LITERAL(102, 6), // "proper"
QT_MOC_LITERAL(109, 5), // "openT"
QT_MOC_LITERAL(115, 7), // "onpaste"
QT_MOC_LITERAL(123, 14), // "handleProgress"
QT_MOC_LITERAL(138, 14) // "updateProgress"

    },
    "BackgroundContextMenu\0Value\0\0value\0"
    "Total\0tot\0started\0fdone\0oniview\0onlview\0"
    "onsort\0_newFolder\0_newfile\0proper\0"
    "openT\0onpaste\0handleProgress\0"
    "updateProgress"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BackgroundContextMenu[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   98,    2, 0x06,    1 /* Public */,
       4,    1,  101,    2, 0x06,    3 /* Public */,
       6,    0,  104,    2, 0x06,    5 /* Public */,
       7,    0,  105,    2, 0x06,    6 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    0,  106,    2, 0x08,    7 /* Private */,
       9,    0,  107,    2, 0x08,    8 /* Private */,
      10,    0,  108,    2, 0x08,    9 /* Private */,
      11,    0,  109,    2, 0x08,   10 /* Private */,
      12,    0,  110,    2, 0x08,   11 /* Private */,
      13,    0,  111,    2, 0x08,   12 /* Private */,
      14,    0,  112,    2, 0x08,   13 /* Private */,
      15,    0,  113,    2, 0x0a,   14 /* Public */,
      16,    0,  114,    2, 0x0a,   15 /* Public */,
      17,    0,  115,    2, 0x0a,   16 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Int, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void BackgroundContextMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BackgroundContextMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->Value((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: { int _r = _t->Total((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])));
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->started(); break;
        case 3: _t->fdone(); break;
        case 4: _t->oniview(); break;
        case 5: _t->onlview(); break;
        case 6: _t->onsort(); break;
        case 7: _t->_newFolder(); break;
        case 8: _t->_newfile(); break;
        case 9: _t->proper(); break;
        case 10: _t->openT(); break;
        case 11: _t->onpaste(); break;
        case 12: _t->handleProgress(); break;
        case 13: _t->updateProgress(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BackgroundContextMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundContextMenu::Value)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = int (BackgroundContextMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundContextMenu::Total)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BackgroundContextMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundContextMenu::started)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BackgroundContextMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BackgroundContextMenu::fdone)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject BackgroundContextMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_BackgroundContextMenu.offsetsAndSize,
    qt_meta_data_BackgroundContextMenu,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_BackgroundContextMenu_t
, QtPrivate::TypeAndForceComplete<BackgroundContextMenu, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *BackgroundContextMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BackgroundContextMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BackgroundContextMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int BackgroundContextMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void BackgroundContextMenu::Value(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
int BackgroundContextMenu::Total(int _t1)
{
    int _t0{};
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t0))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
    return _t0;
}

// SIGNAL 2
void BackgroundContextMenu::started()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BackgroundContextMenu::fdone()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
