/******************************************************************************
*Author:		Kehnin Dyer
*File name:		cons.h
*Date Created:	2012/05/10
*Modifed:		2012/04/11 
******************************************************************************/
#pragma once

#include<windows.h>
#include<iostream>

template <typename T>
void writeAt(COORD pos, T str)
{
	COORD temp;
	HANDLE stout = GetStdHandle(STD_OUTPUT_HANDLE);
	int i(0);
	{
		CONSOLE_SCREEN_BUFFER_INFO ScreenBufferInfo = { 0 };
		
		GetConsoleScreenBufferInfo(stout, &ScreenBufferInfo );
		temp.X = ScreenBufferInfo.dwCursorPosition.X;
		temp.Y = ScreenBufferInfo.dwCursorPosition.Y;
	}
	SetConsoleCursorPosition(stout, pos);
	std::wcout << str;
	SetConsoleCursorPosition(stout, temp);
}

void SetCursor(COORD pos);