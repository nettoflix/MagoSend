#include "CHistoricoForm.h"
#include "VideoFileInfo.h"
#include "ui_CHistoricoForm.h"
#include "CMagoDBCommandsThread.h"
#include <QMessageBox>

CHistoricoForm::CHistoricoForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CHistoricoForm)
{
	ui->setupUi(this);

	ui->dateEdit_1->setDate(QDate::currentDate());
	ui->dateEdit_2->setDate(QDate::currentDate());
	QTime time2(23,59,59);
	ui->timeEdit_2->setTime(time2);
	initTable();

//	db = new MagoDB();
	bool shouldShowErrors = CMagoDBCommandsThread::commands->historicoShouldShowErrors();
	bool shouldShowSuccess = CMagoDBCommandsThread::commands->historicoShouldShowSuccess();
	ui->cb_showErrors->setChecked(shouldShowErrors);
	ui->cb_showSuccess->setChecked(shouldShowSuccess);

	QStringList users = CMagoDBCommandsThread::commands->getUsersFromHistorico();
	QStringList usersFinal;
	usersFinal << "Todos Usuários" << users;
	ui->cb_usuarios->addItems(usersFinal);

	//populateTable(entries);

}

CHistoricoForm::~CHistoricoForm()
{
	 CMagoDBCommandsThread::commands->updateStatusFilter(ui->cb_showSuccess->isChecked(), ui->cb_showErrors->isChecked());
	delete ui;
	//delete db;
}

void CHistoricoForm::populateTable(QList<CDBHistoryEntry> entries)
{
	qDebug("CHistoricoForm::populateTable - IN");

	ui->tableWidget->setRowCount(entries.size());
	int sortedColumn = ui->tableWidget->horizontalHeader()->sortIndicatorSection();
	Qt::SortOrder sortOrder =  ui->tableWidget->horizontalHeader()->sortIndicatorOrder();
	QFont fnt("Arial", 12);
	QTableWidgetItem* tableItem;
	QString lowerStr;

	for (int i = 0; i < entries.size(); ++i)
	{
		CDBHistoryEntry entry = entries.at(i);
		//Data
		//qDebug("entry: [%d]", i);

		tableItem = new QDateTimeWidgetItem(entry.data.toString("dd/MM/yyyy hh:mm:ss"));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 0, tableItem);

		//Status

		lowerStr = entry.status.toLower();
		lowerStr[0] = lowerStr[0].toUpper();
		//		qDebug("LowerStr: [%s]", lowerStr.toLatin1().data());
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 6, tableItem);

		//ID
		lowerStr = entry.numero.toLower();
		lowerStr[0] = lowerStr[0].toUpper();
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 1, tableItem);

		//Titulo
		lowerStr = entry.titulo.toLower();
		lowerStr[0] = lowerStr[0].toUpper();
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 2, tableItem);
		//Caminho
		lowerStr = entry.caminho.toLower();
		lowerStr[0] = lowerStr[0].toUpper();
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 4, tableItem);
		//modalidade
		lowerStr = entry.modalidade.toLower();
		lowerStr[0] = lowerStr[0].toUpper();
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 5, tableItem);
		//duracao
		lowerStr = QString::number(entry.duracao);
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 3, tableItem);
		//IP
		lowerStr = entry.ip.toLower();
		lowerStr[0] = lowerStr[0].toUpper();
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 8, tableItem);
		//Usuário
		lowerStr = entry.usuario.toLower();
		lowerStr[0] = lowerStr[0].toUpper();
		tableItem = new QTableWidgetItem(QString(lowerStr));
		tableItem->setTextAlignment(Qt::AlignCenter);
		tableItem->setFont(fnt);
		ui->tableWidget->setItem(i, 7, tableItem);
		//		qDebug("entry.data: [%s]", entry.data.toString().toLatin1().data());
		//		qDebug("entry.status: [%s]", entry.status.toLatin1().data());
		//		qDebug("entry.numero: [%s]", entry.numero.toLatin1().data());
	}
	ui->tableWidget->setSortingEnabled(true);
	ui->tableWidget->sortItems(sortedColumn, sortOrder);
}
void CHistoricoForm::initTable()
{
	QStringList headers;
	headers << tr("Data") << tr("ID") << tr("Título") << tr("Duração")
			<< tr("Caminho") << tr("Modalidade") << tr("Status")
			<< tr("Usuário") << tr("IP");
	ui->tableWidget->setRowCount(0);
	ui->tableWidget->setColumnCount(headers.size());
	ui->tableWidget->setHorizontalHeaderLabels(headers);
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->tableWidget->setSelectionMode(QAbstractItemView::ExtendedSelection);

	ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
	//ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
	//ui->tableWidget->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
	//ui->tableWidget->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
	//ui->tableWidget->horizontalHeader()->setSectionResizeMode(3, QHeaderView::ResizeToContents);
	ui->tableWidget->setSortingEnabled(false);
	ui->tableWidget->sortByColumn(0, Qt::AscendingOrder);
}

