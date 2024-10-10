#ifndef CMODALIDADESFORM_H
#define CMODALIDADESFORM_H

#include <QWidget>
#include <QDialog>
namespace Ui {
class CModalidadesForm;
}

class CModalidadesForm : public QDialog
{
	Q_OBJECT

public:
	explicit CModalidadesForm(QWidget *parent = 0);
	~CModalidadesForm();

	void addModToTable(QString &modName, QString &modDesc);
	void saveModsToFile(QString filePath);
	void loadModalidadesFromFile(QString filePath);
	void saveModsToDB();
	void loadModalidadesFromDB();
signals:
	void closed();
private:
	Ui::CModalidadesForm *ui;
protected:
	void closeEvent(QCloseEvent* event);
private slots:
	void on_btn_adicionarModalidade_clicked();
	void on_btn_Ok_clicked();
	void on_btn_importMods_clicked();
	void on_btn_ExportarMods_clicked();
	void on_btn_remover_clicked();
	void on_btn_removerTodas_clicked();
};

#endif // CMODALIDADESFORM_H
