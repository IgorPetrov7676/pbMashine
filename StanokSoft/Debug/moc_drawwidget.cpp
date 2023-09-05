/****************************************************************************
** Meta object code from reading C++ file 'drawwidget.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../widgets/drawwidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawwidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_drawWidget_t {
    const uint offsetsAndSize[34];
    char stringdata0[197];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_drawWidget_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_drawWidget_t qt_meta_stringdata_drawWidget = {
    {
QT_MOC_LITERAL(0, 10), // "drawWidget"
QT_MOC_LITERAL(11, 14), // "openFileSignal"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 8), // "fileType"
QT_MOC_LITERAL(36, 13), // "messageSignal"
QT_MOC_LITERAL(50, 7), // "message"
QT_MOC_LITERAL(58, 19), // "startProgrammSignal"
QT_MOC_LITERAL(78, 12), // "QStringList*"
QT_MOC_LITERAL(91, 7), // "program"
QT_MOC_LITERAL(99, 12), // "openFileSlot"
QT_MOC_LITERAL(112, 15), // "forceChangeSlot"
QT_MOC_LITERAL(128, 5), // "value"
QT_MOC_LITERAL(134, 13), // "penChangeSlot"
QT_MOC_LITERAL(148, 11), // "zChangeSlot"
QT_MOC_LITERAL(160, 14), // "moveChangeSlot"
QT_MOC_LITERAL(175, 11), // "reParseSlot"
QT_MOC_LITERAL(187, 9) // "startSlot"

    },
    "drawWidget\0openFileSignal\0\0fileType\0"
    "messageSignal\0message\0startProgrammSignal\0"
    "QStringList*\0program\0openFileSlot\0"
    "forceChangeSlot\0value\0penChangeSlot\0"
    "zChangeSlot\0moveChangeSlot\0reParseSlot\0"
    "startSlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_drawWidget[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   74,    2, 0x06,    1 /* Public */,
       4,    1,   77,    2, 0x06,    3 /* Public */,
       6,    1,   80,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       9,    0,   83,    2, 0x09,    7 /* Protected */,
      10,    1,   84,    2, 0x09,    8 /* Protected */,
      12,    1,   87,    2, 0x09,   10 /* Protected */,
      13,    1,   90,    2, 0x09,   12 /* Protected */,
      14,    1,   93,    2, 0x09,   14 /* Protected */,
      15,    0,   96,    2, 0x09,   16 /* Protected */,
      16,    0,   97,    2, 0x09,   17 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, 0x80000000 | 7,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void, QMetaType::Double,   11,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void drawWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<drawWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->openFileSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->messageSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startProgrammSignal((*reinterpret_cast< QStringList*(*)>(_a[1]))); break;
        case 3: _t->openFileSlot(); break;
        case 4: _t->forceChangeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 5: _t->penChangeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 6: _t->zChangeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 7: _t->moveChangeSlot((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 8: _t->reParseSlot(); break;
        case 9: _t->startSlot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (drawWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&drawWidget::openFileSignal)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (drawWidget::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&drawWidget::messageSignal)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (drawWidget::*)(QStringList * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&drawWidget::startProgrammSignal)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject drawWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_drawWidget.offsetsAndSize,
    qt_meta_data_drawWidget,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_drawWidget_t
, QtPrivate::TypeAndForceComplete<drawWidget, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QStringList *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *drawWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *drawWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_drawWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int drawWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void drawWidget::openFileSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void drawWidget::messageSignal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void drawWidget::startProgrammSignal(QStringList * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
