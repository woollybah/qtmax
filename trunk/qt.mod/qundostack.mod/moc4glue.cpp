/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jan 30 18:37:38 2013
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
static const uint qt_meta_data_MaxQUndoStack[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      23,   15,   14,   14, 0x08,
      54,   46,   14,   14, 0x08,
      83,   77,   14,   14, 0x08,
     108,  104,   14,   14, 0x08,
     137,  128,   14,   14, 0x08,
     173,  164,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQUndoStack[] = {
    "MaxQUndoStack\0\0canRedo\0onCanRedoChanged(bool)\0"
    "canUndo\0onCanUndoChanged(bool)\0clean\0"
    "onCleanChanged(bool)\0idx\0onIndexChanged(int)\0"
    "redoText\0onRedoTextChanged(QString)\0"
    "undoText\0onUndoTextChanged(QString)\0"
};

void MaxQUndoStack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQUndoStack *_t = static_cast<MaxQUndoStack *>(_o);
        switch (_id) {
        case 0: _t->onCanRedoChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onCanUndoChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onCleanChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onRedoTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onUndoTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQUndoStack::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQUndoStack::staticMetaObject = {
    { &QUndoStack::staticMetaObject, qt_meta_stringdata_MaxQUndoStack,
      qt_meta_data_MaxQUndoStack, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQUndoStack::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQUndoStack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQUndoStack::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQUndoStack))
        return static_cast<void*>(const_cast< MaxQUndoStack*>(this));
    return QUndoStack::qt_metacast(_clname);
}

int MaxQUndoStack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QUndoStack::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
