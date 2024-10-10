#include "CMagoDBCommandsThread.h"
#include "CSendOptionsForm.h"
#include "ui_CSendOptionsForm.h"

CSendOptionsForm::CSendOptionsForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CSendOptionsForm)
{
	ui->setupUi(this);
//	db = new MagoDB();
	bool alwaysWarnFile = CMagoDBCommandsThread::commands->warningWhenOverwriteFile();
	bool alwaysWarnId =  CMagoDBCommandsThread::commands->warningWhenOverwriteId();
	ui->checkBox_arquivo->setChecked(alwaysWarnFile);
	ui->checkBox_id->setChecked(alwaysWarnId);
}

CSendOptionsForm::~CSendOptionsForm()
{
//	delete db;
	delete ui;
}

void CSendOptionsForm::closeEvent(QCloseEvent *event)
{
	qDebug("fechoU!");
	CMagoDBCommandsThread::commands->updateSendOptions(ui->checkBox_arquivo->isChecked(),ui->checkBox_id->isChecked());
	this->accept();
}

