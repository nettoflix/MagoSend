/*
 * IMagoDB.h
 *
 *  Created on: 14/03/2018
 *      Author: Leo
 */

#ifndef IMagoDB_H_
#define IMagoDB_H_

#ifdef __linux__
#include "lindows.h"
#endif

#include <QtCore/qglobal.h>

class IMagoDB
{

public:

	virtual bool __stdcall InitDB() = 0;
	//data e validade = dd/MM/yyyy
	virtual bool __stdcall AddEvent(char* numero, char* caminho, char* titulo, int tipo, int inicio, int thumb, int frames, char* data, char* validade, int usuario, char*  modalidade) = 0;
	//data e validade = dd/MM/yyyy
	virtual bool __stdcall UpdateEvent(char* oldnumero, char* newnumero, char* caminho, char* titulo, int tipo, int inicio, int thumb, int frames, char*  data, char*  validade, int usuario, char*  modalidade) = 0;
	virtual bool __stdcall RenameEvent(char* oldnumero, char* newnumero) = 0;
	virtual bool __stdcall RemoveEvent(char* numero) = 0;
	virtual bool __stdcall RemoveAllEvents() = 0;
	virtual bool __stdcall ChangeEventDuration(char* numero, int frames) = 0;
	virtual	bool __stdcall ChangeEventTitulo(char* numero, char* titulo) = 0;
	virtual	bool __stdcall ChangeEventFile(char* numero, char* caminho) = 0;
	virtual	bool __stdcall ChangeEventType(char* numero, int tipo) = 0;
	virtual bool __stdcall ChangeEventInitPos(char * numero, int inicio) = 0;
	virtual bool __stdcall ChangeEventThumb(char * numero, int thumb) = 0;
	//validade = dd/MM/yyyy
	virtual	bool __stdcall ChangeEventValidade(char* numero, char* validade) = 0;
	virtual	bool __stdcall ChangeEventModalidade(char* numero, char*  modalidade) = 0;
	virtual bool __stdcall AddProgram(char* codigo, char* titulo, int breaks, int frames, int posicaomesa) = 0;
	virtual	bool __stdcall UpdateProgram(char* oldcodigo, char* newcodigo, char* titulo, int breaks, int frames, int posicaomesa) = 0;
	virtual	bool __stdcall RemoveProgram(char* codigo) = 0;
	//data = dd/MM/yyyy | entrada e saida = dd/MM/yyyy hh:mm:ss
	virtual int __stdcall AddHistorico(char* numero, int duracaoreal, char* veiculacao, int roteiro, char* data, char* entrada, char* saida, int posicaomesa) = 0;
	virtual bool __stdcall ChangeHistoricoSaida(int id, char* saida) = 0;
	virtual bool __stdcall CleanHistorico() = 0;
	//data = dd/MM/yyyy
	virtual	bool __stdcall RemoveHistorico(char* data) = 0;

	virtual bool __stdcall EventExistsByPath(char* path) = 0;
	virtual bool __stdcall EventExistsByNumber(char* number) = 0;

	virtual void* __stdcall loadAllEventsOrderBy(char* fieldName) = 0;

    virtual QString __stdcall GetEventTitulo(char* number) = 0;
    virtual QString __stdcall GetEventModalidade(char* number) = 0;

	virtual void* __stdcall loadAllEventsOrderByWithValueEqual(char* fieldName, char* fieldNameEqual, char* fieldValue) = 0;
	virtual void* __stdcall getHistoryEntries(char* data = nullptr, char* data2 = nullptr,char* entrada = nullptr, char* saida = nullptr, char* numero = nullptr, char* titulo = nullptr, int roteiro = -1, int posicaoMesa = -1, char* veiculacao =nullptr) = 0;
	virtual void* __stdcall getMagoSendHistoryEntries(char* data = nullptr, char *data2 = nullptr, char* numero = nullptr, char* titulo = nullptr, char* caminho = nullptr, char* modalidade = nullptr, int duracao = -1, char* ip = nullptr, char* status = nullptr, char* usuario=nullptr) = 0;
    virtual void* __stdcall getHistoryFieldValues(char * fieldName) = 0;
	virtual bool __stdcall ChangeMagoDBVersion(char* version) = 0;
	virtual QString __stdcall GetMagoDBVersion() = 0;
};

extern "C"
{
Q_DECL_EXPORT IMagoDB* CreateDB();
Q_DECL_EXPORT void DropDB();
}

#endif /* IMagoDB_H_ */
