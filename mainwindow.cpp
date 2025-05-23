#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "CServiceUtils.h"
#include "HostListDelegate.h"
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
#include <QMessageBox>
#include <QModelIndexList>
#include <QSettings>
#include <chrono>
#include <thread>
#include "CCriarSessaoForm.h"
#include "CEditarSessaoForm.h"
#include "CHistoricoForm.h"
#include "CModalidadesForm.h"
#include "CBDQuery.h"
#include "CSendOptionsForm.h"
#include <QScrollBar>
#include <QToolButton>
MainWindow::MainWindow(QWidget *parent, QString usuario) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	this->usuario = usuario;
	setWindowTitle("MagoSend - " + usuario);
	//cria as tables no banco de dados se elas ainda nao existirem
	connect(&timer, SIGNAL(timeout()), this, SLOT(onTimer()));
	QObject::connect(ui->btn_Enviar, SIGNAL(clicked()), this, SLOT(onEnviarTodosBtnClick()));
	QObject::connect(ui->btn_Remover, SIGNAL(clicked()), this, SLOT(onRemoverBtnClick()));
	QObject::connect(ui->btn_NovoIP, SIGNAL(clicked()), this, SLOT(onNovoIPBtnClick()));
	QObject::connect(ui->btn_ExcluirIP, SIGNAL(clicked()), this, SLOT(onExcluirIPBtnClick()));
	QObject::connect(ui->btn_pausar, SIGNAL(clicked()), this, SLOT(onPausarTodosBtnClick()));
	QObject::connect(ui->btn_cancelaAtual, SIGNAL(clicked()), this, SLOT(onCancelaAtualBtnClick()));
	QObject::connect(ui->btn_atualizarDados, SIGNAL(clicked()), this, SLOT(onAtualizarDadosBtnClick()));

	hostControl = new CHostControl(this);
	transferMonitor = new CTransferMonitor(this);

	QStringList headers;
	headers << tr("ID") << tr("Título") <<tr("Modalidade") << tr("Duração")  << tr("IP") << tr("Progresso") << tr("Status");
	ui->tableWidget->setRowCount(0);
	ui->tableWidget->setColumnCount(headers.size());
	ui->tableWidget->setHorizontalHeaderLabels(headers);


	ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
	ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
	ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);



	QStringList hostTableHeaders;
	hostTableHeaders << "Nome" << tr("IP") << tr("Bitrate");
	ui->hostsTable->setRowCount(0);
	ui->hostsTable->setColumnCount(hostTableHeaders.size());
	ui->hostsTable->setHorizontalHeaderLabels(hostTableHeaders);

	ui->hostsTable->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
	ui->hostsTable->horizontalHeader()->setSectionResizeMode(1,QHeaderView::Stretch);
	ui->hostsTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
	ui->hostsTable->setSelectionBehavior(QAbstractItemView::SelectRows);

	toolBar = this->addToolBar(tr("Barra de ferramentas"));
	toolBar->setStyleSheet("QToolBar {border-bottom: 1px solid black; border-top: 1px solid lightgray; spacing: 5px;}");
	toolBar->setMovable(false);
	toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);


	// Create a QToolButton for the dropdown
	const QIcon settingsIcon = QIcon(":/images/settings.png");
	QToolButton *settingsButton = new QToolButton();
	settingsButton->setIcon(settingsIcon);
	settingsButton->setText(tr("Configurações"));
	settingsButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
	settingsButton->setPopupMode(QToolButton::InstantPopup);



	const QIcon historyIcon = QIcon(":/images/history.png");
	QAction* historicoAction = new QAction(historyIcon, tr("Histórico"), this);
	historicoAction->setStatusTip(tr("Abrir histórico"));
	connect(historicoAction, SIGNAL(triggered()), this, SLOT(onHistoricoAction()));


	const QIcon openFilesIcon = QIcon(":/images/folder.png");
	openFilesAction = new QAction(openFilesIcon, tr("Arquivos"), this);
	openFilesAction->setStatusTip(tr("Selecionar arquivos"));
	connect(openFilesAction, SIGNAL(triggered()), this, SLOT(onFileSelectionBtnClick()));

	//configMenu = menuBar()->addMenu(tr("Configurações"));
	QMenu *configMenu = new QMenu(this);
	//QAction* modAction = new QAction(tr("Modalidades"), this);
	//configMenu->addAction(modAction);
	//connect(modAction, SIGNAL(triggered()), this, SLOT(onModAction()));

	QAction* sessionAction = new QAction(tr("Sessões"), this);
	configMenu->addAction(sessionAction);
	connect(sessionAction, SIGNAL(triggered()), this, SLOT(onSessionAction()));

	QAction* opcoesEnvioAction = new QAction(tr("Opções de envio"), this);
	configMenu->addAction(opcoesEnvioAction);
	connect(opcoesEnvioAction, SIGNAL(triggered()), this, SLOT(onOptionsAction()));



	settingsButton->setMenu(configMenu);
	toolBar->addAction(openFilesAction);
	toolBar->addAction(historicoAction);
	toolBar->addWidget(settingsButton);

	//loadModComboBox();
	loadSessionComboBox();
	timer.start(70);

	worker = new Worker(this);
	//	worker2 = new Worker(this);
	//workerThread.start();
	worker->moveToThread(&workerThread);
	worker->startCheckTimer();
	workerThread.start();
	QObject::connect(worker, &Worker::idAlreadyExistOnHost, this, &MainWindow::updateQueueItemInformation);
	qRegisterMetaType<QList<CFilesOnHost>>("QList<CFilesOnHost>");

	ui->tableWidget->setIconSize(QSize(24, 24));
	iconEspera = new QIcon(":images/espera.png");
	iconSending = new QIcon(":images/sending.png");
	iconCheck = new QIcon(":images/check.png");
	iconError = new QIcon(":images/error.png");
	batchSize = 2000;



	connect(this, &MainWindow::populateQueueWithPaths, worker, &Worker::onPopulateQueueWithPaths, Qt::QueuedConnection);
	connect(worker, &Worker::queueDonePopulating, this, &MainWindow::onQueueDonePopulating, Qt::QueuedConnection);
	//connect(&timer_loadTable, &QTimer::timeout, this, &MainWindow::addQueueToTableWidget);
	connect(this, &MainWindow::triggerWorker, worker ,[this]()
	{
		worker->getFilesAlreadyPresentOnHosts(this->filePaths);
	});
	connect(worker, &Worker::filesAlreadyPresentOnHostsResult, this, &MainWindow::pupulateGuiTable);

	//pega modalidades dos hosts
	connect(this, &MainWindow::getModalidadesFromHosts, worker, &Worker::onGetModalidadesFromHosts, Qt::QueuedConnection);
	connect(worker, &Worker::loadMods, this, &MainWindow::onLoadMods, Qt::QueuedConnection);

	connect(ui->tableWidget, &QTableWidget::itemSelectionChanged, this, &MainWindow::onItemFromTableWidgetSelected);

}

