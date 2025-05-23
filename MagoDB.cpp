/*
 * MagoDB.cpp
 *
 *  Created on: 14/03/2018
 *      Author: Leo
 */

#include "MagoDB.h"
#include <QString>
#include <stdio.h>
#include <iostream>
#include "QDebug"
#include <QSqlDatabase>
#include <QtSql>
#include <QDate>
#include <QApplication>
#include <QMessageBox>


MagoDB::MagoDB(char* IP, bool useRandomConnectionName)
{

	qDebug("InitMagoDB");
	if(IP == "127.0.0.1")
	{
		if (CreateDB("127.0.0.1", QString("magosend"),5432, useRandomConnectionName))
		{
			qDebug("Criou magosend DB");
		}
		else
		{
			qDebug("Erro Criar magosend DB");
			QMessageBox::warning(nullptr, QObject::tr("MagoSen - Falha na conexão com o próprio BD"), QObject::tr("Não foi possível se conectar com o banco de dados do MagoSend"));
		}
	}
	else
	{
		if (CreateDB(IP, QString("magodb"), 5432,useRandomConnectionName))
		{
			qDebug("Criou MagoDB");
		}
		else
		{
			qDebug("Erro Criar DB");
			QMessageBox::warning(nullptr, QObject::tr("MagoSend- Falha na conexão com o BD do Mago"), QObject::tr("Não foi possível se conectar com o banco de dados do Mago"));
		}
	}

}

MagoDB::~MagoDB()
{
	this->Magodb.close();
}

QString MagoDB::databaseName() const
{
	const QString dbName = "";//QLatin1String(qgetenv("SQLATE_DATABASE_NAME").constData());
	if (dbName.isEmpty())
	{
		return QLatin1String("magosend");
	}

	return dbName.toLower();
}

int MagoDB::getDbPort()
{
	QSettings settings(QApplication::applicationDirPath() + "\\MVHconfig.ini", QSettings::IniFormat);
	int dbPort = settings.value("port", "5432").toInt();

	if (dbPort <= 0)
	{
		dbPort = 5432;
	}
	return dbPort;
}

//bool MagoDB::CreateDB()
//{
//	QString dbName = databaseName();
//	Magodb = QSqlDatabase::addDatabase(QLatin1String("QPSQL"));

//	if (!Magodb.isValid())
//	{
//		return false;
//	}

//	Magodb.setDatabaseName(dbName);
//	QSettings settings(QApplication::applicationDirPath() + "\\Arquivos\MagoSend.ini", QSettings::IniFormat);
//	QString dbHost = settings.value("ipServer", "").toString();
//	qDebug("dbHost: [%s]", dbHost.toLatin1().data());
//	if (dbHost.isEmpty())
//	{
//		dbHost = QLatin1String("127.0.0.1");
//	}
//	QString dbUser = QLatin1String(qgetenv("SQLATE_DATABASE_USER").constData());
//	if (dbUser.isEmpty())
//	{
//		dbUser = QLatin1String("postgres");
//	}
//	QString dbPassword = QLatin1String(qgetenv("SQLATE_DATABASE_PASSWORD").constData());
//	if (dbPassword.isEmpty())
//	{
//		dbPassword = QLatin1String("admin");
//	}
//	int dbPort = getDbPort();
//	Magodb.setHostName(dbHost);
//	Magodb.setPort(dbPort);
//	Magodb.setUserName(dbUser);
//	Magodb.setPassword(dbPassword);

//	if (!Magodb.open())
//	{
//		//try to create the database
//		Magodb.close();
//		QSqlDatabase db2 = QSqlDatabase::database();
//		db2.setDatabaseName(QLatin1String("template1"));
//		db2.setHostName(dbHost);
//		db2.setPort(dbPort);
//		db2.setUserName(dbUser);
//		db2.setPassword(dbPassword);
//		if (!db2.open())
//		{
//			qFatal("Failed to connect: %s", db2.lastError().text().toLatin1().constData());
//		}

//		QString s = QString(QLatin1String("CREATE DATABASE %1 WITH OWNER = postgres ENCODING 'UTF8'CONNECTION LIMIT = -1")).arg(databaseName());
//		QSqlQuery query(db2);
//		if (!query.exec(s))
//		{
//			qFatal("Failed to create the %s database: %s", databaseName().toLatin1().constData(), query.lastError().text().toLatin1().constData());
//		}
//		db2.close();
//		//reconnect again
//		Magodb.close();
//		Magodb = QSqlDatabase::database();

//		if (!Magodb.isValid())
//		{
//			return false;
//		}

//		Magodb.setDatabaseName(databaseName());
//		Magodb.setHostName(dbHost);
//		Magodb.setPort(dbPort);
//		Magodb.setUserName(dbUser);
//		Magodb.setPassword(dbPassword);

