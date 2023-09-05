/****************************************************************************
** Meta object code from reading C++ file 'directmanagewidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "widgets/directmanagewidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'directmanagewidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_directManageWidget_t {
    const uint offsetsAndSize[48];
    char stringdata0[300];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_directManageWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_directManageWidget_t qt_meta_stringdata_directManageWidget = {
    {
QT_MOC_LITERAL(0, 18), // "directManageWidget"
QT_MOC_LITERAL(19, 9), // "sendGCode"
QT_MOC_LITERAL(29, 0), // ""
QT_MOC_LITERAL(30, 5), // "gCode"
QT_MOC_LITERAL(36, 11), // "sendProgram"
QT_MOC_LITERAL(48, 12), // "QStringList*"
QT_MOC_LITERAL(61, 7), // "program"
QT_MOC_LITERAL(69, 11), // "errorSignal"
QT_MOC_LITERAL(81, 5), // "error"
QT_MOC_LITERAL(87, 8), // "sendStop"
QT_MOC_LITERAL(96, 11), // "moveRefSlot"
QT_MOC_LITERAL(108, 12), // "moveZeroSlot"
QT_MOC_LITERAL(121, 11), // "setZeroSlot"
QT_MOC_LITERAL(133, 12), // "GPushButton*"
QT_MOC_LITERAL(146, 6), // "button"
QT_MOC_LITERAL(153, 18), // "diableSteppersSlot"
QT_MOC_LITERAL(172, 13), // "sendGCodeSlot"
QT_MOC_LITERAL(186, 20), // "directMoveButtonSlot"
QT_MOC_LITERAL(207, 7), // "pointer"
QT_MOC_LITERAL(215, 18), // "rectMoveButtonSlot"
QT_MOC_LITERAL(234, 16), // "emegencyStopSlot"
QT_MOC_LITERAL(251, 13), // "setEndPosSlot"
QT_MOC_LITERAL(265, 16), // "drawWorkZoneSlot"
QT_MOC_LITERAL(282, 17) // "resetWorkZoneSlot"

    },
    "directManageWidget\0sendGCode\0\0gCode\0"
    "sendProgram\0QStringList*\0program\0"
    "errorSignal\0error\0sendStop\0moveRefSlot\0"
    "moveZeroSlot\0setZeroSlot\0GPushButton*\0"
    "button\0diableSteppersSlot\0sendGCodeSlot\0"
    "directMoveButtonSlot\0pointer\0"
    "rectMoveButtonSlot\0emegencyStopSlot\0"
    "setEndPosSlot\0drawWorkZoneSlot\0"
    "resetWorkZoneSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_directManageWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  104,    2, 0x06,    1 /* Public */,
       4,    1,  107,    2, 0x06,    3 /* Public */,
       7,    1,  110,    2, 0x06,    5 /* Public */,
       9,    0,  113,    2, 0x06,    7 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      10,    0,  114,    2, 0x09,    8 /* Protected */,
      11,    0,  115,    2, 0x09,    9 /* Protected */,
      12,    1,  116,    2, 0x09,   10 /* Protected */,
      15,    0,  119,    2, 0x09,   12 /* Protected */,
      16,    0,  120,    2, 0x09,   13 /* Protected */,
      17,    1,  121,    2, 0x09,   14 /* Protected */,
      19,    1,  124,    2, 0x09,   16 /* Protected */,
      20,    0,  127,    2, 0x09,   18 /* Protected */,
      21,    0,  128,    2, 0x09,   19 /* Protected */,
      22,    0,  129,    2, 0x09,   20 /* Protected */,
      23,    0,  130,    2, 0x09,   21 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   18,
    QMetaType::Void, 0x80000000 | 13,   18,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void directManageWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<directManageWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->sendGCode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->sendProgram((*reinterpret_cast< QStringList*(*)>(_a[1]))); break;
        case 2: _t->errorSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->sendStop(); break;
        case 4: _t->moveRefSlot(); break;
        case 5: _t->moveZeroSlot(); break;
        case 6: _t->setZeroSlot((*reinterpret_cast< GPushButton*(*)>(_a[1]))); break;
        case 7: _t->diableSteppersSlot(); break;
        case 8: _t->sendGCodeSlot(); break;
        case 9: _t->directMoveButtonSlot((*reinterpret_cast< GPushButton*(*)>(_a[1]))); break;
        case 10: _t->rectMoveButtonSlot((*reinterpret_cast< GPushButton*(*)>(_a[1]))); break;
        case 11: _t->emegencyStopSlot(); break;
        case 12: _t->setEndPosSlot(); break;
        case 13: _t->drawWorkZoneSlot(); break;
        case 14: _t->resetWorkZoneSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< GPushButton* >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< GPushButton* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< GPushButton* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (directManageWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&directManageWidget::sendGCode)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (directManageWidget::*)(QStringList * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&directManageWidget::sendProgram)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (directManageWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&directManageWidget::errorSignal)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (directManageWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&directManageWidget::sendStop)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject directManageWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_directManageWidget.offsetsAndSize,
    qt_meta_data_directManageWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_directManageWidget_t
, QtPrivate::TypeAndForceComplete<directManageWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GPushButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GPushButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GPushButton *, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *directManageWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *directManageWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_directManageWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int directManageWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void directManageWidget::sendGCode(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void directManageWidget::sendProgram(QStringList * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void directManageWidget::errorSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void directManageWidget::sendStop()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
