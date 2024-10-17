/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[42];
    char stringdata0[708];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 20), // "cancel_active_upload"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 9), // "hostIndex"
QT_MOC_LITERAL(4, 43, 13), // "triggerWorker"
QT_MOC_LITERAL(5, 57, 22), // "populateQueueWithPaths"
QT_MOC_LITERAL(6, 80, 19), // "filePathsToPopulate"
QT_MOC_LITERAL(7, 100, 2), // "ip"
QT_MOC_LITERAL(8, 103, 23), // "getModalidadesFromHosts"
QT_MOC_LITERAL(9, 127, 5), // "hosts"
QT_MOC_LITERAL(10, 133, 16), // "showErrorMessage"
QT_MOC_LITERAL(11, 150, 5), // "error"
QT_MOC_LITERAL(12, 156, 14), // "onItemSelected"
QT_MOC_LITERAL(13, 171, 14), // "QItemSelection"
QT_MOC_LITERAL(14, 186, 8), // "selected"
QT_MOC_LITERAL(15, 195, 10), // "deselected"
QT_MOC_LITERAL(16, 206, 21), // "addQueueToTableWidget"
QT_MOC_LITERAL(17, 228, 23), // "onFileSelectionBtnClick"
QT_MOC_LITERAL(18, 252, 21), // "onEnviarTodosBtnClick"
QT_MOC_LITERAL(19, 274, 17), // "onRemoverBtnClick"
QT_MOC_LITERAL(20, 292, 16), // "onNovoIPBtnClick"
QT_MOC_LITERAL(21, 309, 19), // "onExcluirIPBtnClick"
QT_MOC_LITERAL(22, 329, 21), // "onPausarTodosBtnClick"
QT_MOC_LITERAL(23, 351, 22), // "onCancelaAtualBtnClick"
QT_MOC_LITERAL(24, 374, 24), // "onAtualizarDadosBtnClick"
QT_MOC_LITERAL(25, 399, 11), // "onModAction"
QT_MOC_LITERAL(26, 411, 15), // "onSessionAction"
QT_MOC_LITERAL(27, 427, 17), // "onHistoricoAction"
QT_MOC_LITERAL(28, 445, 15), // "onOptionsAction"
QT_MOC_LITERAL(29, 461, 7), // "onTimer"
QT_MOC_LITERAL(30, 469, 29), // "on_btn_connectSession_clicked"
QT_MOC_LITERAL(31, 499, 18), // "showWarningMessage"
QT_MOC_LITERAL(32, 518, 7), // "message"
QT_MOC_LITERAL(33, 526, 16), // "pupulateGuiTable"
QT_MOC_LITERAL(34, 543, 19), // "QList<CFilesOnHost>"
QT_MOC_LITERAL(35, 563, 15), // "listFilesOnHost"
QT_MOC_LITERAL(36, 579, 21), // "onQueueDonePopulating"
QT_MOC_LITERAL(37, 601, 10), // "onLoadMods"
QT_MOC_LITERAL(38, 612, 34), // "QList<QPair<QStringList,QStri..."
QT_MOC_LITERAL(39, 647, 11), // "modalidades"
QT_MOC_LITERAL(40, 659, 29), // "onItemFromTableWidgetSelected"
QT_MOC_LITERAL(41, 689, 18) // "onShowErrorMessage"

    },
    "MainWindow\0cancel_active_upload\0\0"
    "hostIndex\0triggerWorker\0populateQueueWithPaths\0"
    "filePathsToPopulate\0ip\0getModalidadesFromHosts\0"
    "hosts\0showErrorMessage\0error\0"
    "onItemSelected\0QItemSelection\0selected\0"
    "deselected\0addQueueToTableWidget\0"
    "onFileSelectionBtnClick\0onEnviarTodosBtnClick\0"
    "onRemoverBtnClick\0onNovoIPBtnClick\0"
    "onExcluirIPBtnClick\0onPausarTodosBtnClick\0"
    "onCancelaAtualBtnClick\0onAtualizarDadosBtnClick\0"
    "onModAction\0onSessionAction\0"
    "onHistoricoAction\0onOptionsAction\0"
    "onTimer\0on_btn_connectSession_clicked\0"
    "showWarningMessage\0message\0pupulateGuiTable\0"
    "QList<CFilesOnHost>\0listFilesOnHost\0"
    "onQueueDonePopulating\0onLoadMods\0"
    "QList<QPair<QStringList,QString> >\0"
    "modalidades\0onItemFromTableWidgetSelected\0"
    "onShowErrorMessage"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  149,    2, 0x06 /* Public */,
       4,    0,  152,    2, 0x06 /* Public */,
       5,    2,  153,    2, 0x06 /* Public */,
       8,    1,  158,    2, 0x06 /* Public */,
      10,    1,  161,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,  164,    2, 0x08 /* Private */,
      16,    0,  169,    2, 0x08 /* Private */,
      17,    0,  170,    2, 0x08 /* Private */,
      18,    0,  171,    2, 0x08 /* Private */,
      19,    0,  172,    2, 0x08 /* Private */,
      20,    0,  173,    2, 0x08 /* Private */,
      21,    0,  174,    2, 0x08 /* Private */,
      22,    0,  175,    2, 0x08 /* Private */,
      23,    0,  176,    2, 0x08 /* Private */,
      24,    0,  177,    2, 0x08 /* Private */,
      25,    0,  178,    2, 0x08 /* Private */,
      26,    0,  179,    2, 0x08 /* Private */,
      27,    0,  180,    2, 0x08 /* Private */,
      28,    0,  181,    2, 0x08 /* Private */,
      29,    0,  182,    2, 0x08 /* Private */,
      30,    0,  183,    2, 0x08 /* Private */,
      31,    1,  184,    2, 0x08 /* Private */,
      33,    1,  187,    2, 0x08 /* Private */,
      36,    0,  190,    2, 0x08 /* Private */,
      37,    1,  191,    2, 0x08 /* Private */,
      40,    0,  194,    2, 0x08 /* Private */,
      41,    1,  195,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, QMetaType::QString,    6,    7,
    QMetaType::Void, QMetaType::QStringList,    9,
    QMetaType::Void, QMetaType::QString,   11,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 13,   14,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   32,
    QMetaType::Void, 0x80000000 | 34,   35,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 38,   39,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cancel_active_upload((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->triggerWorker(); break;
        case 2: _t->populateQueueWithPaths((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->getModalidadesFromHosts((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 4: _t->showErrorMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->onItemSelected((*reinterpret_cast< const QItemSelection(*)>(_a[1])),(*reinterpret_cast< const QItemSelection(*)>(_a[2]))); break;
        case 6: _t->addQueueToTableWidget(); break;
        case 7: _t->onFileSelectionBtnClick(); break;
        case 8: _t->onEnviarTodosBtnClick(); break;
        case 9: _t->onRemoverBtnClick(); break;
        case 10: _t->onNovoIPBtnClick(); break;
        case 11: _t->onExcluirIPBtnClick(); break;
        case 12: _t->onPausarTodosBtnClick(); break;
        case 13: _t->onCancelaAtualBtnClick(); break;
        case 14: _t->onAtualizarDadosBtnClick(); break;
        case 15: _t->onModAction(); break;
        case 16: _t->onSessionAction(); break;
        case 17: _t->onHistoricoAction(); break;
        case 18: _t->onOptionsAction(); break;
        case 19: _t->onTimer(); break;
        case 20: _t->on_btn_connectSession_clicked(); break;
        case 21: _t->showWarningMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 22: _t->pupulateGuiTable((*reinterpret_cast< QList<CFilesOnHost>(*)>(_a[1]))); break;
        case 23: _t->onQueueDonePopulating(); break;
        case 24: _t->onLoadMods((*reinterpret_cast< QList<QPair<QStringList,QString> >(*)>(_a[1]))); break;
        case 25: _t->onItemFromTableWidgetSelected(); break;
        case 26: _t->onShowErrorMessage((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QItemSelection >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainWindow::*_t)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::cancel_active_upload)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::triggerWorker)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QStringList , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::populateQueueWithPaths)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::getModalidadesFromHosts)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainWindow::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow::showErrorMessage)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::cancel_active_upload(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::triggerWorker()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainWindow::populateQueueWithPaths(QStringList _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainWindow::getModalidadesFromHosts(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainWindow::showErrorMessage(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