//		return Magodb.open();
//	}
//	else
//	{
//		return true;
//	}
//}
bool MagoDB::CreateDB(char* IP, QString dbName,int dbPort,bool useRandomConnectionName)
{
	if (useRandomConnectionName)
	{
		QDateTime now = QDateTime::currentDateTime();

		QString connectionName = now.toString("ddMMyyyyhhmmsszzz");

		Magodb = QSqlDatabase::addDatabase(QLatin1String("QPSQL"), connectionName);

		qDebug("MagoDB::CreateDB() - utilizado como nome de conexao [%s]", connectionName.toLatin1().data());
	}
	else
	{
		Magodb = QSqlDatabase::addDatabase(QLatin1String("QPSQL"));
	}

	if (!Magodb.isValid())
	{
		return false;
	}
	dbName = QLatin1String(dbName.toLatin1().data());

	Magodb.setDatabaseName(dbName);
	QString dbHost = QLatin1String(qgetenv("SQLATE_DATABASE_HOST").constData());
	if (dbHost.isEmpty())
	{
		dbHost = QLatin1String(IP);
	}

	QString dbUser = QLatin1String(qgetenv("SQLATE_DATABASE_USER").constData());
	if (dbUser.isEmpty())
	{
		dbUser = QLatin1String("postgres");
	}
	QString dbPassword = QLatin1String(qgetenv("SQLATE_DATABASE_PASSWORD").constData());
	if (dbPassword.isEmpty())
	{
		dbPassword = QLatin1String("admin");
	}

	//int dbPort = getDbPort();
	Magodb.setHostName(dbHost);
	Magodb.setPort(dbPort);
	Magodb.setUserName(dbUser);
	Magodb.setPassword(dbPassword);

	qDebug("dbName %s", dbName.toLatin1().data());
	qDebug("dbHost %s", dbHost.toLatin1().data());
	qDebug("dbPort %d", dbPort);
	qDebug("dbUser %s", dbUser.toLatin1().data());
	qDebug("dbPassword %s", dbPassword.toLatin1().data());


	if (!Magodb.open())
	{

		//try to create the database
		qDebug("try to create database");
		Magodb.close();
		QSqlDatabase db2 = QSqlDatabase::database();
		db2.setDatabaseName(QLatin1String("template1"));
		db2.setHostName(dbHost);
		db2.setPort(dbPort);
		db2.setUserName(dbUser);
		db2.setPassword(dbPassword);

		if (!db2.open())
		{
			if(IP == "127.0.0.1")
			{
				qFatal("Failed to connect: %s", db2.lastError().text().toLatin1().constData());
			}
			else
			{
				qDebug("Failed to connect: %s", db2.lastError().text().toLatin1().constData());
			}

		}

		QString s = QString(QLatin1String("CREATE DATABASE %1 WITH OWNER = postgres ENCODING 'UTF8'CONNECTION LIMIT = -1")).arg(databaseName());
		//QString s = QString(QLatin1String("CREATE DATABASE %1 WITH OWNER = postgres ENCODING 'LATIN1' LC_COLLATE 'pt_BR.ISO-8859-1' LC_CTYPE 'pt_BR.ISO-8859-1' template template0 CONNECTION LIMIT = -1")).arg(databaseName());
		QSqlQuery query(db2);
		if (!query.exec(s))
		{
			if(IP == "127.0.0.1")
			{
				qFatal("Failed to create the %s database: %s", databaseName().toLatin1().constData(), query.lastError().text().toLatin1().constData());
			}
			else
			{
				qDebug("Failed to create the %s database: %s", databaseName().toLatin1().constData(), query.lastError().text().toLatin1().constData());
			}

		}
		db2.close();
		//reconnect again
		Magodb.close();
		Magodb = QSqlDatabase::database();

		if (!Magodb.isValid())
		{
			return false;
		}

		Magodb.setDatabaseName(databaseName());
		Magodb.setHostName(dbHost);
		Magodb.setPort(dbPort);
		Magodb.setUserName(dbUser);
		Magodb.setPassword(dbPassword);

		return Magodb.open();
	}
	else
	{
		return true;
	}
}
bool MagoDB::CreateTableEventos()
{
	QSqlQuery query;
	bool resultado;
	resultado = query.exec(QLatin1String("create table Eventos(numero varchar PRIMARY KEY,"
										 "caminho varchar NOT NULL,"
										 "titulo varchar NOT NULL,"
										 "tipo int,"
										 "inicio int,"
										 "thumb int,"
										 "frames int,"
										 "data date,"
										 "validade date,"
										 "usuario int,"
										 "modalidade varchar);"));
	qDebug()<< query.lastError();

	return resultado;
}

bool MagoDB::CreateTableProgramas()
{
	QSqlQuery query;
	bool resultado;
	resultado = query.exec(QLatin1String("create table Programas(codigo varchar PRIMARY KEY,"
										 "titulo varchar NOT NULL,"
										 "breaks int,"
										 "frames int,"
										 "posicaomesa int)"));
	qDebug() << query.lastError();
	return resultado;
}

bool MagoDB::CreateTableHistorico(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	bool resultado;

	resultado = query->exec(QLatin1String("create table Historico(id SERIAL PRIMARY KEY,"
										  "numero TEXT NOT NULL,"
										  "titulo TEXT NOT NULL,"
										  "caminho TEXT NOT NULL,"
										  "modalidade TEXT NOT NULL,"
										  "duracao int,"
										  "ip TEXT NOT NULL,"
										  "status TEXT NOT NULL,"
										  "data timestamp NOT NULL,"
										  "usuario TEXT)"));
	qDebug() << query->lastError();
	return resultado;
}

bool MagoDB::CreateTableLogin(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	bool resultado;

	resultado = query->exec(QLatin1String("create table Login(id SERIAL PRIMARY KEY,"
										  "usuario varchar NOT NULL,"
										  "senha varchar NOT NULL)"));
	qDebug() << query->lastError();
	return resultado;
}

