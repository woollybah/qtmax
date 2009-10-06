/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 6. Oct 08:15:57 2009
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
static const uint qt_meta_data_MaxQDialogButtonBox[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      21,   20,   20,   20, 0x08,
      41,   34,   20,   20, 0x08,
      69,   20,   20,   20, 0x08,
      87,   20,   20,   20, 0x08,
     104,  100,   20,   20, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQDialogButtonBox[] = {
    "MaxQDialogButtonBox\0\0onAccepted()\0"
    "button\0onClicked(QAbstractButton*)\0"
    "onHelpRequested()\0onRejected()\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQDialogButtonBox::staticMetaObject = {
    { &QDialogButtonBox::staticMetaObject, qt_meta_stringdata_MaxQDialogButtonBox,
      qt_meta_data_MaxQDialogButtonBox, 0 }
};

const QMetaObject *MaxQDialogButtonBox::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQDialogButtonBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQDialogButtonBox))
        return static_cast<void*>(const_cast< MaxQDialogButtonBox*>(this));
    return QDialogButtonBox::qt_metacast(_clname);
}

int MaxQDialogButtonBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialogButtonBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onAccepted(); break;
        case 1: onClicked((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 2: onHelpRequested(); break;
        case 3: onRejected(); break;
        case 4: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
