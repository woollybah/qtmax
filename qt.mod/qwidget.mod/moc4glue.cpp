/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Fri Jan 4 08:37:50 2013
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
static const uint qt_meta_data_MaxQWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

static const char qt_meta_stringdata_MaxQWidget[] = {
    "MaxQWidget\0"
};

void MaxQWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObjectExtraData MaxQWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_MaxQWidget,
      qt_meta_data_MaxQWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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

void MaxQAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQAction *_t = static_cast<MaxQAction *>(_o);
        switch (_id) {
        case 0: _t->onChanged(); break;
        case 1: _t->onHovered(); break;
        case 2: _t->onToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onTriggered((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQAction::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQAction::staticMetaObject = {
    { &MaxQObjectWrapper::staticMetaObject, qt_meta_stringdata_MaxQAction,
      qt_meta_data_MaxQAction, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQAction::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
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
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
static const uint qt_meta_data_MaxQActionGroup[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      24,   17,   16,   16, 0x08,
      44,   17,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQActionGroup[] = {
    "MaxQActionGroup\0\0action\0onHovered(QAction*)\0"
    "onTriggered(QAction*)\0"
};

void MaxQActionGroup::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQActionGroup *_t = static_cast<MaxQActionGroup *>(_o);
        switch (_id) {
        case 0: _t->onHovered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        case 1: _t->onTriggered((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQActionGroup::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQActionGroup::staticMetaObject = {
    { &QActionGroup::staticMetaObject, qt_meta_stringdata_MaxQActionGroup,
      qt_meta_data_MaxQActionGroup, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQActionGroup::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQActionGroup::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQActionGroup::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQActionGroup))
        return static_cast<void*>(const_cast< MaxQActionGroup*>(this));
    return QActionGroup::qt_metacast(_clname);
}

int MaxQActionGroup::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QActionGroup::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
