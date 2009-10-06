/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 6. Oct 08:15:57 2009
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
static const uint qt_meta_data_MaxQFontComboBox[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

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

const QMetaObject MaxQFontComboBox::staticMetaObject = {
    { &QFontComboBox::staticMetaObject, qt_meta_stringdata_MaxQFontComboBox,
      qt_meta_data_MaxQFontComboBox, 0 }
};

const QMetaObject *MaxQFontComboBox::metaObject() const
{
    return &staticMetaObject;
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
        switch (_id) {
        case 0: onCurrentFontChanged((*reinterpret_cast< const QFont(*)>(_a[1]))); break;
        case 1: onActivated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: onCurrentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: onEditTextChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: onHighlighted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: onCustomContextMenuRequested((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
