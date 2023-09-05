/****************************************************************************
** Meta object code from reading C++ file 'usbconnection.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "usbconnection.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usbconnection.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_usbConnection_t {
    const uint offsetsAndSize[30];
    char stringdata0[187];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_usbConnection_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_usbConnection_t qt_meta_stringdata_usbConnection = {
    {
QT_MOC_LITERAL(0, 13), // "usbConnection"
QT_MOC_LITERAL(14, 12), // "statusSignal"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 13), // "plotterStatus"
QT_MOC_LITERAL(42, 6), // "status"
QT_MOC_LITERAL(49, 18), // "disconnectedSignal"
QT_MOC_LITERAL(68, 13), // "messageSignal"
QT_MOC_LITERAL(82, 7), // "message"
QT_MOC_LITERAL(90, 9), // "portError"
QT_MOC_LITERAL(100, 28), // "QSerialPort::SerialPortError"
QT_MOC_LITERAL(129, 5), // "error"
QT_MOC_LITERAL(135, 11), // "requestTime"
QT_MOC_LITERAL(147, 13), // "dataReadyRead"
QT_MOC_LITERAL(161, 12), // "waitTimeSlot"
QT_MOC_LITERAL(174, 12) // "sendStopSlot"

    },
    "usbConnection\0statusSignal\0\0plotterStatus\0"
    "status\0disconnectedSignal\0messageSignal\0"
    "message\0portError\0QSerialPort::SerialPortError\0"
    "error\0requestTime\0dataReadyRead\0"
    "waitTimeSlot\0sendStopSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_usbConnection[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   62,    2, 0x06,    1 /* Public */,
       5,    0,   65,    2, 0x06,    3 /* Public */,
       6,    1,   66,    2, 0x06,    4 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       8,    1,   69,    2, 0x09,    6 /* Protected */,
      11,    0,   72,    2, 0x09,    8 /* Protected */,
      12,    0,   73,    2, 0x09,    9 /* Protected */,
      13,    0,   74,    2, 0x09,   10 /* Protected */,
      14,    0,   75,    2, 0x09,   11 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void usbConnection::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<usbConnection *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->statusSignal((*reinterpret_cast< plotterStatus(*)>(_a[1]))); break;
        case 1: _t->disconnectedSignal(); break;
        case 2: _t->messageSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->portError((*reinterpret_cast< QSerialPort::SerialPortError(*)>(_a[1]))); break;
        case 4: _t->requestTime(); break;
        case 5: _t->dataReadyRead(); break;
        case 6: _t->waitTimeSlot(); break;
        case 7: _t->sendStopSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (usbConnection::*)(plotterStatus );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&usbConnection::statusSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (usbConnection::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&usbConnection::disconnectedSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (usbConnection::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&usbConnection::messageSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject usbConnection::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_usbConnection.offsetsAndSize,
    qt_meta_data_usbConnection,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_usbConnection_t
, QtPrivate::TypeAndForceComplete<usbConnection, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<plotterStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QSerialPort::SerialPortError, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *usbConnection::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *usbConnection::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_usbConnection.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int usbConnection::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void usbConnection::statusSignal(plotterStatus _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void usbConnection::disconnectedSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void usbConnection::messageSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
