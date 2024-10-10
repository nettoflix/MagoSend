#ifndef SPINNERTHREAD_H
#define SPINNERTHREAD_H

#include "CWaitingSpinnerWidget.h"
#include <QThread>



class SpinnerThread : public QThread

{
public:
	SpinnerThread(QWidget* parent=nullptr, int x=0, int y=0);
	void startSpinner();
	void stopSpinner();
	CWaitingSpinnerWidget *getSpinner() const;

protected:
	CWaitingSpinnerWidget* spinner = nullptr;
	void run();
	bool flag=false;
};

#endif // SPINNERTHREAD_H
