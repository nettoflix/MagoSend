#include "CBDQuery.h"
#include "CDateUtils.h"
#include <cmath>

CBDQuery::CBDQuery()
{
	db = CreateDB();
	//MagoDB* magosendDB = static_cast<MagoDB*>(db);
}

QList<CDBHistoryEntry> CBDQuery::getEntries(QDateTime dateIN, QDateTime dateOUT, QString numero, QString titulo, QString caminho, QString modalidade, int duracao, QString ip, QStringList status, QString usuario)
{
	MagoDB* magodb = (MagoDB*) db;
	QSqlQuery* query = (QSqlQuery*) magodb->getMagoSendHistoryEntries(dateIN.isValid() ? dateIN.toString("dd/MM/yyyy hh:mm:ss").toLatin1().data() : nullptr,
														  dateOUT.isValid() ? dateOUT.toString("dd/MM/yyyy hh:mm:ss").toLatin1().data() : nullptr,
														  !numero.isEmpty() ? numero.toLatin1().data()  : nullptr,
														  !titulo.isEmpty() ? titulo.toLatin1().data()  : nullptr,
														  !caminho.isEmpty() ? caminho.toLatin1().data()  : nullptr,
														  !modalidade.isEmpty() ? modalidade.toLatin1().data()  : nullptr,
														  duracao,
														  !ip.isEmpty() ? ip.toLatin1().data()  : nullptr,
														  status,
														  !usuario.isEmpty() ? usuario.toLatin1().data() : nullptr
														  );

	QList<CDBHistoryEntry> entries;


	if (query != nullptr)
	{

		while (query->next())
		{
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
//						qDebug("Entry:");
//						qDebug("entry.data = %s", entry.data.toString("dd/MM/yyyy - hh:mm:ss.zzz").toLatin1().data());
//						qDebug() << "entry.numero =" << entry.numero;
//						qDebug() << "entry.titulo =" << entry.titulo;
//						qDebug() << "entry.caminho =" << entry.caminho;
//						qDebug() << "entry.modalidade =" << entry.modalidade;
//						qDebug() << "entry.ip =" << entry.ip;
//						qDebug() << "entry.duracao =" << entry.duracao;
//						qDebug() << "entry.status =" << entry.status;
//						qDebug() << "entry.usuario = " << entry.usuario;

			 entries.push_back(entry);
		}
	}
	delete query;

	return entries;
}








