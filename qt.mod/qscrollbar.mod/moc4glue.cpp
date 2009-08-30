/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Aug 30 22:56:33 2009
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
static const uint qt_meta_data_MaxQScrollBar[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      22,   15,   14,   14, 0x08,
      53,   45,   14,   14, 0x08,
      83,   77,   14,   14, 0x08,
     102,   14,   14,   14, 0x08,
     120,   14,   14,   14, 0x08,
     139,   77,   14,   14, 0x08,
     163,  159,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQScrollBar[] = {
    "MaxQScrollBar\0\0action\0onActionTriggered(int)\0"
    "min,max\0onRangeChanged(int,int)\0value\0"
    "onSliderMoved(int)\0onSliderPressed()\0"
    "onSliderReleased()\0onValueChanged(int)\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQScrollBar::staticMetaObject = {
    { &QScrollBar::staticMetaObject, qt_meta_stringdata_MaxQScrollBar,
      qt_meta_data_MaxQScrollBar, 0 }
};

const QMetaObject *MaxQScrollBar::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQScrollBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQScrollBar))
        return static_cast<void*>(const_cast< MaxQScrollBar*>(this));
    return QScrollBar::qt_metacast(_clname);
}

int MaxQScrollBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QScrollBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onActionTriggered((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: onRangeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: onSliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: onSliderPressed(); break;
        case 4: onSliderReleased(); break;
        case 5: onValueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
