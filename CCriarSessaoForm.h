#ifndef CCRIARSESSAOFORM_H
#define CCRIARSESSAOFORM_H

#include "MagoDB.h"

#include <QDialog>
#include <QWidget>

namespace Ui {
class CCriarSessaoForm;
}

class CCriarSessaoForm : public QDialog
{
	Q_OBJECT

public:
	explicit CCriarSessaoForm(QWidget *parent = 0, QString sessionName="", bool readOnly=false);
	~CCriarSessaoForm();
	void loadSessao();
	MagoDB* db;

private slots:
	void on_btn_adicionarIP_clicked();


	void on_btn_Salvar_clicked();

	void on_btn_removerIp_clicked();

	void on_btn_sair_clicked();

private:
	Ui::CCriarSessaoForm *ui;
};

#endif // CCRIARSESSAOFORM_H
