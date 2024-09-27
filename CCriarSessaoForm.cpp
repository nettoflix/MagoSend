#include "CCriarSessaoForm.h"
#include "ui_CCriarSessaoForm.h"
#include "CServiceUtils.h"
#include "CEditarSessaoForm.h"

#include <QMessageBox>
#include <QSettings>
CCriarSessaoForm::CCriarSessaoForm(QWidget *parent, QString sessionName, bool readOnly) :
	QDialog(parent),
	ui(new Ui::CCriarSessaoForm)
{
	ui->setupUi(this);
	ui->listWidget_ips->setColumnCount(2);
	ui->listWidget_ips->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
	ui->listWidget_ips->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
	ui->listWidget_ips->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->listWidget_ips->setSelectionMode(QAbstractItemView::NoSelection);

	db = new MagoDB();
	this->setWindowTitle("Criar Sessão");
	ui->te_Sessao->setText(sessionName);
	if(readOnly)
	{
		ui->te_Sessao->setReadOnly(true);
		this->setWindowTitle("Editar sessão");
		loadSessao();
	}


}

CCriarSessaoForm::~CCriarSessaoForm()
{
	delete ui;
	delete db;
}

void CCriarSessaoForm::loadSessao()
{
	//carregar as sessões da DB
	QStringList ipsList = db->getIpListFromSession(ui->te_Sessao->toPlainText().toLatin1().data());
	QStringList nameList = db->getNameListFromSession(ui->te_Sessao->toPlainText().toLatin1().data());
	qDebug()<< "CCriarSessaoForm::loadSessao() - nameList: " << nameList;
	qDebug()<< "CCriarSessaoForm::loadSessao() - ipList: " << ipsList;
	int row = 0;
	for(QString ip : ipsList)
	{
		QTableWidgetItem* ip_ = new QTableWidgetItem(ip);

		QTableWidgetItem* nome = new QTableWidgetItem(nameList.at(row));
		ui->listWidget_ips->setRowCount(row + 1);
		//row = ui->listWidget_ips->rowCount();
		ui->listWidget_ips->setItem(row, 0 , nome);
		ui->listWidget_ips->setItem(row, 1, ip_);
		row++;
	}
}

void CCriarSessaoForm::on_btn_adicionarIP_clicked()
{
	QString ip = ui->le_ip->text();
	QString nome_ = ui->le_nome->text();
	if(nome_.isEmpty())
	{
		//QMessageBox::warning(this, "Nome vazio", "Dê um nome ao Host", QMessageBox::Ok);
		//return;
	}
	bool toAdd = true;
	if(ip != "" && CServiceUtils::isValidIPv4format(ip))
	{

		for(int i=0; i<ui->listWidget_ips->rowCount(); i++)
		{
			QString currentIp = ui->listWidget_ips->item(i,0)->text();
			if(ip == currentIp) //ip já existe
			{
				toAdd=false;
			}

		}
	}
	else
	{
		toAdd = false;
	}
	if(toAdd)
	{

		int rowCount = ui->listWidget_ips->rowCount();
		ui->listWidget_ips->setRowCount(rowCount + 1);

		QTableWidgetItem* ip_ = new QTableWidgetItem(ip);
		QTableWidgetItem* nome = new QTableWidgetItem(nome_);
		ui->listWidget_ips->setItem(rowCount, 0, nome);
		ui->listWidget_ips->setItem(rowCount, 1, ip_);
	}
	else
	{
		QMessageBox::warning(this, "IP inválido", "O endereço de IP informado é inválido ou já existe", QMessageBox::Ok);
	}
}



void CCriarSessaoForm::on_btn_Salvar_clicked()
{

	QString sessionName = ui->te_Sessao->toPlainText();
	QStringList ipList;
	QStringList nameList;
	if(sessionName != "")
	{
		int listSize = ui->listWidget_ips->rowCount();
		for(int i=0; i<listSize; i++)
		{
			QString ip = ui->listWidget_ips->item(i,1)->text();
			ipList << ip;
			nameList << ui->listWidget_ips->item(i,0)->text();
			//qDebug() << " CCriarSessaoForm::on_btn_Salvar_clicked - nameList: " <<nameList;

		}
	}
	else
	{
		QMessageBox::warning(this, "Nome indefinido", "Dê um nome para a sessão", QMessageBox::Ok);
		return;
	}
	if(!ipList.isEmpty())
	{
		//salvar a lista de ip's na row da sessão


		if(db->doesSessionExists(sessionName.toLatin1().data())) //se sessao ja existe na db, atualiza a ipList dessa sessao
		{
			db->updateSessionIpList(sessionName.toLatin1().data(),ipList.join(",").toLatin1().data(), nameList.join(',').toLatin1().data());
		}
		else	//se a sessao nao existe na db, cria ela
		{
			db->createRowOnSessionTable(sessionName.toLatin1().data(), ipList.join(',').toLatin1().data(), nameList.join(',').toLatin1().data());
		}

		CEditarSessaoForm* parent = static_cast<CEditarSessaoForm*> (this->parent());
		parent->init();
		this->accept();
	}
	else
	{
		QMessageBox::warning(this, "Lista vazia", "Não há nenhum IP na lista", QMessageBox::Ok);
	}


}

void CCriarSessaoForm::on_btn_removerIp_clicked()
{
	int currentRow = ui->listWidget_ips->currentRow();
	if(currentRow != -1 && currentRow < ui->listWidget_ips->rowCount())
	{
		ui->listWidget_ips->removeRow(currentRow);
	}
}





void CCriarSessaoForm::on_btn_sair_clicked()
{
	CEditarSessaoForm* parent = static_cast<CEditarSessaoForm*> (this->parent());
	parent->init();
	this->accept();
}
