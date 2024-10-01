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
#include "CUtil.h"
#include <QDate>

#include <CVideoFileInformation.h>
#include "CMainWindow.h"
#include <CMediaLibraryItem.h>

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

	if (CMainWindow::mainWindow->config.isMagoRemoto)
	{
		qDebug("CMagoDBCommandsThread::run - MAGO REMOTO - ip = [%s]", CMainWindow::mainWindow->config.magoServerIP.toLatin1().data());
		magoDB = CreateDB(CMainWindow::mainWindow->config.magoServerIP.toLatin1().data(), true);
	}
	else
	{
		qDebug("CMagoDBCommandsThread::run - NAO É MAGO REMOTO - ip será local");
		magoDB =  CreateDB("127.0.0.1", true);
	}

	//magoDB =  CreateDB("127.0.0.1", true);

	worker = new CMagoDBCommandsThreadWorker(this);

	waiter.wake(1);

	exec();

	delete worker;
	worker = nullptr;
}

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
void CMagoDBCommandsThread::queuedLoadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy, QObject* object, QString methodName)
{
	QMetaObject::invokeMethod(worker, "queuedLoadAllEventsOrderByWithValueEqual", Qt::QueuedConnection, Q_ARG(QString, field), Q_ARG(QString, value), Q_ARG(QString, orderBy), Q_ARG(QObject*, object), Q_ARG(QString, methodName));
}

void CMagoDBCommandsThread::queuedLoadAllProgramsOrderByWithValueEqual(QString field, QString value, QString orderBy, QObject* object, QString methodName)
{
	QMetaObject::invokeMethod(worker, "queuedLoadAllProgramsOrderByWithValueEqual", Qt::QueuedConnection, Q_ARG(QString, field), Q_ARG(QString, value), Q_ARG(QString, orderBy), Q_ARG(QObject*, object), Q_ARG(QString, methodName));
}

/*!
 * atualiza todos os eventos do Banco de dados que tenham esse "Path" com novos frameIn e frameOut...
 * @param path
 * @param frameIn
 * @param frameOut
 */
void CMagoDBCommandsThread::queuedUpdateAllEventsWithNewVideoInformationByPath(QString path, int frameIn, int frameOut)
{
	qDebug("CMagoDBCommandsThread::queuedUpdateAllEventsWithNewVideoInformationByPath() - IN");

	QMetaObject::invokeMethod(worker, "queuedUpdateAllEventsWithNewVideoInformationByPath", Qt::QueuedConnection, Q_ARG(QString, path), Q_ARG(int, frameIn), Q_ARG(int, frameOut));

	qDebug("CMagoDBCommandsThread::queuedUpdateAllEventsWithNewVideoInformationByPath() - OUT");
}

/*!
 * atualiza todos os eventos do Banco de dados que tenham esse "Path" para sem Path
 */

void CMagoDBCommandsThread::queuedSetAllEventsWithNullPath(QString path)
{
	qDebug("CMagoDBCommandsThread::queuedSetAllEventsWithNullPath() - IN");

	QMetaObject::invokeMethod(worker, "queuedSetAllEventsWithNullPath", Qt::QueuedConnection, Q_ARG(QString, path));

	qDebug("CMagoDBCommandsThread::queuedSetAllEventsWithNullPath() - OUT");
}

/*!
 * Faz uma pesquisa via thread PRINCIPAL na tabela de eventos, ordenada pelo campo "orderBy".
 * ATENCAO: esse metodo bloqueia a thread principal...
 * @param field
 * @param value
 * @param orderBy
 * @return
 */
CMagoDBEventCollection CMagoDBCommandsThread::loadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy)
{
	CMagoDBEventCollection events;

	QMetaObject::invokeMethod(worker, "loadAllEventsOrderByWithValueEqual", Qt::BlockingQueuedConnection, Q_ARG(QString, field), Q_ARG(QString, value), Q_ARG(QString, orderBy), Q_ARG(void*, (void* )&events));

	return events;
}

