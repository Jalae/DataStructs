/******************************************************************************
*Author:		Kehnin Dyer
*File name:		FreeCell_Class.h
*Date Created:	2012/05/4
*Modifed:		2012/05/11
******************************************************************************/

#if defined _WIN32 && defined _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else
#define MEMDUMP ;
#endif

#include "FreeCell_Class.h"
#include <iostream>

void main()
{
	{
		FreeCell Game;
		Game.Play();
	}
	MEMDUMP
	std::cin.ignore();
}