bool MagoDB::CreateTableVersion()
{
	QSqlQuery query;
	bool resultado;

	resultado = query.exec(QLatin1String("create table Version(magodb_version varchar PRIMARY KEY"
										 ")"));
	qDebug() << query.lastError();
	return resultado;
}

bool MagoDB::CreateTableSessions(QSqlDatabase* connection)
{
	qDebug("CreateTableSessions - IN");
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	bool resultado;

	resultado = query->exec(QLatin1String("create table Sessions("
										  "nome TEXT NOT NULL,"
										  "ipList TEXT NOT NULL,"
										  "nameList TEXT NOT NULL)"));
	qDebug() << query->lastError();
	return resultado;
}

bool MagoDB::CreateTableModalidades(QSqlDatabase* connection)
{
	qDebug("CreateTableModalidades - IN");
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	bool resultado;

	resultado = query->exec(QLatin1String("create table modalidade("
										  "nome TEXT NOT NULL,"
										  "descricao TEXT NOT NULL)"));
	qDebug() << query->lastError();
	return resultado;
}

bool MagoDB::CreateTableOptions(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QString sql;
	bool resultado;

	resultado = query->exec(QLatin1String("create table options("
										  "overwritefile boolean NOT NULL,"
										  "overwriteId boolean NOT NULL,"
										  "showErrors boolean NOT NULL,"
										  "showSuccess boolean NOT NULL)"));
	qDebug() << query->lastError();
	if(resultado)
	{
		sql.sprintf("INSERT INTO options (overwritefile, overwriteid, showErrors, showSuccess) VALUES (false, false, true,true)");
		qDebug("sql = %s", sql.toLatin1().data());
		query->prepare(sql);
		query->exec();
		qDebug() << query->lastError();
	}

	return resultado;
}

bool MagoDB::doesSessionExists(QString sessao, QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QString sql = "SELECT * FROM sessions WHERE nome = :val_nome";

	qDebug() << "Preparing SQL query:" << sql;

	query->prepare(sql);
	query->bindValue(":val_nome", sessao);

	if (query->exec())
	{
		if (query->next())
		{
			// Session existe
			return true;
		}
	}
	else
	{
		qDebug() << "Error executing query:" << query->lastError();
	}

	// Session nao existe
	return false;
}
bool MagoDB::warningWhenOverwriteFile(QSqlDatabase* connection){
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QString sql;
	sql.sprintf("SELECT overwritefile FROM options LIMIT 1");

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();
	if(query->next())
	{
		qDebug() << query->lastError();
		if(query->value("overwritefile").toBool() == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		qDebug() << query->lastError();
		return false;
	}
}

bool MagoDB::warningWhenOverwriteId(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QString sql;
	sql.sprintf("SELECT overwriteid FROM options LIMIT 1");

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();
	if(query->next())
	{
		qDebug() << query->lastError();
		if(query->value("overwriteid").toBool() == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		qDebug() << query->lastError();
		return false;
	}
}
bool MagoDB::updateSendOptions(bool shouldOverwriteFile, bool shouldOverwriteId, QSqlDatabase* connection)
{

	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QString sql;
	char* str_shouldOverwriteFile = "false";
	char* str_shouldOverwriteId = "false";
	if(shouldOverwriteFile)
	{
		str_shouldOverwriteFile = "true";
	}
	if(shouldOverwriteId)
	{
		str_shouldOverwriteId = "true";
	}

	sql.sprintf("UPDATE options SET overwritefile = '%s'", str_shouldOverwriteFile);
	query->prepare(sql);
	query->exec();
	qDebug() << query->lastError();
	sql.sprintf("UPDATE options SET overwriteid = '%s'", str_shouldOverwriteId);
	//	sql.sprintf("INSERT INTO sessions (ipList) VALUES ('%s')", ipList);
	qDebug("sql = %s", sql.toLatin1().data());
	query->prepare(sql);
	query->exec();
	qDebug() << query->lastError();

}

bool MagoDB::updateStatusFilter(bool showErrors, bool showSuccess,QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}



	QString sql;
	char* str_showErrors = "false";
	char* str_showSuccess = "false";
	if(showErrors)
	{
		str_showErrors = "true";
	}
	if(showSuccess)
	{
		str_showSuccess = "true";
	}

	sql.sprintf("UPDATE options SET showErrors = '%s'", str_showErrors);
	query->prepare(sql);
	query->exec();
	qDebug() << query->lastError();
	sql.sprintf("UPDATE options SET showSuccess = '%s'", str_showSuccess);
	//	sql.sprintf("INSERT INTO sessions (ipList) VALUES ('%s')", ipList);
	qDebug("sql = %s", sql.toLatin1().data());
	query->prepare(sql);
	query->exec();
	qDebug() << query->lastError();
}

bool MagoDB::shouldShowErrors(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QString sql;
	sql.sprintf("SELECT showErrors FROM options LIMIT 1");

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();
	if(query->next())
	{
		qDebug() << query->lastError();
		if(query->value("showErrors").toBool() == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		qDebug() << query->lastError();
		return false;
	}
}
bool MagoDB::shouldShowSuccess(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QString sql;
	sql.sprintf("SELECT showSuccess FROM options LIMIT 1");

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();
	if(query->next())
	{
		qDebug() << query->lastError();
		if(query->value("showSuccess").toBool() == true)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		qDebug() << query->lastError();
		return false;
	}
}
//bool MagoDB::ensureColumnExists(const QString &table_name, const QString &columnName, const QString &columnType)
//{
//	QSqlQuery query;
//	query.prepare(QLatin1String(
//		"SELECT column_name FROM information_schema.columns "
//		"WHERE table_name = :table_name AND column_name = :columnName"));
//	query.bindValue(":table_name", table_name);
//	query.bindValue(":columnName", columnName);


//	if (query.exec() && query.next())
//	{
//		qDebug() << "Column" << columnName << "already exists.";
//		return true;  // Column exists
//	}
//	else
//	{
//		// Column does not exist, so add it
//		QString alterQuery = QString("ALTER TABLE %1 ADD COLUMN %2 %3")
//							 .arg(table_name,columnName, columnType);

//		if (!query.exec(alterQuery))
//		{
//			qDebug() << "Error adding column:" << query.lastError();
//			return false;
//		}
//		qDebug() << "Column" << columnName << "added successfully.";
//		return true;
//	}
//}
void MagoDB::updateSessionIpList(QString sessao, QString ipList, QString nameList, QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}


	QString sql;
	qDebug() << "ipList:" << ipList;
	//	sql.sprintf("UPDATE sessions SET ipList = '%s' WHERE nome = '%s'", ipList, sessao);
	query->prepare("UPDATE sessions SET ipList = :val_ipList WHERE nome = :val_nome");
	query->bindValue(":val_nome", sessao);
	query->bindValue(":val_ipList", ipList);
	query->exec();
	qDebug() << query->lastError();
	//sql.sprintf("UPDATE sessions SET nameList = '%s' WHERE nome = '%s'", nameList, sessao);
	//	sql.sprintf("INSERT INTO sessions (ipList) VALUES ('%s')", ipList);
	query->prepare("UPDATE sessions SET nameList = :val_nameList WHERE nome = :val_nome");
	query->bindValue(":val_nome", sessao);
	query->bindValue(":val_nameList", nameList);
	query->exec();
	qDebug() << query->lastError();
}

void MagoDB::createRowOnSessionTable(QString sessao, QString ipList, QString nameList, QSqlDatabase* connection)
{
	qDebug() << "createRowOnSessionTable - IN" ;
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}



	//QString sql;

	query->prepare("INSERT INTO sessions (nome, iplist, namelist) VALUES (:val_nome, :val_ipList, :val_nameList)");
	query->bindValue(":val_nome", sessao);
	query->bindValue(":val_ipList",ipList);
	query->bindValue(":val_nameList", nameList);
	query->exec();
	qDebug() << "Last Query: " << query->lastQuery();
	qDebug() << query->lastError();
}

