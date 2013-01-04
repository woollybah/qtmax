/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Fri Jan 4 08:37:49 2013
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
static const uint qt_meta_data_MaxQPlainTextEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      33,   19,   18,   18, 0x08,
      62,   58,   18,   18, 0x08,
      84,   18,   18,   18, 0x08,
     118,  110,   18,   18, 0x08,
     156,  146,   18,   18, 0x08,
     178,   18,   18,   18, 0x08,
     199,   18,   18,   18, 0x08,
     215,  146,   18,   18, 0x08,
     245,  237,   18,   18, 0x08,
     276,  272,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQPlainTextEdit[] = {
    "MaxQPlainTextEdit\0\0newBlockCount\0"
    "onBlockCountChanged(int)\0yes\0"
    "onCopyAvailable(bool)\0onCursorPositionChanged()\0"
    "changed\0onModificationChanged(bool)\0"
    "available\0onRedoAvailable(bool)\0"
    "onSelectionChanged()\0onTextChanged()\0"
    "onUndoAvailable(bool)\0rect,dy\0"
    "onUpdateRequest(QRect,int)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

void MaxQPlainTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQPlainTextEdit *_t = static_cast<MaxQPlainTextEdit *>(_o);
        switch (_id) {
        case 0: _t->onBlockCountChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->onCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->onCursorPositionChanged(); break;
        case 3: _t->onModificationChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->onSelectionChanged(); break;
        case 6: _t->onTextChanged(); break;
        case 7: _t->onUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->onUpdateRequest((*reinterpret_cast< const QRect(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQPlainTextEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQPlainTextEdit::staticMetaObject = {
    { &QPlainTextEdit::staticMetaObject, qt_meta_stringdata_MaxQPlainTextEdit,
      qt_meta_data_MaxQPlainTextEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQPlainTextEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQPlainTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQPlainTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQPlainTextEdit))
        return static_cast<void*>(const_cast< MaxQPlainTextEdit*>(this));
    return QPlainTextEdit::qt_metacast(_clname);
}

int MaxQPlainTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPlainTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