void CMagoDBCommandsThread::queuedAddHistorico(QString ticket, QString numero, QString titulo, int duracaoreal, QString veiculacao, int roteiro, QDateTime data, QDateTime entrada, QDateTime saida, int posicaomesa, QString hPrevisto, QString crit1)
{
	QString sData = data.toString("yyyy-MM-dd hh:mm:ss");
	QString sEntrada = entrada.toString("yyyy-MM-dd hh:mm:ss.zzz");
	QString sSaida = saida.toString("yyyy-MM-dd hh:mm:ss.zzz");

	//vai estourar limite, ultimos 3 mandar como list (outra hora arrumo pra mandar tudo como uma lista unica
	QStringList list;
	list.push_back(QString::number(posicaomesa));
	list.push_back(hPrevisto);
	list.push_back(crit1);

	//QMetaObject::invokeMethod(worker, "queuedAddHistorico", Qt::QueuedConnection, Q_ARG(QString, ticket), Q_ARG(QString, numero), Q_ARG(QString, titulo), Q_ARG(int, duracaoreal), Q_ARG(QString, veiculacao), Q_ARG(int, roteiro), Q_ARG(QString, sData), Q_ARG(QString, sEntrada), Q_ARG(QString, sSaida), Q_ARG(int, posicaomesa), Q_ARG(QString, hPrevisto), Q_ARG(QString, crit1));
	QMetaObject::invokeMethod(worker, "queuedAddHistorico", Qt::QueuedConnection, Q_ARG(QString, ticket), Q_ARG(QString, numero), Q_ARG(QString, titulo), Q_ARG(int, duracaoreal), Q_ARG(QString, veiculacao), Q_ARG(int, roteiro), Q_ARG(QString, sData), Q_ARG(QString, sEntrada), Q_ARG(QString, sSaida), Q_ARG(QStringList, list));
}

void CMagoDBCommandsThread::queuedChangeHistoricoSaida(QString ticket, int roteiro, QDateTime saida)
{
	QString sSaida = saida.toString("yyyy-MM-dd hh:mm:ss.zzz");

	QMetaObject::invokeMethod(worker, "queuedChangeHistoricoSaida", Qt::QueuedConnection, Q_ARG(QString, ticket), Q_ARG(int, roteiro), Q_ARG(QString, sSaida));
}

void CMagoDBCommandsThread::queuedCreateEventByPathIfDosentExist(QString path, QObject* object, QString methodName, int finishedInicilization)
{
	QMetaObject::invokeMethod(worker, "queuedCreateEventByPathIfDosentExist", Qt::QueuedConnection, Q_ARG(QString, path), Q_ARG(QObject*, object), Q_ARG(QString, methodName), Q_ARG(int, finishedInicilization));
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

void CMagoDBCommandsThreadWorker::queuedLoadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy, QObject* object, QString methodName)
{

	QString dbConnectionName;
	{
		QSqlDatabase connection = CMagoDBCommandsThread::commands->getRandomConnection();
		dbConnectionName = connection.connectionName();

		QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual(orderBy.toLatin1().data(), field.toLatin1().data(), value.toLatin1().data(), &connection);
		//QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual(orderBy.toLatin1().data(), field.toLatin1().data(), value.toLatin1().data(), &myOwnDatabaseConnection);


		if (query != nullptr)
		{
			CMagoDBEventCollection* events = new CMagoDBEventCollection();

			events->loadFromQuery(query);

			delete query;

			QMetaObject::invokeMethod(object, methodName.toLatin1().data(), Qt::QueuedConnection, Q_ARG(void*, events));
		}
	}
	QSqlDatabase::removeDatabase(dbConnectionName);

}

void CMagoDBCommandsThreadWorker::loadAllEventsOrderByWithValueEqual(QString field, QString value, QString orderBy, void* result)
{
	QString dbConnectionName;
	{
		QSqlDatabase connection = CMagoDBCommandsThread::commands->getRandomConnection();
		dbConnectionName = connection.connectionName();


		CMagoDBEventCollection* events = (CMagoDBEventCollection*) result;

		QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual(orderBy.toLatin1().data(), field.toLatin1().data(), value.toLatin1().data(), &connection);
		//QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual(orderBy.toLatin1().data(), field.toLatin1().data(), value.toLatin1().data(), &myOwnDatabaseConnection);
		if (query != nullptr)
		{
			events->loadFromQuery(query);

			delete query;
		}
	}
	QSqlDatabase::removeDatabase(dbConnectionName);
}

