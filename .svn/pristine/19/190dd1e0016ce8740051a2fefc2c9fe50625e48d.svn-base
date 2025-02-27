#ifndef CALLBACKWORKERTHREAD_H
#define CALLBACKWORKERTHREAD_H
#define SHARED_MEMORY_KEY "MyApp_CallbackQueue_SharedMemory"
#define SEMAPHORE_KEY "MyApp_CallbackQueue_Semaphore"
#define MUTEX_KEY "MyApp_CallbackQueue_Mutex"
#include "CHostControl.h"

#include <QObject>
#include <QThread>
#include <QQueue>
#include <QMutex>
#include <QWaitCondition>
#include <QSharedMemory>
#include <QSystemSemaphore>
#include <QBuffer>
#include <QDataStream>
#include <QtConcurrent>


class CallbackWorkerThread : public QThread
{
    Q_OBJECT
public:
    CallbackWorkerThread(CHostControl* hostControl);
    struct CallbackParameter
    {
        QString filename;
        QString ip;
    };
     QQueue<CallbackParameter> callbackQueue;
     QMutex queueMutex;
     QWaitCondition queueCondition;

    CHostControl* hostControl;
    QThread workerThread;
    void run() override;
    bool tellMagoThatEventWasSent(QString id, QString ip);

public slots:
   void processQueue();
   void enqueue(QString fileName, QString ip);
};

#endif // CALLBACKWORKERTHREAD_H