QList<CDBHistoryEntry> CHistoricoForm::filterEntriesByKeyword(QList<CDBHistoryEntry> entries)
{
	QList<CDBHistoryEntry> entriesFinal;
	for (int i =0; i < entries.size(); i++)
	{
		CDBHistoryEntry entry = entries.at(i);
		QString keyword = ui->le_keyword->text();

		// Adicionado checkBox para busca

		if (ui->ckbExactNumber->isChecked())
		{

			if(keyword.isEmpty() || ( !(QString::compare(keyword, entry.numero, Qt::CaseInsensitive)) ) || ( !(QString::compare(keyword, entry.titulo, Qt::CaseInsensitive)) ) )
			{
				entriesFinal.append(entry);
			}
		} else {
			if(keyword.isEmpty() || ((entry.numero.contains(keyword, Qt::CaseInsensitive)) || (entry.titulo.contains(keyword, Qt::CaseInsensitive))))
			{
				entriesFinal.append(entry);
			}
		}
	}
	return entriesFinal;
}


QStringList CHistoricoForm::getSuccessStatus()
{
	QStringList list = {"ENVIADO"};
	return list;
}

QStringList CHistoricoForm::getErrorStatus()
{
	QStringList list = {"IMPOSSIVEL CONECTAR-SE AO HOST", "FALHA DURANTE O ENVIO DO ARQUIVO", "ARQUIVO NAO EXISTE"};
	return list;
}

