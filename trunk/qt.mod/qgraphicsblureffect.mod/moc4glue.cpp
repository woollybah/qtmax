/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Mon Dec 31 20:39:43 2012
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
static const uint qt_meta_data_MaxQGraphicsBlurEffect[] = {

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
      30,   24,   23,   23, 0x08,
      67,   60,   23,   23, 0x08,
     102,   94,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQGraphicsBlurEffect[] = {
    "MaxQGraphicsBlurEffect\0\0hints\0"
    "onBlurHintsChanged(BlurHints)\0radius\0"
    "onBlurRadiusChanged(qreal)\0enabled\0"
    "onEnabledChanged(bool)\0"
};

void MaxQGraphicsBlurEffect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQGraphicsBlurEffect *_t = static_cast<MaxQGraphicsBlurEffect *>(_o);
        switch (_id) {
        case 0: _t->onBlurHintsChanged((*reinterpret_cast< BlurHints(*)>(_a[1]))); break;
        case 1: _t->onBlurRadiusChanged((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 2: _t->onEnabledChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQGraphicsBlurEffect::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQGraphicsBlurEffect::staticMetaObject = {
    { &QGraphicsBlurEffect::staticMetaObject, qt_meta_stringdata_MaxQGraphicsBlurEffect,
      qt_meta_data_MaxQGraphicsBlurEffect, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQGraphicsBlurEffect::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQGraphicsBlurEffect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQGraphicsBlurEffect::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQGraphicsBlurEffect))
        return static_cast<void*>(const_cast< MaxQGraphicsBlurEffect*>(this));
    return QGraphicsBlurEffect::qt_metacast(_clname);
}

int MaxQGraphicsBlurEffect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsBlurEffect::qt_metacall(_c, _id, _a);
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
