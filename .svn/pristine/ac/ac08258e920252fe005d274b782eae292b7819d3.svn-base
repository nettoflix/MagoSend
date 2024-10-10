#ifndef CBDQUERY_H
#define CBDQUERY_H

#include <QDate>
#include <QDateTime>
#include "MagoDB.h"

struct CDBHistoryEntry
{
    bool operator<(const CDBHistoryEntry& other) const
    {
		return data < other.data;
    }

	QString numero="";
	QString titulo="";
	QString caminho="";
	QString modalidade="";
	int duracao;
	QString ip="";
	QString status="";
	QDateTime data;
	QString usuario="";
};


class CBDQuery
{
public:
    CBDQuery();

	QList<CDBHistoryEntry> getEntries(QDateTime dateIN = QDateTime(), QDateTime dateOUT = QDateTime(), QString numero = "", QString titulo = "", QString caminho="", QString modalidade="", int duracao=-1, QString ip="", QStringList status = QStringList(), QString usuario="");


private:
    IMagoDB * db;

};

#endif // CBDQUERY_H
