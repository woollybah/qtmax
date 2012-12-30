/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Dec 30 17:31:52 2012
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
static const uint qt_meta_data_MaxQToolBar[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

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

void MaxQToolBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQToolBar *_t = static_cast<MaxQToolBar *>(_o);
        switch (_id) {
        case 0: _t->onActionTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->onAllowedAreasChanged((*reinterpret_cast< Qt::ToolBarAreas(*)>(_a[1]))); break;
        case 2: _t->onIconSizeChanged((*reinterpret_cast< const QSize(*)>(_a[1]))); break;
        case 3: _t->onMovableChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onOrientationChanged((*reinterpret_cast< Qt::Orientation(*)>(_a[1]))); break;
        case 5: _t->onToolButtonStyleChanged((*reinterpret_cast< Qt::ToolButtonStyle(*)>(_a[1]))); break;
        case 6: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQToolBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQToolBar::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQToolBar,
      qt_meta_data_MaxQToolBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQToolBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQToolBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
