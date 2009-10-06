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
static const uint qt_meta_data_MaxQDateTimeEdit[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      23,   18,   17,   17, 0x08,
      53,   44,   17,   17, 0x08,
      87,   82,   17,   17, 0x08,
     108,   17,   17,   17, 0x08,
     132,  128,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQDateTimeEdit[] = {
    "MaxQDateTimeEdit\0\0date\0onDateChanged(QDate)\0"
    "datetime\0onDateTimeChanged(QDateTime)\0"
    "time\0onTimeChanged(QTime)\0onEditingFinished()\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQDateTimeEdit::staticMetaObject = {
    { &QDateTimeEdit::staticMetaObject, qt_meta_stringdata_MaxQDateTimeEdit,
      qt_meta_data_MaxQDateTimeEdit, 0 }
};

const QMetaObject *MaxQDateTimeEdit::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQDateTimeEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQDateTimeEdit))
        return static_cast<void*>(const_cast< MaxQDateTimeEdit*>(this));
    return QDateTimeEdit::qt_metacast(_clname);
}

int MaxQDateTimeEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDateTimeEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onDateChanged((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 1: onDateTimeChanged((*reinterpret_cast< const QDateTime(*)>(_a[1]))); break;
        case 2: onTimeChanged((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 3: onEditingFinished(); break;
        case 4: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
