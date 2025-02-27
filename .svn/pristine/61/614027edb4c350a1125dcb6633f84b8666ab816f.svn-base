#include "CAboutForm.h"
#include "ui_CAboutForm.h"
#include <QCloseEvent>
#include <QApplication>

CAboutForm::CAboutForm(QWidget* parent) :
	QDialog(parent),
	ui(new Ui::CAboutForm)
{
	ui->setupUi(this);
	ui->label_3->setTextFormat(Qt::RichText);
	ui->label_3->setText(ui->label_3->text().replace("#version", QApplication::applicationVersion()));
}

CAboutForm::~CAboutForm()
{
	delete ui;
}

void CAboutForm::closeEvent(QCloseEvent* ev)
{
	ev->ignore();
	emit closed();
	ev->accept();
}

void CAboutForm::on_pushButton_clicked()
{
	close();
}
