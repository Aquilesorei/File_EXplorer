/****************************************************************************
** Meta object code from reading C++ file 'QRoundProgressBar.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../libs/QRoundProgressBar/QRoundProgressBar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QRoundProgressBar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QRoundProgressBar_t {
    const uint offsetsAndSize[18];
    char stringdata0[71];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_QRoundProgressBar_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_QRoundProgressBar_t qt_meta_stringdata_QRoundProgressBar = {
    {
QT_MOC_LITERAL(0, 17), // "QRoundProgressBar"
QT_MOC_LITERAL(18, 8), // "setRange"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 3), // "min"
QT_MOC_LITERAL(32, 3), // "max"
QT_MOC_LITERAL(36, 10), // "setMinimum"
QT_MOC_LITERAL(47, 10), // "setMaximum"
QT_MOC_LITERAL(58, 8), // "setValue"
QT_MOC_LITERAL(67, 3) // "val"

    },
    "QRoundProgressBar\0setRange\0\0min\0max\0"
    "setMinimum\0setMaximum\0setValue\0val"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QRoundProgressBar[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   44,    2, 0x0a,    1 /* Public */,
       5,    1,   49,    2, 0x0a,    4 /* Public */,
       6,    1,   52,    2, 0x0a,    6 /* Public */,
       7,    1,   55,    2, 0x0a,    8 /* Public */,
       7,    1,   58,    2, 0x0a,   10 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Double, QMetaType::Double,    3,    4,
    QMetaType::Void, QMetaType::Double,    3,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void, QMetaType::Double,    8,
    QMetaType::Void, QMetaType::Int,    8,

       0        // eod
};

void QRoundProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QRoundProgressBar *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setRange((*reinterpret_cast< std::add_pointer_t<double>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<double>>(_a[2]))); break;
        case 1: _t->setMinimum((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 2: _t->setMaximum((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 3: _t->setValue((*reinterpret_cast< std::add_pointer_t<double>>(_a[1]))); break;
        case 4: _t->setValue((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject QRoundProgressBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_QRoundProgressBar.offsetsAndSize,
    qt_meta_data_QRoundProgressBar,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_QRoundProgressBar_t
, QtPrivate::TypeAndForceComplete<QRoundProgressBar, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *QRoundProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QRoundProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QRoundProgressBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int QRoundProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
