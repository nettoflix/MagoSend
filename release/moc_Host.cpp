/****************************************************************************
** Meta object code from reading C++ file 'Host.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Host.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Host.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Host_t {
    QByteArrayData data[10];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Host_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Host_t qt_meta_stringdata_Host = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Host"
QT_MOC_LITERAL(1, 5, 23), // "TellServiceToUploadFile"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "filename"
QT_MOC_LITERAL(4, 39, 18), // "isSendInSilentMode"
QT_MOC_LITERAL(5, 58, 19), // "adviseAfterEndingIP"
QT_MOC_LITERAL(6, 78, 27), // "adviseAfterEndingMethodName"
QT_MOC_LITERAL(7, 106, 21), // "adviseAfterEndingPort"
QT_MOC_LITERAL(8, 128, 15), // "targetSubFolder"
QT_MOC_LITERAL(9, 144, 7) // "timeout"

    },
    "Host\0TellServiceToUploadFile\0\0filename\0"
    "isSendInSilentMode\0adviseAfterEndingIP\0"
    "adviseAfterEndingMethodName\0"
    "adviseAfterEndingPort\0targetSubFolder\0"
    "timeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Host[] = {

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
       1,    7,   49,    2, 0x0a /* Public */,
       1,    6,   64,    2, 0x2a /* Public | MethodCloned */,
       1,    5,   77,    2, 0x2a /* Public | MethodCloned */,
       1,    4,   88,    2, 0x2a /* Public | MethodCloned */,
       1,    3,   97,    2, 0x2a /* Public | MethodCloned */,
       1,    2,  104,    2, 0x2a /* Public | MethodCloned */,
       1,    1,  109,    2, 0x2a /* Public | MethodCloned */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Float,    3,    4,    5,    6,    7,    8,    9,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    3,    4,    5,    6,    7,    8,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,    3,    4,    5,    6,    7,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    3,    4,    5,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool,    3,    4,
    QMetaType::Bool, QMetaType::QString,    3,

       0        // eod
};

void Host::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Host *_t = static_cast<Host *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< float(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 1: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject Host::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Host.data,
      qt_meta_data_Host,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Host::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Host::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Host.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Host::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
