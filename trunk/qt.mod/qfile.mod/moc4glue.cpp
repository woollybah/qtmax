/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Aug 9 21:58:42 2009
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
static const uint qt_meta_data_MaxQFile[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      10,    9,    9,    9, 0x08,
      33,   27,    9,    9, 0x08,
      56,    9,    9,    9, 0x08,
      80,    9,    9,    9, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQFile[] = {
    "MaxQFile\0\0onAboutToClose()\0bytes\0"
    "onBytesWritten(qint64)\0onReadChannelFinished()\0"
    "onReadyRead()\0"
};

const QMetaObject MaxQFile::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQFile,
      qt_meta_data_MaxQFile, 0 }
};

const QMetaObject *MaxQFile::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQFile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQFile))
        return static_cast<void*>(const_cast< MaxQFile*>(this));
    return MaxQObjectWrapper::qt_metacast(_clname);
}

int MaxQFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MaxQObjectWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onAboutToClose(); break;
        case 1: onBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: onReadChannelFinished(); break;
        case 3: onReadyRead(); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
