/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Cell.h
*Date Created:	2012/04/12
*Modifed:		
******************************************************************************/

#include <iostream>

class Cell
{
	bool m_touched;
	size_t m_shape;
	size_t m_color;
public:
	Cell(size_t shape = 0, size_t color = 0):m_touched(false),m_shape(0),m_color(0)
	{}
	
	void Touch()
	{
		m_touched = true;
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
		std::cout << "X";
	}

	bool Neighborable(Cell const & C)
	{
		if(C.m_shape == 1 || m_shape == 1)
		{
			return true;
		}
		if(C.m_color == m_color || C.m_shape == m_shape)
		{
			return true;
		}
		return false;
	}
};
