/*
 * CUtils.cpp
 *
 *  Created on: 23/10/2013
 *      Author: 4scg
 */

#include "CDateUtils.h"



#ifdef _WIN32
#include "windows.h"
#include <windef.h>
#include <Winver.h>
#endif

#include <QDir>
#include <QTime>
#include <QString>

#include <math.h>

SDateDifference CDateUtils::diffFromCurrentDate(QString date, QString format)
{
    QDateTime todate = QDateTime::fromString(date, format);
    QDateTime current = QDateTime::currentDateTime();

    int duration = todate.secsTo(current);

    SDateDifference dif;
    dif.seconds = (int) (duration % 60);
    duration /= 60;
    dif.minutes = (int) (duration % 60);
    duration /= 60;
    dif.hours = (int) (duration % 24);
    dif.days = (int) (duration / 24);

    return dif;
}

uint64_t CDateUtils::timeValuesToFrames(int hour, int minutes, int secs, int frames)
{
    float ss = secs * 29.97;
    float mm = minutes * (60 * 29.97);
    float hh = hour * (60 * 60 * 29.97);

    return ceil(ss + mm + hh + ((float)frames));
}

double CDateUtils::timeToSeconds(QTime s)
{
    bool isOK = false;
    int hh = s.hour();
    {
        int mm = s.minute();
        {
            int ss = s.second();

            double result = double(ss + (mm * 60) + (hh * 60 * 60));
            return result;
        }
    }

    return 0;
}

double CDateUtils::timeToFrames(QTime s)
{
    bool isOK = false;
    int hh = s.hour();
    {
        int mm = s.minute();
        {
            int ss = s.second();

            double ff = s.msec()*.02997;

            double result = double(ff + ((ss + (mm * 60) + (hh * 60 * 60))*29.97));
            return result;
        }
    }

    return 0;
}

float CDateUtils::frameToSeconds(int frames)
{
    float result = (frames + 0.5) /29.97;
    return result;
}

double CDateUtils::timeAsQStringToSeconds(QString duration)
{
    if (duration.length() >= 8)
    {
        QString hour = duration.mid(0, 2);
        QString min = duration.mid(3, 2);
        QString sec = duration.mid(6, 2);

        bool isOK = false;
        int hh = hour.toInt(&isOK, 10);
        if (isOK)
        {
            int mm = min.toInt(&isOK, 10);
            if (isOK)
            {
                int ss = sec.toInt(&isOK, 10);

                double result = double(ss + (mm * 60) + (hh * 60 * 60));
                return result;
            }
        }
    }

    return -1;
}

QString CDateUtils::secondsToTimeAsQString(int duration)
{
    SDateDifference time = CDateUtils::framesToTime(duration);

    QString s;
    s.sprintf("%02d:%02d:%02d", time.hours, time.minutes, time.seconds);

    return s;
}

QString CDateUtils::framesToTimeAsQString(uint64_t duration)
{
    SDateDifference time = CDateUtils::framesToTime(duration);

    QString s;
    s.sprintf("%02d:%02d:%02d-%02d", time.hours, time.minutes, time.seconds, time.frames);

    return s;
}

QString CDateUtils::framesToTime2AsQString(int duration)
{
    SDateDifference time = CDateUtils::framesToTime(duration);

    QString s;
    s.sprintf("%02d:%02d:%02d", time.minutes, time.seconds, time.frames);

    return s;
}

SDateDifference CDateUtils::secondsToTime(int duration)
{
    SDateDifference dif;
    dif.seconds = (int) (duration % 60);
    duration /= 60;
    dif.minutes = (int) (duration % 60);
    duration /= 60;
    dif.hours = (int) (duration % 24);
    dif.days = (int) (duration / 24);

    return dif;
}

SDateDifference CDateUtils::framesToTime(uint64_t duration)
{
    SDateDifference dif;

    float seconds = frameToSeconds(duration);

    int sec = int(seconds);
    //dif.frames = (int) fmod(duration, 29.97);
    //duration /= 29.97;
    //dif.seconds = (int) (duration % 60);
    //duration /= 60;
    //dif.minutes = (int) (duration % 60);
    //duration /= 60;
    //dif.hours = (int) (duration % 24);
    //dif.days = (int) (duration / 24);

    dif.days = (int) sec / 86400;
    dif.hours = fmod(sec, 86400) / 3600;
    dif.minutes = fmod(sec, 3600) / 60;
    dif.seconds = sec - ((dif.days * 86400) + (dif.hours * 3600) + (dif.minutes * 60));
    dif.frames = (seconds-sec) * 29.97;

    return dif;
}

