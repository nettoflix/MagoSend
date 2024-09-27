#include "SpinnerThread.h"

SpinnerThread::SpinnerThread(QWidget* parent, int x, int y) : QThread()
{
	spinner = new CWaitingSpinnerWidget(parent, false, false);
	spinner->setRoundness(70.0);
	spinner->setMinimumTrailOpacity(15.0);
	spinner->setTrailFadePercentage(70.0);
	spinner->setNumberOfLines(12);
	spinner->setLineLength(10);
	spinner->setLineWidth(5);
	spinner->setInnerRadius(10);
	spinner->setRevolutionsPerSecond(1);
	spinner->setColor(QColor(255, 140, 26));
	spinner->move(x, y);
	spinner->moveToThread(this);
}

void SpinnerThread::startSpinner()
{

	spinner->show();
	spinner->start();
	QThread::start();
}

void SpinnerThread::stopSpinner()
{
	spinner->stop();
	spinner->hide();
	QThread::exit();
}

void SpinnerThread::run()
{

}
