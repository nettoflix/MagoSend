#include "CLoginForm.h"
#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	//CLoginForm loginForm(nullptr, nullptr);
	//loginForm.show();
	w.show();
	return a.exec();
}