//void CMagoDBCommandsThreadWorker::queuedAddHistorico(QString ticket, QString numero, QString titulo, int duracaoreal, QString veiculacao, int roteiro, QString data, QString entrada, QString saida, int posicaomesa, QString hPrevisto, QString crit1)
void CMagoDBCommandsThreadWorker::queuedAddHistorico(QString ticket, QString numero, QString titulo, int duracaoreal, QString veiculacao, int roteiro, QString data, QString entrada, QString saida, QStringList list)
{
	QString fullTicket = ticket + "_" + QString::number(roteiro);

	int histoId = -1;

	int posicaomesa = -1;
	QString posMesa = "";
	QString hPrevisto = "";
	QString crit1 = "";

	for (unsigned int i = 0; i < list.size(); i++)
	{
		switch (i) {
		case 0:
			posMesa = list[i];
			posicaomesa = posMesa.toInt();
			break;
		case 1:
			hPrevisto = list[i];
			break;
		case 2:
			crit1 = list[i];
			break;
		default:
			break;
		}
	}

	QString dbConnectionName;
	{
		QSqlDatabase connection = thread->getRandomConnection();

		dbConnectionName = connection.connectionName();

		try
		{

			 histoId = thread->getMagoDB()->AddHistorico(
							  numero.toLatin1().data(),
							  titulo.toLatin1().data(),
							  duracaoreal,
							  veiculacao.toLatin1().data(),
							  roteiro,
							  data.toLatin1().data(),
							  entrada.toLatin1().data(),
							  saida.toLatin1().data(),
							  posicaomesa,
							  hPrevisto.toLatin1().data(),
							  crit1.toLatin1().data(),
							  &connection
						  );
		}
		catch(...)
		{
			qDebug("CMagoDBCommandsThreadWorker::queuedAddHistorico - Erro exception");
		}

		connection.close();
	}

	//thread->deleteRandomConnection(&connection);

	QSqlDatabase::removeDatabase(dbConnectionName);


	historyIds.insert(fullTicket, histoId);
}

void CMagoDBCommandsThreadWorker::queuedChangeHistoricoSaida(QString ticket, int roteiro, QString saida)
{
	QString fullTicket = ticket + "_" + QString::number(roteiro);

	QString dbConnectionName;
	{

		if (historyIds.contains(fullTicket))
		{
			int histoId = historyIds[fullTicket];

			QSqlDatabase connection = thread->getRandomConnection();

			dbConnectionName = connection.connectionName();

			try
			{
				thread->getMagoDB()->ChangeHistoricoSaida(histoId, saida.toLatin1().data(), &connection);
			}
			catch(...)
			{
				qDebug("CMagoDBCommandsThreadWorker::queuedAddHistorico - Erro exception");
			}

			historyIds.remove(fullTicket);

			connection.close();
		}

		//thread->deleteRandomConnection(&connection);
	}
	QSqlDatabase::removeDatabase(dbConnectionName);
}

/*!
 * atualiaza todos os eventos do Banco de dados que tenham esse "Path" com novos frameIn e frameOut...
 * @param path
 * @param frameIn
 * @param frameOut
 */
void CMagoDBCommandsThreadWorker::queuedUpdateAllEventsWithNewVideoInformationByPath(QString path, int frameIn, int frameOut)
{
	QString dbConnectionName;
	{
		QSqlDatabase connection = CMagoDBCommandsThread::commands->getRandomConnection();
		dbConnectionName = connection.connectionName();

		qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() IN");

		QSqlQuery* query = (QSqlQuery*)thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "caminho", path.toLatin1().data(), &connection);

		//QSqlQuery* query = (QSqlQuery*)thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "caminho", path.toLatin1().data(), &myOwnDatabaseConnection);

		qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 1");

		if (query != nullptr)
		{
			qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 2");

			CMagoDBEventCollection* events = new CMagoDBEventCollection();

			qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 3");

			events->loadFromQuery(query);

			qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 4");

			delete query;

			qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 5");

			for (unsigned int i = 0; i < events->events.size(); i++)
			{
				qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 6");

				CMagoDBEvent evt = events->events[i];

				evt.start = frameIn;
				evt.frames = frameOut - frameIn;

				qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 6.1 - UpdateEvent DB");

				thread->getMagoDB()->UpdateEvent(
					evt.number.toLatin1().data(),
					evt.number.toLatin1().data(),
					evt.path.toLatin1().data(),
					evt.title.toLatin1().data(),
					evt.type,
					evt.start,
					evt.thumb,
					evt.frames,
					evt.data.toString("dd/MM/yyyy").toLatin1().data(),
					evt.validade.toString("dd/MM/yyyy").toLatin1().data(),
					evt.user,
					evt.modality.toLatin1().data(),
					evt.idclient,
					&connection);
					//&myOwnDatabaseConnection);


				qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 6.2");
			}

			qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() 7");

			delete events;
		}
	}
	QSqlDatabase::removeDatabase(dbConnectionName);

	qDebug("queuedUpdateAllEventsWithNewVideoInformationByPath() OUT");
}