QStringList MagoDB::getIpListFromSession(QString sessao, QSqlDatabase* connection)
{

	if (!connection->isOpen())
	{
		qDebug("MagoDB::getIpListFromSession() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::getIpListFromSession() - Conexao estava fechada B");
	}
	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QStringList ipList;
	QString sql;
	//	sql.sprintf("SELECT * FROM sessions WHERE nome = '%s'", sessao);
	query->prepare("SELECT * FROM sessions WHERE nome = :val_nome");
	query->bindValue(":val_nome", sessao);
	bool result = query->exec();
	qDebug() << query->lastError();
	if (result)
	{
		if (query->next())
		{
			ipList = query->value("ipList").toString().split(',');
		}
	}
	return ipList;
}
QStringList MagoDB::getNameListFromSession(QString sessao, QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::getNameListFromSession() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::getNameListFromSession() - Conexao estava fechada B");
	}
	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QStringList nameList;
	//QString sql;
	//sql.sprintf("SELECT * FROM sessions WHERE nome = '%s'", sessao);
	//	qDebug("sql = %s", sql.toLatin1().data());
	query->prepare("SELECT * FROM sessions WHERE nome = :val_nome");
	query->bindValue(":val_nome", sessao);
	bool result = query->exec();
	qDebug() << query->lastError();
	if (result)
	{
		if (query->next())
		{
			nameList = query->value("nameList").toString().split(',');
		}
	}
	return nameList;
}

QStringList MagoDB::getSessionNames(QSqlDatabase* connection)
{

	qDebug("getSessionNames - IN");
	if (!connection->isOpen())
	{
		qDebug("MagoDB::getSessionNames() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::getSessionNames() - Conexao estava fechada B");
	}
	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QStringList ipList;
	//QSqlQuery query;
	QString sql;
	sql.sprintf("SELECT * FROM sessions");
	qDebug("sql = %s", sql.toLatin1().data());
	query->prepare(sql);
	bool result = query->exec();
	qDebug() << query->lastError();
	if (result)
	{
		while (query->next())
		{
			ipList << query->value("nome").toString();
		}
	}
	return ipList;
}

void MagoDB::removeSession(QString sessao, QSqlDatabase* connection)
{
	qDebug("MagoDB::removeSession - IN");
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QString sql = "DELETE FROM sessions WHERE nome = :val_nome";
	query->prepare(sql);
	query->bindValue(":val_nome", sessao);
	if(!query->exec())
	{
		qDebug() << query->lastError();
		qDebug("lastQuery:", query->lastQuery());

	}



}

