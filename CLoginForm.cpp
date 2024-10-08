#include "CCadastrarLoginForm.h"
#include "CLoginForm.h"
#include "mainwindow.h"
#include "ui_CLoginForm.h"

#include <QMessageBox>

CLoginForm::CLoginForm(QWidget *parent, MainWindow* mw) :
	QWidget(parent),
	ui(new Ui::CLoginForm)
{
	ui->setupUi(this);
	setWindowTitle("Login");
//	MagoDB* db = new MagoDB();
//	db->CreateTableLogin();
	//delete db;
	//this->setAttribute(Qt::WA_DeleteOnClose);
	//this->mw = mw;
}

CLoginForm::~CLoginForm()
{
	delete ui;
}

void CLoginForm::on_btn_entrar_clicked()
{
	//	MainWindow* mw = new MainWindow;
	//	mw->show();
	//	this->close();
	QString usuario = ui->le_user->text();
	QString senha = ui->le_password->text();
	if(usuario.isEmpty() || senha.isEmpty())
	{
		QMessageBox::warning(this, "Campo vazio", "Preencha todos os campos", QMessageBox::Ok);
		return;
	}
	QString hashPasswordInformed = QString::fromUtf8(QCryptographicHash::hash(senha.toUtf8(), QCryptographicHash::Sha256).toHex());
	//qDebug("CLoginForm::on_btn_entrar_clicked passwordInformed: [%s]", hashPassword.toLatin1().data());
	if(CMagoDBCommandsThread::commands->userAlreadyExists(usuario))
	{
		QString hashPasswordRetrivied = CMagoDBCommandsThread::commands->getUserPassword(usuario.toLatin1().data());
		qDebug("hash informed: [%s]", hashPasswordInformed.toLatin1().data());
		qDebug("hash retrivied: [%s]", hashPasswordRetrivied.toLatin1().data());
		if(hashPasswordInformed == hashPasswordRetrivied)
		{
			MainWindow* mw = new MainWindow(0,usuario);
			mw->show();
			this->hide();
		}
		else
		{
			QMessageBox::warning(
						this,
						"Senha inválida",
						"A senha informada está incorreta. Verifique se você digitou a senha corretamente.",
						QMessageBox::Ok
						);
		}
		//qDebug("CLoginForm::on_btn_entrar_clicked passwordRetrivied: [%s]", hashPasswordRetrivied.toLatin1().data());
	}
	else
	{
		QMessageBox::warning(
					this,
					"Usuário inválido",
					"Esse usuário ainda não existe",
					QMessageBox::Ok
					);
	}

}

void CLoginForm::on_btn_cadastrar_clicked()
{
	CCadastrarLoginForm form(this);
	this->hide();
	form.exec();
	this->show();

}
