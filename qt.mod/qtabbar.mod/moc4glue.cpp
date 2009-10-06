/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 6. Oct 08:16:01 2009
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
static const uint qt_meta_data_MaxQTabBar[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

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

const QMetaObject MaxQTabBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_MaxQTabBar,
      qt_meta_data_MaxQTabBar, 0 }
};

const QMetaObject *MaxQTabBar::metaObject() const
{
    return &staticMetaObject;
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
        switch (_id) {
        case 0: onCurrentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onTabCloseRequested((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: onTabMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
