/****************************************************************************
** Meta object code from reading C++ file 'disks.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../disks.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'disks.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Device_t {
    const uint offsetsAndSize[36];
    char stringdata0[227];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Device_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Device_t qt_meta_stringdata_Device = {
    {
QT_MOC_LITERAL(0, 6), // "Device"
QT_MOC_LITERAL(7, 12), // "mediaChanged"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 10), // "devicePath"
QT_MOC_LITERAL(32, 12), // "mediaPresent"
QT_MOC_LITERAL(45, 17), // "mountpointChanged"
QT_MOC_LITERAL(63, 16), // "deviceMountpoint"
QT_MOC_LITERAL(80, 11), // "nameChanged"
QT_MOC_LITERAL(92, 10), // "deviceName"
QT_MOC_LITERAL(103, 12), // "errorMessage"
QT_MOC_LITERAL(116, 11), // "deviceError"
QT_MOC_LITERAL(128, 5), // "mount"
QT_MOC_LITERAL(134, 7), // "unmount"
QT_MOC_LITERAL(142, 5), // "eject"
QT_MOC_LITERAL(148, 22), // "updateDeviceProperties"
QT_MOC_LITERAL(171, 23), // "handlePropertiesChanged"
QT_MOC_LITERAL(195, 13), // "interfaceType"
QT_MOC_LITERAL(209, 17) // "changedProperties"

    },
    "Device\0mediaChanged\0\0devicePath\0"
    "mediaPresent\0mountpointChanged\0"
    "deviceMountpoint\0nameChanged\0deviceName\0"
    "errorMessage\0deviceError\0mount\0unmount\0"
    "eject\0updateDeviceProperties\0"
    "handlePropertiesChanged\0interfaceType\0"
    "changedProperties"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Device[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       5,    2,   73,    2, 0x06,    4 /* Public */,
       7,    2,   78,    2, 0x06,    7 /* Public */,
       9,    2,   83,    2, 0x06,   10 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,   88,    2, 0x0a,   13 /* Public */,
      12,    0,   89,    2, 0x0a,   14 /* Public */,
      13,    0,   90,    2, 0x0a,   15 /* Public */,
      14,    0,   91,    2, 0x08,   16 /* Private */,
      15,    2,   92,    2, 0x08,   17 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    6,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    8,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,   10,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QVariantMap,   16,   17,

       0        // eod
};

void Device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Device *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mediaChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 1: _t->mountpointChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 2: _t->nameChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->errorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->mount(); break;
        case 5: _t->unmount(); break;
        case 6: _t->eject(); break;
        case 7: _t->updateDeviceProperties(); break;
        case 8: _t->handlePropertiesChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QMap<QString,QVariant>>>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Device::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::mediaChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Device::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::mountpointChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Device::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::nameChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Device::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Device::errorMessage)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject Device::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Device.offsetsAndSize,
    qt_meta_data_Device,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Device_t
, QtPrivate::TypeAndForceComplete<Device, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QString &, std::false_type>, QtPrivate::TypeAndForceComplete<const QMap<QString,QVariant> &, std::false_type>


>,
    nullptr
} };


