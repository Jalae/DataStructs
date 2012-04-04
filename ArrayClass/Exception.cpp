#include "Exception.h"

//move this to its own file
size_t k_strlen(char* str)
{
	size_t i(0);
	for(i; str[i] != 0; i++); 
	return i;
}

void k_strcpy(char* src, char* des)
{
	if(src==des)
		return;
	size_t len = k_strlen(src);
	if(des)
		delete[] des;
	des = new char[len+1];
	for(size_t i(0); i < (len + 1); i++)
	{
		des[i] = src[i];
	}
}


Exception::Exception():m_msg(nullptr)
{
}

Exception::Exception(char * const msg):m_msg(nullptr)
{
	k_strcpy(msg, m_msg);
}

Exception::Exception(Exception & e):m_msg(nullptr)
{
	*this = e;
}

Exception::~Exception()
{
	delete[] m_msg;
}

Exception & Exception::operator=(Exception& rhs)
{
	if(this != &rhs)
		k_strcpy(rhs.getMessage(), m_msg);
	return *this;
}

char* const Exception::getMessage() const
{
	return m_msg;
}

void Exception::setMessage(char* const msg)
{
	k_strcpy(msg, m_msg);
}

char* const Exception::what() const
{
	return m_msg;
}

ostream & operator<<(ostream & stream, Exception & except)
{
	return stream << except.what();
}
