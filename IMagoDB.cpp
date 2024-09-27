/*
 * IMagoDB.cpp
 *
 *  Created on: 14/03/2018
 *      Author: Leo
 */

#include "IMagoDB.h"
#include "MagoDB.h"


IMagoDB * CreateDB()
{


	IMagoDB * pMagoDB = new MagoDB();
	return pMagoDB;
}

void DropDB()
{

}

