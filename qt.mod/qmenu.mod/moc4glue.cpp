/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Feb 16 20:25:37 2011
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
static const uint qt_meta_data_MaxQMenu[] = {

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
      10,    9,    9,    9, 0x08,
      26,    9,    9,    9, 0x08,
      49,   42,    9,    9, 0x08,
      69,   42,    9,    9, 0x08,
      95,   91,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQMenu[] = {
    "MaxQMenu\0\0onAboutToHide()\0onAboutToShow()\0"
    "action\0onHovered(QAction*)\0"
    "onTriggered(QAction*)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQMenu::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQMenu,
      qt_meta_data_MaxQMenu, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQMenu::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQMenu))
        return static_cast<void*>(const_cast< MaxQMenu*>(this));
    return MaxQObjectWrapper::qt_metacast(_clname);
}

int MaxQMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MaxQObjectWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onAboutToHide(); break;
        case 1: onAboutToShow(); break;
        case 2: onHovered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 3: onTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 4: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
