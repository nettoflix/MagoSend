/*
 * IMagoDB.cpp
 *
 *  Created on: 14/03/2018
 *      Author: Leo
 */

#include "IMagoDB.h"
#include "MagoDB.h"


IMagoDB* CreateDB(char* IP, bool useRandomConnectionName)
{
	IMagoDB* pMagoDB = new MagoDB(IP, useRandomConnectionName);
	return pMagoDB;
}


void DropDB()
{

}

