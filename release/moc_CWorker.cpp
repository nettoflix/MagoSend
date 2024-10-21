/****************************************************************************
** Meta object code from reading C++ file 'CWorker.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../CWorker.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CWorker.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Worker_t {
    QByteArrayData data[24];
    char stringdata0[396];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Worker_t qt_meta_stringdata_Worker = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Worker"
QT_MOC_LITERAL(1, 7, 32), // "filesAlreadyPresentOnHostsResult"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 19), // "QList<CFilesOnHost>"
QT_MOC_LITERAL(4, 61, 15), // "listFilesOnHost"
QT_MOC_LITERAL(5, 77, 20), // "idAlreadyExistOnHost"
QT_MOC_LITERAL(6, 98, 5), // "value"
QT_MOC_LITERAL(7, 104, 19), // "queueDonePopulating"
QT_MOC_LITERAL(8, 124, 25), // "hostTableTextColorChanged"
QT_MOC_LITERAL(9, 150, 5), // "color"
QT_MOC_LITERAL(10, 156, 2), // "ip"
QT_MOC_LITERAL(11, 159, 8), // "loadMods"
QT_MOC_LITERAL(12, 168, 34), // "QList<QPair<QStringList,QStri..."
QT_MOC_LITERAL(13, 203, 11), // "modalidades"
QT_MOC_LITERAL(14, 215, 29), // "getFilesAlreadyPresentOnHosts"
QT_MOC_LITERAL(15, 245, 9), // "filePaths"
QT_MOC_LITERAL(16, 255, 22), // "checkIfIdExistsOnHosts"
QT_MOC_LITERAL(17, 278, 2), // "id"
QT_MOC_LITERAL(18, 281, 24), // "onPopulateQueueWithPaths"
QT_MOC_LITERAL(19, 306, 15), // "pathsToPopulate"
QT_MOC_LITERAL(20, 322, 25), // "onGetModalidadesFromHosts"
QT_MOC_LITERAL(21, 348, 5), // "hosts"
QT_MOC_LITERAL(22, 354, 28), // "onMarkHostAsRemovedFromTable"
QT_MOC_LITERAL(23, 383, 12) // "onRegisterIp"

    },
    "Worker\0filesAlreadyPresentOnHostsResult\0"
    "\0QList<CFilesOnHost>\0listFilesOnHost\0"
    "idAlreadyExistOnHost\0value\0"
    "queueDonePopulating\0hostTableTextColorChanged\0"
    "color\0ip\0loadMods\0QList<QPair<QStringList,QString> >\0"
    "modalidades\0getFilesAlreadyPresentOnHosts\0"
    "filePaths\0checkIfIdExistsOnHosts\0id\0"
    "onPopulateQueueWithPaths\0pathsToPopulate\0"
    "onGetModalidadesFromHosts\0hosts\0"
    "onMarkHostAsRemovedFromTable\0onRegisterIp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Worker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    2,   76,    2, 0x06 /* Public */,
      11,    1,   81,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   84,    2, 0x0a /* Public */,
      16,    2,   87,    2, 0x0a /* Public */,
      18,    2,   92,    2, 0x0a /* Public */,
      20,    1,   97,    2, 0x0a /* Public */,
      22,    1,  100,    2, 0x0a /* Public */,
      23,    1,  103,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QColor, QMetaType::QString,    9,   10,
    QMetaType::Void, 0x80000000 | 12,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,   15,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   10,   17,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString,   19,   10,
    QMetaType::Void, QMetaType::QStringList,   21,
    QMetaType::Void, QMetaType::QString,   10,
    QMetaType::Void, QMetaType::QString,   10,

       0        // eod
};

void Worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Worker *_t = static_cast<Worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->filesAlreadyPresentOnHostsResult((*reinterpret_cast< QList<CFilesOnHost>(*)>(_a[1]))); break;
        case 1: _t->idAlreadyExistOnHost((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->queueDonePopulating(); break;
        case 3: _t->hostTableTextColorChanged((*reinterpret_cast< QColor(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 4: _t->loadMods((*reinterpret_cast< QList<QPair<QStringList,QString> >(*)>(_a[1]))); break;
        case 5: _t->getFilesAlreadyPresentOnHosts((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 6: _t->checkIfIdExistsOnHosts((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 7: _t->onPopulateQueueWithPaths((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 8: _t->onGetModalidadesFromHosts((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 9: _t->onMarkHostAsRemovedFromTable((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->onRegisterIp((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Worker::*_t)(QList<CFilesOnHost> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::filesAlreadyPresentOnHostsResult)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Worker::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::idAlreadyExistOnHost)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Worker::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::queueDonePopulating)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Worker::*_t)(QColor , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::hostTableTextColorChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Worker::*_t)(QList<QPair<QStringList,QString>> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Worker::loadMods)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Worker::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Worker.data,
      qt_meta_data_Worker,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Worker.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Worker::filesAlreadyPresentOnHostsResult(QList<CFilesOnHost> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Worker::idAlreadyExistOnHost(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Worker::queueDonePopulating()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Worker::hostTableTextColorChanged(QColor _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Worker::loadMods(QList<QPair<QStringList,QString>> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
