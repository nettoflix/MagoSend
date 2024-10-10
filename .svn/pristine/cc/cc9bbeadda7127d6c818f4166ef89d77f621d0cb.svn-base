#ifndef CLOGINFORM_H
#define CLOGINFORM_H

#include "mainwindow.h"

#include <QWidget>

namespace Ui {
class CLoginForm;
}

class CLoginForm : public QWidget
{
	Q_OBJECT

public:
	explicit CLoginForm(QWidget *parent = 0, MainWindow* mw = nullptr);
	MainWindow* mw;
	~CLoginForm();

private slots:
	void on_btn_entrar_clicked();

	void on_btn_cadastrar_clicked();

private:
	Ui::CLoginForm *ui;
};

#endif // CLOGINFORM_H
