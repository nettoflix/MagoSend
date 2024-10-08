#include "CCriarSessaoForm.h"
#include "CEditarSessaoForm.h"
#include "mainwindow.h"
#include "ui_CEditarSessaoForm.h"

#include <QSettings>

CEditarSessaoForm::CEditarSessaoForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CEditarSessaoForm)
{
	ui->setupUi(this);
	init();

}

CEditarSessaoForm::~CEditarSessaoForm()
{
	delete ui;
}

void CEditarSessaoForm::init()
{
	this->setWindowTitle("Sessões");
	sessionsToRemove.clear();
	ui->cb_Sessoes->clear();
	//pegar o nome de todas as sessoes do DB
	QStringList sessoes = CMagoDBCommandsThread::commands->getSessionNames();
	ui->cb_Sessoes->addItems(sessoes);

}

void CEditarSessaoForm::on_pushButton_clicked()
{
	CCriarSessaoForm form(this, ui->cb_Sessoes->currentText(), true);
	form.exec();
}

void CEditarSessaoForm::on_btn_excluirSessao_clicked()
{
	sessionsToRemove << ui->cb_Sessoes->currentText();
	ui->cb_Sessoes->removeItem(ui->cb_Sessoes->currentIndex());
}

void CEditarSessaoForm::on_btn_criarSessao_clicked()
{
	CCriarSessaoForm form(this);
	form.exec();
}

void CEditarSessaoForm::on_btn_ok_clicked()
{
	for(QString sessionToRemove: sessionsToRemove)
	{
		CMagoDBCommandsThread::commands->removeSession(sessionToRemove);
	}
	MainWindow* parent = (MainWindow*) this->parent();
	parent->loadSessionComboBox();
	this->accept();
}
