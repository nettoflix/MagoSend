/*
 * CLog.cpp
 *
 *  Created on: 28/05/2014
 *      Author: 4scg
 */

#include "CLog.h"
#include <QDebug>
#include <QThread>
#include <QDateTime>
#include <QFile>
#include <QString>
#include <QDir>
#include <iostream>
#include <QStandardPaths>
#include <QDir>
#define MAX_LOG_FILE_SIZE_IN_BYTES 40000000

#define MAX_LOGFILE_COUNT 40

CLog::CLog(const QString &logName)
{
    this->logName = logName;
    index = 0;
    totalSize = 0;
    QString filename("");

    //procura pelo primeiro arquivo disponivel para log...
    for (int i = 0; i < MAX_LOGFILE_COUNT; i++)
    {

#ifdef _WIN32
        char name[1024];
        QString path("C:/ProgramData/4S/MagoSend");
        QDir programDataDir(path);
        if(!programDataDir.exists())
        {
            if (programDataDir.mkpath(path)) {
                qDebug() << "CLog::CLog - Diretorio de logs criado com sucesso";
                sprintf(&name[0], "%s\\%s%d.txt",path.replace("/", "\\").toLatin1().data(),logName.toLatin1().data(), i);

            } else {
                qDebug() << "CLog::CLog - Nao foi possivel criar o diretorio de logs, tentara escrever em C:\\ProgramData";
                sprintf(&name[0], "C:\\ProgramData\\%s%d.txt",logName.toLatin1().data(), i);
            }

        }
        else
        {
            sprintf(&name[0], "%s\\%s%d.txt",path.replace("/", "\\").toLatin1().data(),logName.toLatin1().data(), i);
        }

        qDebug("CLog::CLog(const QString &logName) - [%s]", name);
#else
		QString homePath = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);
		QString path = homePath + QString("/MagoSendLogs");
		QDir dir(path);
		if(!dir.exists())
		{
			dir.mkpath(path);
		}
        QString name;
		name.sprintf("%s/%s_%d.txt", path.toLatin1().data(), logName.toLatin1().data(), i);
#endif
        QFile ffile(name);
        if (!ffile.exists() || ffile.size() <= MAX_LOG_FILE_SIZE_IN_BYTES)
        {
            filename = QString(name);
            totalSize = ffile.size();
            index = i;
            break;
        }
    }

    //se nenhum nome de arqivo foi montado, significa que ja demos a volta completa em todos
    //os arquivos e precisamos voltar ao inicial
    if (filename == "")
    {
        QFile::remove(logName);
        totalSize = 0;
        index = 0;
    }

    ideLogfile.open(filename.toLatin1().data(), std::ios::app);
}

CLog::~CLog()
{
    ideLogfile.close();
}

void CLog::writeText(char* text)
{
    mutex.lock();

    //monta a string de log contento data + horario + id da thread + msg...
    QDateTime now = QDateTime::currentDateTime();

    //xxx:64 trocado para long long
    QString final = now.toString("dd/MM/yyyy hh:mm:ss - zzzz - ") + QString("%1").arg((long long) QThread::currentThread()) + " - " + QString(text);

    std::string sfinal = final.toStdString();

    totalSize += final.length();
    if (totalSize >= MAX_LOG_FILE_SIZE_IN_BYTES)
    {
        index++;
        if (index >= MAX_LOGFILE_COUNT)
        {
            index = 0;
        }

        totalSize = 0;
        ideLogfile.close();

#ifdef _WIN32
        char filename[1024];
        sprintf(&filename[0], "c:\\%s%d.txt", logName.toLatin1().data(), index);

        QFile::remove(filename);
        ideLogfile.open(filename, std::ios::app);

#else
        QString filename;
        //filename.sprintf("%s/4SMago%d.txt", QDir::homePath().toLatin1().data(), index);
        filename.sprintf("%s/%s_%d.txt", QDir::homePath().toLatin1().data(), logName.toLatin1().data(), index);

        QFile::remove(filename);
        ideLogfile.open(filename.toLatin1().data(), std::ios::app);
#endif

    }

    ideLogfile << sfinal << "\n";
    ideLogfile.flush();

    mutex.unlock();
}