const QMetaObject *Device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Device.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void Device::mediaChanged(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Device::mountpointChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Device::nameChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Device::errorMessage(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_Disks_t {
    const uint offsetsAndSize[52];
    char stringdata0[342];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Disks_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Disks_t qt_meta_stringdata_Disks = {
    {
QT_MOC_LITERAL(0, 5), // "Disks"
QT_MOC_LITERAL(6, 14), // "updatedDevices"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 12), // "mediaChanged"
QT_MOC_LITERAL(35, 4), // "path"
QT_MOC_LITERAL(40, 5), // "media"
QT_MOC_LITERAL(46, 17), // "mountpointChanged"
QT_MOC_LITERAL(64, 10), // "mountpoint"
QT_MOC_LITERAL(75, 18), // "deviceErrorMessage"
QT_MOC_LITERAL(94, 5), // "error"
QT_MOC_LITERAL(100, 14), // "foundNewDevice"
QT_MOC_LITERAL(115, 13), // "removedDevice"
QT_MOC_LITERAL(129, 9), // "setupDBus"
QT_MOC_LITERAL(139, 11), // "scanDevices"
QT_MOC_LITERAL(151, 11), // "deviceAdded"
QT_MOC_LITERAL(163, 15), // "QDBusObjectPath"
QT_MOC_LITERAL(179, 3), // "obj"
QT_MOC_LITERAL(183, 13), // "deviceRemoved"
QT_MOC_LITERAL(197, 24), // "handleDeviceMediaChanged"
QT_MOC_LITERAL(222, 10), // "devicePath"
QT_MOC_LITERAL(233, 12), // "mediaPresent"
QT_MOC_LITERAL(246, 29), // "handleDeviceMountpointChanged"
QT_MOC_LITERAL(276, 16), // "deviceMountpoint"
QT_MOC_LITERAL(293, 24), // "handleDeviceErrorMessage"
QT_MOC_LITERAL(318, 11), // "deviceError"
QT_MOC_LITERAL(330, 11) // "checkUDisks"

    },
    "Disks\0updatedDevices\0\0mediaChanged\0"
    "path\0media\0mountpointChanged\0mountpoint\0"
    "deviceErrorMessage\0error\0foundNewDevice\0"
    "removedDevice\0setupDBus\0scanDevices\0"
    "deviceAdded\0QDBusObjectPath\0obj\0"
    "deviceRemoved\0handleDeviceMediaChanged\0"
    "devicePath\0mediaPresent\0"
    "handleDeviceMountpointChanged\0"
    "deviceMountpoint\0handleDeviceErrorMessage\0"
    "deviceError\0checkUDisks"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Disks[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x06,    1 /* Public */,
       3,    2,   99,    2, 0x06,    2 /* Public */,
       6,    2,  104,    2, 0x06,    5 /* Public */,
       8,    2,  109,    2, 0x06,    8 /* Public */,
      10,    1,  114,    2, 0x06,   11 /* Public */,
      11,    1,  117,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    0,  120,    2, 0x08,   15 /* Private */,
      13,    0,  121,    2, 0x08,   16 /* Private */,
      14,    1,  122,    2, 0x08,   17 /* Private */,
      17,    1,  125,    2, 0x08,   19 /* Private */,
      18,    2,  128,    2, 0x08,   21 /* Private */,
      21,    2,  133,    2, 0x08,   24 /* Private */,
      23,    2,  138,    2, 0x08,   27 /* Private */,
      25,    0,  143,    2, 0x08,   30 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,    4,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    7,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    4,    9,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void, QMetaType::QString, QMetaType::Bool,   19,   20,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   22,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   19,   24,
    QMetaType::Void,

       0        // eod
};

void Disks::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Disks *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->updatedDevices(); break;
        case 1: _t->mediaChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 2: _t->mountpointChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 3: _t->deviceErrorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 4: _t->foundNewDevice((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 5: _t->removedDevice((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 6: _t->setupDBus(); break;
        case 7: _t->scanDevices(); break;
        case 8: _t->deviceAdded((*reinterpret_cast< std::add_pointer_t<QDBusObjectPath>>(_a[1]))); break;
        case 9: _t->deviceRemoved((*reinterpret_cast< std::add_pointer_t<QDBusObjectPath>>(_a[1]))); break;
        case 10: _t->handleDeviceMediaChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<bool>>(_a[2]))); break;
        case 11: _t->handleDeviceMountpointChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 12: _t->handleDeviceErrorMessage((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<QString>>(_a[2]))); break;
        case 13: _t->checkUDisks(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 8:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusObjectPath >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QDBusObjectPath >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Disks::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Disks::updatedDevices)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Disks::*)(QString , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Disks::mediaChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Disks::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Disks::mountpointChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Disks::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Disks::deviceErrorMessage)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Disks::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Disks::foundNewDevice)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Disks::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Disks::removedDevice)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Disks::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Disks.offsetsAndSize,
    qt_meta_data_Disks,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Disks_t
, QtPrivate::TypeAndForceComplete<Disks, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDBusObjectPath &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const QDBusObjectPath &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *Disks::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Disks::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Disks.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Disks::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Disks::updatedDevices()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Disks::mediaChanged(QString _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Disks::mountpointChanged(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Disks::deviceErrorMessage(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Disks::foundNewDevice(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Disks::removedDevice(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