MainWindow::~MainWindow()
{
	//CServiceUtils::KillAllTransferService();
	delete ui;
	delete transferMonitor;
	delete hostControl;
	delete worker;
}

void MainWindow::changeHostsTableTextColor(QColor color, QString ip)
{
	for(int i=0; i<ui->hostsTable->rowCount(); i++)
	{
		QTableWidgetItem *item = ui->hostsTable->item(i, 1);
		if(ip == item->text())
		{item->setTextColor(color);

		}
	}
}

void MainWindow::loadModComboBox()
{



}

void MainWindow::loadSessionComboBox()
{
	ui->cb_sessions->clear();
	QStringList sessions = CMagoDBCommandsThread::commands->queuedGetSessionNames();
	ui->cb_sessions->addItems(sessions);

}

CTransferMonitor *MainWindow::getTransferMonitor() const
{
	return transferMonitor;
}

CHostControl *MainWindow::getHostControl() const
{
	return hostControl;
}

QString MainWindow::getUsuario() const
{
	return usuario;
}

bool MainWindow::getWarningAceppted() const
{
	return warningAceppted;
}


void MainWindow::updateQueueItemInformation(bool idExists)
{
	qDebug("updateQueueInformation [%d]", idExists);
	int currentRow = ui->tableWidget->currentRow();
	QString newID = ui->te_ID->toPlainText();
	QString newTitulo = ui->te_titulo->toPlainText();
	QString newModalidade = ui->cb_modalidades->currentText();
	qDebug("newId [%s]", newID.toLatin1().data());
	QTableWidgetItem *id = ui->tableWidget->item(currentRow,Columns::ID);
	QTableWidgetItem *titulo = ui->tableWidget->item(currentRow,Columns::TITULO);
	QTableWidgetItem *modalidade = ui->tableWidget->item(currentRow,Columns::MODALIDADE);

	bool valido = true;
	if(newID.isEmpty() || newTitulo.isEmpty()) valido = false;
	if(idExists)
	{
		int result = QMessageBox::warning(this,tr("Espere!"),tr("Esse ID já está cadastrado no mago. Você gostaria de atualizar esse cadastro?"),
										  QMessageBox::Yes | QMessageBox::No);
		if(result == QMessageBox::Yes)
		{
			if(!CServiceUtils::isValidIDname(newID))
			{
				valido = false;
			}
			if(!CServiceUtils::isValidIDname(newTitulo))
			{
				valido = false;
			}
		}else
		{
			valido = false;
		}
	}
	else
	{
		if(!CServiceUtils::isValidIDname(newID))
		{
			valido = false;
		}
		if(!CServiceUtils::isValidIDname(newTitulo))
		{
			valido = false;
		}


	}

	if(valido)
	{
		QMutexLocker queueLocker(&getTransferMonitor()->getQueueMutex());
		VideoFileInfo* videoInfo = getTransferMonitor()->getItemFromQueue(currentRow);

		id->setText(newID);
		videoInfo->setId(newID);
		titulo->setText(newTitulo);
		videoInfo->setTitulo(newTitulo);
		if(newModalidade != "Nenhuma")
		{
			modalidade->setText(newModalidade);
			videoInfo->setModalidade(newModalidade);

		}
		else
		{
			modalidade->setText("Nenhuma");
			videoInfo->setModalidade("");
		}
	}
	else
	{
		QMessageBox::warning(this, tr("Atenção!"), tr("O ID ou o título contêm caracteres inválidos. Por favor, insira um valor válido."),
							 QMessageBox::Ok);
	}

}


