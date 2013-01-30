/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jan 30 18:37:36 2013
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
static const uint qt_meta_data_MaxQAbstractItemView[] = {

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
      28,   22,   21,   21, 0x08,
      53,   22,   21,   21, 0x08,
      76,   22,   21,   21, 0x08,
     105,   22,   21,   21, 0x08,
     128,   22,   21,   21, 0x08,
     151,   21,   21,   21, 0x08,
     175,  171,   21,   21, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQAbstractItemView[] = {
    "MaxQAbstractItemView\0\0index\0"
    "onActivated(QModelIndex)\0"
    "onClicked(QModelIndex)\0"
    "onDoubleClicked(QModelIndex)\0"
    "onEntered(QModelIndex)\0onPressed(QModelIndex)\0"
    "onViewportEntered()\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

void MaxQAbstractItemView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQAbstractItemView *_t = static_cast<MaxQAbstractItemView *>(_o);
        switch (_id) {
        case 0: _t->onActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 1: _t->onClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->onEntered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->onPressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->onViewportEntered(); break;
        case 6: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQAbstractItemView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQAbstractItemView::staticMetaObject = {
    { &QAbstractItemView::staticMetaObject, qt_meta_stringdata_MaxQAbstractItemView,
      qt_meta_data_MaxQAbstractItemView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQAbstractItemView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQAbstractItemView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQAbstractItemView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQAbstractItemView))
        return static_cast<void*>(const_cast< MaxQAbstractItemView*>(this));
    return QAbstractItemView::qt_metacast(_clname);
}

int MaxQAbstractItemView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemView::qt_metacall(_c, _id, _a);
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
