/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jan 30 21:46:06 2013
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
static const uint qt_meta_data_MaxQListView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      22,   14,   13,   13, 0x08,
      60,   54,   13,   13, 0x08,
      85,   54,   13,   13, 0x08,
     108,   54,   13,   13, 0x08,
     137,   54,   13,   13, 0x08,
     160,   54,   13,   13, 0x08,
     183,   13,   13,   13, 0x08,
     207,  203,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQListView[] = {
    "MaxQListView\0\0indexes\0"
    "onIndexesMoved(QModelIndexList)\0index\0"
    "onActivated(QModelIndex)\0"
    "onClicked(QModelIndex)\0"
    "onDoubleClicked(QModelIndex)\0"
    "onEntered(QModelIndex)\0onPressed(QModelIndex)\0"
    "onViewportEntered()\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

void MaxQListView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQListView *_t = static_cast<MaxQListView *>(_o);
        switch (_id) {
        case 0: _t->onIndexesMoved((*reinterpret_cast< const QModelIndexList(*)>(_a[1]))); break;
        case 1: _t->onActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 2: _t->onClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 3: _t->onDoubleClicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->onEntered((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->onPressed((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 6: _t->onViewportEntered(); break;
        case 7: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQListView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQListView::staticMetaObject = {
    { &QListView::staticMetaObject, qt_meta_stringdata_MaxQListView,
      qt_meta_data_MaxQListView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQListView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQListView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQListView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQListView))
        return static_cast<void*>(const_cast< MaxQListView*>(this));
    return QListView::qt_metacast(_clname);
}

int MaxQListView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