void MainWindow::onItemSelected(const QItemSelection &selected, const QItemSelection &deselected)
{
	qDebug("OBAA");
}
void MainWindow::addQueueToTableWidget()
{
	populatingTableWidget = true;
	qDebug("addQueueToTableWidget -1");
	//QMutexLocker queueLocker(&getTransferMonitor()->getQueueMutex());
	QVector<VideoFileInfo*> *queue = &getTransferMonitor()->getCurrentQueue();
	int row = ui->tableWidget->rowCount();
	for(int i=0; i < queue->size(); i++)
	{

		//qDebug("addQueueToTableWidget [%d]", i);

		VideoFileInfo *videoInfo = queue->at(i);

		if(!videoInfo->getWasAddedToTableWidget())
		{


			//qDebug("tableWidiget count [%d]", ui->tableWidget->rowCount());
			ui->tableWidget->setRowCount(ui->tableWidget->rowCount() + 1);
			QTableWidgetItem* id = new QTableWidgetItem(QString(videoInfo->getId().toLatin1()));
			QTableWidgetItem* titulo = new QTableWidgetItem(QString(videoInfo->getTitulo().toLatin1()));
			QTableWidgetItem* duration = new QTableWidgetItem(QString::number(videoInfo->duration) + " seg");
			QTableWidgetItem* ip = new QTableWidgetItem(videoInfo->host->ip);
			QTableWidgetItem* modalidade = new QTableWidgetItem(videoInfo->modalidade);
			id->setTextAlignment(Qt::AlignCenter);
			titulo->setTextAlignment(Qt::AlignCenter);
			modalidade->setTextAlignment(Qt::AlignCenter);
			duration->setTextAlignment(Qt::AlignCenter);
			ip->setTextAlignment(Qt::AlignCenter);

			//queueLocker.unlock();
			//QTableWidgetItem* progresso = new QTableWidgetItem(videoInfo.progress);
			ui->tableWidget->setItem(row,0, id);
			ui->tableWidget->setItem(row,Columns::TITULO, titulo);
			ui->tableWidget->setItem(row,Columns::DURACAO, duration);
			ui->tableWidget->setItem(row,Columns::IP, ip);
			ui->tableWidget->setItem(row, Columns::MODALIDADE, modalidade);
			//ui->tableWidget->setRowHeight(row, 120);
			//ui->tableWidget->setItem(row,Columns::PROGRESSO, progresso);
			QProgressBar* progressBar = new QProgressBar();
			QString progressBarStyle = R"(
									   QProgressBar {
									   background-color: #3E3E3E;
									   color: white;
									   border: 2px solid #3E3E3E;
									   border-radius: 5px;
									   text-align: center;
									   }
									   QProgressBar::chunk {
									   background-color: #4A90E2; /* Blue color */
									   border-radius: 5px;
									   }
									   )";
			progressBar->setStyleSheet(
						progressBarStyle
						);
			progressBar->setTextVisible(true);
			progressBar->setValue(0);
			ui->tableWidget->setCellWidget(row, Columns::PROGRESSO, progressBar);

			QTableWidgetItem *iconItem = new QTableWidgetItem();
			//QIcon icon("/home/mago/Switcher/release/espera.png");
			iconItem->setIcon(*iconEspera);
			iconItem->setText("Esperando");
			iconItem->setTextAlignment(Qt::AlignCenter);
			//iconItem->setTextColor(QColor(Qt::blue));
			ui->tableWidget->setItem(row, Columns::ICON, iconItem);
			//QTableWidgetItem* testIconItem = ui->tableWidget->item(row, Columns::ICON);
			//qDebug("testIconItem: [%s]", testIconItem->text().toLatin1().data());
			row++;
			//			queueLocker.relock();
			videoInfo->setWasAddedToTableWidget(true);
			//notAddedCount++;

		}
	}
	//batchIndex += batchSize - notAddedCount;
	qDebug("addQueueToTableWidget -2");

	//só vou parar o timer_loadTable se já adicionei todos os items da queue, se não a queue nao está sendo alimentada
	//e se nao  estou esperando confirmação do usuário pra adicionar mais items
	//	if(batchIndex >= queue->size()) //já adicionei todos os items da queue na tableWidget
	//	{

	if(!waitingUserResponseToAddItems) //não to mais esperando confirmação do usuário para adicionar novos items
	{
		qDebug("addQueueToTableWidget -3");
		if(!worker->isPopulatingQueue) //se a workerThread está adicionando items na queue, quer dizer que logo mais terá mais items pra adicionar na tabela, então nao podemos parar o timer_loadTable nesse caso
		{
			qDebug("addQueueToTableWidget -4");
			ui->tableWidget->show();
			qDebug("STOP SPINNER!");
			//	qDebug("addQueueToTableWidget -3");
			timer_loadTable.stop();
			if(tableSpinner != nullptr)
			{
				tableSpinner->stopSpinner();
				tableSpinner->exit();
				tableSpinner->wait();
				delete tableSpinner;
				tableSpinner = nullptr;
			}

			//workerThread.exit();
			//workerThread.wait();
			ui->btn_Enviar->setEnabled(true);
			ui->btn_pausar->setEnabled(true);
			ui->btn_Remover->setEnabled(true);
			openFilesAction->setEnabled(true);
			batchIndex = queue->size();
		}
	}
	//	batchIndex = queue->size();
	//	}

	//populateCount -= 1;
	//qDebug("addQueueToTableWidget -2");
	qDebug("batchIndex [%d], queueSize [%d], rowCount [%d],isPopulating [%d], waitingUser [%d]", batchIndex, queue->size(),ui->tableWidget->rowCount(),worker->getIsPopulatingQueue(), waitingUserResponseToAddItems);


	populatingTableWidget = false;


}

