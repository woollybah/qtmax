/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Thu Dec 27 21:55:36 2012
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
static const uint qt_meta_data_MaxQButtonGroup[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   17,   16,   16, 0x08,
      58,   17,   16,   16, 0x08,
      92,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQButtonGroup[] = {
    "MaxQButtonGroup\0\0button\0"
    "onButtonClicked(QAbstractButton*)\0"
    "onButtonPressed(QAbstractButton*)\0"
    "onButtonReleased(QAbstractButton*)\0"
};

void MaxQButtonGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQButtonGroup *_t = static_cast<MaxQButtonGroup *>(_o);
        switch (_id) {
        case 0: _t->onButtonClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 1: _t->onButtonPressed((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: _t->onButtonReleased((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQButtonGroup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQButtonGroup::staticMetaObject = {
    { &QButtonGroup::staticMetaObject, qt_meta_stringdata_MaxQButtonGroup,
      qt_meta_data_MaxQButtonGroup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQButtonGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQButtonGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQButtonGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQButtonGroup))
        return static_cast<void*>(const_cast< MaxQButtonGroup*>(this));
    return QButtonGroup::qt_metacast(_clname);
}

int MaxQButtonGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QButtonGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
