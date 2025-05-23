#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "CHostControl.h"
#include "CTransferMonitor.h"
#include "CUploadServiceClient.h"
#include "CustomStringListModel.h"
#include "MagoDB.h"
#include <QFile>
#include <QProcess>
#include <QDebug>
#include <QTextEdit>
#include <QPushButton>
#include <QTimer>
#include <QProgressBar>
#include <QListView>
#include <QStringListModel>
#include <QTableWidgetItem>
#include <QToolBar>
#include "CWaitingSpinnerWidget.h"
#include "CWorker.h"
#include "SpinnerThread.h"

namespace Ui {
class MainWindow;
}
enum Columns {
	ID=0, TITULO,MODALIDADE ,DURACAO, IP, PROGRESSO, ICON
};
class Worker;
class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0, QString usuario = "4S");
	~MainWindow();

	void changeHostsTableTextColor(QColor color, QString ip);
	void loadModComboBox();
	void loadSessionComboBox();

	CTransferMonitor *getTransferMonitor() const;
	CHostControl *getHostControl() const;
	CustomStringListModel *getAddressModel() const;
	QString getUsuario() const;

	bool getWarningAceppted() const;
	void setWarningResponse(bool value);

	MagoDB *getDb() const;

	Worker *getWorker() const;
protected:
	void resizeEvent(QResizeEvent *event) override;
	void showEvent(QShowEvent *event) override;
signals:
	void cancel_active_upload(int hostIndex);
	void triggerWorker();
	void populateQueueWithPaths(QStringList filePathsToPopulate, QString ip);
	void getModalidadesFromHosts(QStringList hosts);

private:
	bool populatingTableWidget = false;
	QAction* openFilesAction;
	QStringList filePaths;
	QMenu* configMenu;
	CTransferMonitor* transferMonitor;
	CHostControl* hostControl;
	Ui::MainWindow *ui;
	QProcess* process;
	QPushButton* btn_fileSelection;
	QTextEdit* te_fileSelectioon;
	QTimer timer;
	QString usuario;
	bool warningAceppted = false;
	QThread workerThread;
	//QThread* workerThread2;
	Worker* worker = nullptr;
	QIcon* iconEspera;
	QIcon* iconSending;
	QIcon* iconCheck;
	QIcon* iconError;
	QToolBar* toolBar;
	CWaitingSpinnerWidget* populateListSpinner;
	SpinnerThread* tableSpinner = nullptr;
	QTimer timer_loadTable;
	//Worker* worker2;
	int batchIndex = 0;
	int batchSize;
	bool waitingUserResponseToAddItems = false;
	QList<QPair<QStringList, QString>> everyHostModalidades;
	//int populateCount =0;
	void updateQueueItemInformation(bool idExists);
	bool isItemVisible(QTableWidgetItem *item);
	QPair<int,int>  getFirstAndLastVisibleRowFromTable();
	void updateModComboBox();
private slots:
	void onItemSelected(const QItemSelection &selected, const QItemSelection &deselected);

	void addQueueToTableWidget();

	void onFileSelectionBtnClick();
	void onEnviarTodosBtnClick();
	void onRemoverBtnClick();
	void onNovoIPBtnClick();
	void onExcluirIPBtnClick();
	void onPausarTodosBtnClick();
	void onCancelaAtualBtnClick();
	void onAtualizarDadosBtnClick();
	void onModAction();
	void onSessionAction();
	void onHistoricoAction();
	void onOptionsAction();
	void onTimer();
	void on_btn_connectSession_clicked();
	void showWarningMessage(const QString &message);
	void pupulateGuiTable(QList<CFilesOnHost> listFilesOnHost);
	void onQueueDonePopulating();
	void onLoadMods(QList<QPair<QStringList, QString>> modalidades);
	void onItemFromTableWidgetSelected();
};

#endif // MAINWINDOW_H
