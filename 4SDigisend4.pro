#-------------------------------------------------
#
# Project created by QtCreator 2024-04-05T10:05:43
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4SDigisend4
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

unix {
    DESTDIR = release
    OBJECTS_DIR = release
    MOC_DIR = release
    RCC_DIR = release

    #seta uma pasta de saida
    DESTDIR = "../Switcher/release"

    CONFIG += c++11

    #descomentar quando quiser gerar versai de release:
    #CONFIG -= debug
    #CONFIG += release

    #descomentar quando quiser gerar versai de debug:
    CONFIG += debug
    CONFIG -= release
    QMAKE_CXXFLAGS += -g

    #--------------------------------------------------------------------------
    #Faz a app carregar as .so de dentro da sua propria pasta "lib" onde roda a
    #aplicacao...
    #--------------------------------------------------------------------------
    #suppress the default RPATH if you wish
    QMAKE_LFLAGS_RPATH =
    #add your own with quoting gyrations to make sure $ORIGIN gets to the
    #command line unexpanded
    QMAKE_LFLAGS += "-Wl,-rpath,\'\$$ORIGIN/lib\'"
    #--------------------------------------------------------------------------
}
SOURCES += \
        main.cpp \
        mainwindow.cpp \
    CServiceUtils.cpp \
    CTransferMonitor.cpp \
    CHostControl.cpp \
    CXmlTransferFinished.cpp \
    Host.cpp \
    HostListDelegate.cpp \
    CustomStringListModel.cpp \
    CModalidadesForm.cpp \
    CCriarSessaoForm.cpp \
    VideoFileInfo.cpp \
    CEditarSessaoForm.cpp \
    IMagoDB.cpp \
    MagoDB.cpp \
    CBDQuery.cpp \
    CDateUtils.cpp \
    CHistoricoForm.cpp \
    CLoginForm.cpp \
    CCadastrarLoginForm.cpp \
    CWorker.cpp \
    EfficientItemDelegate.cpp \
    CustomSelectionModel.cpp \
    CWaitingSpinnerWidget.cpp \
    CSendOptionsForm.cpp \
    SpinnerThread.cpp \
    CMagoDBCommandsThread.cpp \
    CWaiter.cpp

HEADERS += \
        mainwindow.h \
    CServiceUtils.h \
    CTransferMonitor.h \
    CHostControl.h \
    CXmlTransferFinished.h \
    Host.h \
    HostListDelegate.h \
    CustomStringListModel.h \
    CModalidadesForm.h \
    CCriarSessaoForm.h \
    VideoFileInfo.h \
    CEditarSessaoForm.h \
    MagoDB.h \
    IMagoDB.h \
    CBDQuery.h \
    lindows.h \
    CDateUtils.h \
    CHistoricoForm.h \
    CLoginForm.h \
    CCadastrarLoginForm.h \
    CWorker.h \
    EfficientItemDelegate.h \
    CustomSelectionModel.h \
    CWaitingSpinnerWidget.h \
    CSendOptionsForm.h \
    SpinnerThread.h \
    CMagoDBCommandsThread.h \
    CWaiter.h

FORMS += \
        mainwindow.ui \
    CModalidadesForm.ui \
    CCriarSessaoForm.ui \
    CEditarSessaoForm.ui \
    CHistoricoForm.ui \
    CLoginForm.ui \
    CCadastrarLoginForm.ui \
    CSendOptionsForm.ui
#---------------------------4SMagoTransfer------------------------------
INCLUDEPATH += "../4SMagoTransferServer"
SOURCES += "../4SMagoTransferServer/CUploadServiceClient.cpp"
HEADERS += "../4SMagoTransferServer/CUploadServiceClient.h"
#-----------------------------------------------------------------------

##----------------------------XmlRPC------------------------------------
INCLUDEPATH += "../XmlRPC/XmlRpc"
SOURCES += "../XmlRPC/XmlRpc/*.cpp"
HEADERS += "../XmlRPC/XmlRpc/*.h"
win32 {
        DEFINES += _WINDOWS
}
#-----------------------------------------------------------------------
        #ffmpeg:
        LIBS +=  "../ffmpeg/ffmpeg/libavformat/libavformat.so"
        LIBS +=  "../ffmpeg/ffmpeg/libavutil/libavutil.so"


RESOURCES += \
    qrc.qrc


