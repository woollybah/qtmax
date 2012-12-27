/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Thu Dec 27 17:06:58 2012
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
static const uint qt_meta_data_MaxQRadioButton[] = {

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
      25,   17,   16,   16, 0x08,
      41,   16,   16,   16, 0x08,
      53,   16,   16,   16, 0x08,
      66,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQRadioButton[] = {
    "MaxQRadioButton\0\0checked\0onClicked(bool)\0"
    "onPressed()\0onReleased()\0onToggled(bool)\0"
};

void MaxQRadioButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQRadioButton *_t = static_cast<MaxQRadioButton *>(_o);
        switch (_id) {
        case 0: _t->onClicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->onPressed(); break;
        case 2: _t->onReleased(); break;
        case 3: _t->onToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQRadioButton::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQRadioButton::staticMetaObject = {
    { &QRadioButton::staticMetaObject, qt_meta_stringdata_MaxQRadioButton,
      qt_meta_data_MaxQRadioButton, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQRadioButton::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQRadioButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQRadioButton::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQRadioButton))
        return static_cast<void*>(const_cast< MaxQRadioButton*>(this));
    return QRadioButton::qt_metacast(_clname);
}

int MaxQRadioButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QRadioButton::qt_metacall(_c, _id, _a);
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
