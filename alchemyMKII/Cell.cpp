/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Cell.cpp
*Date Created:	2012/04/12
*Modifed:		2012/04/23
******************************************************************************/
#include "Cell.h"

Cell::Cell(size_t shape = 0, size_t color = 0):m_touched(false),m_shape(shape),m_color(color)
{}
Cell::Cell(Cell & c):m_touched(c.m_touched),m_shape(c.m_shape),m_color(c.m_color)
{}
Cell::~Cell()
{}
Cell & Cell::operator=(Cell & c)
{
	m_touched=c.m_touched;
	m_shape=c.m_shape;
	m_color=c.m_color;
}

//returns a cell ref, so that it can be chained.
Cell & Cell::Touch()
{
	m_touched = true;
	return *this;
}
bool Cell::Touched() const
{
	return m_touched;
}

void Cell::Reset()
{
	m_touched = false;
	m_shape = 0;
	m_color = 0;
}

void Cell::SetShape(size_t shape, size_t color)
{
	m_shape = shape;
	m_color = color;
}
void Cell::Draw() const
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
bool Cell::Neighborable(Cell const & C)
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

