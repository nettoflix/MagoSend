#include "CCadastrarLoginForm.h"
#include "MagoDB.h"
#include "ui_CCadastrarLoginForm.h"
#include "CMagoDBCommandsThread.h"
#include <QMessageBox>
#include <QScreen>

CCadastrarLoginForm::CCadastrarLoginForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CCadastrarLoginForm)
{
	ui->setupUi(this);
	setWindowTitle("Cadastro");

	QScreen* screen = QGuiApplication::primaryScreen();
	QRect screenGeometry = screen->geometry();
	int x = (screenGeometry.width() - width()) / 2;
	int y = (screenGeometry.height() - height()) / 2;
	move(x, y);
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



	if(CMagoDBCommandsThread::commands->userAlreadyExists(usuario))
	{
		QMessageBox::warning(this, "Usuário duplicado", "Esse nome de usuário já existe, escolha outro", QMessageBox::Ok);
		return;
	}
	else
	{
		QByteArray passwordHash = QCryptographicHash::hash(senha.toUtf8(), QCryptographicHash::Sha256);
		qDebug() << "hash:" <<passwordHash.toHex();
		if(CMagoDBCommandsThread::commands->AddUserMagoSend(usuario.toLower(), passwordHash))
		{
			int result = QMessageBox::information(
						this,
						"Conta Criada com Sucesso",
						"Sua conta foi criada com sucesso! Agora você pode fazer login e começar a usar o aplicativo. Seja bem-vindo!",
						QMessageBox::Ok
						);
			if(result == QMessageBox::Ok)
			{
				this->accept();
			}

		}
		else
		{

			QMessageBox::warning(
				this,
				"Erro de Registro",
				"Não foi possível registrar o usuário devido a um problema de comunicação com o banco de dados. Por favor, entre em contato com o suporte.",
				QMessageBox::Ok
			);

		}
	}
}
