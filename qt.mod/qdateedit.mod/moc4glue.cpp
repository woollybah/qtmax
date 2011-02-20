/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Feb 20 00:05:56 2011
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
static const uint qt_meta_data_MaxQDateEdit[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   14,   13,   13, 0x08,
      49,   40,   13,   13, 0x08,
      83,   78,   13,   13, 0x08,
     104,   13,   13,   13, 0x08,
     128,  124,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQDateEdit[] = {
    "MaxQDateEdit\0\0date\0onDateChanged(QDate)\0"
    "datetime\0onDateTimeChanged(QDateTime)\0"
    "time\0onTimeChanged(QTime)\0onEditingFinished()\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQDateEdit::staticMetaObject = {
    { &QDateEdit::staticMetaObject, qt_meta_stringdata_MaxQDateEdit,
      qt_meta_data_MaxQDateEdit, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQDateEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQDateEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQDateEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQDateEdit))
        return static_cast<void*>(const_cast< MaxQDateEdit*>(this));
    return QDateEdit::qt_metacast(_clname);
}

int MaxQDateEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDateEdit::qt_metacall(_c, _id, _a);
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
