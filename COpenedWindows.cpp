/*
 * COpenedWindows.cpp
 *
 *  Created on: 05/03/2014
 *      Author: 4scg
 */

#include "COpenedWindows.h"

#ifdef _WIN32
#include <conio.h>
#include <windows.h>
#include <psapi.h>
#include <tlhelp32.h>
#else
#include <QProcess>
#include <QFileInfo>
#endif

#include <iostream>

#include <QDebug>
#include <QApplication>
#include <vector>

//vai conter todos nomes das aplicacoes...
QStringList __internalAppsList;
QStringList __internalAppsListId;

#ifdef _WIN32
void GetProcessNameAndID(DWORD processID)
{
	char szProcessName[MAX_PATH];
	memset(szProcessName, 0, MAX_PATH);

	// Get a handle to the process.

	HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
								   PROCESS_VM_READ,
								   FALSE, processID);

	// Get the process name.

	if (NULL != hProcess)
	{
		HMODULE hMod;
		DWORD cbNeeded;

		if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
		{
			GetModuleBaseName(hProcess, hMod, (WCHAR*) szProcessName, sizeof(szProcessName) / sizeof(char*));

			PROCESSENTRY32 processInfo;
			processInfo.dwSize = sizeof(processInfo);
			Process32First(hProcess, &processInfo);

		}
	}

	QString appName("");
	for (int i = 0; i < MAX_PATH - 2; i += 2)
	{
		if (szProcessName[i] == 0)
		{
			break;
		}
		else
		{
			appName.append(szProcessName[i]);
		}
	}

	// Print the process name and identifier.
	if (appName != "" && appName.length() > 1)
	{
		qDebug("processID %s t %d", appName.toLatin1().data(), (int)processID);

		__internalAppsList.push_back(appName);
		__internalAppsListId.push_back(QString::number(processID));

	}

	CloseHandle(hProcess);
}
#endif

QStringList COpenedWindows::getAllOpenedWindowsIDThathStarWith(QString lookingForThisApp)
{
	qDebug("CCOpenedWindows::getAllOpenedWindows()() - IN");

	__internalAppsList.clear();
	__internalAppsListId.clear();

	QStringList finalList;

#ifdef _WIN32
	DWORD aProcesses[1024], cbNeeded, cProcesses;
	unsigned int i;

	qDebug("CCOpenedWindows::getAllOpenedWindows()() - 1");

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		qDebug("CCOpenedWindows::getAllOpenedWindows()() - 1 erro OUT");
		return __internalAppsListId;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	qDebug("CCOpenedWindows::getAllOpenedWindows()() - 2");

	// Print the name and process identifier for each process.
	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			GetProcessNameAndID(aProcesses[i]);
		}
	}

	for (int j = 0; j < __internalAppsList.size(); j++)
	{
		if (lookingForThisApp.startsWith(__internalAppsList[j]))
		{
			finalList.push_back(__internalAppsListId[j]);
		}
	}
#else

	QProcess processa;

	//esse comando retorna o PID junto...
	processa.start("pidof", QStringList() << lookingForThisApp);

	processa.waitForFinished();
	processa.setProcessChannelMode(QProcess::MergedChannels);
	QString str(processa.readAllStandardOutput());
	QStringList process = str.split("\n");
	for (int i = 0; i < process.size(); i++)
	{
		QString line = process[i];
		{
			QStringList pids = line.split(" ");
			for (int i = 0; i < pids.size(); i++)
			{
				QString sId = pids[i];

				bool ok = false;
				qint64 id = sId.toLongLong(&ok);
				if (id > 0 && ok)
				{
					finalList.push_back(sId);
				}
			}
		}
	}

#endif

	qDebug("CCOpenedWindows::getAllOpenedWindows()() - OUT");

	return finalList;
}

QStringList COpenedWindows::getAllOpenedWindows(QString lookingForThisApp)
{
	qDebug("CCOpenedWindows::getAllOpenedWindows()() - IN");

	__internalAppsList.clear();
	__internalAppsListId.clear();

#ifdef _WIN32

	DWORD aProcesses[1024],
		  cbNeeded, cProcesses;
	unsigned int i;

	qDebug("CCOpenedWindows::getAllOpenedWindows()() - 1");

	if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
	{
		qDebug("CCOpenedWindows::getAllOpenedWindows()() - 1 erro OUT");
		return __internalAppsList;
	}

	// Calculate how many process identifiers were returned.
	cProcesses = cbNeeded / sizeof(DWORD);

	qDebug("CCOpenedWindows::getAllOpenedWindows()() - 2");

	// Print the name and process identifier for each process.
	for (i = 0; i < cProcesses; i++)
	{
		if (aProcesses[i] != 0)
		{
			GetProcessNameAndID(aProcesses[i]);
		}
	}

	qDebug("CCOpenedWindows::getAllOpenedWindows()() - OUT");
#else

	QProcess processa;

	//esse comando retorna o PID junto, mas tem um espaco na frente que nao sei se pode
	//ser utilizado. Etnao estou comentando temporariamente isso...
	//processa.start("sh",QStringList() << "-c" << "ps -Ao pid,cmd");

	//uso entao esse comando que comeca pegando o caminho completo dos apps em execucao...
	processa.start("sh", QStringList() << "-c" << "ps -Ao cmd");
	processa.waitForFinished();
	processa.setProcessChannelMode(QProcess::MergedChannels);
	QString str(processa.readAllStandardOutput());
	QStringList process = str.split("\n");
	for (int i = 0; i < process.size(); i++)
	{
		QString line = process[i];
		QStringList lineInfo = line.split(" ");
		if (lineInfo.size() >= 1)
		{
			QString processFileName = lineInfo[0];

			QFileInfo info(processFileName);
			QString processName = info.completeBaseName();

			if (processName.trimmed() == (lookingForThisApp))
			{
				__internalAppsList.push_back(processName);
			}
		}
	}


	qDebug("CCOpenedWindows::getAllOpenedWindows()() - OUT");

#endif

	return __internalAppsList;
}

int COpenedWindows::getOpenedWindowCount(QString name)
{
	qDebug("COpenedWindows::getWindowOpenCount() - IN");

	QStringList list = COpenedWindows::getAllOpenedWindows(name);

	int count = 0;

	for (int i = 0; i < list.size(); i++)
	{
		QByteArray t1 = name.toLatin1().data();
		QByteArray t2 = list[i].toLatin1().data();

		if (strcmp(t1.data(), t2.data()) == 0)
		{
			count++;
		}
	}

	qDebug("COpenedWindows::getWindowOpenCount() - OUT");

	return count;
}

bool COpenedWindows::isWindowOpen(QString name, int moreThan)
{
	qDebug("COpenedWindows::isWindowOpen() - IN");

	qDebug("COpenedWindows::isWindowOpen() - 1 [%s]", name.toLatin1().data());

	QStringList list = COpenedWindows::getAllOpenedWindows(name);
	int count = 0;

	for (int i = 0; i < list.size(); i++)
	{
		QByteArray t1 = name.toLatin1().data();
		QByteArray t2 = list[i].toLatin1().data();

		if (strcmp(t1.data(), t2.data()) == 0)
		{
			count++;

			if (count > moreThan)
			{
				qDebug("COpenedWindows::isWindowOpen() - OUT TRUE");
				return true;
			}
		}
	}

	qDebug("COpenedWindows::isWindowOpen() - OUT");

	return false;
}
