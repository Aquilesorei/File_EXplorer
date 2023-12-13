/****************************************************************************
** Meta object code from reading C++ file 'Achille.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Achille.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Achille.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Achille_t {
    const uint offsetsAndSize[36];
    char stringdata0[211];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Achille_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Achille_t qt_meta_stringdata_Achille = {
    {
QT_MOC_LITERAL(0, 7), // "Achille"
QT_MOC_LITERAL(8, 15), // "selectAllstatus"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 3), // "val"
QT_MOC_LITERAL(29, 12), // "SelectChange"
QT_MOC_LITERAL(42, 2), // "nb"
QT_MOC_LITERAL(45, 21), // "rename_bouton_clicked"
QT_MOC_LITERAL(67, 10), // "dirChanged"
QT_MOC_LITERAL(78, 4), // "path"
QT_MOC_LITERAL(83, 14), // "historyChanged"
QT_MOC_LITERAL(98, 14), // "selectionState"
QT_MOC_LITERAL(113, 11), // "anySelected"
QT_MOC_LITERAL(125, 19), // "onItemDoubleClicked"
QT_MOC_LITERAL(145, 16), // "QListWidgetItem*"
QT_MOC_LITERAL(162, 4), // "item"
QT_MOC_LITERAL(167, 13), // "onItemClicked"
QT_MOC_LITERAL(181, 14), // "onEnterPressed"
QT_MOC_LITERAL(196, 14) // "onCloseClicked"

    },
    "Achille\0selectAllstatus\0\0val\0SelectChange\0"
    "nb\0rename_bouton_clicked\0dirChanged\0"
    "path\0historyChanged\0selectionState\0"
    "anySelected\0onItemDoubleClicked\0"
    "QListWidgetItem*\0item\0onItemClicked\0"
    "onEnterPressed\0onCloseClicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Achille[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    0,   80,    2, 0x06,    5 /* Public */,
       7,    1,   81,    2, 0x06,    6 /* Public */,
       9,    0,   84,    2, 0x06,    8 /* Public */,
      10,    1,   85,    2, 0x06,    9 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    1,   88,    2, 0x0a,   11 /* Public */,
      15,    1,   91,    2, 0x0a,   13 /* Public */,
      16,    0,   94,    2, 0x08,   15 /* Private */,
      17,    0,   95,    2, 0x08,   16 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Achille::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Achille *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->selectAllstatus((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 1: _t->SelectChange((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->rename_bouton_clicked(); break;
        case 3: _t->dirChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 4: _t->historyChanged(); break;
        case 5: _t->selectionState((*reinterpret_cast< std::add_pointer_t<bool>>(_a[1]))); break;
        case 6: _t->onItemDoubleClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 7: _t->onItemClicked((*reinterpret_cast< std::add_pointer_t<QListWidgetItem*>>(_a[1]))); break;
        case 8: _t->onEnterPressed(); break;
        case 9: _t->onCloseClicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Achille::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Achille::selectAllstatus)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Achille::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Achille::SelectChange)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Achille::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Achille::rename_bouton_clicked)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Achille::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Achille::dirChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Achille::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Achille::historyChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Achille::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Achille::selectionState)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Achille::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_Achille.offsetsAndSize,
    qt_meta_data_Achille,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Achille_t
, QtPrivate::TypeAndForceComplete<Achille, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QListWidgetItem *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Achille::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Achille::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Achille.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Achille::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Achille::selectAllstatus(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Achille::SelectChange(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Achille::rename_bouton_clicked()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Achille::dirChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Achille::historyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Achille::selectionState(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_FileSystemWatcher_t {
    const uint offsetsAndSize[6];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FileSystemWatcher_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FileSystemWatcher_t qt_meta_stringdata_FileSystemWatcher = {
    {
QT_MOC_LITERAL(0, 17), // "FileSystemWatcher"
QT_MOC_LITERAL(18, 9), // "onRefresh"
QT_MOC_LITERAL(28, 0) // ""

    },
    "FileSystemWatcher\0onRefresh\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FileSystemWatcher[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void FileSystemWatcher::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FileSystemWatcher *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onRefresh(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject FileSystemWatcher::staticMetaObject = { {
    QMetaObject::SuperData::link<QTimer::staticMetaObject>(),
    qt_meta_stringdata_FileSystemWatcher.offsetsAndSize,
    qt_meta_data_FileSystemWatcher,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FileSystemWatcher_t
, QtPrivate::TypeAndForceComplete<FileSystemWatcher, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FileSystemWatcher::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FileSystemWatcher::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FileSystemWatcher.stringdata0))
        return static_cast<void*>(this);
    return QTimer::qt_metacast(_clname);
}

int FileSystemWatcher::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTimer::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
