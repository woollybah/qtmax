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
static const uint qt_meta_data_MaxQStandardItemModel[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      40,   23,   22,   22, 0x08,
     159,   88,   22,   22, 0x08,
     220,   23,   22,   22, 0x08,
     267,   23,   22,   22, 0x08,
     306,   88,   22,   22, 0x08,
     358,   23,   22,   22, 0x08,
     416,  396,   22,   22, 0x08,
     478,  455,   22,   22, 0x08,
     523,   22,   22,   22, 0x08,
     550,   22,   22,   22, 0x08,
     568,   22,   22,   22, 0x08,
     592,   22,   22,   22, 0x08,
     607,   23,   22,   22, 0x08,
     720,  652,   22,   22, 0x08,
     778,   23,   22,   22, 0x08,
     822,   23,   22,   22, 0x08,
     858,  652,   22,   22, 0x08,
     907,   23,   22,   22, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQStandardItemModel[] = {
    "MaxQStandardItemModel\0\0parent,start,end\0"
    "onColumnsAboutToBeInserted(QModelIndex,int,int)\0"
    "sourceParent,sourceStart,sourceEnd,destinationParent,destinationColumn\0"
    "onColumnsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)\0"
    "onColumnsAboutToBeRemoved(QModelIndex,int,int)\0"
    "onColumnsInserted(QModelIndex,int,int)\0"
    "onColumnsMoved(QModelIndex,int,int,QModelIndex,int)\0"
    "onColumnsRemoved(QModelIndex,int,int)\0"
    "topLeft,bottomRight\0"
    "onDataChanged(QModelIndex,QModelIndex)\0"
    "orientation,first,last\0"
    "onHeaderDataChanged(Qt::Orientation,int,int)\0"
    "onLayoutAboutToBeChanged()\0onLayoutChanged()\0"
    "onModelAboutToBeReset()\0onModelReset()\0"
    "onRowsAboutToBeInserted(QModelIndex,int,int)\0"
    "sourceParent,sourceStart,sourceEnd,destinationParent,destinationRow\0"
    "onRowsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int)\0"
    "onRowsAboutToBeRemoved(QModelIndex,int,int)\0"
    "onRowsInserted(QModelIndex,int,int)\0"
    "onRowsMoved(QModelIndex,int,int,QModelIndex,int)\0"
    "onRowsRemoved(QModelIndex,int,int)\0"
};

void MaxQStandardItemModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQStandardItemModel *_t = static_cast<MaxQStandardItemModel *>(_o);
        switch (_id) {
        case 0: _t->onColumnsAboutToBeInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 1: _t->onColumnsAboutToBeMoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QModelIndex(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 2: _t->onColumnsAboutToBeRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 3: _t->onColumnsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->onColumnsMoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QModelIndex(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 5: _t->onColumnsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->onDataChanged((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< const QModelIndex(*)>(_a[2]))); break;
        case 7: _t->onHeaderDataChanged((*reinterpret_cast< Qt::Orientation(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 8: _t->onLayoutAboutToBeChanged(); break;
        case 9: _t->onLayoutChanged(); break;
        case 10: _t->onModelAboutToBeReset(); break;
        case 11: _t->onModelReset(); break;
        case 12: _t->onRowsAboutToBeInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 13: _t->onRowsAboutToBeMoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QModelIndex(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 14: _t->onRowsAboutToBeRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 15: _t->onRowsInserted((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 16: _t->onRowsMoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< const QModelIndex(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5]))); break;
        case 17: _t->onRowsRemoved((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQStandardItemModel::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQStandardItemModel::staticMetaObject = {
    { &QAbstractItemModel::staticMetaObject, qt_meta_stringdata_MaxQStandardItemModel,
      qt_meta_data_MaxQStandardItemModel, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQStandardItemModel::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQStandardItemModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQStandardItemModel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQStandardItemModel))
        return static_cast<void*>(const_cast< MaxQStandardItemModel*>(this));
    return QAbstractItemModel::qt_metacast(_clname);
}

int MaxQStandardItemModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
