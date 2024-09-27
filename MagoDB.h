/*
 * MagoDB.h
 *
 *  Created on: 14/03/2018
 *      Author: Leo
 */

#ifndef MAGODB_H_
#define MAGODB_H_

#include "IMagoDB.h"
#include <QSqlDatabase>
#include <QtSql>
#include <QDate>

class IMagoDB;

class MagoDB: public IMagoDB
{

public:
	QSqlDatabase Magodb;
	MagoDB(QString remoteIp = QString(""));
	virtual  ~MagoDB();
	QString databaseName() const;
	int getDbPort();
	bool __stdcall CreateDB(char* IP, QString dbName,int dbPort, bool useRandomConnectionName);
	bool __stdcall CreateTableEventos();
	bool __stdcall CreateTableProgramas();
	bool __stdcall CreateTableHistorico();
	bool __stdcall CreateTableLogin();
	bool __stdcall CreateTableVersion();
	bool __stdcall CreateTableSessions();
	bool __stdcall CreateTableModalidades();
	bool __stdcall CreateTableOptions();
	bool __stdcall updateSendOptions(bool shouldOverwriteFile, bool shouldOverwriteId);
	//bool __stdcall ensureColumnExists(const QString &table_name,const QString &columnName, const QString &columnType);
	bool __stdcall doesSessionExists(char* sessao);
	bool __stdcall warningWhenOverwriteFile();
	bool __stdcall warningWhenOverwriteId();
	void __stdcall updateSessionIpList(char* sessao, char* ipList, char* nameList);
	void __stdcall createRowOnSessionTable(char* sessao, char* ipList, char *nameList);
	QStringList __stdcall getIpListFromSession(char* sessao);
	QStringList __stdcall getNameListFromSession(char *sessao);
	QStringList __stdcall getSessionNames();
	void __stdcall removeSession(char* sessao);
	void __stdcall addModalidadeMagoSend(char* nome, char* descricao);
	void __stdcall clearModalidadeMagoSend();
	QVector<QPair<QString, QString>> getModalidadesMagoSend();
	bool __stdcall InitDB();
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
	int __stdcall AddHistoricoMagoSend(char* numero, char* titulo, char* caminho, char* modalidade, int duracao, char* ip, char* status, char* data, char* usuario);
	int __stdcall AddUserMagoSend(char* usuario, char* senha);
	bool __stdcall userAlreadyExists(char* usuario);
	QString __stdcall getUserPassword(char* usuario);
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
	void* __stdcall getMagoSendHistoryEntries(char* data = nullptr, char *data2 = nullptr, char* numero = nullptr, char* titulo = nullptr, char* caminho = nullptr, char* modalidade = nullptr, int duracao = -1, char* ip = nullptr, char* status = nullptr, char* usuario=nullptr);
	void* __stdcall getHistoryFieldValues(char * fieldName);
    QString __stdcall GetEventTitulo(char* number);
    QString __stdcall GetEventModalidade(char* number);
    bool __stdcall ChangeMagoDBVersion(char* version);
	QString __stdcall GetMagoDBVersion();

};

#endif /* MAGODB_H_ */
