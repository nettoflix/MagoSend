#include "CModalidadesForm.h"
#include "ui_CModalidadesForm.h"

#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>
#include "mainwindow.h"
CModalidadesForm::CModalidadesForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CModalidadesForm)
{
	ui->setupUi(this);

	QStringList headers;
	headers << tr("Nome") << tr("Descrição");
	ui->tableWidget->setRowCount(0);
	ui->tableWidget->setColumnCount(headers.size());
	ui->tableWidget->setHorizontalHeaderLabels(headers);
	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
	ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	//loadModalidadesFromFile(QApplication::applicationDirPath() + "/Arquivos/.modalidades.dmo");
	loadModalidadesFromDB();
}

CModalidadesForm::~CModalidadesForm()
{
	delete ui;
}

void CModalidadesForm::addModToTable(QString &modName, QString &modDesc)
{
	for(int row=0; row<ui->tableWidget->rowCount(); row++)
	{
		QTableWidgetItem *currentItem = ui->tableWidget->item(row,0);
		if(currentItem->text() == modName)
		{
			return; //modalidade já existe na tabela
		}
	}
	int row = ui->tableWidget->rowCount();
	ui->tableWidget->setRowCount(ui->tableWidget->rowCount()+1);
	QTableWidgetItem* nameItem = new QTableWidgetItem(modName);
	QTableWidgetItem* descItem = new QTableWidgetItem(modDesc);
	//QTableWidgetItem* progresso = new QTableWidgetItem(videoInfo.progress);
	ui->tableWidget->setItem(row,0, nameItem);
	ui->tableWidget->setItem(row,1, descItem);
}

void CModalidadesForm::saveModsToFile(QString filePath)
{
	QFile file(filePath);
	qDebug() <<  filePath;
	// Open the file in write mode
	if (!file.open(QIODevice::WriteOnly| QIODevice::Text)) {
		qCritical() << "CModalidadesForm::saveModsToFile - Não conseguiu abrir o arquivo para escrever";
		return;
	}

	for(int row=0; row<ui->tableWidget->rowCount(); row++)
	{
		QString modName = ui->tableWidget->item(row,0)->text();
		QString modDesc = ui->tableWidget->item(row,1)->text();
		//QByteArray output = "iaaaoba";
		QTextStream out(&file);
		out.seek(file.size());
		out << modName + "|" + modDesc + "\n";
	}
	file.close();
}

void CModalidadesForm::loadModalidadesFromFile(QString filePath)
{
	ui->tableWidget->clearContents();;
	ui->tableWidget->setRowCount(0);
	QFile file(filePath);
	qDebug() <<  filePath.toLatin1().data();
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qCritical() << "Não conseguiu abrir o arquivo para ler";
		return;
	}
	QTextStream in(&file);
	while (!in.atEnd()) {
		QString line = in.readLine();
		QString modalidade = line.left(line.indexOf("|"));
		QString descricao = line.mid(line.indexOf("|")+1);
		addModToTable(modalidade, descricao);
	}
}

void CModalidadesForm::saveModsToDB()
{
//	MagoDB* db = new MagoDB();
//	db->clearModalidadeMagoSend();


//	for(int row=0; row<ui->tableWidget->rowCount(); row++)
//	{
//		QString modName = ui->tableWidget->item(row,0)->text();
//		QString modDesc = ui->tableWidget->item(row,1)->text();
//		db->addModalidadeMagoSend(modName.toLatin1().data(), modDesc.toLatin1().data());
//	}
}

void CModalidadesForm::loadModalidadesFromDB()
{
//	MagoDB* db = new MagoDB();
	//QVector<QPair<QString,QString>> modList = db->getModalidadesMagoSend();
//	for(QPair<QString, QString> modalidade : modList)
//	{
//		addModToTable(modalidade.first, modalidade.second);
//	}
//	delete db;
}

void CModalidadesForm::closeEvent(QCloseEvent *event)
{
	emit closed();
}

void CModalidadesForm::on_btn_adicionarModalidade_clicked()
{
	QString modName = ui->te_modName->toPlainText();
	QString modDesc = ui->te_modDesc->toPlainText();
	//lembrar de lidar com codificação da modalidades, aceitar só caracteres compatíveis com o Mago

	if(modName != "" && modDesc != "")
	{
		qDebug("OBA");
		addModToTable(modName, modDesc);
	}
}

void CModalidadesForm::on_btn_Ok_clicked()
{
	//saveModsToFile(QApplication::applicationDirPath() + "/Arquivos/.modalidades.dmo");
	saveModsToDB();
	MainWindow* mainWindow = static_cast<MainWindow*>(this->parentWidget());
	mainWindow->loadModComboBox();
	this->accept();
}

//importa modalidades
void CModalidadesForm::on_btn_importMods_clicked()
{
	QString filePath = QFileDialog::getOpenFileName(this, "Importar Modalidade", QApplication::applicationDirPath(),"Modalidades do Digisend (*.dmo)");
	loadModalidadesFromFile(filePath);
}

void CModalidadesForm::on_btn_ExportarMods_clicked()
{
	QString selectedFileName = QFileDialog::getSaveFileName(nullptr,
															"Exportar modalidades",
															QApplication::applicationDirPath() + "/export_modalidades",
															"Modalides do Digisend (*.dmo)");

	// Check if the user selected a file
	if (!selectedFileName.isEmpty()) {
		if(selectedFileName.endsWith(".dmo"))
		{
			saveModsToFile(selectedFileName);
		}
		else
		{
			saveModsToFile(selectedFileName + ".dmo");
		}

	}
	//abrir um dialog para escolher o caminho e nome do arquivo
	//saveModsToFile(caminho)
}

void CModalidadesForm::on_btn_remover_clicked()
{
	int index = ui->tableWidget->currentRow();
	if(index != -1 && ui->tableWidget->rowCount() > 0)
	{
		ui->tableWidget->removeRow(index);
	}
}

void CModalidadesForm::on_btn_removerTodas_clicked()
{
	ui->tableWidget->clearContents();
	ui->tableWidget->setRowCount(0);
}