void CMagoDBCommandsThreadWorker::queuedSetAllEventsWithNullPath(QString path)
{
	QString dbConnectionName;
	{
		QSqlDatabase connection = CMagoDBCommandsThread::commands->getRandomConnection();
		dbConnectionName = connection.connectionName();
		qDebug("queuedSetAllEventsWithNullPath() IN");

		QSqlQuery* query = (QSqlQuery*)thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "caminho", path.toLatin1().data(), &connection);
		//QSqlQuery* query = (QSqlQuery*)thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "caminho", path.toLatin1().data(), &myOwnDatabaseConnection);

		qDebug("queuedSetAllEventsWithNullPath() 1");

		if (query != nullptr)
		{
			qDebug("queuedSetAllEventsWithNullPath() 2");

			CMagoDBEventCollection* events = new CMagoDBEventCollection();

			qDebug("queuedSetAllEventsWithNullPath() 3");

			events->loadFromQuery(query);

			qDebug("queuedSetAllEventsWithNullPath() 4");

			delete query;

			qDebug("queuedSetAllEventsWithNullPath() 5");

			for (unsigned int i = 0; i < events->events.size(); i++)
			{
				qDebug("queuedSetAllEventsWithNullPath() 6");

				CMagoDBEvent evt = events->events[i];

				evt.path = "";

				qDebug("queuedSetAllEventsWithNullPath() 6.1 - - UpdateEvent DB");

				thread->getMagoDB()->UpdateEvent(
					evt.number.toLatin1().data(),
					evt.number.toLatin1().data(),
					evt.path.toLatin1().data(),
					evt.title.toLatin1().data(),
					evt.type,
					evt.start,
					evt.thumb,
					evt.frames,
					evt.data.toString("dd/MM/yyyy").toLatin1().data(),
					evt.validade.toString("dd/MM/yyyy").toLatin1().data(),
					evt.user,
					evt.modality.toLatin1().data(),
					evt.idclient,
					&connection);
					//&myOwnDatabaseConnection);

				qDebug("queuedSetAllEventsWithNullPath() 6.2");
			}

			qDebug("queuedSetAllEventsWithNullPath() 7");

			delete events;
		}
	}
	QSqlDatabase::removeDatabase(dbConnectionName);
}


