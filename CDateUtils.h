/*
* CUtils.h
*
*  Created on: 23/10/2013
*      Author: 4scg
*/

#ifndef CDATEUTILS_H_
#define CDATEUTILS_H_

#include "CDateUtils.h"

#ifdef _WIN32
#include "windows.h"
#include <windef.h>
#include <Winver.h>
#endif

#include <QDir>
#include <QTime>

#define BYTES_PER_GIGA 1073741824.00F


typedef struct
{
int days;
int hours;
int minutes;
int seconds;
int frames;
} SDateDifference;


class CDateUtils
{
public:
static SDateDifference diffFromCurrentDate(QString date, QString format);
static SDateDifference secondsToTime(int duration);
static SDateDifference framesToTime(uint64_t duration);
static QString secondsToTimeAsQString(int duration);
static QString framesToTimeAsQString(uint64_t duration);
//horario sem hora
static QString framesToTime2AsQString(int duration);
static float frameToSeconds(int frames);
static double timeAsQStringToSeconds(QString s);
static double timeToSeconds(QTime s);
static double timeToFrames(QTime s);

static uint64_t timeValuesToFrames(int hour, int minutes, int secs, int frames);
};

#include <QTableWidgetItem>

class CDateTimeItem : public QTableWidgetItem
{
public:
CDateTimeItem(const QString txt = QDateTime::currentDateTime().toString("dd/MM/yyyy - hh:mm:ss"))
        :QTableWidgetItem(txt)
    {
    }
    bool operator <(const QTableWidgetItem &other) const
    {

        QDateTime dt1 = QDateTime::fromString(text(), "dd/MM/yyyy - hh:mm:ss");
        QDateTime dt2 = QDateTime::fromString(other.text(), "dd/MM/yyyy - hh:mm:ss");

        return dt1 < dt2;
    }
};


#endif /* CDATEUTILS_H_ */
