/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sat Dec 29 12:35:03 2012
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
static const uint qt_meta_data_MaxQTextDocument[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      32,   18,   17,   17, 0x08,
      90,   57,   17,   17, 0x08,
     120,   17,   17,   17, 0x08,
     147,  140,   17,   17, 0x08,
     184,   17,   17,   17, 0x08,
     218,  210,   17,   17, 0x08,
     256,  246,   17,   17, 0x08,
     278,  246,   17,   17, 0x08,
     300,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQTextDocument[] = {
    "MaxQTextDocument\0\0newBlockCount\0"
    "onBlockCountChanged(int)\0"
    "position,charsRemoved,charsAdded\0"
    "onContentsChange(int,int,int)\0"
    "onContentsChanged()\0cursor\0"
    "onCursorPositionChanged(QTextCursor)\0"
    "onDocumentLayoutChanged()\0changed\0"
    "onModificationChanged(bool)\0available\0"
    "onRedoAvailable(bool)\0onUndoAvailable(bool)\0"
    "onUndoCommandAdded()\0"
};

void MaxQTextDocument::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQTextDocument *_t = static_cast<MaxQTextDocument *>(_o);
        switch (_id) {
        case 0: _t->onBlockCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onContentsChange((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 2: _t->onContentsChanged(); break;
        case 3: _t->onCursorPositionChanged((*reinterpret_cast< const QTextCursor(*)>(_a[1]))); break;
        case 4: _t->onDocumentLayoutChanged(); break;
        case 5: _t->onModificationChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->onRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->onUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onUndoCommandAdded(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQTextDocument::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQTextDocument::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQTextDocument,
      qt_meta_data_MaxQTextDocument, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQTextDocument::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQTextDocument::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQTextDocument::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQTextDocument))
        return static_cast<void*>(const_cast< MaxQTextDocument*>(this));
    return MaxQObjectWrapper::qt_metacast(_clname);
}

int MaxQTextDocument::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MaxQObjectWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
