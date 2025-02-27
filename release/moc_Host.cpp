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
    QByteArrayData data[13];
    char stringdata0[177];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Host_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Host_t qt_meta_stringdata_Host = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Host"
QT_MOC_LITERAL(1, 5, 13), // "updateBitrate"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "bitrate"
QT_MOC_LITERAL(4, 28, 2), // "ip"
QT_MOC_LITERAL(5, 31, 23), // "TellServiceToUploadFile"
QT_MOC_LITERAL(6, 55, 8), // "filename"
QT_MOC_LITERAL(7, 64, 18), // "isSendInSilentMode"
QT_MOC_LITERAL(8, 83, 19), // "adviseAfterEndingIP"
QT_MOC_LITERAL(9, 103, 27), // "adviseAfterEndingMethodName"
QT_MOC_LITERAL(10, 131, 21), // "adviseAfterEndingPort"
QT_MOC_LITERAL(11, 153, 15), // "targetSubFolder"
QT_MOC_LITERAL(12, 169, 7) // "timeout"

    },
    "Host\0updateBitrate\0\0bitrate\0ip\0"
    "TellServiceToUploadFile\0filename\0"
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
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    7,   59,    2, 0x0a /* Public */,
       5,    6,   74,    2, 0x2a /* Public | MethodCloned */,
       5,    5,   87,    2, 0x2a /* Public | MethodCloned */,
       5,    4,   98,    2, 0x2a /* Public | MethodCloned */,
       5,    3,  107,    2, 0x2a /* Public | MethodCloned */,
       5,    2,  114,    2, 0x2a /* Public | MethodCloned */,
       5,    1,  119,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, QMetaType::Float, QMetaType::QString,    3,    4,

 // slots: parameters
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::Double,    6,    7,    8,    9,   10,   11,   12,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,    6,    7,    8,    9,   10,   11,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString, QMetaType::Int,    6,    7,    8,    9,   10,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool, QMetaType::QString,    6,    7,    8,
    QMetaType::Bool, QMetaType::QString, QMetaType::Bool,    6,    7,
    QMetaType::Bool, QMetaType::QString,    6,

       0        // eod
};

void Host::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Host *_t = static_cast<Host *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBitrate((*reinterpret_cast< float(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< double(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 4: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: { bool _r = _t->TellServiceToUploadFile((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Host::*_t)(float , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Host::updateBitrate)) {
                *result = 0;
                return;
            }
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Host::updateBitrate(float _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
