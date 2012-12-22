/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sat Dec 22 15:10:53 2012
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
static const uint qt_meta_data_MaxQDoubleSpinBox[] = {

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
      25,   19,   18,   18, 0x08,
      48,   18,   18,   18, 0x08,
      72,   68,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQDoubleSpinBox[] = {
    "MaxQDoubleSpinBox\0\0value\0"
    "onValueChanged(double)\0onEditingFinished()\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

void MaxQDoubleSpinBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQDoubleSpinBox *_t = static_cast<MaxQDoubleSpinBox *>(_o);
        switch (_id) {
        case 0: _t->onValueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 1: _t->onEditingFinished(); break;
        case 2: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQDoubleSpinBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQDoubleSpinBox::staticMetaObject = {
    { &QDoubleSpinBox::staticMetaObject, qt_meta_stringdata_MaxQDoubleSpinBox,
      qt_meta_data_MaxQDoubleSpinBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQDoubleSpinBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQDoubleSpinBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQDoubleSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQDoubleSpinBox))
        return static_cast<void*>(const_cast< MaxQDoubleSpinBox*>(this));
    return QDoubleSpinBox::qt_metacast(_clname);
}

int MaxQDoubleSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDoubleSpinBox::qt_metacall(_c, _id, _a);
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
