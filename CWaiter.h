/*
 * CWaiter.h
 *
 *  Created on: 12 de jul de 2018
 *      Author: Dev
 */

#ifndef CWAITER_H_
#define CWAITER_H_

#include <QMutex>
#include <QWaitCondition>

class CWaiter
{
private:
	QMutex mutex;
	QWaitCondition waitCondition;
	bool isOk;
	int eventId;

public:
	CWaiter();
	virtual ~CWaiter();

	inline bool wait(unsigned long time = ULONG_MAX)
	{
		QMutexLocker locker(&mutex);

		if (!isOk)
		{
			bool b = waitCondition.wait(&mutex, time);
			isOk = false;
			return b;
		}
		else
		{
			isOk = false;
			return true;
		}
	}

	inline void wake(int _eventId = 0)
	{
		mutex.lock();
		isOk = true;
		eventId = _eventId;
		mutex.unlock();

		waitCondition.wakeAll();
	}

	int getEventId()
	{
		QMutexLocker locker(&mutex);
		return eventId;
	}


};

#endif /* CWAITER_H_ */
