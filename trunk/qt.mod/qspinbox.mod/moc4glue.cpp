/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 4. Aug 13:13:31 2009
**      by: The Qt Meta Object Compiler version 61 (Qt 4.5.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "glue.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 61
#error "This file was generated using the moc from 4.5.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaxQSpinBox[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      15,   13,   12,   12, 0x08,
      35,   12,   12,   12, 0x08,
      59,   55,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQSpinBox[] = {
    "MaxQSpinBox\0\0i\0onValueChanged(int)\0"
    "onEditingFinished()\0pos\0"
    "customContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQSpinBox::staticMetaObject = {
    { &QSpinBox::staticMetaObject, qt_meta_stringdata_MaxQSpinBox,
      qt_meta_data_MaxQSpinBox, 0 }
};

const QMetaObject *MaxQSpinBox::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQSpinBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQSpinBox))
        return static_cast<void*>(const_cast< MaxQSpinBox*>(this));
    return QSpinBox::qt_metacast(_clname);
}

int MaxQSpinBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSpinBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onEditingFinished(); break;
        case 2: customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
