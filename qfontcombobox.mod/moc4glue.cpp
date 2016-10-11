/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Wed Jan 30 21:46:05 2013
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
static const uint qt_meta_data_MaxQFontComboBox[] = {

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
      23,   18,   17,   17, 0x08,
      57,   51,   17,   17, 0x08,
      74,   51,   17,   17, 0x08,
     106,  101,   17,   17, 0x08,
     133,   51,   17,   17, 0x08,
     156,  152,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQFontComboBox[] = {
    "MaxQFontComboBox\0\0font\0"
    "onCurrentFontChanged(QFont)\0index\0"
    "onActivated(int)\0onCurrentIndexChanged(int)\0"
    "text\0onEditTextChanged(QString)\0"
    "onHighlighted(int)\0pos\0"
    "onCustomContextMenuRequested(QPoint)\0"
};

void MaxQFontComboBox::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQFontComboBox *_t = static_cast<MaxQFontComboBox *>(_o);
        switch (_id) {
        case 0: _t->onCurrentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 1: _t->onActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->onCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->onHighlighted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQFontComboBox::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQFontComboBox::staticMetaObject = {
    { &QFontComboBox::staticMetaObject, qt_meta_stringdata_MaxQFontComboBox,
      qt_meta_data_MaxQFontComboBox, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQFontComboBox::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQFontComboBox::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQFontComboBox::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQFontComboBox))
        return static_cast<void*>(const_cast< MaxQFontComboBox*>(this));
    return QFontComboBox::qt_metacast(_clname);
}

int MaxQFontComboBox::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QFontComboBox::qt_metacall(_c, _id, _a);
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
