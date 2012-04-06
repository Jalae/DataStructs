/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Row.h
*Date Created:	2012/06/02
*Modifed:		
******************************************************************************/

#ifndef ROW_H_
#define ROW_H_

template <typename T>
class Array2D;

template<typename T>
class Row
{
	Array2D& const m_array2D;
	size_t const m_row;

	Row()
	{}
	Row(Row& const copy)
	{}
	Row& operator=(Row& const rhs)
	{}

public:
	Row(Array2D& const array, size_t row):m_array2D(array), m_row(row)
	{}

	~Row()
	{}

	T& operator[](size_t const column)
	{
		return m_array2D.Select(m_row, column);
	}

	T& const operator[](size_t column) const
	{
		return m_array2D.Select(m_row, column);
	}
	
};

#endif