void MainWindow::onQueueDonePopulating()
{
	qDebug("done populating!");
	addQueueToTableWidget();



}

void MainWindow::onLoadMods(QList<QPair<QStringList, QString>> modalidades)
{
	this->everyHostModalidades = modalidades;

}

void MainWindow::onItemFromTableWidgetSelected()
{
	//só vamos motrar as modalidades correspondentes ao host do item selecionado
	ui->cb_modalidades->clear();
	QStringList modalidadesToShow;
	modalidadesToShow.append("Nenhuma");
	QList<QTableWidgetItem *> selectedItems = ui->tableWidget->selectedItems();
	if (!selectedItems.isEmpty()) {
		qDebug() << "Selected item:" << selectedItems.first()->text();
		QString selectedItemIP = selectedItems.at(4)->text();
		for(QPair<QStringList, QString> modalidade : everyHostModalidades)
		{
			if(modalidade.second == selectedItemIP)
			{
				modalidadesToShow.append(modalidade.first);
			}
		}
		ui->cb_modalidades->addItems(modalidadesToShow);
	}
}

void MainWindow::onFileSelectionBtnClick()
{
	qDebug("MainWindow::onFileSelectionBtnClick! -1 \n");
	filePaths.clear();

	if(ui->hostsTable->rowCount() <= 0)
	{
		QString message = QString("Nenhum destino foi configurado. Por favor, adicione ao menos um endereço de host para continuar com a seleção de arquivos.");
		QMessageBox::information(this, "Destinos não configurados", message, QMessageBox::Ok);
		return;
	}


	//desabilita os botões enquanto está carregando a lista
	ui->btn_Enviar->setEnabled(false);
	ui->btn_pausar->setEnabled(false);
	ui->btn_Remover->setEnabled(false);
	openFilesAction->setEnabled(false);

	tableSpinner = new SpinnerThread(this, ui->tableWidget->pos().x() + ui->tableWidget->width()/2, ui->tableWidget->pos().y() + ui->tableWidget->height()/2);
	tableSpinner->startSpinner();


	QStringList filepaths_ = QFileDialog::getOpenFileNames(
				this,
				tr("Selecionar arquivos"),
				"",
				tr("Arquivos de Vídeo (*.mxf *.mp4 *.avi *.mkv *.mov *.wmv *.mpg *.mpeg)") //	tr("Arquivos de Vídeo (*.mxf *.mp4 *.avi *.mkv *.mov *.wmv *.flv *.mpeg)")
				);
	QStringList invalidFilenames;
	for(QString path: filepaths_){
		QFileInfo info(path);
		QString filename = info.fileName();
		if(CServiceUtils::isValidFilename(filename))
		{
			filePaths << QString::fromLatin1(path.toUtf8().data());
		}
		else
		{
			invalidFilenames<<filename;
		}

	}
	if(!invalidFilenames.isEmpty())
	{

		QString message = QString("Os seguintes arquivos são inválidos e não serão adicionados na lista porque contém caracteres especiais :\n- %1").arg(invalidFilenames.join("\n- "));
		QMessageBox::warning(this, "Arquivos inválidos", message, QMessageBox::Ok);
	}


	if (!filePaths.isEmpty()) {
		bool shouldWarn = CMagoDBCommandsThread::commands->warningWhenOverwriteFile();
		if(shouldWarn) //deve verificar se os videos já existem no destino e pergunta pro usuário se ele quer sobreescrever
		{
			emit triggerWorker();
		}
		else //adiciona todos os arquivos selecionados na lista sem pedir confirmação
		{
			qDebug("shouldAlwaysOverWriteFile = true");
			//qDebug() << "onFileSelectionBtnClick: Current thread ID: " << QThread::currentThreadId();
			for(int i=0; i<ui->hostsTable->rowCount(); i++)
			{

				//workerThread.start();
				QString ip = ui->hostsTable->item(i,1)->text();
				ui->tableWidget->hide();
				qDebug("emite populateQueueWithPaths");
				emit populateQueueWithPaths(filePaths, ip);

			}

		}
	}
	else
	{
		if(tableSpinner != nullptr)
		{
			tableSpinner->stopSpinner();
			tableSpinner->exit();
			tableSpinner->wait();
			delete tableSpinner;
			tableSpinner = nullptr;
		}
		ui->tableWidget->show();
		//habilita os botões novamente
		ui->btn_Enviar->setEnabled(true);
		ui->btn_pausar->setEnabled(true);
		ui->btn_Remover->setEnabled(true);
		openFilesAction->setEnabled(true);
		//		ui->btn_fileSelection->setEnabled(true);

	}

}