void MagoDB::addModalidadeMagoSend(QString nome, QString descricao,QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QString sql = "INSERT INTO modalidade (nome, descricao) VALUES (:val_nome, :val_descricao)";
	query->prepare(sql);
	query->bindValue(":val_nome", nome);
	query->bindValue(":val_descricao", descricao);
	if (!query->exec())
	{
		// Log error if the execution fails
		qDebug() << "Error executing query:" << query->lastError();
		qDebug("lastQuery:", query->lastQuery());
	}
}

void MagoDB::clearModalidadeMagoSend(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QString sql;
	sql.sprintf("DELETE FROM modalidade");
	qDebug("sql = %s", sql.toLatin1().data());
	query->prepare(sql);
	query->exec();
	qDebug() << query->lastError();
}

QVector<QPair<QString, QString>> MagoDB::getModalidadesMagoSend(QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::getSessionNames() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::getSessionNames() - Conexao estava fechada B");
	}
	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QVector<QPair<QString, QString>> modList;
	QString sql;
	sql.sprintf("SELECT * FROM modalidade");
	qDebug("sql = %s", sql.toLatin1().data());
	query->prepare(sql);
	bool result = query->exec();
	qDebug() << query->lastError();
	if (result)
	{
		while (query->next())
		{
			modList.append(QPair<QString, QString>(query->value("nome").toString(), query->value("descricao").toString()));
		}
	}
	return modList;
}

QStringList MagoDB::getUsersFromHistorico(QSqlDatabase *connection)
{
	QStringList users;
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	if (query->exec("SELECT DISTINCT usuario FROM historico"))
	{
		while (query->next())
		{
			QString usuario = query->value(0).toString();
			qDebug() << "getUsersFromHistorico - Usuario:" << usuario;
			users << usuario;
		}
	}
	else
	{
		qDebug() << "getUsersFromHistorico - Query execution failed: " << query->lastError().text();
	}
	return users;
}

bool MagoDB::AddDuracaoRealAtHistorico()
{
	QSqlQuery* query = new QSqlQuery();

	QString sql;

	sql.sprintf("DO $$ BEGIN BEGIN ALTER TABLE Historico ADD COLUMN duracaoreal int;"
				" EXCEPTION WHEN duplicate_column THEN RAISE NOTICE 'column duracaoreal already exists in historico.'; END;  END; $$");

	qDebug("query = %s",sql.toLatin1().data());

	query->prepare(sql);

	query->exec();

	return query;
}

bool MagoDB::InitDB(QSqlDatabase* connection)
{

	CreateTableHistorico(connection);
	CreateTableModalidades(connection);
	CreateTableSessions(connection);
	CreateTableOptions(connection);
	return true;
}

bool MagoDB::EventExistsByNumber(char* number)
{
	QSqlQuery query;

#ifdef _WIN32
	QString snumber = QString::fromLatin1(number).replace("\\", "\\\\");

#else
	QString snumber = QString::fromLatin1(number);
#endif

	QString sql;

	sql.sprintf("select count(numero) as total from  eventos where numero = \'%s\'",snumber.toLatin1().data());
	query.prepare(sql);

	bool result = query.exec();

	if (result)
	{
		if (query.next())
		{
			int count = query.value("total").toInt();
			qDebug("MagoDB::EventExistsByNumber [count = %d]", count);
			if (count >= 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

bool MagoDB::EventExistsByPath(char* path)
{
	QSqlQuery query;

#ifdef _WIN32
	QString spath = QString::fromLatin1(path).replace("\\", "\\\\");

#else
	QString spath = QString::fromLatin1(path);
#endif

	QString sql;

	sql.sprintf("select count(caminho) as total from  eventos where caminho = \'%s\'",spath.toLatin1().data());
	query.prepare(sql);

	bool result = query.exec();

	if (result)
	{
		if (query.next())
		{
			int count = query.value("total").toInt();

			if (count >= 1)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}

	return false;
}

void* MagoDB::loadAllEventsOrderByWithValueEqual(char* fieldName, char* fieldNameEqual, char* fieldValue)
{
	QSqlQuery* query = new QSqlQuery();

#ifdef _WIN32
	QString spath = QString::fromLatin1(fieldValue).replace("\\", "\\\\");

#else
	QString spath = QString::fromLatin1(fieldValue);
#endif

	QString sql;
	sql.sprintf("select * from eventos where %s = \'%s\' order by %s;", fieldNameEqual, spath.toLatin1().data(), fieldName);

	qDebug("query = %s",sql.toLatin1().data());

	query->prepare(sql);

	query->exec();

	return query;
}

void *MagoDB::getHistoryEntries(char *data, char *data2, char *entrada, char *saida, char *numero, char *titulo, int roteiro, int posicaoMesa, char *veiculacao)
{
	QSqlQuery* query = new QSqlQuery();

	QString sql = QString("select * from historico where ");
	bool validCArg = false;

	if(data)
	{
		if(data2 == nullptr)
			sql+= QString("data = \'%1\'").arg(data);
		else
			sql+= QString("(data between \'%1\' and \'%2\')").arg(data).arg(data2);

		validCArg = true;
	}

	if(entrada)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("entrada = \'%1\'").arg(entrada);
		validCArg = true;
	}

	if(saida)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("saida = \'%1\'").arg(saida);
		validCArg = true;
	}

	if(numero)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("numero = \'%1\'").arg(numero);
		validCArg = true;
	}

	if(titulo)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("titulo = \'%1\'").arg(titulo);
		validCArg = true;
	}

	if(roteiro >= 0)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("roteiro = %1").arg(roteiro);
		validCArg = true;
	}

	if(posicaoMesa >= 0)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("posicaoMesa = %1").arg(posicaoMesa);
		validCArg = true;
	}

	if(veiculacao)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("veiculacao = \'%1\'").arg(numero);
		validCArg = true;
	}

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();
	qDebug("sql query size = %d", query->size());

	return query;
}

