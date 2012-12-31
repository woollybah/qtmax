/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Mon Dec 31 20:39:44 2012
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
static const uint qt_meta_data_MaxQItemSelectionModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      41,   24,   23,   23, 0x08,
      83,   24,   23,   23, 0x08,
     131,   24,   23,   23, 0x08,
     196,  176,   23,   23, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQItemSelectionModel[] = {
    "MaxQItemSelectionModel\0\0current,previous\0"
    "onCurrentChanged(QModelIndex,QModelIndex)\0"
    "onCurrentColumnChanged(QModelIndex,QModelIndex)\0"
    "onCurrentRowChanged(QModelIndex,QModelIndex)\0"
    "selected,deselected\0"
    "onSelectionChanged(QItemSelection,QItemSelection)\0"
};

void MaxQItemSelectionModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQItemSelectionModel *_t = static_cast<MaxQItemSelectionModel *>(_o);
        switch (_id) {
        case 0: _t->onCurrentChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 1: _t->onCurrentColumnChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 2: _t->onCurrentRowChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 3: _t->onSelectionChanged((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQItemSelectionModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQItemSelectionModel::staticMetaObject = {
    { &QItemSelectionModel::staticMetaObject, qt_meta_stringdata_MaxQItemSelectionModel,
      qt_meta_data_MaxQItemSelectionModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQItemSelectionModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQItemSelectionModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQItemSelectionModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQItemSelectionModel))
        return static_cast<void*>(const_cast< MaxQItemSelectionModel*>(this));
    return QItemSelectionModel::qt_metacast(_clname);
}

int MaxQItemSelectionModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QItemSelectionModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
