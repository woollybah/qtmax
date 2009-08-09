/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Aug 9 16:12:48 2009
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
static const uint qt_meta_data_MaxQMainWindow[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      25,   16,   15,   15, 0x08,
      66,   50,   15,   15, 0x08,
     116,  112,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQMainWindow[] = {
    "MaxQMainWindow\0\0iconSize\0"
    "onIconSizeChanged(QSize)\0toolButtonStyle\0"
    "onToolButtonStyleChanged(Qt::ToolButtonStyle)\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MaxQMainWindow,
      qt_meta_data_MaxQMainWindow, 0 }
};

const QMetaObject *MaxQMainWindow::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQMainWindow))
        return static_cast<void*>(const_cast< MaxQMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MaxQMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onIconSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 1: onToolButtonStyleChanged((*reinterpret_cast< Qt::ToolButtonStyle(*)>(_a[1]))); break;
        case 2: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
