#ifndef CHISTORICOFORM_H
#define CHISTORICOFORM_H

#include "CBDQuery.h"

#include <QDialog>
#include <QWidget>
#include <QTableWidgetItem>
namespace Ui {
class CHistoricoForm;
}
class QDateTimeWidgetItem : public QTableWidgetItem
{
public:
	QDateTimeWidgetItem(const QString& str) : QTableWidgetItem(str) {}

	bool operator <(const QTableWidgetItem &other) const
	{
		return QDateTime::fromString(text(), "dd/MM/yyyy hh:mm:ss") < QDateTime::fromString(other.text(), "dd/MM/yyyy hh:mm:ss");
	}
};

class CHistoricoForm : public QDialog
{
	Q_OBJECT

public:
	explicit CHistoricoForm(QWidget *parent = 0);
	~CHistoricoForm();


	void populateTable(QList<CDBHistoryEntry> entries);
	void initTable();
	QList<CDBHistoryEntry> filterEntriesByKeyword(QList<CDBHistoryEntry> entries);
	void refresh();
private slots:
	void on_refreshButton_clicked();

	void on_okButton_clicked();

private:
	Ui::CHistoricoForm *ui;
};

#endif // CHISTORICOFORM_H
