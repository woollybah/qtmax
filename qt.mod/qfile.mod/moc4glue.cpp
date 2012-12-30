/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sun Dec 30 17:31:51 2012
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
static const uint qt_meta_data_MaxQFile[] = {

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

void MaxQFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQFile *_t = static_cast<MaxQFile *>(_o);
        switch (_id) {
        case 0: _t->onAboutToClose(); break;
        case 1: _t->onBytesWritten((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->onReadChannelFinished(); break;
        case 3: _t->onReadyRead(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQFile::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQFile::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQFile,
      qt_meta_data_MaxQFile, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQFile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
