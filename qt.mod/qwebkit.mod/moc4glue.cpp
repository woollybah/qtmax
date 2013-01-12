/****************************************************************************
** Meta object code from reading C++ file 'glue.h'
**
** Created: Sat Jan 12 19:37:15 2013
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
static const uint qt_meta_data_MaxQWebView[] = {

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
      13,   12,   12,   12, 0x08,
      33,   29,   12,   12, 0x08,
      56,   53,   12,   12, 0x08,
      86,   77,   12,   12, 0x08,
     106,   12,   12,   12, 0x08,
     122,   12,   12,   12, 0x08,
     148,  143,   12,   12, 0x08,
     182,  176,   12,   12, 0x08,
     206,   29,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MaxQWebView[] = {
    "MaxQWebView\0\0onIconChanged()\0url\0"
    "onLinkClicked(QUrl)\0ok\0onLoadFinished(bool)\0"
    "progress\0onLoadProgress(int)\0"
    "onLoadStarted()\0onSelectionChanged()\0"
    "text\0onStatusBarMessage(QString)\0title\0"
    "onTitleChanged(QString)\0onUrlChanged(QUrl)\0"
};

void MaxQWebView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MaxQWebView *_t = static_cast<MaxQWebView *>(_o);
        switch (_id) {
        case 0: _t->onIconChanged(); break;
        case 1: _t->onLinkClicked((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        case 2: _t->onLoadFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->onLoadProgress((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->onLoadStarted(); break;
        case 5: _t->onSelectionChanged(); break;
        case 6: _t->onStatusBarMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->onTitleChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->onUrlChanged((*reinterpret_cast< const QUrl(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MaxQWebView::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MaxQWebView::staticMetaObject = {
    { &QWebView::staticMetaObject, qt_meta_stringdata_MaxQWebView,
      qt_meta_data_MaxQWebView, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MaxQWebView::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MaxQWebView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MaxQWebView::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MaxQWebView))
        return static_cast<void*>(const_cast< MaxQWebView*>(this));
    return QWebView::qt_metacast(_clname);
}

int MaxQWebView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWebView::qt_metacall(_c, _id, _a);
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
