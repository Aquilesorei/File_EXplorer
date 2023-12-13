/****************************************************************************
** Meta object code from reading C++ file 'toolbarfichiers.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../toolbars/toolbarfichiers.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'toolbarfichiers.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_toolbarfichier_t {
    const uint offsetsAndSize[20];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_toolbarfichier_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_toolbarfichier_t qt_meta_stringdata_toolbarfichier = {
    {
QT_MOC_LITERAL(0, 14), // "toolbarfichier"
QT_MOC_LITERAL(15, 6), // "addNew"
QT_MOC_LITERAL(22, 0), // ""
QT_MOC_LITERAL(23, 13), // "configActions"
QT_MOC_LITERAL(37, 5), // "_copy"
QT_MOC_LITERAL(43, 4), // "_cut"
QT_MOC_LITERAL(48, 6), // "_paste"
QT_MOC_LITERAL(55, 7), // "_rename"
QT_MOC_LITERAL(63, 7), // "_delete"
QT_MOC_LITERAL(71, 5) // "_sort"

    },
    "toolbarfichier\0addNew\0\0configActions\0"
    "_copy\0_cut\0_paste\0_rename\0_delete\0"
    "_sort"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_toolbarfichier[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   62,    2, 0x08,    1 /* Private */,
       3,    0,   63,    2, 0x08,    2 /* Private */,
       4,    0,   64,    2, 0x08,    3 /* Private */,
       5,    0,   65,    2, 0x08,    4 /* Private */,
       6,    0,   66,    2, 0x08,    5 /* Private */,
       7,    0,   67,    2, 0x08,    6 /* Private */,
       8,    0,   68,    2, 0x08,    7 /* Private */,
       9,    0,   69,    2, 0x08,    8 /* Private */,

 // slots: parameters
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

void toolbarfichier::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<toolbarfichier *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addNew(); break;
        case 1: _t->configActions(); break;
        case 2: _t->_copy(); break;
        case 3: _t->_cut(); break;
        case 4: _t->_paste(); break;
        case 5: _t->_rename(); break;
        case 6: _t->_delete(); break;
        case 7: _t->_sort(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject toolbarfichier::staticMetaObject = { {
    QMetaObject::SuperData::link<QToolBar::staticMetaObject>(),
    qt_meta_stringdata_toolbarfichier.offsetsAndSize,
    qt_meta_data_toolbarfichier,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_toolbarfichier_t
, QtPrivate::TypeAndForceComplete<toolbarfichier, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *toolbarfichier::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *toolbarfichier::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_toolbarfichier.stringdata0))
        return static_cast<void*>(this);
    return QToolBar::qt_metacast(_clname);
}

int toolbarfichier::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
