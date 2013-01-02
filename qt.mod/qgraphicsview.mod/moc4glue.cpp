/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jan 2 21:54:09 2013
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
static const uint qt_meta_data_MaxQGraphicsView[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MaxQGraphicsView[] = {
    "MaxQGraphicsView\0"
};

void MaxQGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MaxQGraphicsView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQGraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_MaxQGraphicsView,
      qt_meta_data_MaxQGraphicsView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQGraphicsView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQGraphicsView))
        return static_cast<void*>(const_cast< MaxQGraphicsView*>(this));
    return QGraphicsView::qt_metacast(_clname);
}

int MaxQGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MaxQGraphicsScene[] = {

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
      56,   51,   18,   18, 0x08,
      83,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQGraphicsScene[] = {
    "MaxQGraphicsScene\0\0region\0"
    "onChanged(QList<QRectF>)\0rect\0"
    "onSceneRectChanged(QRectF)\0"
    "onSelectionChanged()\0"
};

void MaxQGraphicsScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQGraphicsScene *_t = static_cast<MaxQGraphicsScene *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< const QList<QRectF>(*)>(_a[1]))); break;
        case 1: _t->onSceneRectChanged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 2: _t->onSelectionChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQGraphicsScene::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_MaxQGraphicsScene,
      qt_meta_data_MaxQGraphicsScene, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQGraphicsScene::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQGraphicsScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQGraphicsScene::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQGraphicsScene))
        return static_cast<void*>(const_cast< MaxQGraphicsScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int MaxQGraphicsScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
