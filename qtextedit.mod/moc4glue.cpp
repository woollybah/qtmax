/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jan 30 21:46:06 2013
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
static const uint qt_meta_data_MaxQTextEdit[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   14,   13,   13, 0x08,
      42,   40,   13,   13, 0x08,
      86,   13,   13,   13, 0x08,
     122,  112,   13,   13, 0x08,
     144,   13,   13,   13, 0x08,
     165,   13,   13,   13, 0x08,
     181,  112,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQTextEdit[] = {
    "MaxQTextEdit\0\0yes\0onCopyAvailable(bool)\0"
    "f\0onCurrentCharFormatChanged(QTextCharFormat)\0"
    "onCursorPositionChanged()\0available\0"
    "onRedoAvailable(bool)\0onSelectionChanged()\0"
    "onTextChanged()\0onUndoAvailable(bool)\0"
};

void MaxQTextEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQTextEdit *_t = static_cast<MaxQTextEdit *>(_o);
        switch (_id) {
        case 0: _t->onCopyAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onCurrentCharFormatChanged((*reinterpret_cast< const QTextCharFormat(*)>(_a[1]))); break;
        case 2: _t->onCursorPositionChanged(); break;
        case 3: _t->onRedoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->onSelectionChanged(); break;
        case 5: _t->onTextChanged(); break;
        case 6: _t->onUndoAvailable((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQTextEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQTextEdit::staticMetaObject = {
    { &QTextEdit::staticMetaObject, qt_meta_stringdata_MaxQTextEdit,
      qt_meta_data_MaxQTextEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQTextEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQTextEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQTextEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQTextEdit))
        return static_cast<void*>(const_cast< MaxQTextEdit*>(this));
    return QTextEdit::qt_metacast(_clname);
}

int MaxQTextEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTextEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
