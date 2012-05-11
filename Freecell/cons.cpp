/******************************************************************************
*Author:		Kehnin Dyer
*File name:		cons.cpp
*Date Created:	2012/05/10
*Modifed:		2012/05/11
******************************************************************************/
#include "cons.h"

void SetCursor(COORD pos)
{
	HANDLE stout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(stout, pos);
}
