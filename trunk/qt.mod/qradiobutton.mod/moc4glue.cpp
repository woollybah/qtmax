/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Aug 16 16:18:48 2009
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
static const uint qt_meta_data_MaxQRadioButton[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      25,   17,   16,   16, 0x08,
      41,   16,   16,   16, 0x08,
      53,   16,   16,   16, 0x08,
      66,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQRadioButton[] = {
    "MaxQRadioButton\0\0checked\0onClicked(bool)\0"
    "onPressed()\0onReleased()\0onToggled(bool)\0"
};

const QMetaObject MaxQRadioButton::staticMetaObject = {
    { &QRadioButton::staticMetaObject, qt_meta_stringdata_MaxQRadioButton,
      qt_meta_data_MaxQRadioButton, 0 }
};

const QMetaObject *MaxQRadioButton::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQRadioButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQRadioButton))
        return static_cast<void*>(const_cast< MaxQRadioButton*>(this));
    return QRadioButton::qt_metacast(_clname);
}

int MaxQRadioButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QRadioButton::qt_metacall(_c, _id, _a);
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
