/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Fri Jan 4 08:37:48 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.4)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "glue.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'glue.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.4. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MaxQDesktopWidget[] = {

 // content:
       6,       // revision
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

void MaxQDesktopWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQDesktopWidget *_t = static_cast<MaxQDesktopWidget *>(_o);
        switch (_id) {
        case 0: _t->onResized((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onWorkAreaResized((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQDesktopWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQDesktopWidget::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQDesktopWidget,
      qt_meta_data_MaxQDesktopWidget, &staticMetaObjectExtraData }
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
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
