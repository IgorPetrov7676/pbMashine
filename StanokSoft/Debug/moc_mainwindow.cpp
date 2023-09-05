/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[44];
    char stringdata0[221];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 11), // "connectSlot"
QT_MOC_LITERAL(23, 0), // ""
QT_MOC_LITERAL(24, 10), // "statusSlot"
QT_MOC_LITERAL(35, 13), // "plotterStatus"
QT_MOC_LITERAL(49, 6), // "status"
QT_MOC_LITERAL(56, 16), // "disconnectedSlot"
QT_MOC_LITERAL(73, 9), // "sendGCode"
QT_MOC_LITERAL(83, 5), // "gCode"
QT_MOC_LITERAL(89, 16), // "sendProgrammSlot"
QT_MOC_LITERAL(106, 12), // "QStringList*"
QT_MOC_LITERAL(119, 7), // "program"
QT_MOC_LITERAL(127, 8), // "openSlot"
QT_MOC_LITERAL(136, 8), // "fileType"
QT_MOC_LITERAL(145, 14), // "updateViewSlot"
QT_MOC_LITERAL(160, 9), // "errorSlot"
QT_MOC_LITERAL(170, 5), // "error"
QT_MOC_LITERAL(176, 5), // "title"
QT_MOC_LITERAL(182, 8), // "stopSlot"
QT_MOC_LITERAL(191, 9), // "pauseSlot"
QT_MOC_LITERAL(201, 11), // "messageSlot"
QT_MOC_LITERAL(213, 7) // "message"

    },
    "MainWindow\0connectSlot\0\0statusSlot\0"
    "plotterStatus\0status\0disconnectedSlot\0"
    "sendGCode\0gCode\0sendProgrammSlot\0"
    "QStringList*\0program\0openSlot\0fileType\0"
    "updateViewSlot\0errorSlot\0error\0title\0"
    "stopSlot\0pauseSlot\0messageSlot\0message"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x09,    1 /* Protected */,
       3,    1,   87,    2, 0x09,    2 /* Protected */,
       6,    0,   90,    2, 0x09,    4 /* Protected */,
       7,    1,   91,    2, 0x09,    5 /* Protected */,
       9,    1,   94,    2, 0x09,    7 /* Protected */,
      12,    1,   97,    2, 0x09,    9 /* Protected */,
      14,    0,  100,    2, 0x09,   11 /* Protected */,
      15,    2,  101,    2, 0x09,   12 /* Protected */,
      15,    1,  106,    2, 0x29,   15 /* Protected | MethodCloned */,
      18,    0,  109,    2, 0x09,   17 /* Protected */,
      19,    0,  110,    2, 0x09,   18 /* Protected */,
      20,    1,  111,    2, 0x09,   19 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   16,   17,
    QMetaType::Void, QMetaType::QString,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   21,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->connectSlot(); break;
        case 1: _t->statusSlot((*reinterpret_cast< plotterStatus(*)>(_a[1]))); break;
        case 2: _t->disconnectedSlot(); break;
        case 3: _t->sendGCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->sendProgrammSlot((*reinterpret_cast< QStringList*(*)>(_a[1]))); break;
        case 5: _t->openSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->updateViewSlot(); break;
        case 7: _t->errorSlot((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->errorSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->stopSlot(); break;
        case 10: _t->pauseSlot(); break;
        case 11: _t->messageSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<plotterStatus, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
