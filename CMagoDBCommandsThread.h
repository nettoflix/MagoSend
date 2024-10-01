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

#include <IMagoDB.h>


#include "CMagoDBEvent.h"
#include "CWaiter.h"
#include "CMainWindow.h"

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

	void queuedAddHistorico(QString ticket, QString numero, QString titulo, int duracaoreal, QString veiculacao, int roteiro, QDateTime data, QDateTime entrada, QDateTime saida, int posicaomesa, QString hPrevisto, QString crit1);


	void queuedChangeHistoricoSaida(QString ticket, int roteiro, QDateTime saida);

	/*!
	 * Cria um evento, baseado em um arquivo de video em disco, caso nao exista nenhum evento no banco
	 * que utilize esse mesmo arquivo em video. Se existir alum evento fazendo referencia a esse arquivo,
	 * entao o metodo sai fora. Assim que tudo e terminado, dando certo ou nao, o meotodo "methodName" do
	 * objeto "object" e chamado...
	 * ATENCAO: esse metodo NAO bloqueia a thread principal...
	 *
	 * @param path
	 */
	void queuedCreateEventByPathIfDosentExist(QString path, QObject* object, QString methodName, int finishedInicilization);

	/*!
	 * Faz uma pesquisa via thread PRINCIPAL na tabela de eventos, ordenada pelo campo "orderBy".
	 * ATENCAO: esse metodo bloqueia a thread principal...
	 * @param field
	 * @param value
	 * @param orderBy
	 * @return
	 */
	CMagoDBEventCollection loadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy);

	/*!
	 * Faz uma pesquisa via thread na tabela de eventos, ordenada pelo campo "orderBy", e assim que estiver pronta,
	 * envia os resultados chamando o o metodo "methodName" de "object"...
	 * ATENCAO: esse metodo NAO bloqueia a thread principal...
	 * @param field
	 * @param value
	 * @param orderBy
	 * @param object
	 * @param methodName
	 */
	void queuedLoadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy, QObject* object, QString methodName);

	void queuedLoadAllProgramsOrderByWithValueEqual(QString field, QString value, QString orderBy, QObject* object, QString methodName);

	/*!
	 * atualiaza todos os eventos do Banco de dados que tenham esse "Path" com novos frameIn e frameOut...
	 * ATENCAO: esse metodo NAO bloqueia a thread principal...
	 * @param path
	 * @param frameIn
	 * @param frameOut
	 */
	void queuedUpdateAllEventsWithNewVideoInformationByPath(QString path, int frameIn, int frameOut);

	void queuedSetAllEventsWithNullPath(QString path);

	inline IMagoDB* getMagoDB()
	{
		return magoDB;
	}


	inline QSqlDatabase getNewConnection(QString dbName)
	{
		QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL", dbName);
		db.setDatabaseName("magodb");
		if (CMainWindow::mainWindow->config.isMagoRemoto)
		{
			qDebug("getNewConnection - MAGO REMOTO - ip = [%s]", CMainWindow::mainWindow->config.magoServerIP.toLatin1().data());
			db.setHostName(CMainWindow::mainWindow->config.magoServerIP.toLatin1().data());
		}
		else
		{
			db.setHostName("127.0.0.1");
		}
		db.setPort(5432);
		db.setUserName("postgres");
		db.setPassword("admin");
		db.open();

		return db;
	}

//	inline void deleteRandomConnection(QSqlDatabase* database)
//	{
//		QString dbConnectionName;
//		{
//			dbConnectionName = database->connectionName();

//			database->close();
//		}
//		//QSqlDatabase::removeDatabase(database->databaseName());

//		QSqlDatabase::removeDatabase(dbConnectionName);
//	}

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
		db.setDatabaseName("magodb");
		if (CMainWindow::mainWindow->config.isMagoRemoto)
		{
			qDebug("getRandomConnection - MAGO REMOTO - ip = [%s]", CMainWindow::mainWindow->config.magoServerIP.toLatin1().data());
			db.setHostName(CMainWindow::mainWindow->config.magoServerIP.toLatin1().data());
		}
		else
		{
			db.setHostName("127.0.0.1");
		}
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
	void queuedAddHistorico(QString ticket, QString numero, QString titulo, int duracaoreal, QString veiculacao, int roteiro, QString data, QString entrada, QString saida, QStringList list);

	void queuedChangeHistoricoSaida(QString ticket, int roteiro, QString saida);

	void queuedCreateEventByPathIfDosentExist(QString path, QObject* object, QString methodName, int finishedInicilization);

	void loadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy, void* result);

	void queuedLoadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy, QObject* object, QString methodName);

	/*!
	 * atualiaza todos os eventos do Banco de dados que tenham esse "Path" com novos frameIn e frameOut...
	 * @param path
	 * @param frameIn
	 * @param frameOut
	 */
	void queuedUpdateAllEventsWithNewVideoInformationByPath(QString path, int frameIn, int frameOut);

	void queuedSetAllEventsWithNullPath(QString path);
};

#endif /* CMAGODBCOMMANDSTHREAD_H_ */
