/****************************************************************************
** Meta object code from reading C++ file 'server.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../HOST/server.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'server.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_myserver__server_t {
    QByteArrayData data[10];
    char stringdata0[133];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_myserver__server_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_myserver__server_t qt_meta_stringdata_myserver__server = {
    {
QT_MOC_LITERAL(0, 0, 16), // "myserver::server"
QT_MOC_LITERAL(1, 17, 9), // "recv_data"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "start"
QT_MOC_LITERAL(4, 34, 6), // "listen"
QT_MOC_LITERAL(5, 41, 16), // "acceptConnection"
QT_MOC_LITERAL(6, 58, 20), // "updateServerProgress"
QT_MOC_LITERAL(7, 79, 12), // "displayError"
QT_MOC_LITERAL(8, 92, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(9, 121, 11) // "socketError"

    },
    "myserver::server\0recv_data\0\0start\0"
    "listen\0acceptConnection\0updateServerProgress\0"
    "displayError\0QAbstractSocket::SocketError\0"
    "socketError"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_myserver__server[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   47,    2, 0x0a /* Public */,
       4,    1,   48,    2, 0x0a /* Public */,
       5,    0,   51,    2, 0x0a /* Public */,
       6,    0,   52,    2, 0x0a /* Public */,
       7,    1,   53,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::UShort,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void myserver::server::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        server *_t = static_cast<server *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->recv_data((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->start(); break;
        case 2: _t->listen((*reinterpret_cast< unsigned short(*)>(_a[1]))); break;
        case 3: _t->acceptConnection(); break;
        case 4: _t->updateServerProgress(); break;
        case 5: _t->displayError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (server::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&server::recv_data)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject myserver::server::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_myserver__server.data,
      qt_meta_data_myserver__server,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *myserver::server::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *myserver::server::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_myserver__server.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int myserver::server::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void myserver::server::recv_data(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
