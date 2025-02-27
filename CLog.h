/*
 * CLog.h
 *
 *  Created on: 28/05/2014
 *      Author: 4scg
 */

#ifndef CLOG_H_
#define CLOG_H_

#include <QMutex>
#include <QString>

#include <fstream>

class CLog
{
public:
	int index;

	unsigned long totalSize;

	QMutex mutex;

	CLog(const QString &logName);
	virtual ~CLog();

	void writeText(char* text);

private:
	QString logName;
	std::ofstream ideLogfile;
};

#endif /* CLOG_H_ */
