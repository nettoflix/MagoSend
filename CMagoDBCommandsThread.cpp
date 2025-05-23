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
	qRegisterMetaType<QSqlQuery*>("QList<CDBHistoryEntry>");
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
	QSqlDatabase connection = getRandomConnection();
	QString	dbConnectionName = connection.connectionName();
	magoDB->InitDB(&connection);
	QSqlDatabase::removeDatabase(dbConnectionName);


	//magoDB =  CreateDB("127.0.0.1", true);

	worker = new CMagoDBCommandsThreadWorker(this);
	worker->moveToThread(this);
	waiter.wake(1);

	exec();

	delete worker;
	worker = nullptr;
}
QList<CDBHistoryEntry> CMagoDBCommandsThread::getMagoSendHistoryEntries(QString data, QString data2, QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QStringList status, QString usuario)
{
	QList<CDBHistoryEntry> entries;
	qDebug("CMagoDBCommandsThread::getMagoSendHistoryEntries - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "getMagoSendHistoryEntries", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QList<CDBHistoryEntry>, entries), Q_ARG(QString, data),Q_ARG(QString, data2),Q_ARG(QString, numero), Q_ARG(QString, titulo), Q_ARG(QString, caminho), Q_ARG(QString, modalidade), Q_ARG(int, duracao), Q_ARG(QString, ip), Q_ARG(QStringList, status), Q_ARG(QString, usuario));
	return entries;
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

void CMagoDBCommandsThread::clearModalidadeMagoSend()
{
	qDebug("CMagoDBCommandsThread::clearModalidadeMagoSend - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "clearModalidadeMagoSend", Qt::BlockingQueuedConnection);
}

QStringList CMagoDBCommandsThread::getUsersFromHistorico()
{
	QStringList users;
	qDebug("CMagoDBCommandsThread::getUsersFromHistorico - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "getUsersFromHistorico", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QStringList, users));
	return users;
}

void CMagoDBCommandsThread::addModalidadeMagoSend(QString nome, QString desc)
{
	qDebug("CMagoDBCommandsThread::addModalidadeMagoSend - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "addModalidadeMagoSend", Qt::BlockingQueuedConnection, Q_ARG(QString, nome), Q_ARG(QString, desc));
}

QStringList CMagoDBCommandsThread::getSessionNames()
{
	qDebug("CMagoDBCommandsThread::getSessionNames - IN");
	QStringList sessionNames;
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "getSessionNames", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QStringList, sessionNames));
	return sessionNames;
}

bool CMagoDBCommandsThread::historicoShouldShowErrors()
{
	bool shouldShowErrors;
	qDebug("CMagoDBCommandsThread::historicoShouldShowErrors - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "historicoShouldShowErrors", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, shouldShowErrors));
	return shouldShowErrors;
}

bool CMagoDBCommandsThread::historicoShouldShowSuccess()
{
	bool shouldShowSuccess;
	qDebug("CMagoDBCommandsThread::historicoShouldShowErrors - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "historicoShouldShowSuccess", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, shouldShowSuccess));
	return shouldShowSuccess;
}

void CMagoDBCommandsThread::updateStatusFilter(bool shouldShowSuccess, bool shouldShowErrors)
{
	qDebug("CMagoDBCommandsThread::updateStatusFilter - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "updateStatusFilter", Qt::QueuedConnection, Q_ARG(bool, shouldShowSuccess), Q_ARG(bool, shouldShowErrors));
}

QVector<QPair<QString, QString> > CMagoDBCommandsThread::getModalidadesMagoSend()
{
	QVector<QPair<QString,QString>> modalidades;
	qDebug("CMagoDBCommandsThread::getModalidadesMagoSend - IN");
	QMetaObject::invokeMethod(worker, "getModalidadesMagoSend", Qt::BlockingQueuedConnection, Q_RETURN_ARG(ModalidadeType, modalidades));
	return modalidades;
}

bool CMagoDBCommandsThread::doesSessionExists(QString session)
{
	bool doesExist;
	qDebug("CMagoDBCommandsThread::doesSessionExists - IN");
	QMetaObject::invokeMethod(worker, "doesSessionExists", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, doesExist), Q_ARG(QString, session));
	return doesExist;
}

void CMagoDBCommandsThread::updateSessionIpList(QString sessao, QString ipList, QString nameList)
{
	qDebug("CMagoDBCommandsThread::updateSessionIpList - IN");
	QMetaObject::invokeMethod(worker, "updateSessionIpList", Qt::QueuedConnection, Q_ARG(QString, sessao),Q_ARG(QString, ipList), Q_ARG(QString, nameList));
}

void CMagoDBCommandsThread::createRowOnSessionTable(QString sessionName, QString ipList, QString nameList)
{
	qDebug("CMagoDBCommandsThread::createRowOnSessionTable - IN");
	QMetaObject::invokeMethod(worker, "createRowOnSessionTable", Qt::QueuedConnection, Q_ARG(QString, sessionName),Q_ARG(QString, ipList), Q_ARG(QString, nameList));
}

void CMagoDBCommandsThread::removeSession(QString session)
{
	qDebug("CMagoDBCommandsThread::removeSession - IN");
	QMetaObject::invokeMethod(worker, "removeSession", Qt::BlockingQueuedConnection, Q_ARG(QString, session));
}

bool CMagoDBCommandsThread::warningWhenOverwriteFile()
{
	bool shouldWarn;
	qDebug("CMagoDBCommandsThread::warningWhenOverwriteFile - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "warningWhenOverwriteFile", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, shouldWarn));
	return shouldWarn;
}
bool CMagoDBCommandsThread::warningWhenOverwriteId()
{
	bool shouldWarn;
	qDebug("CMagoDBCommandsThread::warningWhenOverwriteId - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "warningWhenOverwriteId", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, shouldWarn));
	return shouldWarn;
}

void CMagoDBCommandsThread::updateSendOptions(bool shouldOverwriteFile, bool shouldOverwriteId)
{
	qDebug("CMagoDBCommandsThread::updateSendOptions - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "updateSendOptions", Qt::QueuedConnection, Q_ARG(bool, shouldOverwriteFile), Q_ARG(bool, shouldOverwriteId));
}

bool CMagoDBCommandsThread::userAlreadyExists(QString usuario)
{
	bool exists;
	qDebug("CMagoDBCommandsThread::userAlreadyExists - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "userAlreadyExists", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, exists), Q_ARG(QString, usuario));
	return exists;
}

QString CMagoDBCommandsThread::getUserPassword(QString usuario)
{
	QString password;
	qDebug("CMagoDBCommandsThread::getUserPassword - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "getUserPassword", Qt::BlockingQueuedConnection, Q_RETURN_ARG(QString, password), Q_ARG(QString, usuario));
	return password;
}

bool CMagoDBCommandsThread::AddUserMagoSend(QString usuario, QByteArray password)
{
	bool ok;
	qDebug("CMagoDBCommandsThread::AddUserMagoSend - IN");
	//qDebug() << "queuedAddHistoricoMagoSend thread: Current thread ID:" << QThread::currentThreadId();
	QMetaObject::invokeMethod(worker, "AddUserMagoSend", Qt::BlockingQueuedConnection, Q_RETURN_ARG(bool, ok), Q_ARG(QString, usuario), Q_ARG(QByteArray, password));
	return ok;
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

			thread->getMagoDB()->AddHistoricoMagoSend(numero,titulo,caminho,modalidade,duracao,ip,status,data,usuario,&connection);
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
			ipList = thread->getMagoDB()->getIpListFromSession(session,&connection);
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
			ipList = thread->getMagoDB()->getNameListFromSession(session,&connection);
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

bool CMagoDBCommandsThreadWorker::historicoShouldShowErrors()
{
	bool shouldShowErrors;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			shouldShowErrors = thread->getMagoDB()->shouldShowErrors(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getModalidadesMagoSend - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return shouldShowErrors;
}

bool CMagoDBCommandsThreadWorker::historicoShouldShowSuccess()
{
	bool shouldShowSuccess;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			shouldShowSuccess = thread->getMagoDB()->shouldShowSuccess(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getModalidadesMagoSend - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return shouldShowSuccess;
}

void CMagoDBCommandsThreadWorker::updateStatusFilter(bool shouldShowSuccess, bool shouldShowErrors)
{
	qDebug("CMagoDBCommandsThreadWorker::updateStatusFilter - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->updateStatusFilter(shouldShowErrors,shouldShowSuccess,&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getModalidadesMagoSend - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
}

QList<CDBHistoryEntry> CMagoDBCommandsThreadWorker::getMagoSendHistoryEntries(QString data, QString data2, QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QStringList status, QString usuario)
{
	qDebug("CMagoDBCommandsThreadWorker::getMagoSendHistoryEntries - IN");

	  QByteArray dataByteArray = data.isEmpty() ? QByteArray() : data.toLatin1();
	  QByteArray data2ByteArray = data2.isEmpty() ? QByteArray() : data2.toLatin1();
	  QByteArray numeroByteArray = numero.isEmpty() ? QByteArray() : numero.toLatin1();
	  QByteArray tituloByteArray = titulo.isEmpty() ? QByteArray() : titulo.toLatin1();
	  QByteArray caminhoByteArray = caminho.isEmpty() ? QByteArray() : caminho.toLatin1();
	  QByteArray modalidadeByteArray = modalidade.isEmpty() ? QByteArray() : modalidade.toLatin1();
	  QByteArray ipByteArray = ip.isEmpty() ? QByteArray() : ip.toLatin1();
	  QByteArray usuarioByteArray = usuario.isEmpty() ? QByteArray() : usuario.toLatin1();

	  char *dataVal = dataByteArray.isEmpty() ? nullptr : dataByteArray.data();
	  char *data2Val = data2ByteArray.isEmpty() ? nullptr : data2ByteArray.data();
	  char *numeroVal = numeroByteArray.isEmpty() ? nullptr : numeroByteArray.data();
	  char *tituloVal = tituloByteArray.isEmpty() ? nullptr : tituloByteArray.data();
	  char *caminhoVal = caminhoByteArray.isEmpty() ? nullptr : caminhoByteArray.data();
	  char *modalidadeVal = modalidadeByteArray.isEmpty() ? nullptr : modalidadeByteArray.data();
	  char *ipVal = ipByteArray.isEmpty() ? nullptr : ipByteArray.data();
	  char *usuarioVal = usuarioByteArray.isEmpty() ? nullptr : usuarioByteArray.data();
			qDebug("data [%s]", dataVal);
			qDebug("data2 [%s]", data2Val);

	//													  dateOUT.isValid() ? dateOUT.toString("dd/MM/yyyy hh:mm:ss").toLatin1().data() : nullptr,
	//														  !numero.isEmpty() ? numero.toLatin1().data()  : nullptr,
	//														  !titulo.isEmpty() ? titulo.toLatin1().data()  : nullptr,
	//														  !caminho.isEmpty() ? caminho.toLatin1().data()  : nullptr,
	//														  !modalidade.isEmpty() ? modalidade.toLatin1().data()  : nullptr,
	//														  duracao,
	//														  !ip.isEmpty() ? ip.toLatin1().data()  : nullptr,
	//														  status,
	//														  !usuario.isEmpty() ? usuario.toLatin1().data() : nullptr
	//														  );
	QSqlQuery* query;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			query = static_cast<QSqlQuery*>(thread->getMagoDB()->getMagoSendHistoryEntries(dataVal, data2Val,numeroVal,tituloVal,caminhoVal,modalidadeVal,duracao, ipVal, status, usuarioVal, &connection));
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getMagoSendHistoryEntries - Erro exception");
		}

		connection.close();
	}
	QList<CDBHistoryEntry> entries;
	if (query != nullptr)
	{
		qDebug("CBDQuery::getEntries - 3");
		while (query->next())
		{
			qDebug("CBDQuery::getEntries - 4");
			CDBHistoryEntry entry;

			entry.numero = query->value("numero").toByteArray();
			entry.titulo = query->value("titulo").toByteArray();
			entry.caminho = query->value("caminho").toByteArray();
			entry.modalidade = query->value("modalidade").toByteArray();
			entry.ip = query->value("ip").toByteArray();
			entry.status = query->value("status").toByteArray();
			entry.data = query->value("data").toDateTime();
			entry.duracao = query->value("duracao").toInt();
			entry.usuario = query->value("usuario").toByteArray();
									qDebug("Entry:");
									qDebug("entry.data = %s", entry.data.toString("dd/MM/yyyy - hh:mm:ss.zzz").toLatin1().data());
									qDebug() << "entry.numero =" << entry.numero;
									qDebug() << "entry.titulo =" << entry.titulo;
									qDebug() << "entry.caminho =" << entry.caminho;
									qDebug() << "entry.modalidade =" << entry.modalidade;
									qDebug() << "entry.ip =" << entry.ip;
									qDebug() << "entry.duracao =" << entry.duracao;
									qDebug() << "entry.status =" << entry.status;
									qDebug() << "entry.usuario = " << entry.usuario;

			entries.push_back(entry);
		}
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return entries;
}

void CMagoDBCommandsThreadWorker::clearModalidadeMagoSend()
{
	qDebug("CMagoDBCommandsThreadWorker::clearModalidadeMagoSend - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->clearModalidadeMagoSend(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::clearModalidadeMagoSend - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
}

void CMagoDBCommandsThreadWorker::addModalidadeMagoSend(QString nome, QString desc)
{
	qDebug("CMagoDBCommandsThreadWorker::addModalidadeMagoSend - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->addModalidadeMagoSend(nome,desc,&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::addModalidadeMagoSend - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
}

QStringList CMagoDBCommandsThreadWorker::getSessionNames()
{
	qDebug("CMagoDBCommandsThreadWorker::getSessionNames - IN");
	QStringList sessionNames;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			sessionNames = thread->getMagoDB()->getSessionNames(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getSessionNames - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return sessionNames;
}

bool CMagoDBCommandsThreadWorker::doesSessionExists(QString session)
{
	qDebug("CMagoDBCommandsThreadWorker::doesSessionExists - IN");
	bool doesExist = false;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			doesExist = thread->getMagoDB()->doesSessionExists(session, &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::doesSessionExists - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return doesExist;
}

void CMagoDBCommandsThreadWorker::updateSessionIpList(QString sessao, QString nameList, QString ipList)
{
	qDebug("CMagoDBCommandsThreadWorker::updateSessionIpList - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->updateSessionIpList(sessao,nameList, ipList, &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::updateSessionIpList - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
}

void CMagoDBCommandsThreadWorker::createRowOnSessionTable(QString sessao, QString nameList, QString ipList)
{
	qDebug("CMagoDBCommandsThreadWorker::createRowOnSessionTable - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->createRowOnSessionTable(sessao,nameList, ipList, &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::createRowOnSessionTable - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
}

void CMagoDBCommandsThreadWorker::removeSession(QString sessao)
{
	qDebug("CMagoDBCommandsThreadWorker::removeSession - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->removeSession(sessao, &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::removeSession - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
}

bool CMagoDBCommandsThreadWorker::warningWhenOverwriteFile()
{
	qDebug("CMagoDBCommandsThreadWorker::warningWhenOverwriteFile - IN");
	bool shouldWarn = true;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			shouldWarn = thread->getMagoDB()->warningWhenOverwriteFile(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::warningWhenOverwriteFile - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return shouldWarn;
}

bool CMagoDBCommandsThreadWorker::warningWhenOverwriteId()
{
	qDebug("CMagoDBCommandsThreadWorker::warningWhenOverwriteId - IN");
	bool shouldWarn = true;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			shouldWarn = thread->getMagoDB()->warningWhenOverwriteId(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::warningWhenOverwriteId - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
	return shouldWarn;
}

void CMagoDBCommandsThreadWorker::updateSendOptions(bool shouldOverwriteFile, bool shouldOverwriteId)
{
	qDebug("CMagoDBCommandsThreadWorker::updateSendOptions - IN");
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			thread->getMagoDB()->updateSendOptions(shouldOverwriteFile, shouldOverwriteId, &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::updateSendOptions - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);
}

bool CMagoDBCommandsThreadWorker::userAlreadyExists(QString usuario)
{
	qDebug("CMagoDBCommandsThreadWorker::userAlreadyExists - IN");
	bool exists = false;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			exists = thread->getMagoDB()->userAlreadyExists(usuario.toLatin1().data(), &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::userAlreadyExists - Erro exception");
		}

		connection.close();
	}


	QSqlDatabase::removeDatabase(dbConnectionName);
	return exists;
}

QString CMagoDBCommandsThreadWorker::getUserPassword(QString usuario)
{
	qDebug("CMagoDBCommandsThreadWorker::getUserPassword - IN");
	QString password;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			password = thread->getMagoDB()->getUserPassword(usuario.toLatin1().data(), &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getUserPassword - Erro exception");
		}

		connection.close();
	}


	QSqlDatabase::removeDatabase(dbConnectionName);
	return password;
}

bool CMagoDBCommandsThreadWorker::AddUserMagoSend(QString usuario, QByteArray password)
{
	qDebug("CMagoDBCommandsThreadWorker::AddUserMagoSend - IN");
	bool ok;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			ok = thread->getMagoDB()->AddUserMagoSend(usuario.toLatin1().data(),password.toHex().data(), &connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::AddUserMagoSend - Erro exception");
		}

		connection.close();
	}


	QSqlDatabase::removeDatabase(dbConnectionName);
	return ok;
}

QStringList CMagoDBCommandsThreadWorker::getUsersFromHistorico()
{
	qDebug("CMagoDBCommandsThreadWorker::getUsersFromHistorico - IN");
	QStringList users;
	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{
			users = thread->getMagoDB()->getUsersFromHistorico(&connection);
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::getUsersFromHistorico - Erro exception");
		}

		connection.close();
	}


	QSqlDatabase::removeDatabase(dbConnectionName);
	return users;
}






