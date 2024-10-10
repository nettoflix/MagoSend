/*
 * COpenedWindows.h
 *
 *  Created on: 05/03/2014
 *      Author: 4scg
 */

#ifndef COPENEDWINDOWS_H_
#define COPENEDWINDOWS_H_

#include <QStringList>


#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;


class COpenedWindows
{
public:

	static QStringList getAllOpenedWindowsIDThathStarWith(QString lookingForThisApp);

	static QStringList getAllOpenedWindows(QString lookingForThisApp);

    static bool isWindowOpen(QString name, int moreThan = 0);

	static int getOpenedWindowCount(QString name);
};

#endif /* COPENEDWINDOWS_H_ */
