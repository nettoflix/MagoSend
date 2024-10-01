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
    QByteArrayData data[29];
    char stringdata0[435];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CMagoDBCommandsThreadWorker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CMagoDBCommandsThreadWorker_t qt_meta_stringdata_CMagoDBCommandsThreadWorker = {
    {
QT_MOC_LITERAL(0, 0, 27), // "CMagoDBCommandsThreadWorker"
QT_MOC_LITERAL(1, 28, 18), // "queuedAddHistorico"
QT_MOC_LITERAL(2, 47, 0), // ""
QT_MOC_LITERAL(3, 48, 6), // "ticket"
QT_MOC_LITERAL(4, 55, 6), // "numero"
QT_MOC_LITERAL(5, 62, 6), // "titulo"
QT_MOC_LITERAL(6, 69, 11), // "duracaoreal"
QT_MOC_LITERAL(7, 81, 10), // "veiculacao"
QT_MOC_LITERAL(8, 92, 7), // "roteiro"
QT_MOC_LITERAL(9, 100, 4), // "data"
QT_MOC_LITERAL(10, 105, 7), // "entrada"
QT_MOC_LITERAL(11, 113, 5), // "saida"
QT_MOC_LITERAL(12, 119, 4), // "list"
QT_MOC_LITERAL(13, 124, 26), // "queuedChangeHistoricoSaida"
QT_MOC_LITERAL(14, 151, 36), // "queuedCreateEventByPathIfDose..."
QT_MOC_LITERAL(15, 188, 4), // "path"
QT_MOC_LITERAL(16, 193, 6), // "object"
QT_MOC_LITERAL(17, 200, 10), // "methodName"
QT_MOC_LITERAL(18, 211, 21), // "finishedInicilization"
QT_MOC_LITERAL(19, 233, 34), // "loadAllEventsOrderByWithValue..."
QT_MOC_LITERAL(20, 268, 5), // "field"
QT_MOC_LITERAL(21, 274, 5), // "value"
QT_MOC_LITERAL(22, 280, 7), // "orderBy"
QT_MOC_LITERAL(23, 288, 6), // "result"
QT_MOC_LITERAL(24, 295, 40), // "queuedLoadAllEventsOrderByWit..."
QT_MOC_LITERAL(25, 336, 50), // "queuedUpdateAllEventsWithNewV..."
QT_MOC_LITERAL(26, 387, 7), // "frameIn"
QT_MOC_LITERAL(27, 395, 8), // "frameOut"
QT_MOC_LITERAL(28, 404, 30) // "queuedSetAllEventsWithNullPath"

    },
    "CMagoDBCommandsThreadWorker\0"
    "queuedAddHistorico\0\0ticket\0numero\0"
    "titulo\0duracaoreal\0veiculacao\0roteiro\0"
    "data\0entrada\0saida\0list\0"
    "queuedChangeHistoricoSaida\0"
    "queuedCreateEventByPathIfDosentExist\0"
    "path\0object\0methodName\0finishedInicilization\0"
    "loadAllEventsOrderByWithValueEqual\0"
    "field\0value\0orderBy\0result\0"
    "queuedLoadAllEventsOrderByWithValueEqual\0"
    "queuedUpdateAllEventsWithNewVideoInformationByPath\0"
    "frameIn\0frameOut\0queuedSetAllEventsWithNullPath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMagoDBCommandsThreadWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,   10,   49,    2, 0x0a /* Public */,
      13,    3,   70,    2, 0x0a /* Public */,
      14,    4,   77,    2, 0x0a /* Public */,
      19,    4,   86,    2, 0x0a /* Public */,
      24,    5,   95,    2, 0x0a /* Public */,
      25,    3,  106,    2, 0x0a /* Public */,
      28,    1,  113,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QStringList,    3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    8,   11,
    QMetaType::Void, QMetaType::QString, QMetaType::QObjectStar, QMetaType::QString, QMetaType::Int,   15,   16,   17,   18,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::VoidStar,   20,   21,   22,   23,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QObjectStar, QMetaType::QString,   20,   21,   22,   16,   17,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::Int,   15,   26,   27,
    QMetaType::Void, QMetaType::QString,   15,

       0        // eod
};

void CMagoDBCommandsThreadWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMagoDBCommandsThreadWorker *_t = static_cast<CMagoDBCommandsThreadWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->queuedAddHistorico((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9])),(*reinterpret_cast< QStringList(*)>(_a[10]))); break;
        case 1: _t->queuedChangeHistoricoSaida((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->queuedCreateEventByPathIfDosentExist((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QObject*(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 3: _t->loadAllEventsOrderByWithValueEqual((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< void*(*)>(_a[4]))); break;
        case 4: _t->queuedLoadAllEventsOrderByWithValueEqual((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QObject*(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5]))); break;
        case 5: _t->queuedUpdateAllEventsWithNewVideoInformationByPath((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 6: _t->queuedSetAllEventsWithNullPath((*reinterpret_cast< QString(*)>(_a[1]))); break;
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
