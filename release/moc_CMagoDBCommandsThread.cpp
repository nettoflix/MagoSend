/****************************************************************************
** Meta object code from reading C++ file 'CMagoDBCommandsThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CMagoDBCommandsThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CMagoDBCommandsThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CMagoDBCommandsThread_t {
    QByteArrayData data[1];
    char stringdata0[22];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMagoDBCommandsThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMagoDBCommandsThread_t qt_meta_stringdata_CMagoDBCommandsThread = {
    {
QT_MOC_LITERAL(0, 0, 21) // "CMagoDBCommandsThread"

    },
    "CMagoDBCommandsThread"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMagoDBCommandsThread[] = {

 // content:
       7,       // revision
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

void CMagoDBCommandsThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CMagoDBCommandsThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_CMagoDBCommandsThread.data,
      qt_meta_data_CMagoDBCommandsThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMagoDBCommandsThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMagoDBCommandsThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMagoDBCommandsThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int CMagoDBCommandsThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_CMagoDBCommandsThreadWorker_t {
    QByteArrayData data[12];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMagoDBCommandsThreadWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMagoDBCommandsThreadWorker_t qt_meta_stringdata_CMagoDBCommandsThreadWorker = {
    {
QT_MOC_LITERAL(0, 0, 27), // "CMagoDBCommandsThreadWorker"
QT_MOC_LITERAL(1, 28, 26), // "queuedAddHistoricoMagoSend"
QT_MOC_LITERAL(2, 55, 0), // ""
QT_MOC_LITERAL(3, 56, 6), // "numero"
QT_MOC_LITERAL(4, 63, 6), // "titulo"
QT_MOC_LITERAL(5, 70, 7), // "caminho"
QT_MOC_LITERAL(6, 78, 10), // "modalidade"
QT_MOC_LITERAL(7, 89, 7), // "duracao"
QT_MOC_LITERAL(8, 97, 2), // "ip"
QT_MOC_LITERAL(9, 100, 6), // "status"
QT_MOC_LITERAL(10, 107, 4), // "data"
QT_MOC_LITERAL(11, 112, 7) // "usuario"

    },
    "CMagoDBCommandsThreadWorker\0"
    "queuedAddHistoricoMagoSend\0\0numero\0"
    "titulo\0caminho\0modalidade\0duracao\0ip\0"
    "status\0data\0usuario"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMagoDBCommandsThreadWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    9,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,   11,

       0        // eod
};

void CMagoDBCommandsThreadWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMagoDBCommandsThreadWorker *_t = static_cast<CMagoDBCommandsThreadWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->queuedAddHistoricoMagoSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9]))); break;
        default: ;
        }
    }
}

const QMetaObject CMagoDBCommandsThreadWorker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CMagoDBCommandsThreadWorker.data,
      qt_meta_data_CMagoDBCommandsThreadWorker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CMagoDBCommandsThreadWorker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CMagoDBCommandsThreadWorker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CMagoDBCommandsThreadWorker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int CMagoDBCommandsThreadWorker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
