/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sat Jan 12 19:37:14 2013
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
static const uint qt_meta_data_MaxQLineEdit[] = {

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
      28,   14,   13,   13, 0x08,
      61,   13,   13,   13, 0x08,
      81,   13,   13,   13, 0x08,
      99,   13,   13,   13, 0x08,
     125,  120,   13,   13, 0x08,
     148,  120,   13,   13, 0x08,
     174,  170,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQLineEdit[] = {
    "MaxQLineEdit\0\0oldPos,newPos\0"
    "onCursorPositionChanged(int,int)\0"
    "onEditingFinished()\0onReturnPressed()\0"
    "onSelectionChanged()\0text\0"
    "onTextChanged(QString)\0onTextEdited(QString)\0"
    "pos\0onCustomContextMenuRequested(QPoint)\0"
};

void MaxQLineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQLineEdit *_t = static_cast<MaxQLineEdit *>(_o);
        switch (_id) {
        case 0: _t->onCursorPositionChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->onEditingFinished(); break;
        case 2: _t->onReturnPressed(); break;
        case 3: _t->onSelectionChanged(); break;
        case 4: _t->onTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->onTextEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQLineEdit::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQLineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_MaxQLineEdit,
      qt_meta_data_MaxQLineEdit, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQLineEdit::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQLineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQLineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQLineEdit))
        return static_cast<void*>(const_cast< MaxQLineEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int MaxQLineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
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