void *MagoDB::getMagoSendHistoryEntries(char *data, char *data2, char *numero, char *titulo, char *caminho, char *modalidade, int duracao, char *ip, QStringList status, char* usuario, QSqlDatabase* connection)
{
	qDebug("MagoDB::getMagoSendHistoryEntries - data [%s]", data);
	qDebug("MagoDB::getMagoSendHistoryEntries - data2 [%s]", data2);
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QString sql = QString("select * from historico where ");
	bool validCArg = false;

	if(data)
	{
		if(data2 == nullptr)
			sql+= QString("data = \'%1\'").arg(data);
		else
			sql+= QString("(data between \'%1\' and \'%2\')").arg(data).arg(data2);

		validCArg = true;
	}

	if(numero)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("numero = \'%1\'").arg(numero);
		validCArg = true;
	}

	if(titulo)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("titulo = \'%1\'").arg(titulo);
		validCArg = true;
	}

	if(modalidade)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("modalidade = \'%1\'").arg(modalidade);
		validCArg = true;
	}

	if(duracao >=0 )
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("duracao = \'%1\'").arg(duracao);
		validCArg = true;
	}

	if(ip)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("ip = %1").arg(ip);
		validCArg = true;
	}

	if(status.size() > 0)
	{
		if(validCArg) sql += " and ";

		sql += "status IN(";

		for(int i = 0; i < status.size(); ++i)
		{
			if(i > 0) sql += ", ";
			sql += QString("'%1'").arg(status[i]);
		}

		sql += ")";
		validCArg = true;
	}
	if(usuario)
	{
		if(validCArg)
			sql+= " and ";

		sql+= QString("usuario = '%1'").arg(usuario);
		validCArg = true;
	}

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();
	qDebug("sql query size = %d", query->size());

	return query;
}

void *MagoDB::getHistoryFieldValues(char *fieldName)
{
	QSqlQuery* query = new QSqlQuery();

	QString sql;
	sql.sprintf("select DISTINCT %s from historico; ", fieldName);

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();

	qDebug("sql query size = %d", query->size());
	return query;
}

void* MagoDB::loadAllEventsOrderBy(char* fieldName)
{
	QSqlQuery* query = new QSqlQuery();

	//query->prepare("select * from eventos order by :fieldName;");
	//query->bindValue(":fieldName", fieldName);

	QString sql;
	sql.sprintf("select * from eventos order by %s; ", fieldName);

	query->prepare(sql);

	query->exec();

	return query;
}

bool MagoDB::AddEvent(char* numero, char* caminho, char* titulo, int tipo, int inicio, int thumb, int frames, char* data, char* validade, int usuario, char* modalidade)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("INSERT INTO eventos (numero, caminho, titulo, tipo, inicio, thumb, frames, data, validade, usuario, modalidade) "
				  "VALUES (:val_num, :val_cam, :val_tit, :val_tip, :val_ini, :val_tmb, :val_fra, :val_dat, :val_val, :val_usr, :val_mod)");

	query.bindValue(":val_num", numero);
	query.bindValue(":val_cam", caminho);

	query.bindValue(":val_tit", titulo);

	query.bindValue(":val_tip", tipo);

	query.bindValue(":val_ini", inicio);
	query.bindValue(":val_tmb", thumb);

	query.bindValue(":val_fra", frames);

	QDate datData = QDate::fromString(data, "dd/MM/yyyy");
	qDebug() << data;
	qDebug() << datData;

	if (datData.isValid())
	{
		qDebug() << "isValid";
		query.bindValue(":val_dat", datData);
	}
	else
	{
		qDebug() << "QVariant-Date";
		query.bindValue(":val_dat", QVariant(QVariant::Date));
	}

	QDate datValid = QDate::fromString(validade, "dd/MM/yyyy");
	qDebug() << validade;
	qDebug() << datValid;

	if (datValid.isValid())
	{
		qDebug() << "isValid";
		query.bindValue(":val_val", datValid);
	}
	else
	{
		qDebug() << "QVariant-Date";
		query.bindValue(":val_val", QVariant(QVariant::Date));
	}
	query.bindValue(":val_usr", usuario);
	query.bindValue(":val_mod", modalidade);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}
