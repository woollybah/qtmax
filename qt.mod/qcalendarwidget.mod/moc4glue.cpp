/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Sep 20 12:17:50 2009
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
static const uint qt_meta_data_MaxQCalendarWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      25,   20,   19,   19, 0x08,
      44,   20,   19,   19, 0x08,
      72,   61,   19,   19, 0x08,
     102,   19,   19,   19, 0x08,
     127,  123,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQCalendarWidget[] = {
    "MaxQCalendarWidget\0\0date\0onActivated(QDate)\0"
    "onClicked(QDate)\0year,month\0"
    "onCurrentPageChanged(int,int)\0"
    "onSelectionChanged()\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQCalendarWidget::staticMetaObject = {
    { &QCalendarWidget::staticMetaObject, qt_meta_stringdata_MaxQCalendarWidget,
      qt_meta_data_MaxQCalendarWidget, 0 }
};

const QMetaObject *MaxQCalendarWidget::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQCalendarWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQCalendarWidget))
        return static_cast<void*>(const_cast< MaxQCalendarWidget*>(this));
    return QCalendarWidget::qt_metacast(_clname);
}

int MaxQCalendarWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QCalendarWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onActivated((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 1: onClicked((*reinterpret_cast< const QDate(*)>(_a[1]))); break;
        case 2: onCurrentPageChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: onSelectionChanged(); break;
        case 4: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
