/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jan 2 21:54:08 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "glue.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaxQDial[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   10,    9,    9, 0x08,
      48,   40,    9,    9, 0x08,
      78,   72,    9,    9, 0x08,
      97,    9,    9,    9, 0x08,
     115,    9,    9,    9, 0x08,
     134,   72,    9,    9, 0x08,
     158,  154,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQDial[] = {
    "MaxQDial\0\0action\0onActionTriggered(int)\0"
    "min,max\0onRangeChanged(int,int)\0value\0"
    "onSliderMoved(int)\0onSliderPressed()\0"
    "onSliderReleased()\0onValueChanged(int)\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

void MaxQDial::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQDial *_t = static_cast<MaxQDial *>(_o);
        switch (_id) {
        case 0: _t->onActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->onSliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onSliderPressed(); break;
        case 4: _t->onSliderReleased(); break;
        case 5: _t->onValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQDial::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQDial::staticMetaObject = {
    { &QDial::staticMetaObject, qt_meta_stringdata_MaxQDial,
      qt_meta_data_MaxQDial, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQDial::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQDial::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQDial::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQDial))
        return static_cast<void*>(const_cast< MaxQDial*>(this));
    return QDial::qt_metacast(_clname);
}

int MaxQDial::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDial::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
