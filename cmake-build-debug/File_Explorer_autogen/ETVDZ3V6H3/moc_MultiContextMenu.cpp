/****************************************************************************
** Meta object code from reading C++ file 'MultiContextMenu.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../menu/MultiContextMenu.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MultiContextMenu.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMultiContextMenuENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMultiContextMenuENDCLASS = QtMocHelpers::stringData(
    "MultiContextMenu",
    "onCutClicked",
    "",
    "onCopyClicked",
    "onDeleteAllClicked",
    "openT",
    "proper",
    "_compress"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMultiContextMenuENDCLASS_t {
    uint offsetsAndSizes[16];
    char stringdata0[17];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[14];
    char stringdata4[19];
    char stringdata5[6];
    char stringdata6[7];
    char stringdata7[10];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMultiContextMenuENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMultiContextMenuENDCLASS_t qt_meta_stringdata_CLASSMultiContextMenuENDCLASS = {
    {
        QT_MOC_LITERAL(0, 16),  // "MultiContextMenu"
        QT_MOC_LITERAL(17, 12),  // "onCutClicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 13),  // "onCopyClicked"
        QT_MOC_LITERAL(45, 18),  // "onDeleteAllClicked"
        QT_MOC_LITERAL(64, 5),  // "openT"
        QT_MOC_LITERAL(70, 6),  // "proper"
        QT_MOC_LITERAL(77, 9)   // "_compress"
    },
    "MultiContextMenu",
    "onCutClicked",
    "",
    "onCopyClicked",
    "onDeleteAllClicked",
    "openT",
    "proper",
    "_compress"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMultiContextMenuENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x08,    1 /* Private */,
       3,    0,   51,    2, 0x08,    2 /* Private */,
       4,    0,   52,    2, 0x08,    3 /* Private */,
       5,    0,   53,    2, 0x08,    4 /* Private */,
       6,    0,   54,    2, 0x08,    5 /* Private */,
       7,    0,   55,    2, 0x08,    6 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject MultiContextMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_CLASSMultiContextMenuENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMultiContextMenuENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMultiContextMenuENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MultiContextMenu, std::true_type>,
        // method 'onCutClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCopyClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onDeleteAllClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'openT'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'proper'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method '_compress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void MultiContextMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MultiContextMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCutClicked(); break;
        case 1: _t->onCopyClicked(); break;
        case 2: _t->onDeleteAllClicked(); break;
        case 3: _t->openT(); break;
        case 4: _t->proper(); break;
        case 5: _t->_compress(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *MultiContextMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MultiContextMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMultiContextMenuENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int MultiContextMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP