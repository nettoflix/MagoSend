#include "CSendOptionsForm.h"
#include "ui_CSendOptionsForm.h"

CSendOptionsForm::CSendOptionsForm(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::CSendOptionsForm)
{
	ui->setupUi(this);
	db = new MagoDB();
	bool alwaysWarnFile = db->warningWhenOverwriteFile();
	bool alwaysWarnId = db->warningWhenOverwriteId();
	ui->checkBox_arquivo->setChecked(alwaysWarnFile);
	ui->checkBox_id->setChecked(alwaysWarnId);
}

CSendOptionsForm::~CSendOptionsForm()
{
	delete db;
	delete ui;
}

void CSendOptionsForm::closeEvent(QCloseEvent *event)
{
	qDebug("fechoU!");
	db->updateSendOptions(ui->checkBox_arquivo->isChecked(),ui->checkBox_id->isChecked());
	this->accept();
}