bool MagoDB::UpdateEvent(char* oldnumero, char* newnumero, char* caminho, char* titulo, int tipo, int inicio, int thumb, int frames, char* data, char* validade, int usuario, char*  modalidade)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET numero= :val_newnum, caminho= :val_cam, titulo=:val_tit, tipo= :val_tip, inicio= :val_ini, thumb= :val_tmb, frames= :val_fra, data= :val_dat, validade= :val_val, usuario= :val_usr, modalidade = :val_mod "
				  "WHERE numero= :val_oldnum");
	query.bindValue(":val_newnum", newnumero);
	query.bindValue(":val_cam", caminho);
	query.bindValue(":val_tit", titulo);
	query.bindValue(":val_tip", tipo);
	query.bindValue(":val_ini", inicio);
	query.bindValue(":val_tmb", thumb);
	query.bindValue(":val_fra", frames);
	QDate datData = QDate::fromString(data, "dd/MM/yyyy");
	if (datData.isValid())
	{
		query.bindValue(":val_dat", datData);
	}
	else
	{
		query.bindValue(":val_dat", QVariant(QVariant::Date));
	}
	QDate datValid = QDate::fromString(validade, "dd/MM/yyyy");
	if (datValid.isValid())
	{
		query.bindValue(":val_val", datValid);
	}
	else
	{
		query.bindValue(":val_val", QVariant(QVariant::Date));
	}
	query.bindValue(":val_usr", usuario);
	query.bindValue(":val_mod", modalidade);
	query.bindValue(":val_oldnum", oldnumero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::RenameEvent(char* oldnumero, char* newnumero)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET numero=:val_newnum WHERE numero=:val_oldnum");
	query.bindValue(":val_newnum", newnumero);
	query.bindValue(":val_oldnum", oldnumero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::RemoveEvent(char* numero)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("DELETE FROM eventos WHERE numero = :val_num");
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::RemoveAllEvents()
{
	bool resultado;
	QSqlQuery query;
	query.prepare("DELETE FROM eventos");

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventDuration(char* numero, int frames)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET frames = :val_frames WHERE numero = :val_num");
	query.bindValue(":val_frames", frames);
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventTitulo(char* numero, char* titulo)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET titulo = :val_tit WHERE numero = :val_num");
	query.bindValue(":val_tit", titulo);
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventFile(char* numero, char* caminho)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET caminho = :val_cam WHERE numero = :val_num");
	query.bindValue(":val_cam", caminho);
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventType(char* numero, int tipo)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET tipo = :val_tip WHERE numero = :val_num");
	query.bindValue(":val_tip", tipo);
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventInitPos(char* numero, int inicio)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET inicio = :val_ini WHERE numero = :val_num");
	query.bindValue(":val_ini", inicio);
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug()<< query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventThumb(char* numero, int thumb)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET thumb = :val_tmb WHERE numero = :val_num");
	query.bindValue(":val_tmb", thumb);
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug()<< query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventValidade(char* numero, char* validade)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET validade = :val_val WHERE numero = :val_num");
	QDate datValid = QDate::fromString(validade, "dd/MM/yyyy");
	if (datValid.isValid())
	{
		query.bindValue(":val_val", datValid);
	}
	else
	{
		query.bindValue(":val_val", QVariant(QVariant::Date));
	}
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::ChangeEventModalidade(char* numero, char* modalidade)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE eventos SET modalidade = :val_mod WHERE numero = :val_num");
	query.bindValue(":val_mod", modalidade);
	query.bindValue(":val_num", numero);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::AddProgram(char* codigo, char* titulo, int breaks, int frames, int posicaomesa)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("INSERT INTO programas (codigo, titulo, breaks, frames, posicaomesa) "
				  "VALUES (:val_cod, :val_tit, :val_brk, :val_fra, :val_pos)");
	query.bindValue(":val_cod", codigo);
	query.bindValue(":val_tit", titulo);
	query.bindValue(":val_brk", breaks);
	query.bindValue(":val_fra", frames);
	query.bindValue(":val_pos", posicaomesa);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::UpdateProgram(char* oldcodigo, char* newcodigo, char* titulo, int breaks, int frames, int posicaomesa)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE programas SET codigo = :val_newcod, titulo = :val_tit, breaks = :val_brk, frames = :val_fra, posicaomesa = :val_pos "
				  "WHERE codigo= :val_oldcod");
	query.bindValue(":val_newcod", newcodigo);
	query.bindValue(":val_tit", titulo);
	query.bindValue(":val_brk", breaks);
	query.bindValue(":val_fra", frames);
	query.bindValue(":val_pos", posicaomesa);
	query.bindValue(":val_oldcod", oldcodigo);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::RemoveProgram(char* codigo)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("DELETE FROM programas WHERE codigo = :val_cod");
	query.bindValue(":val_cod", codigo);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}

int MagoDB::AddHistoricoMagoSend(QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QString status, QString data, QString usuario, QSqlDatabase* connection)
{
	int resultado = -1;


	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	query->prepare("INSERT INTO historico (numero, titulo, caminho, modalidade, duracao, ip, status, data, usuario) "
				   "VALUES (:val_num, :val_tit, :val_cam, :val_mod, :val_dur, :val_ip, :val_sta, :val_dat, :val_usu) RETURNING id as id");
	query->bindValue(":val_num", numero);
	query->bindValue(":val_tit", titulo);
	query->bindValue(":val_cam", caminho);
	query->bindValue(":val_mod", modalidade);
	query->bindValue(":val_dur", duracao);
	query->bindValue(":val_ip", ip);
	query->bindValue(":val_sta", status);
	query->bindValue(":val_ent", data);
	query->bindValue(":val_usu", usuario);


	QDateTime datEnt = QDateTime::fromString(data, "yyyy-MM-dd hh:mm:ss");
	if (datEnt.isValid())
	{
		query->bindValue(":val_dat", datEnt);
	}
	else
	{
		query->bindValue(":val_dat", QVariant(QVariant::DateTime));
		//query.bindValue(":val_ent", "entradaaa");
	}

	if (query->exec())
	{
		if (query->next())
		{
			resultado = query->value("id").toInt();
		}
	}
	else
	{
		resultado = -1;
	}

	qDebug() << query->lastError();

	return resultado;
}

int MagoDB::AddUserMagoSend(char *usuario, char* senha, QSqlDatabase* connection)
{
	int resultado = -1;
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}

	QString sql;
	sql.sprintf("INSERT INTO login (usuario, senha) VALUES ('%s', '%s') RETURNING id as id", usuario, senha);

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	resultado = query->exec();
	qDebug() << query->lastError();
	return resultado;
}