void CMagoDBCommandsThreadWorker::queuedCreateEventByPathIfDosentExist(QString path, QObject* object, QString methodName, int finishedInicilization)
{
	qDebug("CMagoDBCommandsThreadWorker::queuedCreateEventByPathIfDosentExist IN [%s]", path.toLatin1().data());

	bool cancelMethod = false;

	QString dbConnectionName;
	{
		QSqlDatabase connection = CMagoDBCommandsThread::commands->getRandomConnection();
		dbConnectionName = connection.connectionName();

		//Adiciona com a data atual que e a que sera usada como referencia no cadastro caso video ainda nao esteja cadastrado...
		QDate current = QDate::currentDate();
		QString strDate = current.toString("dd/MM/yyyy");

		QFileInfo fileInfo(path);
		QFileInfo fileInfo2(CMainWindow::mainWindow->config.getVideoMediaFilePath());

		//se for diferente da pasta padrao de videos coloca na modalidade especifica, senao segue tudo como sempre foi default
		qDebug("absoluteFilePath [%s] | mediapath [%s]", fileInfo.absolutePath().toLatin1().data(), fileInfo2.absolutePath().toLatin1().data());

		//if ((fileInfo.absolutePath()+"/") != CMainWindow::mainWindow->config.getVideoMediaFilePath())
		if ( fileInfo.absolutePath() != fileInfo2.absolutePath() )
		{
			QFileInfo pathInfo(fileInfo.absolutePath());
			QString modalidade = pathInfo.baseName();
			qDebug("modalidade =  %s", modalidade.toLatin1().data());

			//se existe um evento com o path...
			//if (thread->getMagoDB()->EventExistsByPath(path.toLatin1().data(), &myOwnDatabaseConnection))
			if (thread->getMagoDB()->EventExistsByPath(path.toLatin1().data(), &connection))
			{
				qDebug("CMagoDBCommandsThreadWorker::Evento ja existente [%s]", path.toLatin1().data());

				//atualizar a duracao, como era um arquivo que nao existia, mas estava no banco, ou era gravacao ou conversao, entao pode assumir o mesmo nome para atualizar
				//a duracao do cadastro quando deixar de ser zerada. Caso no banco ela nao seja zerada, nao mecher, pois pode ter sido ja acertada pela redundante ou digisend.
				QFileInfo info(path);
				QString stringToBeUsedAsEventNumber = info.completeBaseName();
				CVideoFileInformation infoFile(path, stringToBeUsedAsEventNumber, info.baseName());

				//se esta abrindo o mago nao pode chamar esse update que tambem ira cair nessa parte e ira zerar in e out
				if (finishedInicilization)
				{
					int dbInitPos    = thread->getMagoDB()->GetEventInitPos(stringToBeUsedAsEventNumber.toLatin1().data());
					int dbFrameCount = thread->getMagoDB()->GetEventFrames(stringToBeUsedAsEventNumber.toLatin1().data());

					qDebug("VerificacaoA: dbInitPos[%d] + dbFrameCount[%d] > infoFile->getFrameCount([%d])", dbInitPos, dbFrameCount, infoFile.getFrameCount());
					qDebug("VerificacaoB: dbFrameCount[%d] == 0", dbFrameCount);

					//se o inicio + duracao em frames for maior que o total de frames do arquivo, ou entao a duracao em frames
					//no banco for igual a zero, devemos atualizar o arquivo no BD...

					if (CMainWindow::mainWindow->getIsRedundant())
					{
						if (dbInitPos + dbFrameCount > infoFile.getFrameCount() || dbFrameCount == 0 || CMainWindow::mainWindow->config.getShouldAlwaysUpdateDuration())
						{
							//xxx: era ASSIM vai ter q ser assim ainda...
							thread->getMagoDB()->ChangeEventInitPos(stringToBeUsedAsEventNumber.toLatin1().data(), 0);
							thread->getMagoDB()->ChangeEventDuration(stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
							thread->getMagoDB()->ChangeEventModalidade(stringToBeUsedAsEventNumber.toLatin1().data(), modalidade.toLatin1().data());
							qDebug("Resposta: Sim - Nova duracao para o arquivo [%s] deve ser[%d]", stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
						}
						else
						{
							qDebug("Respost: Nao");
						}
					}
					else
					{
						//xxx: era ASSIM vai ter q ser assim ainda...
						thread->getMagoDB()->ChangeEventInitPos(stringToBeUsedAsEventNumber.toLatin1().data(), 0);
						thread->getMagoDB()->ChangeEventDuration(stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
						thread->getMagoDB()->ChangeEventModalidade(stringToBeUsedAsEventNumber.toLatin1().data(), modalidade.toLatin1().data());
						qDebug("Resposta: Sim 2 - Nova duracao para o arquivo [%s] deve ser[%d]", stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
					}
				}
				else
				{
					//se ainda ta fazendo a inicializacao nao vai chamar o dbupdate para evitar o refresh do medialib eqto carrega os eventos
					//return;
					cancelMethod = true;
				}

			}
			//se NAO existe um evento com o path...
			else
			{
				//se o evento não existe e o arquivo tambem nao existe é porque foi erro do mediachecker na hora de apagar o arquivo, nao vai fazer nada
				if (!QFile::exists(path))
				{
					qDebug("CMagoDBCommandsThreadWorker::Evento nao existe [%s] e nem o arquivo, cancela o insert no banco ", path.toLatin1().data());
					//return;
					cancelMethod = true;
				}
				else
				{
					//gera um NUMERO de evento novo e aleatorio basado no path
					QFileInfo info(path);
					QString stringToBeUsedAsEventNumber = info.completeBaseName();

					CVideoFileInformation* infoFile = new CVideoFileInformation(path, stringToBeUsedAsEventNumber, info.baseName());

					qDebug("CMagoDBCommandsThreadWorker::Evento nao existe [%s] [%s]", path.toLatin1().data(), stringToBeUsedAsEventNumber.toLatin1().data());


					//primeiro tenta adicionar o NUMERO com o NOME original...
					//if (!thread->getMagoDB()->EventExistsByNumber(stringToBeUsedAsEventNumber.toLatin1().data(), &myOwnDatabaseConnection))
					if (!thread->getMagoDB()->EventExistsByNumber(stringToBeUsedAsEventNumber.toLatin1().data(), &connection))
					{
						qDebug("CMagoDBCommandsThreadWorker::AddEvent 1");

						QFileInfo info(path);
						thread->getMagoDB()->AddEvent(
							stringToBeUsedAsEventNumber.toLatin1().data(),
							path.toLatin1().data(),
							info.baseName().toLatin1().data(),
							0,
							0,
							0,
							infoFile->getFrameCount(),
							strDate.toLatin1().data(), //"30/11/2018",
							"",
							0,
							modalidade.toLatin1().data(),
							0,
							&connection);
							//&myOwnDatabaseConnection);

						qDebug("CMagoDBCommandsThreadWorker::Evento nao existente, mas aceito como novo e mantendo o numero fiel ao nome do arquivo [%s]", stringToBeUsedAsEventNumber.toLatin1().data());

					}
					//se ja existir um com NUMERO igual ao NOME original...
					else
					{

						//temos que verificar se devemos usar esse que ja existe. Isso acontece, quando existe um evento com o mesmo
						//numero que estamos tentando utilziar, mas sem nenhum PATH, indicando ser dessa forma um evento VIRRRGGAOO que
						//pode ser usado neste caso...
						bool shouldUseExistent = false;
						//QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "numero", stringToBeUsedAsEventNumber.toLatin1().data(), &myOwnDatabaseConnection);
						QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "numero", stringToBeUsedAsEventNumber.toLatin1().data(), &connection);
						if (query != nullptr)
						{
							//le todos os eventos que voltaram na query->..
							CMagoDBEventCollection events;
							events.loadFromQuery(query);
							delete query;

							//vamos olhar cada evento que ja existia, se existir algum sem PATH, significa q era um evneto vazio
							//e vamos entao atualiza-lo com novo path...
							for (unsigned int i = 0; i < events.events.size(); i++)
							{
								if (events.events[i].path.isEmpty() || events.events[i].path.trimmed() == "")
								{
									CMagoDBEvent evt = events.events[i];
									shouldUseExistent = true;
									thread->getMagoDB()->UpdateEvent(
										evt.number.toLatin1().data(),
										evt.number.toLatin1().data(),
										path.toLatin1().data(),
										evt.title.toLatin1().data(),
										0,
										0,
										0,
										infoFile->getFrameCount(),
										strDate.toLatin1().data(), //"30/11/2018",
										evt.validade.toString("dd/MM/yyyy").toLatin1().data(),
										0,
										modalidade.toLatin1().data(),
										0,
										&connection);
										//&myOwnDatabaseConnection);

									qDebug("CMagoDBCommandsThreadWorker::Evento existente, mas como tinha path vazio sera reutilizado [%s] - UpdateEvent DB", stringToBeUsedAsEventNumber.toLatin1().data());
								}
								else
								{
									if (events.events[i].path.trimmed() == path)
									{
										CMagoDBEvent evt = events.events[i];
										shouldUseExistent = true;
										thread->getMagoDB()->UpdateEvent(
											evt.number.toLatin1().data(),
											evt.number.toLatin1().data(),
											path.toLatin1().data(),
											evt.title.toLatin1().data(),
											0,
											0,
											0,
											infoFile->getFrameCount(),
											strDate.toLatin1().data(), //"30/11/2018",
											evt.validade.toString("dd/MM/yyyy").toLatin1().data(),
											0,
											modalidade.toLatin1().data(),
											0,
											&connection);
											//&myOwnDatabaseConnection);


										qDebug("CMagoDBCommandsThreadWorker::Evento existente, mas o path era exatamente o mesmo do arquivo sera reutilizado [%s] - UpdateEvent DB", stringToBeUsedAsEventNumber.toLatin1().data());
									}
								}
							}
						}

						//se cair aq eh pq devemos criar um novo registro... _x
						if (!shouldUseExistent)
						{
							for (int i = 0; i < 10000; i++)
							{
								QString newTryingNumber = stringToBeUsedAsEventNumber + "_" + QString::number(i);

								//if (!thread->getMagoDB()->EventExistsByNumber(newTryingNumber.toLatin1().data(), &myOwnDatabaseConnection))
								if (!thread->getMagoDB()->EventExistsByNumber(newTryingNumber.toLatin1().data(), &connection))
								{
									QFileInfo info(path);

									qDebug("CMagoDBCommandsThreadWorker::AddEvent 2");

									thread->getMagoDB()->AddEvent(
										newTryingNumber.toLatin1().data(),
										path.toLatin1().data(),
										info.baseName().toLatin1().data(),
										0,
										0,
										0,
										infoFile->getFrameCount(),
										strDate.toLatin1().data(), //"30/11/2018",
										"",
										0,
										modalidade.toLatin1().data(),
										0,
										&connection);
										//&myOwnDatabaseConnection);

									qDebug("CMagoDBCommandsThreadWorker::Evento nao existente, mas aceito como novo tendo o numero adptado a partir do nome do arquivo[%s]", newTryingNumber.toLatin1().data());

									break;
								}
							}
						}
					}
				}
			}

		}
		else
		{
			//se existe um evento com o path...
			//if (thread->getMagoDB()->EventExistsByPath(path.toLatin1().data(), &myOwnDatabaseConnection))
			if (thread->getMagoDB()->EventExistsByPath(path.toLatin1().data(), &connection))
			{
				qDebug("CMagoDBCommandsThreadWorker::Evento ja existente [%s]", path.toLatin1().data());

				//atualizar a duracao, como era um arquivo que nao existia, mas estava no banco, ou era gravacao ou conversao, entao pode assumir o mesmo nome para atualizar
				//a duracao do cadastro quando deixar de ser zerada. Caso no banco ela nao seja zerada, nao mecher, pois pode ter sido ja acertada pela redundante ou digisend.
				QFileInfo info(path);
				QString stringToBeUsedAsEventNumber = info.completeBaseName();
				CVideoFileInformation infoFile(path, stringToBeUsedAsEventNumber, info.baseName());

				//se esta abrindo o mago nao pode chamar esse update que tambem ira cair nessa parte e ira zerar in e out
				if (finishedInicilization)
				{
					bool cond1 =  false;
					bool cond2 = false;
					//se o info é invalido e na lib do mago também era invalido não faz refresh nenhum
					if (! infoFile.isOk()  )
					{
						qDebug("CMagoDBCommandsThreadWorker::info é inválido");
						cond1 = true;
					}

					qDebug("searchEventByNumber - CMagoDBCommandsThreadWorker");

					CMediaLibraryItem* mediaLibItem = CExhibitionWindow::exhibitionWindow->searchEventByNumber(stringToBeUsedAsEventNumber);
					if (mediaLibItem != nullptr)
					{
						qDebug("CMagoDBCommandsThreadWorker:: (mediaLibItem != nullptr)");
						if (! mediaLibItem->videoFileInformation->isOk())
						{
							qDebug("CMagoDBCommandsThreadWorker::na lib esta inválido");
							cond2 = true;
						}
					}

					if (cond1 && cond2)
					{
						qDebug("CMagoDBCommandsThreadWorker::não enche o saco do Mago");
						//return;
						cancelMethod = true;
					}
					else
					{
						int dbInitPos    = thread->getMagoDB()->GetEventInitPos(stringToBeUsedAsEventNumber.toLatin1().data());
						int dbFrameCount = thread->getMagoDB()->GetEventFrames(stringToBeUsedAsEventNumber.toLatin1().data());

						qDebug("VerificacaoA1: dbInitPos[%d] + dbFrameCount[%d] > infoFile->getFrameCount([%d])", dbInitPos, dbFrameCount, infoFile.getFrameCount());
						qDebug("VerificacaoB1: dbFrameCount[%d] == 0", dbFrameCount);

						//se o inicio + duracao em frames for maior que o total de frames do arquivo, ou entao a duracao em frames
						//no banco for igual a zero, devemos atualizar o arquivo no BD...
						//if (dbInitPos + dbFrameCount > infoFile.getFrameCount() || dbFrameCount == 0 || CMainWindow::mainWindow->config.getShouldAlwaysUpdateDuration())
						if (CMainWindow::mainWindow->getIsRedundant())
						{
							if (dbInitPos + dbFrameCount > infoFile.getFrameCount() || dbFrameCount == 0 || CMainWindow::mainWindow->config.getShouldAlwaysUpdateDuration())
							{
								//xxx: era ASSIM vai ter q ser assim ainda...
								thread->getMagoDB()->ChangeEventInitPos(stringToBeUsedAsEventNumber.toLatin1().data(), 0);
								thread->getMagoDB()->ChangeEventDuration(stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
								qDebug("Resposta: Sim - Nova duracao para o arquivo [%s] deve ser[%d]", stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
							}
							else
							{
								qDebug("Respost: Nao");
							}

						}
						else
						{
							thread->getMagoDB()->ChangeEventInitPos(stringToBeUsedAsEventNumber.toLatin1().data(), 0);
							thread->getMagoDB()->ChangeEventDuration(stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
							qDebug("Resposta: Sim 2 - Nova duracao para o arquivo [%s] deve ser[%d]", stringToBeUsedAsEventNumber.toLatin1().data(), infoFile.getFrameCount());
						}
					}
				}
				else
				{
					//se ainda ta fazendo a inicializacao nao vai chamar o dbupdate para evitar o refresh do medialib eqto carrega os eventos
					qDebug("CMagoDBCommandsThreadWorker::ainda ta fazendo a inicializacao nao vai chamar o dbupdate para evitar o refresh do medialib");
					//return;
					cancelMethod = true;
				}

			 }
			 //se NAO existe um evento com o path...
			 else
			 {
				//se o evento não existe e o arquivo tambem nao existe é porque foi erro do mediachecker na hora de apagar o arquivo, nao vai fazer nada
				if (!QFile::exists(path))
				{
					qDebug("CMagoDBCommandsThreadWorker::Evento nao existe [%s] e nem o arquivo, cancela o insert no banco ", path.toLatin1().data());
					//return;
					cancelMethod = true;
				}
				else
				{
					//gera um NUMERO de evento novo e aleatorio basado no path
					QFileInfo info(path);
					QString stringToBeUsedAsEventNumber = info.completeBaseName();

					CVideoFileInformation* infoFile = new CVideoFileInformation(path, stringToBeUsedAsEventNumber, info.baseName());

					qDebug("CMagoDBCommandsThreadWorker::Evento nao existe [%s] [%s]", path.toLatin1().data(), stringToBeUsedAsEventNumber.toLatin1().data());


					//primeiro tenta adicionar o NUMERO com o NOME original...
					//if (!thread->getMagoDB()->EventExistsByNumber(stringToBeUsedAsEventNumber.toLatin1().data(), &myOwnDatabaseConnection))
					if (!thread->getMagoDB()->EventExistsByNumber(stringToBeUsedAsEventNumber.toLatin1().data(), &connection))
					{
						qDebug("CMagoDBCommandsThreadWorker::AddEvent 1");

						QFileInfo info(path);
						thread->getMagoDB()->AddEvent(
							stringToBeUsedAsEventNumber.toLatin1().data(),
							path.toLatin1().data(),
							info.baseName().toLatin1().data(),
							0,
							0,
							0,
							infoFile->getFrameCount(),
							strDate.toLatin1().data(), //"30/11/2018",
							"",
							0,
							"COM",
							0,
							&connection);
							//&myOwnDatabaseConnection);

						qDebug("CMagoDBCommandsThreadWorker::Evento nao existente, mas aceito como novo e mantendo o numero fiel ao nome do arquivo [%s]", stringToBeUsedAsEventNumber.toLatin1().data());

					}
					//se ja existir um com NUMERO igual ao NOME original...
					else
					{

						//temos que verificar se devemos usar esse que ja existe. Isso acontece, quando existe um evento com o mesmo
						//numero que estamos tentando utilziar, mas sem nenhum PATH, indicando ser dessa forma um evento VIRRRGGAOO que
						//pode ser usado neste caso...
						bool shouldUseExistent = false;
						//QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "numero", stringToBeUsedAsEventNumber.toLatin1().data(), &myOwnDatabaseConnection);
						QSqlQuery* query = (QSqlQuery*) thread->getMagoDB()->loadAllEventsOrderByWithValueEqual("numero", "numero", stringToBeUsedAsEventNumber.toLatin1().data(), &connection);
						if (query != nullptr)
						{
							//le todos os eventos que voltaram na query->..
							CMagoDBEventCollection events;
							events.loadFromQuery(query);
							delete query;

							//vamos olhar cada evento que ja existia, se existir algum sem PATH, significa q era um evneto vazio
							//e vamos entao atualiza-lo com novo path...
							for (unsigned int i = 0; i < events.events.size(); i++)
							{
								if (events.events[i].path.isEmpty() || events.events[i].path.trimmed() == "")
								{
									CMagoDBEvent evt = events.events[i];
									shouldUseExistent = true;
									thread->getMagoDB()->UpdateEvent(
										evt.number.toLatin1().data(),
										evt.number.toLatin1().data(),
										path.toLatin1().data(),
										evt.title.toLatin1().data(),
										0,
										0,
										0,
										infoFile->getFrameCount(),
										strDate.toLatin1().data(), //"30/11/2018",
										evt.validade.toString("dd/MM/yyyy").toLatin1().data(),
										0,
										evt.modality.toLatin1().data(),
										0,
										&connection);
										//&myOwnDatabaseConnection);

									qDebug("CMagoDBCommandsThreadWorker::Evento existente, mas como tinha path vazio sera reutilizado [%s] - UpdateEvent DB", stringToBeUsedAsEventNumber.toLatin1().data());
								}
								//TODO - fazer o teste se tiver ja cadastrado com o path igual??
							}
						}

						//se cair aq eh pq devemos criar um novo registro... _x
						if (!shouldUseExistent)
						{
							for (int i = 0; i < 10000; i++)
							{
								QString newTryingNumber = stringToBeUsedAsEventNumber + "_" + QString::number(i);

								//if (!thread->getMagoDB()->EventExistsByNumber(newTryingNumber.toLatin1().data(), &myOwnDatabaseConnection))
								if (!thread->getMagoDB()->EventExistsByNumber(newTryingNumber.toLatin1().data(), &connection))
								{
									QFileInfo info(path);

									qDebug("CMagoDBCommandsThreadWorker::AddEvent 2");

									thread->getMagoDB()->AddEvent(
										newTryingNumber.toLatin1().data(),
										path.toLatin1().data(),
										info.baseName().toLatin1().data(),
										0,
										0,
										0,
										infoFile->getFrameCount(),
										strDate.toLatin1().data(), //"30/11/2018",
										"",
										0,
										"COM",
										0,
										&connection);
										//&myOwnDatabaseConnection);

									qDebug("CMagoDBCommandsThreadWorker::Evento nao existente, mas aceito como novo tendo o numero adptado a partir do nome do arquivo[%s]", newTryingNumber.toLatin1().data());

									break;
								}
							}
						}
					}
				}
			}
		}

		if ((object != nullptr) && (!cancelMethod))
		{
			qDebug("CMagoDBCommandsThreadWorker::Vai chamar DB UPDATE[%s] - MethodName [%s]", path.toLatin1().data(), methodName.toLatin1().data());

			QMetaObject::invokeMethod(object, methodName.toLatin1().data(), Qt::QueuedConnection, Q_ARG(QString, path));
		}

	}

	QSqlDatabase::removeDatabase(dbConnectionName);
}

