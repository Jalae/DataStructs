/******************************************************************************
*Author:		Kehnin Dyer
*File name:		Array2D.h
*Date Created:	2012/04/06
*Modifed:		2012/04/07 - refactored to use T*, all other files unmodified
******************************************************************************/
#if defined _WIN32 && defined _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <stdlib.h>
	#include <crtdbg.h>
#define MEMDUMP _CrtDumpMemoryLeaks();
#else
#define MEMDUMP ;
#endif



#ifndef ARRAY2D_MKII_H_
#define ARRAY2D_MKII_H_


#include "Row.h"
#include "../Utils/k_string.h"
#include "../ArrayClass/Exception.h"

/******************************************************************************
*Class:		Array2D
*
*Purpose:	A 2 dimentional array for anything. version 2, so it's better? :/
*
*Functions:
*		Array2D()
*			default constructor...
*		Array2D(size_t row, size_t col = 0)
*			standard constructor... i want column not defaulted,
*			and row defaulted to 1, but WHATEVER.
*		Array(Array2D & const copy)
*			copy constructor
*		~Array()
*			destructor, destucts the stuff
*		Array2D & operator=(Array2D& const rhs)
*			assignment op for assignment
*		Row<T> operator[](size_t const index)
*			get the correct row, for writing
*		Row<T> const operator[](size_t const index) const
*			get the correct row, for reading
*		size_t getRow() const
*			get the number of rows
*		void setRow(size_t rows)
*			change the number of rows
*		size_t getColumn() const
*			get the number of columns
*		void setColumn(size_t columns)
*			set the number of columns/row.
*		T& Select(size_t const row, size_t const col)
*			selector of element for writes
*		T& const Select(size_t const row, size_t const col) const
*			selector of element for writes
******************************************************************************/
template <typename T>
class Array2D
{
	T* m_array;
	size_t m_row;
	size_t m_col;
public:
	Array2D():m_array(nullptr),m_row(0), m_col(0)
	{}

	Array2D(size_t row, size_t col = 0):m_array(nullptr), m_row(row), m_col(col)
	{
		int len = row*col;
		if (len)
			m_array = new T[row*col];
	}

	Array2D(Array2D const & copy):
						m_array(nullptr),
						m_row(copy.getRow()),
						m_col(copy.getColumn())
	{
		*this = copy;
	}

	~Array2D()
	{
		delete[] m_array;
		m_array = nullptr;
		m_row = 0;
		m_col = 0;
	}

	Array2D & operator=(Array2D const & rhs)
	{// i technicly don't need that check...
		if(this != &rhs)
		{
			m_col = rhs.m_col;
			m_row = rhs.m_row;
			T* temp;
			temp = new T[rhs.m_row*rhs.m_col+1];
			delete[] m_array;
			for(size_t i(0); i < rhs.m_row; i++)
				for(size_t j(0); j < rhs.m_col; j++)
					temp[(i*m_col)+j] = rhs[i][j];
			m_array = temp;
		}
		return *this;
	}

	Row<T> operator[](size_t const row)
	{
		return Row<T>(*this, row);
	}

	Row<T> const operator[](size_t const row) const
	{
		return Row<T>(const_cast<Array2D<T> &>(*this), row);
	}

	inline size_t getRow() const
	{
		return m_row;
	}

	inline void setRow(size_t rows)
	{
		m_row = rows;
	}

	inline size_t getColumn() const
	{
		return m_col;
	}
	
	inline void setColumn(size_t columns)
	{
		m_col = columns;
	}

	T & Select(size_t const row, size_t const col)
	{
		if(col >= m_col)
		{
			throw(Exception("Invalid Column index"));
		}
		if(row >= m_row)
		{
			throw(Exception("Invalid Row index"));
		}
		size_t index = (row*m_col)+col;
		if(index >= m_row*m_col)
		{		//Array handled this before. this only really matters
				//when the user tries to fix things incorrectly from the
				//previous throws.
			throw(Exception("Array Index Out of Bounds"));
		}
		return m_array[(row*m_col)+col];
	}
	
	T const & Select(size_t const row, size_t const col) const
	{
		if(col > m_col)
		{
			throw(Exception("Invalid Column index"));
		}
		if(row > m_row)
		{
			throw(Exception("Invalid Row index"));
		}
		size_t index = (row*m_col)+col;
		if(index > m_row*m_col)
		{		
			throw(Exception("Array Index Out of Bounds"));
		}
		return m_array[(row*m_col)+col];
	}


};

#endif
