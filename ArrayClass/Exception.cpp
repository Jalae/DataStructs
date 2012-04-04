#include "Exception.h"
#include "k_string.h"



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
	if(m_msg)
		delete[] m_msg;
	m_msg = nullptr;
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