void MainWindow::onEnviarTodosBtnClick()
{
	getTransferMonitor()->startUploads();
}

void MainWindow::onRemoverBtnClick()
{

	qDebug("REMOVING ITEMS!");
	ui->btn_Enviar->setEnabled(false);
	ui->btn_pausar->setEnabled(false);
	ui->btn_Remover->setEnabled(false);
	ui->tableWidget->hide();
	tableSpinner = new SpinnerThread(this, ui->tableWidget->pos().x() + ui->tableWidget->width()/2, ui->tableWidget->pos().y() + ui->tableWidget->height()/2);
	tableSpinner->startSpinner();
	//	CWaitingSpinnerWidget spinner(this,false,false);
	//	spinner.setRoundness(70.0);
	//	spinner.setMinimumTrailOpacity(15.0);
	//	spinner.setTrailFadePercentage(70.0);
	//	spinner.setNumberOfLines(12);
	//	spinner.setLineLength(10);
	//	spinner.setLineWidth(5);
	//	spinner.setInnerRadius(10);
	//	spinner.setRevolutionsPerSecond(1);
	//	spinner.setColor(QColor(255, 140, 26));
	//	spinner.move(ui->tableWidget->pos().x() + ui->tableWidget->width()/2,
	//				 ui->tableWidget->pos().y() + ui->tableWidget->height()/2);
	//	spinner.show();
	//	spinner.start();
	int count = 0;
	//pegar row selecionada

	int rowCount = ui->tableWidget->rowCount();

	//		ui->tableWidget->removeRow(row);

	QModelIndexList  selected = ui->tableWidget->selectionModel()->selectedIndexes();
	QSet<int> rows;
	for (const QModelIndex &index : selected)
	{
		rows.insert(index.row());
	}
	QList<int> rowList = rows.values();
	//organiza pra remover em ordem descrecente
	std::sort(rowList.begin(), rowList.end(), std::greater<int>());

	for(int row : rowList)
	{

		//	qDebug("onRemoverBtnClick - 1");
		//	qDebug("onRemoverBtnClick - 2");
		if(row >=0 && row < rowCount)
		{
			//qDebug("onRemoverBtnClick - 3");
			QMutexLocker queueLocker(&getTransferMonitor()->getQueueMutex());
			VideoFileInfo* videoInfo = getTransferMonitor()->getItemFromQueue(row);
			if(!videoInfo->isActiveUpload)
			{
				queueLocker.unlock();
				ui->tableWidget->removeRow(row);
				getTransferMonitor()->removeFromQueue(row);
				count++;
				if(count>=100)
				{
					//	qDebug("processEvents - 4");
					QApplication::processEvents();
					count = 0;

				}
			}
			queueLocker.unlock();
		}

		//qDebug("onRemoverBtnClick - 4");
	}
	//spinner.stop();
	ui->tableWidget->show();
	ui->btn_Enviar->setEnabled(true);
	ui->btn_pausar->setEnabled(true);
	ui->btn_Remover->setEnabled(true);
	openFilesAction->setEnabled(true);
	batchIndex = ui->tableWidget->rowCount();

	tableSpinner->stopSpinner();
	tableSpinner->exit();
	tableSpinner->wait();
	delete tableSpinner;
	tableSpinner = nullptr;

}


void MainWindow::onNovoIPBtnClick()
{
	bool ok;
	QInputDialog* dialog = new QInputDialog(this);
	dialog->setInputMode(QInputDialog::IntInput);
	QString newIp = dialog->getText(this, tr("Novo host"),
									tr("Endereço IP:"), QLineEdit::Normal,
									"", &ok);

	bool toAdd = true;
	if (ok && !newIp.isEmpty()) {
		for(int i=0; i<ui->hostsTable->rowCount(); i++)
		{
			if(newIp == ui->hostsTable->item(i,1)->text())
			{
				toAdd = false; //IP já está na lista
			}
		}
		if(CServiceUtils::isValidIPv4format(newIp) && toAdd)
		{
			int row = ui->hostsTable->rowCount();
			ui->hostsTable->setRowCount(row + 1);
			QTableWidgetItem* ip = new QTableWidgetItem(newIp);
			QTableWidgetItem* bitRate = new QTableWidgetItem("0.00 MB/s");
			ip->setTextColor(QColor(Qt::gray));
			qDebug("oii!1");
			ui->hostsTable->setItem(row, 1, ip);
			ui->hostsTable->setItem(row, 2, bitRate);
			qDebug("oii!2");
			hostControl->registerIp(newIp);
			//hostControl->startTransferService(newIp);
			updateModComboBox();


		}
		else
		{
			toAdd= false;
		}
	}
	if(!toAdd)
	{
		QMessageBox::warning(this, "IP inválido", "O endereço de IP informado é inválido ou já existe na lista", QMessageBox::Ok);
	}



}
void MainWindow::onExcluirIPBtnClick()
{
	int currentRow = ui->hostsTable->currentRow();
	if(currentRow < ui->hostsTable->rowCount() && currentRow != -1)
	{
		QTableWidgetItem *item = ui->hostsTable->item(currentRow,1);
		QString ip = item->text();
		//hostControl->removeHost(ip);
		hostControl->markHostAsRemovedFromTable(ip);
		ui->hostsTable->removeRow(currentRow);
	}
	updateModComboBox();
}

