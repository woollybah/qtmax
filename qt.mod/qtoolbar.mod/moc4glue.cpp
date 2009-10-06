/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 6. Oct 08:16:02 2009
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
static const uint qt_meta_data_MaxQToolBar[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      20,   13,   12,   12, 0x08,
      61,   48,   12,   12, 0x08,
     110,  101,   12,   12, 0x08,
     143,  135,   12,   12, 0x08,
     178,  166,   12,   12, 0x08,
     232,  216,   12,   12, 0x08,
     282,  278,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQToolBar[] = {
    "MaxQToolBar\0\0action\0onActionTriggered(QAction*)\0"
    "allowedAreas\0onAllowedAreasChanged(Qt::ToolBarAreas)\0"
    "iconSize\0onIconSizeChanged(QSize)\0"
    "movable\0onMovableChanged(bool)\0"
    "orientation\0onOrientationChanged(Qt::Orientation)\0"
    "toolButtonStyle\0"
    "onToolButtonStyleChanged(Qt::ToolButtonStyle)\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQToolBar::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQToolBar,
      qt_meta_data_MaxQToolBar, 0 }
};

const QMetaObject *MaxQToolBar::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQToolBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQToolBar))
        return static_cast<void*>(const_cast< MaxQToolBar*>(this));
    return MaxQObjectWrapper::qt_metacast(_clname);
}

int MaxQToolBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MaxQObjectWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onActionTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: onAllowedAreasChanged((*reinterpret_cast< Qt::ToolBarAreas(*)>(_a[1]))); break;
        case 2: onIconSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 3: onMovableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: onOrientationChanged((*reinterpret_cast< Qt::Orientation(*)>(_a[1]))); break;
        case 5: onToolButtonStyleChanged((*reinterpret_cast< Qt::ToolButtonStyle(*)>(_a[1]))); break;
        case 6: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