void CHistoricoForm::refresh()
{
	ui->tableWidget->setSortingEnabled(false);
	ui->tableWidget->clearContents();
	ui->tableWidget->setRowCount(0);
	QDate dateStart = ui->dateEdit_1->date();
	QDate dateEnd = ui->dateEdit_2->date();
	QTime timeStart = ui->timeEdit_1->time();
	QTime timeEnd = ui->timeEdit_2->time();
	QDateTime dateTimeStart(dateStart, timeStart);
	QDateTime dateTimeEnd(dateEnd, timeEnd);
	if(dateTimeStart > dateTimeEnd)
	{
		QMessageBox::information(this, QLatin1String("Datas invalidas"), QLatin1String("Escolha uma data inicial anterior a data final"));
		return;
	}
	//qDebug("dateStart [%s]", dateStart.toString("yyyy-MM-dd").toLatin1().data());
	//qDebug("dateEnd [%s]", dateEnd.toString("yyyy-MM-dd").toLatin1().data());
	//qDebug("dateTimeStart [%s]", dateTimeStart.toString("yyyy-MM-dd hh:mm:ss").toLatin1().data());
	//qDebug("dateTimeEnd [%s]", dateTimeEnd.toString("yyyy-MM-dd hh:mm:ss").toLatin1().data());
	CBDQuery query;
	QList<CDBHistoryEntry> entries;
	QStringList statusList;
	statusList.append("CANCELADO");
	if(ui->cb_showSuccess->isChecked())
	{
		statusList.append(getSuccessStatus());
	}
	if(ui->cb_showErrors->isChecked())
	{
		statusList.append(getErrorStatus());
	}

	 //entries = query.getEntries(dateTimeStart, dateTimeEnd, "","","","",-1,"",statusList,"");
	if(ui->cb_usuarios->currentText() == "Todos Usuários")
	{
		entries = CMagoDBCommandsThread::commands->getMagoSendHistoryEntries(dateTimeStart.toString("dd/MM/yyyy hh:mm:ss"),
																									   dateTimeEnd.toString("dd/MM/yyyy hh:mm:ss"),
																									   "",
																									   "",
																									   "",
																									   "",
																									   -1,
																									   "",
																									   statusList,
																									   "");
	}
	else
	{
		entries = CMagoDBCommandsThread::commands->getMagoSendHistoryEntries(dateTimeStart.toString("dd/MM/yyyy hh:mm:ss"),
																									   dateTimeEnd.toString("dd/MM/yyyy hh:mm:ss"),
																									   "",
																									   "",
																									   "",
																									   "",
																									   -1,
																									   "",
																									   statusList,
																									   ui->cb_usuarios->currentText());
	}

	//QList<CDBHistoryEntry> entriesFiltered = filterEntriesByStatus(entries);
	QList<CDBHistoryEntry> entriesFinal = filterEntriesByKeyword(entries );
	populateTable(entriesFinal);
}

void CHistoricoForm::resizeEvent(QResizeEvent *event)
{
	int tableWidth = ui->tableWidget->viewport()->width();
	int columnCount = ui->tableWidget->columnCount();
	int columnWidth = tableWidth / columnCount;
	for (int i = 0; i < columnCount; ++i) {
		ui->tableWidget->setColumnWidth(i, columnWidth);
	}
}

void CHistoricoForm::showEvent(QShowEvent *event)
{
	int tableWidth = ui->tableWidget->viewport()->width();
	int columnCount = ui->tableWidget->columnCount();
	int columnWidth = tableWidth / columnCount;
	for (int i = 0; i < columnCount; ++i) {
		ui->tableWidget->setColumnWidth(i, columnWidth);
	}
}

void CHistoricoForm::on_refreshButton_clicked()
{
	refresh();
}

void CHistoricoForm::on_okButton_clicked()
{
//	ui->tableWidget->setSortingEnabled(false);
//	ui->tableWidget->clearContents();
//	ui->tableWidget->setRowCount(0);
//	QDate dateStart = ui->dateEdit_1->date();
//	QDate dateEnd = ui->dateEdit_2->date();
//	QTime timeStart = ui->timeEdit_1->time();
//	QTime timeEnd = ui->timeEdit_2->time();
//	QDateTime dateTimeStart(dateStart, timeStart);
//	QDateTime dateTimeEnd(dateEnd, timeEnd);
//	//qDebug("dateStart [%s]", dateStart.toString("yyyy-MM-dd").toLatin1().data());
//	//qDebug("dateEnd [%s]", dateEnd.toString("yyyy-MM-dd").toLatin1().data());
//	//qDebug("dateTimeStart [%s]", dateTimeStart.toString("yyyy-MM-dd hh:mm:ss").toLatin1().data());
//	//qDebug("dateTimeEnd [%s]", dateTimeEnd.toString("yyyy-MM-dd hh:mm:ss").toLatin1().data());
//	CBDQuery query;
//	QList<CDBHistoryEntry> entries = query.getEntries(dateTimeStart,dateTimeEnd);
//	QList<CDBHistoryEntry> entriesFinal = filterEntriesByKeyword(entries);
//	populateTable(entriesFinal);
	refresh();
}



void CHistoricoForm::on_cb_showErrors_clicked()
{

}
