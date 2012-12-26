/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Dec 26 21:45:53 2012
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
static const uint qt_meta_data_MaxQClipboard[] = {

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
      20,   15,   14,   14, 0x08,
      48,   14,   14,   14, 0x08,
      64,   14,   14,   14, 0x08,
      86,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQClipboard[] = {
    "MaxQClipboard\0\0mode\0onChanged(QClipboard::Mode)\0"
    "onDataChanged()\0onFindBufferChanged()\0"
    "onSelectionChanged()\0"
};

void MaxQClipboard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQClipboard *_t = static_cast<MaxQClipboard *>(_o);
        switch (_id) {
        case 0: _t->onChanged((*reinterpret_cast< QClipboard::Mode(*)>(_a[1]))); break;
        case 1: _t->onDataChanged(); break;
        case 2: _t->onFindBufferChanged(); break;
        case 3: _t->onSelectionChanged(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQClipboard::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQClipboard::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQClipboard,
      qt_meta_data_MaxQClipboard, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQClipboard::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQClipboard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQClipboard::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQClipboard))
        return static_cast<void*>(const_cast< MaxQClipboard*>(this));
    return MaxQObjectWrapper::qt_metacast(_clname);
}

int MaxQClipboard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
