/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Cell.h
*Date Created:	2012/04/12
*Modifed:		
******************************************************************************/
#define _UNICODE
#define UNICODE
#include <iostream>
#include <windows.h>

class Cell
{
	bool m_touched;
	size_t m_shape;
	size_t m_color;
public:
	Cell(size_t shape = 0, size_t color = 0):m_touched(false),m_shape(shape),m_color(color)
	{}
	
	Cell & Touch()
	{
		m_touched = true;
		return *this;
	}
	
	bool Touched() const
	{
		return m_touched;
	}

	//puts cell back in the starting state
	void Reset()
	{
		m_touched = false;
		m_shape = 0;
		m_color = 0;
	}
	
	void SetShape(size_t shape, size_t color)
	{
		m_shape = shape;
		m_color = color;
	}

	void Draw() const
	{ //this handles changing the color and shape based on its' members
		_CONSOLE_SCREEN_BUFFER_INFO t;
		HANDLE st = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(st, &t);

		if(m_touched)
			SetConsoleTextAttribute(st, m_color+1 | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
		else
		SetConsoleTextAttribute(st, m_color+1);

		if(m_shape==1 && m_color==1)//wild
		{
			SetConsoleTextAttribute(st, 15 | BACKGROUND_BLUE | BACKGROUND_INTENSITY);
			wchar_t t[] = {223,0};
			DWORD x;
			WriteConsoleW(st, t, 1, &x, NULL);
		}
		else
		{
			if(m_shape)
			{
				wchar_t t[] = {m_shape+223,0};
				DWORD x;
				WriteConsoleW(st, t, 1, &x, NULL);
			}
			else
			{
				DWORD x;
				WriteConsoleW(st, " ", 1, &x, NULL);
			}
		}
		//change them back
		SetConsoleTextAttribute(st,t.wAttributes);
	}

	bool Neighborable(Cell const & C)
	{
		if(m_shape == 0)//im empty
			return true;
		if((C.m_shape == 1) && (C.m_color == 1 ))
		{
			return true;
		}
		if((m_shape == 1) && (m_color == 1 ))
		{
			return true;
		}

		if(C.m_color == m_color || C.m_shape == m_shape)//we are friends
		{
			return true;
		}
		return false;//nope
	}
};
