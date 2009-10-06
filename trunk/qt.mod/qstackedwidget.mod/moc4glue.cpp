/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 6. Oct 08:16:01 2009
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
static const uint qt_meta_data_MaxQStackedWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      25,   19,   18,   18, 0x08,
      47,   19,   18,   18, 0x08,
      72,   68,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQStackedWidget[] = {
    "MaxQStackedWidget\0\0index\0onCurrentChanged(int)\0"
    "onWidgetRemoved(int)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQStackedWidget::staticMetaObject = {
    { &QStackedWidget::staticMetaObject, qt_meta_stringdata_MaxQStackedWidget,
      qt_meta_data_MaxQStackedWidget, 0 }
};

const QMetaObject *MaxQStackedWidget::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQStackedWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQStackedWidget))
        return static_cast<void*>(const_cast< MaxQStackedWidget*>(this));
    return QStackedWidget::qt_metacast(_clname);
}

int MaxQStackedWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStackedWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onWidgetRemoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
