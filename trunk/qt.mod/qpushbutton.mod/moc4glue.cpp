/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Thu 6. Aug 14:36:34 2009
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
static const uint qt_meta_data_MaxQPushButton[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      24,   16,   15,   15, 0x08,
      40,   15,   15,   15, 0x08,
      52,   15,   15,   15, 0x08,
      65,   16,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQPushButton[] = {
    "MaxQPushButton\0\0checked\0onClicked(bool)\0"
    "onPressed()\0onReleased()\0onToggled(bool)\0"
};

const QMetaObject MaxQPushButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_MaxQPushButton,
      qt_meta_data_MaxQPushButton, 0 }
};

const QMetaObject *MaxQPushButton::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQPushButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQPushButton))
        return static_cast<void*>(const_cast< MaxQPushButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int MaxQPushButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: onPressed(); break;
        case 2: onReleased(); break;
        case 3: onToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
