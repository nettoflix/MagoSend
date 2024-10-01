#include "CCadastrarLoginForm.h"
#include "MagoDB.h"
#include "ui_CCadastrarLoginForm.h"

#include <QMessageBox>

CCadastrarLoginForm::CCadastrarLoginForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CCadastrarLoginForm)
{
	ui->setupUi(this);
}

CCadastrarLoginForm::~CCadastrarLoginForm()
{
	delete ui;
}

void CCadastrarLoginForm::on_btn_registrar_clicked()
{
	QString usuario = ui->le_user->text();
	QString senha = ui->le_password->text();
	QString repeatSenha = ui->le_repeatepassword->text();
	if(usuario.isEmpty() || senha.isEmpty() || repeatSenha.isEmpty())
	{
		QMessageBox::warning(this, "Campo vazio", "Preencha todos os campos", QMessageBox::Ok);
		return;
	}
	if(senha != repeatSenha)
	{
		QMessageBox::warning(this, "Senhas não coincidem", "As senhas devem ser iguais!", QMessageBox::Ok);
		return;
	}


//	MagoDB* db = new MagoDB();
//	if(db->userAlreadyExists(usuario.toLatin1().data()))
//	{
//		QMessageBox::warning(this, "Usuário duplicado", "Esse nome de usuário já existe, escolha outro", QMessageBox::Ok);
//		return;
//	}
//	else
//	{
//		QByteArray passwordHash = QCryptographicHash::hash(senha.toUtf8(), QCryptographicHash::Sha256);
//		qDebug() << "hash:" <<passwordHash.toHex();
//		if(db->AddUserMagoSend(usuario.toLatin1().data(), passwordHash.toHex().data()))
//		{
//			int result = QMessageBox::information(
//						this,
//						"Conta Criada com Sucesso",
//						"Sua conta foi criada com sucesso! Agora você pode fazer login e começar a usar o aplicativo. Seja bem-vindo!",
//						QMessageBox::Ok
//						);
//			if(result == QMessageBox::Ok)
//			{
//				this->accept();
//			}

//		}
//		else
//		{

//			QMessageBox::warning(
//				this,
//				"Erro de Registro",
//				"Não foi possível registrar o usuário devido a um problema de comunicação com o banco de dados. Por favor, entre em contato com o suporte.",
//				QMessageBox::Ok
//			);

//		}
//	}
//	delete db;
}
