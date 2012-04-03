#ifndef ARRAY_H
#define ARRAY_H

class Array()
{
	//template
	int * m_array;

	size_t m_length;
	int start_index;

public:
	Array()
	{
	}

	Array(size_t const length, int const start_index = 0)
	{
	}

	Array(Array const & copy)
	{
	}

	~Array()
	{
	}

	Array& operator=(Array const & rhs)
	{
	}

	//template
	int & operator[](int const index)
	{
	}

	int  getStartIndex()
	{
	}

	void setStartIndex(int start_index)
	{
	}

	size_t getLength()
	{
	}

	void setLength(size_t length)
	{
	}

};

#endif