bool MagoDB::userAlreadyExists(char *usuario, QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QString sql;
	sql.sprintf("select * from login where usuario = '%s'", usuario);

	qDebug("sql query = %s", sql.toLatin1().data());

	query->prepare(sql);

	query->exec();
	if(query->next())
	{
		qDebug() << query->lastError();
		return true;
	}
	else
	{
		qDebug() << query->lastError();
		return false;
	}

}

QString MagoDB::getUserPassword(char *usuario, QSqlDatabase* connection)
{
	if (!connection->isOpen())
	{
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada A");
		connection->open();
		qDebug("MagoDB::AddHistorico() - Conexao estava fechada B");
	}

	QSqlQuery* query = nullptr;
	if (connection != nullptr)
	{
		query = new QSqlQuery(*connection);
	}
	else
	{
		query = new QSqlQuery(Magodb);
	}
	QString passwordHash;
	QString sql;
	sql.sprintf("select * from login where usuario = '%s'", usuario);

	query->prepare(sql);

	bool result = query->exec();

	if (result)
	{
		if (query->next())
		{
			//ja retornamos no fortmato certo para ser utilziado como QString
			passwordHash = QString::fromLatin1(query->value("senha").toString().toUtf8().data());
			return passwordHash;
		}
	}

	return passwordHash;
}

int MagoDB::AddHistorico(char *numero, int duracaoreal, char *veiculacao, int roteiro, char *data, char *entrada, char *saida, int posicaomesa)
{

}

bool MagoDB::ChangeHistoricoSaida(int id, char* saida)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("UPDATE historico SET saida = :val_sai WHERE id= :val_id");
	query.bindValue(":val_sai", saida);
	query.bindValue(":val_id", id);

	resultado = query.exec();

	qDebug() << query.lastError();
	return resultado;
}

bool MagoDB::CleanHistorico()
{
	QSqlQuery query;
	bool resultado;

	resultado = query.exec(QLatin1String("TRUNCATE Historico"));

	qDebug() << query.lastError();

	return resultado;
}

bool MagoDB::RemoveHistorico(char* data)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("DELETE FROM historico WHERE data <= :val_dat");
	QDate datValid = QDate::fromString(data, "dd/MM/yyyy");
	if (datValid.isValid())
	{
		query.bindValue(":val_dat", datValid);
		resultado = query.exec();
	}
	else
	{
		resultado = false;
	}

	return resultado;
}

bool MagoDB::ChangeMagoDBVersion(char* version)
{
	bool resultado;
	QSqlQuery query;
	query.prepare("INSERT INTO version (magodb_version) VALUES (:val_ver)");
	query.bindValue(":val_ver", version);

	resultado = query.exec();

	qDebug() << query.lastError();

	return resultado;
}


QString MagoDB::GetMagoDBVersion()
{
	QSqlQuery* query = new QSqlQuery();

	QString sql;
	sql.sprintf("select * from version");

	query->prepare(sql);

	query->exec();

	return query->value("magodb_version").toString();
}

QString MagoDB::GetEventTitulo(char* number)
{
	QSqlQuery query(Magodb);

	QString snumber = QString::fromLatin1(number);

	QString titulo;

	QString sql;

	sql.sprintf("select titulo from eventos where numero = \'%s\'", snumber.toLatin1().data());
	query.prepare(sql);

	bool result = query.exec();

	if (result)
	{
		if (query.next())
		{
			//ja retornamos no fortmato certo para ser utilziado como QString dentro do Mago...
			titulo = QString::fromLatin1(query.value("titulo").toString().toUtf8().data());
			return titulo;
		}
	}

	return titulo;
}

QString MagoDB::GetEventModalidade(char* number)
{
	QSqlQuery query(Magodb);

	QString snumber = QString::fromLatin1(number);

	QString modalidade;

	QString sql;

	sql.sprintf("select modalidade from eventos where numero = \'%s\'", snumber.toLatin1().data());
	query.prepare(sql);

	bool result = query.exec();

	if (result)
	{
		if (query.next())
		{
			//ja retornamos no fortmato certo para ser utilziado como QString dentro do Mago...
			modalidade = QString::fromLatin1(query.value("modalidade").toString().toUtf8().data());
			return modalidade;
		}
	}

	return modalidade;
}

QStringList MagoDB::getModalidadesMago()
{
	QSqlQuery query;

	QStringList modalidades;
	if(query.exec("SELECT * FROM public.grupos"))
	{
		while(query.next())
		{
			modalidades << query.value(0).toString();
		}
	}
	else
	{
		qDebug() << query.lastQuery();
		qDebug() << query.lastError();

	}
	return modalidades;
}
