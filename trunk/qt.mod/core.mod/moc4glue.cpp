/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Feb 20 00:05:55 2011
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "glue.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaxQObjectWrapper[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   19,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQObjectWrapper[] = {
    "MaxQObjectWrapper\0\0obj\0onDestroy(QObject*)\0"
};

const QMetaObject MaxQObjectWrapper::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MaxQObjectWrapper,
      qt_meta_data_MaxQObjectWrapper, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQObjectWrapper::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQObjectWrapper::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQObjectWrapper::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQObjectWrapper))
        return static_cast<void*>(const_cast< MaxQObjectWrapper*>(this));
    return QObject::qt_metacast(_clname);
}

int MaxQObjectWrapper::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onDestroy((*reinterpret_cast< QObject*(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 1;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
