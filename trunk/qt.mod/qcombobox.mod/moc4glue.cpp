/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Aug 2 17:56:05 2009
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
static const uint qt_meta_data_MaxQComboBox[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   14,   13,   13, 0x08,
      37,   14,   13,   13, 0x08,
      69,   64,   13,   13, 0x08,
      96,   14,   13,   13, 0x08,
     119,  115,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQComboBox[] = {
    "MaxQComboBox\0\0index\0onActivated(int)\0"
    "onCurrentIndexChanged(int)\0text\0"
    "onEditTextChanged(QString)\0"
    "onHighlighted(int)\0pos\0"
    "customContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQComboBox::staticMetaObject = {
    { &QComboBox::staticMetaObject, qt_meta_stringdata_MaxQComboBox,
      qt_meta_data_MaxQComboBox, 0 }
};

const QMetaObject *MaxQComboBox::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQComboBox))
        return static_cast<void*>(const_cast< MaxQComboBox*>(this));
    return QComboBox::qt_metacast(_clname);
}

int MaxQComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QComboBox::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: onEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: onHighlighted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: customContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
