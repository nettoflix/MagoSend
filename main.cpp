#include "CLoginForm.h"
#include "mainwindow.h"
#include <QApplication>
CMagoDBCommandsThread* magoDbCommandsThread;


int main(int argc, char *argv[])
{
    //QLoggingCategory::setFilterRules("*.debug=true\nqt.*.debug=true");
    QApplication a(argc, argv);
	a.setWindowIcon(QIcon(":/images/redhat.png"));
    magoDbCommandsThread = new CMagoDBCommandsThread();
    MainWindow w;
    //CLoginForm loginForm(nullptr, nullptr);
    //loginForm.show();
    w.show();
    return a.exec();
}