void MainWindow::onPausarTodosBtnClick()
{
	getTransferMonitor()->cancelUploads();
}

void MainWindow::onCancelaAtualBtnClick()
{
	/*
*/
	qDebug() << "onCancelaBtnClick called from thread:" << QThread::currentThread();

	int currentRow = ui->hostsTable->currentRow();
	if(currentRow == -1)
	{
		return;
	}
	QString ipToCancel = ui->hostsTable->item(currentRow,1)->text();
	getTransferMonitor()->cancelActiveUpload(ipToCancel);

}

void MainWindow::onAtualizarDadosBtnClick()
{
	int ans = QMessageBox::question(this, "Atualizar dados do item", "Você tem certeza que deseja atualizar os dados do item selecionado?", QMessageBox::Ok, QMessageBox::Cancel);
	if(ans == QMessageBox::Ok)
	{
		//pegar o item selecionado
		//atualizar os dados desse item com os valores que estiverem nos campos num, tit, dur, mod
		//pegar o videoFileInfo correspondente da queue e atuazar as informações la também
		int currentRow = ui->tableWidget->currentRow();
		if(currentRow != -1)
		{
			bool shouldWarn = CMagoDBCommandsThread::commands->warningWhenOverwriteId();

			if(!shouldWarn)
			{
				updateQueueItemInformation(false);
			}
			else
			{
				QString newId = ui->te_ID->toPlainText();
				QMutexLocker queueLocker(&getTransferMonitor()->getQueueMutex());
				VideoFileInfo* videoInfo = getTransferMonitor()->getItemFromQueue(currentRow);
				QString ip = videoInfo->host->getIp();
				queueLocker.unlock();
				//checa se o ID ja existe no banco
				worker->checkIfIdExistsOnHosts(ip, newId);
				qDebug("onAtualizarDadosBtnClick - OUT");
			}

		}
	}
}

void MainWindow::onModAction()
{
	//CModalidadesForm modForm(this);
	//modForm.show();
	//modForm.raise();

	//modForm.exec();
	//QEventLoop loop;
	//connect(&modForm, SIGNAL(closed()), &modForm, SLOT(reject()));
	//loop.exec();
}

void MainWindow::onSessionAction()
{
	//CCriarSessaoForm form;
	CEditarSessaoForm form(this);
	form.exec();
}

void MainWindow::onHistoricoAction()
{
	CHistoricoForm form(this);
	form.setWindowTitle("Histórico");
	form.exec();
}

void MainWindow::onOptionsAction()
{
	CSendOptionsForm form(this);
	form.setWindowTitle("Opções de envio");
	form.exec();

}
bool MainWindow::isItemVisible(QTableWidgetItem *item) {
	if (!item) return false;
	int row = item->row();
	int column = item->column();
	QRect viewportRect = ui->tableWidget->viewport()->rect();
	QRect itemRect = ui->tableWidget->visualRect(ui->tableWidget->model()->index(row, column));
	return viewportRect.intersects(itemRect);
}
QPair<int,int> MainWindow:: getFirstAndLastVisibleRowFromTable()
{
	QRect viewportRect = ui->tableWidget->viewport()->rect();
	int firstRow = ui->tableWidget->rowAt(viewportRect.y());
	int lastRow = ui->tableWidget->rowAt(viewportRect.y() + viewportRect.height());
	if(firstRow < 0) firstRow = 0;
	if(lastRow < 0)
	{
		lastRow = ui->tableWidget->rowCount() -1;
	}
	return QPair<int,int>(firstRow,lastRow);
}

void MainWindow::updateModComboBox()
{
	QStringList items;
	for(int i=0; i<ui->hostsTable->rowCount(); i++)
	{
		items << ui->hostsTable->item(i, 1)->text();
	}
	emit getModalidadesFromHosts(items);
}


