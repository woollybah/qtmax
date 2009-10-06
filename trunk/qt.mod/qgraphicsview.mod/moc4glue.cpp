/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 6. Oct 08:15:58 2009
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
static const uint qt_meta_data_MaxQGraphicsView[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_MaxQGraphicsView[] = {
    "MaxQGraphicsView\0"
};

const QMetaObject MaxQGraphicsView::staticMetaObject = {
    { &QGraphicsView::staticMetaObject, qt_meta_stringdata_MaxQGraphicsView,
      qt_meta_data_MaxQGraphicsView, 0 }
};

const QMetaObject *MaxQGraphicsView::metaObject() const
{
    return &staticMetaObject;
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
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

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

const QMetaObject MaxQGraphicsScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_MaxQGraphicsScene,
      qt_meta_data_MaxQGraphicsScene, 0 }
};

const QMetaObject *MaxQGraphicsScene::metaObject() const
{
    return &staticMetaObject;
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
        switch (_id) {
        case 0: onChanged((*reinterpret_cast< const QList<QRectF>(*)>(_a[1]))); break;
        case 1: onSceneRectChanged((*reinterpret_cast< const QRectF(*)>(_a[1]))); break;
        case 2: onSelectionChanged(); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
