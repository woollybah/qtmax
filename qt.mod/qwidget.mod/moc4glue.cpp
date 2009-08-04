/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Tue 4. Aug 13:13:32 2009
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
static const uint qt_meta_data_MaxQWidget[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

       0        // eod
};

static const char qt_meta_stringdata_MaxQWidget[] = {
    "MaxQWidget\0"
};

const QMetaObject MaxQWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaxQWidget,
      qt_meta_data_MaxQWidget, 0 }
};

const QMetaObject *MaxQWidget::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQWidget))
        return static_cast<void*>(const_cast< MaxQWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int MaxQWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    return _id;
}
static const uint qt_meta_data_MaxQAction[] = {

 // content:
       2,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   12, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      24,   11,   11,   11, 0x08,
      44,   36,   11,   11, 0x08,
      60,   36,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQAction[] = {
    "MaxQAction\0\0onChanged()\0onHovered()\0"
    "checked\0onToggled(bool)\0onTriggered(bool)\0"
};

const QMetaObject MaxQAction::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQAction,
      qt_meta_data_MaxQAction, 0 }
};

const QMetaObject *MaxQAction::metaObject() const
{
    return &staticMetaObject;
}

void *MaxQAction::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQAction))
        return static_cast<void*>(const_cast< MaxQAction*>(this));
    return MaxQObjectWrapper::qt_metacast(_clname);
}

int MaxQAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = MaxQObjectWrapper::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: onChanged(); break;
        case 1: onHovered(); break;
        case 2: onToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: onTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
