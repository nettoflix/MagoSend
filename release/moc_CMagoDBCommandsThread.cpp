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
    QByteArrayData data[47];
    char stringdata0[728];
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
QT_MOC_LITERAL(11, 112, 7), // "usuario"
QT_MOC_LITERAL(12, 120, 21), // "queuedGetSessionNames"
QT_MOC_LITERAL(13, 142, 20), // "getIpListFromSession"
QT_MOC_LITERAL(14, 163, 7), // "session"
QT_MOC_LITERAL(15, 171, 22), // "getNameListFromSession"
QT_MOC_LITERAL(16, 194, 22), // "getModalidadesMagoSend"
QT_MOC_LITERAL(17, 217, 14), // "ModalidadeType"
QT_MOC_LITERAL(18, 232, 25), // "historicoShouldShowErrors"
QT_MOC_LITERAL(19, 258, 26), // "historicoShouldShowSuccess"
QT_MOC_LITERAL(20, 285, 18), // "updateStatusFilter"
QT_MOC_LITERAL(21, 304, 17), // "shouldShowSuccess"
QT_MOC_LITERAL(22, 322, 16), // "shouldShowErrors"
QT_MOC_LITERAL(23, 339, 25), // "getMagoSendHistoryEntries"
QT_MOC_LITERAL(24, 365, 22), // "QList<CDBHistoryEntry>"
QT_MOC_LITERAL(25, 388, 5), // "data2"
QT_MOC_LITERAL(26, 394, 23), // "clearModalidadeMagoSend"
QT_MOC_LITERAL(27, 418, 21), // "addModalidadeMagoSend"
QT_MOC_LITERAL(28, 440, 4), // "nome"
QT_MOC_LITERAL(29, 445, 4), // "desc"
QT_MOC_LITERAL(30, 450, 15), // "getSessionNames"
QT_MOC_LITERAL(31, 466, 17), // "doesSessionExists"
QT_MOC_LITERAL(32, 484, 19), // "updateSessionIpList"
QT_MOC_LITERAL(33, 504, 6), // "sessao"
QT_MOC_LITERAL(34, 511, 8), // "nameList"
QT_MOC_LITERAL(35, 520, 6), // "ipList"
QT_MOC_LITERAL(36, 527, 23), // "createRowOnSessionTable"
QT_MOC_LITERAL(37, 551, 13), // "removeSession"
QT_MOC_LITERAL(38, 565, 24), // "warningWhenOverwriteFile"
QT_MOC_LITERAL(39, 590, 22), // "warningWhenOverwriteId"
QT_MOC_LITERAL(40, 613, 17), // "updateSendOptions"
QT_MOC_LITERAL(41, 631, 19), // "shouldOverwriteFile"
QT_MOC_LITERAL(42, 651, 17), // "shouldOverwriteId"
QT_MOC_LITERAL(43, 669, 17), // "userAlreadyExists"
QT_MOC_LITERAL(44, 687, 15), // "getUserPassword"
QT_MOC_LITERAL(45, 703, 15), // "AddUserMagoSend"
QT_MOC_LITERAL(46, 719, 8) // "password"

    },
    "CMagoDBCommandsThreadWorker\0"
    "queuedAddHistoricoMagoSend\0\0numero\0"
    "titulo\0caminho\0modalidade\0duracao\0ip\0"
    "status\0data\0usuario\0queuedGetSessionNames\0"
    "getIpListFromSession\0session\0"
    "getNameListFromSession\0getModalidadesMagoSend\0"
    "ModalidadeType\0historicoShouldShowErrors\0"
    "historicoShouldShowSuccess\0"
    "updateStatusFilter\0shouldShowSuccess\0"
    "shouldShowErrors\0getMagoSendHistoryEntries\0"
    "QList<CDBHistoryEntry>\0data2\0"
    "clearModalidadeMagoSend\0addModalidadeMagoSend\0"
    "nome\0desc\0getSessionNames\0doesSessionExists\0"
    "updateSessionIpList\0sessao\0nameList\0"
    "ipList\0createRowOnSessionTable\0"
    "removeSession\0warningWhenOverwriteFile\0"
    "warningWhenOverwriteId\0updateSendOptions\0"
    "shouldOverwriteFile\0shouldOverwriteId\0"
    "userAlreadyExists\0getUserPassword\0"
    "AddUserMagoSend\0password"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CMagoDBCommandsThreadWorker[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      32,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    9,  174,    2, 0x0a /* Public */,
      12,    0,  193,    2, 0x0a /* Public */,
      13,    1,  194,    2, 0x0a /* Public */,
      15,    1,  197,    2, 0x0a /* Public */,
      16,    0,  200,    2, 0x0a /* Public */,
      18,    0,  201,    2, 0x0a /* Public */,
      19,    0,  202,    2, 0x0a /* Public */,
      20,    2,  203,    2, 0x0a /* Public */,
      23,   10,  208,    2, 0x0a /* Public */,
      23,    9,  229,    2, 0x2a /* Public | MethodCloned */,
      23,    8,  248,    2, 0x2a /* Public | MethodCloned */,
      23,    7,  265,    2, 0x2a /* Public | MethodCloned */,
      23,    6,  280,    2, 0x2a /* Public | MethodCloned */,
      23,    5,  293,    2, 0x2a /* Public | MethodCloned */,
      23,    4,  304,    2, 0x2a /* Public | MethodCloned */,
      23,    3,  313,    2, 0x2a /* Public | MethodCloned */,
      23,    2,  320,    2, 0x2a /* Public | MethodCloned */,
      23,    1,  325,    2, 0x2a /* Public | MethodCloned */,
      23,    0,  328,    2, 0x2a /* Public | MethodCloned */,
      26,    0,  329,    2, 0x0a /* Public */,
      27,    2,  330,    2, 0x0a /* Public */,
      30,    0,  335,    2, 0x0a /* Public */,
      31,    1,  336,    2, 0x0a /* Public */,
      32,    3,  339,    2, 0x0a /* Public */,
      36,    3,  346,    2, 0x0a /* Public */,
      37,    1,  353,    2, 0x0a /* Public */,
      38,    0,  356,    2, 0x0a /* Public */,
      39,    0,  357,    2, 0x0a /* Public */,
      40,    2,  358,    2, 0x0a /* Public */,
      43,    1,  363,    2, 0x0a /* Public */,
      44,    1,  366,    2, 0x0a /* Public */,
      45,    2,  369,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,    7,    8,    9,   10,   11,
    QMetaType::QStringList,
    QMetaType::QStringList, QMetaType::QString,   14,
    QMetaType::QStringList, QMetaType::QString,   14,
    0x80000000 | 17,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   21,   22,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QStringList, QMetaType::QString,   10,   25,    3,    4,    5,    6,    7,    8,    9,   11,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString, QMetaType::QStringList,   10,   25,    3,    4,    5,    6,    7,    8,    9,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int, QMetaType::QString,   10,   25,    3,    4,    5,    6,    7,    8,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Int,   10,   25,    3,    4,    5,    6,    7,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   25,    3,    4,    5,    6,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   25,    3,    4,    5,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   25,    3,    4,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString, QMetaType::QString,   10,   25,    3,
    0x80000000 | 24, QMetaType::QString, QMetaType::QString,   10,   25,
    0x80000000 | 24, QMetaType::QString,   10,
    0x80000000 | 24,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,   28,   29,
    QMetaType::QStringList,
    QMetaType::Bool, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   33,   34,   35,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString,   33,   34,   35,
    QMetaType::Void, QMetaType::QString,   33,
    QMetaType::Bool,
    QMetaType::Bool,
    QMetaType::Void, QMetaType::Bool, QMetaType::Bool,   41,   42,
    QMetaType::Bool, QMetaType::QString,   11,
    QMetaType::QString, QMetaType::QString,   11,
    QMetaType::Bool, QMetaType::QString, QMetaType::QByteArray,   11,   46,

       0        // eod
};

