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
static const uint qt_meta_data_MaxQDesktopWidget[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      26,   19,   18,   18, 0x08,
      41,   19,   18,   18, 0x08,
      68,   64,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQDesktopWidget[] = {
    "MaxQDesktopWidget\0\0screen\0onResized(int)\0"
    "onWorkAreaResized(int)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQDesktopWidget::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQDesktopWidget,
      qt_meta_data_MaxQDesktopWidget, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQDesktopWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQDesktopWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQDesktopWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQDesktopWidget))
        return static_cast<void*>(const_cast< MaxQDesktopWidget*>(this));
    return MaxQObjectWrapper::qt_metacast(_clname);
}

int MaxQDesktopWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MaxQObjectWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onResized((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onWorkAreaResized((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
