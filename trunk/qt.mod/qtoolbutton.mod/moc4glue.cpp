/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Dec 23 00:29:04 2012
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
static const uint qt_meta_data_MaxQToolButton[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   16,   15,   15, 0x08,
      53,   45,   15,   15, 0x08,
      69,   15,   15,   15, 0x08,
      81,   15,   15,   15, 0x08,
      94,   45,   15,   15, 0x08,
     114,  110,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQToolButton[] = {
    "MaxQToolButton\0\0action\0onTriggered(QAction*)\0"
    "checked\0onClicked(bool)\0onPressed()\0"
    "onReleased()\0onToggled(bool)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

void MaxQToolButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQToolButton *_t = static_cast<MaxQToolButton *>(_o);
        switch (_id) {
        case 0: _t->onTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->onClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onPressed(); break;
        case 3: _t->onReleased(); break;
        case 4: _t->onToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQToolButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQToolButton::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_MaxQToolButton,
      qt_meta_data_MaxQToolButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQToolButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQToolButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQToolButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQToolButton))
        return static_cast<void*>(const_cast< MaxQToolButton*>(this));
    return QToolButton::qt_metacast(_clname);
}

int MaxQToolButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
