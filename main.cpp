#include "CLoginForm.h"
#include "mainwindow.h"
#include <QApplication>

CMagoDBCommandsThread* magoDbCommandsThread;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	magoDbCommandsThread = new CMagoDBCommandsThread();
	//MainWindow w;
	CLoginForm loginForm(nullptr, nullptr);
	loginForm.show();
	//w.show();
	return a.exec();
}
