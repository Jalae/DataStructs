#ifndef ARRAY_H
#define ARRAY_H

#include "Exception.h"

class Array
{
	//template
	int * m_array;

	size_t m_length;
	int m_start_index;

public:
	Array():m_array(nullptr), m_length(0), m_start_index(0)
	{
	}

	Array(size_t const length, int const start_index = 0):
								m_array(nullptr),
								m_length( (length >= 0) ? length : 0),
								m_start_index(start_index)
	{
		//template
		m_array = new int[length];
	}

	Array(Array& copy):
						m_array(nullptr),
						m_length(copy.m_length),
						m_start_index(copy.m_start_index)
	{

		*this = copy;
	}

	~Array()
	{
		delete[] m_array;
		m_array = nullptr;
	}

	Array& operator=(Array& rhs)
	{
		if(this != &rhs)
		{
			if(m_array)
				delete[] m_array;
			m_length = rhs.m_length;
			m_start_index = rhs.m_start_index;
			m_array = new int[m_length];
			for(size_t i(0); i < m_length; i++)
			{
				m_array[i] = rhs.m_array[i];
			}
		}
		
		return *this;
	}

	//template
	int & operator[](int const index)
	{
		int trueindex = index - m_start_index;
		if(trueindex >= (int) m_length)
		{
			throw Exception("Index out of bounds: Greater");
			
		}
		if(trueindex < 0)
		{
			throw Exception("Index out of bounds: Lower");
			
		}
		return m_array[trueindex];
	}

	int getStartIndex() const
	{
		return m_start_index;
	}

	void setStartIndex(int start_index)
	{
		//nothing specified for this... so...
		//should {1, 2, 3, 4, 5} starting 0, if changed to 2
		//stay the same? or become {3, 4, 5, ?, ?} 
		//eh... first variant for now.
		m_start_index = start_index;
	}

	size_t getLength() const
	{
		return m_length;
	}

	void setLength(size_t length)
	{
		length = (length > 0) ? length : 0;
		//getting larger
		if(m_length < length)
		{
			//template
			int* temp = new int[length];
			if(m_array)
			{
				for(size_t i(0); i < m_length; i++)
					temp[i] = m_array[i];
				delete[] m_array;
			}
			m_array = temp;	
		}
		m_length = length;
	}

};

#endif
