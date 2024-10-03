/*
 * CMagoDBCommandsThread.cpp
 *
 *  Created on: 30 de nov de 2018
 *      Author: helmuth
 */

#include <QFileInfo>
#include <QVariant>
#include <QSqlQuery>

#include "CMagoDBCommandsThread.h"
#include <QDate>



CMagoDBCommandsThread* CMagoDBCommandsThread::commands = nullptr;

QMutex CMagoDBCommandsThread::mutex;
QStringList CMagoDBCommandsThread::connectionsNames;

CMagoDBCommandsThread::CMagoDBCommandsThread() :
	QThread()
{
	CMagoDBCommandsThread::commands = this;

	magoDB = nullptr;
	worker = nullptr;

	QThread::start();

	waiter.wait();

}

CMagoDBCommandsThread::~CMagoDBCommandsThread()
{
	exit();
	wait();

	CMagoDBCommandsThread::commands = nullptr;
}

void CMagoDBCommandsThread::run()
{
	//isso faz criar um DB com uma conexao com nome extra para nao
	//dar rolo com a conexao principal...

	qDebug("CMagoDBCommandsThread::run - NAO É MAGO REMOTO - ip será local");
	magoDB =  CreateDB("127.0.0.1", true);


	//magoDB =  CreateDB("127.0.0.1", true);

	worker = new CMagoDBCommandsThreadWorker(this);
	worker->moveToThread(this);
	waiter.wake(1);

	exec();

	delete worker;
	worker = nullptr;
}

void CMagoDBCommandsThread::queuedAddHistoricoMagoSend(QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QString status, QString data, QString usuario)
{

qDebug("CMagoDBCommandsThread::queuedAddHistorico - IN");
//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
QMetaObject::invokeMethod(worker, "queuedAddHistoricoMagoSend", Qt::QueuedConnection, Q_ARG(QString, numero), Q_ARG(QString, titulo), Q_ARG(QString, caminho), Q_ARG(QString, modalidade), Q_ARG(int, duracao), Q_ARG(QString, ip), Q_ARG(QString, status), Q_ARG(QString, data), Q_ARG(QString, usuario));
}

QStringList CMagoDBCommandsThread::queuedGetSessionNames()
{
	QStringList sessionNames;
	qDebug("CMagoDBCommandsThread::queuedGetSessionNames - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "queuedGetSessionNames", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QStringList, sessionNames));
	return sessionNames;
}

QStringList CMagoDBCommandsThread::getNameListFromSession(QString selectedSession)
{
	QStringList nameList;
	qDebug("CMagoDBCommandsThread::getNameListFromSession - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "getNameListFromSession", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QStringList, nameList), Q_ARG(QString, selectedSession));
	return nameList;
}

QVector<QPair<QString, QString> > CMagoDBCommandsThread::getModalidadesMagoSend()
{
	QVector<QPair<QString,QString>> modalidades;
	qDebug("CMagoDBCommandsThread::getModalidadesMagoSend - IN");
	QMetaObject::invokeMethod(worker, "getModalidadesMagoSend", Qt::BlockingQueuedConnection, Q_RETURN_ARG(ModalidadeType, modalidades));
	return modalidades;
}

QStringList CMagoDBCommandsThread::getIpListFromSession(QString selectedSession)
{
	QStringList ipList;
	qDebug("CMagoDBCommandsThread::getIpListFromSession - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "getIpListFromSession", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QStringList, ipList), Q_ARG(QString, selectedSession));
	return ipList;
}


CMagoDBCommandsThreadWorker::CMagoDBCommandsThreadWorker(CMagoDBCommandsThread* t) :
	QObject()
{
	thread = t;

	myOwnDatabaseConnection = thread->getRandomConnection();
	qDebug("CMagoDBCommandsThreadWorker dbconnectionname [%s]", myOwnDatabaseConnection.connectionName().toLatin1().data());
}

CMagoDBCommandsThreadWorker::~CMagoDBCommandsThreadWorker()
{
	myOwnDatabaseConnection.close();
}
//void CMagoDBCommandsThreadWorker::queuedAddHistorico(QString ticket, QString numero, QString titulo, int duracaoreal, QString veiculacao, int roteiro, QString data, QString entrada, QString saida, int posicaomesa, QString hPrevisto, QString crit1)
void CMagoDBCommandsThreadWorker::queuedAddHistoricoMagoSend(QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QString status, QString data, QString usuario)
{
//	qDebug() << "queuedAddHistoricoMagoSend worker: Current thread ID:" << QThread::currentThreadId();
	qDebug("CMagoDBCommandsThreadWorker::queuedAddHistorico - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->AddHistoricoMagoSend(numero.toLatin1().data(),titulo.toLatin1().data(),caminho.toLatin1().data(),modalidade.toLatin1().data(),duracao,ip.toLatin1().data(),status.toLatin1().data(),data.toLatin1().data(),usuario.toLatin1().data(),&connection);
//			histoId = thread->getMagoDB()->AddHistorico(
//						numero.toLatin1().data(),
//						titulo.toLatin1().data(),
//						duracaoreal,
//						veiculacao.toLatin1().data(),
//						roteiro,
//						data.toLatin1().data(),
//						entrada.toLatin1().data(),
//						saida.toLatin1().data(),
//						posicaomesa,
//						hPrevisto.toLatin1().data(),
//						crit1.toLatin1().data(),
//						&connection
//						);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::queuedAddHistorico - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);


}

QStringList CMagoDBCommandsThreadWorker::queuedGetSessionNames()
{
	qDebug("CMagoDBCommandsThreadWorker::queuedGetSessionNames - IN");
	QStringList sessionNames;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			sessionNames = thread->getMagoDB()->getSessionNames(&connection);
//			histoId = thread->getMagoDB()->AddHistorico(
//						numero.toLatin1().data(),
//						titulo.toLatin1().data(),
//						duracaoreal,
//						veiculacao.toLatin1().data(),
//						roteiro,
//						data.toLatin1().data(),
//						entrada.toLatin1().data(),
//						saida.toLatin1().data(),
//						posicaomesa,
//						hPrevisto.toLatin1().data(),
//						crit1.toLatin1().data(),
//						&connection
//						);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::queuedGetSessionNames - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return sessionNames;
}

QStringList CMagoDBCommandsThreadWorker::getIpListFromSession(QString session)
{
	qDebug("CMagoDBCommandsThreadWorker::getIpListFromSession - IN");
	QStringList ipList;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			ipList = thread->getMagoDB()->getIpListFromSession(session.toLatin1().data(),&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getIpListFromSession - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return ipList;
}

QStringList CMagoDBCommandsThreadWorker::getNameListFromSession(QString session)
{
	qDebug("CMagoDBCommandsThreadWorker::getNameListFromSession - IN");
	QStringList ipList;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			ipList = thread->getMagoDB()->getNameListFromSession(session.toLatin1().data(),&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getNameListFromSession - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return ipList;
}

ModalidadeType CMagoDBCommandsThreadWorker::getModalidadesMagoSend()
{
	ModalidadeType modalidades;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			modalidades = thread->getMagoDB()->getModalidadesMagoSend(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getModalidadesMagoSend - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return modalidades;
}





