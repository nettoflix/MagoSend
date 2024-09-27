#ifndef CEDITARSESSAOFORM_H
#define CEDITARSESSAOFORM_H

#include <QWidget>
#include <QDialog>
namespace Ui {
class CEditarSessaoForm;
}

class CEditarSessaoForm : public QDialog
{
	Q_OBJECT

public:
	explicit CEditarSessaoForm(QWidget *parent = 0);
	~CEditarSessaoForm();
	QStringList sessionsToRemove;
	void init();
private slots:
	void on_pushButton_clicked();

	void on_btn_excluirSessao_clicked();

	void on_btn_criarSessao_clicked();

	void on_btn_ok_clicked();

private:
	Ui::CEditarSessaoForm *ui;
};

#endif // CEDITARSESSAOFORM_H
