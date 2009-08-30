/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sat Aug 29 18:23:45 2009
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
static const uint qt_meta_data_MaxQLabel[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      16,   11,   10,   10, 0x08,
      41,   11,   10,   10, 0x08,
      68,   64,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQLabel[] = {
    "MaxQLabel\0\0link\0onLinkActivated(QString)\0"
    "onLinkHovered(QString)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

const QMetaObject MaxQLabel::staticMetaObject = {
    { &QLabel::staticMetaObject, qt_meta_stringdata_MaxQLabel,
      qt_meta_data_MaxQLabel, 0 }
};

const QMetaObject *MaxQLabel::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQLabel))
        return static_cast<void*>(const_cast< MaxQLabel*>(this));
    return QLabel::qt_metacast(_clname);
}

int MaxQLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLabel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onLinkActivated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: onLinkHovered((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