void MainWindow::onTimer()
{
	for(int i=0; i<ui->hostsTable->rowCount(); i++)
	{
		QString ip = ui->hostsTable->item(i, 1)->text();
		for(Host* host : hostControl->getHosts())
		{
			if(host->ip == ip)
			{
				QTableWidgetItem *bitRate = ui->hostsTable->item(i,2);
				if(host->getBitRate() == 0) bitRate->setText("0.00 MB/s");
				else bitRate->setText(QString::number(host->getBitRate()) + QString("MB/s"));
			}
		}
	}
	if(worker->isPopulatingQueue) return; //se a workerThread estiver populando a fila, não podemos tentar pegar o lock da queueLocker, se não a GUI thread vai freezar
	QPair<int,int> rows = getFirstAndLastVisibleRowFromTable();
	for(int i=rows.first; i<=rows.second; i++)
	{
		if(ui->tableWidget->rowCount() <= 0) return;

		QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
		//QString fileName = 	ui->tableWidget->item(i, Columns::ID)->text();
		QMutexLocker queueLocker(&getTransferMonitor()->getQueueMutex());
		VideoFileInfo* videoInfo = getTransferMonitor()->getItemFromQueue(i);
		int progresso = videoInfo->getProgress();
		if(videoInfo->getStatus() == CVideoStatus::SENT)
		{
			item->setIcon(*iconCheck);
			item->setText("Sucesso");
			QWidget* widget = ui->tableWidget->cellWidget(i, Columns::PROGRESSO);
			QProgressBar* progressBar = qobject_cast<QProgressBar*>(widget);
			// Update the value of the progress bar
			progressBar->setValue(100);

		}
		else
		{
			if(videoInfo->getStatus() == CVideoStatus::ERROR)//progress < 0
			{
				if(progresso == UploadFileStatus::FILE_DOSENT_EXIST)
				{

					//qDebug("ARQUIVO NÃO EXISTE!");
					QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
					item->setIcon(*iconError);
					item->setText("Error");
					item->setToolTip("Arquivo não existe!");
				}
				else if(progresso == UploadFileStatus::NO_POSSIBLE_CONNECTION_TO_HOST)
				{
					//qDebug("Sem conexão com host!");
					QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
					item->setIcon(*iconError);
					item->setText("Error");
					item->setToolTip("Sem conexão com o host!");
				}
				else if(progresso == UploadFileStatus::CONNECTION_FAIL_WHILE_UPLOADING)
				{
					//qDebug("Falha durante o envio do arquivo!");
					QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
					item->setIcon(*iconError);
					item->setText("Error");
					item->setToolTip("Falha durante o envio do arquivo!");
				}
			}
			else if(videoInfo->getStatus() == CVideoStatus::SENDING)
			{
				QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
				item->setIcon(*iconSending);
				item->setText("Enviando");
				//item->setToolTip("");


				QWidget* widget = ui->tableWidget->cellWidget(i, Columns::PROGRESSO);
				// Cast the widget back to QProgressBar
				QProgressBar* progressBar = qobject_cast<QProgressBar*>(widget);

				// Check if the cast was successful
				if (progressBar) {
					// Update the value of the progress bar
					progressBar->setValue(progresso);  // Set the progress
				}

				if(progresso >= 100)
				{
					QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
					item->setIcon(*iconCheck);
					item->setText("Sucesso");
				}

			}
			else if(videoInfo->getStatus() == CVideoStatus::WAITING)
			{
				QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
				item->setIcon(*iconEspera);
				item->setText("Em espera");
			}
			else if(videoInfo->getStatus() == CVideoStatus::CANCELLED)
			{
				QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
				item->setIcon(*iconEspera);
				item->setText("Cancelado");
			}
			else if(videoInfo->getStatus() == CVideoStatus::TRYING_TO_CONNECT)
			{
				QTableWidgetItem *item = ui->tableWidget->item(i,Columns::ICON);
				item->setIcon(*iconSending);
				item->setText("Conectando...");
			}

		}

		//}


	}

}



void MainWindow::on_btn_connectSession_clicked()
{
	QString selectedSession = ui->cb_sessions->currentText();
	//qDebug("currentText: [%s]", selectedSession.toLatin1().data());

	//limpa a lista de ips atual
	for(int i=0; i<ui->hostsTable->rowCount(); i++)
	{
		hostControl->markHostAsRemovedFromTable(ui->hostsTable->item(i,1)->text());
		ui->hostsTable->removeRow(i);
		qDebug("remove i [%d]", i);
	}
	ui->hostsTable->setRowCount(0);

	QStringList ipList = CMagoDBCommandsThread::commands->getIpListFromSession(selectedSession);
	QStringList nameList = CMagoDBCommandsThread::commands->getNameListFromSession(selectedSession);

	for(QString ip : ipList)
	{
		//if(CServiceUtils::isValidIPv4format(ip))
		//{
		int row = ui->hostsTable->rowCount();
		ui->hostsTable->setRowCount(row + 1);
		QTableWidgetItem* nameItem = new QTableWidgetItem(nameList.at(row));
		QTableWidgetItem* ipItem = new QTableWidgetItem(ip);
		QTableWidgetItem* bitRate = new QTableWidgetItem("0.00 MB/s");
		ipItem->setTextColor(QColor(Qt::gray));
		ui->hostsTable->setItem(row, 0, nameItem);
		ui->hostsTable->setItem(row, 1, ipItem);
		ui->hostsTable->setItem(row, 2, bitRate);
		hostControl->registerIp(ip);

	}
	updateModComboBox();
}

void MainWindow::setWarningResponse(bool value)
{
	warningAceppted = value;
}


Worker *MainWindow::getWorker() const
{
	return worker;
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
	QMainWindow::resizeEvent(event);
	int tableWidth = ui->tableWidget->viewport()->width();
	int columnCount = ui->tableWidget->columnCount();
	int columnWidth = tableWidth / columnCount;
	for (int i = 0; i < columnCount; ++i) {
		ui->tableWidget->setColumnWidth(i, columnWidth);
	}
	if(tableSpinner!=nullptr && tableSpinner->getSpinner()!=nullptr)
	{
		qDebug("OIE");
		tableSpinner->getSpinner()->move(ui->tableWidget->pos().x() + ui->tableWidget->width()/2, ui->tableWidget->pos().y() + ui->tableWidget->height()/2);
	}
}

