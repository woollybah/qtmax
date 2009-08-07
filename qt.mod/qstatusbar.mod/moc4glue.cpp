/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Fri Aug 7 22:48:24 2009
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
static const uint qt_meta_data_MaxQStatusBar[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x08,
      53,   49,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQStatusBar[] = {
    "MaxQStatusBar\0\0message\0onMessageChanged(QString)\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQStatusBar::staticMetaObject = {
    { &QStatusBar::staticMetaObject, qt_meta_stringdata_MaxQStatusBar,
      qt_meta_data_MaxQStatusBar, 0 }
};

const QMetaObject *MaxQStatusBar::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQStatusBar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQStatusBar))
        return static_cast<void*>(const_cast< MaxQStatusBar*>(this));
    return QStatusBar::qt_metacast(_clname);
}

int MaxQStatusBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStatusBar::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onMessageChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