void CMagoDBCommandsThreadWorker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CMagoDBCommandsThreadWorker *_t = static_cast<CMagoDBCommandsThreadWorker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->queuedAddHistoricoMagoSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< QString(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QString(*)>(_a[9]))); break;
        case 1: { QStringList _r = _t->queuedGetSessionNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 2: { QStringList _r = _t->getIpListFromSession((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 3: { QStringList _r = _t->getNameListFromSession((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 4: { ModalidadeType _r = _t->getModalidadesMagoSend();
            if (_a[0]) *reinterpret_cast< ModalidadeType*>(_a[0]) = std::move(_r); }  break;
        case 5: { bool _r = _t->historicoShouldShowErrors();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 6: { bool _r = _t->historicoShouldShowSuccess();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 7: _t->updateStatusFilter((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 8: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QStringList(*)>(_a[9])),(*reinterpret_cast< QString(*)>(_a[10])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 9: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])),(*reinterpret_cast< QStringList(*)>(_a[9])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 10: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])),(*reinterpret_cast< QString(*)>(_a[8])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 11: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])),(*reinterpret_cast< int(*)>(_a[7])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 12: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])),(*reinterpret_cast< QString(*)>(_a[6])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 13: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])),(*reinterpret_cast< QString(*)>(_a[5])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 14: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 15: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 16: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 17: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 18: { QList<CDBHistoryEntry> _r = _t->getMagoSendHistoryEntries();
            if (_a[0]) *reinterpret_cast< QList<CDBHistoryEntry>*>(_a[0]) = std::move(_r); }  break;
        case 19: _t->clearModalidadeMagoSend(); break;
        case 20: _t->addModalidadeMagoSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 21: { QStringList _r = _t->getSessionNames();
            if (_a[0]) *reinterpret_cast< QStringList*>(_a[0]) = std::move(_r); }  break;
        case 22: { bool _r = _t->doesSessionExists((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 23: _t->updateSessionIpList((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 24: _t->createRowOnSessionTable((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 25: _t->removeSession((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 26: { bool _r = _t->warningWhenOverwriteFile();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 27: { bool _r = _t->warningWhenOverwriteId();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 28: _t->updateSendOptions((*reinterpret_cast< bool(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 29: { bool _r = _t->userAlreadyExists((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 30: { QString _r = _t->getUserPassword((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 31: { bool _r = _t->AddUserMagoSend((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
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
        if (_id < 32)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 32;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 32)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 32;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