void MainWindow::showEvent(QShowEvent *event)
{
	QMainWindow::showEvent(event);
	int tableWidth = ui->tableWidget->viewport()->width();
	int columnCount = ui->tableWidget->columnCount();
	int columnWidth = tableWidth / columnCount;
	for (int i = 0; i < columnCount; ++i) {
		ui->tableWidget->setColumnWidth(i, columnWidth);
	}
}

void MainWindow::showWarningMessage(const QString &message)
{
	if(QMessageBox::warning(this,"Atenção!",message,QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::Yes)
	{
		warningAceppted = true;
	}
}

void MainWindow::pupulateGuiTable(QList<CFilesOnHost> listFilesOnHost)
{
	qDebug("MainWindow::pupulateGuiTable listFilesOnHost.size: [%d]", listFilesOnHost.size());
	waitingUserResponseToAddItems = true;
	for(CFilesOnHost fileOnHost : listFilesOnHost)
	{
		QString ip = fileOnHost.ip;

		QStringList hostFilesPaths;
		for(QString path : filePaths)
		{
			QFileInfo fileInfo(path);
			hostFilesPaths << fileInfo.baseName() + "." + fileInfo.suffix();
		}
		QStringList filenames;
		for(QString filepath_ : fileOnHost.filespath)
		{
			QFileInfo fileInfo(filepath_);
			QString filename = fileInfo.baseName() + "." + fileInfo.suffix();
			filenames << filename;
		}
		QString hostName;
		for(int i=0; i<ui->hostsTable->rowCount(); i++)
		{
			if(ui->hostsTable->item(i,0)!=nullptr)
			{
				QString hIp = ui->hostsTable->item(i,1)->text();
				if(ip == hIp) hostName = ui->hostsTable->item(i,0)->text();
			}

		}
		qDebug("pupulateGuiTable - ip: [%s]", ip.toLatin1().data());
		//mostra um warning dos arquivos que ja existem para cada host perguntando se quer sobreescrever
		if(fileOnHost.couldConnect)
		{
			qDebug("filespath.size(): [%d]",fileOnHost.filespath.size());
			if(fileOnHost.filespath.size() > 1)
			{
				QString formattedFilenames = filenames.join("\n- ").prepend("- ").toStdString().c_str();
				formattedFilenames.chop(3);


				// Construct the message using QString's arg method to avoid encoding issues
				QString replaceMessage = QString("Os seguintes arquivos já existem na máquina de destino \"%1\" (%2):\n\n%3\n\nDeseja sobrescrevê-los?")
						.arg(hostName)
						.arg(ip)
						.arg(QString(formattedFilenames.toLatin1()));
				// se não deseja sobreescrever, tira os arquivos que existem no host da lista de "filepaths"
				if (QMessageBox::warning(this, "Atenção!", replaceMessage, QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes) == QMessageBox::No)
				{
					qDebug("NAO QUERO ENVIAR VIDEO REPETIDO!!!");
					for (const QString &item : fileOnHost.filespath)
					{
						//qDebug("ITEM: [%s]", item.toLatin1().data());
						//qDebug("hostFilesPath: [%s]", QString(hostFilesPaths.join(",")).toLatin1().data());
						hostFilesPaths.removeAll(item);
					}
				}
				else
				{
					qDebug("EU QUERO ENVIAR VIDEO REPETIDO!!!");
				}
			}


			QStringList pathsToPopulate;

			for(const QString path : hostFilesPaths)
			{
				QFileInfo fileInfo(filePaths.at(0));

				pathsToPopulate << fileInfo.absolutePath() + "/" + path;//QString::fromLatin1(path.toUtf8().data());
				//qDebug("MainWindow::pupulateGuiTable : populateQueue filepath [%s]", filePath.toLatin1().data());
				//getTransferMonitor()->populateQueue(filePath, ip);
			}

			qDebug("emite monitorPopulateQueue!");
			//qDebug() << "pupulateGuiTable: Current thread ID:" << QThread::currentThreadId();
			ui->tableWidget->hide();

			emit populateQueueWithPaths(pathsToPopulate, ip);
		}
		else
		{
			QString replaceMessage;
			replaceMessage.sprintf("Não foi possível estabelecer conexão com a máquina \"%s\" (%s). Nenhum vídeo selecionado será enviado para esse destino.\n\n" ,hostName.toStdString().c_str(),ip.toStdString().c_str());
			QMessageBox::warning(this,"Atenção!",replaceMessage);
			if(tableSpinner != nullptr)
			{
				tableSpinner->stopSpinner();
				tableSpinner->exit();
				tableSpinner->wait();
				delete tableSpinner;
				tableSpinner = nullptr;
			}
			ui->btn_Enviar->setEnabled(true);
			ui->btn_pausar->setEnabled(true);
			ui->btn_Remover->setEnabled(true);
			openFilesAction->setEnabled(true);
		}

		//se deseja sobreescrever, adiciona todos os file de "filePaths" na table
	}
	waitingUserResponseToAddItems = false;
	//timer_loadTable.start(30);
}
