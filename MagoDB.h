/*
 * MagoDB.h
 *
 *  Created on: 14/03/2018
 *      Author: Leo
 */

#ifndef MAGODB_H_
#define MAGODB_H_

#include "IMagoDB.h"

#include <QtSql>
#include <QDate>

class IMagoDB;

class MagoDB: public IMagoDB
{

public:
	QSqlDatabase Magodb;
	 MagoDB(char* IP, bool useRandomConnectionName);
	virtual  ~MagoDB();
	QString databaseName() const;
	int getDbPort();
	bool __stdcall CreateDB(char* IP, QString dbName,int dbPort, bool useRandomConnectionName);
	bool __stdcall CreateTableEventos();
	bool __stdcall CreateTableProgramas();
	bool __stdcall CreateTableHistorico(QSqlDatabase* connection);
	bool __stdcall CreateTableLogin(QSqlDatabase* connection);
	bool __stdcall CreateTableVersion();
	bool __stdcall CreateTableSessions(QSqlDatabase* connection);
	bool __stdcall CreateTableModalidades(QSqlDatabase* connection);
	bool __stdcall CreateTableOptions(QSqlDatabase* connection);
	bool __stdcall updateSendOptions(bool shouldOverwriteFile, bool shouldOverwriteId, QSqlDatabase* connection);
	bool __stdcall updateStatusFilter(bool showErrors = false, bool showSuccess = false, QSqlDatabase* connection= nullptr);
	bool __stdcall shouldShowErrors(QSqlDatabase* connection);
	bool __stdcall shouldShowSuccess(QSqlDatabase* connection);
	//bool __stdcall ensureColumnExists(const QString &table_name,const QString &columnName, const QString &columnType);
	bool __stdcall doesSessionExists(QString sessao, QSqlDatabase* connection);
	bool __stdcall warningWhenOverwriteFile(QSqlDatabase* connection);
	bool __stdcall warningWhenOverwriteId(QSqlDatabase* connection);
	void __stdcall updateSessionIpList(QString sessao, QString ipList, QString nameList, QSqlDatabase* connection);
	void __stdcall createRowOnSessionTable(QString sessao, QString ipList, QString nameList, QSqlDatabase* connection);
	QStringList __stdcall getIpListFromSession(QString sessao,QSqlDatabase* connection);
	QStringList __stdcall getNameListFromSession(QString sessao,QSqlDatabase* connection);
	QStringList __stdcall getSessionNames(QSqlDatabase* connection);
	void __stdcall removeSession(QString sessao, QSqlDatabase* connection);
	void __stdcall addModalidadeMagoSend(QString nome, QString descricao, QSqlDatabase* connection);
	void __stdcall clearModalidadeMagoSend(QSqlDatabase* connection);
	QVector<QPair<QString, QString>> __stdcall getModalidadesMagoSend(QSqlDatabase* connection);
	QStringList __stdcall getUsersFromHistorico(QSqlDatabase *connection);
	bool __stdcall InitDB(QSqlDatabase* connection);
	bool __stdcall AddEvent(char* numero, char* caminho, char* titulo, int tipo, int inicio, int thumb, int frames, char* data, char* validade, int usuario, char* modalidade);
	bool __stdcall UpdateEvent(char* oldnumero, char* newnumero, char* caminho, char * titulo, int tipo, int inicio, int thumb, int frames, char* data, char* validade, int usuario, char* modalidade);
	bool __stdcall RenameEvent(char* oldnumero, char* newnumero);
	bool __stdcall RemoveEvent(char* numero);
	bool __stdcall RemoveAllEvents();
	bool __stdcall ChangeEventDuration(char* numero, int frames);
	bool __stdcall ChangeEventTitulo(char* numero, char* titulo);
	bool __stdcall ChangeEventFile(char* numero, char* caminho);
	bool __stdcall ChangeEventType(char* numero, int tipo);
	bool __stdcall ChangeEventInitPos(char * numero, int inicio);
	bool __stdcall ChangeEventThumb(char * numero, int thumb);
	bool __stdcall ChangeEventValidade(char* numero, char* validade);
	bool __stdcall ChangeEventModalidade(char* numero, char*  modalidade);
	bool __stdcall AddProgram(char* codigo, char* titulo, int breaks, int frames, int posicaomesa);
	bool __stdcall UpdateProgram(char* oldcodigo, char* newcodigo, char* titulo, int breaks, int frames, int posicaomesa);
	bool __stdcall RemoveProgram(char* codigo);
	int __stdcall AddHistoricoMagoSend(QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QString status, QString data, QString usuario, QSqlDatabase* connection);
	int __stdcall AddUserMagoSend(char* usuario, char* senha, QSqlDatabase* connection);
	bool __stdcall userAlreadyExists(char* usuario, QSqlDatabase* connection);
	QString __stdcall getUserPassword(char* usuario, QSqlDatabase* connection);
	int __stdcall AddHistorico(char* numero, int duracaoreal, char* veiculacao, int roteiro, char* data, char* entrada, char* saida, int posicaomesa);
	bool __stdcall ChangeHistoricoSaida(int id, char* saida);
	bool __stdcall CleanHistorico();
	bool __stdcall RemoveHistorico(char* data);
	bool __stdcall AddDuracaoRealAtHistorico();
	bool __stdcall EventExistsByPath(char* path);
	bool __stdcall EventExistsByNumber(char* number);
	void* __stdcall loadAllEventsOrderBy(char* fieldName);
	void* __stdcall loadAllEventsOrderByWithValueEqual(char* fieldName, char* fieldNameEqual, char* fieldValue);
	void* __stdcall getHistoryEntries(char* data = nullptr, char *data2 = nullptr, char* entrada = nullptr, char* saida = nullptr, char* numero = nullptr, char* titulo = nullptr, int roteiro = -1, int posicaoMesa = -1, char* veiculacao =nullptr);
	void* __stdcall getMagoSendHistoryEntries(char* data = nullptr, char *data2 = nullptr, char* numero = nullptr, char* titulo = nullptr, char* caminho = nullptr, char* modalidade = nullptr, int duracao = -1, char* ip = nullptr, QStringList status = QStringList(), char* usuario=nullptr, QSqlDatabase* connection=nullptr);
	void* __stdcall getHistoryFieldValues(char * fieldName);
    QString __stdcall GetEventTitulo(char* number);
    QString __stdcall GetEventModalidade(char* number);
    bool __stdcall ChangeMagoDBVersion(char* version);
	QString __stdcall GetMagoDBVersion();

};

#endif /* MAGODB_H_ */
