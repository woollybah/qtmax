/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Dec 26 21:45:54 2012
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
static const uint qt_meta_data_MaxQTabBar[] = {

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
      18,   12,   11,   11, 0x08,
      40,   12,   11,   11, 0x08,
      73,   65,   11,   11, 0x08,
      97,   93,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQTabBar[] = {
    "MaxQTabBar\0\0index\0onCurrentChanged(int)\0"
    "onTabCloseRequested(int)\0from,to\0"
    "onTabMoved(int,int)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

void MaxQTabBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQTabBar *_t = static_cast<MaxQTabBar *>(_o);
        switch (_id) {
        case 0: _t->onCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onTabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onTabMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQTabBar::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQTabBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_MaxQTabBar,
      qt_meta_data_MaxQTabBar, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQTabBar::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQTabBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQTabBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQTabBar))
        return static_cast<void*>(const_cast< MaxQTabBar*>(this));
    return QTabBar::qt_metacast(_clname);
}

int MaxQTabBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
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
