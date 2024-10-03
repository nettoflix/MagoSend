/*
 * CMagoDBCommandsThread.h
 *
 *  Created on: 30 de nov de 2018
 *      Author: helmuth
 */

#ifndef CMAGODBCOMMANDSTHREAD_H_
#define CMAGODBCOMMANDSTHREAD_H_

#include <QThread>
#include <QHash>
#include <QSqlDatabase>

#include <IMagoDB.h>

#include "CWaiter.h"
#include "MagoDB.h"

class CMagoDBCommandsThreadWorker;

class CMagoDBCommandsThread: public QThread
{
Q_OBJECT
public:

	static CMagoDBCommandsThread* commands;

	CMagoDBCommandsThread();
	virtual ~CMagoDBCommandsThread();

	inline CMagoDBCommandsThreadWorker* getWorker()
	{
		return worker;
	}
	void queuedAddHistoricoMagoSend(QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QString status, QString data, QString usuario);
	QStringList queuedGetSessionNames();
	QStringList getIpListFromSession(QString selectedSession);
	QStringList getNameListFromSession(QString selectedSession);
	QVector<QPair<QString,QString>> getModalidadesMagoSend();
	inline MagoDB* getMagoDB()
	{
		return (MagoDB*) magoDB;
	}


	inline QSqlDatabase getNewConnection(QString dbName)
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", dbName);
		db.setDatabaseName("magosend");
		db.setHostName("127.0.0.1");
		db.setPort(5432);
		db.setUserName("postgres");
		db.setPassword("admin");
		db.open();

		return db;
	}

	inline QSqlDatabase getRandomConnection()
	{
		//tranca/segura as outras threads que tb estao querendo um nome randomico e usam essa classe...
		QMutexLocker locker(&CMagoDBCommandsThread::mutex);

		//gera o nome randomico...
		srand(time(NULL));
		int  iSecret = rand() % 100000 + 1;
		QString dbName("RandomConnection" + QString::number((qint64)GetTickCount()) + QString::number(iSecret));

		//aguarda disponibilidade do nome randomico...
		while (CMagoDBCommandsThread::connectionsNames.contains(dbName))
		{
			qDebug("QSqlDatabase::getRandomConnection() - nome de conexao em uso[%s]. Aguardando oportunidade.", dbName.toLatin1().data());
			QThread::msleep(1);
			//gera novamente um novo nome randomico...
			iSecret = rand() % 100000 + 1;
			dbName = ("RandomConnection" + QString::number((qint64)GetTickCount()) + QString::number(iSecret));
		}

		//qDebug("getRandomConnection - Vai criar connection [%s]", dbName.toLatin1().data());

		//cria a nova conexao com banco utilizando esse nome randomico..
		QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", dbName);
		db.setDatabaseName("magosend");
		db.setHostName("127.0.0.1");
		//db.setHostName("127.0.0.1");
		db.setPort(5432);
		db.setUserName("postgres");
		db.setPassword("admin");
		db.open();

		return db;
	}

protected:
	CWaiter waiter;

	CMagoDBCommandsThreadWorker* worker;

	IMagoDB* magoDB;

	static QMutex mutex;

	static QStringList connectionsNames;

	void run();
};
using ModalidadeType = QVector<QPair<QString, QString>>;
class CMagoDBCommandsThreadWorker: public QObject
{
Q_OBJECT
public:
	QHash<QString, int> historyIds;

	CMagoDBCommandsThreadWorker(CMagoDBCommandsThread* thread);
	~CMagoDBCommandsThreadWorker();

protected:
	QSqlDatabase myOwnDatabaseConnection;

	CMagoDBCommandsThread* thread;

public slots:

	//void queuedAddHistorico(QString ticket, QString numero, QString titulo, int duracaoreal, QString veiculacao, int roteiro, QString data, QString entrada, QString saida, int posicaomesa, QString hPrevisto, QString crit1);
	void queuedAddHistoricoMagoSend(QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QString status, QString data, QString usuario);
	QStringList queuedGetSessionNames();
	QStringList getIpListFromSession(QString session);
	QStringList getNameListFromSession(QString session);
	ModalidadeType getModalidadesMagoSend();

};

#endif /* CMAGODBCOMMANDSTHREAD_H_ */
