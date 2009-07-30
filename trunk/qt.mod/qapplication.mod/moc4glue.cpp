/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jul 29 22:35:09 2009
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
static const uint qt_meta_data_MaxQApplication[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      25,   17,   16,   16, 0x08,
      71,   63,   16,   16, 0x08,
     105,   16,   16,   16, 0x08,
     129,   16,   16,   16, 0x08,
     150,   17,   16,   16, 0x08,
     187,   16,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQApplication[] = {
    "MaxQApplication\0\0manager\0"
    "onCommitDataRequest(QSessionManager&)\0"
    "old,now\0onFocusChanged(QWidget*,QWidget*)\0"
    "onFontDatabaseChanged()\0onLastWindowClosed()\0"
    "onSaveStateRequest(QSessionManager&)\0"
    "onAboutToQuit()\0"
};

const QMetaObject MaxQApplication::staticMetaObject = {
    { &QApplication::staticMetaObject, qt_meta_stringdata_MaxQApplication,
      qt_meta_data_MaxQApplication, 0 }
};

const QMetaObject *MaxQApplication::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQApplication::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQApplication))
        return static_cast<void*>(const_cast< MaxQApplication*>(this));
    return QApplication::qt_metacast(_clname);
}

int MaxQApplication::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onCommitDataRequest((*reinterpret_cast< QSessionManager(*)>(_a[1]))); break;
        case 1: onFocusChanged((*reinterpret_cast< QWidget*(*)>(_a[1])),(*reinterpret_cast< QWidget*(*)>(_a[2]))); break;
        case 2: onFontDatabaseChanged(); break;
        case 3: onLastWindowClosed(); break;
        case 4: onSaveStateRequest((*reinterpret_cast< QSessionManager(*)>(_a[1]))); break;
        case 5: onAboutToQuit(); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
